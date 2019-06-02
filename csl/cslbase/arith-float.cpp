// arith-float.cpp                              Copyright (C) 2019 Codemist

#ifdef ARITHLIB

// $Id$


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

#include "headers.h"
#include "dispatch.h"

using number_dispatcher::Fixnum;
// uint64_t *
using number_dispatcher::Rat;
using number_dispatcher::Cpx;
using number_dispatcher::SFlt;
// double
using number_dispatcher::Flt;
using number_dispatcher::LFlt;

LispObject Float::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Float>("float", a);
}

// A mere cast to double here would not guarantee the rounding mode in
// cases that the integer was longer than 52 bits.
LispObject Float::op(Fixnum a)
{   return make_boxfloat(arithlib_lowlevel::Double::op(a.intval()));
}

// In this next one note thar atithlib has a class Float that converts
// to a C++ float and a separate one called Double that converts to a
// C++ double and hence is what I need here!
LispObject Float::op(uint64_t *a)
{   return make_boxfloat(arithlib_lowlevel::Double::op(a));
}

LispObject Float::op(Rat a)
{   aerror("float of rat not coded yet");
//    return Float::op(a.numerator()) / Float::op(a.denominator());
}

LispObject Float::op(Cpx a)
{   aerror1("bad argument for float", a.value());
}

LispObject Float::op(SFlt a)
{   return make_boxfloat(a.floatval());
}

LispObject Float::op(Flt a)
{   return make_boxfloat(a.floatval());
}

LispObject Float::op(double a)
{   return make_boxfloat(a);
}

LispObject Float::op(LFlt a)
{   float64_t f = f128_to_f64(a.floatval());
// Ha ha - the jolly activity here is a response to the Strict Aliasing Rules
// that (I believe) allow me to feel safe if I move things treating it as
// byte data.
    double d;
    memcpy(&d, &f, sizeof(double));
    return make_boxfloat(d);
}

LispObject Float128::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Float128>("float128", a);
}

LispObject Float128::op(Fixnum a)
{   return make_boxfloat128(i64_to_f128(a.intval()));
}

LispObject Float128::op(uint64_t *a)
{   return make_boxfloat128(arithlib_lowlevel::Float128::op(a));
}

LispObject Float128::op(Rat a)
{   aerror("floating a rat not implemented yet");
//return f128_div(Float128::op(a.numerator()), Float128::op(a.denominator()));
}

LispObject Float128::op(Cpx a)
{   aerror1("bad argument for float128", a.value());
}

LispObject Float128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(double a)
{   double d = a;
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(LFlt a)
{   return a.value();
}

double RawFloat::op(LispObject a)
{   return number_dispatcher::unary<double,RawFloat>("float", a);
}

double RawFloat::op(Fixnum a)
{   return arithlib_lowlevel::Double::op(a.intval());
}

double RawFloat::op(uint64_t *a)
{   return arithlib_lowlevel::Double::op(a);
}

double RawFloat::op(Rat a)
{   int64_t px, qx;
    double p = number_dispatcher::unary<double,Frexp>("frexp", a.numerator(), px);
    double q = number_dispatcher::unary<double,Frexp>("frexp", a.denominator(), qx);
    return std::ldexp(p/q, px-qx);
}

double RawFloat::op(Cpx a)
{   aerror1("bad argument for float", a.value());
}

double RawFloat::op(SFlt a)
{   return a.floatval();
}

double RawFloat::op(Flt a)
{   return a.floatval();
}

double RawFloat::op(double a)
{   return a;
}

double RawFloat::op(LFlt a)
{   float64_t f = f128_to_f64(a.floatval());
// Ha ha - the jolly activity here is a response to the Strict Aliasing Rules
// that (I believe) allow me to feel safe if I move things treating it as
// byte data.
    double d;
    memcpy(&d, &f, sizeof(double));
    return d;
}

float128_t RawFloat128::op(LispObject a)
{   return number_dispatcher::unary<float128_t,RawFloat128>("float128", a);
}

float128_t RawFloat128::op(Fixnum a)
{   return i64_to_f128(a.intval());
}

float128_t RawFloat128::op(uint64_t *a)
{   return arithlib_lowlevel::Float128::op(a);
}

float128_t RawFloat128::op(Rat a)
{   int64_t px, qx;
    float128_t p = Frexp128::op(a.numerator(), px);
    float128_t q = Frexp128::op(a.denominator(), qx);
    float128_t d = f128_div(p, q);
    f128M_ldexp(&d, px-qx);
    return d;
}

float128_t RawFloat128::op(Cpx a)
{   aerror1("bad argument for float128", a.value());
}

float128_t RawFloat128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t RawFloat128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t RawFloat128::op(double a)
{   double d = a;
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t RawFloat128::op(LFlt a)
{   return a.floatval();
}

LispObject Fix::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Fix>("fix", a);
}

LispObject Fix::op(Fixnum a)
{   return a.value();
}

LispObject Fix::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Fix::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Fix::op(Cpx a)
{   aerror1("bad argument for fix", a.value());
}

LispObject Fix::op(SFlt a)
{   return arithlib_lowlevel::double_to_bignum(a.floatval());
}

LispObject Fix::op(Flt a)
{   return arithlib_lowlevel::double_to_bignum(a.floatval());
}

LispObject Fix::op(double a)
{   return arithlib_lowlevel::double_to_bignum(a);
}

LispObject Fix::op(LFlt a)
{   return arithlib_lowlevel::float128_to_bignum(a.floatval());
}

LispObject Floor::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Floor>("floor", a);
}

