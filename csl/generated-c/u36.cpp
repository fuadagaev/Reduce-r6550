
// $destdir/u36.c        Machine generated C code

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <setjmp.h>
#include <exception>
#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
extern "C"
{
#include "softfloat.h"
}
#if !defined EMBEDDED
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
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
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
#define CSL_IGNORE(x) ((void)(x))
#ifndef PAGE_BITS
# define PAGE_BITS 22
#endif 
#define PAGE_POWER_OF_TWO (((intptr_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO - 256)
#ifndef MAX_HEAPSIZE
# define MAX_HEAPSIZE (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#define MEGABYTE ((intptr_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#endif
#define LONGEST_LEGAL_FILENAME 1024
typedef intptr_t LispObject;
#define CELL ((size_t)sizeof(LispObject))
#define TAG_BITS 7
#define XTAG_BITS 15
#define TAG_CONS 0 
#define TAG_VECTOR 1 
#define TAG_HDR_IMMED 2 
#define TAG_FORWARD 3 
#define TAG_SYMBOL 4 
#define TAG_NUMBERS 5 
#define TAG_BOXFLOAT 6 
#define TAG_FIXNUM 7 
#define TAG_XBIT 8 
#define XTAG_SFLOAT 15 
#define XTAG_FLOAT32 16
#define is_forward(p) ((((int)(p)) & TAG_BITS) == TAG_FORWARD)
#define is_number(p) ((((int)(p)) & TAG_BITS) >= TAG_NUMBERS)
#define is_float(p) (((0xc040 >> (((int)(p)) & XTAG_BITS)) & 1) != 0)
#define is_immed_or_cons(p) (((0x85 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define is_immed_cons_sym(p) (((0x95 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define need_more_than_eq(p) (((0x63 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define fixnum_of_int(x) ((LispObject)((((uintptr_t)(x))<<4)+TAG_FIXNUM))
#define int_of_fixnum(x) (((intptr_t)(x) & ~(intptr_t)15)/16)
#define valid_as_fixnum(x) (int_of_fixnum(fixnum_of_int(x)) == (x))
#define MOST_POSITIVE_FIXVAL (((intptr_t)1 << (8*sizeof(LispObject)-5)) - 1)
#define MOST_NEGATIVE_FIXVAL (-((intptr_t)1 << (8*sizeof(LispObject)-5)))
#define MOST_POSITIVE_FIXNUM fixnum_of_int(MOST_POSITIVE_FIXVAL)
#define MOST_NEGATIVE_FIXNUM fixnum_of_int(MOST_NEGATIVE_FIXVAL)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED) 
#define is_sfloat(p) ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#define car_legal(p) is_cons(p)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject no_args(LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef LispObject four_args(LispObject, size_t, LispObject, LispObject,
 LispObject, LispObject);
typedef uintptr_t Header;
#define Tw (3)
#define header_mask (0x7f<<Tw)
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) ((((size_t)(h)) >> (Tw+7)) << 2)
#define length_of_bitheader(h) ((((size_t)(h)) >> (Tw+2)) - 31)
#define length_of_byteheader(h) ((((size_t)(h)) >> (Tw+5)) - 3)
#define length_of_hwordheader(h) ((((size_t)(h)) >> (Tw+6)) - 1)
#define bitvechdr_(n) (TYPE_BITVEC_1 + ((((n)+31)&31)<<(Tw+2)))
#define TYPE_SYMBOL 0x00000000 
#define SYM_SPECIAL_VAR 0x00000080 
#define SYM_FLUID_VAR 0x00000080 
#define SYM_GLOBAL_VAR 0x00000100 
#define SYM_KEYWORD_VAR 0x00000180 
#define SYM_SPECIAL_FORM 0x00000200 
#define SYM_MACRO 0x00000400 
#define SYM_C_DEF 0x00000800 
#define SYM_CODEPTR 0x00001000 
#define SYM_ANY_GENSYM 0x00002000 
#define SYM_TRACED 0x00004000 
#define SYM_TRACESET 0x00008000 
#define SYM_TAGGED 0x00010000 
#define SYM_FASTGET_MASK 0x007e0000 
#define SYM_FASTGET_SHIFT 17
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00800000 
#define SYM_IN_PACKAGE 0xff000000U 
#define SYM_IN_PKG_SHIFT 24
#define SYM_IN_PKG_COUNT 8
#else 
#define SYM_UNPRINTED_GENSYM 0x00800000 
#endif 
#define symhdr_length (doubleword_align_up(sizeof(Symbol_Head)))
#define is_symbol_header(h) (((int)h & (0xf<<Tw)) == TYPE_SYMBOL)
#define is_symbol_header_full_test(h) \
 (((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED))
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define is_number_header_full_test(h) \
 (((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED))
#define is_vector_header_full_test(h) \
 (is_odds(h) && (((int)h & (0x3<<Tw)) != 0))
#define is_array_header(h) (type_of_header(h) == TYPE_ARRAY)
#define vector_i8(h) (((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i16(h) (((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i32(h) (((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i64(h) (((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i128(h) (((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f32(h) (((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f64(h) (((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f128(h) (((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x1d <<Tw)
#define TYPE_COMPLEX_NUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define is_string_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1)
#define is_string(n) is_string_header(vechdr(n))
#define is_vec8_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1)
#define is_vec8(n) is_vec8_header(vechdr(n))
#define is_bps_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1)
#define is_bps(n) is_bps_header(vechdr(n))
#define is_vec16_header(h) ((type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1)
#define is_vec16(n) is_vec16_header(vechdr(n))
#define is_bitvec_header(h) ((type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1)
#define is_bitvec(n) is_bitvec_header(vechdr(n))
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))*sizeof(LispObject))))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define data_of_bps(v) ((unsigned char *)(v) + (CELL-TAG_VECTOR))
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
#define vselt(v, n) (*(LispObject *)(((intptr_t)(v) & ~((intptr_t)TAG_BITS)) + \
 ((1 + (intptr_t)(n))*sizeof(LispObject))))
#define helt(v, n) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)))
#define sethelt(v, n, x) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)) = (x))
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(intptr_t))))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(int32_t))))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(float))))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(double))))
#define TYPE_BITVEC_1 ( 0x02 <<Tw) 
#define TYPE_BITVEC_2 ( 0x06 <<Tw) 
#define TYPE_BITVEC_3 ( 0x0a <<Tw) 
#define TYPE_BITVEC_4 ( 0x0c <<Tw) 
#define TYPE_BITVEC_5 ( 0x12 <<Tw) 
#define TYPE_BITVEC_6 ( 0x16 <<Tw) 
#define TYPE_BITVEC_7 ( 0x1a <<Tw) 
#define TYPE_BITVEC_8 ( 0x1c <<Tw) 
#define TYPE_BITVEC_9 ( 0x22 <<Tw) 
#define TYPE_BITVEC_10 ( 0x26 <<Tw) 
#define TYPE_BITVEC_11 ( 0x2a <<Tw) 
#define TYPE_BITVEC_12 ( 0x2c <<Tw) 
#define TYPE_BITVEC_13 ( 0x32 <<Tw) 
#define TYPE_BITVEC_14 ( 0x36 <<Tw) 
#define TYPE_BITVEC_15 ( 0x3a <<Tw) 
#define TYPE_BITVEC_16 ( 0x3c <<Tw) 
#define TYPE_BITVEC_17 ( 0x42 <<Tw) 
#define TYPE_BITVEC_18 ( 0x46 <<Tw) 
#define TYPE_BITVEC_19 ( 0x4a <<Tw) 
#define TYPE_BITVEC_20 ( 0x4c <<Tw) 
#define TYPE_BITVEC_21 ( 0x52 <<Tw) 
#define TYPE_BITVEC_22 ( 0x56 <<Tw) 
#define TYPE_BITVEC_23 ( 0x5a <<Tw) 
#define TYPE_BITVEC_24 ( 0x5c <<Tw) 
#define TYPE_BITVEC_25 ( 0x62 <<Tw) 
#define TYPE_BITVEC_26 ( 0x66 <<Tw) 
#define TYPE_BITVEC_27 ( 0x6a <<Tw) 
#define TYPE_BITVEC_28 ( 0x6c <<Tw) 
#define TYPE_BITVEC_29 ( 0x72 <<Tw) 
#define TYPE_BITVEC_30 ( 0x76 <<Tw) 
#define TYPE_BITVEC_31 ( 0x7a <<Tw) 
#define TYPE_BITVEC_32 ( 0x7c <<Tw) 
#define TYPE_STRING_1 ( 0x07 <<Tw) 
#define TYPE_STRING_2 ( 0x27 <<Tw) 
#define TYPE_STRING_3 ( 0x47 <<Tw) 
#define TYPE_STRING_4 ( 0x67 <<Tw) 
#define TYPE_VEC8_1 ( 0x03 <<Tw) 
#define TYPE_VEC8_2 ( 0x23 <<Tw) 
#define TYPE_VEC8_3 ( 0x43 <<Tw) 
#define TYPE_VEC8_4 ( 0x63 <<Tw) 
#define TYPE_BPS_1 ( 0x0b <<Tw) 
#define TYPE_BPS_2 ( 0x2b <<Tw) 
#define TYPE_BPS_3 ( 0x4b <<Tw) 
#define TYPE_BPS_4 ( 0x6b <<Tw) 
#define TYPE_VEC16_1 ( 0x0f <<Tw) 
#define TYPE_VEC16_2 ( 0x4f <<Tw) 
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
#define TYPE_FOREIGN ( 0x33 <<Tw) 
#define TYPE_SP ( 0x37 <<Tw) 
#define TYPE_ENCAPSULATE ( 0x3b <<Tw) 
#define vector_holds_binary(h) (((h) & (0x2<<Tw)) != 0)
#define TYPE_SIMPLE_VEC ( 0x01 <<Tw) 
#define TYPE_INDEXVEC ( 0x11 <<Tw) 
#define TYPE_NEWHASH ( 0x15 <<Tw) 
#define TYPE_NEWHASHX ( 0x19 <<Tw) 
#define TYPE_HASH ( 0x21 <<Tw) 
#define TYPE_ARRAY ( 0x05 <<Tw) 
#define TYPE_STRUCTURE ( 0x09 <<Tw) 
#define TYPE_OBJECT ( 0x0d <<Tw) 
#define TYPE_VEC32 ( 0x13 <<Tw) 
#define TYPE_VEC64 ( 0x17 <<Tw) 
#define TYPE_VEC128 ( 0x1b <<Tw) 
#define TYPE_VECFLOAT32 ( 0x53 <<Tw) 
#define TYPE_VECFLOAT64 ( 0x57 <<Tw) 
#define TYPE_VECFLOAT128 ( 0x5b <<Tw) 
#define is_mixed_header(h) (((h) & (0x73<<Tw)) == TYPE_MIXED1)
#define TYPE_MIXED1 ( 0x41 <<Tw) 
#define TYPE_MIXED2 ( 0x45 <<Tw) 
#define TYPE_MIXED3 ( 0x49 <<Tw) 
#define TYPE_STREAM ( 0x4d <<Tw) 
#define VIRTUAL_TYPE_CONS ( 0x7d <<Tw) 
#define HDR_IMMED_MASK (( 0xf <<Tw) | TAG_BITS)
#define TAG_CHAR (( 0x4 <<Tw) | TAG_HDR_IMMED) 
#define TAG_SPID (( 0xc <<Tw) | TAG_HDR_IMMED) 
#define SPID_NIL (TAG_SPID+(0x00<<(Tw+4))) 
#define SPID_FBIND (TAG_SPID+(0x01<<(Tw+4))) 
#define SPID_CATCH (TAG_SPID+(0x02<<(Tw+4))) 
#define SPID_PROTECT (TAG_SPID+(0x03<<(Tw+4))) 
#define SPID_HASHEMPTY (TAG_SPID+(0x04<<(Tw+4))) 
#define SPID_HASHTOMB (TAG_SPID+(0x05<<(Tw+4))) 
#define SPID_GCMARK (TAG_SPID+(0x06<<(Tw+4))) 
#define SPID_NOINPUT (TAG_SPID+(0x07<<(Tw+4))) 
#define SPID_ERROR (TAG_SPID+(0x08<<(Tw+4))) 
#define SPID_PVBIND (TAG_SPID+(0x09<<(Tw+4))) 
#define SPID_NOARG (TAG_SPID+(0x0a<<(Tw+4))) 
#define SPID_NOPROP (TAG_SPID+(0x0b<<(Tw+4))) 
#define SPID_LIBRARY (TAG_SPID+(0x0c<<(Tw+4))) 
#define is_header(x) (((int)(x) & (0x3<<Tw)) != 0) 
#define is_char(x) (((int)(x) & HDR_IMMED_MASK) == TAG_CHAR)
#define is_spid(x) (((int)(x) & HDR_IMMED_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xfffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> (21+4+Tw)) & 0xf)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> (4+Tw)) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << (21+4+Tw)) | \
 (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR))
#define CHAR_EOF pack_char(0, 0x0010ffff)
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head
{
 Header header; 
 LispObject value; 
 LispObject env; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject package; 
 LispObject pname; 
 intptr_t function0; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t function3; 
 union {
 intptr_t functionn; 
 intptr_t function4; 
 intptr_t function5up;
 };
 uint64_t count; 
} Symbol_Head;
#define MAX_FASTGET_SIZE 63
#define qheader(p) (*(Header *)((char *)(p) + (0*CELL-TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)((char *)(p) + (1*CELL-TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)((char *)(p) + (2*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define qpackage(p) (*(LispObject *)((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define ifn0(p) (*(intptr_t *)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define ifn1(p) (*(intptr_t *)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define ifn3(p) (*(intptr_t *)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define ifn4(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn0(p) (*(no_args **)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfn1(p) (*(one_args **)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qfn2(p) (*(two_args **)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define qfn3(p) (*(three_args **)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define qfnn(p) (*(n_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn4(p) (*(four_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uint64_t *)((char *)(p) + (12*CELL-TAG_SYMBOL)))
typedef union Float_union
{ float f;
 uint32_t i;
 float32_t f32;
} Float_union;
#define low32(a) ((LispObject)(uint32_t)(a))
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#define bignum_digits(b) \
 ((uint32_t *)((char *)(b) + (CELL-TAG_NUMBERS)))
#define bignum_digits64(b, n) \
 ((int64_t)((int32_t *)((char *)(b)+(CELL-TAG_NUMBERS)))[n])
