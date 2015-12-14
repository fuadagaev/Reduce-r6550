
// $destdir\u08.c        Machine generated C code

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS 1
#endif
#endif
#ifdef WIN32
# if defined WIN64 || defined __WIN64__
# define OPSYS "win64"
# define IMPNAME "win64"
# else
# define OPSYS "win32"
# define IMPNAME "win32"
# endif
#else
# ifdef HOST_OS
# define OPSYS HOST_OS
# ifdef HOST_CPU
# define IMPNAME HOST_OS ":" HOST_CPU
# else
# define IMPNAME HOST_OS
# endif
# else
# define OPSYS "Unknown"
# define IMPNAME "Generic"
# endif
#endif
#ifdef HAVE_STDINT_H
#if defined __cplusplus && !defined __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
typedef int CSLbool;
#define YES 1
#define NO 0
#ifndef PAGE_BITS
# define PAGE_BITS 22
#endif 
#define PAGE_POWER_OF_TWO (((intptr_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO - 256)
#ifndef MAX_HEAPSIZE
# define MAX_HEAPSIZE (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
# define MAX_BPSSIZE 64
#endif 
#define MEGABYTE ((intptr_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES MAX_BPS_PAGES
#define CSL_IGNORE(x) (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK 0xff
typedef intptr_t LispObject;
#define CELL ((intptr_t)sizeof(LispObject))
#define TAG_BITS 7
#define TAG_CONS 0 
#define TAG_FIXNUM 1 
#define TAG_ODDS 2 
#define TAG_SFLOAT 3 
#define TAG_SYMBOL 4 
#define TAG_NUMBERS 5 
#define TAG_VECTOR 6 
#define TAG_BOXFLOAT 7 
#define fixnum_of_int(x) ((LispObject)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x) ((int32_t)(((int32_t)(x)) < 0 ? \
 (((int32_t)(x))>>4) | (-0x10000000) : \
 (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x) ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I 8 
#define GC_BIT_H 8 
#define GC_BIT_P ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w) (((int)(w) & GC_BIT_I) != 0)
extern LispObject address_sign; 
#define is_marked_p(w) (((LispObject)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((LispObject)(w) & ~GC_BIT_P) + \
 address_sign)
#define flip_mark_bit_i(w) ((LispObject)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w) ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w) ((LispObject)(w) ^ GC_BIT_P)
#define is_marked_h(w) (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception() (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
 do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h) ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h) ((LispObject)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((LispObject)(h) & ~GC_BIT_I)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p) (is_cons(p) && (p) != nil)
#define symbolp(p) (is_symbol(p) || (p) == nil)
#else 
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p) ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef uintptr_t Header;
#define header_mask 0x3f0
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL 0x00000010
#define SYM_SPECIAL_VAR 0x00000040 
#define SYM_GLOBAL_VAR 0x00000080 
#define SYM_SPECIAL_FORM 0x00000100 
#define SYM_MACRO 0x00000200 
#define SYM_C_DEF 0x00000400 
#define SYM_CODEPTR 0x00000800 
#define SYM_ANY_GENSYM 0x00001000 
#define SYM_TRACED 0x00002000
#define SYM_FASTGET_MASK 0x000fc000 
#define SYM_FASTGET_SHIFT 14
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00100000 
#define SYM_IN_PACKAGE 0xffe00000 
#define SYM_IN_PKG_SHIFT 23
#define SYM_IN_PKG_COUNT 11
#else 
#define SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM 0x020 
#define TYPE_RATNUM 0x060
#define TYPE_COMPLEX_NUM 0x0a0
#define TYPE_SINGLE_FLOAT 0x120
#define TYPE_DOUBLE_FLOAT 0x160
#define TYPE_LONG_FLOAT 0x1a0
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_VECTOR)))
#define elt(v, n) (*(LispObject *)memory_reference((intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
 (intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
 (intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
 ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
 (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
 do { \
 *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
 *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
 } while (0)
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#define TYPE_BITVEC1 0x030 
#define TYPE_BITVEC2 0x0b0 
#define TYPE_BITVEC3 0x130
#define TYPE_BITVEC4 0x1b0 
#define TYPE_BITVEC5 0x230 
#define TYPE_BITVEC6 0x2b0 
#define TYPE_BITVEC7 0x330 
#define TYPE_BITVEC8 0x3b0 
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#define TYPE_STRING 0x070 
#define TYPE_BPS 0x170 
#define TYPE_SPARE 0x270 
#define TYPE_MAPLEREF TYPE_SPARE 
#define TYPE_FOREIGN TYPE_SPARE 
#define TYPE_SP 0x370 
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#define TYPE_SIMPLE_VEC 0x0f0 
#define TYPE_HASH 0x1f0 
#define TYPE_ARRAY 0x2f0 
#define TYPE_STRUCTURE 0x3f0 
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8 TYPE_BPS
#define TYPE_VEC16 0x220 
#define TYPE_VEC32 0x260 
#define TYPE_MIXED1 0x2a0 
#define TYPE_MIXED2 0x2e0 
#define TYPE_FLOAT32 0x320 
#define TYPE_FLOAT64 0x360 
#define TYPE_MIXED3 0x3a0 
#define TYPE_STREAM 0x3e0 
#define ODDS_MASK 0xff
#define TAG_CHAR 0x02 
#define TAG_BPS 0x42
#define TAG_SPID 0xc2 
#define SPID_NIL (TAG_SPID+0x0000) 
#define SPID_FBIND (TAG_SPID+0x0100) 
#define SPID_CATCH (TAG_SPID+0x0200) 
#define SPID_PROTECT (TAG_SPID+0x0300) 
#define SPID_HASH0 (TAG_SPID+0x0400) 
#define SPID_HASH1 (TAG_SPID+0x0500) 
#define SPID_GCMARK (TAG_SPID+0x0600) 
#define SPID_NOINPUT (TAG_SPID+0x0700) 
#define SPID_ERROR (TAG_SPID+0x0800) 
#define SPID_PVBIND (TAG_SPID+0x0900) 
#define SPID_NOARG (TAG_SPID+0x0a00) 
#define SPID_NOPROP (TAG_SPID+0x0b00) 
#define SPID_LIBRARY (TAG_SPID+0x0c00) 
#define is_header(x) (((int)(x) & 0x30) != 0) 
#define is_char(x) (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x) (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x) (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> 8) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << 29) | \
 (((uint32_t)(code)) << 8) | TAG_CHAR))
#define CHAR_EOF pack_char(0, 0x0010ffff)
#define data_of_bps(v) \
 ((char *)(doubleword_align_up((intptr_t) \
 bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) + \
 (SIXTY_FOUR_BIT ? \
 (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
 PAGE_POWER_OF_TWO) : \
 0) + \
 (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head
{
 Header header; 
 LispObject value; 
 LispObject env; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t functionn; 
 LispObject pname; 
 LispObject plist; 
 LispObject fastgets;
 uintptr_t count; 
#ifdef COMMON
 LispObject package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE 63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
 ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
 (n))
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p) (*(Header *) symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p) (*(LispObject *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p) ((one_args *) *((intptr_t *)symalign((char *)(p) + \
 (3*CELL - TAG_SYMBOL))))
#define qfn2(p) ((two_args *) *((intptr_t *)symalign((char *)(p) + \
 (4*CELL - TAG_SYMBOL))))
#define qfnn(p) ((n_args *) *((intptr_t *)symalign((char *)(p) + \
 (5*CELL - TAG_SYMBOL))))
