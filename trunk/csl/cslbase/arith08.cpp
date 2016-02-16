//  arith08.cpp                       Copyright (C) 1990-2015 Codemist Ltd

//
// Arithmetic functions.
//

/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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


static LispObject Lboole(LispObject nil, int nargs, ...)
{   LispObject r, op, a, b;
    va_list aa;
    argcheck(nargs, 3, "boole");
    va_start(aa, nargs);
    op = va_arg(aa, LispObject);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    va_end(aa);
    switch (op)
    {   case fixnum_of_int(boole_clr):
            return onevalue(fixnum_of_int(0));
        case fixnum_of_int(boole_and):
            r = logand2(a, b);
            break;
        case fixnum_of_int(boole_andc2):
            push(a);
            b = lognot(b);
            pop(a);
            errexit();
            r = logand2(a, b);
            break;
        case fixnum_of_int(boole_1):
            return onevalue(a);
        case fixnum_of_int(boole_andc1):
            push(b);
            a = lognot(a);
            pop(b);
            errexit();
            r = logand2(a, b);
            break;
        case fixnum_of_int(boole_2):
            return onevalue(b);
        case fixnum_of_int(boole_xor):
            r = logxor2(a, b);
            break;
        case fixnum_of_int(boole_ior):
            r = logior2(a, b);
            break;
        case fixnum_of_int(boole_nor):
            a = logior2(a, b);
            errexit();
            r = lognot(a);
            break;
        case fixnum_of_int(boole_eqv):
            r = logeqv2(a, b);
            break;
        case fixnum_of_int(boole_c2):
            r = lognot(b);
            break;
        case fixnum_of_int(boole_orc2):
            b = lognot(b);
            errexit();
            r = logior2(a, b);
            break;
        case fixnum_of_int(boole_c1):
            r = lognot(a);
            break;
        case fixnum_of_int(boole_orc1):
            push(b);
            a = lognot(a);
            pop(b);
            errexit();
            r = logior2(a, b);
            break;
        case fixnum_of_int(boole_nand):
            a = logand2(a, b);
            errexit();
            r = lognot(a);
            break;
        case fixnum_of_int(boole_set):
            return onevalue(fixnum_of_int(-1));
        default:
            return aerror1("bad arg for boole",  op);
    }
    errexit();
    return onevalue(r);
}

#ifdef COMMON
static LispObject Lbyte(LispObject, LispObject a, LispObject b)
{   a = cons(a, b);
    errexit();
    return onevalue(a);
}

static LispObject Lbyte_position(LispObject, LispObject a)
{   if (!consp(a)) return aerror1("byte-position", a);
    else return onevalue(qcdr(a));
}

static LispObject Lbyte_size(LispObject, LispObject a)
{   if (!consp(a)) return aerror1("byte-size", a);
    else return onevalue(qcar(a));
}

static LispObject Lcomplex_2(LispObject, LispObject a, LispObject b)
{
// /* Need to coerce a and b to the same type here...
    a = make_complex(a, b);
    errexit();
    return onevalue(a);
}

static LispObject Lcomplex_1(LispObject, LispObject a)
{
// /* Need to make zero of same type as a
    a = make_complex(a, fixnum_of_int(0));
    errexit();
    return onevalue(a);
}

static LispObject Lconjugate(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("conjugate", a);
    if (is_numbers(a) && is_complex(a))
    {   LispObject r = real_part(a),
                       i = imag_part(a);
        push(r);
        i = negate(i);
        pop(r);
        errexit();
        a = make_complex(r, i);
        errexit();
        return onevalue(a);
    }
    else return onevalue(a);
}

static LispObject Ldenominator(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("denominator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(denominator(a));
    else return onevalue(fixnum_of_int(1));
}
#endif

#ifdef DEPOSIT_FIELD_IMPLEMENTED
static LispObject Ldeposit_field(LispObject, int nargs, ...)
{
//
// Not implemented yet!
//
    va_list aa;
    LispObject a, b, c;
    (void)nargs;   // should really check value
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    return aerror("deposit-field");
}
#endif

#ifdef DPB_IMPLEMENTED
static LispObject Ldpb(LispObject, int nargs, ...)
{
//
// Not implemented yet!
//
    va_list aa;
    LispObject a, b, c;
    (void)nargs;  // should really check value
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    return aerror("dpb");
}
#endif

#ifdef COMMON
static LispObject Lffloor(LispObject, LispObject, LispObject)
{
//
// Not implemented yet!
//
    return aerror("ffloor");
}
#endif

LispObject Lgcd_n(LispObject nil, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs == 0) return fixnum_of_int(0);
    va_start(a, nargs);
    push_args(a, nargs);
//
// The actual args have been passed a C args - I can not afford to
// risk garbage collection until they have all been moved somewhere safe,
// and here that safe place is the Lisp stack.  I have to delay checking for
// overflow on same until all args have been pushed.
//
    stackcheck0(nargs);
    pop(r);
    for (i = 1; i<nargs; i++)
    {   LispObject w;
        if (r == fixnum_of_int(1))
        {   popv(nargs-i);
            break;
        }
        pop(w);
        r = gcd(r, w);
        errexitn(nargs-i-1);
    }
    return onevalue(r);
}