#define make_bighdr(n) (TAG_HDR_IMMED+TYPE_BIGNUM+(((intptr_t)(n))<<(Tw+7)))
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
#define make_padder(n) (pack_hdrlength((n)/4) + TYPE_VEC8_1 + TAG_HDR_IMMED)
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
 float32_t f32;
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define float32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f32)
#define intfloat32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.i)
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float64_t_val(v) (*(float64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat64_t_val(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 24
#define long_float_addr(v) ((float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define long_float_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float128_t_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val0(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val1(v) (*(int64_t *)((char *)(v) + \
 (16-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((uintptr_t)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-16)))
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_SIGNAL 0x6 
#define UNWIND_SIGINT 0x7 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#define MAXSHIFT(n, a) ((n) >= (int)(8*sizeof(a)) || (n) < 0 ? 0 : (n))
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
#define ASR(a, n) ((a) >> MAXSHIFT((n), a))
#else 
#include <type_traits>
template <typename T>
static inline T ASR(T a, int n)
{ typedef typename std::make_signed<T>::type ST;
 return ((ST)(a&~(((T)1<<MAXSHIFT(n,T))-1)))/((ST)1<<MAXSHIFT(n,T));
}
#endif 
#define ASL32(a,n) ((int32_t)((uint32_t)(a)<<MAXSHIFT((n),uint32_t)))
#define ASLptr(a,n) ((intptr_t)((uintptr_t)(a)<<MAXSHIFT((n),uintptr_t)))
#define ASL64(a,n) ((int64_t)((uint64_t)(a)<<MAXSHIFT((n),uint64_t)))
#define ASL128(a,n) ((int128_t)((uint128_t)(a)<<MAXSHIFT((n),uint128_t)))
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern "C" LispObject interrupted(LispObject p);
extern "C" NORETURN void error(int nargs, int code, ...);
extern "C" NORETURN void cerror(int nargs, int code1, int code2, ...);
extern "C" NORETURN void too_few_2(LispObject env, LispObject a1);
extern "C" NORETURN void too_many_1(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_0a(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_0b(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_3a(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_3b(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_na(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_nb(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_1(LispObject env, int nargs, ...);
extern "C" NORETURN void wrong_no_2(LispObject env, int nargs, ...);
extern "C" NORETURN void bad_specialn(LispObject env, int nargs, ...);
#define TOO_FEW_2 ((one_args *)too_few_2)
#define TOO_MANY_1 ((two_args *)too_many_1)
#define WRONG_NO_0A ((one_args *)wrong_no_0a)
#define WRONG_NO_0B ((two_args *)wrong_no_0b)
#define WRONG_NO_3A ((one_args *)wrong_no_3a)
#define WRONG_NO_3B ((two_args *)wrong_no_3b)
#define WRONG_NO_NA ((one_args *)wrong_no_na)
#define WRONG_NO_NB ((two_args *)wrong_no_nb)
#define WRONG_NO_1 ((n_args *)wrong_no_1)
#define WRONG_NO_2 ((n_args *)wrong_no_2)
#define BAD_SPECIALN ((n_args *)bad_specialn)
extern "C" NORETURN void aerror(const char *s); 
extern "C" NORETURN void aerror0(const char *s);
extern "C" NORETURN void aerror1(const char *s, LispObject a);
extern "C" NORETURN void aerror2(const char *s, LispObject a, LispObject b);
extern "C" NORETURN void fatal_error(int code, ...);
extern "C" LispObject carerror(LispObject a);
extern "C" LispObject cdrerror(LispObject a);
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
#define err_undefined_function_0 3 
#define err_undefined_function_1 4 
#define err_undefined_function_2 5 
#define err_undefined_function_3 6 
#define err_undefined_function_4 7 
#define err_undefined_function_n 7 
#define err_wrong_no_args 8 
#define err_unbound_lexical 9 
#define err_bad_rplac 10 
#define err_bad_arith 11 
#define err_redef_special 12 
#define err_bad_arg 13 
#define err_bad_declare 14 
#define err_bad_fn 15 
#define err_unset_var 16 
#define err_too_many_args0 17 
#define err_too_many_args1 18 
#define err_too_many_args2 19 
#define err_too_many_args3 20 
#define err_bad_apply 21 
#define err_macroex_hook 22 
#define err_block_tag 23 
#define err_go_tag 24 
#define err_excess_args 25
#define err_insufficient_args 26
#define err_bad_bvl 27 
#define err_bad_keyargs 28
#define err_write_err 29
#define err_bad_endp 30 
#define err_no_fasldir 31
#define err_no_fasl 32 
#define err_open_failed 33 
#define err_pipe_failed 34 
#define err_stack_overflow 35
#define err_top_bit 36
#define err_mem_spans_zero 37
#define err_no_longer_used 38 
#define err_no_tempdir 39
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
 "attempt to take cdr of an atom",
 "insufficient freestore to run this package",
 "undefined function (0 arg)",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function (3 arg)",
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
 "too many arguments for 0-arg function",
 "too many arguments for 1-arg function",
 "too many arguments for 2-arg function",
 "too many arguments for 3-arg function",
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
extern void **pages, **heap_pages, **vheap_pages;
extern void **new_heap_pages, **new_vheap_pages;
extern void *allocate_page(const char *why);
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS 0
#define PAGE_TYPE_VECTOR 1
typedef struct page_map_t
{ void *start;
 void *end;
 int type;
} page_map_t;
#endif
extern int32_t pages_count, heap_pages_count, vheap_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count;
extern LispObject *list_bases[];
extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern LispObject *stack;
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern bool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif
extern LispObject multiplication_buffer;
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
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
#define GC_PRESERVE 6
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
 if (check_stack("@" __FILE__,__LINE__)) \
 { show_stack(); aerror("stack overflow"); }
#else
#define if_check_stack \
 { const char *_p_ = (char *)&_p_; \
 if (_p_ < C_stack_limit) aerror("stack overflow"); \
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
#define stackcheck0(k) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { reclaim(nil, "stack", GC_STACK, 0); \
 }
#define stackcheck1(k, a1) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { a1 = reclaim(a1, "stack", GC_STACK, 0); \
 }
#define stackcheck2(k, a1, a2) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push(a2); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2); \
 }
#define stackcheck3(k, a1, a2, a3) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push2(a2, a3); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop2(a3, a2); \
 }
#define stackcheck4(k, a1, a2, a3, a4) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push3(a2, a3, a4); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop3(a4, a3, a2); \
 }
extern LispObject nil;
#define first_nil_offset 50 
#define work_0_offset 250
#define last_nil_offset 301
#define NIL_SEGMENT_SIZE (last_nil_offset*sizeof(LispObject) + 32)
#define SPARE 512
extern intptr_t byteflip;
extern LispObject * volatile stacklimit;
extern LispObject fringe;
extern LispObject volatile heaplimit;
extern LispObject volatile vheaplimit;
extern LispObject vfringe;
extern intptr_t nwork;
extern unsigned int exit_count;
extern uint64_t gensym_ser;
extern intptr_t print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol, apply_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table, progn_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject big_divisor, big_dividend, big_quotient;
extern LispObject big_fake1, big_fake2, active_stream, current_module;
extern LispObject mv_call_symbol, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject startup_symbol, mv_call_symbol, traceprint_symbol;
extern LispObject load_source_symbol, load_selected_source_symbol;
extern LispObject bytecoded_symbol, funcall_symbol, autoload_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, current_function, keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol, expand_def_symbol, allow_key_key;
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
extern LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol;
extern LispObject not_symbol, reader_workspace, named_character;
extern LispObject read_float_format, short_float, single_float, double_float;
extern LispObject long_float, bit_symbol, pathname_symbol, print_array_sym;
extern LispObject read_base, initial_element;
extern LispObject builtin0_symbol, builtin1_symbol, builtin2_symbol;
extern LispObject builtin3_symbol, builtin4_symbol; 
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern LispObject om_connectTCP(LispObject env, int nargs, ...);
extern LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject env, LispObject ldev);
extern LispObject om_putEndApp(LispObject env, LispObject ldev);
extern LispObject om_putAtp(LispObject env, LispObject ldev);
extern LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern LispObject om_putAttr(LispObject env, LispObject ldev);
extern LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern LispObject om_putBind(LispObject env, LispObject ldev);
extern LispObject om_putEndBind(LispObject env, LispObject ldev);
extern LispObject om_putBVar(LispObject env, LispObject ldev);
extern LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern LispObject om_putError(LispObject env, LispObject ldev);
extern LispObject om_putEndError(LispObject env, LispObject ldev);
extern LispObject om_putObject(LispObject env, LispObject ldev);
extern LispObject om_putEndObject(LispObject env, LispObject ldev);
extern LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern LispObject om_getApp(LispObject env, LispObject ldev);
extern LispObject om_getEndApp(LispObject env, LispObject ldev);
extern LispObject om_getAtp(LispObject env, LispObject ldev);
extern LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern LispObject om_getAttr(LispObject env, LispObject ldev);
extern LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern LispObject om_getBind(LispObject env, LispObject ldev);
extern LispObject om_getEndBind(LispObject env, LispObject ldev);
extern LispObject om_getBVar(LispObject env, LispObject ldev);
extern LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern LispObject om_getError(LispObject env, LispObject ldev);
extern LispObject om_getEndError(LispObject env, LispObject ldev);
extern LispObject om_getObject(LispObject env, LispObject ldev);
extern LispObject om_getEndObject(LispObject env, LispObject ldev);
extern LispObject om_getInt(LispObject env, LispObject ldev);
extern LispObject om_getFloat(LispObject env, LispObject ldev);
extern LispObject om_getByteArray(LispObject env, LispObject ldev);
extern LispObject om_getVar(LispObject env, LispObject ldev);
extern LispObject om_getString(LispObject env, LispObject ldev);
extern LispObject om_getSymbol(LispObject env, LispObject ldev);
extern LispObject om_getType(LispObject env, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern LispObject om_read(LispObject env, LispObject dev);
extern LispObject om_supportsCD(LispObject env, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject env, int nargs, ...);
extern LispObject om_listSymbols(LispObject env, LispObject lcd);
extern LispObject om_whichCDs(LispObject env, LispObject lsym);
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
extern void copy_into_nilseg();
extern void copy_out_of_nilseg();
#define LOG2_VECTOR_CHUNK_WORDS 17
#define VECTOR_CHUNK_WORDS ((size_t)(1<<LOG2_VECTOR_CHUNK_WORDS)) 
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_WORDS+1];
extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char *s, LispObject x);
extern LispObject eq_hash_tables, equal_hash_tables;
extern uint32_t hash_equal(LispObject key);
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
extern bool garbage_collection_permitted;
#define MAX_INPUT_FILES 40 
#define MAX_SYMBOLS_TO_DEFINE 40
#define MAX_FASL_PATHS 20
extern const char *files_to_read[MAX_INPUT_FILES],
 *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
 *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern bool fasl_output_file;
extern size_t output_directory;
extern LispObject *repeat_heap;
extern size_t repeat_count;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern FILE *binary_write_file;
extern size_t boffop;
extern void packcharacter(int c);
extern void packbyte(int c);
#define boffo_char(i) ucelt(boffo, i)
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#ifdef SOCKETS
extern bool sockets_ready;
extern void flush_socket();
#endif
extern void report_file(const char *s);
extern bool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern size_t number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths;
extern int init_flags;
extern const char *standard_directory;
extern int gc_number;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
#define CODESIZE 0x1000
typedef struct _entry_point0
{ no_args *p;
 const char *s;
} entry_point0;
typedef struct _entry_point1
{ one_args *p;
 const char *s;
} entry_point1;
typedef struct _entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct _entry_point3
{ three_args *p;
 const char *s;
} entry_point3;
typedef struct _entry_point4
{ four_args *p;
 const char *s;
} entry_point4;
typedef struct _entry_pointn
{ n_args *p;
 const char *s;
} entry_pointn;
extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4 entries_table4[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_tableio[];
extern void set_up_entry_lookup();
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
extern LispObject Lencapsulatedp(LispObject env, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit();
extern void IreInit();
extern void Ilist();
extern bool open_output(const char *s, size_t len);
#define IMAGE_CODE ((size_t)(-1000))
#define HELP_CODE ((size_t)(-1001))
#define BANNER_CODE ((size_t)(-1002))
#define IOPEN_OUT 0
#define IOPEN_IN 1
extern bool Iopen(const char *name, size_t len, int dirn, char *expanded_name);
extern bool Iopen_from_stdin(), Iopen_to_stdout();
extern bool IopenRoot(char *expanded_name, size_t hard, int sixtyfour);
extern bool Iwriterootp(char *expanded);
extern bool Iopen_banner(int code);
extern bool Imodulep(const char *name, size_t len, char *datestamp,
 size_t *size, char *expanded_name);
extern char *trim_module_name(char *name, size_t *lenp);
extern bool Icopy(const char *name, size_t len);
extern bool Idelete(const char *name, size_t len);
extern bool IcloseInput();
extern bool IcloseOutput();
extern bool Ifinished();
extern int Igetc();
extern bool Iread(void *buff, size_t size);
extern bool Iputc(int ch);
extern bool Iwrite(const void *buff, size_t size);
extern bool def_init();
extern bool inf_init();
extern bool def_finish();
extern bool inf_finish();
extern int Zgetc();
extern bool Zread(void *buff, size_t size);
extern bool Zputc(int ch);
extern bool Zwrite(const void *buff, size_t size);
extern long int Ioutsize();
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char *data, size_t len);
extern void CSL_MD5_Final(unsigned char *md);
extern bool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen();
extern int window_heading;
extern void my_abort();
extern "C" NORETURN void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock();
extern double pop_clock();
extern double consolidated_time[10], gc_time;
extern bool volatile already_in_gc, tick_on_gc_exit;
extern bool volatile interrupt_pending, tick_pending;
extern int deal_with_tick();
extern bool trap_floating_overflow;
extern const volatile char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
extern "C" void low_level_signal_handler(int code);
extern "C" void sigint_handler(int code);
extern "C" int async_interrupt(int a);
extern "C" void record_get(LispObject tag, bool found);
extern int primep(int32_t);
extern void set_up_functions(int restartp);
extern void get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(size_t ppc, LispObject lit,
 LispObject *entry_stack);
extern bool complex_stringp(LispObject a);
extern LispObject copy_string(LispObject a, size_t n);
extern void freshline_trace();
extern void freshline_debug();
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern uint32_t Crand();
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern "C" bool eql_fn(LispObject a, LispObject b);
extern "C" bool cl_equal_fn(LispObject a, LispObject b);
extern "C" bool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" bool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs, LispObject env,
 LispObject from);
extern LispObject apply_lambda(LispObject def, int nargs,
 LispObject env, LispObject name);
extern void deallocate_pages();
extern void drop_heap_segments();
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
extern "C" LispObject get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern uint32_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" bool geq2(LispObject a, LispObject b);
extern "C" bool greaterp2(LispObject a, LispObject b);
extern "C" bool lesseq2(LispObject a, LispObject b);
extern "C" bool lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
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
extern void preserve(const char *msg, size_t len);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t &len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prinhex_to_trace(const char *msg, LispObject value);
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
extern void print_bignum(LispObject u, bool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, bool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject quotrem2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
extern void set_fns(LispObject sym, one_args *f1,
 two_args *f2, n_args *fn);
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
extern int64_t sixty_four_bits(LispObject a);
extern uint64_t crc64(uint64_t crc, const void *buf, size_t size);
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
static inline LispObject onevalue(LispObject r)
{ exit_count = 1;
 return r;
}
static inline LispObject nvalues(LispObject r, int n)
{ exit_count = n;
 return r;
}
#define equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 equal_fn(a, b)))
#define cl_equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 cl_equal_fn(a, b)))
#define eql(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 eql_fn(a, b)))
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#define argcheck(var, n, msg) if ((var)!=(n)) aerror(msg);
extern n_args *no_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern four_args *four_arg_functions[];
extern n_args *three_arg_functions[];
extern bool no_arg_traceflags[];
extern bool one_arg_traceflags[];
extern bool two_arg_traceflags[];
extern bool four_arg_traceflags[];
extern bool three_arg_traceflags[];
extern const char *no_arg_names[];
extern const char *one_arg_names[];
extern const char *two_arg_names[];
extern const char *four_arg_names[];
extern const char *three_arg_names[];
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
 lisphash_setup[], newhash_setup[], print_setup[], read_setup[],
 restart_setup[], mpi_setup[];
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
 LispObject env, int compilerp);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
NORETURN extern void resource_exceeded();
extern int64_t time_base, space_base, io_base, errors_base;
extern int64_t time_now, space_now, io_now, errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern bool symbol_protect_flag, warn_about_protected_symbols;
#ifdef HASH_STATISTICS
extern uint64_t Nhget, Nhgetp, Nhput1, Nhputp1, Nhput2, Nhputp2, Nhputtmp;
extern uint64_t Noget, Nogetp, Noput, Noputp, Noputtmp;
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#if defined HAVE___INT128 && !defined __HAVE_INT128_T
typedef __int128 int128_t;
#define HAVE_INT128_T
#endif
#if defined HAVE_UNSIGNED___INT128 && !defined __HAVE_UINT128_T
typedef unsigned __int128 uint128_t;
#define HAVE_UINT128_T
#endif
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
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
#define top_bit(n) ((int32_t)(((uint32_t)(n)) >> 31))
#define set_top_bit(n) ((int32_t)((uint32_t)(n) | (uint32_t)0x80000000U))
#define clear_top_bit(n) ((int32_t)(n) & 0x7fffffff)
#define signed_overflow(n) \
 top_bit_set((uint32_t)(n) ^ ((uint32_t)(n) << 1))
#define ADD32(a, b) ((uint32_t)(a) + (uint32_t)(b))
#define signed29_in_64(n) \
 (((int64_t)(((uint64_t)(n) & 0x1fffffffU) << 35) / ((int64_t)1 << 35)) == \
 (int64_t)(n))
#define signed31_in_64(n) \
 (((int64_t)(((uint64_t)(n) & 0x7fffffffU) << 33) / ((int64_t)1 << 33)) == \
 (int64_t)(n))
#define signed31_in_ptr(n) \
 (((intptr_t)(((uintptr_t)(n)&0x7fffffffU) << (8*sizeof(intptr_t) - 31)) / \
 ((intptr_t)1 << (8*sizeof(intptr_t) - 31))) == (intptr_t)(n))
#define floating_edge_case(r) (1.0/(r) == 0.0 || (r) != (r))
#define floating_clear_flags() ((void)0)
#define floating_edge_case128(r) \
 (f128M_infinite(r) || f128M_nan(r))
#define Dmultiply(hi, lo, a, b, c) \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) + \
 (uint32_t)(c); \
 (lo) = 0x7fffffffu & (uint32_t)r64; \
 (hi) = (uint32_t)(r64 >> 31); } while (0)
#define Ddivide(r, q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#define Ddivideq(q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); } while (0)
#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)
#define Ddivider(r, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern "C" LispObject negateb(LispObject);
extern "C" LispObject copyb(LispObject);
extern "C" LispObject negate(LispObject);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern "C" LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject CLquot2(LispObject a, LispObject b);
extern "C" LispObject quotbn(LispObject a, int32_t n);
extern "C" LispObject quotbn1(LispObject a, int32_t n);
#define QUOTBB_QUOTIENT_NEEDED 1
#define QUOTBB_REMAINDER_NEEDED 2
extern "C" LispObject quotbb(LispObject a, LispObject b, int needs);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern "C" LispObject rembi(LispObject a, LispObject b);
extern "C" LispObject rembb(LispObject a, LispObject b);
extern "C" LispObject shrink_bignum(LispObject a, size_t lena);
extern "C" LispObject modulus(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern "C" LispObject rationalize(LispObject a);
extern "C" LispObject lcm(LispObject a, LispObject b);
extern "C" LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern "C" bool numeq2(LispObject a, LispObject b);
extern "C" bool zerop(LispObject a);
extern "C" bool onep(LispObject a);
extern "C" bool minusp(LispObject a);
extern "C" bool plusp(LispObject a);
extern "C" bool lesspbd(LispObject a, double b);
extern "C" bool lessprd(LispObject a, double b);
extern "C" bool lesspdb(double a, LispObject b);
extern "C" bool lesspdr(double a, LispObject b);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
 uint32_t a3, size_t n);
extern LispObject make_lisp_integer32_fn(int32_t n);
static inline LispObject make_lisp_integer32(int32_t n)
{ if (SIXTY_FOUR_BIT || valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer32_fn(n);
}
extern LispObject make_lisp_integer64_fn(int64_t n);
static inline LispObject make_lisp_integer64(int64_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer64_fn(n);
}
extern LispObject make_lisp_unsigned64_fn(uint64_t n);
static inline LispObject make_lisp_unsigned64(uint64_t n)
{ if (n < ((uint64_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsigned64_fn(n);
}
extern LispObject make_lisp_integerptr_fn(intptr_t n);
static inline LispObject make_lisp_integerptr(intptr_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
#ifdef HAVE_INT128_T
extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer128_fn(n);
}
#endif
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
extern LispObject make_boxfloat128(float128_t a);
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
extern bool lesspbi(LispObject a, LispObject b);
extern bool lesspib(LispObject a, LispObject b);
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
extern size_t karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
extern "C" int f128M_exponent(const float128_t *p);
extern "C" void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
extern "C" bool f128M_infinite(const float128_t *p);
extern "C" bool f128M_nan(const float128_t *x);
extern "C" bool f128M_subnorm(const float128_t *x);
extern "C" bool f128M_negative(const float128_t *x);
extern "C" void f128M_negate(float128_t *x);
extern "C" void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
extern "C" float128_t f128_0, f128_1, f128_10, f128_10_17,
 f128_10_18, f128_r10, f128_N1;
typedef struct _float256_t
{
#ifdef LITTLEENDIAN
 float128_t lo;
 float128_t hi;
#else
 float128_t hi;
 float128_t lo;
#endif
} float256_t;
extern "C" void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);
extern "C" float128_t atof128(const char *s);
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern "C" LispObject Lbatchp(LispObject env, int nargs, ...);
extern "C" LispObject bytecounts(LispObject env, int nargs, ...);
extern "C" LispObject Ldate(LispObject env, int nargs, ...);
extern "C" LispObject Ldatestamp(LispObject env, int nargs, ...);
extern "C" LispObject Leject(LispObject env, int nargs, ...);
extern "C" NORETURN void Lerror(LispObject env, int nargs, ...);
extern "C" NORETURN void Lerror0(LispObject env, int nargs, ...);
extern "C" LispObject Lall_symbols0(LispObject env, int nargs, ...);
extern "C" LispObject Lflush(LispObject env, int nargs, ...);
extern "C" LispObject Lgc0(LispObject env, int nargs, ...);
extern "C" LispObject Lgctime(LispObject env, int nargs, ...);
extern "C" LispObject Lgensym(LispObject env, int nargs, ...);
extern "C" LispObject Llist_modules(LispObject env, int nargs, ...);
extern "C" LispObject Llibrary_members0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_source0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_selected_source0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_spid(LispObject, int nargs, ...);
extern "C" LispObject Llposn(LispObject env, int nargs, ...);
extern "C" LispObject Lmapstore0(LispObject env, int nargs, ...);
extern "C" LispObject Lnext_random(LispObject env, int nargs, ...);
extern "C" LispObject Lposn(LispObject env, int nargs, ...);
extern "C" LispObject Lread(LispObject env, int nargs, ...);
extern "C" LispObject Lreadch(LispObject env, int nargs, ...);
extern "C" LispObject Lrtell(LispObject env, int nargs, ...);
extern "C" LispObject Lterpri(LispObject env, int nargs, ...);
extern "C" LispObject Ltime(LispObject env, int nargs, ...);
extern "C" LispObject Ltmpnam(LispObject env, int nargs, ...);
extern "C" LispObject Ltyi(LispObject env, int nargs, ...);
extern "C" LispObject Lunserialize(LispObject env, int nargs, ...);
extern "C" LispObject undefined0(LispObject env);
extern "C" LispObject autoload1(LispObject env, LispObject a1);
extern "C" LispObject bytecoded1(LispObject env, LispObject a);
extern "C" LispObject bytecounts1(LispObject env, LispObject a);
extern "C" LispObject byteopt1(LispObject def, LispObject a);
extern "C" LispObject byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject funarged1(LispObject env, LispObject a1);
extern "C" LispObject tracefunarged1(LispObject env, LispObject a1);
extern "C" LispObject hardopt1(LispObject def, LispObject a);
extern "C" LispObject hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject interpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracebyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracebyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject traceinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracehardopt1(LispObject def, LispObject a);
extern "C" LispObject tracehardoptrest1(LispObject def, LispObject a);
extern "C" LispObject undefined1(LispObject env, LispObject a1);
extern "C" LispObject f1_as_0(LispObject env, LispObject a);
extern "C" LispObject f1_as_1(LispObject env, LispObject a);
extern "C" LispObject Labsval(LispObject env, LispObject a);
extern "C" LispObject Ladd1(LispObject env, LispObject a);
extern "C" LispObject Lalpha_char_p(LispObject env, LispObject a);
extern "C" LispObject Lall_symbols(LispObject env, LispObject a1);
extern "C" LispObject Lapply0(LispObject env, LispObject a);
extern "C" LispObject Lapply_1(LispObject env, LispObject fn);
extern "C" LispObject Latan(LispObject env, LispObject a);
extern "C" LispObject Latom(LispObject env, LispObject a);
extern "C" LispObject Lbanner(LispObject env, LispObject a);
extern "C" LispObject Lboundp(LispObject env, LispObject a);
extern "C" LispObject Lbpsp(LispObject env, LispObject a);
extern "C" LispObject Lbpsupbv(LispObject env, LispObject v);
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
extern "C" NORETURN void Lerror1(LispObject env, LispObject a1);
extern "C" LispObject Lerrorset1(LispObject env, LispObject form);
extern "C" LispObject Leval(LispObject env, LispObject a);
extern "C" LispObject Levenp(LispObject env, LispObject a);
extern "C" LispObject Levlis(LispObject env, LispObject a);
extern "C" LispObject Lexplode(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lc(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lcn(LispObject env, LispObject a);
extern "C" LispObject Lexplode2n(LispObject env, LispObject a);
extern "C" LispObject Lexplodec(LispObject env, LispObject a);
extern "C" LispObject Lexplodecn(LispObject env, LispObject a);
extern "C" LispObject Lexplodehex(LispObject env, LispObject a);
extern "C" LispObject Lexploden(LispObject env, LispObject a);
extern "C" LispObject Lexplodeoctal(LispObject env, LispObject a);
extern "C" LispObject Lfixp(LispObject env, LispObject a);
extern "C" LispObject Lfloat(LispObject env, LispObject a);
extern "C" LispObject Lfloatp(LispObject env, LispObject a);
extern "C" LispObject Lfrexp(LispObject env, LispObject a);
extern "C" LispObject Lfuncall1(LispObject env, LispObject fn);
extern "C" LispObject Lgc(LispObject env, LispObject a);
extern "C" LispObject Lgensym0(LispObject env, LispObject a, const char *s);
extern "C" LispObject Lgensym1(LispObject env, LispObject a);
extern "C" LispObject Lgensym2(LispObject env, LispObject a);
extern "C" LispObject Lgetd(LispObject env, LispObject a);
extern "C" LispObject Lgetenv(LispObject env, LispObject a);
extern "C" LispObject Lget_bps(LispObject env, LispObject a);
extern "C" LispObject Liadd1(LispObject env, LispObject a);
extern "C" LispObject Lidentity(LispObject env, LispObject a);
extern "C" LispObject Liminus(LispObject env, LispObject a);
extern "C" LispObject Liminusp(LispObject env, LispObject a);
extern "C" LispObject Lindirect(LispObject env, LispObject a);
extern "C" LispObject Lintegerp(LispObject env, LispObject a);
extern "C" LispObject Lintern(LispObject env, LispObject a);
extern "C" LispObject Lionep(LispObject env, LispObject a);
extern "C" LispObject Lis_spid(LispObject env, LispObject a);
extern "C" LispObject Lisub1(LispObject env, LispObject a);
extern "C" LispObject Lizerop(LispObject env, LispObject a);
extern "C" LispObject Llength(LispObject env, LispObject a);
extern "C" LispObject Llengthc(LispObject env, LispObject a);
extern "C" LispObject Llibrary_members(LispObject env, LispObject a);
extern "C" LispObject Llinelength(LispObject env, LispObject a);
extern "C" LispObject Llist_to_string(LispObject env, LispObject a);
extern "C" LispObject Llist_to_vector(LispObject env, LispObject a);
extern "C" LispObject Lload_module(LispObject env, LispObject a);
extern "C" LispObject Lload_source(LispObject env, LispObject a);
extern "C" LispObject Lload_selected_source(LispObject env, LispObject a);
extern "C" LispObject Llognot(LispObject env, LispObject a);
extern "C" LispObject Llog_1(LispObject env, LispObject a);
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
extern "C" LispObject Lmkevect(LispObject env, LispObject n);
extern "C" LispObject Lmkquote(LispObject env, LispObject a);
extern "C" LispObject Lmkvect(LispObject env, LispObject a);
extern "C" LispObject Lmodular_minus(LispObject env, LispObject a);
extern "C" LispObject Lmodular_number(LispObject env, LispObject a);
extern "C" LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern "C" LispObject Lmodule_exists(LispObject env, LispObject a);
extern "C" LispObject Lmsd(LispObject env, LispObject a);
extern "C" LispObject Lmv_list(LispObject env, LispObject a);
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
extern "C" LispObject Lprin2a(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprint(LispObject env, LispObject a);
extern "C" LispObject Lprintc(LispObject env, LispObject a);
extern "C" LispObject Lrandom(LispObject env, LispObject a);
extern "C" LispObject Lrational(LispObject env, LispObject a);
extern "C" LispObject Lrdf1(LispObject env, LispObject a);
extern "C" LispObject Lrds(LispObject env, LispObject a);
extern "C" LispObject Lremd(LispObject env, LispObject a);
extern "C" LispObject Lrepresentation1(LispObject env, LispObject a);
extern "C" LispObject Lreverse(LispObject env, LispObject a);
extern "C" LispObject Lserialize(LispObject env, LispObject a);
extern "C" LispObject Lserialize1(LispObject env, LispObject a);
extern "C" LispObject Lsetpchar(LispObject env, LispObject a);
extern "C" LispObject Lset_small_modulus(LispObject env, LispObject a);
extern "C" LispObject Lsmkvect(LispObject env, LispObject a);
extern "C" LispObject Lspecial_char(LispObject env, LispObject a);
extern "C" LispObject Lspecial_form_p(LispObject env, LispObject a);
extern "C" LispObject Lspid_to_nil(LispObject env, LispObject a);
extern "C" LispObject Lspool(LispObject env, LispObject a);
extern "C" LispObject Lstart_module(LispObject env, LispObject a);
extern "C" NORETURN void Lstop(LispObject env, LispObject a);
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
extern "C" LispObject Lwrs(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lzerop(LispObject env, LispObject a);
extern "C" LispObject Lfind_symbol_1(LispObject env, LispObject str);
extern "C" LispObject Llistp(LispObject env, LispObject a);
extern "C" LispObject autoload2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracefunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject traceinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracehardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject undefined2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lappend(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lbpsgetv(LispObject env, LispObject v, LispObject n);
extern "C" LispObject Lcons(LispObject env, LispObject a, LispObject b);
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
extern "C" NORETURN void Lerror2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject Lerrorset2(LispObject env, LispObject form, LispObject ffg1);
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
extern "C" LispObject Lidifference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lileq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lilessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limax(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limin(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Linorm(LispObject env, LispObject a, LispObject k);
extern "C" LispObject Lintersect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lintersect_symlist(LispObject env, LispObject a, LispObject b);
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
extern "C" LispObject Llog_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
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
extern "C" LispObject Lpair(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrem(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrepresentation2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lresource_limit2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrseek(LispObject env, LispObject a);
extern "C" LispObject Lset(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lset_help_file(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
extern "C" NORETURN void Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion_symlist(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lwrite_module(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lxcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Laref2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfloat_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrandom_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject undefined3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern "C" LispObject autoloadn(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject funargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracefunargedn(LispObject env, int nargs, ...);
extern "C" LispObject hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracebyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracebyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracebytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject traceinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracehardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracehardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject undefinedn(LispObject env, int nargs, ...);
extern "C" LispObject f0_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_1(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_2(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_3(LispObject env, int nargs, ...);
extern "C" LispObject Lacons(LispObject env, int nargs, ...);
extern "C" LispObject Lapply_n(LispObject env, int nargs, ...);
extern "C" LispObject Lapply2(LispObject env, int nargs, ...);
extern "C" LispObject Lapply3(LispObject env, int nargs, ...);
extern "C" LispObject Lbpsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorset3(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorsetn(LispObject env, int nargs, ...);
extern "C" LispObject Lfuncalln(LispObject env, int nargs, ...);
extern "C" LispObject Llist(LispObject env, int nargs, ...);
extern "C" LispObject Llist2star(LispObject env, int nargs, ...);
extern "C" LispObject Llist3(LispObject env, int nargs, ...);
extern "C" LispObject Llogand(LispObject env, int nargs, ...);
extern "C" LispObject Llogeqv(LispObject env, int nargs, ...);
extern "C" LispObject Llogor(LispObject env, int nargs, ...);
extern "C" LispObject Llogxor(LispObject env, int nargs, ...);
extern "C" LispObject Lmax(LispObject env, int nargs, ...);
extern "C" LispObject Lmin(LispObject env, int nargs, ...);
extern "C" LispObject Lmkhash(LispObject env, int nargs, ...);
extern "C" LispObject Lput_hash(LispObject env, int nargs, ...);
extern "C" LispObject Lputprop(LispObject env, int nargs, ...);
extern "C" LispObject Lputv(LispObject env, int nargs, ...);
extern "C" LispObject Lresource_limitn(LispObject env, int nargs, ...);
extern "C" LispObject Lsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lsubst(LispObject env, int nargs, ...);
extern "C" LispObject Lvalues(LispObject env, int nargs, ...);
extern "C" LispObject Lappend_n(LispObject env, int nargs, ...);
extern "C" LispObject Laref(LispObject env, int nargs, ...);
extern "C" LispObject Laset(LispObject env, int nargs, ...);
extern "C" LispObject Leqn_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgcd_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgeq_n(LispObject env, int nargs, ...);
extern "C" LispObject Lget_3(LispObject env, int nargs, ...);
extern "C" LispObject Lgreaterp_n(LispObject env, int nargs, ...);
extern "C" LispObject Llcm_n(LispObject env, int nargs, ...);
extern "C" LispObject Lleq_n(LispObject env, int nargs, ...);
extern "C" LispObject Llessp_n(LispObject env, int nargs, ...);
extern "C" LispObject Lquotient_n(LispObject env, int nargs, ...);
#ifdef OPENMATH
extern "C" LispObject om_openFileDev(LispObject env, int nargs, ...);
extern "C" LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern "C" LispObject om_closeDev(LispObject env, LispObject dev);
extern "C" LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern "C" LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern "C" LispObject om_closeConn(LispObject env, LispObject lconn);
extern "C" LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern "C" LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern "C" LispObject om_connectTCP(LispObject env, int nargs, ...);
extern "C" LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern "C" LispObject om_putApp(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndApp(LispObject env, LispObject ldev);
extern "C" LispObject om_putAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_putAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_putBind(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndBind(LispObject env, LispObject ldev);
extern "C" LispObject om_putBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_putError(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndError(LispObject env, LispObject ldev);
extern "C" LispObject om_putObject(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndObject(LispObject env, LispObject ldev);
extern "C" LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern "C" LispObject om_getApp(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndApp(LispObject env, LispObject ldev);
extern "C" LispObject om_getAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_getAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_getBind(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndBind(LispObject env, LispObject ldev);
extern "C" LispObject om_getBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getError(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndError(LispObject env, LispObject ldev);
extern "C" LispObject om_getObject(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndObject(LispObject env, LispObject ldev);
extern "C" LispObject om_getInt(LispObject env, LispObject ldev);
extern "C" LispObject om_getFloat(LispObject env, LispObject ldev);
extern "C" LispObject om_getByteArray(LispObject env, LispObject ldev);
extern "C" LispObject om_getVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getString(LispObject env, LispObject ldev);
extern "C" LispObject om_getSymbol(LispObject env, LispObject ldev);
extern "C" LispObject om_getType(LispObject env, LispObject ldev);
extern "C" LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern "C" LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern "C" LispObject om_read(LispObject env, LispObject dev);
extern "C" LispObject om_supportsCD(LispObject env, LispObject lcd);
extern "C" LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern "C" LispObject om_listCDs(LispObject env, int nargs, ...);
extern "C" LispObject om_listSymbols(LispObject env, LispObject lcd);
extern "C" LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern "C" LispObject undefined4(LispObject env, size_t n, LispObject a1,
 LispObject a2, LispObject a3, LispObject a4);
#endif 
#ifndef __lispthrow_h
#define __lispthrow_h 1
class stack_popper
{ int n;
public:
 stack_popper(int nn)
 { n = nn;
 }
 ~stack_popper()
 { popv(n);
 }
};
class stack_restorer
{ LispObject *stackSave;
public:
 stack_restorer()
 { stackSave = stack;
 }
 ~stack_restorer()
 { stack = stackSave;
 }
};
class save_current_function
{ LispObject *savestack;
public:
 save_current_function(LispObject newfn)
 { push(current_function);
 savestack = stack;
 current_function = newfn;
 }
 ~save_current_function()
 { stack = savestack;
 pop(current_function);
 }
};
class bind_fluid_stack
{ LispObject *savestack;
 int env_loc;
 int name_loc;
 int val_loc;
public:
 bind_fluid_stack(int e, int name, int val)
 { savestack = stack;
 env_loc = e;
 name_loc = name;
 val_loc = val;
#ifdef TRACE_FLUID
 debug_printf("bind_fluid_stack(%d, %d, %d) @ %p\n", e, name, val, stack);
 debug_printf("name="); prin_to_debug(elt(savestack[e], name));
 debug_printf(" old-val="); prin_to_debug(qvalue(elt(savestack[e], name)));
 debug_printf("\n");
#endif
 savestack[val] = qvalue(elt(savestack[e], name));
 }
 ~bind_fluid_stack()
 {
#ifdef TRACE_FLUID
 debug_printf("restore(%d, %d, %d) @ %p\n", env_loc, name_loc, val_loc, savestack);
 debug_printf("name="); prin_to_debug(elt(savestack[env_loc], name_loc));
 debug_printf(" local-val="); prin_to_debug(qvalue(elt(savestack[env_loc], name_loc)));
 debug_printf(" restored-val="); prin_to_debug(savestack[val_loc]);
 debug_printf("\n");
#endif
 qvalue(elt(savestack[env_loc], name_loc)) = savestack[val_loc];
 }
};
struct LispException : public std::exception
{ virtual const char *what() const throw()
 { return "Generic Lisp Exception";
 }
};
 struct LispError : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Error";
 }
 };
 struct LispSignal : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Signal";
 }
 };
 struct LispResource : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Resouce Limiter";
 }
 };
 struct LispSigint : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Sigint";
 }
 };
 struct LispGo : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Go";
 }
 };
 struct LispReturnFrom : public LispException
 { virtual const char *what() const throw()
 { return "Lisp ReturnFrom";
 }
 };
 struct LispThrow : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Throw";
 }
 };
 struct LispRestart : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Restart";
 }
 };
class RAIIstack_sanity
{ LispObject *saveStack;
 const char *fname;
 const char *file;
 int line;
 LispObject w;
public:
 RAIIstack_sanity(const char *fn, const char *fi, int li)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = nil;
 }
 RAIIstack_sanity(const char *fn, const char *fi, int li, LispObject ww)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = ww;
 }
 ~RAIIstack_sanity()
 { if (saveStack != stack && !std::uncaught_exception())
 { printf("???SP %p => %p in %s : %s:%d\n",
 saveStack, stack, fname, file, line);
 if (w != nil)
 { err_printf("Data: ");
 prin_to_error(w);
 err_printf("\n");
 }
 }
 }
};
static inline const char *tidy_filename(const char *a)
{ const char *b = strrchr(a, '/');
 return (b == NULL ? a : b+1);
}
#ifdef DEBUG
#define STACK_SANITY \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__);
#define STACK_SANITY1(w) \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__, w);
#else
#define STACK_SANITY ;
#define STACK_SANITY1(w) ;
#endif
class RAIIsave_codevec
{ LispObject *saveStack;
public:
 RAIIsave_codevec()
 { push2(litvec, codevec);
 saveStack = stack;
 }
 ~RAIIsave_codevec()
 { stack = saveStack;
 pop2(codevec, litvec);
 }
};
#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;
extern LispObject *stack;
extern jmp_buf *global_jb;
class RAIIsave_stack_and_jb
{ LispObject *saveStack;
 jmp_buf *jbsave;
public:
 RAIIsave_stack_and_jb()
 { jbsave = global_jb; 
 saveStack = stack; 
 }
 ~RAIIsave_stack_and_jb()
 { global_jb = jbsave; 
 stack = saveStack; 
 }
};
class RAIIsave_stack
{ LispObject *saveStack;
public:
 RAIIsave_stack()
 { saveStack = stack; 
 }
 ~RAIIsave_stack()
 { stack = saveStack; 
 }
};
#define START_SETJMP_BLOCK \
 jmp_buf jb; \
 RAIIsave_stack_and_jb save_stack_Object; \
 switch (setjmp(jb)) \
 { default: \
 case 1: exit_reason = UNWIND_SIGNAL; \
 throw LispSignal(); \
 case 2: exit_reason = UNWIND_SIGINT; \
 throw LispSigint(); \
 case 0: break; \
 } \
 global_jb = &jb;
#define START_TRY_BLOCK \
 RAIIsave_stack save_stack_Object;
#define on_backtrace(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { int _reason = exit_reason; \
 b; \
 exit_reason = _reason; \
 throw; \
 }
#define if_error(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { b; \
 }
#define ignore_error(a) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { \
 }
#define ignore_exception(a) \
 try \
 { START_SETJMP_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { \
 }
#endif 



// Code for ofsf_smcpknowl

static LispObject CC_ofsf_smcpknowl(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20326, v_20327;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_20326 = v_20252;
// end of prologue
    stack[-4] = v_20326;
    v_20326 = stack[-4];
    if (v_20326 == nil) goto v_20263;
    else goto v_20264;
v_20263:
    v_20326 = nil;
    goto v_20258;
v_20264:
    v_20326 = stack[-4];
    v_20326 = qcar(v_20326);
    v_20327 = v_20326;
    goto v_20276;
v_20272:
    v_20326 = v_20327;
    stack[0] = qcar(v_20326);
    goto v_20273;
v_20274:
    goto v_20284;
v_20280:
    v_20326 = v_20327;
    v_20327 = qcdr(v_20326);
    goto v_20281;
v_20282:
    v_20326 = nil;
    goto v_20283;
v_20284:
    goto v_20280;
v_20281:
    goto v_20282;
v_20283:
    v_20326 = Lappend(nil, v_20327, v_20326);
    env = stack[-5];
    goto v_20275;
v_20276:
    goto v_20272;
v_20273:
    goto v_20274;
v_20275:
    v_20326 = cons(stack[0], v_20326);
    env = stack[-5];
    v_20326 = ncons(v_20326);
    env = stack[-5];
    stack[-2] = v_20326;
    stack[-3] = v_20326;
v_20259:
    v_20326 = stack[-4];
    v_20326 = qcdr(v_20326);
    stack[-4] = v_20326;
    v_20326 = stack[-4];
    if (v_20326 == nil) goto v_20292;
    else goto v_20293;
v_20292:
    v_20326 = stack[-3];
    goto v_20258;
v_20293:
    goto v_20301;
v_20297:
    stack[-1] = stack[-2];
    goto v_20298;
v_20299:
    v_20326 = stack[-4];
    v_20326 = qcar(v_20326);
    v_20327 = v_20326;
    goto v_20312;
v_20308:
    v_20326 = v_20327;
    stack[0] = qcar(v_20326);
    goto v_20309;
v_20310:
    goto v_20320;
v_20316:
    v_20326 = v_20327;
    v_20327 = qcdr(v_20326);
    goto v_20317;
v_20318:
    v_20326 = nil;
    goto v_20319;
v_20320:
    goto v_20316;
v_20317:
    goto v_20318;
v_20319:
    v_20326 = Lappend(nil, v_20327, v_20326);
    env = stack[-5];
    goto v_20311;
v_20312:
    goto v_20308;
v_20309:
    goto v_20310;
v_20311:
    v_20326 = cons(stack[0], v_20326);
    env = stack[-5];
    v_20326 = ncons(v_20326);
    env = stack[-5];
    goto v_20300;
v_20301:
    goto v_20297;
v_20298:
    goto v_20299;
v_20300:
    v_20326 = Lrplacd(nil, stack[-1], v_20326);
    env = stack[-5];
    v_20326 = stack[-2];
    v_20326 = qcdr(v_20326);
    stack[-2] = v_20326;
    goto v_20259;
v_20258:
    return onevalue(v_20326);
}



// Code for multdf

static LispObject CC_multdf(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20320, v_20321;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20253;
    stack[-1] = v_20252;
// end of prologue
    v_20320 = stack[-1];
    if (v_20320 == nil) goto v_20261;
    else goto v_20262;
v_20261:
    v_20320 = lisp_true;
    goto v_20260;
v_20262:
    v_20320 = stack[0];
    v_20320 = (v_20320 == nil ? lisp_true : nil);
    goto v_20260;
    v_20320 = nil;
v_20260:
    if (v_20320 == nil) goto v_20258;
    v_20320 = nil;
    goto v_20256;
v_20258:
    goto v_20280;
v_20276:
    v_20320 = stack[-1];
    v_20321 = qcar(v_20320);
    goto v_20277;
v_20278:
    v_20320 = stack[0];
    v_20320 = qcar(v_20320);
    goto v_20279;
v_20280:
    goto v_20276;
v_20277:
    goto v_20278;
v_20279:
    fn = elt(env, 1); // multerm
    v_20320 = (*qfn2(fn))(fn, v_20321, v_20320);
    env = stack[-3];
    goto v_20290;
v_20286:
    stack[-2] = v_20320;
    goto v_20287;
v_20288:
    goto v_20297;
v_20293:
    v_20320 = stack[-1];
    v_20321 = qcdr(v_20320);
    goto v_20294;
v_20295:
    v_20320 = stack[0];
    goto v_20296;
v_20297:
    goto v_20293;
v_20294:
    goto v_20295;
v_20296:
    v_20320 = CC_multdf(elt(env, 0), v_20321, v_20320);
    env = stack[-3];
    goto v_20289;
v_20290:
    goto v_20286;
v_20287:
    goto v_20288;
v_20289:
    fn = elt(env, 2); // plusdf
    v_20320 = (*qfn2(fn))(fn, stack[-2], v_20320);
    env = stack[-3];
    goto v_20306;
v_20302:
    stack[-2] = v_20320;
    goto v_20303;
v_20304:
    goto v_20313;
v_20309:
    v_20320 = stack[-1];
    v_20320 = qcar(v_20320);
    v_20321 = ncons(v_20320);
    env = stack[-3];
    goto v_20310;
v_20311:
    v_20320 = stack[0];
    v_20320 = qcdr(v_20320);
    goto v_20312;
v_20313:
    goto v_20309;
v_20310:
    goto v_20311;
v_20312:
    v_20320 = CC_multdf(elt(env, 0), v_20321, v_20320);
    env = stack[-3];
    goto v_20305;
v_20306:
    goto v_20302;
v_20303:
    goto v_20304;
v_20305:
    {
        LispObject v_20325 = stack[-2];
        fn = elt(env, 2); // plusdf
        return (*qfn2(fn))(fn, v_20325, v_20320);
    }
    goto v_20256;
    v_20320 = nil;
v_20256:
    return onevalue(v_20320);
}



// Code for domainvalchk

static LispObject CC_domainvalchk(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20321, v_20322, v_20323;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20253;
    stack[-1] = v_20252;
// end of prologue
    goto v_20268;
v_20264:
    v_20322 = qvalue(elt(env, 1)); // dmode!*
    goto v_20265;
v_20266:
    v_20321 = elt(env, 0); // domainvalchk
    goto v_20267;
v_20268:
    goto v_20264;
v_20265:
    goto v_20266;
v_20267:
    v_20321 = get(v_20322, v_20321);
    env = stack[-3];
    stack[-2] = v_20321;
    if (v_20321 == nil) goto v_20262;
    goto v_20278;
v_20272:
    v_20323 = stack[-2];
    goto v_20273;
v_20274:
    v_20322 = stack[-1];
    goto v_20275;
v_20276:
    v_20321 = stack[0];
    goto v_20277;
v_20278:
    goto v_20272;
v_20273:
    goto v_20274;
v_20275:
    goto v_20276;
v_20277:
        return Lapply2(nil, 3, v_20323, v_20322, v_20321);
v_20262:
    v_20321 = stack[0];
    v_20321 = Lreverse(nil, v_20321);
    env = stack[-3];
    stack[0] = v_20321;
v_20258:
    v_20321 = stack[0];
    if (v_20321 == nil) goto v_20286;
    else goto v_20287;
v_20286:
    goto v_20294;
v_20290:
    v_20322 = stack[-1];
    goto v_20291;
v_20292:
    v_20321 = stack[-2];
    goto v_20293;
v_20294:
    goto v_20290;
v_20291:
    goto v_20292;
v_20293:
    {
        fn = elt(env, 2); // valuechk
        return (*qfn2(fn))(fn, v_20322, v_20321);
    }
v_20287:
    goto v_20303;
v_20299:
    v_20321 = stack[0];
    v_20321 = qcar(v_20321);
    v_20322 = qcdr(v_20321);
    goto v_20300;
v_20301:
    v_20321 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20302;
v_20303:
    goto v_20299;
v_20300:
    goto v_20301;
v_20302:
    if (v_20322 == v_20321) goto v_20298;
    v_20321 = nil;
    goto v_20257;
v_20298:
    goto v_20314;
v_20310:
    v_20321 = stack[0];
    v_20321 = qcar(v_20321);
    fn = elt(env, 3); // mk!*sq
    v_20322 = (*qfn1(fn))(fn, v_20321);
    env = stack[-3];
    goto v_20311;
v_20312:
    v_20321 = stack[-2];
    goto v_20313;
v_20314:
    goto v_20310;
v_20311:
    goto v_20312;
v_20313:
    v_20321 = cons(v_20322, v_20321);
    env = stack[-3];
    stack[-2] = v_20321;
    v_20321 = stack[0];
    v_20321 = qcdr(v_20321);
    stack[0] = v_20321;
    goto v_20258;
v_20257:
    return onevalue(v_20321);
}



// Code for pasf_anegrel

static LispObject CC_pasf_anegrel(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20275, v_20276, v_20277;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20277 = v_20252;
// end of prologue
    goto v_20261;
v_20257:
    v_20276 = v_20277;
    goto v_20258;
v_20259:
    v_20275 = elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong))
    goto v_20260;
v_20261:
    goto v_20257;
v_20258:
    goto v_20259;
v_20260:
    v_20275 = Latsoc(nil, v_20276, v_20275);
    v_20275 = qcdr(v_20275);
    if (v_20275 == nil) goto v_20256;
    else goto v_20255;
v_20256:
    goto v_20272;
v_20268:
    v_20275 = elt(env, 2); // "pasf_anegrel: unknown operator "
    goto v_20269;
v_20270:
    v_20276 = v_20277;
    goto v_20271;
v_20272:
    goto v_20268;
v_20269:
    goto v_20270;
v_20271:
    v_20275 = list2(v_20275, v_20276);
    env = stack[0];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_20275);
    }
v_20255:
    return onevalue(v_20275);
}



// Code for aex_subrat1

static LispObject CC_aex_subrat1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20292, v_20293, v_20294;
    LispObject fn;
    LispObject v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_subrat1");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20254,v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20252,v_20253,v_20254);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20254;
    stack[-1] = v_20253;
    stack[-2] = v_20252;
// end of prologue
    v_20292 = stack[-2];
    fn = elt(env, 1); // aex_ex
    v_20292 = (*qfn1(fn))(fn, v_20292);
    env = stack[-3];
    goto v_20269;
v_20263:
    v_20294 = qcar(v_20292);
    goto v_20264;
v_20265:
    v_20293 = stack[-1];
    goto v_20266;
v_20267:
    v_20292 = stack[0];
    goto v_20268;
v_20269:
    goto v_20263;
v_20264:
    goto v_20265;
v_20266:
    goto v_20267;
v_20268:
    fn = elt(env, 2); // sfto_qsubhor1
    v_20292 = (*qfnn(fn))(fn, 3, v_20294, v_20293, v_20292);
    env = stack[-3];
    goto v_20279;
v_20275:
    stack[-1] = v_20292;
    goto v_20276;
v_20277:
    goto v_20286;
v_20282:
    v_20292 = qcar(v_20292);
    fn = elt(env, 3); // kernels
    stack[0] = (*qfn1(fn))(fn, v_20292);
    env = stack[-3];
    goto v_20283;
v_20284:
    v_20292 = stack[-2];
    fn = elt(env, 4); // aex_ctx
    v_20292 = (*qfn1(fn))(fn, v_20292);
    env = stack[-3];
    goto v_20285;
v_20286:
    goto v_20282;
v_20283:
    goto v_20284;
v_20285:
    fn = elt(env, 5); // ctx_filter
    v_20292 = (*qfn2(fn))(fn, stack[0], v_20292);
    env = stack[-3];
    goto v_20278;
v_20279:
    goto v_20275;
v_20276:
    goto v_20277;
v_20278:
    {
        LispObject v_20298 = stack[-1];
        fn = elt(env, 6); // aex_mk
        return (*qfn2(fn))(fn, v_20298, v_20292);
    }
    return onevalue(v_20292);
}



// Code for fnrd

static LispObject CC_fnrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20282, v_20283;
    LispObject fn;
    argcheck(nargs, 0, "fnrd");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// end of prologue
    stack[0] = nil;
    fn = elt(env, 3); // lex
    v_20282 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_20265;
v_20261:
    v_20283 = qvalue(elt(env, 1)); // char
    goto v_20262;
v_20263:
    v_20282 = elt(env, 2); // (c i)
    goto v_20264;
v_20265:
    goto v_20261;
v_20262:
    goto v_20263;
v_20264:
    if (equal(v_20283, v_20282)) goto v_20260;
    goto v_20273;
v_20269:
    v_20282 = qvalue(elt(env, 1)); // char
    v_20283 = Lcompress(nil, v_20282);
    env = stack[-1];
    goto v_20270;
v_20271:
    v_20282 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_20272;
v_20273:
    goto v_20269;
v_20270:
    goto v_20271;
v_20272:
    fn = elt(env, 4); // errorml
    v_20282 = (*qfn2(fn))(fn, v_20283, v_20282);
    env = stack[-1];
    goto v_20258;
v_20260:
    fn = elt(env, 5); // mathml2
    v_20282 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_20282;
    goto v_20258;
v_20258:
    fn = elt(env, 3); // lex
    v_20282 = (*qfnn(fn))(fn, 0);
    v_20282 = stack[0];
    return onevalue(v_20282);
}



// Code for sc_subtrsq

static LispObject CC_sc_subtrsq(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20264, v_20265;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20264 = v_20253;
    v_20265 = v_20252;
// end of prologue
    goto v_20260;
v_20256:
    stack[0] = v_20265;
    goto v_20257;
v_20258:
    fn = elt(env, 1); // negsq
    v_20264 = (*qfn1(fn))(fn, v_20264);
    env = stack[-1];
    goto v_20259;
v_20260:
    goto v_20256;
v_20257:
    goto v_20258;
v_20259:
    {
        LispObject v_20267 = stack[0];
        fn = elt(env, 2); // addsq
        return (*qfn2(fn))(fn, v_20267, v_20264);
    }
}



// Code for vdpilcomb1

static LispObject CC_vdpilcomb1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20330, v_20331, v_20332, v_20333, v_20334, v_20335;
    LispObject fn;
    LispObject v_20257, v_20256, v_20255, v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "vdpilcomb1");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    v_20255 = va_arg(aa, LispObject);
    v_20256 = va_arg(aa, LispObject);
    v_20257 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_20257,v_20256,v_20255,v_20254,v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_20252,v_20253,v_20254,v_20255,v_20256,v_20257);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_20257;
    v_20330 = v_20256;
    stack[-2] = v_20255;
    stack[-3] = v_20254;
    v_20331 = v_20253;
    stack[-4] = v_20252;
// end of prologue
    goto v_20276;
v_20264:
    v_20332 = stack[-4];
    v_20332 = qcdr(v_20332);
    v_20332 = qcdr(v_20332);
    v_20332 = qcdr(v_20332);
    v_20335 = qcar(v_20332);
    goto v_20265;
v_20266:
    v_20334 = v_20331;
    goto v_20267;
v_20268:
    v_20333 = stack[-3];
    goto v_20269;
v_20270:
    v_20331 = stack[-2];
    v_20331 = qcdr(v_20331);
    v_20331 = qcdr(v_20331);
    v_20331 = qcdr(v_20331);
    v_20332 = qcar(v_20331);
    goto v_20271;
v_20272:
    v_20331 = v_20330;
    goto v_20273;
v_20274:
    v_20330 = stack[-1];
    goto v_20275;
v_20276:
    goto v_20264;
v_20265:
    goto v_20266;
v_20267:
    goto v_20268;
v_20269:
    goto v_20270;
v_20271:
    goto v_20272;
v_20273:
    goto v_20274;
v_20275:
    fn = elt(env, 2); // dipilcomb1
    v_20330 = (*qfnn(fn))(fn, 6, v_20335, v_20334, v_20333, v_20332, v_20331, v_20330);
    env = stack[-6];
    fn = elt(env, 3); // dip2vdp
    v_20330 = (*qfn1(fn))(fn, v_20330);
    env = stack[-6];
    stack[-5] = v_20330;
    v_20330 = qvalue(elt(env, 1)); // !*gsugar
    if (v_20330 == nil) goto v_20294;
    goto v_20301;
v_20297:
    stack[0] = stack[-5];
    goto v_20298;
v_20299:
    goto v_20308;
v_20304:
    goto v_20314;
v_20310:
    v_20330 = stack[-4];
    fn = elt(env, 4); // gsugar
    stack[-4] = (*qfn1(fn))(fn, v_20330);
    env = stack[-6];
    goto v_20311;
v_20312:
    v_20330 = stack[-3];
    fn = elt(env, 5); // vevtdeg
    v_20330 = (*qfn1(fn))(fn, v_20330);
    env = stack[-6];
    goto v_20313;
v_20314:
    goto v_20310;
v_20311:
    goto v_20312;
v_20313:
    stack[-3] = plus2(stack[-4], v_20330);
    env = stack[-6];
    goto v_20305;
v_20306:
    goto v_20324;
v_20320:
    v_20330 = stack[-2];
    fn = elt(env, 4); // gsugar
    stack[-2] = (*qfn1(fn))(fn, v_20330);
    env = stack[-6];
    goto v_20321;
v_20322:
    v_20330 = stack[-1];
    fn = elt(env, 5); // vevtdeg
    v_20330 = (*qfn1(fn))(fn, v_20330);
    env = stack[-6];
    goto v_20323;
v_20324:
    goto v_20320;
v_20321:
    goto v_20322;
v_20323:
    v_20330 = plus2(stack[-2], v_20330);
    env = stack[-6];
    goto v_20307;
v_20308:
    goto v_20304;
v_20305:
    goto v_20306;
v_20307:
    fn = elt(env, 6); // max
    v_20330 = (*qfn2(fn))(fn, stack[-3], v_20330);
    env = stack[-6];
    goto v_20300;
v_20301:
    goto v_20297;
v_20298:
    goto v_20299;
v_20300:
    fn = elt(env, 7); // gsetsugar
    v_20330 = (*qfn2(fn))(fn, stack[0], v_20330);
    goto v_20292;
v_20294:
v_20292:
    v_20330 = stack[-5];
    return onevalue(v_20330);
}



// Code for calc_coeff

static LispObject CC_calc_coeff(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20305, v_20306, v_20307;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20253;
    stack[-1] = v_20252;
// end of prologue
    v_20305 = stack[-1];
    if (v_20305 == nil) goto v_20257;
    else goto v_20258;
v_20257:
    v_20305 = (LispObject)16+TAG_FIXNUM; // 1
    return ncons(v_20305);
v_20258:
    goto v_20269;
v_20265:
    v_20305 = stack[-1];
    v_20306 = qcar(v_20305);
    goto v_20266;
v_20267:
    v_20305 = stack[0];
    goto v_20268;
v_20269:
    goto v_20265;
v_20266:
    goto v_20267;
v_20268:
    fn = elt(env, 1); // calc_world
    v_20305 = (*qfn2(fn))(fn, v_20306, v_20305);
    env = stack[-3];
    v_20307 = v_20305;
    goto v_20282;
v_20278:
    v_20306 = v_20307;
    goto v_20279;
v_20280:
    v_20305 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20281;
v_20282:
    goto v_20278;
v_20279:
    goto v_20280;
v_20281:
    if (v_20306 == v_20305) goto v_20276;
    else goto v_20277;
v_20276:
    v_20305 = (LispObject)0+TAG_FIXNUM; // 0
    return ncons(v_20305);
v_20277:
    goto v_20294;
v_20290:
    stack[-2] = v_20307;
    goto v_20291;
v_20292:
    goto v_20301;
v_20297:
    v_20305 = stack[-1];
    v_20306 = qcdr(v_20305);
    goto v_20298;
v_20299:
    v_20305 = stack[0];
    goto v_20300;
v_20301:
    goto v_20297;
v_20298:
    goto v_20299;
v_20300:
    v_20305 = CC_calc_coeff(elt(env, 0), v_20306, v_20305);
    goto v_20293;
v_20294:
    goto v_20290;
v_20291:
    goto v_20292;
v_20293:
    {
        LispObject v_20311 = stack[-2];
        return cons(v_20311, v_20305);
    }
    v_20305 = nil;
    goto v_20256;
    v_20305 = nil;
v_20256:
    return onevalue(v_20305);
}



// Code for dp_neworder

static LispObject CC_dp_neworder(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20321, v_20322;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_20321 = v_20252;
// end of prologue
    goto v_20259;
v_20255:
    stack[-4] = v_20321;
    v_20321 = stack[-4];
    if (v_20321 == nil) goto v_20269;
    else goto v_20270;
v_20269:
    v_20321 = nil;
    v_20322 = v_20321;
    goto v_20264;
v_20270:
    v_20321 = stack[-4];
    v_20321 = qcar(v_20321);
    stack[0] = v_20321;
    goto v_20282;
v_20278:
    v_20321 = stack[0];
    v_20321 = qcar(v_20321);
    fn = elt(env, 2); // mo_neworder
    v_20322 = (*qfn1(fn))(fn, v_20321);
    env = stack[-5];
    goto v_20279;
v_20280:
    v_20321 = stack[0];
    v_20321 = qcdr(v_20321);
    goto v_20281;
v_20282:
    goto v_20278;
v_20279:
    goto v_20280;
v_20281:
    v_20321 = cons(v_20322, v_20321);
    env = stack[-5];
    v_20321 = ncons(v_20321);
    env = stack[-5];
    stack[-2] = v_20321;
    stack[-3] = v_20321;
v_20265:
    v_20321 = stack[-4];
    v_20321 = qcdr(v_20321);
    stack[-4] = v_20321;
    v_20321 = stack[-4];
    if (v_20321 == nil) goto v_20292;
    else goto v_20293;
v_20292:
    v_20321 = stack[-3];
    v_20322 = v_20321;
    goto v_20264;
v_20293:
    goto v_20301;
v_20297:
    stack[-1] = stack[-2];
    goto v_20298;
v_20299:
    v_20321 = stack[-4];
    v_20321 = qcar(v_20321);
    stack[0] = v_20321;
    goto v_20312;
v_20308:
    v_20321 = stack[0];
    v_20321 = qcar(v_20321);
    fn = elt(env, 2); // mo_neworder
    v_20322 = (*qfn1(fn))(fn, v_20321);
    env = stack[-5];
    goto v_20309;
v_20310:
    v_20321 = stack[0];
    v_20321 = qcdr(v_20321);
    goto v_20311;
v_20312:
    goto v_20308;
v_20309:
    goto v_20310;
v_20311:
    v_20321 = cons(v_20322, v_20321);
    env = stack[-5];
    v_20321 = ncons(v_20321);
    env = stack[-5];
    goto v_20300;
v_20301:
    goto v_20297;
v_20298:
    goto v_20299;
v_20300:
    v_20321 = Lrplacd(nil, stack[-1], v_20321);
    env = stack[-5];
    v_20321 = stack[-2];
    v_20321 = qcdr(v_20321);
    stack[-2] = v_20321;
    goto v_20265;
v_20264:
    goto v_20256;
v_20257:
    v_20321 = elt(env, 1); // dp!=mocompare
    goto v_20258;
v_20259:
    goto v_20255;
v_20256:
    goto v_20257;
v_20258:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_20322, v_20321);
    }
}



// Code for dfprintfn

static LispObject CC_dfprintfn(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20307, v_20308, v_20309;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20307 = v_20252;
// end of prologue
    v_20308 = qvalue(elt(env, 1)); // !*nat
    if (v_20308 == nil) goto v_20260;
    else goto v_20261;
v_20260:
    v_20308 = lisp_true;
    goto v_20259;
v_20261:
    v_20308 = qvalue(elt(env, 2)); // !*fort
    if (v_20308 == nil) goto v_20268;
    else goto v_20267;
v_20268:
    v_20308 = qvalue(elt(env, 3)); // !*dfprint
    v_20308 = (v_20308 == nil ? lisp_true : nil);
v_20267:
    goto v_20259;
    v_20308 = nil;
v_20259:
    if (v_20308 == nil) goto v_20257;
    v_20307 = elt(env, 4); // failed
    goto v_20255;
v_20257:
    goto v_20285;
v_20279:
    goto v_20291;
v_20287:
    v_20308 = elt(env, 5); // !!df!!
    goto v_20288;
v_20289:
    v_20307 = qcdr(v_20307);
    goto v_20290;
v_20291:
    goto v_20287;
v_20288:
    goto v_20289;
v_20290:
    v_20309 = cons(v_20308, v_20307);
    env = stack[0];
    goto v_20280;
v_20281:
    v_20308 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20282;
v_20283:
    v_20307 = nil;
    goto v_20284;
v_20285:
    goto v_20279;
v_20280:
    goto v_20281;
v_20282:
    goto v_20283;
v_20284:
    fn = elt(env, 6); // layout!-formula
    v_20307 = (*qfnn(fn))(fn, 3, v_20309, v_20308, v_20307);
    env = stack[0];
    v_20308 = v_20307;
    v_20307 = v_20308;
    if (v_20307 == nil) goto v_20299;
    else goto v_20300;
v_20299:
    v_20307 = elt(env, 4); // failed
    goto v_20277;
v_20300:
    v_20307 = v_20308;
    fn = elt(env, 7); // putpline
    v_20307 = (*qfn1(fn))(fn, v_20307);
    goto v_20298;
v_20298:
    v_20307 = nil;
v_20277:
    goto v_20255;
    v_20307 = nil;
v_20255:
    return onevalue(v_20307);
}



// Code for clean_numid

static LispObject CC_clean_numid(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20285, v_20286;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20252;
// end of prologue
    stack[-1] = nil;
v_20257:
    v_20285 = stack[0];
    if (v_20285 == nil) goto v_20260;
    else goto v_20261;
v_20260:
    v_20285 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_20285);
    }
