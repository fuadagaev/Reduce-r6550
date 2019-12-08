// newallocate.cpp                         Copyright (C) 2018-2019 Codemist
//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
//


// Development game-plan for this stuff - showing the steps or stages
// to go through:
// [Steps I have achieved are deleted from this list!]
//
// (3) Arrange that every garbage collection will be a major one and
//     re-work the allocation and re-allocation of memory blocks for that.
//     By keeping the code with precise list-bases for everything that
//     matters the ambiguous pointers should never be the only reason
//     for saving any data - they just pin things and hence mess up memory
//     layout. Get that version of GC working. Note that write barriers
//     may collect information but it is never used!
// (4) Make some collections minor ones, thus needing to cope with the
//     consequences of the write barrier.
// (5) Put in explicit test cases for data that is only preserved via an
//     ambiguous list-base.
// (6) Thread-synchronization for GC entry.
// (7) Thread-local support for fluid bindings, and simple code in the Lisp
//     for creating threads, even though almost everything is not thread-safe.
// (8) [in various orders] get rid of push/pop stuff if the main code in
//     favour of just letting conservative memory management cope. And
//     migrate more status to thread-local and/or protect it with critical
//     regions.
// (9) Fix ccomp.red and bytes2.cpp regarding new treatment of fluids and
//     for thread safety.
// (10)Protection of blocking calls so that GC can still happen.


// Well by the time I have got started at all on that list the issue of
// the exact sequence towards the end will become clearer! Really it is the
// first 3 that are my initial plan.


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

/*!!! csl
*/

#include "headers.h"

//
// This is a place for my latest round of thinking about a new storage
// management scheme. The ideal I set now is that garbage collection should
// be both conservative and generational and that it should be able to
// support multiple mutator threads. I am NOT intending either to run
// garbage collection concurrently with the mutator (so the GC is a "stop
// the world" one, although most garbage collections should be "minor" ones
// and hence not too disruptive). I have thought about using multiple threads
// during garbage collection but will not attempt that in a first version -
// and preliminary measurements of the overhead of atomic exchange
// instructions on current computers make me suspect it may not be sensible.


// The design here has to mingle plans for global storage allocation,
// the CONS operation as well as operations involving Lisp atoms, the
// way that Lisp threads can access the values of variables, synchronization
// matters and so on. In general it seems that almost all aspects from the
// lowest to the most global level interact.

// So here is an overview. Well I fear I may have written bits of this already
// in several places, but writing it out helps me to plan. All of the numeric
// values given here are indicative rather than guaanteed final.

// Memory is grabbed from the operating system in large chunks, with a few
// hundred megabytes for the first chunk and larger ones potentially sized
// in geometric progression, so that with a maximum of 16 chunks I can end up
// with as much memort as can ever be useful. The limit on the total number
// of chunks used as so that given a value that might be a pointer it will
// be possible to identify the chunk it might point within using a small
// number of comparison operations. The mega-chunk allocation is such that the
// system can start with fairly sane amounts of memory but expand on need.
//
// Each chunk is divided into 8Mbyte pages. At any one moment one page will
// be "Current", a second will be "Previous", some others will be "Busy" and
// the rest "Free". All mutator allocation happens within the Current page.
// When that becomes full live data is evacuated from the Previous page into
// Busy memory and what was Current becomes Previous. The old Previous page
// becomes Free and a Free page is chosen to be the new Current. Note this
// might be done by swapping the sense of Current and Previous, but if I
// did that then if those two pages get severly fragmented that that situation
// would persist, so I will want to arrange that pages get moved to be
// extensions to the Busy pool from time to time. Which will tend to happen
// naturally but may need forcing in pathological case!
//
// Because garbage collection is conservative there can be ambiguous pointers
// that refer into Previous. Data at the locations so addressed must not be
// moved: I will refer to it as "pinned". The Current and each Free page may
// have some pinned items present. When a page becomes Current it will have
// three pointers - gFringe, gLimit and gNext. gFringe identifies the first
// point at which data could be allocated, gLimit points either one beyond
// the end of the page or to the start address of the next pinned block.
// If there is a pinned block then gNext points just beyond it, and the first
// two words of the free region after that contain new values for gLimit and
// gNext. If gLimit points to the end of the whole page then gNext will be
// zero.
// In Previous and Busy each page will be kept full by placement of padder
// pseudo-objects anywhere where there could be gaps: that is so that it is
// possible to perform a sequential scan of the page with each item within
// it identifiable by inspection of its first (header) word. A challenge to
// nots is that this means that only valid objects may be pinned, so that
// sequential scans of a page can traverse past them without trouble.
//
// Allocation within Current is by incrementing gFringe and if necessary
// skipping on to gNext. By making gFringe std::atomic this allocation can be
// thread-safe.
//
// Within a page allocation (via gFringe) allocated 16Kbyte chunks to each
// thread. The thread holds variable fringe and limit to allow it to perform
// simple sequential allocation within the chunk with low overhead. During
// garbage collection it is necessary to access and update fringe and limit
// values for every thread, and to support that I have data such as the
// array fringeBis[] that is indexed by a thread-number. Especially when
// garbage collection is being triggered data can be moved from the simple
// (albeit thread-local) variable into this array. Because each thread has
// its own chunk most allocation within a chunk doe snot involve any locks.
// When a chunk overflows a fresh one needs to be allocated. If the request
// that triggered this was for n bytes of memory that the next chunk that is
// grabbed is of size 16K+n so that 16Kbytes are left available after the
// potentiallt large allocation. As regards space use the worst case for this
// is if there are many sequential requests each needing just over 16Kbytes
// apiece. In that case around 50% of memory in Current end up unused. This
// space will remain unused in Previous, but when data is evacuated to Busy
// it will be packed properly closely, so across the whole system the worst
// possible "waste" that way will be 8Mbytes. Of course most allocations will
// be of much smaller objects and so I am not worried in this area.
//
// The trigger for garbage collection is when at least one thread attempts
// an allocation and moved gFringe on beyond gLimit. As a C pedant I ough to
// worry if that led to a pointer beyond the range of the mega-chunk that
// had been grabbed from the OS, or (worse) if it led to overflow in address
// arithmetic. If I was super-cautious I would leave the top of each huge
// chunk as unused buffer against just such concerns. The amount I would
// need to reserve would be VECTOR_CHUNK_BYTES (2Mb) times the maximum number
// of threads (64), and that may be way more that I am happy with! So just
// for now I will duck that concern. But I will want the higgest-addressed
// huge chunk to end at least 128M before the end of memory address space!
//
// When a thread (or several threads) overflows a page it must trigger garbage
// collection. In the process it must synchronize with all the other threads.
// To achieve that it sets the limit value in every (active) thread to zero.
// The consequence will be that when the thread next tried to allocate memory
// it will get the initial impression that its chunk was full and can go into
// a more elaborate path which detects that actual situation. There are two
// cases when a memory allocation request might not arise promptly. One is
// code loops that do not allocate memory: each of those must contain a
// polling request which will be implemented as a request for zero bytes of
// memory - which in term will merely amount to a comparison between fringe
// and limit. The other would be when the thread was perfroming some operation
// that could or did block. That will obviously include when it uses range of
// synchronization primitives. In such case before blocking it must remove
// itself from the pool of active threads, and it can reinstate itself later.
//
// As garbage collection starts each thread must record its stack pointer and
// ensure that all pointer-objects that it is using are recorded on the
// stack (as well as potentially being in machine registers). The (C++) stack
// will then be scanned with all values on it treated as potential or
// ambiguous pointers.
//
// Given a potential pointer the system must be able to determine if it in
// fact points within a properly allocated object. This process starts by
// checking which mega-chunk is involved. From that information simple
// arithmetic can identify a page. Pointers that are into the header sections
// of a page or beyond its gLimit are certainly not references to live
// objects. I will then use a bitmap associated with the relevant page to
// let me identify that start of any object that the potential pointer lies
// within. If this object is a padder the pointer was invalid.
// Setting up the bitmaps is achieved by a linear scan of the page. This is
// a reason for using padders so that the page as a whole is linearly
// consistent. During a minor GC the only page that needs a bitmap is Previous.
// During a major GC bitmaps can be created when one first observes a
// potential pointer into the page. My expectation is that the vast majority
// of (valid) potential pointers will be into Current, with the next higher
// number into Previous. That is because fairly recently allocated objects
// are most likely to have references to them on the stack. For older material
// I think I expect a tendancy for clustering and with a large memory
// configuration only a small fraction of the total number of pages will
// be involved. So with lazy creation of the bitmaps it is likely that
// the cost of bitmap creation will not be excessive. Searching a bitmap
// is most expensive if a potential pointer refers to a high address in a
// very large object. It is not yet clear whether there is any merit in
// trying to take special action to speed up treatment of that case.
//
// A consequence of using a generational system is that I need to be able
// to respond to updates to old data that lead to references to new data.
// When I perform a major GC I will be scavanging everything and so no special
// treatment is called for, but to support minor GCs I will arrange that any
// use of RPLACD, RPLACD or PUTV (or derived operations such as PUTHASH, PUT
// and NCONC) set a mark indicating a region of memory that must be treated
// as roots. I make the map of dirty regions out of bytes, arguming that
// updating a byte to atomically set it non-zero is likely to be cheaper than
// the read-modify-write of an atomic bit update. I also expect that many
// pages (at least when one is performing a large calculation) will not have
// any dirty data, so each page has a flag marking whether any segment of it
// has been updated. The dirty regions may not align neatly with object starts
// and finishes, and so when I mark from them I will treat the pointers that
// they contain as ambiguous. This will tend to lead to more pinned items
// within Pending. Thus use of imperative features such as RPLACx carry two
// costs - one the work of the write barrier as they execute and the second
// some extra pinning and hence memory inflexibility withing Previous.
// It may be worth noting that the issue of pinned items will not arise
// when an updated reference is to Busy data, but that dirty marks can only
// trivially be cancelled during a full GC, and that dirty bits can be needed
// on pages that are Free apart from the fact that they contain some pinned
// items. So for some purposes I will want to partition unused pages into
// Free and MostlyFree!
// When I scan a dirty region it will be cheap to check if any of the
// pages that potential-pointers within it are either Current, Pending or
// MostlyFree. If there are no such pointers then the dirty bit can be cleared
// even though one is just within a minor GC. If MostlyFree pages are given
// priority for use to extend the Busy region as data is evacuated from
// Previous then there will be some tendancy for dirty markers to become
// cancellable. It may made sense to monitor the number of dirty regions
// and if it gets really excessive to trigger a major GC, but that is an
// informal idea at present and will probably not be very useful!