#define ifn1(p) (*(intptr_t *)symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p) (*(LispObject *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p) (*(Header *) memory_reference((intptr_t) \
 symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p) ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p) ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p) ((n_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p) (*(uintptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
typedef union Float_union
{ float f;
 int32_t i;
} Float_union;
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b) ((uint32_t *)memory_reference((intptr_t)((char *)b + \
 (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b) ((uint32_t *)((char *)b + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n) (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
#define numerator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
#define real_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 16
#define long_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((LispObject)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((LispObject)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((LispObject)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((LispObject)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((LispObject)((intptr_t)(n) & (-16)))
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#if 0 && defined DEBUG
#define SHOW_FNAME (exit_reason == UNWIND_THROW || \
 (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS (exit_reason == UNWIND_THROW || \
 (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#endif
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern "C" LispObject interrupted(LispObject p);
extern "C" LispObject error(int nargs, int code, ...);
extern "C" LispObject cerror(int nargs, int code1, int code2, ...);
extern "C" LispObject too_few_2(LispObject env, LispObject a1);
extern "C" LispObject too_many_1(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_0a(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_0b(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_3a(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_3b(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_na(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_nb(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_1(LispObject env, int nargs, ...);
extern "C" LispObject wrong_no_2(LispObject env, int nargs, ...);
extern "C" LispObject bad_specialn(LispObject env, int nargs, ...);
extern "C" LispObject aerror(const char *s); 
extern "C" LispObject aerror0(const char *s);
extern "C" LispObject aerror1(const char *s, LispObject a);
extern "C" LispObject aerror2(const char *s, LispObject a, LispObject b);
extern "C" void fatal_error(int code, ...);
#define GC_MESSAGES 0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS 0x04
#define GC_MSG_BITS 0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG 0x10
#define ARGS_FLAG 0x20
#define BACKTRACE_MSG_BITS 0x38
#define err_bad_car 0 
#define err_bad_cdr 1 
#define err_no_store 2 
#define err_undefined_function_1 3 
#define err_undefined_function_2 4 
#define err_undefined_function_n 5 
#define err_wrong_no_args 6 
#define err_unbound_lexical 7 
#define err_bad_rplac 8 
#define err_bad_arith 9 
#define err_redef_special 10 
#define err_bad_arg 11 
#define err_bad_declare 12 
#define err_bad_fn 13 
#define err_unset_var 14 
#define err_too_many_args1 15 
#define err_too_many_args2 16 
#define err_bad_apply 17 
#define err_macroex_hook 18 
#define err_block_tag 19 
#define err_go_tag 20 
#define err_excess_args 21
#define err_insufficient_args 22
#define err_bad_bvl 23 
#define err_bad_keyargs 24
#define err_write_err 25
#define err_bad_endp 26 
#define err_no_fasldir 27
#define err_no_fasl 28 
#define err_open_failed 29 
#define err_pipe_failed 30 
#define err_stack_overflow 31
#define err_top_bit 32
#define err_mem_spans_zero 33
#define err_no_longer_used 34 
#define err_no_tempdir 35
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
 "attempt to take cdr of an atom",
 "insufficient freestore to run this package",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function",
 "wrong number of arguments",
 "unbound lexical variable",
 "bad rplaca/rplacd",
 "bad argument for an arithmetic function",
 "attempt to redefine a special form",
 "not a variable",
 "bad use of declare",
 "attempt to apply non-function",
 "unset variable",
 "too many arguments",
 "too many arguments",
 "object not valid as a function (apply,",
 "macroexpand-hook failure",
 "block tag not found",
 "go tag not found",
 "too many arguments provided",
 "not enough arguments provided",
 "bad item in bound variable list",
 "bad keyword arguments",
 "write-error on file",
 "endp used on badly terminated list",
 "environment parameter 'fasldir' not set",
 "loadable module not found for loading",
 "file could not be opened",
 "unable to establish pipe",
 "stack overflow",
 "top bit of address has unexpected value",
 "memory block spans the zero address",
 "this error code available for re-use",
 "unable to find a directory for temporary files",
 "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
 fflush(stderr); \
 } while (0)
#define DS(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
 fflush(stderr); \
 } while (0)
#define DX(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
 (long long unsigned)(s)); \
 fflush(stderr); \
 } while (0)
extern void **pages,
 **heap_pages, **vheap_pages,
 **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
 **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS 0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS 2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{ void *start;
 void *end;
 int type;
} page_map_t;
#endif
extern int32_t pages_count,
 heap_pages_count, vheap_pages_count,
 bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
 new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern LispObject *C_stack;
#define stack C_stack
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif
extern LispObject multiplication_buffer;
#ifdef MEMORY_TRACE
#define push(a) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); } while (0)
#define push2(a,b) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); \
 *++stack = (d); \
 memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); \
 *++stack = (d); \
 memory_reference((intptr_t)stack); \
 *++stack = (e); \
 memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop() (memory_reference((int32_t)stack), (*stack--))
#define pop(a) { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
 memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
 memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n) stack -= (n)
#else 
#define push(a) { *++stack = (a); }
#define push2(a,b) { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack += 3; }
#define push4(a,b,c,d) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) { \
 stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack[6] = (f); \
 stack += 6; }
#define pop(a) { (a) = *stack--; }
#define pop2(a,b) { stack -= 2; (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c) { stack -= 3; (a) = stack[3]; (b) = stack[2]; \
 (c) = stack[1]; }
#define pop4(a,b,c,d) { stack -= 4; (a) = stack[4]; (b) = stack[3]; \
 (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5; (a) = stack[5]; (b) = stack[4]; \
 (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6; \
 (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
 (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n) stack -= (n)
#endif 
#define errexit() { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n) { nil = C_nil; \
 if (exception_pending()) { popv(n); return nil; } }
#define errexitv() { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil; \
 if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
#define GC_PRESERVE 6
#define GC_NATIVE 7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
 if (check_stack("@" __FILE__,__LINE__)) \
 { show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
 { const char *p = (char *)&p; \
 if (p < C_stack_limit) return aerror("stack overflow"); \
 }
#endif
extern int32_t software_ticks, countdown;
#ifdef DEBUG
extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);
#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
 if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
extern volatile int blipflag;
extern int64_t blipcount, startblip;
#if defined __linux__ && defined DEBUG
#define HANDLE_BLIP \
 if (blipflag) \
 { blipflag = 0; \
 if (startblip >= 0 && ++blipcount > startblip) \
 { fprintf(stderr, "Line %d of file %s\n", __LINE__, __FILE__); \
 fflush(stderr); \
 } \
 }
#else
#define HANDLE_BLIP
#endif
#define stackcheck0(k) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { reclaim(nil, "stack", GC_STACK, 0); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck1(k, a1) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { a1 = reclaim(a1, "stack", GC_STACK, 0); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck2(k, a1, a2) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push(a2); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck3(k, a1, a2, a3) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push2(a2, a3); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop2(a3, a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck4(k, a1, a2, a3, a4) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push3(a2, a3, a4); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop3(a4, a3, a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
extern LispObject C_nil;
#define first_nil_offset 50 
#define work_0_offset 200
#define last_nil_offset 251
#define NIL_SEGMENT_SIZE (last_nil_offset*sizeof(LispObject) + 32)
#define SPARE 512
#ifdef COMMON
#define BASE ((LispObject *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((LispObject *)(nil+4)): ((LispObject *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern LispObject codefringe;
extern LispObject volatile codelimit;
extern LispObject * volatile stacklimit;
extern LispObject fringe;
extern LispObject volatile heaplimit;
extern LispObject volatile vheaplimit;
extern LispObject vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table;
extern LispObject progn_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject cl_symbols, active_stream, current_module;
extern LispObject native_defs, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject native_code, native_symbol, traceprint_symbol;
extern LispObject loadsource_symbol;
extern LispObject hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, count_high;
#ifdef COMMON
extern LispObject keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol;
extern LispObject expand_def_symbol, allow_key_key;
#endif
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern LispObject om_closeConn(LispObject nil, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject nil, LispObject ldev);
extern LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern LispObject om_putAtp(LispObject nil, LispObject ldev);
extern LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_putAttr(LispObject nil, LispObject ldev);
extern LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_putBind(LispObject nil, LispObject ldev);
extern LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern LispObject om_putBVar(LispObject nil, LispObject ldev);
extern LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_putError(LispObject nil, LispObject ldev);
extern LispObject om_putEndError(LispObject nil, LispObject ldev);
extern LispObject om_putObject(LispObject nil, LispObject ldev);
extern LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern LispObject om_getApp(LispObject nil, LispObject ldev);
extern LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern LispObject om_getAtp(LispObject nil, LispObject ldev);
extern LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_getAttr(LispObject nil, LispObject ldev);
extern LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_getBind(LispObject nil, LispObject ldev);
extern LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern LispObject om_getBVar(LispObject nil, LispObject ldev);
extern LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_getError(LispObject nil, LispObject ldev);
extern LispObject om_getEndError(LispObject nil, LispObject ldev);
extern LispObject om_getObject(LispObject nil, LispObject ldev);
extern LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern LispObject om_getInt(LispObject nil, LispObject ldev);
extern LispObject om_getFloat(LispObject nil, LispObject ldev);
extern LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern LispObject om_getVar(LispObject nil, LispObject ldev);
extern LispObject om_getString(LispObject nil, LispObject ldev);
extern LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern LispObject om_getType(LispObject nil, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);
extern LispObject om_read(LispObject nil, LispObject dev);
extern LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject nil, int nargs, ...);
extern LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern LispObject om_whichCDs(LispObject nil, LispObject lsym);
#endif
extern LispObject workbase[51];
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 workbase[0]
#define work_1 workbase[1]
#define mv_1 workbase[1]
#define mv_2 workbase[2]
#define mv_3 workbase[3]
#define work_50 workbase[50]
#else 
#define nil_as_base LispObject nil = C_nil;
#define byteflip BASE[12]
#define codefringe BASE[13]
#define codelimit (*(LispObject volatile *)&BASE[14])
extern LispObject * volatile stacklimit;
#define fringe BASE[18]
#define heaplimit (*(LispObject volatile *)&BASE[19])
#define vheaplimit (*(LispObject volatile *)&BASE[20])
#define vfringe BASE[21]
#define miscflags BASE[22]
#define nwork BASE[24]
#define exit_count BASE[26]
#define gensym_ser BASE[27]
#define print_precision BASE[28]
#define current_modulus BASE[29]
#define fastget_size BASE[30]
#define package_bits BASE[31]
#define modulus_is_large BASE[32]
#define current_package BASE[52]
#define B_reg BASE[53]
#define codevec BASE[54]
#define litvec BASE[55]
#define exit_tag BASE[56]
#define exit_value BASE[57]
#define catch_tags BASE[58]
#define lisp_package BASE[59]
#define boffo BASE[60]
#define charvec BASE[61]
#define sys_hash_table BASE[62]
#define help_index BASE[63]
#define gensym_base BASE[64]
#define err_table BASE[65]
#define supervisor BASE[66]
#define startfn BASE[67]
#define faslvec BASE[68]
#define tracedfn BASE[69]
#define prompt_thing BASE[70]
#define faslgensyms BASE[71]
#define cl_symbols BASE[72]
#define active_stream BASE[73]
#define current_module BASE[74]
#define native_defs BASE[75]
#define append_symbol BASE[90]
#define applyhook BASE[91]
#define cfunarg BASE[92]
#define comma_at_symbol BASE[93]
#define comma_symbol BASE[94]
#define compiler_symbol BASE[95]
#define comp_symbol BASE[96]
#define cons_symbol BASE[97]
#define echo_symbol BASE[98]
#define emsg_star BASE[99]
#define evalhook BASE[100]
#define eval_symbol BASE[101]
#define expr_symbol BASE[102]
#define features_symbol BASE[103]
#define fexpr_symbol BASE[104]
#define funarg BASE[105]
#define function_symbol BASE[106]
#define lambda BASE[107]
#define lisp_true BASE[108]
#define lower_symbol BASE[109]
#define macroexpand_hook BASE[110]
#define macro_symbol BASE[111]
#define opt_key BASE[112]
#define prinl_symbol BASE[113]
#define progn_symbol BASE[114]
#define quote_symbol BASE[115]
#define raise_symbol BASE[116]
#define redef_msg BASE[117]
#define rest_key BASE[118]
#define savedef BASE[119]
#define string_char_sym BASE[120]
#define unset_var BASE[121]
#define work_symbol BASE[122]
#define lex_words BASE[123]
#define get_counts BASE[124]
#define fastget_names BASE[125]
#define input_libraries BASE[126]
#define output_library BASE[127]
#define current_file BASE[128]
#define break_function BASE[129]
#define lisp_work_stream BASE[130]
#define lisp_standard_output BASE[131]
#define lisp_standard_input BASE[132]
#define lisp_debug_io BASE[133]
#define lisp_error_output BASE[134]
#define lisp_query_io BASE[135]
#define lisp_terminal_io BASE[136]
#define lisp_trace_output BASE[137]
#define standard_output BASE[138]
#define standard_input BASE[139]
#define debug_io BASE[140]
#define error_output BASE[141]
#define query_io BASE[142]
#define terminal_io BASE[143]
#define trace_output BASE[144]
#define fasl_stream BASE[145]
#define native_code BASE[146]
#define native_symbol BASE[147]
#define traceprint_symbol BASE[148]
#define loadsource_symbol BASE[149]
#define hankaku_symbol BASE[150]
#define bytecoded_symbol BASE[151]
#define nativecoded_symbol BASE[152]
#define gchook BASE[153]
#define resources BASE[154]
#define callstack BASE[155]
#define procstack BASE[156]
#define procmem BASE[157]
#define trap_time BASE[158]
#define count_high BASE[159]
#ifdef COMMON
#define keyword_package BASE[170]
#define all_packages BASE[171]
#define package_symbol BASE[172]
#define internal_symbol BASE[173]
#define external_symbol BASE[174]
#define inherited_symbol BASE[175]
#define key_key BASE[176]
#define allow_other_keys BASE[177]
#define aux_key BASE[178]
#define format_symbol BASE[179]
#define expand_def_symbol BASE[180]
#define allow_key_key BASE[181]
#endif
#define declare_symbol BASE[182]
#define special_symbol BASE[183]
#define large_modulus BASE[184]
#define used_space BASE[185]
#define avail_space BASE[186]
#define eof_symbol BASE[187]
#define call_stack BASE[188]
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 BASE[200]
#define work_1 BASE[201]
#define mv_1 work_1
#define mv_2 BASE[202]
#define mv_3 BASE[203]
#define work_50 BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list BASE[50] 
#define equal_hash_table_list BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(LispObject v);
extern LispObject eq_hash_tables, equal_hash_tables;
extern LispObject volatile savecodelimit;
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
#ifndef NO_BYTECOUNT
extern const char *name_of_caller;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES 40 
#define MAX_SYMBOLS_TO_DEFINE 40
#define MAX_FASL_PATHS 20
extern const char *files_to_read[MAX_INPUT_FILES],
 *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
 *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern int boffop;
extern void packbyte(int c);
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern int number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths,
 init_flags;
extern int native_code_tag;
extern const char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{ FILE *f; 
 long int o; 
 long int n; 
 uint32_t chk; 
 int status; 
 int nativedir; 
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE 0x1000
typedef struct entry_point1
{ one_args *p;
 const char *s;
} entry_point1;
typedef struct entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct entry_pointn
{ n_args *p;
 const char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject nil, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern int load_dynamic(const char *objname, const char *modname,
 LispObject name, LispObject fns);
extern "C" LispObject Linstate_c_code(LispObject nil,
 LispObject name, LispObject fns);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(const char *s, int len);
#define IOPEN_OUT 0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED 2
extern CSLbool Iopen(const char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(const char *name, int len, char *datestamp, int32_t *size,
 char *expanded_name);
extern CSLbool Icopy(const char *name, int len);
extern CSLbool Idelete(const char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(const void *buff, int32_t size);
extern long int Ioutsize(void);
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(const unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
extern const char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern "C" void sigint_handler(int code);
extern "C" void record_get(LispObject tag, CSLbool found);
extern int primep(int32_t);
extern void adjust_all(void);
extern void set_up_functions(CSLbool restartp);
extern void get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(LispObject code, LispObject lit,
 LispObject *entry_stack);
extern CSLbool complex_stringp(LispObject a);
extern void freshline_trace(void);
extern void freshline_debug(void);
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject Ceval(LispObject u, LispObject env);
extern LispObject noisy_Ceval(LispObject u, LispObject env);
extern uint32_t Crand(void);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern "C" CSLbool eql_fn(LispObject a, LispObject b);
extern "C" CSLbool cl_equal_fn(LispObject a, LispObject b);
extern "C" CSLbool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" CSLbool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs,
 LispObject env, LispObject fname, int noisy);
extern LispObject apply_lambda(LispObject def, int nargs,
 LispObject env, LispObject name, int noisy);
extern void deallocate_pages(void);
extern void drop_heap_segments(void);
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
#ifdef COMMON
extern "C" LispObject get(LispObject a, LispObject b, LispObject c);
#else
extern "C" LispObject get(LispObject a, LispObject b);
#endif
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern LispObject getcodevector(int type, size_t size);
extern uint32_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" CSLbool geq2(LispObject a, LispObject b);
extern "C" CSLbool greaterp2(LispObject a, LispObject b);
extern "C" CSLbool lesseq2(LispObject a, LispObject b);
extern "C" CSLbool lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, int32_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 one_args *f1, two_args *f2, n_args *fn);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern "C" LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern "C" LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern FILE *open_file(char *filename, const char *original_name,
 size_t n, const char *dirn, FILE *old_file);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, int len);
extern void preserve_native_code(void);
extern void relocate_native_function(unsigned char *bps);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t *len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prin_to_error(LispObject u);
extern void loop_print_stdout(LispObject o);
extern void loop_print_terminal(LispObject o);
extern void loop_print_debug(LispObject o);
extern void loop_print_query(LispObject o);
extern void loop_print_trace(LispObject o);
extern void loop_print_error(LispObject o);
extern void internal_prin(LispObject u, int prefix);
extern LispObject princ(LispObject u);
extern LispObject print(LispObject u);
extern LispObject printc(LispObject u);
extern void print_bignum(LispObject u, CSLbool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, CSLbool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(const char *why, int line, const char *file);
extern int check_env(LispObject env);
#endif
extern CSLbool do_not_kill_native_code;
extern void set_fns(LispObject sym, one_args *f1,
 two_args *f2, n_args *fn);
extern void setup(int restartp, double storesize);
extern LispObject simplify_string(LispObject s);
extern CSLbool stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
#ifdef HAVE_INT64_T
extern int64_t sixty_four_bits(LispObject a);
#endif
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r) (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r) (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#define noisy_eval(a, b) noisy_Ceval(a, b)
#define noisy_voideval(a, b) noisy_Ceval(a, b)
#else
#define eval(a, b) \
 (is_cons(a) ? Ceval(a, b) : \
 is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
 onevalue(qvalue(a))) : \
 onevalue(a))
#define voideval(a, b) \
 if (is_cons(a)) Ceval(a, b) 
#define noisy_eval(a, b) \
 (is_cons(a) ? noisy_Ceval(a, b) : \
 is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
 onevalue(qvalue(a))) : \
 onevalue(a))
#define noisy_voideval(a, b) \
 if (is_cons(a)) noisy_Ceval(a, b) 
#endif
#define equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 equal_fn(a, b)))
#define cl_equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 cl_equal_fn(a, b)))
#define eql(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
 uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args *three_arg_functions[];
extern void *useful_functions[];
extern char *address_of_var(int n);
typedef struct setup_type
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
 uint32_t c1;
 uint32_t c2;
} setup_type_1;
extern setup_type const
arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
 arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
 eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
 print_setup[], read_setup[], mpi_setup[];
extern setup_type const
u01_setup[], u02_setup[], u03_setup[], u04_setup[],
 u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
 u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
 u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
 u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
 u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
 u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
 u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
 u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
 u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
 u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
 u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
 u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern const char *find_image_directory(int argc, const char *argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
 LispObject env, int compilerp, int noisy);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject noisy_mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject noisy_progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
extern LispObject noisy_tagbody_fn(LispObject args, LispObject env);
extern LispObject resource_exceeded();
extern int64_t time_base, space_base, io_base, errors_base;
extern int64_t time_now, space_now, io_now, errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(LispObject def, LispObject env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
#define M2_31_1 -2147483649.0 
#define _pi ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr 0
#define boole_and 1
#define boole_andc2 2
#define boole_1 3
#define boole_andc1 4
#define boole_2 5
#define boole_xor 6
#define boole_ior 7
#define boole_nor 8
#define boole_eqv 9
#define boole_c2 10
#define boole_orc2 11
#define boole_c1 12
#define boole_orc1 13
#define boole_nand 14
#define boole_set 15
#define top_bit_set(n) (((int32_t)(n)) < 0)
#define top_bit(n) (((uint32_t)(n)) >> 31)
#define set_top_bit(n) ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n) ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1 
#define Dmultiply(hi, lo, a, b, c) \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) + \
 (uint32_t)(c); \
 (lo) = 0x7fffffffu & (uint32_t)r64; \
 (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE 1
#define Ddivide(r, q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b) ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, int32_t n);
extern LispObject quotbn1(LispObject a, int32_t n);
extern LispObject quotbb(LispObject a, LispObject b);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, int32_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern CSLbool numeq2(LispObject a, LispObject b);
extern "C" CSLbool zerop(LispObject a);
extern CSLbool onep(LispObject a);
extern CSLbool minusp(LispObject a);
extern CSLbool plusp(LispObject a);
extern CSLbool lesspbd(LispObject a, double b);
extern CSLbool lessprd(LispObject a, double b);
extern CSLbool lesspdb(double a, LispObject b);
extern CSLbool lesspdr(double a, LispObject b);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
 uint32_t a3, int32_t n);
extern LispObject make_lisp_integer32(int32_t n);
extern LispObject make_lisp_integer64(int64_t n);
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(LispObject a, LispObject b);
extern CSLbool lesspib(LispObject a, LispObject b);
typedef struct Complex
{ double real;
 double imag;
} Complex;
extern Complex Cln(Complex a);
extern Complex Ccos(Complex a);
extern Complex Cexp(Complex a);
extern Complex Cpow(Complex a, Complex b);
extern double Cabs(Complex a);
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
#ifdef MACINTOSH
extern sem_t *kara_sem1a, *kara_sem1b, *kara_sem1c,
 *kara_sem2a, *kara_sem2b, *kara_sem2c;
#else
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
 kara_sem2a, kara_sem2b, kara_sem2c;
#endif
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern "C" LispObject Lbatchp(LispObject env, int nargs, ...);
extern "C" LispObject bytecounts(LispObject nil, int nargs, ...);
extern "C" LispObject Ldate(LispObject env, int nargs, ...);
extern "C" LispObject Ldatestamp(LispObject nil, int nargs, ...);
extern "C" LispObject Leject(LispObject env, int nargs, ...);
extern "C" LispObject Lerror(LispObject env, int nargs, ...);
extern "C" LispObject Lerror0(LispObject env, int nargs, ...);
extern "C" LispObject Lflush(LispObject nil, int nargs, ...);
extern "C" LispObject Lgc0(LispObject nil, int nargs, ...);
extern "C" LispObject Lgctime(LispObject env, int nargs, ...);
extern "C" LispObject Lgensym(LispObject env, int nargs, ...);
extern "C" LispObject Llist_modules(LispObject env, int nargs, ...);
extern "C" LispObject Llibrary_members0(LispObject env, int nargs, ...);
extern "C" LispObject Llposn(LispObject env, int nargs, ...);
extern "C" LispObject Lmapstore0(LispObject env, int nargs, ...);
extern "C" LispObject Lnext_random(LispObject env, int nargs, ...);
extern "C" LispObject Lposn(LispObject env, int nargs, ...);
extern "C" LispObject Lread(LispObject env, int nargs, ...);
extern "C" LispObject Lreadch(LispObject env, int nargs, ...);
extern "C" LispObject Lrtell(LispObject nil, int nargs, ...);
extern "C" LispObject Lterpri(LispObject env, int nargs, ...);
extern "C" LispObject Ltime(LispObject env, int nargs, ...);
extern "C" LispObject Ltmpnam(LispObject nil, int nargs, ...);
extern "C" LispObject Ltyi(LispObject env, int nargs, ...);
extern "C" LispObject autoload1(LispObject env, LispObject a1);
extern "C" LispObject bytecoded1(LispObject env, LispObject a);
extern "C" LispObject bytecounts1(LispObject env, LispObject a);
extern "C" LispObject byteopt1(LispObject def, LispObject a);
extern "C" LispObject byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_bytecoded1(LispObject env, LispObject a);
extern "C" LispObject double_byteopt1(LispObject def, LispObject a);
extern "C" LispObject double_byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_funarged1(LispObject env, LispObject a1);
extern "C" LispObject double_hardopt1(LispObject def, LispObject a);
extern "C" LispObject double_hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_interpreted1(LispObject env, LispObject a1);
extern "C" LispObject funarged1(LispObject env, LispObject a1);
extern "C" LispObject tracefunarged1(LispObject env, LispObject a1);
extern "C" LispObject tracesetfunarged1(LispObject env, LispObject a1);
extern "C" LispObject hardopt1(LispObject def, LispObject a);
extern "C" LispObject hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject interpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracesetbytecoded1(LispObject env, LispObject a);
extern "C" LispObject jitcompileme1(LispObject env, LispObject a);
extern "C" LispObject tracebyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracesetbyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracebyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracesetbyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracesetbytecoded1(LispObject env, LispObject a);
extern "C" LispObject traceinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracesetinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracehardopt1(LispObject def, LispObject a);
extern "C" LispObject tracesethardopt1(LispObject def, LispObject a);
extern "C" LispObject tracehardoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracesethardoptrest1(LispObject def, LispObject a);
extern "C" LispObject undefined1(LispObject env, LispObject a1);
extern "C" LispObject f1_as_0(LispObject env, LispObject a);
extern "C" LispObject f1_as_1(LispObject env, LispObject a);
#ifdef CJAVA
extern "C" LispObject java1(LispObject env, LispObject a);
#endif
extern "C" LispObject Labsval(LispObject env, LispObject a);
extern "C" LispObject Ladd1(LispObject env, LispObject a);
extern "C" LispObject Lalpha_char_p(LispObject env, LispObject a);
extern "C" LispObject Lapply0(LispObject env, LispObject a);
extern "C" LispObject Lapply_1(LispObject env, LispObject fn);
extern "C" LispObject Latan(LispObject env, LispObject a);
extern "C" LispObject Latom(LispObject env, LispObject a);
extern "C" LispObject Lbanner(LispObject env, LispObject a);
extern "C" LispObject Lboundp(LispObject env, LispObject a);
extern "C" LispObject Lbpsp(LispObject nil, LispObject a);
extern "C" LispObject Lbpsupbv(LispObject nil, LispObject v);
extern "C" LispObject Lcaaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaadar(LispObject env, LispObject a);
extern "C" LispObject Lcaaddr(LispObject env, LispObject a);
extern "C" LispObject Lcaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcadaar(LispObject env, LispObject a);
extern "C" LispObject Lcadadr(LispObject env, LispObject a);
extern "C" LispObject Lcadar(LispObject env, LispObject a);
extern "C" LispObject Lcaddar(LispObject env, LispObject a);
extern "C" LispObject Lcadddr(LispObject env, LispObject a);
extern "C" LispObject Lcaddr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcdaaar(LispObject env, LispObject a);
extern "C" LispObject Lcdaadr(LispObject env, LispObject a);
extern "C" LispObject Lcdaar(LispObject env, LispObject a);
extern "C" LispObject Lcdadar(LispObject env, LispObject a);
extern "C" LispObject Lcdaddr(LispObject env, LispObject a);
extern "C" LispObject Lcdadr(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcddaar(LispObject env, LispObject a);
extern "C" LispObject Lcddadr(LispObject env, LispObject a);
extern "C" LispObject Lcddar(LispObject env, LispObject a);
extern "C" LispObject Lcdddar(LispObject env, LispObject a);
extern "C" LispObject Lcddddr(LispObject env, LispObject a);
extern "C" LispObject Lcdddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lchar_code(LispObject env, LispObject a);
extern "C" LispObject Lclose(LispObject env, LispObject a);
extern "C" LispObject Lcodep(LispObject env, LispObject a);
extern "C" LispObject Lcompress(LispObject env, LispObject a);
extern "C" LispObject Lconsp(LispObject env, LispObject a);
extern "C" LispObject Lconstantp(LispObject env, LispObject a);
extern "C" LispObject Lcopy_module(LispObject env, LispObject a);
extern "C" LispObject Ldefine_in_module(LispObject env, LispObject a);
extern "C" LispObject Ldelete_module(LispObject env, LispObject a);
extern "C" LispObject Ldigitp(LispObject env, LispObject a);
extern "C" LispObject Lendp(LispObject env, LispObject a);
extern "C" LispObject Lerror1(LispObject nil, LispObject a1);
extern "C" LispObject Lerrorset1(LispObject nil, LispObject form);
extern "C" LispObject Leval(LispObject env, LispObject a);
extern "C" LispObject Levenp(LispObject env, LispObject a);
extern "C" LispObject Levlis(LispObject env, LispObject a);
extern "C" LispObject Lexplode(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lc(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lcn(LispObject nil, LispObject a);
extern "C" LispObject Lexplode2n(LispObject env, LispObject a);
extern "C" LispObject Lexplodec(LispObject env, LispObject a);
extern "C" LispObject Lexplodecn(LispObject env, LispObject a);
extern "C" LispObject Lexplodehex(LispObject nil, LispObject a);
extern "C" LispObject Lexploden(LispObject env, LispObject a);
extern "C" LispObject Lexplodeoctal(LispObject nil, LispObject a);
extern "C" LispObject Lfixp(LispObject env, LispObject a);
extern "C" LispObject Lfloat(LispObject env, LispObject a);
extern "C" LispObject Lfloatp(LispObject env, LispObject a);
extern "C" LispObject Lfrexp(LispObject nil, LispObject a);
extern "C" LispObject Lfuncall1(LispObject env, LispObject fn);
extern "C" LispObject Lgc(LispObject nil, LispObject a);
extern "C" LispObject Lgensym1(LispObject env, LispObject a);
extern "C" LispObject Lgensym2(LispObject env, LispObject a);
extern "C" LispObject Lgetd(LispObject env, LispObject a);
extern "C" LispObject Lgetenv(LispObject env, LispObject a);
extern "C" LispObject Lget_bps(LispObject env, LispObject a);
extern "C" LispObject Lhelp(LispObject nil, LispObject a);
extern "C" LispObject Liadd1(LispObject env, LispObject a);
extern "C" LispObject Lidentity(LispObject env, LispObject a);
extern "C" LispObject Liminus(LispObject env, LispObject a);
extern "C" LispObject Liminusp(LispObject env, LispObject a);
extern "C" LispObject Lindirect(LispObject env, LispObject a);
extern "C" LispObject Lintegerp(LispObject env, LispObject a);
extern "C" LispObject Lintern(LispObject env, LispObject a);
extern "C" LispObject Lionep(LispObject nil, LispObject a);
extern "C" LispObject Lisub1(LispObject env, LispObject a);
extern "C" LispObject Lizerop(LispObject nil, LispObject a);
extern "C" LispObject Llength(LispObject env, LispObject a);
extern "C" LispObject Llengthc(LispObject env, LispObject a);
extern "C" LispObject Llibrary_members(LispObject nil, LispObject a);
extern "C" LispObject Llinelength(LispObject env, LispObject a);
extern "C" LispObject Llist_to_string(LispObject env, LispObject a);
extern "C" LispObject Llist_to_vector(LispObject env, LispObject a);
extern "C" LispObject Lload_module(LispObject env, LispObject a);
extern "C" LispObject Lload_source(LispObject env, LispObject a);
extern "C" LispObject Llognot(LispObject env, LispObject a);
extern "C" LispObject Llog_1(LispObject nil, LispObject a);
extern "C" LispObject Llsd(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern "C" LispObject Lmacro_function(LispObject env, LispObject a);
extern "C" LispObject Lmake_global(LispObject env, LispObject a);
extern "C" LispObject Lmake_special(LispObject env, LispObject a);
extern "C" LispObject Lmapstore(LispObject env, LispObject a);
extern "C" LispObject Lmd5(LispObject env, LispObject a1);
extern "C" LispObject Lmd60(LispObject env, LispObject a1);
extern "C" LispObject Lminus(LispObject env, LispObject a);
extern "C" LispObject Lminusp(LispObject env, LispObject a);
extern "C" LispObject Lmkevect(LispObject nil, LispObject n);
extern "C" LispObject Lmkquote(LispObject env, LispObject a);
extern "C" LispObject Lmkvect(LispObject env, LispObject a);
extern "C" LispObject Lmodular_minus(LispObject env, LispObject a);
extern "C" LispObject Lmodular_number(LispObject env, LispObject a);
extern "C" LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern "C" LispObject Lmodule_exists(LispObject env, LispObject a);
extern "C" LispObject Lmsd(LispObject env, LispObject a);
extern "C" LispObject Lmv_list(LispObject nil, LispObject a);
extern "C" LispObject Lncons(LispObject env, LispObject a);
extern "C" LispObject Lnreverse(LispObject env, LispObject a);
extern "C" LispObject Lnull(LispObject env, LispObject a);
extern "C" LispObject Lnumberp(LispObject env, LispObject a);
extern "C" LispObject Loddp(LispObject env, LispObject a);
extern "C" LispObject Lonep(LispObject env, LispObject a);
extern "C" LispObject Lpagelength(LispObject env, LispObject a);
extern "C" LispObject Lplist(LispObject env, LispObject a);
extern "C" LispObject Lplusp(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin2a(LispObject nil, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprint(LispObject env, LispObject a);
extern "C" LispObject Lprintc(LispObject env, LispObject a);
extern "C" LispObject Lrandom(LispObject env, LispObject a);
extern "C" LispObject Lrational(LispObject env, LispObject a);
extern "C" LispObject Lrdf1(LispObject env, LispObject a);
extern "C" LispObject Lrds(LispObject env, LispObject a);
extern "C" LispObject Lremd(LispObject env, LispObject a);
extern "C" LispObject Lreverse(LispObject env, LispObject a);
extern "C" LispObject Lsetpchar(LispObject env, LispObject a);
extern "C" LispObject Lset_small_modulus(LispObject env, LispObject a);
extern "C" LispObject Lsmkvect(LispObject env, LispObject a);
extern "C" LispObject Lspecial_char(LispObject env, LispObject a);
extern "C" LispObject Lspecial_form_p(LispObject env, LispObject a);
extern "C" LispObject Lspool(LispObject env, LispObject a);
extern "C" LispObject Lstart_module(LispObject env, LispObject a);
extern "C" LispObject Lstop(LispObject env, LispObject a);
extern "C" LispObject Lstringp(LispObject env, LispObject a);
extern "C" LispObject Lsub1(LispObject env, LispObject a);
extern "C" LispObject Lsymbolp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_env(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_function(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_name(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_value(LispObject env, LispObject a);
extern "C" LispObject Lsystem(LispObject env, LispObject a);
extern "C" LispObject Lthreevectorp(LispObject env, LispObject a);
extern "C" LispObject Lthrow_nil(LispObject env, LispObject a);
extern "C" LispObject Ltrace(LispObject env, LispObject a);
extern "C" LispObject Ltraceset(LispObject env, LispObject a);
extern "C" LispObject Ltruncate(LispObject env, LispObject a);
extern "C" LispObject Lttab(LispObject env, LispObject a);
extern "C" LispObject Ltyo(LispObject env, LispObject a);
extern "C" LispObject Lunintern(LispObject env, LispObject a);
extern "C" LispObject Lunmake_global(LispObject env, LispObject a);
extern "C" LispObject Lunmake_special(LispObject env, LispObject a);
extern "C" LispObject Luntrace(LispObject env, LispObject a);
extern "C" LispObject Lupbv(LispObject env, LispObject a);
extern "C" LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern "C" LispObject Lvectorp(LispObject env, LispObject a);
extern "C" LispObject Lverbos(LispObject env, LispObject a);
extern "C" LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern "C" LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern "C" LispObject Lwrite_module(LispObject env, LispObject a);
extern "C" LispObject Lwrs(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lzerop(LispObject env, LispObject a);
#ifdef COMMON
extern "C" LispObject Lfind_symbol_1(LispObject nil, LispObject str);
extern "C" LispObject Llistp(LispObject env, LispObject a);
#endif
extern "C" LispObject autoload2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject double_byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject double_hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracefunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracesetfunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesetbyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesetbyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject tracesetbytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject jitcompileme2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject traceinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracesetinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracehardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesethardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesethardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject undefined2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
#ifdef CJAVA
extern "C" LispObject java2(LispObject env, LispObject a, LispObject b);
#endif
extern "C" LispObject Lappend(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lbpsgetv(LispObject nil, LispObject v, LispObject n);
extern "C" LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcopy_native(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldifference2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldivide(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leql(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqn(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lerror2(LispObject nil, LispObject a1, LispObject a2);
extern "C" LispObject Lerrorset2(LispObject nil, LispObject form, LispObject ffg1);
extern "C" LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfuncall2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lgcd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lhelp_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lidifference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligeq(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Ligreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lileq(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lilessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limax(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limin(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Linorm(LispObject nil, LispObject a, LispObject k);
extern "C" LispObject Linstate_c_code(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lintersect(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Liplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liremainder(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Litimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llcm(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llist2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lmax2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmin2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmod(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lneq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lpair(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrem(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lresource_limit2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrseek(LispObject nil, LispObject a);
extern "C" LispObject Lset(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lset_help_file(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lwrite_help_module(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lxcons(LispObject env, LispObject a, LispObject b);
#ifdef COMMON
extern "C" LispObject Laref2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfloat_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrandom_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
#endif
extern "C" LispObject autoloadn(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject double_bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject double_bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject double_byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject double_byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_funargedn(LispObject env, int nargs, ...);
extern "C" LispObject double_hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject double_hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject funargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracefunargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetfunargedn(LispObject env, int nargs, ...);
extern "C" LispObject hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracebyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracesetbyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracebyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracesetbyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracebytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject jitcompileme0(LispObject env, int nargs, ...);
extern "C" LispObject jitcompileme3(LispObject env, int nargs, ...);
extern "C" LispObject jitcompilemen(LispObject env, int nargs, ...);
extern "C" LispObject traceinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracehardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracesethardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracehardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracesethardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject undefinedn(LispObject env, int nargs, ...);
extern "C" LispObject f0_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_1(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_2(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_3(LispObject env, int nargs, ...);
#ifdef CJAVA
extern "C" LispObject java0(LispObject env, int nargs, ...);
extern "C" LispObject java3(LispObject env, int nargs, ...);
extern "C" LispObject javan(LispObject env, int nargs, ...);
#endif
extern "C" LispObject Lacons(LispObject env, int nargs, ...);
extern "C" LispObject Lapply_n(LispObject env, int nargs, ...);
extern "C" LispObject Lapply2(LispObject env, int nargs, ...);
extern "C" LispObject Lapply3(LispObject env, int nargs, ...);
extern "C" LispObject Lbpsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorset3(LispObject nil, int nargs, ...);
extern "C" LispObject Lerrorsetn(LispObject env, int nargs, ...);
extern "C" LispObject Lfuncalln(LispObject env, int nargs, ...);
extern "C" LispObject Lhelp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llist(LispObject env, int nargs, ...);
extern "C" LispObject Llist2star(LispObject env, int nargs, ...);
extern "C" LispObject Llist3(LispObject env, int nargs, ...);
extern "C" LispObject Llogand(LispObject env, int nargs, ...);
extern "C" LispObject Llogeqv(LispObject env, int nargs, ...);
extern "C" LispObject Llogor(LispObject env, int nargs, ...);
extern "C" LispObject Llogxor(LispObject env, int nargs, ...);
extern "C" LispObject Lmax(LispObject env, int nargs, ...);
extern "C" LispObject Lmin(LispObject env, int nargs, ...);
extern "C" LispObject Lmkhash(LispObject nil, int nargs, ...);
extern "C" LispObject Lput_hash(LispObject env, int nargs, ...);
extern "C" LispObject Lputprop(LispObject env, int nargs, ...);
extern "C" LispObject Lputv(LispObject env, int nargs, ...);
extern "C" LispObject Lresource_limitn(LispObject env, int nargs, ...);
extern "C" LispObject Lsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lsubst(LispObject env, int nargs, ...);
extern "C" LispObject Lvalues(LispObject env, int nargs, ...);
#ifdef COMMON
extern "C" LispObject Lappend_n(LispObject nil, int nargs, ...);
extern "C" LispObject Laref(LispObject env, int nargs, ...);
extern "C" LispObject Laset(LispObject env, int nargs, ...);
extern "C" LispObject Leqn_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lgcd_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgeq_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lget_3(LispObject env, int nargs, ...);
extern "C" LispObject Lgreaterp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llcm_n(LispObject env, int nargs, ...);
extern "C" LispObject Lleq_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llessp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lquotient_n(LispObject nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern "C" LispObject om_openFileDev(LispObject env, int nargs, ...);
extern "C" LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern "C" LispObject om_closeDev(LispObject env, LispObject dev);
extern "C" LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern "C" LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern "C" LispObject om_closeConn(LispObject nil, LispObject lconn);
extern "C" LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern "C" LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern "C" LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern "C" LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern "C" LispObject om_putApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_putBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_putBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_putError(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndError(LispObject nil, LispObject ldev);
extern "C" LispObject om_putObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern "C" LispObject om_getApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_getBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_getBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getError(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndError(LispObject nil, LispObject ldev);
extern "C" LispObject om_getObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_getInt(LispObject nil, LispObject ldev);
extern "C" LispObject om_getFloat(LispObject nil, LispObject ldev);
extern "C" LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern "C" LispObject om_getVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getString(LispObject nil, LispObject ldev);
extern "C" LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern "C" LispObject om_getType(LispObject nil, LispObject ldev);
extern "C" LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern "C" LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);
extern "C" LispObject om_read(LispObject nil, LispObject dev);
extern "C" LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern "C" LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern "C" LispObject om_listCDs(LispObject nil, int nargs, ...);
extern "C" LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern "C" LispObject om_whichCDs(LispObject nil, LispObject lsym);
#endif
#endif 



// Code for c!:extmult

static LispObject CC_cTextmult(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0052, v0053, v0054;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:extmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    v0052 = qvalue(elt(env, 1)); // nil
    stack[-5] = v0052;
    goto v0055;

v0055:
    v0052 = stack[-4];
    if (v0052 == nil) goto v0056;
    v0052 = stack[-3];
    v0052 = (v0052 == nil ? lisp_true : nil);
    goto v0057;

v0057:
    if (v0052 == nil) goto v0058;
    v0052 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0052;
    goto v0059;

v0059:
    v0052 = stack[-5];
    if (v0052 == nil) { LispObject res = stack[-1]; popv(7); return onevalue(res); }
    v0052 = stack[-5];
    v0052 = qcar(v0052);
    v0054 = v0052;
    v0052 = stack[-5];
    v0052 = qcdr(v0052);
    stack[-5] = v0052;
    v0052 = v0054;
    v0053 = qcar(v0052);
    v0052 = (LispObject)17; // 1
    if (v0053 == v0052) goto v0060;
    v0052 = v0054;
    v0053 = qcar(v0052);
    v0052 = (LispObject)33; // 2
    if (v0053 == v0052) goto v0061;
    v0052 = v0054;
    v0053 = qcar(v0052);
    v0052 = (LispObject)49; // 3
    if (v0053 == v0052) goto v0062;
    v0052 = v0054;
    v0053 = qcar(v0052);
    v0052 = (LispObject)65; // 4
    if (v0053 == v0052) goto v0063;
    v0052 = elt(env, 3); // "should never get here"
    fn = elt(env, 4); // rederr
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0052 = nil;
    { popv(7); return onevalue(v0052); }

v0063:
    v0052 = stack[-1];
    v0053 = v0054;
    v0053 = qcdr(v0053);
    fn = elt(env, 5); // c!:extadd
    v0052 = (*qfn2(fn))(qenv(fn), v0052, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-1] = v0052;
    goto v0059;

v0062:
    v0052 = v0054;
    v0052 = qcdr(v0052);
    v0054 = v0052;
    v0052 = v0054;
    v0052 = qcar(v0052);
    stack[-2] = v0052;
    v0052 = v0054;
    v0052 = qcdr(v0052);
    v0054 = v0052;
    v0052 = v0054;
    v0052 = qcar(v0052);
    stack[0] = v0052;
    v0052 = v0054;
    v0052 = qcdr(v0052);
    v0054 = v0052;
    v0052 = v0054;
    v0052 = qcar(v0052);
    stack[-4] = v0052;
    v0052 = v0054;
    v0052 = qcdr(v0052);
    stack[-3] = v0052;
    v0052 = stack[-4];
    v0052 = qcar(v0052);
    v0053 = qcdr(v0052);
    v0052 = stack[-3];
    v0052 = qcar(v0052);
    v0052 = qcdr(v0052);
    fn = elt(env, 6); // c!:subs2multf
    v0052 = (*qfn2(fn))(qenv(fn), v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0054 = v0052;
    v0052 = stack[0];
    v0052 = qcar(v0052);
    if (v0052 == nil) goto v0065;
    v0052 = v0054;
    fn = elt(env, 7); // negf
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0054 = v0052;
    goto v0065;

v0065:
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0053 = v0054;
    v0052 = cons(v0052, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[0] = ncons(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0053 = stack[-1];
    v0052 = stack[-2];
    fn = elt(env, 5); // c!:extadd
    v0052 = (*qfn2(fn))(qenv(fn), v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    fn = elt(env, 5); // c!:extadd
    v0052 = (*qfn2(fn))(qenv(fn), stack[0], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-1] = v0052;
    goto v0059;

v0061:
    v0052 = v0054;
    v0052 = qcdr(v0052);
    v0054 = v0052;
    v0052 = v0054;
    v0052 = qcar(v0052);
    stack[-4] = v0052;
    v0052 = v0054;
    v0052 = qcdr(v0052);
    stack[-3] = v0052;
    v0054 = (LispObject)65; // 4
    v0053 = stack[-1];
    v0052 = stack[-5];
    v0052 = acons(v0054, v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-5] = v0052;
    v0052 = stack[-4];
    v0052 = qcar(v0052);
    v0052 = ncons(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-4] = v0052;
    v0052 = stack[-3];
    v0052 = qcdr(v0052);
    stack[-3] = v0052;
    goto v0055;

v0060:
    v0052 = v0054;
    v0052 = qcdr(v0052);
    v0054 = v0052;
    v0052 = v0054;
    v0052 = qcar(v0052);
    stack[0] = v0052;
    v0052 = v0054;
    v0052 = qcdr(v0052);
    v0054 = v0052;
    v0052 = v0054;
    v0052 = qcar(v0052);
    stack[-4] = v0052;
    v0052 = v0054;
    v0052 = qcdr(v0052);
    stack[-3] = v0052;
    stack[-2] = (LispObject)49; // 3
    v0053 = stack[-4];
    v0052 = stack[-3];
    v0052 = cons(v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0053 = list2star(stack[-1], stack[0], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0052 = stack[-5];
    v0052 = acons(stack[-2], v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-5] = v0052;
    v0052 = stack[-4];
    v0052 = qcar(v0052);
    v0052 = ncons(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-4] = v0052;
    v0052 = stack[-3];
    v0052 = qcdr(v0052);
    stack[-3] = v0052;
    goto v0055;

v0058:
    v0053 = stack[-3];
    v0052 = (LispObject)17; // 1
    if (v0053 == v0052) goto v0066;
    v0052 = stack[-4];
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    v0053 = qcar(v0052);
    v0052 = stack[-3];
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    fn = elt(env, 8); // c!:ordexn
    v0052 = (*qfn2(fn))(qenv(fn), v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[0] = v0052;
    v0052 = stack[0];
    if (v0052 == nil) goto v0067;
    stack[-1] = (LispObject)17; // 1
    v0054 = stack[0];
    v0053 = stack[-4];
    v0052 = stack[-3];
    v0053 = list2star(v0054, v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0052 = stack[-5];
    v0052 = acons(stack[-1], v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-5] = v0052;
    v0052 = stack[-4];
    v0052 = qcdr(v0052);
    stack[-4] = v0052;
    goto v0055;

v0067:
    stack[0] = (LispObject)33; // 2
    v0053 = stack[-4];
    v0052 = stack[-3];
    v0053 = cons(v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0052 = stack[-5];
    v0052 = acons(stack[0], v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-5] = v0052;
    v0052 = stack[-4];
    v0052 = qcdr(v0052);
    stack[-4] = v0052;
    goto v0055;

v0066:
    v0052 = stack[-4];
    stack[-1] = v0052;
    goto v0059;

v0056:
    v0052 = qvalue(elt(env, 2)); // t
    goto v0057;
// error exit handlers
v0064:
    popv(7);
    return nil;
}



// Code for symtabget

static LispObject CC_symtabget(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0073, v0048, v0074, v0075;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symtabget");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0074 = v0001;
    v0048 = v0000;
// end of prologue
    v0073 = v0074;
    if (v0073 == nil) goto v0004;
    v0073 = v0048;
    if (!(v0073 == nil)) goto v0076;
    v0073 = qvalue(elt(env, 1)); // !*symboltable!*
    v0073 = qcar(v0073);
    goto v0076;

v0076:
    v0048 = v0073;
    goto v0004;

v0004:
    v0073 = v0048;
    if (v0073 == nil) goto v0077;
    v0073 = v0074;
    v0075 = elt(env, 2); // (!*type!* !*params!* !*decs!*)
    v0073 = Lmemq(nil, v0073, v0075);
    if (v0073 == nil) goto v0078;
    v0073 = v0048;
    v0048 = v0074;
    return get(v0073, v0048);

v0078:
    v0073 = v0074;
    if (!symbolp(v0048)) v0048 = nil;
    else { v0048 = qfastgets(v0048);
           if (v0048 != nil) { v0048 = elt(v0048, 58); // !*decs!*
#ifdef RECORD_GET
             if (v0048 != SPID_NOPROP)
                record_get(elt(fastget_names, 58), 1);
             else record_get(elt(fastget_names, 58), 0),
                v0048 = nil; }
           else record_get(elt(fastget_names, 58), 0); }
#else
             if (v0048 == SPID_NOPROP) v0048 = nil; }}
#endif
    v0073 = Lassoc(nil, v0073, v0048);
    return onevalue(v0073);

v0077:
    v0073 = qvalue(elt(env, 1)); // !*symboltable!*
    return onevalue(v0073);
}



// Code for getphystype

static LispObject CC_getphystype(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0087, v0088;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0087 = stack[0];
    fn = elt(env, 8); // physopp
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0087 == nil) goto v0072;
    v0087 = stack[0];
    fn = elt(env, 9); // scalopp
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0087 == nil) goto v0090;
    v0087 = elt(env, 1); // scalar
    { popv(3); return onevalue(v0087); }

v0090:
    v0087 = stack[0];
    fn = elt(env, 10); // vecopp
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0087 == nil) goto v0056;
    v0087 = elt(env, 2); // vector
    { popv(3); return onevalue(v0087); }

v0056:
    v0087 = stack[0];
    fn = elt(env, 11); // tensopp
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0087 == nil) goto v0091;
    v0087 = elt(env, 3); // tensor
    { popv(3); return onevalue(v0087); }

v0091:
    v0087 = stack[0];
    fn = elt(env, 12); // po!:statep
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0087 == nil) goto v0092;
    v0087 = elt(env, 4); // state
    { popv(3); return onevalue(v0087); }

v0092:
    v0087 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0087); }

v0072:
    v0087 = stack[0];
    if (!consp(v0087)) goto v0050;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    if (!symbolp(v0087)) v0088 = nil;
    else { v0088 = qfastgets(v0087);
           if (v0088 != nil) { v0088 = elt(v0088, 18); // phystype
#ifdef RECORD_GET
             if (v0088 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0088 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0088 == SPID_NOPROP) v0088 = nil; }}
#endif
    v0087 = v0088;
    if (!(v0088 == nil)) { popv(3); return onevalue(v0087); }
    v0087 = stack[0];
    v0088 = qcar(v0087);
    v0087 = elt(env, 6); // phystypefn
    v0088 = get(v0088, v0087);
    env = stack[-2];
    v0087 = v0088;
    if (v0088 == nil) goto v0047;
    v0088 = v0087;
    v0087 = stack[0];
    v0087 = qcdr(v0087);
        popv(3);
        return Lapply1(nil, v0088, v0087);

v0047:
    v0087 = stack[0];
    fn = elt(env, 13); // collectphystype
    v0088 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0087 = v0088;
    if (v0088 == nil) goto v0093;
    v0088 = v0087;
    v0088 = qcdr(v0088);
    if (v0088 == nil) goto v0094;
    v0088 = elt(env, 4); // state
    v0087 = Lmember(nil, v0088, v0087);
    if (v0087 == nil) goto v0095;
    v0087 = elt(env, 4); // state
    { popv(3); return onevalue(v0087); }

v0095:
    stack[-1] = elt(env, 0); // getphystype
    v0088 = elt(env, 7); // "PHYSOP type conflict in"
    v0087 = stack[0];
    v0087 = list2(v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    {
        LispObject v0096 = stack[-1];
        popv(3);
        fn = elt(env, 14); // rederr2
        return (*qfn2(fn))(qenv(fn), v0096, v0087);
    }

v0094:
    v0087 = qcar(v0087);
    { popv(3); return onevalue(v0087); }

v0093:
    v0087 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0087); }

v0050:
    v0087 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0087); }
// error exit handlers
v0089:
    popv(3);
    return nil;
}



// Code for contrsp2

static LispObject CC_contrsp2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0101, v0102;
    LispObject v0083, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0083 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contrsp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0083,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0083;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = (LispObject)33; // 2
    v0101 = stack[-2];
    v0101 = Llength(nil, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-4];
    if (stack[-3] == v0101) goto v0104;
    v0101 = nil;
    { popv(5); return onevalue(v0101); }

v0104:
    v0102 = stack[0];
    v0101 = stack[-2];
    v0101 = qcar(v0101);
    if (equal(v0102, v0101)) goto v0105;
    v0102 = stack[0];
    v0101 = stack[-2];
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    if (equal(v0102, v0101)) goto v0048;
    v0101 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0101); }

v0048:
    v0101 = stack[-2];
    v0102 = qcar(v0101);
    v0101 = stack[-1];
    popv(5);
    return cons(v0102, v0101);

v0105:
    v0101 = stack[-2];
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = stack[-1];
    popv(5);
    return cons(v0102, v0101);
// error exit handlers
v0103:
    popv(5);
    return nil;
}



// Code for lispapply

static LispObject CC_lispapply(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0050, v0070, v0107;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispapply");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0070 = v0001;
    v0107 = v0000;
// end of prologue
    v0050 = v0107;
    if (!consp(v0050)) goto v0105;
    stack[-1] = elt(env, 1); // rlisp
    stack[0] = (LispObject)33; // 2
    v0050 = elt(env, 2); // "Apply called with non-id arg"
    v0070 = v0107;
    v0050 = list2(v0050, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    {
        LispObject v0109 = stack[-1];
        LispObject v0110 = stack[0];
        popv(3);
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0109, v0110, v0050);
    }

v0105:
    v0050 = v0107;
    {
        popv(3);
        fn = elt(env, 4); // apply
        return (*qfn2(fn))(qenv(fn), v0050, v0070);
    }
// error exit handlers
v0108:
    popv(3);
    return nil;
}



// Code for mo!=deglist

static LispObject CC_moMdeglist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0122, v0123;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=deglist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0000;
// end of prologue
    v0122 = stack[-4];
    if (v0122 == nil) goto v0004;
    v0122 = stack[-4];
    v0123 = qcar(v0122);
    v0122 = qvalue(elt(env, 3)); // cali!=degrees
    v0122 = Lassoc(nil, v0123, v0122);
    stack[-5] = v0122;
    v0122 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 4); // ring_degrees
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    stack[-3] = v0122;
    v0122 = stack[-3];
    if (v0122 == nil) goto v0042;
    v0122 = stack[-3];
    v0122 = qcar(v0122);
    v0123 = stack[-4];
    v0123 = qcdr(v0123);
    fn = elt(env, 5); // mo!=sprod
    v0122 = (*qfn2(fn))(qenv(fn), v0123, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    v0122 = ncons(v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    stack[-1] = v0122;
    stack[-2] = v0122;
    goto v0094;

v0094:
    v0122 = stack[-3];
    v0122 = qcdr(v0122);
    stack[-3] = v0122;
    v0122 = stack[-3];
    if (v0122 == nil) goto v0040;
    stack[0] = stack[-1];
    v0122 = stack[-3];
    v0122 = qcar(v0122);
    v0123 = stack[-4];
    v0123 = qcdr(v0123);
    fn = elt(env, 5); // mo!=sprod
    v0122 = (*qfn2(fn))(qenv(fn), v0123, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    v0122 = ncons(v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    v0122 = Lrplacd(nil, stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    stack[-1] = v0122;
    goto v0094;

v0040:
    v0122 = stack[-2];
    v0123 = v0122;
    goto v0084;

v0084:
    v0122 = stack[-5];
    if (v0122 == nil) goto v0124;
    v0122 = stack[-5];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    goto v0043;

v0043:
    {
        popv(7);
        fn = elt(env, 6); // mo!=sum
        return (*qfn2(fn))(qenv(fn), v0123, v0122);
    }

v0124:
    v0122 = qvalue(elt(env, 2)); // nil
    goto v0043;

v0042:
    v0122 = qvalue(elt(env, 2)); // nil
    v0123 = v0122;
    goto v0084;

v0004:
    v0122 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 4); // ring_degrees
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    stack[-3] = v0122;
    v0122 = stack[-3];
    if (v0122 == nil) goto v0051;
    v0122 = (LispObject)1; // 0
    v0122 = ncons(v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    stack[-1] = v0122;
    stack[-2] = v0122;
    goto v0125;

v0125:
    v0122 = stack[-3];
    v0122 = qcdr(v0122);
    stack[-3] = v0122;
    v0122 = stack[-3];
    if (v0122 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0122 = (LispObject)1; // 0
    v0122 = ncons(v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    v0122 = Lrplacd(nil, stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-6];
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    stack[-1] = v0122;
    goto v0125;

v0051:
    v0122 = qvalue(elt(env, 2)); // nil
    { popv(7); return onevalue(v0122); }
// error exit handlers
v0026:
    popv(7);
    return nil;
}



// Code for pneg

static LispObject CC_pneg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0102, v0084;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pneg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0102 = v0000;
// end of prologue
    stack[-4] = v0102;
    v0102 = stack[-4];
    if (v0102 == nil) goto v0059;
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    v0084 = v0102;
    v0102 = v0084;
    stack[0] = qcar(v0102);
    v0102 = v0084;
    v0102 = qcdr(v0102);
    fn = elt(env, 2); // cneg
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-5];
    v0102 = cons(stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-5];
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-5];
    stack[-2] = v0102;
    stack[-3] = v0102;
    goto v0012;

v0012:
    v0102 = stack[-4];
    v0102 = qcdr(v0102);
    stack[-4] = v0102;
    v0102 = stack[-4];
    if (v0102 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    v0084 = v0102;
    v0102 = v0084;
    stack[0] = qcar(v0102);
    v0102 = v0084;
    v0102 = qcdr(v0102);
    fn = elt(env, 2); // cneg
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-5];
    v0102 = cons(stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-5];
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-5];
    v0102 = Lrplacd(nil, stack[-1], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-5];
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    stack[-2] = v0102;
    goto v0012;

v0059:
    v0102 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0102); }
// error exit handlers
v0111:
    popv(6);
    return nil;
}



// Code for gionep!:

static LispObject CC_gionepT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0105, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gionep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0058 = v0000;
// end of prologue
    v0066 = v0058;
    v0066 = qcdr(v0066);
    v0105 = qcar(v0066);
    v0066 = (LispObject)17; // 1
    if (v0105 == v0066) goto v0130;
    v0066 = qvalue(elt(env, 1)); // nil
    return onevalue(v0066);

v0130:
    v0066 = v0058;
    v0066 = qcdr(v0066);
    v0105 = qcdr(v0066);
    v0066 = (LispObject)1; // 0
    v0066 = (v0105 == v0066 ? lisp_true : nil);
    return onevalue(v0066);
}



// Code for setdiff

static LispObject CC_setdiff(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0105, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0001;
    v0105 = v0000;
// end of prologue

v0015:
    v0058 = stack[0];
    if (v0058 == nil) { popv(2); return onevalue(v0105); }
    v0058 = v0105;
    if (v0058 == nil) goto v0125;
    v0058 = stack[0];
    v0058 = qcar(v0058);
    v0105 = Ldelete(nil, v0058, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    stack[0] = v0058;
    goto v0015;

v0125:
    v0105 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0105); }
// error exit handlers
v0131:
    popv(2);
    return nil;
}



// Code for preptayexp

static LispObject CC_preptayexp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0125, v0100;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for preptayexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0100 = v0000;
// end of prologue
    v0125 = v0100;
    if (!consp(v0125)) return onevalue(v0100);
    v0125 = v0100;
    {
        fn = elt(env, 1); // rnprep!:
        return (*qfn1(fn))(qenv(fn), v0125);
    }
}



// Code for cl_simplat

static LispObject CC_cl_simplat(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0092, v0106, v0049;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_simplat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0106 = v0001;
    v0049 = v0000;
// end of prologue
    v0092 = qvalue(elt(env, 1)); // !*rlidentify
    if (v0092 == nil) goto v0076;
    v0092 = v0049;
    fn = elt(env, 3); // rl_simplat1
    v0106 = (*qfn2(fn))(qenv(fn), v0092, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[0];
    v0092 = elt(env, 2); // cl_identifyat
    {
        popv(1);
        fn = elt(env, 4); // cl_apply2ats
        return (*qfn2(fn))(qenv(fn), v0106, v0092);
    }

v0076:
    v0092 = v0049;
    {
        popv(1);
        fn = elt(env, 3); // rl_simplat1
        return (*qfn2(fn))(qenv(fn), v0092, v0106);
    }
// error exit handlers
v0050:
    popv(1);
    return nil;
}



// Code for ibalp_litlp

static LispObject CC_ibalp_litlp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0128;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_litlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue

v0133:
    v0128 = stack[0];
    if (v0128 == nil) goto v0004;
    v0128 = stack[0];
    v0128 = qcar(v0128);
    fn = elt(env, 3); // ibalp_litp
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    if (v0128 == nil) goto v0125;
    v0128 = stack[0];
    v0128 = qcdr(v0128);
    stack[0] = v0128;
    goto v0133;

v0125:
    v0128 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0128); }

v0004:
    v0128 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0128); }
// error exit handlers
v0099:
    popv(2);
    return nil;
}



// Code for initbrsea

static LispObject CC_initbrsea(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0116, v0117, v0034;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initbrsea");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for initbrsea");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// end of prologue
    v0116 = (LispObject)3201; // 200
    stack[-2] = v0116;
    v0116 = qvalue(elt(env, 1)); // rowmin
    stack[-1] = v0116;
    goto v0077;

v0077:
    v0117 = qvalue(elt(env, 2)); // rowmax
    v0116 = stack[-1];
    v0116 = difference2(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0116 = Lminusp(nil, v0116);
    env = stack[-3];
    if (v0116 == nil) goto v0092;
    fn = elt(env, 8); // redcodmat
    v0116 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0116 = qvalue(elt(env, 6)); // codhisto
    if (v0116 == nil) goto v0095;
    v0116 = (LispObject)1; // 0
    stack[0] = v0116;
    goto v0094;

v0094:
    v0117 = (LispObject)3201; // 200
    v0116 = stack[0];
    v0116 = difference2(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0116 = Lminusp(nil, v0116);
    env = stack[-3];
    if (!(v0116 == nil)) goto v0086;
    v0034 = qvalue(elt(env, 6)); // codhisto
    v0117 = stack[0];
    v0116 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0034 + (CELL-TAG_VECTOR) + ((int32_t)v0117/(16/CELL))) = v0116;
    v0116 = stack[0];
    v0116 = add1(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    stack[0] = v0116;
    goto v0094;

v0086:
    v0116 = (LispObject)1; // 0
    qvalue(elt(env, 7)) = v0116; // headhisto
    v0116 = (LispObject)1; // 0
    stack[0] = v0116;
    goto v0114;

v0114:
    v0117 = qvalue(elt(env, 2)); // rowmax
    v0116 = stack[0];
    v0116 = difference2(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0116 = Lminusp(nil, v0116);
    env = stack[-3];
    if (v0116 == nil) goto v0143;
    v0116 = nil;
    { popv(4); return onevalue(v0116); }

v0143:
    v0116 = stack[0];
    fn = elt(env, 9); // inshisto
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0116 = stack[0];
    v0116 = add1(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    stack[0] = v0116;
    goto v0114;

v0095:
    v0116 = stack[-2];
    v0116 = Lmkvect(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    qvalue(elt(env, 6)) = v0116; // codhisto
    goto v0086;

v0092:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0117 = qvalue(elt(env, 5)); // maxvar
    v0116 = stack[-1];
    v0116 = plus2(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0117 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0116/(16/CELL)));
    v0116 = (LispObject)1; // 0
    v0116 = *(LispObject *)((char *)v0117 + (CELL-TAG_VECTOR) + ((int32_t)v0116/(16/CELL)));
    if (v0116 == nil) goto v0099;
    v0116 = stack[-1];
    fn = elt(env, 10); // initwght
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0099;

v0099:
    v0116 = stack[-1];
    v0116 = add1(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    stack[-1] = v0116;
    goto v0077;
// error exit handlers
v0142:
    popv(4);
    return nil;
}



// Code for !:difference

static LispObject CC_Tdifference(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0097, v0145, v0113, v0135;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0113 = v0001;
    v0135 = v0000;
// end of prologue
    v0097 = v0135;
    if (v0097 == nil) goto v0015;
    v0097 = v0113;
    if (v0097 == nil) return onevalue(v0135);
    v0145 = v0135;
    v0097 = v0113;
    if (equal(v0145, v0097)) goto v0090;
    v0097 = v0135;
    if (!consp(v0097)) goto v0066;
    v0097 = qvalue(elt(env, 1)); // nil
    goto v0071;

v0071:
    if (v0097 == nil) goto v0047;
    v0097 = v0135;
    v0145 = v0113;
    return difference2(v0097, v0145);

v0047:
    v0145 = v0135;
    v0097 = elt(env, 2); // difference
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0145, v0113, v0097);
    }

v0066:
    v0097 = v0113;
    v0097 = (consp(v0097) ? nil : lisp_true);
    goto v0071;

v0090:
    v0097 = qvalue(elt(env, 1)); // nil
    return onevalue(v0097);

v0015:
    v0097 = v0113;
    {
        fn = elt(env, 4); // !:minus
        return (*qfn1(fn))(qenv(fn), v0097);
    }
}



// Code for opnum!*

static LispObject CC_opnumH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0103, v0119, v0111;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opnum*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0119 = v0000;
// end of prologue
    stack[-1] = nil;
    v0103 = v0119;
    if (symbolp(v0103)) goto v0072;
    stack[0] = v0119;
    v0103 = v0119;
    fn = elt(env, 3); // collectindices
    v0103 = (*qfn1(fn))(qenv(fn), v0103);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-2];
    fn = elt(env, 4); // removeindices
    v0103 = (*qfn2(fn))(qenv(fn), stack[0], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-2];
    v0119 = v0103;
    goto v0072;

v0072:
    v0103 = v0119;
    if (symbolp(v0103)) goto v0128;
    v0103 = v0119;
    v0103 = qcar(v0103);
    v0119 = qcdr(v0119);
    stack[-1] = v0119;
    goto v0049;

v0049:
    v0119 = v0103;
    v0103 = elt(env, 2); // opnum
    v0103 = get(v0119, v0103);
    env = stack[-2];
    v0111 = v0103;
    v0119 = stack[-1];
    v0103 = v0111;
    v0103 = Lassoc(nil, v0119, v0103);
    v0119 = v0103;
    if (v0103 == nil) goto v0145;
    v0103 = v0119;
    v0103 = qcdr(v0103);
    { popv(3); return onevalue(v0103); }

v0145:
    v0103 = qvalue(elt(env, 1)); // nil
    v0119 = v0111;
    v0103 = Lassoc(nil, v0103, v0119);
    v0103 = qcdr(v0103);
    { popv(3); return onevalue(v0103); }

v0128:
    v0103 = v0119;
    goto v0049;
// error exit handlers
v0146:
    popv(3);
    return nil;
}



// Code for prin2t

static LispObject CC_prin2t(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prin2t");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0005 = stack[0];
    v0005 = Lprinc(nil, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    v0005 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0072:
    popv(2);
    return nil;
}



// Code for errorset2

static LispObject CC_errorset2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0057, v0056;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for errorset2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0057 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // !*protfg
    qvalue(elt(env, 1)) = nil; // !*protfg
    v0051 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0051; // !*protfg
    v0056 = v0057;
    v0057 = qvalue(elt(env, 3)); // nil
    v0051 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 4); // errorset
    v0051 = (*qfnn(fn))(qenv(fn), 3, v0056, v0057, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*protfg
    { popv(2); return onevalue(v0051); }
// error exit handlers
v0141:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*protfg
    popv(2);
    return nil;
}



// Code for mv!-pow!-!+

static LispObject CC_mvKpowKL(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0070, v0107;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-+");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0005;

v0005:
    v0070 = stack[-1];
    if (v0070 == nil) goto v0076;
    v0070 = stack[-1];
    v0107 = qcar(v0070);
    v0070 = stack[0];
    v0070 = qcar(v0070);
    v0107 = plus2(v0107, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0070 = stack[-2];
    v0070 = cons(v0107, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    stack[-2] = v0070;
    v0070 = stack[-1];
    v0070 = qcdr(v0070);
    stack[-1] = v0070;
    v0070 = stack[0];
    v0070 = qcdr(v0070);
    stack[0] = v0070;
    goto v0005;

v0076:
    v0070 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0070);
    }
// error exit handlers
v0109:
    popv(4);
    return nil;
}



// Code for conv!:bf2i

static LispObject CC_convTbf2i(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0090, v0130;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for conv:bf2i");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0090 = v0000;
// end of prologue
    v0130 = v0090;
    v0130 = qcdr(v0130);
    v0130 = qcar(v0130);
    v0090 = qcdr(v0090);
    v0090 = qcdr(v0090);
    {
        fn = elt(env, 1); // ashift
        return (*qfn2(fn))(qenv(fn), v0130, v0090);
    }
}



// Code for qqe_ofsf_prepat

static LispObject CC_qqe_ofsf_prepat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0130;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_prepat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0130 = stack[0];
    fn = elt(env, 1); // qqe_op
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    fn = elt(env, 2); // qqe_rqopp
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    if (v0130 == nil) goto v0059;
    v0130 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); // qqe_prepat
        return (*qfn1(fn))(qenv(fn), v0130);
    }

v0059:
    v0130 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // ofsf_prepat
        return (*qfn1(fn))(qenv(fn), v0130);
    }
// error exit handlers
v0051:
    popv(2);
    return nil;
}



// Code for comfac!-to!-poly

static LispObject CC_comfacKtoKpoly(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0090, v0130;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comfac-to-poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0090 = v0000;
// end of prologue
    v0130 = v0090;
    v0130 = qcar(v0130);
    if (v0130 == nil) goto v0004;
    return ncons(v0090);

v0004:
    v0090 = qcdr(v0090);
    return onevalue(v0090);
}



// Code for ibalp_vequal

static LispObject CC_ibalp_vequal(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0100, v0090;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_vequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0100 = v0001;
    v0090 = v0000;
// end of prologue
    v0090 = qcar(v0090);
    v0100 = qcar(v0100);
    v0100 = (v0090 == v0100 ? lisp_true : nil);
    return onevalue(v0100);
}



// Code for quotk

static LispObject CC_quotk(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0146, v0046, v0044;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    v0046 = qcdr(v0146);
    v0146 = stack[0];
    fn = elt(env, 2); // quotf1
    v0146 = (*qfn2(fn))(qenv(fn), v0046, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-3];
    stack[-2] = v0146;
    v0146 = stack[-2];
    if (v0146 == nil) goto v0111;
    v0146 = stack[-1];
    v0146 = qcdr(v0146);
    if (v0146 == nil) goto v0071;
    v0146 = stack[-1];
    v0046 = qcdr(v0146);
    v0146 = stack[0];
    fn = elt(env, 2); // quotf1
    v0146 = (*qfn2(fn))(qenv(fn), v0046, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-3];
    v0046 = v0146;
    v0146 = v0046;
    if (v0146 == nil) goto v0093;
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    v0044 = qcar(v0146);
    v0146 = stack[-2];
    popv(4);
    return acons(v0044, v0146, v0046);

v0093:
    v0146 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0146); }

v0071:
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    v0046 = qcar(v0146);
    v0146 = stack[-2];
    v0146 = cons(v0046, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    popv(4);
    return ncons(v0146);

v0111:
    v0146 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0146); }
// error exit handlers
v0147:
    popv(4);
    return nil;
}



// Code for testred

static LispObject CC_testred(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0155, v0156, v0157;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0156 = qvalue(elt(env, 2)); // maxvar
    v0155 = stack[0];
    v0155 = plus2(v0156, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0156 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0155 = (LispObject)1; // 0
    v0155 = *(LispObject *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    if (v0155 == nil) goto v0015;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0156 = qvalue(elt(env, 2)); // maxvar
    v0155 = stack[0];
    v0155 = plus2(v0156, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0156 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0155 = (LispObject)17; // 1
    v0155 = *(LispObject *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0155 = qcar(v0155);
    v0156 = qcar(v0155);
    v0155 = (LispObject)33; // 2
    v0155 = (LispObject)lessp2(v0156, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0155 = v0155 ? lisp_true : nil;
    env = stack[-2];
    if (v0155 == nil) goto v0015;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0156 = qvalue(elt(env, 2)); // maxvar
    v0155 = stack[0];
    v0155 = plus2(v0156, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0157 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0156 = (LispObject)1; // 0
    v0155 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0157 + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL))) = v0155;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0156 = qvalue(elt(env, 2)); // maxvar
    v0155 = stack[0];
    v0155 = plus2(v0156, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0156 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0155 = (LispObject)65; // 4
    v0155 = *(LispObject *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    stack[-1] = v0155;
    goto v0137;

v0137:
    v0155 = stack[-1];
    if (v0155 == nil) goto v0060;
    v0155 = stack[-1];
    v0155 = qcar(v0155);
    stack[0] = v0155;
    v0155 = stack[0];
    v0156 = qcar(v0155);
    v0155 = stack[0];
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    fn = elt(env, 4); // downwght1
    v0155 = (*qfn2(fn))(qenv(fn), v0156, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0155 = stack[0];
    v0155 = qcar(v0155);
    v0155 = CC_testred(env, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0155 = stack[-1];
    v0155 = qcdr(v0155);
    stack[-1] = v0155;
    goto v0137;

v0060:
    v0155 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0155); }

v0015:
    v0155 = nil;
    { popv(3); return onevalue(v0155); }
// error exit handlers
v0028:
    popv(3);
    return nil;
}



// Code for xdegree

static LispObject CC_xdegree(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0090, v0130;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xdegree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0090 = v0000;
// end of prologue
    fn = elt(env, 1); // deg!*form
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    errexit();
    v0130 = v0090;
    v0090 = v0130;
    if (!(v0090 == nil)) return onevalue(v0130);
    v0090 = (LispObject)1; // 0
    return onevalue(v0090);
}



// Code for token1

static LispObject CC_token1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0276, v0277;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "token1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for token1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// end of prologue
    stack[-2] = nil;
    v0276 = qvalue(elt(env, 1)); // crchar!*
    stack[-3] = v0276;
    goto v0140;

v0140:
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0070;
    v0276 = stack[-3];
    fn = elt(env, 37); // id2string
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0277 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = (LispObject)17; // 1
    v0276 = (v0277 == v0276 ? lisp_true : nil);
    v0276 = (v0276 == nil ? lisp_true : nil);
    goto v0050;

v0050:
    if (!(v0276 == nil)) goto v0012;
    v0276 = stack[-3];
    v0276 = Lwhitespace_char_p(nil, v0276);
    env = stack[-4];
    if (v0276 == nil) goto v0084;
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 4)); // !$eol!$
    if (v0277 == v0276) goto v0279;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0111;

v0111:
    if (!(v0276 == nil)) goto v0084;
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    goto v0140;

v0084:
    v0276 = stack[-3];
    v0276 = Ldigitp(nil, v0276);
    env = stack[-4];
    if (v0276 == nil) goto v0082;
    v0276 = stack[-3];
    {
        popv(5);
        fn = elt(env, 40); // token!-number
        return (*qfn1(fn))(qenv(fn), v0276);
    }

v0082:
    v0276 = stack[-3];
    v0276 = Lalpha_char_p(nil, v0276);
    env = stack[-4];
    if (!(v0276 == nil)) goto v0076;
    v0277 = stack[-3];
    v0276 = elt(env, 7); // tokprop
    v0276 = get(v0277, v0276);
    env = stack[-4];
    stack[-2] = v0276;
    if (v0276 == nil) goto v0280;
    v0277 = stack[-2];
    v0276 = qvalue(elt(env, 6)); // nil
    {
        popv(5);
        fn = elt(env, 41); // lispapply
        return (*qfn2(fn))(qenv(fn), v0277, v0276);
    }

v0280:
    v0277 = stack[-3];
    v0276 = elt(env, 8); // !%
    if (v0277 == v0276) goto v0281;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0282;

v0282:
    if (v0276 == nil) goto v0155;
    stack[-1] = qvalue(elt(env, 21)); // !*raise
    qvalue(elt(env, 21)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 22)); // !*lower
    qvalue(elt(env, 22)) = nil; // !*lower
    goto v0283;

v0283:
    v0276 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 35)) = v0276; // named!-character!*
    fn = elt(env, 39); // readch1
    v0277 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-4];
    stack[-3] = v0277;
    v0276 = qvalue(elt(env, 4)); // !$eol!$
    if (v0277 == v0276) goto v0285;
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    v0276 = (v0277 == v0276 ? lisp_true : nil);
    goto v0286;

v0286:
    if (v0276 == nil) goto v0287;
    v0276 = qvalue(elt(env, 35)); // named!-character!*
    goto v0288;

v0288:
    if (!(v0276 == nil)) goto v0283;
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    goto v0140;

v0287:
    v0276 = qvalue(elt(env, 3)); // t
    goto v0288;

v0285:
    v0276 = qvalue(elt(env, 3)); // t
    goto v0286;

v0155:
    v0277 = stack[-3];
    v0276 = elt(env, 10); // !!
    if (v0277 == v0276) goto v0122;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0289;

v0289:
    if (!(v0276 == nil)) goto v0072;
    v0277 = stack[-3];
    v0276 = elt(env, 13); // !"
    if (v0277 == v0276) goto v0066;
    v0277 = stack[-3];
    v0276 = elt(env, 14); // !\ (backslash)
    if (!(v0277 == v0276)) goto v0012;
    v0276 = elt(env, 31); // (!\ e n d !{ r e d u c e !})
    stack[-2] = v0276;
    v0276 = qvalue(elt(env, 6)); // nil
    stack[0] = v0276;
    goto v0290;

v0290:
    v0277 = stack[-3];
    v0276 = stack[0];
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[0] = v0276;
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    v0276 = stack[-2];
    v0276 = qcdr(v0276);
    stack[-2] = v0276;
    v0276 = stack[-2];
    if (v0276 == nil) goto v0051;
    v0277 = stack[-3];
    v0276 = stack[-2];
    v0276 = qcar(v0276);
    if (v0277 == v0276) goto v0290;
    v0277 = stack[-3];
    v0276 = stack[0];
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = Lreverse(nil, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = qcdr(v0276);
    qvalue(elt(env, 32)) = v0276; // peekchar!*
    v0276 = (LispObject)49; // 3
    qvalue(elt(env, 15)) = v0276; // ttype!*
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0276; // crchar!*
    v0276 = elt(env, 14); // !\ (backslash)
    qvalue(elt(env, 17)) = v0276; // nxtsym!*
    v0276 = qvalue(elt(env, 17)); // nxtsym!*
    { popv(5); return onevalue(v0276); }

v0051:
    v0276 = elt(env, 33); // (!\ b e g i n !{ r e d u c e !})
    stack[-2] = v0276;
    v0276 = (LispObject)49; // 3
    qvalue(elt(env, 15)) = v0276; // ttype!*
    goto v0291;

v0291:
    v0277 = stack[-3];
    v0276 = elt(env, 8); // !%
    if (v0277 == v0276) goto v0056;
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0292;
    v0276 = stack[-2];
    if (v0276 == nil) goto v0140;
    v0276 = stack[-3];
    stack[0] = v0276;
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    v0277 = stack[0];
    v0276 = stack[-2];
    v0276 = qcar(v0276);
    if (!(v0277 == v0276)) goto v0051;
    v0276 = stack[-2];
    v0276 = qcdr(v0276);
    stack[-2] = v0276;
    goto v0291;

v0292:
    v0276 = elt(env, 16); // ! 
    qvalue(elt(env, 1)) = v0276; // crchar!*
    fn = elt(env, 42); // filenderr
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = stack[-3];
    qvalue(elt(env, 17)) = v0276; // nxtsym!*
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0056:
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0291;
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 4)); // !$eol!$
    if (v0277 == v0276) goto v0051;
    else goto v0056;

v0012:
    v0276 = (LispObject)49; // 3
    qvalue(elt(env, 15)) = v0276; // ttype!*
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (!(v0277 == v0276)) goto v0293;
    v0276 = elt(env, 16); // ! 
    qvalue(elt(env, 1)) = v0276; // crchar!*
    fn = elt(env, 42); // filenderr
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    goto v0293;

v0293:
    v0276 = stack[-3];
    qvalue(elt(env, 17)) = v0276; // nxtsym!*
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0294;
    v0276 = stack[-3];
    fn = elt(env, 37); // id2string
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0277 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = (LispObject)17; // 1
    if (v0277 == v0276) goto v0295;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0296;

v0296:
    if (v0276 == nil) goto v0016;
    v0276 = elt(env, 16); // ! 
    qvalue(elt(env, 1)) = v0276; // crchar!*
    goto v0294;

v0294:
    v0277 = stack[-3];
    v0276 = elt(env, 18); // !-
    if (v0277 == v0276) goto v0297;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0298;

v0298:
    if (v0276 == nil) goto v0090;
    v0276 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 40); // token!-number
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    v0276 = stack[-3];
    if (is_number(v0276)) goto v0299;
    v0276 = stack[-3];
    stack[0] = qcdr(v0276);
    v0277 = elt(env, 20); // minus
    v0276 = stack[-3];
    v0276 = qcdr(v0276);
    v0276 = qcar(v0276);
    v0276 = Lapply1(nil, v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = Lrplaca(nil, stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0299:
    v0277 = elt(env, 20); // minus
    v0276 = stack[-3];
        popv(5);
        return Lapply1(nil, v0277, v0276);

v0090:
    v0276 = qvalue(elt(env, 17)); // nxtsym!*
    { popv(5); return onevalue(v0276); }

v0297:
    v0277 = qvalue(elt(env, 1)); // crchar!*
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0300;
    v0276 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 37); // id2string
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0277 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = (LispObject)17; // 1
    if (v0277 == v0276) goto v0301;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0298;

v0301:
    v0276 = qvalue(elt(env, 1)); // crchar!*
    v0276 = Ldigitp(nil, v0276);
    env = stack[-4];
    if (v0276 == nil) goto v0006;
    v0276 = qvalue(elt(env, 19)); // !*minusliter
    goto v0298;

v0006:
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0298;

v0300:
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0298;

v0016:
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0276; // crchar!*
    goto v0294;

v0295:
    v0276 = stack[-3];
    fn = elt(env, 43); // delcp
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    goto v0296;

v0066:
    stack[-1] = qvalue(elt(env, 21)); // !*raise
    qvalue(elt(env, 21)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 22)); // !*lower
    qvalue(elt(env, 22)) = nil; // !*lower
    goto v0302;

v0302:
    v0276 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-4];
    stack[-3] = v0276;
    goto v0304;

v0304:
    v0276 = stack[-3];
    if (v0276 == nil) goto v0305;
    v0276 = stack[-3];
    v0277 = qcar(v0276);
    v0276 = stack[-2];
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-4];
    stack[-2] = v0276;
    v0276 = stack[-3];
    v0276 = qcdr(v0276);
    stack[-3] = v0276;
    goto v0304;

v0305:
    v0276 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 35)) = v0276; // named!-character!*
    fn = elt(env, 39); // readch1
    v0277 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-4];
    stack[-3] = v0277;
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0306;
    v0277 = stack[-3];
    v0276 = elt(env, 13); // !"
    if (v0277 == v0276) goto v0307;
    v0276 = qvalue(elt(env, 3)); // t
    goto v0308;

v0308:
    if (!(v0276 == nil)) goto v0302;

v0309:
    v0276 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 35)) = v0276; // named!-character!*
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-4];
    stack[-3] = v0276;
    v0277 = stack[-3];
    v0276 = elt(env, 13); // !"
    if (v0277 == v0276) goto v0310;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0311;

v0311:
    if (!(v0276 == nil)) goto v0302;
    v0276 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-4];
    v0276 = qcdr(v0276);
    fn = elt(env, 46); // list2widestring
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-4];
    qvalue(elt(env, 17)) = v0276; // nxtsym!*
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    v0276 = (LispObject)17; // 1
    qvalue(elt(env, 15)) = v0276; // ttype!*
    v0276 = stack[-3];
    qvalue(elt(env, 1)) = v0276; // crchar!*
    goto v0090;

v0310:
    v0276 = qvalue(elt(env, 35)); // named!-character!*
    v0276 = (v0276 == nil ? lisp_true : nil);
    goto v0311;

v0307:
    v0276 = qvalue(elt(env, 35)); // named!-character!*
    goto v0308;

v0306:
    v0276 = elt(env, 16); // ! 
    qvalue(elt(env, 1)) = v0276; // crchar!*
    v0277 = elt(env, 36); // "***** End-of-file in string"
    v0276 = qvalue(elt(env, 6)); // nil
    fn = elt(env, 47); // lpriw
    v0276 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-4];
    fn = elt(env, 42); // filenderr
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-4];
    goto v0309;

v0072:
    stack[-1] = qvalue(elt(env, 21)); // !*raise
    qvalue(elt(env, 21)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 22)); // !*lower
    qvalue(elt(env, 22)) = nil; // !*lower
    v0276 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 23)) = v0276; // escaped!*
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    stack[-3] = v0276;
    v0276 = stack[-3];
    v0276 = Lalpha_char_p(nil, v0276);
    env = stack[-4];
    if (v0276 == nil) goto v0313;
    v0276 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 23)) = v0276; // escaped!*
    goto v0313;

v0313:
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    goto v0076;

v0076:
    v0276 = (LispObject)1; // 0
    qvalue(elt(env, 15)) = v0276; // ttype!*
    goto v0055;

v0055:
    v0276 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    goto v0059;

v0059:
    v0276 = stack[-3];
    if (v0276 == nil) goto v0125;
    v0276 = stack[-3];
    v0277 = qcar(v0276);
    v0276 = stack[-2];
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-2] = v0276;
    v0276 = stack[-3];
    v0276 = qcdr(v0276);
    stack[-3] = v0276;
    goto v0059;

v0125:
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0314;
    v0276 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 37); // id2string
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0277 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = (LispObject)17; // 1
    v0276 = (v0277 == v0276 ? lisp_true : nil);
    v0276 = (v0276 == nil ? lisp_true : nil);
    goto v0315;

v0315:
    if (!(v0276 == nil)) goto v0100;
    v0276 = stack[-3];
    v0276 = Ldigitp(nil, v0276);
    env = stack[-4];
    if (!(v0276 == nil)) goto v0055;
    v0276 = stack[-3];
    v0276 = Lalpha_char_p(nil, v0276);
    env = stack[-4];
    if (!(v0276 == nil)) goto v0055;
    v0277 = stack[-3];
    v0276 = elt(env, 10); // !!
    if (v0277 == v0276) goto v0072;
    v0277 = stack[-3];
    v0276 = elt(env, 18); // !-
    if (v0277 == v0276) goto v0316;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0317;

v0317:
    if (!(v0276 == nil)) goto v0055;
    v0277 = stack[-3];
    v0276 = elt(env, 24); // !_
    if (v0277 == v0276) goto v0055;
    v0277 = stack[-3];
    v0276 = elt(env, 25); // !:
    if (!(v0277 == v0276)) goto v0100;
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    v0277 = stack[-3];
    v0276 = elt(env, 25); // !:
    if (v0277 == v0276) goto v0141;
    v0276 = stack[-3];
    v0276 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    qvalue(elt(env, 32)) = v0276; // peekchar!*
    v0276 = elt(env, 25); // !:
    stack[-3] = v0276;
    goto v0100;

v0100:
    v0276 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 48); // list2wideid
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-2] = v0276;
    v0277 = stack[-2];
    v0276 = qvalue(elt(env, 26)); // !*line!-marker
    if (equal(v0277, v0276)) goto v0318;
    v0277 = stack[-2];
    v0276 = qvalue(elt(env, 28)); // !*file!-marker
    if (equal(v0277, v0276)) goto v0319;
    v0276 = stack[-2];
    qvalue(elt(env, 17)) = v0276; // nxtsym!*
    goto v0320;