LispObject Lgcd(LispObject nil, LispObject a, LispObject b)
{   a = gcd(a, b);
    errexit();
    return onevalue(a);
}

LispObject Lgcd_1(LispObject, LispObject a)
{   return onevalue(a);
}

#ifdef COMMON
static LispObject Limagpart(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("imagpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(imag_part(a));
// /* the 0.0 returned here ought to be the same type as a has
    else return onevalue(fixnum_of_int(0));
}

static LispObject Lldb(LispObject, LispObject, LispObject)
{
//
// Not implemented yet!
//
    return aerror("ldb");
}
#endif // COMMON

LispObject Llcm_n(LispObject nil, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(1));
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    pop(r);
    for (i = 1; i<nargs; i++)
    {   LispObject w;
        pop(w);
        r = lcm(r, w);
        errexitn(nargs-i-1);
    }
    return onevalue(r);
}

LispObject Llcm(LispObject nil, LispObject a, LispObject b)
{   a = lcm(a, b);
    errexit();
    return onevalue(a);
}

LispObject Llcm_1(LispObject, LispObject a)
{   return onevalue(a);
}

#ifdef COMMON
static LispObject Lldb_test(LispObject, LispObject, LispObject)
{
//
// Not implemented yet!
//
    return aerror("ldb-test");
}