v_20261:
    v_20285 = stack[0];
    v_20285 = qcar(v_20285);
    fn = elt(env, 2); // !*id2num
    v_20285 = (*qfn1(fn))(fn, v_20285);
    env = stack[-2];
    if (v_20285 == nil) goto v_20266;
    v_20285 = stack[0];
    v_20285 = qcdr(v_20285);
    stack[0] = v_20285;
    goto v_20257;
v_20266:
    goto v_20279;
v_20275:
    v_20285 = stack[0];
    v_20286 = qcar(v_20285);
    goto v_20276;
v_20277:
    v_20285 = stack[-1];
    goto v_20278;
v_20279:
    goto v_20275;
v_20276:
    goto v_20277;
v_20278:
    v_20285 = cons(v_20286, v_20285);
    env = stack[-2];
    stack[-1] = v_20285;
    v_20285 = stack[0];
    v_20285 = qcdr(v_20285);
    stack[0] = v_20285;
    goto v_20257;
    v_20285 = nil;
    return onevalue(v_20285);
}



// Code for dummyp

static LispObject CC_dummyp(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20371, v_20372, v_20373;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_20252;
// end of prologue
    v_20371 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_20371;
    v_20371 = stack[-3];
    fn = elt(env, 4); // listp
    v_20371 = (*qfn1(fn))(fn, v_20371);
    env = stack[-5];
    if (v_20371 == nil) goto v_20264;
    goto v_20276;
v_20272:
    v_20372 = stack[-3];
    goto v_20273;
v_20274:
    v_20371 = elt(env, 1); // minus
    goto v_20275;
v_20276:
    goto v_20272;
v_20273:
    goto v_20274;
v_20275:
    if (!consp(v_20372)) goto v_20270;
    v_20372 = qcar(v_20372);
    if (v_20372 == v_20371) goto v_20269;
    else goto v_20270;
v_20269:
    v_20371 = stack[-3];
    v_20371 = qcdr(v_20371);
    v_20371 = qcar(v_20371);
    stack[-3] = v_20371;
    goto v_20268;
v_20270:
    v_20371 = nil;
    goto v_20258;
v_20268:
    goto v_20262;
v_20264:
v_20262:
    v_20371 = stack[-3];
    if (is_number(v_20371)) goto v_20287;
    v_20371 = stack[-3];
    fn = elt(env, 5); // !*id2num
    v_20371 = (*qfn1(fn))(fn, v_20371);
    env = stack[-5];
    if (v_20371 == nil) goto v_20291;
    else goto v_20287;
v_20291:
    goto v_20288;
v_20287:
    v_20371 = nil;
    goto v_20258;
v_20288:
    v_20371 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_20371;
v_20298:
    goto v_20308;
v_20304:
    stack[0] = stack[-4];
    goto v_20305;
v_20306:
    v_20371 = qvalue(elt(env, 2)); // g_dvnames
    fn = elt(env, 6); // upbve
    v_20371 = (*qfn1(fn))(fn, v_20371);
    env = stack[-5];
    goto v_20307;
v_20308:
    goto v_20304;
v_20305:
    goto v_20306;
v_20307:
    v_20371 = (LispObject)lesseq2(stack[0], v_20371);
    v_20371 = v_20371 ? lisp_true : nil;
    env = stack[-5];
    if (v_20371 == nil) goto v_20301;
    else goto v_20302;
v_20301:
    goto v_20297;
v_20302:
    goto v_20321;
v_20317:
    stack[-1] = stack[-3];
    goto v_20318;
v_20319:
    goto v_20327;
v_20323:
    stack[0] = qvalue(elt(env, 2)); // g_dvnames
    goto v_20324;
v_20325:
    v_20371 = stack[-4];
    v_20371 = sub1(v_20371);
    env = stack[-5];
    goto v_20326;
v_20327:
    goto v_20323;
v_20324:
    goto v_20325;
v_20326:
    v_20371 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_20371-TAG_FIXNUM)/(16/CELL)));
    goto v_20320;
