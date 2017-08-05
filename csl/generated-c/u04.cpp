
// $destdir/u04.c        Machine generated C code

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
#ifndef NDEBUG
#define NDEBUG 1
#endif
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
typedef intptr_t LispObject;
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
static inline void CSL_IGNORE(LispObject x)
{ (void)x;
}
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
static inline bool is_cons(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_CONS);
}
static inline bool is_fixnum(LispObject p)
{ return ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM);
}
static inline bool is_odds(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED); 
}
static inline bool is_sfloat(LispObject p)
{ return ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT);
}
static inline bool is_symbol(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_SYMBOL);
}
static inline bool is_numbers(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_NUMBERS);
}
static inline bool is_vector(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_VECTOR);
}
static inline bool is_bfloat(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT);
}
static inline bool consp(LispObject p)
{ return is_cons(p);
}
static inline bool symbolp(LispObject p)
{ return is_symbol(p);
}
static inline bool car_legal(LispObject p)
{ return is_cons(p);
}
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
static inline LispObject& qcar(LispObject p)
{ return ((Cons_Cell *)p)->car;
}
static inline LispObject& qcdr(LispObject p)
{ return ((Cons_Cell *)p)->cdr;
}
static inline LispObject& qcar(char * p)
{ return ((Cons_Cell *)p)->car;
}
static inline LispObject& qcdr(char * p)
{ return ((Cons_Cell *)p)->cdr;
}
static inline int32_t& car32(LispObject p)
{ return ((int32_t *)p)[0];
}
static inline int32_t& cdr32(LispObject p)
{ return ((int32_t *)p)[1];
}
static inline int32_t& car32(char * p)
{ return ((int32_t *)p)[0];
}
static inline int32_t& cdr32(char * p)
{ return ((int32_t *)p)[1];
}
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
static Header& vechdr(LispObject v)
{ return *(Header *)((char *)(v) - TAG_VECTOR);
}
static inline unsigned int type_of_header(Header h)
{ return ((unsigned int)h) & header_mask;
}
static inline size_t length_of_header(Header h)
{ return (((size_t)h) >> (Tw+7)) << 2;
}
static inline size_t length_of_bitheader(Header h)
{ return (((size_t)h) >> (Tw+2)) - 31;
}
static inline size_t length_of_byteheader(Header h)
{ return (((size_t)h) >> (Tw+5)) - 3;
}
static inline size_t length_of_hwordheader(Header h)
{ return (((size_t)h) >> (Tw+6)) - 1;
}
static inline Header bitvechdr_(size_t n)
{ return TYPE_BITVEC_1 + (((n+31)&31)<<(Tw+2));
}
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
static inline bool is_symbol_header(Header h)
{ return ((int)h & (0xf<<Tw)) == TYPE_SYMBOL;
}
static inline bool is_symbol_header_full_test(Header h)
{ return ((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED);
}
static inline int header_fastget(Header h)
{ return (h >> SYM_FASTGET_SHIFT) & 0x3f;
}
static inline bool is_number_header_full_test(Header h)
{ return ((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED);
}
static inline bool is_vector_header_full_test(Header h)
{ return is_odds(h) && (((int)h & (0x3<<Tw)) != 0);
}
static inline bool is_array_header(Header h)
{ return type_of_header(h) == TYPE_ARRAY;
}
static inline bool vector_i8(Header h)
{ return ((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_i16(Header h)
{ return ((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_i32(Header h)
{ return ((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_i64(Header h)
{ return ((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_i128(Header h)
{ return ((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_f32(Header h)
{ return ((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_f64(Header h)
{ return ((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_f128(Header h)
{ return ((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x1d <<Tw)
#define TYPE_COMPLEX_NUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
static inline Header& numhdr(LispObject v)
{ return *(Header *)((char *)(v) - TAG_NUMBERS);
}
static inline Header& flthdr(LispObject v)
{ return *(Header *)((char *)(v) - TAG_BOXFLOAT);
}
static inline bool is_ratio(LispObject n)
{ return type_of_header(numhdr(n)) == TYPE_RATNUM;
}
static inline bool is_complex(LispObject n)
{ return type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM;
}
static inline bool is_bignum_header(Header h)
{ return type_of_header(h) == TYPE_BIGNUM;
}
static inline bool is_bignum(LispObject n)
{ return is_bignum_header(numhdr(n));
}
static inline bool is_string_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1;
}
static inline bool is_string(LispObject n)
{ return is_string_header(vechdr(n));
}
static inline bool is_vec8_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1;
}
static inline bool is_vec8(LispObject n)
{ return is_vec8_header(vechdr(n));
}
static inline bool is_bps_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1;
}
static inline bool is_bps(LispObject n)
{ return is_bps_header(vechdr(n));
}
static inline bool is_vec16_header(Header h)
{ return (type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1;
}
static inline bool is_vec16(LispObject n)
{ return is_vec16_header(vechdr(n));
}
static inline bool is_bitvec_header(Header h)
{ return (type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1;
}
static inline bool is_bitvec(LispObject n)
{ return is_bitvec_header(vechdr(n));
}
static inline LispObject& elt(LispObject v, size_t n)
{ return *(LispObject *)((char *)v +
 (CELL-TAG_VECTOR) +
 (n*sizeof(LispObject)));
}
static inline char& celt(LispObject v, size_t n)
{ return *((char *)(v) + (CELL-TAG_VECTOR) + n);
}
static inline unsigned char& ucelt(LispObject v, size_t n)
{ return *((unsigned char *)v + (CELL-TAG_VECTOR) + n);
}
static inline signed char& scelt(LispObject v, size_t n)
{ return *((signed char *)v + (CELL-TAG_VECTOR) + n);
}
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
static inline unsigned char* data_of_bps(LispObject v)
{ return (unsigned char *)v + BPS_DATA_OFFSET;
}
static inline LispObject& vselt(LispObject v, size_t n)
{ return *(LispObject *)(((intptr_t)v & ~((intptr_t)TAG_BITS)) +
 ((1 + n)*sizeof(LispObject)));
}
static inline int16_t& helt(LispObject v, size_t n)
{ return *(int16_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(int16_t));
}
static inline intptr_t& ielt(LispObject v, size_t n)
{ return *(intptr_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(intptr_t));
}
static inline int32_t& ielt32(LispObject v, size_t n)
{ return *(int32_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(int32_t));
}
static inline float& felt(LispObject v, size_t n)
{ return *(float *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(float));
}
static inline double& delt(LispObject v, size_t n)
{ return *(double *)((char *)v +
 (8-TAG_VECTOR) +
 n*sizeof(double));
}
static inline bool is_header(LispObject x)
{ return ((int)x & (0x3<<Tw)) != 0; 
}
static inline bool is_char(LispObject x)
{ return ((int)x & HDR_IMMED_MASK) == TAG_CHAR;
}
static inline bool is_spid(LispObject x)
{ return ((int)x & HDR_IMMED_MASK) == TAG_SPID;
}
static inline bool is_library(LispObject x)
{ return ((int)x & 0xfffff) == SPID_LIBRARY;
}
static inline unsigned int library_number(LispObject x)
{ return (x >> 20) & 0xfff;
}
static inline int font_of_char(LispObject n)
{ return ((int32_t)n >> (21+4+Tw)) & 0xf;
}
static inline int bits_of_char(LispObject n)
{ return 0;
}
static inline unsigned int code_of_char(LispObject n)
{ return ((uint32_t)(n) >> (4+Tw)) & 0x001fffff;
}
static inline LispObject pack_char(int font, unsigned int code)
{ return (LispObject)((((uint32_t)(font)) << (21+4+Tw)) |
 (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR);
}
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
static inline Header& qheader(LispObject p)
{ return *(Header *)((char *)p + (0*CELL-TAG_SYMBOL));
}
static inline LispObject& qvalue(LispObject p)
{ return *(LispObject *)((char *)p + (1*CELL-TAG_SYMBOL));
}
static inline LispObject& qenv(LispObject p)
{ return *(LispObject *)((char *)p + (2*CELL-TAG_SYMBOL));
}
static inline LispObject& qplist(LispObject p)
{ return *(LispObject *)((char *)p + (3*CELL-TAG_SYMBOL));
}
static inline LispObject& qfastgets(LispObject p)
{ return *(LispObject *)((char *)p + (4*CELL-TAG_SYMBOL));
}
static inline LispObject& qpackage(LispObject p)
{ return *(LispObject *)((char *)p + (5*CELL-TAG_SYMBOL));
}
static inline LispObject& qpname(LispObject p)
{ return *(LispObject *)((char *)p + (6*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn0(LispObject p)
{ return *(intptr_t *)((char *)p + (7*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn1(LispObject p)
{ return *(intptr_t *)((char *)p + (8*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn2(LispObject p)
{ return *(intptr_t *)((char *)p + (9*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn3(LispObject p)
{ return *(intptr_t *)((char *)p + (10*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifnn(LispObject p)
{ return *(intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn4(LispObject p)
{ return *(intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline no_args*& qfn0(LispObject p)
{ return *(no_args **)((char *)p + (7*CELL-TAG_SYMBOL));
}
static inline one_args*& qfn1(LispObject p)
{ return *(one_args **)((char *)p + (8*CELL-TAG_SYMBOL));
}
static inline two_args*& qfn2(LispObject p)
{ return *(two_args **)((char *)p + (9*CELL-TAG_SYMBOL));
}
static inline three_args*& qfn3(LispObject p)
{ return *(three_args **)((char *)p + (10*CELL-TAG_SYMBOL));
}
static inline n_args*& qfnn(LispObject p)
{ return *(n_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline four_args*& qfn4(LispObject p)
{ return *(four_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline uint64_t& qcount(LispObject p)
{ return *(uint64_t *)((char *)p + (12*CELL-TAG_SYMBOL));
}
typedef union _Float_union
{ float f;
 uint32_t i;
 float32_t f32;
} Float_union;
static inline LispObject low32(LispObject a)
{ return (LispObject)(uint32_t)a;
}
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
static inline size_t bignum_length(LispObject b)
{ return length_of_header(numhdr(b));
}
static inline uint32_t* bignum_digits(LispObject b)
{ return (uint32_t *)((char *)b + (CELL-TAG_NUMBERS));
}
static inline int64_t bignum_digits64(LispObject b, size_t n)
{ return (int64_t)((int32_t *)((char *)b+(CELL-TAG_NUMBERS)))[n];
}
static inline Header make_bighdr(size_t n)
{ return TAG_HDR_IMMED+TYPE_BIGNUM+(n<<(Tw+7));
}
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
#define make_padder(n) (pack_hdrlength((n)/4) + TYPE_VEC8_1 + TAG_HDR_IMMED)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
static inline LispObject& numerator(LispObject r)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->num;
}
static inline LispObject& denominator(LispObject r)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->den;
}
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
static inline LispObject& real_part(LispObject r)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->real;
}
static inline LispObject& imag_part(LispObject r)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->imag;
}
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 float32_t f32;
 int32_t i;
 } f;
} Single_Float;
static inline float& single_float_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f;
}
static inline float32_t& float32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f32;
}
static inline int32_t& intfloat32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.i;
}
typedef union _Double_union
{ double f;
 uint32_t i[2];
 uint64_t i64;
 float64_t f64;
} Double_union;
#define SIZEOF_DOUBLE_FLOAT 16
static inline double *double_float_addr(LispObject v)
{ return (double *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int32_t& double_float_pad(LispObject v)
{ return *(int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
static inline double& double_float_val(LispObject v)
{ return *(double *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline float64_t& float64_t_val(LispObject v)
{ return *(float64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int64_t& intfloat64_t_val(LispObject v)
{ return *(int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
#define SIZEOF_LONG_FLOAT 24
static inline float128_t *long_float_addr(LispObject v)
{ return (float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int32_t& long_float_pad(LispObject v)
{ return *(int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
static inline float128_t& long_float_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline float128_t& float128_t_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int64_t& intfloat128_t_val0(LispObject v)
{ return *(int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int64_t& intfloat128_t_val1(LispObject v)
{ return *(int64_t *)((char *)v + (16-TAG_BOXFLOAT));
}
static inline uintptr_t word_align_up(uintptr_t n)
{ return (LispObject)((n + 3) & (-(uintptr_t)4U));
}
static inline uintptr_t doubleword_align_up(uintptr_t n)
{ return (uintptr_t)((n + 7) & (-(uintptr_t)8U));
}
static inline LispObject doubleword_align_up(LispObject n)
{ return (LispObject)(((uintptr_t)n + 7) & (-(uintptr_t)8U));
}
static inline uintptr_t doubleword_align_down(uintptr_t n)
{ return (uintptr_t)((intptr_t)n & (-(uintptr_t)8U));
}
static inline uintptr_t object_align_up(uintptr_t n)
{ return (uintptr_t)((n + sizeof(LispObject) - 1) &
 (-(uintptr_t)sizeof(LispObject)));
}
static inline uintptr_t quadword_align_up(uintptr_t n)
{ return (uintptr_t)((n + 15) & (-(uintptr_t)16U));
}
static inline uintptr_t quadword_align_down(uintptr_t n)
{ return (uintptr_t)(n & (-(uintptr_t)16U));
}
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
static inline void push(LispObject a)
{ *++stack = a;
 assert(a != 0);
}
static inline void push2(LispObject a, LispObject b)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
}
static inline void push3(LispObject a, LispObject b, LispObject c)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
 *++stack = c;
 assert(c != 0);
}
static inline void push4(LispObject a, LispObject b, LispObject c,
 LispObject d)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
 *++stack = c;
 assert(c != 0);
 *++stack = d;
 assert(d != 0);
}
static inline void push5(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
 *++stack = c;
 assert(c != 0);
 *++stack = d;
 assert(d != 0);
 *++stack = e;
 assert(e != 0);
}
static inline void push6(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e, LispObject f)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
 *++stack = c;
 assert(c != 0);
 *++stack = d;
 assert(d != 0);
 *++stack = e;
 assert(e != 0);
 *++stack = f;
 assert(f != 0);
}
static inline void pop(LispObject& a)
{ a = *stack--;
 assert(a != 0);
}
static inline void pop(volatile LispObject& a)
{ a = *stack--;
 assert(a != 0);
}
static inline void pop2(LispObject& a, LispObject& b)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
}
static inline void pop3(LispObject& a, LispObject& b, LispObject& c)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
 c = *stack--;
 assert(c != 0);
}
static inline void pop4(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
 c = *stack--;
 assert(c != 0);
 d = *stack--;
 assert(d != 0);
}
static inline void pop5(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
 c = *stack--;
 assert(c != 0);
 d = *stack--;
 assert(d != 0);
 e = *stack--;
 assert(e != 0);
}
static inline void pop6(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e, LispObject& f)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
 c = *stack--;
 assert(c != 0);
 d = *stack--;
 assert(d != 0);
 e = *stack--;
 assert(e != 0);
 f = *stack--;
 assert(f != 0);
}
static inline void popv(int n)
{ stack -= n;
}
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
#define LOG2_VECTOR_CHUNK_BYTES 20
#define VECTOR_CHUNK_BYTES ((size_t)(1<<LOG2_VECTOR_CHUNK_BYTES))
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1];
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
extern LispObject get_basic_vector(int tag, int type, size_t length);
extern LispObject get_basic_vector_init(size_t n, LispObject v);
extern LispObject get_vector(int tag, int type, size_t length);
extern LispObject get_vector_init(size_t n, LispObject v);
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
 { LispObject r = get_basic_vector(TAG_BOXFLOAT,
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



// Code for lex

static LispObject CC_lex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1225, v_1226;
    LispObject fn;
    argcheck(nargs, 0, "lex");
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
// Binding safe_atts
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // safe_atts
    v_1225 = nil;
    qvalue(elt(env, 2)) = v_1225; // char
    v_1225 = qvalue(elt(env, 3)); // atts
    if (v_1225 == nil) goto v_1124;
    v_1225 = qvalue(elt(env, 3)); // atts
    qvalue(elt(env, 1)) = v_1225; // safe_atts
    goto v_1122;
v_1124:
v_1122:
    v_1225 = nil;
    qvalue(elt(env, 3)) = v_1225; // atts
    goto v_1136;
v_1132:
    stack[0] = qvalue(elt(env, 4)); // ch
    goto v_1133;
v_1134:
    v_1225 = (LispObject)160+TAG_FIXNUM; // 10
    v_1225 = ncons(v_1225);
    env = stack[-2];
    fn = elt(env, 9); // list2string
    v_1225 = (*qfn1(fn))(fn, v_1225);
    env = stack[-2];
    v_1225 = Lintern(nil, v_1225);
    env = stack[-2];
    goto v_1135;
v_1136:
    goto v_1132;
v_1133:
    goto v_1134;
v_1135:
    if (stack[0] == v_1225) goto v_1130;
    else goto v_1131;
v_1130:
    v_1225 = Lreadch(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_1225; // ch
    goto v_1129;
v_1131:
v_1129:
    goto v_1151;
v_1147:
    v_1226 = qvalue(elt(env, 4)); // ch
    goto v_1148;
v_1149:
    v_1225 = qvalue(elt(env, 5)); // !$eof!$
    goto v_1150;
v_1151:
    goto v_1147;
v_1148:
    goto v_1149;
v_1150:
    if (equal(v_1226, v_1225)) goto v_1146;
    goto v_1162;
v_1158:
    v_1226 = qvalue(elt(env, 4)); // ch
    goto v_1159;
v_1160:
    v_1225 = qvalue(elt(env, 6)); // space
    goto v_1161;
v_1162:
    goto v_1158;
v_1159:
    goto v_1160;
v_1161:
    if (equal(v_1226, v_1225)) goto v_1156;
    else goto v_1157;
v_1156:
v_1167:
    goto v_1177;
v_1173:
    v_1226 = Lreadch(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_1226; // ch
    goto v_1174;
v_1175:
    v_1225 = qvalue(elt(env, 6)); // space
    goto v_1176;
v_1177:
    goto v_1173;
v_1174:
    goto v_1175;
v_1176:
    if (equal(v_1226, v_1225)) goto v_1172;
    goto v_1166;
v_1172:
    goto v_1167;
v_1166:
    goto v_1155;
v_1157:
    goto v_1187;
v_1183:
    v_1226 = qvalue(elt(env, 4)); // ch
    goto v_1184;
v_1185:
    v_1225 = elt(env, 7); // !<
    goto v_1186;
v_1187:
    goto v_1183;
v_1184:
    goto v_1185;
v_1186:
    if (v_1226 == v_1225) goto v_1181;
    else goto v_1182;
v_1181:
    fn = elt(env, 10); // get_token
    v_1225 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_1225; // char
    goto v_1155;
v_1182:
    fn = elt(env, 11); // get_content
    v_1225 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_1225; // char
    goto v_1155;
v_1155:
    v_1225 = qvalue(elt(env, 2)); // char
    if (v_1225 == nil) goto v_1197;
    v_1225 = qvalue(elt(env, 8)); // count
    v_1225 = add1(v_1225);
    env = stack[-2];
    qvalue(elt(env, 8)) = v_1225; // count
    v_1225 = qvalue(elt(env, 2)); // char
    v_1225 = Lreverse(nil, v_1225);
    env = stack[-2];
    stack[0] = v_1225;
    v_1225 = qvalue(elt(env, 2)); // char
    fn = elt(env, 12); // notstring
    v_1225 = (*qfn1(fn))(fn, v_1225);
    env = stack[-2];
    if (v_1225 == nil) goto v_1206;
    v_1225 = stack[0];
    fn = elt(env, 13); // butes
    v_1225 = (*qfn1(fn))(fn, v_1225);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_1225; // char
    v_1225 = qvalue(elt(env, 2)); // char
    fn = elt(env, 14); // isvalid
    v_1225 = (*qfn1(fn))(fn, v_1225);
    env = stack[-2];
    goto v_1218;
v_1214:
    v_1226 = qvalue(elt(env, 2)); // char
    goto v_1215;
v_1216:
    v_1225 = stack[0];
    goto v_1217;
v_1218:
    goto v_1214;
v_1215:
    goto v_1216;
v_1217:
    fn = elt(env, 15); // attributes
    v_1225 = (*qfn2(fn))(fn, v_1226, v_1225);
    goto v_1204;
v_1206:
v_1204:
    goto v_1195;
v_1197:
    v_1225 = CC_lex(elt(env, 0), 0);
    goto v_1195;
v_1195:
    goto v_1144;
v_1146:
v_1144:
    v_1225 = nil;
    ;}  // end of a binding scope
    return onevalue(v_1225);
}



// Code for replus1

static LispObject CC_replus1(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1166, v_1167, v_1168;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1168 = v_1114;
// end of prologue
    v_1166 = v_1168;
    if (v_1166 == nil) goto v_1118;
    else goto v_1119;
v_1118:
    v_1166 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1117;
v_1119:
    v_1166 = v_1168;
    if (!consp(v_1166)) goto v_1126;
    else goto v_1127;
v_1126:
    v_1166 = lisp_true;
    goto v_1125;
v_1127:
    goto v_1141;
v_1137:
    v_1167 = v_1168;
    goto v_1138;
v_1139:
    v_1166 = elt(env, 1); // plus
    goto v_1140;
v_1141:
    goto v_1137;
v_1138:
    goto v_1139;
v_1140:
    if (!consp(v_1167)) goto v_1135;
    v_1167 = qcar(v_1167);
    if (v_1167 == v_1166) goto v_1134;
    else goto v_1135;
v_1134:
    v_1166 = v_1168;
    v_1166 = qcdr(v_1166);
    goto v_1133;
v_1135:
    v_1166 = nil;
    goto v_1133;
    v_1166 = nil;
v_1133:
    goto v_1125;
    v_1166 = nil;
v_1125:
    if (v_1166 == nil) goto v_1123;
    v_1166 = v_1168;
    goto v_1117;
v_1123:
    v_1166 = v_1168;
    v_1166 = qcdr(v_1166);
    if (v_1166 == nil) goto v_1150;
    else goto v_1151;
v_1150:
    v_1166 = v_1168;
    v_1166 = qcar(v_1166);
    goto v_1117;
v_1151:
    goto v_1163;
v_1159:
    v_1166 = elt(env, 1); // plus
    goto v_1160;
v_1161:
    v_1167 = v_1168;
    goto v_1162;
v_1163:
    goto v_1159;
v_1160:
    goto v_1161;
v_1162:
    return cons(v_1166, v_1167);
    v_1166 = nil;
v_1117:
    return onevalue(v_1166);
}



// Code for !*q2a1

static LispObject CC_Hq2a1(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1128, v_1129;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1128 = v_1115;
    v_1129 = v_1114;
// end of prologue
    if (v_1128 == nil) goto v_1119;
    else goto v_1120;
v_1119:
    v_1128 = v_1129;
    {
        fn = elt(env, 1); // mk!*sq
        return (*qfn1(fn))(fn, v_1128);
    }
v_1120:
    v_1128 = v_1129;
    {
        fn = elt(env, 2); // prepsqxx
        return (*qfn1(fn))(fn, v_1128);
    }
    v_1128 = nil;
    return onevalue(v_1128);
}



// Code for peel

static LispObject CC_peel(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1174, v_1175;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
    goto v_1124;
v_1120:
    v_1174 = stack[0];
    v_1175 = qcar(v_1174);
    goto v_1121;
v_1122:
    v_1174 = elt(env, 1); // (liedf innerprod)
    goto v_1123;
v_1124:
    goto v_1120;
v_1121:
    goto v_1122;
v_1123:
    v_1174 = Lmemq(nil, v_1175, v_1174);
    if (v_1174 == nil) goto v_1119;
    v_1174 = stack[0];
    v_1174 = qcdr(v_1174);
    v_1174 = qcdr(v_1174);
    v_1174 = qcar(v_1174);
    goto v_1117;
v_1119:
    goto v_1139;
v_1135:
    v_1174 = stack[0];
    v_1175 = qcar(v_1174);
    goto v_1136;
v_1137:
    v_1174 = elt(env, 2); // quotient
    goto v_1138;
v_1139:
    goto v_1135;
v_1136:
    goto v_1137;
v_1138:
    if (v_1175 == v_1174) goto v_1133;
    else goto v_1134;
v_1133:
    goto v_1152;
v_1148:
    v_1174 = stack[0];
    v_1174 = qcdr(v_1174);
    v_1175 = qcar(v_1174);
    goto v_1149;
v_1150:
    v_1174 = stack[0];
    v_1174 = qcdr(v_1174);
    v_1174 = qcdr(v_1174);
    v_1174 = qcar(v_1174);
    goto v_1151;
v_1152:
    goto v_1148;
v_1149:
    goto v_1150;
v_1151:
    fn = elt(env, 3); // worderp
    v_1174 = (*qfn2(fn))(fn, v_1175, v_1174);
    if (v_1174 == nil) goto v_1146;
    v_1174 = stack[0];
    v_1174 = qcdr(v_1174);
    v_1174 = qcar(v_1174);
    goto v_1144;
v_1146:
    v_1174 = stack[0];
    v_1174 = qcdr(v_1174);
    v_1174 = qcdr(v_1174);
    v_1174 = qcar(v_1174);
    goto v_1144;
    v_1174 = nil;
v_1144:
    goto v_1117;
v_1134:
    v_1174 = stack[0];
    v_1174 = qcdr(v_1174);
    v_1174 = qcar(v_1174);
    goto v_1117;
    v_1174 = nil;
v_1117:
    return onevalue(v_1174);
}



// Code for mo_ecart

static LispObject CC_mo_ecart(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1162, v_1163;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
    v_1162 = stack[0];
    v_1162 = qcar(v_1162);
    if (v_1162 == nil) goto v_1118;
    else goto v_1119;
v_1118:
    v_1162 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1117;
v_1119:
    goto v_1129;
v_1125:
    v_1162 = stack[0];
    fn = elt(env, 3); // mo_comp
    v_1163 = (*qfn1(fn))(fn, v_1162);
    env = stack[-1];
    goto v_1126;
v_1127:
    v_1162 = qvalue(elt(env, 1)); // cali!=degrees
    goto v_1128;
v_1129:
    goto v_1125;
v_1126:
    goto v_1127;
v_1128:
    v_1162 = Latsoc(nil, v_1163, v_1162);
    v_1163 = v_1162;
    goto v_1140;
v_1136:
    v_1162 = v_1163;
    if (v_1162 == nil) goto v_1144;
    goto v_1151;
v_1147:
    v_1162 = v_1163;
    v_1163 = qcdr(v_1162);
    goto v_1148;
v_1149:
    v_1162 = stack[0];
    goto v_1150;
v_1151:
    goto v_1147;
v_1148:
    goto v_1149;
v_1150:
    fn = elt(env, 4); // mo_sum
    v_1162 = (*qfn2(fn))(fn, v_1163, v_1162);
    env = stack[-1];
    goto v_1142;
v_1144:
    v_1162 = stack[0];
    goto v_1142;
    v_1162 = nil;
v_1142:
    v_1162 = qcar(v_1162);
    stack[0] = qcdr(v_1162);
    goto v_1137;
v_1138:
    v_1162 = qvalue(elt(env, 2)); // cali!=basering
    fn = elt(env, 5); // ring_ecart
    v_1162 = (*qfn1(fn))(fn, v_1162);
    env = stack[-1];
    goto v_1139;
v_1140:
    goto v_1136;
v_1137:
    goto v_1138;
v_1139:
    {
        LispObject v_1165 = stack[0];
        fn = elt(env, 6); // mo!=sprod
        return (*qfn2(fn))(fn, v_1165, v_1162);
    }
    v_1162 = nil;
v_1117:
    return onevalue(v_1162);
}



// Code for pv_sort

static LispObject CC_pv_sort(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1135, v_1136;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1136 = v_1114;
// end of prologue
    v_1135 = v_1136;
    if (v_1135 == nil) goto v_1118;
    else goto v_1119;
v_1118:
    v_1135 = nil;
    goto v_1117;
v_1119:
    goto v_1129;
v_1125:
    v_1135 = v_1136;
    stack[0] = qcdr(v_1135);
    goto v_1126;
v_1127:
    v_1135 = v_1136;
    v_1135 = qcar(v_1135);
    v_1135 = ncons(v_1135);
    env = stack[-1];
    goto v_1128;
v_1129:
    goto v_1125;
v_1126:
    goto v_1127;
v_1128:
    {
        LispObject v_1138 = stack[0];
        fn = elt(env, 1); // pv_sort1
        return (*qfn2(fn))(fn, v_1138, v_1135);
    }
    v_1135 = nil;
v_1117:
    return onevalue(v_1135);
}



// Code for flatten!-sorted!-tree

static LispObject CC_flattenKsortedKtree(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1151, v_1152, v_1153;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_1151 = v_1115;
    v_1152 = v_1114;
// end of prologue
v_1120:
    v_1153 = v_1152;
    if (v_1153 == nil) goto v_1123;
    else goto v_1124;
v_1123:
    goto v_1119;
v_1124:
    v_1153 = v_1152;
    v_1153 = qcar(v_1153);
    stack[-1] = v_1153;
    goto v_1136;
v_1132:
    v_1153 = v_1152;
    v_1153 = qcdr(v_1153);
    stack[0] = qcar(v_1153);
    goto v_1133;
v_1134:
    goto v_1145;
v_1141:
    v_1152 = qcdr(v_1152);
    v_1152 = qcdr(v_1152);
    goto v_1142;
v_1143:
    goto v_1144;
v_1145:
    goto v_1141;
v_1142:
    goto v_1143;
v_1144:
    v_1151 = CC_flattenKsortedKtree(elt(env, 0), v_1152, v_1151);
    env = stack[-2];
    goto v_1135;
v_1136:
    goto v_1132;
v_1133:
    goto v_1134;
v_1135:
    v_1151 = cons(stack[0], v_1151);
    env = stack[-2];
    v_1152 = stack[-1];
    goto v_1120;
    v_1151 = nil;
v_1119:
    return onevalue(v_1151);
}



// Code for ofsf_posdefp

static LispObject CC_ofsf_posdefp(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1127, v_1128;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1128 = v_1114;
// end of prologue
    v_1127 = qvalue(elt(env, 1)); // !*rlpos
    if (v_1127 == nil) goto v_1119;
    v_1127 = v_1128;
    {
        fn = elt(env, 2); // ofsf_posdefp!-pos
        return (*qfn1(fn))(fn, v_1127);
    }
v_1119:
    v_1127 = v_1128;
    {
        fn = elt(env, 3); // sfto_tsqsumf
        return (*qfn1(fn))(fn, v_1127);
    }
    v_1127 = nil;
    return onevalue(v_1127);
}



// Code for reordop

static LispObject CC_reordop(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1169, v_1170;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
    goto v_1126;
v_1122:
    v_1170 = stack[-1];
    goto v_1123;
v_1124:
    v_1169 = stack[0];
    goto v_1125;
v_1126:
    goto v_1122;
v_1123:
    goto v_1124;
v_1125:
    fn = elt(env, 2); // reordablep
    v_1169 = (*qfn2(fn))(fn, v_1170, v_1169);
    env = stack[-2];
    if (v_1169 == nil) goto v_1120;
    goto v_1134;
v_1130:
    v_1170 = stack[-1];
    goto v_1131;
v_1132:
    v_1169 = stack[0];
    goto v_1133;
v_1134:
    goto v_1130;
v_1131:
    goto v_1132;
v_1133:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_1170, v_1169);
    }
v_1120:
    v_1169 = qvalue(elt(env, 1)); // !*ncmp
    if (v_1169 == nil) goto v_1144;
    else goto v_1145;
v_1144:
    v_1169 = nil;
    goto v_1143;
v_1145:
    v_1169 = stack[-1];
    fn = elt(env, 4); // noncomp1
    v_1169 = (*qfn1(fn))(fn, v_1169);
    env = stack[-2];
    if (v_1169 == nil) goto v_1152;
    else goto v_1153;
v_1152:
    v_1169 = nil;
    goto v_1151;
v_1153:
    v_1169 = stack[0];
    fn = elt(env, 4); // noncomp1
    v_1169 = (*qfn1(fn))(fn, v_1169);
    env = stack[-2];
    goto v_1151;
    v_1169 = nil;
v_1151:
    goto v_1143;
    v_1169 = nil;
v_1143:
    if (v_1169 == nil) goto v_1141;
    else goto v_1140;
v_1141:
    goto v_1166;
v_1162:
    v_1170 = stack[-1];
    goto v_1163;
v_1164:
    v_1169 = stack[0];
    goto v_1165;
v_1166:
    goto v_1162;
v_1163:
    goto v_1164;
v_1165:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_1170, v_1169);
    }
v_1140:
    goto v_1118;
    v_1169 = nil;
v_1118:
    return onevalue(v_1169);
}



// Code for free!-powerp

static LispObject CC_freeKpowerp(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1156;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
v_1113:
    v_1156 = stack[0];
    if (!consp(v_1156)) goto v_1122;
    else goto v_1123;
v_1122:
    v_1156 = lisp_true;
    goto v_1121;
v_1123:
    v_1156 = stack[0];
    v_1156 = qcar(v_1156);
    v_1156 = (consp(v_1156) ? nil : lisp_true);
    goto v_1121;
    v_1156 = nil;
v_1121:
    if (v_1156 == nil) goto v_1118;
    else goto v_1119;
v_1118:
    v_1156 = stack[0];
    v_1156 = qcar(v_1156);
    v_1156 = qcar(v_1156);
    v_1156 = qcdr(v_1156);
    v_1156 = integerp(v_1156);
    if (v_1156 == nil) goto v_1133;
    else goto v_1134;
v_1133:
    v_1156 = lisp_true;
    goto v_1132;
v_1134:
    v_1156 = stack[0];
    v_1156 = qcar(v_1156);
    v_1156 = qcdr(v_1156);
    v_1156 = CC_freeKpowerp(elt(env, 0), v_1156);
    env = stack[-1];
    if (v_1156 == nil) goto v_1145;
    else goto v_1144;
v_1145:
    v_1156 = stack[0];
    v_1156 = qcdr(v_1156);
    stack[0] = v_1156;
    goto v_1113;
v_1144:
    goto v_1132;
    v_1156 = nil;
v_1132:
    goto v_1117;
v_1119:
    v_1156 = nil;
    goto v_1117;
    v_1156 = nil;
v_1117:
    return onevalue(v_1156);
}



// Code for retimes

static LispObject CC_retimes(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1159, v_1160;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1159 = v_1114;
// end of prologue
// Binding !*bool
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*bool
    fn = elt(env, 4); // retimes1
    v_1159 = (*qfn1(fn))(fn, v_1159);
    env = stack[-1];
    v_1160 = v_1159;
    if (v_1160 == nil) goto v_1123;
    else goto v_1124;
v_1123:
    v_1159 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1122;
v_1124:
    v_1160 = v_1159;
    v_1160 = qcdr(v_1160);
    if (v_1160 == nil) goto v_1128;
    goto v_1136;
v_1132:
    v_1160 = elt(env, 2); // times
    goto v_1133;
v_1134:
    goto v_1135;
v_1136:
    goto v_1132;
v_1133:
    goto v_1134;
v_1135:
    v_1159 = cons(v_1160, v_1159);
    env = stack[-1];
    goto v_1122;
v_1128:
    v_1159 = qcar(v_1159);
    goto v_1122;
    v_1159 = nil;
v_1122:
    v_1160 = qvalue(elt(env, 1)); // !*bool
    if (v_1160 == nil) goto v_1146;
    goto v_1153;
v_1149:
    v_1160 = elt(env, 3); // minus
    goto v_1150;
v_1151:
    goto v_1152;
v_1153:
    goto v_1149;
v_1150:
    goto v_1151;
v_1152:
    v_1159 = list2(v_1160, v_1159);
    goto v_1144;
v_1146:
    goto v_1144;
    v_1159 = nil;
v_1144:
    ;}  // end of a binding scope
    return onevalue(v_1159);
}



// Code for mkwedge

static LispObject CC_mkwedge(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1128, v_1129, v_1130;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
// copy arguments values to proper place
    v_1128 = v_1114;
// end of prologue
    goto v_1124;
v_1118:
    v_1130 = v_1128;
    goto v_1119;
v_1120:
    v_1129 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1121;
v_1122:
    v_1128 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1123;
v_1124:
    goto v_1118;
v_1119:
    goto v_1120;
v_1121:
    goto v_1122;
v_1123:
    v_1128 = list2star(v_1130, v_1129, v_1128);
    return ncons(v_1128);
}



// Code for idlistp

static LispObject CC_idlistp(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1144, v_1145;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1144 = v_1114;
// end of prologue
v_1113:
    v_1145 = v_1144;
    if (v_1145 == nil) goto v_1118;
    else goto v_1119;
v_1118:
    v_1144 = lisp_true;
    goto v_1117;
v_1119:
    v_1145 = v_1144;
    if (!consp(v_1145)) goto v_1127;
    v_1145 = v_1144;
    v_1145 = qcar(v_1145);
    if (symbolp(v_1145)) goto v_1132;
    v_1144 = nil;
    goto v_1130;
v_1132:
    v_1144 = qcdr(v_1144);
    goto v_1113;
    v_1144 = nil;
v_1130:
    goto v_1125;
v_1127:
    v_1144 = nil;
    goto v_1125;
    v_1144 = nil;
v_1125:
    goto v_1117;
    v_1144 = nil;
v_1117:
    return onevalue(v_1144);
}



// Code for qassoc

static LispObject CC_qassoc(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1143, v_1144, v_1145, v_1146;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1144 = v_1115;
    v_1145 = v_1114;
// end of prologue
v_1119:
    v_1143 = v_1144;
    if (v_1143 == nil) goto v_1122;
    else goto v_1123;
v_1122:
    v_1143 = nil;
    goto v_1118;
v_1123:
    goto v_1132;
v_1128:
    v_1146 = v_1145;
    goto v_1129;
v_1130:
    v_1143 = v_1144;
    v_1143 = qcar(v_1143);
    v_1143 = qcar(v_1143);
    goto v_1131;
v_1132:
    goto v_1128;
v_1129:
    goto v_1130;
v_1131:
    if (v_1146 == v_1143) goto v_1126;
    else goto v_1127;
v_1126:
    v_1143 = v_1144;
    v_1143 = qcar(v_1143);
    goto v_1118;
v_1127:
    v_1143 = v_1144;
    v_1143 = qcdr(v_1143);
    v_1144 = v_1143;
    goto v_1119;
    v_1143 = nil;
v_1118:
    return onevalue(v_1143);
}



// Code for negf

static LispObject CC_negf(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1194, v_1195;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_1114;
// end of prologue
    stack[-2] = nil;
v_1119:
    v_1194 = stack[-1];
    if (v_1194 == nil) goto v_1122;
    else goto v_1123;
v_1122:
    v_1194 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_1194);
    }
v_1123:
    v_1194 = stack[-1];
    if (!consp(v_1194)) goto v_1131;
    else goto v_1132;
v_1131:
    v_1194 = lisp_true;
    goto v_1130;
v_1132:
    v_1194 = stack[-1];
    v_1194 = qcar(v_1194);
    v_1194 = (consp(v_1194) ? nil : lisp_true);
    goto v_1130;
    v_1194 = nil;
v_1130:
    if (v_1194 == nil) goto v_1128;
    goto v_1145;
v_1141:
    stack[0] = stack[-2];
    goto v_1142;
v_1143:
    v_1194 = stack[-1];
    if (!consp(v_1194)) goto v_1154;
    else goto v_1155;
v_1154:
    v_1194 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_1194)) v_1194 = nil;
    else { v_1194 = qfastgets(v_1194);
           if (v_1194 != nil) { v_1194 = elt(v_1194, 5); // convert
#ifdef RECORD_GET
             if (v_1194 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_1194 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_1194 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_1194 == SPID_NOPROP) v_1194 = nil; else v_1194 = lisp_true; }}
#endif
    goto v_1153;
v_1155:
    v_1194 = nil;
    goto v_1153;
    v_1194 = nil;
v_1153:
    if (v_1194 == nil) goto v_1151;
    goto v_1167;
v_1163:
    v_1194 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_1194)) v_1195 = nil;
    else { v_1195 = qfastgets(v_1194);
           if (v_1195 != nil) { v_1195 = elt(v_1195, 34); // i2d
#ifdef RECORD_GET
             if (v_1195 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_1195 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_1195 == SPID_NOPROP) v_1195 = nil; }}
#endif
    goto v_1164;
v_1165:
    v_1194 = stack[-1];
    goto v_1166;
v_1167:
    goto v_1163;
v_1164:
    goto v_1165;
v_1166:
    v_1194 = Lapply1(nil, v_1195, v_1194);
    env = stack[-3];
    goto v_1149;
v_1151:
    v_1194 = stack[-1];
    goto v_1149;
    v_1194 = nil;
v_1149:
    fn = elt(env, 3); // !:minus
    v_1194 = (*qfn1(fn))(fn, v_1194);
    env = stack[-3];
    goto v_1144;
v_1145:
    goto v_1141;
v_1142:
    goto v_1143;
v_1144:
    {
        LispObject v_1199 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_1199, v_1194);
    }
v_1128:
    goto v_1183;
v_1177:
    v_1194 = stack[-1];
    v_1194 = qcar(v_1194);
    stack[0] = qcar(v_1194);
    goto v_1178;
v_1179:
    v_1194 = stack[-1];
    v_1194 = qcar(v_1194);
    v_1194 = qcdr(v_1194);
    v_1195 = CC_negf(elt(env, 0), v_1194);
    env = stack[-3];
    goto v_1180;
v_1181:
    v_1194 = stack[-2];
    goto v_1182;
v_1183:
    goto v_1177;
v_1178:
    goto v_1179;
v_1180:
    goto v_1181;
v_1182:
    v_1194 = acons(stack[0], v_1195, v_1194);
    env = stack[-3];
    stack[-2] = v_1194;
    v_1194 = stack[-1];
    v_1194 = qcdr(v_1194);
    stack[-1] = v_1194;
    goto v_1119;
    v_1194 = nil;
    return onevalue(v_1194);
}



// Code for formlis

static LispObject CC_formlis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1153, v_1154, v_1155;
    LispObject fn;
    LispObject v_1116, v_1115, v_1114;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formlis");
    va_start(aa, nargs);
    v_1114 = va_arg(aa, LispObject);
    v_1115 = va_arg(aa, LispObject);
    v_1116 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_1116,v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_1114,v_1115,v_1116);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_1116;
    stack[-1] = v_1115;
    stack[-2] = v_1114;
// end of prologue
    stack[-3] = nil;
v_1123:
    v_1153 = stack[-2];
    if (v_1153 == nil) goto v_1126;
    else goto v_1127;
v_1126:
    goto v_1122;
v_1127:
    goto v_1135;
v_1131:
    goto v_1143;
v_1137:
    v_1153 = stack[-2];
    v_1155 = qcar(v_1153);
    goto v_1138;
v_1139:
    v_1154 = stack[-1];
    goto v_1140;
v_1141:
    v_1153 = stack[0];
    goto v_1142;
v_1143:
    goto v_1137;
v_1138:
    goto v_1139;
v_1140:
    goto v_1141;
v_1142:
    fn = elt(env, 1); // form1
    v_1154 = (*qfnn(fn))(fn, 3, v_1155, v_1154, v_1153);
    env = stack[-4];
    goto v_1132;
v_1133:
    v_1153 = stack[-3];
    goto v_1134;
v_1135:
    goto v_1131;
v_1132:
    goto v_1133;
v_1134:
    v_1153 = cons(v_1154, v_1153);
    env = stack[-4];
    stack[-3] = v_1153;
    v_1153 = stack[-2];
    v_1153 = qcdr(v_1153);
    stack[-2] = v_1153;
    goto v_1123;
v_1122:
    v_1153 = stack[-3];
    {
        fn = elt(env, 2); // reversip!*
        return (*qfn1(fn))(fn, v_1153);
    }
    return onevalue(v_1153);
}



// Code for nonzero!-length

static LispObject CC_nonzeroKlength(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1143, v_1144, v_1145;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
// copy arguments values to proper place
    v_1144 = v_1114;
// end of prologue
v_1118:
    v_1143 = v_1144;
    if (v_1143 == nil) goto v_1121;
    else goto v_1122;
v_1121:
    v_1143 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1117;
v_1122:
    goto v_1131;
v_1127:
    v_1143 = v_1144;
    v_1145 = qcar(v_1143);
    goto v_1128;
v_1129:
    v_1143 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1130;
v_1131:
    goto v_1127;
v_1128:
    goto v_1129;
v_1130:
    if (v_1145 == v_1143) goto v_1125;
    else goto v_1126;
v_1125:
    v_1143 = v_1144;
    v_1143 = qcdr(v_1143);
    v_1144 = v_1143;
    goto v_1118;
v_1126:
    v_1143 = v_1144;
    v_1143 = qcdr(v_1143);
    v_1143 = CC_nonzeroKlength(elt(env, 0), v_1143);
    return add1(v_1143);
    v_1143 = nil;
v_1117:
    return onevalue(v_1143);
}



// Code for pv_renorm

static LispObject CC_pv_renorm(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1277, v_1278;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
    v_1277 = stack[0];
    if (v_1277 == nil) goto v_1118;
    else goto v_1119;
v_1118:
    v_1277 = nil;
    goto v_1117;
v_1119:
v_1130:
    v_1277 = stack[0];
    if (v_1277 == nil) goto v_1133;
    goto v_1142;
v_1138:
    v_1277 = stack[0];
    v_1277 = qcar(v_1277);
    v_1278 = qcar(v_1277);
    goto v_1139;
v_1140:
    v_1277 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1141;
v_1142:
    goto v_1138;
v_1139:
    goto v_1140;
v_1141:
    if (v_1278 == v_1277) goto v_1137;
    else goto v_1133;
v_1137:
    goto v_1134;
v_1133:
    goto v_1129;
v_1134:
    v_1277 = stack[0];
    v_1277 = qcdr(v_1277);
    stack[0] = v_1277;
    goto v_1130;
v_1129:
    v_1277 = stack[0];
    if (v_1277 == nil) goto v_1152;
    else goto v_1153;
v_1152:
    v_1277 = nil;
    goto v_1127;
v_1153:
    goto v_1165;
v_1161:
    v_1277 = stack[0];
    v_1277 = qcar(v_1277);
    v_1278 = qcar(v_1277);
    goto v_1162;
v_1163:
    v_1277 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1164;
v_1165:
    goto v_1161;
v_1162:
    goto v_1163;
v_1164:
    v_1277 = (LispObject)lessp2(v_1278, v_1277);
    v_1277 = v_1277 ? lisp_true : nil;
    env = stack[-4];
    if (v_1277 == nil) goto v_1159;
    v_1277 = stack[0];
    fn = elt(env, 1); // pv_neg
    v_1277 = (*qfn1(fn))(fn, v_1277);
    env = stack[-4];
    stack[0] = v_1277;
    goto v_1157;
v_1159:
v_1157:
    v_1277 = stack[0];
    v_1277 = qcar(v_1277);
    v_1277 = qcar(v_1277);
    stack[-2] = v_1277;
    v_1277 = stack[0];
    v_1277 = qcdr(v_1277);
    stack[-3] = v_1277;
v_1179:
    v_1277 = stack[-3];
    if (v_1277 == nil) goto v_1182;
    goto v_1191;
v_1187:
    v_1278 = stack[-2];
    goto v_1188;
v_1189:
    v_1277 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1190;
v_1191:
    goto v_1187;
v_1188:
    goto v_1189;
v_1190:
    if (v_1278 == v_1277) goto v_1182;
    goto v_1183;
v_1182:
    goto v_1178;
v_1183:
    goto v_1200;
v_1196:
    v_1278 = stack[-2];
    goto v_1197;
v_1198:
    v_1277 = stack[-3];
    v_1277 = qcar(v_1277);
    v_1277 = qcar(v_1277);
    goto v_1199;
v_1200:
    goto v_1196;
v_1197:
    goto v_1198;
v_1199:
    fn = elt(env, 2); // gcdf!*
    v_1277 = (*qfn2(fn))(fn, v_1278, v_1277);
    env = stack[-4];
    stack[-2] = v_1277;
    v_1277 = stack[-3];
    v_1277 = qcdr(v_1277);
    stack[-3] = v_1277;
    goto v_1179;
v_1178:
    v_1277 = nil;
    stack[-3] = v_1277;
    v_1277 = stack[0];
    stack[-1] = v_1277;
v_1212:
    v_1277 = stack[-1];
    if (v_1277 == nil) goto v_1216;
    else goto v_1217;
v_1216:
    goto v_1211;
v_1217:
    v_1277 = stack[-1];
    v_1277 = qcar(v_1277);
    stack[0] = v_1277;
    goto v_1231;
v_1227:
    v_1277 = stack[0];
    v_1278 = qcar(v_1277);
    goto v_1228;
v_1229:
    v_1277 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1230;
v_1231:
    goto v_1227;
v_1228:
    goto v_1229;
v_1230:
    if (v_1278 == v_1277) goto v_1226;
    goto v_1240;
v_1236:
    goto v_1249;
v_1245:
    v_1278 = stack[-2];
    goto v_1246;
v_1247:
    v_1277 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1248;
v_1249:
    goto v_1245;
v_1246:
    goto v_1247;
v_1248:
    if (v_1278 == v_1277) goto v_1243;
    else goto v_1244;
v_1243:
    v_1277 = stack[0];
    v_1278 = v_1277;
    goto v_1242;
v_1244:
    goto v_1260;
v_1256:
    goto v_1266;
v_1262:
    v_1277 = stack[0];
    v_1278 = qcar(v_1277);
    goto v_1263;
v_1264:
    v_1277 = stack[-2];
    goto v_1265;
v_1266:
    goto v_1262;
v_1263:
    goto v_1264;
v_1265:
    v_1278 = quot2(v_1278, v_1277);
    env = stack[-4];
    goto v_1257;
v_1258:
    v_1277 = stack[0];
    v_1277 = qcdr(v_1277);
    goto v_1259;
v_1260:
    goto v_1256;
v_1257:
    goto v_1258;
v_1259:
    v_1277 = cons(v_1278, v_1277);
    env = stack[-4];
    v_1278 = v_1277;
    goto v_1242;
    v_1278 = nil;
v_1242:
    goto v_1237;
v_1238:
    v_1277 = stack[-3];
    goto v_1239;
v_1240:
    goto v_1236;
v_1237:
    goto v_1238;
v_1239:
    v_1277 = cons(v_1278, v_1277);
    env = stack[-4];
    stack[-3] = v_1277;
    goto v_1224;
v_1226:
v_1224:
    v_1277 = stack[-1];
    v_1277 = qcdr(v_1277);
    stack[-1] = v_1277;
    goto v_1212;
v_1211:
    v_1277 = stack[-3];
        return Lnreverse(nil, v_1277);
v_1127:
    goto v_1117;
    v_1277 = nil;
v_1117:
    return onevalue(v_1277);
}



// Code for general!-modular!-number

static LispObject CC_generalKmodularKnumber(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1147, v_1148;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
    goto v_1123;
v_1119:
    v_1148 = stack[0];
    goto v_1120;
v_1121:
    v_1147 = qvalue(elt(env, 1)); // current!-modulus
    goto v_1122;
v_1123:
    goto v_1119;
v_1120:
    goto v_1121;
v_1122:
    v_1147 = Cremainder(v_1148, v_1147);
    env = stack[-1];
    stack[0] = v_1147;
    goto v_1135;
v_1131:
    v_1148 = stack[0];
    goto v_1132;
v_1133:
    v_1147 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1134;
v_1135:
    goto v_1131;
v_1132:
    goto v_1133;
v_1134:
    v_1147 = (LispObject)lessp2(v_1148, v_1147);
    v_1147 = v_1147 ? lisp_true : nil;
    env = stack[-1];
    if (v_1147 == nil) goto v_1129;
    goto v_1143;
v_1139:
    v_1148 = stack[0];
    goto v_1140;
v_1141:
    v_1147 = qvalue(elt(env, 1)); // current!-modulus
    goto v_1142;
v_1143:
    goto v_1139;
v_1140:
    goto v_1141;
v_1142:
    v_1147 = plus2(v_1148, v_1147);
    stack[0] = v_1147;
    goto v_1127;
v_1129:
v_1127:
    v_1147 = stack[0];
    return onevalue(v_1147);
}



// Code for bfzerop!:

static LispObject CC_bfzeropT(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1126, v_1127;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1126 = v_1114;
// end of prologue
    goto v_1120;
v_1116:
    v_1126 = qcdr(v_1126);
    v_1127 = qcar(v_1126);
    goto v_1117;
v_1118:
    v_1126 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1119;
v_1120:
    goto v_1116;
v_1117:
    goto v_1118;
v_1119:
    v_1126 = (v_1127 == v_1126 ? lisp_true : nil);
    return onevalue(v_1126);
}



// Code for ordopcar

static LispObject CC_ordopcar(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1127, v_1128;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1127 = v_1115;
    v_1128 = v_1114;
// end of prologue
    goto v_1122;
v_1118:
    v_1128 = qcar(v_1128);
    goto v_1119;
v_1120:
    v_1127 = qcar(v_1127);
    goto v_1121;
v_1122:
    goto v_1118;
v_1119:
    goto v_1120;
v_1121:
    {
        fn = elt(env, 1); // ordop
        return (*qfn2(fn))(fn, v_1128, v_1127);
    }
}



// Code for checkargcount

static LispObject CC_checkargcount(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1174, v_1175, v_1176, v_1177, v_1178;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_1176 = v_1115;
    v_1177 = v_1114;
// end of prologue
    goto v_1129;
v_1125:
    v_1175 = v_1177;
    goto v_1126;
v_1127:
    v_1174 = elt(env, 1); // naryargs
    goto v_1128;
v_1129:
    goto v_1125;
v_1126:
    goto v_1127;
v_1128:
    v_1174 = Lflagp(nil, v_1175, v_1174);
    env = stack[-3];
    if (v_1174 == nil) goto v_1123;
    v_1174 = nil;
    goto v_1119;
v_1123:
    v_1174 = v_1177;
    if (!symbolp(v_1174)) v_1174 = nil;
    else { v_1174 = qfastgets(v_1174);
           if (v_1174 != nil) { v_1174 = elt(v_1174, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_1174 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_1174 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_1174 == SPID_NOPROP) v_1174 = nil; }}
#endif
    v_1178 = v_1174;
    v_1174 = v_1178;
    if (v_1174 == nil) goto v_1137;
    else goto v_1138;
v_1137:
    goto v_1145;
v_1141:
    v_1174 = v_1177;
    goto v_1142;
v_1143:
    v_1175 = v_1176;
    goto v_1144;
v_1145:
    goto v_1141;
v_1142:
    goto v_1143;
v_1144:
    {
        fn = elt(env, 3); // hasarg
        return (*qfn2(fn))(fn, v_1174, v_1175);
    }
v_1138:
    goto v_1156;
v_1152:
    v_1175 = v_1178;
    goto v_1153;
v_1154:
    v_1174 = v_1176;
    goto v_1155;
v_1156:
    goto v_1152;
v_1153:
    goto v_1154;
v_1155:
    if (equal(v_1175, v_1174)) goto v_1151;
    goto v_1168;
v_1160:
    stack[-2] = v_1177;
    goto v_1161;
v_1162:
    stack[-1] = v_1178;
    goto v_1163;
v_1164:
    stack[0] = v_1176;
    goto v_1165;
v_1166:
    v_1174 = qvalue(elt(env, 2)); // curfun!*
    v_1174 = ncons(v_1174);
    env = stack[-3];
    goto v_1167;
v_1168:
    goto v_1160;
v_1161:
    goto v_1162;
v_1163:
    goto v_1164;
v_1165:
    goto v_1166;
v_1167:
    fn = elt(env, 4); // instdof
    v_1174 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_1174);
    goto v_1149;
v_1151:
v_1149:
    v_1174 = nil;
v_1119:
    return onevalue(v_1174);
}



// Code for treesizep1

static LispObject CC_treesizep1(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1150, v_1151;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
v_1119:
    v_1150 = stack[-1];
    if (!consp(v_1150)) goto v_1122;
    else goto v_1123;
v_1122:
    v_1150 = stack[0];
    return sub1(v_1150);
v_1123:
    goto v_1134;
v_1130:
    goto v_1140;
v_1136:
    v_1150 = stack[-1];
    v_1151 = qcar(v_1150);
    goto v_1137;
v_1138:
    v_1150 = stack[0];
    goto v_1139;
v_1140:
    goto v_1136;
v_1137:
    goto v_1138;
v_1139:
    v_1151 = CC_treesizep1(elt(env, 0), v_1151, v_1150);
    env = stack[-2];
    stack[0] = v_1151;
    goto v_1131;
v_1132:
    v_1150 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1133;
v_1134:
    goto v_1130;
v_1131:
    goto v_1132;
v_1133:
    v_1150 = (LispObject)greaterp2(v_1151, v_1150);
    v_1150 = v_1150 ? lisp_true : nil;
    env = stack[-2];
    if (v_1150 == nil) goto v_1128;
    v_1150 = stack[-1];
    v_1150 = qcdr(v_1150);
    stack[-1] = v_1150;
    goto v_1119;
v_1128:
    v_1150 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1118;
    v_1150 = nil;
v_1118:
    return onevalue(v_1150);
}



// Code for listeval

static LispObject CC_listeval(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1227, v_1228;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_1115;
    stack[0] = v_1114;
// end of prologue
    goto v_1126;
v_1122:
    v_1227 = qvalue(elt(env, 1)); // simpcount!*
    v_1228 = add1(v_1227);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_1228; // simpcount!*
    goto v_1123;
v_1124:
    v_1227 = qvalue(elt(env, 2)); // simplimit!*
    goto v_1125;
v_1126:
    goto v_1122;
v_1123:
    goto v_1124;
v_1125:
    v_1227 = (LispObject)greaterp2(v_1228, v_1227);
    v_1227 = v_1227 ? lisp_true : nil;
    env = stack[-5];
    if (v_1227 == nil) goto v_1120;
    v_1227 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_1227; // simpcount!*
    v_1227 = elt(env, 3); // "Simplification recursion too deep"
    fn = elt(env, 4); // rederr
    v_1227 = (*qfn1(fn))(fn, v_1227);
    env = stack[-5];
    goto v_1118;
v_1120:
v_1118:
    v_1227 = stack[0];
    if (!consp(v_1227)) goto v_1135;
    else goto v_1136;
v_1135:
    goto v_1143;
v_1139:
    v_1227 = stack[0];
    if (!symbolp(v_1227)) v_1227 = nil;
    else { v_1227 = qfastgets(v_1227);
           if (v_1227 != nil) { v_1227 = elt(v_1227, 17); // share
#ifdef RECORD_GET
             if (v_1227 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_1227 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_1227 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_1227 == SPID_NOPROP) v_1227 = nil; else v_1227 = lisp_true; }}
#endif
    if (v_1227 == nil) goto v_1147;
    v_1227 = stack[0];
    fn = elt(env, 5); // eval
    v_1227 = (*qfn1(fn))(fn, v_1227);
    env = stack[-5];
    v_1228 = v_1227;
    goto v_1145;
v_1147:
    v_1227 = stack[0];
    if (!symbolp(v_1227)) v_1227 = nil;
    else { v_1227 = qfastgets(v_1227);
           if (v_1227 != nil) { v_1227 = elt(v_1227, 4); // avalue
#ifdef RECORD_GET
             if (v_1227 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_1227 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_1227 == SPID_NOPROP) v_1227 = nil; }}
#endif
    v_1227 = qcdr(v_1227);
    v_1227 = qcar(v_1227);
    v_1228 = v_1227;
    goto v_1145;
    v_1228 = nil;
v_1145:
    goto v_1140;
v_1141:
    v_1227 = stack[-1];
    goto v_1142;
v_1143:
    goto v_1139;
v_1140:
    goto v_1141;
v_1142:
    v_1227 = CC_listeval(elt(env, 0), v_1228, v_1227);
    env = stack[-5];
    goto v_1134;
v_1136:
    goto v_1166;
v_1162:
    v_1227 = stack[0];
    stack[-4] = qcar(v_1227);
    goto v_1163;
v_1164:
    v_1227 = stack[0];
    v_1227 = qcdr(v_1227);
    stack[-3] = v_1227;
    v_1227 = stack[-3];
    if (v_1227 == nil) goto v_1179;
    else goto v_1180;
v_1179:
    v_1227 = nil;
    goto v_1173;
v_1180:
    v_1227 = stack[-3];
    v_1227 = qcar(v_1227);
    goto v_1192;
v_1188:
    v_1228 = v_1227;
    goto v_1189;
v_1190:
    v_1227 = lisp_true;
    goto v_1191;
v_1192:
    goto v_1188;
v_1189:
    goto v_1190;
v_1191:
    fn = elt(env, 6); // reval1
    v_1227 = (*qfn2(fn))(fn, v_1228, v_1227);
    env = stack[-5];
    v_1227 = ncons(v_1227);
    env = stack[-5];
    stack[-1] = v_1227;
    stack[-2] = v_1227;
v_1174:
    v_1227 = stack[-3];
    v_1227 = qcdr(v_1227);
    stack[-3] = v_1227;
    v_1227 = stack[-3];
    if (v_1227 == nil) goto v_1199;
    else goto v_1200;
v_1199:
    v_1227 = stack[-2];
    goto v_1173;
v_1200:
    goto v_1208;
v_1204:
    stack[0] = stack[-1];
    goto v_1205;
v_1206:
    v_1227 = stack[-3];
    v_1227 = qcar(v_1227);
    goto v_1219;
v_1215:
    v_1228 = v_1227;
    goto v_1216;
v_1217:
    v_1227 = lisp_true;
    goto v_1218;
v_1219:
    goto v_1215;
v_1216:
    goto v_1217;
v_1218:
    fn = elt(env, 6); // reval1
    v_1227 = (*qfn2(fn))(fn, v_1228, v_1227);
    env = stack[-5];
    v_1227 = ncons(v_1227);
    env = stack[-5];
    goto v_1207;
v_1208:
    goto v_1204;
v_1205:
    goto v_1206;
v_1207:
    v_1227 = Lrplacd(nil, stack[0], v_1227);
    env = stack[-5];
    v_1227 = stack[-1];
    v_1227 = qcdr(v_1227);
    stack[-1] = v_1227;
    goto v_1174;
v_1173:
    goto v_1165;
v_1166:
    goto v_1162;
v_1163:
    goto v_1164;
v_1165:
    v_1227 = cons(stack[-4], v_1227);
    env = stack[-5];
    goto v_1134;
    v_1227 = nil;
v_1134:
    stack[0] = v_1227;
    v_1227 = qvalue(elt(env, 1)); // simpcount!*
    v_1227 = sub1(v_1227);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_1227; // simpcount!*
    v_1227 = stack[0];
    return onevalue(v_1227);
}



// Code for quotf!-fail

static LispObject CC_quotfKfail(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1196, v_1197, v_1198;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_1115;
    stack[-2] = v_1114;
// end of prologue
    v_1196 = stack[-2];
    if (v_1196 == nil) goto v_1119;
    else goto v_1120;
v_1119:
    v_1196 = nil;
    goto v_1118;
v_1120:
    goto v_1133;
v_1129:
    v_1197 = stack[-2];
    goto v_1130;
v_1131:
    v_1196 = stack[-1];
    goto v_1132;
v_1133:
    goto v_1129;
v_1130:
    goto v_1131;
v_1132:
    fn = elt(env, 5); // quotf
    v_1196 = (*qfn2(fn))(fn, v_1197, v_1196);
    env = stack[-4];
    v_1197 = v_1196;
    v_1196 = v_1197;
    if (v_1196 == nil) goto v_1142;
    else goto v_1143;
v_1142:
    v_1196 = qvalue(elt(env, 1)); // !*rounded
    if (v_1196 == nil) goto v_1147;
    else goto v_1148;
v_1147:
    v_1196 = nil;
    goto v_1146;
v_1148:
    v_1196 = qvalue(elt(env, 2)); // !*roundall
    goto v_1146;
    v_1196 = nil;
v_1146:
    goto v_1141;
v_1143:
    v_1196 = nil;
    goto v_1141;
    v_1196 = nil;
v_1141:
    if (v_1196 == nil) goto v_1139;
    v_1196 = nil;
// Binding !*roundall
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = v_1196; // !*roundall
    goto v_1164;
v_1160:
    v_1197 = stack[-2];
    goto v_1161;
v_1162:
    v_1196 = stack[-1];
    goto v_1163;
v_1164:
    goto v_1160;
v_1161:
    goto v_1162;
v_1163:
    fn = elt(env, 5); // quotf
    v_1196 = (*qfn2(fn))(fn, v_1197, v_1196);
    env = stack[-4];
    v_1197 = v_1196;
    ;}  // end of a binding scope
    goto v_1137;
v_1139:
v_1137:
    v_1196 = v_1197;
    if (v_1196 == nil) goto v_1169;
    else goto v_1170;
v_1169:
    goto v_1179;
v_1173:
    stack[-3] = elt(env, 3); // poly
    goto v_1174;
v_1175:
    stack[0] = (LispObject)1584+TAG_FIXNUM; // 99
    goto v_1176;
v_1177:
    goto v_1189;
v_1183:
    v_1198 = elt(env, 4); // "UNEXPECTED DIVISION FAILURE"
    goto v_1184;
v_1185:
    v_1197 = stack[-2];
    goto v_1186;
v_1187:
    v_1196 = stack[-1];
    goto v_1188;
v_1189:
    goto v_1183;
v_1184:
    goto v_1185;
v_1186:
    goto v_1187;
v_1188:
    v_1196 = list3(v_1198, v_1197, v_1196);
    env = stack[-4];
    goto v_1178;
v_1179:
    goto v_1173;
v_1174:
    goto v_1175;
v_1176:
    goto v_1177;
v_1178:
    fn = elt(env, 6); // rerror
    v_1196 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_1196);
    goto v_1168;
v_1170:
    v_1196 = v_1197;
    goto v_1127;
v_1168:
    v_1196 = nil;
v_1127:
    goto v_1118;
    v_1196 = nil;
v_1118:
    return onevalue(v_1196);
}



// Code for get!+col!+nr

static LispObject CC_getLcolLnr(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1121;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1121 = v_1114;
// end of prologue
    v_1121 = qcar(v_1121);
        return Llength(nil, v_1121);
    return onevalue(v_1121);
}



// Code for cl_simplat

static LispObject CC_cl_simplat(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1147, v_1148, v_1149;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_1148 = v_1115;
    v_1149 = v_1114;
// end of prologue
    v_1147 = qvalue(elt(env, 1)); // !*rlidentify
    if (v_1147 == nil) goto v_1119;
    else goto v_1120;
v_1119:
    goto v_1127;
v_1123:
    v_1147 = v_1149;
    goto v_1124;
v_1125:
    goto v_1126;
v_1127:
    goto v_1123;
v_1124:
    goto v_1125;
v_1126:
    {
        fn = elt(env, 3); // rl_simplat1
        return (*qfn2(fn))(fn, v_1147, v_1148);
    }
v_1120:
    goto v_1137;
v_1133:
    goto v_1143;
v_1139:
    v_1147 = v_1149;
    goto v_1140;
v_1141:
    goto v_1142;
v_1143:
    goto v_1139;
v_1140:
    goto v_1141;
v_1142:
    fn = elt(env, 3); // rl_simplat1
    v_1148 = (*qfn2(fn))(fn, v_1147, v_1148);
    env = stack[0];
    goto v_1134;
v_1135:
    v_1147 = elt(env, 2); // cl_identifyat
    goto v_1136;
v_1137:
    goto v_1133;
v_1134:
    goto v_1135;
v_1136:
    {
        fn = elt(env, 4); // cl_apply2ats
        return (*qfn2(fn))(fn, v_1148, v_1147);
    }
    v_1147 = nil;
    return onevalue(v_1147);
}



// Code for pasf_dec

static LispObject CC_pasf_dec(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1157, v_1158;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_1158 = v_1114;
// end of prologue
    v_1157 = v_1158;
    stack[-1] = v_1157;
v_1122:
    v_1157 = stack[-1];
    if (!consp(v_1157)) goto v_1129;
    else goto v_1130;
v_1129:
    v_1157 = lisp_true;
    goto v_1128;
v_1130:
    v_1157 = stack[-1];
    v_1157 = qcar(v_1157);
    v_1157 = (consp(v_1157) ? nil : lisp_true);
    goto v_1128;
    v_1157 = nil;
v_1128:
    if (v_1157 == nil) goto v_1126;
    goto v_1121;
v_1126:
    v_1157 = stack[-1];
    v_1157 = qcdr(v_1157);
    stack[-1] = v_1157;
    goto v_1122;
v_1121:
    goto v_1146;
v_1142:
    goto v_1152;
v_1148:
    stack[0] = v_1158;
    goto v_1149;
v_1150:
    v_1157 = stack[-1];
    fn = elt(env, 1); // negf
    v_1157 = (*qfn1(fn))(fn, v_1157);
    env = stack[-2];
    goto v_1151;
v_1152:
    goto v_1148;
v_1149:
    goto v_1150;
v_1151:
    fn = elt(env, 2); // addf
    v_1158 = (*qfn2(fn))(fn, stack[0], v_1157);
    goto v_1143;
v_1144:
    v_1157 = stack[-1];
    goto v_1145;
v_1146:
    goto v_1142;
v_1143:
    goto v_1144;
v_1145:
    return cons(v_1158, v_1157);
    return onevalue(v_1157);
}



// Code for vevcompless!?

static LispObject CC_vevcomplessW(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1132, v_1133;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_1133 = v_1115;
    v_1132 = v_1114;
// end of prologue
    goto v_1121;
v_1117:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1118;
v_1119:
    goto v_1128;
v_1124:
    goto v_1125;
v_1126:
    goto v_1127;
v_1128:
    goto v_1124;
v_1125:
    goto v_1126;
v_1127:
    fn = elt(env, 1); // evcomp
    v_1132 = (*qfn2(fn))(fn, v_1133, v_1132);
    goto v_1120;
v_1121:
    goto v_1117;
v_1118:
    goto v_1119;
v_1120:
    v_1132 = (stack[0] == v_1132 ? lisp_true : nil);
    return onevalue(v_1132);
}



// Code for fprin2

static LispObject CC_fprin2(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1129, v_1130;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1130 = v_1114;
// end of prologue
    v_1129 = nil;
// Binding !*lower
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_1129; // !*lower
    v_1129 = qvalue(elt(env, 2)); // !*fortupper
    if (v_1129 == nil) goto v_1121;
    v_1129 = v_1130;
    fn = elt(env, 3); // prin2!-upcase
    v_1129 = (*qfn1(fn))(fn, v_1129);
    goto v_1119;
v_1121:
    v_1129 = v_1130;
    fn = elt(env, 4); // prin2!-downcase
    v_1129 = (*qfn1(fn))(fn, v_1129);
    goto v_1119;
    v_1129 = nil;
v_1119:
    ;}  // end of a binding scope
    return onevalue(v_1129);
}



// Code for widestring2list

static LispObject CC_widestring2list(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1402, v_1403;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_1402 = v_1114;
// end of prologue
    stack[-2] = nil;
    fn = elt(env, 2); // string2list
    v_1402 = (*qfn1(fn))(fn, v_1402);
    env = stack[-4];
    stack[-3] = v_1402;
v_1126:
    v_1402 = stack[-3];
    if (v_1402 == nil) goto v_1129;
    else goto v_1130;
v_1129:
    goto v_1125;
v_1130:
    v_1402 = stack[-3];
    v_1402 = qcar(v_1402);
    stack[0] = v_1402;
    v_1402 = stack[-3];
    v_1402 = qcdr(v_1402);
    stack[-3] = v_1402;
    goto v_1145;
v_1141:
    goto v_1151;
v_1147:
    v_1403 = stack[0];
    goto v_1148;
v_1149:
    v_1402 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_1150;
v_1151:
    goto v_1147;
v_1148:
    goto v_1149;
v_1150:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1142;
v_1143:
    v_1402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1144;
v_1145:
    goto v_1141;
v_1142:
    goto v_1143;
v_1144:
    if (v_1403 == v_1402) goto v_1140;
    goto v_1163;
v_1159:
    goto v_1169;
v_1165:
    v_1403 = stack[0];
    goto v_1166;
v_1167:
    v_1402 = (LispObject)3584+TAG_FIXNUM; // 224
    goto v_1168;
v_1169:
    goto v_1165;
v_1166:
    goto v_1167;
v_1168:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1160;
v_1161:
    v_1402 = (LispObject)3072+TAG_FIXNUM; // 192
    goto v_1162;
v_1163:
    goto v_1159;
v_1160:
    goto v_1161;
v_1162:
    if (v_1403 == v_1402) goto v_1157;
    else goto v_1158;
v_1157:
    v_1402 = stack[-3];
    fn = elt(env, 4); // moan!-if!-truncated
    v_1402 = (*qfn1(fn))(fn, v_1402);
    env = stack[-4];
    stack[-1] = v_1402;
    v_1402 = stack[-3];
    v_1402 = qcdr(v_1402);
    stack[-3] = v_1402;
    goto v_1182;
v_1178:
    goto v_1188;
v_1184:
    goto v_1194;
v_1190:
    v_1403 = stack[0];
    goto v_1191;
v_1192:
    v_1402 = (LispObject)496+TAG_FIXNUM; // 31
    goto v_1193;
v_1194:
    goto v_1190;
v_1191:
    goto v_1192;
v_1193:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1185;
v_1186:
    v_1402 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_1187;
v_1188:
    goto v_1184;
v_1185:
    goto v_1186;
v_1187:
    fn = elt(env, 5); // lshift
    stack[0] = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1179;
v_1180:
    goto v_1203;
v_1199:
    v_1403 = stack[-1];
    goto v_1200;
v_1201:
    v_1402 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_1202;
v_1203:
    goto v_1199;
v_1200:
    goto v_1201;
v_1202:
    fn = elt(env, 3); // land
    v_1402 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1181;
v_1182:
    goto v_1178;
v_1179:
    goto v_1180;
v_1181:
    v_1402 = plus2(stack[0], v_1402);
    env = stack[-4];
    stack[0] = v_1402;
    goto v_1156;
v_1158:
    goto v_1212;
v_1208:
    goto v_1218;
v_1214:
    v_1403 = stack[0];
    goto v_1215;
v_1216:
    v_1402 = (LispObject)3840+TAG_FIXNUM; // 240
    goto v_1217;
v_1218:
    goto v_1214;
v_1215:
    goto v_1216;
v_1217:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1209;
v_1210:
    v_1402 = (LispObject)3584+TAG_FIXNUM; // 224
    goto v_1211;
v_1212:
    goto v_1208;
v_1209:
    goto v_1210;
v_1211:
    if (v_1403 == v_1402) goto v_1206;
    else goto v_1207;
v_1206:
    v_1402 = stack[-3];
    fn = elt(env, 4); // moan!-if!-truncated
    v_1402 = (*qfn1(fn))(fn, v_1402);
    env = stack[-4];
    stack[-1] = v_1402;
    v_1402 = stack[-3];
    v_1402 = qcdr(v_1402);
    stack[-3] = v_1402;
    goto v_1231;
v_1227:
    goto v_1237;
v_1233:
    goto v_1243;
v_1239:
    v_1403 = stack[0];
    goto v_1240;
v_1241:
    v_1402 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_1242;
v_1243:
    goto v_1239;
v_1240:
    goto v_1241;
v_1242:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1234;
v_1235:
    v_1402 = (LispObject)192+TAG_FIXNUM; // 12
    goto v_1236;
v_1237:
    goto v_1233;
v_1234:
    goto v_1235;
v_1236:
    fn = elt(env, 5); // lshift
    stack[0] = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1228;
v_1229:
    goto v_1252;
v_1248:
    goto v_1258;
v_1254:
    v_1403 = stack[-1];
    goto v_1255;
v_1256:
    v_1402 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_1257;
v_1258:
    goto v_1254;
v_1255:
    goto v_1256;
v_1257:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1249;
v_1250:
    v_1402 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_1251;
v_1252:
    goto v_1248;
v_1249:
    goto v_1250;
v_1251:
    fn = elt(env, 5); // lshift
    v_1402 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1230;
v_1231:
    goto v_1227;
v_1228:
    goto v_1229;
v_1230:
    v_1402 = plus2(stack[0], v_1402);
    env = stack[-4];
    stack[0] = v_1402;
    v_1402 = stack[-3];
    fn = elt(env, 4); // moan!-if!-truncated
    v_1402 = (*qfn1(fn))(fn, v_1402);
    env = stack[-4];
    stack[-1] = v_1402;
    v_1402 = stack[-3];
    v_1402 = qcdr(v_1402);
    stack[-3] = v_1402;
    goto v_1271;
v_1267:
    goto v_1268;
v_1269:
    goto v_1278;
v_1274:
    v_1403 = stack[-1];
    goto v_1275;
v_1276:
    v_1402 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_1277;
v_1278:
    goto v_1274;
v_1275:
    goto v_1276;
v_1277:
    fn = elt(env, 3); // land
    v_1402 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1270;
v_1271:
    goto v_1267;
v_1268:
    goto v_1269;
v_1270:
    v_1402 = plus2(stack[0], v_1402);
    env = stack[-4];
    stack[0] = v_1402;
    goto v_1156;
v_1207:
    goto v_1287;
v_1283:
    goto v_1293;
v_1289:
    v_1403 = stack[0];
    goto v_1290;
v_1291:
    v_1402 = (LispObject)3968+TAG_FIXNUM; // 248
    goto v_1292;
v_1293:
    goto v_1289;
v_1290:
    goto v_1291;
v_1292:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1284;
v_1285:
    v_1402 = (LispObject)3840+TAG_FIXNUM; // 240
    goto v_1286;
v_1287:
    goto v_1283;
v_1284:
    goto v_1285;
v_1286:
    if (v_1403 == v_1402) goto v_1281;
    else goto v_1282;
v_1281:
    v_1402 = stack[-3];
    fn = elt(env, 4); // moan!-if!-truncated
    v_1402 = (*qfn1(fn))(fn, v_1402);
    env = stack[-4];
    stack[-1] = v_1402;
    v_1402 = stack[-3];
    v_1402 = qcdr(v_1402);
    stack[-3] = v_1402;
    goto v_1306;
v_1302:
    goto v_1312;
v_1308:
    goto v_1318;
v_1314:
    v_1403 = stack[0];
    goto v_1315;
v_1316:
    v_1402 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_1317;
v_1318:
    goto v_1314;
v_1315:
    goto v_1316;
v_1317:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1309;
v_1310:
    v_1402 = (LispObject)288+TAG_FIXNUM; // 18
    goto v_1311;
v_1312:
    goto v_1308;
v_1309:
    goto v_1310;
v_1311:
    fn = elt(env, 5); // lshift
    stack[0] = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1303;
v_1304:
    goto v_1327;
v_1323:
    goto v_1333;
v_1329:
    v_1403 = stack[-1];
    goto v_1330;
v_1331:
    v_1402 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_1332;
v_1333:
    goto v_1329;
v_1330:
    goto v_1331;
v_1332:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1324;
v_1325:
    v_1402 = (LispObject)192+TAG_FIXNUM; // 12
    goto v_1326;
v_1327:
    goto v_1323;
v_1324:
    goto v_1325;
v_1326:
    fn = elt(env, 5); // lshift
    v_1402 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1305;
v_1306:
    goto v_1302;
v_1303:
    goto v_1304;
v_1305:
    v_1402 = plus2(stack[0], v_1402);
    env = stack[-4];
    stack[0] = v_1402;
    v_1402 = stack[-3];
    fn = elt(env, 4); // moan!-if!-truncated
    v_1402 = (*qfn1(fn))(fn, v_1402);
    env = stack[-4];
    stack[-1] = v_1402;
    v_1402 = stack[-3];
    v_1402 = qcdr(v_1402);
    stack[-3] = v_1402;
    goto v_1346;
v_1342:
    goto v_1343;
v_1344:
    goto v_1353;
v_1349:
    goto v_1359;
v_1355:
    v_1403 = stack[-1];
    goto v_1356;
v_1357:
    v_1402 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_1358;
v_1359:
    goto v_1355;
v_1356:
    goto v_1357;
v_1358:
    fn = elt(env, 3); // land
    v_1403 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1350;
v_1351:
    v_1402 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_1352;
v_1353:
    goto v_1349;
v_1350:
    goto v_1351;
v_1352:
    fn = elt(env, 5); // lshift
    v_1402 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1345;
v_1346:
    goto v_1342;
v_1343:
    goto v_1344;
v_1345:
    v_1402 = plus2(stack[0], v_1402);
    env = stack[-4];
    stack[0] = v_1402;
    v_1402 = stack[-3];
    fn = elt(env, 4); // moan!-if!-truncated
    v_1402 = (*qfn1(fn))(fn, v_1402);
    env = stack[-4];
    stack[-1] = v_1402;
    v_1402 = stack[-3];
    v_1402 = qcdr(v_1402);
    stack[-3] = v_1402;
    goto v_1372;
v_1368:
    goto v_1369;
v_1370:
    goto v_1379;
v_1375:
    v_1403 = stack[-1];
    goto v_1376;
v_1377:
    v_1402 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_1378;
v_1379:
    goto v_1375;
v_1376:
    goto v_1377;
v_1378:
    fn = elt(env, 3); // land
    v_1402 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1371;
v_1372:
    goto v_1368;
v_1369:
    goto v_1370;
v_1371:
    v_1402 = plus2(stack[0], v_1402);
    env = stack[-4];
    stack[0] = v_1402;
    goto v_1156;
v_1282:
    goto v_1389;
v_1385:
    v_1403 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1386;
v_1387:
    v_1402 = elt(env, 1); // "Improper byte in utf-8 string"
    goto v_1388;
v_1389:
    goto v_1385;
v_1386:
    goto v_1387;
v_1388:
    fn = elt(env, 6); // error
    v_1402 = (*qfn2(fn))(fn, v_1403, v_1402);
    env = stack[-4];
    goto v_1156;
v_1156:
    goto v_1138;
v_1140:
v_1138:
    goto v_1397;
v_1393:
    v_1403 = stack[0];
    goto v_1394;
v_1395:
    v_1402 = stack[-2];
    goto v_1396;
v_1397:
    goto v_1393;
v_1394:
    goto v_1395;
v_1396:
    v_1402 = cons(v_1403, v_1402);
    env = stack[-4];
    stack[-2] = v_1402;
    goto v_1126;
v_1125:
    v_1402 = stack[-2];
        return Lnreverse(nil, v_1402);
    return onevalue(v_1402);
}



// Code for mo!=sum

static LispObject CC_moMsum(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1170, v_1171, v_1172;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
    v_1172 = nil;
v_1122:
    v_1170 = stack[-1];
    if (v_1170 == nil) goto v_1125;
    v_1170 = stack[0];
    if (v_1170 == nil) goto v_1125;
    goto v_1126;
v_1125:
    goto v_1121;
v_1126:
    goto v_1137;
v_1133:
    goto v_1142;
v_1138:
    v_1170 = stack[-1];
    v_1171 = qcar(v_1170);
    goto v_1139;
v_1140:
    v_1170 = stack[0];
    v_1170 = qcar(v_1170);
    goto v_1141;
v_1142:
    goto v_1138;
v_1139:
    goto v_1140;
v_1141:
    v_1170 = (LispObject)(intptr_t)((intptr_t)v_1171 + (intptr_t)v_1170 - TAG_FIXNUM);
    goto v_1134;
v_1135:
    v_1171 = v_1172;
    goto v_1136;
v_1137:
    goto v_1133;
v_1134:
    goto v_1135;
v_1136:
    v_1170 = cons(v_1170, v_1171);
    env = stack[-2];
    v_1172 = v_1170;
    v_1170 = stack[-1];
    v_1170 = qcdr(v_1170);
    stack[-1] = v_1170;
    v_1170 = stack[0];
    v_1170 = qcdr(v_1170);
    stack[0] = v_1170;
    goto v_1122;
v_1121:
    goto v_1158;
v_1154:
    v_1170 = v_1172;
    v_1171 = Lnreverse(nil, v_1170);
    goto v_1155;
v_1156:
    v_1170 = stack[-1];
    if (v_1170 == nil) goto v_1164;
    v_1170 = stack[-1];
    goto v_1162;
v_1164:
    v_1170 = stack[0];
    goto v_1162;
    v_1170 = nil;
v_1162:
    goto v_1157;
v_1158:
    goto v_1154;
v_1155:
    goto v_1156;
v_1157:
        return Lappend(nil, v_1171, v_1170);
    return onevalue(v_1170);
}



// Code for lcm

static LispObject CC_lcm(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1176, v_1177, v_1178, v_1179;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_1178 = v_1115;
    v_1179 = v_1114;
// end of prologue
    v_1176 = v_1179;
    if (v_1176 == nil) goto v_1123;
    else goto v_1124;
v_1123:
    v_1176 = lisp_true;
    goto v_1122;
v_1124:
    v_1176 = v_1178;
    v_1176 = (v_1176 == nil ? lisp_true : nil);
    goto v_1122;
    v_1176 = nil;
v_1122:
    if (v_1176 == nil) goto v_1120;
    v_1176 = nil;
    goto v_1118;
v_1120:
    goto v_1138;
v_1134:
    v_1177 = v_1179;
    goto v_1135;
v_1136:
    v_1176 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1137;
v_1138:
    goto v_1134;
v_1135:
    goto v_1136;
v_1137:
    if (v_1177 == v_1176) goto v_1132;
    else goto v_1133;
v_1132:
    v_1176 = v_1178;
    goto v_1118;
v_1133:
    goto v_1148;
v_1144:
    v_1177 = v_1178;
    goto v_1145;
v_1146:
    v_1176 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1147;
v_1148:
    goto v_1144;
v_1145:
    goto v_1146;
v_1147:
    if (v_1177 == v_1176) goto v_1142;
    else goto v_1143;
v_1142:
    v_1176 = v_1179;
    goto v_1118;
v_1143:
    goto v_1159;
v_1155:
    stack[-1] = v_1179;
    goto v_1156;
v_1157:
    goto v_1166;
v_1162:
    stack[0] = v_1178;
    goto v_1163;
v_1164:
    goto v_1173;
v_1169:
    v_1176 = v_1179;
    goto v_1170;
v_1171:
    v_1177 = v_1178;
    goto v_1172;
v_1173:
    goto v_1169;
v_1170:
    goto v_1171;
v_1172:
    fn = elt(env, 1); // gcdf
    v_1176 = (*qfn2(fn))(fn, v_1176, v_1177);
    env = stack[-2];
    goto v_1165;
v_1166:
    goto v_1162;
v_1163:
    goto v_1164;
v_1165:
    fn = elt(env, 2); // quotf!-fail
    v_1176 = (*qfn2(fn))(fn, stack[0], v_1176);
    env = stack[-2];
    goto v_1158;
v_1159:
    goto v_1155;
v_1156:
    goto v_1157;
v_1158:
    {
        LispObject v_1182 = stack[-1];
        fn = elt(env, 3); // multf
        return (*qfn2(fn))(fn, v_1182, v_1176);
    }
    v_1176 = nil;
v_1118:
    return onevalue(v_1176);
}



// Code for arzerop!:

static LispObject CC_arzeropT(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1119;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1119 = v_1114;
// end of prologue
    v_1119 = qcdr(v_1119);
    v_1119 = (v_1119 == nil ? lisp_true : nil);
    return onevalue(v_1119);
}



// Code for simpexpon

static LispObject CC_simpexpon(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1124, v_1125;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1124 = v_1114;
// end of prologue
    goto v_1121;
v_1117:
    v_1125 = v_1124;
    goto v_1118;
v_1119:
    v_1124 = elt(env, 1); // simp!*
    goto v_1120;
v_1121:
    goto v_1117;
v_1118:
    goto v_1119;
v_1120:
    {
        fn = elt(env, 2); // simpexpon1
        return (*qfn2(fn))(fn, v_1125, v_1124);
    }
}



// Code for lalr_lr0_closure

static LispObject CC_lalr_lr0_closure(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1286, v_1287, v_1288;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_1114;
// end of prologue
    stack[-7] = nil;
    stack[-5] = nil;
    stack[-2] = nil;
    v_1286 = stack[-6];
    stack[0] = v_1286;
v_1128:
    v_1286 = stack[0];
    if (v_1286 == nil) goto v_1132;
    else goto v_1133;
v_1132:
    goto v_1127;
v_1133:
    v_1286 = stack[0];
    v_1286 = qcar(v_1286);
    goto v_1143;
v_1139:
    v_1287 = elt(env, 1); // !.
    goto v_1140;
v_1141:
    goto v_1142;
v_1143:
    goto v_1139;
v_1140:
    goto v_1141;
v_1142:
    v_1286 = Lmember(nil, v_1287, v_1286);
    v_1286 = qcdr(v_1286);
    v_1287 = v_1286;
    v_1286 = v_1287;
    if (v_1286 == nil) goto v_1151;
    v_1286 = v_1287;
    v_1286 = qcar(v_1286);
    stack[-4] = v_1286;
    if (v_1286 == nil) goto v_1151;
    v_1286 = stack[-4];
    if (symbolp(v_1286)) goto v_1159;
    else goto v_1151;
v_1159:
    goto v_1166;
v_1162:
    v_1287 = stack[-4];
    goto v_1163;
v_1164:
    v_1286 = stack[-5];
    goto v_1165;
v_1166:
    goto v_1162;
v_1163:
    goto v_1164;
v_1165:
    v_1286 = Lmember(nil, v_1287, v_1286);
    if (v_1286 == nil) goto v_1161;
    else goto v_1151;
v_1161:
    goto v_1175;
v_1171:
    v_1287 = stack[-4];
    goto v_1172;
v_1173:
    v_1286 = stack[-5];
    goto v_1174;
v_1175:
    goto v_1171;
v_1172:
    goto v_1173;
v_1174:
    v_1286 = cons(v_1287, v_1286);
    env = stack[-8];
    stack[-5] = v_1286;
    goto v_1149;
v_1151:
v_1149:
    v_1286 = stack[0];
    v_1286 = qcdr(v_1286);
    stack[0] = v_1286;
    goto v_1128;
v_1127:
v_1182:
    v_1286 = stack[-5];
    if (v_1286 == nil) goto v_1185;
    else goto v_1186;
v_1185:
    goto v_1181;
v_1186:
    v_1286 = stack[-5];
    v_1286 = qcar(v_1286);
    stack[-4] = v_1286;
    v_1286 = stack[-5];
    v_1286 = qcdr(v_1286);
    stack[-5] = v_1286;
    goto v_1198;
v_1194:
    v_1287 = stack[-4];
    goto v_1195;
v_1196:
    v_1286 = stack[-7];
    goto v_1197;
v_1198:
    goto v_1194;
v_1195:
    goto v_1196;
v_1197:
    v_1286 = cons(v_1287, v_1286);
    env = stack[-8];
    stack[-7] = v_1286;
    v_1286 = stack[-4];
    fn = elt(env, 2); // lalr_productions
    v_1286 = (*qfn1(fn))(fn, v_1286);
    env = stack[-8];
    stack[-1] = v_1286;
v_1204:
    v_1286 = stack[-1];
    if (v_1286 == nil) goto v_1209;
    else goto v_1210;
v_1209:
    goto v_1203;
v_1210:
    v_1286 = stack[-1];
    v_1286 = qcar(v_1286);
    v_1286 = qcar(v_1286);
    stack[-3] = v_1286;
    goto v_1225;
v_1219:
    stack[0] = stack[-4];
    goto v_1220;
v_1221:
    goto v_1232;
v_1228:
    v_1287 = elt(env, 1); // !.
    goto v_1229;
v_1230:
    v_1286 = stack[-3];
    goto v_1231;
v_1232:
    goto v_1228;
v_1229:
    goto v_1230;
v_1231:
    v_1287 = cons(v_1287, v_1286);
    env = stack[-8];
    goto v_1222;
v_1223:
    v_1286 = stack[-2];
    goto v_1224;
v_1225:
    goto v_1219;
v_1220:
    goto v_1221;
v_1222:
    goto v_1223;
v_1224:
    v_1286 = acons(stack[0], v_1287, v_1286);
    env = stack[-8];
    stack[-2] = v_1286;
    v_1286 = stack[-3];
    if (v_1286 == nil) goto v_1239;
    v_1286 = stack[-3];
    v_1286 = qcar(v_1286);
    v_1288 = v_1286;
    if (v_1286 == nil) goto v_1239;
    v_1286 = v_1288;
    if (symbolp(v_1286)) goto v_1247;
    else goto v_1239;
v_1247:
    goto v_1255;
v_1251:
    v_1287 = v_1288;
    goto v_1252;
v_1253:
    v_1286 = stack[-7];
    goto v_1254;
v_1255:
    goto v_1251;
v_1252:
    goto v_1253;
v_1254:
    v_1286 = Lmember(nil, v_1287, v_1286);
    if (v_1286 == nil) goto v_1250;
    else goto v_1239;
v_1250:
    goto v_1264;
v_1260:
    v_1287 = v_1288;
    goto v_1261;
v_1262:
    v_1286 = stack[-5];
    goto v_1263;
v_1264:
    goto v_1260;
v_1261:
    goto v_1262;
v_1263:
    v_1286 = Lmember(nil, v_1287, v_1286);
    if (v_1286 == nil) goto v_1259;
    else goto v_1239;
v_1259:
    goto v_1273;
v_1269:
    v_1287 = v_1288;
    goto v_1270;
v_1271:
    v_1286 = stack[-5];
    goto v_1272;
v_1273:
    goto v_1269;
v_1270:
    goto v_1271;
v_1272:
    v_1286 = cons(v_1287, v_1286);
    env = stack[-8];
    stack[-5] = v_1286;
    goto v_1237;
v_1239:
v_1237:
    v_1286 = stack[-1];
    v_1286 = qcdr(v_1286);
    stack[-1] = v_1286;
    goto v_1204;
v_1203:
    goto v_1182;
v_1181:
    goto v_1283;
v_1279:
    v_1287 = stack[-6];
    goto v_1280;
v_1281:
    v_1286 = stack[-2];
    goto v_1282;
v_1283:
    goto v_1279;
v_1280:
    goto v_1281;
v_1282:
    {
        fn = elt(env, 3); // union
        return (*qfn2(fn))(fn, v_1287, v_1286);
    }
    return onevalue(v_1286);
}



// Code for anform

static LispObject CC_anform(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1195, v_1196;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
    v_1195 = stack[0];
    if (!consp(v_1195)) goto v_1118;
    else goto v_1119;
v_1118:
    v_1195 = qvalue(elt(env, 1)); // !*globals
    if (v_1195 == nil) goto v_1124;
    v_1195 = stack[0];
    if (v_1195 == nil) goto v_1124;
    goto v_1139;
v_1135:
    v_1196 = stack[0];
    goto v_1136;
v_1137:
    v_1195 = lisp_true;
    goto v_1138;
v_1139:
    goto v_1135;
v_1136:
    goto v_1137;
v_1138:
    if (v_1196 == v_1195) goto v_1134;
    v_1195 = stack[0];
    if (symbolp(v_1195)) goto v_1145;
    v_1195 = nil;
    goto v_1143;
v_1145:
    goto v_1154;
v_1150:
    v_1196 = stack[0];
    goto v_1151;
v_1152:
    v_1195 = qvalue(elt(env, 2)); // locls!*
    goto v_1153;
v_1154:
    goto v_1150;
v_1151:
    goto v_1152;
v_1153:
    v_1195 = Lassoc(nil, v_1196, v_1195);
    v_1195 = (v_1195 == nil ? lisp_true : nil);
    goto v_1143;
    v_1195 = nil;
v_1143:
    goto v_1132;
v_1134:
    v_1195 = nil;
    goto v_1132;
    v_1195 = nil;
v_1132:
    if (v_1195 == nil) goto v_1124;
    goto v_1171;
v_1167:
    v_1196 = stack[0];
    goto v_1168;
v_1169:
    v_1195 = elt(env, 3); // glb2rf
    goto v_1170;
v_1171:
    goto v_1167;
v_1168:
    goto v_1169;
v_1170:
    v_1195 = Lflagp(nil, v_1196, v_1195);
    env = stack[-1];
    if (v_1195 == nil) goto v_1164;
    else goto v_1165;
v_1164:
    goto v_1179;
v_1175:
    v_1195 = stack[0];
    v_1196 = ncons(v_1195);
    env = stack[-1];
    goto v_1176;
v_1177:
    v_1195 = elt(env, 3); // glb2rf
    goto v_1178;
v_1179:
    goto v_1175;
v_1176:
    goto v_1177;
v_1178:
    v_1195 = Lflag(nil, v_1196, v_1195);
    env = stack[-1];
    goto v_1188;
v_1184:
    v_1196 = stack[0];
    goto v_1185;
v_1186:
    v_1195 = qvalue(elt(env, 4)); // globs!*
    goto v_1187;
v_1188:
    goto v_1184;
v_1185:
    goto v_1186;
v_1187:
    v_1195 = cons(v_1196, v_1195);
    env = stack[-1];
    qvalue(elt(env, 4)) = v_1195; // globs!*
    goto v_1163;
v_1165:
    v_1195 = nil;
v_1163:
    goto v_1122;
v_1124:
    v_1195 = nil;
v_1122:
    goto v_1117;
v_1119:
    v_1195 = stack[0];
    {
        fn = elt(env, 5); // anform1
        return (*qfn1(fn))(fn, v_1195);
    }
    v_1195 = nil;
v_1117:
    return onevalue(v_1195);
}



// Code for maxdeg

static LispObject CC_maxdeg(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1149, v_1150;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
v_1120:
    v_1149 = stack[-1];
    if (v_1149 == nil) goto v_1123;
    else goto v_1124;
v_1123:
    v_1149 = stack[0];
    goto v_1119;
v_1124:
    goto v_1134;
v_1130:
    v_1149 = stack[-1];
    v_1149 = qcar(v_1149);
    v_1150 = qcdr(v_1149);
    goto v_1131;
v_1132:
    v_1149 = stack[0];
    v_1149 = qcdr(v_1149);
    goto v_1133;
v_1134:
    goto v_1130;
v_1131:
    goto v_1132;
v_1133:
    v_1149 = (LispObject)greaterp2(v_1150, v_1149);
    v_1149 = v_1149 ? lisp_true : nil;
    env = stack[-2];
    if (v_1149 == nil) goto v_1128;
    v_1149 = stack[-1];
    v_1149 = qcdr(v_1149);
    v_1150 = v_1149;
    v_1149 = stack[-1];
    v_1149 = qcar(v_1149);
    stack[0] = v_1149;
    v_1149 = v_1150;
    stack[-1] = v_1149;
    goto v_1120;
v_1128:
    v_1149 = stack[-1];
    v_1149 = qcdr(v_1149);
    stack[-1] = v_1149;
    goto v_1120;
    v_1149 = nil;
v_1119:
    return onevalue(v_1149);
}



// Code for praddf

static LispObject CC_praddf(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1143, v_1144;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
    goto v_1122;
v_1118:
    goto v_1128;
v_1124:
    v_1143 = stack[-1];
    v_1144 = qcar(v_1143);
    goto v_1125;
v_1126:
    v_1143 = stack[0];
    v_1143 = qcar(v_1143);
    goto v_1127;
v_1128:
    goto v_1124;
v_1125:
    goto v_1126;
v_1127:
    fn = elt(env, 1); // addf
    stack[-2] = (*qfn2(fn))(fn, v_1144, v_1143);
    env = stack[-3];
    goto v_1119;
v_1120:
    goto v_1138;
v_1134:
    v_1143 = stack[-1];
    v_1144 = qcdr(v_1143);
    goto v_1135;
v_1136:
    v_1143 = stack[0];
    v_1143 = qcdr(v_1143);
    goto v_1137;
v_1138:
    goto v_1134;
v_1135:
    goto v_1136;
v_1137:
    fn = elt(env, 1); // addf
    v_1143 = (*qfn2(fn))(fn, v_1144, v_1143);
    goto v_1121;
v_1122:
    goto v_1118;
v_1119:
    goto v_1120;
v_1121:
    {
        LispObject v_1148 = stack[-2];
        return cons(v_1148, v_1143);
    }
}



// Code for gcdf

static LispObject CC_gcdf(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1219, v_1220;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_1115;
    stack[-3] = v_1114;
// end of prologue
// Binding !*exp
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = nil; // !*exp
// Binding !*rounded
// FLUIDBIND: reloadenv=5 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*rounded
    v_1219 = qvalue(elt(env, 3)); // !*mcd
    stack[0] = v_1219;
    v_1219 = lisp_true;
    qvalue(elt(env, 1)) = v_1219; // !*exp
    v_1219 = stack[-3];
    if (!consp(v_1219)) goto v_1134;
    else goto v_1135;
v_1134:
    v_1219 = lisp_true;
    goto v_1133;
v_1135:
    v_1219 = stack[-3];
    v_1219 = qcar(v_1219);
    v_1219 = (consp(v_1219) ? nil : lisp_true);
    goto v_1133;
    v_1219 = nil;
v_1133:
    if (v_1219 == nil) goto v_1131;
    v_1219 = lisp_true;
    goto v_1129;
v_1131:
    v_1219 = stack[-2];
    if (!consp(v_1219)) goto v_1152;
    else goto v_1153;
v_1152:
    v_1219 = lisp_true;
    goto v_1151;
v_1153:
    v_1219 = stack[-2];
    v_1219 = qcar(v_1219);
    v_1219 = (consp(v_1219) ? nil : lisp_true);
    goto v_1151;
    v_1219 = nil;
v_1151:
    if (v_1219 == nil) goto v_1149;
    v_1219 = lisp_true;
    goto v_1147;
v_1149:
    v_1219 = qvalue(elt(env, 4)); // !*ezgcd
    if (v_1219 == nil) goto v_1166;
    else goto v_1167;
v_1166:
    v_1219 = lisp_true;
    goto v_1165;
v_1167:
    v_1219 = qvalue(elt(env, 5)); // dmode!*
    if (v_1219 == nil) goto v_1174;
    else goto v_1173;
v_1174:
    v_1219 = stack[-3];
    fn = elt(env, 7); // free!-powerp
    v_1219 = (*qfn1(fn))(fn, v_1219);
    env = stack[-5];
    if (v_1219 == nil) goto v_1178;
    else goto v_1177;
v_1178:
    v_1219 = stack[-2];
    fn = elt(env, 7); // free!-powerp
    v_1219 = (*qfn1(fn))(fn, v_1219);
    env = stack[-5];
v_1177:
v_1173:
    goto v_1165;
    v_1219 = nil;
v_1165:
    goto v_1147;
    v_1219 = nil;
v_1147:
    goto v_1129;
    v_1219 = nil;
v_1129:
    if (v_1219 == nil) goto v_1127;
    v_1219 = qvalue(elt(env, 6)); // !*combineexpt
    if (v_1219 == nil) goto v_1186;
    v_1219 = lisp_true;
    qvalue(elt(env, 3)) = v_1219; // !*mcd
    goto v_1184;
v_1186:
v_1184:
    goto v_1194;
v_1190:
    v_1220 = stack[-3];
    goto v_1191;
v_1192:
    v_1219 = stack[-2];
    goto v_1193;
v_1194:
    goto v_1190;
v_1191:
    goto v_1192;
v_1193:
    fn = elt(env, 8); // gcdf1
    v_1219 = (*qfn2(fn))(fn, v_1220, v_1219);
    env = stack[-5];
    goto v_1125;
v_1127:
    goto v_1204;
v_1200:
    v_1220 = stack[-3];
    goto v_1201;
v_1202:
    v_1219 = stack[-2];
    goto v_1203;
v_1204:
    goto v_1200;
v_1201:
    goto v_1202;
v_1203:
    fn = elt(env, 9); // ezgcdf
    v_1219 = (*qfn2(fn))(fn, v_1220, v_1219);
    env = stack[-5];
    goto v_1125;
    v_1219 = nil;
v_1125:
    stack[-3] = v_1219;
    v_1219 = stack[0];
    qvalue(elt(env, 3)) = v_1219; // !*mcd
    v_1219 = stack[-3];
    fn = elt(env, 10); // minusf
    v_1219 = (*qfn1(fn))(fn, v_1219);
    env = stack[-5];
    if (v_1219 == nil) goto v_1211;
    v_1219 = stack[-3];
    fn = elt(env, 11); // negf
    v_1219 = (*qfn1(fn))(fn, v_1219);
    goto v_1209;
v_1211:
    v_1219 = stack[-3];
    goto v_1209;
    v_1219 = nil;
v_1209:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_1219);
}



// Code for invsq

static LispObject CC_invsq(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1146, v_1147, v_1148;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
    v_1146 = stack[0];
    v_1146 = qcar(v_1146);
    if (v_1146 == nil) goto v_1120;
    else goto v_1121;
v_1120:
    goto v_1131;
v_1125:
    v_1148 = elt(env, 1); // poly
    goto v_1126;
v_1127:
    v_1147 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_1128;
v_1129:
    v_1146 = elt(env, 2); // "Zero divisor"
    goto v_1130;
v_1131:
    goto v_1125;
v_1126:
    goto v_1127;
v_1128:
    goto v_1129;
v_1130:
    fn = elt(env, 4); // rerror
    v_1146 = (*qfnn(fn))(fn, 3, v_1148, v_1147, v_1146);
    env = stack[-1];
    goto v_1119;
v_1121:
v_1119:
    v_1146 = stack[0];
    fn = elt(env, 5); // revpr
    v_1146 = (*qfn1(fn))(fn, v_1146);
    env = stack[-1];
    stack[0] = v_1146;
    v_1146 = qvalue(elt(env, 3)); // !*rationalize
    if (v_1146 == nil) goto v_1140;
    v_1146 = stack[0];
    fn = elt(env, 6); // gcdchk
    v_1146 = (*qfn1(fn))(fn, v_1146);
    env = stack[-1];
    stack[0] = v_1146;
    goto v_1138;
v_1140:
v_1138:
    v_1146 = stack[0];
    {
        fn = elt(env, 7); // canonsq
        return (*qfn1(fn))(fn, v_1146);
    }
    return onevalue(v_1146);
}



// Code for tmsf!*

static LispObject CC_tmsfH(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1137, v_1138;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
    v_1137 = stack[0];
    if (is_number(v_1137)) goto v_1120;
    else goto v_1119;
v_1120:
    goto v_1127;
v_1123:
    v_1137 = stack[0];
    v_1137 = Ltruncate(nil, v_1137);
    env = stack[-1];
    v_1138 = Labsval(nil, v_1137);
    env = stack[-1];
    goto v_1124;
v_1125:
    v_1137 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1126;
v_1127:
    goto v_1123;
v_1124:
    goto v_1125;
v_1126:
    if (v_1138 == v_1137) goto v_1122;
    else goto v_1119;
v_1122:
    v_1137 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1117;
v_1119:
    v_1137 = stack[0];
    {
        fn = elt(env, 1); // tmsf
        return (*qfn1(fn))(fn, v_1137);
    }
    v_1137 = nil;
v_1117:
    return onevalue(v_1137);
}



// Code for cl_smrmknowl

static LispObject CC_cl_smrmknowl(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1118, v_1119;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1118 = v_1115;
    v_1119 = v_1114;
// end of prologue
    v_1118 = nil;
    return onevalue(v_1118);
}



// Code for ibalp_varlt

static LispObject CC_ibalp_varlt(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1124, v_1125;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1124 = v_1114;
// end of prologue
    goto v_1121;
v_1117:
    v_1125 = v_1124;
    goto v_1118;
v_1119:
    v_1124 = nil;
    goto v_1120;
v_1121:
    goto v_1117;
v_1118:
    goto v_1119;
v_1120:
    {
        fn = elt(env, 1); // ibalp_varlt1
        return (*qfn2(fn))(fn, v_1125, v_1124);
    }
}



// Code for ev_tdeg

static LispObject CC_ev_tdeg(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1141, v_1142, v_1143;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1142 = v_1114;
// end of prologue
    v_1141 = (LispObject)0+TAG_FIXNUM; // 0
v_1122:
    v_1143 = v_1142;
    if (v_1143 == nil) goto v_1125;
    else goto v_1126;
v_1125:
    goto v_1121;
v_1126:
    goto v_1133;
v_1129:
    v_1143 = v_1142;
    v_1143 = qcar(v_1143);
    goto v_1130;
v_1131:
    goto v_1132;
v_1133:
    goto v_1129;
v_1130:
    goto v_1131;
v_1132:
    v_1141 = (LispObject)(intptr_t)((intptr_t)v_1143 + (intptr_t)v_1141 - TAG_FIXNUM);
    v_1142 = qcdr(v_1142);
    goto v_1122;
v_1121:
    return onevalue(v_1141);
}



// Code for ev_comp

static LispObject CC_ev_comp(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1132, v_1133;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1132 = v_1115;
    v_1133 = v_1114;
// end of prologue
    goto v_1122;
v_1118:
    stack[0] = qvalue(elt(env, 1)); // dip_sortevcomp!*
    goto v_1119;
v_1120:
    goto v_1129;
v_1125:
    goto v_1126;
v_1127:
    goto v_1128;
v_1129:
    goto v_1125;
v_1126:
    goto v_1127;
v_1128:
    v_1132 = list2(v_1133, v_1132);
    env = stack[-1];
    goto v_1121;
v_1122:
    goto v_1118;
v_1119:
    goto v_1120;
v_1121:
    {
        LispObject v_1135 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_1135, v_1132);
    }
}



// Code for fullcopy

static LispObject CC_fullcopy(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1208, v_1209;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_1114;
// end of prologue
    stack[0] = nil;
v_1119:
    v_1208 = stack[-5];
    v_1208 = Lconsp(nil, v_1208);
    env = stack[-7];
    if (v_1208 == nil) goto v_1123;
    goto v_1131;
v_1127:
    v_1208 = stack[-5];
    v_1208 = qcar(v_1208);
    v_1209 = CC_fullcopy(elt(env, 0), v_1208);
    env = stack[-7];
    goto v_1128;
v_1129:
    v_1208 = stack[0];
    goto v_1130;
v_1131:
    goto v_1127;
v_1128:
    goto v_1129;
v_1130:
    v_1208 = cons(v_1209, v_1208);
    env = stack[-7];
    stack[0] = v_1208;
    v_1208 = stack[-5];
    v_1208 = qcdr(v_1208);
    stack[-5] = v_1208;
    goto v_1119;
v_1123:
    v_1208 = stack[-5];
    v_1208 = Lsimple_vectorp(nil, v_1208);
    env = stack[-7];
    if (v_1208 == nil) goto v_1139;
    goto v_1147;
v_1143:
    stack[-6] = stack[0];
    goto v_1144;
v_1145:
    v_1208 = stack[-5];
    v_1208 = Lupbv(nil, v_1208);
    env = stack[-7];
    stack[-3] = v_1208;
    v_1208 = stack[-3];
    v_1208 = Lmkvect(nil, v_1208);
    env = stack[-7];
    stack[-4] = v_1208;
    v_1208 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_1208;
v_1161:
    goto v_1173;
v_1169:
    v_1209 = stack[-3];
    goto v_1170;
v_1171:
    v_1208 = stack[-2];
    goto v_1172;
v_1173:
    goto v_1169;
v_1170:
    goto v_1171;
v_1172:
    v_1208 = difference2(v_1209, v_1208);
    env = stack[-7];
    v_1208 = Lminusp(nil, v_1208);
    env = stack[-7];
    if (v_1208 == nil) goto v_1166;
    goto v_1160;
v_1166:
    goto v_1183;
v_1177:
    stack[-1] = stack[-4];
    goto v_1178;
v_1179:
    stack[0] = stack[-2];
    goto v_1180;
v_1181:
    goto v_1191;
v_1187:
    v_1209 = stack[-5];
    goto v_1188;
v_1189:
    v_1208 = stack[-2];
    goto v_1190;
v_1191:
    goto v_1187;
v_1188:
    goto v_1189;
v_1190:
    v_1208 = *(LispObject *)((char *)v_1209 + (CELL-TAG_VECTOR) + (((intptr_t)v_1208-TAG_FIXNUM)/(16/CELL)));
    v_1208 = CC_fullcopy(elt(env, 0), v_1208);
    env = stack[-7];
    goto v_1182;
v_1183:
    goto v_1177;
v_1178:
    goto v_1179;
v_1180:
    goto v_1181;
v_1182:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_1208;
    v_1208 = stack[-2];
    v_1208 = add1(v_1208);
    env = stack[-7];
    stack[-2] = v_1208;
    goto v_1161;
v_1160:
    v_1208 = stack[-4];
    goto v_1146;
v_1147:
    goto v_1143;
v_1144:
    goto v_1145;
v_1146:
    {
        LispObject v_1217 = stack[-6];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_1217, v_1208);
    }
v_1139:
    goto v_1205;
v_1201:
    v_1209 = stack[0];
    goto v_1202;
v_1203:
    v_1208 = stack[-5];
    goto v_1204;
v_1205:
    goto v_1201;
v_1202:
    goto v_1203;
v_1204:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_1209, v_1208);
    }
    v_1208 = nil;
    return onevalue(v_1208);
}



// Code for scprint

static LispObject CC_scprint(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1194, v_1195;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_1115;
    v_1195 = v_1114;
// end of prologue
    v_1194 = qvalue(elt(env, 1)); // !*utf8
    if (v_1194 == nil) goto v_1123;
    goto v_1130;
v_1126:
    goto v_1127;
v_1128:
    v_1194 = stack[-2];
    goto v_1129;
v_1130:
    goto v_1126;
v_1127:
    goto v_1128;
v_1129:
    {
        fn = elt(env, 3); // utf8_scprint
        return (*qfn2(fn))(fn, v_1195, v_1194);
    }
v_1123:
    v_1194 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_1194; // posn!*
    v_1194 = v_1195;
    stack[-1] = v_1194;
v_1137:
    v_1194 = stack[-1];
    if (v_1194 == nil) goto v_1141;
    else goto v_1142;
v_1141:
    goto v_1136;
v_1142:
    v_1194 = stack[-1];
    v_1194 = qcar(v_1194);
    stack[0] = v_1194;
    goto v_1156;
v_1152:
    v_1194 = stack[0];
    v_1194 = qcar(v_1194);
    v_1195 = qcdr(v_1194);
    goto v_1153;
v_1154:
    v_1194 = stack[-2];
    goto v_1155;
v_1156:
    goto v_1152;
v_1153:
    goto v_1154;
v_1155:
    if (equal(v_1195, v_1194)) goto v_1150;
    else goto v_1151;
v_1150:
    goto v_1170;
v_1166:
    goto v_1176;
v_1172:
    v_1194 = stack[0];
    v_1194 = qcar(v_1194);
    v_1194 = qcar(v_1194);
    v_1195 = qcar(v_1194);
    goto v_1173;
v_1174:
    v_1194 = qvalue(elt(env, 2)); // posn!*
    goto v_1175;
v_1176:
    goto v_1172;
v_1173:
    goto v_1174;
v_1175:
    v_1195 = difference2(v_1195, v_1194);
    env = stack[-4];
    stack[-3] = v_1195;
    goto v_1167;
v_1168:
    v_1194 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1169;
v_1170:
    goto v_1166;
v_1167:
    goto v_1168;
v_1169:
    v_1194 = (LispObject)lessp2(v_1195, v_1194);
    v_1194 = v_1194 ? lisp_true : nil;
    env = stack[-4];
    if (v_1194 == nil) goto v_1163;
    else goto v_1164;
v_1163:
    v_1194 = stack[-3];
    v_1194 = Lxtab(nil, v_1194);
    env = stack[-4];
    goto v_1162;
v_1164:
v_1162:
    v_1194 = stack[0];
    v_1194 = qcdr(v_1194);
    v_1194 = Lprinc(nil, v_1194);
    env = stack[-4];
    v_1194 = stack[0];
    v_1194 = qcar(v_1194);
    v_1194 = qcar(v_1194);
    v_1194 = qcdr(v_1194);
    qvalue(elt(env, 2)) = v_1194; // posn!*
    goto v_1149;
v_1151:
v_1149:
    v_1194 = stack[-1];
    v_1194 = qcdr(v_1194);
    stack[-1] = v_1194;
    goto v_1137;
v_1136:
    v_1194 = nil;
    return onevalue(v_1194);
}



// Code for tensopp

static LispObject CC_tensopp(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1165, v_1166, v_1167;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
// copy arguments values to proper place
    v_1167 = v_1114;
// end of prologue
    v_1165 = v_1167;
    if (symbolp(v_1165)) goto v_1122;
    v_1165 = nil;
    goto v_1120;
v_1122:
    goto v_1131;
v_1127:
    v_1165 = v_1167;
    if (!symbolp(v_1165)) v_1166 = nil;
    else { v_1166 = qfastgets(v_1165);
           if (v_1166 != nil) { v_1166 = elt(v_1166, 18); // phystype
#ifdef RECORD_GET
             if (v_1166 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_1166 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_1166 == SPID_NOPROP) v_1166 = nil; }}
#endif
    goto v_1128;
v_1129:
    v_1165 = elt(env, 1); // tensor
    goto v_1130;
v_1131:
    goto v_1127;
v_1128:
    goto v_1129;
v_1130:
    v_1165 = (v_1166 == v_1165 ? lisp_true : nil);
    goto v_1120;
    v_1165 = nil;
v_1120:
    if (v_1165 == nil) goto v_1118;
    else goto v_1117;
v_1118:
    v_1165 = v_1167;
    if (!consp(v_1165)) goto v_1139;
    goto v_1149;
v_1145:
    v_1165 = v_1167;
    v_1165 = qcar(v_1165);
    if (!symbolp(v_1165)) v_1166 = nil;
    else { v_1166 = qfastgets(v_1165);
           if (v_1166 != nil) { v_1166 = elt(v_1166, 18); // phystype
#ifdef RECORD_GET
             if (v_1166 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_1166 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_1166 == SPID_NOPROP) v_1166 = nil; }}
#endif
    goto v_1146;
v_1147:
    v_1165 = elt(env, 1); // tensor
    goto v_1148;
v_1149:
    goto v_1145;
v_1146:
    goto v_1147;
v_1148:
    if (v_1166 == v_1165) goto v_1143;
    else goto v_1144;
v_1143:
    v_1165 = v_1167;
    v_1165 = qcdr(v_1165);
    v_1165 = qcar(v_1165);
    fn = elt(env, 2); // isanindex
    v_1165 = (*qfn1(fn))(fn, v_1165);
    v_1165 = (v_1165 == nil ? lisp_true : nil);
    goto v_1142;
v_1144:
    v_1165 = nil;
    goto v_1142;
    v_1165 = nil;
v_1142:
    goto v_1137;
v_1139:
    v_1165 = nil;
    goto v_1137;
    v_1165 = nil;
v_1137:
v_1117:
    return onevalue(v_1165);
}



// Code for getroad

static LispObject CC_getroad(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1154, v_1155, v_1156, v_1157;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
// copy arguments values to proper place
    v_1156 = v_1115;
    v_1157 = v_1114;
// end of prologue
v_1119:
    v_1154 = v_1156;
    if (v_1154 == nil) goto v_1122;
    else goto v_1123;
v_1122:
    v_1154 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1118;
v_1123:
    goto v_1132;
v_1128:
    v_1154 = v_1157;
    v_1155 = qcdr(v_1154);
    goto v_1129;
v_1130:
    v_1154 = v_1156;
    v_1154 = qcar(v_1154);
    v_1154 = qcdr(v_1154);
    goto v_1131;
v_1132:
    goto v_1128;
v_1129:
    goto v_1130;
v_1131:
    if (equal(v_1155, v_1154)) goto v_1126;
    else goto v_1127;
v_1126:
    goto v_1143;
v_1139:
    v_1154 = v_1157;
    v_1154 = qcar(v_1154);
    goto v_1140;
v_1141:
    v_1155 = v_1156;
    v_1155 = qcar(v_1155);
    v_1155 = qcar(v_1155);
    goto v_1142;
v_1143:
    goto v_1139;
v_1140:
    goto v_1141;
v_1142:
    fn = elt(env, 1); // qassoc
    v_1154 = (*qfn2(fn))(fn, v_1154, v_1155);
    v_1154 = qcdr(v_1154);
    goto v_1118;
v_1127:
    v_1154 = v_1156;
    v_1154 = qcdr(v_1154);
    v_1156 = v_1154;
    goto v_1119;
    v_1154 = nil;
v_1118:
    return onevalue(v_1154);
}



// Code for readch1

static LispObject CC_readch1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1492, v_1493, v_1494;
    LispObject fn;
    argcheck(nargs, 0, "readch1");
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
    stack[0] = nil;
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    if (v_1492 == nil) goto v_1131;
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    v_1492 = qcar(v_1492);
    stack[-1] = v_1492;
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    v_1492 = qcdr(v_1492);
    qvalue(elt(env, 1)) = v_1492; // peekchar!*
    goto v_1145;
v_1141:
    v_1493 = stack[-1];
    goto v_1142;
v_1143:
    v_1492 = qvalue(elt(env, 2)); // !$eof!$
    goto v_1144;
v_1145:
    goto v_1141;
v_1142:
    goto v_1143;
v_1144:
    if (v_1493 == v_1492) goto v_1139;
    else goto v_1140;
v_1139:
    goto v_1138;
v_1140:
    v_1492 = qvalue(elt(env, 3)); // !*psl
    if (v_1492 == nil) goto v_1150;
    v_1492 = qvalue(elt(env, 4)); // !*raise
    if (v_1492 == nil) goto v_1155;
    v_1492 = stack[-1];
    fn = elt(env, 19); // red!-char!-downcase
    v_1492 = (*qfn1(fn))(fn, v_1492);
    stack[-1] = v_1492;
    goto v_1153;
v_1155:
v_1153:
    goto v_1138;
v_1150:
    v_1492 = qvalue(elt(env, 5)); // !*lower
    if (v_1492 == nil) goto v_1160;
    v_1492 = stack[-1];
    fn = elt(env, 20); // char!-downcase
    v_1492 = (*qfn1(fn))(fn, v_1492);
    stack[-1] = v_1492;
    goto v_1138;
v_1160:
    v_1492 = qvalue(elt(env, 4)); // !*raise
    if (v_1492 == nil) goto v_1165;
    v_1492 = stack[-1];
    fn = elt(env, 21); // char!-upcase
    v_1492 = (*qfn1(fn))(fn, v_1492);
    stack[-1] = v_1492;
    goto v_1138;
v_1165:
v_1138:
    v_1492 = stack[-1];
    goto v_1121;
v_1131:
v_1122:
    fn = elt(env, 22); // terminalp
    v_1492 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_1492 == nil) goto v_1172;
    else goto v_1173;
v_1172:
    v_1492 = Lreadch(nil, 0);
    env = stack[-2];
    stack[-1] = v_1492;
    goto v_1184;
v_1180:
    v_1493 = stack[-1];
    goto v_1181;
v_1182:
    v_1492 = qvalue(elt(env, 6)); // !$eol!$
    goto v_1183;
v_1184:
    goto v_1180;
v_1181:
    goto v_1182;
v_1183:
    if (v_1493 == v_1492) goto v_1178;
    else goto v_1179;
v_1178:
    v_1492 = qvalue(elt(env, 7)); // curline!*
    v_1492 = add1(v_1492);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_1492; // curline!*
    goto v_1177;
v_1179:
v_1177:
    goto v_1171;
v_1173:
    v_1492 = qvalue(elt(env, 8)); // crbuf1!*
    if (v_1492 == nil) goto v_1190;
    v_1492 = qvalue(elt(env, 8)); // crbuf1!*
    v_1492 = qcar(v_1492);
    stack[-1] = v_1492;
    v_1492 = qvalue(elt(env, 8)); // crbuf1!*
    v_1492 = qcdr(v_1492);
    qvalue(elt(env, 8)) = v_1492; // crbuf1!*
    goto v_1171;
v_1190:
    v_1492 = Lreadch(nil, 0);
    env = stack[-2];
    stack[-1] = v_1492;
    goto v_1171;
v_1171:
    goto v_1204;
v_1200:
    v_1493 = stack[-1];
    goto v_1201;
v_1202:
    v_1492 = qvalue(elt(env, 9)); // crbuf!*
    goto v_1203;
v_1204:
    goto v_1200;
v_1201:
    goto v_1202;
v_1203:
    v_1492 = cons(v_1493, v_1492);
    env = stack[-2];
    qvalue(elt(env, 9)) = v_1492; // crbuf!*
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    if (v_1492 == nil) goto v_1209;
    else goto v_1210;
v_1209:
    goto v_1220;
v_1216:
    v_1493 = stack[-1];
    goto v_1217;
v_1218:
    v_1492 = elt(env, 10); // !#
    goto v_1219;
v_1220:
    goto v_1216;
v_1217:
    goto v_1218;
v_1219:
    if (v_1493 == v_1492) goto v_1215;
    v_1492 = stack[-1];
    goto v_1121;
v_1215:
    goto v_1229;
v_1225:
    v_1493 = qvalue(elt(env, 4)); // !*raise
    goto v_1226;
v_1227:
    v_1492 = qvalue(elt(env, 5)); // !*lower
    goto v_1228;
v_1229:
    goto v_1225;
v_1226:
    goto v_1227;
v_1228:
    v_1492 = cons(v_1493, v_1492);
    env = stack[-2];
    stack[0] = v_1492;
    v_1492 = nil;
    qvalue(elt(env, 5)) = v_1492; // !*lower
    qvalue(elt(env, 4)) = v_1492; // !*raise
    goto v_1238;
v_1234:
    v_1493 = stack[-1];
    goto v_1235;
v_1236:
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    goto v_1237;
v_1238:
    goto v_1234;
v_1235:
    goto v_1236;
v_1237:
    v_1492 = cons(v_1493, v_1492);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_1492; // peekchar!*
    goto v_1122;
v_1210:
    goto v_1251;
v_1247:
    v_1493 = stack[-1];
    goto v_1248;
v_1249:
    v_1492 = qvalue(elt(env, 2)); // !$eof!$
    goto v_1250;
v_1251:
    goto v_1247;
v_1248:
    goto v_1249;
v_1250:
    if (v_1493 == v_1492) goto v_1246;
    goto v_1262;
v_1258:
    v_1492 = stack[-1];
    fn = elt(env, 23); // id2string
    v_1492 = (*qfn1(fn))(fn, v_1492);
    env = stack[-2];
    fn = elt(env, 24); // string!-length
    v_1493 = (*qfn1(fn))(fn, v_1492);
    env = stack[-2];
    goto v_1259;
v_1260:
    v_1492 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1261;
v_1262:
    goto v_1258;
v_1259:
    goto v_1260;
v_1261:
    if (v_1493 == v_1492) goto v_1256;
    else goto v_1257;
v_1256:
    v_1492 = stack[-1];
    v_1492 = Lalpha_char_p(nil, v_1492);
    env = stack[-2];
    if (v_1492 == nil) goto v_1269;
    else goto v_1268;
v_1269:
    v_1492 = stack[-1];
    v_1492 = Ldigitp(nil, v_1492);
    env = stack[-2];
v_1268:
    goto v_1255;
v_1257:
    v_1492 = nil;
    goto v_1255;
    v_1492 = nil;
v_1255:
    goto v_1244;
v_1246:
    v_1492 = nil;
    goto v_1244;
    v_1492 = nil;
v_1244:
    if (v_1492 == nil) goto v_1242;
    goto v_1285;
v_1281:
    v_1493 = stack[-1];
    goto v_1282;
v_1283:
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    goto v_1284;
v_1285:
    goto v_1281;
v_1282:
    goto v_1283;
v_1284:
    v_1492 = cons(v_1493, v_1492);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_1492; // peekchar!*
    goto v_1122;
v_1242:
    v_1492 = stack[0];
    v_1492 = qcar(v_1492);
    qvalue(elt(env, 4)) = v_1492; // !*raise
    v_1492 = stack[0];
    v_1492 = qcdr(v_1492);
    qvalue(elt(env, 5)) = v_1492; // !*lower
    goto v_1304;
v_1300:
    v_1493 = stack[-1];
    goto v_1301;
v_1302:
    v_1492 = elt(env, 11); // !;
    goto v_1303;
v_1304:
    goto v_1300;
v_1301:
    goto v_1302;
v_1303:
    if (v_1493 == v_1492) goto v_1299;
    v_1492 = lisp_true;
    goto v_1297;
v_1299:
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    v_1492 = qcdr(v_1492);
    v_1492 = (v_1492 == nil ? lisp_true : nil);
    goto v_1297;
    v_1492 = nil;
v_1297:
    if (v_1492 == nil) goto v_1295;
    goto v_1319;
v_1315:
    v_1493 = stack[-1];
    goto v_1316;
v_1317:
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    goto v_1318;
v_1319:
    goto v_1315;
v_1316:
    goto v_1317;
v_1318:
    v_1492 = cons(v_1493, v_1492);
    env = stack[-2];
    v_1492 = Lnreverse(nil, v_1492);
    env = stack[-2];
    v_1492 = qcdr(v_1492);
    qvalue(elt(env, 1)) = v_1492; // peekchar!*
    v_1492 = elt(env, 10); // !#
    goto v_1121;
v_1295:
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    v_1492 = Lreverse(nil, v_1492);
    env = stack[-2];
    v_1492 = qcdr(v_1492);
    stack[-1] = v_1492;
    fn = elt(env, 25); // list2string
    v_1492 = (*qfn1(fn))(fn, v_1492);
    env = stack[-2];
    v_1492 = Lintern(nil, v_1492);
    env = stack[-2];
    v_1493 = v_1492;
    goto v_1338;
v_1334:
    goto v_1335;
v_1336:
    v_1492 = elt(env, 12); // unicode_character
    goto v_1337;
v_1338:
    goto v_1334;
v_1335:
    goto v_1336;
v_1337:
    v_1492 = get(v_1493, v_1492);
    env = stack[-2];
    v_1493 = v_1492;
    if (v_1492 == nil) goto v_1332;
    v_1492 = nil;
    qvalue(elt(env, 1)) = v_1492; // peekchar!*
    v_1492 = lisp_true;
    qvalue(elt(env, 13)) = v_1492; // named!-character!*
    v_1492 = v_1493;
    {
        fn = elt(env, 26); // int2wideid
        return (*qfn1(fn))(fn, v_1492);
    }
v_1332:
    v_1492 = (LispObject)0+TAG_FIXNUM; // 0
    v_1494 = v_1492;
    goto v_1359;
v_1355:
    v_1493 = stack[-1];
    goto v_1356;
v_1357:
    v_1492 = elt(env, 14); // u
    goto v_1358;
v_1359:
    goto v_1355;
v_1356:
    goto v_1357;
v_1358:
    if (!consp(v_1493)) goto v_1353;
    v_1493 = qcar(v_1493);
    if (v_1493 == v_1492) goto v_1352;
    else goto v_1353;
v_1352:
    v_1492 = lisp_true;
    goto v_1351;
v_1353:
    goto v_1370;
v_1366:
    v_1493 = stack[-1];
    goto v_1367;
v_1368:
    v_1492 = elt(env, 15); // !U
    goto v_1369;
v_1370:
    goto v_1366;
v_1367:
    goto v_1368;
v_1369:
    v_1492 = Leqcar(nil, v_1493, v_1492);
    env = stack[-2];
    goto v_1351;
    v_1492 = nil;
v_1351:
    if (v_1492 == nil) goto v_1349;
    goto v_1124;
v_1349:
    goto v_1386;
v_1382:
    v_1493 = stack[-1];
    goto v_1383;
v_1384:
    v_1492 = elt(env, 16); // x
    goto v_1385;
v_1386:
    goto v_1382;
v_1383:
    goto v_1384;
v_1385:
    if (!consp(v_1493)) goto v_1380;
    v_1493 = qcar(v_1493);
    if (v_1493 == v_1492) goto v_1379;
    else goto v_1380;
v_1379:
    v_1492 = lisp_true;
    goto v_1378;
v_1380:
    goto v_1397;
v_1393:
    v_1493 = stack[-1];
    goto v_1394;
v_1395:
    v_1492 = elt(env, 17); // !X
    goto v_1396;
v_1397:
    goto v_1393;
v_1394:
    goto v_1395;
v_1396:
    v_1492 = Leqcar(nil, v_1493, v_1492);
    env = stack[-2];
    goto v_1378;
    v_1492 = nil;
v_1378:
    if (v_1492 == nil) goto v_1376;
    v_1492 = stack[-1];
    v_1492 = qcdr(v_1492);
    stack[-1] = v_1492;
    goto v_1374;
v_1376:
v_1374:
v_1123:
    v_1492 = stack[-1];
    if (v_1492 == nil) goto v_1404;
    else goto v_1405;
v_1404:
    goto v_1126;
v_1405:
    goto v_1412;
v_1408:
    v_1492 = stack[-1];
    v_1493 = qcar(v_1492);
    goto v_1409;
v_1410:
    v_1492 = elt(env, 18); // hexdigit
    goto v_1411;
v_1412:
    goto v_1408;
v_1409:
    goto v_1410;
v_1411:
    v_1492 = get(v_1493, v_1492);
    env = stack[-2];
    stack[0] = v_1492;
    v_1492 = stack[0];
    if (v_1492 == nil) goto v_1418;
    else goto v_1419;
v_1418:
    goto v_1127;
v_1419:
    goto v_1426;
v_1422:
    goto v_1432;
v_1428:
    v_1492 = (LispObject)256+TAG_FIXNUM; // 16
    goto v_1429;
v_1430:
    v_1493 = v_1494;
    goto v_1431;
v_1432:
    goto v_1428;
v_1429:
    goto v_1430;
v_1431:
    v_1493 = times2(v_1492, v_1493);
    env = stack[-2];
    goto v_1423;
v_1424:
    v_1492 = stack[0];
    goto v_1425;
v_1426:
    goto v_1422;
v_1423:
    goto v_1424;
v_1425:
    v_1492 = plus2(v_1493, v_1492);
    env = stack[-2];
    v_1494 = v_1492;
    v_1492 = stack[-1];
    v_1492 = qcdr(v_1492);
    stack[-1] = v_1492;
    goto v_1123;
v_1124:
    v_1492 = stack[-1];
    v_1492 = qcdr(v_1492);
    stack[-1] = v_1492;
v_1125:
    v_1492 = stack[-1];
    if (v_1492 == nil) goto v_1442;
    else goto v_1443;
v_1442:
    goto v_1126;
v_1443:
    v_1492 = stack[-1];
    v_1492 = qcar(v_1492);
    v_1492 = Ldigitp(nil, v_1492);
    env = stack[-2];
    if (v_1492 == nil) goto v_1447;
    else goto v_1448;
v_1447:
    goto v_1127;
v_1448:
    goto v_1457;
v_1453:
    goto v_1463;
v_1459:
    v_1492 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_1460;
v_1461:
    v_1493 = v_1494;
    goto v_1462;
v_1463:
    goto v_1459;
v_1460:
    goto v_1461;
v_1462:
    v_1494 = times2(v_1492, v_1493);
    env = stack[-2];
    goto v_1454;
v_1455:
    goto v_1471;
v_1467:
    v_1492 = stack[-1];
    v_1493 = qcar(v_1492);
    goto v_1468;
v_1469:
    v_1492 = elt(env, 18); // hexdigit
    goto v_1470;
v_1471:
    goto v_1467;
v_1468:
    goto v_1469;
v_1470:
    v_1492 = get(v_1493, v_1492);
    env = stack[-2];
    goto v_1456;
v_1457:
    goto v_1453;
v_1454:
    goto v_1455;
v_1456:
    v_1492 = plus2(v_1494, v_1492);
    env = stack[-2];
    v_1494 = v_1492;
    v_1492 = stack[-1];
    v_1492 = qcdr(v_1492);
    stack[-1] = v_1492;
    goto v_1125;
v_1126:
    v_1492 = nil;
    qvalue(elt(env, 1)) = v_1492; // peekchar!*
    v_1492 = lisp_true;
    qvalue(elt(env, 13)) = v_1492; // named!-character!*
    v_1492 = v_1494;
    {
        fn = elt(env, 26); // int2wideid
        return (*qfn1(fn))(fn, v_1492);
    }
v_1127:
    goto v_1487;
v_1483:
    v_1493 = elt(env, 11); // !;
    goto v_1484;
v_1485:
    v_1492 = qvalue(elt(env, 1)); // peekchar!*
    goto v_1486;
v_1487:
    goto v_1483;
v_1484:
    goto v_1485;
v_1486:
    v_1492 = cons(v_1493, v_1492);
    env = stack[-2];
    v_1492 = Lreverse(nil, v_1492);
    env = stack[-2];
    v_1492 = qcdr(v_1492);
    qvalue(elt(env, 1)) = v_1492; // peekchar!*
    v_1492 = elt(env, 10); // !#
v_1121:
    return onevalue(v_1492);
}



// Code for mo!=degcomp

static LispObject CC_moMdegcomp(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1156, v_1157, v_1158, v_1159;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1157 = v_1115;
    v_1158 = v_1114;
// end of prologue
v_1119:
    v_1156 = v_1158;
    if (v_1156 == nil) goto v_1122;
    else goto v_1123;
v_1122:
    v_1156 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1118;
v_1123:
    goto v_1132;
v_1128:
    v_1156 = v_1158;
    v_1159 = qcar(v_1156);
    goto v_1129;
v_1130:
    v_1156 = v_1157;
    v_1156 = qcar(v_1156);
    goto v_1131;
v_1132:
    goto v_1128;
v_1129:
    goto v_1130;
v_1131:
    if (equal(v_1159, v_1156)) goto v_1126;
    else goto v_1127;
v_1126:
    v_1156 = v_1158;
    v_1156 = qcdr(v_1156);
    v_1158 = v_1156;
    v_1156 = v_1157;
    v_1156 = qcdr(v_1156);
    v_1157 = v_1156;
    goto v_1119;
v_1127:
    goto v_1147;
v_1143:
    v_1156 = v_1158;
    v_1156 = qcar(v_1156);
    goto v_1144;
v_1145:
    v_1157 = qcar(v_1157);
    goto v_1146;
v_1147:
    goto v_1143;
v_1144:
    goto v_1145;
v_1146:
    if (((intptr_t)(v_1156)) < ((intptr_t)(v_1157))) goto v_1141;
    else goto v_1142;
v_1141:
    v_1156 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_1118;
v_1142:
    v_1156 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1118;
    v_1156 = nil;
v_1118:
    return onevalue(v_1156);
}



// Code for dquot

static LispObject CC_dquot(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1164, v_1165, v_1166;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
    stack[-2] = nil;
v_1121:
    goto v_1128;
v_1124:
    v_1164 = stack[-1];
    v_1165 = qcar(v_1164);
    goto v_1125;
v_1126:
    v_1164 = stack[0];
    v_1164 = qcar(v_1164);
    goto v_1127;
v_1128:
    goto v_1124;
v_1125:
    goto v_1126;
v_1127:
    v_1164 = difference2(v_1165, v_1164);
    env = stack[-3];
    v_1166 = v_1164;
    goto v_1141;
v_1137:
    v_1165 = v_1166;
    goto v_1138;
v_1139:
    v_1164 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1140;
v_1141:
    goto v_1137;
v_1138:
    goto v_1139;
v_1140:
    if (((intptr_t)(v_1165)) < ((intptr_t)(v_1164))) goto v_1135;
    else goto v_1136;
v_1135:
    v_1164 = nil;
    goto v_1120;
v_1136:
    goto v_1150;
v_1146:
    v_1165 = v_1166;
    goto v_1147;
v_1148:
    v_1164 = stack[-2];
    goto v_1149;
v_1150:
    goto v_1146;
v_1147:
    goto v_1148;
v_1149:
    v_1164 = cons(v_1165, v_1164);
    env = stack[-3];
    stack[-2] = v_1164;
    v_1164 = stack[0];
    v_1164 = qcdr(v_1164);
    stack[0] = v_1164;
    v_1164 = stack[-1];
    v_1164 = qcdr(v_1164);
    stack[-1] = v_1164;
    v_1164 = stack[0];
    if (v_1164 == nil) goto v_1160;
    goto v_1121;
v_1160:
    v_1164 = stack[-2];
        return Lnreverse(nil, v_1164);
v_1120:
    return onevalue(v_1164);
}



// Code for pv_add

static LispObject CC_pv_add(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1259, v_1260, v_1261;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
    v_1259 = stack[-1];
    if (v_1259 == nil) goto v_1119;
    else goto v_1120;
v_1119:
    v_1259 = stack[0];
    goto v_1118;
v_1120:
    v_1259 = stack[0];
    if (v_1259 == nil) goto v_1123;
    else goto v_1124;
v_1123:
    v_1259 = stack[-1];
    goto v_1118;
v_1124:
    stack[-2] = nil;
v_1135:
    v_1259 = stack[-1];
    if (v_1259 == nil) goto v_1140;
    else goto v_1139;
v_1140:
    v_1259 = stack[0];
    if (v_1259 == nil) goto v_1142;
    else goto v_1139;
v_1142:
    goto v_1134;
v_1139:
    v_1259 = stack[-1];
    if (v_1259 == nil) goto v_1148;
    v_1259 = stack[0];
    if (v_1259 == nil) goto v_1148;
    goto v_1159;
v_1155:
    v_1259 = stack[-1];
    v_1259 = qcar(v_1259);
    v_1260 = qcdr(v_1259);
    goto v_1156;
v_1157:
    v_1259 = stack[0];
    v_1259 = qcar(v_1259);
    v_1259 = qcdr(v_1259);
    goto v_1158;
v_1159:
    goto v_1155;
v_1156:
    goto v_1157;
v_1158:
    if (equal(v_1260, v_1259)) goto v_1154;
    else goto v_1148;
v_1154:
    goto v_1171;
v_1167:
    v_1259 = stack[-1];
    v_1259 = qcar(v_1259);
    v_1260 = qcar(v_1259);
    goto v_1168;
v_1169:
    v_1259 = stack[0];
    v_1259 = qcar(v_1259);
    v_1259 = qcar(v_1259);
    goto v_1170;
v_1171:
    goto v_1167;
v_1168:
    goto v_1169;
v_1170:
    v_1259 = plus2(v_1260, v_1259);
    env = stack[-3];
    v_1261 = v_1259;
    goto v_1186;
v_1182:
    v_1260 = v_1261;
    goto v_1183;
v_1184:
    v_1259 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1185;
v_1186:
    goto v_1182;
v_1183:
    goto v_1184;
v_1185:
    if (v_1260 == v_1259) goto v_1181;
    goto v_1196;
v_1190:
    goto v_1191;
v_1192:
    v_1259 = stack[-1];
    v_1259 = qcar(v_1259);
    v_1260 = qcdr(v_1259);
    goto v_1193;
v_1194:
    v_1259 = stack[-2];
    goto v_1195;
v_1196:
    goto v_1190;
v_1191:
    goto v_1192;
v_1193:
    goto v_1194;
v_1195:
    v_1259 = acons(v_1261, v_1260, v_1259);
    env = stack[-3];
    stack[-2] = v_1259;
    goto v_1179;
v_1181:
v_1179:
    v_1259 = stack[-1];
    v_1259 = qcdr(v_1259);
    stack[-1] = v_1259;
    v_1259 = stack[0];
    v_1259 = qcdr(v_1259);
    stack[0] = v_1259;
    goto v_1146;
v_1148:
    v_1259 = stack[-1];
    if (v_1259 == nil) goto v_1209;
    v_1259 = stack[0];
    if (v_1259 == nil) goto v_1212;
    else goto v_1209;
v_1212:
    goto v_1207;
v_1209:
    v_1259 = stack[-1];
    if (v_1259 == nil) goto v_1214;
    v_1259 = stack[0];
    if (v_1259 == nil) goto v_1214;
    goto v_1226;
v_1222:
    v_1259 = stack[-1];
    v_1259 = qcar(v_1259);
    v_1260 = qcdr(v_1259);
    goto v_1223;
v_1224:
    v_1259 = stack[0];
    v_1259 = qcar(v_1259);
    v_1259 = qcdr(v_1259);
    goto v_1225;
v_1226:
    goto v_1222;
v_1223:
    goto v_1224;
v_1225:
    v_1259 = (LispObject)greaterp2(v_1260, v_1259);
    v_1259 = v_1259 ? lisp_true : nil;
    env = stack[-3];
    if (v_1259 == nil) goto v_1214;
    goto v_1207;
v_1214:
    goto v_1208;
v_1207:
    goto v_1238;
v_1234:
    v_1259 = stack[-1];
    v_1260 = qcar(v_1259);
    goto v_1235;
v_1236:
    v_1259 = stack[-2];
    goto v_1237;
v_1238:
    goto v_1234;
v_1235:
    goto v_1236;
v_1237:
    v_1259 = cons(v_1260, v_1259);
    env = stack[-3];
    stack[-2] = v_1259;
    v_1259 = stack[-1];
    v_1259 = qcdr(v_1259);
    stack[-1] = v_1259;
    goto v_1146;
v_1208:
    goto v_1251;
v_1247:
    v_1259 = stack[0];
    v_1260 = qcar(v_1259);
    goto v_1248;
v_1249:
    v_1259 = stack[-2];
    goto v_1250;
v_1251:
    goto v_1247;
v_1248:
    goto v_1249;
v_1250:
    v_1259 = cons(v_1260, v_1259);
    env = stack[-3];
    stack[-2] = v_1259;
    v_1259 = stack[0];
    v_1259 = qcdr(v_1259);
    stack[0] = v_1259;
    goto v_1146;
v_1146:
    goto v_1135;
v_1134:
    v_1259 = stack[-2];
        return Lnreverse(nil, v_1259);
    goto v_1118;
    v_1259 = nil;
v_1118:
    return onevalue(v_1259);
}



// Code for rntimes!:

static LispObject CC_rntimesT(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1147, v_1148;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
    goto v_1122;
v_1118:
    goto v_1128;
v_1124:
    v_1147 = stack[-1];
    v_1147 = qcdr(v_1147);
    v_1148 = qcar(v_1147);
    goto v_1125;
v_1126:
    v_1147 = stack[0];
    v_1147 = qcdr(v_1147);
    v_1147 = qcar(v_1147);
    goto v_1127;
v_1128:
    goto v_1124;
v_1125:
    goto v_1126;
v_1127:
    stack[-2] = times2(v_1148, v_1147);
    env = stack[-3];
    goto v_1119;
v_1120:
    goto v_1140;
v_1136:
    v_1147 = stack[-1];
    v_1147 = qcdr(v_1147);
    v_1148 = qcdr(v_1147);
    goto v_1137;
v_1138:
    v_1147 = stack[0];
    v_1147 = qcdr(v_1147);
    v_1147 = qcdr(v_1147);
    goto v_1139;
v_1140:
    goto v_1136;
v_1137:
    goto v_1138;
v_1139:
    v_1147 = times2(v_1148, v_1147);
    env = stack[-3];
    goto v_1121;
v_1122:
    goto v_1118;
v_1119:
    goto v_1120;
v_1121:
    {
        LispObject v_1152 = stack[-2];
        fn = elt(env, 1); // mkrn
        return (*qfn2(fn))(fn, v_1152, v_1147);
    }
}



// Code for frvarsof

static LispObject CC_frvarsof(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1175, v_1176, v_1177, v_1178;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1176 = v_1115;
    v_1177 = v_1114;
// end of prologue
v_1120:
    goto v_1129;
v_1125:
    v_1178 = v_1177;
    goto v_1126;
v_1127:
    v_1175 = qvalue(elt(env, 1)); // frlis!*
    goto v_1128;
v_1129:
    goto v_1125;
v_1126:
    goto v_1127;
v_1128:
    v_1175 = Lmemq(nil, v_1178, v_1175);
    if (v_1175 == nil) goto v_1124;
    goto v_1141;
v_1137:
    v_1178 = v_1177;
    goto v_1138;
v_1139:
    v_1175 = v_1176;
    goto v_1140;
v_1141:
    goto v_1137;
v_1138:
    goto v_1139;
v_1140:
    v_1175 = Lmemq(nil, v_1178, v_1175);
    if (v_1175 == nil) goto v_1136;
    v_1175 = v_1176;
    goto v_1119;
v_1136:
    goto v_1153;
v_1149:
    stack[0] = v_1176;
    goto v_1150;
v_1151:
    v_1175 = v_1177;
    v_1175 = ncons(v_1175);
    goto v_1152;
v_1153:
    goto v_1149;
v_1150:
    goto v_1151;
v_1152:
    {
        LispObject v_1180 = stack[0];
        return Lappend(nil, v_1180, v_1175);
    }
    goto v_1122;
v_1124:
    v_1175 = v_1177;
    if (!consp(v_1175)) goto v_1157;
    else goto v_1158;
v_1157:
    v_1175 = v_1176;
    goto v_1119;
v_1158:
    v_1175 = v_1177;
    v_1175 = qcdr(v_1175);
    stack[0] = v_1175;
    goto v_1170;
v_1166:
    v_1175 = v_1177;
    v_1175 = qcar(v_1175);
    goto v_1167;
v_1168:
    goto v_1169;
v_1170:
    goto v_1166;
v_1167:
    goto v_1168;
v_1169:
    v_1175 = CC_frvarsof(elt(env, 0), v_1175, v_1176);
    env = stack[-1];
    v_1176 = v_1175;
    v_1175 = stack[0];
    v_1177 = v_1175;
    goto v_1120;
v_1122:
    v_1175 = nil;
v_1119:
    return onevalue(v_1175);
}



// Code for orderactions

static LispObject CC_orderactions(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1186, v_1187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1115;
    stack[-1] = v_1114;
// end of prologue
    goto v_1126;
v_1122:
    v_1186 = stack[-1];
    v_1187 = qcar(v_1186);
    goto v_1123;
v_1124:
    v_1186 = stack[0];
    v_1186 = qcar(v_1186);
    goto v_1125;
v_1126:
    goto v_1122;
v_1123:
    goto v_1124;
v_1125:
    v_1186 = (LispObject)lessp2(v_1187, v_1186);
    v_1186 = v_1186 ? lisp_true : nil;
    env = stack[-2];
    if (v_1186 == nil) goto v_1120;
    v_1186 = lisp_true;
    goto v_1118;
v_1120:
    goto v_1139;
v_1135:
    v_1186 = stack[-1];
    v_1187 = qcar(v_1186);
    goto v_1136;
v_1137:
    v_1186 = stack[0];
    v_1186 = qcar(v_1186);
    goto v_1138;
v_1139:
    goto v_1135;
v_1136:
    goto v_1137;
v_1138:
    v_1186 = (LispObject)greaterp2(v_1187, v_1186);
    v_1186 = v_1186 ? lisp_true : nil;
    env = stack[-2];
    if (v_1186 == nil) goto v_1133;
    v_1186 = nil;
    goto v_1118;
v_1133:
    goto v_1151;
v_1147:
    v_1186 = stack[-1];
    v_1186 = qcdr(v_1186);
    v_1186 = qcar(v_1186);
    v_1187 = qcar(v_1186);
    goto v_1148;
v_1149:
    v_1186 = stack[0];
    v_1186 = qcdr(v_1186);
    v_1186 = qcar(v_1186);
    v_1186 = qcar(v_1186);
    goto v_1150;
v_1151:
    goto v_1147;
v_1148:
    goto v_1149;
v_1150:
    if (equal(v_1187, v_1186)) goto v_1145;
    else goto v_1146;
v_1145:
    goto v_1165;
v_1161:
    v_1186 = stack[-1];
    v_1187 = qcdr(v_1186);
    goto v_1162;
v_1163:
    v_1186 = stack[0];
    v_1186 = qcdr(v_1186);
    goto v_1164;
v_1165:
    goto v_1161;
v_1162:
    goto v_1163;
v_1164:
    {
        fn = elt(env, 2); // ordp
        return (*qfn2(fn))(fn, v_1187, v_1186);
    }
v_1146:
    goto v_1176;
v_1172:
    v_1186 = stack[-1];
    v_1186 = qcdr(v_1186);
    v_1186 = qcar(v_1186);
    v_1186 = qcar(v_1186);
    goto v_1173;
v_1174:
    v_1187 = elt(env, 1); // shift
    goto v_1175;
v_1176:
    goto v_1172;
v_1173:
    goto v_1174;
v_1175:
    if (v_1186 == v_1187) goto v_1170;
    else goto v_1171;
v_1170:
    v_1186 = lisp_true;
    goto v_1118;
v_1171:
    v_1186 = nil;
    goto v_1118;
    v_1186 = nil;
v_1118:
    return onevalue(v_1186);
}



// Code for ofsf_clnegrel

static LispObject CC_ofsf_clnegrel(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1127, v_1128;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1127 = v_1115;
    v_1128 = v_1114;
// end of prologue
    if (v_1127 == nil) goto v_1120;
    v_1127 = v_1128;
    goto v_1118;
v_1120:
    v_1127 = v_1128;
    {
        fn = elt(env, 1); // ofsf_lnegrel
        return (*qfn1(fn))(fn, v_1127);
    }
    v_1127 = nil;
v_1118:
    return onevalue(v_1127);
}



// Code for remove!-free!-vars

static LispObject CC_removeKfreeKvars(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1293, v_1294, v_1295;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1114;
// end of prologue
    v_1293 = stack[0];
    if (!consp(v_1293)) goto v_1122;
    else goto v_1123;
v_1122:
    v_1293 = stack[0];
    goto v_1121;
v_1123:
    goto v_1132;
v_1128:
    v_1293 = stack[0];
    v_1294 = qcar(v_1293);
    goto v_1129;
v_1130:
    v_1293 = elt(env, 1); // !~
    goto v_1131;
v_1132:
    goto v_1128;
v_1129:
    goto v_1130;
v_1131:
    if (v_1294 == v_1293) goto v_1126;
    else goto v_1127;
v_1126:
    v_1293 = qvalue(elt(env, 2)); // !*!*noremove!*!*
    if (v_1293 == nil) goto v_1139;
    goto v_1150;
v_1146:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1294 = qcar(v_1293);
    goto v_1147;
v_1148:
    v_1293 = qvalue(elt(env, 3)); // frasc!*
    goto v_1149;
v_1150:
    goto v_1146;
v_1147:
    goto v_1148;
v_1149:
    v_1293 = Latsoc(nil, v_1294, v_1293);
    v_1295 = v_1293;
    if (v_1293 == nil) goto v_1145;
    else goto v_1143;
v_1145:
    goto v_1166;
v_1162:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1294 = qcar(v_1293);
    goto v_1163;
v_1164:
    v_1293 = elt(env, 1); // !~
    goto v_1165;
v_1166:
    goto v_1162;
v_1163:
    goto v_1164;
v_1165:
    if (!consp(v_1294)) goto v_1160;
    v_1294 = qcar(v_1294);
    if (v_1294 == v_1293) goto v_1159;
    else goto v_1160;
v_1159:
    goto v_1175;
v_1171:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    goto v_1172;
v_1173:
    v_1294 = qvalue(elt(env, 3)); // frasc!*
    goto v_1174;
v_1175:
    goto v_1171;
v_1172:
    goto v_1173;
v_1174:
    v_1293 = Latsoc(nil, v_1293, v_1294);
    v_1295 = v_1293;
    goto v_1158;
v_1160:
    v_1293 = nil;
    goto v_1158;
    v_1293 = nil;
v_1158:
    if (v_1293 == nil) goto v_1156;
    else goto v_1143;
v_1156:
    goto v_1144;
v_1143:
    v_1293 = v_1295;
    v_1293 = qcdr(v_1293);
    goto v_1142;
v_1144:
    v_1293 = stack[0];
    goto v_1142;
    v_1293 = nil;
v_1142:
    goto v_1137;
v_1139:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    if (!consp(v_1293)) goto v_1191;
    else goto v_1192;
v_1191:
    goto v_1200;
v_1196:
    v_1294 = stack[0];
    goto v_1197;
v_1198:
    v_1293 = elt(env, 4); // "free variable"
    goto v_1199;
v_1200:
    goto v_1196;
v_1197:
    goto v_1198;
v_1199:
    {
        fn = elt(env, 6); // typerr
        return (*qfn2(fn))(fn, v_1294, v_1293);
    }
v_1192:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    stack[-1] = v_1293;
    if (is_number(v_1293)) goto v_1203;
    else goto v_1204;
v_1203:
    v_1293 = stack[0];
    goto v_1137;
v_1204:
    v_1293 = stack[-1];
    if (symbolp(v_1293)) goto v_1209;
    goto v_1223;
v_1219:
    v_1294 = stack[-1];
    goto v_1220;
v_1221:
    v_1293 = elt(env, 1); // !~
    goto v_1222;
v_1223:
    goto v_1219;
v_1220:
    goto v_1221;
v_1222:
    if (!consp(v_1294)) goto v_1217;
    v_1294 = qcar(v_1294);
    if (v_1294 == v_1293) goto v_1216;
    else goto v_1217;
v_1216:
    v_1293 = stack[-1];
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    stack[-1] = v_1293;
    goto v_1215;
v_1217:
    v_1293 = nil;
    goto v_1215;
    v_1293 = nil;
v_1215:
    if (v_1293 == nil) goto v_1213;
    else goto v_1209;
v_1213:
    goto v_1210;
v_1209:
    goto v_1237;
v_1233:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    fn = elt(env, 7); // get!-free!-form
    v_1293 = (*qfn1(fn))(fn, v_1293);
    env = stack[-2];
    v_1294 = ncons(v_1293);
    env = stack[-2];
    goto v_1234;
v_1235:
    v_1293 = qvalue(elt(env, 5)); // frlis!*
    goto v_1236;
v_1237:
    goto v_1233;
v_1234:
    goto v_1235;
v_1236:
    fn = elt(env, 8); // union
    v_1293 = (*qfn2(fn))(fn, v_1294, v_1293);
    env = stack[-2];
    qvalue(elt(env, 5)) = v_1293; // frlis!*
    v_1293 = stack[-1];
    goto v_1137;
v_1210:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    v_1293 = qcar(v_1293);
    if (symbolp(v_1293)) goto v_1245;
    else goto v_1246;
v_1245:
    goto v_1256;
v_1252:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    v_1293 = qcar(v_1293);
    fn = elt(env, 7); // get!-free!-form
    v_1293 = (*qfn1(fn))(fn, v_1293);
    env = stack[-2];
    v_1294 = ncons(v_1293);
    env = stack[-2];
    goto v_1253;
v_1254:
    v_1293 = qvalue(elt(env, 5)); // frlis!*
    goto v_1255;
v_1256:
    goto v_1252;
v_1253:
    goto v_1254;
v_1255:
    fn = elt(env, 8); // union
    v_1293 = (*qfn2(fn))(fn, v_1294, v_1293);
    env = stack[-2];
    qvalue(elt(env, 5)) = v_1293; // frlis!*
    goto v_1269;
v_1265:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    stack[-1] = qcar(v_1293);
    goto v_1266;
v_1267:
    v_1293 = stack[0];
    v_1293 = qcdr(v_1293);
    v_1293 = qcar(v_1293);
    v_1293 = qcdr(v_1293);
    fn = elt(env, 9); // remove!-free!-vars!-l
    v_1293 = (*qfn1(fn))(fn, v_1293);
    goto v_1268;
v_1269:
    goto v_1265;
v_1266:
    goto v_1267;
v_1268:
    {
        LispObject v_1298 = stack[-1];
        return cons(v_1298, v_1293);
    }
v_1246:
    goto v_1286;
v_1282:
    v_1294 = stack[0];
    goto v_1283;
v_1284:
    v_1293 = elt(env, 4); // "free variable"
    goto v_1285;
v_1286:
    goto v_1282;
v_1283:
    goto v_1284;
v_1285:
    {
        fn = elt(env, 6); // typerr
        return (*qfn2(fn))(fn, v_1294, v_1293);
    }
    v_1293 = nil;
v_1137:
    goto v_1121;
v_1127:
    v_1293 = stack[0];
    {
        fn = elt(env, 9); // remove!-free!-vars!-l
        return (*qfn1(fn))(fn, v_1293);
    }
    v_1293 = nil;
v_1121:
    return onevalue(v_1293);
}



// Code for stable!-sortip

static LispObject CC_stableKsortip(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1335, v_1336, v_1337;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_1115;
    stack[-3] = v_1114;
// end of prologue
    v_1335 = stack[-3];
    if (v_1335 == nil) goto v_1124;
    else goto v_1125;
v_1124:
    v_1335 = stack[-3];
    goto v_1121;
v_1125:
    v_1335 = stack[-3];
    stack[-4] = v_1335;
    v_1335 = stack[-3];
    v_1335 = qcdr(v_1335);
    stack[-1] = v_1335;
    v_1335 = stack[-1];
    if (v_1335 == nil) goto v_1133;
    else goto v_1134;
v_1133:
    v_1335 = stack[-3];
    goto v_1121;
v_1134:
    v_1335 = stack[-1];
    v_1335 = qcdr(v_1335);
    stack[-3] = v_1335;
    v_1335 = stack[-3];
    if (v_1335 == nil) goto v_1141;
    else goto v_1142;
v_1141:
    goto v_1155;
v_1149:
    v_1337 = stack[-2];
    goto v_1150;
v_1151:
    v_1335 = stack[-1];
    v_1336 = qcar(v_1335);
    goto v_1152;
v_1153:
    v_1335 = stack[-4];
    v_1335 = qcar(v_1335);
    goto v_1154;
v_1155:
    goto v_1149;
v_1150:
    goto v_1151;
v_1152:
    goto v_1153;
v_1154:
    v_1335 = Lapply2(nil, 3, v_1337, v_1336, v_1335);
    env = stack[-5];
    if (v_1335 == nil) goto v_1147;
    v_1335 = stack[-4];
    v_1335 = qcar(v_1335);
    stack[-3] = v_1335;
    goto v_1168;
v_1164:
    v_1336 = stack[-4];
    goto v_1165;
v_1166:
    v_1335 = stack[-1];
    v_1335 = qcar(v_1335);
    goto v_1167;
v_1168:
    goto v_1164;
v_1165:
    goto v_1166;
v_1167:
    v_1335 = Lrplaca(nil, v_1336, v_1335);
    env = stack[-5];
    goto v_1177;
v_1173:
    v_1336 = stack[-1];
    goto v_1174;
v_1175:
    v_1335 = stack[-3];
    goto v_1176;
v_1177:
    goto v_1173;
v_1174:
    goto v_1175;
v_1176:
    v_1335 = Lrplaca(nil, v_1336, v_1335);
    goto v_1145;
v_1147:
v_1145:
    v_1335 = stack[-4];
    goto v_1121;
v_1142:
    v_1335 = stack[-4];
    stack[-3] = v_1335;
v_1184:
    v_1335 = stack[-1];
    if (v_1335 == nil) goto v_1187;
    goto v_1199;
v_1193:
    v_1337 = stack[-2];
    goto v_1194;
v_1195:
    v_1335 = stack[-1];
    v_1336 = qcar(v_1335);
    goto v_1196;
v_1197:
    v_1335 = stack[-3];
    v_1335 = qcar(v_1335);
    goto v_1198;
v_1199:
    goto v_1193;
v_1194:
    goto v_1195;
v_1196:
    goto v_1197;
v_1198:
    v_1335 = Lapply2(nil, 3, v_1337, v_1336, v_1335);
    env = stack[-5];
    if (v_1335 == nil) goto v_1191;
    else goto v_1187;
v_1191:
    goto v_1188;
v_1187:
    goto v_1183;
v_1188:
    v_1335 = stack[-1];
    stack[-3] = v_1335;
    v_1335 = stack[-1];
    v_1335 = qcdr(v_1335);
    stack[-1] = v_1335;
    goto v_1184;
v_1183:
    v_1335 = stack[-1];
    if (v_1335 == nil) goto v_1211;
    else goto v_1212;
v_1211:
    v_1335 = stack[-4];
    goto v_1121;
v_1212:
    v_1335 = stack[-4];
    stack[-1] = v_1335;
    v_1335 = stack[-1];
    v_1335 = qcdr(v_1335);
    v_1335 = qcdr(v_1335);
    stack[-3] = v_1335;
v_1221:
    v_1335 = stack[-3];
    if (v_1335 == nil) goto v_1224;
    v_1335 = stack[-3];
    v_1335 = qcdr(v_1335);
    if (v_1335 == nil) goto v_1224;
    goto v_1225;
v_1224:
    goto v_1220;
v_1225:
    v_1335 = stack[-1];
    v_1335 = qcdr(v_1335);
    stack[-1] = v_1335;
    v_1335 = stack[-3];
    v_1335 = qcdr(v_1335);
    v_1335 = qcdr(v_1335);
    stack[-3] = v_1335;
    goto v_1221;
v_1220:
    v_1335 = stack[-1];
    stack[-3] = v_1335;
    v_1335 = stack[-1];
    v_1335 = qcdr(v_1335);
    stack[-1] = v_1335;
    goto v_1245;
v_1241:
    v_1336 = stack[-3];
    goto v_1242;
v_1243:
    v_1335 = nil;
    goto v_1244;
v_1245:
    goto v_1241;
v_1242:
    goto v_1243;
v_1244:
    v_1335 = Lrplacd(nil, v_1336, v_1335);
    env = stack[-5];
    goto v_1253;
v_1249:
    v_1336 = stack[-4];
    goto v_1250;
v_1251:
    v_1335 = stack[-2];
    goto v_1252;
v_1253:
    goto v_1249;
v_1250:
    goto v_1251;
v_1252:
    v_1335 = CC_stableKsortip(elt(env, 0), v_1336, v_1335);
    env = stack[-5];
    stack[-4] = v_1335;
    goto v_1261;
v_1257:
    v_1336 = stack[-1];
    goto v_1258;
v_1259:
    v_1335 = stack[-2];
    goto v_1260;
v_1261:
    goto v_1257;
v_1258:
    goto v_1259;
v_1260:
    v_1335 = CC_stableKsortip(elt(env, 0), v_1336, v_1335);
    env = stack[-5];
    stack[-1] = v_1335;
    v_1335 = nil;
    v_1335 = ncons(v_1335);
    env = stack[-5];
    stack[0] = v_1335;
    stack[-3] = v_1335;
v_1268:
    v_1335 = stack[-4];
    if (v_1335 == nil) goto v_1271;
    v_1335 = stack[-1];
    if (v_1335 == nil) goto v_1271;
    goto v_1272;
v_1271:
    goto v_1267;
v_1272:
    goto v_1289;
v_1283:
    v_1337 = stack[-2];
    goto v_1284;
v_1285:
    v_1335 = stack[-1];
    v_1336 = qcar(v_1335);
    goto v_1286;
v_1287:
    v_1335 = stack[-4];
    v_1335 = qcar(v_1335);
    goto v_1288;
v_1289:
    goto v_1283;
v_1284:
    goto v_1285;
v_1286:
    goto v_1287;
v_1288:
    v_1335 = Lapply2(nil, 3, v_1337, v_1336, v_1335);
    env = stack[-5];
    if (v_1335 == nil) goto v_1281;
    goto v_1300;
v_1296:
    v_1336 = stack[0];
    goto v_1297;
v_1298:
    v_1335 = stack[-1];
    goto v_1299;
v_1300:
    goto v_1296;
v_1297:
    goto v_1298;
v_1299:
    v_1335 = Lrplacd(nil, v_1336, v_1335);
    env = stack[-5];
    v_1335 = stack[-1];
    stack[0] = v_1335;
    v_1335 = stack[-1];
    v_1335 = qcdr(v_1335);
    stack[-1] = v_1335;
    goto v_1279;
v_1281:
    goto v_1313;
v_1309:
    v_1336 = stack[0];
    goto v_1310;
v_1311:
    v_1335 = stack[-4];
    goto v_1312;
v_1313:
    goto v_1309;
v_1310:
    goto v_1311;
v_1312:
    v_1335 = Lrplacd(nil, v_1336, v_1335);
    env = stack[-5];
    v_1335 = stack[-4];
    stack[0] = v_1335;
    v_1335 = stack[-4];
    v_1335 = qcdr(v_1335);
    stack[-4] = v_1335;
    goto v_1279;
v_1279:
    goto v_1268;
v_1267:
    v_1335 = stack[-4];
    if (v_1335 == nil) goto v_1322;
    v_1335 = stack[-4];
    stack[-1] = v_1335;
    goto v_1320;
v_1322:
v_1320:
    goto v_1330;
v_1326:
    v_1336 = stack[0];
    goto v_1327;
v_1328:
    v_1335 = stack[-1];
    goto v_1329;
v_1330:
    goto v_1326;
v_1327:
    goto v_1328;
v_1329:
    v_1335 = Lrplacd(nil, v_1336, v_1335);
    v_1335 = stack[-3];
    v_1335 = qcdr(v_1335);
v_1121:
    return onevalue(v_1335);
}



// Code for resimp

static LispObject CC_resimp(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1120, v_1121;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1121 = v_1114;
// end of prologue
    v_1120 = nil;
// Binding varstack!*
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_1120; // varstack!*
    v_1120 = v_1121;
    fn = elt(env, 2); // resimp1
    v_1120 = (*qfn1(fn))(fn, v_1120);
    ;}  // end of a binding scope
    return onevalue(v_1120);
}



// Code for tayexp!-plus2

static LispObject CC_tayexpKplus2(LispObject env,
                         LispObject v_1114, LispObject v_1115)
{
    env = qenv(env);
    LispObject v_1197, v_1198, v_1199;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1115,v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1114,v_1115);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1115;
    v_1198 = v_1114;
// end of prologue
    v_1197 = v_1198;
    if (!consp(v_1197)) goto v_1123;
    else goto v_1124;
v_1123:
    v_1197 = stack[0];
    v_1197 = (consp(v_1197) ? nil : lisp_true);
    goto v_1122;
v_1124:
    v_1197 = nil;
    goto v_1122;
    v_1197 = nil;
v_1122:
    if (v_1197 == nil) goto v_1120;
    goto v_1136;
v_1132:
    goto v_1133;
v_1134:
    v_1197 = stack[0];
    goto v_1135;
v_1136:
    goto v_1132;
v_1133:
    goto v_1134;
v_1135:
    return plus2(v_1198, v_1197);
v_1120:
    v_1197 = v_1198;
    if (!consp(v_1197)) goto v_1143;
    else goto v_1144;
v_1143:
    goto v_1151;
v_1147:
    v_1197 = v_1198;
    fn = elt(env, 1); // !*i2rn
    v_1198 = (*qfn1(fn))(fn, v_1197);
    env = stack[-2];
    goto v_1148;
v_1149:
    v_1197 = stack[0];
    goto v_1150;
v_1151:
    goto v_1147;
v_1148:
    goto v_1149;
v_1150:
    fn = elt(env, 2); // rnplus!:
    v_1197 = (*qfn2(fn))(fn, v_1198, v_1197);
    goto v_1142;
v_1144:
    v_1197 = stack[0];
    if (!consp(v_1197)) goto v_1155;
    else goto v_1156;
v_1155:
    goto v_1163;
v_1159:
    stack[-1] = v_1198;
    goto v_1160;
v_1161:
    v_1197 = stack[0];
    fn = elt(env, 1); // !*i2rn
    v_1197 = (*qfn1(fn))(fn, v_1197);
    env = stack[-2];
    goto v_1162;
v_1163:
    goto v_1159;
v_1160:
    goto v_1161;
v_1162:
    fn = elt(env, 2); // rnplus!:
    v_1197 = (*qfn2(fn))(fn, stack[-1], v_1197);
    goto v_1142;
v_1156:
    goto v_1174;
v_1170:
    goto v_1171;
v_1172:
    v_1197 = stack[0];
    goto v_1173;
v_1174:
    goto v_1170;
v_1171:
    goto v_1172;
v_1173:
    fn = elt(env, 2); // rnplus!:
    v_1197 = (*qfn2(fn))(fn, v_1198, v_1197);
    goto v_1142;
    v_1197 = nil;
v_1142:
    v_1199 = v_1197;
    goto v_1186;
v_1182:
    v_1197 = v_1199;
    v_1197 = qcdr(v_1197);
    v_1198 = qcdr(v_1197);
    goto v_1183;
v_1184:
    v_1197 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1185;
v_1186:
    goto v_1182;
v_1183:
    goto v_1184;
v_1185:
    if (v_1198 == v_1197) goto v_1180;
    else goto v_1181;
v_1180:
    v_1197 = v_1199;
    v_1197 = qcdr(v_1197);
    v_1197 = qcar(v_1197);
    goto v_1179;
v_1181:
    v_1197 = v_1199;
    goto v_1179;
    v_1197 = nil;
v_1179:
    goto v_1118;
    v_1197 = nil;
v_1118:
    return onevalue(v_1197);
}



// Code for subs2

static LispObject CC_subs2(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1195, v_1196, v_1197;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1114);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1114);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_1196 = v_1114;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v_1195 = qvalue(elt(env, 1)); // subfg!*
    if (v_1195 == nil) goto v_1124;
    else goto v_1125;
v_1124:
    v_1195 = v_1196;
    goto v_1121;
v_1125:
    v_1195 = qvalue(elt(env, 2)); // !*sub2
    if (v_1195 == nil) goto v_1130;
    else goto v_1128;
v_1130:
    v_1195 = qvalue(elt(env, 3)); // powlis1!*
    if (v_1195 == nil) goto v_1132;
    else goto v_1128;
v_1132:
    goto v_1129;
v_1128:
    v_1195 = v_1196;
    fn = elt(env, 7); // subs2q
    v_1195 = (*qfn1(fn))(fn, v_1195);
    env = stack[-4];
    v_1196 = v_1195;
    goto v_1123;
v_1129:
v_1123:
    v_1195 = v_1196;
    fn = elt(env, 8); // exptchksq
    v_1195 = (*qfn1(fn))(fn, v_1195);
    env = stack[-4];
    v_1196 = v_1195;
    v_1195 = elt(env, 4); // slash
    if (!symbolp(v_1195)) v_1195 = nil;
    else { v_1195 = qfastgets(v_1195);
           if (v_1195 != nil) { v_1195 = elt(v_1195, 9); // opmtch
#ifdef RECORD_GET
             if (v_1195 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_1195 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_1195 == SPID_NOPROP) v_1195 = nil; }}
#endif
    stack[0] = v_1195;
    v_1195 = qvalue(elt(env, 5)); // !*match
    if (v_1195 == nil) goto v_1148;
    else goto v_1147;
v_1148:
    v_1195 = stack[0];
    if (v_1195 == nil) goto v_1150;
    else goto v_1147;
v_1150:
    v_1195 = lisp_true;
    goto v_1145;
v_1147:
    v_1195 = v_1196;
    v_1195 = qcar(v_1195);
    v_1195 = (v_1195 == nil ? lisp_true : nil);
    goto v_1145;
    v_1195 = nil;
v_1145:
    if (v_1195 == nil) goto v_1143;
    v_1195 = v_1196;
    goto v_1121;
v_1143:
    v_1195 = qvalue(elt(env, 6)); // !*exp
    if (v_1195 == nil) goto v_1159;
    else goto v_1160;
v_1159:
    v_1195 = lisp_true;
    stack[-3] = v_1195;
    v_1195 = lisp_true;
    qvalue(elt(env, 6)) = v_1195; // !*exp
    v_1195 = v_1196;
    stack[-2] = v_1195;
    v_1195 = v_1196;
    fn = elt(env, 9); // resimp
    v_1195 = (*qfn1(fn))(fn, v_1195);
    env = stack[-4];
    v_1196 = v_1195;
    stack[-1] = v_1195;
    goto v_1141;
v_1160:
v_1141:
    v_1195 = v_1196;
    fn = elt(env, 10); // subs3q
    v_1195 = (*qfn1(fn))(fn, v_1195);
    env = stack[-4];
    v_1196 = v_1195;
    v_1195 = stack[-3];
    if (v_1195 == nil) goto v_1172;
    v_1195 = nil;
    qvalue(elt(env, 6)) = v_1195; // !*exp
    goto v_1183;
v_1179:
    v_1197 = v_1196;
    goto v_1180;
v_1181:
    v_1195 = stack[-1];
    goto v_1182;
v_1183:
    goto v_1179;
v_1180:
    goto v_1181;
v_1182:
    if (equal(v_1197, v_1195)) goto v_1177;
    else goto v_1178;
v_1177:
    v_1195 = stack[-2];
    v_1196 = v_1195;
    goto v_1176;
v_1178:
v_1176:
    goto v_1170;
v_1172:
v_1170:
    v_1195 = stack[0];
    if (v_1195 == nil) goto v_1190;
    v_1195 = v_1196;
    fn = elt(env, 11); // subs4q
    v_1195 = (*qfn1(fn))(fn, v_1195);
    v_1196 = v_1195;
    goto v_1188;
v_1190:
v_1188:
    v_1195 = v_1196;
v_1121:
    return onevalue(v_1195);
}



// Code for mri_floorp

static LispObject CC_mri_floorp(LispObject env,
                         LispObject v_1114)
{
    env = qenv(env);
    LispObject v_1143, v_1144, v_1145;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1144 = v_1114;
// end of prologue
v_1113:
    v_1143 = v_1144;
    if (v_1143 == nil) goto v_1118;
    else goto v_1119;
v_1118:
    v_1143 = nil;
    goto v_1117;
v_1119:
    goto v_1133;
v_1129:
    v_1143 = v_1144;
    v_1145 = qcar(v_1143);
    goto v_1130;
v_1131:
    v_1143 = elt(env, 1); // floor
    goto v_1132;
v_1133:
    goto v_1129;
v_1130:
    goto v_1131;
v_1132:
    if (!consp(v_1145)) goto v_1127;
    v_1145 = qcar(v_1145);
    if (v_1145 == v_1143) goto v_1126;
    else goto v_1127;
v_1126:
    v_1143 = lisp_true;
    goto v_1125;
v_1127:
    v_1143 = v_1144;
    v_1143 = qcdr(v_1143);
    v_1144 = v_1143;
    goto v_1113;
    v_1143 = nil;
v_1125:
    goto v_1117;
    v_1143 = nil;
v_1117:
    return onevalue(v_1143);
}



setup_type const u04_setup[] =
{
    {"lex",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex},
    {"replus1",                 CC_replus1,     TOO_MANY_1,    WRONG_NO_1},
    {"*q2a1",                   TOO_FEW_2,      CC_Hq2a1,      WRONG_NO_2},
    {"peel",                    CC_peel,        TOO_MANY_1,    WRONG_NO_1},
    {"mo_ecart",                CC_mo_ecart,    TOO_MANY_1,    WRONG_NO_1},
    {"pv_sort",                 CC_pv_sort,     TOO_MANY_1,    WRONG_NO_1},
    {"flatten-sorted-tree",     TOO_FEW_2,      CC_flattenKsortedKtree,WRONG_NO_2},
    {"ofsf_posdefp",            CC_ofsf_posdefp,TOO_MANY_1,    WRONG_NO_1},
    {"reordop",                 TOO_FEW_2,      CC_reordop,    WRONG_NO_2},
    {"free-powerp",             CC_freeKpowerp, TOO_MANY_1,    WRONG_NO_1},
    {"retimes",                 CC_retimes,     TOO_MANY_1,    WRONG_NO_1},
    {"mkwedge",                 CC_mkwedge,     TOO_MANY_1,    WRONG_NO_1},
    {"idlistp",                 CC_idlistp,     TOO_MANY_1,    WRONG_NO_1},
    {"qassoc",                  TOO_FEW_2,      CC_qassoc,     WRONG_NO_2},
    {"negf",                    CC_negf,        TOO_MANY_1,    WRONG_NO_1},
    {"formlis",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formlis},
    {"nonzero-length",          CC_nonzeroKlength,TOO_MANY_1,  WRONG_NO_1},
    {"pv_renorm",               CC_pv_renorm,   TOO_MANY_1,    WRONG_NO_1},
    {"general-modular-number",  CC_generalKmodularKnumber,TOO_MANY_1,WRONG_NO_1},
    {"bfzerop:",                CC_bfzeropT,    TOO_MANY_1,    WRONG_NO_1},
    {"ordopcar",                TOO_FEW_2,      CC_ordopcar,   WRONG_NO_2},
    {"checkargcount",           TOO_FEW_2,      CC_checkargcount,WRONG_NO_2},
    {"treesizep1",              TOO_FEW_2,      CC_treesizep1, WRONG_NO_2},
    {"listeval",                TOO_FEW_2,      CC_listeval,   WRONG_NO_2},
    {"quotf-fail",              TOO_FEW_2,      CC_quotfKfail, WRONG_NO_2},
    {"get+col+nr",              CC_getLcolLnr,  TOO_MANY_1,    WRONG_NO_1},
    {"cl_simplat",              TOO_FEW_2,      CC_cl_simplat, WRONG_NO_2},
    {"pasf_dec",                CC_pasf_dec,    TOO_MANY_1,    WRONG_NO_1},
    {"vevcompless?",            TOO_FEW_2,      CC_vevcomplessW,WRONG_NO_2},
    {"fprin2",                  CC_fprin2,      TOO_MANY_1,    WRONG_NO_1},
    {"widestring2list",         CC_widestring2list,TOO_MANY_1, WRONG_NO_1},
    {"mo=sum",                  TOO_FEW_2,      CC_moMsum,     WRONG_NO_2},
    {"lcm",                     TOO_FEW_2,      CC_lcm,        WRONG_NO_2},
    {"arzerop:",                CC_arzeropT,    TOO_MANY_1,    WRONG_NO_1},
    {"simpexpon",               CC_simpexpon,   TOO_MANY_1,    WRONG_NO_1},
    {"lalr_lr0_closure",        CC_lalr_lr0_closure,TOO_MANY_1,WRONG_NO_1},
    {"anform",                  CC_anform,      TOO_MANY_1,    WRONG_NO_1},
    {"maxdeg",                  TOO_FEW_2,      CC_maxdeg,     WRONG_NO_2},
    {"praddf",                  TOO_FEW_2,      CC_praddf,     WRONG_NO_2},
    {"gcdf",                    TOO_FEW_2,      CC_gcdf,       WRONG_NO_2},
    {"invsq",                   CC_invsq,       TOO_MANY_1,    WRONG_NO_1},
    {"tmsf*",                   CC_tmsfH,       TOO_MANY_1,    WRONG_NO_1},
    {"cl_smrmknowl",            TOO_FEW_2,      CC_cl_smrmknowl,WRONG_NO_2},
    {"ibalp_varlt",             CC_ibalp_varlt, TOO_MANY_1,    WRONG_NO_1},
    {"ev_tdeg",                 CC_ev_tdeg,     TOO_MANY_1,    WRONG_NO_1},
    {"ev_comp",                 TOO_FEW_2,      CC_ev_comp,    WRONG_NO_2},
    {"fullcopy",                CC_fullcopy,    TOO_MANY_1,    WRONG_NO_1},
    {"scprint",                 TOO_FEW_2,      CC_scprint,    WRONG_NO_2},
    {"tensopp",                 CC_tensopp,     TOO_MANY_1,    WRONG_NO_1},
    {"getroad",                 TOO_FEW_2,      CC_getroad,    WRONG_NO_2},
    {"readch1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_readch1},
    {"mo=degcomp",              TOO_FEW_2,      CC_moMdegcomp, WRONG_NO_2},
    {"dquot",                   TOO_FEW_2,      CC_dquot,      WRONG_NO_2},
    {"pv_add",                  TOO_FEW_2,      CC_pv_add,     WRONG_NO_2},
    {"rntimes:",                TOO_FEW_2,      CC_rntimesT,   WRONG_NO_2},
    {"frvarsof",                TOO_FEW_2,      CC_frvarsof,   WRONG_NO_2},
    {"orderactions",            TOO_FEW_2,      CC_orderactions,WRONG_NO_2},
    {"ofsf_clnegrel",           TOO_FEW_2,      CC_ofsf_clnegrel,WRONG_NO_2},
    {"remove-free-vars",        CC_removeKfreeKvars,TOO_MANY_1,WRONG_NO_1},
    {"stable-sortip",           TOO_FEW_2,      CC_stableKsortip,WRONG_NO_2},
    {"resimp",                  CC_resimp,      TOO_MANY_1,    WRONG_NO_1},
    {"tayexp-plus2",            TOO_FEW_2,      CC_tayexpKplus2,WRONG_NO_2},
    {"subs2",                   CC_subs2,       TOO_MANY_1,    WRONG_NO_1},
    {"mri_floorp",              CC_mri_floorp,  TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u04", (two_args *)"163246 5523744 7402947", 0}
};

// end of generated code
