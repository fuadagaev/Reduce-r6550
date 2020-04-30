// File newcslgc.cpp                      Copyright (c) Codemist, 1990-2020

//
// Garbage collection.
//

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

#include "headers.h"


// Overview of procedure for full garbage collection:
//
// For garbage collection I will refer to the full half-space as "A"
// for Active, the empty one as "C" for Clear. At the entry to GC I will
// expect that all pages in C have chaining set up in them in the form
//
//   |.....................XXXXXpq.........XXXXXrs.........XXXXXt0......|
//    ^                    ^    ^          ^    ^          ^    ^       ^
//  gFringe             gLimit gNext       p    q          r    s       t
// where XXXX denote items pinned by a previous GC, p is a subsequent limit
// and q a subsequent next (and similarly for r,s,t) with the follow-on next
// value zero at the end of the page.
// Within the active part of the heap there will be a list pinsC that has
// pointers to each pinned item in C. This is not a Lisp standard list - it
// will be chained in the CAR field with pointers tagged as FORWARD while the
// CDR field of each entry refers to the pinned item. furthermore this list is
// sorted so that items appear in it in order of increasing memory address,
// and each of the lists freePages and mostlyFreePages will be similarly
// sorted. *MAYBE*!!!!!!!
// I should note that at the start of a GC the object-start and pinned bitmaps
// for each page contain junk - that is because those two bitmaps share space
// with maps used for write barriers. During a global GC write barrier data
// is not used. During a minor GC it will be necessary to use dirty bits
// (where RPLACx, PUTVEC and relatives have updated field in stable data and
// these must be treated as list-bases potentially referring into the
// current nursery and previous pages). In that case I will need to set up
// pinned maps for victimPage (which is the only one from which information
// gets evacuated). Because all live data in that is about to be relocated
// dirty bits associated with it are not relevant. So I first set up
// information about pinning in victimPage. I can then inspect all data
// that may be dirty, and if it refers into victimPage I leave it alone if
// pinned, evacuate data or follow a forwarding address. If while doing that
// I find that all references from the region marked as dirty end up in
// pages that will be stable at the end of this collection I can clear the
// dirty bit. If pointers remain into what is current at the start of GC
// (and so will be previous at the end) I leave the dirty bit set. But beyond
// that I can use the space for pin information if I want.
//
// When I say that all pages in C have freespace mapping in them I will in
// fact in due course arrange that on a "lazy" basis so that from when the
// program starts up I only initialize a page when I am first about to use
// it.

// (1) Clear the "pinned" maps for pages in A.
//     Initialize pinsA list to be empty.
//
// (2) For each ambiguous value (ie value on the stack associated with
//     any thread) do:
//   If value could not be a pointer into A then ignore it.
//   Ensure that object-starts bitmap in relevant page of A is set up.
//   Identify the start of the object in A that the value might refer to.
//   If that item is already pinned then no need to do more.
//   If that object is part of pinsC (because the CAR field contains
//     something tagged as FORWARD) do no more.
//   Set pinned bit for the location concerned. Mark page as one that
//     contains pinned items.
//   Add the pinned item to the list pinsA, which is built in space C.
//
// (3) Evacuate each of the following locations:
//   (a) Every precise pointer.
//   (b) Every pointer field in any object in list pinsC.
//   (c) Every pointer field in any object copies into C in via the
//       evacuation process.
//   See later for explanation of "evacuate".
//
// (4) Set up A with the structure needed to be an empty page, ie
//   a gFringe/gLimit/gNext chain that works around pinned items. To do this
//   a sorted version of pinsA is liable to be useful, especially if while
//   doing this I can have all pages making up A in a sorted list.
//
// (5) Flip status and interpretation of A and C.
//
//
// Evacution:
//   If the location to be evacuated holds immediate data do nothing,
//     otherwise it holds a pointer to some object.
//   If that object is not in A or it is in A but is pinned then do nothing.
//   If the CAR field of the object holds a forwarding address use that to
//     update the location to be a proper pointer to relocated data. Done!
//   Make a (binary) copy of the object in the next free space within C.
//   Set the CAR field to be a forwarding address to the copy.
// Note that the copy will then (in due course) be scanned under (3.c).


// Code for sorting "lists"...