v_20321:
    goto v_20317;
v_20318:
    goto v_20319;
v_20320:
    if (equal(stack[-1], v_20371)) goto v_20315;
    else goto v_20316;
v_20315:
    v_20371 = stack[-4];
    stack[-2] = v_20371;
    v_20371 = qvalue(elt(env, 2)); // g_dvnames
    fn = elt(env, 6); // upbve
    v_20371 = (*qfn1(fn))(fn, v_20371);
    env = stack[-5];
    v_20371 = add1(v_20371);
    env = stack[-5];
    stack[-4] = v_20371;
    goto v_20314;
v_20316:
    v_20371 = stack[-4];
    v_20371 = add1(v_20371);
    env = stack[-5];
    stack[-4] = v_20371;
    goto v_20314;
v_20314:
    goto v_20298;
v_20297:
    goto v_20349;
v_20345:
    v_20372 = stack[-2];
    goto v_20346;
v_20347:
    v_20371 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20348;
v_20349:
    goto v_20345;
v_20346:
    goto v_20347;
v_20348:
    if (v_20372 == v_20371) goto v_20343;
    else goto v_20344;
v_20343:
    v_20371 = stack[-3];
    fn = elt(env, 7); // ad_splitname
    v_20371 = (*qfn1(fn))(fn, v_20371);
    env = stack[-5];
    v_20372 = v_20371;
    goto v_20362;
v_20358:
    v_20371 = v_20372;
    v_20371 = qcar(v_20371);
    goto v_20359;
v_20360:
    v_20373 = qvalue(elt(env, 3)); // g_dvbase
    goto v_20361;
v_20362:
    goto v_20358;
v_20359:
    goto v_20360;
v_20361:
    if (v_20371 == v_20373) goto v_20356;
    else goto v_20357;
v_20356:
    v_20371 = v_20372;
    v_20371 = qcdr(v_20371);
    goto v_20258;
v_20357:
    goto v_20342;
v_20344:
    v_20371 = stack[-2];
    goto v_20258;
v_20342:
    v_20371 = nil;
v_20258:
    return onevalue(v_20371);
}



// Code for difbf

static LispObject CC_difbf(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20506, v_20507, v_20508;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_20253;
    stack[-7] = v_20252;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-9, 1, -2);
    qvalue(elt(env, 1)) = nil; // d
    goto v_20272;
v_20268:
    v_20506 = stack[-7];
    v_20506 = qcdr(v_20506);
    v_20507 = qcar(v_20506);
    stack[-8] = v_20507;
    goto v_20269;
v_20270:
    v_20506 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20271;
v_20272:
    goto v_20268;
v_20269:
    goto v_20270;
v_20271:
    if (v_20507 == v_20506) goto v_20266;
    else goto v_20267;
v_20266:
    v_20506 = stack[-6];
    fn = elt(env, 4); // minus!:
    v_20506 = (*qfn1(fn))(fn, v_20506);
    env = stack[-9];
    goto v_20263;
v_20267:
    goto v_20287;
v_20283:
    v_20506 = stack[-6];
    v_20506 = qcdr(v_20506);
    v_20507 = qcar(v_20506);
    stack[-5] = v_20507;
    goto v_20284;
v_20285:
    v_20506 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20286;
v_20287:
    goto v_20283;
v_20284:
    goto v_20285;
v_20286:
    if (v_20507 == v_20506) goto v_20281;
    else goto v_20282;
v_20281:
    v_20506 = stack[-7];
    goto v_20263;
v_20282:
    goto v_20301;
v_20297:
    goto v_20307;
v_20303:
    v_20506 = stack[-7];
    v_20506 = qcdr(v_20506);
    v_20507 = qcdr(v_20506);
    stack[-4] = v_20507;
    goto v_20304;
v_20305:
    v_20506 = stack[-6];
    v_20506 = qcdr(v_20506);
    v_20506 = qcdr(v_20506);
    stack[-3] = v_20506;
    goto v_20306;
v_20307:
    goto v_20303;
v_20304:
    goto v_20305;
v_20306:
    v_20507 = difference2(v_20507, v_20506);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_20507; // d
    goto v_20298;
v_20299:
    v_20506 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20300;
v_20301:
    goto v_20297;
v_20298:
    goto v_20299;
v_20300:
    if (v_20507 == v_20506) goto v_20295;
    else goto v_20296;
v_20295:
    goto v_20322;
v_20316:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_20317;
v_20318:
    goto v_20329;
v_20325:
    v_20507 = stack[-8];
    goto v_20326;
v_20327:
    v_20506 = stack[-5];
    goto v_20328;
v_20329:
    goto v_20325;
v_20326:
    goto v_20327;
v_20328:
    v_20507 = difference2(v_20507, v_20506);
    env = stack[-9];
    goto v_20319;
v_20320:
    v_20506 = stack[-4];
    goto v_20321;
v_20322:
    goto v_20316;
v_20317:
    goto v_20318;
v_20319:
    goto v_20320;
v_20321:
    v_20506 = list2star(stack[0], v_20507, v_20506);
    env = stack[-9];
    goto v_20263;
v_20296:
    goto v_20338;
v_20334:
    stack[-1] = qvalue(elt(env, 1)); // d
    goto v_20335;
v_20336:
    goto v_20345;
v_20341:
    v_20506 = stack[-8];
    v_20506 = Labsval(nil, v_20506);
    env = stack[-9];
    fn = elt(env, 5); // msd
    stack[0] = (*qfn1(fn))(fn, v_20506);
    env = stack[-9];
    goto v_20342;
v_20343:
    v_20506 = stack[-5];
    v_20506 = Labsval(nil, v_20506);
    env = stack[-9];
    fn = elt(env, 5); // msd
    v_20506 = (*qfn1(fn))(fn, v_20506);
    env = stack[-9];
    goto v_20344;
v_20345:
    goto v_20341;
v_20342:
    goto v_20343;
v_20344:
    v_20506 = difference2(stack[0], v_20506);
    env = stack[-9];
    goto v_20337;
v_20338:
    goto v_20334;
v_20335:
    goto v_20336;
v_20337:
    v_20506 = plus2(stack[-1], v_20506);
    env = stack[-9];
    stack[-1] = v_20506;
    v_20506 = qvalue(elt(env, 3)); // !:bprec!:
    v_20506 = add1(v_20506);
    env = stack[-9];
    stack[0] = v_20506;
    goto v_20363;
v_20359:
    v_20507 = stack[-1];
    goto v_20360;
v_20361:
    v_20506 = stack[0];
    goto v_20362;
v_20363:
    goto v_20359;
v_20360:
    goto v_20361;
v_20362:
    v_20506 = (LispObject)greaterp2(v_20507, v_20506);
    v_20506 = v_20506 ? lisp_true : nil;
    env = stack[-9];
    if (v_20506 == nil) goto v_20357;
    v_20506 = stack[-7];
    goto v_20263;
v_20357:
    goto v_20376;
v_20372:
    goto v_20373;
v_20374:
    v_20506 = stack[0];
    v_20506 = negate(v_20506);
    env = stack[-9];
    goto v_20375;
v_20376:
    goto v_20372;
v_20373:
    goto v_20374;
v_20375:
    v_20506 = (LispObject)lessp2(stack[-1], v_20506);
    v_20506 = v_20506 ? lisp_true : nil;
    env = stack[-9];
    if (v_20506 == nil) goto v_20370;
    v_20506 = stack[-6];
    fn = elt(env, 4); // minus!:
    v_20506 = (*qfn1(fn))(fn, v_20506);
    env = stack[-9];
    goto v_20263;
v_20370:
    goto v_20391;
v_20387:
    v_20507 = qvalue(elt(env, 1)); // d
    goto v_20388;
v_20389:
    v_20506 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20390;
v_20391:
    goto v_20387;
v_20388:
    goto v_20389;
v_20390:
    v_20506 = (LispObject)greaterp2(v_20507, v_20506);
    v_20506 = v_20506 ? lisp_true : nil;
    env = stack[-9];
    if (v_20506 == nil) goto v_20385;
    goto v_20401;
v_20395:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_20396;
v_20397:
    goto v_20408;
v_20404:
    goto v_20414;
v_20410:
    v_20507 = stack[-8];
    goto v_20411;
v_20412:
    v_20506 = qvalue(elt(env, 1)); // d
    goto v_20413;
v_20414:
    goto v_20410;
v_20411:
    goto v_20412;
v_20413:
    fn = elt(env, 6); // ashift
    v_20507 = (*qfn2(fn))(fn, v_20507, v_20506);
    env = stack[-9];
    goto v_20405;
v_20406:
    v_20506 = stack[-5];
    goto v_20407;
v_20408:
    goto v_20404;
v_20405:
    goto v_20406;
v_20407:
    v_20507 = difference2(v_20507, v_20506);
    env = stack[-9];
    goto v_20398;
v_20399:
    v_20506 = stack[-3];
    goto v_20400;
v_20401:
    goto v_20395;
v_20396:
    goto v_20397;
v_20398:
    goto v_20399;
v_20400:
    v_20506 = list2star(stack[0], v_20507, v_20506);
    env = stack[-9];
    goto v_20263;
v_20385:
    goto v_20428;
v_20422:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_20423;
v_20424:
    goto v_20435;
v_20431:
    stack[-1] = stack[-8];
    goto v_20432;
v_20433:
    goto v_20442;
v_20438:
    stack[-3] = stack[-5];
    goto v_20439;
v_20440:
    v_20506 = qvalue(elt(env, 1)); // d
    v_20506 = negate(v_20506);
    env = stack[-9];
    goto v_20441;
v_20442:
    goto v_20438;
v_20439:
    goto v_20440;
v_20441:
    fn = elt(env, 6); // ashift
    v_20506 = (*qfn2(fn))(fn, stack[-3], v_20506);
    env = stack[-9];
    goto v_20434;
v_20435:
    goto v_20431;
v_20432:
    goto v_20433;
v_20434:
    v_20507 = difference2(stack[-1], v_20506);
    env = stack[-9];
    goto v_20425;
v_20426:
    v_20506 = stack[-4];
    goto v_20427;
v_20428:
    goto v_20422;
v_20423:
    goto v_20424;
v_20425:
    goto v_20426;
v_20427:
    v_20506 = list2star(stack[0], v_20507, v_20506);
    env = stack[-9];
    goto v_20263;
    v_20506 = nil;
v_20263:
    ;}  // end of a binding scope
    stack[-2] = v_20506;
    v_20506 = stack[-2];
    v_20506 = qcdr(v_20506);
    v_20506 = qcar(v_20506);
    v_20508 = v_20506;
    goto v_20462;
v_20458:
    v_20507 = v_20508;
    goto v_20459;
v_20460:
    v_20506 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20461;
v_20462:
    goto v_20458;
v_20459:
    goto v_20460;
v_20461:
    if (v_20507 == v_20506) goto v_20456;
    else goto v_20457;
v_20456:
    goto v_20472;
v_20466:
    v_20508 = elt(env, 2); // !:rd!:
    goto v_20467;
v_20468:
    v_20507 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20469;
v_20470:
    v_20506 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20471;
v_20472:
    goto v_20466;
v_20467:
    goto v_20468;
v_20469:
    goto v_20470;
v_20471:
    return list2star(v_20508, v_20507, v_20506);
v_20457:
    goto v_20481;
v_20477:
    v_20507 = v_20508;
    goto v_20478;
v_20479:
    v_20506 = qvalue(elt(env, 3)); // !:bprec!:
    goto v_20480;
v_20481:
    goto v_20477;
v_20478:
    goto v_20479;
v_20480:
    fn = elt(env, 7); // inorm
    v_20506 = (*qfn2(fn))(fn, v_20507, v_20506);
    env = stack[-9];
    v_20508 = v_20506;
    goto v_20491;
v_20485:
    stack[-1] = elt(env, 2); // !:rd!:
    goto v_20486;
v_20487:
    v_20506 = v_20508;
    stack[0] = qcar(v_20506);
    goto v_20488;
v_20489:
    goto v_20500;
v_20496:
    v_20506 = v_20508;
    v_20507 = qcdr(v_20506);
    goto v_20497;
v_20498:
    v_20506 = stack[-2];
    v_20506 = qcdr(v_20506);
    v_20506 = qcdr(v_20506);
    goto v_20499;
v_20500:
    goto v_20496;
v_20497:
    goto v_20498;
v_20499:
    v_20506 = plus2(v_20507, v_20506);
    goto v_20490;
v_20491:
    goto v_20485;
v_20486:
    goto v_20487;
v_20488:
    goto v_20489;
v_20490:
    {
        LispObject v_20518 = stack[-1];
        LispObject v_20519 = stack[0];
        return list2star(v_20518, v_20519, v_20506);
    }
    return onevalue(v_20506);
}



// Code for order_of_der_mind

static LispObject CC_order_of_der_mind(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20258;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20258 = v_20252;
// end of prologue
    v_20258 = qcdr(v_20258);
    v_20258 = qcar(v_20258);
    {
        fn = elt(env, 1); // length_multiindex
        return (*qfn1(fn))(fn, v_20258);
    }
}



// Code for ext_mult

static LispObject CC_ext_mult(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20328, v_20329, v_20330;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20328 = v_20253;
    v_20329 = v_20252;
// end of prologue
    goto v_20260;
v_20256:
    v_20329 = qcdr(v_20329);
    goto v_20257;
v_20258:
    v_20328 = qcdr(v_20328);
    goto v_20259;
v_20260:
    goto v_20256;
v_20257:
    goto v_20258;
v_20259:
    fn = elt(env, 2); // merge_lists
    v_20328 = (*qfn2(fn))(fn, v_20329, v_20328);
    env = stack[-1];
    stack[0] = v_20328;
    v_20328 = stack[0];
    if (v_20328 == nil) goto v_20268;
    else goto v_20269;
v_20268:
    goto v_20276;
v_20272:
    v_20329 = nil;
    goto v_20273;
v_20274:
    v_20328 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20275;
v_20276:
    goto v_20272;
v_20273:
    goto v_20274;
v_20275:
    return cons(v_20329, v_20328);
v_20269:
    v_20328 = stack[0];
    v_20328 = qcdr(v_20328);
    if (v_20328 == nil) goto v_20279;
    else goto v_20280;
v_20279:
    goto v_20288;
v_20284:
    v_20329 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20285;
v_20286:
    v_20328 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20287;
v_20288:
    goto v_20284;
v_20285:
    goto v_20286;
v_20287:
    return cons(v_20329, v_20328);
v_20280:
    goto v_20300;
v_20294:
    goto v_20306;
v_20302:
    goto v_20312;
v_20308:
    goto v_20319;
v_20315:
    v_20329 = elt(env, 1); // ext
    goto v_20316;
v_20317:
    v_20328 = stack[0];
    v_20328 = qcdr(v_20328);
    goto v_20318;
v_20319:
    goto v_20315;
v_20316:
    goto v_20317;
v_20318:
    v_20328 = cons(v_20329, v_20328);
    env = stack[-1];
    fn = elt(env, 3); // !*a2k
    v_20329 = (*qfn1(fn))(fn, v_20328);
    env = stack[-1];
    goto v_20309;
v_20310:
    v_20328 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20311;
v_20312:
    goto v_20308;
v_20309:
    goto v_20310;
v_20311:
    fn = elt(env, 4); // to
    v_20329 = (*qfn2(fn))(fn, v_20329, v_20328);
    env = stack[-1];
    goto v_20303;
v_20304:
    v_20328 = stack[0];
    v_20328 = qcar(v_20328);
    goto v_20305;
v_20306:
    goto v_20302;
v_20303:
    goto v_20304;
v_20305:
    v_20330 = cons(v_20329, v_20328);
    goto v_20295;
v_20296:
    v_20329 = nil;
    goto v_20297;
v_20298:
    v_20328 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20299;
v_20300:
    goto v_20294;
v_20295:
    goto v_20296;
v_20297:
    goto v_20298;
v_20299:
    return acons(v_20330, v_20329, v_20328);
    v_20328 = nil;
    return onevalue(v_20328);
}



// Code for bc_mkat

static LispObject CC_bc_mkat(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20267, v_20268, v_20269;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20267 = v_20253;
    v_20268 = v_20252;
// end of prologue
    goto v_20262;
v_20256:
    v_20269 = v_20268;
    goto v_20257;
v_20258:
    v_20268 = qcar(v_20267);
    goto v_20259;
v_20260:
    v_20267 = nil;
    goto v_20261;
v_20262:
    goto v_20256;
v_20257:
    goto v_20258;
v_20259:
    goto v_20260;
v_20261:
    return list3(v_20269, v_20268, v_20267);
}



// Code for ithlistelem

static LispObject CC_ithlistelem(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20286, v_20287;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20253;
    stack[-1] = v_20252;
// end of prologue
    v_20286 = stack[-1];
    if (v_20286 == nil) goto v_20260;
    goto v_20267;
v_20263:
    goto v_20273;
v_20269:
    v_20286 = stack[-1];
    v_20287 = qcar(v_20286);
    goto v_20270;
v_20271:
    v_20286 = stack[0];
    goto v_20272;
v_20273:
    goto v_20269;
v_20270:
    goto v_20271;
v_20272:
    fn = elt(env, 1); // nth
    stack[-2] = (*qfn2(fn))(fn, v_20287, v_20286);
    env = stack[-3];
    goto v_20264;
v_20265:
    goto v_20282;
v_20278:
    v_20286 = stack[-1];
    v_20287 = qcdr(v_20286);
    goto v_20279;
v_20280:
    v_20286 = stack[0];
    goto v_20281;
v_20282:
    goto v_20278;
v_20279:
    goto v_20280;
v_20281:
    v_20286 = CC_ithlistelem(elt(env, 0), v_20287, v_20286);
    goto v_20266;
v_20267:
    goto v_20263;
v_20264:
    goto v_20265;
v_20266:
    {
        LispObject v_20291 = stack[-2];
        return cons(v_20291, v_20286);
    }
v_20260:
    v_20286 = nil;
    return onevalue(v_20286);
}



// Code for maxl

static LispObject CC_maxl(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20295, v_20296;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20252;
// end of prologue
    stack[-1] = nil;
v_20258:
    v_20295 = stack[0];
    if (v_20295 == nil) goto v_20263;
    else goto v_20264;
v_20263:
    goto v_20259;
v_20264:
    goto v_20271;
v_20267:
    v_20295 = stack[0];
    v_20296 = qcar(v_20295);
    goto v_20268;
v_20269:
    v_20295 = stack[-1];
    goto v_20270;
v_20271:
    goto v_20267;
v_20268:
    goto v_20269;
v_20270:
    v_20295 = cons(v_20296, v_20295);
    env = stack[-2];
    stack[-1] = v_20295;
    v_20295 = stack[0];
    v_20295 = qcdr(v_20295);
    stack[0] = v_20295;
    goto v_20258;
v_20259:
    v_20295 = (LispObject)-160000+TAG_FIXNUM; // -10000
    v_20296 = v_20295;
v_20260:
    v_20295 = stack[-1];
    if (v_20295 == nil) goto v_20280;
    else goto v_20281;
v_20280:
    v_20295 = v_20296;
    goto v_20257;
v_20281:
    goto v_20289;
v_20285:
    v_20295 = stack[-1];
    v_20295 = qcar(v_20295);
    goto v_20286;
v_20287:
    goto v_20288;
v_20289:
    goto v_20285;
v_20286:
    goto v_20287;
v_20288:
    fn = elt(env, 1); // max
    v_20295 = (*qfn2(fn))(fn, v_20295, v_20296);
    env = stack[-2];
    v_20296 = v_20295;
    v_20295 = stack[-1];
    v_20295 = qcdr(v_20295);
    stack[-1] = v_20295;
    goto v_20260;
v_20257:
    return onevalue(v_20295);
}



// Code for make!-unique!-freevars

static LispObject CC_makeKuniqueKfreevars(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20364, v_20365, v_20366;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_20365 = v_20252;
// end of prologue
    v_20364 = v_20365;
    if (!consp(v_20364)) goto v_20256;
    else goto v_20257;
v_20256:
    goto v_20268;
v_20264:
    v_20366 = v_20365;
    goto v_20265;
v_20266:
    v_20364 = elt(env, 1); // gen
    goto v_20267;
v_20268:
    goto v_20264;
v_20265:
    goto v_20266;
v_20267:
    v_20364 = get(v_20366, v_20364);
    env = stack[-4];
    if (v_20364 == nil) goto v_20262;
    goto v_20278;
v_20274:
    v_20366 = v_20365;
    goto v_20275;
v_20276:
    v_20364 = qvalue(elt(env, 2)); // freevarlist!*
    goto v_20277;
v_20278:
    goto v_20274;
v_20275:
    goto v_20276;
v_20277:
    v_20364 = Latsoc(nil, v_20366, v_20364);
    stack[0] = v_20364;
    v_20364 = stack[0];
    if (v_20364 == nil) goto v_20284;
    else goto v_20285;
v_20284:
    goto v_20292;
v_20288:
    stack[0] = v_20365;
    goto v_20289;
v_20290:
    fn = elt(env, 3); // pm!:gensym
    v_20364 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_20291;
v_20292:
    goto v_20288;
v_20289:
    goto v_20290;
v_20291:
    v_20364 = cons(stack[0], v_20364);
    env = stack[-4];
    stack[0] = v_20364;
    goto v_20302;
v_20296:
    v_20364 = stack[0];
    v_20366 = qcdr(v_20364);
    goto v_20297;
v_20298:
    v_20365 = elt(env, 1); // gen
    goto v_20299;
v_20300:
    v_20364 = lisp_true;
    goto v_20301;
v_20302:
    goto v_20296;
v_20297:
    goto v_20298;
v_20299:
    goto v_20300;
v_20301:
    v_20364 = Lputprop(nil, 3, v_20366, v_20365, v_20364);
    env = stack[-4];
    goto v_20312;
v_20308:
    v_20365 = stack[0];
    goto v_20309;
v_20310:
    v_20364 = qvalue(elt(env, 2)); // freevarlist!*
    goto v_20311;
v_20312:
    goto v_20308;
v_20309:
    goto v_20310;
v_20311:
    v_20364 = cons(v_20365, v_20364);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_20364; // freevarlist!*
    goto v_20283;
v_20285:
v_20283:
    v_20364 = stack[0];
    v_20364 = qcdr(v_20364);
    goto v_20260;
v_20262:
    v_20364 = v_20365;
    goto v_20260;
    v_20364 = nil;
v_20260:
    goto v_20255;
v_20257:
    v_20364 = v_20365;
    stack[-3] = v_20364;
    v_20364 = stack[-3];
    if (v_20364 == nil) goto v_20331;
    else goto v_20332;
v_20331:
    v_20364 = nil;
    goto v_20326;
v_20332:
    v_20364 = stack[-3];
    v_20364 = qcar(v_20364);
    v_20364 = CC_makeKuniqueKfreevars(elt(env, 0), v_20364);
    env = stack[-4];
    v_20364 = ncons(v_20364);
    env = stack[-4];
    stack[-1] = v_20364;
    stack[-2] = v_20364;
v_20327:
    v_20364 = stack[-3];
    v_20364 = qcdr(v_20364);
    stack[-3] = v_20364;
    v_20364 = stack[-3];
    if (v_20364 == nil) goto v_20345;
    else goto v_20346;
v_20345:
    v_20364 = stack[-2];
    goto v_20326;
v_20346:
    goto v_20354;
v_20350:
    stack[0] = stack[-1];
    goto v_20351;
v_20352:
    v_20364 = stack[-3];
    v_20364 = qcar(v_20364);
    v_20364 = CC_makeKuniqueKfreevars(elt(env, 0), v_20364);
    env = stack[-4];
    v_20364 = ncons(v_20364);
    env = stack[-4];
    goto v_20353;
v_20354:
    goto v_20350;
v_20351:
    goto v_20352;
v_20353:
    v_20364 = Lrplacd(nil, stack[0], v_20364);
    env = stack[-4];
    v_20364 = stack[-1];
    v_20364 = qcdr(v_20364);
    stack[-1] = v_20364;
    goto v_20327;
v_20326:
    goto v_20255;
    v_20364 = nil;
v_20255:
    return onevalue(v_20364);
}