v0320:
    v0276 = stack[-3];
    qvalue(elt(env, 1)) = v0276; // crchar!*
    goto v0090;

v0319:
    v0276 = qvalue(elt(env, 29)); // ifl!*
    if (v0276 == nil) goto v0321;
    v0276 = qvalue(elt(env, 29)); // ifl!*
    v0276 = qcar(v0276);
    goto v0322;

v0322:
    qvalue(elt(env, 17)) = v0276; // nxtsym!*
    goto v0320;

v0321:
    v0276 = elt(env, 30); // "Terminal"
    goto v0322;

v0318:
    v0276 = qvalue(elt(env, 27)); // curline!*
    qvalue(elt(env, 17)) = v0276; // nxtsym!*
    goto v0320;

v0141:
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0323;
    v0276 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 37); // id2string
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0277 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = (LispObject)17; // 1
    if (v0277 == v0276) goto v0324;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0325;

v0325:
    if (v0276 == nil) goto v0326;
    v0276 = stack[-2];
    v0276 = Lreverse(nil, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 48); // list2wideid
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = elt(env, 25); // !:
    fn = elt(env, 49); // string2list
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[0] = qcar(v0276);
    v0276 = elt(env, 25); // !:
    fn = elt(env, 49); // string2list
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0277 = qcar(v0276);
    v0276 = stack[-2];
    v0276 = list2star(stack[0], v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-2] = v0276;
    goto v0128;

