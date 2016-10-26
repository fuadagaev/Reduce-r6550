// bytes1.cpp                        Copyright (C) 1991-2016, Codemist    
//
//
// Bytecode interpreter for Lisp
//

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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

#include "bytes.h"

//
// I can arrange that the option that allows me to count the number of byte
// opcodes that are executed also lets me collect statistics on which
// indicators are most heavily used with PUT and GET.
//

#ifndef NO_BYTECOUNT
//
// RECORD_GET can be set to track all used of PUT, GET, FLAG and FLAGP. This
// may be useful when deciding which tags should be treated specially as
// "fastget" ones, but that decision is not going to be reviwed at all often
// and so I will leave things so that when somebody wants that information
// they need to manually edit this file or use "-DRECORD_GET" in CPPFLAGS
// rather than the expense of recording uses of GET being standard.
//
// #define RECORD_GET 1
#endif

void record_get(LispObject tag, bool found)
{
#ifdef RECORD_GET
    LispObject nil = C_nil;
    LispObject w;
    push(tag);
    w = Lget_hash_2(nil, tag, get_counts);
    pop(tag);
    errexitv();
    if (w == nil)
    {   w = cons_no_gc(fixnum_of_int(0), fixnum_of_int(0));
        push(w);
        Lput_hash(nil, 3, tag, get_counts, w);
        pop(w);
        errexitv();
    }
    if (found) qcar(w) += 0x10;
    else qcdr(w) += 0x10;
#endif
}

//
// Here is a short essay on the interaction between flags and properties.
// It is written because the issue appears to be delicate, especially in the
// face of a scheme that I use to speed things up.
// (a) If you use FLAG, REMFLAG and FLAGP with some indicator then that
//     indicator is known as a flag.
// (b) If you use PUT, REMPROP and GET with an indicator then what you
//     have is a property.
// (c) Providing the names of flags and properties are disjoint no difficulty
//     whatever should arise.
// (d) If you use PLIST to gain direct access to a property list then flags
//     are visible as pairs (tag . t) and properties as (tag . value).
// (e) Using RPLACx operations on the result of PLIST may cause system
//     damage.  It is to be considered illegal. Also changes made that
//     way may not be matched in any accelerating caches that I keep.
// (f) After (FLAG '(id) 'tag) [when id did not previously have any flags
//     or properties] a call (GET 'id 'tag) will return t.
// (g) After (PUT 'id 'tag 'anything) a call (FLAGP 'id 'tag) will return t
//     whatever the value of "anything".  A call (GET 'id 'tag) will return
//     the saved value (which might be nil).  Thus FLAGP can be thought of
//     as a function that tests if a given property is attached to a
//     symbol.
// (h) As a consequence of (g) REMPROP and REMFLAG are really the same
//     operation.
//

#ifndef COMMON

LispObject get(LispObject a, LispObject b)
{   LispObject pl, prev, w, nil = C_nil;
    int n;
//
// In CSL mode plists are structured like association lists, and
// NOT as lists with alternate tags and values.  There is also
// a bitmap that can provide a fast test for the presence of a
// property...
//
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
        w = elt(w, n-1);
        if (w == SPID_NOPROP) w = nil;
#ifdef RECORD_GET
        push(w);
        record_get(b, w != nil);
        pop(w);
        errexit();
#endif
        return onevalue(w);
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
if ((intptr_t)w < 0)
{  fprintf(stderr, "\n@@@ messed up symbol ");
   simple_print(a);
   fprintf(stderr, " GETTING ");
   simple_print(b);
   fprintf(stderr, "\n");
   return aerror("get messed up");
}
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        push(w);
        record_get(b, true);
        pop(w);
        errexit();
#endif
        return onevalue(qcdr(w));
    }
    pl = qcdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        push(w);
        record_get(b, true);
        pop(w);
        errexit();
#endif
        return onevalue(qcdr(w));
    }
    prev = pl;
    pl = qcdr(pl);
    if (pl == prev) return aerror("looped up plist in get");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    for (;;)
    {   w = qcar(pl);
//
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
//
        if (qcar(w) == b)
        {   qcdr(prev) = qcdr(pl);
            qcdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            push(w);
            record_get(b, true);
            pop(w);
            errexit();
#endif
            return onevalue(qcdr(w));
        }
        prev = pl;
        pl = qcdr(pl);
        if (pl == prev) return aerror("looped up plist in get");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
    }
}

static void myabort()
{  ensure_screen();
   abort();
}

LispObject putprop(LispObject a, LispObject b, LispObject c)
{   LispObject nil = C_nil;
    LispObject pl;
    int n;
    if (!symbolp(a)) return c;
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   pl = qfastgets(a);
        if (pl == nil)
        {   push3(a, b, c);
            pl = getvector_init(CELL+CELL*fastget_size, SPID_NOPROP);
            pop3(c, b, a);
            errexit();
            qfastgets(a) = pl;
        }
        elt(pl, n-1) = c;
        return c;            // NB the property is NOT on the plist
    }
    pl = qplist(a);
    while (pl != nil)
    {   LispObject w = qcar(pl);
if ((intptr_t)w < 0)
{  fprintf(stderr, "\n@@@ putprop mess for symbol %p<", (void *)a);
   simple_print(a);
   fprintf(stderr, "> property %p<", (void *)b);
   simple_print(b);
   fprintf(stderr, ">\n");
   myabort();
}
        if (qcar(w) == b)
        {   qcdr(w) = c;
            return c;
        }
        else pl = qcdr(pl);
    }
    stackcheck3(0, a, b, c);
    nil = C_nil;
    push2(a, c);
    b = acons(b, c, qplist(a));
    pop2(c, a);
    errexit();
    qplist(a) = b;
    return c;
}

static LispObject remprop(LispObject a, LispObject b)
{   LispObject pl, prevp;
    LispObject nil = C_nil;
    int n;
    if (!symbolp(a)) return nil;
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   pl = qfastgets(a);
        if (pl != nil) elt(pl, n-1) = SPID_NOPROP;
        return nil;
    }
    prevp = nil;
    pl = qplist(a);
    while (pl != nil)
    {   LispObject w = qcar(pl);
        if (qcar(w) == b)
        {   pl = qcdr(pl);
            if (prevp == nil) qplist(a) = pl;
            else qcdr(prevp) = pl;
            return qcdr(w);
        }
        prevp = pl;
        pl = qcdr(prevp);
        if (pl == prevp) return aerror("looped up plist in remprop");
    }
    return nil;
}

LispObject get_0(LispObject a, int n)
{   LispObject w, nil = C_nil;
    if (!symbolp(a)) return onevalue(nil);
    {   if ((w = qfastgets(a)) == nil)
            return onevalue(nil);
        w = elt(w, n);
        if (w == SPID_NOPROP) w = nil;
        return onevalue(w);
    }
}

#else // in a COMMON world I have to use flat plists

LispObject get(LispObject a, LispObject b, LispObject c)
{   LispObject nil = C_nil;
    LispObject pl;
    int n;
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return c;
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((pl = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            push(c);
            record_get(b, false);
            pop(c);
            errexit();
#endif
            return onevalue(c);
        }
        pl = elt(pl, n-1);
        if (pl == SPID_NOPROP)
        {
#ifdef RECORD_GET
            push(c);
            record_get(b, false);
            pop(c);
            errexit();
#endif
            return onevalue(c);
        }
#ifdef RECORD_GET
        push(pl);
        record_get(b, true);
        pop(pl);
        errexit();
#endif
        return onevalue(pl);
    }
    pl = qplist(a);
    while (pl != nil)
    {   if (qcar(pl) == b)
        {
#ifdef RECORD_GET
            push(pl);
            record_get(b, true);
            pop(pl);
            errexit();
#endif
            return qcar(qcdr(pl));
        }
        else pl = qcdr(qcdr(pl));
    }
#ifdef RECORD_GET
    record_get(b, false);
    errexit();
#endif
    return c;
}

LispObject putprop(LispObject a, LispObject b, LispObject c)
{   LispObject nil = C_nil;
    LispObject pl;
    int n;
    if (!symbolp(a)) return c;
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   pl = qfastgets(a);
        if (pl == nil)
        {   push3(a, b, c);
            pl = getvector_init(CELL+CELL*fastget_size, SPID_NOPROP);
            pop3(c, b, a);
            errexit();
            qfastgets(a) = pl;
        }
        elt(pl, n-1) = c;
        return c;            // NB the property in NOT on the plist
    }
    pl = qplist(a);
    while (pl != nil)
    {   if (qcar(pl) == b)
        {   pl = qcdr(pl);
            qcar(pl) = c;
            return c;
        }
        else pl = qcdr(qcdr(pl));
    }
    stackcheck3(0, a, b, c);
    nil = C_nil;
    push2(a, c);
    b = list2star(b, c, qplist(a));
    pop2(c, a);
    errexit();
    qplist(a) = b;
    return c;
}

static LispObject remprop(LispObject a, LispObject b)
{   LispObject nil = C_nil;
    LispObject pl, prevp = nil;
    int n;
    if (!symbolp(a)) return nil;
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   pl = qfastgets(a);
        if (pl != nil) elt(pl, n-1) = SPID_NOPROP;
        return nil;
    }
    pl = qplist(a);
    while (pl != nil)
    {   if (qcar(pl) == b)
        {   LispObject v = qcdr(pl);
            pl = qcdr(v);
            if (prevp == nil) qplist(a) = pl;
            else qcdr(prevp) = pl;
            return lisp_true;
        }
        prevp = qcdr(pl);
        pl = qcdr(prevp);
        if (pl == prevp) return aerror("looped up plist in remprop (1)");
    }
    return nil;
}

#endif // end of property list stuff

#ifndef COMMON

LispObject Lget(LispObject nil, LispObject a, LispObject b)
{   LispObject pl, prev, w;
    int n;
//
// In CSL mode plists are structured like association lists, and
// NOT as lists with alternate tags and values.  There is also
// a bitmap that can provide a fast test for the presence of a
// property...
//
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
        w = elt(w, n-1);
        if (w == SPID_NOPROP) w = nil;
#ifdef RECORD_GET
        push(w);
        record_get(b, w != nil);
        pop(w);
        errexit();
#endif
        return onevalue(w);
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        push(w);
        record_get(b, true);
        pop(w);
        errexit();
#endif
        return onevalue(qcdr(w));
    }
    pl = qcdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        push(w);
        record_get(b, true);
        pop(w);
        errexit();
#endif
        return onevalue(qcdr(w));
    }
    prev = pl;
    pl = qcdr(pl);
    if (pl == prev) return aerror("looped up plist in Lget");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    for (;;)
    {   w = qcar(pl);
//
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
//
        if (qcar(w) == b)
        {   qcdr(prev) = qcdr(pl);
            qcdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            push(w);
            record_get(b, true);
            pop(w);
            errexit();
#endif
            return onevalue(qcdr(w));
        }
        prev = pl;
        pl = qcdr(pl);
        if (pl == prev) return aerror("looped up plist in Lget");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
    }
}

#else

LispObject Lget_3(LispObject, int nargs, ...)
{   va_list aa;
    LispObject a, b, c;
    if (nargs != 3) return aerror("get");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    return onevalue(get(a, b, c));
}

LispObject Lget(LispObject nil, LispObject a, LispObject b)
{   return onevalue(get(a, b, nil));
}

#endif

LispObject Lputprop(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject a, b, c;
    argcheck(nargs, 3, "put");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    a = putprop(a, b, c);
    errexit();
    return onevalue(a);
}

#ifdef COMMON

LispObject Lflagp(LispObject nil, LispObject a, LispObject b)
{   a = get(a, b, unset_var);
    errexit();
    return onevalue(a == unset_var ? nil : lisp_true);
}

LispObject Lflagpcar(LispObject nil,
                     LispObject a, LispObject b)
{
// Fairly heavily used by Reduce test file - hence in here
    if (!consp(a)) return onevalue(nil);
    a = qcar(a);
    a = get(a, b, unset_var);
    errexit();
    return onevalue(a == unset_var ? nil : lisp_true);
}

LispObject Lflag(LispObject nil,
                 LispObject a, LispObject b)
{   while (consp(a))
    {   LispObject v = qcar(a);
        a = qcdr(a);
        if (!symbolp(v)) continue;
        push2(a, b);
        putprop(v, b, lisp_true);
        pop2(b, a);
        errexit();
    }
    return onevalue(nil);
}

LispObject Lremflag(LispObject nil,
                    LispObject a, LispObject b)
{   while (consp(a))
    {   LispObject v = qcar(a);
        a = qcdr(a);
        if (!symbolp(v)) continue;
        push2(a, b);
        remprop(v, b);
        pop2(b, a);
        errexit();
    }
    return onevalue(nil);
}

#else

LispObject Lflagp(LispObject nil, LispObject a, LispObject b)
{   LispObject pl, prev, w;
    int n;
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
        w = elt(w, n-1);
        if (w == SPID_NOPROP)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return onevalue(lisp_true);
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return onevalue(lisp_true);
    }
    pl = qcdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return onevalue(lisp_true);
    }
    prev = pl;
    pl = qcdr(pl);
    if (pl == prev) return aerror("looped up plist in Lflagp");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    for (;;)
    {   w = qcar(pl);
//
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
//
        if (qcar(w) == b)
        {   qcdr(prev) = qcdr(pl);
            qcdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            record_get(b, true);
            errexit();
#endif
            return onevalue(lisp_true);
        }
        prev = pl;
        pl = qcdr(pl);
        if (pl == prev) return aerror("looped up plist in Lflagp");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
    }
}

LispObject Lflagpcar(LispObject nil, LispObject a, LispObject b)
{   LispObject pl, prev, w;
    int n;
// Fairly heavily used by Reduce test file - hence in here
    if (a != nil)
    {   if (!consp(a))
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
        a = qcar(a);
        if (!symbolp(a))
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
        w = elt(w, n-1);
        if (w == SPID_NOPROP)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return onevalue(lisp_true);
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return onevalue(lisp_true);
    }
    pl = qcdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return onevalue(lisp_true);
    }
    prev = pl;
    pl = qcdr(pl);
    if (pl == prev) return aerror("looped up plist in flagpcar");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return onevalue(nil);
    }
    for (;;)
    {   w = qcar(pl);
//
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
//
        if (qcar(w) == b)
        {   qcdr(prev) = qcdr(pl);
            qcdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            record_get(b, true);
            errexit();
#endif
            return onevalue(lisp_true);
        }
        prev = pl;
        pl = qcdr(pl);
        if (pl == prev) return aerror("looped up plist in flagpcar");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return onevalue(nil);
        }
    }
}