std::size_t pagesCount;
std::size_t activePagesCount;

// Ha ha potentially clever idea. Have activeTheads an atomic<uint32_t> and use
// the bottom 10 bits for the number of threads that are busy and the next
// 10 bits for the number potentially busy and finally 10 bits for the total
// number of threads in play. That way I can eg subtract (1<<10)+1 when a
// thread temporarily removes itself from the pool because it
// may be about to block! Etc etc. The second idea is that there is potential
// misery about needing to get every thread to exit when STOP is called. Well
// maybe I can avoid using mutexes at all as places that code can block and
// instead use condition variables with a condition of the form
// (<sensible-condition> || need_to_exit) and then when the barrier is passed
// I immediately check need_to_exit and tidy up a bit more. To make that work
// I suspect I will need a table of every muxex/condition variable anywhere
// so that when I set need_tO-exit I can notify all of them!
// Well for muxexes and condition variables visible at the Lisp level I will
// need underlying C++ ones which will sort of need garbage collection but
// must never move. I think that the best bet is to have a vector pool of
// synchronization objects with the Lisp objects that encapsulate them holding
// an integer index that will need to be treated as a weak pointer to
// keep the object "alive". Whe not alive the object is just available for
// re-use... That is all going to be a bit messy.

// Another though to be left as comments here until I implement it and comment
// it where the code ends up:
// The copying GC can probably be coded so as to use multiple threads to do
// the copying! I have bits of that sketched in my mind, util until I can sit
// down quietly with a full sized keyboard and code some of it things are a
// bit uncertain. In particular there will be issues about the cost of
// the test-and-set operations I would need to use to keep threads from
// entanglement.
// A though is that when I am about to evactuate the item it address p I
// start with a = atomic_store(p, TAG_FORWARD) where tht returns the
// previous value at p. Then if that was TAG_FORWARD I will know that
// somebody else had been evacuating that location - I just re-try in a busy-
// waiting style. If what was there was a forwarding address then I do an
// (atomic) store to put it back. Otherwise I have the original contents and
// I have marked the word with TAG_FORWARD so that no other thread will mess
// with it (much). As quickly as I can I work out where the data will need
// to end up. This is going to be an atomic_add operation on the fringe of
// the new heap. Then I can store a proper forwarding address in place.
// I HOPE that it will be rare that two threads try to evacuate the same
// location at once, so the spin-wait will be uncommon, and I hope that
// working out where something moves to will be quick so that when it does
// happen it will not need to run for long.
// I can batch the identification of locations to evacuate so I can use a
// mutex to protect that code that grabs them, and that will be ok provided
// identifting locations is (much) cheaper than actually altering stuff.

// BEWARE:
//   consider the imlemention of v = cons(a,b) where v is some value that may
// be shared across threads. Eg rplacd(V, cons(a, b)) is almost certainly
// going to count. The natural implementation will be along the lines
//    w = allocate();
//    w[0] = a;
//    w[1] = b;
//    v = w;
// but as a first issue the compiler might use v in place of the temporary w,
// and then we have
//    v = allocate();
//    some other thread accesses uninitialized car v here!
//    v[0] = a; v[1] = b;
// Things are even worse because with the code written in vanilla form the CPU
// may re-order all the memory writes, again leaving v referencing a chunk of
// memory not fully initialized. The two issues must be dealt with using one
// of two ideas. Synchronization primitives such as mutexes could be used to
// enclose the operation as a critical region, and potential accesses would
// do likewise. The performance and ugliness costs are horrendous! Or memory
// fences can be used. So that shows I will need to study thread-fence methods
// and all the options that provide. Note that without a fence after the update
// of v it could be that the chance made would reside locally so that other
// threads would not see it, so a fence may be needed to "publish" it.
// Making almost every value std::atomic<T> might also do the job, but that
// would then imply fences everywhere and could hurt performance and it would
// also be horribly ponderous and clumsy.
// 