static LispObject Lnumerator(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("numerator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(numerator(a));
    else return onevalue(a);
}

static LispObject Lrealpart(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("realpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(real_part(a));
    else return onevalue(a);
}
#endif // COMMON

//
// This now does special things for NaNs and infinities. For a NaN is just
// returns nil. For an infinity a returns an exponent value that is 1000000,
// much larger than any proper value.
// I iught to worry about negative zero tooo...
//

static LispObject Ldecode_float(LispObject nil, LispObject a)
{   double d, neg = 1.0;
    int x;
    LispObject sign;
    if (!is_float(a)) return aerror("decode-float");
    d = float_of_number(a);
    if (!(d == d)) return onevalue(nil); // a NaN
    if (d < 0.0 || (d == 0.0 && 1.0/d < 0)) d = -d, neg = -1.0;
    if (d == 0.0) x = 0;
    else if (1.0/d == 0.0)               // An infinity
    {   x = 1000000;                     // Extreme (arbitrary) value
    }
    else
    {   d = frexp(d, &x);
        if (d == 1.0) d = 0.5, x++;
    }
    if (is_sfloat(a)) sign = make_sfloat(neg);
    else sign = make_boxfloat(neg, type_of_header(flthdr(a)));
    errexit();
    push(sign);
    if (is_sfloat(a)) a = make_sfloat(d);
    else a = make_boxfloat(d, type_of_header(flthdr(a)));
    pop(sign);
    errexit();
#ifdef COMMON
//
// Until and unless Standard Lisp supports multiple values this has to
// return a list ion standard lisp mode.
//
    mv_2 = fixnum_of_int(x);
    mv_3 = sign;
    return nvalues(a, 3);
#else
    return list3(sign, fixnum_of_int(x), a);
#endif
}

//
// The next two functions depend on IEEE-format floating point numbers.
// They are (thus?) potentially a portability trap, but may suffice for
// MOST systems. I need to test the handling of double precision values
// on computers that store the two words of a double in each of the
// possible orders. If the exponent field in floats was not stored in the
// position that would be 0x7f800000 in an integer my treatment of short
// floats would fail, so I have already assumed that that is so. I think.
//
// These first two are now DEPRECATED in favour of fp-infinite etc defined
// just lower down... and I will now assume that all the machines I will ever
// use will use IEEE-style floating point. So goodbye some options used on
// old Vax and old System/360 and /370. And any system that uses roughly
// IEEE representation but does not support infinities and NaNs will cause
// pain.
//

static LispObject Lfloat_denormalized_p(LispObject nil, LispObject a)
{   int x = 0;
    switch ((int)a & TAG_BITS)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            if ((a & 0x7fffffff) == TAG_SFLOAT) return onevalue(nil);  // 0.0
            x = (int32_t)a & 0x7f800000;
            return onevalue(x == 0 ? lisp_true : nil);
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    if (single_float_val(a) == 0.0) return onevalue(nil);
                    x = ((Single_Float *)((char *)a-TAG_BOXFLOAT))->f.i & 0x7f800000;
                    return onevalue(x == 0 ? lisp_true : nil);
                case TYPE_LONG_FLOAT:
                    if (long_float_val(a) == 0.0) return onevalue(nil);
                    x = ((int32_t *)long_float_addr(a))[
                            current_fp_rep&FP_WORD_ORDER ? 0 : 1] & 0x7ff00000;
                    return onevalue(x == 0 ? lisp_true : nil);
                case TYPE_DOUBLE_FLOAT:
                    if (double_float_val(a) == 0.0) return onevalue(nil);
                    x = ((int32_t *)double_float_addr(a))[
                            current_fp_rep&FP_WORD_ORDER ? 0 : 1] & 0x7ff00000;
                    return onevalue(x == 0 ? lisp_true : nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

static LispObject Lfloat_infinity_p(LispObject nil, LispObject a)
{   int32_t x;
    switch ((int)a & TAG_BITS)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            x = (int32_t)a & 0x7f800000;
            return onevalue(x == 0x7f800000 ? lisp_true : nil);
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    if (1.0 / single_float_val(a) != 0.0) return onevalue(nil);
                    return onevalue(lisp_true);
                case TYPE_LONG_FLOAT:
                    if (1.0 / long_float_val(a) != 0.0) return onevalue(nil);
                    return onevalue(lisp_true);
                case TYPE_DOUBLE_FLOAT:
                    if (1.0 / double_float_val(a) != 0.0) return onevalue(nil);
                    return onevalue(lisp_true);
            }
        default:
            break;
    }
    return onevalue(nil);
}


//
// Now the newer IEEE-support functions...
//


//
// If I have a number d then if (1.0/d)==0.0 I think that d must have been
// infinite and not a NaN. One needs to be confident that for a HUGE (but
// finite) d that the reciprocal will not underflow - but IEEE subnormal
// numbers extend the range to make that OK. Note that if d==0.0 then 1.0/d
// will come out as an infinity (not raising an exception) so all will be OK!
//

static LispObject Lfp_infinite(LispObject nil, LispObject a)
{   int32_t x;
    switch ((int)a & TAG_BITS)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            x = (int32_t)a & 0x7f800000;
            return onevalue(x == 0x7f800000 ? lisp_true : nil);
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    if (1.0 / single_float_val(a) != 0.0) return onevalue(nil);
                    return onevalue(lisp_true);
                case TYPE_LONG_FLOAT:
                    if (1.0 / long_float_val(a) != 0.0) return onevalue(nil);
                    return onevalue(lisp_true);
                case TYPE_DOUBLE_FLOAT:
                    if (1.0 / double_float_val(a) != 0.0) return onevalue(nil);
                    return onevalue(lisp_true);
            }
        default:
            break;
    }
    return onevalue(nil);
}

//
// A NaN is not equal to even itself....
//

static LispObject Lfp_nan(LispObject nil, LispObject a)
{   int32_t x;
    switch ((int)a & TAG_BITS)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            a &= 0x7fffffff;
            if (a == 0x7f800000) return onevalue(nil);
            x = (int32_t)a & 0x7f800000;
            return onevalue(x == 0x7f800000 ? lisp_true : nil);
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    if (single_float_val(a) == single_float_val(a))
                        return onevalue(nil);
                    return onevalue(lisp_true);
                case TYPE_LONG_FLOAT:
                    if (long_float_val(a) == long_float_val(a))
                        return onevalue(nil);
                    return onevalue(lisp_true);
                case TYPE_DOUBLE_FLOAT:
// a NaN should not be equal even to itself, but beware any compiler that
// tries to be clever here and things otherwise!
//
                    if (double_float_val(a) == double_float_val(a))
                        return onevalue(nil);
                    return onevalue(lisp_true);
            }
        default:
            break;
    }
    return onevalue(nil);
}

//
// infinity/infinity => NaN
// NaN/NaN => NaN
// otherwise x/x => 1.0
//