LispObject Lflag(LispObject nil, LispObject a, LispObject b)
{   int n = 0;
    if (symbolp(b)) n = header_fastget(qheader(b));
    while (consp(a))
    {   LispObject v = qcar(a), pl;
        a = qcdr(a);
        if (!symbolp(v)) continue;
//
// I store FLAGS just as if they were PROPERTIES that have the value
// T, so after (flag '(a b c) 'd) if anybody goes (get 'a 'd) they get back
// the value T.
//
        if (n)
        {   pl = qfastgets(v);
            if (pl == nil)
            {   push2(v, b);
                pl = getvector_init(CELL+CELL*fastget_size, SPID_NOPROP);
                pop2(b, v);
                errexit();
                qfastgets(v) = pl;
            }
            elt(pl, n-1) = lisp_true;
            continue;
        }
        push2(a, b);
        pl = qplist(v);
        while (pl != nil)
        {   LispObject w = qcar(pl);
            if (qcar(w) == b)
            {   qcdr(w) = lisp_true;
                goto already_flagged;
            }
            else pl = qcdr(pl);
        }
        push(v);
        b = acons(b, lisp_true, qplist(v));
        errexitn(3);
        pop(v);
        qplist(v) = b;
    already_flagged:
        pop2(b, a);
    }
    return onevalue(nil);
}

LispObject Lremflag(LispObject nil, LispObject a, LispObject b)
{   int n = 0;
    if (symbolp(b)) n = header_fastget(qheader(b));
    while (consp(a))
    {   LispObject pl, prevp, v = qcar(a);
        a = qcdr(a);
        if (!symbolp(v)) continue;
        if (n)
        {   pl = qfastgets(v);
            if (pl != nil) elt(pl, n-1) = SPID_NOPROP;
            continue;
        }
        prevp = nil;
        pl = qplist(v);
        while (pl != nil)
        {   LispObject w = qcar(pl);
            if (qcar(w) == b)
            {   pl = qcdr(pl);
                if (prevp == nil) qplist(v) = pl;
                else qcdr(prevp) = pl;
                break;
            }
            prevp = pl;
            pl = qcdr(prevp);
            if (pl == prevp) return aerror("looped up plist in remflag");
        }
    }
    return onevalue(nil);
}

#endif

LispObject Lremprop(LispObject, LispObject a, LispObject b)
{   return onevalue(remprop(a, b));
}


LispObject Lplist(LispObject nil, LispObject a)
{   LispObject r;
    int i;
    if (!symbolp(a)) return aerror1("plist", a);
    r = qplist(a);
    a = qfastgets(a);
    if (a == nil) return onevalue(r);
    for (i=0; i<fastget_size; i++)
    {   LispObject w = elt(a, i);
        if (w != SPID_NOPROP)
        {   push(a);
#ifdef COMMON
            r = list2star(elt(fastget_names, i), w, r);
#else
            r = acons(elt(fastget_names, i), w, r);
#endif
            pop(a);
            errexit();
        }
    }
    return onevalue(r);
}

#ifndef NO_BYTECOUNT
//
// Unless NO_BYTECOUNT is set I keep two sorts of counts - first
// ones that show how many bytecodes are executed in each separate
// piece of code that the user runs.  These can be inspected by
// calling MAPSTORE.  Then ones that show (overall) which particular
// byte opcodes are most heavily used.  This information is displayed
// when you call BYTECOUNTS.
//
extern int profile_count_mode;

#include "opnames.cpp"

static uint64_t total = 0, frequencies[256];

#endif

LispObject bytecounts(LispObject nil, int nargs, ...)
{
#if !defined NO_BYTECOUNT || defined RECORD_GET
    int32_t i;
#endif
#ifdef RECORD_GET
    int32_t size;
    LispObject v;
    double tot;
#endif
    argcheck(nargs, 0, "bytecounts");
#ifdef NO_BYTECOUNT
    stdout_printf("bytecode statistics not available\n");
#else
    stdout_printf("\nFrequencies of each bytecode (%ldM total)",
                  (int)(total/1000000));
    if (total == 0) total = 1;
    for (i=0; i<256; i++)
    {   if ((i & 3) == 0) stdout_printf("\n");
        stdout_printf("%-9.9s%7.4f  ",
                      opnames[i],
                      100.0*(double)frequencies[i]/(double)total);
    }
    stdout_printf("\n");
#endif

#ifdef RECORD_GET
    v = elt(get_counts, 4);
    if (v == nil) return onevalue(nil);
    size = length_of_header(vechdr(v));
    size = (size - CELL)/CELL;
    term_printf("\n %%SCORE      TOTAL   NOTFOUND  INDICATOR-NAME\n");
    tot = 0.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(qcar(val)),
                            no  = int_of_fixnum(qcdr(val));
        tot += (double)(yes+2*no);
    }
    tot /= 100.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(qcar(val)),
                            no  = int_of_fixnum(qcdr(val));
        stdout_printf("%7.2f %10d %10d  ", (double)(yes+2*no)/tot, yes+no, no);
        errexit();
        loop_print_stdout(key);
        stdout_printf("\n");
    }

    v = Lmkhash(nil, 3, fixnum_of_int(5), fixnum_of_int(0), nil);
    errexit();
    get_counts = v;
#endif
    return onevalue(nil);
}

LispObject bytecounts1(LispObject nil, LispObject a)
{
#ifdef RECORD_GET
    int32_t i, size;
    LispObject v;
    double tot;
#endif
#ifdef NO_BYTECOUNT
    stdout_printf("bytecode statistics not available\n");
#endif

#ifdef RECORD_GET
    v = elt(get_counts, 4);
    if (v == nil) return onevalue(nil);
    size = length_of_header(vechdr(v));
    size = (size - CELL)/CELL;
    tot = 0.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(qcar(val)),
                            no  = int_of_fixnum(qcdr(val));
        tot += (double)(yes+2*no);
    }
    tot /= 100.0;
    stdout_printf("\n(\n");
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(qcar(val)),
                            no  = int_of_fixnum(qcdr(val));
        stdout_printf("(%7.2f ", (double)(yes+2*no)/tot);
        errexit();
        loop_print_stdout(key);
        stdout_printf(")\n");
    }
    stdout_printf("\n)\n");

    v = Lmkhash(nil, 3, fixnum_of_int(5), fixnum_of_int(0), nil);
    errexit();
    get_counts = v;
#endif

    return onevalue(nil);
}

LispObject *C_stack;

//
// Throughout most of the system I use the name "stack" as a synonym for
// the external variable "C_stack", but in the main byte-code interpreter
// loop I disable that mapping and use a register variable as stack
// pointer, updating the extern value from time to time as necessary.
// pointer, updating the extern value from time to time as necessary. It
// may in fact be that current good optimising compilers make this hackery
// unnecessary...
//

#undef stack

static int CSLerrcode;

static LispObject *do_freebind(LispObject bvec, LispObject *stack)
{   int32_t n, k;
    n = length_of_header(vechdr(bvec));
    for (k=CELL; k<n; k+=CELL)
    {   LispObject v = *(LispObject *)((intptr_t)bvec + k - TAG_VECTOR);
        push(qvalue(v));
        qvalue(v) = C_nil;
    }
//
// SPID_FBIND is a value that can NEVER occur elsewhere in the Lisp system,
// and so it unambiguously marks a block of fluid bindings on that stack.
//
    push2(bvec, (LispObject)SPID_FBIND);
    return stack;
}

static LispObject *do_freerstr(LispObject *stack)
{   LispObject bv;
    size_t n;
    popv(1);
    pop(bv);
    n = length_of_header(vechdr(bv));
    while (n>CELL)
    {   LispObject v = *(LispObject *)((intptr_t)bv + n - (CELL + TAG_VECTOR));
        n -= CELL;
        pop(qvalue(v));
    }
    return stack;
}

//
// If OUT_OF_LINE is defined than various fragments of code are written
// as subroutines called from the main body of bytestream_interpret.
// This may hurt speed a little, but reduces the size of the one huge
// function in this file, and may be useful either when memory is at
// a huge premium (ugh) or [more plausibly] when C compilers get very
// unhappy with the bulk of the code when all written out in place.
// The default case I leave (with OUT_OF_LINE undefined) is the one that
// prefers a few percent speed-up to a fraction of a percent space
// saving.
//

#ifdef OUT_OF_LINE

static LispObject poll_jump_back(LispObject *stack, LispObject A_reg)
{   LispObject nil = C_nil;
    if (--countdown < 0) deal_with_tick();
    C_stack = stack;
    if (stack >= stacklimit)
    {   A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return SPID_ERROR;
    }
    return A_reg;
}

#endif

#ifdef COMMON

static LispObject *do_pvbind(LispObject vals, LispObject vars,
                             LispObject *stack)
{   LispObject val, var, nil = C_nil;
    push4(nil, SPID_PVBIND, vars, vals);
    while (consp(vars))
    {   var = qcar(vars);
        vars = qcdr(vars);
        if (!symbolp(var) || var == nil) continue;
        push(vars);
        C_stack = stack;
        var = acons(var, qvalue(var), stack[-4]);
        stack = C_stack;
        nil = C_nil;
        if (exception_pending())
        {   popv(2);
            return stack;
        }
        stack[-4] = var;
        pop(vars);
    }
    pop2(vals, vars);
    while (consp(vars))
    {   if (consp(vals)) val = qcar(vals), vals = qcdr(vals);
        else val = unset_var;
        var = qcar(vars);
        if (symbolp(var) && var != nil) qvalue(var) = val;
        vars = qcdr(vars);
    }
    return stack;
}

static LispObject *do_pvrestore(LispObject *stack)
{   LispObject w, nil = C_nil;
    popv(1);
    pop(w);
    while (w != nil)
    {   LispObject q = qcar(w);
        qvalue(qcar(q)) = qcdr(q);
        w = qcdr(w);
    }
    return stack;
}

#endif

static LispObject encapsulate_sp(LispObject *sp)
//
// Creates a boxed up representation of a pointer into the stack.
//
{   LispObject w = getvector(TAG_VECTOR, TYPE_SP, 2*CELL);
    LispObject nil;
    errexit();
    elt(w, 0) = (LispObject)sp;
    return w;
}

static void trace_print_0(LispObject name, LispObject *stack)
{   freshline_trace();
    trace_printf("Tail calling ");
    loop_print_trace(name);
    trace_printf(" (no args) from ");
    loop_print_trace(*stack);
    trace_printf("\n");
}

static void trace_print_1(LispObject name, LispObject *stack)
{   freshline_trace();
    trace_printf("Tail calling ");
    loop_print_trace(name);
    trace_printf(" (1 arg) from ");
    loop_print_trace(*stack);
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(stack[-3]);
    trace_printf("\n");
}

static void trace_print_2(LispObject name, LispObject *stack)
{   freshline_trace();
    trace_printf("Tail calling ");
    loop_print_trace(name);
    trace_printf(" (2 args) from ");
    loop_print_trace(*stack);
    trace_printf("\n");
    trace_printf("Arg1: ");   loop_print_trace(stack[-4]);
    trace_printf("\nArg2: "); loop_print_trace(stack[-3]);
    trace_printf("\n");
}

static void trace_print_3(LispObject name, LispObject *stack)
{   freshline_trace();
    trace_printf("Tail calling ");
    loop_print_trace(name);
    trace_printf(" (3 args) from ");
    loop_print_trace(*stack);
    trace_printf("\n");
    trace_printf("Arg1: ");   loop_print_trace(stack[-5]);
    trace_printf("\nArg2: "); loop_print_trace(stack[-4]);
    trace_printf("\nArg3: "); loop_print_trace(stack[-3]);
    trace_printf("\n");
}

// Over garbage collection codevec may be relocated, so I keep an offset
// (pc) relative to it so I track where ppc should point.

#define save_pc() pc = (unsigned int)(ppc - (unsigned char *)codevec)

#define restore_pc() ppc = (unsigned char *)codevec + pc

#ifdef MEMORY_TRACE
#define next_byte (cmemory_reference((intptr_t)ppc), *ppc++)
#else
#define next_byte (*ppc++)
#endif

#define most_recent_byte (*(ppc-1))

#ifdef CHECK_STACK
char *native_stack = NULL, *native_stack_base = NULL;
#endif

//
// Before calling apply() or the function in the qfn1, qfn2 or qfnn cell
// of anything I will set this variable to refer to a string (which may be
// up to 15 characters long) naming the [bytecoded] function responsible for
// the call. Sometimes the variable may end up NULL which should be taken
// to indicate that I do not know who the caller was. For instance I set
// it to NULL as bytestream_interpret exits (and the string that would be
// used is popped form the stack).
//
const char *name_of_caller = NULL;

extern LispObject bytestream_interpret1(unsigned char *ppc, LispObject lit,
                                        LispObject *entry_stack);
#ifdef CHECK_STACK
static int maxnest = 0;
#endif

LispObject bytestream_interpret(unsigned char *ppc, LispObject lit,
                                LispObject *entry_stack)
#ifdef CHECK_STACK
{
//
// Here I have a wrapper function that is used to help me track
// ultra deep recursions! This is only used when CHECK_STACK had been
// defined at compile-time, and I view any performance consequences as
// utterly unimportant provided it sometimes allows me to discover
// what is leading to uncontrolled recursion. This must not trigger a GC
// until it calls bytestread_interpret1.
//
    LispObject w, nil = C_nil;
    int len = 0;
    call_stack = cons_no_gc(elt(lit, 0), call_stack);
    for (w = call_stack; w != nil; w = qcdr(w)) len++;
    if (len > maxnest+(maxnest/2)+1)
    {   maxnest = len;
        trace_printf("\n+++++ bytecode nesting depth %d observed\n", maxnest);
        w = call_stack;
        while (w != nil)
        {   *++C_stack = w;
            prin_to_trace(qcar(w)); // should be a symbol
            nil = C_nil;
            if (exception_pending()) flip_exception();
            w = *C_stack--;
            w = qcdr(w);
            trace_printf("\n");
        }
    }
    if (len > 20000) flip_exception();
    else w = bytestream_interpret1(ppc, lit, entry_stack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        call_stack = qcdr(call_stack);
        flip_exception();
    }
    else call_stack = qcdr(call_stack);
    return w;
}

LispObject bytestream_interpret1(unsigned char *ppc, LispObject lit,
                                 LispObject *entry_stack)