// Code for noncomexpf

static LispObject CC_noncomexpf(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20290;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20252;
// end of prologue
v_20251:
    v_20290 = stack[0];
    if (!consp(v_20290)) goto v_20260;
    else goto v_20261;
v_20260:
    v_20290 = lisp_true;
    goto v_20259;
v_20261:
    v_20290 = stack[0];
    v_20290 = qcar(v_20290);
    v_20290 = (consp(v_20290) ? nil : lisp_true);
    goto v_20259;
    v_20290 = nil;
v_20259:
    if (v_20290 == nil) goto v_20256;
    else goto v_20257;
v_20256:
    v_20290 = stack[0];
    v_20290 = qcar(v_20290);
    v_20290 = qcar(v_20290);
    v_20290 = qcar(v_20290);
    fn = elt(env, 1); // noncomp
    v_20290 = (*qfn1(fn))(fn, v_20290);
    env = stack[-1];
    if (v_20290 == nil) goto v_20271;
    else goto v_20270;
v_20271:
    v_20290 = stack[0];
    v_20290 = qcar(v_20290);
    v_20290 = qcdr(v_20290);
    v_20290 = CC_noncomexpf(elt(env, 0), v_20290);
    env = stack[-1];
    if (v_20290 == nil) goto v_20279;
    else goto v_20278;
v_20279:
    v_20290 = stack[0];
    v_20290 = qcdr(v_20290);
    stack[0] = v_20290;
    goto v_20251;
v_20278:
v_20270:
    goto v_20255;
v_20257:
    v_20290 = nil;
    goto v_20255;
    v_20290 = nil;
v_20255:
    return onevalue(v_20290);
}



// Code for getrlist

static LispObject CC_getrlist(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20296, v_20297, v_20298;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20298 = v_20252;
// end of prologue
    goto v_20263;
v_20259:
    v_20297 = v_20298;
    goto v_20260;
v_20261:
    v_20296 = elt(env, 1); // list
    goto v_20262;
v_20263:
    goto v_20259;
v_20260:
    goto v_20261;
v_20262:
    if (!consp(v_20297)) goto v_20257;
    v_20297 = qcar(v_20297);
    if (v_20297 == v_20296) goto v_20256;
    else goto v_20257;
v_20256:
    v_20296 = v_20298;
    v_20296 = qcdr(v_20296);
    goto v_20255;
v_20257:
    goto v_20275;
v_20271:
    goto v_20285;
v_20281:
    v_20297 = v_20298;
    goto v_20282;
v_20283:
    v_20296 = elt(env, 2); // !*sq
    goto v_20284;
v_20285:
    goto v_20281;
v_20282:
    goto v_20283;
v_20284:
    if (!consp(v_20297)) goto v_20279;
    v_20297 = qcar(v_20297);
    if (v_20297 == v_20296) goto v_20278;
    else goto v_20279;
v_20278:
    v_20296 = v_20298;
    v_20296 = qcdr(v_20296);
    v_20296 = qcar(v_20296);
    fn = elt(env, 4); // prepsq
    v_20296 = (*qfn1(fn))(fn, v_20296);
    env = stack[0];
    v_20297 = v_20296;
    goto v_20277;
v_20279:
    v_20296 = v_20298;
    v_20297 = v_20296;
    goto v_20277;
    v_20297 = nil;
v_20277:
    goto v_20272;
v_20273:
    v_20296 = elt(env, 3); // "list"
    goto v_20274;
v_20275:
    goto v_20271;
v_20272:
    goto v_20273;
v_20274:
    {
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(fn, v_20297, v_20296);
    }
    v_20296 = nil;
v_20255:
    return onevalue(v_20296);
}



// Code for chkint!*

static LispObject CC_chkintH(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20359, v_20360, v_20361;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20252;
// end of prologue
    v_20359 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_20359 == nil) goto v_20257;
    v_20359 = stack[0];
    v_20359 = Lfloatp(nil, v_20359);
    env = stack[-1];
    if (v_20359 == nil) goto v_20262;
    v_20359 = stack[0];
    {
        fn = elt(env, 4); // fl2bf
        return (*qfn1(fn))(fn, v_20359);
    }
v_20262:
    v_20359 = stack[0];
    if (!consp(v_20359)) goto v_20273;
    v_20359 = stack[0];
    goto v_20271;
v_20273:
    v_20359 = stack[0];
    v_20359 = integerp(v_20359);
    if (v_20359 == nil) goto v_20277;
    goto v_20287;
v_20281:
    v_20361 = elt(env, 2); // !:rd!:
    goto v_20282;
v_20283:
    v_20360 = stack[0];
    goto v_20284;
v_20285:
    v_20359 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20286;
v_20287:
    goto v_20281;
v_20282:
    goto v_20283;
v_20284:
    goto v_20285;
v_20286:
    v_20359 = list2star(v_20361, v_20360, v_20359);
    env = stack[-1];
    goto v_20271;
v_20277:
    v_20359 = stack[0];
    fn = elt(env, 5); // read!:num
    v_20359 = (*qfn1(fn))(fn, v_20359);
    env = stack[-1];
    goto v_20271;
    v_20359 = nil;
v_20271:
    {
        fn = elt(env, 6); // normbf
        return (*qfn1(fn))(fn, v_20359);
    }
    v_20359 = nil;
    goto v_20255;
v_20257:
    v_20359 = stack[0];
    v_20359 = Labsval(nil, v_20359);
    env = stack[-1];
    v_20360 = v_20359;
    v_20359 = stack[0];
    v_20359 = Lfloatp(nil, v_20359);
    env = stack[-1];
    if (v_20359 == nil) goto v_20303;
    v_20359 = stack[0];
    goto v_20301;
v_20303:
    goto v_20314;
v_20310:
    v_20359 = v_20360;
    fn = elt(env, 7); // msd
    v_20360 = (*qfn1(fn))(fn, v_20359);
    env = stack[-1];
    goto v_20311;
v_20312:
    v_20359 = qvalue(elt(env, 3)); // !!maxbflexp
    goto v_20313;
v_20314:
    goto v_20310;
v_20311:
    goto v_20312;
v_20313:
    v_20359 = (LispObject)lesseq2(v_20360, v_20359);
    v_20359 = v_20359 ? lisp_true : nil;
    env = stack[-1];
    if (v_20359 == nil) goto v_20308;
    v_20359 = stack[0];
        return Lfloat(nil, v_20359);
v_20308:
    fn = elt(env, 8); // rndbfon
    v_20359 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_20359 = stack[0];
    v_20359 = Lfloatp(nil, v_20359);
    env = stack[-1];
    if (v_20359 == nil) goto v_20326;
    v_20359 = stack[0];
    {
        fn = elt(env, 4); // fl2bf
        return (*qfn1(fn))(fn, v_20359);
    }
v_20326:
    v_20359 = stack[0];
    if (!consp(v_20359)) goto v_20337;
    v_20359 = stack[0];
    goto v_20335;
v_20337:
    v_20359 = stack[0];
    v_20359 = integerp(v_20359);
    if (v_20359 == nil) goto v_20341;
    goto v_20351;
v_20345:
    v_20361 = elt(env, 2); // !:rd!:
    goto v_20346;
v_20347:
    v_20360 = stack[0];
    goto v_20348;
v_20349:
    v_20359 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20350;
v_20351:
    goto v_20345;
v_20346:
    goto v_20347;
v_20348:
    goto v_20349;
v_20350:
    v_20359 = list2star(v_20361, v_20360, v_20359);
    env = stack[-1];
    goto v_20335;
v_20341:
    v_20359 = stack[0];
    fn = elt(env, 5); // read!:num
    v_20359 = (*qfn1(fn))(fn, v_20359);
    env = stack[-1];
    goto v_20335;
    v_20359 = nil;
v_20335:
    {
        fn = elt(env, 6); // normbf
        return (*qfn1(fn))(fn, v_20359);
    }
    v_20359 = nil;
    goto v_20301;
    v_20359 = nil;
v_20301:
    goto v_20255;
    v_20359 = nil;
v_20255:
    return onevalue(v_20359);
}



// Code for indordl2

static LispObject CC_indordl2(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20285, v_20286;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20253;
    stack[-1] = v_20252;
// end of prologue
    goto v_20264;
v_20260:
    v_20286 = stack[-1];
    goto v_20261;
v_20262:
    v_20285 = stack[0];
    goto v_20263;
v_20264:
    goto v_20260;
v_20261:
    goto v_20262;
v_20263:
    fn = elt(env, 1); // indordlp
    v_20285 = (*qfn2(fn))(fn, v_20286, v_20285);
    if (v_20285 == nil) goto v_20258;
    goto v_20272;
v_20268:
    v_20286 = stack[-1];
    goto v_20269;
v_20270:
    v_20285 = stack[0];
    goto v_20271;
v_20272:
    goto v_20268;
v_20269:
    goto v_20270;
v_20271:
    return list2(v_20286, v_20285);
v_20258:
    goto v_20282;
v_20278:
    v_20286 = stack[0];
    goto v_20279;
v_20280:
    v_20285 = stack[-1];
    goto v_20281;
v_20282:
    goto v_20278;
v_20279:
    goto v_20280;
v_20281:
    return list2(v_20286, v_20285);
    v_20285 = nil;
    return onevalue(v_20285);
}



// Code for liennewstruc

static LispObject CC_liennewstruc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21021, v_21022, v_21023, v_21024;
    LispObject fn;
    LispObject v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "liennewstruc");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20254,v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20252,v_20253,v_20254);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-12] = v_20254;
    stack[-13] = v_20253;
    stack[-14] = v_20252;
// end of prologue
    goto v_20268;
v_20262:
    v_21023 = elt(env, 1); // lie_a
    goto v_20263;
v_20264:
    v_21022 = stack[-14];
    goto v_20265;
v_20266:
    v_21021 = stack[-14];
    goto v_20267;
v_20268:
    goto v_20262;
v_20263:
    goto v_20264;
v_20265:
    goto v_20266;
v_20267:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    v_21021 = ncons(v_21021);
    env = stack[-16];
    fn = elt(env, 11); // matrix
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20277;
v_20273:
    stack[0] = elt(env, 1); // lie_a
    goto v_20274;
v_20275:
    goto v_20287;
v_20281:
    v_21023 = elt(env, 2); // expt
    goto v_20282;
v_20283:
    v_21022 = elt(env, 1); // lie_a
    goto v_20284;
v_20285:
    v_21021 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20286;
v_20287:
    goto v_20281;
v_20282:
    goto v_20283;
v_20284:
    goto v_20285;
v_20286:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20276;
v_20277:
    goto v_20273;
v_20274:
    goto v_20275;
v_20276:
    fn = elt(env, 13); // setk
    v_21021 = (*qfn2(fn))(fn, stack[0], v_21021);
    env = stack[-16];
    v_21021 = stack[-13];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-15] = v_21021;
v_20294:
    goto v_20309;
v_20303:
    stack[0] = elt(env, 3); // difference
    goto v_20304;
v_20305:
    goto v_20319;
v_20313:
    v_21023 = elt(env, 3); // difference
    goto v_20314;
v_20315:
    v_21022 = stack[-14];
    goto v_20316;
v_20317:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20318;
v_20319:
    goto v_20313;
v_20314:
    goto v_20315;
v_20316:
    goto v_20317;
v_20318:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20306;
v_20307:
    v_21021 = stack[-15];
    goto v_20308;
v_20309:
    goto v_20303;
v_20304:
    goto v_20305;
v_20306:
    goto v_20307;
v_20308:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20300;
    goto v_20293;
v_20300:
    goto v_20337;
v_20331:
    v_21023 = elt(env, 4); // plus
    goto v_20332;
v_20333:
    v_21022 = stack[-15];
    goto v_20334;
v_20335:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20336;
v_20337:
    goto v_20331;
v_20332:
    goto v_20333;
v_20334:
    goto v_20335;
v_20336:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-11] = v_21021;
v_20328:
    goto v_20353;
v_20347:
    stack[0] = elt(env, 3); // difference
    goto v_20348;
v_20349:
    v_21021 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20350;
v_20351:
    v_21021 = stack[-11];
    goto v_20352;
v_20353:
    goto v_20347;
v_20348:
    goto v_20349;
v_20350:
    goto v_20351;
v_20352:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20344;
    goto v_20327;
v_20344:
    goto v_20364;
v_20360:
    goto v_20372;
v_20366:
    v_21023 = elt(env, 5); // lie_lamb
    goto v_20367;
v_20368:
    v_21022 = stack[-15];
    goto v_20369;
v_20370:
    v_21021 = stack[-11];
    goto v_20371;
v_20372:
    goto v_20366;
v_20367:
    goto v_20368;
v_20369:
    goto v_20370;
v_20371:
    stack[-10] = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20361;
v_20362:
    goto v_20384;
v_20378:
    stack[-9] = elt(env, 6); // quotient
    goto v_20379;
v_20380:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_21021;
    v_21021 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_21021;
v_20390:
    goto v_20405;
v_20399:
    stack[0] = elt(env, 3); // difference
    goto v_20400;
v_20401:
    v_21021 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20402;
v_20403:
    v_21021 = stack[-8];
    goto v_20404;
v_20405:
    goto v_20399;
v_20400:
    goto v_20401;
v_20402:
    goto v_20403;
v_20404:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20396;
    v_21021 = stack[-7];
    stack[0] = v_21021;
    goto v_20389;
v_20396:
    goto v_20419;
v_20413:
    stack[-6] = elt(env, 4); // plus
    goto v_20414;
v_20415:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21021;
    v_21021 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_21021;
v_20425:
    goto v_20440;
v_20434:
    stack[0] = elt(env, 3); // difference
    goto v_20435;
v_20436:
    v_21021 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20437;
v_20438:
    v_21021 = stack[-5];
    goto v_20439;
v_20440:
    goto v_20434;
v_20435:
    goto v_20436;
v_20437:
    goto v_20438;
v_20439:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20431;
    v_21021 = stack[-4];
    v_21022 = v_21021;
    goto v_20424;
v_20431:
    goto v_20454;
v_20448:
    stack[-3] = elt(env, 4); // plus
    goto v_20449;
v_20450:
    goto v_20466;
v_20458:
    stack[-2] = elt(env, 7); // times
    goto v_20459;
v_20460:
    goto v_20475;
v_20469:
    v_21023 = elt(env, 8); // lientrans
    goto v_20470;
v_20471:
    v_21022 = stack[-15];
    goto v_20472;
v_20473:
    v_21021 = stack[-8];
    goto v_20474;
v_20475:
    goto v_20469;
v_20470:
    goto v_20471;
v_20472:
    goto v_20473;
v_20474:
    stack[-1] = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20461;
v_20462:
    goto v_20486;
v_20480:
    v_21023 = elt(env, 8); // lientrans
    goto v_20481;
v_20482:
    v_21022 = stack[-11];
    goto v_20483;
v_20484:
    v_21021 = stack[-5];
    goto v_20485;
v_20486:
    goto v_20480;
v_20481:
    goto v_20482;
v_20483:
    goto v_20484;
v_20485:
    stack[0] = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20463;
v_20464:
    goto v_20499;
v_20491:
    v_21024 = elt(env, 9); // lie_cc
    goto v_20492;
v_20493:
    v_21023 = stack[-8];
    goto v_20494;
v_20495:
    v_21022 = stack[-5];
    goto v_20496;
v_20497:
    v_21021 = stack[-12];
    goto v_20498;
v_20499:
    goto v_20491;
v_20492:
    goto v_20493;
v_20494:
    goto v_20495;
v_20496:
    goto v_20497;
v_20498:
    v_21021 = list4(v_21024, v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20465;
v_20466:
    goto v_20458;
v_20459:
    goto v_20460;
v_20461:
    goto v_20462;
v_20463:
    goto v_20464;
v_20465:
    v_21021 = list4(stack[-2], stack[-1], stack[0], v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20451;
v_20452:
    v_21021 = stack[-4];
    goto v_20453;
v_20454:
    goto v_20448;
v_20449:
    goto v_20450;
v_20451:
    goto v_20452;
v_20453:
    v_21021 = list3(stack[-3], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-4] = v_21021;
    v_21021 = stack[-5];
    goto v_20515;
v_20509:
    v_21023 = elt(env, 4); // plus
    goto v_20510;
v_20511:
    v_21022 = v_21021;
    goto v_20512;
v_20513:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20514;
v_20515:
    goto v_20509;
v_20510:
    goto v_20511;
v_20512:
    goto v_20513;
v_20514:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-5] = v_21021;
    goto v_20425;
v_20424:
    goto v_20416;
v_20417:
    v_21021 = stack[-7];
    goto v_20418;
v_20419:
    goto v_20413;
v_20414:
    goto v_20415;
v_20416:
    goto v_20417;
v_20418:
    v_21021 = list3(stack[-6], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-7] = v_21021;
    v_21021 = stack[-8];
    goto v_20530;
v_20524:
    v_21023 = elt(env, 4); // plus
    goto v_20525;
v_20526:
    v_21022 = v_21021;
    goto v_20527;
v_20528:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20529;
v_20530:
    goto v_20524;
v_20525:
    goto v_20526;
v_20527:
    goto v_20528;
v_20529:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-8] = v_21021;
    goto v_20390;
v_20389:
    goto v_20381;
v_20382:
    goto v_20541;
v_20535:
    v_21023 = elt(env, 8); // lientrans
    goto v_20536;
v_20537:
    v_21022 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20538;
v_20539:
    v_21021 = stack[-12];
    goto v_20540;
v_20541:
    goto v_20535;
v_20536:
    goto v_20537;
v_20538:
    goto v_20539;
v_20540:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20383;
v_20384:
    goto v_20378;
v_20379:
    goto v_20380;
v_20381:
    goto v_20382;
v_20383:
    v_21021 = list3(stack[-9], stack[0], v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20363;
v_20364:
    goto v_20360;
v_20361:
    goto v_20362;
v_20363:
    fn = elt(env, 13); // setk
    v_21021 = (*qfn2(fn))(fn, stack[-10], v_21021);
    env = stack[-16];
    v_21021 = stack[-11];
    goto v_20555;
v_20549:
    v_21023 = elt(env, 4); // plus
    goto v_20550;
v_20551:
    v_21022 = v_21021;
    goto v_20552;
v_20553:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20554;
v_20555:
    goto v_20549;
v_20550:
    goto v_20551;
v_20552:
    goto v_20553;
v_20554:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-11] = v_21021;
    goto v_20328;
v_20327:
    v_21021 = stack[-15];
    goto v_20569;
v_20563:
    v_21023 = elt(env, 4); // plus
    goto v_20564;
v_20565:
    v_21022 = v_21021;
    goto v_20566;
v_20567:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20568;
v_20569:
    goto v_20563;
v_20564:
    goto v_20565;
v_20566:
    goto v_20567;
v_20568:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-15] = v_21021;
    goto v_20294;
v_20293:
    goto v_20585;
v_20579:
    v_21023 = elt(env, 4); // plus
    goto v_20580;
v_20581:
    v_21022 = stack[-13];
    goto v_20582;
v_20583:
    v_21021 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20584;
v_20585:
    goto v_20579;
v_20580:
    goto v_20581;
v_20582:
    goto v_20583;
v_20584:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-2] = v_21021;
v_20576:
    goto v_20601;
v_20595:
    stack[0] = elt(env, 3); // difference
    goto v_20596;
v_20597:
    v_21021 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20598;
v_20599:
    v_21021 = stack[-2];
    goto v_20600;
v_20601:
    goto v_20595;
v_20596:
    goto v_20597;
v_20598:
    goto v_20599;
v_20600:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20592;
    goto v_20575;
v_20592:
    goto v_20612;
v_20608:
    goto v_20620;
v_20614:
    stack[-1] = elt(env, 1); // lie_a
    goto v_20615;
v_20616:
    stack[0] = stack[-2];
    goto v_20617;
v_20618:
    goto v_20630;
v_20624:
    v_21023 = elt(env, 4); // plus
    goto v_20625;
v_20626:
    v_21022 = stack[-13];
    goto v_20627;
v_20628:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20629;
v_20630:
    goto v_20624;
v_20625:
    goto v_20626;
v_20627:
    goto v_20628;
v_20629:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20619;
v_20620:
    goto v_20614;
v_20615:
    goto v_20616;
v_20617:
    goto v_20618;
v_20619:
    stack[-1] = list3(stack[-1], stack[0], v_21021);
    env = stack[-16];
    goto v_20609;
v_20610:
    goto v_20640;
v_20636:
    stack[0] = elt(env, 10); // minus
    goto v_20637;
v_20638:
    goto v_20649;
v_20643:
    v_21023 = elt(env, 5); // lie_lamb
    goto v_20644;
v_20645:
    v_21022 = stack[-13];
    goto v_20646;
v_20647:
    v_21021 = stack[-2];
    goto v_20648;
v_20649:
    goto v_20643;
v_20644:
    goto v_20645;
v_20646:
    goto v_20647;
v_20648:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20639;
v_20640:
    goto v_20636;
v_20637:
    goto v_20638;
v_20639:
    v_21021 = list2(stack[0], v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20611;
v_20612:
    goto v_20608;
v_20609:
    goto v_20610;
v_20611:
    fn = elt(env, 13); // setk
    v_21021 = (*qfn2(fn))(fn, stack[-1], v_21021);
    env = stack[-16];
    goto v_20658;
v_20654:
    goto v_20666;
v_20660:
    v_21023 = elt(env, 1); // lie_a
    goto v_20661;
v_20662:
    v_21022 = stack[-2];
    goto v_20663;
v_20664:
    v_21021 = stack[-13];
    goto v_20665;
v_20666:
    goto v_20660;
v_20661:
    goto v_20662;
v_20663:
    goto v_20664;
v_20665:
    stack[-1] = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20655;
v_20656:
    goto v_20678;
v_20672:
    stack[0] = elt(env, 5); // lie_lamb
    goto v_20673;
v_20674:
    goto v_20687;
v_20681:
    v_21023 = elt(env, 4); // plus
    goto v_20682;
v_20683:
    v_21022 = stack[-13];
    goto v_20684;
v_20685:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20686;
v_20687:
    goto v_20681;
v_20682:
    goto v_20683;
v_20684:
    goto v_20685;
v_20686:
    v_21022 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20675;
v_20676:
    v_21021 = stack[-2];
    goto v_20677;
v_20678:
    goto v_20672;
v_20673:
    goto v_20674;
v_20675:
    goto v_20676;
v_20677:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20657;
v_20658:
    goto v_20654;
v_20655:
    goto v_20656;
v_20657:
    fn = elt(env, 13); // setk
    v_21021 = (*qfn2(fn))(fn, stack[-1], v_21021);
    env = stack[-16];
    v_21021 = stack[-2];
    goto v_20702;
v_20696:
    v_21023 = elt(env, 4); // plus
    goto v_20697;
v_20698:
    v_21022 = v_21021;
    goto v_20699;
v_20700:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20701;
v_20702:
    goto v_20696;
v_20697:
    goto v_20698;
v_20699:
    goto v_20700;
v_20701:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-2] = v_21021;
    goto v_20576;
v_20575:
    goto v_20711;
v_20707:
    stack[0] = elt(env, 8); // lientrans
    goto v_20708;
v_20709:
    goto v_20721;
v_20715:
    v_21023 = elt(env, 7); // times
    goto v_20716;
v_20717:
    v_21022 = elt(env, 1); // lie_a
    goto v_20718;
v_20719:
    v_21021 = elt(env, 8); // lientrans
    goto v_20720;
v_20721:
    goto v_20715;
v_20716:
    goto v_20717;
v_20718:
    goto v_20719;
v_20720:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20710;
v_20711:
    goto v_20707;
v_20708:
    goto v_20709;
v_20710:
    fn = elt(env, 13); // setk
    v_21021 = (*qfn2(fn))(fn, stack[0], v_21021);
    env = stack[-16];
    goto v_20737;
v_20731:
    v_21023 = elt(env, 4); // plus
    goto v_20732;
v_20733:
    v_21022 = stack[-13];
    goto v_20734;
v_20735:
    v_21021 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20736;
v_20737:
    goto v_20731;
v_20732:
    goto v_20733;
v_20734:
    goto v_20735;
v_20736:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-13] = v_21021;
v_20728:
    goto v_20753;
v_20747:
    stack[0] = elt(env, 3); // difference
    goto v_20748;
v_20749:
    goto v_20763;
v_20757:
    v_21023 = elt(env, 3); // difference
    goto v_20758;
v_20759:
    v_21022 = stack[-14];
    goto v_20760;
v_20761:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20762;
v_20763:
    goto v_20757;
v_20758:
    goto v_20759;
v_20760:
    goto v_20761;
v_20762:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20750;
v_20751:
    v_21021 = stack[-13];
    goto v_20752;
v_20753:
    goto v_20747;
v_20748:
    goto v_20749;
v_20750:
    goto v_20751;
v_20752:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20744;
    goto v_20727;
v_20744:
    goto v_20781;
v_20775:
    v_21023 = elt(env, 4); // plus
    goto v_20776;
v_20777:
    v_21022 = stack[-13];
    goto v_20778;
v_20779:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20780;
v_20781:
    goto v_20775;