// This is to sort some form of structure that is in abstract terms a list.
// The "list" is passed and returned an an item of type Concrete. This might
// but a type that is a pointer to a node object, or it could be "void *"
// where implementation details are being hidden from other parts of the
// code, or it might be "uintptr_t" and a handle for the start of the list.
// Abstract then needs to be a class that provides a collection of static
// methods to inspect and update the list. Because this sorts the list
// in-place there is no need for any storage allocation. I will expect that
// the Concrete type is small, so that creating an array of length 1000 will
// not strain stack-size.

#include <algorithm>

template <typename Concrete, class Abstract>
Concrete sortList(Concrete a)
{   if (Abstract::isNil(a)) return a; // a trivial case
// Count the length of the list.
    size_t n = 0;
    for (Concrete b = a; !Abstract::isNil(b); b = Abstract::cdr(b)) n++;
// If the list is short enough then I will copy the data to a simple
// C++ array, use std::sort to get it in the right order and then patch
// things back into list form.
    const size_t LIMIT = 1000;
    if (n < LIMIT)
    {   Concrete v[LIMIT];
        size_t i=0;
        for (Concrete b = a; !Abstract::isNil(b); b = Abstract::cdr(b))
            v[i++] = b;
        std::sort(&v[0], &v[n], Abstract::before);
        Concrete r = v[0];
        Concrete pr = r;
        for (i=1; i<n; i++)
        {   Abstract::rplacd(pr, v[i]);
            pr = v[i];
        }
        Abstract::rplacd(pr, Abstract::nil());
        return r;
    }
// If I have too much data to be able to sort it all at once I will partition
// into two lists, sort each and then merge. The partitioning does not need
// to preserve ordering at all.
    Concrete l1 = Abstract::nil();
    Concrete l2 = Abstract::nil();
    while (!Abstract::isNil(a))
    {   Concrete w = a;
        a = Abstract::cdr(a);
        Abstract::rplacd(w, l1);
        l1 = w;
        if (!Abstract::isNil(a))
        {   w = a;
            a = Abstract::cdr(a);
            Abstract::rplacd(w, l2);
            l2 = w;
        }
    }
    l1 = sortList<Concrete,Abstract>(l1);
    l2 = sortList<Concrete,Abstract>(l2);
// Now merge.
    Concrete r = Abstract::nil();
    Concrete rp = r;
    bool some = false;
    while (!Abstract::isNil(l1) &&
           !Abstract::isNil(l2))
    {   if (Abstract::before(l1, l2))
        {   Concrete w = l1;
            l1 = Abstract::cdr(l1);
            if (some)
            {   Abstract::rplacd(rp, w);
                rp = w;
            }
            else
            {   r = rp = w;
                some = true;
            }
        }
        else
        {   Concrete w = l2;
            l2 = Abstract::cdr(l2);
            if (some)
            {   Abstract::rplacd(rp, w);
                rp = w;
            }
            else
            {   r = rp = w;
                some = true;
            }
        }
    }
    if (Abstract::isNil(l1)) Abstract::rplacd(rp, l2);
    else Abstract::rplacd(rp, l1);
    return r;
};

// Pages are chained via a "chain" field. I will want to
// sort the list of mostlyFreePages based on their memory address.

class PageListClass
{
public:
    static Page *nil()
    {   return (Page *)0;
    }
    static bool isNil(Page *p)
    {   return p == (Page *)0;
    }
    static Page *cdr(Page *p)
    {   return p->chain;
    }
    static void rplacd(Page *p, Page *x)
    {   p->chain = x;
    }
    static bool before(Page *x, Page *y)
    {   return (uintptr_t)x < (uintptr_t)y;
    }
};

Page *sortPages(Page *p)
{   return sortList<Page *, PageListClass>(p);
}

// I will have a list of pinned items, with chaining through what would
// normally be the CAR field and with chaining pointers using TAG_FORWARD.
// I will want this sorted on the address value stored in the CDR field.