static LispObject Lfp_finite(LispObject nil, LispObject a)
{   int32_t x;
    switch ((int)a & TAG_BITS)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            x = (int32_t)a & 0x7f800000;
            return onevalue(x != 0x7f800000 ? lisp_true : nil);
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                {   float f = single_float_val(a);
                    if (f-f == 0.0)
                        return onevalue(lisp_true);
                }
                return onevalue(nil);
                case TYPE_LONG_FLOAT:
                {   double f = long_float_val(a);
                    if (f-f == 0.0)
                        return onevalue(lisp_true);
                }
                return onevalue(nil);
//
// If something is infinite oa a NaN then subtracting it from itself yields
// a NaN. For any finite value the subtraction should give zero.
//
                case TYPE_DOUBLE_FLOAT:
                {   double f = double_float_val(a);
                    if (f-f == 0.0)
                        return onevalue(lisp_true);
                }
                return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

//
// I detect sub-normalised numbers by looking at the bit pattern that
// represents them. I could instead just have carefully specified
// constants the give the threshold below which values fall into this
// state.
//

static LispObject Lfp_subnorm(LispObject nil, LispObject a)
{   int32_t x = 0;
    switch ((int)a & TAG_BITS)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            if ((a & 0x7fffffff) == TAG_SFLOAT) return onevalue(nil);  // 0.0
            x = (int32_t)a & 0x7f800000;
            return onevalue(x == 0 ? lisp_true : nil);
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    if (single_float_val(a) == 0.0) return onevalue(nil);
                    x = ((Single_Float *)((char *)a-TAG_BOXFLOAT))->f.i & 0x7f800000;
                    return onevalue(x == 0 ? lisp_true : nil);
                case TYPE_LONG_FLOAT:
                    if (long_float_val(a) == 0.0) return onevalue(nil);
                    x = ((int32_t *)long_float_addr(a))[
                            current_fp_rep&FP_WORD_ORDER ? 0 : 1] & 0x7ff00000;
                    return onevalue(x == 0 ? lisp_true : nil);
                case TYPE_DOUBLE_FLOAT:
                    if (double_float_val(a) == 0.0) return onevalue(nil);
                    x = ((int32_t *)double_float_addr(a))[
                            current_fp_rep&FP_WORD_ORDER ? 0 : 1] & 0x7ff00000;
                    return onevalue(x == 0 ? lisp_true : nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

//
// This will return T if its argument has its sign bit set. Note that this
// NOT the same a test (x < 0) because this function returns T for -0.0.
//

static LispObject Lfp_signbit(LispObject nil, LispObject a)
{
#ifndef HAVE_SIGNBIT
    int32_t x = 0;
#endif
    switch ((int)a & TAG_BITS)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            if ((int32_t)a < 0) return onevalue(lisp_true);
            else return onevalue(nil);
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
#ifdef HAVE_SIGNBIT
                    return onevalue(signbit(single_float_val(a)) ? lisp_true : nil);
#else
                    x = ((Single_Float *)((char *)a-TAG_BOXFLOAT))->f.i;
// If the integer representation is negative then the sign bit is set.
                    return onevalue(x < 0 ? lisp_true : nil);
#endif
                case TYPE_LONG_FLOAT:
#ifdef HAVE_SIGNBIT
                    return onevalue(signbit(long_float_val(a)) ? lisp_true : nil);
#else
                    x = ((int32_t *)long_float_addr(a))[
                            current_fp_rep&FP_WORD_ORDER ? 0 : 1];
                    return onevalue(x < 0 ? lisp_true : nil);
#endif
                case TYPE_DOUBLE_FLOAT:
#ifdef HAVE_SIGNBIT
                    return onevalue(signbit(double_float_val(a)) ? lisp_true : nil);
#else
                    x = ((int32_t *)double_float_addr(a))[
                            current_fp_rep&FP_WORD_ORDER ? 0 : 1];
                    return onevalue(x < 0 ? lisp_true : nil);
#endif
            }
        default:
            break;
    }
    return onevalue(nil);
}


//
// The functions such as float-digits, float-precision, float-radix are
// coded here assuming that IEEE-style arithmetic is being used. If this is
// not so then all the code in this file needs review.  Furthermore I will
// be lazy about NaNs and denormalised numbers for now and come back to
// worry about them later on if I am really forced to.
//

static LispObject Lfloat_digits(LispObject, LispObject a)
{   int tag = (int)a & TAG_BITS;
    switch (tag)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            return onevalue(fixnum_of_int(20));
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    return onevalue(fixnum_of_int(24));
                default:
                    return onevalue(fixnum_of_int(53));
            }
        default:
            return aerror("float-digits");
    }
}

static LispObject Lfloat_precision(LispObject, LispObject a)
{   int tag = (int)a & TAG_BITS;
    double d = float_of_number(a);
    if (d == 0.0) return onevalue(fixnum_of_int(0));
// /* I do not cope with de-normalised numbers here
    switch (tag)
    {
#ifndef EXPERIMENT
        case TAG_SFLOAT:
            return onevalue(fixnum_of_int(20));
#endif
        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    return onevalue(fixnum_of_int(24));
                default:
// Beware here if long floats ever exist!
                    return onevalue(fixnum_of_int(53));
            }
        default:
            return aerror("float-precision");
    }
}