v0128:
    v0276 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    goto v0091;

v0091:
    v0276 = stack[-3];
    if (v0276 == nil) goto v0099;
    v0276 = stack[-3];
    v0277 = qcar(v0276);
    v0276 = stack[-2];
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-2] = v0276;
    v0276 = stack[-3];
    v0276 = qcdr(v0276);
    stack[-3] = v0276;
    goto v0091;

v0099:
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-3] = v0276;
    v0277 = stack[-3];
    v0276 = qvalue(elt(env, 2)); // !$eof!$
    if (v0277 == v0276) goto v0327;
    v0276 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 37); // id2string
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0277 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = (LispObject)17; // 1
    v0276 = (v0277 == v0276 ? lisp_true : nil);
    v0276 = (v0276 == nil ? lisp_true : nil);
    goto v0328;

v0328:
    if (!(v0276 == nil)) goto v0127;
    v0276 = stack[-3];
    v0276 = Ldigitp(nil, v0276);
    env = stack[-4];
    if (!(v0276 == nil)) goto v0128;
    v0276 = stack[-3];
    v0276 = Lalpha_char_p(nil, v0276);
    env = stack[-4];
    if (!(v0276 == nil)) goto v0128;
    v0277 = stack[-3];
    v0276 = elt(env, 10); // !!
    if (v0277 == v0276) goto v0071;
    v0277 = stack[-3];
    v0276 = elt(env, 18); // !-
    if (v0277 == v0276) goto v0329;
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0330;

