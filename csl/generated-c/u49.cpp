
// $destdir/u49.c        Machine generated C code

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
#ifndef DEBUG
#define NDEBUG 1
#endif
#if defined HAVE_COMPLEX_H && \
 defined HAVE_COMPLEX_DOUBLE && \
 defined HAVE_CSQRT
#define HAVE_COMPLEX 1
#endif
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H
#if defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP
#if defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif
#endif
#endif
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#ifdef WIN32
#define __USE_MINGW_ANSI_STDIO 1
#endif
#ifdef WIN32
#include <winsock.h>
#include <semaphore.h>
#include <windows.h>
#else 
#define unix_posix 1 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <fcntl.h>
#define WSAGetLastError() errno 
#define WSACleanup() 
#define closesocket(a) close(a)
#define SOCKET int
#define SOCKET_ERROR (-1)
#ifndef INADDR_NONE
# define INADDR_NONE 0xffffffff
#endif
#ifdef HAVE_LIBPTHREAD
#include <semaphore.h>
#include <pthread.h>
#endif
#endif 
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <exception>
#include <errno.h>
#include <assert.h>
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
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
#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 4)
typedef int32_t intptr_t;
#define INTPTR_MAX INT32_MAX
#define INTPTR_MIN INT32_MIN
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 8)
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 4)
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 8)
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#ifndef UINTPTR_MAX
#define UINTPTR_MAX ((uintptr_t)(-1))
#endif
#ifndef INTPTR_MAX
#define INTPTR_MAX ((intptr_t)((UINTPTR_MAX-1)/2))
#endif
#ifndef INTPTR_MIN
#define INTPTR_MIN (-1-INTPTR_MAX)
#endif
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
#ifdef HAVE_UINT128_T
#define HAVE_NATIVE_UINT128 1
#elif defined HAVE_UNSIGNED___INT128
typedef unsigned __int128 uint128_t;
#define HAVE_NATIVE_UINT128
#else
#include "uint128_t.h" 
#endif
#ifdef HAVE_INT128_T
#define HAVE_NATIVE_INT128 1
#elif defined HAVE___INT128
typedef __int128 int128_t;
#define HAVE_NATIVE_INT128
#elif defined HAVE_UINT128_T || defined HAVE_UNSIGNED___INT128
#error Seem to have unsigned 128-bit type but not a signed one!
#endif
#endif 
#ifndef header_int128_t_h
#define header_int128_t_h 1
#ifdef HAVE_NATIVE_INT128
static inline bool greaterp128(int128_t a, int128_t b)
{ return a > b;
}
static inline bool lessp128(int128_t a, int128_t b)
{ return a < b;
}
static inline bool geq128(int128_t a, int128_t b)
{ return a >= b;
}
static inline bool leq128(int128_t a, int128_t b)
{ return a <= b;
}
static inline int128_t ASL128(int128_t a, int n)
{ return (uint128_t)a << MAXSHIFT(n, int128_t);
}
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
static inline int128_t ASR128(int128_t a, int n)
{ return a >> MAXSHIFT(n, int128_t);
}
#else 
static inline int128_t ASR128(int128_t a, int n)
{ n = MAXSHIFT(n, int128_t);
 return (a & ~((uint128_t)1<<n - 1))/(int128_t)1<<n;
}
#endif 
static inline int64_t NARROW128(int128_t a)
{ return (int64_t)a;
}
static inline void divrem128(int128_t a, int128_t b,
 int128_t & q, int128_t & r)
{ uint128_t qq = a/b;
 q = qq;
 r = a - qq*b;
}
#else 
typedef uint128_t int128_t;
static inline bool greaterp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa > bb;
}
static inline bool lessp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa < bb;
}
static inline bool geq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa >= bb;
}
static inline bool leq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa <= bb;
}
static inline int128_t ASL128(const int128_t & a, int n)
{ n = MAXSHIFT(n, int128_t);
 if (n < 64) return
 int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
 a.lower()<<n);
 else if (n == 64) return int128_t(a.lower(), 0);
 else return int128_t(a.lower()<<(n-64), 0);
}
static inline int128_t ASR128(const int128_t & a, int n)
{ n = MAXSHIFT(n, int128_t);
 if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else if (n == 64) return int128_t(-(int64_t)(a.upper()<0),
 a.upper());
 else return int128_t(-(int64_t)(a.upper()<0),
 ASR(((int64_t)a.upper()), n-64));
}
static inline int64_t NARROW128(const int128_t & a)
{ return (int64_t)a.lower();
}
static inline void divrem128(const int128_t & a, const int128_t & b,
 int128_t & q, int128_t & r)
{ if ((int64_t)a.upper() < 0)
 { if ((int64_t)b.upper() < 0) q = (-a)/(-b);
 else q = -((-a)/b);
 }
 else
 { if ((int64_t)b.upper() < 0) q = -(a/(-b));
 else q = a/b;
 }
 r = a - q*b;
}
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
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
static inline bool is_forward(LispObject p)
{ return (p & TAG_BITS) == TAG_FORWARD;
}
static inline bool is_number(LispObject p)
{ return (p & TAG_BITS) >= TAG_NUMBERS;
}
static inline bool is_float(LispObject p)
{ return ((0xc040 >> (p & XTAG_BITS)) & 1) != 0;
}
static inline bool is_immed_or_cons(LispObject p)
{ return ((0x85 >> (p & TAG_BITS)) & 1) != 0;
}
static inline bool is_immed_cons_sym(LispObject p)
{ return ((0x95 >> (p & TAG_BITS)) & 1) != 0;
}
static inline bool need_more_than_eq(LispObject p)
{ return ((0x63 >> (p & TAG_BITS)) & 1) != 0;
}
static inline LispObject fixnum_of_int(intptr_t x)
{ return (LispObject)((((uintptr_t)x)<<4) + TAG_FIXNUM);
}
static inline intptr_t int_of_fixnum(LispObject x)
{ return ((intptr_t)x & ~(intptr_t)15)/16;
}
static inline bool valid_as_fixnum(int32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(int64_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(int128_t x)
{ return int_of_fixnum(fixnum_of_int(NARROW128(x))) == x;
}
static inline bool intptr_valid_as_fixnum(intptr_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(uint32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return x < (((uintptr_t)1) << 28);
}
static inline bool valid_as_fixnum(uint64_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
static inline bool uint128_valid_as_fixnum(uint128_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
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
#if 0
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
#endif
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
typedef union _Float_union
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
typedef union _Double_union
{ double f;
 uint32_t i[2];
 uint64_t i64;
 float64_t f64;
} Double_union;
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
extern LispObject err_table, progn_symbol, gcknt_symbol;
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
extern int64_t gc_number;
extern int64_t reclaim_trap_count;
extern uintptr_t reclaim_stack_limit;
extern bool next_gc_is_hard;
extern uint64_t force_cons, force_vec;
static inline bool cons_forced(size_t n)
{
#ifdef DEBUG
 if (force_cons == 0) return false;
 if (force_cons <= n)
 { force_cons = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_cons -= n;
#endif
 return false;
}
static inline bool vec_forced(size_t n)
{
#ifdef DEBUG
 if (force_vec == 0) return false;
 if (force_vec <= n)
 { force_vec = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_vec -= n;
#endif
 return false;
}
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
extern bool isprime(uint64_t);
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
extern uint64_t sixty_four_bits_unsigned(LispObject a);
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
static inline bool equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return equal_fn(a, b);
 else return false;
}
static inline bool cl_equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return cl_equal_fn(a, b);
 else return false;
}
static inline bool eql(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return eql_fn(a, b);
 else return false;
}
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
extern unsigned char msd_table[256], lsd_table[256];
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
#define FIX_TRUNCATE softfloat_round_minMag
#define FIX_ROUND softfloat_round_near_even
#define FIX_FLOOR softfloat_round_min
#define FIX_CEILING softfloat_round_max
extern LispObject lisp_fix(LispObject a, int roundmode);
extern LispObject lisp_ifix(LispObject a, LispObject b, int roundmode);
static inline bool floating_edge_case(double r)
{ return (1.0/r == 0.0 || r != r);
}
static inline void floating_clear_flags()
{}
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
#define fixnum_minusp(a) ((intptr_t)(a) < 0)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
static inline double value_of_immediate_float(LispObject a)
{ Float_union aa;
 if (SIXTY_FOUR_BIT) aa.i = (int32_t)((uint64_t)a>>32);
 else aa.i = (int32_t)(a - XTAG_SFLOAT);
 return aa.f;
}
extern LispObject make_boxfloat(double a, int type);
extern LispObject make_boxfloat128(float128_t a);
static inline LispObject pack_short_float(double d)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with short float");
 }
 aa.i &= ~0xf;
 if (SIXTY_FOUR_BIT)
 return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT;
 else return aa.i + XTAG_SFLOAT;
}
static inline LispObject pack_single_float(double d)
{ if (SIXTY_FOUR_BIT)
 { Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return (LispObject)((uint64_t)aa.i << 32) + XTAG_SFLOAT + XTAG_FLOAT32;
 }
 else
 { LispObject r = getvector(TAG_BOXFLOAT,
 TYPE_SINGLE_FLOAT, sizeof(Single_Float));
 single_float_val(r) = (float)d;
 if (trap_floating_overflow &&
 floating_edge_case(single_float_val(r)))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return r;
 }
}
static inline LispObject pack_immediate_float(double d,
 LispObject l1, LispObject l2=0)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 if (((l1 | l2) & XTAG_FLOAT32) != 0)
 aerror("exception with single float");
 else aerror("exception with short float");
 }
 if (SIXTY_FOUR_BIT)
 { if (((l1 | l2) & XTAG_FLOAT32) == 0) aa.i &= ~0xf;
 return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT +
 ((l1 | l2) & XTAG_FLOAT32);
 }
 aa.i &= ~0xf;
 return aa.i + XTAG_SFLOAT;
}
static inline bool eq_i64d(int64_t a, double b)
{
 if (b != (double)a) return false;
 if (b == (double)((uint64_t)1<<63)) return false;
 return a == (int64_t)b;
}
static inline bool lessp_i64d(int64_t a, double b)
{
 if (a <= ((int64_t)1<<53) &&
 a >= -((int64_t)1<<53)) return (double)a < b;
 if (!(b >= -(double)((uint64_t)1<<63))) return false;
 if (!(b < (double)((uint64_t)1<<63))) return true;
 return a < (int64_t)b;
}
static inline bool lessp_di64(double a, int64_t b)
{
 if (b <= ((int64_t)1<<53) &&
 b >= -((int64_t)1<<53)) return a < (double)b;
 if (!(a < (double)((uint64_t)1<<63))) return false;
 if (!(a >= -(double)((uint64_t)1<<63))) return true;
 return (int64_t)a < b;
}
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
extern "C" LispObject integer_decode_long_float(LispObject a);
extern "C" LispObject Linteger_decode_float(LispObject env, LispObject a);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_n_word_bignum(int32_t a2, uint32_t a1,
 uint32_t a0, size_t n);
extern LispObject make_n4_word_bignum(int32_t a3, uint32_t a2,
 uint32_t a1, uint32_t a0, size_t n);
extern LispObject make_n5_word_bignum(int32_t a4, uint32_t a3,
 uint32_t a2, uint32_t a1,
 uint32_t a0, size_t n);
extern LispObject make_power_of_two(size_t n);
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
{ if (intptr_valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(NARROW128(n));
 else return make_lisp_integer128_fn(n);
}
extern LispObject make_lisp_unsigned128_fn(uint128_t n);
static inline LispObject make_lisp_unsigned128(uint128_t n)
{ if (uint128_valid_as_fixnum(n))
 return fixnum_of_int((uint64_t)NARROW128(n));
 else return make_lisp_unsigned128_fn(n);
}
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern LispObject make_approx_ratio(LispObject p, LispObject q, int bits);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
extern LispObject rationalf128(float128_t *d);
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
#ifdef WIN32
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
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
static int f128M_exponent(const float128_t *p);
static void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
extern "C" void f128M_frexp(float128_t *p, float128_t *r, int *x);
static bool f128M_infinite(const float128_t *p);
static bool f128M_finite(const float128_t *p);
static bool f128M_nan(const float128_t *x);
static bool f128M_subnorm(const float128_t *x);
static bool f128M_negative(const float128_t *x);
static void f128M_negate(float128_t *x);
extern "C" void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
#ifdef LITTLEENDIAN
#define HIPART 1
#define LOPART 0
#else
#define HIPART 0
#define LOPART 1
#endif
static inline bool f128M_zero(const float128_t *p)
{ return ((p->v[HIPART] & INT64_C(0x7fffffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
static inline bool f128M_infinite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 ((p->v[HIPART] & INT64_C(0xffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
static inline bool f128M_finite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) != 0x7fff);
}
static inline void f128M_make_infinite(float128_t *p)
{ p->v[HIPART] |= UINT64_C(0x7fff000000000000);
 p->v[HIPART] &= UINT64_C(0xffff000000000000);
 p->v[LOPART] = 0;
}
static inline void f128M_make_zero(float128_t *p)
{ p->v[HIPART] &= UINT64_C(0x8000000000000000);
 p->v[LOPART] = 0;
}
static inline bool f128M_subnorm(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
static inline bool f128M_nan(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
static inline bool f128M_negative(const float128_t *x)
{ if (f128M_nan(x)) return false;
 return ((int64_t)x->v[HIPART]) < 0;
}
static inline int f128M_exponent(const float128_t *p)
{ return ((p->v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}
static inline void f128M_set_exponent(float128_t *p, int n)
{ p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
 (((uint64_t)n + 0x3fff) << 48);
}
static inline void f128M_negate(float128_t *x)
{ x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}
static inline bool floating_edge_case128(float128_t *r)
{ return f128M_infinite(r) || f128M_nan(r);
}
extern int double_to_binary(double d, int64_t &m);
extern int float128_to_binary(const float128_t *d,
 int64_t &mhi, uint64_t &mlo);
extern intptr_t double_to_3_digits(double d,
 int32_t &a2, uint32_t &a1, uint32_t &a0);
extern intptr_t float128_to_5_digits(float128_t *d,
 int32_t &a4, uint32_t &a3, uint32_t &a2, uint32_t &a1, uint32_t &a0);
extern "C" float128_t f128_0, 
 f128_half, 
 f128_mhalf, 
 f128_1, 
 f128_10, 
 f128_10_17, 
 f128_10_18, 
 f128_r10, 
 f128_N1; 
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
static inline void f128M_to_f256M(const float128_t *a, float256_t *b)
{ b->hi = *a;
 b->lo = f128_0;
} 
extern "C" void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);
extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);
extern "C" float128_t atof128(const char *s);
#define arith_dispatch_1(stgclass, type, name) \
stgclass type name(LispObject a1) \
{ if (is_fixnum(a1)) return name##_i(a1); \
 switch (a1 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1); \
 case TYPE_RATNUM: \
 return name##_r(a1); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
}
#define arith_dispatch_1a(stgclass, type, name, rawname) \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a2)) return name##_i(a1, a2); \
 switch (a2 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1, a2); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a2))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a2))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
}
#define arith_dispatch_2(stgclass, type, name) \
arith_dispatch_1a(static inline, type, name##_i, name) \
 \
arith_dispatch_1a(static inline, type, name##_b, name) \
 \
arith_dispatch_1a(static inline, type, name##_r, name) \
 \
arith_dispatch_1a(static inline, type, name##_c, name) \
 \
arith_dispatch_1a(static inline, type, name##_s, name) \
 \
arith_dispatch_1a(static inline, type, name##_f, name) \
 \
arith_dispatch_1a(static inline, type, name##_d, name) \
 \
arith_dispatch_1a(static inline, type, name##_l, name) \
 \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a1)) return name##_i(a1, a2); \
 switch (a1 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1, a2); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
}
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



// Code for setmatelem

static LispObject CC_setmatelem(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28248, v_28249, v_28250;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_28062;
    stack[-3] = v_28061;
// end of prologue
    goto v_28077;
v_28073:
    v_28248 = stack[-3];
    v_28249 = Llength(nil, v_28248);
    env = stack[-5];
    goto v_28074;
v_28075:
    v_28248 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28076;
v_28077:
    goto v_28073;
v_28074:
    goto v_28075;
v_28076:
    if (v_28249 == v_28248) goto v_28072;
    goto v_28086;
v_28082:
    v_28249 = stack[-3];
    goto v_28083;
v_28084:
    v_28248 = elt(env, 2); // "matrix element"
    goto v_28085;
v_28086:
    goto v_28082;
v_28083:
    goto v_28084;
v_28085:
    fn = elt(env, 9); // typerr
    v_28248 = (*qfn2(fn))(fn, v_28249, v_28248);
    env = stack[-5];
    goto v_28070;
v_28072:
v_28070:
    v_28248 = stack[-3];
    v_28248 = qcar(v_28248);
    if (!symbolp(v_28248)) v_28248 = nil;
    else { v_28248 = qfastgets(v_28248);
           if (v_28248 != nil) { v_28248 = elt(v_28248, 4); // avalue
#ifdef RECORD_GET
             if (v_28248 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_28248 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_28248 == SPID_NOPROP) v_28248 = nil; }}
#endif
    stack[-4] = v_28248;
    v_28248 = stack[-4];
    if (v_28248 == nil) goto v_28098;
    else goto v_28099;
v_28098:
    v_28248 = lisp_true;
    goto v_28097;
v_28099:
    goto v_28108;
v_28104:
    v_28248 = stack[-4];
    v_28249 = qcar(v_28248);
    goto v_28105;
v_28106:
    v_28248 = elt(env, 3); // matrix
    goto v_28107;
v_28108:
    goto v_28104;
v_28105:
    goto v_28106;
v_28107:
    v_28248 = (v_28249 == v_28248 ? lisp_true : nil);
    v_28248 = (v_28248 == nil ? lisp_true : nil);
    goto v_28097;
    v_28248 = nil;
v_28097:
    if (v_28248 == nil) goto v_28095;
    goto v_28119;
v_28115:
    v_28248 = stack[-3];
    v_28249 = qcar(v_28248);
    goto v_28116;
v_28117:
    v_28248 = elt(env, 4); // "matrix"
    goto v_28118;
v_28119:
    goto v_28115;
v_28116:
    goto v_28117;
v_28118:
    fn = elt(env, 9); // typerr
    v_28248 = (*qfn2(fn))(fn, v_28249, v_28248);
    env = stack[-5];
    goto v_28093;
v_28095:
    goto v_28130;
v_28126:
    v_28248 = stack[-4];
    v_28248 = qcdr(v_28248);
    v_28249 = qcar(v_28248);
    stack[-4] = v_28249;
    goto v_28127;
v_28128:
    v_28248 = elt(env, 5); // mat
    goto v_28129;
v_28130:
    goto v_28126;
v_28127:
    goto v_28128;
v_28129:
    if (!consp(v_28249)) goto v_28123;
    v_28249 = qcar(v_28249);
    if (v_28249 == v_28248) goto v_28124;
v_28123:
    goto v_28142;
v_28136:
    stack[-1] = elt(env, 3); // matrix
    goto v_28137;
v_28138:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_28139;
v_28140:
    goto v_28152;
v_28146:
    v_28250 = elt(env, 6); // "Matrix"
    goto v_28147;
v_28148:
    v_28248 = stack[-3];
    v_28249 = qcar(v_28248);
    goto v_28149;
v_28150:
    v_28248 = elt(env, 7); // "not set"
    goto v_28151;
v_28152:
    goto v_28146;
v_28147:
    goto v_28148;
v_28149:
    goto v_28150;
v_28151:
    v_28248 = list3(v_28250, v_28249, v_28248);
    env = stack[-5];
    goto v_28141;
v_28142:
    goto v_28136;
v_28137:
    goto v_28138;
v_28139:
    goto v_28140;
v_28141:
    fn = elt(env, 10); // rerror
    v_28248 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_28248);
    env = stack[-5];
    goto v_28093;
v_28124:
v_28093:
    v_28248 = stack[-3];
    v_28248 = qcdr(v_28248);
    v_28248 = qcar(v_28248);
    fn = elt(env, 11); // reval_without_mod
    v_28248 = (*qfn1(fn))(fn, v_28248);
    env = stack[-5];
    stack[0] = v_28248;
    v_28248 = stack[0];
    v_28248 = integerp(v_28248);
    if (v_28248 == nil) goto v_28167;
    else goto v_28168;
v_28167:
    v_28248 = lisp_true;
    goto v_28166;
v_28168:
    goto v_28179;
v_28175:
    v_28249 = stack[0];
    goto v_28176;
v_28177:
    v_28248 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28178;
v_28179:
    goto v_28175;
v_28176:
    goto v_28177;
v_28178:
    v_28248 = (LispObject)lesseq2(v_28249, v_28248);
    v_28248 = v_28248 ? lisp_true : nil;
    env = stack[-5];
    goto v_28166;
    v_28248 = nil;
v_28166:
    if (v_28248 == nil) goto v_28164;
    goto v_28187;
v_28183:
    v_28249 = stack[0];
    goto v_28184;
v_28185:
    v_28248 = elt(env, 8); // "positive integer"
    goto v_28186;
v_28187:
    goto v_28183;
v_28184:
    goto v_28185;
v_28186:
    fn = elt(env, 9); // typerr
    v_28248 = (*qfn2(fn))(fn, v_28249, v_28248);
    env = stack[-5];
    goto v_28162;
v_28164:
v_28162:
    goto v_28195;
v_28191:
    v_28248 = stack[-4];
    v_28249 = qcdr(v_28248);
    goto v_28192;
v_28193:
    v_28248 = stack[0];
    goto v_28194;
v_28195:
    goto v_28191;
v_28192:
    goto v_28193;
v_28194:
    fn = elt(env, 12); // nth
    v_28248 = (*qfn2(fn))(fn, v_28249, v_28248);
    env = stack[-5];
    stack[-4] = v_28248;
    v_28248 = stack[-3];
    v_28248 = qcdr(v_28248);
    v_28248 = qcdr(v_28248);
    v_28248 = qcar(v_28248);
    fn = elt(env, 11); // reval_without_mod
    v_28248 = (*qfn1(fn))(fn, v_28248);
    env = stack[-5];
    stack[0] = v_28248;
    v_28248 = stack[0];
    v_28248 = integerp(v_28248);
    if (v_28248 == nil) goto v_28210;
    else goto v_28211;
v_28210:
    v_28248 = lisp_true;
    goto v_28209;
v_28211:
    goto v_28222;
v_28218:
    v_28249 = stack[0];
    goto v_28219;
v_28220:
    v_28248 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28221;
v_28222:
    goto v_28218;
v_28219:
    goto v_28220;
v_28221:
    v_28248 = (LispObject)lesseq2(v_28249, v_28248);
    v_28248 = v_28248 ? lisp_true : nil;
    env = stack[-5];
    goto v_28209;
    v_28248 = nil;
v_28209:
    if (v_28248 == nil) goto v_28207;
    goto v_28230;
v_28226:
    v_28249 = stack[0];
    goto v_28227;
v_28228:
    v_28248 = elt(env, 8); // "positive integer"
    goto v_28229;
v_28230:
    goto v_28226;
v_28227:
    goto v_28228;
v_28229:
    fn = elt(env, 9); // typerr
    v_28248 = (*qfn2(fn))(fn, v_28249, v_28248);
    env = stack[-5];
    goto v_28205;
v_28207:
v_28205:
    goto v_28238;
v_28234:
    goto v_28244;
v_28240:
    v_28249 = stack[-4];
    goto v_28241;
v_28242:
    v_28248 = stack[0];
    goto v_28243;
v_28244:
    goto v_28240;
v_28241:
    goto v_28242;
v_28243:
    fn = elt(env, 13); // pnth
    v_28249 = (*qfn2(fn))(fn, v_28249, v_28248);
    goto v_28235;
v_28236:
    v_28248 = stack[-2];
    goto v_28237;
v_28238:
    goto v_28234;
v_28235:
    goto v_28236;
v_28237:
        return Lrplaca(nil, v_28249, v_28248);
    return onevalue(v_28248);
}



// Code for mv2sf

static LispObject CC_mv2sf(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28118, v_28119, v_28120;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28062;
    stack[-1] = v_28061;
// end of prologue
    stack[-2] = nil;
v_28068:
    v_28118 = stack[-1];
    if (v_28118 == nil) goto v_28073;
    else goto v_28074;
v_28073:
    goto v_28069;
v_28074:
    goto v_28081;
v_28077:
    goto v_28089;
v_28083:
    v_28118 = stack[-1];
    v_28118 = qcar(v_28118);
    v_28120 = qcar(v_28118);
    goto v_28084;
v_28085:
    v_28118 = stack[-1];
    v_28118 = qcar(v_28118);
    v_28119 = qcdr(v_28118);
    goto v_28086;
v_28087:
    v_28118 = stack[0];
    goto v_28088;
v_28089:
    goto v_28083;
v_28084:
    goto v_28085;
v_28086:
    goto v_28087;
v_28088:
    fn = elt(env, 1); // mv2sf1
    v_28119 = (*qfnn(fn))(fn, 3, v_28120, v_28119, v_28118);
    env = stack[-3];
    goto v_28078;
v_28079:
    v_28118 = stack[-2];
    goto v_28080;
v_28081:
    goto v_28077;
v_28078:
    goto v_28079;
v_28080:
    v_28118 = cons(v_28119, v_28118);
    env = stack[-3];
    stack[-2] = v_28118;
    v_28118 = stack[-1];
    v_28118 = qcdr(v_28118);
    stack[-1] = v_28118;
    goto v_28068;
v_28069:
    v_28118 = nil;
    v_28119 = v_28118;
v_28070:
    v_28118 = stack[-2];
    if (v_28118 == nil) goto v_28103;
    else goto v_28104;
v_28103:
    v_28118 = v_28119;
    goto v_28067;
v_28104:
    goto v_28112;
v_28108:
    v_28118 = stack[-2];
    v_28118 = qcar(v_28118);
    goto v_28109;
v_28110:
    goto v_28111;
v_28112:
    goto v_28108;
v_28109:
    goto v_28110;
v_28111:
    fn = elt(env, 2); // addf
    v_28118 = (*qfn2(fn))(fn, v_28118, v_28119);
    env = stack[-3];
    v_28119 = v_28118;
    v_28118 = stack[-2];
    v_28118 = qcdr(v_28118);
    stack[-2] = v_28118;
    goto v_28070;
v_28067:
    return onevalue(v_28118);
}



// Code for nodum_varp

static LispObject CC_nodum_varp(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28116, v_28117;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28061;
// end of prologue
    v_28116 = stack[0];
    fn = elt(env, 4); // listp
    v_28116 = (*qfn1(fn))(fn, v_28116);
    env = stack[-1];
    if (v_28116 == nil) goto v_28066;
    v_28116 = lisp_true;
    goto v_28064;
v_28066:
    v_28116 = stack[0];
    if (!symbolp(v_28116)) v_28116 = nil;
    else { v_28116 = qfastgets(v_28116);
           if (v_28116 != nil) { v_28116 = elt(v_28116, 32); // dummy
#ifdef RECORD_GET
             if (v_28116 == SPID_NOPROP)
                record_get(elt(fastget_names, 32), 0),
                v_28116 = nil;
             else record_get(elt(fastget_names, 32), 1),
                v_28116 = lisp_true; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v_28116 == SPID_NOPROP) v_28116 = nil; else v_28116 = lisp_true; }}
#endif
    if (v_28116 == nil) goto v_28075;
    v_28116 = lisp_true;
    goto v_28073;
v_28075:
    goto v_28089;
v_28085:
    v_28116 = stack[0];
    fn = elt(env, 5); // ad_splitname
    v_28116 = (*qfn1(fn))(fn, v_28116);
    env = stack[-1];
    v_28117 = qcar(v_28116);
    goto v_28086;
v_28087:
    v_28116 = qvalue(elt(env, 1)); // g_dvbase
    goto v_28088;
v_28089:
    goto v_28085;
v_28086:
    goto v_28087;
v_28088:
    if (equal(v_28117, v_28116)) goto v_28083;
    else goto v_28084;
v_28083:
    v_28116 = lisp_true;
    goto v_28082;
v_28084:
    goto v_28101;
v_28097:
    goto v_28098;
v_28099:
    goto v_28108;
v_28104:
    v_28117 = elt(env, 2); // !~dv
    goto v_28105;
v_28106:
    v_28116 = elt(env, 3); // !~dva
    goto v_28107;
v_28108:
    goto v_28104;
v_28105:
    goto v_28106;
v_28107:
    v_28116 = list2(v_28117, v_28116);
    goto v_28100;
v_28101:
    goto v_28097;
v_28098:
    goto v_28099;
v_28100:
    v_28116 = Lmember(nil, stack[0], v_28116);
    goto v_28082;
    v_28116 = nil;
v_28082:
    goto v_28073;
    v_28116 = nil;
v_28073:
    if (v_28116 == nil) goto v_28071;
    v_28116 = nil;
    goto v_28064;
v_28071:
    v_28116 = lisp_true;
    goto v_28064;
    v_28116 = nil;
v_28064:
    return onevalue(v_28116);
}



// Code for try!-all!-constants

static LispObject CC_tryKallKconstants(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28155, v_28156, v_28157;
    LispObject fn;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "try-all-constants");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28063,v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28061,v_28062,v_28063);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_28063;
    stack[-3] = v_28062;
    v_28156 = v_28061;
// end of prologue
    v_28155 = nil;
    stack[-1] = v_28155;
    v_28155 = v_28156;
    stack[-4] = v_28155;
    v_28155 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_28155;
v_28071:
    goto v_28082;
v_28076:
    v_28157 = stack[-3];
    goto v_28077;
v_28078:
    v_28156 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28079;
v_28080:
    v_28155 = stack[0];
    goto v_28081;
v_28082:
    goto v_28076;
v_28077:
    goto v_28078;
v_28079:
    goto v_28080;
v_28081:
    *(LispObject *)((char *)v_28157 + (CELL-TAG_VECTOR) + (((intptr_t)v_28156-TAG_FIXNUM)/(16/CELL))) = v_28155;
    goto v_28093;
v_28087:
    v_28157 = stack[-4];
    goto v_28088;
v_28089:
    v_28156 = stack[-3];
    goto v_28090;
v_28091:
    v_28155 = stack[-2];
    goto v_28092;
v_28093:
    goto v_28087;
v_28088:
    goto v_28089;
v_28090:
    goto v_28091;
v_28092:
    fn = elt(env, 4); // split!-further
    v_28155 = (*qfnn(fn))(fn, 3, v_28157, v_28156, v_28155);
    env = stack[-5];
    v_28156 = v_28155;
    v_28155 = v_28156;
    v_28155 = qcdr(v_28155);
    stack[-4] = v_28155;
    v_28155 = v_28156;
    v_28155 = qcar(v_28155);
    v_28156 = v_28155;
    goto v_28106;
v_28102:
    goto v_28103;
v_28104:
    v_28155 = stack[-1];
    goto v_28105;
v_28106:
    goto v_28102;
v_28103:
    goto v_28104;
v_28105:
    v_28155 = Lnconc(nil, v_28156, v_28155);
    env = stack[-5];
    stack[-1] = v_28155;
    v_28155 = stack[-4];
    if (v_28155 == nil) goto v_28111;
    else goto v_28112;
v_28111:
    v_28155 = stack[-1];
    goto v_28070;
v_28112:
    goto v_28123;
v_28119:
    v_28156 = qvalue(elt(env, 2)); // number!-needed
    goto v_28120;
v_28121:
    v_28155 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28122;
v_28123:
    goto v_28119;
v_28120:
    goto v_28121;
v_28122:
    if (v_28156 == v_28155) goto v_28117;
    else goto v_28118;
v_28117:
    goto v_28131;
v_28127:
    v_28156 = stack[-4];
    goto v_28128;
v_28129:
    v_28155 = stack[-1];
    goto v_28130;
v_28131:
    goto v_28127;
v_28128:
    goto v_28129;
v_28130:
        return Lnconc(nil, v_28156, v_28155);
v_28118:
    v_28155 = stack[0];
    v_28155 = (LispObject)((intptr_t)(v_28155) + 0x10);
    stack[0] = v_28155;
    goto v_28144;
v_28140:
    v_28156 = stack[0];
    goto v_28141;
v_28142:
    v_28155 = qvalue(elt(env, 3)); // current!-modulus
    goto v_28143;
v_28144:
    goto v_28140;
v_28141:
    goto v_28142;
v_28143:
    if (((intptr_t)(v_28156)) < ((intptr_t)(v_28155))) goto v_28138;
    else goto v_28139;
v_28138:
    goto v_28071;
v_28139:
    goto v_28152;
v_28148:
    v_28156 = stack[-4];
    goto v_28149;
v_28150:
    v_28155 = stack[-1];
    goto v_28151;
v_28152:
    goto v_28148;
v_28149:
    goto v_28150;
v_28151:
        return Lnconc(nil, v_28156, v_28155);
v_28070:
    return onevalue(v_28155);
}



// Code for aex_psremseq

static LispObject CC_aex_psremseq(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28162, v_28163, v_28164;
    LispObject fn;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_psremseq");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28063,v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28061,v_28062,v_28063);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_28063;
    stack[-1] = v_28062;
    stack[-2] = v_28061;
// end of prologue
    goto v_28073;
    goto v_28071;
v_28073:
v_28071:
    goto v_28080;
v_28076:
    v_28162 = stack[-2];
    fn = elt(env, 2); // aex_mklcnt
    v_28163 = (*qfn1(fn))(fn, v_28162);
    env = stack[-4];
    goto v_28077;
v_28078:
    v_28162 = stack[0];
    goto v_28079;
v_28080:
    goto v_28076;
v_28077:
    goto v_28078;
v_28079:
    fn = elt(env, 3); // aex_divposcnt
    v_28162 = (*qfn2(fn))(fn, v_28163, v_28162);
    env = stack[-4];
    stack[-2] = v_28162;
    goto v_28089;
v_28085:
    v_28162 = stack[-1];
    fn = elt(env, 2); // aex_mklcnt
    v_28163 = (*qfn1(fn))(fn, v_28162);
    env = stack[-4];
    goto v_28086;
v_28087:
    v_28162 = stack[0];
    goto v_28088;
v_28089:
    goto v_28085;
v_28086:
    goto v_28087;
v_28088:
    fn = elt(env, 3); // aex_divposcnt
    v_28162 = (*qfn2(fn))(fn, v_28163, v_28162);
    env = stack[-4];
    stack[-1] = v_28162;
    goto v_28098;
v_28094:
    v_28163 = stack[-1];
    goto v_28095;
v_28096:
    v_28162 = stack[-2];
    goto v_28097;
v_28098:
    goto v_28094;
v_28095:
    goto v_28096;
v_28097:
    v_28162 = list2(v_28163, v_28162);
    env = stack[-4];
    stack[-3] = v_28162;
v_28103:
    goto v_28113;
v_28109:
    goto v_28119;
v_28115:
    v_28163 = stack[-1];
    goto v_28116;
v_28117:
    v_28162 = stack[0];
    goto v_28118;
v_28119:
    goto v_28115;
v_28116:
    goto v_28117;
v_28118:
    fn = elt(env, 4); // aex_deg
    v_28163 = (*qfn2(fn))(fn, v_28163, v_28162);
    env = stack[-4];
    goto v_28110;
v_28111:
    v_28162 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28112;
v_28113:
    goto v_28109;
v_28110:
    goto v_28111;
v_28112:
    v_28162 = (LispObject)greaterp2(v_28163, v_28162);
    v_28162 = v_28162 ? lisp_true : nil;
    env = stack[-4];
    if (v_28162 == nil) goto v_28106;
    else goto v_28107;
v_28106:
    goto v_28102;
v_28107:
    goto v_28131;
v_28125:
    v_28164 = stack[-2];
    goto v_28126;
v_28127:
    v_28163 = stack[-1];
    goto v_28128;
v_28129:
    v_28162 = stack[0];
    goto v_28130;
v_28131:
    goto v_28125;
v_28126:
    goto v_28127;
v_28128:
    goto v_28129;
v_28130:
    fn = elt(env, 5); // aex_psrem
    v_28162 = (*qfnn(fn))(fn, 3, v_28164, v_28163, v_28162);
    env = stack[-4];
    v_28163 = v_28162;
    v_28162 = stack[-1];
    stack[-2] = v_28162;
    v_28162 = v_28163;
    fn = elt(env, 6); // aex_neg
    v_28162 = (*qfn1(fn))(fn, v_28162);
    env = stack[-4];
    stack[-1] = v_28162;
    v_28162 = stack[-1];
    fn = elt(env, 7); // aex_simplenullp
    v_28162 = (*qfn1(fn))(fn, v_28162);
    env = stack[-4];
    if (v_28162 == nil) goto v_28140;
    else goto v_28141;
v_28140:
    goto v_28149;
v_28145:
    v_28163 = stack[-1];
    goto v_28146;
v_28147:
    v_28162 = stack[0];
    goto v_28148;
v_28149:
    goto v_28145;
v_28146:
    goto v_28147;
v_28148:
    fn = elt(env, 3); // aex_divposcnt
    v_28162 = (*qfn2(fn))(fn, v_28163, v_28162);
    env = stack[-4];
    stack[-1] = v_28162;
    goto v_28157;
v_28153:
    v_28163 = stack[-1];
    goto v_28154;
v_28155:
    v_28162 = stack[-3];
    goto v_28156;
v_28157:
    goto v_28153;
v_28154:
    goto v_28155;
v_28156:
    v_28162 = cons(v_28163, v_28162);
    env = stack[-4];
    stack[-3] = v_28162;
    goto v_28139;
v_28141:
v_28139:
    goto v_28103;
v_28102:
    v_28162 = stack[-3];
        return Lnreverse(nil, v_28162);
    return onevalue(v_28162);
}



// Code for polynomlistautoreduce

static LispObject CC_polynomlistautoreduce(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28273, v_28274, v_28275;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_28062;
    stack[-4] = v_28061;
// end of prologue
    v_28273 = nil;
    v_28273 = ncons(v_28273);
    env = stack[-6];
    stack[-5] = v_28273;
v_28075:
    v_28273 = stack[-4];
    v_28273 = qcar(v_28273);
    if (v_28273 == nil) goto v_28078;
    else goto v_28079;
v_28078:
    goto v_28074;
v_28079:
    goto v_28090;
v_28084:
    v_28275 = stack[-5];
    goto v_28085;
v_28086:
    v_28273 = stack[-4];
    v_28274 = qcar(v_28273);
    goto v_28087;
v_28088:
    v_28273 = stack[-3];
    goto v_28089;
v_28090:
    goto v_28084;
v_28085:
    goto v_28086;
v_28087:
    goto v_28088;
v_28089:
    fn = elt(env, 2); // polynomlistreduce
    v_28273 = (*qfnn(fn))(fn, 3, v_28275, v_28274, v_28273);
    env = stack[-6];
    stack[-2] = v_28273;
    goto v_28100;
v_28096:
    goto v_28106;
v_28102:
    v_28274 = stack[-4];
    goto v_28103;
v_28104:
    v_28273 = stack[-4];
    v_28273 = qcdr(v_28273);
    v_28273 = qcar(v_28273);
    goto v_28105;
v_28106:
    goto v_28102;
v_28103:
    goto v_28104;
v_28105:
    v_28274 = Lrplaca(nil, v_28274, v_28273);
    env = stack[-6];
    goto v_28097;
v_28098:
    v_28273 = stack[-4];
    v_28273 = qcdr(v_28273);
    v_28273 = qcdr(v_28273);
    goto v_28099;
v_28100:
    goto v_28096;
v_28097:
    goto v_28098;
v_28099:
    v_28273 = Lrplacd(nil, v_28274, v_28273);
    env = stack[-6];
    v_28273 = stack[-2];
    v_28273 = qcar(v_28273);
    if (v_28273 == nil) goto v_28117;
    v_28273 = stack[-2];
    v_28273 = qcar(v_28273);
    stack[-1] = v_28273;
    v_28273 = stack[-5];
    stack[0] = v_28273;
v_28125:
    v_28273 = stack[0];
    v_28273 = qcar(v_28273);
    if (v_28273 == nil) goto v_28128;
    else goto v_28129;
v_28128:
    goto v_28124;
v_28129:
    goto v_28142;
v_28138:
    v_28273 = stack[0];
    v_28273 = qcar(v_28273);
    v_28274 = qcar(v_28273);
    goto v_28139;
v_28140:
    v_28273 = stack[-1];
    goto v_28141;
v_28142:
    goto v_28138;
v_28139:
    goto v_28140;
v_28141:
    fn = elt(env, 3); // monomisdivisibleby
    v_28273 = (*qfn2(fn))(fn, v_28274, v_28273);
    env = stack[-6];
    if (v_28273 == nil) goto v_28136;
    goto v_28152;
v_28148:
    v_28274 = stack[-4];
    goto v_28149;
v_28150:
    v_28273 = stack[0];
    v_28273 = qcar(v_28273);
    goto v_28151;
v_28152:
    goto v_28148;
v_28149:
    goto v_28150;
v_28151:
    fn = elt(env, 4); // pushback
    v_28273 = (*qfn2(fn))(fn, v_28274, v_28273);
    env = stack[-6];
    goto v_28161;
v_28157:
    goto v_28167;
v_28163:
    v_28274 = stack[0];
    goto v_28164;
v_28165:
    v_28273 = stack[0];
    v_28273 = qcdr(v_28273);
    v_28273 = qcar(v_28273);
    goto v_28166;
v_28167:
    goto v_28163;
v_28164:
    goto v_28165;
v_28166:
    v_28274 = Lrplaca(nil, v_28274, v_28273);
    env = stack[-6];
    goto v_28158;
v_28159:
    v_28273 = stack[0];
    v_28273 = qcdr(v_28273);
    v_28273 = qcdr(v_28273);
    goto v_28160;
v_28161:
    goto v_28157;
v_28158:
    goto v_28159;
v_28160:
    v_28273 = Lrplacd(nil, v_28274, v_28273);
    env = stack[-6];
    goto v_28134;
v_28136:
    v_28273 = stack[0];
    v_28273 = qcdr(v_28273);
    stack[0] = v_28273;
    goto v_28134;
v_28134:
    goto v_28125;
v_28124:
    goto v_28187;
v_28183:
    v_28274 = stack[-5];
    goto v_28184;
v_28185:
    v_28273 = stack[-2];
    goto v_28186;
v_28187:
    goto v_28183;
v_28184:
    goto v_28185;
v_28186:
    fn = elt(env, 4); // pushback
    v_28273 = (*qfn2(fn))(fn, v_28274, v_28273);
    env = stack[-6];
    goto v_28115;
v_28117:
v_28115:
    goto v_28075;
v_28074:
    v_28273 = stack[-5];
    stack[0] = v_28273;
v_28195:
    v_28273 = stack[0];
    v_28273 = qcar(v_28273);
    if (v_28273 == nil) goto v_28198;
    else goto v_28199;
v_28198:
    goto v_28194;
v_28199:
    v_28273 = stack[0];
    v_28273 = qcar(v_28273);
    stack[-2] = v_28273;
    goto v_28210;
v_28206:
    goto v_28216;
v_28212:
    v_28274 = stack[0];
    goto v_28213;
v_28214:
    v_28273 = stack[0];
    v_28273 = qcdr(v_28273);
    v_28273 = qcar(v_28273);
    goto v_28215;
v_28216:
    goto v_28212;
v_28213:
    goto v_28214;
v_28215:
    v_28274 = Lrplaca(nil, v_28274, v_28273);
    env = stack[-6];
    goto v_28207;
v_28208:
    v_28273 = stack[0];
    v_28273 = qcdr(v_28273);
    v_28273 = qcdr(v_28273);
    goto v_28209;
v_28210:
    goto v_28206;
v_28207:
    goto v_28208;
v_28209:
    v_28273 = Lrplacd(nil, v_28274, v_28273);
    env = stack[-6];
    goto v_28231;
v_28225:
    v_28275 = stack[-5];
    goto v_28226;
v_28227:
    v_28274 = stack[-2];
    goto v_28228;
v_28229:
    v_28273 = stack[-3];
    goto v_28230;
v_28231:
    goto v_28225;
v_28226:
    goto v_28227;
v_28228:
    goto v_28229;
v_28230:
    fn = elt(env, 2); // polynomlistreduce
    v_28273 = (*qfnn(fn))(fn, 3, v_28275, v_28274, v_28273);
    env = stack[-6];
    stack[-2] = v_28273;
    v_28273 = stack[-2];
    if (v_28273 == nil) goto v_28238;
    v_28273 = stack[-2];
    v_28273 = qcar(v_28273);
    if (v_28273 == nil) goto v_28238;
    goto v_28249;
v_28245:
    goto v_28255;
v_28251:
    stack[-1] = stack[0];
    goto v_28252;
v_28253:
    goto v_28262;
v_28258:
    v_28273 = stack[0];
    v_28274 = qcar(v_28273);
    goto v_28259;
v_28260:
    v_28273 = stack[0];
    v_28273 = qcdr(v_28273);
    goto v_28261;
v_28262:
    goto v_28258;
v_28259:
    goto v_28260;
v_28261:
    v_28273 = cons(v_28274, v_28273);
    env = stack[-6];
    goto v_28254;
v_28255:
    goto v_28251;
v_28252:
    goto v_28253;
v_28254:
    v_28274 = Lrplacd(nil, stack[-1], v_28273);
    env = stack[-6];
    goto v_28246;
v_28247:
    v_28273 = stack[-2];
    goto v_28248;
v_28249:
    goto v_28245;
v_28246:
    goto v_28247;
v_28248:
    v_28273 = Lrplaca(nil, v_28274, v_28273);
    env = stack[-6];
    v_28273 = stack[0];
    v_28273 = qcdr(v_28273);
    stack[0] = v_28273;
    goto v_28236;
v_28238:
v_28236:
    goto v_28195;
v_28194:
    v_28273 = stack[-5];
    return onevalue(v_28273);
}



// Code for checkexp

static LispObject CC_checkexp(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28100, v_28101, v_28102, v_28103;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28102 = v_28062;
    v_28103 = v_28061;
// end of prologue
    goto v_28072;
v_28068:
    v_28101 = v_28102;
    goto v_28069;
v_28070:
    v_28100 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28071;
v_28072:
    goto v_28068;
v_28069:
    goto v_28070;
v_28071:
    if (v_28101 == v_28100) goto v_28066;
    else goto v_28067;
v_28066:
    v_28100 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28065;
v_28067:
    goto v_28082;
v_28078:
    v_28101 = v_28102;
    goto v_28079;
v_28080:
    v_28100 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28081;
v_28082:
    goto v_28078;
v_28079:
    goto v_28080;
v_28081:
    if (v_28101 == v_28100) goto v_28076;
    else goto v_28077;
v_28076:
    v_28100 = v_28103;
    goto v_28065;
v_28077:
    goto v_28095;
v_28089:
    stack[-1] = elt(env, 1); // expt
    goto v_28090;
v_28091:
    stack[0] = v_28103;
    goto v_28092;
v_28093:
    v_28100 = v_28102;
    fn = elt(env, 2); // preptayexp
    v_28100 = (*qfn1(fn))(fn, v_28100);
    goto v_28094;
v_28095:
    goto v_28089;
v_28090:
    goto v_28091;
v_28092:
    goto v_28093;
v_28094:
    {
        LispObject v_28106 = stack[-1];
        LispObject v_28107 = stack[0];
        return list3(v_28106, v_28107, v_28100);
    }
    v_28100 = nil;
v_28065:
    return onevalue(v_28100);
}



// Code for my_freeof

static LispObject CC_my_freeof(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28090, v_28091, v_28092;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28062;
    stack[-1] = v_28061;
// end of prologue
    goto v_28073;
v_28069:
    v_28091 = stack[0];
    goto v_28070;
v_28071:
    v_28090 = stack[-1];
    goto v_28072;
v_28073:
    goto v_28069;
v_28070:
    goto v_28071;
v_28072:
    fn = elt(env, 2); // smember
    v_28090 = (*qfn2(fn))(fn, v_28091, v_28090);
    env = stack[-2];
    if (v_28090 == nil) goto v_28066;
    else goto v_28067;
v_28066:
    goto v_28083;
v_28077:
    v_28092 = qvalue(elt(env, 1)); // depl!*
    goto v_28078;
v_28079:
    v_28091 = stack[-1];
    goto v_28080;
v_28081:
    v_28090 = stack[0];
    goto v_28082;
v_28083:
    goto v_28077;
v_28078:
    goto v_28079;
v_28080:
    goto v_28081;
v_28082:
    {
        fn = elt(env, 3); // freeofdepl
        return (*qfnn(fn))(fn, 3, v_28092, v_28091, v_28090);
    }
v_28067:
    v_28090 = nil;
    goto v_28065;
    v_28090 = nil;
v_28065:
    return onevalue(v_28090);
}



// Code for talp_simplatlinv

static LispObject CC_talp_simplatlinv(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28098, v_28099, v_28100;
    LispObject fn;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatlinv");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28063,v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28061,v_28062,v_28063);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28063;
    stack[-1] = v_28062;
    stack[-2] = v_28061;
// end of prologue
    v_28098 = stack[-1];
    fn = elt(env, 1); // talp_simplt
    v_28098 = (*qfn1(fn))(fn, v_28098);
    env = stack[-3];
    stack[-1] = v_28098;
    v_28098 = stack[-1];
    fn = elt(env, 2); // talp_invp
    v_28098 = (*qfn1(fn))(fn, v_28098);
    env = stack[-3];
    if (v_28098 == nil) goto v_28070;
    goto v_28080;
v_28074:
    v_28100 = stack[-2];
    goto v_28075;
v_28076:
    v_28099 = stack[-1];
    goto v_28077;
v_28078:
    v_28098 = stack[0];
    goto v_28079;
v_28080:
    goto v_28074;
v_28075:
    goto v_28076;
v_28077:
    goto v_28078;
v_28079:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_28100, v_28099, v_28098);
    }
v_28070:
    goto v_28093;
v_28087:
    goto v_28088;
v_28089:
    goto v_28090;
v_28091:
    v_28098 = stack[0];
    fn = elt(env, 1); // talp_simplt
    v_28098 = (*qfn1(fn))(fn, v_28098);
    env = stack[-3];
    goto v_28092;
v_28093:
    goto v_28087;
v_28088:
    goto v_28089;
v_28090:
    goto v_28091;
v_28092:
    {
        LispObject v_28104 = stack[-2];
        LispObject v_28105 = stack[-1];
        fn = elt(env, 4); // talp_simplat2
        return (*qfnn(fn))(fn, 3, v_28104, v_28105, v_28098);
    }
    v_28098 = nil;
    return onevalue(v_28098);
}



// Code for qqe_simplqneq

static LispObject CC_qqe_simplqneq(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28136, v_28137, v_28138;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_28137 = v_28062;
    v_28136 = v_28061;
// end of prologue
    v_28137 = v_28136;
    v_28137 = qcdr(v_28137);
    v_28137 = qcar(v_28137);
    v_28136 = qcdr(v_28136);
    v_28136 = qcdr(v_28136);
    v_28136 = qcar(v_28136);
    goto v_28085;
v_28081:
    goto v_28093;
v_28087:
    v_28138 = elt(env, 2); // qequal
    goto v_28088;
v_28089:
    goto v_28090;
v_28091:
    goto v_28092;
v_28093:
    goto v_28087;
v_28088:
    goto v_28089;
v_28090:
    goto v_28091;
v_28092:
    fn = elt(env, 6); // qqe_mk2
    v_28137 = (*qfnn(fn))(fn, 3, v_28138, v_28137, v_28136);
    env = stack[-3];
    goto v_28082;
v_28083:
    v_28136 = nil;
    goto v_28084;
v_28085:
    goto v_28081;
v_28082:
    goto v_28083;
v_28084:
    fn = elt(env, 7); // qqe_simplqequal
    v_28136 = (*qfn2(fn))(fn, v_28137, v_28136);
    env = stack[-3];
    stack[-2] = v_28136;
    goto v_28106;
v_28102:
    v_28137 = stack[-2];
    goto v_28103;
v_28104:
    v_28136 = elt(env, 3); // true
    goto v_28105;
v_28106:
    goto v_28102;
v_28103:
    goto v_28104;
v_28105:
    if (v_28137 == v_28136) goto v_28100;
    else goto v_28101;
v_28100:
    v_28136 = elt(env, 4); // false
    goto v_28099;
v_28101:
    goto v_28116;
v_28112:
    v_28137 = stack[-2];
    goto v_28113;
v_28114:
    v_28136 = elt(env, 4); // false
    goto v_28115;
v_28116:
    goto v_28112;
v_28113:
    goto v_28114;
v_28115:
    if (v_28137 == v_28136) goto v_28110;
    else goto v_28111;
v_28110:
    v_28136 = elt(env, 3); // true
    goto v_28099;
v_28111:
    goto v_28129;
v_28123:
    stack[-1] = elt(env, 5); // qneq
    goto v_28124;
v_28125:
    v_28136 = stack[-2];
    fn = elt(env, 8); // qqe_arg2l
    stack[0] = (*qfn1(fn))(fn, v_28136);
    env = stack[-3];
    goto v_28126;
v_28127:
    v_28136 = stack[-2];
    fn = elt(env, 9); // qqe_arg2r
    v_28136 = (*qfn1(fn))(fn, v_28136);
    env = stack[-3];
    goto v_28128;
v_28129:
    goto v_28123;
v_28124:
    goto v_28125;
v_28126:
    goto v_28127;
v_28128:
    fn = elt(env, 6); // qqe_mk2
    v_28136 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_28136);
    goto v_28099;
v_28099:
    return onevalue(v_28136);
}



// Code for gb_searchinlist

static LispObject CC_gb_searchinlist(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28091, v_28092;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28062;
    stack[-1] = v_28061;
// end of prologue
v_28066:
    v_28091 = stack[0];
    if (v_28091 == nil) goto v_28069;
    else goto v_28070;
v_28069:
    v_28091 = nil;
    goto v_28065;
v_28070:
    goto v_28080;
v_28076:
    v_28091 = stack[0];
    v_28091 = qcar(v_28091);
    fn = elt(env, 1); // vdp_evlmon
    v_28092 = (*qfn1(fn))(fn, v_28091);
    env = stack[-2];
    goto v_28077;
v_28078:
    v_28091 = stack[-1];
    goto v_28079;
v_28080:
    goto v_28076;
v_28077:
    goto v_28078;
v_28079:
    fn = elt(env, 2); // gb_buch!-ev_divides!?
    v_28091 = (*qfn2(fn))(fn, v_28092, v_28091);
    env = stack[-2];
    if (v_28091 == nil) goto v_28074;
    v_28091 = stack[0];
    v_28091 = qcar(v_28091);
    goto v_28065;
v_28074:
    v_28091 = stack[0];
    v_28091 = qcdr(v_28091);
    stack[0] = v_28091;
    goto v_28066;
    v_28091 = nil;
v_28065:
    return onevalue(v_28091);
}



// Code for cnml

static LispObject CC_cnml(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28083, v_28084;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28061;
// end of prologue
    v_28083 = elt(env, 1); // "<cn"
    fn = elt(env, 4); // printout
    v_28083 = (*qfn1(fn))(fn, v_28083);
    env = stack[-1];
    goto v_28073;
v_28069:
    v_28083 = stack[0];
    v_28084 = qcar(v_28083);
    goto v_28070;
v_28071:
    v_28083 = elt(env, 2); // ""
    goto v_28072;
v_28073:
    goto v_28069;
v_28070:
    goto v_28071;
v_28072:
    fn = elt(env, 5); // attributesml
    v_28083 = (*qfn2(fn))(fn, v_28084, v_28083);
    env = stack[-1];
    v_28083 = stack[0];
    v_28083 = qcdr(v_28083);
    v_28083 = qcar(v_28083);
    v_28083 = Lprinc(nil, v_28083);
    env = stack[-1];
    v_28083 = elt(env, 3); // "</cn>"
    v_28083 = Lprinc(nil, v_28083);
    v_28083 = nil;
    return onevalue(v_28083);
}



// Code for newsym1

static LispObject CC_newsym1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28079, v_28080;
    argcheck(nargs, 0, "newsym1");
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
    v_28079 = qvalue(elt(env, 2)); // cindex!*
    v_28079 = Lexplode(nil, v_28079);
    env = stack[-1];
    stack[0] = v_28079;
    v_28079 = qvalue(elt(env, 2)); // cindex!*
    v_28079 = add1(v_28079);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_28079; // cindex!*
    goto v_28076;
v_28072:
    v_28080 = qvalue(elt(env, 3)); // cname!*
    goto v_28073;
v_28074:
    v_28079 = stack[0];
    goto v_28075;
v_28076:
    goto v_28072;
v_28073:
    goto v_28074;
v_28075:
    v_28079 = Lappend(nil, v_28080, v_28079);
        return Lcompress(nil, v_28079);
    return onevalue(v_28079);
}