static LispObject Lfloat_radix(LispObject, LispObject)
{   return onevalue(fixnum_of_int(FLT_RADIX));
}

static LispObject Lfloat_sign2(LispObject, LispObject a, LispObject b)
{   double d = float_of_number(b);
// Worry a bit about -0.0 here
    if (float_of_number(a) < 0.0) d = -d;
    if (is_sfloat(b)) return onevalue(make_sfloat(d));
    else if (!is_bfloat(b)) return aerror1("bad arg for float-sign",  b);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(b))));
}

static LispObject Lfloat_sign1(LispObject, LispObject a)
{   double d = float_of_number(a);
// worry a bit about -0.0 here
    if (d < 0.0) d = -1.0; else d = 1.0;
    if (is_sfloat(a)) return onevalue(make_sfloat(d));
    else if (!is_bfloat(a)) return aerror1("bad arg for float-sign",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

#ifdef ROUND_AND_TRUNCATE
static LispObject Lfround(LispObject, LispObject, LispObject)
{   return aerror("fround");
}

static LispObject Lftruncate(LispObject, LispObject, LispObject)
{   return aerror("ftruncate");
}
#endif

//
// This may need to worry about NaNs and infinities.
//

static LispObject Linteger_decode_float(LispObject nil, LispObject a)
{   double d;
    int tag = (int)a & TAG_BITS;
    int x, neg = 0;
    int32_t a1, a2;
    if (!is_float(a)) return aerror("integer-decode-float");
    d = float_of_number(a);
    if (!(d == d)) return onevalue(nil);
    if (d == 0.0)
#ifdef COMMON
    {   mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(d<0 ? -1 : 1);
        nvalues(fixnum_of_int(0), 3);
    }
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(d<0 ? -1 : 1));
#endif
    if (d < 0.0 || (d == 0.0 && 1.0/d < 0)) d = -d, neg = 1;
    if (1.0/d == 0.0)
    {   a = fixnum_of_int(1);
        x = 1000000;
    }
    else
    {   d = frexp(d, &x);
        if (d == 1.0) d = 0.5, x++;
#ifndef EXPERIMENT
        if (tag == TAG_SFLOAT)
        {   d *= TWO_20;
            x -= 20;
            a1 = (int32_t)d;
            a = fixnum_of_int(a1);
        }
        else
#endif
        if (tag == TAG_BOXFLOAT &&
                 type_of_header(flthdr(a)) == TYPE_SINGLE_FLOAT)
        {   d *= TWO_24;
            x -= 24;
            a1 = (int32_t)d;
            a = fixnum_of_int(a1);
        }
        else
        {   d *= TWO_22;
            a1 = (int32_t)d;
            d -= (double)a1;
            a2 = (int32_t)(d*TWO_31);  // This conversion should be exact
            x -= 53;
            a = make_two_word_bignum(a1, a2);
            errexit();
        }
    }
#ifdef COMMON
    {   mv_2 = fixnum_of_int(x);
        mv_3 = neg ? fixnum_of_int(-1) : fixnum_of_int(1);
        return nvalues(a, 3);
    }
#else
    return list3(a, fixnum_of_int(x),
                 neg ? fixnum_of_int(-1) : fixnum_of_int(1));
#endif
}

static LispObject Linteger_length(LispObject nil, LispObject a)
{   a = Labsval(nil, a);
    errexit();
    return Lmsd(nil, a);
}

#if LOGFNS
static LispObject Llogbitp(LispObject, LispObject, LispObject)
{   return aerror("logbitp");
}

static LispObject Llogcount(LispObject, LispObject)
{   return aerror("logcount");
}

static LispObject Llogtest(LispObject, LispObject, LispObject)
{   return aerror("logtest");
}

static LispObject Lmask_field(LispObject, LispObject, LispObject)
{   return aerror("mask-field");
}
#endif

static LispObject Lscale_float(LispObject, LispObject a, LispObject b)
{   double d = float_of_number(a);
    if (!is_fixnum(b)) return aerror("scale-float");
    d = ldexp(d, int_of_fixnum(b));
    if (is_sfloat(a)) return onevalue(make_sfloat(d));
    else if (!is_bfloat(a)) return aerror1("bad arg for scale-float",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

#define FIX_TRUNCATE 0
#define FIX_ROUND    1
#define FIX_FLOOR    2
#define FIX_CEILING  3

static LispObject lisp_fix_sub(LispObject a, int roundmode)
//
// This converts from a double to a Lisp integer, which will
// quite often have to be a bignum.  No overflow is permitted - the
// result can always be accurate.
//
{   int32_t a0, a1, a2, a3;
    int x, x1;
    bool negative;
    double d = float_of_number(a);
    if (!(d == d)) return aerror("NaN in fix");
    if (1.0/d == 0.0) return aerror("infinity in fix");
    if (M2_31_1 < d && d < TWO_31)
    {   int32_t a = (int32_t)d;
//
// If my floating point value is in the range -(2^31+1) to +2^31 (exclusive)
// then when C truncates it I will get an integer in the inclusive range
// from -2^31 to 2^31-1, i.e. the whole range of C 32-bit integers.
// If I then apply a rounding mode other than truncation I may just have
// overflow, which I have to detect specially.
//
        int32_t w;
        double f;
        switch (roundmode)
        {   case FIX_TRUNCATE:
                break;          // C casts truncate, so this is OK
            case FIX_ROUND:
                f = d - (double)a;
                if (f > 0.5)
                {   if (a == 0x7fffffff) return make_two_word_bignum(1, 0);
                    else a++;
                }
                else if (f < -0.5)
                {   if (a == ~0x7fffffff)
                        return make_two_word_bignum(-2, 0x7fffffff);
                    else a--;
                }
                // The rounding rule on the next lines show what I do in 1/2ulp cases
                else if (f == 0.5) a = (a+1) & ~1;
                else if (f == -0.5)
                {   if (a == ~0x7fffffff)
                        return make_two_word_bignum(-2, 0x7fffffff);
                    else a = a & ~1;
                }
                break;
            case FIX_FLOOR:
                f = d - (double)a;
                if (f < 0.0)
                {   if (a == ~0x7fffffff)
                        return make_two_word_bignum(-2, 0x7fffffff);
                    else a--;
                }
                break;
            case FIX_CEILING:
                f = d - (double)a;
                if (f > 0.0)
                {   if (a == 0x7fffffff) return make_two_word_bignum(1, 0);
                    else a++;
                }
                break;
        }
        w = a & fix_mask;
        if (w == 0 || w == fix_mask) return fixnum_of_int(a);
        else if (!signed_overflow(a)) return make_one_word_bignum(a);
        else if (a > 0) return make_two_word_bignum(0, a);
        else return make_two_word_bignum(-1, clear_top_bit(a));
    }
    if (d < 0.0) d = -d, negative = true;
    else negative = false;
    d = frexp(d, &x); // 0.5 <= abs(d) < 1.0, x = the (binary) exponent
    if (d == 1.0) d = 0.5, x++;
    d *= TWO_31;
    a1 = (int32_t)d;      // 2^31 > d >= 2^30
    d -= (double)a1;
    a2 = (uint32_t)(d*TWO_31);  // This conversion should be exact
    if (negative)
    {   if (a2 == 0) a1 = -a1;
        else a2 = clear_top_bit(-a2), a1 = ~a1;
    }
    x -= 62;
    if (x < 0)              // Need to shift right x places
    {   x = -x;             // The shift amount here can be 31 at most...
        a3 = a2 << (32 - x);
        a2 = clear_top_bit((a2 >> x) | (a1 << (31 - x)));
        a1 = ASR(a1, x);
        switch (roundmode)
        {   case FIX_TRUNCATE:
                if (a1 < 0 && a3 != 0)  // proper rounding on -ve values
                {   a2++;
                    if (a2 < 0) // carry
                    {   a2 = 0;
                        a1++;
                    }
                }
                break;
            case FIX_ROUND:
                if ((a3 & 0x80000000U) != 0 &&
                    (a3 != ~0x7fffffff || (a2 & 1) != 0))
                {   a2++;
                    if (a2 < 0) // carry
                    {   a2 = 0;
                        a1++;
                    }
                }
                break;
            case FIX_FLOOR: // Comes out in wash of 2's complement
                break;
            case FIX_CEILING:
                if (a3 != 0)
                {   a2++;
                    if (a2 < 0) // carry
                    {   a2 = 0;
                        a1++;
                    }
                }
                break;
        }
        return make_two_word_bignum(a1, a2);
    }
// Now the double-length value (a1,a2) is correct and exact, and it
// needs shifting left by x bits.  This will give a 3 or more word bignum.
// Note that no rounding etc is needed at all here since there are no
// fractional bits in the representation.
//
    if (a1 < 0)
    {   a0 = -1;
        a1 = clear_top_bit(a1);
    }
    else a0 = 0;
    x1 = x / 31;
    x = x % 31;
    a0 = (a0 << x) | (a1 >> (31-x));
    a1 = clear_top_bit(a1 << x) | (a2 >> (31-x));
    a2 = clear_top_bit(a2 << x);
    return make_n_word_bignum(a0, a1, a2, x1);
}

static LispObject lisp_fix_ratio(LispObject a, int roundmode)
//
// This converts from a ratio to a Lisp integer.  It has to apply
// the specified rounding regime.
//
{   LispObject p, q, r, nil = C_nil;
    p = numerator(a);
    q = denominator(a);
    push2(q, p);
    r = quot2(p, q);
    errexitn(2);
    p = stack[0];
    stack[0] = r;
    p = Cremainder(p, stack[-1]);
    pop2(r, q);
    errexit();
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
            // /* This case unfinished at present
            break;
        case FIX_FLOOR:
            if (minusp(p))
            {   push(r);
                p = plus2(p, q);
                pop(r);
                errexit();
                r = sub1(r);
                errexit();
            }
            break;
        case FIX_CEILING:
            if (plusp(p))
            {   push(r);
                p = difference2(p, q);
                pop(r);
                errexit();
                r = add1(r);
                errexit();
            }
            break;
    }
    mv_2 = p;
    return nvalues(r, 2);
}

static LispObject lisp_fix(LispObject a, int roundmode)
{   LispObject r, nil;
    push(a);
    r = lisp_fix_sub(a, roundmode);
    errexitn(1);
    a = stack[0];
    stack[0] = r;
    a = difference2(a, r);
    pop(r);
    errexit();
    mv_2 = a;
    return nvalues(r, 2);
}

static LispObject lisp_ifix(LispObject a, LispObject b, int roundmode)
{   LispObject q, r, nil;
    if (is_float(a) || is_float(b))
    {   double p = float_of_number(a), q = float_of_number(b), d = p/q;
        a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
        errexit();
        r = lisp_fix(a, roundmode);
        errexit();
        push(r);
        a = make_boxfloat(float_of_number(mv_2)*q, TYPE_DOUBLE_FLOAT);
        pop(r);
        errexit();
        mv_2 = a;
        return nvalues(r, 2);
    }
    push2(a, b);
    q = quot2(a, b);
    errexitn(2);
    a = stack[-1];
    b = stack[0];
    push(q);
    r = Cremainder(a, b);
    errexitn(3);
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
            popv(3); return aerror("two-arg ROUND");
        case FIX_FLOOR:
            if (!minusp(r)) break;
            r = plus2(r, stack[-1]);
            errexitn(3);
            q = stack[0];
            push(r);
            q = sub1(q);
            pop(r);
            errexitn(3);
            stack[0] = q;
            break;
        case FIX_CEILING:
            if (!plusp(r)) break;
            r = difference2(r, stack[-1]);
            errexitn(3);
            q = stack[0];
            push(r);
            q = add1(q);
            pop(r);
            errexitn(3);
            stack[0] = q;
            break;
    }
    pop3(q, b, a);
    mv_2 = r;
    return nvalues(q, 2);
}

//
// So far I have not implemented support for rational numbers in the 2-arg
// versions of these functions. /*
//

static LispObject Lceiling_2(LispObject, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) return aerror1("ceiling", a);
    return lisp_ifix(a, b, FIX_CEILING);
}