class PinChainClass
{
public:
    static uintptr_t nil()
    {   return TAG_FORWARD;
    }
    static bool isNil(uintptr_t p)
    {   return p == TAG_FORWARD;
    }
    static uintptr_t cdr(uintptr_t p)
    {   return ((uintptr_t *)(p-TAG_FORWARD))[0];
    }
    static void rplacd(uintptr_t p, uintptr_t x)
    {   ((uintptr_t *)(p-TAG_FORWARD))[0] = x;
    }
    static bool before(uintptr_t x, uintptr_t y)
    {   return ((uintptr_t *)(x-TAG_FORWARD))[1] <
               ((uintptr_t *)(y-TAG_FORWARD))[1];
    }
};

uintptr_t sortPinList(uintptr_t l)
{   return sortList<uintptr_t, PinChainClass>(l);
}

// During garbage collection I will allocate items in the half of my memory
// that has been free up to now. This follows a pattern rather similar to
// the onme used by the main allocation code, except that it does not have
// to concern itself with concurrency at all (YET!). I *could* try a bit
// harder to avoid fragmentation by keeping track of holes that I leave in
// newly allocated memory, but I will certainoly not do that in a first
// version and it could very easily be that to do so would complicate matters
// and slow GC down for gains in memory occupancy that would not be great
// enough to justify it. If I am keen I will come back to the issue later on,
// but I will need to evaluate whether it would actually help before I code
// too much.

uintptr_t nFringe, nLimit, nNext;

uintptr_t get_n_bytes_new(size_t n)
{   size_t gap = nLimit - nFringe;
    while (n > gap)
    {   if (gap != 0) setcar(nFringe, makePaddingHeader(gap));
        if (nNext != 0)
        {   nFringe = nNext;   // Skip past pinned data to the next chunk.
            nLimit = ((uintptr_t *)nFringe)[0];
            nNext = ((uintptr_t *)nFringe)[1];
            gap = nLimit - nFringe;
        }
        else   // Need to allocate a further page.
        {   Page *nextPage;
            if (mostlyFreePages != nullptr)   // Use pages with pinned items 1st.
            {   nextPage = mostlyFreePages;
                mostlyFreePages = mostlyFreePages->chain;
                mostlyFreePagesCount--;
            }
            else
            {   nextPage = freePages;
                freePages = freePages->chain;
                freePagesCount--;
            }
// Here I carefully take the newly allocated page on the END of the list of
// busy pages so that I will be able to scan that list sequentially and when
// I do so I will visit objects in the order of their allocation. This is
// needed to make the Garbage Collector work.
            nextPage->pageClass = currentPageTag;
            nextPage->chain = nullptr;
            if (busyPages == nullptr)
            {   busyPages = nextPage;
                victimPage = nullptr;
            }
            else
            {   if (victimPage != nullptr)
                    victimPage->pageClass = busyPageTag;
                currentPage->chain = nextPage;
                victimPage = currentPage;
                victimPage->pageClass = victimPageTag;
            }
            currentPage = nextPage;
            busyPagesCount++;
            uintptr_t pFringe = currentPage->fringe;
            uintptr_t pLimit = currentPage->limit;
            nFringe = pFringe;
            nLimit = pLimit;
            gap = nLimit - nFringe;
        }
    }
    uintptr_t r = nFringe;
    nFringe += n;
    return r;
}

void evacuate(LispObject *p)
{
// Here p is a pointer to a location that is a list-base, ie it contains
// a valid Lisp object. I want to arrange that the object and all its
// components are moved to the new half space, and (if necessary) the
// list base is updated to refer to the copy and a forwarding pointer is left
// where the original had been. The procedure is:
//   Let a = *p, ie the object that may need to be copied.
//   If a is tagged as immediate data do nothing.
//   [now a is some sort of tagged pointer]
//   If *a is a forwarding pointer replace the list base with the
//      object referred to, reconstructing suitable tag bits.
//   If the address that a refers to is in the free half-space it must be
//      a pointer to an object that had been pinned last time, so do nothing.
//   Determine the length, b, of the object that a refers to.
//   Allocate b byte in the new space and do a simple binary copy of all
//      of object a to there.
//   Write in a forwarding pointer.
//   Update the list-base to refer to the copy.
// Note that this is a shallow copy operation. A later stage must perform
// a linear scan of the newly copied material. That stage is not discussed
// here because this function does not directly cause it to happen.
//
    LispObject a = *p;
    if (is_odds(a) || is_immediate_num(a) || a == nil) return;
    LispObject *ap = reinterpret_cast<LispObject *>(a & ~TAG_BITS);
    LispObject aa = *ap;
    if (is_forward(aa))
    {   *p = aa + ((a&TAG_BITS)-TAG_FORWARD);
        return;
    }
    size_t len;
    if (is_cons(a)) len = 2*CELL;
    else if (is_symbol(a)) len = symhdr_length;
    else len = doubleword_align_up(length_of_header(aa));
    aa = get_n_bytes_new(len);
    std::memcpy(reinterpret_cast<void *>(aa), ap, len);
    *ap = TAG_FORWARD + aa;
    *p = aa + (a&TAG_BITS);
}