// Code for groebcplistmerge

static LispObject CC_groebcplistmerge(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28133, v_28134;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_28062;
    stack[-2] = v_28061;
// end of prologue
    v_28133 = stack[-2];
    if (v_28133 == nil) goto v_28072;
    else goto v_28073;
v_28072:
    v_28133 = stack[-1];
    goto v_28068;
v_28073:
    v_28133 = stack[-1];
    if (v_28133 == nil) goto v_28078;
    else goto v_28079;
v_28078:
    v_28133 = stack[-2];
    goto v_28068;
v_28079:
    v_28133 = stack[-2];
    v_28133 = qcar(v_28133);
    stack[-3] = v_28133;
    v_28133 = stack[-1];
    v_28133 = qcar(v_28133);
    stack[0] = v_28133;
    goto v_28091;
v_28087:
    v_28134 = stack[-3];
    goto v_28088;
v_28089:
    v_28133 = stack[0];
    goto v_28090;
v_28091:
    goto v_28087;
v_28088:
    goto v_28089;
v_28090:
    fn = elt(env, 2); // groebcpcompless!?
    v_28133 = (*qfn2(fn))(fn, v_28134, v_28133);
    env = stack[-4];
    if (v_28133 == nil) goto v_28097;
    goto v_28104;
v_28100:
    stack[0] = stack[-3];
    goto v_28101;
v_28102:
    goto v_28111;
v_28107:
    v_28133 = stack[-2];
    v_28134 = qcdr(v_28133);
    goto v_28108;
v_28109:
    v_28133 = stack[-1];
    goto v_28110;
v_28111:
    goto v_28107;
v_28108:
    goto v_28109;
v_28110:
    v_28133 = CC_groebcplistmerge(elt(env, 0), v_28134, v_28133);
    goto v_28103;
v_28104:
    goto v_28100;
v_28101:
    goto v_28102;
v_28103:
    {
        LispObject v_28139 = stack[0];
        return cons(v_28139, v_28133);
    }
v_28097:
    goto v_28122;
v_28118:
    goto v_28119;
v_28120:
    goto v_28129;
v_28125:
    v_28134 = stack[-2];
    goto v_28126;
v_28127:
    v_28133 = stack[-1];
    v_28133 = qcdr(v_28133);
    goto v_28128;
v_28129:
    goto v_28125;
v_28126:
    goto v_28127;
v_28128:
    v_28133 = CC_groebcplistmerge(elt(env, 0), v_28134, v_28133);
    goto v_28121;
v_28122:
    goto v_28118;
v_28119:
    goto v_28120;
v_28121:
    {
        LispObject v_28140 = stack[0];
        return cons(v_28140, v_28133);
    }
    v_28133 = nil;
v_28068:
    return onevalue(v_28133);
}