std::uintptr_t *C_stackbase;   // base of the main thread
std::atomic<std::uint32_t> activeThreads;

//  0x00 : total_threads : lisp_threads : still_busy_threads



// All the heap memory I use here will be allocated within (up to) 32
// segments that are grabbed using "new" etc...
// Each segment of memory will start aligned at a multiple of CSL_PAGE_SIZE
// which is (at present) 8 Mbytes. The idea here is that I grab seriously
// large chunks of memory from the system and these chunks may not be
// contiguous. But with at most 32 of them I can take any bit-pattern and
// with around 5 comparisons I can identify which (if any!) of these
// chunks it points within. Then division by 8M can get me to the start of
// the 8 Mbyte segment that is involved. That bit of search will be heavily
// used when processing ambiguous pointers.
//


// Provide the kernel of the allocation code...

// This is an updated and fuller explanation of memory layout on each
// page.
// A page may either be one where allopcation is currently happening within
// it or one that is full of data, or it may be one that is currently
// free. A messy complication is that in each situation its general pattern
// of use can be disrupted by virtue of it having some data within it that
// was pinned during a previous garbage collection and so had to be left
// in place. That means my idea of having separate pages for cons cells and
// for vectors seems to fail.

// A page will have as its layout:
// (1) A smallish header that contains its fringe, arrangements so it can
//     be chained along with other pages etc. Details will emerge as I code
//     all this and discover what I need!
// (2) A region that acts as a "dirty map". This region will be present in
//     every page and is an array of atomic<uint8_t>, where each byte maps
//     a 64-byte block within the page and will get set non-zero if a RPLAC
//     or PUTV (style) operation updates anything within that small block.
//     for 8 Mbyte pages this map will be 128 Kbytes large. It only gets
//     written to when Lisp performs a valid RPLAC/PUTV and so addresses
//     such as those in the bitmap itself will never become dirty. So if
//     this map is aliased to start at the beginning of the page the first
//     2 Kbytes may be used (eg for the header) without risk.
// (3) A bitmap that can be used to tag "pinned" objects. To have one bit for
//     each 8-byte item in the heap (and every valid LispObject will be
//     positioned so as to be 8-byte aligned, whether on a 32 or 64-bit
//     platform) will require 128 Kbytes, and this will be set up as an
//     array of uint64_t values which will mean that any linear scan of it
//     only has 16 K words to check. Pinned status is established for memory
//     in the scavengable region as a first step in garbage collection. Two
//     cases arise. In Minor garbage collection pinning only happens in the
//     single page of scavengable material, and all of that will be processed
//     so issues as to whether there are up-pointers present in it do not
//     arise. Pinned bits are not set in the Stable part of the heap so
//     dirty bits there are unaffected. On the other hand during a Major
//     garbage collection all memory is Scavangable and will need pin
//     information, but dirty bits are not relevant. So provided pinned bits
//     are ONLY used or inspected during garbage collection the bitmap here
//     can overlay the dirty map.
//     If at the end of garbage collection there had been pinned items in the
//     Scavengable region and if the contents of any of those are up-pointers
//     then they must be marked as dirty when the page is put in the Free area.
// (4) A further 128 Kbyte bitmap that can mark which addresses within a page
//     are at the start of a LispObject. These get set in the Scavengable
//     region as a prelude and prerequisite for setting pinned bits. Well to
//     be more careful about that statement, when an ambiguous address is
//     inspected to use it for pinning the page it refers into will need its
//     object-start map set up. So pages that contain no pinned items at all
//     avoid this. So during a minor GC only the scavengable region gets
//     scanned to identify object starts, while during a major GC only pages
//     that are the targets of ambiguous pointers will.
//

// Here is a layout for an 8 Mbyte page, specifying the various
// ways in which data can be accessed. This uses a union so that the page
// header will overlap the beginning of the objstart[] bitmap, but because
// objects only reside in the data[] part the first couple of kilobytes
// of objstart[] will never be used.


Page *currentPage;       // Where allocation is happening. The "nursery".
Page *previousPage;      // A page that was recently the current one.
Page *busyPages;         // Chained list of pages that contain live data.
Page *doomedPages;       // Page from which live stuff is being evacuated.
Page *mostlyFreePages;   // Chained list of pages that the GC has mostly
                         // cleared but that have some pinned data left in
                         // them.
Page *freePages;         // Chained list of pages that are not currenty in
                         // use and that contain no useful information.

std::size_t busyPagesCount, mostlyFreePagesCount, freePagesCount;

void *heapSegment[32];
void *heapSegmentBase[32];
std::size_t heapSegmentSize[32];
std::size_t heapSegmentCount;



// I make some assumptions about the variations on std::atomic<> that I
// use, but then would like to use static_assert to confirm them or to
// cause CSL to fail to compile. However the test has to be dynamic, so I can
// at best cause things to fail at system startup. Boo Hiss!
// I believe that my assumptions have a good chance of being satisfied
// on almost all machines, even though I can imagine architectures
// where there may be trouble. But what matters most to me will be x86,
// x86_64 and both 32 and 64-bit ARM when using g++ or clang, and those will
// get checked the first time I compile this code on each.
//
// Note that the C++ standard explictly says that there is no guarantee that
// the sizes of atomic specializations match those of the underlying raw
// types, but that implementations are encouraged to make that the situation
// where they can.
// Well std::atomic_flag is guaranteed lock-free and to my mind that would
// suggest it had no need for extra memory and I might hope it was thus
// of size 1, but this is not guaranteed either. So my code is not guaranteed
// portable! What an amazing situation (ha ha).

class MakeAssertions
{
public:
    MakeAssertions()
    {   if (sizeof(std::atomic<std::uint8_t>) != 1)
        {   std::cout << "Atomics bytes are too large" << std::endl;
            std::abort();
        }
        if (!std::atomic<std::uint8_t>().is_lock_free())
        {   std::cout << "Atomic<uint8_t> not lock-free" << std::endl;
            std::abort();
        }
        if (!std::atomic<std::uintptr_t>().is_lock_free())
        {   std::cout << "Atomic<uintptr_t> not lock-free" << std::endl;
            std::abort();
        }
    }
};

static MakeAssertions test_for_lockfree;

// Before checking an ambiguous pointer I need to set up the bitmap that
// notes the start-point of objects. This function does that for one page.