v0330:
    if (!(v0276 == nil)) goto v0128;
    v0277 = stack[-3];
    v0276 = elt(env, 24); // !_
    if (v0277 == v0276) goto v0128;
    else goto v0127;

v0127:
    v0276 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 48); // list2wideid
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-2] = v0276;
    v0277 = elt(env, 34); // "Name with double colon in detected:"
    v0276 = stack[-2];
    v0276 = list2(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 50); // lprim
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0276 = stack[-2];
    qvalue(elt(env, 17)) = v0276; // nxtsym!*
    v0276 = stack[-3];
    qvalue(elt(env, 1)) = v0276; // crchar!*
    v0276 = qvalue(elt(env, 17)); // nxtsym!*
    { popv(5); return onevalue(v0276); }

v0329:
    v0276 = qvalue(elt(env, 19)); // !*minusliter
    goto v0330;

v0071:
    stack[-1] = qvalue(elt(env, 21)); // !*raise
    qvalue(elt(env, 21)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 22)); // !*lower
    qvalue(elt(env, 22)) = nil; // !*lower
    v0276 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 23)) = v0276; // escaped!*
    fn = elt(env, 39); // readch1
    v0276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0331;
    env = stack[-4];
    stack[-3] = v0276;
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    goto v0128;

v0327:
    v0276 = qvalue(elt(env, 3)); // t
    goto v0328;