// Code for xregister_spoly_pair

static LispObject CC_xregister_spoly_pair(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28063;
    argcheck(nargs, 0, "xregister_spoly_pair");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_28063 = nil;
    return onevalue(v_28063);
}



// Code for mkforttab

static LispObject CC_mkforttab(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28077, v_28078;
    argcheck(nargs, 0, "mkforttab");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// end of prologue
    goto v_28067;
v_28063:
    stack[0] = elt(env, 1); // forttab
    goto v_28064;
v_28065:
    goto v_28074;
v_28070:
    v_28078 = qvalue(elt(env, 2)); // fortcurrind!*
    goto v_28071;
v_28072:
    v_28077 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_28073;
v_28074:
    goto v_28070;
v_28071:
    goto v_28072;
v_28073:
    v_28077 = plus2(v_28078, v_28077);
    goto v_28066;
v_28067:
    goto v_28063;
v_28064:
    goto v_28065;
v_28066:
    {
        LispObject v_28080 = stack[0];
        return list2(v_28080, v_28077);
    }
}



// Code for asymmetrize!-inds

static LispObject CC_asymmetrizeKinds(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28399, v_28400;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_28062;
    stack[-9] = v_28061;
// end of prologue
    v_28399 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-10] = v_28399;
    v_28399 = stack[-9];
    stack[-7] = v_28399;
    v_28399 = stack[-7];
    if (v_28399 == nil) goto v_28083;
    else goto v_28084;
v_28083:
    v_28399 = nil;
    goto v_28078;
v_28084:
    v_28399 = stack[-7];
    v_28399 = qcar(v_28399);
    v_28400 = v_28399;
    if (!consp(v_28400)) goto v_28093;
    else goto v_28094;
v_28093:
    goto v_28101;
v_28097:
    v_28400 = stack[-8];
    goto v_28098;
v_28099:
    goto v_28100;
v_28101:
    goto v_28097;
v_28098:
    goto v_28099;
v_28100:
    fn = elt(env, 2); // nth
    v_28399 = (*qfn2(fn))(fn, v_28400, v_28399);
    env = stack[-11];
    goto v_28092;
v_28094:
    stack[-3] = v_28399;
    v_28399 = stack[-3];
    if (v_28399 == nil) goto v_28115;
    else goto v_28116;
v_28115:
    v_28399 = nil;
    goto v_28110;
v_28116:
    v_28399 = stack[-3];
    v_28399 = qcar(v_28399);
    goto v_28128;
v_28124:
    v_28400 = stack[-8];
    goto v_28125;
v_28126:
    goto v_28127;
v_28128:
    goto v_28124;
v_28125:
    goto v_28126;
v_28127:
    fn = elt(env, 2); // nth
    v_28399 = (*qfn2(fn))(fn, v_28400, v_28399);
    env = stack[-11];
    v_28399 = ncons(v_28399);
    env = stack[-11];
    stack[-1] = v_28399;
    stack[-2] = v_28399;
v_28111:
    v_28399 = stack[-3];
    v_28399 = qcdr(v_28399);
    stack[-3] = v_28399;
    v_28399 = stack[-3];
    if (v_28399 == nil) goto v_28135;
    else goto v_28136;
v_28135:
    v_28399 = stack[-2];
    goto v_28110;
v_28136:
    goto v_28144;
v_28140:
    stack[0] = stack[-1];
    goto v_28141;
v_28142:
    v_28399 = stack[-3];
    v_28399 = qcar(v_28399);
    goto v_28155;
v_28151:
    v_28400 = stack[-8];
    goto v_28152;
v_28153:
    goto v_28154;
v_28155:
    goto v_28151;
v_28152:
    goto v_28153;
v_28154:
    fn = elt(env, 2); // nth
    v_28399 = (*qfn2(fn))(fn, v_28400, v_28399);
    env = stack[-11];
    v_28399 = ncons(v_28399);
    env = stack[-11];
    goto v_28143;
v_28144:
    goto v_28140;
v_28141:
    goto v_28142;
v_28143:
    v_28399 = Lrplacd(nil, stack[0], v_28399);
    env = stack[-11];
    v_28399 = stack[-1];
    v_28399 = qcdr(v_28399);
    stack[-1] = v_28399;
    goto v_28111;
v_28110:
    goto v_28092;
    v_28399 = nil;
v_28092:
    v_28399 = ncons(v_28399);
    env = stack[-11];
    stack[-5] = v_28399;
    stack[-6] = v_28399;
v_28079:
    v_28399 = stack[-7];
    v_28399 = qcdr(v_28399);
    stack[-7] = v_28399;
    v_28399 = stack[-7];
    if (v_28399 == nil) goto v_28164;
    else goto v_28165;
v_28164:
    v_28399 = stack[-6];
    goto v_28078;
v_28165:
    goto v_28173;
v_28169:
    stack[-4] = stack[-5];
    goto v_28170;
v_28171:
    v_28399 = stack[-7];
    v_28399 = qcar(v_28399);
    v_28400 = v_28399;
    if (!consp(v_28400)) goto v_28181;
    else goto v_28182;
v_28181:
    goto v_28189;
v_28185:
    v_28400 = stack[-8];
    goto v_28186;
v_28187:
    goto v_28188;
v_28189:
    goto v_28185;
v_28186:
    goto v_28187;
v_28188:
    fn = elt(env, 2); // nth
    v_28399 = (*qfn2(fn))(fn, v_28400, v_28399);
    env = stack[-11];
    goto v_28180;
v_28182:
    stack[-3] = v_28399;
    v_28399 = stack[-3];
    if (v_28399 == nil) goto v_28203;
    else goto v_28204;
v_28203:
    v_28399 = nil;
    goto v_28198;
v_28204:
    v_28399 = stack[-3];
    v_28399 = qcar(v_28399);
    goto v_28216;
v_28212:
    v_28400 = stack[-8];
    goto v_28213;
v_28214:
    goto v_28215;
v_28216:
    goto v_28212;
v_28213:
    goto v_28214;
v_28215:
    fn = elt(env, 2); // nth
    v_28399 = (*qfn2(fn))(fn, v_28400, v_28399);
    env = stack[-11];
    v_28399 = ncons(v_28399);
    env = stack[-11];
    stack[-1] = v_28399;
    stack[-2] = v_28399;
v_28199:
    v_28399 = stack[-3];
    v_28399 = qcdr(v_28399);
    stack[-3] = v_28399;
    v_28399 = stack[-3];
    if (v_28399 == nil) goto v_28223;
    else goto v_28224;
v_28223:
    v_28399 = stack[-2];
    goto v_28198;
v_28224:
    goto v_28232;
v_28228:
    stack[0] = stack[-1];
    goto v_28229;
v_28230:
    v_28399 = stack[-3];
    v_28399 = qcar(v_28399);
    goto v_28243;
v_28239:
    v_28400 = stack[-8];
    goto v_28240;
v_28241:
    goto v_28242;
v_28243:
    goto v_28239;
v_28240:
    goto v_28241;
v_28242:
    fn = elt(env, 2); // nth
    v_28399 = (*qfn2(fn))(fn, v_28400, v_28399);
    env = stack[-11];
    v_28399 = ncons(v_28399);
    env = stack[-11];
    goto v_28231;
v_28232:
    goto v_28228;
v_28229:
    goto v_28230;
v_28231:
    v_28399 = Lrplacd(nil, stack[0], v_28399);
    env = stack[-11];
    v_28399 = stack[-1];
    v_28399 = qcdr(v_28399);
    stack[-1] = v_28399;
    goto v_28199;
v_28198:
    goto v_28180;
    v_28399 = nil;
v_28180:
    v_28399 = ncons(v_28399);
    env = stack[-11];
    goto v_28172;
v_28173:
    goto v_28169;
v_28170:
    goto v_28171;
v_28172:
    v_28399 = Lrplacd(nil, stack[-4], v_28399);
    env = stack[-11];
    v_28399 = stack[-5];
    v_28399 = qcdr(v_28399);
    stack[-5] = v_28399;
    goto v_28079;
v_28078:
    stack[0] = v_28399;
    v_28399 = stack[0];
    fn = elt(env, 3); // repeats
    v_28399 = (*qfn1(fn))(fn, v_28399);
    env = stack[-11];
    if (v_28399 == nil) goto v_28253;
    v_28399 = nil;
    goto v_28070;
v_28253:
    goto v_28266;
v_28262:
    v_28399 = stack[0];
    v_28399 = qcar(v_28399);
    if (!consp(v_28399)) goto v_28269;
    else goto v_28270;
v_28269:
    v_28399 = stack[0];
    fn = elt(env, 4); // indordn
    v_28399 = (*qfn1(fn))(fn, v_28399);
    env = stack[-11];
    v_28400 = v_28399;
    goto v_28268;
v_28270:
    v_28399 = stack[0];
    fn = elt(env, 5); // indordln
    v_28399 = (*qfn1(fn))(fn, v_28399);
    env = stack[-11];
    v_28400 = v_28399;
    goto v_28268;
    v_28400 = nil;
v_28268:
    stack[-5] = v_28400;
    goto v_28263;
v_28264:
    v_28399 = stack[0];
    goto v_28265;
v_28266:
    goto v_28262;
v_28263:
    goto v_28264;
v_28265:
    fn = elt(env, 6); // permp
    v_28399 = (*qfn2(fn))(fn, v_28400, v_28399);
    env = stack[-11];
    if (v_28399 == nil) goto v_28260;
    v_28399 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28258;
v_28260:
    v_28399 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_28258;
    v_28399 = nil;
v_28258:
    stack[0] = v_28399;
    v_28399 = stack[-9];
    v_28399 = qcar(v_28399);
    if (!consp(v_28399)) goto v_28287;
    v_28399 = stack[-9];
    fn = elt(env, 7); // flatindl
    v_28399 = (*qfn1(fn))(fn, v_28399);
    env = stack[-11];
    stack[-9] = v_28399;
    v_28399 = stack[-5];
    fn = elt(env, 7); // flatindl
    v_28399 = (*qfn1(fn))(fn, v_28399);
    env = stack[-11];
    stack[-5] = v_28399;
    goto v_28285;
v_28287:
v_28285:
    goto v_28299;
v_28295:
    v_28400 = stack[-9];
    goto v_28296;
v_28297:
    v_28399 = stack[-5];
    goto v_28298;
v_28299:
    goto v_28295;
v_28296:
    goto v_28297;
v_28298:
    fn = elt(env, 8); // pair
    v_28399 = (*qfn2(fn))(fn, v_28400, v_28399);
    env = stack[-11];
    stack[-5] = v_28399;
    goto v_28307;
v_28303:
    stack[-6] = stack[0];
    goto v_28304;
v_28305:
    v_28399 = stack[-8];
    stack[-7] = v_28399;
    v_28399 = stack[-7];
    if (v_28399 == nil) goto v_28318;
    else goto v_28319;
v_28318:
    v_28399 = nil;
    goto v_28313;
v_28319:
    v_28399 = stack[-7];
    v_28399 = qcar(v_28399);
    stack[-1] = v_28399;
    v_28399 = stack[-5];
    if (v_28399 == nil) goto v_28329;
    goto v_28337;
v_28333:
    v_28399 = stack[-5];
    v_28399 = qcar(v_28399);
    stack[0] = qcar(v_28399);
    goto v_28334;
v_28335:
    v_28399 = stack[-10];
    v_28399 = add1(v_28399);
    env = stack[-11];
    stack[-10] = v_28399;
    goto v_28336;
v_28337:
    goto v_28333;
v_28334:
    goto v_28335;
v_28336:
    if (equal(stack[0], v_28399)) goto v_28332;
    else goto v_28329;
v_28332:
    v_28399 = stack[-5];
    v_28399 = qcar(v_28399);
    v_28399 = qcdr(v_28399);
    v_28400 = v_28399;
    v_28399 = stack[-5];
    v_28399 = qcdr(v_28399);
    stack[-5] = v_28399;
    v_28399 = v_28400;
    goto v_28327;