// For the following p starts off as a pointer to the first word of an object.
// It must identify the object type and call evacuate() on every pointer-
// holding field within it. It returns a pointer just beyond the object.

LispObject *evacuateContents(LispObject *p)
{   LispObject a = *p;
// a will NOT be a forwarding pointer because any object may only have this
// operation invoked on it once. If the object is a symbol or a vector then
// a will be tagged as its header. In other cases the object will be just
// a CONS cell.
    if (!is_odds(a) || !is_header(a))
    {   evacuate(&p[0]);            // A cons cell.
        evacuate(&p[1]);
        return &p[2];
    }
    if (is_symbol_header(a))
    {
//...
        return &p[symhdr_length/CELL];
    }
    size_t len = length_of_header(a);
    if (vector_holds_binary(a)) return &p[doubleword_align_up(len)/CELL];
//...
    return &p[doubleword_align_up(len)/CELL];
}

void prepareForGarbageCollection(bool major)
{   cout << "peepareForGarbageCollection" << endl;
    my_abort();
}

void clearPinnedInformation(bool major)
{   cout << "clearPinnedInformation" << endl;
    my_abort();
}

// Each page consists of a header followed by a number of chunks. There may
// be unused space in the page after the last chunk. For the purposes of
// pinning I want to identify the chunk (if any) that (a) points into, and
// arrange that it is on a per-page list of pinned chunks and that if there
// are any such chunks that the page itself is on a list of pages that contain
// pinned material.

void processAmbiguousInPage(bool major, Page *p, uintptr_t a)
{
//@@    uintptr_t pp = reinterpret_cast<uintptr_t>(p);
//@@    uintptr_t offset = a - pp;
    if (p->chunkCount.load() == 0) return;  // An empty Page.
// The list of chunks will be arranged such that the highest address one
// is first in the list. I will now scan it until I find one such that
// the chunk has (a) pointing within it, and I should not need many tries
// at all. The soring order MUST be consistent with the order I assume in
// my binary search code lower down, and so I use std::qsort which lets
// me specify my own ordering predicate without needing to wait for c++2x,
// at which stage std::sort gets such a generality.
    if (!p->chunkMapSorted)
        std::qsort(p->chunkMap, p->chunkCount, sizeof(p->chunkMap[0]),
                   [](const void *a, const void *b)
                   {   const Chunk *aa =
                           static_cast<const atomic<Chunk *>*>(a)->load();
                       const Chunk *bb =
                           static_cast<const atomic<Chunk *>*>(b)->load();
                       uintptr_t aaa = reinterpret_cast<uintptr_t>(aa);
                       uintptr_t bbb = reinterpret_cast<uintptr_t>(bb);
                       return aaa < bbb ? -1 :
                              aaa > bbb ? 1 : 0;
                   });
// chunkMap is now a table of pointers to chunks sorted into ascending order.
// I will use binary search to find out which (if any) of those chunks
// contains the address a.
    size_t low = 0, high = p->chunkCount.load()-1;
    while (low < high)
    {   size_t middle = (low + high + 1)/2;
        if (a < reinterpret_cast<uintptr_t>(p->chunkMap[middle].load()))
            high = middle-1;
        else low = middle;
    }
    Chunk *c = p->chunkMap[low];
    if (!c->pointsWithin(a)) return;
// Here (a) lies within the range of the chunk c. Every page that has any
// pinning must record that both by being on a chain of pages with pins
// and by having a list of its own pinned chunks.
// If the chunk is already tagged as pinned there is no need to do so again.
    if (c->isPinned) return;
    c->isPinned = true;
// Note that a single thread looks at ambiguous pointers so while I want
// everything atomic<> so that later on if other threads happen to look you
// you know they will see updates, I do not need to worry about race
// conditions while I form the chain of pinned chunks and pages.
//
// The use of .load() on the next line is because atomic items are not
// copyable as such.
    c->pinChain = p->pinnedChunks.load();
    p->pinnedChunks = c;
// When a chunk gets pinned then page must be too unless it already has been.
    if (p->hasPinned) return;
    p->hasPinned = true;
    p->pinChain = globalPinChain;
    globalPinChain = p;
}