v_20776:
    goto v_20777;
v_20778:
    goto v_20779;
v_20780:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-11] = v_21021;
v_20772:
    goto v_20797;
v_20791:
    stack[0] = elt(env, 3); // difference
    goto v_20792;
v_20793:
    v_21021 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20794;
v_20795:
    v_21021 = stack[-11];
    goto v_20796;
v_20797:
    goto v_20791;
v_20792:
    goto v_20793;
v_20794:
    goto v_20795;
v_20796:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20788;
    goto v_20771;
v_20788:
    goto v_20808;
v_20804:
    goto v_20816;
v_20810:
    v_21023 = elt(env, 5); // lie_lamb
    goto v_20811;
v_20812:
    v_21022 = stack[-13];
    goto v_20813;
v_20814:
    v_21021 = stack[-11];
    goto v_20815;
v_20816:
    goto v_20810;
v_20811:
    goto v_20812;
v_20813:
    goto v_20814;
v_20815:
    stack[-10] = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20805;
v_20806:
    goto v_20828;
v_20822:
    stack[-9] = elt(env, 6); // quotient
    goto v_20823;
v_20824:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_21021;
    v_21021 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_21021;
v_20834:
    goto v_20849;
v_20843:
    stack[0] = elt(env, 3); // difference
    goto v_20844;
v_20845:
    v_21021 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20846;
v_20847:
    v_21021 = stack[-8];
    goto v_20848;
v_20849:
    goto v_20843;
v_20844:
    goto v_20845;
v_20846:
    goto v_20847;
v_20848:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20840;
    v_21021 = stack[-7];
    stack[0] = v_21021;
    goto v_20833;
v_20840:
    goto v_20863;
v_20857:
    stack[-6] = elt(env, 4); // plus
    goto v_20858;
v_20859:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21021;
    v_21021 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_21021;
v_20869:
    goto v_20884;
v_20878:
    stack[0] = elt(env, 3); // difference
    goto v_20879;
v_20880:
    v_21021 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20881;
v_20882:
    v_21021 = stack[-5];
    goto v_20883;
v_20884:
    goto v_20878;
v_20879:
    goto v_20880;
v_20881:
    goto v_20882;
v_20883:
    v_21021 = list3(stack[0], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    if (v_21021 == nil) goto v_20875;
    v_21021 = stack[-4];
    v_21022 = v_21021;
    goto v_20868;
v_20875:
    goto v_20898;
v_20892:
    stack[-3] = elt(env, 4); // plus
    goto v_20893;
v_20894:
    goto v_20910;
v_20902:
    stack[-2] = elt(env, 7); // times
    goto v_20903;
v_20904:
    goto v_20919;
v_20913:
    v_21023 = elt(env, 8); // lientrans
    goto v_20914;
v_20915:
    v_21022 = stack[-13];
    goto v_20916;
v_20917:
    v_21021 = stack[-8];
    goto v_20918;
v_20919:
    goto v_20913;
v_20914:
    goto v_20915;
v_20916:
    goto v_20917;
v_20918:
    stack[-1] = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20905;
v_20906:
    goto v_20930;
v_20924:
    v_21023 = elt(env, 8); // lientrans
    goto v_20925;
v_20926:
    v_21022 = stack[-11];
    goto v_20927;
v_20928:
    v_21021 = stack[-5];
    goto v_20929;
v_20930:
    goto v_20924;
v_20925:
    goto v_20926;
v_20927:
    goto v_20928;
v_20929:
    stack[0] = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20907;
v_20908:
    goto v_20943;
v_20935:
    v_21024 = elt(env, 9); // lie_cc
    goto v_20936;
v_20937:
    v_21023 = stack[-8];
    goto v_20938;
v_20939:
    v_21022 = stack[-5];
    goto v_20940;
v_20941:
    v_21021 = stack[-12];
    goto v_20942;
v_20943:
    goto v_20935;
v_20936:
    goto v_20937;
v_20938:
    goto v_20939;
v_20940:
    goto v_20941;
v_20942:
    v_21021 = list4(v_21024, v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20909;
v_20910:
    goto v_20902;
v_20903:
    goto v_20904;
v_20905:
    goto v_20906;
v_20907:
    goto v_20908;
v_20909:
    v_21021 = list4(stack[-2], stack[-1], stack[0], v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21022 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20895;
v_20896:
    v_21021 = stack[-4];
    goto v_20897;
v_20898:
    goto v_20892;
v_20893:
    goto v_20894;
v_20895:
    goto v_20896;
v_20897:
    v_21021 = list3(stack[-3], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-4] = v_21021;
    v_21021 = stack[-5];
    goto v_20959;
v_20953:
    v_21023 = elt(env, 4); // plus
    goto v_20954;
v_20955:
    v_21022 = v_21021;
    goto v_20956;
v_20957:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20958;
v_20959:
    goto v_20953;
v_20954:
    goto v_20955;
v_20956:
    goto v_20957;
v_20958:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-5] = v_21021;
    goto v_20869;
v_20868:
    goto v_20860;
v_20861:
    v_21021 = stack[-7];
    goto v_20862;
v_20863:
    goto v_20857;
v_20858:
    goto v_20859;
v_20860:
    goto v_20861;
v_20862:
    v_21021 = list3(stack[-6], v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-7] = v_21021;
    v_21021 = stack[-8];
    goto v_20974;
v_20968:
    v_21023 = elt(env, 4); // plus
    goto v_20969;
v_20970:
    v_21022 = v_21021;
    goto v_20971;
v_20972:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20973;
v_20974:
    goto v_20968;
v_20969:
    goto v_20970;
v_20971:
    goto v_20972;
v_20973:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-8] = v_21021;
    goto v_20834;
v_20833:
    goto v_20825;
v_20826:
    goto v_20985;
v_20979:
    v_21023 = elt(env, 8); // lientrans
    goto v_20980;
v_20981:
    v_21022 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20982;
v_20983:
    v_21021 = stack[-12];
    goto v_20984;
v_20985:
    goto v_20979;
v_20980:
    goto v_20981;
v_20982:
    goto v_20983;
v_20984:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    goto v_20827;
v_20828:
    goto v_20822;
v_20823:
    goto v_20824;
v_20825:
    goto v_20826;
v_20827:
    v_21021 = list3(stack[-9], stack[0], v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    goto v_20807;
v_20808:
    goto v_20804;
v_20805:
    goto v_20806;
v_20807:
    fn = elt(env, 13); // setk
    v_21021 = (*qfn2(fn))(fn, stack[-10], v_21021);
    env = stack[-16];
    v_21021 = stack[-11];
    goto v_20999;
v_20993:
    v_21023 = elt(env, 4); // plus
    goto v_20994;
v_20995:
    v_21022 = v_21021;
    goto v_20996;
v_20997:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20998;
v_20999:
    goto v_20993;
v_20994:
    goto v_20995;
v_20996:
    goto v_20997;
v_20998:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-11] = v_21021;
    goto v_20772;
v_20771:
    v_21021 = stack[-13];
    goto v_21013;
v_21007:
    v_21023 = elt(env, 4); // plus
    goto v_21008;
v_21009:
    v_21022 = v_21021;
    goto v_21010;
v_21011:
    v_21021 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21012;
v_21013:
    goto v_21007;
v_21008:
    goto v_21009;
v_21010:
    goto v_21011;
v_21012:
    v_21021 = list3(v_21023, v_21022, v_21021);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    stack[-13] = v_21021;
    goto v_20728;
v_20727:
    v_21021 = elt(env, 1); // lie_a
    v_21021 = ncons(v_21021);
    env = stack[-16];
    fn = elt(env, 16); // clear
    v_21021 = (*qfn1(fn))(fn, v_21021);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_21021 = (*qfn1(fn))(fn, v_21021);
    v_21021 = nil;
    return onevalue(v_21021);
}



// Code for listsub

static LispObject CC_listsub(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20311, v_20312;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_20311 = v_20253;
    stack[-3] = v_20252;
// end of prologue
    v_20311 = qcdr(v_20311);
    stack[-4] = v_20311;
    v_20311 = stack[-4];
    if (v_20311 == nil) goto v_20266;
    else goto v_20267;
v_20266:
    v_20311 = nil;
    goto v_20260;
v_20267:
    v_20311 = stack[-4];
    v_20311 = qcar(v_20311);
    goto v_20279;
v_20275:
    v_20312 = stack[-3];
    goto v_20276;
v_20277:
    goto v_20278;
v_20279:
    goto v_20275;
v_20276:
    goto v_20277;
v_20278:
    fn = elt(env, 1); // subeval1
    v_20311 = (*qfn2(fn))(fn, v_20312, v_20311);
    env = stack[-5];
    v_20311 = ncons(v_20311);
    env = stack[-5];
    stack[-1] = v_20311;
    stack[-2] = v_20311;
v_20261:
    v_20311 = stack[-4];
    v_20311 = qcdr(v_20311);
    stack[-4] = v_20311;
    v_20311 = stack[-4];
    if (v_20311 == nil) goto v_20286;
    else goto v_20287;
v_20286:
    v_20311 = stack[-2];
    goto v_20260;
v_20287:
    goto v_20295;
v_20291:
    stack[0] = stack[-1];
    goto v_20292;
v_20293:
    v_20311 = stack[-4];
    v_20311 = qcar(v_20311);
    goto v_20306;
v_20302:
    v_20312 = stack[-3];
    goto v_20303;
v_20304:
    goto v_20305;
v_20306:
    goto v_20302;
v_20303:
    goto v_20304;
v_20305:
    fn = elt(env, 1); // subeval1
    v_20311 = (*qfn2(fn))(fn, v_20312, v_20311);
    env = stack[-5];
    v_20311 = ncons(v_20311);
    env = stack[-5];
    goto v_20294;
v_20295:
    goto v_20291;
v_20292:
    goto v_20293;
v_20294:
    v_20311 = Lrplacd(nil, stack[0], v_20311);
    env = stack[-5];
    v_20311 = stack[-1];
    v_20311 = qcdr(v_20311);
    stack[-1] = v_20311;
    goto v_20261;
v_20260:
    {
        fn = elt(env, 2); // makelist
        return (*qfn1(fn))(fn, v_20311);
    }
}



// Code for mo!=zero

static LispObject CC_moMzero(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20280, v_20281, v_20282;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20281 = v_20252;
// end of prologue
v_20251:
    v_20280 = v_20281;
    if (v_20280 == nil) goto v_20256;
    else goto v_20257;
v_20256:
    v_20280 = lisp_true;
    goto v_20255;
v_20257:
    goto v_20270;
v_20266:
    v_20280 = v_20281;
    v_20282 = qcar(v_20280);
    goto v_20267;
v_20268:
    v_20280 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20269;
v_20270:
    goto v_20266;
v_20267:
    goto v_20268;
v_20269:
    if (v_20282 == v_20280) goto v_20264;
    else goto v_20265;
v_20264:
    v_20280 = v_20281;
    v_20280 = qcdr(v_20280);
    v_20281 = v_20280;
    goto v_20251;
v_20265:
    v_20280 = nil;
    goto v_20263;
    v_20280 = nil;
v_20263:
    goto v_20255;
    v_20280 = nil;
v_20255:
    return onevalue(v_20280);
}



// Code for lalr_get_lex_codes

static LispObject CC_lalr_get_lex_codes(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20298, v_20299;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20298 = v_20252;
// end of prologue
    stack[-1] = nil;
    stack[0] = v_20298;
v_20262:
    v_20298 = stack[0];
    if (v_20298 == nil) goto v_20266;
    else goto v_20267;
v_20266:
    goto v_20261;
v_20267:
    v_20298 = stack[0];
    v_20298 = qcar(v_20298);
    v_20299 = v_20298;
    v_20298 = v_20299;
    v_20298 = Lstringp(nil, v_20298);
    env = stack[-2];
    if (v_20298 == nil) goto v_20276;
    goto v_20284;
v_20280:
    goto v_20281;
v_20282:
    v_20298 = stack[-1];
    goto v_20283;
v_20284:
    goto v_20280;
v_20281:
    goto v_20282;
v_20283:
    v_20298 = cons(v_20299, v_20298);
    env = stack[-2];
    stack[-1] = v_20298;
    goto v_20274;
v_20276:
v_20274:
    v_20298 = stack[0];
    v_20298 = qcdr(v_20298);
    stack[0] = v_20298;
    goto v_20262;
v_20261:
    fn = elt(env, 2); // lex_save_context
    v_20298 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_20298;
    fn = elt(env, 3); // lex_cleanup
    v_20298 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_20298 = stack[-1];
    fn = elt(env, 4); // lex_keywords
    v_20298 = (*qfn1(fn))(fn, v_20298);
    env = stack[-2];
    fn = elt(env, 2); // lex_save_context
    v_20298 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_20298; // lex_context
    fn = elt(env, 5); // lex_export_codes
    v_20298 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_20298;
    v_20298 = stack[0];
    fn = elt(env, 6); // lex_restore_context
    v_20298 = (*qfn1(fn))(fn, v_20298);
    v_20298 = stack[-1];
    return onevalue(v_20298);
}



// Code for polynomcompare

static LispObject CC_polynomcompare(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20339, v_20340, v_20341;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20340 = v_20253;
    v_20339 = v_20252;
// end of prologue
    stack[-1] = v_20339;
    v_20339 = v_20340;
    stack[0] = v_20339;
v_20265:
    v_20339 = stack[-1];
    v_20339 = qcar(v_20339);
    if (v_20339 == nil) goto v_20268;
    v_20339 = stack[0];
    v_20339 = qcar(v_20339);
    if (v_20339 == nil) goto v_20268;
    goto v_20269;
v_20268:
    goto v_20264;
v_20269:
    goto v_20282;
v_20278:
    v_20339 = stack[-1];
    v_20340 = qcar(v_20339);
    goto v_20279;
v_20280:
    v_20339 = stack[0];
    v_20339 = qcar(v_20339);
    goto v_20281;
v_20282:
    goto v_20278;
v_20279:
    goto v_20280;
v_20281:
    fn = elt(env, 1); // monomcompare
    v_20339 = (*qfn2(fn))(fn, v_20340, v_20339);
    env = stack[-2];
    v_20341 = v_20339;
    goto v_20295;
v_20291:
    v_20340 = v_20341;
    goto v_20292;
v_20293:
    v_20339 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20294;
v_20295:
    goto v_20291;
v_20292:
    goto v_20293;
v_20294:
    if (v_20340 == v_20339) goto v_20289;
    else goto v_20290;
v_20289:
    v_20339 = nil;
    v_20339 = ncons(v_20339);
    env = stack[-2];
    stack[0] = v_20339;
    goto v_20288;
v_20290:
    goto v_20307;
v_20303:
    v_20340 = v_20341;
    goto v_20304;
v_20305:
    v_20339 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20306;
v_20307:
    goto v_20303;
v_20304:
    goto v_20305;
v_20306:
    if (v_20340 == v_20339) goto v_20301;
    else goto v_20302;
v_20301:
    v_20339 = nil;
    v_20339 = ncons(v_20339);
    env = stack[-2];
    stack[-1] = v_20339;
    goto v_20288;
v_20302:
    v_20339 = stack[-1];
    v_20339 = qcdr(v_20339);
    stack[-1] = v_20339;
    v_20339 = stack[0];
    v_20339 = qcdr(v_20339);
    stack[0] = v_20339;
    goto v_20288;
v_20288:
    goto v_20265;
v_20264:
    v_20339 = stack[-1];
    v_20339 = qcar(v_20339);
    if (v_20339 == nil) goto v_20324;
    v_20339 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20259;
v_20324:
    v_20339 = stack[0];
    v_20339 = qcar(v_20339);
    if (v_20339 == nil) goto v_20330;
    v_20339 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20259;
v_20330:
    v_20339 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20259;
    v_20339 = nil;
v_20259:
    return onevalue(v_20339);
}



// Code for maxfrom1

static LispObject CC_maxfrom1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20286, v_20287;
    LispObject fn;
    LispObject v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "maxfrom1");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20254,v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20252,v_20253,v_20254);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20254;
    stack[-1] = v_20253;
    stack[-2] = v_20252;
// end of prologue
v_20258:
    v_20286 = stack[-2];
    if (v_20286 == nil) goto v_20261;
    else goto v_20262;
v_20261:
    v_20286 = stack[0];
    goto v_20257;
v_20262:
    goto v_20272;
v_20268:
    goto v_20278;
v_20274:
    v_20286 = stack[-2];
    v_20286 = qcar(v_20286);
    v_20287 = qcar(v_20286);
    goto v_20275;
v_20276:
    v_20286 = stack[-1];
    goto v_20277;
v_20278:
    goto v_20274;
v_20275:
    goto v_20276;
v_20277:
    fn = elt(env, 1); // nth
    v_20287 = (*qfn2(fn))(fn, v_20287, v_20286);
    env = stack[-3];
    goto v_20269;
v_20270:
    v_20286 = stack[0];
    goto v_20271;
v_20272:
    goto v_20268;
v_20269:
    goto v_20270;
v_20271:
    fn = elt(env, 2); // max
    v_20286 = (*qfn2(fn))(fn, v_20287, v_20286);
    env = stack[-3];
    stack[0] = v_20286;
    v_20286 = stack[-2];
    v_20286 = qcdr(v_20286);
    stack[-2] = v_20286;
    goto v_20258;
    v_20286 = nil;
v_20257:
    return onevalue(v_20286);
}



// Code for get!-denom!-l

static LispObject CC_getKdenomKl(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20304, v_20305, v_20306;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20305 = v_20252;
// end of prologue
    v_20304 = v_20305;
    v_20304 = qcar(v_20304);
    if (!consp(v_20304)) goto v_20256;
    else goto v_20257;
v_20256:
    v_20304 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20255;
v_20257:
    v_20304 = v_20305;
    v_20304 = qcar(v_20304);
    v_20304 = qcdr(v_20304);
    v_20304 = qcdr(v_20304);
    goto v_20255;
    v_20304 = nil;
v_20255:
    v_20305 = qcdr(v_20305);
    stack[0] = v_20305;
v_20271:
    v_20305 = stack[0];
    if (v_20305 == nil) goto v_20276;
    else goto v_20277;
v_20276:
    goto v_20270;
v_20277:
    v_20305 = stack[0];
    v_20305 = qcar(v_20305);
    v_20306 = v_20305;
    goto v_20288;
v_20284:
    v_20305 = v_20304;
    goto v_20285;
v_20286:
    v_20304 = v_20306;
    if (!consp(v_20304)) goto v_20292;
    else goto v_20293;
v_20292:
    v_20304 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20291;
v_20293:
    v_20304 = v_20306;
    v_20304 = qcdr(v_20304);
    v_20304 = qcdr(v_20304);
    goto v_20291;
    v_20304 = nil;
v_20291:
    goto v_20287;
v_20288:
    goto v_20284;
v_20285:
    goto v_20286;
v_20287:
    fn = elt(env, 1); // lcmn
    v_20304 = (*qfn2(fn))(fn, v_20305, v_20304);
    env = stack[-1];
    v_20305 = stack[0];
    v_20305 = qcdr(v_20305);
    stack[0] = v_20305;
    goto v_20271;
v_20270:
    return onevalue(v_20304);
}



// Code for mk!+real!+inner!+product

static LispObject CC_mkLrealLinnerLproduct(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20338, v_20339;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_20253;
    stack[-3] = v_20252;
// end of prologue
    goto v_20267;
v_20263:
    v_20338 = stack[-3];
    fn = elt(env, 3); // get!+vec!+dim
    stack[0] = (*qfn1(fn))(fn, v_20338);
    env = stack[-5];
    goto v_20264;
v_20265:
    v_20338 = stack[-2];
    fn = elt(env, 3); // get!+vec!+dim
    v_20338 = (*qfn1(fn))(fn, v_20338);
    env = stack[-5];
    goto v_20266;
v_20267:
    goto v_20263;
v_20264:
    goto v_20265;
v_20266:
    if (equal(stack[0], v_20338)) goto v_20262;
    v_20338 = elt(env, 1); // "wrong dimensions in innerproduct"
    fn = elt(env, 4); // rederr
    v_20338 = (*qfn1(fn))(fn, v_20338);
    env = stack[-5];
    goto v_20260;
v_20262:
v_20260:
    goto v_20279;
v_20275:
    v_20339 = nil;
    goto v_20276;
v_20277:
    v_20338 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20278;
v_20279:
    goto v_20275;
v_20276:
    goto v_20277;
v_20278:
    v_20338 = cons(v_20339, v_20338);
    env = stack[-5];
    stack[0] = v_20338;
    v_20338 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_20338;
v_20285:
    goto v_20297;
v_20293:
    v_20338 = stack[-3];
    fn = elt(env, 3); // get!+vec!+dim
    v_20339 = (*qfn1(fn))(fn, v_20338);
    env = stack[-5];
    goto v_20294;
v_20295:
    v_20338 = stack[-4];
    goto v_20296;
v_20297:
    goto v_20293;
v_20294:
    goto v_20295;
v_20296:
    v_20338 = difference2(v_20339, v_20338);
    env = stack[-5];
    v_20338 = Lminusp(nil, v_20338);
    env = stack[-5];
    if (v_20338 == nil) goto v_20290;
    goto v_20284;
v_20290:
    goto v_20307;
v_20303:
    stack[-1] = stack[0];
    goto v_20304;
v_20305:
    goto v_20314;
v_20310:
    goto v_20320;
v_20316:
    v_20339 = stack[-3];
    goto v_20317;
v_20318:
    v_20338 = stack[-4];
    goto v_20319;
v_20320:
    goto v_20316;
v_20317:
    goto v_20318;
v_20319:
    fn = elt(env, 5); // get!+vec!+entry
    stack[0] = (*qfn2(fn))(fn, v_20339, v_20338);
    env = stack[-5];
    goto v_20311;
v_20312:
    goto v_20328;
v_20324:
    v_20339 = stack[-2];
    goto v_20325;
v_20326:
    v_20338 = stack[-4];
    goto v_20327;
v_20328:
    goto v_20324;
v_20325:
    goto v_20326;
v_20327:
    fn = elt(env, 5); // get!+vec!+entry
    v_20338 = (*qfn2(fn))(fn, v_20339, v_20338);
    env = stack[-5];
    goto v_20313;
v_20314:
    goto v_20310;
v_20311:
    goto v_20312;
v_20313:
    fn = elt(env, 6); // multsq
    v_20338 = (*qfn2(fn))(fn, stack[0], v_20338);
    env = stack[-5];
    goto v_20306;
v_20307:
    goto v_20303;
v_20304:
    goto v_20305;
v_20306:
    fn = elt(env, 7); // addsq
    v_20338 = (*qfn2(fn))(fn, stack[-1], v_20338);
    env = stack[-5];
    stack[0] = v_20338;
    v_20338 = stack[-4];
    v_20338 = add1(v_20338);
    env = stack[-5];
    stack[-4] = v_20338;
    goto v_20285;
v_20284:
    v_20338 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=5 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 2, -1);
    qvalue(elt(env, 2)) = v_20338; // !*sub2
    v_20338 = stack[0];
    fn = elt(env, 8); // subs2
    v_20338 = (*qfn1(fn))(fn, v_20338);
    stack[0] = v_20338;
    ;}  // end of a binding scope
    v_20338 = stack[0];
    return onevalue(v_20338);
}



// Code for cl_bvarl1

static LispObject CC_cl_bvarl1(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20257;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
// copy arguments values to proper place
    v_20257 = v_20252;
// end of prologue
    fn = elt(env, 1); // cl_varl1
    v_20257 = (*qfn1(fn))(fn, v_20257);
    v_20257 = qcdr(v_20257);
    return onevalue(v_20257);
}



// Code for iv_cutcongs1

static LispObject CC_iv_cutcongs1(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20284, v_20285;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20253;
    stack[-1] = v_20252;
// end of prologue
v_20257:
    v_20284 = stack[0];
    if (v_20284 == nil) goto v_20261;
    goto v_20272;
v_20268:
    v_20285 = stack[-1];
    goto v_20269;
v_20270:
    v_20284 = stack[0];
    v_20284 = qcar(v_20284);
    goto v_20271;
v_20272:
    goto v_20268;
v_20269:
    goto v_20270;
v_20271:
    fn = elt(env, 1); // iv_cutcongs2
    v_20284 = (*qfn2(fn))(fn, v_20285, v_20284);
    env = stack[-2];
    if (v_20284 == nil) goto v_20266;
    v_20284 = stack[0];
    v_20284 = qcdr(v_20284);
    stack[0] = v_20284;
    goto v_20257;
v_20266:
    v_20284 = nil;
    goto v_20256;
    goto v_20259;
v_20261:
    v_20284 = lisp_true;
    goto v_20256;
v_20259:
    v_20284 = nil;
v_20256:
    return onevalue(v_20284);
}



// Code for ofsf_sippsignchkf

static LispObject CC_ofsf_sippsignchkf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20433, v_20434, v_20435, v_20436, v_20437, v_20438, v_20439;
    LispObject fn;
    LispObject v_20258, v_20257, v_20256, v_20255, v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "ofsf_sippsignchkf");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    v_20255 = va_arg(aa, LispObject);
    v_20256 = va_arg(aa, LispObject);
    v_20257 = va_arg(aa, LispObject);
    v_20258 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_20258,v_20257,v_20256,v_20255,v_20254,v_20253);
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_20252,v_20253,v_20254,v_20255,v_20256,v_20257);
        pop(v_20258);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-1] = v_20258;
    stack[-2] = v_20257;
    stack[-3] = v_20256;
    stack[-4] = v_20255;
    stack[-5] = v_20254;
    stack[-6] = v_20253;
    stack[-7] = v_20252;
// end of prologue
    v_20433 = stack[-7];
    if (!consp(v_20433)) goto v_20272;
    else goto v_20273;
v_20272:
    v_20433 = lisp_true;
    goto v_20271;
v_20273:
    v_20433 = stack[-7];
    v_20433 = qcar(v_20433);
    v_20433 = (consp(v_20433) ? nil : lisp_true);
    goto v_20271;
    v_20433 = nil;
v_20271:
    if (v_20433 == nil) goto v_20269;
    v_20433 = stack[-7];
    {
        fn = elt(env, 2); // ofsf_updsigndom
        return (*qfn1(fn))(fn, v_20433);
    }
v_20269:
    goto v_20298;
v_20284:
    v_20433 = stack[-7];
    v_20433 = qcar(v_20433);
    v_20433 = qcar(v_20433);
    v_20439 = qcar(v_20433);
    goto v_20285;
v_20286:
    v_20438 = stack[-6];
    goto v_20287;
v_20288:
    v_20437 = stack[-5];
    goto v_20289;
v_20290:
    v_20436 = stack[-4];
    goto v_20291;
v_20292:
    v_20435 = stack[-3];
    goto v_20293;
v_20294:
    v_20434 = stack[-2];
    goto v_20295;
v_20296:
    v_20433 = stack[-1];
    goto v_20297;
v_20298:
    goto v_20284;
v_20285:
    goto v_20286;
v_20287:
    goto v_20288;
v_20289:
    goto v_20290;
v_20291:
    goto v_20292;