v_28329:
    v_28399 = stack[-1];
    goto v_28327;
    v_28399 = nil;
v_28327:
    v_28399 = ncons(v_28399);
    env = stack[-11];
    stack[-3] = v_28399;
    stack[-4] = v_28399;
v_28314:
    v_28399 = stack[-7];
    v_28399 = qcdr(v_28399);
    stack[-7] = v_28399;
    v_28399 = stack[-7];
    if (v_28399 == nil) goto v_28356;
    else goto v_28357;
v_28356:
    v_28399 = stack[-4];
    goto v_28313;
v_28357:
    goto v_28365;
v_28361:
    stack[-2] = stack[-3];
    goto v_28362;
v_28363:
    v_28399 = stack[-7];
    v_28399 = qcar(v_28399);
    stack[-1] = v_28399;
    v_28399 = stack[-5];
    if (v_28399 == nil) goto v_28374;
    goto v_28382;
v_28378:
    v_28399 = stack[-5];
    v_28399 = qcar(v_28399);
    stack[0] = qcar(v_28399);
    goto v_28379;
v_28380:
    v_28399 = stack[-10];
    v_28399 = add1(v_28399);
    env = stack[-11];
    stack[-10] = v_28399;
    goto v_28381;
v_28382:
    goto v_28378;
v_28379:
    goto v_28380;
v_28381:
    if (equal(stack[0], v_28399)) goto v_28377;
    else goto v_28374;
v_28377:
    v_28399 = stack[-5];
    v_28399 = qcar(v_28399);
    v_28399 = qcdr(v_28399);
    v_28400 = v_28399;
    v_28399 = stack[-5];
    v_28399 = qcdr(v_28399);
    stack[-5] = v_28399;
    v_28399 = v_28400;
    goto v_28372;
v_28374:
    v_28399 = stack[-1];
    goto v_28372;
    v_28399 = nil;
v_28372:
    v_28399 = ncons(v_28399);
    env = stack[-11];
    goto v_28364;
v_28365:
    goto v_28361;
v_28362:
    goto v_28363;
v_28364:
    v_28399 = Lrplacd(nil, stack[-2], v_28399);
    env = stack[-11];
    v_28399 = stack[-3];
    v_28399 = qcdr(v_28399);
    stack[-3] = v_28399;
    goto v_28314;
v_28313:
    goto v_28306;
v_28307:
    goto v_28303;
v_28304:
    goto v_28305;
v_28306:
    {
        LispObject v_28412 = stack[-6];
        return cons(v_28412, v_28399);
    }
v_28070:
    return onevalue(v_28399);
}



// Code for split!-comfac!-part

static LispObject CC_splitKcomfacKpart(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28074, v_28075, v_28076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28074 = v_28061;
// end of prologue
    goto v_28070;
v_28064:
    v_28076 = v_28074;
    goto v_28065;
v_28066:
    v_28075 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28067;
v_28068:
    v_28074 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28069;
v_28070:
    goto v_28064;
v_28065:
    goto v_28066;
v_28067:
    goto v_28068;
v_28069:
    {
        fn = elt(env, 1); // split!-comfac
        return (*qfnn(fn))(fn, 3, v_28076, v_28075, v_28074);
    }
}



// Code for mv!-compact

static LispObject CC_mvKcompact(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28212, v_28213, v_28214;
    LispObject fn;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mv-compact");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28063,v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28061,v_28062,v_28063);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_28063;
    stack[-2] = v_28062;
    stack[-3] = v_28061;
// end of prologue
v_28060:
    v_28212 = stack[-3];
    if (v_28212 == nil) goto v_28072;
    else goto v_28073;
v_28072:
    v_28212 = stack[-1];
    {
        fn = elt(env, 2); // mv!-reverse
        return (*qfn1(fn))(fn, v_28212);
    }
v_28073:
    goto v_28087;
v_28083:
    v_28213 = stack[-3];
    goto v_28084;
v_28085:
    v_28212 = stack[-2];
    goto v_28086;
v_28087:
    goto v_28083;
v_28084:
    goto v_28085;
v_28086:
    fn = elt(env, 3); // mv!-pow!-chk
    v_28212 = (*qfn2(fn))(fn, v_28213, v_28212);
    env = stack[-5];
    stack[-4] = v_28212;
    if (v_28212 == nil) goto v_28080;
    goto v_28096;
v_28092:
    stack[0] = stack[-3];
    goto v_28093;
v_28094:
    goto v_28103;
v_28099:
    v_28213 = stack[-4];
    goto v_28100;
v_28101:
    v_28212 = stack[-2];
    goto v_28102;
v_28103:
    goto v_28099;
v_28100:
    goto v_28101;
v_28102:
    fn = elt(env, 4); // mv!-pow!-mv!-!+
    v_28212 = (*qfn2(fn))(fn, v_28213, v_28212);
    env = stack[-5];
    goto v_28095;
v_28096:
    goto v_28092;
v_28093:
    goto v_28094;
v_28095:
    fn = elt(env, 5); // mv!-compact2
    v_28212 = (*qfn2(fn))(fn, stack[0], v_28212);
    env = stack[-5];
    stack[0] = v_28212;
    if (v_28212 == nil) goto v_28080;
    goto v_28113;
v_28107:
    v_28214 = stack[0];
    goto v_28108;
v_28109:
    v_28213 = stack[-2];
    goto v_28110;
v_28111:
    v_28212 = stack[-1];
    goto v_28112;
v_28113:
    goto v_28107;
v_28108:
    goto v_28109;
v_28110:
    goto v_28111;
v_28112:
    stack[-3] = v_28214;
    stack[-2] = v_28213;
    stack[-1] = v_28212;
    goto v_28060;
v_28080:
    goto v_28125;
v_28121:
    v_28213 = stack[-3];
    goto v_28122;
v_28123:
    v_28212 = stack[-2];
    v_28212 = qcdr(v_28212);
    goto v_28124;
v_28125:
    goto v_28121;
v_28122:
    goto v_28123;
v_28124:
    fn = elt(env, 3); // mv!-pow!-chk
    v_28212 = (*qfn2(fn))(fn, v_28213, v_28212);
    env = stack[-5];
    stack[-4] = v_28212;
    if (v_28212 == nil) goto v_28118;
    goto v_28139;
v_28135:
    goto v_28145;
v_28141:
    v_28213 = stack[-4];
    goto v_28142;
v_28143:
    v_28212 = stack[-2];
    v_28212 = qcar(v_28212);
    v_28212 = qcar(v_28212);
    goto v_28144;
v_28145:
    goto v_28141;
v_28142:
    goto v_28143;
v_28144:
    fn = elt(env, 6); // mv!-pow!-!+
    v_28213 = (*qfn2(fn))(fn, v_28213, v_28212);
    env = stack[-5];
    stack[0] = v_28213;
    goto v_28136;
v_28137:
    v_28212 = stack[-1];
    goto v_28138;
v_28139:
    goto v_28135;
v_28136:
    goto v_28137;
v_28138:
    fn = elt(env, 7); // mv!-pow!-assoc
    v_28212 = (*qfn2(fn))(fn, v_28213, v_28212);
    env = stack[-5];
    if (v_28212 == nil) goto v_28132;
    else goto v_28133;
v_28132:
    goto v_28156;
v_28152:
    goto v_28164;
v_28158:
    v_28214 = stack[0];
    goto v_28159;
v_28160:
    v_28213 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28161;
v_28162:
    v_28212 = stack[-3];
    goto v_28163;
v_28164:
    goto v_28158;
v_28159:
    goto v_28160;
v_28161:
    goto v_28162;
v_28163:
    stack[0] = acons(v_28214, v_28213, v_28212);
    env = stack[-5];
    goto v_28153;
v_28154:
    goto v_28173;
v_28169:
    v_28213 = stack[-4];
    goto v_28170;
v_28171:
    v_28212 = stack[-2];
    goto v_28172;
v_28173:
    goto v_28169;
v_28170:
    goto v_28171;
v_28172:
    fn = elt(env, 4); // mv!-pow!-mv!-!+
    v_28212 = (*qfn2(fn))(fn, v_28213, v_28212);
    env = stack[-5];
    goto v_28155;
v_28156:
    goto v_28152;
v_28153:
    goto v_28154;
v_28155:
    fn = elt(env, 5); // mv!-compact2
    v_28212 = (*qfn2(fn))(fn, stack[0], v_28212);
    env = stack[-5];
    stack[0] = v_28212;
    goto v_28131;
v_28133:
    v_28212 = nil;
    goto v_28131;
    v_28212 = nil;
v_28131:
    if (v_28212 == nil) goto v_28118;
    goto v_28186;
v_28180:
    v_28214 = stack[0];
    goto v_28181;
v_28182:
    v_28213 = stack[-2];
    goto v_28183;
v_28184:
    v_28212 = stack[-1];
    goto v_28185;
v_28186:
    goto v_28180;
v_28181:
    goto v_28182;
v_28183:
    goto v_28184;
v_28185:
    stack[-3] = v_28214;
    stack[-2] = v_28213;
    stack[-1] = v_28212;
    goto v_28060;
v_28118:
    goto v_28199;
v_28193:
    v_28212 = stack[-3];
    stack[0] = qcdr(v_28212);
    goto v_28194;
v_28195:
    goto v_28196;
v_28197:
    goto v_28208;
v_28204:
    v_28212 = stack[-3];
    v_28213 = qcar(v_28212);
    goto v_28205;
v_28206:
    v_28212 = stack[-1];
    goto v_28207;
v_28208:
    goto v_28204;
v_28205:
    goto v_28206;
v_28207:
    v_28212 = cons(v_28213, v_28212);
    env = stack[-5];
    goto v_28198;
v_28199:
    goto v_28193;
v_28194:
    goto v_28195;
v_28196:
    goto v_28197;
v_28198:
    stack[-3] = stack[0];
    stack[-1] = v_28212;
    goto v_28060;
    v_28212 = nil;
    return onevalue(v_28212);
}



// Code for simp!-prop

static LispObject CC_simpKprop(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28282, v_28283, v_28284;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_28061;
// end of prologue
// Binding propvars!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // propvars!*
    v_28282 = stack[-2];
    v_28282 = qcdr(v_28282);
    stack[-4] = v_28282;
    v_28282 = stack[-4];
    if (v_28282 == nil) goto v_28079;
    else goto v_28080;
v_28079:
    v_28282 = nil;
    goto v_28073;
v_28080:
    v_28282 = stack[-4];
    v_28282 = qcar(v_28282);
    fn = elt(env, 13); // reval
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    v_28282 = ncons(v_28282);
    env = stack[-7];
    stack[-1] = v_28282;
    stack[-3] = v_28282;
v_28074:
    v_28282 = stack[-4];
    v_28282 = qcdr(v_28282);
    stack[-4] = v_28282;
    v_28282 = stack[-4];
    if (v_28282 == nil) goto v_28093;
    else goto v_28094;
v_28093:
    v_28282 = stack[-3];
    goto v_28073;
v_28094:
    goto v_28102;
v_28098:
    stack[0] = stack[-1];
    goto v_28099;
v_28100:
    v_28282 = stack[-4];
    v_28282 = qcar(v_28282);
    fn = elt(env, 13); // reval
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    v_28282 = ncons(v_28282);
    env = stack[-7];
    goto v_28101;
v_28102:
    goto v_28098;
v_28099:
    goto v_28100;
v_28101:
    v_28282 = Lrplacd(nil, stack[0], v_28282);
    env = stack[-7];
    v_28282 = stack[-1];
    v_28282 = qcdr(v_28282);
    stack[-1] = v_28282;
    goto v_28074;
v_28073:
    stack[-5] = v_28282;
    goto v_28120;
v_28116:
    v_28283 = elt(env, 3); // and
    goto v_28117;
v_28118:
    v_28282 = stack[-5];
    goto v_28119;
v_28120:
    goto v_28116;
v_28117:
    goto v_28118;
v_28119:
    v_28282 = Lmember(nil, v_28283, v_28282);
    if (v_28282 == nil) goto v_28115;
    v_28282 = elt(env, 4); // or
    qvalue(elt(env, 5)) = v_28282; // !'and
    v_28282 = elt(env, 3); // and
    qvalue(elt(env, 6)) = v_28282; // !'or
    v_28282 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 7)) = v_28282; // !'true
    v_28282 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 8)) = v_28282; // !'false
    goto v_28113;
v_28115:
    v_28282 = elt(env, 3); // and
    qvalue(elt(env, 5)) = v_28282; // !'and
    v_28282 = elt(env, 4); // or
    qvalue(elt(env, 6)) = v_28282; // !'or
    v_28282 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 7)) = v_28282; // !'true
    v_28282 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 8)) = v_28282; // !'false
    goto v_28113;
v_28113:
    goto v_28143;
v_28139:
    v_28282 = stack[-2];
    v_28283 = qcar(v_28282);
    goto v_28140;
v_28141:
    v_28282 = lisp_true;
    goto v_28142;
v_28143:
    goto v_28139;
v_28140:
    goto v_28141;
v_28142:
    fn = elt(env, 14); // simp!-prop1
    v_28282 = (*qfn2(fn))(fn, v_28283, v_28282);
    env = stack[-7];
    fn = elt(env, 15); // prepf
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    fn = elt(env, 13); // reval
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    v_28284 = v_28282;
    goto v_28155;
v_28151:
    v_28283 = v_28284;
    goto v_28152;
v_28153:
    v_28282 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28154;
v_28155:
    goto v_28151;
v_28152:
    goto v_28153;
v_28154:
    if (v_28283 == v_28282) goto v_28149;
    else goto v_28150;
v_28149:
    v_28282 = qvalue(elt(env, 8)); // !'false
    fn = elt(env, 16); // simp
    v_28282 = (*qfn1(fn))(fn, v_28282);
    goto v_28067;
v_28150:
    v_28282 = qvalue(elt(env, 1)); // propvars!*
    stack[-4] = v_28282;
v_28163:
    v_28282 = stack[-4];
    if (v_28282 == nil) goto v_28167;
    else goto v_28168;
v_28167:
    goto v_28162;
v_28168:
    v_28282 = stack[-4];
    v_28282 = qcar(v_28282);
    goto v_28182;
v_28176:
    stack[-3] = elt(env, 9); // times
    goto v_28177;
v_28178:
    stack[-2] = v_28284;
    goto v_28179;
v_28180:
    goto v_28191;
v_28187:
    goto v_28199;
v_28193:
    stack[-1] = qvalue(elt(env, 6)); // !'or
    goto v_28194;
v_28195:
    stack[0] = v_28282;
    goto v_28196;
v_28197:
    goto v_28207;
v_28203:
    v_28283 = elt(env, 10); // not
    goto v_28204;
v_28205:
    goto v_28206;
v_28207:
    goto v_28203;
v_28204:
    goto v_28205;
v_28206:
    v_28282 = list2(v_28283, v_28282);
    env = stack[-7];
    goto v_28198;
v_28199:
    goto v_28193;
v_28194:
    goto v_28195;
v_28196:
    goto v_28197;
v_28198:
    v_28283 = list3(stack[-1], stack[0], v_28282);
    env = stack[-7];
    goto v_28188;
v_28189:
    v_28282 = lisp_true;
    goto v_28190;
v_28191:
    goto v_28187;
v_28188:
    goto v_28189;
v_28190:
    fn = elt(env, 14); // simp!-prop1
    v_28282 = (*qfn2(fn))(fn, v_28283, v_28282);
    env = stack[-7];
    fn = elt(env, 15); // prepf
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    goto v_28181;
v_28182:
    goto v_28176;
v_28177:
    goto v_28178;
v_28179:
    goto v_28180;
v_28181:
    v_28282 = list3(stack[-3], stack[-2], v_28282);
    env = stack[-7];
    fn = elt(env, 13); // reval
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    v_28284 = v_28282;
    v_28282 = stack[-4];
    v_28282 = qcdr(v_28282);
    stack[-4] = v_28282;
    goto v_28163;
v_28162:
    v_28282 = v_28284;
    fn = elt(env, 17); // simp!-prop!-dist
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    v_28284 = v_28282;
    goto v_28223;
v_28219:
    v_28283 = elt(env, 11); // full
    goto v_28220;
v_28221:
    v_28282 = stack[-5];
    goto v_28222;
v_28223:
    goto v_28219;
v_28220:
    goto v_28221;
v_28222:
    v_28282 = Lmember(nil, v_28283, v_28282);
    if (v_28282 == nil) goto v_28217;
    else goto v_28218;
v_28217:
    v_28282 = v_28284;
    fn = elt(env, 18); // simp!-prop2
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    v_28284 = v_28282;
    goto v_28216;
v_28218:
v_28216:
    v_28282 = v_28284;
    fn = elt(env, 19); // simp!-prop!-form
    v_28282 = (*qfn1(fn))(fn, v_28282);
    env = stack[-7];
    v_28284 = v_28282;
    v_28282 = v_28284;
    if (is_number(v_28282)) goto v_28233;
    else goto v_28234;
v_28233:
    goto v_28241;
v_28237:
    v_28283 = v_28284;
    goto v_28238;
v_28239:
    v_28282 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28240;
v_28241:
    goto v_28237;
v_28238:
    goto v_28239;
v_28240:
    v_28282 = cons(v_28283, v_28282);
    goto v_28067;
v_28234:
    v_28282 = v_28284;
    if (!consp(v_28282)) goto v_28247;
    goto v_28254;
v_28250:
    v_28282 = elt(env, 12); // boolean
    goto v_28251;
v_28252:
    v_28283 = v_28284;
    goto v_28253;
v_28254:
    goto v_28250;
v_28251:
    goto v_28252;
v_28253:
    v_28282 = list2(v_28282, v_28283);
    env = stack[-7];
    v_28284 = v_28282;
    goto v_28245;
v_28247:
v_28245:
    goto v_28264;
v_28258:
    goto v_28270;
v_28266:
    goto v_28276;
v_28272:
    v_28283 = v_28284;
    goto v_28273;
v_28274:
    v_28282 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28275;
v_28276:
    goto v_28272;
v_28273:
    goto v_28274;
v_28275:
    fn = elt(env, 20); // to
    v_28283 = (*qfn2(fn))(fn, v_28283, v_28282);
    env = stack[-7];
    goto v_28267;
v_28268:
    v_28282 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28269;
v_28270:
    goto v_28266;
v_28267:
    goto v_28268;
v_28269:
    v_28284 = cons(v_28283, v_28282);
    env = stack[-7];
    goto v_28259;
v_28260:
    v_28283 = nil;
    goto v_28261;
v_28262:
    v_28282 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28263;
v_28264:
    goto v_28258;
v_28259:
    goto v_28260;
v_28261:
    goto v_28262;
v_28263:
    v_28282 = acons(v_28284, v_28283, v_28282);
v_28067:
    ;}  // end of a binding scope
    return onevalue(v_28282);
}



// Code for vecsimp!*

static LispObject CC_vecsimpH(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28074;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28061;
// end of prologue
    v_28074 = stack[0];
    fn = elt(env, 1); // vecp
    v_28074 = (*qfn1(fn))(fn, v_28074);
    env = stack[-1];
    if (v_28074 == nil) goto v_28066;
    v_28074 = stack[0];
    {
        fn = elt(env, 2); // vecsm!*
        return (*qfn1(fn))(fn, v_28074);
    }
v_28066:
    v_28074 = stack[0];
    goto v_28064;
    v_28074 = nil;
v_28064:
    return onevalue(v_28074);
}



// Code for check_letop

static LispObject CC_check_letop(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28077, v_28078;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_28077 = v_28061;
// end of prologue
    goto v_28072;
v_28068:
    v_28078 = v_28077;
    goto v_28069;
v_28070:
    v_28077 = elt(env, 1); // letop
    goto v_28071;
v_28072:
    goto v_28068;
v_28069:
    goto v_28070;
v_28071:
    fn = elt(env, 3); // freeof
    v_28077 = (*qfn2(fn))(fn, v_28078, v_28077);
    env = stack[0];
    if (v_28077 == nil) goto v_28065;
    else goto v_28066;
v_28065:
    v_28077 = elt(env, 2); // "Presence of letop, jetspace too small!"
    {
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(fn, v_28077);
    }
v_28066:
    v_28077 = nil;
    return onevalue(v_28077);
}



// Code for random!-small!-prime

static LispObject CC_randomKsmallKprime(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28085;
    LispObject fn;
    argcheck(nargs, 0, "random-small-prime");
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
v_28068:
    fn = elt(env, 2); // small!-random!-number
    v_28085 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_28085;
    v_28085 = stack[0];
    v_28085 = Levenp(nil, v_28085);
    env = stack[-1];
    if (v_28085 == nil) goto v_28073;
    v_28085 = stack[0];
    v_28085 = (LispObject)((intptr_t)(v_28085) + 0x10);
    stack[0] = v_28085;
    goto v_28071;
v_28073:
v_28071:
    v_28085 = stack[0];
    fn = elt(env, 3); // primep
    v_28085 = (*qfn1(fn))(fn, v_28085);
    env = stack[-1];
    if (v_28085 == nil) goto v_28080;
    else goto v_28081;
v_28080:
    goto v_28068;
v_28081:
    v_28085 = stack[0];
    return onevalue(v_28085);
}



// Code for aex_xtothen

static LispObject CC_aex_xtothen(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28086, v_28087;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28086 = v_28062;
    v_28087 = v_28061;
// end of prologue
    goto v_28069;
v_28065:
    goto v_28075;
v_28071:
    goto v_28081;
v_28077:
    goto v_28078;
v_28079:
    goto v_28080;
v_28081:
    goto v_28077;
v_28078:
    goto v_28079;
v_28080:
    fn = elt(env, 1); // sfto_kexp
    v_28087 = (*qfn2(fn))(fn, v_28087, v_28086);
    env = stack[-1];
    goto v_28072;
v_28073:
    v_28086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28074;
v_28075:
    goto v_28071;
v_28072:
    goto v_28073;
v_28074:
    stack[0] = cons(v_28087, v_28086);
    env = stack[-1];
    goto v_28066;
v_28067:
    fn = elt(env, 2); // ctx_new
    v_28086 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_28068;
v_28069:
    goto v_28065;
v_28066:
    goto v_28067;
v_28068:
    {
        LispObject v_28089 = stack[0];
        fn = elt(env, 3); // aex_mk
        return (*qfn2(fn))(fn, v_28089, v_28086);
    }
}



// Code for ofsf_facequal