LispObject Floor::op(Fixnum a)
{   return a.value();
}

LispObject Floor::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Floor::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Floor(Rat)")
}

LispObject Floor::op(Cpx a)
{   aerror1("bad argument for floor", a.value());
}

LispObject Floor::op(SFlt a)
{   return arithlib_lowlevel::double_to_floor(a.floatval());
}

LispObject Floor::op(Flt a)
{   return arithlib_lowlevel::double_to_floor(a.floatval());
}

LispObject Floor::op(double a)
{   return arithlib_lowlevel::double_to_floor(a);
}

LispObject Floor::op(LFlt a)
{   return arithlib_lowlevel::float128_to_floor(a.floatval());
}

LispObject Ceiling::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Ceiling>("ceiling", a);
}

LispObject Ceiling::op(Fixnum a)
{   return a.value();
}

LispObject Ceiling::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Ceiling::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Ceiling(Rat)")
}

LispObject Ceiling::op(Cpx a)
{   aerror1("bad argument for ceiling", a.value());
}

LispObject Ceiling::op(SFlt a)
{   return arithlib_lowlevel::double_to_ceiling(a.floatval());
}

LispObject Ceiling::op(Flt a)
{   return arithlib_lowlevel::double_to_ceiling(a.floatval());
}

LispObject Ceiling::op(double a)
{   return arithlib_lowlevel::double_to_ceiling(a);
}

LispObject Ceiling::op(LFlt a)
{   return arithlib_lowlevel::float128_to_ceiling(a.floatval());
}

// (frexp nn) => (double-float . fixnum)

LispObject Frexp::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Frexp>("frexp", a);
}

LispObject frexp_finalize(double d, int x)
{   int x1;
    d = std::frexp(d, &x1);
    return cons(fixnum_of_int(x + x1), make_boxfloat(d));
}

LispObject Frexp::op(Fixnum a)
{   return frexp_finalize((double)a.intval(), 0);
}

LispObject Frexp::op(uint64_t *a)
{   int64_t x;
    double d = arithlib_lowlevel::Frexp::op(a, x);
    return frexp_finalize(d, x);
}

LispObject Frexp::op(Rat a)
{   int64_t xp;
    double p = Frexp::op(a.numerator(), xp);
    int64_t xq;
    double q = Frexp::op(a.denominator(), xq);
    return frexp_finalize(p/q, xp-xq);
}

LispObject Frexp::op(Cpx a)
{   aerror1("bad argument for frexp", a.value());
}

LispObject Frexp::op(SFlt a)
{   return frexp_finalize(a.floatval(), 0);
}

LispObject Frexp::op(Flt a)
{   return frexp_finalize(a.floatval(), 0);
}

LispObject Frexp::op(double a)
{   return frexp_finalize(a, 0);
}

LispObject Frexp::op(LFlt a)
{   return frexp_finalize(Float::op(a), 0);
}

double frexp_finalize(double d, int x, int64_t &xx)
{   int x1;
    d = std::frexp(d, &x1);
    xx = x + x1;
    return d;
}

double Frexp::op(LispObject a, int64_t &xx)
{   return number_dispatcher::unary<double,Frexp>("frexp", a, xx);
}

double Frexp::op(Fixnum a, int64_t &xx)
{   return frexp_finalize((double)a.intval(), 0, xx);
}

double Frexp::op(uint64_t *a, int64_t &xx)
{   int64_t x;
    double d = arithlib_lowlevel::Frexp::op(a, x);
    return frexp_finalize(d, x, xx);
}