void recordObjectStarts(Page *x)
{   std::memset(x->pageBody.pageBitmaps.maps.objstart, 0,
           sizeof(x->pageBody.pageBitmaps.maps.objstart));
    LispObject *p = x->pageBody.data;
// @@ The version I have here does not yet allow fror the fact that the
// data region within the page will have some pinned objects in and they
// will all need object start tags set - and that fringe may be the
// current level of allocation but the way that interacts with interleaved
// pinned items is not really considered.
    while (reinterpret_cast<std::uintptr_t>(p) < x->pageHeader.fringe)
    {   std::size_t os = (reinterpret_cast<std::uintptr_t>(p) -
                     reinterpret_cast<std::uintptr_t>(x))/8;
        x->pageBody.pageBitmaps.maps.objstart[os/64] |= UINT64_C(1)<<(os%64);
        LispObject v = *p;
        if (!is_odds(v)) p += 2;
        else if (is_symbol_header(v)) p += symhdr_length/sizeof(LispObject);
        else p += doubleword_align_up(length_of_header(v))/sizeof(LispObject);
    }
    x->pageHeader.onstarts_present = true;
}

// For findObjectStart() the objectstart bitmap is set in the relevant page
// and I must return the untagged address of the item containing the address
// p, or NULL if there is none such. This is used when an ambiguous pointer
// is processed and it maps from the random address-like value to either 0
// which is taken to indicate that the value is not a valid pointer, or
// to the 8-byte aligned address of the start of an object that the
// address lies within. This is perhaps the part of dealing with ambiguous
// pointers that I view as having required most thought!

std::uintptr_t findObjectStart(std::uintptr_t p, Page *x)
{
// First check if p is actually within the (active) data region in the page.
    if (p < reinterpret_cast<std::uintptr_t>(x->pageBody.data) ||
        p >= reinterpret_cast<std::uintptr_t>(x->pageHeader.fringe)) return 0;
// Now, and I have NOT done this yet, I shoule cope with the case where p
// points within an item that had been pinned within page x by an earlier
// GC.
//  @@ unfinished work here
// Next search for the nearest object start at a lower address than p,
// using the objectstart bitmap to help.
    std::size_t os = (p - reinterpret_cast<std::uintptr_t>(x))/8;
    std::size_t word = os/64;
    int bit = os%64;
// I am going to expect that an especially common case will be when the
// pointer p is just to the start of an object with at most a tag value
// added. My division by 8 a few lines above disarded those low bits, so
// I will see if what I end up with is in fact a proper object start.
    if ((x->pageBody.pageBitmaps.maps.objstart[word] & (UINT64_C(1)<<bit)) != 0)
        return p & -(std::uintptr_t)8;
// The next case I will consider is if the object header is fairly close
// to p, and the word in the bitmap that covers p includes mention of it.
    if (bit != 0)
    {   std::uint64_t v = ((UINT64_C(1)<<bit) - 1) &
                     x->pageBody.pageBitmaps.maps.objstart[word];
// Now v records any headers just before p.
        if (v != 0)
        {   int n = 63-nlz(v);
// Convert back from an address in the bitmap to the location in memory.
            return reinterpret_cast<std::uintptr_t>(x) + 8*(word*64 + n);
        }
    }
// Now I can scan down 64 8-byte locations at a time, ie 512 bytes at a go.
// The distance I may need to go is certainly bounded by the possible size
// of an object that I seem to point within, but for any pointer that is
// really valid it is related to how far down that object I am pointing,
// and so to have a really bad cost here I would have to have a (probable)
// pointer referring to almost the end of a huge object. Because of the
// finite size of a page the very worst cost could be going round the
// simple loop 16K times. Well in fact it is better than that. These days
// the largest basic Lisp object I ever create is of size maybe pageSize/4
// (specifically VECTOR_CHUNK_BYTES), and this sets the worst case distance
// that it can ever be necessary to scan to find an object start.
    word--;
    while (x->pageBody.pageBitmaps.maps.objstart[word] == 0) word--;
// The loop must terminate because any page either has no data in it at all,
// and in that case an ambiguous pointer will be detected as invalid because
// it addresses above fringe, or it will have at least one item in it,
// including one right at its start.
// I will need to double-check this when I put in full support for items that
// where pinned by the last garbage collection, including the case where the
// very first item in the page has that status. Anyway when I find a nonzero
// entry in the map the top bit it identifies the highest-addressed object
// start, and that is what I want.
    int n = 63-nlz(x->pageBody.pageBitmaps.maps.objstart[word]);
    return reinterpret_cast<std::uintptr_t>(x) + 8*(word*64 + n);
}

// Here we have a function to call during a major garbage collection. It is
// given an (ambiguous) pointer. If necessary it established an object-start
// map for the page that addresses, and then it marks as pinned the object
// referenced.

void setPinnedMajor(std::uintptr_t p)
{
//   If value could not be a pointer into A then ignore it.
//   Ensure that object-starts bitmap in relevant page of A is set up.
//   Identify the start of the object in A that the value might refer to.
//   If that item is already pinned then no need to do more.
//   If that object is part of pinsC (because the CAR field contains
//     something tagged as FORWARD) do no more.
//   Set pinned bit for the location concerned. Mark page as one that
//     contains pinned items.
//   Add the pinned item to the list pinsA, which is built in space C.
    Page *x = findPage(p);
    if (x == NULL) return;      // Not pointing at any page at all.
    if (!pageIsBusy(x)) return; // not in A.
    if (!x->pageHeader.onstarts_present) recordObjectStarts(x);
    std::uintptr_t os = findObjectStart(p, x);
    if (os == 0) return;               // Does not point within any object
    if (is_forward(car(os))) return;   // part of pinsC
    os = (os - reinterpret_cast<std::uintptr_t>(x))/8;
    x->pageBody.pageBitmaps.maps.pinned[os/64] |= UINT64_C(1)<<(os%64);
    x->pageHeader.somePins = true;
    p = get_n_bytes_new(2*CELL);
    setcar(p, pinsA);
    pinsA = p + TAG_FORWARD;
}

// At the start of a minor garbage collection it it is necessary to call
// this so that the start-point of all objects in the scavengable region
// are known. This is done explicitly rather than having it done
// conditionally on each case where a pointer (seems to) refer to that region.

void recordObjectStartsMinor()
{   recordObjectStarts(previousPage);
}

// Set a pinned bit for an address if it lies within the single scavengable
// page that exists during a minor collection.

void setPinnedMinor(std::uintptr_t p)
{
// If the address is not in the scavengable page I can ignore it.
    if (!inPreviousPage(p)) return;
// Find the object within the page that it is within, or return NULL if none.
// This will always return a value that is an address aligned zero mod 8.
    std::uintptr_t os = findObjectStart(p, previousPage);
    if (os == 0) return;
// Now I set a bit in the pinned map.
    os = (os - reinterpret_cast<std::uintptr_t>(previousPage))/8;
    previousPage->pageBody.pageBitmaps.maps.pinned[os/64] |= UINT64_C(1)<<(os%64);
}

// Just to provide a level of abstraction I provide a function that clears
// the pinned map in a page. At the start of a minor collection this should
// be called on the scavengable region. Before a major collection on all
// pages.

void clearPinnedMap(Page *x)
{   std::memset(x->pageBody.pageBitmaps.maps.pinned, 0,
           sizeof(x->pageBody.pageBitmaps.maps.pinned));
}

LispObject get_symbol(bool gensymp)
{   return get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
}