static LispObject CC_ofsf_facequal(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28167, v_28168, v_28169;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_28167 = v_28061;
// end of prologue
    fn = elt(env, 6); // sfto_fctrf
    v_28167 = (*qfn1(fn))(fn, v_28167);
    env = stack[-4];
    v_28167 = qcdr(v_28167);
    stack[-3] = v_28167;
    v_28167 = stack[-3];
    if (v_28167 == nil) goto v_28074;
    else goto v_28075;
v_28074:
    v_28167 = nil;
    goto v_28067;
v_28075:
    v_28167 = stack[-3];
    v_28167 = qcar(v_28167);
    goto v_28089;
v_28083:
    v_28169 = elt(env, 1); // equal
    goto v_28084;
v_28085:
    v_28168 = qcar(v_28167);
    goto v_28086;
v_28087:
    v_28167 = nil;
    goto v_28088;
v_28089:
    goto v_28083;
v_28084:
    goto v_28085;
v_28086:
    goto v_28087;
v_28088:
    v_28167 = list3(v_28169, v_28168, v_28167);
    env = stack[-4];
    v_28167 = ncons(v_28167);
    env = stack[-4];
    stack[-1] = v_28167;
    stack[-2] = v_28167;
v_28068:
    v_28167 = stack[-3];
    v_28167 = qcdr(v_28167);
    stack[-3] = v_28167;
    v_28167 = stack[-3];
    if (v_28167 == nil) goto v_28098;
    else goto v_28099;
v_28098:
    v_28167 = stack[-2];
    goto v_28067;
v_28099:
    goto v_28107;
v_28103:
    stack[0] = stack[-1];
    goto v_28104;
v_28105:
    v_28167 = stack[-3];
    v_28167 = qcar(v_28167);
    goto v_28120;
v_28114:
    v_28169 = elt(env, 1); // equal
    goto v_28115;
v_28116:
    v_28168 = qcar(v_28167);
    goto v_28117;
v_28118:
    v_28167 = nil;
    goto v_28119;
v_28120:
    goto v_28114;
v_28115:
    goto v_28116;
v_28117:
    goto v_28118;
v_28119:
    v_28167 = list3(v_28169, v_28168, v_28167);
    env = stack[-4];
    v_28167 = ncons(v_28167);
    env = stack[-4];
    goto v_28106;
v_28107:
    goto v_28103;
v_28104:
    goto v_28105;
v_28106:
    v_28167 = Lrplacd(nil, stack[0], v_28167);
    env = stack[-4];
    v_28167 = stack[-1];
    v_28167 = qcdr(v_28167);
    stack[-1] = v_28167;
    goto v_28068;
v_28067:
    v_28168 = v_28167;
    v_28167 = v_28168;
    if (v_28167 == nil) goto v_28131;
    v_28167 = v_28168;
    v_28167 = qcdr(v_28167);
    if (v_28167 == nil) goto v_28131;
    goto v_28142;
v_28138:
    v_28167 = elt(env, 2); // or
    goto v_28139;
v_28140:
    goto v_28141;
v_28142:
    goto v_28138;
v_28139:
    goto v_28140;
v_28141:
    return cons(v_28167, v_28168);
v_28131:
    v_28167 = v_28168;
    if (v_28167 == nil) goto v_28145;
    else goto v_28146;
v_28145:
    goto v_28156;
v_28152:
    v_28168 = elt(env, 2); // or
    goto v_28153;
v_28154:
    v_28167 = elt(env, 3); // and
    goto v_28155;
v_28156:
    goto v_28152;
v_28153:
    goto v_28154;
v_28155:
    if (v_28168 == v_28167) goto v_28150;
    else goto v_28151;
v_28150:
    v_28167 = elt(env, 4); // true
    goto v_28149;
v_28151:
    v_28167 = elt(env, 5); // false
    goto v_28149;
    v_28167 = nil;
v_28149:
    goto v_28129;
v_28146:
    v_28167 = v_28168;
    v_28167 = qcar(v_28167);
    goto v_28129;
    v_28167 = nil;
v_28129:
    return onevalue(v_28167);
}



// Code for cl_identifyonoff

static LispObject CC_cl_identifyonoff(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28064;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28064 = v_28061;
// end of prologue
    v_28064 = nil;
    qvalue(elt(env, 1)) = v_28064; // cl_identify!-atl!*
    return onevalue(v_28064);
}



// Code for ofsf_smeqtable

static LispObject CC_ofsf_smeqtable(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28103, v_28104, v_28105, v_28106, v_28107, v_28108;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28106 = v_28062;
    v_28107 = v_28061;
// end of prologue
    v_28103 = elt(env, 2); // ((equal (equal . equal) (neq . false) (geq . equal) (leq . equal) (greaterp . false) (lessp . false)) (neq (neq . neq) (geq
// . greaterp) (leq . lessp) (greaterp . greaterp) (lessp . lessp)) (geq (geq . geq) (leq . equal) (greaterp . greaterp) (lessp
// . false)) (leq (leq . leq) (greaterp . false) (lessp . lessp)) (greaterp (greaterp . greaterp) (lessp . false)) (lessp (lessp
// . lessp)))
    v_28108 = v_28103;
    goto v_28076;
v_28072:
    v_28105 = v_28106;
    goto v_28073;
v_28074:
    goto v_28082;
v_28078:
    v_28104 = v_28107;
    goto v_28079;
v_28080:
    v_28103 = v_28108;
    goto v_28081;
v_28082:
    goto v_28078;
v_28079:
    goto v_28080;
v_28081:
    v_28103 = Latsoc(nil, v_28104, v_28103);
    goto v_28075;
v_28076:
    goto v_28072;
v_28073:
    goto v_28074;
v_28075:
    v_28103 = Latsoc(nil, v_28105, v_28103);
    if (v_28103 == nil) goto v_28071;
    else goto v_28070;
v_28071:
    goto v_28091;
v_28087:
    v_28103 = v_28107;
    goto v_28088;
v_28089:
    goto v_28097;
v_28093:
    v_28104 = v_28106;
    goto v_28094;
v_28095:
    v_28105 = v_28108;
    goto v_28096;
v_28097:
    goto v_28093;
v_28094:
    goto v_28095;
v_28096:
    v_28104 = Latsoc(nil, v_28104, v_28105);
    goto v_28090;
v_28091:
    goto v_28087;
v_28088:
    goto v_28089;
v_28090:
    v_28103 = Latsoc(nil, v_28103, v_28104);
v_28070:
    v_28103 = qcdr(v_28103);
    return onevalue(v_28103);
}



// Code for dfdeg

static LispObject CC_dfdeg(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28099, v_28100;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28099 = v_28062;
    v_28100 = v_28061;
// end of prologue
    goto v_28072;
v_28068:
    goto v_28069;
v_28070:
    goto v_28071;
v_28072:
    goto v_28068;
v_28069:
    goto v_28070;
v_28071:
    v_28099 = Lmember(nil, v_28099, v_28100);
    v_28100 = v_28099;
    if (v_28099 == nil) goto v_28066;
    else goto v_28067;
v_28066:
    v_28099 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28065;
v_28067:
    v_28099 = v_28100;
    v_28099 = qcdr(v_28099);
    if (v_28099 == nil) goto v_28081;
    else goto v_28082;
v_28081:
    v_28099 = lisp_true;
    goto v_28080;
v_28082:
    v_28099 = v_28100;
    v_28099 = qcdr(v_28099);
    v_28099 = qcar(v_28099);
    v_28099 = integerp(v_28099);
    v_28099 = (v_28099 == nil ? lisp_true : nil);
    goto v_28080;
    v_28099 = nil;
v_28080:
    if (v_28099 == nil) goto v_28078;
    v_28099 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28065;
v_28078:
    v_28099 = v_28100;
    v_28099 = qcdr(v_28099);
    v_28099 = qcar(v_28099);
    goto v_28065;
    v_28099 = nil;
v_28065:
    return onevalue(v_28099);
}



// Code for mksfpf

static LispObject CC_mksfpf(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28194, v_28195;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28062;
    v_28194 = v_28061;
// end of prologue
    fn = elt(env, 3); // mkprod
    v_28194 = (*qfn1(fn))(fn, v_28194);
    env = stack[-2];
    stack[-1] = v_28194;
    goto v_28075;
v_28071:
    v_28195 = stack[0];
    goto v_28072;
v_28073:
    v_28194 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28074;
v_28075:
    goto v_28071;
v_28072:
    goto v_28073;
v_28074:
    if (v_28195 == v_28194) goto v_28069;
    else goto v_28070;
v_28069:
    v_28194 = stack[-1];
    goto v_28068;
v_28070:
    v_28194 = stack[-1];
    if (!consp(v_28194)) goto v_28083;
    else goto v_28084;
v_28083:
    v_28194 = lisp_true;
    goto v_28082;
v_28084:
    v_28194 = stack[-1];
    v_28194 = qcar(v_28194);
    v_28194 = (consp(v_28194) ? nil : lisp_true);
    goto v_28082;
    v_28194 = nil;
v_28082:
    if (v_28194 == nil) goto v_28080;
    goto v_28097;
v_28093:
    v_28195 = stack[-1];
    goto v_28094;
v_28095:
    v_28194 = stack[0];
    goto v_28096;
v_28097:
    goto v_28093;
v_28094:
    goto v_28095;
v_28096:
    {
        fn = elt(env, 4); // !:expt
        return (*qfn2(fn))(fn, v_28195, v_28194);
    }
v_28080:
    goto v_28108;
v_28104:
    v_28195 = stack[0];
    goto v_28105;
v_28106:
    v_28194 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28107;
v_28108:
    goto v_28104;
v_28105:
    goto v_28106;
v_28107:
    v_28194 = (LispObject)geq2(v_28195, v_28194);
    v_28194 = v_28194 ? lisp_true : nil;
    env = stack[-2];
    if (v_28194 == nil) goto v_28101;
    v_28194 = stack[-1];
    v_28194 = qcar(v_28194);
    v_28194 = qcdr(v_28194);
    v_28194 = Lonep(nil, v_28194);
    env = stack[-2];
    if (v_28194 == nil) goto v_28101;
    v_28194 = stack[-1];
    v_28194 = qcdr(v_28194);
    if (v_28194 == nil) goto v_28117;
    else goto v_28101;
v_28117:
    goto v_28125;
v_28121:
    v_28194 = stack[-1];
    v_28194 = qcar(v_28194);
    v_28194 = qcar(v_28194);
    v_28195 = qcdr(v_28194);
    goto v_28122;
v_28123:
    v_28194 = stack[0];
    goto v_28124;
v_28125:
    goto v_28121;
v_28122:
    goto v_28123;
v_28124:
    v_28195 = times2(v_28195, v_28194);
    env = stack[-2];
    v_28194 = stack[-1];
    v_28194 = qcar(v_28194);
    v_28194 = qcar(v_28194);
    v_28194 = qcar(v_28194);
    stack[-1] = v_28195;
    stack[0] = v_28194;
    goto v_28141;
v_28137:
    v_28195 = stack[0];
    goto v_28138;
v_28139:
    v_28194 = qvalue(elt(env, 1)); // asymplis!*
    goto v_28140;
v_28141:
    goto v_28137;
v_28138:
    goto v_28139;
v_28140:
    v_28194 = Lassoc(nil, v_28195, v_28194);
    v_28195 = v_28194;
    v_28194 = qvalue(elt(env, 2)); // subfg!*
    if (v_28194 == nil) goto v_28149;
    v_28194 = v_28195;
    if (v_28194 == nil) goto v_28149;
    goto v_28161;
v_28157:
    v_28194 = v_28195;
    v_28195 = qcdr(v_28194);
    goto v_28158;
v_28159:
    v_28194 = stack[-1];
    goto v_28160;
v_28161:
    goto v_28157;
v_28158:
    goto v_28159;
v_28160:
    v_28194 = (LispObject)lesseq2(v_28195, v_28194);
    v_28194 = v_28194 ? lisp_true : nil;
    env = stack[-2];
    if (v_28194 == nil) goto v_28149;
    v_28194 = nil;
    goto v_28147;
v_28149:
    goto v_28174;
v_28170:
    goto v_28180;
v_28176:
    v_28195 = stack[0];
    goto v_28177;
v_28178:
    v_28194 = stack[-1];
    goto v_28179;
v_28180:
    goto v_28176;
v_28177:
    goto v_28178;
v_28179:
    fn = elt(env, 5); // mksp
    v_28195 = (*qfn2(fn))(fn, v_28195, v_28194);
    env = stack[-2];
    goto v_28171;
v_28172:
    v_28194 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28173;
v_28174:
    goto v_28170;
v_28171:
    goto v_28172;
v_28173:
    v_28194 = cons(v_28195, v_28194);
    return ncons(v_28194);
    v_28194 = nil;
v_28147:
    goto v_28068;
v_28101:
    goto v_28191;
v_28187:
    v_28195 = stack[-1];
    goto v_28188;
v_28189:
    v_28194 = stack[0];
    goto v_28190;
v_28191:
    goto v_28187;
v_28188:
    goto v_28189;
v_28190:
    {
        fn = elt(env, 6); // exptf2
        return (*qfn2(fn))(fn, v_28195, v_28194);
    }
    v_28194 = nil;
v_28068:
    return onevalue(v_28194);
}



// Code for cl_sacat

static LispObject CC_cl_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28080, v_28081, v_28082;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_sacat");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28080 = v_28063;
    v_28081 = v_28062;
    v_28082 = v_28061;
// end of prologue
    goto v_28073;
v_28069:
    v_28080 = v_28082;
    goto v_28070;
v_28071:
    goto v_28072;
v_28073:
    goto v_28069;
v_28070:
    goto v_28071;
v_28072:
    if (equal(v_28080, v_28081)) goto v_28067;
    else goto v_28068;
v_28067:
    v_28080 = elt(env, 1); // keep
    goto v_28066;
v_28068:
    v_28080 = nil;
    goto v_28066;
    v_28080 = nil;
v_28066:
    return onevalue(v_28080);
}



// Code for acfsf_clnegrel

static LispObject CC_acfsf_clnegrel(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28074, v_28075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28074 = v_28062;
    v_28075 = v_28061;
// end of prologue
    if (v_28074 == nil) goto v_28067;
    v_28074 = v_28075;
    goto v_28065;
v_28067:
    v_28074 = v_28075;
    {
        fn = elt(env, 1); // acfsf_lnegrel
        return (*qfn1(fn))(fn, v_28074);
    }
    v_28074 = nil;
v_28065:
    return onevalue(v_28074);
}



// Code for nestzerop!:

static LispObject CC_nestzeropT(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28079, v_28080;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
// copy arguments values to proper place
    v_28080 = v_28061;
// end of prologue
    v_28079 = v_28080;
    v_28079 = integerp(v_28079);
    if (v_28079 == nil) goto v_28066;
    v_28079 = v_28080;
    fn = elt(env, 1); // simp
    v_28079 = (*qfn1(fn))(fn, v_28079);
    goto v_28064;
v_28066:
    v_28079 = v_28080;
    v_28079 = qcdr(v_28079);
    v_28079 = qcdr(v_28079);
    v_28079 = qcdr(v_28079);
    goto v_28064;
    v_28079 = nil;
v_28064:
    v_28079 = qcar(v_28079);
    v_28079 = (v_28079 == nil ? lisp_true : nil);
    return onevalue(v_28079);
}



// Code for reduce!-weights

static LispObject CC_reduceKweights(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28150, v_28151;
    LispObject fn;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "reduce-weights");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28063,v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28061,v_28062,v_28063);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_28063;
    stack[-4] = v_28062;
    stack[-5] = v_28061;
// end of prologue
    stack[-6] = nil;
    goto v_28079;
v_28075:
    v_28151 = stack[-5];
    goto v_28076;
v_28077:
    v_28150 = stack[-3];
    goto v_28078;
v_28079:
    goto v_28075;
v_28076:
    goto v_28077;
v_28078:
    fn = elt(env, 2); // red!-weight
    v_28150 = (*qfn2(fn))(fn, v_28151, v_28150);
    env = stack[-7];
    stack[-2] = v_28150;
v_28071:
    goto v_28087;
v_28083:
    v_28151 = stack[-5];
    goto v_28084;
v_28085:
    v_28150 = stack[-4];
    goto v_28086;
v_28087:
    goto v_28083;
v_28084:
    goto v_28085;
v_28086:
    fn = elt(env, 3); // mv!-domainlist!-!+
    v_28150 = (*qfn2(fn))(fn, v_28151, v_28150);
    env = stack[-7];
    stack[-1] = v_28150;
    goto v_28095;
v_28091:
    v_28151 = stack[-1];
    goto v_28092;
v_28093:
    v_28150 = stack[-3];
    goto v_28094;
v_28095:
    goto v_28091;
v_28092:
    goto v_28093;
v_28094:
    fn = elt(env, 2); // red!-weight
    v_28150 = (*qfn2(fn))(fn, v_28151, v_28150);
    env = stack[-7];
    stack[0] = v_28150;
    goto v_28107;
v_28103:
    v_28151 = stack[0];
    goto v_28104;
v_28105:
    v_28150 = stack[-2];
    goto v_28106;
v_28107:
    goto v_28103;
v_28104:
    goto v_28105;
v_28106:
    fn = elt(env, 4); // red!-weight!-less!-p
    v_28150 = (*qfn2(fn))(fn, v_28151, v_28150);
    env = stack[-7];
    if (v_28150 == nil) goto v_28101;
    v_28150 = lisp_true;
    stack[-6] = v_28150;
    v_28150 = stack[-1];
    stack[-5] = v_28150;
    v_28150 = stack[0];
    stack[-2] = v_28150;
    goto v_28071;
v_28101:
    v_28150 = stack[-6];
    if (v_28150 == nil) goto v_28116;
    v_28150 = stack[-5];
    goto v_28070;
v_28116:
v_28072:
    goto v_28124;
v_28120:
    v_28151 = stack[-5];
    goto v_28121;
v_28122:
    v_28150 = stack[-4];
    goto v_28123;
v_28124:
    goto v_28120;
v_28121:
    goto v_28122;
v_28123:
    fn = elt(env, 5); // mv!-domainlist!-!-
    v_28150 = (*qfn2(fn))(fn, v_28151, v_28150);
    env = stack[-7];
    stack[-1] = v_28150;
    goto v_28132;
v_28128:
    v_28151 = stack[-1];
    goto v_28129;
v_28130:
    v_28150 = stack[-3];
    goto v_28131;
v_28132:
    goto v_28128;
v_28129:
    goto v_28130;
v_28131:
    fn = elt(env, 2); // red!-weight
    v_28150 = (*qfn2(fn))(fn, v_28151, v_28150);
    env = stack[-7];
    stack[0] = v_28150;
    goto v_28144;
v_28140:
    v_28151 = stack[0];
    goto v_28141;
v_28142:
    v_28150 = stack[-2];
    goto v_28143;
v_28144:
    goto v_28140;
v_28141:
    goto v_28142;
v_28143:
    fn = elt(env, 4); // red!-weight!-less!-p
    v_28150 = (*qfn2(fn))(fn, v_28151, v_28150);
    env = stack[-7];
    if (v_28150 == nil) goto v_28138;
    v_28150 = stack[-1];
    stack[-5] = v_28150;
    v_28150 = stack[0];
    stack[-2] = v_28150;
    goto v_28072;
v_28138:
    v_28150 = stack[-5];
v_28070:
    return onevalue(v_28150);
}



// Code for groeb!=testb

static LispObject CC_groebMtestb(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28172, v_28173;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28062;
    stack[-1] = v_28061;
// end of prologue
    goto v_28072;
v_28068:
    v_28172 = stack[-1];
    fn = elt(env, 1); // mo_comp
    v_28173 = (*qfn1(fn))(fn, v_28172);
    env = stack[-3];
    goto v_28069;
v_28070:
    v_28172 = stack[0];
    v_28172 = qcar(v_28172);
    goto v_28071;
v_28072:
    goto v_28068;
v_28069:
    goto v_28070;
v_28071:
    if (equal(v_28173, v_28172)) goto v_28066;
    else goto v_28067;
v_28066:
    goto v_28086;
v_28082:
    stack[-2] = stack[-1];
    goto v_28083;
v_28084:
    goto v_28093;
v_28089:
    v_28173 = stack[0];
    goto v_28090;
v_28091:
    v_28172 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28092;
v_28093:
    goto v_28089;
v_28090:
    goto v_28091;
v_28092:
    fn = elt(env, 2); // nth
    v_28172 = (*qfn2(fn))(fn, v_28173, v_28172);
    env = stack[-3];
    goto v_28085;
v_28086:
    goto v_28082;
v_28083:
    goto v_28084;
v_28085:
    fn = elt(env, 3); // mo_divides!?
    v_28172 = (*qfn2(fn))(fn, stack[-2], v_28172);
    env = stack[-3];
    if (v_28172 == nil) goto v_28079;
    else goto v_28080;
v_28079:
    v_28172 = nil;
    goto v_28078;
v_28080:
    goto v_28108;
v_28104:
    goto v_28114;
v_28110:
    goto v_28122;
v_28118:
    v_28173 = stack[0];
    goto v_28119;
v_28120:
    v_28172 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_28121;
v_28122:
    goto v_28118;
v_28119:
    goto v_28120;
v_28121:
    fn = elt(env, 2); // nth
    v_28172 = (*qfn2(fn))(fn, v_28173, v_28172);
    env = stack[-3];
    fn = elt(env, 4); // bas_dpoly
    v_28172 = (*qfn1(fn))(fn, v_28172);
    env = stack[-3];
    fn = elt(env, 5); // dp_lmon
    v_28173 = (*qfn1(fn))(fn, v_28172);
    env = stack[-3];
    goto v_28111;
v_28112:
    v_28172 = stack[-1];
    goto v_28113;
v_28114:
    goto v_28110;
v_28111:
    goto v_28112;
v_28113:
    fn = elt(env, 6); // mo_lcm
    stack[-2] = (*qfn2(fn))(fn, v_28173, v_28172);
    env = stack[-3];
    goto v_28105;
v_28106:
    goto v_28131;
v_28127:
    v_28173 = stack[0];
    goto v_28128;
v_28129:
    v_28172 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28130;
v_28131:
    goto v_28127;
v_28128:
    goto v_28129;
v_28130:
    fn = elt(env, 2); // nth
    v_28172 = (*qfn2(fn))(fn, v_28173, v_28172);
    env = stack[-3];
    goto v_28107;
v_28108:
    goto v_28104;
v_28105:
    goto v_28106;
v_28107:
    fn = elt(env, 7); // mo_equal!?
    v_28172 = (*qfn2(fn))(fn, stack[-2], v_28172);
    env = stack[-3];
    if (v_28172 == nil) goto v_28101;
    else goto v_28102;
v_28101:
    goto v_28139;
v_28135:
    goto v_28145;
v_28141:
    goto v_28153;
v_28149:
    v_28173 = stack[0];
    goto v_28150;
v_28151:
    v_28172 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_28152;
v_28153:
    goto v_28149;
v_28150:
    goto v_28151;
v_28152:
    fn = elt(env, 2); // nth
    v_28172 = (*qfn2(fn))(fn, v_28173, v_28172);
    env = stack[-3];
    fn = elt(env, 4); // bas_dpoly
    v_28172 = (*qfn1(fn))(fn, v_28172);
    env = stack[-3];
    fn = elt(env, 5); // dp_lmon
    v_28173 = (*qfn1(fn))(fn, v_28172);
    env = stack[-3];
    goto v_28142;
v_28143:
    v_28172 = stack[-1];
    goto v_28144;
v_28145:
    goto v_28141;
v_28142:
    goto v_28143;
v_28144:
    fn = elt(env, 6); // mo_lcm
    stack[-1] = (*qfn2(fn))(fn, v_28173, v_28172);
    env = stack[-3];
    goto v_28136;
v_28137:
    goto v_28162;
v_28158:
    v_28173 = stack[0];
    goto v_28159;
v_28160:
    v_28172 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28161;
v_28162:
    goto v_28158;
v_28159:
    goto v_28160;
v_28161:
    fn = elt(env, 2); // nth
    v_28172 = (*qfn2(fn))(fn, v_28173, v_28172);
    env = stack[-3];
    goto v_28138;
v_28139:
    goto v_28135;
v_28136:
    goto v_28137;
v_28138:
    fn = elt(env, 7); // mo_equal!?
    v_28172 = (*qfn2(fn))(fn, stack[-1], v_28172);
    v_28172 = (v_28172 == nil ? lisp_true : nil);
    goto v_28100;
v_28102:
    v_28172 = nil;
    goto v_28100;
    v_28172 = nil;
v_28100:
    goto v_28078;
    v_28172 = nil;
v_28078:
    goto v_28065;
v_28067:
    v_28172 = nil;
    goto v_28065;
    v_28172 = nil;
v_28065:
    return onevalue(v_28172);
}



// Code for girationalize!:

static LispObject CC_girationalizeT(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28161, v_28162, v_28163;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_28061;
// end of prologue
    stack[-5] = nil;
// Binding !*gcd
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-6, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*gcd
    v_28161 = lisp_true;
    qvalue(elt(env, 1)) = v_28161; // !*gcd
    goto v_28078;
v_28074:
    stack[-1] = stack[-5];
    goto v_28075;
v_28076:
    v_28161 = stack[-4];
    v_28161 = qcdr(v_28161);
    stack[-5] = v_28161;
    fn = elt(env, 4); // conjgd
    v_28161 = (*qfn1(fn))(fn, v_28161);
    env = stack[-6];
    stack[0] = v_28161;
    goto v_28077;
v_28078:
    goto v_28074;
v_28075:
    goto v_28076;
v_28077:
    if (equal(stack[-1], v_28161)) goto v_28072;
    else goto v_28073;
v_28072:
    v_28161 = stack[-4];
    goto v_28067;
v_28073:
    goto v_28089;
v_28085:
    stack[-2] = stack[0];
    goto v_28086;
v_28087:
    goto v_28096;
v_28092:
    goto v_28102;
v_28098:
    goto v_28108;
v_28104:
    v_28162 = stack[-5];
    goto v_28105;
v_28106:
    v_28161 = stack[0];
    goto v_28107;
v_28108:
    goto v_28104;
v_28105:
    goto v_28106;
v_28107:
    fn = elt(env, 5); // addf
    stack[-1] = (*qfn2(fn))(fn, v_28162, v_28161);
    env = stack[-6];
    goto v_28099;
v_28100:
    goto v_28116;
v_28112:
    goto v_28122;
v_28118:
    goto v_28119;
v_28120:
    v_28161 = stack[-5];
    fn = elt(env, 6); // negf
    v_28161 = (*qfn1(fn))(fn, v_28161);
    env = stack[-6];
    goto v_28121;
v_28122:
    goto v_28118;
v_28119:
    goto v_28120;
v_28121:
    fn = elt(env, 5); // addf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_28161);
    env = stack[-6];
    goto v_28113;
v_28114:
    goto v_28133;
v_28127:
    v_28163 = elt(env, 3); // !:gi!:
    goto v_28128;
v_28129:
    v_28162 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28130;
v_28131:
    v_28161 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28132;
v_28133:
    goto v_28127;
v_28128:
    goto v_28129;
v_28130:
    goto v_28131;
v_28132:
    v_28161 = list2star(v_28163, v_28162, v_28161);
    env = stack[-6];
    goto v_28115;
v_28116:
    goto v_28112;
v_28113:
    goto v_28114;
v_28115:
    fn = elt(env, 7); // multf
    v_28161 = (*qfn2(fn))(fn, stack[0], v_28161);
    env = stack[-6];
    goto v_28101;
v_28102:
    goto v_28098;
v_28099:
    goto v_28100;
v_28101:
    fn = elt(env, 8); // gcdf
    v_28162 = (*qfn2(fn))(fn, stack[-1], v_28161);
    env = stack[-6];
    goto v_28093;
v_28094:
    v_28161 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_28095;
v_28096:
    goto v_28092;
v_28093:
    goto v_28094;
v_28095:
    fn = elt(env, 9); // quotf
    v_28161 = (*qfn2(fn))(fn, v_28162, v_28161);
    env = stack[-6];
    goto v_28088;
v_28089:
    goto v_28085;
v_28086:
    goto v_28087;
v_28088:
    fn = elt(env, 10); // quotf!-fail
    v_28161 = (*qfn2(fn))(fn, stack[-2], v_28161);
    env = stack[-6];
    stack[0] = v_28161;
    goto v_28143;
v_28139:
    goto v_28149;
v_28145:
    v_28161 = stack[-4];
    v_28162 = qcar(v_28161);
    goto v_28146;
v_28147:
    v_28161 = stack[0];
    goto v_28148;
v_28149:
    goto v_28145;
v_28146:
    goto v_28147;
v_28148:
    fn = elt(env, 7); // multf
    stack[-1] = (*qfn2(fn))(fn, v_28162, v_28161);
    env = stack[-6];
    goto v_28140;
v_28141:
    goto v_28158;
v_28154:
    v_28162 = stack[-5];
    goto v_28155;
v_28156:
    v_28161 = stack[0];
    goto v_28157;
v_28158:
    goto v_28154;
v_28155:
    goto v_28156;
v_28157:
    fn = elt(env, 7); // multf
    v_28161 = (*qfn2(fn))(fn, v_28162, v_28161);
    env = stack[-6];
    goto v_28142;
v_28143:
    goto v_28139;
v_28140:
    goto v_28141;
v_28142:
    fn = elt(env, 11); // gigcdsq
    v_28161 = (*qfn2(fn))(fn, stack[-1], v_28161);
v_28067:
    ;}  // end of a binding scope
    return onevalue(v_28161);
}



// Code for f2df

static LispObject CC_f2df(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28177, v_28178, v_28179;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28061;
// end of prologue
    v_28177 = stack[0];
    if (!consp(v_28177)) goto v_28069;
    else goto v_28070;
v_28069:
    v_28177 = lisp_true;
    goto v_28068;
v_28070:
    v_28177 = stack[0];
    v_28177 = qcar(v_28177);
    v_28177 = (consp(v_28177) ? nil : lisp_true);
    goto v_28068;
    v_28177 = nil;
v_28068:
    if (v_28177 == nil) goto v_28066;
    goto v_28084;
v_28080:
    v_28178 = stack[0];
    goto v_28081;
v_28082:
    v_28177 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28083;
v_28084:
    goto v_28080;
v_28081:
    goto v_28082;
v_28083:
    v_28177 = cons(v_28178, v_28177);
    env = stack[-2];
    {
        fn = elt(env, 2); // dfconst
        return (*qfn1(fn))(fn, v_28177);
    }
v_28066:
    goto v_28093;
v_28089:
    v_28177 = stack[0];
    v_28177 = qcar(v_28177);
    v_28177 = qcar(v_28177);
    v_28178 = qcar(v_28177);
    goto v_28090;
v_28091:
    v_28177 = qvalue(elt(env, 1)); // zlist
    goto v_28092;
v_28093:
    goto v_28089;
v_28090:
    goto v_28091;
v_28092:
    v_28177 = Lmember(nil, v_28178, v_28177);
    if (v_28177 == nil) goto v_28088;
    goto v_28105;
v_28101:
    goto v_28111;
v_28107:
    goto v_28119;
v_28113:
    v_28177 = stack[0];
    v_28177 = qcar(v_28177);
    v_28177 = qcar(v_28177);
    v_28179 = qcar(v_28177);
    goto v_28114;
v_28115:
    v_28177 = stack[0];
    v_28177 = qcar(v_28177);
    v_28177 = qcar(v_28177);
    v_28178 = qcdr(v_28177);
    goto v_28116;
v_28117:
    v_28177 = qvalue(elt(env, 1)); // zlist
    goto v_28118;
v_28119:
    goto v_28113;
v_28114:
    goto v_28115;
v_28116:
    goto v_28117;
v_28118:
    fn = elt(env, 3); // vp2df
    stack[-1] = (*qfnn(fn))(fn, 3, v_28179, v_28178, v_28177);
    env = stack[-2];
    goto v_28108;
v_28109:
    v_28177 = stack[0];
    v_28177 = qcar(v_28177);
    v_28177 = qcdr(v_28177);
    v_28177 = CC_f2df(elt(env, 0), v_28177);
    env = stack[-2];
    goto v_28110;
v_28111:
    goto v_28107;
v_28108:
    goto v_28109;
v_28110:
    fn = elt(env, 4); // multdf
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_28177);
    env = stack[-2];
    goto v_28102;
v_28103:
    v_28177 = stack[0];
    v_28177 = qcdr(v_28177);
    v_28177 = CC_f2df(elt(env, 0), v_28177);
    env = stack[-2];
    goto v_28104;
v_28105:
    goto v_28101;
v_28102:
    goto v_28103;
v_28104:
    {
        LispObject v_28182 = stack[-1];
        fn = elt(env, 5); // plusdf
        return (*qfn2(fn))(fn, v_28182, v_28177);
    }
v_28088:
    goto v_28143;
v_28139:
    goto v_28149;
v_28145:
    goto v_28157;
v_28151:
    goto v_28163;
v_28159:
    v_28177 = stack[0];
    v_28177 = qcar(v_28177);
    v_28178 = qcar(v_28177);
    goto v_28160;
v_28161:
    v_28177 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28162;
v_28163:
    goto v_28159;
v_28160:
    goto v_28161;
v_28162:
    v_28179 = cons(v_28178, v_28177);
    env = stack[-2];
    goto v_28152;
v_28153:
    v_28178 = nil;
    goto v_28154;
v_28155:
    v_28177 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28156;
v_28157:
    goto v_28151;
v_28152:
    goto v_28153;
v_28154:
    goto v_28155;
v_28156:
    stack[-1] = acons(v_28179, v_28178, v_28177);
    env = stack[-2];
    goto v_28146;
v_28147:
    v_28177 = stack[0];
    v_28177 = qcar(v_28177);
    v_28177 = qcdr(v_28177);
    v_28177 = CC_f2df(elt(env, 0), v_28177);
    env = stack[-2];
    goto v_28148;
v_28149:
    goto v_28145;
v_28146:
    goto v_28147;
v_28148:
    fn = elt(env, 6); // multdfconst
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_28177);
    env = stack[-2];
    goto v_28140;
v_28141:
    v_28177 = stack[0];
    v_28177 = qcdr(v_28177);
    v_28177 = CC_f2df(elt(env, 0), v_28177);
    env = stack[-2];
    goto v_28142;
v_28143:
    goto v_28139;
v_28140:
    goto v_28141;
v_28142:
    {
        LispObject v_28183 = stack[-1];
        fn = elt(env, 5); // plusdf
        return (*qfn2(fn))(fn, v_28183, v_28177);
    }
    v_28177 = nil;
    return onevalue(v_28177);
}



// Code for cl_rename!-vars1

static LispObject CC_cl_renameKvars1(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28700, v_28701, v_28702, v_28703;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_28062;
    stack[0] = v_28061;
// end of prologue
    stack[-3] = nil;
    v_28700 = stack[0];
    if (!consp(v_28700)) goto v_28074;
    else goto v_28075;
v_28074:
    v_28700 = stack[0];
    goto v_28073;
v_28075:
    v_28700 = stack[0];
    v_28700 = qcar(v_28700);
    goto v_28073;
    v_28700 = nil;
v_28073:
    stack[-5] = v_28700;
    goto v_28102;
v_28098:
    v_28701 = stack[-5];
    goto v_28099;
v_28100:
    v_28700 = elt(env, 2); // or
    goto v_28101;
v_28102:
    goto v_28098;
v_28099:
    goto v_28100;
v_28101:
    if (v_28701 == v_28700) goto v_28096;
    else goto v_28097;
v_28096:
    v_28700 = lisp_true;
    goto v_28095;
v_28097:
    goto v_28112;
v_28108:
    v_28701 = stack[-5];
    goto v_28109;
v_28110:
    v_28700 = elt(env, 3); // and
    goto v_28111;
v_28112:
    goto v_28108;
v_28109:
    goto v_28110;
v_28111:
    v_28700 = (v_28701 == v_28700 ? lisp_true : nil);
    goto v_28095;
    v_28700 = nil;
v_28095:
    if (v_28700 == nil) goto v_28093;
    v_28700 = lisp_true;
    goto v_28091;
v_28093:
    goto v_28123;
v_28119:
    v_28701 = stack[-5];
    goto v_28120;
v_28121:
    v_28700 = elt(env, 4); // not
    goto v_28122;
v_28123:
    goto v_28119;
v_28120:
    goto v_28121;
v_28122:
    v_28700 = (v_28701 == v_28700 ? lisp_true : nil);
    goto v_28091;
    v_28700 = nil;
v_28091:
    if (v_28700 == nil) goto v_28089;
    v_28700 = lisp_true;
    goto v_28087;
v_28089:
    goto v_28138;
v_28134:
    v_28701 = stack[-5];
    goto v_28135;
v_28136:
    v_28700 = elt(env, 5); // impl
    goto v_28137;
v_28138:
    goto v_28134;
v_28135:
    goto v_28136;
v_28137:
    if (v_28701 == v_28700) goto v_28132;
    else goto v_28133;
v_28132:
    v_28700 = lisp_true;
    goto v_28131;
v_28133:
    goto v_28152;
v_28148:
    v_28701 = stack[-5];
    goto v_28149;
v_28150:
    v_28700 = elt(env, 6); // repl
    goto v_28151;
v_28152:
    goto v_28148;
v_28149:
    goto v_28150;
v_28151:
    if (v_28701 == v_28700) goto v_28146;
    else goto v_28147;
v_28146:
    v_28700 = lisp_true;
    goto v_28145;
v_28147:
    goto v_28162;
v_28158:
    v_28701 = stack[-5];
    goto v_28159;
v_28160:
    v_28700 = elt(env, 7); // equiv
    goto v_28161;
v_28162:
    goto v_28158;
v_28159:
    goto v_28160;
v_28161:
    v_28700 = (v_28701 == v_28700 ? lisp_true : nil);
    goto v_28145;
    v_28700 = nil;
v_28145:
    goto v_28131;
    v_28700 = nil;
v_28131:
    goto v_28087;
    v_28700 = nil;
v_28087:
    if (v_28700 == nil) goto v_28085;
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    stack[0] = v_28700;
v_28169:
    v_28700 = stack[0];
    if (v_28700 == nil) goto v_28174;
    else goto v_28175;
v_28174:
    goto v_28168;
v_28175:
    v_28700 = stack[0];
    v_28700 = qcar(v_28700);
    goto v_28189;
v_28185:
    v_28701 = v_28700;
    goto v_28186;
v_28187:
    v_28700 = stack[-4];
    goto v_28188;
v_28189:
    goto v_28185;
v_28186:
    goto v_28187;
v_28188:
    v_28700 = CC_cl_renameKvars1(elt(env, 0), v_28701, v_28700);
    env = stack[-7];
    v_28701 = v_28700;
    v_28700 = v_28701;
    v_28700 = qcar(v_28700);
    stack[-1] = v_28700;
    v_28700 = v_28701;
    v_28700 = qcdr(v_28700);
    stack[-4] = v_28700;
    goto v_28202;
v_28198:
    v_28701 = stack[-1];
    goto v_28199;
v_28200:
    v_28700 = stack[-3];
    goto v_28201;
v_28202:
    goto v_28198;
v_28199:
    goto v_28200;
v_28201:
    v_28700 = cons(v_28701, v_28700);
    env = stack[-7];
    stack[-3] = v_28700;
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    stack[0] = v_28700;
    goto v_28169;
v_28168:
    goto v_28215;
v_28209:
    v_28701 = stack[-5];
    goto v_28210;
v_28211:
    v_28700 = stack[-3];
    v_28702 = Lnreverse(nil, v_28700);
    goto v_28212;
v_28213:
    v_28700 = stack[-4];
    goto v_28214;
v_28215:
    goto v_28209;
v_28210:
    goto v_28211;
v_28212:
    goto v_28213;
v_28214:
    return acons(v_28701, v_28702, v_28700);
v_28085:
    goto v_28232;
v_28228:
    v_28701 = stack[-5];
    goto v_28229;
v_28230:
    v_28700 = elt(env, 8); // ex
    goto v_28231;
v_28232:
    goto v_28228;
v_28229:
    goto v_28230;
v_28231:
    if (v_28701 == v_28700) goto v_28226;
    else goto v_28227;
v_28226:
    v_28700 = lisp_true;
    goto v_28225;
v_28227:
    goto v_28242;
v_28238:
    v_28701 = stack[-5];
    goto v_28239;
v_28240:
    v_28700 = elt(env, 9); // all
    goto v_28241;
v_28242:
    goto v_28238;
v_28239:
    goto v_28240;
v_28241:
    v_28700 = (v_28701 == v_28700 ? lisp_true : nil);
    goto v_28225;
    v_28700 = nil;
v_28225:
    if (v_28700 == nil) goto v_28223;
    goto v_28254;
v_28250:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28700 = qcdr(v_28700);
    v_28701 = qcar(v_28700);
    goto v_28251;
v_28252:
    v_28700 = stack[-4];
    goto v_28253;
v_28254:
    goto v_28250;
v_28251:
    goto v_28252;
v_28253:
    v_28700 = CC_cl_renameKvars1(elt(env, 0), v_28701, v_28700);
    env = stack[-7];
    v_28701 = v_28700;
    v_28700 = v_28701;
    v_28700 = qcar(v_28700);
    stack[-1] = v_28700;
    v_28700 = v_28701;
    v_28700 = qcdr(v_28700);
    stack[-4] = v_28700;
    goto v_28269;
v_28265:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28701 = qcar(v_28700);
    goto v_28266;
v_28267:
    v_28700 = stack[-4];
    v_28700 = qcdr(v_28700);
    goto v_28268;
v_28269:
    goto v_28265;
v_28266:
    goto v_28267;
v_28268:
    v_28700 = Lassoc(nil, v_28701, v_28700);
    stack[-3] = v_28700;
    v_28700 = stack[-3];
    if (v_28700 == nil) goto v_28279;
    goto v_28290;
v_28286:
    v_28700 = stack[-3];
    v_28701 = qcdr(v_28700);
    goto v_28287;
v_28288:
    v_28700 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28289;
v_28290:
    goto v_28286;
v_28287:
    goto v_28288;
v_28289:
    v_28700 = Leqn(nil, v_28701, v_28700);
    env = stack[-7];
    if (v_28700 == nil) goto v_28284;
    goto v_28299;
v_28295:
    v_28701 = stack[-3];
    goto v_28296;
v_28297:
    v_28700 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28298;
v_28299:
    goto v_28295;
v_28296:
    goto v_28297;
v_28298:
    fn = elt(env, 13); // setcdr
    v_28700 = (*qfn2(fn))(fn, v_28701, v_28700);
    env = stack[-7];
    goto v_28307;
v_28303:
    goto v_28315;
v_28309:
    v_28702 = stack[-5];
    goto v_28310;
v_28311:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28701 = qcar(v_28700);
    goto v_28312;
v_28313:
    v_28700 = stack[-1];
    goto v_28314;
v_28315:
    goto v_28309;
v_28310:
    goto v_28311;
v_28312:
    goto v_28313;
v_28314:
    v_28701 = list3(v_28702, v_28701, v_28700);
    goto v_28304;
v_28305:
    v_28700 = stack[-4];
    goto v_28306;
v_28307:
    goto v_28303;
v_28304:
    goto v_28305;
v_28306:
    return cons(v_28701, v_28700);
v_28284:
v_28324:
    goto v_28330;
v_28326:
    v_28700 = stack[-3];
    v_28701 = qcar(v_28700);
    goto v_28327;
v_28328:
    v_28700 = stack[-3];
    v_28700 = qcdr(v_28700);
    goto v_28329;
v_28330:
    goto v_28326;
v_28327:
    goto v_28328;
v_28329:
    fn = elt(env, 14); // mkid
    v_28700 = (*qfn2(fn))(fn, v_28701, v_28700);
    env = stack[-7];
    stack[-2] = v_28700;
    goto v_28340;
v_28336:
    stack[0] = stack[-3];
    goto v_28337;
v_28338:
    v_28700 = stack[-3];
    v_28700 = qcdr(v_28700);
    v_28700 = add1(v_28700);
    env = stack[-7];
    goto v_28339;
v_28340:
    goto v_28336;
v_28337:
    goto v_28338;
v_28339:
    fn = elt(env, 13); // setcdr
    v_28700 = (*qfn2(fn))(fn, stack[0], v_28700);
    env = stack[-7];
    goto v_28354;
v_28350:
    v_28701 = stack[-2];
    goto v_28351;
v_28352:
    v_28700 = stack[-4];
    v_28700 = qcar(v_28700);
    goto v_28353;
v_28354:
    goto v_28350;
v_28351:
    goto v_28352;
v_28353:
    v_28700 = Lmemq(nil, v_28701, v_28700);
    if (v_28700 == nil) goto v_28349;
    else goto v_28347;
v_28349:
    v_28700 = stack[-2];
    if (!symbolp(v_28700)) v_28700 = nil;
    else { v_28700 = qfastgets(v_28700);
           if (v_28700 != nil) { v_28700 = elt(v_28700, 4); // avalue
#ifdef RECORD_GET
             if (v_28700 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_28700 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_28700 == SPID_NOPROP) v_28700 = nil; }}
#endif
    if (v_28700 == nil) goto v_28359;
    else goto v_28347;
v_28359:
    goto v_28348;
v_28347:
    goto v_28324;
v_28348:
    goto v_28367;
v_28363:
    stack[0] = stack[-4];
    goto v_28364;
v_28365:
    goto v_28374;
v_28370:
    v_28701 = stack[-2];
    goto v_28371;
v_28372:
    v_28700 = stack[-4];
    v_28700 = qcar(v_28700);
    goto v_28373;
v_28374:
    goto v_28370;
v_28371:
    goto v_28372;
v_28373:
    v_28700 = cons(v_28701, v_28700);
    env = stack[-7];
    goto v_28366;
v_28367:
    goto v_28363;
v_28364:
    goto v_28365;
v_28366:
    fn = elt(env, 15); // setcar
    v_28700 = (*qfn2(fn))(fn, stack[0], v_28700);
    env = stack[-7];
    goto v_28386;
v_28380:
    goto v_28381;
v_28382:
    stack[0] = elt(env, 10); // rl_varsubstat
    goto v_28383;
v_28384:
    goto v_28394;
v_28390:
    v_28701 = stack[-2];
    goto v_28391;
v_28392:
    v_28700 = stack[-3];
    v_28700 = qcar(v_28700);
    goto v_28393;
v_28394:
    goto v_28390;
v_28391:
    goto v_28392;
v_28393:
    v_28700 = list2(v_28701, v_28700);
    env = stack[-7];
    goto v_28385;
v_28386:
    goto v_28380;
v_28381:
    goto v_28382;
v_28383:
    goto v_28384;
v_28385:
    fn = elt(env, 16); // cl_apply2ats1
    v_28700 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_28700);
    env = stack[-7];
    stack[-1] = v_28700;
    goto v_28403;
v_28399:
    goto v_28411;
v_28405:
    v_28702 = stack[-5];
    goto v_28406;
v_28407:
    v_28701 = stack[-2];
    goto v_28408;
v_28409:
    v_28700 = stack[-1];
    goto v_28410;
v_28411:
    goto v_28405;
v_28406:
    goto v_28407;
v_28408:
    goto v_28409;
v_28410:
    v_28701 = list3(v_28702, v_28701, v_28700);
    goto v_28400;
v_28401:
    v_28700 = stack[-4];
    goto v_28402;
v_28403:
    goto v_28399;
v_28400:
    goto v_28401;
v_28402:
    return cons(v_28701, v_28700);
v_28279:
    goto v_28421;
v_28417:
    goto v_28429;
v_28423:
    v_28702 = stack[-5];
    goto v_28424;
v_28425:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28701 = qcar(v_28700);
    goto v_28426;
v_28427:
    v_28700 = stack[-1];
    goto v_28428;
v_28429:
    goto v_28423;
v_28424:
    goto v_28425;
v_28426:
    goto v_28427;
v_28428:
    v_28701 = list3(v_28702, v_28701, v_28700);
    goto v_28418;
v_28419:
    v_28700 = stack[-4];
    goto v_28420;
v_28421:
    goto v_28417;
v_28418:
    goto v_28419;
v_28420:
    return cons(v_28701, v_28700);
v_28223:
    goto v_28448;
v_28444:
    v_28701 = stack[-5];
    goto v_28445;
v_28446:
    v_28700 = elt(env, 11); // bex
    goto v_28447;
v_28448:
    goto v_28444;
v_28445:
    goto v_28446;
v_28447:
    if (v_28701 == v_28700) goto v_28442;
    else goto v_28443;
v_28442:
    v_28700 = lisp_true;
    goto v_28441;
v_28443:
    goto v_28458;
v_28454:
    v_28701 = stack[-5];
    goto v_28455;
v_28456:
    v_28700 = elt(env, 12); // ball
    goto v_28457;
v_28458:
    goto v_28454;
v_28455:
    goto v_28456;