#endif // CHECK_STACK
{
//
// entry_stack may be its "1" bit set if I am to be "noisy" whenever I
// assign to a special/global variable.
//
    LispObject A_reg;
    LispObject nil = C_nil;
    LispObject *stack = C_stack;
    LispObject r1, r2, r3;
    one_args *f1;
    two_args *f2;
    n_args *f345;
    unsigned int fname, pc, w;
    int32_t n, k;
    unsigned char *xppc;
//
// I declare all the other variables I need here up at the top of the function
// since at least on some C compilers putting the declarations more locally
// seems to be unexpectedly costly.  In some cases moving the stack pointer
// may be a pain, in others code like
//   { int x; ...} { int x; ... } { int x;  ... }
// end up allocating three stack locations (one for each instance of x) and
// hence makes this function overall have much to big a stack frame.
//
#if defined DEBUG || !defined NO_BYTECOUNT
//
// ffname will be the first 31 characters of the name of the function
// that is being interpreted.
// This is jolly useful if one is in a debugger trying to understand what
// has been going on! Note that the executable code here does not use this
// variable at all: it is JUST so that I have a simple string variable
// that a symbolic debugger can inspect to find my function name without
// me having to mess about too much. I make this "volatile" in the hope that
// that will prevent any compiler from optimising it out of existence!
// If your function names are very long this may not give you all the info
// you would like.
//
    LispObject volatile ffsym = elt(lit, 0);
    char volatile ffname[32];
    memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), sizeof(ffname));
    size_t fflength =
        (size_t)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
    ffname[fflength] = 0;
    if (*ffname == 0)
    {   fprintf(stderr, "\nffname empty - system corrupted?\n");
        fflush(stderr);
        ensure_screen();
        *((int *)(-1)) = 0x55555555; // Collapse!
        abort();
    }
    debug_record((const char *)ffname);
    (void)ffsym;   // Not used by the code but may be useful under a debugger
    debug_assert(1);
#endif
#ifdef CHECK_STACK
    {   char *my_stack = (char *)&my_stack;
        if (native_stack == NULL) native_stack = native_stack_base = my_stack;
        else if (my_stack + 10000 < native_stack)
        {   native_stack = my_stack;
            LispObject ffsym = elt(lit, 0);
            trace_printf("\nFunction %s stack depth %d\n",
                         &celt(qpname(ffsym), 0),
                         native_stack_base - my_stack);
        }
    }
#endif

//
// The byte-stream interpreter here uses the lisp stack and two
// special registers, called A, and B which act as a mini stack.
//

#ifndef NO_BYTECOUNT
//
// If I am collecting bytecounts I am in the slow version of REDUCE
// with everything bytecoded rather than turned into C. I will view this as
// a debugging as well as a bootstrapping environment, so I will keep more
// information about the call stack.
//
#ifdef ACN
// ... except that I will only go the whole hog if one defines ACN
    {   codevec = ((LispObject)ppc & ~(LispObject)3) + (TAG_VECTOR-CELL);
        uintptr_t w = (uintptr_t)ppc - codevec;
        push2(codevec, lit);
        C_stack = stack;
        callstack = cons(elt(lit, 0), callstack);
        stack = C_stack;
        pop2(lit, codevec);
        ppc = (unsigned char *)(codevec + w);
        C_stack = stack;
        errexit();
    }
#endif
#endif
    litvec = lit;
#ifndef NO_BYTECOUNT
    qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
    // Attribute 30-bytecode overhead to entry sequence
#endif
//
// The next lines are used to allow for functions with > 3 args, and for
// &optional and &rest cases. Some of these need one or two bytes at the
// start of the code-vector to indicate just how many arguments are
// expected. In such cases the byte pointer ppc points to the first
// byte of genuine executable stuff just beyond those prelude bytes. Hence
// (ppc & ~3) will point at a word-aligned starting point for bytes
// and ((ppc & ~3) + (TAG_VECTOR-CELL)) will be a proper LispObject value
// that stands for the BPS object. Well that bit of arithmetic will need
// some casts to make it valid, but writing if plainly is perhaps clearest.
// I could in fact cope with up to 7 prefix bytes, but at present I only
// have use for 0, 1 or 2.
//
    codevec = ((LispObject)ppc & ~(LispObject)3) + (TAG_VECTOR-CELL);
//
// I am careful to reload stack from C_stack after any
// function call, to allow that the garbage collector may relocate the
// whole stack region.  But at present I do not protect entry_stack in
// this way, so if the garbage collector moves my stack and subsequently
// I take an error exit I will get in a big mess.  At present the garbage
// collector is not that enthusiastic, so the problem will not arise. If
// I was sure it NEVER would I could avoid a few cases of "stack = C_stack"
// here and speed things up by some utterly insignificant amount.
//
    A_reg = nil;
#ifdef CHECK_STACK
    if ((char *)fringe <= (char *)heaplimit)
    {   save_pc();
        C_stack = stack;
        A_reg = cons_gc_test(A_reg);
        nil = C_nil;
        if (exception_pending()) goto call_error_exit;
        stack = C_stack;
        restore_pc();
    }

#ifdef DEBUG
    if (check_stack((char *)&ffname[0],__LINE__))
    {   name_of_caller = NULL;
        err_printf("\n+++ stack overflow\n");
        goto pop_stack_and_exit;
    }
#else
    if (check_stack("bytecode_interpreter",__LINE__))
    {   name_of_caller = NULL;
        err_printf("\n+++ stack overflow\n");
        goto pop_stack_and_exit;
    }
#endif
#else
    {   char *p = (char *)&p;
        if (p < C_stack_limit)
        {   name_of_caller = NULL;
            err_printf("\n+++ stack overflow\n");
            goto pop_stack_and_exit;
        }
    }