LispObject get_basic_vector(int tag, int type, std::size_t size)
{
// tag is the value (e.g. TAG_VECTOR) that will go in the low order
// 3 bits of the pointer result.
// type is the code (e.g. TYPE_STRING) that gets packed, together with
// the size, into a header word.
// size is measured in bytes and must allow space for the header word.
// [Note that this last issue - size including the header - was probably
// a mistake since the header size depends on whether I am using a
// 32-bit or 64-bit representation. However it would be hard to unwind
// that now!]
//
    std::size_t allocSize = (std::size_t)doubleword_align_up(size);
// Basic vectors must be smaller then the CSL page size.
    if (allocSize > (CSL_PAGE_SIZE - 32))
        aerror1("request for basic vector too big",
                fixnum_of_int(allocSize/CELL-1));
    LispObject r = get_n_bytes(allocSize);
    *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
//
// DANGER: the vector allocated here is left uninitialised at this stage.
// This is OK if the vector will contain binary information, but if it
// will hold any LispObjects it needs safe values put in PDQ.
//
// All vectors are allocated so as to be 8-byte aligned. On a 64-bit system
// a vector that will not end up being a multiple of 8 bytes long naturally
// gets padded out. Here I arrange to zero out any such padder word. This
// should not be very important since nobody should ever try to use that
// word. When the garbage collector copies material around it transcribes
// the whole vector (including the padder), but it should never try to trace
// through it. By tidying this up here can feel that I do not have any
// need to worry about it elsewhere.
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *(LispObject *)(r+allocSize-CELL) = 0;
    return (LispObject)(r + tag);
}

// This takes a vector (which can be one represented using an INDEXVEC)
// and reduces its size to a total value len. It returns the shorter
// vector. Only used on simple vectors. This is ONLY used when a hash table
// finds that the number of items in it has decreased dramatically and it
// wants to shrink. For big tables the index vector will decrease in size
// but each sub-vector stored in it will remain as it is. For smaller tables
// it can be the table itself that shrinks. When a vector shrinks I should
// put a padder in the vacated space so that it will still be possible to
// do linear scans of memory.

LispObject reduce_basic_vector_size(LispObject v, std::size_t len)
{   std::size_t oldlen = doubleword_align_up(length_of_header(vechdr(v)));
    setvechdr(v, TYPE_SIMPLE_VEC + (len << (Tw+5)) + TAG_HDR_IMMED);
    len = doubleword_align_up(len);
    if (len != oldlen) setvechdr(v + len, makePaddingHeader(oldlen-len));
    return v;
}

// As well as shrinking vectors the hash table code can want to "borrow"
// space by allocating vectors (never lists) from the half of memory that
// the copying garbage collector is not keeping live data in at present.
// The protocol I have is that it goes
//      {   Borrowing borrowObject;
//          ... get_vector() ... get_vector() ...
//      }
// and it MUST be coded so that it can not trigger garbage collection while
// the "borrowed" vectors are in use. It does not have any specific way of
// indicating when the space is no longer needed, save that a subsequent
// call to prepare_for_borrowing() must not happen while borrowed space is
// still needed. The key use for this is when a hash table needs to be
// re-hashed - the code borrows space and copies the existing table contents
// into it. It then re-hashes everything back into the existing vector.
// Doing things that way really simplifies the hash table code, and avoids
// having the temporary space anything other than rather temporary and
// transient. However the scheme is not very thread-friendly! My current
// plan is that only one thread may be re-hashing (and hence borrowing) at
// once, and while that is happening any other thread that needs to trigger
// garbage collection will have to wait. I am putting in stubs of code here
// but the code to borrow memory will in fact be very similar to that used
// during garbage collection to allocate space in the new half-space when
// a vector needs to be evacuated to there.
// Note that other threads might be busy allocating memory during the
// time that one is borrowing, so they can need garbage collection. It will
// have to wait until the use of borrowed memory is over.

// Perhaps I could invent and then use an alternative protocol so that each
// thread could do its own borrowing without messy clashes. Perhaps the main
// issue there is recovering memory when a thread has finished. To think
// about how vital that might be I would need to consider whether hash tables
// might need rehashing multiple times between garbage collections - if the
// answer is "no" then each hash table could have its own associated
// borrowed shadow ... that starts to sound sensible to me! I will get a LOT
// more of this code working before I worry about that detail.

//thread_local Page *borrowPages;
//thread_local std::uintptr_t borrowFringe;
//thread_local std::uintptr_t borrowLimit;
//thread_local std::uintptr_t borrowNext;

// Here I need to arrange that if several threads each try to borrow memory
// at the same (or overlapping) times that they end up with separate
// chunks. I do this by letting each grab memort from mostlyFreePages and
// freePages, but with a mutex to protect the allocation. Then when borrowing
// is complete I push stuff back. I do not change the recorded counts of
// free pages.

LispObject borrow_n_bytes(std::size_t n)
{   for (;;)
    {   size_t gap=borrowLimit::get() - borrowFringe::get();
        if (n <= gap)
        {   uintptr_t r = borrowFringe::get();
            borrowFringe::set(borrowFringe::get() + n);
            return (LispObject)r;
        }
        if (borrowNext::get() != 0)
        {   borrowFringe::set(borrowNext::get());
            borrowLimit::set(((std::uintptr_t *)borrowFringe::get())[0]);
            borrowNext::set(((std::uintptr_t *)borrowFringe::get())[1]);
            continue;
        }
// here I need to allocate a new page....
        std::lock_guard<std::mutex> lock(mutexForFreePages);
        Page *w;
        if (mostlyFreePages != NULL)
        {   w = mostlyFreePages;
            mostlyFreePages = mostlyFreePages->pageHeader.chain;
        }
        else
        {   w = freePages;
            freePages = freePages->pageHeader.chain;
        }
        w->pageHeader.chain = borrowPages::get();
        borrowPages::set(w);
        borrowFringe::set(w->pageHeader.fringe);
        borrowLimit::set(w->pageHeader.heaplimit);
        borrowNext::set(0);    // BAD....
    }
}

LispObject borrow_basic_vector(int tag, int type, std::size_t size)
{   std::size_t allocSize = (std::size_t)doubleword_align_up(size);
    if (allocSize > (CSL_PAGE_SIZE - 32))
        aerror1("request for basic vector too big",
                fixnum_of_int(allocSize/CELL-1));
    LispObject r = borrow_n_bytes(allocSize);
    *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *(LispObject *)(r+allocSize-CELL) = 0;
    return (LispObject)(r + tag);
}

LispObject borrow_vector(int tag, int type, std::size_t n)
{   if (n-CELL > VECTOR_CHUNK_BYTES)
    {   std::size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1)/VECTOR_CHUNK_BYTES;
        std::size_t lastSize = (n - CELL) % VECTOR_CHUNK_BYTES;
        if (lastSize == 0) lastSize = VECTOR_CHUNK_BYTES;
        LispObject v =
            borrow_basic_vector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
        for (std::size_t i=0; i<chunks; i++)
        {   std::size_t k = i==chunks-1 ? lastSize : VECTOR_CHUNK_BYTES;
            basic_elt(v, i) = borrow_basic_vector(tag, type, k+CELL);
        }
        return v;
    }
    else return borrow_basic_vector(tag, type, n);
}