v0326:
    v0277 = elt(env, 25); // !:
    v0276 = stack[-3];
    v0276 = list2(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    qvalue(elt(env, 32)) = v0276; // peekchar!*
    v0276 = elt(env, 25); // !:
    stack[-3] = v0276;
    goto v0100;

v0324:
    v0276 = stack[-3];
    v0276 = Lalpha_char_p(nil, v0276);
    env = stack[-4];
    goto v0325;

v0323:
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0325;

v0316:
    v0276 = qvalue(elt(env, 19)); // !*minusliter
    goto v0317;

v0314:
    v0276 = qvalue(elt(env, 3)); // t
    goto v0315;

v0122:
    v0276 = qvalue(elt(env, 11)); // !*micro!-version
    if (v0276 == nil) goto v0332;
    v0276 = qvalue(elt(env, 12)); // !*defn
    v0276 = (v0276 == nil ? lisp_true : nil);
    goto v0333;

v0333:
    v0276 = (v0276 == nil ? lisp_true : nil);
    goto v0289;

v0332:
    v0276 = qvalue(elt(env, 6)); // nil
    goto v0333;

v0281:
    v0276 = qvalue(elt(env, 9)); // !*savecomments!*
    v0276 = (v0276 == nil ? lisp_true : nil);
    goto v0282;

v0279:
    v0276 = qvalue(elt(env, 5)); // !*eoldelimp
    goto v0111;

v0070:
    v0276 = qvalue(elt(env, 3)); // t
    goto v0050;
// error exit handlers
v0331:
    env = stack[-4];
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0312:
    env = stack[-4];
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0303:
    env = stack[-4];
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0284:
    env = stack[-4];
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0278:
    popv(5);
    return nil;
}



// Code for kernp

static LispObject CC_kernp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0044, v0045, v0042;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0045 = v0000;
// end of prologue
    v0044 = v0045;
    v0042 = qcdr(v0044);
    v0044 = (LispObject)17; // 1
    if (v0042 == v0044) goto v0004;
    v0044 = qvalue(elt(env, 2)); // nil
    return onevalue(v0044);

v0004:
    v0044 = v0045;
    v0044 = qcar(v0044);
    v0045 = v0044;
    v0042 = v0044;
    v0044 = v0042;
    if (!consp(v0044)) goto v0128;
    v0044 = v0042;
    v0044 = qcar(v0044);
    v0044 = (consp(v0044) ? nil : lisp_true);
    goto v0129;

v0129:
    if (v0044 == nil) goto v0077;
    v0044 = qvalue(elt(env, 2)); // nil
    return onevalue(v0044);

v0077:
    v0044 = v0045;
    v0044 = qcdr(v0044);
    if (v0044 == nil) goto v0109;
    v0044 = qvalue(elt(env, 2)); // nil
    return onevalue(v0044);

v0109:
    v0044 = v0045;
    v0044 = qcar(v0044);
    v0042 = qcdr(v0044);
    v0044 = (LispObject)17; // 1
    if (v0042 == v0044) goto v0074;
    v0044 = qvalue(elt(env, 2)); // nil
    return onevalue(v0044);

v0074:
    v0044 = v0045;
    v0044 = qcar(v0044);
    v0044 = qcar(v0044);
    v0045 = qcdr(v0044);
    v0044 = (LispObject)17; // 1
    v0044 = (v0045 == v0044 ? lisp_true : nil);
    return onevalue(v0044);

v0128:
    v0044 = qvalue(elt(env, 1)); // t
    goto v0129;
}



// Code for crprcd

static LispObject CC_crprcd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0104, v0141;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crprcd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    v0104 = qcar(v0104);
    fn = elt(env, 1); // convprec!*
    stack[-1] = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    fn = elt(env, 1); // convprec!*
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0141 = stack[-1];
    popv(3);
    return cons(v0141, v0104);
// error exit handlers
v0091:
    popv(3);
    return nil;
}



// Code for matrix!+p

static LispObject CC_matrixLp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086, v0097;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrix+p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0086 = stack[0];
    v0097 = Llength(nil, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    v0086 = (LispObject)17; // 1
    v0086 = (LispObject)lessp2(v0097, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    v0086 = v0086 ? lisp_true : nil;
    env = stack[-4];
    if (v0086 == nil) goto v0072;
    v0086 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0086); }