#endif
    for (;;)
    {
//      HANDLE_BLIP;
#ifndef NO_BYTECOUNT
        if (!profile_count_mode) qcount(elt(litvec, 0)) += 1;
        total++;
        frequencies[*ppc]++;
#endif
//
// With at least some compilers (eg Watcom) if I cast the value obtained here
// to something other than unsigned char I get worse code, because the fact
// that the switch range is exactly 0-255 and my control value must be in that
// range gets lost.
//
        switch (next_byte)
        {
//
// I give labels for all 256 possible cases here so that a sufficiently
// clever compiler can understand that there is no "default" that can possibly
// be activated.
//
            case OP_SPARE:
            default:
//
// Here I have an unrecognised opcode - the result of a compiler error
//
                err_printf("\nUnrecognized opcode byte %x\n", *(ppc-1));
                aerror("compiler failure");
                nil = C_nil;
                C_stack = stack;
                goto error_exit;

            case OP_ONEVALUE:
                exit_count = 1;
                continue;

            case OP_LOC0EXIT:
                A_reg = stack[0];
                C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
                name_of_caller = NULL;
#endif
                return A_reg;


            case OP_LOC1EXIT:
                A_reg = stack[-1];
                C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
                name_of_caller = NULL;
#endif
                return A_reg;


            case OP_LOC2EXIT:
                A_reg = stack[-2];
                C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
                name_of_caller = NULL;
#endif
                return A_reg;

            case OP_NILEXIT:
                C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
                name_of_caller = NULL;
#endif
                return onevalue(nil);

            case OP_FREEBIND:
                stack = do_freebind(elt(litvec, next_byte), stack);
                continue;

            case OP_FREERSTR:
                stack = do_freerstr(stack);
                continue;

#ifdef COMMON
            case OP_PVBIND:
                save_pc();
                stack = do_pvbind(A_reg, B_reg, stack);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                restore_pc();
                continue;

            case OP_PVRESTORE:
                stack = do_pvrestore(stack);
                continue;
#endif

            case OP_STOREFREE:
                if ((1 & (int)(intptr_t)entry_stack) != 0)
                {   push4(codevec, litvec, B_reg, A_reg);
                    save_pc();
                    C_stack = stack;
                    freshline_trace();
                    trace_printf("+++ Inside ");
                    loop_print_trace(elt(litvec, 0));
                    trace_printf(": ");
                    loop_print_trace(elt(litvec, *ppc));
                    trace_printf(" := ");
                    loop_print_trace(C_stack[0]);
                    trace_printf("\n");
                    stack = C_stack;
                    pop4(A_reg, B_reg, litvec, codevec);
                    restore_pc();
                }
                qvalue(elt(litvec, next_byte)) = A_reg;  // store into special var
                continue;

            case OP_STOREFREE1:
                if ((1 & (int)(intptr_t)entry_stack) != 0)
                {   push4(codevec, litvec, B_reg, A_reg);
                    save_pc();
                    C_stack = stack;
                    freshline_trace();
                    trace_printf("+++ Inside ");
                    loop_print_trace(elt(litvec, 0));
                    trace_printf(": ");
                    loop_print_trace(elt(litvec, 1));
                    trace_printf(" := ");
                    loop_print_trace(C_stack[0]);
                    trace_printf("\n");
                    stack = C_stack;
                    pop4(A_reg, B_reg, litvec, codevec);
                    restore_pc();
                }
                qvalue(elt(litvec, 1)) = A_reg;
                continue;

            case OP_STOREFREE2:
                if ((1 & (int)(intptr_t)entry_stack) != 0)
                {   push4(codevec, litvec, B_reg, A_reg);
                    save_pc();
                    C_stack = stack;
                    freshline_trace();
                    trace_printf("+++ Inside ");
                    loop_print_trace(elt(litvec, 0));
                    trace_printf(": ");
                    loop_print_trace(elt(litvec, 2));
                    trace_printf(" := ");
                    loop_print_trace(C_stack[0]);
                    trace_printf("\n");
                    stack = C_stack;
                    pop4(A_reg, B_reg, litvec, codevec);
                    restore_pc();
                }
                qvalue(elt(litvec, 2)) = A_reg;
                continue;

            case OP_STOREFREE3:
                if ((1 & (int)(intptr_t)entry_stack) != 0)
                {   push4(codevec, litvec, B_reg, A_reg);
                    save_pc();
                    C_stack = stack;
                    freshline_trace();
                    trace_printf("+++ Inside ");
                    loop_print_trace(elt(litvec, 0));
                    trace_printf(": ");
                    loop_print_trace(elt(litvec, 3));
                    trace_printf(" := ");
                    loop_print_trace(C_stack[0]);
                    trace_printf("\n");
                    stack = C_stack;
                    pop4(A_reg, B_reg, litvec, codevec);
                    restore_pc();
                }
                qvalue(elt(litvec, 3)) = A_reg;
                continue;

            case OP_PUSHNILS:
                n = next_byte;
                for (k=0; k<n; k++) push(nil);
                continue;

            case OP_VNIL:
                B_reg = A_reg;
                A_reg = nil;
                continue;

            case OP_SWOP:
                r1 = B_reg;
                B_reg = A_reg;
                A_reg = r1;
                continue;

            case OP_NCONS:                          // A_reg = cons(A_reg, nil);
#ifndef OUT_OF_LINE
                // NB preserves B register
                r1 = (LispObject)((char *)fringe - sizeof(Cons_Cell));
                qcar(r1) = A_reg;
                qcdr(r1) = nil;
                fringe = r1;
                if ((char *)r1 <= (char *)heaplimit)
                {   push(B_reg);
                    save_pc();
                    C_stack = stack;
                    A_reg = reclaim((LispObject)((char *)r1 + TAG_CONS),
                                    "bytecoded ncons", GC_CONS, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;        // may have been changed by GC
                    restore_pc();
                    pop(B_reg);
                }
                else A_reg = (LispObject)((char *)r1 + TAG_CONS);
#else
//
// What this example shows is that IN_LINE is not always such a bad deal.
// Making everything safe across the potential garbage collection here
// is a big mess!
//
                push(B_reg);
                save_pc();
                C_stack = stack;
                A_reg = ncons(A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;        // may have been changed by GC
                restore_pc();
                pop(B_reg);
#endif
                continue;

            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
#ifndef OUT_OF_LINE
                r1 = (LispObject)((char *)fringe - sizeof(Cons_Cell));
                qcar(r1) = A_reg;
                qcdr(r1) = B_reg;
                fringe = r1;
                if ((char *)r1 <= (char *)heaplimit)
                {   save_pc();
                    C_stack = stack;
                    A_reg = reclaim((LispObject)((char *)r1 + TAG_CONS),
                                    "bytecoded xcons", GC_CONS, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;        // may have been changed by GC
                    restore_pc();
                }
                else A_reg = (LispObject)((char *)r1 + TAG_CONS);
#else
                save_pc();
                C_stack = stack;
                A_reg = cons(A_reg, B_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;        // may have been changed by GC
                restore_pc();
#endif
                continue;

            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
#ifndef OUT_OF_LINE
                r1 = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
                qcar(r1) = B_reg;
                qcdr(r1) = (LispObject)((char *)r1 +
                                        sizeof(Cons_Cell) + TAG_CONS);
                qcar((LispObject)((char *)r1+sizeof(Cons_Cell))) = A_reg;
                qcdr((LispObject)((char *)r1+sizeof(Cons_Cell))) = nil;
                fringe = r1;
                if ((char *)r1 <= (char *)heaplimit)
                {   save_pc();
                    C_stack = stack;
                    A_reg = reclaim((LispObject)((char *)r1 + TAG_CONS),
                                    "bytecoded list2", GC_CONS, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;
                    restore_pc();
                }
                else A_reg = (LispObject)((char *)r1 + TAG_CONS);
#else
                save_pc();
                C_stack = stack;
                A_reg = list2(B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;        // may have been changed by GC
                restore_pc();
#endif
                continue;

            case OP_ACONS:                  // A_reg = acons(pop(), B_reg, A_reg);
                // = (pop() . B) . A
#ifndef OUT_OF_LINE
                r1 = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
                qcar(r1) = (LispObject)((char *)r1 +
                                        sizeof(Cons_Cell) + TAG_CONS);
                qcdr(r1) = A_reg;
                pop(qcar((LispObject)((char *)r1+sizeof(Cons_Cell))));
                qcdr((LispObject)((char *)r1+sizeof(Cons_Cell))) = B_reg;
                fringe = r1;
                if ((char *)r1 <= (char *)heaplimit)
                {   save_pc();
                    C_stack = stack;
                    A_reg = reclaim((LispObject)((char *)r1 + TAG_CONS),
                                    "bytecoded acons", GC_CONS, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;
                    restore_pc();
                }
                else A_reg = (LispObject)((char *)r1 + TAG_CONS);
#else
                pop(r1);
                save_pc();
                C_stack = stack;
                A_reg = acons(r1, B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;        // may have been changed by GC
                restore_pc();
#endif
                continue;

//
// For the next two opcodes the first argument to the current function
// must have been an environment pointer as set up with CLOSURE. I do
// not check that I have a closure object - perhaps I can excuse that by
// claiming that all creation and management of encapsulated closures
// will have been introduced by the compiler, which I propose to trust!
// (actually as of April 2002 I think there may be bugs I need to fix...)
//
            case OP_LOADLEX:
                r1 = elt(stack[1-(int)next_byte], 0);
                B_reg = A_reg;
                w = next_byte;             // Number of levels to chain
                while (w != 0) r1 = ((LispObject *)r1)[1], w--;
                A_reg = ((LispObject *)r1)[next_byte];
                continue;

            case OP_STORELEX:
                r1 = elt(stack[1-(int)next_byte], 0);
                w = next_byte;             // Number of levels to chain
                while (w != 0) r1 = ((LispObject *)r1)[1], w--;
                ((LispObject *)r1)[next_byte] = A_reg;
                continue;

            case OP_CLOSURE:
                push2(B_reg, A_reg);
//
// This will be the address where the first arg of this function lives on
// the stack.  It provides a hook for the called function to access lexical
// variables.
//
                w = next_byte;
                goto create_closure;

            case OP_BIGSTACK:               // LOADLOC, STORELOC, CLOSURE etc
                //
                // This opcode allows me to support functions that use up to
                // 2047-deep stack frames using LOADLEX and STORELEX, or
                // up to 4095 deep if just using LOADLOC and STORELOC. I hope
                // that such cases are very uncommon, but examples have been
                // shown to me where my previous limit of 256-item frames was
                // inadequate. The BIGSTACK opcode is followed by a byte that
                // contains a few bits selecting which operation is to be
                // performed, plus an extension to the address byte that follows.
                //
                w = next_byte;             // contains sub-opcode
                switch (w & 0xc0)
                {   case 0x00:                  // LOADLOC extended
                        B_reg = A_reg;
                        w = (w & 0x3f) << 8;
                        A_reg = stack[-(int)(w + next_byte)];
                        continue;
                    case 0x40:                  // STORELOC extended
                        w = (w & 0x3f) << 8;
                        stack[-(int)(w + next_byte)] = A_reg;
                        continue;
                    case 0x80:                  // CLOSURE extended
                        push2(B_reg, A_reg);
                        w = ((w & 0x3f) << 8) + next_byte;
                        goto create_closure;
                    case 0xc0:                  // LOADLEX, STORELEX extended
                        n = next_byte;
                        k = next_byte;
                        n = (n << 4) | (k >> 4);
                        k = ((k & 0xf) << 8) | next_byte;
                        r1 = elt(stack[1-n], 0);
                        B_reg = A_reg;
                        n = w & 0x1f;
                        while (n != 0) r1 = ((LispObject *)r1)[1], n--;
                        if ((w & 0x20) == 0) A_reg = ((LispObject *)r1)[k];
                        else ((LispObject *)r1)[k] = A_reg;
                        continue;
                }

            case OP_LIST2STAR:              // A_reg = list2!*(pop(), B_reg, A_reg);
                // = pop() . (B . A)
#ifndef OUT_OF_LINE
                r1 = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
                pop(qcar(r1));
                qcdr(r1) = (LispObject)((char *)r1 +
                                        sizeof(Cons_Cell) + TAG_CONS);
                qcar((LispObject)((char *)r1+sizeof(Cons_Cell))) = B_reg;
                qcdr((LispObject)((char *)r1+sizeof(Cons_Cell))) = A_reg;
                fringe = r1;
                if ((char *)r1 <= (char *)heaplimit)
                {   save_pc();
                    C_stack = stack;
                    A_reg = reclaim((LispObject)((char *)r1 + TAG_CONS),
                                    "bytecoded list2*", GC_CONS, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;
                    restore_pc();
                }
                else A_reg = (LispObject)((char *)r1 + TAG_CONS);
#else
                pop(r1);
                save_pc();
                C_stack = stack;
                A_reg = list2star(r1, B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;        // may have been changed by GC
                restore_pc();
#endif
                continue;

            case OP_LIST3:                  // A_reg = list3(pop(), B_reg, A_reg);
                // = pop() . (B . (A . nil))
#ifndef OUT_OF_LINE
                r1 = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
                pop(qcar(r1));
                qcdr(r1) = (LispObject)((char *)r1 +
                                        sizeof(Cons_Cell) + TAG_CONS);
                qcar((LispObject)((char *)r1+sizeof(Cons_Cell))) = B_reg;
                qcdr((LispObject)((char *)r1+sizeof(Cons_Cell))) =
                    (LispObject)((char *)r1 +
                                 2*sizeof(Cons_Cell) + TAG_CONS);
                qcar((LispObject)((char *)r1+2*sizeof(Cons_Cell))) = A_reg;
                qcdr((LispObject)((char *)r1+2*sizeof(Cons_Cell))) = nil;
                fringe = r1;
                if ((char *)r1 <= (char *)heaplimit)
                {   save_pc();
                    C_stack = stack;
                    A_reg = reclaim((LispObject)((char *)r1 + TAG_CONS),
                                    "bytecoded list3", GC_CONS, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;
                    restore_pc();
                }
                else A_reg = (LispObject)((char *)r1 + TAG_CONS);
#else
                pop(r1);
                save_pc();
                C_stack = stack;
                A_reg = list3(r1, B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;        // may have been changed by GC
                restore_pc();
#endif
                continue;

            case OP_ADD1:
                if (is_fixnum(A_reg) && A_reg != fixnum_of_int(0x07ffffff))
                {   A_reg += 0x10;
                    continue;
                }
//
// I drop through in the case of floating, bignum or error arithmetic.
//
                save_pc();
                C_stack = stack;
                A_reg = plus2(A_reg, fixnum_of_int(1));
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_PLUS2:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   n = int_of_fixnum(A_reg) + int_of_fixnum(B_reg);
                    k = n & fix_mask;
                    if (k == 0 || k == fix_mask)
                    {   A_reg = fixnum_of_int(n);
                        continue;
                    }
                }
//
// I drop through in the case of floating, bignum or error arithmetic.
//
                save_pc();
                C_stack = stack;
                A_reg = plus2(B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_SUB1:
                if (is_fixnum(A_reg) && A_reg != fixnum_of_int(~0x07ffffff))
                {   A_reg -= 0x10;
                    continue;
                }
//
// I drop through in the case of floating, bignum or error arithmetic.
//
                save_pc();
                C_stack = stack;
                A_reg = plus2(A_reg, fixnum_of_int(-1));
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_DIFFERENCE:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   n = int_of_fixnum(B_reg) - int_of_fixnum(A_reg);
                    k = n & fix_mask;
                    if (k == 0 || k == fix_mask)
                    {   A_reg = fixnum_of_int(n);
                        continue;
                    }
                }
//
// Although computing A-B as A+(-B) is a bit clumsy here, it is only
// done when there is a bignum or float involved - the important case
// where everything is a small integer is handled directly in-line.
//
                save_pc();
                push(B_reg);
                C_stack = stack;
                A_reg = negate(A_reg);
                stack = C_stack;
                pop(B_reg);
                C_stack = stack;
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                A_reg = plus2(B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_TIMES2:
//
// I do not in-line even the integer case here, since overflow checking
// is a slight mess.
//
                save_pc();
                C_stack = stack;
                A_reg = times2(B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_LESSP:
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg < A_reg;
                else
                {   save_pc();
                    C_stack = stack;
                    w = lessp2(B_reg, A_reg);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;
                    restore_pc();
                }
                A_reg = Lispify_predicate(w);
                continue;

            case OP_GREATERP:
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg > A_reg;
                else
                {   save_pc();
                    C_stack = stack;
                    w = lessp2(A_reg, B_reg);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;
                    restore_pc();
                }
                A_reg = Lispify_predicate(w);
                continue;

            case OP_FLAGP:                                  // A = flagp(B, A)
#ifdef COMMON
                save_pc(); C_stack = stack;
                A_reg = get(B_reg, A_reg, unset_var);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack; restore_pc();
                if (A_reg == unset_var) A_reg = nil;
                else A_reg = lisp_true;
                continue;
#else
#ifndef OUT_OF_LINE
                if (!symbolp(B_reg))
                {
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(A_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    A_reg = nil;
                    continue;
                }
                else if (symbolp(A_reg) &&
                         (n = header_fastget(qheader(A_reg))) != 0)
                {   r1 = qfastgets(B_reg);
                    if (r1 == nil)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(A_reg, false);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        A_reg = nil;
                        continue;
                    }
                    r1 = elt(r1, n-1);
#ifdef RECORD_GET
                    push(r1);
                    save_pc(); C_stack = stack;
                    record_get(A_reg, r1 != SPID_NOPROP);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
                    pop(r1);
#endif
                    if (r1 == SPID_NOPROP) A_reg = nil; else A_reg = lisp_true;
                    continue;
                }
                else
                {   r1 = qplist(B_reg);
                    if (r1 == nil)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(A_reg, false);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        A_reg = nil;
                        continue;
                    }
                    r3 = qcar(r1);
                    if (qcar(r3) == A_reg)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(A_reg, true);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        A_reg = lisp_true;
                        continue;
                    }
                    r1 = qcdr(r1);
                    if (r1 == nil)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(A_reg, false);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        A_reg = nil;
                        continue;
                    }
                    r3 = qcar(r1);
                    if (qcar(r3) == A_reg)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(A_reg, true);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        A_reg = lisp_true;
                        continue;
                    }
                    r2 = r1;
                    r1 = qcdr(r1);
                    if (r1 == nil)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(A_reg, false);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        A_reg = nil;
                        continue;
                    }
                    for (;;)
                    {   r3 = qcar(r1);
                        if (qcar(r3) == A_reg)
                        {   qcdr(r2) = qcdr(r1);
                            qcdr(r1) = qplist(B_reg);
                            qplist(B_reg) = r1;
#ifdef RECORD_GET
                            save_pc(); C_stack = stack;
                            record_get(A_reg, false);
                            nil = C_nil;
                            if (exception_pending()) goto error_exit;
                            stack = C_stack; restore_pc();
#endif
                            A_reg = lisp_true;
                            break;
                        }
                        r2 = r1;
                        r1 = qcdr(r1);
                        if (r1 == nil)
                        {
#ifdef RECORD_GET
                            save_pc(); C_stack = stack;
                            record_get(A_reg, false);
                            nil = C_nil;
                            if (exception_pending()) goto error_exit;
                            stack = C_stack; restore_pc();
#endif
                            A_reg = nil;
                            break;
                        }
                    }
                }
                continue;
#else
                A_reg = Lflagp(nil, B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                continue;
#endif
#endif

            case OP_APPLY1:
                save_pc();
                if (is_symbol(B_reg))   // can optimise this case, I guess
                {   f1 = qfn1(B_reg);
#ifdef DEBUG
                    if (f1 == NULL)
                    {   term_printf("Illegal function\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
#ifndef NO_BYTECOUNT
                    name_of_caller = (const char *)ffname;
#endif
                    push(B_reg);
                    C_stack = stack;
                    A_reg = f1(qenv(B_reg), A_reg);
                    nil = C_nil;
                    if (exception_pending()) goto stack_apply_error;
                    stack = C_stack;
                    popv(1);
                    restore_pc();
                    continue;
                }
                push(A_reg);
                C_stack = stack;
#ifndef NO_BYTECOUNT
                name_of_caller = (const char *)ffname;
#endif
                A_reg = apply(B_reg, 1, nil, B_reg, (1 & (int)(intptr_t)entry_stack));
                nil = C_nil;
                if (exception_pending()) goto apply_error;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_APPLY2:
                save_pc();
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   f2 = qfn2(r2);
#ifdef DEBUG
                    if (f2 == NULL)
                    {   term_printf("Illegal function\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
#ifndef NO_BYTECOUNT
                    name_of_caller = (const char *)ffname;
#endif
                    C_stack = stack;
                    A_reg = f2(qenv(r2), B_reg, A_reg);
                    nil = C_nil;
                    if (exception_pending()) goto stack_apply_error;
                    stack = C_stack;
                    popv(1);
                    restore_pc();
                    continue;
                }
                *stack = B_reg;
                push(A_reg);
                C_stack = stack;
#ifndef NO_BYTECOUNT
                name_of_caller = (const char *)ffname;
#endif
                A_reg = apply(r2, 2, nil, r2, (1 & (int)(intptr_t)entry_stack));
                nil = C_nil;
                if (exception_pending()) goto apply_error;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_APPLY3:
                save_pc();
                pop(r1);
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   f345 = qfnn(r2);
#ifdef DEBUG
                    if (f345 == NULL)
                    {   term_printf("Illegal function\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
#ifndef NO_BYTECOUNT
                    name_of_caller = (const char *)ffname;
#endif
                    C_stack = stack;
                    A_reg = f345(qenv(r2), 3, r1, B_reg, A_reg);
                    nil = C_nil;
                    if (exception_pending()) goto stack_apply_error;
                    stack = C_stack;
                    popv(1);
                    restore_pc();
                    continue;
                }
                *stack = r1;
                push2(B_reg, A_reg);
                C_stack = stack;
#ifndef NO_BYTECOUNT
                name_of_caller = (const char *)ffname;
#endif
                A_reg = apply(r2, 3, nil, r2, (1 & (int)(intptr_t)entry_stack));
                nil = C_nil;
                if (exception_pending()) goto apply_error;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_APPLY4:
//
// It is not yet clear that APPLY4 is important enough to justify the
// mess it would involve here...
//
                err_printf("\nAPPLY4 not implemented yet\n");
                aerror("unfinished work in bytes1.c");
                nil = C_nil;
                C_stack = stack;
                goto error_exit;

#ifdef COMMON
#define EQUAL cl_equal
#else
#define EQUAL equal
#endif

            case OP_EQUAL:                                  // A = equal(B, A)
                A_reg = EQUAL(B_reg, A_reg) ? lisp_true : nil;
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                continue;

            case OP_EQ:                                     // A = eq(B, A)
                if (A_reg == B_reg) A_reg = lisp_true;
                else A_reg = nil;
                continue;

            case OP_NUMBERP:                                // A = numberp(A)
                A_reg = Lispify_predicate(is_number(A_reg));
                continue;

            case OP_QGETV:                          // A_reg = getv(B_reg, A_reg)
//
// Note - this is an UNCHECKED vector access, used when carcheck(nil) has
// been selected because the user prefers speed to security.  This is in
// here because the Reduce factoriser test uses getv VERY heavily indeed
// and both use of a special opcode here and removal of the checking make
// noticable differences to performance.
//
                A_reg = *(LispObject *)(
                            (char *)B_reg +
                            (CELL - TAG_VECTOR) +
                            (CELL*int_of_fixnum(A_reg)));
                continue;

            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
#ifndef OUT_OF_LINE
                if (!(is_vector(B_reg)) ||
                    vector_holds_binary(k = vechdr(B_reg)))
                {   aerror1("getv", B_reg);
                    nil = C_nil;
                    goto error_exit;
                }
                else if (!is_fixnum(A_reg))
                {   aerror1("getv offset not fixnum", A_reg);
                    nil = C_nil;
                    goto error_exit;
                }
                k = (length_of_header(k) - CELL)/CELL;
                n = int_of_fixnum(A_reg);
                if (n < 0 || n >= k)
                {   aerror1("getv index range", A_reg);
                    nil = C_nil;
                    goto error_exit;
                }
                A_reg = *(LispObject *)(
                            (char *)B_reg +
                            (CELL - TAG_VECTOR) +
                            CELL*int_of_fixnum(A_reg));
#else
                save_pc();
                C_stack = stack;
                A_reg = Lgetv(nil, B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;        // may have been changed by GC
                restore_pc();
#endif
                continue;

            case OP_QGETVN:                         // A_reg = getv(A_reg, n)
//
// Note - this is an UNCHECKED vector access, and only applicable to simple
// vectors that hold general Lisp data.  The offset is passed in the
// byte stream.  It is expected that it will help with code that passes
// around vectors of guff and use (getv vvv 0) etc (aka svref) to
// grab stuff out.
//
                A_reg = *(LispObject *)(
                            (char *)A_reg + (CELL - TAG_VECTOR) + (CELL*(next_byte)));
                continue;

            case OP_EQCAR:
                if (car_legal(B_reg) && A_reg == qcar(B_reg)) A_reg = lisp_true;
                else A_reg = nil;
                continue;

            case OP_LENGTH:
                save_pc();
                C_stack = stack;
                A_reg = Llength(nil, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

//
// The following combinations feel a little odd, but ONE of them showed up
// very clearly in REDUCE tests, and adding the other few seems liable
// (on sentiment, not measurement!) to make reasonable sense.
//
            case OP_LOC0LOC1:
                B_reg = stack[-0];
                A_reg = stack[-1];
                continue;

            case OP_LOC1LOC2:
                B_reg = stack[-1];
                A_reg = stack[-2];
                continue;

            case OP_LOC2LOC3:
                B_reg = stack[-2];
                A_reg = stack[-3];
                continue;

            case OP_LOC1LOC0:
                B_reg = stack[-1];
                A_reg = stack[-0];
                continue;

            case OP_LOC2LOC1:
                B_reg = stack[-2];
                A_reg = stack[-1];
                continue;

            case OP_LOC3LOC2:
                B_reg = stack[-3];
                A_reg = stack[-2];
                continue;

            case OP_CDRLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;

            case OP_CDRLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;

            case OP_CDRLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;

            case OP_CDRLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;

            case OP_CDRLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;

            case OP_CDRLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;

            case OP_CAARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                goto caar;

            case OP_CAARLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                goto caar;

            case OP_CAARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                goto caar;

            case OP_CAARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                goto caar;

            case OP_CAAR:
                goto caar;

            case OP_CADR:
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else
                {   CSLerrcode = err_bad_cdr;
                    C_stack = stack;
                    goto error_1_A;
                }
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CDAR:
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else
                {   CSLerrcode = err_bad_car;
                    C_stack = stack;
                    goto error_1_A;
                }
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;

            case OP_CDDR:
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else
                {   CSLerrcode = err_bad_cdr;
                    C_stack = stack;
                    goto error_1_A;
                }
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;


//
// The ICASE opcode is followed by a byte (n say) that indicates the number
// of cases that follow, followed by n+1 double-byte label values.
// If these addresses are called L<dflt>, L<0>, L<1>, ... L<n-1> then if the
// A register contains an integer in the range 0 <= k < n then control is
// transferred to L<k>, while if the A register does not hold an integer or
// if its value is out of range then control goes to L<dflt>.
//
            case OP_ICASE:
                w = next_byte;
                if (is_fixnum(A_reg) &&
                    (n = int_of_fixnum(A_reg)) >= 0 &&
                    n < (int)w) ppc += 2*n + 2;
                w = next_byte;
//
// I support backwards jumps here by setting their top bit. At present I do
// poll for interrupts on a backwards case-branch. And the encoding used means
// that case branches can not reach quite as far as regular jumps.
//
                if (w & 0x80) ppc = ppc - (((w & 0x7f) << 8) + *ppc);
                else ppc = ppc + (w << 8) + *ppc;
                continue;

//
// There are a bunch of special-case jumps here - they are only
// provided with the variants that jump forwards by small offsets,
// but are expected to pick up a useful number of cases (for both speed and
// compactness) all the same.
//

            case OP_JUMPL0NIL:
                xppc = ppc;
                ppc++;
                if (stack[0] == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL0T:
                xppc = ppc;
                ppc++;
                if (stack[0] != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL1NIL:
                xppc = ppc;
                ppc++;
                if (stack[-1] == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL1T:
                xppc = ppc;
                ppc++;
                if (stack[-1] != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL2NIL:
                xppc = ppc;
                ppc++;
                if (stack[-2] == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL2T:
                xppc = ppc;
                ppc++;
                if (stack[-2] != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL3NIL:
                xppc = ppc;
                ppc++;
                if (stack[-3] == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL3T:
                xppc = ppc;
                ppc++;
                if (stack[-3] != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL4NIL:
                xppc = ppc;
                ppc++;
                if (stack[-4] == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL4T:
                xppc = ppc;
                ppc++;
                if (stack[-4] != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL0ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[0])) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL0NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[0])) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL1ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-1])) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL1NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-1])) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL2ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-2])) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL2NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-2])) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL3ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-3])) ppc = ppc + *xppc;
                continue;

            case OP_JUMPL3NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-3])) ppc = ppc + *xppc;
                continue;

            case OP_JUMPST0NIL:
                xppc = ppc;
                ppc++;
                if ((stack[0] = A_reg) == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPST0T:
                xppc = ppc;
                ppc++;
                if ((stack[0] = A_reg) != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPST1NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-1] = A_reg) == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPST1T:
                xppc = ppc;
                ppc++;
                if ((stack[-1] = A_reg) != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPST2NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-2] = A_reg) == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPST2T:
                xppc = ppc;
                ppc++;
                if ((stack[-2] = A_reg) != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREE1NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, 1)) == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREE1T:
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, 1)) != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREE2NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, 2)) == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREE2T:
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, 2)) != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREE3NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, 3)) == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREE3T:
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, 3)) != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREE4NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, 4)) == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREE4T:
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, 4)) != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLIT1EQ:
                xppc = ppc;
                ppc++;
                if (elt(litvec, 1) == A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLIT1NE:
                xppc = ppc;
                ppc++;
                if (elt(litvec, 1) != A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLIT2EQ:
                xppc = ppc;
                ppc++;
                if (elt(litvec, 2) == A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLIT2NE:
                xppc = ppc;
                ppc++;
                if (elt(litvec, 2) != A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLIT3EQ:
                xppc = ppc;
                ppc++;
                if (elt(litvec, 3) == A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLIT3NE:
                xppc = ppc;
                ppc++;
                if (elt(litvec, 3) != A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLIT4EQ:
                xppc = ppc;
                ppc++;
                if (elt(litvec, 4) == A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLIT4NE:
                xppc = ppc;
                ppc++;
                if (elt(litvec, 4) != A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREENIL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, w)) == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFREET:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(elt(litvec, w)) != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLITEQ:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (elt(litvec, w) == A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPLITNE:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (elt(litvec, w) != A_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPB1NIL:
                f1 = one_arg_functions[next_byte];
                save_pc();
                C_stack = stack;
                A_reg = f1(nil, A_reg);
                nil = C_nil;
                if (exception_pending()) goto call_error_exit;
                stack = C_stack;
                restore_pc();
                xppc = ppc;
                ppc++;
                if (A_reg == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPB1T:
                f1 = one_arg_functions[next_byte];
                save_pc();
                C_stack = stack;
                A_reg = f1(nil, A_reg);
                nil = C_nil;
                if (exception_pending()) goto call_error_exit;
                stack = C_stack;
                restore_pc();
                xppc = ppc;
                ppc++;
                if (A_reg != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPB2NIL:
                f2 = two_arg_functions[next_byte];
                save_pc();
                C_stack = stack;
                A_reg = f2(nil, B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                xppc = ppc;
                ppc++;
                if (A_reg == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPB2T:
                f2 = two_arg_functions[next_byte];
                save_pc();
                C_stack = stack;
                A_reg = f2(nil, B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                xppc = ppc;
                ppc++;
                if (A_reg != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (car_legal(A_reg) &&
                    elt(litvec, w) == qcar(A_reg)) ppc = ppc + *xppc;
                continue;

            case OP_JUMPNEQCAR:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!car_legal(A_reg) ||
                    elt(litvec, w) != qcar(A_reg)) ppc = ppc + *xppc;
                continue;

            case OP_JUMPFLAGP:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!symbolp(A_reg)) continue;
                else
#ifdef COMMON
                {   save_pc(); C_stack = stack;
                    r1 = get(A_reg, elt(litvec, w), unset_var);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
                    if (r1 != unset_var) ppc = ppc + *xppc;
                    continue;
                }
#else
#ifndef OUT_OF_LINE
                    B_reg = elt(litvec, w);
                if (symbolp(B_reg) &&
                    (n = header_fastget(qheader(B_reg))) != 0)
                {   r1 = qfastgets(A_reg);
                    if (r1 == nil)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(B_reg, false);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        continue;
                    }
                    r1 = elt(r1, n-1);
#ifdef RECORD_GET
                    push(r1);
                    save_pc(); C_stack = stack;
                    record_get(B_reg, r1 != SPID_NOPROP);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
                    pop(r1);
#endif
                    if (r1 != SPID_NOPROP) ppc = ppc + *xppc;
                    continue;
                }
                r1 = qplist(A_reg);
                if (r1 == nil)
                {
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                r3 = qcar(r1);
                if (qcar(r3) == B_reg)
                {   ppc = ppc + *xppc;
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, true);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                r1 = qcdr(r1);
                if (r1 == nil)
                {
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                r3 = qcar(r1);
                if (qcar(r3) == B_reg)
                {   ppc = ppc + *xppc;
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, true);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                r2 = r1;
                r1 = qcdr(r1);
                if (r1 == nil)
                {
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                for (;;)
                {   r3 = qcar(r1);
                    if (qcar(r3) == B_reg)
                    {   qcdr(r2) = qcdr(r1);
                        qcdr(r1) = qplist(A_reg);
                        qplist(A_reg) = r1;
                        ppc = ppc + *xppc;
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(B_reg, true);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        break;
                    }
                    r2 = r1;
                    r1 = qcdr(r1);
                    if (r1 == nil)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(B_reg, false);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        break;
                    }
                }
                continue;
#else
                    r1 = Lflagp(nil, A_reg, elt(litvec, w));
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                if (r1 != nil) ppc = ppc + *xppc;
                continue;
#endif
#endif

            case OP_JUMPNFLAGP:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!symbolp(A_reg))
                {   ppc = ppc + *xppc;
                    continue;
                }
                else
#ifdef COMMON
                {   save_pc(); C_stack = stack;
                    r1 = get(A_reg, elt(litvec, w), unset_var);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
                    if (r1 == unset_var) ppc = ppc + *xppc;
                    continue;
                }
#else
#ifndef OUT_OF_LINE
                    B_reg = elt(litvec, w);
                if (symbolp(B_reg) &&
                    (n = header_fastget(qheader(B_reg))) != 0)
                {   r1 = qfastgets(A_reg);
                    if (r1 == nil)
                    {
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(B_reg, false);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        ppc = ppc + *xppc;
                        continue;
                    }
                    r1 = elt(r1, n-1);
#ifdef RECORD_GET
                    push(r1);
                    save_pc(); C_stack = stack;
                    record_get(B_reg, r1 != SPID_NOPROP);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
                    pop(r1);
#endif
                    if (r1 == SPID_NOPROP) ppc = ppc + *xppc;
                    continue;
                }
                r1 = qplist(A_reg);
                if (r1 == nil)
                {   ppc = ppc + *xppc;
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                r3 = qcar(r1);
                if (qcar(r3) == B_reg)
                {
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, true);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                r1 = qcdr(r1);
                if (r1 == nil)
                {   ppc = ppc + *xppc;
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                r3 = qcar(r1);
                if (qcar(r3) == B_reg)
                {
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, true);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                r2 = r1;
                r1 = qcdr(r1);
                if (r1 == nil)
                {   ppc = ppc + *xppc;
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(B_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    continue;
                }
                for (;;)
                {   r3 = qcar(r1);
                    if (qcar(r3) == B_reg)
                    {   qcdr(r2) = qcdr(r1);
                        qcdr(r1) = qplist(A_reg);
                        qplist(A_reg) = r1;
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(B_reg, true);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        break;
                    }
                    r2 = r1;
                    r1 = qcdr(r1);
                    if (r1 == nil)
                    {   ppc = ppc + *xppc;
#ifdef RECORD_GET
                        save_pc(); C_stack = stack;
                        record_get(B_reg, false);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack; restore_pc();
#endif
                        break;
                    }
                }
                continue;
#else
                    r1 = Lflagp(nil, A_reg, elt(litvec, w));
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                if (r1 == nil) ppc = ppc + *xppc;
                continue;
#endif
#endif

//
// Now the general jumps.  Each has four variants - forwards and backwards
// and long and short offsets.  Backwards jumps poll for interrupts so that
// all loops will be interruptible.
//

            case OP_JUMPATOM:
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) ppc = ppc + *xppc;
                continue;

            case OP_JUMPATOM_B:
                xppc = ppc;
                ppc++;
                if (!consp(A_reg))
                {   ppc = ppc - *xppc;
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPNATOM:
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) ppc = ppc + *xppc;
                continue;

            case OP_JUMPNATOM_B:
                xppc = ppc;
                ppc++;
                if (consp(A_reg))
                {   ppc = ppc - *xppc;
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPEQ:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPEQ_B:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg)
                {   ppc = ppc - *xppc;
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPNE:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) ppc = ppc + *xppc;
                continue;

            case OP_JUMPNE_B:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg)
                {   ppc = ppc - *xppc;
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPEQUAL:
                xppc = ppc;
                ppc++;
                if (EQUAL(A_reg, B_reg)) ppc = ppc + *xppc;
                continue;

            case OP_JUMPEQUAL_B:
                xppc = ppc;
                ppc++;
                if (EQUAL(A_reg, B_reg))
                {   ppc = ppc - *xppc;
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPNEQUAL:
                xppc = ppc;
                ppc++;
                if (!EQUAL(A_reg, B_reg)) ppc = ppc + *xppc;
                continue;

            case OP_JUMPNEQUAL_B:
                xppc = ppc;
                ppc++;
                if (!EQUAL(A_reg, B_reg))
                {   ppc = ppc - *xppc;
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMP:
                ppc = ppc + *ppc + 1;
                continue;

            case OP_JUMP_B:
                ppc = ppc - *ppc + 1;
#ifndef OUT_OF_LINE
                if (--countdown < 0) deal_with_tick();
                if (stack >= stacklimit)
                {   C_stack = stack;
                    A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;        // may have been changed by GC
                }
#else
                if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                    goto error_exit;
                stack = C_stack;
#endif
                continue;

            case OP_JUMPATOM_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) ppc = ppc + ((w << 8) + *xppc);
                continue;

            case OP_JUMPATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg))
                {   ppc = ppc - ((w << 8) + *xppc);
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPNATOM_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) ppc = ppc + ((w << 8) + *xppc);
                continue;

            case OP_JUMPNATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (consp(A_reg))
                {   ppc = ppc - ((w << 8) + *xppc);
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPEQ_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) ppc = ppc + ((w << 8) + *xppc);
                continue;

            case OP_JUMPEQ_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg)
                {   ppc = ppc - ((w << 8) + *xppc);
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPNE_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) ppc = ppc + ((w << 8) + *xppc);
                continue;

            case OP_JUMPNE_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg)
                {   ppc = ppc - ((w << 8) + *xppc);
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPEQUAL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (EQUAL(A_reg, B_reg))
                    ppc = ppc + ((w << 8) + *xppc);
                continue;

            case OP_JUMPEQUAL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (EQUAL(A_reg, B_reg))
                {   ppc = ppc - ((w << 8) + *xppc);
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPNEQUAL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!EQUAL(A_reg, B_reg))
                    ppc = ppc + ((w << 8) + *xppc);
                continue;

            case OP_JUMPNEQUAL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!EQUAL(A_reg, B_reg))
                {   ppc = ppc - ((w << 8) + *xppc);
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMP_L:
                w = next_byte;
                ppc = ppc + ((w << 8) + *ppc) + 1;
                continue;

            case OP_JUMP_BL:
                w = next_byte;
                ppc = ppc - ((w << 8) + *ppc) + 1;
#ifndef OUT_OF_LINE
                if (--countdown < 0) deal_with_tick();
                if (stack >= stacklimit)
                {   C_stack = stack;
                    A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;        // may have been changed by GC
                }
#else
                if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                    goto error_exit;
                stack = C_stack;
#endif
                continue;

            case OP_CATCH:
                w = (unsigned int)((ppc + *ppc) -
                                   (unsigned char *)data_of_bps(codevec));
                ppc++;
                goto catcher;

            case OP_CATCH_B:
                w = (unsigned int)((ppc - *ppc) -
                                   (unsigned char *)data_of_bps(codevec));
                ppc++;
                goto catcher;

            case OP_CATCH_L:
                w = next_byte;
                w = (unsigned int)((ppc + (w << 8) + *ppc) -
                                   (unsigned char *)data_of_bps(codevec));
                ppc++;
                goto catcher;

            case OP_CATCH_BL:
                w = next_byte;
                w = (unsigned int)((ppc - ((w << 8) + *ppc)) -
                                   (unsigned char *)data_of_bps(codevec));
                ppc++;
                goto catcher;

            case OP_UNCATCH:
                popv(1); pop(r1); popv(1);
                catch_tags = qcdr(r1);
                qcar(r1) = r1; qcdr(r1) = nil;
                continue;

            case OP_PROTECT:
//
// This is used to support UNWIND-PROTECT.
// This needs to save A_reg, all the multiple-result registers,
// and the exit_count. Also something to indicate that there had not been
// an error.
//
                popv(1); pop(r1); popv(1);
                catch_tags = qcdr(r1);
                qcar(r1) = r1; qcdr(r1) = nil;
#ifdef COMMON
                A_reg = Lmv_list(nil, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
#endif
                push3(nil, fixnum_of_int(UNWIND_NULL), A_reg);
                continue;

            case OP_UNPROTECT:
//
// This must restore all the results (including exit_count). If the
// PROTECT had been done by an unwinding then exit_reason and exit_tag
// must also be restored, and the unwind condition must be re-instated.
//
                pop3(A_reg, B_reg, exit_tag);
                exit_reason = int_of_fixnum(B_reg);
#ifdef COMMON
//
// Here I have multiple values to restore.
//
                exit_count = 0;
                B_reg = A_reg;
                A_reg = nil;
                if (consp(B_reg))
                {   A_reg = qcar(B_reg);
                    B_reg = qcdr(B_reg);
                    exit_count++;
                    while (consp(B_reg))
                    {   (&mv_1)[exit_count++] = qcar(B_reg);
                        B_reg = qcdr(B_reg);
                    }
                }
#endif
                exit_value = A_reg;
                if (exit_reason != UNWIND_NULL) goto pop_stack_and_exit;
                continue;

            case OP_THROW:
                pop(r1);       // the tag to throw to
                for (r2 = catch_tags; r2!=nil; r2=qcdr(r2))
                    if (r1 == qcar(r2)) break;
                if (r2==nil)
                {   aerror1("throw: tag not found", r1);
                    nil = C_nil;
                    goto error_exit;
                }
                catch_tags = qcdr(r2);
                exit_tag = r2;
                exit_value = A_reg;
                exit_reason = UNWIND_THROW;
                flip_exception();
//
// NOTE WELL: this means that at error_exit (after all the possible cases
// where something I call returns with NIL marked) it is essential to check
// for THROW as well as just error returns.
//
                goto error_exit;

//
// I expect that calling functions with 0, 1, 2 or 3 arguments will
// be enormously important for Lisp, and so separate opcodes are provided
// for these cases.  The operand in each case selects the function to be
// called, which MUST be a symbol (loaded from the literal vector),
// and arguments are taken from A and B as necessary.  If several
// arguments are needed the first argument will be loaded first, and thus
// it is the LAST argument that end up in the A register.
//

            case OP_CALL0_0:      // Calling myself...
                fname = 0;
                goto call0;

            case OP_CALL0_1:
                fname = 1;
                goto call0;

            case OP_CALL0_2:
                fname = 2;
                goto call0;

            case OP_CALL0_3:
                fname = 3;
                goto call0;

            case OP_CALL0:
                fname = next_byte;
                goto call0;

            case OP_JCALL:
//
// This version has the number of args and the target packed into a
// single operand byte.  JCALLN is functionally similar but allows
// for more extreme cases by using one byte to specify the target
// and another to give the number of arguments being passed.
//
                w = next_byte;
                fname = w & 0x1f;
                w = (w >> 5) & 0x7;
                switch (w)
                {   case 0: goto jcall0;
                    case 1: goto jcall1;
                    case 2: goto jcall2;
                    case 3: goto jcall3;
                    default:goto jcalln;
                }

            case OP_JCALLN:
                fname = next_byte;
                w = next_byte;
                switch (w)
                {   case 0: goto jcall0;
                    case 1: goto jcall1;
                    case 2: goto jcall2;
                    case 3: goto jcall3;
                    default:goto jcalln;
                }

            case OP_BIGCALL:
//
// This provides for calls (and a few other operations!) where the literal
// to be referenced is beyond position 256 in the literal vector. The
// encoding is that BIGCALL is followed by two bytes. The top half of the
// first of these is a sub opcode, while the remaining 12 bits provide
// support for literal vectors with up to 4096 elements. At present I
// will just not support code bigger than that. Note that if I were feeling
// keen here I could easily arrange that the 12-bit offset here started at
// 256 and went on upwards. But for simplicity in a first version I will
// leave a bit of redundancy.
//
                w = next_byte;
                fname = next_byte + ((w & 0xf) << 8);
                switch (w >> 4)
                {   case 0: goto call0;
                    case 1: goto call1;
                    case 2: goto call2;
                    case 3: goto call3;
                    case 4:
//
// Here I write out a variant on the CALLN code.
//
                        push2(B_reg, A_reg);
                        save_pc();
                        C_stack = stack;
                        A_reg = elt(litvec, fname);
#ifndef NO_BYTECOUNT
                        name_of_caller = (const char *)ffname;
#endif
                        A_reg = apply(A_reg, (int)(*ppc), nil, A_reg, (1 & (int)(intptr_t)entry_stack));
                        nil = C_nil;
                        if (exception_pending()) goto ncall_error_exit;
                        stack = C_stack;         // args were popped by apply
                        restore_pc();
                        ppc++;
                        continue;

                    case 5: goto call2r;
//
// sub-opcodes 6 and 7 are use for LOADFREE and STOREFREE - this is a bit
// odd but fits the required operations tightly into the opcode map.
//
                    case 6:
                        B_reg = A_reg;
                        A_reg = qvalue(elt(litvec, fname));
                        continue;
                    case 7:
                        qvalue(elt(litvec, fname)) = A_reg;  // store into special var
                        continue;
                    case 8: goto jcall0;
                    case 9: goto jcall1;
                    case 10:goto jcall2;
                    case 11:goto jcall3;
// The codes for big JCALLs take a further byte that give the number of args
                    case 12:w = next_byte; goto jcalln;
//
// Codes 13 and 14 do FREEBIND and LITGET, which completes the list of
// byte operations that access big literals.
//
                    case 13:stack = do_freebind(elt(litvec, fname), stack);
                        continue;
                    case 14:B_reg = A_reg;
                        A_reg = elt(litvec, fname);
                        goto perform_get;
//
// Code 15 is LOADLIT with a long offset, which may be used as an alternative
// to the LOADLIT/QGETVN mechanism that I otherwise support.
//
                    case 15:B_reg = A_reg;
                        A_reg = elt(litvec, fname);
                        continue;
                }

            case OP_CALL1_0:
//
// Note that this is spotted and treated as a direct call to the
// current function (because offset zero in the literal vector is reserved
// for the name of the function).  I can NOT avoid the overhead of stacking
// and restoring codevec and litvec here, even the values used in the called
// function are the same as the present ones, because the lower level call
// might itself do a JCALL and corrupt them!  Also I know that the current
// function is bytecoded, so I avoid the overhead of (re-)discovering that.
//
                push3(codevec, litvec, A_reg); // the argument
                save_pc();
                C_stack = stack;
                if (--countdown < 0) deal_with_tick();
                if (stack >= stacklimit)
                {   reclaim(nil, "stack", GC_STACK, 0);
                    nil = C_nil;
                    if (exception_pending()) goto callself_error_exit;
                }
                A_reg = bytestream_interpret(data_of_bps(codevec), litvec, stack-1);
                nil = C_nil;
                if (exception_pending()) goto callself_error_exit;
                stack = C_stack;
                pop2(litvec, codevec);
                restore_pc();
                continue;

            case OP_CALL1_1:
                fname = 1;
                goto call1;

            case OP_CALL1_2:
                fname = 2;
                goto call1;

            case OP_CALL1_3:
                fname = 3;
                goto call1;

            case OP_CALL1_4:
                fname = 4;
                goto call1;

            case OP_CALL1_5:
                fname = 5;
                goto call1;

            case OP_CALL1:
                fname = next_byte;
                goto call1;


            case OP_CALL2_0:
                push4(codevec, litvec, B_reg, A_reg);
                save_pc();
                C_stack = stack;
                if (--countdown < 0) deal_with_tick();
                if (stack >= stacklimit)
                {   reclaim(nil, "stack", GC_STACK, 0);
                    nil = C_nil;
                    if (exception_pending()) goto callself_error_exit;
                }
                A_reg = bytestream_interpret(data_of_bps(codevec), litvec, stack-2);
                nil = C_nil;
                if (exception_pending()) goto callself_error_exit;
                stack = C_stack;
                pop2(litvec, codevec);
                restore_pc();
                continue;

            case OP_CALL2_1:
                fname = 1;
                goto call2;

            case OP_CALL2_2:
                fname = 2;
                goto call2;

            case OP_CALL2_3:
                fname = 3;
                goto call2;

            case OP_CALL2_4:
                fname = 4;
                goto call2;

            case OP_CALL2:
                fname = next_byte;
                goto call2;


            case OP_CALL2R:
                fname = next_byte;
                goto call2r;

            case OP_CALL3:
                fname = next_byte;
                goto call3;

            case OP_CALLN:
//
// Here the first post-byte indicates the function to be called,
// and the second is the number of args (>= 4) to be passed. All but the
// last two args have been pushed onto the stack already. The last two are
// in A and B.
//
                push2(B_reg, A_reg);
                save_pc();
                C_stack = stack;
                A_reg = elt(litvec, *ppc);
//
// Note that I never need to call something with 0, 1, 2 or 3 args here.
//
#ifndef NO_BYTECOUNT
                name_of_caller = (const char *)ffname;
#endif
                A_reg = apply(A_reg, (int)(*(ppc+1)), nil, A_reg, (1 & (int)(intptr_t)entry_stack));
                nil = C_nil;
                if (exception_pending()) goto ncall_error_exit;
                stack = C_stack;                    // args were popped by apply
                restore_pc();
                ppc = ppc + 2;
                continue;

            case OP_BUILTIN0:
                debug_assert(1);
// At present this uses the "old" scheme for functions that do not take
// arguments that passes the integer 0 to tell them of the lack of args
// actually passed.
                f345 = no_arg_functions[next_byte];
                debug_record_int("BUILTIN0", most_recent_byte);
// BUILTIN0:  A=fn()
                save_pc();
                C_stack = stack;
                A_reg = f345(nil, 0);
                debug_assert(1);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_BUILTIN2R:
                debug_assert(1);
                f2 = two_arg_functions[next_byte];
                debug_record_int("BUILTIN2R", most_recent_byte);
// BUILTIN2R:   A=fn(A,B); NOTE arg order reversed
                save_pc();
                C_stack = stack;
                A_reg = f2(nil, A_reg, B_reg);
                debug_assert(1);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_BUILTIN3:
                debug_assert(1);
                f345 = three_arg_functions[next_byte];
                debug_record_int("BUILTIN3", most_recent_byte);
// CALL3:   A=fn(pop(),B,A);
                save_pc();
                pop(r1);
                C_stack = stack;
                A_reg = f345(nil, 3, r1, B_reg, A_reg);
                debug_assert(1);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

//
// Now here in a neat block I will have the cases that seem to occur most
// frequently, at least when I tested things running REDUCE. By collecting
// these together I hope to (slightly) improve the cache locality behaviour
// for this code - maybe...
//
            case OP_LOADLOC:
                B_reg = A_reg;
                A_reg = stack[-(int)next_byte];
                continue;

            case OP_LOADLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                continue;

            case OP_LOADLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                continue;

            case OP_LOADLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                continue;

            case OP_LOADLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                continue;

            case OP_LOADLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                continue;

            case OP_LOADLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                continue;

            case OP_LOADLOC6:
                B_reg = A_reg;
                A_reg = stack[-6];
                continue;

            case OP_LOADLOC7:
                B_reg = A_reg;
                A_reg = stack[-7];
                continue;

            case OP_LOADLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                continue;

            case OP_LOADLOC9:
                B_reg = A_reg;
                A_reg = stack[-9];
                continue;

            case OP_LOADLOC10:
                B_reg = A_reg;
                A_reg = stack[-10];
                continue;

            case OP_LOADLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                continue;

            case OP_CAR:
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC6:
                B_reg = A_reg;
                A_reg = stack[-6];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC7:
                B_reg = A_reg;
                A_reg = stack[-7];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC9:
                B_reg = A_reg;
                A_reg = stack[-9];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC10:
                B_reg = A_reg;
                A_reg = stack[-10];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CARLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                if (car_legal(A_reg))
                {   A_reg = qcar(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_car;
                C_stack = stack;
                goto error_1_A;

            case OP_CDR:
                if (car_legal(A_reg))
                {   A_reg = qcdr(A_reg);
                    continue;
                }
                CSLerrcode = err_bad_cdr;
                C_stack = stack;
                goto error_1_A;

            case OP_STORELOC:
                stack[-(int)next_byte] = A_reg;
// NB this opcode does not pop the A/B stack
                continue;

            case OP_STORELOC0:
                stack[-0] = A_reg;
                continue;

            case OP_STORELOC1:
                stack[-1] = A_reg;
                continue;

            case OP_STORELOC2:
                stack[-2] = A_reg;
                continue;

            case OP_STORELOC3:
                stack[-3] = A_reg;
                continue;

            case OP_STORELOC4:
                stack[-4] = A_reg;
                continue;

            case OP_STORELOC5:
                stack[-5] = A_reg;
                continue;

            case OP_STORELOC6:
                stack[-6] = A_reg;
                continue;

            case OP_STORELOC7:
                stack[-7] = A_reg;
                continue;

            case OP_LOADLIT:
//
// Associated with each body of byte-codes there is a literal vector,
// and this opcode loads values from same.  The literal vector has a
// header word and is tagged as a Lisp vector.
//
                B_reg = A_reg;
                A_reg = elt(litvec, next_byte);
                continue;

            case OP_LOADLIT1:
                B_reg = A_reg;
                A_reg = elt(litvec, 1);
                continue;

            case OP_LOADLIT2:
                B_reg = A_reg;
                A_reg = elt(litvec, 2);
                continue;

            case OP_LOADLIT3:
                B_reg = A_reg;
                A_reg = elt(litvec, 3);
                continue;

            case OP_LOADLIT4:
                B_reg = A_reg;
                A_reg = elt(litvec, 4);
                continue;

            case OP_LOADLIT5:
                B_reg = A_reg;
                A_reg = elt(litvec, 5);
                continue;

            case OP_LOADLIT6:
                B_reg = A_reg;
                A_reg = elt(litvec, 6);
                continue;

            case OP_LOADLIT7:
                B_reg = A_reg;
                A_reg = elt(litvec, 7);
                continue;

            case OP_LOADFREE:
//
// Load the value of a free (GLOBAL, SPECIAL, FLUID) variable
//
                B_reg = A_reg;
                A_reg = qvalue(elt(litvec, next_byte));
                continue;

            case OP_LOADFREE1:
                B_reg = A_reg;
                A_reg = qvalue(elt(litvec, 1));
                continue;

            case OP_LOADFREE2:
                B_reg = A_reg;
                A_reg = qvalue(elt(litvec, 2));
                continue;

            case OP_LOADFREE3:
                B_reg = A_reg;
                A_reg = qvalue(elt(litvec, 3));
                continue;

            case OP_LOADFREE4:
                B_reg = A_reg;
                A_reg = qvalue(elt(litvec, 4));
                continue;

            case OP_JUMPNIL:
                xppc = ppc;
                ppc++;
                if (A_reg == nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPNIL_B:
                xppc = ppc;
                ppc++;
                if (A_reg == nil)
                {   ppc = ppc - *xppc;
//
// To ensure that all code is interruptable I poll on every backwards
// jump.  The SIGINT event simulates a stack overflow, and the
// consequent entry to the garbage collector then handles the event.
//
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPT:
                xppc = ppc;
                ppc++;
                if (A_reg != nil) ppc = ppc + *xppc;
                continue;

            case OP_JUMPT_B:
                xppc = ppc;
                ppc++;
                if (A_reg != nil)
                {   ppc = ppc - *xppc;
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPNIL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil) ppc = ppc + ((w << 8) + *xppc);
                continue;

            case OP_JUMPNIL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil)
                {   ppc = ppc - ((w << 8) + *xppc);
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_JUMPT_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != nil) ppc = ppc + ((w << 8) + *xppc);
                continue;

            case OP_JUMPT_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != nil)
                {   ppc = ppc - ((w << 8) + *xppc);
#ifndef OUT_OF_LINE
                    if (--countdown < 0) deal_with_tick();
                    if (stack >= stacklimit)
                    {   C_stack = stack;
                        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
                        nil = C_nil;
                        if (exception_pending()) goto error_exit;
                        stack = C_stack;        // may have been changed by GC
                    }
#else
                    if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
                        goto error_exit;
                    stack = C_stack;
#endif
                }
                continue;

            case OP_BUILTIN1:
                debug_assert(1);
                f1 = one_arg_functions[next_byte];
                debug_record_int("BUILTIN1", most_recent_byte);
// BUILTIN1:   A=fn(A);
                save_pc();
                C_stack = stack;
                A_reg = f1(nil, A_reg);
                debug_assert(1);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_BUILTIN2:
                debug_assert(1);
                f2 = two_arg_functions[next_byte];
                debug_record_int("BUILTIN2", most_recent_byte);
// BUILTIN2:   A=fn(B,A);
                save_pc();
                C_stack = stack;
                A_reg = f2(nil, B_reg, A_reg);
                debug_assert(1);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;
                restore_pc();
                continue;

            case OP_EXIT:
//
// Here I assume that exit_count has been set up already. Note also that
// there is no need to do any LOSE operations just before an EXIT since the
// stack gets reset automatically here.
//
                C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
#endif
                return A_reg;


            case OP_PUSH:
                push(A_reg);
                continue;

            case OP_PUSHNIL:
                push(nil);
                continue;

            case OP_PUSHNIL2:
                push2(nil, nil);
                continue;

            case OP_PUSHNIL3:
                push3(nil, nil, nil);
                continue;

            case OP_POP:
                B_reg = A_reg;
                pop(A_reg);
                continue;

            case OP_LOSE:
                popv(1);
                continue;

            case OP_LOSE2:
                popv(2);
                continue;

            case OP_LOSE3:
                popv(3);
                continue;

            case OP_LOSES:
                popv(next_byte);
                continue;

            case OP_CONS:                           // A_reg = cons(B_reg, A_reg);
#ifndef OUT_OF_LINE
                r1 = (LispObject)((char *)fringe - sizeof(Cons_Cell));
                qcar(r1) = B_reg;
                qcdr(r1) = A_reg;
                fringe = r1;
                if ((char *)r1 <= (char *)heaplimit)
                {   save_pc();
                    C_stack = stack;
                    A_reg = reclaim((LispObject)((char *)r1 + TAG_CONS),
                                    "bytecoded cons", GC_CONS, 0);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack;        // may have been changed by GC
                    restore_pc();
                }
                else A_reg = (LispObject)((char *)r1 + TAG_CONS);
#else
                save_pc();
                C_stack = stack;
                A_reg = cons(B_reg, A_reg);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack;        // may have been changed by GC
                restore_pc();
#endif
#ifdef DEBUG
                if (((int)A_reg & (2*CELL-1)) != 0)
                {   term_printf("badly aligned CONS\n");
                    ensure_screen();
                    abort();
                }
#endif
                continue;

//
// FASTGET n
//     0 <= n < 64       (GET A_reg property_n)
//    64 <= n < 128      (GET A_reg property_n B_reg)
//   128 <= n < 192      (FLAGP A_reg property_n)
//   192 <= n < 256      not used at present.
//
            case OP_FASTGET:
                w = next_byte;
#ifdef RECORD_GET
                n = 0;
#endif
                if (symbolp(A_reg))
                {   r1 = qfastgets(A_reg);
                    if (r1 == nil)
                    {   if (w & 0x40) A_reg = B_reg;
                        else A_reg = nil;
                    }
                    else
                    {   A_reg = elt(r1, w & 0x3f);
                        if (A_reg == SPID_NOPROP)
                        {   if (w & 0x40) A_reg = B_reg;
                            else A_reg = nil;
#ifdef RECORD_GET
                            n = 1;
#endif
                        }
                        else if (w & 0x80) A_reg = lisp_true;
                    }
                }
                else A_reg = nil;
#ifdef RECORD_GET
                save_pc(); C_stack = stack;
                record_get(elt(fastget_names, w & 0x7f), n);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack; restore_pc();
#endif
                continue;

            case OP_LITGET:
                B_reg = A_reg;
                A_reg = elt(litvec, next_byte);
                goto perform_get;

            case OP_GET:                                    // A = get(B, A)
                goto perform_get;

        }
//
// Now various code-fragments that want to be inside the "for (;;)" loop
// but outside the "switch".
//

    perform_get:
#ifdef COMMON
//
// This direct byte code supports the 2-argument version of GET. The
// 3-arg version should be done as a regular general call.
//
        save_pc(); C_stack = stack;
        A_reg = get(B_reg, A_reg, nil);
        nil = C_nil;
        if (exception_pending()) goto error_exit;
        stack = C_stack; restore_pc();
        continue;
#else
#ifndef OUT_OF_LINE
//
// Get is very heavily used - so I have in-lined it here since it is fairly
// short code and ought not to overload register allocation.  See "fns1.c"
// for the regular version of this code.
//
        if (!symbolp(B_reg))
        {
#ifdef RECORD_GET
            save_pc(); C_stack = stack;
            record_get(A_reg, false);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            stack = C_stack; restore_pc();
#endif
            A_reg = nil;
            continue;
        }
        else
        {   if (symbolp(A_reg) &&
                (n = header_fastget(qheader(A_reg))) != 0)
            {   if ((r1 = qfastgets(B_reg)) == nil)
                {
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(A_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    A_reg = nil;
                    continue;
                }
#ifdef RECORD_GET
                push(r1);
                save_pc(); C_stack = stack;
                record_get(A_reg, elt(r1, n-1) != nil);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack; restore_pc();
                pop(r1);
#endif
                A_reg = elt(r1, n-1);
                if (A_reg == SPID_NOPROP) A_reg = nil;
                continue;
            }
//
// I write out the check on the first two items in the property list
// longhand, expecting that a match will most often occur there.  If
// I get a match later on I will migrate the entry to the front of the list.
//
            r1 = qplist(B_reg);
            if (r1 == nil)
            {
#ifdef RECORD_GET
                save_pc(); C_stack = stack;
                record_get(A_reg, false);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack; restore_pc();
#endif
                A_reg = nil;
                continue;
            }
            r3 = qcar(r1);
            if (qcar(r3) == A_reg)
            {
#ifdef RECORD_GET
                save_pc(); C_stack = stack;
                record_get(A_reg, true);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack; restore_pc();
#endif
                A_reg = qcdr(r3);
                continue;
            }
            r1 = qcdr(r1);
            if (r1 == nil)
            {
#ifdef RECORD_GET
                save_pc(); C_stack = stack;
                record_get(A_reg, false);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack; restore_pc();
#endif
                A_reg = nil;
                continue;
            }
            r3 = qcar(r1);
            if (qcar(r3) == A_reg)
            {
#ifdef RECORD_GET
                save_pc(); C_stack = stack;
                record_get(A_reg, true);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack; restore_pc();
#endif
                A_reg = qcdr(r3);
                continue;
            }
            r2 = r1;
            r1 = qcdr(r1);
            if (r1 == nil)
            {
#ifdef RECORD_GET
                save_pc(); C_stack = stack;
                record_get(A_reg, false);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
                stack = C_stack; restore_pc();
#endif
                A_reg = nil;
                continue;
            }
            for (;;)
            {   r3 = qcar(r1);
                if (qcar(r3) == A_reg)
                {   qcdr(r2) = qcdr(r1);
                    qcdr(r1) = qplist(B_reg);
                    qplist(B_reg) = r1;
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(A_reg, true);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    A_reg = qcdr(r3);
                    break;
                }
                r2 = r1;
                r1 = qcdr(r1);
                if (r1 == nil)
                {
#ifdef RECORD_GET
                    save_pc(); C_stack = stack;
                    record_get(A_reg, false);
                    nil = C_nil;
                    if (exception_pending()) goto error_exit;
                    stack = C_stack; restore_pc();
#endif
                    A_reg = nil;
                    break;
                }
            }
        }
        continue;
#else
        save_pc(); C_stack = stack;
        A_reg = get(B_reg, A_reg);
        nil = C_nil;
        if (exception_pending()) goto error_exit;
        stack = C_stack; restore_pc();
        continue;
#endif
#endif

    caar:
        if (car_legal(A_reg)) A_reg = qcar(A_reg);
        else
        {   CSLerrcode = err_bad_car;
            C_stack = stack;
            goto error_1_A;
        }
        if (car_legal(A_reg))
        {   A_reg = qcar(A_reg);
            continue;
        }
        CSLerrcode = err_bad_car;
        C_stack = stack;
        goto error_1_A;

    catcher:
        A_reg = cons(A_reg, catch_tags);
        nil = C_nil;
        if (exception_pending()) goto error_exit;
        catch_tags = A_reg;
        push3(fixnum_of_int(w+1), catch_tags, SPID_CATCH);
        continue;

    call0:  r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
//
// NB I set fname to be the literal-vector offset in the line above so that
// it will be possible to find the name of the function that was called
// if I have to display a backtrace.
//
        f345 = qfnn(r1);
// CALL0:  A=fn()
#ifdef DEBUG
        if (f345 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
        save_pc();
        C_stack = stack;
        A_reg = f345(qenv(r1), 0);
        debug_assert(1);
        nil = C_nil;
        if (exception_pending()) goto call_error_exit;
        stack = C_stack;
        restore_pc();
        continue;

    jcall0: r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
        f345 = qfnn(r1);
#ifdef DEBUG
        if (f345 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
//
// The issue here is cases such as
//    (de f1 (x) (f2 x))
//    (de f2 (x) (f1 x))
// where the bodies of the functions so not do enough work that polling
// for interrupts or for window-system updates will happen. Thus it seems
// I need to perform a polling operation as part of the tail-call sequence.
//
#ifndef OUT_OF_LINE
        if (--countdown < 0) deal_with_tick();
        if (stack >= stacklimit)
        {   C_stack = stack;
            A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            stack = C_stack;        // may have been changed by GC
        }
#else
        if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
            goto error_exit;
        stack = C_stack;
#endif
        if (f345 == bytecoded0)
        {   lit = qenv(r1);
            codevec = qcar(lit);
            litvec = qcdr(lit);
#if defined DEBUG || !defined NO_BYTECOUNT
            ffsym = elt(litvec, 0);
            memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), 16);
            fflength = (int)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
            if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
            ffname[fflength] = 0;
#endif
            stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
            ppc = (unsigned char *)data_of_bps(codevec);
#ifndef NO_BYTECOUNT
            qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
            continue;
        }
        else if (f345 == tracebytecoded0 || f345 == tracesetbytecoded0)
        {   r2 = elt(litvec, 0);
            lit = qenv(r1);
            codevec = qcar(lit);
            litvec = qcdr(lit);
#if defined DEBUG || !defined NO_BYTECOUNT
            ffsym = elt(litvec, 0);
            memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), 16);
            fflength = (int)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
            if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
            ffname[fflength] = 0;
#endif
//
// I make TRACECODED a special case, in effect writing it out in-line
// here, to avoid some ugly confusion with backtraces following tail calls.
//
            stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
            push3(litvec, codevec, r2);
            C_stack = stack;
            trace_print_0(elt(litvec, 0), stack);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            popv(1);
            pop2(codevec, litvec);
            ppc = (unsigned char *)data_of_bps(codevec);
#ifndef NO_BYTECOUNT
            qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
            continue;
        }
        C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
        if (callstack != nil) callstack = qcdr(callstack);
        A_reg = f345(qenv(r1), 0);
        name_of_caller = NULL;
        return A_reg;
#else
        return f345(qenv(r1), 0);
#endif

    call1:  r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
        f1 = qfn1(r1);
#ifdef DEBUG
        if (f1 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
// CALL1:   A=fn(A);
        save_pc();
        C_stack = stack;
        A_reg = f1(qenv(r1), A_reg);
        debug_assert(1);
        nil = C_nil;
        if (exception_pending()) goto call_error_exit;
        stack = C_stack;
        restore_pc();
        continue;

    jcall1: r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
        f1 = qfn1(r1);
#ifdef DEBUG
        if (f1 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
//
// The issue here is cases such as
//    (de f1 (x) (f2 x))
//    (de f2 (x) (f1 x))
// where the bodies of the functions so not do enough work that polling
// for interrupts or for window-system updates will happen. Thus it seems
// I need to perform a polling operation as part of the tail-call sequence.
//
#ifndef OUT_OF_LINE
        if (--countdown < 0) deal_with_tick();
        if (stack >= stacklimit)
        {   C_stack = stack;
            A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            stack = C_stack;        // may have been changed by GC
        }
#else
        if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
            goto error_exit;
        stack = C_stack;
#endif
        if (f1 == bytecoded1)
        {   lit = qenv(r1);
            codevec = qcar(lit);
            litvec = qcdr(lit);
#if defined DEBUG || !defined NO_BYTECOUNT
            ffsym = elt(litvec, 0);
            memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), 16);
            fflength = (int)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
            if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
            ffname[fflength] = 0;
#endif
            stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
            push(A_reg);
            ppc = (unsigned char *)data_of_bps(codevec);
#ifndef NO_BYTECOUNT
            qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
            continue;
        }
        else if (f1 == tracebytecoded1 || f1 == tracesetbytecoded1)
        {   r2 = elt(litvec, 0);
            lit = qenv(r1);
            codevec = qcar(lit);
            litvec = qcdr(lit);
#if defined DEBUG || !defined NO_BYTECOUNT
            ffsym = elt(litvec, 0);
            memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), 16);
            fflength = (int)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
            if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
            ffname[fflength] = 0;
#endif
            stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
            push(A_reg);
            push3(litvec, codevec, r2);
            C_stack = stack;
            trace_print_1(elt(litvec, 0), stack);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            popv(1);
            pop2(codevec, litvec);
            ppc = (unsigned char *)data_of_bps(codevec);
#ifndef NO_BYTECOUNT
            qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
            continue;
        }
        C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
        if (callstack != nil) callstack = qcdr(callstack);
        A_reg = f1(qenv(r1), A_reg);
        name_of_caller = NULL;
        return A_reg;
#else
        return f1(qenv(r1), A_reg);
#endif

    call2:  r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
        f2 = qfn2(r1);
#ifdef DEBUG
        if (f2 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
// CALL2:   A=fn(B,A);
        save_pc();
        C_stack = stack;
        A_reg = f2(qenv(r1), B_reg, A_reg);
        debug_assert(1);
        nil = C_nil;
        if (exception_pending()) goto call_error_exit;
        stack = C_stack;
        restore_pc();
        continue;

    call2r: r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
        f2 = qfn2(r1);
#ifdef DEBUG
        if (f2 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
// CALL2R:   A=fn(A,B); NOTE arg order reversed
        save_pc();
        C_stack = stack;
        A_reg = f2(qenv(r1), A_reg, B_reg);
        debug_assert(1);
        nil = C_nil;
        if (exception_pending()) goto call_error_exit;
        stack = C_stack;
        restore_pc();
        continue;

    jcall2: r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
        f2 = qfn2(r1);
#ifdef DEBUG
        if (f2 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
//
// The issue here is cases such as
//    (de f1 (x) (f2 x))
//    (de f2 (x) (f1 x))
// where the bodies of the functions so not do enough work that polling
// for interrupts or for window-system updates will happen. Thus it seems
// I need to perform a polling operation as part of the tail-call sequence.
//
#ifndef OUT_OF_LINE
        if (--countdown < 0) deal_with_tick();
        if (stack >= stacklimit)
        {   C_stack = stack;
            A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            stack = C_stack;        // may have been changed by GC
        }
#else
        if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
            goto error_exit;
        stack = C_stack;
#endif
        if (f2 == bytecoded2)
        {   lit = qenv(r1);
            codevec = qcar(lit);
            litvec = qcdr(lit);
#if defined DEBUG || !defined NO_BYTECOUNT
            ffsym = elt(litvec, 0);
            memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), 16);
            fflength = (int)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
            if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
            ffname[fflength] = 0;
#endif
            stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
            push2(B_reg, A_reg);
            ppc = (unsigned char *)data_of_bps(codevec);
#ifndef NO_BYTECOUNT
            qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
            continue;
        }
        else if (f2 == tracebytecoded2 || f2 == tracesetbytecoded2)
        {   r2 = elt(litvec, 0);
            lit = qenv(r1);
            codevec = qcar(lit);
            litvec = qcdr(lit);
#if defined DEBUG || !defined NO_BYTECOUNT
            ffsym = elt(litvec, 0);
            memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), 16);
            fflength = (int)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
            if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
            ffname[fflength] = 0;
#endif
            stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
            push2(B_reg, A_reg);
            push3(litvec, codevec, r2);
            C_stack = stack;
            trace_print_2(elt(litvec, 0), stack);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            popv(1);
            pop2(codevec, litvec);
            ppc = (unsigned char *)data_of_bps(codevec);
#ifndef NO_BYTECOUNT
            qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
            continue;
        }
        C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
        if (callstack != nil) callstack = qcdr(callstack);
        A_reg = f2(qenv(r1), B_reg, A_reg);
        name_of_caller = NULL;
        return A_reg;
#else
        return f2(qenv(r1), B_reg, A_reg);
#endif

    call3:  r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
        f345 = qfnn(r1);
#ifdef DEBUG
        if (f345 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
// CALL3:   A=fn(pop(),B,A);
        save_pc();
        pop(r2);
        C_stack = stack;
        A_reg = f345(qenv(r1), 3, r2, B_reg, A_reg);
        debug_assert(1);
        nil = C_nil;
        if (exception_pending()) goto call_error_exit;
        stack = C_stack;
        restore_pc();
        continue;

    jcall3: r1 = elt(litvec, fname);
        debug_record_symbol(r1);
        debug_assert(1);
        f345 = qfnn(r1);
#ifdef DEBUG
        if (f345 == NULL)
        {   term_printf("Illegal function\n");
            my_exit(EXIT_FAILURE);
        }
#endif
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
        pop(r2);
//
// The issue here is cases such as
//    (de f1 (x) (f2 x))
//    (de f2 (x) (f1 x))
// where the bodies of the functions so not do enough work that polling
// for interrupts or for window-system updates will happen. Thus it seems
// I need to perform a polling operation as part of the tail-call sequence.
//
#ifndef OUT_OF_LINE
        if (--countdown < 0) deal_with_tick();
        if (stack >= stacklimit)
        {   C_stack = stack;
            A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            stack = C_stack;        // may have been changed by GC
        }
#else
        if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
            goto error_exit;
        stack = C_stack;
#endif
        if (f345 == bytecoded3)
        {   lit = qenv(r1);
            codevec = qcar(lit);
            litvec = qcdr(lit);
#if defined DEBUG || !defined NO_BYTECOUNT
            ffsym = elt(litvec, 0);
            memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), 16);
            fflength = (int)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
            if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
            ffname[fflength] = 0;
#endif
            stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
            push3(r2, B_reg, A_reg);
            ppc = (unsigned char *)data_of_bps(codevec);
#ifndef NO_BYTECOUNT
            qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
            continue;
        }
        else if (f345 == tracebytecoded3 || f345 == tracesetbytecoded3)
        {   r3 = elt(litvec, 0);
            lit = qenv(r1);
            codevec = qcar(lit);
            litvec = qcdr(lit);
#if defined DEBUG || !defined NO_BYTECOUNT
            ffsym = elt(litvec, 0);
            memcpy((void *)&ffname[0], &celt(qpname(ffsym), 0), 16);
            fflength = (int)(length_of_byteheader(vechdr(qpname(ffsym))) - CELL);
            if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
            ffname[fflength] = 0;
#endif
            stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
            push3(r2, B_reg, A_reg);
            push3(litvec, codevec, r3);
            C_stack = stack;
            trace_print_3(elt(litvec, 0), stack);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            popv(1);
            pop2(codevec, litvec);
            ppc = (unsigned char *)data_of_bps(codevec);
#ifndef NO_BYTECOUNT
            qcount(elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
            continue;
        }
        C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
        if (callstack != nil) callstack = qcdr(callstack);
        A_reg = f345(qenv(r1), 3, r2, B_reg, A_reg);
        name_of_caller = NULL;
        return A_reg;
#else
        return f345(qenv(r1), 3, r2, B_reg, A_reg);
#endif

    jcalln:
//
// The issue here is cases such as
//    (de f1 (x) (f2 x))
//    (de f2 (x) (f1 x))
// where the bodies of the functions so not do enough work that polling
// for interrupts or for window-system updates will happen. Thus it seems
// I need to perform a polling operation as part of the tail-call sequence.
//
#ifndef OUT_OF_LINE
        if (--countdown < 0) deal_with_tick();
        if (stack >= stacklimit)
        {   C_stack = stack;
            A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
            nil = C_nil;
            if (exception_pending()) goto error_exit;
            stack = C_stack;        // may have been changed by GC
        }
#else
        if ((A_reg = poll_jump_back(stack, A_reg)) == SPID_ERROR)
            goto error_exit;
        stack = C_stack;
#endif
//
// here I could shuffle the stack down quite a lot...
//
        push2(B_reg, A_reg);
        C_stack = stack;
        A_reg = elt(litvec, fname);
        debug_record_symbol(A_reg);
        debug_assert(1);
//
// Also if the function is byte-coded I can enter it more directly.
// It is strongly desirable that I do so so that backtraces will work
// better. However (at present) I have not implemented the hack tha
// would turn a jcalln into an iteration here. That is sort of a
// matter of laziness and because I had not expected it to be on
// too many critical paths. The first case where I feel it might have
// been mattering is the 4-arg general-reciprocal!-by!-gcd (which I have
// just re-written so that what happens here is irrelevant in that case!).
//
#ifndef NO_BYTECOUNT
        name_of_caller = (const char *)ffname;
#endif
        A_reg = apply(A_reg, (int)w, nil, A_reg, (1 & (int)(intptr_t)entry_stack));
        debug_assert(1);
        nil = C_nil;
        if (exception_pending()) goto ncall_error_exit;
        C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
        if (callstack != nil) callstack = qcdr(callstack);
        name_of_caller = NULL;
#endif
        return A_reg;

    create_closure:
        save_pc();
        A_reg = encapsulate_sp(&stack[-2-(int)w]);
        nil = C_nil;
        if (exception_pending()) goto error_exit;
        pop(B_reg);
        C_stack = stack;
        A_reg = list2star(cfunarg, B_reg, A_reg);
        nil = C_nil;
        if (exception_pending()) goto error_exit;
        stack = C_stack;        // may have been changed by GC
        restore_pc();
        pop(B_reg);
        continue;

        /*****************************************************************************/

    call_error_exit:
        flip_exception();
        C_stack = stack;
        goto pop_stack_and_exit;

    ncall_error_exit:
        flip_exception();
        goto pop_stack_and_exit;

    callself_error_exit:
        flip_exception();
        goto pop_stack_and_exit;

    stack_apply_error:
        {   flip_exception();
            stack = C_stack;
            pop(r1);
            C_stack = stack;
//
// I suspect that the next few lines are UNHELPFUL now, so maybe I should
// get rid of them...
//
            if (SHOW_FNAME)
            {   err_printf("apply: ");
                loop_print_error(r1);
                err_printf("\n");
                nil = C_nil;
                if (exception_pending()) flip_exception();
            }
        }
        goto pop_stack_and_exit;

    apply_error:
        flip_exception();
        C_stack = stack;
//
// I suspect that the next few lines are UNHELPFUL now, so maybe I should
// get rid of them...
//
        if (SHOW_FNAME)
        {   err_printf("apply: ");
            loop_print_error(A_reg);
            err_printf("\n");
            nil = C_nil;
            if (exception_pending()) flip_exception();
        }
        goto pop_stack_and_exit;

    error_exit:
        flip_exception();
        goto pop_stack_and_exit;

    error_1_A:
        C_stack = stack;
        error(1, CSLerrcode, A_reg);
        nil = C_nil;
        flip_exception();
        goto pop_stack_and_exit;

    pop_stack_and_exit:
        stack = C_stack;
//
// What follows is my current guess for a good diagnostic...
//
        if (SHOW_FNAME)
        {   err_printf("Inside: ");
            loop_print_error(elt(litvec, 0));
            err_printf("\n");
            nil = C_nil;
            if (exception_pending()) flip_exception();
        }
//
// Here I need to scan down the current stack-frame looking for either a
// CATCH or an UNWIND-PROTECT marker.
//
        for (;;)
        {   unwind_stack(((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1)), true);
            if (C_stack == ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1)))
            {   w = 0;
                break;
            }
// Here I have a CATCH/UNWIND record within the current function
            stack = C_stack;
            pop2(r1, r2);
            C_stack = stack;
//
// If the tag matches exit_tag then I must reset pc based on offset (r2)
// and continue. NB need to restore A_reg from exit_value.
//
            w = int_of_fixnum(r2);
            if (qcar(r1) == SPID_PROTECT)
            {   // This is an UNWIND catcher
                push2(exit_tag, fixnum_of_int(exit_reason));
#ifdef COMMON
                C_stack = stack;
                A_reg = Lmv_list(nil, exit_value);
                nil = C_nil;
                if (exception_pending()) goto error_exit;
#endif
                push(A_reg);
                ppc = (unsigned char *)data_of_bps(codevec) + w;
                w = 1;
                break;
            }
            else if (exit_reason == UNWIND_THROW && r1 == exit_tag)
            {   ppc = (unsigned char *)data_of_bps(codevec) + w;
                w = 1;
                break;
            }
        }
        if (w)
        {   A_reg = exit_value;
            continue;
        }
        C_stack = ((LispObject *)((intptr_t)entry_stack & ~(intptr_t)1));
#ifndef NO_BYTECOUNT
        if (callstack != nil) callstack = qcdr(callstack);
        name_of_caller = NULL;
#endif
        flip_exception();
        return nil;
    }
}

// end of bytes1.cpp