static LispObject Lfloor_2(LispObject, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) return aerror1("floor", a);
    return lisp_ifix(a, b, FIX_FLOOR);
}

static LispObject Lround_2(LispObject, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) return aerror1("round", a);
    return lisp_ifix(a, b, FIX_ROUND);
}

LispObject Ltruncate_2(LispObject, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) return aerror1("truncate", a);
    return lisp_ifix(a, b, FIX_TRUNCATE);
}

static LispObject Lceiling(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("ceiling", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_CEILING);
    if (!is_float(a))
    {   mv_2 = fixnum_of_int(0);
        return nvalues(a, 2);
    }
    return lisp_fix(a, FIX_CEILING);
}

static LispObject Lfloor(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("floor", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_FLOOR);
    if (!is_float(a))
    {   mv_2 = fixnum_of_int(0);
        return nvalues(a, 2);
    }
    return lisp_fix(a, FIX_FLOOR);
}

static LispObject Lround(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("round", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_ROUND);
    if (!is_float(a))
    {   mv_2 = fixnum_of_int(0);
        return nvalues(a, 2);
    }
    return lisp_fix(a, FIX_ROUND);
}

LispObject Ltruncate(LispObject, LispObject a)
{   if (!is_number(a)) return aerror1("fix", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_TRUNCATE);
    if (!is_float(a))
    {   mv_2 = fixnum_of_int(0);
        return nvalues(a, 2);
    }
    return lisp_fix(a, FIX_TRUNCATE);
}