v_28457:
    v_28700 = (v_28701 == v_28700 ? lisp_true : nil);
    goto v_28441;
    v_28700 = nil;
v_28441:
    if (v_28700 == nil) goto v_28439;
    goto v_28470;
v_28466:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28700 = qcdr(v_28700);
    v_28701 = qcar(v_28700);
    goto v_28467;
v_28468:
    v_28700 = stack[-4];
    goto v_28469;
v_28470:
    goto v_28466;
v_28467:
    goto v_28468;
v_28469:
    v_28700 = CC_cl_renameKvars1(elt(env, 0), v_28701, v_28700);
    env = stack[-7];
    v_28701 = v_28700;
    v_28700 = v_28701;
    v_28700 = qcar(v_28700);
    stack[-1] = v_28700;
    v_28700 = v_28701;
    v_28700 = qcdr(v_28700);
    stack[-4] = v_28700;
    goto v_28485;
v_28481:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28701 = qcar(v_28700);
    goto v_28482;
v_28483:
    v_28700 = stack[-4];
    v_28700 = qcdr(v_28700);
    goto v_28484;
v_28485:
    goto v_28481;
v_28482:
    goto v_28483;
v_28484:
    v_28700 = Lassoc(nil, v_28701, v_28700);
    stack[-3] = v_28700;
    v_28700 = stack[-3];
    if (v_28700 == nil) goto v_28495;
    goto v_28506;
v_28502:
    v_28700 = stack[-3];
    v_28701 = qcdr(v_28700);
    goto v_28503;
v_28504:
    v_28700 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28505;
v_28506:
    goto v_28502;
v_28503:
    goto v_28504;
v_28505:
    v_28700 = Leqn(nil, v_28701, v_28700);
    env = stack[-7];
    if (v_28700 == nil) goto v_28500;
    goto v_28515;
v_28511:
    v_28701 = stack[-3];
    goto v_28512;
v_28513:
    v_28700 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28514;
v_28515:
    goto v_28511;
v_28512:
    goto v_28513;
v_28514:
    fn = elt(env, 13); // setcdr
    v_28700 = (*qfn2(fn))(fn, v_28701, v_28700);
    env = stack[-7];
    goto v_28523;
v_28519:
    goto v_28533;
v_28525:
    v_28703 = stack[-5];
    goto v_28526;
v_28527:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28702 = qcar(v_28700);
    goto v_28528;
v_28529:
    v_28701 = stack[-1];
    goto v_28530;
v_28531:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28700 = qcdr(v_28700);
    v_28700 = qcdr(v_28700);
    v_28700 = qcar(v_28700);
    goto v_28532;
v_28533:
    goto v_28525;
v_28526:
    goto v_28527;
v_28528:
    goto v_28529;
v_28530:
    goto v_28531;
v_28532:
    v_28701 = list4(v_28703, v_28702, v_28701, v_28700);
    goto v_28520;
v_28521:
    v_28700 = stack[-4];
    goto v_28522;
v_28523:
    goto v_28519;
v_28520:
    goto v_28521;
v_28522:
    return cons(v_28701, v_28700);
v_28500:
v_28547:
    goto v_28553;
v_28549:
    v_28700 = stack[-3];
    v_28701 = qcar(v_28700);
    goto v_28550;
v_28551:
    v_28700 = stack[-3];
    v_28700 = qcdr(v_28700);
    goto v_28552;
v_28553:
    goto v_28549;
v_28550:
    goto v_28551;
v_28552:
    fn = elt(env, 14); // mkid
    v_28700 = (*qfn2(fn))(fn, v_28701, v_28700);
    env = stack[-7];
    stack[-2] = v_28700;
    goto v_28563;
v_28559:
    stack[-6] = stack[-3];
    goto v_28560;
v_28561:
    v_28700 = stack[-3];
    v_28700 = qcdr(v_28700);
    v_28700 = add1(v_28700);
    env = stack[-7];
    goto v_28562;
v_28563:
    goto v_28559;
v_28560:
    goto v_28561;
v_28562:
    fn = elt(env, 13); // setcdr
    v_28700 = (*qfn2(fn))(fn, stack[-6], v_28700);
    env = stack[-7];
    goto v_28577;
v_28573:
    v_28701 = stack[-2];
    goto v_28574;
v_28575:
    v_28700 = stack[-4];
    v_28700 = qcar(v_28700);
    goto v_28576;
v_28577:
    goto v_28573;
v_28574:
    goto v_28575;
v_28576:
    v_28700 = Lmemq(nil, v_28701, v_28700);
    if (v_28700 == nil) goto v_28572;
    else goto v_28570;
v_28572:
    v_28700 = stack[-2];
    if (!symbolp(v_28700)) v_28700 = nil;
    else { v_28700 = qfastgets(v_28700);
           if (v_28700 != nil) { v_28700 = elt(v_28700, 4); // avalue
#ifdef RECORD_GET
             if (v_28700 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_28700 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_28700 == SPID_NOPROP) v_28700 = nil; }}
#endif
    if (v_28700 == nil) goto v_28582;
    else goto v_28570;
v_28582:
    goto v_28571;
v_28570:
    goto v_28547;
v_28571:
    goto v_28590;
v_28586:
    stack[-6] = stack[-4];
    goto v_28587;
v_28588:
    goto v_28597;
v_28593:
    v_28701 = stack[-2];
    goto v_28594;
v_28595:
    v_28700 = stack[-4];
    v_28700 = qcar(v_28700);
    goto v_28596;
v_28597:
    goto v_28593;
v_28594:
    goto v_28595;
v_28596:
    v_28700 = cons(v_28701, v_28700);
    env = stack[-7];
    goto v_28589;
v_28590:
    goto v_28586;
v_28587:
    goto v_28588;
v_28589:
    fn = elt(env, 15); // setcar
    v_28700 = (*qfn2(fn))(fn, stack[-6], v_28700);
    env = stack[-7];
    goto v_28609;
v_28603:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28700 = qcdr(v_28700);
    v_28700 = qcdr(v_28700);
    stack[-6] = qcar(v_28700);
    goto v_28604;
v_28605:
    stack[0] = elt(env, 10); // rl_varsubstat
    goto v_28606;
v_28607:
    goto v_28621;
v_28617:
    v_28701 = stack[-2];
    goto v_28618;
v_28619:
    v_28700 = stack[-3];
    v_28700 = qcar(v_28700);
    goto v_28620;
v_28621:
    goto v_28617;
v_28618:
    goto v_28619;
v_28620:
    v_28700 = list2(v_28701, v_28700);
    env = stack[-7];
    goto v_28608;
v_28609:
    goto v_28603;
v_28604:
    goto v_28605;
v_28606:
    goto v_28607;
v_28608:
    fn = elt(env, 16); // cl_apply2ats1
    v_28700 = (*qfnn(fn))(fn, 3, stack[-6], stack[0], v_28700);
    env = stack[-7];
    stack[-6] = v_28700;
    goto v_28632;
v_28626:
    goto v_28627;
v_28628:
    stack[0] = elt(env, 10); // rl_varsubstat
    goto v_28629;
v_28630:
    goto v_28640;
v_28636:
    v_28701 = stack[-2];
    goto v_28637;
v_28638:
    v_28700 = stack[-3];
    v_28700 = qcar(v_28700);
    goto v_28639;
v_28640:
    goto v_28636;
v_28637:
    goto v_28638;
v_28639:
    v_28700 = list2(v_28701, v_28700);
    env = stack[-7];
    goto v_28631;
v_28632:
    goto v_28626;
v_28627:
    goto v_28628;
v_28629:
    goto v_28630;
v_28631:
    fn = elt(env, 16); // cl_apply2ats1
    v_28700 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_28700);
    env = stack[-7];
    stack[-1] = v_28700;
    goto v_28649;
v_28645:
    goto v_28659;
v_28651:
    v_28703 = stack[-5];
    goto v_28652;
v_28653:
    v_28702 = stack[-2];
    goto v_28654;
v_28655:
    v_28701 = stack[-1];
    goto v_28656;
v_28657:
    v_28700 = stack[-6];
    goto v_28658;
v_28659:
    goto v_28651;
v_28652:
    goto v_28653;
v_28654:
    goto v_28655;
v_28656:
    goto v_28657;
v_28658:
    v_28701 = list4(v_28703, v_28702, v_28701, v_28700);
    goto v_28646;
v_28647:
    v_28700 = stack[-4];
    goto v_28648;
v_28649:
    goto v_28645;
v_28646:
    goto v_28647;
v_28648:
    return cons(v_28701, v_28700);
v_28495:
    goto v_28670;
v_28666:
    goto v_28680;
v_28672:
    v_28703 = stack[-5];
    goto v_28673;
v_28674:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28702 = qcar(v_28700);
    goto v_28675;
v_28676:
    v_28701 = stack[-1];
    goto v_28677;
v_28678:
    v_28700 = stack[0];
    v_28700 = qcdr(v_28700);
    v_28700 = qcdr(v_28700);
    v_28700 = qcdr(v_28700);
    v_28700 = qcar(v_28700);
    goto v_28679;
v_28680:
    goto v_28672;
v_28673:
    goto v_28674;
v_28675:
    goto v_28676;
v_28677:
    goto v_28678;
v_28679:
    v_28701 = list4(v_28703, v_28702, v_28701, v_28700);
    goto v_28667;
v_28668:
    v_28700 = stack[-4];
    goto v_28669;
v_28670:
    goto v_28666;
v_28667:
    goto v_28668;
v_28669:
    return cons(v_28701, v_28700);
v_28439:
    goto v_28697;
v_28693:
    v_28701 = stack[0];
    goto v_28694;
v_28695:
    v_28700 = stack[-4];
    goto v_28696;
v_28697:
    goto v_28693;
v_28694:
    goto v_28695;
v_28696:
    return cons(v_28701, v_28700);
    return onevalue(v_28700);
}



// Code for dvfsf_susipost

static LispObject CC_dvfsf_susipost(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28065, v_28066;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28065 = v_28062;
    v_28066 = v_28061;
// end of prologue
    v_28065 = v_28066;
    return onevalue(v_28065);
}



// Code for indordln

static LispObject CC_indordln(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28103, v_28104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28104 = v_28061;
// end of prologue
    v_28103 = v_28104;
    if (v_28103 == nil) goto v_28065;
    else goto v_28066;
v_28065:
    v_28103 = nil;
    goto v_28064;
v_28066:
    v_28103 = v_28104;
    v_28103 = qcdr(v_28103);
    if (v_28103 == nil) goto v_28069;
    else goto v_28070;
v_28069:
    v_28103 = v_28104;
    goto v_28064;
v_28070:
    v_28103 = v_28104;
    v_28103 = qcdr(v_28103);
    v_28103 = qcdr(v_28103);
    if (v_28103 == nil) goto v_28074;
    else goto v_28075;
v_28074:
    goto v_28084;
v_28080:
    v_28103 = v_28104;
    v_28103 = qcar(v_28103);
    goto v_28081;
v_28082:
    v_28104 = qcdr(v_28104);
    v_28104 = qcar(v_28104);
    goto v_28083;
v_28084:
    goto v_28080;
v_28081:
    goto v_28082;
v_28083:
    {
        fn = elt(env, 1); // indordl2
        return (*qfn2(fn))(fn, v_28103, v_28104);
    }
v_28075:
    goto v_28097;
v_28093:
    v_28103 = v_28104;
    stack[0] = qcar(v_28103);
    goto v_28094;
v_28095:
    v_28103 = v_28104;
    v_28103 = qcdr(v_28103);
    v_28103 = CC_indordln(elt(env, 0), v_28103);
    env = stack[-1];
    goto v_28096;
v_28097:
    goto v_28093;
v_28094:
    goto v_28095;
v_28096:
    {
        LispObject v_28106 = stack[0];
        fn = elt(env, 2); // indordlad
        return (*qfn2(fn))(fn, v_28106, v_28103);
    }
    v_28103 = nil;
v_28064:
    return onevalue(v_28103);
}



// Code for defined_all_edge

static LispObject CC_defined_all_edge(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28138, v_28139, v_28140;
    LispObject fn;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "defined_all_edge");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28063,v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28061,v_28062,v_28063);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_28063;
    stack[-1] = v_28062;
    stack[-2] = v_28061;
// end of prologue
v_28068:
    v_28138 = stack[-2];
    if (v_28138 == nil) goto v_28071;
    else goto v_28072;
v_28071:
    v_28138 = nil;
    goto v_28067;
v_28072:
    goto v_28082;
v_28078:
    v_28138 = stack[-2];
    v_28139 = qcar(v_28138);
    goto v_28079;
v_28080:
    v_28138 = stack[0];
    goto v_28081;
v_28082:
    goto v_28078;
v_28079:
    goto v_28080;
v_28081:
    fn = elt(env, 1); // def_edge
    v_28138 = (*qfn2(fn))(fn, v_28139, v_28138);
    env = stack[-4];
    if (v_28138 == nil) goto v_28076;
    v_28138 = stack[-2];
    v_28138 = qcar(v_28138);
    fn = elt(env, 2); // p_def_edge
    v_28138 = (*qfn1(fn))(fn, v_28138);
    env = stack[-4];
    if (v_28138 == nil) goto v_28089;
    v_28138 = lisp_true;
    goto v_28067;
v_28089:
    goto v_28101;
v_28097:
    goto v_28107;
v_28103:
    v_28139 = stack[-1];
    goto v_28104;
v_28105:
    v_28138 = stack[-2];
    goto v_28106;
v_28107:
    goto v_28103;
v_28104:
    goto v_28105;
v_28106:
    stack[0] = Lnconc(nil, v_28139, v_28138);
    env = stack[-4];
    goto v_28098;
v_28099:
    goto v_28117;
v_28111:
    v_28138 = stack[-2];
    v_28138 = qcar(v_28138);
    v_28138 = qcdr(v_28138);
    v_28140 = qcar(v_28138);
    goto v_28112;
v_28113:
    v_28139 = lisp_true;
    goto v_28114;
v_28115:
    v_28138 = nil;
    goto v_28116;
v_28117:
    goto v_28111;
v_28112:
    goto v_28113;
v_28114:
    goto v_28115;
v_28116:
    v_28138 = list2star(v_28140, v_28139, v_28138);
    env = stack[-4];
    goto v_28100;
v_28101:
    goto v_28097;
v_28098:
    goto v_28099;
v_28100:
    {
        LispObject v_28145 = stack[0];
        fn = elt(env, 3); // rep_edge_prop_
        return (*qfn2(fn))(fn, v_28145, v_28138);
    }
    goto v_28070;
v_28076:
    v_28138 = stack[-2];
    v_28138 = qcdr(v_28138);
    stack[-3] = v_28138;
    goto v_28133;
v_28129:
    v_28138 = stack[-2];
    v_28139 = qcar(v_28138);
    goto v_28130;
v_28131:
    v_28138 = stack[-1];
    goto v_28132;
v_28133:
    goto v_28129;
v_28130:
    goto v_28131;
v_28132:
    v_28138 = cons(v_28139, v_28138);
    env = stack[-4];
    stack[-1] = v_28138;
    v_28138 = stack[-3];
    stack[-2] = v_28138;
    goto v_28068;
v_28070:
    v_28138 = nil;
v_28067:
    return onevalue(v_28138);
}



// Code for freeoflist

static LispObject CC_freeoflist(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28089, v_28090;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28062;
    stack[-1] = v_28061;
// end of prologue
v_28066:
    v_28089 = stack[0];
    if (v_28089 == nil) goto v_28069;
    else goto v_28070;
v_28069:
    v_28089 = lisp_true;
    goto v_28065;
v_28070:
    goto v_28080;
v_28076:
    v_28090 = stack[-1];
    goto v_28077;
v_28078:
    v_28089 = stack[0];
    v_28089 = qcar(v_28089);
    goto v_28079;
v_28080:
    goto v_28076;
v_28077:
    goto v_28078;
v_28079:
    fn = elt(env, 1); // freeof
    v_28089 = (*qfn2(fn))(fn, v_28090, v_28089);
    env = stack[-2];
    if (v_28089 == nil) goto v_28074;
    v_28089 = stack[0];
    v_28089 = qcdr(v_28089);
    stack[0] = v_28089;
    goto v_28066;
v_28074:
    v_28089 = nil;
    goto v_28065;
    v_28089 = nil;
v_28065:
    return onevalue(v_28089);
}



// Code for !*a2kwoweight

static LispObject CC_Ha2kwoweight(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28091, v_28092;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_28061;
// end of prologue
    v_28092 = lisp_true;
    v_28091 = nil;
// Binding !*uncached
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_28092; // !*uncached
// Binding wtl!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 2, -1);
    qvalue(elt(env, 2)) = v_28091; // wtl!*
    v_28091 = stack[-2];
    fn = elt(env, 4); // simp!*
    v_28091 = (*qfn1(fn))(fn, v_28091);
    env = stack[-4];
    stack[0] = v_28091;
    v_28091 = stack[0];
    fn = elt(env, 5); // kernp
    v_28091 = (*qfn1(fn))(fn, v_28091);
    env = stack[-4];
    if (v_28091 == nil) goto v_28073;
    v_28091 = stack[0];
    v_28091 = qcar(v_28091);
    v_28091 = qcar(v_28091);
    v_28091 = qcar(v_28091);
    v_28091 = qcar(v_28091);
    goto v_28071;
v_28073:
    goto v_28088;
v_28084:
    v_28092 = stack[-2];
    goto v_28085;
v_28086:
    v_28091 = elt(env, 3); // kernel
    goto v_28087;
v_28088:
    goto v_28084;
v_28085:
    goto v_28086;
v_28087:
    fn = elt(env, 6); // typerr
    v_28091 = (*qfn2(fn))(fn, v_28092, v_28091);
    goto v_28071;
    v_28091 = nil;
v_28071:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_28091);
}



// Code for count!-linear!-factors!-mod!-p

static LispObject CC_countKlinearKfactorsKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28386, v_28387, v_28388, v_28389, v_28390;
    LispObject fn;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "count-linear-factors-mod-p");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28063,v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28061,v_28062,v_28063);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_28063;
    stack[-2] = v_28062;
    stack[-3] = v_28061;
// end of prologue
// Binding linear!-factors
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 1, 0);
    qvalue(elt(env, 1)) = nil; // linear!-factors
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    v_28390 = v_28386;
v_28074:
    goto v_28084;
v_28080:
    v_28387 = qvalue(elt(env, 3)); // dpoly
    goto v_28081;
v_28082:
    v_28386 = v_28390;
    goto v_28083;
v_28084:
    goto v_28080;
v_28081:
    goto v_28082;
v_28083:
    v_28386 = (LispObject)(intptr_t)((intptr_t)v_28387 - (intptr_t)v_28386 + TAG_FIXNUM);
    v_28386 = ((intptr_t)(v_28386) < 0 ? lisp_true : nil);
    if (v_28386 == nil) goto v_28079;
    goto v_28073;
v_28079:
    goto v_28096;
v_28090:
    v_28389 = stack[-2];
    goto v_28091;
v_28092:
    v_28388 = v_28390;
    goto v_28093;
v_28094:
    goto v_28103;
v_28099:
    v_28387 = qvalue(elt(env, 4)); // poly!-vector
    goto v_28100;
v_28101:
    v_28386 = v_28390;
    goto v_28102;
v_28103:
    goto v_28099;
v_28100:
    goto v_28101;
v_28102:
    v_28386 = *(LispObject *)((char *)v_28387 + (CELL-TAG_VECTOR) + (((intptr_t)v_28386-TAG_FIXNUM)/(16/CELL)));
    goto v_28095;
v_28096:
    goto v_28090;
v_28091:
    goto v_28092;
v_28093:
    goto v_28094;
v_28095:
    *(LispObject *)((char *)v_28389 + (CELL-TAG_VECTOR) + (((intptr_t)v_28388-TAG_FIXNUM)/(16/CELL))) = v_28386;
    v_28386 = v_28390;
    v_28386 = (LispObject)((intptr_t)(v_28386) + 0x10);
    v_28390 = v_28386;
    goto v_28074;
v_28073:
    goto v_28116;
v_28110:
    v_28388 = qvalue(elt(env, 5)); // current!-modulus
    goto v_28111;
v_28112:
    v_28387 = stack[-3];
    goto v_28113;
v_28114:
    v_28386 = stack[-1];
    goto v_28115;
v_28116:
    goto v_28110;
v_28111:
    goto v_28112;
v_28113:
    goto v_28114;
v_28115:
    fn = elt(env, 6); // make!-x!-to!-p
    v_28386 = (*qfnn(fn))(fn, 3, v_28388, v_28387, v_28386);
    env = stack[-5];
    stack[-4] = v_28386;
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    v_28390 = v_28386;
v_28123:
    goto v_28133;
v_28129:
    v_28387 = stack[-4];
    goto v_28130;
v_28131:
    v_28386 = v_28390;
    goto v_28132;
v_28133:
    goto v_28129;
v_28130:
    goto v_28131;
v_28132:
    v_28386 = (LispObject)(intptr_t)((intptr_t)v_28387 - (intptr_t)v_28386 + TAG_FIXNUM);
    v_28386 = ((intptr_t)(v_28386) < 0 ? lisp_true : nil);
    if (v_28386 == nil) goto v_28128;
    goto v_28122;
v_28128:
    goto v_28145;
v_28139:
    v_28389 = stack[-3];
    goto v_28140;
v_28141:
    v_28388 = v_28390;
    goto v_28142;
v_28143:
    goto v_28152;
v_28148:
    v_28387 = stack[-1];
    goto v_28149;
v_28150:
    v_28386 = v_28390;
    goto v_28151;
v_28152:
    goto v_28148;
v_28149:
    goto v_28150;
v_28151:
    v_28386 = *(LispObject *)((char *)v_28387 + (CELL-TAG_VECTOR) + (((intptr_t)v_28386-TAG_FIXNUM)/(16/CELL)));
    goto v_28144;
v_28145:
    goto v_28139;
v_28140:
    goto v_28141;
v_28142:
    goto v_28143;
v_28144:
    *(LispObject *)((char *)v_28389 + (CELL-TAG_VECTOR) + (((intptr_t)v_28388-TAG_FIXNUM)/(16/CELL))) = v_28386;
    v_28386 = v_28390;
    v_28386 = (LispObject)((intptr_t)(v_28386) + 0x10);
    v_28390 = v_28386;
    goto v_28123;
v_28122:
    goto v_28166;
v_28162:
    v_28387 = stack[-4];
    goto v_28163;
v_28164:
    v_28386 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28165;
v_28166:
    goto v_28162;
v_28163:
    goto v_28164;
v_28165:
    if (((intptr_t)(v_28387)) < ((intptr_t)(v_28386))) goto v_28160;
    else goto v_28161;
v_28160:
    goto v_28177;
v_28173:
    v_28387 = stack[-4];
    goto v_28174;
v_28175:
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28176;
v_28177:
    goto v_28173;
v_28174:
    goto v_28175;
v_28176:
    if (((intptr_t)(v_28387)) < ((intptr_t)(v_28386))) goto v_28171;
    else goto v_28172;
v_28171:
    goto v_28186;
v_28180:
    v_28388 = stack[-3];
    goto v_28181;
v_28182:
    v_28387 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28183;
v_28184:
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28185;
v_28186:
    goto v_28180;
v_28181:
    goto v_28182;
v_28183:
    goto v_28184;
v_28185:
    *(LispObject *)((char *)v_28388 + (CELL-TAG_VECTOR) + (((intptr_t)v_28387-TAG_FIXNUM)/(16/CELL))) = v_28386;
    goto v_28170;
v_28172:
v_28170:
    goto v_28196;
v_28190:
    v_28388 = stack[-3];
    goto v_28191;
v_28192:
    v_28387 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28193;
v_28194:
    v_28386 = (LispObject)16+TAG_FIXNUM; // 1
    {   intptr_t w = int_of_fixnum(v_28386);
        if (w != 0) w = current_modulus - w;
        v_28386 = fixnum_of_int(w);
    }
    goto v_28195;