// Here I have an item that may be arbitrary binary material but which COULD
// be a LispObject that will later be re-used. If it is a LispObject that
// refers to memory address (a) then I will want to be certain that garbage
// collection does not relocate material at (a). For a minor collection only
// objects in the victim page will be evacuated, so I have a simple initial
// filter. For a full GC I will need to determine whether (a) points anywhere
// within memory that is currently in use holding active Lisp data. This
// could be within the page currently bein allocated into, its predecessor
// page, all the pages that ephemeral collection would view as stable plus
// those sections of otherwise empty pages that might have live data that
// had been pinned during a previous GC. But not pages that had ended up
// totally empty.

void processAmbiguousValue(bool major, uintptr_t a)
{   if (!major)
    {   uintptr_t victimBase =
            reinterpret_cast<uintptr_t>(victimPage);
        if (victimBase <= a && a < victimBase+pageSize)
            processAmbiguousInPage(major, victimPage, a);
        return;
    }
    Page* p = findPage(a);
    if (!p->hasPinned) processAmbiguousInPage(major, p, a);
}

void identifyPinnedItems(bool major)
{
// For each ambiguous value (ie value on the stack associated with
// any thread) do processAmbiguousValue(). This must ensure that if
// the item might be a LispObject that is a reference that the destination
// address of that reference is marked as "pinned". During a minor GC
// the only items that need special marking will be one in the "victim"
// page since nothing else will ever be moved.
    for (unsigned int thr=0; thr<maxThreads; thr++)
    {   if ((threadMap & threadBit(thr)) != 0)
        {   uintptr_t base = stackBases[thr];
            uintptr_t fringe = stackFringes[thr];
            for (uintptr_t s=fringe; s<base; s+=sizeof(uintptr_t))
            {   processAmbiguousValue(major,
                                      *reinterpret_cast<uintptr_t *>(s));
            }
        }
    }
}

void evacuateFromUnambiguousBases(bool major)
{   cout << "evacuateFromUnambiguousBases" << endl;
    my_abort();
}

void evacuateFromPinnedItems(bool major)
{   cout << "evacuateFromPinnedItems" << endl;
    my_abort();
}

void evacuateFromDirty()
{   cout << "evacuateFromDirty" << endl;
    my_abort();
}

void evacuateFromCopiedData(bool major)
{   cout << "evacuateFromCopiedData" << endl;
    my_abort();
}

void endOfGarbageCollection(bool major)
{   cout << "endOfGarbageCollection" << endl;
    my_abort();
}

void garbageCollect(bool major)
{   cout << "\n+++++ Start of a "
         << (major ? "major" : "minor")
         << " GC\n";
    prepareForGarbageCollection(major);
    clearPinnedInformation(major);
    identifyPinnedItems(major);
    evacuateFromUnambiguousBases(major);
    evacuateFromPinnedItems(major);
    if (!major) evacuateFromDirty();
    evacuateFromCopiedData(major);
    endOfGarbageCollection(major);
}


#if 0
     uintptr_t pinsA, pinsC;

// (1) Clear the "pinned" maps for pages in A.
//     Initialize pinsA list to be empty.
for (Page *p=busyPages; p!=nullptr; p=p->chain)
    clearPinnedMap(p);