double Frexp::op(Rat a, int64_t &xx)
{   int64_t xp;
    double p = Frexp::op(a.numerator(), xp);
    int64_t xq;
    double q = Frexp::op(a.denominator(), xq);
    return frexp_finalize(p/q, xp-xq, xx);
}

double Frexp::op(Cpx a, int64_t &xx)
{   aerror1("bad argument for frexp", a.value());
}

double Frexp::op(SFlt a, int64_t &xx)
{   return frexp_finalize((double)a.floatval(), 0, xx);
}

double Frexp::op(Flt a, int64_t &xx)
{   return frexp_finalize((double)a.floatval(), 0, xx);
}

double Frexp::op(double a, int64_t &xx)
{   return frexp_finalize((double)a, 0, xx);
}

double Frexp::op(LFlt a, int64_t &xx)
{   return frexp_finalize(Float::op(a), 0, xx);
}

LispObject frexp_finalize(float128_t d, int x)
{   int x1;
    f128M_frexp(&d, &d, &x1);
    return cons(fixnum_of_int(x+x1), make_boxfloat128(d));
}

LispObject Frexp128::op(Fixnum a)
{   return frexp_finalize((double)a.intval(), 0);
}

LispObject Frexp128::op(uint64_t *a)
{   int64_t x;
    float128_t d = arithlib_lowlevel::Frexp128::op(a, x);
    return frexp_finalize(d, x);
}

LispObject Frexp128::op(Rat a)
{   int64_t xp;
    float128_t p = Frexp128::op(a.numerator(), xp);
    int64_t xq;
    float128_t q = Frexp128::op(a.denominator(), xq);
    return frexp_finalize(f128_div(p, q), xp-xq);
}

LispObject Frexp128::op(Cpx a)
{   aerror1("bad argument for frexp", a.value());
}

LispObject Frexp128::op(SFlt a)
{   return frexp_finalize(a.floatval(), 0);
}

LispObject Frexp128::op(Flt a)
{   return frexp_finalize(a.floatval(), 0);
}

LispObject Frexp128::op(double a)
{   return frexp_finalize(a, 0);
}

LispObject Frexp128::op(LFlt a)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0);
}

float128_t Frexp128::op(LispObject a, int64_t &xx)
{   return number_dispatcher::unary<float128_t,Frexp128>("frexp128", a, xx);
}

float128_t frexp_finalize(float128_t d, int x, int64_t &xx)
{   int x1;
    f128M_frexp(&d, &d, &x1);
    xx = x + x1;
    return d;
}

float128_t Frexp128::op(Fixnum a, int64_t &xx)
{   return frexp_finalize(RawFloat128::op(a), 0, xx);
}

float128_t Frexp128::op(uint64_t *a, int64_t &xx)
{   int64_t x;
    float128_t d = arithlib_lowlevel::Frexp128::op(a, x);
    return frexp_finalize(d, x, xx);
}

float128_t Frexp128::op(Rat a, int64_t &xx)
{   int64_t xp;
    float128_t p = Frexp128::op(a.numerator(), xp);
    int64_t xq;
    float128_t q = Frexp128::op(a.denominator(), xq);
    return frexp_finalize(f128_div(p, q), xp-xq, xx);
}

float128_t Frexp128::op(Cpx a, int64_t &xx)
{   aerror1("bad argument for frexp", a.value());
}

float128_t Frexp128::op(SFlt a, int64_t &xx)
{   return frexp_finalize(RawFloat128::op(a), 0, xx);
}

float128_t Frexp128::op(Flt a, int64_t &xx)
{   return frexp_finalize(RawFloat128::op(a), 0, xx);
}

float128_t Frexp128::op(double a, int64_t &xx)
{   return frexp_finalize(RawFloat128::op(a), 0, xx);
}

float128_t Frexp128::op(LFlt a, int64_t &xx)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0, xx);
}

LispObject Ldexp::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Ldexp>("ldexp", a, b);
}

LispObject Ldexp::op(Fixnum a, Fixnum b)
{   double d = std::ldexp((double)a.intval(), b.intval());
    return make_boxfloat(d);
}

LispObject Ldexp::op(uint64_t *a, Fixnum b)
{   double d = std::ldexp(Float::op(a), b.intval());
    return make_boxfloat(d);
}

LispObject Ldexp::op(Rat a, Fixnum b)
{   double d = std::ldexp(Float::op(a), b.intval());
    return make_boxfloat(d);
}

LispObject Ldexp::op(Cpx a, Fixnum b)
{   aerror1("bad argument for ldexp", a.value());
}