v0072:
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = Llength(nil, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    stack[-3] = v0086;
    v0086 = qvalue(elt(env, 2)); // t
    stack[-2] = v0086;
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    goto v0066;

v0066:
    v0086 = stack[-1];
    if (v0086 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    stack[0] = stack[-3];
    v0086 = Llength(nil, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    if (equal(stack[0], v0086)) goto v0108;
    v0086 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0086;
    goto v0108;

v0108:
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    goto v0066;
// error exit handlers
v0102:
    popv(5);
    return nil;
}



// Code for ibalp_simpat

static LispObject CC_ibalp_simpat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0141;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_simpat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    v0141 = stack[-1];
    stack[-2] = qcar(v0141);
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    v0141 = qcar(v0141);
    fn = elt(env, 1); // ibalp_simpterm
    stack[0] = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    v0141 = qcdr(v0141);
    v0141 = qcar(v0141);
    fn = elt(env, 1); // ibalp_simpterm
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    {
        LispObject v0127 = stack[-2];
        LispObject v0071 = stack[0];
        popv(4);
        fn = elt(env, 2); // ibalp_mk2
        return (*qfnn(fn))(qenv(fn), 3, v0127, v0071, v0141);
    }
// error exit handlers
v0099:
    popv(4);
    return nil;
}



// Code for objectom

static LispObject CC_objectom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0068, v0047, v0098;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for objectom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0047 = v0000;
// end of prologue
    v0068 = v0047;
    v0068 = Lconsp(nil, v0068);
    env = stack[-1];
    if (v0068 == nil) goto v0109;
    v0068 = v0047;
    v0098 = qcar(v0068);
    v0068 = qvalue(elt(env, 1)); // ir2mml!*
    v0068 = Lassoc(nil, v0098, v0068);
    v0098 = v0068;
    if (v0068 == nil) goto v0070;
    v0068 = v0098;
    v0068 = qcdr(v0068);
    v0068 = qcdr(v0068);
    v0068 = qcdr(v0068);
    stack[0] = qcar(v0068);
    v0068 = v0047;
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    fn = elt(env, 3); // apply
    v0068 = (*qfn2(fn))(qenv(fn), stack[0], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    goto v0005;

v0005:
    v0068 = nil;
    { popv(2); return onevalue(v0068); }

v0070:
    v0068 = v0047;
    fn = elt(env, 4); // fnom
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    goto v0005;

v0109:
    v0068 = v0047;
    fn = elt(env, 5); // basicom
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    goto v0005;
// error exit handlers
v0048:
    popv(2);
    return nil;
}



// Code for ident

static LispObject CC_ident(LispObject env,
                         LispObject v0000)
{
    LispObject v0023;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ident");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0023 = v0000;
// end of prologue
    return onevalue(v0023);
}



// Code for dim!<deg

static LispObject CC_dimRdeg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0105;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dim<deg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0066 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // dimex!*
    fn = elt(env, 4); // deg!*farg
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-1];
    fn = elt(env, 5); // negf
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-1];
    fn = elt(env, 6); // addf
    v0066 = (*qfn2(fn))(qenv(fn), stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-1];
    v0105 = v0066;
    v0066 = v0105;
    if (!(is_number(v0066))) goto v0099;
    v0066 = v0105;
    v0066 = Lminusp(nil, v0066);
    env = stack[-1];
    if (v0066 == nil) goto v0099;
    v0066 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0066); }

v0099:
    v0066 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0066); }
// error exit handlers
v0132:
    popv(2);
    return nil;
}



// Code for id2bytelist

static LispObject CC_id2bytelist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for id2bytelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0015 = v0000;
// end of prologue
    fn = elt(env, 1); // id2string
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // string2bytelist
        return (*qfn1(fn))(qenv(fn), v0015);
    }
// error exit handlers
v0005:
    popv(1);
    return nil;
}



// Code for assert_analyze