pinsA = TAG_FORWARD;
// (1a) Get ready for allocation into free space.
doomedPages = busyPages;
doomedPagesCount = busyPagesCount;
busyPages = nullptr;
currentPage = victimPage = nullptr;
busyPagesCount = 0;
nFringe = nLimit = nNext = 0;
//
//
// (3) Evacuate each of the following locations:
//   (a) Every precise pointer.
//   (b) Every pointer field in any object in list pinsC.
//   (c) Every pointer field in any object copied into C in via the
//       evacuation process.
//
// I should remind you, gentle reader, that the value cell
// and env cells of nil will always contain nil, which does not move,
// and so I do not need to copy them here provided that NIL itself
// never moves.
evacuate(reinterpret_cast<LispObject *>(plistaddr(nil)));
evacuate(reinterpret_cast<LispObject *>(pnameaddr(nil)));
evacuate(reinterpret_cast<LispObject *>(fastgetsaddr(nil)));
evacuate(reinterpret_cast<LispObject *>(packageaddr(nil)));
// All of the "ordinary" list bases are scanned here.
for (LispObject **p = list_bases; *p!=nullptr; p++) evacuate(*p);
// This Lisp stack still exists, even though my longer term aim is to
// be able to get rid of it.
for (LispObject *sp=stack;
     sp>reinterpret_cast<LispObject *>(stackBase); sp--) evacuate(sp);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
if (repeat_heap != nullptr)
{   for (size_t i=1; i<=repeat_count; i++)
        evacuate(&repeat_heap[i]);
}
// Now I should deal with all pointers emerging from items in the C region
// they were pinned and hence have to be deemed alive.
for (uintptr_t p=pinsC;
     p!=0;
     p=(reinterpret_cast<uintptr_t *>(p-TAG_FORWARD))[0])
{   static_cast<void>(evacuateContents(
                          &(reinterpret_cast)<LispObject *>(p-TAG_FORWARD))[1]);
}
// (3.1)
// Scan the copied data evacuating fields found within it. This of course
// can add to the total bulk of copied data! So stop when the evacuation
// process catches up to the end of the copied data.
// There is a special issue to consider here. I have just done evacuateContents
// on every pinned item that was in the mostlyFree page-set. As I perform
// the following scan I will do evacuateContents on every item that I find
// amongst that data that I have copied to there, and that interleaves with
// the pinned data. I must not process anything twice!
// To cope with this I will arrange that when I have one or a sequence of
// pinned items left behind clogging up otherwise free memory I will prefix
// same with a header word that indicates a block of binary data spanning
// across the pinned region. So in the scan that follows I will come across
// these special headers and that causes me to skip over the pinned data
// which has in fact already been processed). To make it possible to set this
// up I need to be able to place a header word in front of anything that ends
// up pinned. The only very special case there is if the first real object
// on a page ends up pinned. To cope with that I will arrange that the very
// first item placed on every page starts off as a padder header with its
// length code such that no data follows it. This will of course never end up
// either pinned or live (I ensure that I do not pin padder data ever!) and
// so there will always be space before the first real item.
// Note that in a free page any pinned block is followed by two words that
// identify the start and end of the following pinned block - that is until
// allocation reaches and passes it. These two words will not be included in
// the region spanned by the padding header. However their presence means that
// pinned blocks need to be at least 3 units apart. In reality I will want to
// cluster sets of pinned data that lie reasonably compactly into a single
// pinned block, because there is overhead in the allocator moving from one
// free region to the next.
Page *scanPage = busyPages;
uintptr_t scanPoint = scanPage->fringe;
uintptr_t scanLimit = scanPage->limit;
for (;;)
{   scanPoint =
        reinterpret_cast<uintptr_t>(
            evacuateContents(reinterpret_cast<LispObject *>(scanPoint)));
    if (scanPoint >= scanLimit)
    {   if (scanPoint == nFringe) break;
//          ...
    }
}

//
// (4) Set up A with the structure needed to be an empty page, ie
//   a gFringe/gLimit/gNext chain that works around pinned items. To do this
//   a sorted version of pinsA is liable to be useful, especially if while
//   doing this I can have all pages making up A in a sorted list.
//
// (5) Flip status and interpretation of A and C.
// For a FULL garbage collection the partly filled page that was the final
// one that material was evacuated into becomed the new currentPage.
//
my_abort();
}

#endif

bool generationalGarbageCollection = false;

void generationalGarbageCollect()
{   garbageCollect(false);
}

void fullGarbageCollect()
{   garbageCollect(true);
}

// end of file newcslgc.cpp