v_28196:
    goto v_28190;
v_28191:
    goto v_28192;
v_28193:
    goto v_28194;
v_28195:
    *(LispObject *)((char *)v_28388 + (CELL-TAG_VECTOR) + (((intptr_t)v_28387-TAG_FIXNUM)/(16/CELL))) = v_28386;
    v_28386 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_28386;
    goto v_28159;
v_28161:
    goto v_28210;
v_28204:
    v_28389 = stack[-3];
    goto v_28205;
v_28206:
    v_28388 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28207;
v_28208:
    goto v_28217;
v_28213:
    goto v_28222;
v_28218:
    v_28387 = stack[-3];
    goto v_28219;
v_28220:
    v_28386 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28221;
v_28222:
    goto v_28218;
v_28219:
    goto v_28220;
v_28221:
    v_28387 = *(LispObject *)((char *)v_28387 + (CELL-TAG_VECTOR) + (((intptr_t)v_28386-TAG_FIXNUM)/(16/CELL)));
    goto v_28214;
v_28215:
    v_28386 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28216;
v_28217:
    goto v_28213;
v_28214:
    goto v_28215;
v_28216:
    {   intptr_t w = int_of_fixnum(v_28387) - int_of_fixnum(v_28386);
        if (w < 0) w += current_modulus;
        v_28386 = fixnum_of_int(w);
    }
    goto v_28209;
v_28210:
    goto v_28204;
v_28205:
    goto v_28206;
v_28207:
    goto v_28208;
v_28209:
    *(LispObject *)((char *)v_28389 + (CELL-TAG_VECTOR) + (((intptr_t)v_28388-TAG_FIXNUM)/(16/CELL))) = v_28386;
    goto v_28240;
v_28236:
    v_28387 = stack[-4];
    goto v_28237;
v_28238:
    v_28386 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28239;
v_28240:
    goto v_28236;
v_28237:
    goto v_28238;
v_28239:
    if (v_28387 == v_28386) goto v_28234;
    else goto v_28235;
v_28234:
    goto v_28247;
v_28243:
    goto v_28252;
v_28248:
    v_28387 = stack[-3];
    goto v_28249;
v_28250:
    v_28386 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28251;
v_28252:
    goto v_28248;
v_28249:
    goto v_28250;
v_28251:
    v_28387 = *(LispObject *)((char *)v_28387 + (CELL-TAG_VECTOR) + (((intptr_t)v_28386-TAG_FIXNUM)/(16/CELL)));
    goto v_28244;
v_28245:
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28246;
v_28247:
    goto v_28243;
v_28244:
    goto v_28245;
v_28246:
    v_28386 = (v_28387 == v_28386 ? lisp_true : nil);
    goto v_28233;
v_28235:
    v_28386 = nil;
    goto v_28233;
    v_28386 = nil;
v_28233:
    if (v_28386 == nil) goto v_28231;
    goto v_28269;
v_28265:
    goto v_28274;
v_28270:
    v_28387 = stack[-3];
    goto v_28271;
v_28272:
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28273;
v_28274:
    goto v_28270;
v_28271:
    goto v_28272;
v_28273:
    v_28387 = *(LispObject *)((char *)v_28387 + (CELL-TAG_VECTOR) + (((intptr_t)v_28386-TAG_FIXNUM)/(16/CELL)));
    goto v_28266;
v_28267:
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28268;
v_28269:
    goto v_28265;
v_28266:
    goto v_28267;
v_28268:
    if (v_28387 == v_28386) goto v_28263;
    else goto v_28264;
v_28263:
    v_28386 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-4] = v_28386;
    goto v_28262;
v_28264:
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_28386;
    goto v_28262;
v_28262:
    goto v_28229;
v_28231:
v_28229:
    goto v_28159;
v_28159:
    goto v_28291;
v_28287:
    v_28387 = stack[-4];
    goto v_28288;
v_28289:
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28290;
v_28291:
    goto v_28287;
v_28288:
    goto v_28289;
v_28290:
    if (((intptr_t)(v_28387)) < ((intptr_t)(v_28386))) goto v_28285;
    else goto v_28286;
v_28285:
    goto v_28301;
v_28295:
    v_28388 = stack[-2];
    goto v_28296;
v_28297:
    v_28387 = qvalue(elt(env, 3)); // dpoly
    goto v_28298;
v_28299:
    v_28386 = stack[-3];
    goto v_28300;
v_28301:
    goto v_28295;
v_28296:
    goto v_28297;
v_28298:
    goto v_28299;
v_28300:
    fn = elt(env, 7); // copy!-vector
    v_28386 = (*qfnn(fn))(fn, 3, v_28388, v_28387, v_28386);
    env = stack[-5];
    stack[-1] = v_28386;
    goto v_28284;
v_28286:
    goto v_28316;
v_28308:
    v_28389 = stack[-3];
    goto v_28309;
v_28310:
    v_28388 = stack[-4];
    goto v_28311;
v_28312:
    v_28387 = stack[-2];
    goto v_28313;
v_28314:
    v_28386 = qvalue(elt(env, 3)); // dpoly
    goto v_28315;
v_28316:
    goto v_28308;
v_28309:
    goto v_28310;
v_28311:
    goto v_28312;
v_28313:
    goto v_28314;
v_28315:
    fn = elt(env, 8); // gcd!-in!-vector
    v_28386 = (*qfnn(fn))(fn, 4, v_28389, v_28388, v_28387, v_28386);
    env = stack[-5];
    stack[-1] = v_28386;
    goto v_28284;
v_28284:
    v_28386 = stack[-1];
    v_28386 = Lmkvect(nil, v_28386);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_28386; // linear!-factors
    v_28386 = (LispObject)0+TAG_FIXNUM; // 0
    v_28390 = v_28386;
v_28326:
    goto v_28336;
v_28332:
    v_28387 = stack[-1];
    goto v_28333;
v_28334:
    v_28386 = v_28390;
    goto v_28335;
v_28336:
    goto v_28332;
v_28333:
    goto v_28334;
v_28335:
    v_28386 = (LispObject)(intptr_t)((intptr_t)v_28387 - (intptr_t)v_28386 + TAG_FIXNUM);
    v_28386 = ((intptr_t)(v_28386) < 0 ? lisp_true : nil);
    if (v_28386 == nil) goto v_28331;
    goto v_28325;
v_28331:
    goto v_28348;
v_28342:
    v_28389 = qvalue(elt(env, 1)); // linear!-factors
    goto v_28343;
v_28344:
    v_28388 = v_28390;
    goto v_28345;
v_28346:
    goto v_28355;
v_28351:
    v_28387 = stack[-3];
    goto v_28352;
v_28353:
    v_28386 = v_28390;
    goto v_28354;
v_28355:
    goto v_28351;
v_28352:
    goto v_28353;
v_28354:
    v_28386 = *(LispObject *)((char *)v_28387 + (CELL-TAG_VECTOR) + (((intptr_t)v_28386-TAG_FIXNUM)/(16/CELL)));
    goto v_28347;
v_28348:
    goto v_28342;
v_28343:
    goto v_28344;
v_28345:
    goto v_28346;
v_28347:
    *(LispObject *)((char *)v_28389 + (CELL-TAG_VECTOR) + (((intptr_t)v_28388-TAG_FIXNUM)/(16/CELL))) = v_28386;
    v_28386 = v_28390;
    v_28386 = (LispObject)((intptr_t)(v_28386) + 0x10);
    v_28390 = v_28386;
    goto v_28326;
v_28325:
    goto v_28370;
v_28362:
    v_28389 = qvalue(elt(env, 4)); // poly!-vector
    goto v_28363;
v_28364:
    v_28388 = qvalue(elt(env, 3)); // dpoly
    goto v_28365;
v_28366:
    v_28387 = qvalue(elt(env, 1)); // linear!-factors
    goto v_28367;
v_28368:
    v_28386 = stack[-1];
    goto v_28369;
v_28370:
    goto v_28362;
v_28363:
    goto v_28364;
v_28365:
    goto v_28366;
v_28367:
    goto v_28368;
v_28369:
    fn = elt(env, 9); // quotfail!-in!-vector
    v_28386 = (*qfnn(fn))(fn, 4, v_28389, v_28388, v_28387, v_28386);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_28386; // dpoly
    goto v_28382;
v_28376:
    v_28388 = stack[-1];
    goto v_28377;
v_28378:
    v_28387 = qvalue(elt(env, 1)); // linear!-factors
    goto v_28379;
v_28380:
    v_28386 = stack[-4];
    goto v_28381;
v_28382:
    goto v_28376;
v_28377:
    goto v_28378;
v_28379:
    goto v_28380;
v_28381:
    v_28386 = list3(v_28388, v_28387, v_28386);
    ;}  // end of a binding scope
    return onevalue(v_28386);
}



// Code for polynomreduceby

static LispObject CC_polynomreduceby(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28144, v_28145;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_28062;
    stack[-2] = v_28061;
// end of prologue
    stack[-3] = nil;
v_28072:
    v_28144 = stack[-3];
    if (v_28144 == nil) goto v_28076;
    goto v_28071;
v_28076:
    v_28144 = stack[-2];
    stack[0] = v_28144;
v_28082:
    v_28144 = stack[0];
    v_28144 = qcar(v_28144);
    if (v_28144 == nil) goto v_28085;
    goto v_28096;
v_28092:
    v_28144 = stack[0];
    v_28145 = qcar(v_28144);
    goto v_28093;
v_28094:
    v_28144 = stack[-1];
    v_28144 = qcar(v_28144);
    goto v_28095;
v_28096:
    goto v_28092;
v_28093:
    goto v_28094;
v_28095:
    fn = elt(env, 3); // monomisdivisibleby
    v_28144 = (*qfn2(fn))(fn, v_28145, v_28144);
    env = stack[-4];
    if (v_28144 == nil) goto v_28090;
    else goto v_28085;
v_28090:
    goto v_28086;
v_28085:
    goto v_28081;
v_28086:
    v_28144 = stack[0];
    v_28144 = qcdr(v_28144);
    stack[0] = v_28144;
    goto v_28082;
v_28081:
    v_28144 = stack[0];
    v_28144 = qcar(v_28144);
    if (v_28144 == nil) goto v_28107;
    else goto v_28108;
v_28107:
    v_28144 = lisp_true;
    stack[-3] = v_28144;
    goto v_28106;
v_28108:
    goto v_28120;
v_28116:
    v_28144 = stack[0];
    v_28145 = qcar(v_28144);
    goto v_28117;
v_28118:
    v_28144 = stack[-1];
    v_28144 = qcar(v_28144);
    goto v_28119;
v_28120:
    goto v_28116;
v_28117:
    goto v_28118;
v_28119:
    fn = elt(env, 4); // monomdivide
    v_28144 = (*qfn2(fn))(fn, v_28145, v_28144);
    env = stack[-4];
    goto v_28130;
v_28126:
    stack[0] = stack[-2];
    goto v_28127;
v_28128:
    goto v_28137;
v_28133:
    v_28145 = stack[-1];
    goto v_28134;
v_28135:
    goto v_28136;
v_28137:
    goto v_28133;
v_28134:
    goto v_28135;
v_28136:
    fn = elt(env, 5); // polynommultiplybymonom
    v_28144 = (*qfn2(fn))(fn, v_28145, v_28144);
    env = stack[-4];
    goto v_28129;
v_28130:
    goto v_28126;
v_28127:
    goto v_28128;
v_28129:
    fn = elt(env, 6); // polynomadd
    v_28144 = (*qfn2(fn))(fn, stack[0], v_28144);
    env = stack[-4];
    goto v_28106;
v_28106:
    goto v_28072;
v_28071:
    v_28144 = qvalue(elt(env, 2)); // fluidbibasisreductionsmade
    v_28144 = (LispObject)((intptr_t)(v_28144) + 0x10);
    qvalue(elt(env, 2)) = v_28144; // fluidbibasisreductionsmade
    v_28144 = nil;
    return onevalue(v_28144);
}



// Code for rl_sacat

static LispObject CC_rl_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28083, v_28084, v_28085;
    LispObject fn;
    LispObject v_28063, v_28062, v_28061;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_sacat");
    va_start(aa, nargs);
    v_28061 = va_arg(aa, LispObject);
    v_28062 = va_arg(aa, LispObject);
    v_28063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28063,v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28061,v_28062,v_28063);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28083 = v_28063;
    v_28084 = v_28062;
    v_28085 = v_28061;
// end of prologue
    goto v_28070;
v_28066:
    stack[0] = qvalue(elt(env, 1)); // rl_sacat!*
    goto v_28067;
v_28068:
    goto v_28079;
v_28073:
    goto v_28074;
v_28075:
    goto v_28076;
v_28077:
    goto v_28078;
v_28079:
    goto v_28073;
v_28074:
    goto v_28075;
v_28076:
    goto v_28077;
v_28078:
    v_28083 = list3(v_28085, v_28084, v_28083);
    env = stack[-1];
    goto v_28069;
v_28070:
    goto v_28066;
v_28067:
    goto v_28068;
v_28069:
    {
        LispObject v_28087 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_28087, v_28083);
    }
}



// Code for bc_dcont

static LispObject CC_bc_dcont(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28066;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28066 = v_28061;
// end of prologue
    v_28066 = qcar(v_28066);
    {
        fn = elt(env, 1); // sfto_dcontentf
        return (*qfn1(fn))(fn, v_28066);
    }
}



// Code for dvfsf_ppolyp

static LispObject CC_dvfsf_ppolyp(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28103, v_28104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28061);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_28104 = v_28061;
// end of prologue
    v_28103 = v_28104;
    if (!consp(v_28103)) goto v_28073;
    else goto v_28074;
v_28073:
    v_28103 = lisp_true;
    goto v_28072;
v_28074:
    v_28103 = v_28104;
    v_28103 = qcar(v_28103);
    v_28103 = (consp(v_28103) ? nil : lisp_true);
    goto v_28072;
    v_28103 = nil;
v_28072:
    if (v_28103 == nil) goto v_28070;
    v_28103 = lisp_true;
    goto v_28065;
v_28070:
    v_28103 = v_28104;
    fn = elt(env, 3); // kernels
    v_28103 = (*qfn1(fn))(fn, v_28103);
    env = stack[0];
    v_28104 = v_28103;
    v_28103 = v_28104;
    v_28103 = qcdr(v_28103);
    if (v_28103 == nil) goto v_28087;
    else goto v_28088;
v_28087:
    goto v_28095;
v_28091:
    v_28103 = v_28104;
    v_28103 = qcar(v_28103);
    goto v_28092;
v_28093:
    v_28104 = elt(env, 2); // p
    goto v_28094;
v_28095:
    goto v_28091;
v_28092:
    goto v_28093;
v_28094:
    v_28103 = (v_28103 == v_28104 ? lisp_true : nil);
    goto v_28086;
v_28088:
    v_28103 = nil;
    goto v_28086;
    v_28103 = nil;
v_28086:
v_28065:
    return onevalue(v_28103);
}



// Code for copy_vect

static LispObject CC_copy_vect(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28094, v_28095, v_28096;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28062,v_28061);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28061,v_28062);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28062;
    stack[-1] = v_28061;
// end of prologue
    v_28094 = stack[-1];
    v_28094 = qcdr(v_28094);
    v_28094 = qcar(v_28094);
    fn = elt(env, 3); // fullcopy
    v_28094 = (*qfn1(fn))(fn, v_28094);
    env = stack[-2];
    v_28095 = stack[0];
    if (v_28095 == nil) goto v_28076;
    else goto v_28077;
v_28076:
    v_28095 = stack[-1];
    v_28095 = qcdr(v_28095);
    v_28095 = qcdr(v_28095);
    v_28095 = qcar(v_28095);
    stack[0] = v_28095;
    goto v_28075;
v_28077:
v_28075:
    goto v_28090;
v_28084:
    v_28096 = elt(env, 2); // sparsemat
    goto v_28085;
v_28086:
    v_28095 = v_28094;
    goto v_28087;
v_28088:
    v_28094 = stack[0];
    goto v_28089;
v_28090:
    goto v_28084;
v_28085:
    goto v_28086;
v_28087:
    goto v_28088;
v_28089:
    return list3(v_28096, v_28095, v_28094);
    return onevalue(v_28094);
}



// Code for dipretimes

static LispObject CC_dipretimes(LispObject env,
                         LispObject v_28061)
{
    env = qenv(env);
    LispObject v_28105, v_28106, v_28107;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28106 = v_28061;
// end of prologue
v_28065:
    goto v_28074;
v_28070:
    v_28105 = v_28106;
    v_28107 = qcar(v_28105);
    goto v_28071;
v_28072:
    v_28105 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28073;
v_28074:
    goto v_28070;
v_28071:
    goto v_28072;
v_28073:
    if (v_28107 == v_28105) goto v_28068;
    else goto v_28069;
v_28068:
    v_28105 = v_28106;
    v_28105 = qcdr(v_28105);
    if (v_28105 == nil) goto v_28081;
    v_28105 = v_28106;
    v_28105 = qcdr(v_28105);
    v_28106 = v_28105;
    goto v_28065;
v_28081:
    v_28105 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28064;
    goto v_28067;
v_28069:
    v_28105 = v_28106;
    v_28105 = qcdr(v_28105);
    if (v_28105 == nil) goto v_28089;
    else goto v_28090;
v_28089:
    v_28105 = v_28106;
    v_28105 = qcar(v_28105);
    goto v_28064;
v_28090:
    goto v_28102;
v_28098:
    v_28105 = elt(env, 1); // times
    goto v_28099;
v_28100:
    goto v_28101;
v_28102:
    goto v_28098;
v_28099:
    goto v_28100;
v_28101:
    return cons(v_28105, v_28106);
v_28067:
    v_28105 = nil;
v_28064:
    return onevalue(v_28105);
}



// Code for gfquotient

static LispObject CC_gfquotient(LispObject env,
                         LispObject v_28061, LispObject v_28062)
{
    env = qenv(env);
    LispObject v_28088, v_28089, v_28090;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28089 = v_28062;
    v_28090 = v_28061;
// end of prologue
    v_28088 = v_28090;
    v_28088 = qcar(v_28088);
    if (!consp(v_28088)) goto v_28066;
    else goto v_28067;
v_28066:
    goto v_28075;
v_28071:
    v_28088 = v_28090;
    goto v_28072;
v_28073:
    goto v_28074;
v_28075:
    goto v_28071;
v_28072:
    goto v_28073;
v_28074:
    {
        fn = elt(env, 1); // gffquot
        return (*qfn2(fn))(fn, v_28088, v_28089);
    }
v_28067:
    goto v_28085;
v_28081:
    v_28088 = v_28090;
    goto v_28082;
v_28083:
    goto v_28084;
v_28085:
    goto v_28081;
v_28082:
    goto v_28083;
v_28084:
    {
        fn = elt(env, 2); // gbfquot
        return (*qfn2(fn))(fn, v_28088, v_28089);
    }
    v_28088 = nil;
    return onevalue(v_28088);
}



setup_type const u49_setup[] =
{
    {"setmatelem",              TOO_FEW_2,      CC_setmatelem, WRONG_NO_2},
    {"mv2sf",                   TOO_FEW_2,      CC_mv2sf,      WRONG_NO_2},
    {"nodum_varp",              CC_nodum_varp,  TOO_MANY_1,    WRONG_NO_1},
    {"try-all-constants",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tryKallKconstants},
    {"aex_psremseq",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_aex_psremseq},
    {"polynomlistautoreduce",   TOO_FEW_2,      CC_polynomlistautoreduce,WRONG_NO_2},
    {"checkexp",                TOO_FEW_2,      CC_checkexp,   WRONG_NO_2},
    {"my_freeof",               TOO_FEW_2,      CC_my_freeof,  WRONG_NO_2},
    {"talp_simplatlinv",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatlinv},
    {"qqe_simplqneq",           TOO_FEW_2,      CC_qqe_simplqneq,WRONG_NO_2},
    {"gb_searchinlist",         TOO_FEW_2,      CC_gb_searchinlist,WRONG_NO_2},
    {"cnml",                    CC_cnml,        TOO_MANY_1,    WRONG_NO_1},
    {"newsym1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_newsym1},
    {"groebcplistmerge",        TOO_FEW_2,      CC_groebcplistmerge,WRONG_NO_2},
    {"xregister_spoly_pair",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xregister_spoly_pair},
    {"mkforttab",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkforttab},
    {"asymmetrize-inds",        TOO_FEW_2,      CC_asymmetrizeKinds,WRONG_NO_2},
    {"split-comfac-part",       CC_splitKcomfacKpart,TOO_MANY_1,WRONG_NO_1},
    {"mv-compact",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mvKcompact},
    {"simp-prop",               CC_simpKprop,   TOO_MANY_1,    WRONG_NO_1},
    {"vecsimp*",                CC_vecsimpH,    TOO_MANY_1,    WRONG_NO_1},
    {"check_letop",             CC_check_letop, TOO_MANY_1,    WRONG_NO_1},
    {"random-small-prime",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_randomKsmallKprime},
    {"aex_xtothen",             TOO_FEW_2,      CC_aex_xtothen,WRONG_NO_2},
    {"ofsf_facequal",           CC_ofsf_facequal,TOO_MANY_1,   WRONG_NO_1},
    {"cl_identifyonoff",        CC_cl_identifyonoff,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_smeqtable",          TOO_FEW_2,      CC_ofsf_smeqtable,WRONG_NO_2},
    {"dfdeg",                   TOO_FEW_2,      CC_dfdeg,      WRONG_NO_2},
    {"mksfpf",                  TOO_FEW_2,      CC_mksfpf,     WRONG_NO_2},
    {"cl_sacat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_sacat},
    {"acfsf_clnegrel",          TOO_FEW_2,      CC_acfsf_clnegrel,WRONG_NO_2},
    {"nestzerop:",              CC_nestzeropT,  TOO_MANY_1,    WRONG_NO_1},
    {"reduce-weights",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reduceKweights},
    {"groeb=testb",             TOO_FEW_2,      CC_groebMtestb,WRONG_NO_2},
    {"girationalize:",          CC_girationalizeT,TOO_MANY_1,  WRONG_NO_1},
    {"f2df",                    CC_f2df,        TOO_MANY_1,    WRONG_NO_1},
    {"cl_rename-vars1",         TOO_FEW_2,      CC_cl_renameKvars1,WRONG_NO_2},
    {"dvfsf_susipost",          TOO_FEW_2,      CC_dvfsf_susipost,WRONG_NO_2},
    {"indordln",                CC_indordln,    TOO_MANY_1,    WRONG_NO_1},
    {"defined_all_edge",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_defined_all_edge},
    {"freeoflist",              TOO_FEW_2,      CC_freeoflist, WRONG_NO_2},
    {"*a2kwoweight",            CC_Ha2kwoweight,TOO_MANY_1,    WRONG_NO_1},
    {"count-linear-factors-mod-p",WRONG_NO_NA,  WRONG_NO_NB,   (n_args *)CC_countKlinearKfactorsKmodKp},
    {"polynomreduceby",         TOO_FEW_2,      CC_polynomreduceby,WRONG_NO_2},
    {"rl_sacat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_sacat},
    {"bc_dcont",                CC_bc_dcont,    TOO_MANY_1,    WRONG_NO_1},
    {"dvfsf_ppolyp",            CC_dvfsf_ppolyp,TOO_MANY_1,    WRONG_NO_1},
    {"copy_vect",               TOO_FEW_2,      CC_copy_vect,  WRONG_NO_2},
    {"dipretimes",              CC_dipretimes,  TOO_MANY_1,    WRONG_NO_1},
    {"gfquotient",              TOO_FEW_2,      CC_gfquotient, WRONG_NO_2},
    {NULL, (one_args *)"u49", (two_args *)"107456 5796170 5831405", 0}
};

// end of generated code