LispObject Ldexp::op(SFlt a, Fixnum b)
{   double d = std::ldexp(a.floatval(), b.intval());
    return pack_short_float(d);
}

LispObject Ldexp::op(Flt a, Fixnum b)
{   double d = std::ldexp(a.floatval(), b.intval());
    return pack_single_float(d);
}

LispObject Ldexp::op(double a, Fixnum b)
{   double d = std::ldexp(a, b.intval());
    return make_boxfloat(d);
}

LispObject Ldexp::op(LFlt a, Fixnum b)
{   float128_t f = a.floatval();
    f128M_ldexp(&f, b.intval());
    return make_boxfloat128(f);
}

// If the exponent imposed by ldexp is a bignum I map to zero if it is
// negative and I force in an exponent of 10000000 otherwise, expecting
// that to leave 0.0 as 0.0 but turn everything else into an infinity.

LispObject Ldexp::op(Fixnum a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat(0.0);
    double d = std::ldexp((double)a.intval(), 100000000);
    return make_boxfloat(d);
}

LispObject Ldexp::op(uint64_t *a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat(0.0);
    double d = std::ldexp(Float::op(a), 100000000);
    return make_boxfloat(d);
}

LispObject Ldexp::op(Rat a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat(0.0);
    double d = std::ldexp(Float::op(a), 100000000);
    return make_boxfloat(d);
}

LispObject Ldexp::op(Cpx a, uint64_t *b)
{   aerror1("bad argument for ldexp", a.value());
}

LispObject Ldexp::op(SFlt a, uint64_t *b)
{   if (Minusp::op(b)) return pack_short_float(
        a.floatval() == a.floatval() ? 0.0 : 0.0/0.0);
    double d = std::ldexp(a.floatval(), 100000000);
    return pack_short_float(d);
}

LispObject Ldexp::op(Flt a, uint64_t *b)
{   if (Minusp::op(b)) return pack_single_float(
        a.floatval() == a.floatval() ? 0.0 : 0.0/0.0);
    double d = std::ldexp(a.floatval(), 100000000);
    return pack_single_float(d);
}

LispObject Ldexp::op(double a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat(
        a == a ? 0.0 : 0.0/0.0,
        TYPE_DOUBLE_FLOAT);
    double d = std::ldexp(a, 100000000);
    return make_boxfloat(d);
}

// I am not dealing with a NaN in the float128 case at present.

LispObject Ldexp::op(LFlt a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat128(i64_to_f128(0));
    float128_t f = a.floatval();
    f128M_ldexp(&f, 100000000);
    return make_boxfloat128(f);
}

LispObject Sqrt::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Sqrt>("sqrt", a);
}

LispObject Sqrt::op(Fixnum a)
{   return make_boxfloat(std::sqrt((double)a.intval()));
}

LispObject Sqrt::op(uint64_t *a)
{   return make_boxfloat(std::sqrt(RawFloat::op(a)));
}

LispObject Sqrt::op(Rat a)
{   int64_t px, qx;
    double p = Frexp::op(a.numerator(), px);
    double q = Frexp::op(a.denominator(), qx);
    if (px%2 != 0)
    {   p *= 2.0;
        px--;
    }
    if (qx%2 != 0)
    {   q *= 2.0;
        qx--;
    }
    return make_boxfloat(std::ldexp(std::sqrt(p/q), (p-q)/2));
}

LispObject Sqrt::op(Cpx a)
{   aerror1("complex sqrt not coded yet", a.value());
}

LispObject Sqrt::op(SFlt a)
{   return make_boxfloat(std::sqrt(Float::op(a)));
}

LispObject Sqrt::op(Flt a)
{  return make_boxfloat(std::sqrt(Float::op(a)));
}

LispObject Sqrt::op(double a)
{   return make_boxfloat(std::sqrt(a));
}

LispObject Sqrt::op(LFlt a)
{   return make_boxfloat128(f128_sqrt(a.floatval()));
}

LispObject Isqrt::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,Isqrt>("isqrt", a);
}

LispObject Isqrt::op(Fixnum a)
{   return arithlib_lowlevel::Isqrt::op(a.intval());
}

LispObject Isqrt::op(uint64_t *a)
{   return arithlib_lowlevel::Isqrt::op(a);
}

LispObject Isqrt::op(Rat a)
{   aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(Cpx a)
{   aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(SFlt a)
{   aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(Flt a)
{   aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(double a)
{   aerror1("bad argument for isqrt", make_boxfloat(a));
}

LispObject Isqrt::op(LFlt a)
{   aerror1("bad argument for isqrt", a.value());
}

#endif // ARITHLIB

// end of arith-float.cpp