v_20293:
    goto v_20294;
v_20295:
    goto v_20296;
v_20297:
    fn = elt(env, 3); // ofsf_updsignvar
    v_20433 = (*qfnn(fn))(fn, 7, v_20439, v_20438, v_20437, v_20436, v_20435, v_20434, v_20433);
    env = stack[-9];
    stack[0] = v_20433;
    goto v_20317;
v_20313:
    v_20434 = stack[0];
    goto v_20314;
v_20315:
    v_20433 = elt(env, 1); // unknown
    goto v_20316;
v_20317:
    goto v_20313;
v_20314:
    goto v_20315;
v_20316:
    if (v_20434 == v_20433) goto v_20311;
    else goto v_20312;
v_20311:
    v_20433 = elt(env, 1); // unknown
    goto v_20265;
v_20312:
    goto v_20336;
v_20322:
    v_20433 = stack[-7];
    v_20433 = qcar(v_20433);
    v_20439 = qcdr(v_20433);
    goto v_20323;
v_20324:
    v_20438 = stack[-6];
    goto v_20325;
v_20326:
    v_20437 = stack[-5];
    goto v_20327;
v_20328:
    v_20436 = stack[-4];
    goto v_20329;
v_20330:
    v_20435 = stack[-3];
    goto v_20331;
v_20332:
    v_20434 = stack[-2];
    goto v_20333;
v_20334:
    v_20433 = stack[-1];
    goto v_20335;
v_20336:
    goto v_20322;
v_20323:
    goto v_20324;
v_20325:
    goto v_20326;
v_20327:
    goto v_20328;
v_20329:
    goto v_20330;
v_20331:
    goto v_20332;
v_20333:
    goto v_20334;
v_20335:
    v_20433 = CC_ofsf_sippsignchkf(elt(env, 0), 7, v_20439, v_20438, v_20437, v_20436, v_20435, v_20434, v_20433);
    env = stack[-9];
    stack[-8] = v_20433;
    goto v_20354;
v_20350:
    v_20434 = stack[-8];
    goto v_20351;
v_20352:
    v_20433 = elt(env, 1); // unknown
    goto v_20353;
v_20354:
    goto v_20350;
v_20351:
    goto v_20352;
v_20353:
    if (v_20434 == v_20433) goto v_20348;
    else goto v_20349;
v_20348:
    v_20433 = elt(env, 1); // unknown
    goto v_20265;
v_20349:
    goto v_20373;
v_20359:
    v_20433 = stack[-7];
    v_20439 = qcdr(v_20433);
    goto v_20360;
v_20361:
    v_20438 = stack[-6];
    goto v_20362;
v_20363:
    v_20437 = stack[-5];
    goto v_20364;
v_20365:
    v_20436 = stack[-4];
    goto v_20366;
v_20367:
    v_20435 = stack[-3];
    goto v_20368;
v_20369:
    v_20434 = stack[-2];
    goto v_20370;
v_20371:
    v_20433 = stack[-1];
    goto v_20372;
v_20373:
    goto v_20359;
v_20360:
    goto v_20361;
v_20362:
    goto v_20363;
v_20364:
    goto v_20365;
v_20366:
    goto v_20367;
v_20368:
    goto v_20369;
v_20370:
    goto v_20371;
v_20372:
    v_20433 = CC_ofsf_sippsignchkf(elt(env, 0), 7, v_20439, v_20438, v_20437, v_20436, v_20435, v_20434, v_20433);
    env = stack[-9];
    stack[-1] = v_20433;
    goto v_20390;
v_20386:
    v_20434 = stack[-1];
    goto v_20387;
v_20388:
    v_20433 = elt(env, 1); // unknown
    goto v_20389;
v_20390:
    goto v_20386;
v_20387:
    goto v_20388;
v_20389:
    if (v_20434 == v_20433) goto v_20384;
    else goto v_20385;
v_20384:
    v_20433 = elt(env, 1); // unknown
    goto v_20265;
v_20385:
    goto v_20399;
v_20395:
    v_20434 = stack[0];
    goto v_20396;
v_20397:
    v_20433 = stack[-7];
    v_20433 = qcar(v_20433);
    v_20433 = qcar(v_20433);
    v_20433 = qcdr(v_20433);
    goto v_20398;
v_20399:
    goto v_20395;
v_20396:
    goto v_20397;
v_20398:
    fn = elt(env, 4); // ofsf_updsignpow
    v_20433 = (*qfn2(fn))(fn, v_20434, v_20433);
    env = stack[-9];
    stack[0] = v_20433;
    goto v_20410;
v_20406:
    v_20434 = stack[-8];
    goto v_20407;
v_20408:
    v_20433 = stack[0];
    goto v_20409;
v_20410:
    goto v_20406;
v_20407:
    goto v_20408;
v_20409:
    fn = elt(env, 5); // ofsf_updsignmult
    v_20433 = (*qfn2(fn))(fn, v_20434, v_20433);
    env = stack[-9];
    v_20435 = v_20433;
    goto v_20421;
v_20417:
    v_20434 = v_20435;
    goto v_20418;
v_20419:
    v_20433 = elt(env, 1); // unknown
    goto v_20420;
v_20421:
    goto v_20417;
v_20418:
    goto v_20419;
v_20420:
    if (v_20434 == v_20433) goto v_20415;
    else goto v_20416;
v_20415:
    v_20433 = elt(env, 1); // unknown
    goto v_20265;
v_20416:
    goto v_20430;
v_20426:
    v_20434 = v_20435;
    goto v_20427;
v_20428:
    v_20433 = stack[-1];
    goto v_20429;
v_20430:
    goto v_20426;
v_20427:
    goto v_20428;
v_20429:
    {
        fn = elt(env, 6); // ofsf_updsignadd
        return (*qfn2(fn))(fn, v_20434, v_20433);
    }
v_20265:
    return onevalue(v_20433);
}



// Code for dip_moncomp

static LispObject CC_dip_moncomp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20267, v_20268, v_20269;
    LispObject v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip_moncomp");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20267 = v_20254;
    v_20268 = v_20253;
    v_20269 = v_20252;
// end of prologue
    goto v_20263;
v_20257:
    goto v_20258;
v_20259:
    goto v_20260;
v_20261:
    goto v_20262;
v_20263:
    goto v_20257;
v_20258:
    goto v_20259;
v_20260:
    goto v_20261;
v_20262:
    return list2star(v_20268, v_20269, v_20267);
}



// Code for getargsrd

static LispObject CC_getargsrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20277, v_20278;
    LispObject fn;
    argcheck(nargs, 0, "getargsrd");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// end of prologue
    goto v_20264;
v_20260:
    v_20278 = qvalue(elt(env, 1)); // char
    goto v_20261;
v_20262:
    v_20277 = elt(env, 2); // (b v a r)
    goto v_20263;
v_20264:
    goto v_20260;
v_20261:
    goto v_20262;
v_20263:
    if (equal(v_20278, v_20277)) goto v_20258;
    else goto v_20259;
v_20258:
    fn = elt(env, 3); // bvarrd
    v_20277 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_20277;
    fn = elt(env, 4); // lex
    v_20277 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_20274;
v_20270:
    goto v_20271;
v_20272:
    v_20277 = CC_getargsrd(elt(env, 0), 0);
    goto v_20273;
v_20274:
    goto v_20270;
v_20271:
    goto v_20272;
v_20273:
    {
        LispObject v_20280 = stack[0];
        return cons(v_20280, v_20277);
    }
v_20259:
    v_20277 = nil;
    return onevalue(v_20277);
}



// Code for sc_mkmatrix

static LispObject CC_sc_mkmatrix(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20334, v_20335, v_20336;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_20253;
    stack[-6] = v_20252;
// end of prologue
    v_20334 = stack[-6];
    v_20334 = sub1(v_20334);
    env = stack[-8];
    v_20334 = Lmkvect(nil, v_20334);
    env = stack[-8];
    stack[-7] = v_20334;
    v_20334 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_20334;
v_20265:
    goto v_20277;
v_20273:
    v_20334 = stack[-6];
    v_20335 = sub1(v_20334);
    env = stack[-8];
    goto v_20274;
v_20275:
    v_20334 = stack[-3];
    goto v_20276;
v_20277:
    goto v_20273;
v_20274:
    goto v_20275;
v_20276:
    v_20334 = difference2(v_20335, v_20334);
    env = stack[-8];
    v_20334 = Lminusp(nil, v_20334);
    env = stack[-8];
    if (v_20334 == nil) goto v_20270;
    goto v_20264;
v_20270:
    v_20334 = stack[-5];
    v_20334 = sub1(v_20334);
    env = stack[-8];
    v_20334 = Lmkvect(nil, v_20334);
    env = stack[-8];
    stack[-4] = v_20334;
    v_20334 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_20334;
v_20288:
    goto v_20300;
v_20296:
    v_20334 = stack[-5];
    v_20335 = sub1(v_20334);
    env = stack[-8];
    goto v_20297;
v_20298:
    v_20334 = stack[-2];
    goto v_20299;
v_20300:
    goto v_20296;
v_20297:
    goto v_20298;
v_20299:
    v_20334 = difference2(v_20335, v_20334);
    env = stack[-8];
    v_20334 = Lminusp(nil, v_20334);
    env = stack[-8];
    if (v_20334 == nil) goto v_20293;
    goto v_20287;
v_20293:
    goto v_20312;
v_20306:
    stack[-1] = stack[-4];
    goto v_20307;
v_20308:
    stack[0] = stack[-2];
    goto v_20309;
v_20310:
    v_20334 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 1); // sc_simp
    v_20334 = (*qfn1(fn))(fn, v_20334);
    env = stack[-8];
    goto v_20311;
v_20312:
    goto v_20306;
v_20307:
    goto v_20308;
v_20309:
    goto v_20310;
v_20311:
    fn = elt(env, 2); // sc_iputv
    v_20334 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_20334);
    env = stack[-8];
    v_20334 = stack[-2];
    v_20334 = add1(v_20334);
    env = stack[-8];
    stack[-2] = v_20334;
    goto v_20288;
v_20287:
    goto v_20326;
v_20320:
    v_20336 = stack[-7];
    goto v_20321;
v_20322:
    v_20335 = stack[-3];
    goto v_20323;
v_20324:
    v_20334 = stack[-4];
    goto v_20325;
v_20326:
    goto v_20320;
v_20321:
    goto v_20322;
v_20323:
    goto v_20324;
v_20325:
    fn = elt(env, 2); // sc_iputv
    v_20334 = (*qfnn(fn))(fn, 3, v_20336, v_20335, v_20334);
    env = stack[-8];
    v_20334 = stack[-3];
    v_20334 = add1(v_20334);
    env = stack[-8];
    stack[-3] = v_20334;
    goto v_20265;
v_20264:
    v_20334 = stack[-7];
    return onevalue(v_20334);
}



// Code for evalb

static LispObject CC_evalb(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20274, v_20275, v_20276;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20274 = v_20252;
// end of prologue
    goto v_20266;
v_20260:
    v_20276 = v_20274;
    goto v_20261;
v_20262:
    v_20275 = nil;
    goto v_20263;
v_20264:
    v_20274 = elt(env, 1); // algebraic
    goto v_20265;
v_20266:
    goto v_20260;
v_20261:
    goto v_20262;
v_20263:
    goto v_20264;
v_20265:
    fn = elt(env, 4); // formbool
    v_20274 = (*qfnn(fn))(fn, 3, v_20276, v_20275, v_20274);
    env = stack[0];
    fn = elt(env, 5); // eval
    v_20274 = (*qfn1(fn))(fn, v_20274);
    env = stack[0];
    if (v_20274 == nil) goto v_20257;
    v_20274 = elt(env, 2); // true
    goto v_20255;
v_20257:
    v_20274 = elt(env, 3); // false
    goto v_20255;
    v_20274 = nil;
v_20255:
    return onevalue(v_20274);
}



// Code for min0

static LispObject CC_min0(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20270, v_20271;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20270 = v_20253;
    v_20271 = v_20252;
// end of prologue
    goto v_20260;
v_20256:
    goto v_20266;
v_20262:
    goto v_20263;
v_20264:
    goto v_20265;
v_20266:
    goto v_20262;
v_20263:
    goto v_20264;
v_20265:
    fn = elt(env, 1); // min
    v_20271 = (*qfn2(fn))(fn, v_20271, v_20270);
    env = stack[0];
    goto v_20257;
v_20258:
    v_20270 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20259;
v_20260:
    goto v_20256;
v_20257:
    goto v_20258;
v_20259:
    {
        fn = elt(env, 2); // max
        return (*qfn2(fn))(fn, v_20271, v_20270);
    }
}



// Code for physoptimes

static LispObject CC_physoptimes(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20509, v_20510;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[0] = v_20252;
// end of prologue
    stack[-2] = nil;
    goto v_20276;
v_20272:
    v_20510 = qvalue(elt(env, 1)); // tstack!*
    goto v_20273;
v_20274:
    v_20509 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20275;
v_20276:
    goto v_20272;
v_20273:
    goto v_20274;
v_20275:
    if (v_20510 == v_20509) goto v_20270;
    else goto v_20271;
v_20270:
    v_20509 = qvalue(elt(env, 2)); // mul!*
    goto v_20269;
v_20271:
    v_20509 = nil;
    goto v_20269;
    v_20509 = nil;
v_20269:
    if (v_20509 == nil) goto v_20267;
    v_20509 = qvalue(elt(env, 2)); // mul!*
    stack[-2] = v_20509;
    v_20509 = nil;
    qvalue(elt(env, 2)) = v_20509; // mul!*
    goto v_20265;
v_20267:
v_20265:
    v_20509 = qvalue(elt(env, 1)); // tstack!*
    v_20509 = add1(v_20509);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_20509; // tstack!*
    v_20509 = stack[0];
    v_20509 = qcar(v_20509);
    fn = elt(env, 4); // physopsim!*
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-6] = v_20509;
    v_20509 = stack[0];
    v_20509 = qcdr(v_20509);
    stack[-1] = v_20509;
v_20294:
    v_20509 = stack[-1];
    if (v_20509 == nil) goto v_20299;
    else goto v_20300;
v_20299:
    goto v_20293;
v_20300:
    v_20509 = stack[-1];
    v_20509 = qcar(v_20509);
    fn = elt(env, 4); // physopsim!*
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-5] = v_20509;
    v_20509 = stack[-6];
    fn = elt(env, 5); // getphystype
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-4] = v_20509;
    v_20509 = stack[-5];
    fn = elt(env, 5); // getphystype
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-3] = v_20509;
    v_20509 = stack[-4];
    if (v_20509 == nil) goto v_20314;
    else goto v_20315;
v_20314:
    v_20509 = stack[-3];
    if (v_20509 == nil) goto v_20319;
    else goto v_20320;
v_20319:
    goto v_20328;
v_20324:
    v_20509 = stack[-6];
    fn = elt(env, 6); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20325;
v_20326:
    v_20509 = stack[-5];
    fn = elt(env, 6); // physop2sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20327;
v_20328:
    goto v_20324;
v_20325:
    goto v_20326;
v_20327:
    fn = elt(env, 7); // multsq
    v_20509 = (*qfn2(fn))(fn, stack[0], v_20509);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-6] = v_20509;
    goto v_20318;
v_20320:
    v_20509 = stack[-6];
    v_20509 = (LispObject)zerop(v_20509);
    v_20509 = v_20509 ? lisp_true : nil;
    env = stack[-7];
    if (v_20509 == nil) goto v_20334;
    goto v_20343;
v_20339:
    v_20510 = nil;
    goto v_20340;
v_20341:
    v_20509 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20342;
v_20343:
    goto v_20339;
v_20340:
    goto v_20341;
v_20342:
    v_20509 = cons(v_20510, v_20509);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-6] = v_20509;
    goto v_20318;
v_20334:
    v_20509 = stack[-6];
    v_20509 = Lonep(nil, v_20509);
    env = stack[-7];
    if (v_20509 == nil) goto v_20347;
    v_20509 = stack[-5];
    fn = elt(env, 6); // physop2sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-6] = v_20509;
    goto v_20318;
v_20347:
    goto v_20361;
v_20357:
    v_20509 = stack[-6];
    fn = elt(env, 6); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20358;
v_20359:
    v_20509 = stack[-5];
    fn = elt(env, 6); // physop2sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20360;
v_20361:
    goto v_20357;
v_20358:
    goto v_20359;
v_20360:
    fn = elt(env, 7); // multsq
    v_20509 = (*qfn2(fn))(fn, stack[0], v_20509);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-6] = v_20509;
    goto v_20318;
v_20318:
    goto v_20313;
v_20315:
    v_20509 = stack[-3];
    if (v_20509 == nil) goto v_20366;
    else goto v_20367;
v_20366:
    v_20509 = stack[-5];
    v_20509 = (LispObject)zerop(v_20509);
    v_20509 = v_20509 ? lisp_true : nil;
    env = stack[-7];
    if (v_20509 == nil) goto v_20372;
    goto v_20381;
v_20377:
    v_20510 = nil;
    goto v_20378;
v_20379:
    v_20509 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20380;
v_20381:
    goto v_20377;
v_20378:
    goto v_20379;
v_20380:
    v_20509 = cons(v_20510, v_20509);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20370;
v_20372:
    v_20509 = stack[-5];
    v_20509 = Lonep(nil, v_20509);
    env = stack[-7];
    if (v_20509 == nil) goto v_20385;
    v_20509 = stack[-6];
    fn = elt(env, 6); // physop2sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20370;
v_20385:
    goto v_20399;
v_20395:
    v_20509 = stack[-5];
    fn = elt(env, 6); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20396;
v_20397:
    v_20509 = stack[-6];
    fn = elt(env, 6); // physop2sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20398;
v_20399:
    goto v_20395;
v_20396:
    goto v_20397;
v_20398:
    fn = elt(env, 7); // multsq
    v_20509 = (*qfn2(fn))(fn, stack[0], v_20509);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20370;
    v_20509 = nil;
v_20370:
    stack[-6] = v_20509;
    goto v_20313;
v_20367:
    goto v_20412;
v_20408:
    v_20509 = stack[-6];
    fn = elt(env, 9); // physopaeval
    stack[0] = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20409;
v_20410:
    v_20509 = stack[-5];
    fn = elt(env, 9); // physopaeval
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20411;
v_20412:
    goto v_20408;
v_20409:
    goto v_20410;
v_20411:
    fn = elt(env, 10); // physopordchk
    v_20509 = (*qfn2(fn))(fn, stack[0], v_20509);
    env = stack[-7];
    if (v_20509 == nil) goto v_20405;
    goto v_20426;
v_20422:
    v_20510 = stack[-4];
    goto v_20423;
v_20424:
    v_20509 = stack[-3];
    goto v_20425;
v_20426:
    goto v_20422;
v_20423:
    goto v_20424;
v_20425:
    if (equal(v_20510, v_20509)) goto v_20420;
    else goto v_20421;
v_20420:
    goto v_20433;
v_20429:
    v_20510 = stack[-4];
    goto v_20430;
v_20431:
    v_20509 = elt(env, 3); // scalar
    goto v_20432;
v_20433:
    goto v_20429;
v_20430:
    goto v_20431;
v_20432:
    v_20509 = (v_20510 == v_20509 ? lisp_true : nil);
    goto v_20419;
v_20421:
    v_20509 = nil;
    goto v_20419;
    v_20509 = nil;
v_20419:
    if (v_20509 == nil) goto v_20405;
    goto v_20446;
v_20442:
    v_20509 = stack[-6];
    fn = elt(env, 6); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20443;
v_20444:
    v_20509 = stack[-5];
    fn = elt(env, 6); // physop2sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    goto v_20445;
v_20446:
    goto v_20442;
v_20443:
    goto v_20444;
v_20445:
    fn = elt(env, 7); // multsq
    v_20509 = (*qfn2(fn))(fn, stack[0], v_20509);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20509 = (*qfn1(fn))(fn, v_20509);
    env = stack[-7];
    stack[-6] = v_20509;
    goto v_20313;
v_20405:
    goto v_20458;
v_20454:
    v_20510 = stack[-6];
    goto v_20455;
v_20456:
    v_20509 = stack[-5];
    goto v_20457;
v_20458:
    goto v_20454;
v_20455:
    goto v_20456;
v_20457:
    fn = elt(env, 11); // multopop!*
    v_20509 = (*qfn2(fn))(fn, v_20510, v_20509);
    env = stack[-7];
    stack[-6] = v_20509;
    goto v_20313;
v_20313:
    v_20509 = stack[-1];
    v_20509 = qcdr(v_20509);
    stack[-1] = v_20509;
    goto v_20294;
v_20293:
v_20262:
    v_20509 = qvalue(elt(env, 2)); // mul!*
    if (v_20509 == nil) goto v_20469;
    else goto v_20470;
v_20469:
    v_20509 = lisp_true;
    goto v_20468;
v_20470:
    goto v_20480;
v_20476:
    v_20510 = qvalue(elt(env, 1)); // tstack!*
    goto v_20477;
v_20478:
    v_20509 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20479;
v_20480:
    goto v_20476;
v_20477:
    goto v_20478;
v_20479:
    v_20509 = (LispObject)greaterp2(v_20510, v_20509);
    v_20509 = v_20509 ? lisp_true : nil;
    env = stack[-7];
    goto v_20468;
    v_20509 = nil;
v_20468:
    if (v_20509 == nil) goto v_20466;
    goto v_20263;
v_20466:
    goto v_20488;
v_20484:
    v_20509 = qvalue(elt(env, 2)); // mul!*
    v_20510 = qcar(v_20509);
    goto v_20485;
v_20486:
    v_20509 = stack[-6];
    goto v_20487;
v_20488:
    goto v_20484;
v_20485:
    goto v_20486;
v_20487:
    v_20509 = Lapply1(nil, v_20510, v_20509);
    env = stack[-7];
    stack[-6] = v_20509;
    v_20509 = qvalue(elt(env, 2)); // mul!*
    v_20509 = qcdr(v_20509);
    qvalue(elt(env, 2)) = v_20509; // mul!*
    goto v_20262;
v_20263:
    v_20509 = qvalue(elt(env, 1)); // tstack!*
    v_20509 = sub1(v_20509);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_20509; // tstack!*
    goto v_20504;
v_20500:
    v_20510 = qvalue(elt(env, 1)); // tstack!*
    goto v_20501;
v_20502:
    v_20509 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20503;
v_20504:
    goto v_20500;
v_20501:
    goto v_20502;
v_20503:
    if (v_20510 == v_20509) goto v_20498;
    else goto v_20499;
v_20498:
    v_20509 = stack[-2];
    qvalue(elt(env, 2)) = v_20509; // mul!*
    goto v_20497;
v_20499:
v_20497:
    v_20509 = stack[-6];
    return onevalue(v_20509);
}



// Code for prop!-simp1

static LispObject CC_propKsimp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20370, v_20371, v_20372;
    LispObject fn;
    LispObject v_20256, v_20255, v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "prop-simp1");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    v_20255 = va_arg(aa, LispObject);
    v_20256 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_20256,v_20255,v_20254,v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_20252,v_20253,v_20254,v_20255,v_20256);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_20256;
    stack[0] = v_20255;
    stack[-5] = v_20254;
    stack[-2] = v_20253;
    stack[-6] = v_20252;
// end of prologue
v_20251:
    v_20370 = stack[-2];
    if (v_20370 == nil) goto v_20260;
    else goto v_20261;
v_20260:
    goto v_20270;
v_20264:
    goto v_20276;
v_20272:
    v_20371 = stack[0];
    goto v_20273;
v_20274:
    v_20370 = stack[-4];
    goto v_20275;
v_20276:
    goto v_20272;
v_20273:
    goto v_20274;
v_20275:
    stack[0] = list2(v_20371, v_20370);
    env = stack[-8];
    goto v_20265;
v_20266:
    stack[-1] = stack[-6];
    goto v_20267;
v_20268:
    v_20370 = stack[-5];
    v_20370 = Lreverse(nil, v_20370);
    goto v_20269;
v_20270:
    goto v_20264;
v_20265:
    goto v_20266;
v_20267:
    goto v_20268;
v_20269:
    {
        LispObject v_20381 = stack[0];
        LispObject v_20382 = stack[-1];
        return list2star(v_20381, v_20382, v_20370);
    }
v_20261:
    goto v_20289;
v_20285:
    v_20371 = stack[-6];
    goto v_20286;
v_20287:
    v_20370 = stack[-2];
    v_20370 = qcar(v_20370);
    goto v_20288;
v_20289:
    goto v_20285;
v_20286:
    goto v_20287;
v_20288:
    fn = elt(env, 1); // prop!-simp2
    v_20370 = (*qfn2(fn))(fn, v_20371, v_20370);
    env = stack[-8];
    stack[-3] = v_20370;
    v_20370 = stack[-3];
    if (v_20370 == nil) goto v_20296;
    else goto v_20297;
v_20296:
    goto v_20310;
v_20300:
    stack[-3] = stack[-6];
    goto v_20301;
v_20302:
    v_20370 = stack[-2];
    stack[-1] = qcdr(v_20370);
    goto v_20303;
v_20304:
    goto v_20319;
v_20315:
    v_20370 = stack[-2];
    v_20371 = qcar(v_20370);
    goto v_20316;
v_20317:
    v_20370 = stack[-5];
    goto v_20318;
v_20319:
    goto v_20315;
v_20316:
    goto v_20317;
v_20318:
    v_20372 = cons(v_20371, v_20370);
    env = stack[-8];
    goto v_20305;
v_20306:
    v_20371 = stack[0];
    goto v_20307;
v_20308:
    v_20370 = stack[-4];
    goto v_20309;
v_20310:
    goto v_20300;
v_20301:
    goto v_20302;
v_20303:
    goto v_20304;
v_20305:
    goto v_20306;
v_20307:
    goto v_20308;
v_20309:
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v_20372;
    stack[0] = v_20371;
    stack[-4] = v_20370;
    goto v_20251;
v_20297:
    goto v_20338;
v_20328:
    v_20370 = stack[-3];
    stack[-6] = qcdr(v_20370);
    goto v_20329;
v_20330:
    v_20370 = stack[-2];
    stack[-2] = qcdr(v_20370);
    goto v_20331;
v_20332:
    stack[-1] = stack[-5];
    goto v_20333;
v_20334:
    v_20370 = stack[0];
    stack[0] = add1(v_20370);
    env = stack[-8];
    goto v_20335;
v_20336:
    goto v_20351;
v_20347:
    v_20370 = stack[-3];
    stack[-7] = qcar(v_20370);
    goto v_20348;
v_20349:
    goto v_20359;
v_20355:
    goto v_20356;
v_20357:
    goto v_20366;
v_20362:
    stack[-3] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20363;
v_20364:
    v_20370 = stack[-5];
    v_20370 = Llength(nil, v_20370);
    env = stack[-8];
    goto v_20365;
v_20366:
    goto v_20362;
v_20363:
    goto v_20364;
v_20365:
    v_20370 = Lexpt(nil, stack[-3], v_20370);
    env = stack[-8];
    goto v_20358;
v_20359:
    goto v_20355;
v_20356:
    goto v_20357;