static LispObject CC_assert_analyze(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0342, v0003;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_analyze");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_analyze");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// end of prologue
    v0342 = (LispObject)1; // 0
    stack[0] = v0342;
    v0342 = (LispObject)1; // 0
    stack[-4] = v0342;
    v0342 = (LispObject)1; // 0
    stack[-2] = v0342;
    v0003 = qvalue(elt(env, 1)); // assertstatistics!*
    v0342 = elt(env, 2); // lambda_wrlijy187crc
    fn = elt(env, 8); // sort
    v0342 = (*qfn2(fn))(qenv(fn), v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0342; // assertstatistics!*
    v0342 = qvalue(elt(env, 1)); // assertstatistics!*
    stack[-3] = v0342;
    goto v0129;

v0129:
    v0342 = stack[-3];
    if (v0342 == nil) goto v0141;
    v0342 = stack[-3];
    v0342 = qcar(v0342);
    stack[-1] = v0342;
    v0003 = stack[0];
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    v0342 = plus2(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = v0342;
    v0003 = stack[-4];
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    v0342 = plus2(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[-4] = v0342;
    v0003 = stack[-2];
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    v0342 = plus2(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[-2] = v0342;
    v0342 = stack[-3];
    v0342 = qcdr(v0342);
    stack[-3] = v0342;
    goto v0129;

v0141:
    v0342 = elt(env, 4); // (function !#calls !#bad! calls !#assertion! violations)
    stack[-3] = v0342;
    stack[-1] = elt(env, 5); // sum
    v0003 = stack[-4];
    v0342 = stack[-2];
    v0342 = list2(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = list2star(stack[-1], stack[0], v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[-4] = qvalue(elt(env, 3)); // nil
    stack[-2] = qvalue(elt(env, 3)); // nil
    stack[-1] = qvalue(elt(env, 3)); // nil
    stack[0] = v0342;
    v0003 = qvalue(elt(env, 3)); // nil
    v0342 = qvalue(elt(env, 1)); // assertstatistics!*
    v0342 = cons(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = list2star(stack[-1], stack[0], v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = Lnreverse(nil, v0342);
    env = stack[-5];
    v0342 = cons(stack[-2], v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = list2star(stack[-4], stack[-3], v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0342; // assertstatistics!*
    v0342 = qvalue(elt(env, 1)); // assertstatistics!*
    stack[-2] = v0342;
    goto v0344;

v0344:
    v0342 = stack[-2];
    if (v0342 == nil) goto v0142;
    v0342 = stack[-2];
    v0342 = qcar(v0342);
    stack[-1] = v0342;
    v0342 = stack[-1];
    if (v0342 == nil) goto v0345;
    v0342 = stack[-1];
    v0342 = qcar(v0342);
    v0342 = Lprinc(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = stack[-1];
    v0342 = qcar(v0342);
    v0342 = Lexplodec(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = Llength(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    v0342 = Lexplodec(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = Llength(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = plus2(stack[0], v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = v0342;
    goto v0346;

v0346:
    v0003 = (LispObject)369; // 23
    v0342 = stack[0];
    v0342 = difference2(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = Lminusp(nil, v0342);
    env = stack[-5];
    if (v0342 == nil) goto v0271;
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    v0342 = Lprinc(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    v0342 = Lexplodec(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = Llength(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = v0342;
    goto v0347;

v0347:
    v0003 = (LispObject)369; // 23
    v0342 = stack[0];
    v0342 = difference2(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = Lminusp(nil, v0342);
    env = stack[-5];
    if (v0342 == nil) goto v0348;
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    v0342 = Lprinc(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    v0342 = Lexplodec(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = Llength(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = v0342;
    goto v0349;

v0349:
    v0003 = (LispObject)369; // 23
    v0342 = stack[0];
    v0342 = difference2(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = Lminusp(nil, v0342);
    env = stack[-5];
    if (v0342 == nil) goto v0350;
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    fn = elt(env, 9); // prin2t
    v0342 = (*qfn1(fn))(qenv(fn), v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    goto v0157;

v0157:
    v0342 = stack[-2];
    v0342 = qcdr(v0342);
    stack[-2] = v0342;
    goto v0344;

v0350:
    v0342 = elt(env, 6); // " "
    v0342 = Lprinc(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = stack[0];
    v0342 = add1(v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = v0342;
    goto v0349;

v0348:
    v0342 = elt(env, 6); // " "
    v0342 = Lprinc(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = stack[0];
    v0342 = add1(v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = v0342;
    goto v0347;

v0271:
    v0342 = elt(env, 6); // " "
    v0342 = Lprinc(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = stack[0];
    v0342 = add1(v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = v0342;
    goto v0346;

v0345:
    v0342 = (LispObject)17; // 1
    stack[0] = v0342;
    goto v0351;

v0351:
    v0003 = (LispObject)1153; // 72
    v0342 = stack[0];
    v0342 = difference2(v0003, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = Lminusp(nil, v0342);
    env = stack[-5];
    if (v0342 == nil) goto v0352;
    v0342 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    goto v0157;

v0352:
    v0342 = elt(env, 7); // "-"
    v0342 = Lprinc(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    v0342 = stack[0];
    v0342 = add1(v0342);
    nil = C_nil;
    if (exception_pending()) goto v0343;
    env = stack[-5];
    stack[0] = v0342;
    goto v0351;

v0142:
    v0342 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 1)) = v0342; // assertstatistics!*
    v0342 = nil;
    { popv(6); return onevalue(v0342); }
// error exit handlers
v0343:
    popv(6);
    return nil;
}



// Code for lambda_wrlijy187crc

static LispObject CC_lambda_wrlijy187crc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0100, v0090;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_wrlijy187crc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0090 = v0001;
    v0100 = v0000;
// end of prologue
    v0090 = qcar(v0090);
    v0100 = qcar(v0100);
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(qenv(fn), v0090, v0100);
    }
}



// Code for maprint

static LispObject CC_maprint(LispObject env,
                         LispObject v0001, LispObject v0083)
{
    LispObject nil = C_nil;
    LispObject v0367, v0010, v0011;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0367 = v0083;
    stack[-3] = v0001;
// end of prologue
    stack[-4] = qvalue(elt(env, 1)); // p!*!*
    qvalue(elt(env, 1)) = nil; // p!*!*
    qvalue(elt(env, 1)) = v0367; // p!*!*
    stack[0] = nil;
    v0367 = qvalue(elt(env, 1)); // p!*!*
    stack[-2] = v0367;
    v0367 = stack[-3];
    if (v0367 == nil) goto v0077;
    v0367 = stack[-3];
    if (!consp(v0367)) goto v0104;
    v0367 = stack[-3];
    v0367 = qcar(v0367);
    if (!consp(v0367)) goto v0121;
    v0367 = stack[-3];
    v0010 = qcar(v0367);
    v0367 = stack[-2];
    v0367 = CC_maprint(env, v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    goto v0130;

v0130:
    v0367 = elt(env, 5); // "("
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0367 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 10)) = v0367; // obrkp!*
    v0367 = qvalue(elt(env, 8)); // orig!*
    stack[0] = v0367;
    v0010 = qvalue(elt(env, 9)); // posn!*
    v0367 = (LispObject)289; // 18
    v0367 = (LispObject)lessp2(v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0367 = v0367 ? lisp_true : nil;
    env = stack[-5];
    if (v0367 == nil) goto v0017;
    v0367 = qvalue(elt(env, 9)); // posn!*
    goto v0368;

v0368:
    qvalue(elt(env, 8)) = v0367; // orig!*
    v0367 = stack[-3];
    v0367 = qcdr(v0367);
    if (v0367 == nil) goto v0294;
    v0011 = elt(env, 11); // !*comma!*
    v0010 = (LispObject)1; // 0
    v0367 = stack[-3];
    v0367 = qcdr(v0367);
    fn = elt(env, 13); // inprint
    v0367 = (*qfnn(fn))(qenv(fn), 3, v0011, v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    goto v0294;

v0294:
    v0367 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 10)) = v0367; // obrkp!*
    v0367 = stack[0];
    qvalue(elt(env, 8)) = v0367; // orig!*
    v0367 = elt(env, 6); // ")"
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0367 = stack[-3];
    goto v0005;

v0005:
    qvalue(elt(env, 1)) = stack[-4]; // p!*!*
    { popv(6); return onevalue(v0367); }

v0017:
    v0010 = qvalue(elt(env, 8)); // orig!*
    v0367 = (LispObject)49; // 3
    v0367 = plus2(v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    goto v0368;

v0121:
    v0367 = stack[-3];
    v0367 = qcar(v0367);
    if (!symbolp(v0367)) v0367 = nil;
    else { v0367 = qfastgets(v0367);
           if (v0367 != nil) { v0367 = elt(v0367, 60); // pprifn
#ifdef RECORD_GET
             if (v0367 != SPID_NOPROP)
                record_get(elt(fastget_names, 60), 1);
             else record_get(elt(fastget_names, 60), 0),
                v0367 = nil; }
           else record_get(elt(fastget_names, 60), 0); }
#else
             if (v0367 == SPID_NOPROP) v0367 = nil; }}
#endif
    stack[-1] = v0367;
    if (v0367 == nil) goto v0040;
    v0011 = stack[-1];
    v0010 = stack[-3];
    v0367 = stack[-2];
    v0010 = Lapply2(nil, 3, v0011, v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0367 = elt(env, 7); // failed
    if (!(v0010 == v0367)) goto v0340;

v0040:
    v0367 = stack[-3];
    v0367 = qcar(v0367);
    if (!symbolp(v0367)) v0367 = nil;
    else { v0367 = qfastgets(v0367);
           if (v0367 != nil) { v0367 = elt(v0367, 57); // prifn
#ifdef RECORD_GET
             if (v0367 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0367 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0367 == SPID_NOPROP) v0367 = nil; }}
#endif
    stack[-1] = v0367;
    if (v0367 == nil) goto v0039;
    v0010 = stack[-1];
    v0367 = stack[-3];
    v0010 = Lapply1(nil, v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0367 = elt(env, 7); // failed
    if (!(v0010 == v0367)) goto v0340;

v0039:
    v0367 = stack[-3];
    v0367 = qcar(v0367);
    if (!symbolp(v0367)) v0367 = nil;
    else { v0367 = qfastgets(v0367);
           if (v0367 != nil) { v0367 = elt(v0367, 23); // infix
#ifdef RECORD_GET
             if (v0367 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0367 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0367 == SPID_NOPROP) v0367 = nil; }}
#endif
    stack[-1] = v0367;
    if (v0367 == nil) goto v0337;
    v0010 = stack[-1];
    v0367 = stack[-2];
    v0367 = (LispObject)greaterp2(v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0367 = v0367 ? lisp_true : nil;
    env = stack[-5];
    v0367 = (v0367 == nil ? lisp_true : nil);
    stack[-2] = v0367;
    v0367 = stack[-2];
    if (v0367 == nil) goto v0369;
    v0367 = qvalue(elt(env, 8)); // orig!*
    stack[0] = v0367;
    v0367 = elt(env, 5); // "("
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0010 = qvalue(elt(env, 9)); // posn!*
    v0367 = (LispObject)289; // 18
    v0367 = (LispObject)lessp2(v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0367 = v0367 ? lisp_true : nil;
    env = stack[-5];
    if (v0367 == nil) goto v0370;
    v0367 = qvalue(elt(env, 9)); // posn!*
    goto v0270;

v0270:
    qvalue(elt(env, 8)) = v0367; // orig!*
    goto v0369;

v0369:
    v0367 = stack[-3];
    v0011 = qcar(v0367);
    v0010 = stack[-1];
    v0367 = stack[-3];
    v0367 = qcdr(v0367);
    fn = elt(env, 13); // inprint
    v0367 = (*qfnn(fn))(qenv(fn), 3, v0011, v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0367 = stack[-2];
    if (v0367 == nil) goto v0371;
    v0367 = elt(env, 6); // ")"
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0367 = stack[0];
    qvalue(elt(env, 8)) = v0367; // orig!*
    goto v0371;

v0371:
    v0367 = stack[-3];
    goto v0005;

v0370:
    v0010 = qvalue(elt(env, 8)); // orig!*
    v0367 = (LispObject)49; // 3
    v0367 = plus2(v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    goto v0270;

v0337:
    v0367 = stack[-3];
    v0367 = qcar(v0367);
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    goto v0130;

v0340:
    v0367 = stack[-3];
    goto v0005;

v0104:
    v0367 = stack[-3];
    v0367 = Lsimple_vectorp(nil, v0367);
    env = stack[-5];
    if (v0367 == nil) goto v0127;
    v0010 = stack[-3];
    v0367 = qvalue(elt(env, 1)); // p!*!*
    fn = elt(env, 14); // vec!-maprin
    v0367 = (*qfn2(fn))(qenv(fn), v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    goto v0091;

v0091:
    v0367 = stack[-3];
    goto v0005;

v0127:
    v0367 = stack[-3];
    if (is_number(v0367)) goto v0075;
    v0367 = qvalue(elt(env, 3)); // t
    goto v0078;

v0078:
    if (v0367 == nil) goto v0046;
    v0367 = stack[-3];
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    goto v0091;

v0046:
    v0367 = elt(env, 5); // "("
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0367 = stack[-3];
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    v0367 = elt(env, 6); // ")"
    fn = elt(env, 12); // prin2!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-5];
    goto v0091;

v0075:
    v0010 = stack[-3];
    v0367 = (LispObject)1; // 0
    v0367 = (LispObject)lessp2(v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0367 = v0367 ? lisp_true : nil;
    env = stack[-5];
    if (v0367 == nil) goto v0073;
    v0010 = stack[-2];
    v0367 = elt(env, 4); // minus
    if (!symbolp(v0367)) v0367 = nil;
    else { v0367 = qfastgets(v0367);
           if (v0367 != nil) { v0367 = elt(v0367, 23); // infix
#ifdef RECORD_GET
             if (v0367 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0367 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0367 == SPID_NOPROP) v0367 = nil; }}
#endif
    v0367 = (LispObject)lesseq2(v0010, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0367 = v0367 ? lisp_true : nil;
    env = stack[-5];
    goto v0078;

v0073:
    v0367 = qvalue(elt(env, 3)); // t
    goto v0078;

v0077:
    v0367 = qvalue(elt(env, 2)); // nil
    goto v0005;
// error exit handlers
v0260:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; // p!*!*
    popv(6);
    return nil;
}



// Code for !*i2gi

static LispObject CC_Hi2gi(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0100, v0090, v0130;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2gi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0100 = v0000;
// end of prologue
    v0130 = elt(env, 1); // !:gi!:
    v0090 = v0100;
    v0100 = (LispObject)1; // 0
    return list2star(v0130, v0090, v0100);
}



// Code for freevarinexptchk

static LispObject CC_freevarinexptchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freevarinexptchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue

v0133:
    v0108 = stack[0];
    if (!consp(v0108)) goto v0072;
    v0108 = stack[0];
    v0108 = qcar(v0108);
    v0108 = (consp(v0108) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0108 == nil) goto v0004;
    v0108 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0108); }

v0004:
    v0108 = stack[0];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    if (is_number(v0108)) goto v0127;
    v0108 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0108); }

v0127:
    v0108 = stack[0];
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = CC_freevarinexptchk(env, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-1];
    if (!(v0108 == nil)) { popv(2); return onevalue(v0108); }
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    stack[0] = v0108;
    goto v0133;

v0072:
    v0108 = qvalue(elt(env, 1)); // t
    goto v0012;
// error exit handlers
v0110:
    popv(2);
    return nil;
}



// Code for searchtm

static LispObject CC_searchtm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0131, v0092;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for searchtm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0092 = v0000;
// end of prologue
    v0131 = v0092;
    if (!consp(v0131)) goto v0072;
    v0131 = v0092;
    v0131 = qcar(v0131);
    v0131 = (consp(v0131) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0131 == nil) goto v0141;
    v0131 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0131); }

v0141:
    v0131 = v0092;
    v0131 = qcar(v0131);
    stack[0] = qcar(v0131);
    v0131 = v0092;
    v0131 = qcdr(v0131);
    fn = elt(env, 3); // searchpl
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    {
        LispObject v0050 = stack[0];
        popv(1);
        return cons(v0050, v0131);
    }

v0072:
    v0131 = qvalue(elt(env, 1)); // t
    goto v0012;
// error exit handlers
v0049:
    popv(1);
    return nil;
}



// Code for bcone!?

static LispObject CC_bconeW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0109, v0110;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcone?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0110 = v0000;
// end of prologue
    v0108 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0108 == nil) goto v0141;
    v0109 = v0110;
    v0108 = (LispObject)17; // 1
        return Leqn(nil, v0109, v0108);

v0141:
    v0108 = v0110;
    v0109 = qcdr(v0108);
    v0108 = (LispObject)17; // 1
    if (v0109 == v0108) goto v0105;
    v0108 = qvalue(elt(env, 2)); // nil
    return onevalue(v0108);

v0105:
    v0108 = v0110;
    v0109 = qcar(v0108);
    v0108 = (LispObject)17; // 1
    v0108 = (v0109 == v0108 ? lisp_true : nil);
    return onevalue(v0108);
}



// Code for ncmpchk

static LispObject CC_ncmpchk(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0127, v0071;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ncmpchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0071 = stack[-1];
    v0127 = stack[0];
    fn = elt(env, 2); // noncommuting
    v0127 = (*qfn2(fn))(qenv(fn), v0071, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    if (v0127 == nil) goto v0015;
    v0071 = stack[-1];
    v0127 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // physop!-ordop
        return (*qfn2(fn))(qenv(fn), v0071, v0127);
    }

v0015:
    v0127 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0127); }
// error exit handlers
v0058:
    popv(3);
    return nil;
}



// Code for contrsp

static LispObject CC_contrsp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0107, v0140, v0078;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contrsp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    v0078 = qcar(v0107);
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    v0107 = qcdr(v0107);
    v0140 = qcar(v0107);
    v0107 = stack[0];
    fn = elt(env, 1); // contrsp2
    v0107 = (*qfnn(fn))(qenv(fn), 3, v0078, v0140, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    if (!(v0107 == nil)) { popv(3); return onevalue(v0107); }
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    v0107 = qcdr(v0107);
    v0078 = qcar(v0107);
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    v0140 = qcar(v0107);
    v0107 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // contrsp2
        return (*qfnn(fn))(qenv(fn), 3, v0078, v0140, v0107);
    }
// error exit handlers
v0110:
    popv(3);
    return nil;
}



// Code for take!-realpart

static LispObject CC_takeKrealpart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0071, v0066;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for take-realpart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0071 = stack[0];
    v0071 = qcar(v0071);
    fn = elt(env, 1); // repartf
    v0066 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    v0071 = (LispObject)17; // 1
    stack[-1] = cons(v0066, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    v0066 = (LispObject)17; // 1
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    v0071 = cons(v0066, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    {
        LispObject v0131 = stack[-1];
        popv(3);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0131, v0071);
    }
// error exit handlers
v0132:
    popv(3);
    return nil;
}



// Code for cali_bc_fi

static LispObject CC_cali_bc_fi(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0057, v0056;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_bc_fi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0056 = v0000;
// end of prologue
    v0057 = v0056;
    v0051 = (LispObject)1; // 0
    if (!(v0057 == v0051)) return onevalue(v0056);
    v0051 = qvalue(elt(env, 1)); // nil
    return onevalue(v0051);
}



// Code for oprin

static LispObject CC_oprin(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0084, v0043;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oprin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0084 = stack[0];
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 37); // prtch
#ifdef RECORD_GET
             if (v0084 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0084 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; }}
#endif
    stack[-1] = v0084;
    v0084 = stack[-1];
    if (v0084 == nil) goto v0012;
    v0084 = qvalue(elt(env, 2)); // !*fort
    if (v0084 == nil) goto v0051;
    v0084 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0084);
    }

v0051:
    v0084 = qvalue(elt(env, 3)); // !*list
    if (v0084 == nil) goto v0129;
    v0084 = qvalue(elt(env, 4)); // obrkp!*
    if (v0084 == nil) goto v0129;
    v0043 = stack[0];
    v0084 = elt(env, 5); // (plus minus)
    v0084 = Lmemq(nil, v0043, v0084);
    if (v0084 == nil) goto v0129;
    v0084 = qvalue(elt(env, 6)); // testing!-width!*
    if (v0084 == nil) goto v0110;
    v0084 = qvalue(elt(env, 7)); // t
    qvalue(elt(env, 8)) = v0084; // overflowed!*
    { popv(3); return onevalue(v0084); }

v0110:
    v0084 = qvalue(elt(env, 7)); // t
    fn = elt(env, 10); // terpri!*
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0084 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0084);
    }

v0129:
    v0084 = stack[0];
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 61); // spaced
#ifdef RECORD_GET
             if (v0084 == SPID_NOPROP)
                record_get(elt(fastget_names, 61), 0),
                v0084 = nil;
             else record_get(elt(fastget_names, 61), 1),
                v0084 = lisp_true; }
           else record_get(elt(fastget_names, 61), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; else v0084 = lisp_true; }}
#endif
    if (v0084 == nil) goto v0113;
    v0084 = elt(env, 1); // " "
    fn = elt(env, 9); // prin2!*
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0084 = stack[-1];
    fn = elt(env, 9); // prin2!*
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0084 = elt(env, 1); // " "
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0084);
    }

v0113:
    v0084 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0084);
    }

v0012:
    v0084 = elt(env, 1); // " "
    fn = elt(env, 9); // prin2!*
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0084 = stack[0];
    fn = elt(env, 9); // prin2!*
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0084 = elt(env, 1); // " "
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0084);
    }
// error exit handlers
v0103:
    popv(3);
    return nil;
}



// Code for th_match0

static LispObject CC_th_match0(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0092, v0106, v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for th_match0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    v0049 = v0000;
// end of prologue
    v0092 = v0049;
    v0106 = qcar(v0092);
    v0092 = stack[0];
    v0092 = qcar(v0092);
    if (equal(v0106, v0092)) goto v0077;
    v0092 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0092); }

v0077:
    v0092 = v0049;
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    stack[-1] = Llength(nil, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-2];
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    v0092 = Llength(nil, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    v0092 = (equal(stack[-1], v0092) ? lisp_true : nil);
    { popv(3); return onevalue(v0092); }
// error exit handlers
v0107:
    popv(3);
    return nil;
}



// Code for searchpl

static LispObject CC_searchpl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0144, v0085;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for searchpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    stack[-1] = nil;
    goto v0005;

v0005:
    v0144 = stack[0];
    if (!consp(v0144)) goto v0130;
    v0144 = stack[0];
    v0144 = qcar(v0144);
    v0144 = (consp(v0144) ? nil : lisp_true);
    goto v0090;

v0090:
    if (v0144 == nil) goto v0099;
    v0144 = qvalue(elt(env, 2)); // nil
    v0085 = v0144;
    goto v0072;

v0072:
    v0144 = stack[-1];
    if (v0144 == nil) { popv(3); return onevalue(v0085); }
    v0144 = stack[-1];
    v0144 = qcar(v0144);
    fn = elt(env, 3); // setunion
    v0144 = (*qfn2(fn))(qenv(fn), v0144, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-2];
    v0085 = v0144;
    v0144 = stack[-1];
    v0144 = qcdr(v0144);
    stack[-1] = v0144;
    goto v0072;

v0099:
    v0144 = stack[0];
    v0144 = qcar(v0144);
    fn = elt(env, 4); // searchtm
    v0085 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-2];
    v0144 = stack[-1];
    v0144 = cons(v0085, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-2];
    stack[-1] = v0144;
    v0144 = stack[0];
    v0144 = qcdr(v0144);
    stack[0] = v0144;
    goto v0005;

v0130:
    v0144 = qvalue(elt(env, 1)); // t
    goto v0090;
// error exit handlers
v0145:
    popv(3);
    return nil;
}



// Code for rl_gettype

static LispObject CC_rl_gettype(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0077, v0051, v0057;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_gettype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0051 = v0000;
// end of prologue
    v0077 = v0051;
    if (!symbolp(v0077)) v0077 = nil;
    else { v0077 = qfastgets(v0077);
           if (v0077 != nil) { v0077 = elt(v0077, 4); // avalue
#ifdef RECORD_GET
             if (v0077 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0077 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0077 == SPID_NOPROP) v0077 = nil; }}
#endif
    v0057 = v0077;
    v0077 = v0057;
    if (v0077 == nil) goto v0125;
    v0077 = v0057;
    v0077 = qcar(v0077);
    return onevalue(v0077);

v0125:
    v0077 = v0051;
    if (!symbolp(v0077)) v0077 = nil;
    else { v0077 = qfastgets(v0077);
           if (v0077 != nil) { v0077 = elt(v0077, 2); // rtype
#ifdef RECORD_GET
             if (v0077 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0077 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0077 == SPID_NOPROP) v0077 = nil; }}
#endif
    return onevalue(v0077);
}



// Code for omair

static LispObject CC_omair(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0131, v0092;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omair");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// end of prologue
    stack[0] = nil;
    fn = elt(env, 4); // lex
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    fn = elt(env, 5); // omobj
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    stack[-1] = v0131;
    v0131 = stack[-1];
    v0092 = qcar(v0131);
    v0131 = elt(env, 1); // matrix
    if (v0092 == v0131) goto v0099;
    fn = elt(env, 4); // lex
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    fn = elt(env, 6); // omobjs
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    stack[0] = v0131;
    v0131 = elt(env, 2); // (!/ o m a)
    fn = elt(env, 7); // checktag
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    goto v0099;

v0099:
    v0092 = stack[-1];
    v0131 = stack[0];
        popv(3);
        return Lappend(nil, v0092, v0131);
// error exit handlers
v0050:
    popv(3);
    return nil;
}



// Code for off_mod_reval

static LispObject CC_off_mod_reval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0128;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for off_mod_reval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0128 = qvalue(elt(env, 1)); // !*modular
    if (v0128 == nil) goto v0057;
    v0128 = elt(env, 2); // modular
    v0128 = ncons(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    fn = elt(env, 4); // off
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    v0128 = stack[0];
    fn = elt(env, 5); // reval
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    stack[0] = v0128;
    v0128 = elt(env, 2); // modular
    v0128 = ncons(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    fn = elt(env, 6); // on
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0057:
    v0128 = stack[0];
    fn = elt(env, 5); // reval
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    stack[0] = v0128;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0099:
    popv(2);
    return nil;
}



// Code for mkuwedge

static LispObject CC_mkuwedge(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0129, v0128;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkuwedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0129 = v0000;
// end of prologue
    v0128 = v0129;
    v0128 = qcdr(v0128);
    if (v0128 == nil) goto v0057;
    v0128 = elt(env, 1); // wedge
    v0129 = cons(v0128, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[0];
    fn = elt(env, 2); // fkern
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0129 = qcar(v0129);
    { popv(1); return onevalue(v0129); }

v0057:
    v0129 = qcar(v0129);
    { popv(1); return onevalue(v0129); }
// error exit handlers
v0091:
    popv(1);
    return nil;
}



// Code for carx

static LispObject CC_carx(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0132, v0131, v0092;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for carx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0131 = v0001;
    v0092 = v0000;
// end of prologue
    v0132 = v0092;
    v0132 = qcdr(v0132);
    if (v0132 == nil) goto v0015;
    stack[-1] = elt(env, 1); // alg
    stack[0] = (LispObject)81; // 5
    v0132 = elt(env, 2); // "Wrong number of arguments to"
    v0132 = list2(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    {
        LispObject v0070 = stack[-1];
        LispObject v0107 = stack[0];
        popv(3);
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0070, v0107, v0132);
    }

v0015:
    v0132 = v0092;
    v0132 = qcar(v0132);
    { popv(3); return onevalue(v0132); }
// error exit handlers
v0050:
    popv(3);
    return nil;
}



// Code for has_parents

static LispObject CC_has_parents(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058, v0132, v0131;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for has_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0058 = v0000;
// end of prologue
    v0058 = qcdr(v0058);
    v0058 = qcar(v0058);
    v0131 = v0058;
    v0058 = v0131;
    v0132 = qcar(v0058);
    v0058 = elt(env, 1); // !?
    if (v0132 == v0058) goto v0071;
    v0058 = v0131;
    v0058 = qcdr(v0058);
    v0132 = elt(env, 1); // !?
        return Lneq(nil, v0058, v0132);

v0071:
    v0058 = qvalue(elt(env, 2)); // nil
    return onevalue(v0058);
}



// Code for take!-impart

static LispObject CC_takeKimpart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0071, v0066;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for take-impart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0071 = stack[0];
    v0071 = qcar(v0071);
    fn = elt(env, 1); // impartf
    v0066 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    v0071 = (LispObject)17; // 1
    stack[-1] = cons(v0066, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    v0066 = (LispObject)17; // 1
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    v0071 = cons(v0066, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    {
        LispObject v0131 = stack[-1];
        popv(3);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0131, v0071);
    }
// error exit handlers
v0132:
    popv(3);
    return nil;
}



// Code for lprim

static LispObject CC_lprim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057, v0056;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lprim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0057 = v0000;
// end of prologue
    v0056 = qvalue(elt(env, 1)); // !*msg
    if (v0056 == nil) goto v0004;
    v0056 = elt(env, 3); // "***"
    {
        fn = elt(env, 4); // lpriw
        return (*qfn2(fn))(qenv(fn), v0056, v0057);
    }

v0004:
    v0057 = qvalue(elt(env, 2)); // nil
    return onevalue(v0057);
}



setup_type const u08_setup[] =
{
    {"c:extmult",               too_few_2,      CC_cTextmult,  wrong_no_2},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"lispapply",               too_few_2,      CC_lispapply,  wrong_no_2},
    {"mo=deglist",              CC_moMdeglist,  too_many_1,    wrong_no_1},
    {"pneg",                    CC_pneg,        too_many_1,    wrong_no_1},
    {"gionep:",                 CC_gionepT,     too_many_1,    wrong_no_1},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"preptayexp",              CC_preptayexp,  too_many_1,    wrong_no_1},
    {"cl_simplat",              too_few_2,      CC_cl_simplat, wrong_no_2},
    {"ibalp_litlp",             CC_ibalp_litlp, too_many_1,    wrong_no_1},
    {"initbrsea",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_initbrsea},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"opnum*",                  CC_opnumH,      too_many_1,    wrong_no_1},
    {"prin2t",                  CC_prin2t,      too_many_1,    wrong_no_1},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"conv:bf2i",               CC_convTbf2i,   too_many_1,    wrong_no_1},
    {"qqe_ofsf_prepat",         CC_qqe_ofsf_prepat,too_many_1, wrong_no_1},
    {"comfac-to-poly",          CC_comfacKtoKpoly,too_many_1,  wrong_no_1},
    {"ibalp_vequal",            too_few_2,      CC_ibalp_vequal,wrong_no_2},
    {"quotk",                   too_few_2,      CC_quotk,      wrong_no_2},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"token1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_token1},
    {"kernp",                   CC_kernp,       too_many_1,    wrong_no_1},
    {"crprcd",                  CC_crprcd,      too_many_1,    wrong_no_1},
    {"matrix+p",                CC_matrixLp,    too_many_1,    wrong_no_1},
    {"ibalp_simpat",            CC_ibalp_simpat,too_many_1,    wrong_no_1},
    {"objectom",                CC_objectom,    too_many_1,    wrong_no_1},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"dim<deg",                 CC_dimRdeg,     too_many_1,    wrong_no_1},
    {"id2bytelist",             CC_id2bytelist, too_many_1,    wrong_no_1},
    {"assert_analyze",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_analyze},
    {"lambda_wrlijy187crc",     too_few_2,      CC_lambda_wrlijy187crc,wrong_no_2},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"*i2gi",                   CC_Hi2gi,       too_many_1,    wrong_no_1},
    {"freevarinexptchk",        CC_freevarinexptchk,too_many_1,wrong_no_1},
    {"searchtm",                CC_searchtm,    too_many_1,    wrong_no_1},
    {"bcone?",                  CC_bconeW,      too_many_1,    wrong_no_1},
    {"ncmpchk",                 too_few_2,      CC_ncmpchk,    wrong_no_2},
    {"contrsp",                 too_few_2,      CC_contrsp,    wrong_no_2},
    {"take-realpart",           CC_takeKrealpart,too_many_1,   wrong_no_1},
    {"cali_bc_fi",              CC_cali_bc_fi,  too_many_1,    wrong_no_1},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"th_match0",               too_few_2,      CC_th_match0,  wrong_no_2},
    {"searchpl",                CC_searchpl,    too_many_1,    wrong_no_1},
    {"rl_gettype",              CC_rl_gettype,  too_many_1,    wrong_no_1},
    {"omair",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omair},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"take-impart",             CC_takeKimpart, too_many_1,    wrong_no_1},
    {"lprim",                   CC_lprim,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u08", (two_args *)"482 6316607 1236138", 0}
};

// end of generated code