// This code sets up an empty page - it is ONLY intended for use at the
// start of a run when there can not be any pinned items present anywhere.
// I put the code here adjacent to the code that allocates from pages so
// that the setup and use can be compared.

static_assert(spareBytes/64 > offsetof(Page, pageHeader.endOfHeader));

void setUpEmptyPage(Page *p)
{   p->pageHeader.fringe = reinterpret_cast<std::uintptr_t>(&p->pageBody.data);
    p->pageHeader.heaplimit = reinterpret_cast<std::uintptr_t>(p) + sizeof(Page);
    p->pageHeader.dirtypage.store(false);
    p->pageHeader.onstarts_present = false;
    p->pageHeader.somePins = false;
// I would like to be able to set the dirty bitmap all zero other than by
// using the store() method one byte at a time. It is also possible that
// when I first allocate a page that page will not be put in the stable
// region of the heap so its dirty map will not be inspected - and if that is
// the case this initialization loop is not actually needed. I will put it
// in for now to be tidy! But another delicacy here is that while the map
// is defined as a vector covering the whole page, the only parts of it that
// will be used are the ones mapping addresses within pageBody.data. So
// I must not clobber memory earlier than that because the first bytes of the
// page are always needed for the pageHeader! Well what I will do is zero
// out everything from the end of pageHeader onwards.
    for (std::size_t i=spareBytes/64; i<2*bytesForMap; i++)
        p->pageBody.pageBitmaps.dirty[i].store(0);
}

void setVariablesFromPage(Page *p)
{
// Set the variable that are used when allocating within the active page.
    uintptr_t pFringe = p->pageHeader.fringe;
    uintptr_t pLimit = p->pageHeader.heaplimit;
// Here I suppose there are no pinned items in the page. I set fringe and
// limit such that on the very first allocation the code will grab a bit of
// memory at gFringe.
    fringe::set(limit[threadId::get()] = limitBis[threadId::get()] =
        gFringe = pFringe);
    gLimit = pLimit;
    gNext = 0;
}

void saveVariablesToPage(Page *p)
{
// Dump global variable values back into a page header. THIS IS NOT USEFUL
// OR CORRECT YET!
    p->pageHeader.fringe = fringe::get();
    p->pageHeader.heaplimit  = limitBis[threadId::get()];
}

// This code allocates a segment by asking the operating system.
// It grabs a block that is aligned to sizeof(Page).
// The collection of segments must be stored in heapSegments[]
// such that their addresses are in ascending order, and in consequence of
// that allocating a new segment may shuffle existing ones in the tables.
// So the index of a segment in the tables may not be viewed as permenant.

void allocateSegment(std::size_t n)
{
// I will round up the size to allocate so it is a multiple of the
// page size. Note that this will be quite a large value!
    n = (n + pageSize - 1) & -pageSize;
    Page *r;
    void *rbase;
// If I have C++17 I can rely on alignment constraints and just allocate
// using new[]
#ifdef __cpp_aligned_new
    r = new Page[n/pageSize];
    my_assert(r != NULL);
    rbase = static_cast<void *>(r);
#else // !__cpp_aligned_new
// On older platforms I need to allocate extra memory and then use std::align
// to get the address within the bigger block that I want.
// In this case I will need to preserve the base of the full block because
// that will be what I will be able to free at the end.
    std::size_t N = n + pageSize - 1;
    rbase = static_cast<void *>(new char[N]);
    my_assert(rbase != NULL);
    void *work = rbase;
    work = std::align(pageSize, n, work, N);
    my_assert(work != NULL);
    r = static_cast<Page *>(work);
#endif // !__cpp_aligned_new
    heapSegment[heapSegmentCount] = r;
    heapSegmentBase[heapSegmentCount] = rbase;
    heapSegmentSize[heapSegmentCount] = n;
    heapSegmentCount++;
// Now I need to arrange that the segments are sorted in the tables
// that record them.
    for (std::size_t i=heapSegmentCount-1; i!=0; i--)
    {   int j = i-1;
        void *h1 = heapSegment[i], *h2 = heapSegment[j];
        if (reinterpret_cast<std::uintptr_t>(h2) < reinterpret_cast<std::uintptr_t>(h1))
            break; // Ordering is OK
// The segment must sink a place in the tables.
        std::swap(heapSegment[i], heapSegment[j]);
        std::swap(heapSegmentBase[i], heapSegmentBase[j]);
        std::swap(heapSegmentSize[i], heapSegmentSize[j]);
    }
// r now refers to a new segment of size n, I want to structure it into
// pages.
//
//  for (std::size_t k=0; k<n; k+=CSL_PAGE_SIZE)
// Go forwards or backwards!
    for (std::size_t k=n; k!=0; k-=CSL_PAGE_SIZE)
    {   Page *p =
            reinterpret_cast<Page *>(
                reinterpret_cast<char *>(r) + k - CSL_PAGE_SIZE);
// Keep a chain of all the pages.
        setUpEmptyPage(p);
        p->pageHeader.pageClass = freePageTag;
        p->pageHeader.chain = freePages;
        freePages = p;
        freePagesCount++;
    }
    std::printf("%" PRIu64 " pages available\n", (std::uint64_t)freePagesCount);
}

std::size_t pages_count = 0;
std::size_t heap_pages_count = 0;
std::size_t vheap_pages_count = 0;
bool garbage_collection_permitted = true;
bool force_verbos = false;

// gc-forcer(a, b) should arrange that a garbage collection is triggered
// when at most A cons-sized units of consing happens or when at most
// B units of space is used for vectors (where vectors include bignums and
// boxed floats). This is intended to be used to trigger garbage collection
// with rather fine control over when it happens to help with debugging
// storage management issues.

bool next_gc_is_hard = false;
std::uint64_t force_cons=0, force_vec = 0;

LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b)
{   if (force_cons != 0 || force_vec != 0)
        trace_printf("Remaining CONS : %" PRIu64 " VEC : %" PRIu64 "\n",
            force_cons, force_vec);
// If you pass a non-fixnum then that leaves the trigger-point unchanged.
    if (is_fixnum(a)) force_cons = (std::uint64_t)sixty_four_bits(a);
    if (is_fixnum(b)) force_vec = (std::uint64_t)sixty_four_bits(b);
    return onevalue(nil);
}

LispObject Lgc_forcer1(LispObject env, LispObject a)
{   return Lgc_forcer(env, a, a);
}