v_20358:
    v_20370 = times2(stack[-4], v_20370);
    env = stack[-8];
    goto v_20350;
v_20351:
    goto v_20347;
v_20348:
    goto v_20349;
v_20350:
    v_20370 = times2(stack[-7], v_20370);
    env = stack[-8];
    goto v_20337;
v_20338:
    goto v_20328;
v_20329:
    goto v_20330;
v_20331:
    goto v_20332;
v_20333:
    goto v_20334;
v_20335:
    goto v_20336;
v_20337:
    stack[-5] = stack[-1];
    stack[-4] = v_20370;
    goto v_20251;
    v_20370 = nil;
    goto v_20259;
    v_20370 = nil;
v_20259:
    return onevalue(v_20370);
}



// Code for no!-side!-effectp

static LispObject CC_noKsideKeffectp(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20308, v_20309;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20252;
// end of prologue
    v_20308 = stack[0];
    if (!consp(v_20308)) goto v_20256;
    else goto v_20257;
v_20256:
    v_20308 = stack[0];
    v_20308 = (is_number(v_20308) ? lisp_true : nil);
    if (v_20308 == nil) goto v_20261;
    else goto v_20260;
v_20261:
    v_20308 = stack[0];
    if (symbolp(v_20308)) goto v_20267;
    v_20308 = nil;
    goto v_20265;
v_20267:
    v_20308 = stack[0];
    v_20308 = Lsymbol_specialp(nil, v_20308);
    env = stack[-1];
    if (v_20308 == nil) goto v_20274;
    else goto v_20273;
v_20274:
    v_20308 = stack[0];
    v_20308 = Lsymbol_globalp(nil, v_20308);
v_20273:
    v_20308 = (v_20308 == nil ? lisp_true : nil);
    goto v_20265;
    v_20308 = nil;
v_20265:
v_20260:
    goto v_20255;
v_20257:
    goto v_20286;
v_20282:
    v_20308 = stack[0];
    v_20309 = qcar(v_20308);
    goto v_20283;
v_20284:
    v_20308 = elt(env, 1); // quote
    goto v_20285;
v_20286:
    goto v_20282;
v_20283:
    goto v_20284;
v_20285:
    if (v_20309 == v_20308) goto v_20280;
    else goto v_20281;
v_20280:
    v_20308 = lisp_true;
    goto v_20255;
v_20281:
    goto v_20298;
v_20294:
    v_20308 = stack[0];
    v_20309 = qcar(v_20308);
    goto v_20295;
v_20296:
    v_20308 = elt(env, 2); // nosideeffects
    goto v_20297;
v_20298:
    goto v_20294;
v_20295:
    goto v_20296;
v_20297:
    v_20308 = Lflagp(nil, v_20309, v_20308);
    env = stack[-1];
    if (v_20308 == nil) goto v_20292;
    v_20308 = stack[0];
    v_20308 = qcdr(v_20308);
    {
        fn = elt(env, 3); // no!-side!-effect!-listp
        return (*qfn1(fn))(fn, v_20308);
    }
v_20292:
    v_20308 = nil;
    goto v_20255;
    v_20308 = nil;
v_20255:
    return onevalue(v_20308);
}



// Code for remchkf1

static LispObject CC_remchkf1(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20301, v_20302, v_20303;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20252,v_20253);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20253;
    stack[-1] = v_20252;
// end of prologue
    v_20301 = stack[-1];
    fn = elt(env, 3); // termsf
    v_20301 = (*qfn1(fn))(fn, v_20301);
    env = stack[-3];
    stack[-2] = v_20301;
    goto v_20268;
v_20262:
    v_20303 = stack[-1];
    goto v_20263;
v_20264:
    v_20302 = stack[0];
    goto v_20265;
v_20266:
    v_20301 = stack[-2];
    goto v_20267;
v_20268:
    goto v_20262;
v_20263:
    goto v_20264;
v_20265:
    goto v_20266;
v_20267:
    fn = elt(env, 4); // xremf
    v_20301 = (*qfnn(fn))(fn, 3, v_20303, v_20302, v_20301);
    env = stack[-3];
    stack[0] = v_20301;
    v_20301 = stack[0];
    if (v_20301 == nil) goto v_20278;
    else goto v_20279;
v_20278:
    v_20301 = lisp_true;
    goto v_20277;
v_20279:
    goto v_20289;
v_20285:
    v_20301 = stack[0];
    v_20301 = qcar(v_20301);
    stack[0] = v_20301;
    fn = elt(env, 3); // termsf
    v_20302 = (*qfn1(fn))(fn, v_20301);
    env = stack[-3];
    goto v_20286;
v_20287:
    v_20301 = stack[-2];
    goto v_20288;
v_20289:
    goto v_20285;
v_20286:
    goto v_20287;
v_20288:
    v_20301 = (LispObject)geq2(v_20302, v_20301);
    v_20301 = v_20301 ? lisp_true : nil;
    env = stack[-3];
    goto v_20277;
    v_20301 = nil;
v_20277:
    if (v_20301 == nil) goto v_20275;
    v_20301 = stack[-1];
    goto v_20257;
v_20275:
    v_20301 = qvalue(elt(env, 1)); // !*trcompact
    if (v_20301 == nil) goto v_20296;
    v_20301 = elt(env, 2); // "*** Remainder smaller"
    fn = elt(env, 5); // prin2t
    v_20301 = (*qfn1(fn))(fn, v_20301);
    goto v_20273;
v_20296:
v_20273:
    v_20301 = stack[0];
v_20257:
    return onevalue(v_20301);
}



// Code for red_tailreddriver

static LispObject CC_red_tailreddriver(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20310;
    LispObject fn;
    LispObject v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "red_tailreddriver");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20254,v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20252,v_20253,v_20254);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_20254;
    stack[-2] = v_20253;
    stack[-3] = v_20252;
// end of prologue
    v_20310 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20310 = (*qfn1(fn))(fn, v_20310);
    env = stack[-5];
    if (v_20310 == nil) goto v_20262;
    else goto v_20263;
v_20262:
    v_20310 = lisp_true;
    goto v_20261;
v_20263:
    v_20310 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20310 = (*qfn1(fn))(fn, v_20310);
    env = stack[-5];
    v_20310 = qcdr(v_20310);
    if (v_20310 == nil) goto v_20271;
    else goto v_20272;
v_20271:
    v_20310 = lisp_true;
    goto v_20270;
v_20272:
    v_20310 = stack[-3];
    v_20310 = (v_20310 == nil ? lisp_true : nil);
    goto v_20270;
    v_20310 = nil;
v_20270:
    goto v_20261;
    v_20310 = nil;
v_20261:
    if (v_20310 == nil) goto v_20259;
    v_20310 = stack[-2];
    goto v_20257;
v_20259:
v_20288:
    v_20310 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20310 = (*qfn1(fn))(fn, v_20310);
    env = stack[-5];
    if (v_20310 == nil) goto v_20291;
    else goto v_20292;
v_20291:
    goto v_20287;
v_20292:
    goto v_20303;
v_20297:
    stack[-4] = stack[-1];
    goto v_20298;
v_20299:
    stack[0] = stack[-3];
    goto v_20300;
v_20301:
    v_20310 = stack[-2];
    fn = elt(env, 2); // red!=hidelt
    v_20310 = (*qfn1(fn))(fn, v_20310);
    env = stack[-5];
    goto v_20302;
v_20303:
    goto v_20297;
v_20298:
    goto v_20299;
v_20300:
    goto v_20301;
v_20302:
    v_20310 = Lapply2(nil, 3, stack[-4], stack[0], v_20310);
    env = stack[-5];
    stack[-2] = v_20310;
    goto v_20288;
v_20287:
    v_20310 = stack[-2];
    {
        fn = elt(env, 3); // red!=recover
        return (*qfn1(fn))(fn, v_20310);
    }
    goto v_20257;
    v_20310 = nil;
v_20257:
    return onevalue(v_20310);
}



// Code for ra_qmk

static LispObject CC_ra_qmk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20274, v_20275, v_20276;
    LispObject fn;
    LispObject v_20254, v_20253, v_20252;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ra_qmk");
    va_start(aa, nargs);
    v_20252 = va_arg(aa, LispObject);
    v_20253 = va_arg(aa, LispObject);
    v_20254 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20254,v_20253,v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20252,v_20253,v_20254);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20274 = v_20254;
    v_20275 = v_20253;
    v_20276 = v_20252;
// end of prologue
    goto v_20263;
v_20257:
    stack[-1] = elt(env, 1); // !:ra!:
    goto v_20258;
v_20259:
    stack[0] = v_20276;
    goto v_20260;
v_20261:
    goto v_20271;
v_20267:
    goto v_20268;
v_20269:
    goto v_20270;
v_20271:
    goto v_20267;
v_20268:
    goto v_20269;
v_20270:
    fn = elt(env, 2); // riv_mk
    v_20274 = (*qfn2(fn))(fn, v_20275, v_20274);
    goto v_20262;
v_20263:
    goto v_20257;
v_20258:
    goto v_20259;
v_20260:
    goto v_20261;
v_20262:
    {
        LispObject v_20279 = stack[-1];
        LispObject v_20280 = stack[0];
        return list3(v_20279, v_20280, v_20274);
    }
}



// Code for lalr_print_first_information

static LispObject CC_lalr_print_first_information(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20307, v_20308;
    LispObject fn;
    argcheck(nargs, 0, "lalr_print_first_information");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
    v_20307 = elt(env, 1); // "=== FIRST sets for each nonterminal ==="
    v_20307 = Lprinc(nil, v_20307);
    env = stack[-2];
    v_20307 = Lterpri(nil, 0);
    env = stack[-2];
    v_20307 = qvalue(elt(env, 2)); // nonterminals
    stack[-1] = v_20307;
v_20259:
    v_20307 = stack[-1];
    if (v_20307 == nil) goto v_20263;
    else goto v_20264;
v_20263:
    goto v_20258;
v_20264:
    v_20307 = stack[-1];
    v_20307 = qcar(v_20307);
    stack[0] = v_20307;
    v_20307 = stack[0];
    fn = elt(env, 6); // lalr_prin_symbol
    v_20307 = (*qfn1(fn))(fn, v_20307);
    env = stack[-2];
    v_20307 = elt(env, 3); // ":"
    v_20307 = Lprinc(nil, v_20307);
    env = stack[-2];
    v_20307 = (LispObject)320+TAG_FIXNUM; // 20
    v_20307 = Lttab(nil, v_20307);
    env = stack[-2];
    goto v_20285;
v_20281:
    v_20308 = stack[0];
    goto v_20282;
v_20283:
    v_20307 = elt(env, 4); // lalr_first
    goto v_20284;
v_20285:
    goto v_20281;
v_20282:
    goto v_20283;
v_20284:
    v_20307 = get(v_20308, v_20307);
    env = stack[-2];
    stack[0] = v_20307;
v_20279:
    v_20307 = stack[0];
    if (v_20307 == nil) goto v_20290;
    else goto v_20291;
v_20290:
    goto v_20278;
v_20291:
    v_20307 = stack[0];
    v_20307 = qcar(v_20307);
    fn = elt(env, 6); // lalr_prin_symbol
    v_20307 = (*qfn1(fn))(fn, v_20307);
    env = stack[-2];
    v_20307 = elt(env, 5); // " "
    v_20307 = Lprinc(nil, v_20307);
    env = stack[-2];
    v_20307 = stack[0];
    v_20307 = qcdr(v_20307);
    stack[0] = v_20307;
    goto v_20279;
v_20278:
    v_20307 = Lterpri(nil, 0);
    env = stack[-2];
    v_20307 = stack[-1];
    v_20307 = qcdr(v_20307);
    stack[-1] = v_20307;
    goto v_20259;
v_20258:
        return Lterpri(nil, 0);
}



// Code for dvfsf_v

static LispObject CC_dvfsf_v(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20276, v_20277;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20276 = v_20252;
// end of prologue
    goto v_20259;
v_20255:
    v_20277 = v_20276;
    goto v_20256;
v_20257:
    v_20276 = qvalue(elt(env, 1)); // dvfsf_p!*
    goto v_20258;
v_20259:
    goto v_20255;
v_20256:
    goto v_20257;
v_20258:
    fn = elt(env, 2); // qremf
    v_20276 = (*qfn2(fn))(fn, v_20277, v_20276);
    env = stack[0];
    v_20277 = v_20276;
    v_20276 = v_20277;
    v_20276 = qcdr(v_20276);
    if (v_20276 == nil) goto v_20265;
    else goto v_20266;
v_20265:
    v_20276 = v_20277;
    v_20276 = qcar(v_20276);
    v_20276 = CC_dvfsf_v(elt(env, 0), v_20276);
    return add1(v_20276);
v_20266:
    v_20276 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20264;
    v_20276 = nil;
v_20264:
    return onevalue(v_20276);
}



// Code for rl_fvarl

static LispObject CC_rl_fvarl(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20263;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20263 = v_20252;
// end of prologue
    goto v_20259;
v_20255:
    stack[0] = qvalue(elt(env, 1)); // rl_fvarl!*
    goto v_20256;
v_20257:
    v_20263 = ncons(v_20263);
    env = stack[-1];
    goto v_20258;
v_20259:
    goto v_20255;
v_20256:
    goto v_20257;
v_20258:
    {
        LispObject v_20265 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_20265, v_20263);
    }
}



// Code for pasf_smordtable1

static LispObject CC_pasf_smordtable1(LispObject env,
                         LispObject v_20252, LispObject v_20253)
{
    env = qenv(env);
    LispObject v_20275, v_20276, v_20277;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20275 = v_20253;
    v_20276 = v_20252;
// end of prologue
    v_20277 = elt(env, 1); // ((lessp (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (leq (lessp 1) (leq 1)
// (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (equal (lessp 1) (leq 1) (equal false) (neq 1)
// (geq false) (greaterp false) (cong nil) (ncong nil)) (neq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2)
// (cong nil) (ncong nil)) (geq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)) (greaterp
// (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)))
    goto v_20263;
v_20259:
    goto v_20260;
v_20261:
    goto v_20269;
v_20265:
    goto v_20266;
v_20267:
    goto v_20268;
v_20269:
    goto v_20265;
v_20266:
    goto v_20267;
v_20268:
    v_20276 = Latsoc(nil, v_20276, v_20277);
    goto v_20262;
v_20263:
    goto v_20259;
v_20260:
    goto v_20261;
v_20262:
    v_20275 = Latsoc(nil, v_20275, v_20276);
    v_20275 = qcdr(v_20275);
    return onevalue(v_20275);
}



// Code for cgp_lbc

static LispObject CC_cgp_lbc(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20257;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20257 = v_20252;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v_20257 = (*qfn1(fn))(fn, v_20257);
    env = stack[0];
    {
        fn = elt(env, 2); // dip_lbc
        return (*qfn1(fn))(fn, v_20257);
    }
}



// Code for symbolsom

static LispObject CC_symbolsom(LispObject env,
                         LispObject v_20252)
{
    env = qenv(env);
    LispObject v_20396, v_20397, v_20398;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20252);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20252);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_20252;
// end of prologue
    stack[-1] = nil;
    goto v_20265;
v_20261:
    v_20396 = stack[-4];
    v_20397 = qcar(v_20396);
    goto v_20262;
v_20263:
    v_20396 = qvalue(elt(env, 1)); // valid_om!*
    goto v_20264;
v_20265:
    goto v_20261;
v_20262:
    goto v_20263;
v_20264:
    v_20396 = Lassoc(nil, v_20397, v_20396);
    stack[-5] = v_20396;
    v_20396 = stack[-5];
    if (v_20396 == nil) goto v_20273;
    v_20396 = stack[-5];
    v_20396 = qcdr(v_20396);
    v_20396 = qcar(v_20396);
    stack[-5] = v_20396;
    goto v_20271;
v_20273:
v_20271:
    v_20396 = stack[-4];
    v_20396 = qcar(v_20396);
    stack[0] = v_20396;
    v_20396 = stack[-4];
    v_20396 = qcdr(v_20396);
    v_20396 = qcdr(v_20396);
    v_20396 = qcar(v_20396);
    stack[-3] = v_20396;
    v_20396 = stack[-4];
    v_20396 = Lreverse(nil, v_20396);
    env = stack[-6];
    v_20396 = qcar(v_20396);
    stack[-2] = v_20396;
    goto v_20295;
v_20291:
    v_20397 = stack[0];
    goto v_20292;
v_20293:
    v_20396 = elt(env, 2); // diff
    goto v_20294;
v_20295:
    goto v_20291;
v_20292:
    goto v_20293;
v_20294:
    if (v_20397 == v_20396) goto v_20290;
    v_20396 = stack[-4];
    v_20396 = qcdr(v_20396);
    v_20396 = qcdr(v_20396);
    v_20396 = qcdr(v_20396);
    v_20396 = qcar(v_20396);
    stack[-1] = v_20396;
    goto v_20288;
v_20290:
v_20288:
    v_20396 = stack[-1];
    if (v_20396 == nil) goto v_20306;
    goto v_20316;
v_20312:
    v_20396 = stack[-1];
    v_20397 = qcar(v_20396);
    goto v_20313;
v_20314:
    v_20396 = elt(env, 3); // condition
    goto v_20315;
v_20316:
    goto v_20312;
v_20313:
    goto v_20314;
v_20315:
    if (v_20397 == v_20396) goto v_20310;
    else goto v_20311;
v_20310:
    goto v_20325;
v_20321:
    v_20397 = elt(env, 4); // "<condition> tag not supported in MathML"
    goto v_20322;
v_20323:
    v_20396 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20324;
v_20325:
    goto v_20321;
v_20322:
    goto v_20323;
v_20324:
    fn = elt(env, 13); // errorml
    v_20396 = (*qfn2(fn))(fn, v_20397, v_20396);
    env = stack[-6];
    goto v_20309;
v_20311:
v_20309:
    goto v_20304;
v_20306:
v_20304:
    v_20396 = elt(env, 5); // "<OMA>"
    fn = elt(env, 14); // printout
    v_20396 = (*qfn1(fn))(fn, v_20396);
    env = stack[-6];
    v_20396 = lisp_true;
    fn = elt(env, 15); // indent!*
    v_20396 = (*qfn1(fn))(fn, v_20396);
    env = stack[-6];
    v_20396 = stack[-1];
    if (v_20396 == nil) goto v_20339;
    goto v_20345;
v_20341:
    v_20397 = stack[0];
    goto v_20342;
v_20343:
    v_20396 = elt(env, 6); // int
    goto v_20344;
v_20345:
    goto v_20341;
v_20342:
    goto v_20343;
v_20344:
    v_20396 = (v_20397 == v_20396 ? lisp_true : nil);
    goto v_20337;
v_20339:
    v_20396 = nil;
    goto v_20337;
    v_20396 = nil;
v_20337:
    if (v_20396 == nil) goto v_20335;
    v_20396 = elt(env, 7); // defint
    stack[0] = v_20396;
    goto v_20333;
v_20335:
v_20333:
    v_20396 = elt(env, 8); // "<OMS cd="""
    fn = elt(env, 14); // printout
    v_20396 = (*qfn1(fn))(fn, v_20396);
    env = stack[-6];
    v_20396 = stack[-5];
    v_20396 = Lprinc(nil, v_20396);
    env = stack[-6];
    v_20396 = elt(env, 9); // """ name="""
    v_20396 = Lprinc(nil, v_20396);
    env = stack[-6];
    v_20396 = stack[0];
    v_20396 = Lprinc(nil, v_20396);
    env = stack[-6];
    v_20396 = elt(env, 10); // """/>"
    v_20396 = Lprinc(nil, v_20396);
    env = stack[-6];
    v_20396 = stack[-1];
    if (v_20396 == nil) goto v_20366;
    v_20396 = stack[-1];
    fn = elt(env, 16); // objectom
    v_20396 = (*qfn1(fn))(fn, v_20396);
    env = stack[-6];
    goto v_20364;
v_20366:
v_20364:
    goto v_20378;
v_20372:
    stack[-1] = elt(env, 11); // lambda
    goto v_20373;
v_20374:
    stack[0] = nil;
    goto v_20375;
v_20376:
    goto v_20388;
v_20382:
    v_20398 = stack[-3];
    goto v_20383;
v_20384:
    v_20397 = stack[-2];
    goto v_20385;
v_20386:
    v_20396 = nil;
    goto v_20387;
v_20388:
    goto v_20382;
v_20383:
    goto v_20384;
v_20385:
    goto v_20386;
v_20387:
    v_20396 = list2star(v_20398, v_20397, v_20396);
    env = stack[-6];
    goto v_20377;
v_20378:
    goto v_20372;
v_20373:
    goto v_20374;
v_20375:
    goto v_20376;
v_20377:
    v_20396 = list2star(stack[-1], stack[0], v_20396);
    env = stack[-6];
    fn = elt(env, 17); // lambdaom
    v_20396 = (*qfn1(fn))(fn, v_20396);
    env = stack[-6];
    v_20396 = nil;
    fn = elt(env, 15); // indent!*
    v_20396 = (*qfn1(fn))(fn, v_20396);
    env = stack[-6];
    v_20396 = elt(env, 12); // "</OMA>"
    fn = elt(env, 14); // printout
    v_20396 = (*qfn1(fn))(fn, v_20396);
    v_20396 = nil;
    return onevalue(v_20396);
}



// Code for close_forall

static LispObject CC_close_forall(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20268, v_20269;
    LispObject fn;
    argcheck(nargs, 0, "close_forall");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
// end of prologue
    goto v_20263;
v_20259:
    v_20269 = qvalue(elt(env, 1)); // flagg
    goto v_20260;
v_20261:
    v_20268 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20262;
v_20263:
    goto v_20259;
v_20260:
    goto v_20261;
v_20262:
    if (v_20269 == v_20268) goto v_20257;
    else goto v_20258;
v_20257:
    v_20268 = elt(env, 2); // "</apply>"
    fn = elt(env, 3); // printout
    v_20268 = (*qfn1(fn))(fn, v_20268);
    goto v_20256;
v_20258:
v_20256:
    v_20268 = nil;
    return onevalue(v_20268);
}



setup_type const u36_setup[] =
{
    {"ofsf_smcpknowl",          CC_ofsf_smcpknowl,TOO_MANY_1,  WRONG_NO_1},
    {"multdf",                  TOO_FEW_2,      CC_multdf,     WRONG_NO_2},
    {"domainvalchk",            TOO_FEW_2,      CC_domainvalchk,WRONG_NO_2},
    {"pasf_anegrel",            CC_pasf_anegrel,TOO_MANY_1,    WRONG_NO_1},
    {"aex_subrat1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_aex_subrat1},
    {"fnrd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fnrd},
    {"sc_subtrsq",              TOO_FEW_2,      CC_sc_subtrsq, WRONG_NO_2},
    {"vdpilcomb1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpilcomb1},
    {"calc_coeff",              TOO_FEW_2,      CC_calc_coeff, WRONG_NO_2},
    {"dp_neworder",             CC_dp_neworder, TOO_MANY_1,    WRONG_NO_1},
    {"dfprintfn",               CC_dfprintfn,   TOO_MANY_1,    WRONG_NO_1},
    {"clean_numid",             CC_clean_numid, TOO_MANY_1,    WRONG_NO_1},
    {"dummyp",                  CC_dummyp,      TOO_MANY_1,    WRONG_NO_1},
    {"difbf",                   TOO_FEW_2,      CC_difbf,      WRONG_NO_2},
    {"order_of_der_mind",       CC_order_of_der_mind,TOO_MANY_1,WRONG_NO_1},
    {"ext_mult",                TOO_FEW_2,      CC_ext_mult,   WRONG_NO_2},
    {"bc_mkat",                 TOO_FEW_2,      CC_bc_mkat,    WRONG_NO_2},
    {"ithlistelem",             TOO_FEW_2,      CC_ithlistelem,WRONG_NO_2},
    {"maxl",                    CC_maxl,        TOO_MANY_1,    WRONG_NO_1},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,TOO_MANY_1,WRONG_NO_1},
    {"noncomexpf",              CC_noncomexpf,  TOO_MANY_1,    WRONG_NO_1},
    {"getrlist",                CC_getrlist,    TOO_MANY_1,    WRONG_NO_1},
    {"chkint*",                 CC_chkintH,     TOO_MANY_1,    WRONG_NO_1},
    {"indordl2",                TOO_FEW_2,      CC_indordl2,   WRONG_NO_2},
    {"liennewstruc",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_liennewstruc},
    {"listsub",                 TOO_FEW_2,      CC_listsub,    WRONG_NO_2},
    {"mo=zero",                 CC_moMzero,     TOO_MANY_1,    WRONG_NO_1},
    {"lalr_get_lex_codes",      CC_lalr_get_lex_codes,TOO_MANY_1,WRONG_NO_1},
    {"polynomcompare",          TOO_FEW_2,      CC_polynomcompare,WRONG_NO_2},
    {"maxfrom1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_maxfrom1},
    {"get-denom-l",             CC_getKdenomKl, TOO_MANY_1,    WRONG_NO_1},
    {"mk+real+inner+product",   TOO_FEW_2,      CC_mkLrealLinnerLproduct,WRONG_NO_2},
    {"cl_bvarl1",               CC_cl_bvarl1,   TOO_MANY_1,    WRONG_NO_1},
    {"iv_cutcongs1",            TOO_FEW_2,      CC_iv_cutcongs1,WRONG_NO_2},
    {"ofsf_sippsignchkf",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_sippsignchkf},
    {"dip_moncomp",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dip_moncomp},
    {"getargsrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_getargsrd},
    {"sc_mkmatrix",             TOO_FEW_2,      CC_sc_mkmatrix,WRONG_NO_2},
    {"evalb",                   CC_evalb,       TOO_MANY_1,    WRONG_NO_1},
    {"min0",                    TOO_FEW_2,      CC_min0,       WRONG_NO_2},
    {"physoptimes",             CC_physoptimes, TOO_MANY_1,    WRONG_NO_1},
    {"prop-simp1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_propKsimp1},
    {"no-side-effectp",         CC_noKsideKeffectp,TOO_MANY_1, WRONG_NO_1},
    {"remchkf1",                TOO_FEW_2,      CC_remchkf1,   WRONG_NO_2},
    {"red_tailreddriver",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_red_tailreddriver},
    {"ra_qmk",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_qmk},
    {"lalr_print_first_information",WRONG_NO_NA,WRONG_NO_NB,   (n_args *)CC_lalr_print_first_information},
    {"dvfsf_v",                 CC_dvfsf_v,     TOO_MANY_1,    WRONG_NO_1},
    {"rl_fvarl",                CC_rl_fvarl,    TOO_MANY_1,    WRONG_NO_1},
    {"pasf_smordtable1",        TOO_FEW_2,      CC_pasf_smordtable1,WRONG_NO_2},
    {"cgp_lbc",                 CC_cgp_lbc,     TOO_MANY_1,    WRONG_NO_1},
    {"symbolsom",               CC_symbolsom,   TOO_MANY_1,    WRONG_NO_1},
    {"close_forall",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_close_forall},
    {NULL, (one_args *)"u36", (two_args *)"76934 5119303 9414104", 0}
};

// end of generated code