setup_type const arith08_setup[] =
{   {"ceiling",                 Lceiling, Lceiling_2, wrong_no_1},
    {"floor",                   Lfloor, Lfloor_2, wrong_no_1},
    {"round",                   Lround, Lround_2, wrong_no_1},
    {"fix",                     Ltruncate, Ltruncate_2, wrong_no_1},
    {"truncate",                Ltruncate, Ltruncate_2, wrong_no_1},
    {"decode-float",            Ldecode_float, too_many_1, wrong_no_1},
    {"float-denormalized-p",    Lfloat_denormalized_p, too_many_1, wrong_no_1},
    {"float-infinity-p",        Lfloat_infinity_p, too_many_1, wrong_no_1},
//
// The next are four functions that are new as of March 2015 - introduced
// as a start towards support for the special IEEE values. They replace the
// two above, which I hereby deprecate (and I expect that nobody has ever
// used anyway).
//
    {"fp-infinite",             Lfp_infinite, too_many_1, wrong_no_1},
    {"fp-nan",                  Lfp_nan, too_many_1, wrong_no_1},
    {"fp-finite",               Lfp_finite, too_many_1, wrong_no_1},
    {"fp-subnorm",              Lfp_subnorm, too_many_1, wrong_no_1},
    {"fp-signbit",              Lfp_signbit, too_many_1, wrong_no_1},
    {"integer-decode-float",    Linteger_decode_float, too_many_1, wrong_no_1},
    {"integer-length",          Linteger_length, too_many_1, wrong_no_1},
    {"float-digits",            Lfloat_digits, too_many_1, wrong_no_1},
    {"float-precision",         Lfloat_precision, too_many_1, wrong_no_1},
    {"float-radix",             Lfloat_radix, too_many_1, wrong_no_1},
    {"float-sign",              Lfloat_sign1, Lfloat_sign2, wrong_no_2},
#ifdef ROUND_AND_TRUNCATE
    {"fround",                  too_few_2, Lfround, wrong_no_2},
    {"ftruncate",               too_few_2, Lftruncate, wrong_no_2},
#endif
#ifdef LOGFNS
    {"logbitp",                 too_few_2, Llogbitp, wrong_no_2},
    {"logcount",                Llogcount, too_many_1, wrong_no_1},
    {"logtest",                 too_few_2, Llogtest, wrong_no_2},
    {"mask-field",              too_few_2, Lmask_field, wrong_no_2},
#endif
    {"scale-float",             too_few_2, Lscale_float, wrong_no_2},
    {"boole",                   wrong_no_na, wrong_no_nb, Lboole},
#ifdef COMMON
    {"byte",                    too_few_2, Lbyte, wrong_no_2},
    {"byte-position",           Lbyte_position, too_many_1, wrong_no_1},
    {"byte-size",               Lbyte_size, too_many_1, wrong_no_1},
    {"complex",                 Lcomplex_1, Lcomplex_2, wrong_no_2},
    {"conjugate",               Lconjugate, too_many_1, wrong_no_1},
#endif
    {"decode-float",            Ldecode_float, too_many_1, wrong_no_1},
    {"float-denormalized-p",    Lfloat_denormalized_p, too_many_1, wrong_no_1},
    {"float-infinity-p",        Lfloat_infinity_p, too_many_1, wrong_no_1},
#ifdef COMMON
    {"denominator",             Ldenominator, too_many_1, wrong_no_1},
#endif
#ifdef DEPOSIT_FIELD_IMPLEMENTED
    {"deposit-field",           wrong_no_na, wrong_no_nb, Ldeposit_field},
#endif
#ifdef DPB_IMPLEMENTED
    {"dpb",                     wrong_no_na, wrong_no_nb, Ldpb},
#endif
#ifdef COMMON
    {"ffloor",                  too_few_2, Lffloor, wrong_no_2},
    {"imagpart",                Limagpart, too_many_1, wrong_no_1},
    {"ldb",                     too_few_2, Lldb, wrong_no_2},
    {"ldb-test",                too_few_2, Lldb_test, wrong_no_2},
    {"numerator",               Lnumerator, too_many_1, wrong_no_1},
    {"realpart",                Lrealpart, too_many_1, wrong_no_1},
#endif
    {"gcd",                     Lgcd_1, Lgcd, Lgcd_n},
    {"gcdn",                    Lgcd_1, Lgcd, Lgcd_n},
    {"lcmn",                    Llcm_1, Llcm, Llcm_n},
    {NULL,                      0,0,0}
};

// end of arith08.cpp