// When a thread exhausts memory (to be more specific, when it fills up
// the nursery page) it must arrange that all but one threads are stopped
// with information about their stacks visible somewhere central and all
// their active values on the stack rather than in machine registers.
// Then garbage collection car occur - or sometimes in simplet cases just
// the allocation of a fresh nursery page.
// To organize this threads need to be suspended. The following are the
// techiques that could potentially apply:
// (1) Busy-waiting on a suitable atomic flag. Hmm busy waiting is generally
//     not a good strategy except for very short periods.
// (2) Arranging that the thread receives a signal that takes it into
//     a signal handler that sleeps, in such a manner that it can be woken
//     from the sleep by a further notification. Well the rules about
//     proper portable use of signals and their handler make this hard to
//     arrange ina way that can be counted on across architectures, and I
//     do not really want to get down to that level of grungy detail and
//     verify it on Windows and with various Linux releases.
// (3) A thread can wait when it attempts to claim a semaphore, so for
//     each thread to be paused each will have to claim its own particular
//     semaphore. There are then two follow-on challenges - one is to
//     detect when every thread has become inactive and hence garbage
//     collection can proceed. The second arises when the threads release
//     their semaphores - somebody else must then lock them all with certainty
//     that that has happened before anybody runs out of memory again. There
//     are potential race conditions there and so further synchronization
//     steps are required. I think that this means that the associated
//     complexity means that the apparent simplicity of each thread "just
//     needing to lock a mutex" is apparent rather then real.
// (4) Somewhat in the style of (3) I can use condition variables, and
//     all the threads that are to pause can wait on the same condition
//     variable with a notify_all() operation releasing then all. This is
//     what I have tried to code here and it still feels messier than I
//     would have liked. But this section of comments is to suggest what else
//     I considered and how I ended up with this plan.

std::jmp_buf *buffer_pointer;

// Each thread will need a thread_number and I need to be able to allocate
// and release such identifying numbers. I will allow for up to 64 threads.

std::mutex threadStartingMutex;
// threadMap will have a zero bit in places that correspond to thread
// numbers that are allocated.

std::uint64_t threadMap = -1;

std::uint64_t threadBit(unsigned int n)
{   return (std::uint64_t)1 << (63-n);
}

unsigned int allocateThreadNumber()
{   my_assert(threadMap != 0); // I need at least one spare.
    unsigned int n = nlz(threadMap);
// Now n is 0 if the top bit is set, 1 for the next etc down to 63 when
// the least bit is the only one se    threadMap &= ~threadBit(n);
    return n;
}

void releaseThreadNumber(unsigned int n)
{   my_assert(n <=63);
    threadMap |= threadBit(n);
}

ThreadStartup::ThreadStartup()
{   std::cout << "ThreadStartup" << std::endl;
    std::lock_guard<std::mutex> lock(mutexForGc);
    threadId::set(allocateThreadNumber());
// The update here is just fine while I am in fact single threaded, but I
// will need to review it when multiple threads can be in play.
    activeThreads.fetch_add(0x00010101);
}

ThreadStartup::~ThreadStartup()
{   std::cout << "~ThreadStartup" << std::endl;
    std::lock_guard<std::mutex> lock(mutexForGc);
    releaseThreadNumber(threadId::get());
    activeThreads.fetch_sub(0x00010101);
}

LispObject *nilSegmentBase, *stackSegmentBase;
LispObject *nilSegment, *stackSegment;


void initHeapSegments(double storeSize)
//
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double rather
// than as an integer so that overflow is not an issue.
{
// I will make the default initial store size around 64M on a 64-bit
// machine and 512M on a 64-bit system. If the user specified a "-K" option
// they can override this, and also the system will tend to allocate more
// space (if it can) when its memory starts to get full.
    std::size_t freeSpace = (SIXTY_FOUR_BIT ? 512 : 64)*1024*1024;
    std::size_t request = (std::size_t)storeSize;
    if (request != 0) freeSpace = 1024*request;
// Now freeSpace is the amount I want to allocate. I will explicitly
// set the variables that are associated with tracking memory allocation
// to keep everything as clear as I can.
    heapSegmentCount = 0;
    freePages = mostlyFreePages = NULL;
    pinsA = pinsC = TAG_FORWARD;
    std::printf("Allocate %" PRIu64 " Kbytes\n", (std::uint64_t)freeSpace/1024);
    allocateSegment(freeSpace);

// There are other bits of memory that I will grab manually for now...
// and at present csl.cpp ALSO sets them up... @@@@
#if defined __cpp_aligned_new && defined HAVE_ALIGNED_ALLOC
    nilSegment = nilSegmentBase =
        reinterpret_cast<LispObject *>(
            std::aligned_alloc(16, NIL_SEGMENT_SIZE));
#else
    nilSegmentBase =
       reinterpret_cast<LispObject *>(std::malloc(NIL_SEGMENT_SIZE+32));
    nilSegment = reinterpret_cast<LispObject *>(
        doubleword_align_up(reinterpret_cast<std::uintptr_t>(nilSegmentBase)));
#endif
    if (nilSegment == NULL) fatal_error(err_no_store);
    nil = (LispObject)((std::uintptr_t)nilSegment + TAG_SYMBOL);
#if defined __cpp_aligned_new&& defined HAVE_ALIGNED_ALLOC
    stackSegment = stackSegmentBase =
        reinterpret_cast<LispObject *>(
            std::aligned_alloc(16, CSL_PAGE_SIZE));
#else
    stackSegmentBase =
        reinterpret_cast<LispObject *>(std::malloc(CSL_PAGE_SIZE+32));
    stackSegment = reinterpret_cast<LispObject *>(
        doubleword_align_up(reinterpret_cast<std::uintptr_t>(stackSegmentBase)));
#endif
    if (stackSegment == NULL) fatal_error(err_no_store);
    stackBase = (LispObject *)stackSegment;
}

void dropHeapSegments(void)
{
#ifdef __cpp_aligned_new
    for (std::size_t i=0; i<heapSegmentCount; i++)
        delete [] static_cast<Page *>(heapSegmentBase[i]);
#else
    for (std::size_t i=0; i<heapSegmentCount; i++)
        delete [] static_cast<char *>(heapSegmentBase[i]);
#endif
    std::free(nilSegmentBase);
    std::free(stackSegmentBase);
}

void drop_heap_segments()
{   dropHeapSegments();
}

// This allocates another page of memory if that is allowed and if it is
// possible. It returns true on success.

bool allocate_more_memory()
{   return false;
//  if ((init_flags & INIT_EXPANDABLE) == 0) return false;
//  void *page = (void *)std::aligned_alloc((size_t)CSL_PAGE_SIZE);
//  if (page == NULL)
//  {   init_flags &= ~INIT_EXPANDABLE;
//      return false;
//  }
//  else
//  {   pages[pagesCount++] = page;
//      return true;
//  }
}

double maxStoreSize = 0.0;

void grab_more_memory(std::size_t npages)
{
// Here I grab more memory (if I am allowed to).
// An initial version here, and one still suitable on machines that will
// have plenty of real memory, will be to defined ok_to_grab_memory(n) as
// 3*n + 2. This expands until the proportion of the heap active at the
// end of garbage collection is less than 1/4.
// If the attempt to grab more memory fails I clear the bit in init_flags
// that allows me to try to expand, so I will not waste time again.  If
// HOLD_BACK_MEMORY was asserted (for machines where grabbing all seemingly
// available memory may cause a crash) I do not try this operation.  The
// aim of keeping the heap less than half full is an heuristic and could be
// adjusted on the basis of experience with this code.
// On systems where it is possible to measure the amount of available
// real memory more sophisticated calculations may be possible.
    if (init_flags & INIT_EXPANDABLE)
    {   std::size_t ideal = MAX_PAGES; //
//@@@@ ok_to_grab_memory(heap_pagesCount + vheap_pagesCount);
        std::size_t more;
        if (ideal > MAX_PAGES) ideal = MAX_PAGES;
        if (maxStoreSize != 0.0)
        {   double pageLimit = maxStoreSize*1024*1024/(double)CSL_PAGE_SIZE;
// Limit memory to (about) the amount the user indicated with --max-mem
            std::size_t plim = (std::size_t)pageLimit;
            if (ideal > plim) ideal = plim;
        }
        if (ideal > pagesCount)
        {   more = ideal - pagesCount;
            while (more > 0)
            {   if (!allocate_more_memory()) break;
                more--;
            }
        }
    }
}

void init_heap_segments(double d)
{   std::cout << "init_heap_segments " << d << std::endl;

// I first impose a minimum of K megabytes, then convert the value so that
// I pass it in kilobytes.
    static const double K = 16384.0; // for an 16 Gbyte default for now!!!
    if (maxStoreSize != 0 && d > maxStoreSize) d = maxStoreSize;
    if (d < K*1024.0*1024.0)
        d = K*1024.0*1024.0;

    initHeapSegments(d/1024.0);
}

std::uintptr_t stackBases[maxThreads];
std::uintptr_t stackFringes[maxThreads];
extern std::atomic<std::uint32_t> threadCount;
std::mutex mutexForGc;
std::mutex mutexForFreePages;
bool gc_started;
std::condition_variable cv_for_gc_idling;
std::condition_variable cv_for_gc_busy;
bool gc_complete;
std::condition_variable cv_for_gc_complete;
// fringe::get() declared in newallocate.h, as is threadId.
std::atomic<std::uintptr_t> limit[maxThreads];
std::uintptr_t              limitBis[maxThreads];
std::uintptr_t              fringeBis[maxThreads];
std::size_t                 request[maxThreads];
LispObject             result[maxThreads];
std::size_t                 gIncrement[maxThreads];
std::atomic<std::uintptr_t> gFringe;
std::uintptr_t              gLimit;
std::uintptr_t              gNext;

#ifdef WIN32
#include <conio.h>
#endif

std::int64_t gc_number = 0;
std::int64_t reclaim_trap_count = -1;
std::uintptr_t reclaim_stack_limit = 0;
std::uint64_t reclaim_trigger_count = 0, reclaim_trigger_target = 0;

//static intptr_t cons_cells, symbol_heads, strings, user_vectors,
//       big_numbers, box_floats, bytestreams, other_mem,
//       litvecs, getvecs;

LispObject Lgc0(LispObject env)
{   return Lgc(env, lisp_true);
}

LispObject Lgc(LispObject env, LispObject a)
{
// If GC is called with a non-nil argument the garbage collection
// will be a full one - otherwise it will be soft and may do hardly
// anything.
#if 0
    return reclaim(nil, "user request",
                   a != nil ? GC_USER_HARD : GC_USER_SOFT, 0);
#endif
    return nil;
}

LispObject Lverbos(LispObject env, LispObject a)
// (verbos 0) or (verbos nil)       silent garbage collection
// (verbos 1) or (verbos t)         standard GC messages
// (verbos 2)                       messages when FASL module loaded
// (verbos 4)                       extra timing info for GC process
// These bits can be added to get combination effects, except that
// "4" has no effect unless "1" is present.
{   int code, old_code = verbos_flag;
    if (a == nil) code = 0;
    else if (is_fixnum(a)) code = (int)int_of_fixnum(a);
    else code = 1;
    miscflags = (miscflags & ~GC_MSG_BITS) | (code & GC_MSG_BITS);
    return onevalue(fixnum_of_int(old_code));
}

bool volatile already_in_gc;
bool volatile interrupt_pending;

// static int stop_after_gc = 0;

// bool force_verbos = false;

// bool garbage_collection_permitted = false;

// static void real_garbage_collector()
// {
// // I lift the real garbage collector to a separate function mainly
// // so that I can set breakpoints on it!
//     for (int i=0; i<=LOG2_VECTOR_CHUNK_BYTES; i++)
//         free_vectors[i] = 0;
//
// }

// LispObject reclaim(LispObject p, const char *why, int stg_class, size_t size)
// {   return p;
// }

static unsigned int MEM=2u*1024u*1024u*1024u;
bool pageFull;

LispObject Lgctest_0(LispObject env)
{   LispObject a = nil;
    for (unsigned int i=0; i<MEM/16u; i++)
    {   a = cons(fixnum_of_int(i), a);
        printf(":"); fflush(stdout);
        if (i % 1000000 == 0)
        {   printf("%u", i);
            LispObject b = a;
            for (unsigned int j=i; j!=(unsigned int)(-1); j--)
            {   if (!is_cons(b)) my_abort();
                if (car(b) != fixnum_of_int(j)) my_abort();
                b = cdr(b);
            }
            if (b != nil) my_abort();
        }
    }
    return nil;
}

LispObject Lgctest_1(LispObject env, LispObject a1)
{   LispObject a = nil, b;
    size_t n = int_of_fixnum(a1);
    for (unsigned int i=0; i<n; i++)
        a = cons(fixnum_of_int(i), a);
    std::cout << "list created" << std::endl;
    b = a;
    for (unsigned int j=n-1; j!=(unsigned int)(-1); j--)
    {   if (!is_cons(b)) goto failing2;
        if (car(b) != fixnum_of_int(j))
        {   std::cout << "Fail3 case with j = " << std::dec << j << std::endl
                << " fixnum_of_int(j) = " << std::hex << fixnum_of_int(j) << std::endl
                << " car(b) = " << car(b) << " which differs" << std::endl
                << " " << (n-1-j) << " items down the list" << std::endl;
            goto failing3; //<<<<<<<<<
        }
        b = cdr(b);
    }
    if (b != nil) goto failing4;
    return nil;
failing2:
    std::cout << "Crashed2 " << std::hex << "b = " << b
        << " car(b) = " << car(b) << std::endl;
    std::cout << "n = " << n << std::endl;
    for (int z=1; z<10; z++)
    {   std::cout << std::dec << (car(b)/16) << " ";
        b = cdr(b);
    }
    std::cout << std::endl;
    return nil;
failing3:
    std::cout << "Crashed3 " << std::hex << "b = " << b
        << " car(b) = " << car(b) << std::endl;
    std::cout << "n = " << n << std::endl;
    for (int z=1; z<10; z++)
    {   std::cout << std::dec << (car(b)/16) << " ";
        b = cdr(b);
    }
    std::cout << std::endl;
    return nil;
failing4:
    std::cout << "Crashed4 " << std::hex << "b = " << b
        << " car(b) = " << car(b) << std::endl;
    std::cout << "n = " << n << std::endl;
    for (int z=1; z<10; z++)
    {   std::cout << std::dec << (car(b)/16) << " ";
        b = cdr(b);
    }
    std::cout << std::endl;
    return nil;
}

LispObject Lgctest_2(LispObject env, LispObject a1, LispObject a2)
{
    return nil;
}

// end of newallocate.cpp