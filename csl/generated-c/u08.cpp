
// $destdir/u08.c        Machine generated C code

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



// Code for letmtr3

static LispObject CC_letmtr3(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3977, v_3978, v_3979, v_3980;
    LispObject fn;
    LispObject v_3592, v_3591, v_3590, v_3589;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "letmtr3");
    va_start(aa, nargs);
    v_3589 = va_arg(aa, LispObject);
    v_3590 = va_arg(aa, LispObject);
    v_3591 = va_arg(aa, LispObject);
    v_3592 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_3592,v_3591,v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_3589,v_3590,v_3591,v_3592);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_3592;
    stack[-3] = v_3591;
    stack[-4] = v_3590;
    stack[-5] = v_3589;
// end of prologue
    stack[-6] = nil;
    v_3977 = stack[-5];
    v_3977 = qcdr(v_3977);
    v_3977 = qcdr(v_3977);
    if (v_3977 == nil) goto v_3607;
    else goto v_3608;
v_3607:
    goto v_3621;
v_3617:
    v_3978 = stack[-3];
    goto v_3618;
v_3619:
    v_3977 = elt(env, 1); // sparsemat
    goto v_3620;
v_3621:
    goto v_3617;
v_3618:
    goto v_3619;
v_3620:
    if (!consp(v_3978)) goto v_3614;
    v_3978 = qcar(v_3978);
    if (v_3978 == v_3977) goto v_3615;
v_3614:
    goto v_3631;
v_3625:
    stack[-1] = elt(env, 2); // matrix
    goto v_3626;
v_3627:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_3628;
v_3629:
    goto v_3641;
v_3635:
    v_3979 = elt(env, 3); // "Matrix"
    goto v_3636;
v_3637:
    v_3977 = stack[-5];
    v_3978 = qcar(v_3977);
    goto v_3638;
v_3639:
    v_3977 = elt(env, 4); // "not set"
    goto v_3640;
v_3641:
    goto v_3635;
v_3636:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    v_3977 = list3(v_3979, v_3978, v_3977);
    env = stack[-7];
    goto v_3630;
v_3631:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    goto v_3629;
v_3630:
    fn = elt(env, 7); // rerror
    v_3977 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_3977);
    goto v_3613;
v_3615:
    v_3977 = stack[-5];
    v_3977 = qcdr(v_3977);
    fn = elt(env, 8); // revlis
    v_3977 = (*qfn1(fn))(fn, v_3977);
    env = stack[-7];
    stack[-6] = v_3977;
    fn = elt(env, 9); // numlis
    v_3977 = (*qfn1(fn))(fn, v_3977);
    env = stack[-7];
    if (v_3977 == nil) goto v_3650;
    else goto v_3651;
v_3650:
    v_3977 = lisp_true;
    goto v_3649;
v_3651:
    goto v_3664;
v_3660:
    v_3977 = stack[-6];
    v_3978 = Llength(nil, v_3977);
    env = stack[-7];
    goto v_3661;
v_3662:
    v_3977 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3663;
v_3664:
    goto v_3660;
v_3661:
    goto v_3662;
v_3663:
    v_3977 = Lneq(nil, v_3978, v_3977);
    env = stack[-7];
    goto v_3649;
    v_3977 = nil;
v_3649:
    if (v_3977 == nil) goto v_3647;
    goto v_3673;
v_3669:
    v_3978 = stack[-5];
    goto v_3670;
v_3671:
    v_3977 = elt(env, 5); // hold
    goto v_3672;
v_3673:
    goto v_3669;
v_3670:
    goto v_3671;
v_3672:
    {
        fn = elt(env, 10); // errpri2
        return (*qfn2(fn))(fn, v_3978, v_3977);
    }
v_3647:
v_3613:
    goto v_3682;
v_3676:
    v_3977 = stack[-3];
    v_3977 = qcdr(v_3977);
    v_3979 = qcar(v_3977);
    goto v_3677;
v_3678:
    v_3977 = stack[-5];
    v_3977 = qcdr(v_3977);
    v_3978 = qcar(v_3977);
    goto v_3679;
v_3680:
    v_3977 = stack[-4];
    goto v_3681;
v_3682:
    goto v_3676;
v_3677:
    goto v_3678;
v_3679:
    goto v_3680;
v_3681:
    *(LispObject *)((char *)v_3979 + (CELL-TAG_VECTOR) + (((intptr_t)v_3978-TAG_FIXNUM)/(16/CELL))) = v_3977;
    goto v_3606;
v_3608:
    goto v_3702;
v_3698:
    v_3978 = stack[-3];
    goto v_3699;
v_3700:
    v_3977 = elt(env, 1); // sparsemat
    goto v_3701;
v_3702:
    goto v_3698;
v_3699:
    goto v_3700;
v_3701:
    if (!consp(v_3978)) goto v_3695;
    v_3978 = qcar(v_3978);
    if (v_3978 == v_3977) goto v_3696;
v_3695:
    goto v_3712;
v_3706:
    stack[-1] = elt(env, 2); // matrix
    goto v_3707;
v_3708:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_3709;
v_3710:
    goto v_3722;
v_3716:
    v_3979 = elt(env, 3); // "Matrix"
    goto v_3717;
v_3718:
    v_3977 = stack[-5];
    v_3978 = qcar(v_3977);
    goto v_3719;
v_3720:
    v_3977 = elt(env, 4); // "not set"
    goto v_3721;
v_3722:
    goto v_3716;
v_3717:
    goto v_3718;
v_3719:
    goto v_3720;
v_3721:
    v_3977 = list3(v_3979, v_3978, v_3977);
    env = stack[-7];
    goto v_3711;
v_3712:
    goto v_3706;
v_3707:
    goto v_3708;
v_3709:
    goto v_3710;
v_3711:
    fn = elt(env, 7); // rerror
    v_3977 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_3977);
    env = stack[-7];
    goto v_3694;
v_3696:
    v_3977 = stack[-5];
    v_3977 = qcdr(v_3977);
    fn = elt(env, 8); // revlis
    v_3977 = (*qfn1(fn))(fn, v_3977);
    env = stack[-7];
    stack[-6] = v_3977;
    fn = elt(env, 9); // numlis
    v_3977 = (*qfn1(fn))(fn, v_3977);
    env = stack[-7];
    if (v_3977 == nil) goto v_3731;
    else goto v_3732;
v_3731:
    v_3977 = lisp_true;
    goto v_3730;
v_3732:
    goto v_3745;
v_3741:
    v_3977 = stack[-6];
    v_3978 = Llength(nil, v_3977);
    env = stack[-7];
    goto v_3742;
v_3743:
    v_3977 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3744;
v_3745:
    goto v_3741;
v_3742:
    goto v_3743;
v_3744:
    v_3977 = Lneq(nil, v_3978, v_3977);
    env = stack[-7];
    goto v_3730;
    v_3977 = nil;
v_3730:
    if (v_3977 == nil) goto v_3728;
    goto v_3754;
v_3750:
    v_3978 = stack[-5];
    goto v_3751;
v_3752:
    v_3977 = elt(env, 5); // hold
    goto v_3753;
v_3754:
    goto v_3750;
v_3751:
    goto v_3752;
v_3753:
    {
        fn = elt(env, 10); // errpri2
        return (*qfn2(fn))(fn, v_3978, v_3977);
    }
v_3728:
v_3694:
    goto v_3761;
v_3757:
    v_3977 = stack[-3];
    v_3977 = qcdr(v_3977);
    v_3978 = qcar(v_3977);
    goto v_3758;
v_3759:
    v_3977 = stack[-6];
    v_3977 = qcar(v_3977);
    goto v_3760;
v_3761:
    goto v_3757;
v_3758:
    goto v_3759;
v_3760:
    v_3977 = *(LispObject *)((char *)v_3978 + (CELL-TAG_VECTOR) + (((intptr_t)v_3977-TAG_FIXNUM)/(16/CELL)));
    v_3980 = v_3977;
    v_3977 = v_3980;
    if (v_3977 == nil) goto v_3770;
    else goto v_3771;
v_3770:
    goto v_3785;
v_3781:
    v_3978 = stack[-4];
    goto v_3782;
v_3783:
    v_3977 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3784;
v_3785:
    goto v_3781;
v_3782:
    goto v_3783;
v_3784:
    if (v_3978 == v_3977) goto v_3779;
    else goto v_3780;
v_3779:
    goto v_3792;
v_3788:
    v_3978 = stack[-2];
    goto v_3789;
v_3790:
    v_3977 = elt(env, 6); // cx
    goto v_3791;
v_3792:
    goto v_3788;
v_3789:
    goto v_3790;
v_3791:
    v_3977 = (v_3978 == v_3977 ? lisp_true : nil);
    v_3977 = (v_3977 == nil ? lisp_true : nil);
    goto v_3778;
v_3780:
    v_3977 = nil;
    goto v_3778;
    v_3977 = nil;
v_3778:
    if (v_3977 == nil) goto v_3776;
    goto v_3774;
v_3776:
    goto v_3809;
v_3803:
    v_3977 = stack[-3];
    v_3977 = qcdr(v_3977);
    stack[-2] = qcar(v_3977);
    goto v_3804;
v_3805:
    v_3977 = stack[-6];
    stack[-1] = qcar(v_3977);
    goto v_3806;
v_3807:
    goto v_3820;
v_3816:
    v_3977 = nil;
    stack[0] = ncons(v_3977);
    env = stack[-7];
    goto v_3817;
v_3818:
    goto v_3828;
v_3824:
    v_3977 = stack[-6];
    v_3977 = qcdr(v_3977);
    v_3978 = qcar(v_3977);
    goto v_3825;
v_3826:
    v_3977 = stack[-4];
    goto v_3827;
v_3828:
    goto v_3824;
v_3825:
    goto v_3826;
v_3827:
    v_3977 = cons(v_3978, v_3977);
    env = stack[-7];
    goto v_3819;
v_3820:
    goto v_3816;
v_3817:
    goto v_3818;
v_3819:
    v_3977 = list2(stack[0], v_3977);
    goto v_3808;
v_3809:
    goto v_3803;
v_3804:
    goto v_3805;
v_3806:
    goto v_3807;
v_3808:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-1]-TAG_FIXNUM)/(16/CELL))) = v_3977;
    goto v_3774;
v_3774:
    goto v_3769;
v_3771:
    goto v_3840;
v_3836:
    v_3977 = stack[-6];
    v_3977 = qcdr(v_3977);
    v_3978 = qcar(v_3977);
    goto v_3837;
v_3838:
    v_3977 = v_3980;
    goto v_3839;
v_3840:
    goto v_3836;
v_3837:
    goto v_3838;
v_3839:
    v_3977 = Latsoc(nil, v_3978, v_3977);
    v_3979 = v_3977;
    v_3977 = v_3979;
    if (v_3977 == nil) goto v_3848;
    else goto v_3849;
v_3848:
    goto v_3863;
v_3859:
    v_3978 = stack[-4];
    goto v_3860;
v_3861:
    v_3977 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3862;
v_3863:
    goto v_3859;
v_3860:
    goto v_3861;
v_3862:
    if (v_3978 == v_3977) goto v_3857;
    else goto v_3858;
v_3857:
    goto v_3870;
v_3866:
    v_3978 = stack[-2];
    goto v_3867;
v_3868:
    v_3977 = elt(env, 6); // cx
    goto v_3869;
v_3870:
    goto v_3866;
v_3867:
    goto v_3868;
v_3869:
    v_3977 = (v_3978 == v_3977 ? lisp_true : nil);
    v_3977 = (v_3977 == nil ? lisp_true : nil);
    goto v_3856;
v_3858:
    v_3977 = nil;
    goto v_3856;
    v_3977 = nil;
v_3856:
    if (v_3977 == nil) goto v_3854;
    goto v_3852;
v_3854:
    goto v_3888;
v_3882:
    v_3977 = stack[-6];
    v_3977 = qcdr(v_3977);
    v_3978 = qcar(v_3977);
    goto v_3883;
v_3884:
    v_3979 = v_3980;
    goto v_3885;
v_3886:
    v_3977 = stack[-4];
    goto v_3887;
v_3888:
    goto v_3882;
v_3883:
    goto v_3884;
v_3885:
    goto v_3886;
v_3887:
    fn = elt(env, 11); // sortcolelem
    v_3977 = (*qfnn(fn))(fn, 3, v_3978, v_3979, v_3977);
    goto v_3852;
v_3852:
    goto v_3847;
v_3849:
    goto v_3909;
v_3905:
    v_3978 = stack[-4];
    goto v_3906;
v_3907:
    v_3977 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3908;
v_3909:
    goto v_3905;
v_3906:
    goto v_3907;
v_3908:
    if (v_3978 == v_3977) goto v_3903;
    else goto v_3904;
v_3903:
    goto v_3916;
v_3912:
    v_3978 = stack[-2];
    goto v_3913;
v_3914:
    v_3977 = elt(env, 6); // cx
    goto v_3915;
v_3916:
    goto v_3912;
v_3913:
    goto v_3914;
v_3915:
    v_3977 = (v_3978 == v_3977 ? lisp_true : nil);
    v_3977 = (v_3977 == nil ? lisp_true : nil);
    goto v_3902;
v_3904:
    v_3977 = nil;
    goto v_3902;
    v_3977 = nil;
v_3902:
    if (v_3977 == nil) goto v_3900;
    v_3977 = v_3980;
    v_3977 = qcdr(v_3977);
    v_3977 = qcdr(v_3977);
    if (v_3977 == nil) goto v_3926;
    else goto v_3927;
v_3926:
    goto v_3937;
v_3931:
    v_3977 = stack[-3];
    v_3977 = qcdr(v_3977);
    v_3979 = qcar(v_3977);
    goto v_3932;
v_3933:
    v_3977 = stack[-6];
    v_3978 = qcar(v_3977);
    goto v_3934;
v_3935:
    v_3977 = nil;
    goto v_3936;
v_3937:
    goto v_3931;
v_3932:
    goto v_3933;
v_3934:
    goto v_3935;
v_3936:
    *(LispObject *)((char *)v_3979 + (CELL-TAG_VECTOR) + (((intptr_t)v_3978-TAG_FIXNUM)/(16/CELL))) = v_3977;
    goto v_3925;
v_3927:
    goto v_3952;
v_3948:
    stack[0] = v_3980;
    goto v_3949;
v_3950:
    goto v_3959;
v_3955:
    v_3977 = v_3979;
    goto v_3956;
v_3957:
    v_3978 = v_3980;
    goto v_3958;
v_3959:
    goto v_3955;
v_3956:
    goto v_3957;
v_3958:
    v_3977 = Ldelete(nil, v_3977, v_3978);
    env = stack[-7];
    v_3977 = qcdr(v_3977);
    goto v_3951;
v_3952:
    goto v_3948;
v_3949:
    goto v_3950;
v_3951:
    v_3977 = Lrplacd(nil, stack[0], v_3977);
    goto v_3925;
v_3925:
    goto v_3898;
v_3900:
    goto v_3971;
v_3967:
    v_3978 = v_3979;
    goto v_3968;
v_3969:
    v_3977 = stack[-4];
    goto v_3970;
v_3971:
    goto v_3967;
v_3968:
    goto v_3969;
v_3970:
    v_3977 = Lrplacd(nil, v_3978, v_3977);
    goto v_3898;
v_3898:
    goto v_3847;
v_3847:
    goto v_3769;
v_3769:
    goto v_3606;
v_3606:
    v_3977 = nil;
    return onevalue(v_3977);
}



// Code for bound

static LispObject CC_bound(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3610, v_3611;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3610 = v_3589;
// end of prologue
    fn = elt(env, 2); // binding
    v_3610 = (*qfn1(fn))(fn, v_3610);
    env = stack[0];
    v_3611 = v_3610;
    v_3610 = v_3611;
    if (v_3610 == nil) goto v_3596;
    else goto v_3597;
v_3596:
    v_3610 = nil;
    goto v_3595;
v_3597:
    goto v_3607;
v_3603:
    v_3610 = v_3611;
    goto v_3604;
v_3605:
    v_3611 = elt(env, 1); // unbound
    goto v_3606;
v_3607:
    goto v_3603;
v_3604:
    goto v_3605;
v_3606:
        return Lneq(nil, v_3610, v_3611);
    v_3610 = nil;
v_3595:
    return onevalue(v_3610);
}



// Code for bcsum

static LispObject CC_bcsum(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3631, v_3632, v_3633;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3590;
    stack[-1] = v_3589;
// end of prologue
    v_3631 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_3631 == nil) goto v_3595;
    goto v_3603;
v_3599:
    v_3632 = stack[-1];
    goto v_3600;
v_3601:
    v_3631 = stack[0];
    goto v_3602;
v_3603:
    goto v_3599;
v_3600:
    goto v_3601;
v_3602:
    v_3631 = plus2(v_3632, v_3631);
    env = stack[-2];
    {
        fn = elt(env, 3); // bcfi
        return (*qfn1(fn))(fn, v_3631);
    }
v_3595:
    goto v_3618;
v_3612:
    v_3633 = stack[-1];
    goto v_3613;
v_3614:
    v_3632 = stack[0];
    goto v_3615;
v_3616:
    v_3631 = elt(env, 2); // plus2
    goto v_3617;
v_3618:
    goto v_3612;
v_3613:
    goto v_3614;
v_3615:
    goto v_3616;
v_3617:
    fn = elt(env, 4); // bcint2op
    v_3631 = (*qfnn(fn))(fn, 3, v_3633, v_3632, v_3631);
    env = stack[-2];
    if (v_3631 == nil) goto v_3610;
    else goto v_3609;
v_3610:
    goto v_3628;
v_3624:
    v_3632 = stack[-1];
    goto v_3625;
v_3626:
    v_3631 = stack[0];
    goto v_3627;
v_3628:
    goto v_3624;
v_3625:
    goto v_3626;
v_3627:
    fn = elt(env, 5); // addsq
    v_3631 = (*qfn2(fn))(fn, v_3632, v_3631);
    env = stack[-2];
    {
        fn = elt(env, 6); // bccheckz
        return (*qfn1(fn))(fn, v_3631);
    }
v_3609:
    goto v_3593;
    v_3631 = nil;
v_3593:
    return onevalue(v_3631);
}



// Code for vecopp

static LispObject CC_vecopp(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3640, v_3641, v_3642;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
// copy arguments values to proper place
    v_3642 = v_3589;
// end of prologue
    v_3640 = v_3642;
    if (symbolp(v_3640)) goto v_3597;
    v_3640 = nil;
    goto v_3595;
v_3597:
    goto v_3606;
v_3602:
    v_3640 = v_3642;
    if (!symbolp(v_3640)) v_3641 = nil;
    else { v_3641 = qfastgets(v_3640);
           if (v_3641 != nil) { v_3641 = elt(v_3641, 18); // phystype
#ifdef RECORD_GET
             if (v_3641 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_3641 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_3641 == SPID_NOPROP) v_3641 = nil; }}
#endif
    goto v_3603;
v_3604:
    v_3640 = elt(env, 1); // vector
    goto v_3605;
v_3606:
    goto v_3602;
v_3603:
    goto v_3604;
v_3605:
    v_3640 = (v_3641 == v_3640 ? lisp_true : nil);
    goto v_3595;
    v_3640 = nil;
v_3595:
    if (v_3640 == nil) goto v_3593;
    else goto v_3592;
v_3593:
    v_3640 = v_3642;
    if (!consp(v_3640)) goto v_3614;
    goto v_3624;
v_3620:
    v_3640 = v_3642;
    v_3640 = qcar(v_3640);
    if (!symbolp(v_3640)) v_3641 = nil;
    else { v_3641 = qfastgets(v_3640);
           if (v_3641 != nil) { v_3641 = elt(v_3641, 18); // phystype
#ifdef RECORD_GET
             if (v_3641 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_3641 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_3641 == SPID_NOPROP) v_3641 = nil; }}
#endif
    goto v_3621;
v_3622:
    v_3640 = elt(env, 1); // vector
    goto v_3623;
v_3624:
    goto v_3620;
v_3621:
    goto v_3622;
v_3623:
    if (v_3641 == v_3640) goto v_3618;
    else goto v_3619;
v_3618:
    v_3640 = v_3642;
    v_3640 = qcdr(v_3640);
    v_3640 = qcar(v_3640);
    fn = elt(env, 2); // isanindex
    v_3640 = (*qfn1(fn))(fn, v_3640);
    v_3640 = (v_3640 == nil ? lisp_true : nil);
    goto v_3617;
v_3619:
    v_3640 = nil;
    goto v_3617;
    v_3640 = nil;
v_3617:
    goto v_3612;
v_3614:
    v_3640 = nil;
    goto v_3612;
    v_3640 = nil;
v_3612:
v_3592:
    return onevalue(v_3640);
}



// Code for sroad

static LispObject CC_sroad(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3643, v_3644, v_3645;
    LispObject fn;
    LispObject v_3591, v_3590, v_3589;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sroad");
    va_start(aa, nargs);
    v_3589 = va_arg(aa, LispObject);
    v_3590 = va_arg(aa, LispObject);
    v_3591 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3591,v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3589,v_3590,v_3591);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3591;
    stack[-1] = v_3590;
    stack[-2] = v_3589;
// end of prologue
    v_3645 = nil;
v_3596:
    v_3643 = stack[0];
    if (v_3643 == nil) goto v_3599;
    else goto v_3600;
v_3599:
    v_3643 = v_3645;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_3643);
    }
v_3600:
    goto v_3610;
v_3606:
    v_3644 = stack[-2];
    goto v_3607;
v_3608:
    v_3643 = stack[0];
    v_3643 = qcar(v_3643);
    goto v_3609;
v_3610:
    goto v_3606;
v_3607:
    goto v_3608;
v_3609:
    if (equal(v_3644, v_3643)) goto v_3604;
    else goto v_3605;
v_3604:
    goto v_3619;
v_3615:
    stack[-2] = v_3645;
    goto v_3616;
v_3617:
    goto v_3626;
v_3622:
    v_3644 = stack[-1];
    goto v_3623;
v_3624:
    v_3643 = stack[0];
    v_3643 = qcdr(v_3643);
    goto v_3625;
v_3626:
    goto v_3622;
v_3623:
    goto v_3624;
v_3625:
    v_3643 = Lappend(nil, v_3644, v_3643);
    env = stack[-3];
    goto v_3618;
v_3619:
    goto v_3615;
v_3616:
    goto v_3617;
v_3618:
    {
        LispObject v_3649 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3649, v_3643);
    }
v_3605:
    goto v_3637;
v_3633:
    v_3643 = stack[0];
    v_3643 = qcar(v_3643);
    goto v_3634;
v_3635:
    v_3644 = v_3645;
    goto v_3636;
v_3637:
    goto v_3633;
v_3634:
    goto v_3635;
v_3636:
    v_3643 = cons(v_3643, v_3644);
    env = stack[-3];
    v_3645 = v_3643;
    v_3643 = stack[0];
    v_3643 = qcdr(v_3643);
    stack[0] = v_3643;
    goto v_3596;
    v_3643 = nil;
    return onevalue(v_3643);
}



// Code for list2widestring

static LispObject CC_list2widestring(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_4049, v_4050, v_4051;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_3589;
// end of prologue
    v_4049 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_4049;
    v_4049 = stack[-8];
    stack[0] = v_4049;
v_3597:
    v_4049 = stack[0];
    if (v_4049 == nil) goto v_3604;
    else goto v_3605;
v_3604:
    goto v_3598;
v_3605:
    v_4049 = stack[0];
    v_4049 = qcar(v_4049);
    stack[-9] = v_4049;
    v_4049 = stack[0];
    v_4049 = qcdr(v_4049);
    stack[0] = v_4049;
    v_4049 = stack[-9];
    if (symbolp(v_4049)) goto v_3613;
    else goto v_3614;
v_3613:
    v_4049 = stack[-9];
    v_4049 = Lsymbol_name(nil, v_4049);
    env = stack[-10];
    fn = elt(env, 5); // widestring2list
    v_4049 = (*qfn1(fn))(fn, v_4049);
    env = stack[-10];
    v_4049 = qcar(v_4049);
    stack[-9] = v_4049;
    goto v_3612;
v_3614:
    v_4049 = stack[-9];
    v_4049 = Lstringp(nil, v_4049);
    env = stack[-10];
    if (v_4049 == nil) goto v_3621;
    goto v_3630;
v_3626:
    v_4050 = stack[-9];
    goto v_3627;
v_3628:
    v_4049 = elt(env, 1); // ""
    goto v_3629;
v_3630:
    goto v_3626;
v_3627:
    goto v_3628;
v_3629:
    if (equal(v_4050, v_4049)) goto v_3621;
    v_4049 = stack[-9];
    fn = elt(env, 5); // widestring2list
    v_4049 = (*qfn1(fn))(fn, v_4049);
    env = stack[-10];
    v_4049 = qcar(v_4049);
    stack[-9] = v_4049;
    goto v_3612;
v_3621:
    v_4049 = stack[-9];
    v_4049 = integerp(v_4049);
    if (v_4049 == nil) goto v_3636;
    else goto v_3637;
v_3636:
    v_4049 = elt(env, 2); // "Invalid item in arg to list2widestring"
    fn = elt(env, 6); // rederr
    v_4049 = (*qfn1(fn))(fn, v_4049);
    env = stack[-10];
    goto v_3612;
v_3637:
v_3612:
    goto v_3651;
v_3647:
    v_4050 = stack[-9];
    goto v_3648;
v_3649:
    v_4049 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3650;
v_3651:
    goto v_3647;
v_3648:
    goto v_3649;
v_3650:
    v_4049 = (LispObject)lessp2(v_4050, v_4049);
    v_4049 = v_4049 ? lisp_true : nil;
    env = stack[-10];
    if (v_4049 == nil) goto v_3645;
    goto v_3659;
v_3655:
    v_4050 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3656;
v_3657:
    v_4049 = elt(env, 3); // "Negative integer in list2widestring"
    goto v_3658;
v_3659:
    goto v_3655;
v_3656:
    goto v_3657;
v_3658:
    fn = elt(env, 7); // error
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3643;
v_3645:
    goto v_3669;
v_3665:
    v_4050 = stack[-9];
    goto v_3666;
v_3667:
    v_4049 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3668;
v_3669:
    goto v_3665;
v_3666:
    goto v_3667;
v_3668:
    v_4049 = (LispObject)lessp2(v_4050, v_4049);
    v_4049 = v_4049 ? lisp_true : nil;
    env = stack[-10];
    if (v_4049 == nil) goto v_3663;
    v_4049 = stack[-6];
    v_4049 = add1(v_4049);
    env = stack[-10];
    stack[-6] = v_4049;
    goto v_3643;
v_3663:
    goto v_3681;
v_3677:
    v_4050 = stack[-9];
    goto v_3678;
v_3679:
    v_4049 = (LispObject)32768+TAG_FIXNUM; // 2048
    goto v_3680;
v_3681:
    goto v_3677;
v_3678:
    goto v_3679;
v_3680:
    v_4049 = (LispObject)lessp2(v_4050, v_4049);
    v_4049 = v_4049 ? lisp_true : nil;
    env = stack[-10];
    if (v_4049 == nil) goto v_3675;
    goto v_3689;
v_3685:
    v_4050 = stack[-6];
    goto v_3686;
v_3687:
    v_4049 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3688;
v_3689:
    goto v_3685;
v_3686:
    goto v_3687;
v_3688:
    v_4049 = plus2(v_4050, v_4049);
    env = stack[-10];
    stack[-6] = v_4049;
    goto v_3643;
v_3675:
    goto v_3699;
v_3695:
    v_4050 = stack[-9];
    goto v_3696;
v_3697:
    v_4049 = (LispObject)1048576+TAG_FIXNUM; // 65536
    goto v_3698;
v_3699:
    goto v_3695;
v_3696:
    goto v_3697;
v_3698:
    v_4049 = (LispObject)lessp2(v_4050, v_4049);
    v_4049 = v_4049 ? lisp_true : nil;
    env = stack[-10];
    if (v_4049 == nil) goto v_3693;
    goto v_3707;
v_3703:
    v_4050 = stack[-6];
    goto v_3704;
v_3705:
    v_4049 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_3706;
v_3707:
    goto v_3703;
v_3704:
    goto v_3705;
v_3706:
    v_4049 = plus2(v_4050, v_4049);
    env = stack[-10];
    stack[-6] = v_4049;
    goto v_3643;
v_3693:
    goto v_3717;
v_3713:
    v_4050 = stack[-9];
    goto v_3714;
v_3715:
    v_4049 = (LispObject)17825792+TAG_FIXNUM; // 1114112
    goto v_3716;
v_3717:
    goto v_3713;
v_3714:
    goto v_3715;
v_3716:
    v_4049 = (LispObject)lessp2(v_4050, v_4049);
    v_4049 = v_4049 ? lisp_true : nil;
    env = stack[-10];
    if (v_4049 == nil) goto v_3711;
    goto v_3725;
v_3721:
    v_4050 = stack[-6];
    goto v_3722;
v_3723:
    v_4049 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_3724;
v_3725:
    goto v_3721;
v_3722:
    goto v_3723;
v_3724:
    v_4049 = plus2(v_4050, v_4049);
    env = stack[-10];
    stack[-6] = v_4049;
    goto v_3643;
v_3711:
    goto v_3735;
v_3731:
    v_4050 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3732;
v_3733:
    v_4049 = elt(env, 4); // "Integer too large in list2widestring"
    goto v_3734;
v_3735:
    goto v_3731;
v_3732:
    goto v_3733;
v_3734:
    fn = elt(env, 7); // error
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3643;
v_3643:
    goto v_3597;
v_3598:
    v_4049 = stack[-6];
    fn = elt(env, 8); // allocate!-string
    v_4049 = (*qfn1(fn))(fn, v_4049);
    env = stack[-10];
    stack[-7] = v_4049;
    v_4049 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_4049;
v_3743:
    v_4049 = stack[-8];
    if (v_4049 == nil) goto v_3746;
    else goto v_3747;
v_3746:
    goto v_3742;
v_3747:
    v_4049 = stack[-8];
    v_4049 = qcar(v_4049);
    stack[-9] = v_4049;
    v_4049 = stack[-9];
    if (symbolp(v_4049)) goto v_3754;
    else goto v_3755;
v_3754:
    v_4049 = stack[-9];
    v_4049 = Lsymbol_name(nil, v_4049);
    env = stack[-10];
    fn = elt(env, 5); // widestring2list
    v_4049 = (*qfn1(fn))(fn, v_4049);
    env = stack[-10];
    v_4049 = qcar(v_4049);
    stack[-9] = v_4049;
    goto v_3753;
v_3755:
    v_4049 = stack[-9];
    v_4049 = Lstringp(nil, v_4049);
    env = stack[-10];
    if (v_4049 == nil) goto v_3762;
    goto v_3771;
v_3767:
    v_4050 = stack[-9];
    goto v_3768;
v_3769:
    v_4049 = elt(env, 1); // ""
    goto v_3770;
v_3771:
    goto v_3767;
v_3768:
    goto v_3769;
v_3770:
    if (equal(v_4050, v_4049)) goto v_3762;
    v_4049 = stack[-9];
    fn = elt(env, 5); // widestring2list
    v_4049 = (*qfn1(fn))(fn, v_4049);
    env = stack[-10];
    v_4049 = qcar(v_4049);
    stack[-9] = v_4049;
    goto v_3753;
v_3762:
v_3753:
    v_4049 = stack[-8];
    v_4049 = qcdr(v_4049);
    stack[-8] = v_4049;
    goto v_3788;
v_3784:
    v_4050 = stack[-9];
    goto v_3785;
v_3786:
    v_4049 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3787;
v_3788:
    goto v_3784;
v_3785:
    goto v_3786;
v_3787:
    v_4049 = (LispObject)lessp2(v_4050, v_4049);
    v_4049 = v_4049 ? lisp_true : nil;
    env = stack[-10];
    if (v_4049 == nil) goto v_3782;
    goto v_3798;
v_3792:
    v_4051 = stack[-7];
    goto v_3793;
v_3794:
    v_4050 = stack[-6];
    goto v_3795;
v_3796:
    v_4049 = stack[-9];
    goto v_3797;
v_3798:
    goto v_3792;
v_3793:
    goto v_3794;
v_3795:
    goto v_3796;
v_3797:
    fn = elt(env, 9); // string!-store
    v_4049 = (*qfnn(fn))(fn, 3, v_4051, v_4050, v_4049);
    env = stack[-10];
    v_4049 = stack[-6];
    v_4049 = add1(v_4049);
    env = stack[-10];
    stack[-6] = v_4049;
    goto v_3780;
v_3782:
    goto v_3811;
v_3807:
    v_4050 = stack[-9];
    goto v_3808;
v_3809:
    v_4049 = (LispObject)32768+TAG_FIXNUM; // 2048
    goto v_3810;
v_3811:
    goto v_3807;
v_3808:
    goto v_3809;
v_3810:
    v_4049 = (LispObject)lessp2(v_4050, v_4049);
    v_4049 = v_4049 ? lisp_true : nil;
    env = stack[-10];
    if (v_4049 == nil) goto v_3805;
    goto v_3823;
v_3815:
    stack[-3] = stack[-7];
    goto v_3816;
v_3817:
    stack[-2] = stack[-6];
    goto v_3818;
v_3819:
    goto v_3831;
v_3827:
    stack[0] = (LispObject)3072+TAG_FIXNUM; // 192
    goto v_3828;
v_3829:
    goto v_3838;
v_3834:
    v_4050 = stack[-9];
    goto v_3835;
v_3836:
    v_4049 = (LispObject)-96+TAG_FIXNUM; // -6
    goto v_3837;
v_3838:
    goto v_3834;
v_3835:
    goto v_3836;
v_3837:
    fn = elt(env, 10); // lshift
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3830;
v_3831:
    goto v_3827;
v_3828:
    goto v_3829;
v_3830:
    stack[-1] = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3820;
v_3821:
    goto v_3846;
v_3842:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3843;
v_3844:
    goto v_3853;
v_3849:
    v_4050 = stack[-9];
    goto v_3850;
v_3851:
    v_4049 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3852;
v_3853:
    goto v_3849;
v_3850:
    goto v_3851;
v_3852:
    fn = elt(env, 11); // land
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3845;
v_3846:
    goto v_3842;
v_3843:
    goto v_3844;
v_3845:
    v_4049 = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3822;
v_3823:
    goto v_3815;
v_3816:
    goto v_3817;
v_3818:
    goto v_3819;
v_3820:
    goto v_3821;
v_3822:
    fn = elt(env, 12); // string!-store2
    v_4049 = (*qfnn(fn))(fn, 4, stack[-3], stack[-2], stack[-1], v_4049);
    env = stack[-10];
    goto v_3861;
v_3857:
    v_4050 = stack[-6];
    goto v_3858;
v_3859:
    v_4049 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3860;
v_3861:
    goto v_3857;
v_3858:
    goto v_3859;
v_3860:
    v_4049 = plus2(v_4050, v_4049);
    env = stack[-10];
    stack[-6] = v_4049;
    goto v_3780;
v_3805:
    goto v_3871;
v_3867:
    v_4050 = stack[-9];
    goto v_3868;
v_3869:
    v_4049 = (LispObject)1048576+TAG_FIXNUM; // 65536
    goto v_3870;
v_3871:
    goto v_3867;
v_3868:
    goto v_3869;
v_3870:
    v_4049 = (LispObject)lessp2(v_4050, v_4049);
    v_4049 = v_4049 ? lisp_true : nil;
    env = stack[-10];
    if (v_4049 == nil) goto v_3865;
    goto v_3885;
v_3875:
    stack[-4] = stack[-7];
    goto v_3876;
v_3877:
    stack[-3] = stack[-6];
    goto v_3878;
v_3879:
    goto v_3893;
v_3889:
    stack[0] = (LispObject)3584+TAG_FIXNUM; // 224
    goto v_3890;
v_3891:
    goto v_3900;
v_3896:
    v_4050 = stack[-9];
    goto v_3897;
v_3898:
    v_4049 = (LispObject)-192+TAG_FIXNUM; // -12
    goto v_3899;
v_3900:
    goto v_3896;
v_3897:
    goto v_3898;
v_3899:
    fn = elt(env, 10); // lshift
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3892;
v_3893:
    goto v_3889;
v_3890:
    goto v_3891;
v_3892:
    stack[-2] = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3880;
v_3881:
    goto v_3908;
v_3904:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3905;
v_3906:
    goto v_3915;
v_3911:
    goto v_3921;
v_3917:
    v_4050 = stack[-9];
    goto v_3918;
v_3919:
    v_4049 = (LispObject)-96+TAG_FIXNUM; // -6
    goto v_3920;
v_3921:
    goto v_3917;
v_3918:
    goto v_3919;
v_3920:
    fn = elt(env, 10); // lshift
    v_4050 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3912;
v_3913:
    v_4049 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3914;
v_3915:
    goto v_3911;
v_3912:
    goto v_3913;
v_3914:
    fn = elt(env, 11); // land
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3907;
v_3908:
    goto v_3904;
v_3905:
    goto v_3906;
v_3907:
    stack[-1] = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3882;
v_3883:
    goto v_3930;
v_3926:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3927;
v_3928:
    goto v_3937;
v_3933:
    v_4050 = stack[-9];
    goto v_3934;
v_3935:
    v_4049 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3936;
v_3937:
    goto v_3933;
v_3934:
    goto v_3935;
v_3936:
    fn = elt(env, 11); // land
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3929;
v_3930:
    goto v_3926;
v_3927:
    goto v_3928;
v_3929:
    v_4049 = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3884;
v_3885:
    goto v_3875;
v_3876:
    goto v_3877;
v_3878:
    goto v_3879;
v_3880:
    goto v_3881;
v_3882:
    goto v_3883;
v_3884:
    fn = elt(env, 13); // string!-store3
    v_4049 = (*qfnn(fn))(fn, 5, stack[-4], stack[-3], stack[-2], stack[-1], v_4049);
    env = stack[-10];
    goto v_3945;
v_3941:
    v_4050 = stack[-6];
    goto v_3942;
v_3943:
    v_4049 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_3944;
v_3945:
    goto v_3941;
v_3942:
    goto v_3943;
v_3944:
    v_4049 = plus2(v_4050, v_4049);
    env = stack[-10];
    stack[-6] = v_4049;
    goto v_3780;
v_3865:
    goto v_3963;
v_3951:
    stack[-5] = stack[-7];
    goto v_3952;
v_3953:
    stack[-4] = stack[-6];
    goto v_3954;
v_3955:
    goto v_3971;
v_3967:
    stack[0] = (LispObject)3840+TAG_FIXNUM; // 240
    goto v_3968;
v_3969:
    goto v_3978;
v_3974:
    v_4050 = stack[-9];
    goto v_3975;
v_3976:
    v_4049 = (LispObject)-288+TAG_FIXNUM; // -18
    goto v_3977;
v_3978:
    goto v_3974;
v_3975:
    goto v_3976;
v_3977:
    fn = elt(env, 10); // lshift
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3970;
v_3971:
    goto v_3967;
v_3968:
    goto v_3969;
v_3970:
    stack[-3] = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3956;
v_3957:
    goto v_3986;
v_3982:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3983;
v_3984:
    goto v_3993;
v_3989:
    goto v_3999;
v_3995:
    v_4050 = stack[-9];
    goto v_3996;
v_3997:
    v_4049 = (LispObject)-192+TAG_FIXNUM; // -12
    goto v_3998;
v_3999:
    goto v_3995;
v_3996:
    goto v_3997;
v_3998:
    fn = elt(env, 10); // lshift
    v_4050 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3990;
v_3991:
    v_4049 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3992;
v_3993:
    goto v_3989;
v_3990:
    goto v_3991;
v_3992:
    fn = elt(env, 11); // land
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_3985;
v_3986:
    goto v_3982;
v_3983:
    goto v_3984;
v_3985:
    stack[-2] = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3958;
v_3959:
    goto v_4008;
v_4004:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_4005;
v_4006:
    goto v_4015;
v_4011:
    goto v_4021;
v_4017:
    v_4050 = stack[-9];
    goto v_4018;
v_4019:
    v_4049 = (LispObject)-96+TAG_FIXNUM; // -6
    goto v_4020;
v_4021:
    goto v_4017;
v_4018:
    goto v_4019;
v_4020:
    fn = elt(env, 10); // lshift
    v_4050 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_4012;
v_4013:
    v_4049 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_4014;
v_4015:
    goto v_4011;
v_4012:
    goto v_4013;
v_4014:
    fn = elt(env, 11); // land
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_4007;
v_4008:
    goto v_4004;
v_4005:
    goto v_4006;
v_4007:
    stack[-1] = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3960;
v_3961:
    goto v_4030;
v_4026:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_4027;
v_4028:
    goto v_4037;
v_4033:
    v_4050 = stack[-9];
    goto v_4034;
v_4035:
    v_4049 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_4036;
v_4037:
    goto v_4033;
v_4034:
    goto v_4035;
v_4036:
    fn = elt(env, 11); // land
    v_4049 = (*qfn2(fn))(fn, v_4050, v_4049);
    env = stack[-10];
    goto v_4029;
v_4030:
    goto v_4026;
v_4027:
    goto v_4028;
v_4029:
    v_4049 = plus2(stack[0], v_4049);
    env = stack[-10];
    goto v_3962;
v_3963:
    goto v_3951;
v_3952:
    goto v_3953;
v_3954:
    goto v_3955;
v_3956:
    goto v_3957;
v_3958:
    goto v_3959;
v_3960:
    goto v_3961;
v_3962:
    fn = elt(env, 14); // string!-store4
    v_4049 = (*qfnn(fn))(fn, 6, stack[-5], stack[-4], stack[-3], stack[-2], stack[-1], v_4049);
    env = stack[-10];
    goto v_4045;
v_4041:
    v_4050 = stack[-6];
    goto v_4042;
v_4043:
    v_4049 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_4044;
v_4045:
    goto v_4041;
v_4042:
    goto v_4043;
v_4044:
    v_4049 = plus2(v_4050, v_4049);
    env = stack[-10];
    stack[-6] = v_4049;
    goto v_3780;
v_3780:
    goto v_3743;
v_3742:
    v_4049 = stack[-7];
    return onevalue(v_4049);
}



// Code for red!-weight1

static LispObject CC_redKweight1(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3644, v_3645;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3590;
    stack[-1] = v_3589;
// end of prologue
    stack[-2] = nil;
v_3596:
    v_3644 = stack[-1];
    if (v_3644 == nil) goto v_3601;
    else goto v_3602;
v_3601:
    goto v_3597;
v_3602:
    goto v_3609;
v_3605:
    goto v_3615;
v_3611:
    v_3644 = stack[-1];
    v_3644 = qcar(v_3644);
    v_3645 = Labsval(nil, v_3644);
    env = stack[-3];
    goto v_3612;
v_3613:
    v_3644 = stack[0];
    v_3644 = qcar(v_3644);
    goto v_3614;
v_3615:
    goto v_3611;
v_3612:
    goto v_3613;
v_3614:
    v_3645 = times2(v_3645, v_3644);
    env = stack[-3];
    goto v_3606;
v_3607:
    v_3644 = stack[-2];
    goto v_3608;
v_3609:
    goto v_3605;
v_3606:
    goto v_3607;
v_3608:
    v_3644 = cons(v_3645, v_3644);
    env = stack[-3];
    stack[-2] = v_3644;
    v_3644 = stack[-1];
    v_3644 = qcdr(v_3644);
    stack[-1] = v_3644;
    v_3644 = stack[0];
    v_3644 = qcdr(v_3644);
    stack[0] = v_3644;
    goto v_3596;
v_3597:
    v_3644 = (LispObject)0+TAG_FIXNUM; // 0
    v_3645 = v_3644;
v_3598:
    v_3644 = stack[-2];
    if (v_3644 == nil) goto v_3629;
    else goto v_3630;
v_3629:
    v_3644 = v_3645;
    goto v_3595;
v_3630:
    goto v_3638;
v_3634:
    v_3644 = stack[-2];
    v_3644 = qcar(v_3644);
    goto v_3635;
v_3636:
    goto v_3637;
v_3638:
    goto v_3634;
v_3635:
    goto v_3636;
v_3637:
    v_3644 = plus2(v_3644, v_3645);
    env = stack[-3];
    v_3645 = v_3644;
    v_3644 = stack[-2];
    v_3644 = qcdr(v_3644);
    stack[-2] = v_3644;
    goto v_3598;
v_3595:
    return onevalue(v_3644);
}



// Code for dp_times_bc

static LispObject CC_dp_times_bc(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3664, v_3665;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_3664 = v_3590;
    stack[-4] = v_3589;
// end of prologue
    stack[-5] = v_3664;
    v_3664 = stack[-5];
    if (v_3664 == nil) goto v_3601;
    else goto v_3602;
v_3601:
    v_3664 = nil;
    goto v_3596;
v_3602:
    v_3664 = stack[-5];
    v_3664 = qcar(v_3664);
    goto v_3614;
v_3610:
    v_3665 = v_3664;
    stack[0] = qcar(v_3665);
    goto v_3611;
v_3612:
    goto v_3622;
v_3618:
    v_3665 = stack[-4];
    goto v_3619;
v_3620:
    v_3664 = qcdr(v_3664);
    goto v_3621;
v_3622:
    goto v_3618;
v_3619:
    goto v_3620;
v_3621:
    fn = elt(env, 1); // cali_bc_prod
    v_3664 = (*qfn2(fn))(fn, v_3665, v_3664);
    env = stack[-6];
    goto v_3613;
v_3614:
    goto v_3610;
v_3611:
    goto v_3612;
v_3613:
    v_3664 = cons(stack[0], v_3664);
    env = stack[-6];
    v_3664 = ncons(v_3664);
    env = stack[-6];
    stack[-2] = v_3664;
    stack[-3] = v_3664;
v_3597:
    v_3664 = stack[-5];
    v_3664 = qcdr(v_3664);
    stack[-5] = v_3664;
    v_3664 = stack[-5];
    if (v_3664 == nil) goto v_3630;
    else goto v_3631;
v_3630:
    v_3664 = stack[-3];
    goto v_3596;
v_3631:
    goto v_3639;
v_3635:
    stack[-1] = stack[-2];
    goto v_3636;
v_3637:
    v_3664 = stack[-5];
    v_3664 = qcar(v_3664);
    goto v_3650;
v_3646:
    v_3665 = v_3664;
    stack[0] = qcar(v_3665);
    goto v_3647;
v_3648:
    goto v_3658;
v_3654:
    v_3665 = stack[-4];
    goto v_3655;
v_3656:
    v_3664 = qcdr(v_3664);
    goto v_3657;
v_3658:
    goto v_3654;
v_3655:
    goto v_3656;
v_3657:
    fn = elt(env, 1); // cali_bc_prod
    v_3664 = (*qfn2(fn))(fn, v_3665, v_3664);
    env = stack[-6];
    goto v_3649;
v_3650:
    goto v_3646;
v_3647:
    goto v_3648;
v_3649:
    v_3664 = cons(stack[0], v_3664);
    env = stack[-6];
    v_3664 = ncons(v_3664);
    env = stack[-6];
    goto v_3638;
v_3639:
    goto v_3635;
v_3636:
    goto v_3637;
v_3638:
    v_3664 = Lrplacd(nil, stack[-1], v_3664);
    env = stack[-6];
    v_3664 = stack[-2];
    v_3664 = qcdr(v_3664);
    stack[-2] = v_3664;
    goto v_3597;
v_3596:
    return onevalue(v_3664);
}



// Code for dv_skelhead

static LispObject CC_dv_skelhead(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3594;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3594 = v_3589;
// end of prologue
    v_3594 = qcar(v_3594);
    {
        fn = elt(env, 1); // dv_cambhead
        return (*qfn1(fn))(fn, v_3594);
    }
}



// Code for general!-plus!-mod!-p

static LispObject CC_generalKplusKmodKp(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3862, v_3863, v_3864;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3590;
    stack[-2] = v_3589;
// end of prologue
    stack[0] = nil;
v_3595:
    v_3862 = stack[-2];
    if (v_3862 == nil) goto v_3598;
    else goto v_3599;
v_3598:
    goto v_3606;
v_3602:
    v_3863 = stack[0];
    goto v_3603;
v_3604:
    v_3862 = stack[-1];
    goto v_3605;
v_3606:
    goto v_3602;
v_3603:
    goto v_3604;
v_3605:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3863, v_3862);
    }
v_3599:
    v_3862 = stack[-1];
    if (v_3862 == nil) goto v_3609;
    else goto v_3610;
v_3609:
    goto v_3617;
v_3613:
    v_3863 = stack[0];
    goto v_3614;
v_3615:
    v_3862 = stack[-2];
    goto v_3616;
v_3617:
    goto v_3613;
v_3614:
    goto v_3615;
v_3616:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3863, v_3862);
    }
v_3610:
    v_3862 = stack[-2];
    if (!consp(v_3862)) goto v_3624;
    else goto v_3625;
v_3624:
    v_3862 = lisp_true;
    goto v_3623;
v_3625:
    v_3862 = stack[-2];
    v_3862 = qcar(v_3862);
    v_3862 = (consp(v_3862) ? nil : lisp_true);
    goto v_3623;
    v_3862 = nil;
v_3623:
    if (v_3862 == nil) goto v_3621;
    v_3862 = stack[-1];
    if (!consp(v_3862)) goto v_3639;
    else goto v_3640;
v_3639:
    v_3862 = lisp_true;
    goto v_3638;
v_3640:
    v_3862 = stack[-1];
    v_3862 = qcar(v_3862);
    v_3862 = (consp(v_3862) ? nil : lisp_true);
    goto v_3638;
    v_3862 = nil;
v_3638:
    if (v_3862 == nil) goto v_3636;
    goto v_3653;
v_3649:
    goto v_3650;
v_3651:
    goto v_3661;
v_3657:
    v_3863 = stack[-2];
    goto v_3658;
v_3659:
    v_3862 = stack[-1];
    goto v_3660;
v_3661:
    goto v_3657;
v_3658:
    goto v_3659;
v_3660:
    fn = elt(env, 2); // general!-modular!-plus
    v_3862 = (*qfn2(fn))(fn, v_3863, v_3862);
    env = stack[-4];
    fn = elt(env, 3); // !*n2f
    v_3862 = (*qfn1(fn))(fn, v_3862);
    env = stack[-4];
    goto v_3652;
v_3653:
    goto v_3649;
v_3650:
    goto v_3651;
v_3652:
    {
        LispObject v_3869 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3869, v_3862);
    }
v_3636:
    goto v_3671;
v_3667:
    v_3862 = stack[-1];
    v_3863 = qcar(v_3862);
    goto v_3668;
v_3669:
    v_3862 = stack[0];
    goto v_3670;
v_3671:
    goto v_3667;
v_3668:
    goto v_3669;
v_3670:
    v_3862 = cons(v_3863, v_3862);
    env = stack[-4];
    stack[0] = v_3862;
    v_3862 = stack[-1];
    v_3862 = qcdr(v_3862);
    stack[-1] = v_3862;
    goto v_3595;
    goto v_3597;
v_3621:
    v_3862 = stack[-1];
    if (!consp(v_3862)) goto v_3681;
    else goto v_3682;
v_3681:
    v_3862 = lisp_true;
    goto v_3680;
v_3682:
    v_3862 = stack[-1];
    v_3862 = qcar(v_3862);
    v_3862 = (consp(v_3862) ? nil : lisp_true);
    goto v_3680;
    v_3862 = nil;
v_3680:
    if (v_3862 == nil) goto v_3678;
    goto v_3695;
v_3691:
    v_3862 = stack[-2];
    v_3863 = qcar(v_3862);
    goto v_3692;
v_3693:
    v_3862 = stack[0];
    goto v_3694;
v_3695:
    goto v_3691;
v_3692:
    goto v_3693;
v_3694:
    v_3862 = cons(v_3863, v_3862);
    env = stack[-4];
    stack[0] = v_3862;
    v_3862 = stack[-2];
    v_3862 = qcdr(v_3862);
    stack[-2] = v_3862;
    goto v_3595;
v_3678:
    goto v_3707;
v_3703:
    v_3862 = stack[-2];
    v_3862 = qcar(v_3862);
    v_3863 = qcar(v_3862);
    goto v_3704;
v_3705:
    v_3862 = stack[-1];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    goto v_3706;
v_3707:
    goto v_3703;
v_3704:
    goto v_3705;
v_3706:
    if (equal(v_3863, v_3862)) goto v_3701;
    else goto v_3702;
v_3701:
    goto v_3719;
v_3715:
    stack[-3] = stack[0];
    goto v_3716;
v_3717:
    goto v_3726;
v_3722:
    v_3862 = stack[-2];
    v_3862 = qcar(v_3862);
    v_3863 = qcdr(v_3862);
    goto v_3723;
v_3724:
    v_3862 = stack[-1];
    v_3862 = qcar(v_3862);
    v_3862 = qcdr(v_3862);
    goto v_3725;
v_3726:
    goto v_3722;
v_3723:
    goto v_3724;
v_3725:
    stack[0] = CC_generalKplusKmodKp(elt(env, 0), v_3863, v_3862);
    env = stack[-4];
    goto v_3738;
v_3734:
    v_3862 = stack[-2];
    v_3863 = qcdr(v_3862);
    goto v_3735;
v_3736:
    v_3862 = stack[-1];
    v_3862 = qcdr(v_3862);
    goto v_3737;
v_3738:
    goto v_3734;
v_3735:
    goto v_3736;
v_3737:
    v_3862 = CC_generalKplusKmodKp(elt(env, 0), v_3863, v_3862);
    env = stack[-4];
    v_3863 = stack[0];
    v_3864 = v_3863;
    if (v_3864 == nil) goto v_3747;
    else goto v_3748;
v_3747:
    goto v_3746;
v_3748:
    goto v_3760;
v_3754:
    v_3864 = stack[-2];
    v_3864 = qcar(v_3864);
    v_3864 = qcar(v_3864);
    goto v_3755;
v_3756:
    goto v_3757;
v_3758:
    goto v_3759;
v_3760:
    goto v_3754;
v_3755:
    goto v_3756;
v_3757:
    goto v_3758;
v_3759:
    v_3862 = acons(v_3864, v_3863, v_3862);
    env = stack[-4];
    goto v_3746;
    v_3862 = nil;
v_3746:
    goto v_3718;
v_3719:
    goto v_3715;
v_3716:
    goto v_3717;
v_3718:
    {
        LispObject v_3870 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3870, v_3862);
    }
v_3702:
    goto v_3777;
v_3773:
    v_3862 = stack[-2];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    v_3863 = qcar(v_3862);
    goto v_3774;
v_3775:
    v_3862 = stack[-1];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    goto v_3776;
v_3777:
    goto v_3773;
v_3774:
    goto v_3775;
v_3776:
    if (equal(v_3863, v_3862)) goto v_3771;
    else goto v_3772;
v_3771:
    goto v_3790;
v_3786:
    v_3862 = stack[-2];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    v_3863 = qcdr(v_3862);
    goto v_3787;
v_3788:
    v_3862 = stack[-1];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    v_3862 = qcdr(v_3862);
    goto v_3789;
v_3790:
    goto v_3786;
v_3787:
    goto v_3788;
v_3789:
    v_3862 = ((intptr_t)v_3863 > (intptr_t)v_3862) ? lisp_true : nil;
    goto v_3770;
v_3772:
    v_3862 = nil;
    goto v_3770;
    v_3862 = nil;
v_3770:
    if (v_3862 == nil) goto v_3768;
    else goto v_3766;
v_3768:
    goto v_3812;
v_3808:
    v_3862 = stack[-2];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    v_3863 = qcar(v_3862);
    goto v_3809;
v_3810:
    v_3862 = stack[-1];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    goto v_3811;
v_3812:
    goto v_3808;
v_3809:
    goto v_3810;
v_3811:
    if (equal(v_3863, v_3862)) goto v_3807;
    goto v_3826;
v_3822:
    v_3862 = stack[-2];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    v_3863 = qcar(v_3862);
    goto v_3823;
v_3824:
    v_3862 = stack[-1];
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    v_3862 = qcar(v_3862);
    goto v_3825;
v_3826:
    goto v_3822;
v_3823:
    goto v_3824;
v_3825:
    fn = elt(env, 4); // ordop
    v_3862 = (*qfn2(fn))(fn, v_3863, v_3862);
    env = stack[-4];
    goto v_3805;
v_3807:
    v_3862 = nil;
    goto v_3805;
    v_3862 = nil;
v_3805:
    if (v_3862 == nil) goto v_3803;
    else goto v_3766;
v_3803:
    goto v_3767;
v_3766:
    goto v_3843;
v_3839:
    v_3862 = stack[-2];
    v_3863 = qcar(v_3862);
    goto v_3840;
v_3841:
    v_3862 = stack[0];
    goto v_3842;
v_3843:
    goto v_3839;
v_3840:
    goto v_3841;
v_3842:
    v_3862 = cons(v_3863, v_3862);
    env = stack[-4];
    stack[0] = v_3862;
    v_3862 = stack[-2];
    v_3862 = qcdr(v_3862);
    stack[-2] = v_3862;
    goto v_3595;
v_3767:
    goto v_3856;
v_3852:
    v_3862 = stack[-1];
    v_3863 = qcar(v_3862);
    goto v_3853;
v_3854:
    v_3862 = stack[0];
    goto v_3855;
v_3856:
    goto v_3852;
v_3853:
    goto v_3854;
v_3855:
    v_3862 = cons(v_3863, v_3862);
    env = stack[-4];
    stack[0] = v_3862;
    v_3862 = stack[-1];
    v_3862 = qcdr(v_3862);
    stack[-1] = v_3862;
    goto v_3595;
v_3597:
    v_3862 = nil;
    return onevalue(v_3862);
}



// Code for mcharg2

static LispObject CC_mcharg2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3725, v_3726, v_3727;
    LispObject fn;
    LispObject v_3592, v_3591, v_3590, v_3589;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "mcharg2");
    va_start(aa, nargs);
    v_3589 = va_arg(aa, LispObject);
    v_3590 = va_arg(aa, LispObject);
    v_3591 = va_arg(aa, LispObject);
    v_3592 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_3592,v_3591,v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_3589,v_3590,v_3591,v_3592);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-6] = v_3592;
    stack[-7] = v_3591;
    stack[-8] = v_3590;
    stack[-9] = v_3589;
// end of prologue
    v_3725 = stack[-9];
    if (v_3725 == nil) goto v_3599;
    else goto v_3600;
v_3599:
    v_3725 = stack[-7];
    goto v_3596;
v_3600:
    goto v_3608;
v_3604:
    v_3725 = stack[-9];
    v_3726 = qcar(v_3725);
    goto v_3605;
v_3606:
    v_3725 = stack[-8];
    v_3725 = qcar(v_3725);
    goto v_3607;
v_3608:
    goto v_3604;
v_3605:
    goto v_3606;
v_3607:
    fn = elt(env, 1); // mchk
    v_3725 = (*qfn2(fn))(fn, v_3726, v_3725);
    env = stack[-11];
    v_3726 = v_3725;
    v_3725 = stack[-9];
    v_3725 = qcdr(v_3725);
    stack[-9] = v_3725;
    v_3725 = stack[-8];
    v_3725 = qcdr(v_3725);
    stack[-8] = v_3725;
    v_3725 = v_3726;
    stack[-10] = v_3725;
v_3622:
    v_3725 = stack[-10];
    if (v_3725 == nil) goto v_3627;
    else goto v_3628;
v_3627:
    v_3725 = nil;
    goto v_3621;
v_3628:
    v_3725 = stack[-10];
    v_3725 = qcar(v_3725);
    stack[-2] = v_3725;
    goto v_3643;
v_3635:
    stack[-1] = stack[-9];
    goto v_3636;
v_3637:
    goto v_3652;
v_3646:
    v_3727 = stack[-2];
    goto v_3647;
v_3648:
    v_3726 = stack[-8];
    goto v_3649;
v_3650:
    v_3725 = stack[-6];
    goto v_3651;
v_3652:
    goto v_3646;
v_3647:
    goto v_3648;
v_3649:
    goto v_3650;
v_3651:
    fn = elt(env, 2); // updtemplate
    stack[0] = (*qfnn(fn))(fn, 3, v_3727, v_3726, v_3725);
    env = stack[-11];
    goto v_3638;
v_3639:
    goto v_3661;
v_3657:
    v_3726 = stack[-7];
    goto v_3658;
v_3659:
    v_3725 = stack[-2];
    goto v_3660;
v_3661:
    goto v_3657;
v_3658:
    goto v_3659;
v_3660:
    fn = elt(env, 3); // msappend
    v_3726 = (*qfn2(fn))(fn, v_3726, v_3725);
    env = stack[-11];
    goto v_3640;
v_3641:
    v_3725 = stack[-6];
    goto v_3642;
v_3643:
    goto v_3635;
v_3636:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    goto v_3641;
v_3642:
    v_3725 = CC_mcharg2(elt(env, 0), 4, stack[-1], stack[0], v_3726, v_3725);
    env = stack[-11];
    stack[-5] = v_3725;
    v_3725 = stack[-5];
    fn = elt(env, 4); // lastpair
    v_3725 = (*qfn1(fn))(fn, v_3725);
    env = stack[-11];
    stack[-4] = v_3725;
    v_3725 = stack[-10];
    v_3725 = qcdr(v_3725);
    stack[-10] = v_3725;
    v_3725 = stack[-4];
    if (!consp(v_3725)) goto v_3671;
    else goto v_3672;
v_3671:
    goto v_3622;
v_3672:
v_3623:
    v_3725 = stack[-10];
    if (v_3725 == nil) goto v_3676;
    else goto v_3677;
v_3676:
    v_3725 = stack[-5];
    goto v_3621;
v_3677:
    goto v_3685;
v_3681:
    stack[-3] = stack[-4];
    goto v_3682;
v_3683:
    v_3725 = stack[-10];
    v_3725 = qcar(v_3725);
    stack[-2] = v_3725;
    goto v_3699;
v_3691:
    stack[-1] = stack[-9];
    goto v_3692;
v_3693:
    goto v_3708;
v_3702:
    v_3727 = stack[-2];
    goto v_3703;
v_3704:
    v_3726 = stack[-8];
    goto v_3705;
v_3706:
    v_3725 = stack[-6];
    goto v_3707;
v_3708:
    goto v_3702;
v_3703:
    goto v_3704;
v_3705:
    goto v_3706;
v_3707:
    fn = elt(env, 2); // updtemplate
    stack[0] = (*qfnn(fn))(fn, 3, v_3727, v_3726, v_3725);
    env = stack[-11];
    goto v_3694;
v_3695:
    goto v_3717;
v_3713:
    v_3726 = stack[-7];
    goto v_3714;
v_3715:
    v_3725 = stack[-2];
    goto v_3716;
v_3717:
    goto v_3713;
v_3714:
    goto v_3715;
v_3716:
    fn = elt(env, 3); // msappend
    v_3726 = (*qfn2(fn))(fn, v_3726, v_3725);
    env = stack[-11];
    goto v_3696;
v_3697:
    v_3725 = stack[-6];
    goto v_3698;
v_3699:
    goto v_3691;
v_3692:
    goto v_3693;
v_3694:
    goto v_3695;
v_3696:
    goto v_3697;
v_3698:
    v_3725 = CC_mcharg2(elt(env, 0), 4, stack[-1], stack[0], v_3726, v_3725);
    env = stack[-11];
    goto v_3684;
v_3685:
    goto v_3681;
v_3682:
    goto v_3683;
v_3684:
    v_3725 = Lrplacd(nil, stack[-3], v_3725);
    env = stack[-11];
    v_3725 = stack[-4];
    fn = elt(env, 4); // lastpair
    v_3725 = (*qfn1(fn))(fn, v_3725);
    env = stack[-11];
    stack[-4] = v_3725;
    v_3725 = stack[-10];
    v_3725 = qcdr(v_3725);
    stack[-10] = v_3725;
    goto v_3623;
v_3621:
v_3596:
    return onevalue(v_3725);
}



// Code for times!-term!-mod!-p

static LispObject CC_timesKtermKmodKp(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3810, v_3811, v_3812;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3590;
    stack[-2] = v_3589;
// end of prologue
    stack[-3] = nil;
v_3597:
    v_3810 = stack[-1];
    if (v_3810 == nil) goto v_3601;
    else goto v_3602;
v_3601:
    v_3810 = nil;
    v_3811 = v_3810;
    goto v_3598;
v_3602:
    v_3810 = stack[-1];
    if (!consp(v_3810)) goto v_3609;
    else goto v_3610;
v_3609:
    v_3810 = lisp_true;
    goto v_3608;
v_3610:
    v_3810 = stack[-1];
    v_3810 = qcar(v_3810);
    v_3810 = (consp(v_3810) ? nil : lisp_true);
    goto v_3608;
    v_3810 = nil;
v_3608:
    if (v_3810 == nil) goto v_3606;
    goto v_3623;
v_3619:
    v_3810 = stack[-2];
    v_3811 = qcdr(v_3810);
    goto v_3620;
v_3621:
    v_3810 = stack[-1];
    goto v_3622;
v_3623:
    goto v_3619;
v_3620:
    goto v_3621;
v_3622:
    fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
    v_3811 = (*qfn2(fn))(fn, v_3811, v_3810);
    env = stack[-4];
    v_3810 = nil;
    v_3812 = v_3811;
    if (v_3812 == nil) goto v_3632;
    else goto v_3633;
v_3632:
    goto v_3631;
v_3633:
    goto v_3645;
v_3639:
    v_3812 = stack[-2];
    v_3812 = qcar(v_3812);
    goto v_3640;
v_3641:
    goto v_3642;
v_3643:
    goto v_3644;
v_3645:
    goto v_3639;
v_3640:
    goto v_3641;
v_3642:
    goto v_3643;
v_3644:
    v_3810 = acons(v_3812, v_3811, v_3810);
    env = stack[-4];
    goto v_3631;
    v_3810 = nil;
v_3631:
    v_3811 = v_3810;
    goto v_3598;
v_3606:
    goto v_3656;
v_3652:
    v_3810 = stack[-2];
    v_3810 = qcar(v_3810);
    v_3811 = qcar(v_3810);
    goto v_3653;
v_3654:
    v_3810 = stack[-1];
    v_3810 = qcar(v_3810);
    v_3810 = qcar(v_3810);
    v_3810 = qcar(v_3810);
    goto v_3655;
v_3656:
    goto v_3652;
v_3653:
    goto v_3654;
v_3655:
    if (equal(v_3811, v_3810)) goto v_3650;
    else goto v_3651;
v_3650:
    goto v_3671;
v_3665:
    goto v_3677;
v_3673:
    v_3810 = stack[-2];
    v_3810 = qcar(v_3810);
    v_3812 = qcar(v_3810);
    goto v_3674;
v_3675:
    goto v_3685;
v_3681:
    v_3810 = stack[-2];
    v_3810 = qcar(v_3810);
    v_3811 = qcdr(v_3810);
    goto v_3682;
v_3683:
    v_3810 = stack[-1];
    v_3810 = qcar(v_3810);
    v_3810 = qcar(v_3810);
    v_3810 = qcdr(v_3810);
    goto v_3684;
v_3685:
    goto v_3681;
v_3682:
    goto v_3683;
v_3684:
    v_3810 = (LispObject)(intptr_t)((intptr_t)v_3811 + (intptr_t)v_3810 - TAG_FIXNUM);
    goto v_3676;
v_3677:
    goto v_3673;
v_3674:
    goto v_3675;
v_3676:
    fn = elt(env, 2); // mksp
    stack[0] = (*qfn2(fn))(fn, v_3812, v_3810);
    env = stack[-4];
    goto v_3666;
v_3667:
    goto v_3699;
v_3695:
    v_3810 = stack[-2];
    v_3811 = qcdr(v_3810);
    goto v_3696;
v_3697:
    v_3810 = stack[-1];
    v_3810 = qcar(v_3810);
    v_3810 = qcdr(v_3810);
    goto v_3698;
v_3699:
    goto v_3695;
v_3696:
    goto v_3697;
v_3698:
    fn = elt(env, 3); // times!-mod!-p
    v_3811 = (*qfn2(fn))(fn, v_3811, v_3810);
    env = stack[-4];
    goto v_3668;
v_3669:
    v_3810 = stack[-3];
    goto v_3670;
v_3671:
    goto v_3665;
v_3666:
    goto v_3667;
v_3668:
    goto v_3669;
v_3670:
    v_3810 = acons(stack[0], v_3811, v_3810);
    env = stack[-4];
    stack[-3] = v_3810;
    v_3810 = stack[-1];
    v_3810 = qcdr(v_3810);
    stack[-1] = v_3810;
    goto v_3597;
v_3651:
    goto v_3715;
v_3711:
    v_3810 = stack[-2];
    v_3810 = qcar(v_3810);
    v_3811 = qcar(v_3810);
    goto v_3712;
v_3713:
    v_3810 = stack[-1];
    v_3810 = qcar(v_3810);
    v_3810 = qcar(v_3810);
    v_3810 = qcar(v_3810);
    goto v_3714;
v_3715:
    goto v_3711;
v_3712:
    goto v_3713;
v_3714:
    fn = elt(env, 4); // ordop
    v_3810 = (*qfn2(fn))(fn, v_3811, v_3810);
    env = stack[-4];
    if (v_3810 == nil) goto v_3709;
    goto v_3728;
v_3724:
    v_3810 = stack[-2];
    v_3811 = qcdr(v_3810);
    goto v_3725;
v_3726:
    v_3810 = stack[-1];
    goto v_3727;
v_3728:
    goto v_3724;
v_3725:
    goto v_3726;
v_3727:
    fn = elt(env, 3); // times!-mod!-p
    v_3811 = (*qfn2(fn))(fn, v_3811, v_3810);
    env = stack[-4];
    v_3810 = nil;
    v_3812 = v_3811;
    if (v_3812 == nil) goto v_3737;
    else goto v_3738;
v_3737:
    goto v_3736;
v_3738:
    goto v_3750;
v_3744:
    v_3812 = stack[-2];
    v_3812 = qcar(v_3812);
    goto v_3745;
v_3746:
    goto v_3747;
v_3748:
    goto v_3749;
v_3750:
    goto v_3744;
v_3745:
    goto v_3746;
v_3747:
    goto v_3748;
v_3749:
    v_3810 = acons(v_3812, v_3811, v_3810);
    env = stack[-4];
    goto v_3736;
    v_3810 = nil;
v_3736:
    v_3811 = v_3810;
    goto v_3598;
v_3709:
    goto v_3764;
v_3758:
    v_3810 = stack[-1];
    v_3810 = qcar(v_3810);
    stack[0] = qcar(v_3810);
    goto v_3759;
v_3760:
    goto v_3773;
v_3769:
    v_3811 = stack[-2];
    goto v_3770;
v_3771:
    v_3810 = stack[-1];
    v_3810 = qcar(v_3810);
    v_3810 = qcdr(v_3810);
    goto v_3772;
v_3773:
    goto v_3769;
v_3770:
    goto v_3771;
v_3772:
    v_3811 = CC_timesKtermKmodKp(elt(env, 0), v_3811, v_3810);
    env = stack[-4];
    goto v_3761;
v_3762:
    v_3810 = stack[-3];
    goto v_3763;
v_3764:
    goto v_3758;
v_3759:
    goto v_3760;
v_3761:
    goto v_3762;
v_3763:
    v_3810 = acons(stack[0], v_3811, v_3810);
    env = stack[-4];
    stack[-3] = v_3810;
    v_3810 = stack[-1];
    v_3810 = qcdr(v_3810);
    stack[-1] = v_3810;
    goto v_3597;
v_3598:
v_3783:
    v_3810 = stack[-3];
    if (v_3810 == nil) goto v_3786;
    else goto v_3787;
v_3786:
    goto v_3782;
v_3787:
    v_3810 = stack[-3];
    v_3810 = qcdr(v_3810);
    stack[0] = v_3810;
    v_3810 = stack[-3];
    v_3810 = qcar(v_3810);
    v_3810 = qcdr(v_3810);
    if (v_3810 == nil) goto v_3795;
    goto v_3804;
v_3800:
    v_3810 = stack[-3];
    goto v_3801;
v_3802:
    goto v_3803;
v_3804:
    goto v_3800;
v_3801:
    goto v_3802;
v_3803:
    v_3810 = Lrplacd(nil, v_3810, v_3811);
    env = stack[-4];
    v_3810 = stack[-3];
    v_3811 = v_3810;
    goto v_3793;
v_3795:
v_3793:
    v_3810 = stack[0];
    stack[-3] = v_3810;
    goto v_3783;
v_3782:
    v_3810 = v_3811;
    return onevalue(v_3810);
}



// Code for get_first_kernel

static LispObject CC_get_first_kernel(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3603, v_3604, v_3605;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3603 = v_3590;
    v_3604 = v_3589;
// end of prologue
    goto v_3599;
v_3593:
    v_3605 = v_3604;
    goto v_3594;
v_3595:
    v_3604 = v_3603;
    goto v_3596;
v_3597:
    v_3603 = nil;
    goto v_3598;
v_3599:
    goto v_3593;
v_3594:
    goto v_3595;
v_3596:
    goto v_3597;
v_3598:
    {
        fn = elt(env, 1); // gfk
        return (*qfnn(fn))(fn, 3, v_3605, v_3604, v_3603);
    }
}



// Code for lalr_precedence

static LispObject CC_lalr_precedence(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3610, v_3611;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3610 = v_3589;
// end of prologue
    goto v_3595;
v_3591:
    v_3611 = qvalue(elt(env, 1)); // precedence_table
    goto v_3592;
v_3593:
    goto v_3594;
v_3595:
    goto v_3591;
v_3592:
    goto v_3593;
v_3594:
    v_3610 = *(LispObject *)((char *)v_3611 + (CELL-TAG_VECTOR) + (((intptr_t)v_3610-TAG_FIXNUM)/(16/CELL)));
    v_3611 = v_3610;
    v_3610 = v_3611;
    if (v_3610 == nil) goto v_3603;
    v_3610 = v_3611;
    v_3610 = qcar(v_3610);
    goto v_3601;
v_3603:
    v_3610 = nil;
    goto v_3601;
    v_3610 = nil;
v_3601:
    return onevalue(v_3610);
}



// Code for anforml

static LispObject CC_anforml(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3682, v_3683;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3589;
// end of prologue
v_3595:
    v_3682 = stack[0];
    if (!consp(v_3682)) goto v_3598;
    else goto v_3599;
v_3598:
    goto v_3594;
v_3599:
    v_3682 = stack[0];
    v_3682 = qcar(v_3682);
    fn = elt(env, 5); // anform
    v_3682 = (*qfn1(fn))(fn, v_3682);
    env = stack[-1];
    v_3682 = stack[0];
    v_3682 = qcdr(v_3682);
    stack[0] = v_3682;
    goto v_3595;
v_3594:
    v_3682 = stack[0];
    if (v_3682 == nil) goto v_3610;
    v_3682 = qvalue(elt(env, 1)); // !*globals
    if (v_3682 == nil) goto v_3615;
    v_3682 = stack[0];
    if (v_3682 == nil) goto v_3615;
    goto v_3630;
v_3626:
    v_3683 = stack[0];
    goto v_3627;
v_3628:
    v_3682 = lisp_true;
    goto v_3629;
v_3630:
    goto v_3626;
v_3627:
    goto v_3628;
v_3629:
    if (v_3683 == v_3682) goto v_3625;
    v_3682 = stack[0];
    if (symbolp(v_3682)) goto v_3636;
    v_3682 = nil;
    goto v_3634;
v_3636:
    goto v_3645;
v_3641:
    v_3683 = stack[0];
    goto v_3642;
v_3643:
    v_3682 = qvalue(elt(env, 2)); // locls!*
    goto v_3644;
v_3645:
    goto v_3641;
v_3642:
    goto v_3643;
v_3644:
    v_3682 = Lassoc(nil, v_3683, v_3682);
    v_3682 = (v_3682 == nil ? lisp_true : nil);
    goto v_3634;
    v_3682 = nil;
v_3634:
    goto v_3623;
v_3625:
    v_3682 = nil;
    goto v_3623;
    v_3682 = nil;
v_3623:
    if (v_3682 == nil) goto v_3615;
    goto v_3662;
v_3658:
    v_3683 = stack[0];
    goto v_3659;
v_3660:
    v_3682 = elt(env, 3); // glb2rf
    goto v_3661;
v_3662:
    goto v_3658;
v_3659:
    goto v_3660;
v_3661:
    v_3682 = Lflagp(nil, v_3683, v_3682);
    env = stack[-1];
    if (v_3682 == nil) goto v_3655;
    else goto v_3656;
v_3655:
    goto v_3670;
v_3666:
    v_3682 = stack[0];
    v_3683 = ncons(v_3682);
    env = stack[-1];
    goto v_3667;
v_3668:
    v_3682 = elt(env, 3); // glb2rf
    goto v_3669;
v_3670:
    goto v_3666;
v_3667:
    goto v_3668;
v_3669:
    v_3682 = Lflag(nil, v_3683, v_3682);
    env = stack[-1];
    goto v_3679;
v_3675:
    v_3683 = stack[0];
    goto v_3676;
v_3677:
    v_3682 = qvalue(elt(env, 4)); // globs!*
    goto v_3678;
v_3679:
    goto v_3675;
v_3676:
    goto v_3677;
v_3678:
    v_3682 = cons(v_3683, v_3682);
    env = stack[-1];
    qvalue(elt(env, 4)) = v_3682; // globs!*
    goto v_3654;
v_3656:
v_3654:
    goto v_3613;
v_3615:
v_3613:
    goto v_3608;
v_3610:
v_3608:
    v_3682 = nil;
    return onevalue(v_3682);
}



// Code for totallessp

static LispObject CC_totallessp(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3607, v_3608;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3607 = v_3590;
    v_3608 = v_3589;
// end of prologue
    goto v_3596;
v_3592:
    goto v_3602;
v_3598:
    goto v_3599;
v_3600:
    goto v_3601;
v_3602:
    goto v_3598;
v_3599:
    goto v_3600;
v_3601:
    fn = elt(env, 2); // totalcompare
    v_3607 = (*qfn2(fn))(fn, v_3608, v_3607);
    env = stack[0];
    goto v_3593;
v_3594:
    v_3608 = elt(env, 1); // less
    goto v_3595;
v_3596:
    goto v_3592;
v_3593:
    goto v_3594;
v_3595:
    v_3607 = (v_3607 == v_3608 ? lisp_true : nil);
    return onevalue(v_3607);
}



// Code for talp_varlat

static LispObject CC_talp_varlat(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3603;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3589;
// end of prologue
    goto v_3596;
v_3592:
    v_3603 = stack[0];
    fn = elt(env, 1); // talp_arg2l
    v_3603 = (*qfn1(fn))(fn, v_3603);
    env = stack[-2];
    fn = elt(env, 2); // talp_varlt
    stack[-1] = (*qfn1(fn))(fn, v_3603);
    env = stack[-2];
    goto v_3593;
v_3594:
    v_3603 = stack[0];
    fn = elt(env, 3); // talp_arg2r
    v_3603 = (*qfn1(fn))(fn, v_3603);
    env = stack[-2];
    fn = elt(env, 2); // talp_varlt
    v_3603 = (*qfn1(fn))(fn, v_3603);
    env = stack[-2];
    goto v_3595;
v_3596:
    goto v_3592;
v_3593:
    goto v_3594;
v_3595:
    {
        LispObject v_3606 = stack[-1];
        fn = elt(env, 4); // union
        return (*qfn2(fn))(fn, v_3606, v_3603);
    }
}



// Code for ibalp_commonlenisone

static LispObject CC_ibalp_commonlenisone(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3615;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3590;
    stack[-1] = v_3589;
// end of prologue
    v_3615 = stack[-1];
    if (v_3615 == nil) goto v_3597;
    else goto v_3598;
v_3597:
    v_3615 = stack[0];
    fn = elt(env, 1); // ibalp_lenisone
    v_3615 = (*qfn1(fn))(fn, v_3615);
    env = stack[-2];
    goto v_3596;
v_3598:
    v_3615 = nil;
    goto v_3596;
    v_3615 = nil;
v_3596:
    if (v_3615 == nil) goto v_3594;
    else goto v_3593;
v_3594:
    v_3615 = stack[0];
    if (v_3615 == nil) goto v_3607;
    else goto v_3608;
v_3607:
    v_3615 = stack[-1];
    {
        fn = elt(env, 1); // ibalp_lenisone
        return (*qfn1(fn))(fn, v_3615);
    }
v_3608:
    v_3615 = nil;
    goto v_3606;
    v_3615 = nil;
v_3606:
v_3593:
    return onevalue(v_3615);
}



// Code for vdp_poly

static LispObject CC_vdp_poly(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3596;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3596 = v_3589;
// end of prologue
    v_3596 = qcdr(v_3596);
    v_3596 = qcdr(v_3596);
    v_3596 = qcdr(v_3596);
    v_3596 = qcar(v_3596);
    return onevalue(v_3596);
}



// Code for retattributes

static LispObject CC_retattributes(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3653, v_3654;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3590;
    stack[-1] = v_3589;
// end of prologue
v_3588:
    v_3653 = stack[0];
    if (v_3653 == nil) goto v_3597;
    else goto v_3598;
v_3597:
    goto v_3596;
v_3598:
    goto v_3608;
v_3604:
    v_3654 = stack[-1];
    goto v_3605;
v_3606:
    v_3653 = stack[0];
    v_3653 = qcar(v_3653);
    goto v_3607;
v_3608:
    goto v_3604;
v_3605:
    goto v_3606;
v_3607:
    fn = elt(env, 1); // find
    v_3653 = (*qfn2(fn))(fn, v_3654, v_3653);
    env = stack[-3];
    v_3654 = v_3653;
    if (v_3654 == nil) goto v_3615;
    goto v_3622;
v_3618:
    goto v_3628;
v_3624:
    v_3654 = stack[0];
    v_3654 = qcar(v_3654);
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    goto v_3624;
v_3625:
    goto v_3626;
v_3627:
    stack[-2] = list2(v_3654, v_3653);
    env = stack[-3];
    goto v_3619;
v_3620:
    goto v_3637;
v_3633:
    v_3654 = stack[-1];
    goto v_3634;
v_3635:
    v_3653 = stack[0];
    v_3653 = qcdr(v_3653);
    goto v_3636;
v_3637:
    goto v_3633;
v_3634:
    goto v_3635;
v_3636:
    v_3653 = CC_retattributes(elt(env, 0), v_3654, v_3653);
    goto v_3621;
v_3622:
    goto v_3618;
v_3619:
    goto v_3620;
v_3621:
    {
        LispObject v_3658 = stack[-2];
        return cons(v_3658, v_3653);
    }
v_3615:
    goto v_3648;
v_3644:
    v_3654 = stack[-1];
    goto v_3645;
v_3646:
    v_3653 = stack[0];
    v_3653 = qcdr(v_3653);
    goto v_3647;
v_3648:
    goto v_3644;
v_3645:
    goto v_3646;
v_3647:
    stack[-1] = v_3654;
    stack[0] = v_3653;
    goto v_3588;
    goto v_3596;
v_3596:
    v_3653 = nil;
    return onevalue(v_3653);
}



// Code for retimes1

static LispObject CC_retimes1(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3707, v_3708;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3589;
// end of prologue
    stack[-1] = nil;
v_3594:
    v_3707 = stack[0];
    if (v_3707 == nil) goto v_3597;
    else goto v_3598;
v_3597:
    v_3707 = stack[-1];
    {
        fn = elt(env, 4); // nreverse
        return (*qfn1(fn))(fn, v_3707);
    }
v_3598:
    goto v_3608;
v_3604:
    v_3707 = stack[0];
    v_3708 = qcar(v_3707);
    goto v_3605;
v_3606:
    v_3707 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3607;
v_3608:
    goto v_3604;
v_3605:
    goto v_3606;
v_3607:
    if (v_3708 == v_3707) goto v_3602;
    else goto v_3603;
v_3602:
    v_3707 = stack[0];
    v_3707 = qcdr(v_3707);
    stack[0] = v_3707;
    goto v_3594;
v_3603:
    v_3707 = stack[0];
    v_3707 = qcar(v_3707);
    v_3707 = Lminusp(nil, v_3707);
    env = stack[-2];
    if (v_3707 == nil) goto v_3615;
    v_3707 = qvalue(elt(env, 1)); // !*bool
    v_3707 = (v_3707 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v_3707; // !*bool
    goto v_3626;
v_3622:
    v_3707 = stack[0];
    v_3707 = qcar(v_3707);
    v_3708 = negate(v_3707);
    env = stack[-2];
    goto v_3623;
v_3624:
    v_3707 = stack[0];
    v_3707 = qcdr(v_3707);
    goto v_3625;
v_3626:
    goto v_3622;
v_3623:
    goto v_3624;
v_3625:
    v_3707 = cons(v_3708, v_3707);
    env = stack[-2];
    stack[0] = v_3707;
    goto v_3594;
v_3615:
    v_3707 = stack[0];
    v_3707 = qcar(v_3707);
    if (!consp(v_3707)) goto v_3632;
    else goto v_3633;
v_3632:
    goto v_3641;
v_3637:
    v_3707 = stack[0];
    v_3708 = qcar(v_3707);
    goto v_3638;
v_3639:
    v_3707 = stack[-1];
    goto v_3640;
v_3641:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    v_3707 = cons(v_3708, v_3707);
    env = stack[-2];
    stack[-1] = v_3707;
    v_3707 = stack[0];
    v_3707 = qcdr(v_3707);
    stack[0] = v_3707;
    goto v_3594;
v_3633:
    goto v_3653;
v_3649:
    v_3707 = stack[0];
    v_3707 = qcar(v_3707);
    v_3708 = qcar(v_3707);
    goto v_3650;
v_3651:
    v_3707 = elt(env, 2); // minus
    goto v_3652;
v_3653:
    goto v_3649;
v_3650:
    goto v_3651;
v_3652:
    if (v_3708 == v_3707) goto v_3647;
    else goto v_3648;
v_3647:
    v_3707 = qvalue(elt(env, 1)); // !*bool
    v_3707 = (v_3707 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v_3707; // !*bool
    goto v_3665;
v_3661:
    v_3707 = stack[0];
    v_3707 = qcar(v_3707);
    v_3707 = qcdr(v_3707);
    v_3708 = qcar(v_3707);
    goto v_3662;
v_3663:
    v_3707 = stack[0];
    v_3707 = qcdr(v_3707);
    goto v_3664;
v_3665:
    goto v_3661;
v_3662:
    goto v_3663;
v_3664:
    v_3707 = cons(v_3708, v_3707);
    env = stack[-2];
    stack[0] = v_3707;
    goto v_3594;
v_3648:
    goto v_3678;
v_3674:
    v_3707 = stack[0];
    v_3707 = qcar(v_3707);
    v_3708 = qcar(v_3707);
    goto v_3675;
v_3676:
    v_3707 = elt(env, 3); // times
    goto v_3677;
v_3678:
    goto v_3674;
v_3675:
    goto v_3676;
v_3677:
    if (v_3708 == v_3707) goto v_3672;
    else goto v_3673;
v_3672:
    goto v_3688;
v_3684:
    v_3707 = stack[0];
    v_3707 = qcar(v_3707);
    v_3708 = qcdr(v_3707);
    goto v_3685;
v_3686:
    v_3707 = stack[0];
    v_3707 = qcdr(v_3707);
    goto v_3687;
v_3688:
    goto v_3684;
v_3685:
    goto v_3686;
v_3687:
    v_3707 = Lappend(nil, v_3708, v_3707);
    env = stack[-2];
    stack[0] = v_3707;
    goto v_3594;
v_3673:
    goto v_3701;
v_3697:
    v_3707 = stack[0];
    v_3708 = qcar(v_3707);
    goto v_3698;
v_3699:
    v_3707 = stack[-1];
    goto v_3700;
v_3701:
    goto v_3697;
v_3698:
    goto v_3699;
v_3700:
    v_3707 = cons(v_3708, v_3707);
    env = stack[-2];
    stack[-1] = v_3707;
    v_3707 = stack[0];
    v_3707 = qcdr(v_3707);
    stack[0] = v_3707;
    goto v_3594;
    v_3707 = nil;
    return onevalue(v_3707);
}



// Code for variables

static LispObject CC_variables(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3734, v_3735;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_3589;
// end of prologue
    v_3734 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_3734;
    v_3734 = stack[-5];
    if (v_3734 == nil) goto v_3606;
    else goto v_3607;
v_3606:
    v_3734 = nil;
    goto v_3598;
v_3607:
    v_3734 = qvalue(elt(env, 1)); // dipvars!*
    v_3734 = Llength(nil, v_3734);
    env = stack[-7];
    stack[-6] = v_3734;
    v_3734 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_3734;
    goto v_3629;
v_3625:
    v_3735 = stack[-6];
    goto v_3626;
v_3627:
    v_3734 = stack[-3];
    goto v_3628;
v_3629:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    v_3734 = difference2(v_3735, v_3734);
    env = stack[-7];
    v_3734 = Lminusp(nil, v_3734);
    env = stack[-7];
    if (v_3734 == nil) goto v_3622;
    v_3734 = nil;
    goto v_3616;
v_3622:
    v_3734 = nil;
    v_3734 = ncons(v_3734);
    env = stack[-7];
    stack[-1] = v_3734;
    stack[-2] = v_3734;
v_3617:
    v_3734 = stack[-3];
    v_3734 = add1(v_3734);
    env = stack[-7];
    stack[-3] = v_3734;
    goto v_3647;
v_3643:
    v_3735 = stack[-6];
    goto v_3644;
v_3645:
    v_3734 = stack[-3];
    goto v_3646;
v_3647:
    goto v_3643;
v_3644:
    goto v_3645;
v_3646:
    v_3734 = difference2(v_3735, v_3734);
    env = stack[-7];
    v_3734 = Lminusp(nil, v_3734);
    env = stack[-7];
    if (v_3734 == nil) goto v_3640;
    v_3734 = stack[-2];
    goto v_3616;
v_3640:
    goto v_3656;
v_3652:
    stack[0] = stack[-1];
    goto v_3653;
v_3654:
    v_3734 = nil;
    v_3734 = ncons(v_3734);
    env = stack[-7];
    goto v_3655;
v_3656:
    goto v_3652;
v_3653:
    goto v_3654;
v_3655:
    v_3734 = Lrplacd(nil, stack[0], v_3734);
    env = stack[-7];
    v_3734 = stack[-1];
    v_3734 = qcdr(v_3734);
    stack[-1] = v_3734;
    goto v_3617;
v_3616:
    stack[0] = v_3734;
v_3599:
    v_3734 = stack[-5];
    v_3734 = qcar(v_3734);
    v_3734 = qcdr(v_3734);
    v_3734 = qcdr(v_3734);
    v_3734 = qcdr(v_3734);
    v_3734 = qcar(v_3734);
    stack[-2] = v_3734;
v_3600:
    v_3734 = stack[-2];
    v_3734 = qcar(v_3734);
    stack[-3] = v_3734;
    v_3734 = stack[0];
    stack[-1] = v_3734;
v_3601:
    goto v_3680;
v_3676:
    v_3734 = stack[-3];
    v_3735 = qcar(v_3734);
    goto v_3677;
v_3678:
    v_3734 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3679;
v_3680:
    goto v_3676;
v_3677:
    goto v_3678;
v_3679:
    if (((intptr_t)(v_3735)) > ((intptr_t)(v_3734))) goto v_3675;
    else goto v_3674;
v_3675:
    v_3734 = stack[-1];
    v_3734 = qcar(v_3734);
    if (v_3734 == nil) goto v_3684;
    else goto v_3674;
v_3684:
    goto v_3692;
v_3688:
    v_3735 = stack[-1];
    goto v_3689;
v_3690:
    v_3734 = lisp_true;
    goto v_3691;
v_3692:
    goto v_3688;
v_3689:
    goto v_3690;
v_3691:
    fn = elt(env, 2); // setcar
    v_3734 = (*qfn2(fn))(fn, v_3735, v_3734);
    env = stack[-7];
    v_3734 = stack[-4];
    v_3734 = (LispObject)((intptr_t)(v_3734) + 0x10);
    stack[-4] = v_3734;
    goto v_3672;
v_3674:
v_3672:
    goto v_3705;
v_3701:
    v_3735 = stack[-4];
    goto v_3702;
v_3703:
    v_3734 = stack[-6];
    goto v_3704;
v_3705:
    goto v_3701;
v_3702:
    goto v_3703;
v_3704:
    if (v_3735 == v_3734) goto v_3699;
    else goto v_3700;
v_3699:
    v_3734 = stack[0];
    goto v_3598;
v_3700:
    v_3734 = stack[-3];
    v_3734 = qcdr(v_3734);
    stack[-3] = v_3734;
    v_3734 = stack[-3];
    if (v_3734 == nil) goto v_3714;
    v_3734 = stack[-1];
    v_3734 = qcdr(v_3734);
    stack[-1] = v_3734;
    goto v_3601;
v_3714:
    v_3734 = stack[-2];
    v_3734 = qcdr(v_3734);
    v_3734 = qcdr(v_3734);
    stack[-2] = v_3734;
    v_3734 = stack[-2];
    if (v_3734 == nil) goto v_3724;
    goto v_3600;
v_3724:
    v_3734 = stack[-5];
    v_3734 = qcdr(v_3734);
    stack[-5] = v_3734;
    v_3734 = stack[-5];
    if (v_3734 == nil) goto v_3731;
    goto v_3599;
v_3731:
    v_3734 = stack[0];
v_3598:
    return onevalue(v_3734);
}



// Code for worderp

static LispObject CC_worderp(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3758, v_3759, v_3760;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3590;
    stack[-1] = v_3589;
// end of prologue
v_3588:
v_3594:
    v_3758 = stack[-1];
    if (!consp(v_3758)) goto v_3602;
    v_3758 = stack[-1];
    v_3758 = qcar(v_3758);
    if (!symbolp(v_3758)) v_3758 = nil;
    else { v_3758 = qfastgets(v_3758);
           if (v_3758 != nil) { v_3758 = elt(v_3758, 16); // indexvar
#ifdef RECORD_GET
             if (v_3758 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_3758 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_3758 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_3758 == SPID_NOPROP) v_3758 = nil; else v_3758 = lisp_true; }}
#endif
    if (v_3758 == nil) goto v_3607;
    v_3758 = stack[0];
    if (!consp(v_3758)) goto v_3614;
    v_3758 = stack[0];
    v_3758 = qcar(v_3758);
    if (!symbolp(v_3758)) v_3758 = nil;
    else { v_3758 = qfastgets(v_3758);
           if (v_3758 != nil) { v_3758 = elt(v_3758, 16); // indexvar
#ifdef RECORD_GET
             if (v_3758 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_3758 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_3758 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_3758 == SPID_NOPROP) v_3758 = nil; else v_3758 = lisp_true; }}
#endif
    goto v_3612;
v_3614:
    v_3758 = nil;
    goto v_3612;
    v_3758 = nil;
v_3612:
    goto v_3605;
v_3607:
    v_3758 = nil;
    goto v_3605;
    v_3758 = nil;
v_3605:
    goto v_3600;
v_3602:
    v_3758 = nil;
    goto v_3600;
    v_3758 = nil;
v_3600:
    if (v_3758 == nil) goto v_3598;
    goto v_3633;
v_3629:
    v_3759 = stack[-1];
    goto v_3630;
v_3631:
    v_3758 = stack[0];
    goto v_3632;
v_3633:
    goto v_3629;
v_3630:
    goto v_3631;
v_3632:
    {
        fn = elt(env, 2); // indexvarordp
        return (*qfn2(fn))(fn, v_3759, v_3758);
    }
v_3598:
    v_3758 = stack[-1];
    if (!consp(v_3758)) goto v_3640;
    else goto v_3641;
v_3640:
    v_3758 = lisp_true;
    goto v_3639;
v_3641:
    goto v_3650;
v_3646:
    v_3759 = stack[-1];
    goto v_3647;
v_3648:
    v_3758 = qvalue(elt(env, 1)); // kord!*
    goto v_3649;
v_3650:
    goto v_3646;
v_3647:
    goto v_3648;
v_3649:
    v_3758 = Lmemq(nil, v_3759, v_3758);
    goto v_3639;
    v_3758 = nil;
v_3639:
    if (v_3758 == nil) goto v_3637;
    v_3758 = stack[0];
    if (!consp(v_3758)) goto v_3660;
    else goto v_3661;
v_3660:
    v_3758 = lisp_true;
    goto v_3659;
v_3661:
    goto v_3670;
v_3666:
    v_3759 = stack[0];
    goto v_3667;
v_3668:
    v_3758 = qvalue(elt(env, 1)); // kord!*
    goto v_3669;
v_3670:
    goto v_3666;
v_3667:
    goto v_3668;
v_3669:
    v_3758 = Lmemq(nil, v_3759, v_3758);
    goto v_3659;
    v_3758 = nil;
v_3659:
    if (v_3758 == nil) goto v_3657;
    goto v_3679;
v_3675:
    v_3759 = stack[-1];
    goto v_3676;
v_3677:
    v_3758 = stack[0];
    goto v_3678;
v_3679:
    goto v_3675;
v_3676:
    goto v_3677;
v_3678:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_3759, v_3758);
    }
v_3657:
    v_3758 = stack[0];
    fn = elt(env, 4); // peel
    v_3758 = (*qfn1(fn))(fn, v_3758);
    env = stack[-2];
    v_3760 = v_3758;
    goto v_3695;
v_3691:
    v_3759 = stack[-1];
    goto v_3692;
v_3693:
    v_3758 = v_3760;
    goto v_3694;
v_3695:
    goto v_3691;
v_3692:
    goto v_3693;
v_3694:
    if (v_3759 == v_3758) goto v_3689;
    else goto v_3690;
v_3689:
    v_3758 = lisp_true;
    goto v_3688;
v_3690:
    goto v_3706;
v_3702:
    v_3758 = stack[-1];
    goto v_3703;
v_3704:
    v_3759 = v_3760;
    goto v_3705;
v_3706:
    goto v_3702;
v_3703:
    goto v_3704;
v_3705:
    stack[-1] = v_3758;
    stack[0] = v_3759;
    goto v_3588;
    v_3758 = nil;
v_3688:
    goto v_3593;
    goto v_3596;
v_3637:
    v_3758 = stack[0];
    if (!consp(v_3758)) goto v_3713;
    else goto v_3714;
v_3713:
    v_3758 = lisp_true;
    goto v_3712;
v_3714:
    goto v_3723;
v_3719:
    v_3759 = stack[0];
    goto v_3720;
v_3721:
    v_3758 = qvalue(elt(env, 1)); // kord!*
    goto v_3722;
v_3723:
    goto v_3719;
v_3720:
    goto v_3721;
v_3722:
    v_3758 = Lmemq(nil, v_3759, v_3758);
    goto v_3712;
    v_3758 = nil;
v_3712:
    if (v_3758 == nil) goto v_3710;
    v_3758 = stack[-1];
    fn = elt(env, 4); // peel
    v_3758 = (*qfn1(fn))(fn, v_3758);
    env = stack[-2];
    v_3760 = v_3758;
    goto v_3738;
v_3734:
    v_3759 = v_3760;
    goto v_3735;
v_3736:
    v_3758 = stack[0];
    goto v_3737;
v_3738:
    goto v_3734;
v_3735:
    goto v_3736;
v_3737:
    if (v_3759 == v_3758) goto v_3732;
    else goto v_3733;
v_3732:
    v_3758 = nil;
    goto v_3731;
v_3733:
    goto v_3749;
v_3745:
    v_3759 = v_3760;
    goto v_3746;
v_3747:
    v_3758 = stack[0];
    goto v_3748;
v_3749:
    goto v_3745;
v_3746:
    goto v_3747;
v_3748:
    stack[-1] = v_3759;
    stack[0] = v_3758;
    goto v_3588;
    v_3758 = nil;
v_3731:
    goto v_3593;
v_3710:
    v_3758 = stack[-1];
    fn = elt(env, 4); // peel
    v_3758 = (*qfn1(fn))(fn, v_3758);
    env = stack[-2];
    stack[-1] = v_3758;
    v_3758 = stack[0];
    fn = elt(env, 4); // peel
    v_3758 = (*qfn1(fn))(fn, v_3758);
    env = stack[-2];
    stack[0] = v_3758;
    goto v_3594;
v_3596:
    v_3758 = nil;
v_3593:
    return onevalue(v_3758);
}



// Code for evaluate0

static LispObject CC_evaluate0(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3601, v_3602;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3590;
    v_3601 = v_3589;
// end of prologue
    goto v_3597;
v_3593:
    fn = elt(env, 1); // evaluate!-horner
    v_3602 = (*qfn1(fn))(fn, v_3601);
    env = stack[-1];
    goto v_3594;
v_3595:
    v_3601 = stack[0];
    goto v_3596;
v_3597:
    goto v_3593;
v_3594:
    goto v_3595;
v_3596:
    {
        fn = elt(env, 2); // evaluate1
        return (*qfn2(fn))(fn, v_3602, v_3601);
    }
}



// Code for eofcheck

static LispObject CC_eofcheck(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3620, v_3621;
    argcheck(nargs, 0, "eofcheck");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
    stack_popper stack_popper_var(1);
// end of prologue
    goto v_3598;
v_3594:
    v_3621 = qvalue(elt(env, 1)); // program!*
    goto v_3595;
v_3596:
    v_3620 = qvalue(elt(env, 2)); // !$eof!$
    goto v_3597;
v_3598:
    goto v_3594;
v_3595:
    goto v_3596;
v_3597:
    if (v_3621 == v_3620) goto v_3592;
    else goto v_3593;
v_3592:
    goto v_3609;
v_3605:
    v_3621 = qvalue(elt(env, 3)); // ttype!*
    goto v_3606;
v_3607:
    v_3620 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_3608;
v_3609:
    goto v_3605;
v_3606:
    goto v_3607;
v_3608:
    if (v_3621 == v_3620) goto v_3603;
    else goto v_3604;
v_3603:
    v_3620 = qvalue(elt(env, 4)); // eof!*
    v_3620 = add1(v_3620);
    env = stack[0];
    qvalue(elt(env, 4)) = v_3620; // eof!*
    goto v_3602;
v_3604:
    v_3620 = nil;
    goto v_3602;
    v_3620 = nil;
v_3602:
    goto v_3591;
v_3593:
    v_3620 = nil;
    goto v_3591;
    v_3620 = nil;
v_3591:
    return onevalue(v_3620);
}



// Code for simpplus

static LispObject CC_simpplus(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3634, v_3635;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3589;
// end of prologue
    goto v_3603;
v_3599:
    v_3634 = stack[0];
    v_3635 = Llength(nil, v_3634);
    env = stack[-2];
    goto v_3600;
v_3601:
    v_3634 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3602;
v_3603:
    goto v_3599;
v_3600:
    goto v_3601;
v_3602:
    if (v_3635 == v_3634) goto v_3597;
    else goto v_3598;
v_3597:
    v_3634 = stack[0];
    fn = elt(env, 1); // ckpreci!#
    v_3634 = (*qfn1(fn))(fn, v_3634);
    env = stack[-2];
    goto v_3596;
v_3598:
v_3596:
    goto v_3614;
v_3610:
    v_3635 = nil;
    goto v_3611;
v_3612:
    v_3634 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3613;
v_3614:
    goto v_3610;
v_3611:
    goto v_3612;
v_3613:
    v_3634 = cons(v_3635, v_3634);
    env = stack[-2];
    stack[-1] = v_3634;
v_3594:
    v_3634 = stack[0];
    if (v_3634 == nil) goto v_3619;
    else goto v_3620;
v_3619:
    v_3634 = stack[-1];
    goto v_3593;
v_3620:
    goto v_3628;
v_3624:
    v_3634 = stack[0];
    fn = elt(env, 2); // simpcar
    v_3635 = (*qfn1(fn))(fn, v_3634);
    env = stack[-2];
    goto v_3625;
v_3626:
    v_3634 = stack[-1];
    goto v_3627;
v_3628:
    goto v_3624;
v_3625:
    goto v_3626;
v_3627:
    fn = elt(env, 3); // addsq
    v_3634 = (*qfn2(fn))(fn, v_3635, v_3634);
    env = stack[-2];
    stack[-1] = v_3634;
    v_3634 = stack[0];
    v_3634 = qcdr(v_3634);
    stack[0] = v_3634;
    goto v_3594;
v_3593:
    return onevalue(v_3634);
}



// Code for dp_ecart

static LispObject CC_dp_ecart(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3610;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3589;
// end of prologue
    v_3610 = stack[0];
    if (v_3610 == nil) goto v_3593;
    else goto v_3594;
v_3593:
    v_3610 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3592;
v_3594:
    goto v_3604;
v_3600:
    v_3610 = stack[0];
    fn = elt(env, 1); // dp!=ecart
    stack[-1] = (*qfn1(fn))(fn, v_3610);
    env = stack[-2];
    goto v_3601;
v_3602:
    v_3610 = stack[0];
    fn = elt(env, 2); // dp_lmon
    v_3610 = (*qfn1(fn))(fn, v_3610);
    env = stack[-2];
    fn = elt(env, 3); // mo_ecart
    v_3610 = (*qfn1(fn))(fn, v_3610);
    goto v_3603;
v_3604:
    goto v_3600;
v_3601:
    goto v_3602;
v_3603:
    {
        LispObject v_3613 = stack[-1];
        return difference2(v_3613, v_3610);
    }
    v_3610 = nil;
v_3592:
    return onevalue(v_3610);
}



// Code for pdmult

static LispObject CC_pdmult(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3778, v_3779;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_3590;
    v_3778 = v_3589;
// end of prologue
    stack[-9] = v_3778;
    v_3778 = stack[-9];
    if (v_3778 == nil) goto v_3601;
    else goto v_3602;
v_3601:
    v_3778 = nil;
    goto v_3596;
v_3602:
    v_3778 = stack[-9];
    v_3778 = qcar(v_3778);
    stack[-4] = v_3778;
    goto v_3614;
v_3610:
    goto v_3626;
v_3622:
    v_3778 = stack[-4];
    v_3779 = qcar(v_3778);
    goto v_3623;
v_3624:
    v_3778 = stack[-8];
    goto v_3625;
v_3626:
    goto v_3622;
v_3623:
    goto v_3624;
v_3625:
    fn = elt(env, 1); // pair
    v_3778 = (*qfn2(fn))(fn, v_3779, v_3778);
    env = stack[-10];
    stack[-3] = v_3778;
    v_3778 = stack[-3];
    if (v_3778 == nil) goto v_3632;
    else goto v_3633;
v_3632:
    v_3778 = nil;
    v_3779 = v_3778;
    goto v_3619;
v_3633:
    v_3778 = stack[-3];
    v_3778 = qcar(v_3778);
    goto v_3644;
v_3640:
    v_3779 = v_3778;
    v_3779 = qcar(v_3779);
    goto v_3641;
v_3642:
    v_3778 = qcdr(v_3778);
    goto v_3643;
v_3644:
    goto v_3640;
v_3641:
    goto v_3642;
v_3643:
    v_3778 = (LispObject)(intptr_t)((intptr_t)v_3779 + (intptr_t)v_3778 - TAG_FIXNUM);
    v_3778 = ncons(v_3778);
    env = stack[-10];
    stack[-1] = v_3778;
    stack[-2] = v_3778;
v_3620:
    v_3778 = stack[-3];
    v_3778 = qcdr(v_3778);
    stack[-3] = v_3778;
    v_3778 = stack[-3];
    if (v_3778 == nil) goto v_3654;
    else goto v_3655;
v_3654:
    v_3778 = stack[-2];
    v_3779 = v_3778;
    goto v_3619;
v_3655:
    goto v_3663;
v_3659:
    stack[0] = stack[-1];
    goto v_3660;
v_3661:
    v_3778 = stack[-3];
    v_3778 = qcar(v_3778);
    goto v_3673;
v_3669:
    v_3779 = v_3778;
    v_3779 = qcar(v_3779);
    goto v_3670;
v_3671:
    v_3778 = qcdr(v_3778);
    goto v_3672;
v_3673:
    goto v_3669;
v_3670:
    goto v_3671;
v_3672:
    v_3778 = (LispObject)(intptr_t)((intptr_t)v_3779 + (intptr_t)v_3778 - TAG_FIXNUM);
    v_3778 = ncons(v_3778);
    env = stack[-10];
    goto v_3662;
v_3663:
    goto v_3659;
v_3660:
    goto v_3661;
v_3662:
    v_3778 = Lrplacd(nil, stack[0], v_3778);
    env = stack[-10];
    v_3778 = stack[-1];
    v_3778 = qcdr(v_3778);
    stack[-1] = v_3778;
    goto v_3620;
v_3619:
    goto v_3611;
v_3612:
    v_3778 = stack[-4];
    v_3778 = qcdr(v_3778);
    goto v_3613;
v_3614:
    goto v_3610;
v_3611:
    goto v_3612;
v_3613:
    v_3778 = cons(v_3779, v_3778);
    env = stack[-10];
    v_3778 = ncons(v_3778);
    env = stack[-10];
    stack[-6] = v_3778;
    stack[-7] = v_3778;
v_3597:
    v_3778 = stack[-9];
    v_3778 = qcdr(v_3778);
    stack[-9] = v_3778;
    v_3778 = stack[-9];
    if (v_3778 == nil) goto v_3687;
    else goto v_3688;
v_3687:
    v_3778 = stack[-7];
    goto v_3596;
v_3688:
    goto v_3696;
v_3692:
    stack[-5] = stack[-6];
    goto v_3693;
v_3694:
    v_3778 = stack[-9];
    v_3778 = qcar(v_3778);
    stack[-4] = v_3778;
    goto v_3707;
v_3703:
    goto v_3719;
v_3715:
    v_3778 = stack[-4];
    v_3779 = qcar(v_3778);
    goto v_3716;
v_3717:
    v_3778 = stack[-8];
    goto v_3718;
v_3719:
    goto v_3715;
v_3716:
    goto v_3717;
v_3718:
    fn = elt(env, 1); // pair
    v_3778 = (*qfn2(fn))(fn, v_3779, v_3778);
    env = stack[-10];
    stack[-3] = v_3778;
    v_3778 = stack[-3];
    if (v_3778 == nil) goto v_3725;
    else goto v_3726;
v_3725:
    v_3778 = nil;
    v_3779 = v_3778;
    goto v_3712;
v_3726:
    v_3778 = stack[-3];
    v_3778 = qcar(v_3778);
    goto v_3737;
v_3733:
    v_3779 = v_3778;
    v_3779 = qcar(v_3779);
    goto v_3734;
v_3735:
    v_3778 = qcdr(v_3778);
    goto v_3736;
v_3737:
    goto v_3733;
v_3734:
    goto v_3735;
v_3736:
    v_3778 = (LispObject)(intptr_t)((intptr_t)v_3779 + (intptr_t)v_3778 - TAG_FIXNUM);
    v_3778 = ncons(v_3778);
    env = stack[-10];
    stack[-1] = v_3778;
    stack[-2] = v_3778;
v_3713:
    v_3778 = stack[-3];
    v_3778 = qcdr(v_3778);
    stack[-3] = v_3778;
    v_3778 = stack[-3];
    if (v_3778 == nil) goto v_3747;
    else goto v_3748;
v_3747:
    v_3778 = stack[-2];
    v_3779 = v_3778;
    goto v_3712;
v_3748:
    goto v_3756;
v_3752:
    stack[0] = stack[-1];
    goto v_3753;
v_3754:
    v_3778 = stack[-3];
    v_3778 = qcar(v_3778);
    goto v_3766;
v_3762:
    v_3779 = v_3778;
    v_3779 = qcar(v_3779);
    goto v_3763;
v_3764:
    v_3778 = qcdr(v_3778);
    goto v_3765;
v_3766:
    goto v_3762;
v_3763:
    goto v_3764;
v_3765:
    v_3778 = (LispObject)(intptr_t)((intptr_t)v_3779 + (intptr_t)v_3778 - TAG_FIXNUM);
    v_3778 = ncons(v_3778);
    env = stack[-10];
    goto v_3755;
v_3756:
    goto v_3752;
v_3753:
    goto v_3754;
v_3755:
    v_3778 = Lrplacd(nil, stack[0], v_3778);
    env = stack[-10];
    v_3778 = stack[-1];
    v_3778 = qcdr(v_3778);
    stack[-1] = v_3778;
    goto v_3713;
v_3712:
    goto v_3704;
v_3705:
    v_3778 = stack[-4];
    v_3778 = qcdr(v_3778);
    goto v_3706;
v_3707:
    goto v_3703;
v_3704:
    goto v_3705;
v_3706:
    v_3778 = cons(v_3779, v_3778);
    env = stack[-10];
    v_3778 = ncons(v_3778);
    env = stack[-10];
    goto v_3695;
v_3696:
    goto v_3692;
v_3693:
    goto v_3694;
v_3695:
    v_3778 = Lrplacd(nil, stack[-5], v_3778);
    env = stack[-10];
    v_3778 = stack[-6];
    v_3778 = qcdr(v_3778);
    stack[-6] = v_3778;
    goto v_3597;
v_3596:
    return onevalue(v_3778);
}



// Code for divide!:

static LispObject CC_divideT(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3656, v_3657;
    LispObject fn;
    LispObject v_3591, v_3590, v_3589;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "divide:");
    va_start(aa, nargs);
    v_3589 = va_arg(aa, LispObject);
    v_3590 = va_arg(aa, LispObject);
    v_3591 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3591,v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3589,v_3590,v_3591);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_3591;
    stack[-2] = v_3590;
    stack[-3] = v_3589;
// end of prologue
    goto v_3600;
v_3596:
    goto v_3597;
v_3598:
    goto v_3607;
v_3603:
    stack[0] = stack[-1];
    goto v_3604;
v_3605:
    v_3656 = stack[-2];
    v_3656 = qcdr(v_3656);
    v_3656 = qcar(v_3656);
    v_3656 = Labsval(nil, v_3656);
    env = stack[-5];
    fn = elt(env, 2); // msd
    v_3656 = (*qfn1(fn))(fn, v_3656);
    env = stack[-5];
    v_3656 = add1(v_3656);
    env = stack[-5];
    goto v_3606;
v_3607:
    goto v_3603;
v_3604:
    goto v_3605;
v_3606:
    v_3656 = plus2(stack[0], v_3656);
    env = stack[-5];
    goto v_3599;
v_3600:
    goto v_3596;
v_3597:
    goto v_3598;
v_3599:
    fn = elt(env, 3); // conv!:mt
    v_3656 = (*qfn2(fn))(fn, stack[-3], v_3656);
    env = stack[-5];
    stack[-3] = v_3656;
    goto v_3622;
v_3616:
    stack[-4] = elt(env, 1); // !:rd!:
    goto v_3617;
v_3618:
    goto v_3629;
v_3625:
    v_3656 = stack[-3];
    v_3656 = qcdr(v_3656);
    v_3657 = qcar(v_3656);
    goto v_3626;
v_3627:
    v_3656 = stack[-2];
    v_3656 = qcdr(v_3656);
    v_3656 = qcar(v_3656);
    goto v_3628;
v_3629:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    stack[0] = quot2(v_3657, v_3656);
    env = stack[-5];
    goto v_3619;
v_3620:
    goto v_3641;
v_3637:
    v_3656 = stack[-3];
    v_3656 = qcdr(v_3656);
    v_3657 = qcdr(v_3656);
    goto v_3638;
v_3639:
    v_3656 = stack[-2];
    v_3656 = qcdr(v_3656);
    v_3656 = qcdr(v_3656);
    goto v_3640;
v_3641:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    v_3656 = difference2(v_3657, v_3656);
    env = stack[-5];
    goto v_3621;
v_3622:
    goto v_3616;
v_3617:
    goto v_3618;
v_3619:
    goto v_3620;
v_3621:
    v_3656 = list2star(stack[-4], stack[0], v_3656);
    env = stack[-5];
    stack[-3] = v_3656;
    goto v_3653;
v_3649:
    v_3657 = stack[-3];
    goto v_3650;
v_3651:
    v_3656 = stack[-1];
    goto v_3652;
v_3653:
    goto v_3649;
v_3650:
    goto v_3651;
v_3652:
    {
        fn = elt(env, 4); // round!:mt
        return (*qfn2(fn))(fn, v_3657, v_3656);
    }
    return onevalue(v_3656);
}



// Code for cancel

static LispObject CC_cancel(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3665, v_3666;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3589;
// end of prologue
    v_3665 = qvalue(elt(env, 1)); // !*mcd
    if (v_3665 == nil) goto v_3595;
    else goto v_3593;
v_3595:
    goto v_3602;
v_3598:
    v_3665 = stack[0];
    v_3666 = qcdr(v_3665);
    goto v_3599;
v_3600:
    v_3665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3601;
v_3602:
    goto v_3598;
v_3599:
    goto v_3600;
v_3601:
    if (v_3666 == v_3665) goto v_3593;
    goto v_3594;
v_3593:
    goto v_3611;
v_3607:
    goto v_3617;
v_3613:
    v_3665 = stack[0];
    v_3666 = qcar(v_3665);
    goto v_3614;
v_3615:
    v_3665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3616;
v_3617:
    goto v_3613;
v_3614:
    goto v_3615;
v_3616:
    stack[-1] = cons(v_3666, v_3665);
    env = stack[-2];
    goto v_3608;
v_3609:
    goto v_3626;
v_3622:
    v_3666 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3623;
v_3624:
    v_3665 = stack[0];
    v_3665 = qcdr(v_3665);
    goto v_3625;
v_3626:
    goto v_3622;
v_3623:
    goto v_3624;
v_3625:
    v_3665 = cons(v_3666, v_3665);
    env = stack[-2];
    goto v_3610;
v_3611:
    goto v_3607;
v_3608:
    goto v_3609;
v_3610:
    {
        LispObject v_3669 = stack[-1];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_3669, v_3665);
    }
v_3594:
    goto v_3637;
v_3633:
    goto v_3643;
v_3639:
    v_3665 = stack[0];
    v_3666 = qcar(v_3665);
    goto v_3640;
v_3641:
    v_3665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3642;
v_3643:
    goto v_3639;
v_3640:
    goto v_3641;
v_3642:
    stack[-1] = cons(v_3666, v_3665);
    env = stack[-2];
    goto v_3634;
v_3635:
    goto v_3653;
v_3649:
    goto v_3660;
v_3656:
    v_3665 = stack[0];
    v_3666 = qcdr(v_3665);
    goto v_3657;
v_3658:
    v_3665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3659;
v_3660:
    goto v_3656;
v_3657:
    goto v_3658;
v_3659:
    v_3665 = cons(v_3666, v_3665);
    env = stack[-2];
    fn = elt(env, 3); // mk!*sq
    v_3666 = (*qfn1(fn))(fn, v_3665);
    env = stack[-2];
    goto v_3650;
v_3651:
    v_3665 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_3652;
v_3653:
    goto v_3649;
v_3650:
    goto v_3651;
v_3652:
    v_3665 = list2(v_3666, v_3665);
    env = stack[-2];
    fn = elt(env, 4); // simpexpt
    v_3665 = (*qfn1(fn))(fn, v_3665);
    env = stack[-2];
    goto v_3636;
v_3637:
    goto v_3633;
v_3634:
    goto v_3635;
v_3636:
    {
        LispObject v_3670 = stack[-1];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_3670, v_3665);
    }
    v_3665 = nil;
    return onevalue(v_3665);
}



// Code for canonsq

static LispObject CC_canonsq(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3826, v_3827, v_3828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_3589;
// end of prologue
    goto v_3599;
v_3595:
    v_3826 = stack[-2];
    v_3827 = qcdr(v_3826);
    goto v_3596;
v_3597:
    v_3826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3598;
v_3599:
    goto v_3595;
v_3596:
    goto v_3597;
v_3598:
    if (v_3827 == v_3826) goto v_3593;
    else goto v_3594;
v_3593:
    v_3826 = stack[-2];
    goto v_3592;
v_3594:
    v_3826 = stack[-2];
    v_3826 = qcar(v_3826);
    if (v_3826 == nil) goto v_3604;
    else goto v_3605;
v_3604:
    goto v_3613;
v_3609:
    v_3827 = nil;
    goto v_3610;
v_3611:
    v_3826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3612;
v_3613:
    goto v_3609;
v_3610:
    goto v_3611;
v_3612:
    return cons(v_3827, v_3826);
v_3605:
    stack[-1] = nil;
    v_3826 = qvalue(elt(env, 1)); // asymplis!*
    if (v_3826 == nil) goto v_3625;
    goto v_3633;
v_3629:
    goto v_3639;
v_3635:
    v_3826 = stack[-2];
    v_3827 = qcar(v_3826);
    goto v_3636;
v_3637:
    v_3826 = stack[-2];
    v_3826 = qcdr(v_3826);
    goto v_3638;
v_3639:
    goto v_3635;
v_3636:
    goto v_3637;
v_3638:
    fn = elt(env, 5); // gcdf
    v_3827 = (*qfn2(fn))(fn, v_3827, v_3826);
    env = stack[-4];
    stack[-3] = v_3827;
    goto v_3630;
v_3631:
    v_3826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3632;
v_3633:
    goto v_3629;
v_3630:
    goto v_3631;
v_3632:
    if (v_3827 == v_3826) goto v_3625;
    goto v_3650;
v_3646:
    goto v_3656;
v_3652:
    v_3826 = stack[-2];
    v_3827 = qcar(v_3826);
    goto v_3653;
v_3654:
    v_3826 = stack[-3];
    goto v_3655;
v_3656:
    goto v_3652;
v_3653:
    goto v_3654;
v_3655:
    fn = elt(env, 6); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_3827, v_3826);
    env = stack[-4];
    goto v_3647;
v_3648:
    goto v_3665;
v_3661:
    v_3826 = stack[-2];
    v_3827 = qcdr(v_3826);
    goto v_3662;
v_3663:
    v_3826 = stack[-3];
    goto v_3664;
v_3665:
    goto v_3661;
v_3662:
    goto v_3663;
v_3664:
    fn = elt(env, 6); // quotf!-fail
    v_3826 = (*qfn2(fn))(fn, v_3827, v_3826);
    env = stack[-4];
    goto v_3649;
v_3650:
    goto v_3646;
v_3647:
    goto v_3648;
v_3649:
    v_3826 = cons(stack[0], v_3826);
    env = stack[-4];
    stack[-2] = v_3826;
    goto v_3623;
v_3625:
v_3623:
    v_3826 = stack[-2];
    v_3826 = qcdr(v_3826);
    fn = elt(env, 7); // lnc
    v_3826 = (*qfn1(fn))(fn, v_3826);
    env = stack[-4];
    stack[-3] = v_3826;
    goto v_3680;
v_3676:
    v_3827 = stack[-3];
    goto v_3677;
v_3678:
    v_3826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3679;
v_3680:
    goto v_3676;
v_3677:
    goto v_3678;
v_3679:
    if (v_3827 == v_3826) goto v_3674;
    else goto v_3675;
v_3674:
    v_3826 = stack[-2];
    goto v_3621;
v_3675:
    v_3826 = stack[-3];
    if (!consp(v_3826)) goto v_3684;
    else goto v_3685;
v_3684:
    v_3826 = stack[-3];
    v_3826 = Lminusp(nil, v_3826);
    env = stack[-4];
    if (v_3826 == nil) goto v_3690;
    goto v_3698;
v_3694:
    v_3826 = stack[-2];
    v_3826 = qcar(v_3826);
    fn = elt(env, 8); // negf
    stack[0] = (*qfn1(fn))(fn, v_3826);
    env = stack[-4];
    goto v_3695;
v_3696:
    v_3826 = stack[-2];
    v_3826 = qcdr(v_3826);
    fn = elt(env, 8); // negf
    v_3826 = (*qfn1(fn))(fn, v_3826);
    env = stack[-4];
    goto v_3697;
v_3698:
    goto v_3694;
v_3695:
    goto v_3696;
v_3697:
    v_3826 = cons(stack[0], v_3826);
    env = stack[-4];
    stack[-2] = v_3826;
    v_3826 = stack[-3];
    v_3826 = negate(v_3826);
    env = stack[-4];
    stack[-3] = v_3826;
    goto v_3688;
v_3690:
    goto v_3688;
v_3688:
    goto v_3673;
v_3685:
    goto v_3717;
v_3713:
    v_3826 = stack[-3];
    v_3826 = qcar(v_3826);
    if (!symbolp(v_3826)) v_3827 = nil;
    else { v_3827 = qfastgets(v_3826);
           if (v_3827 != nil) { v_3827 = elt(v_3827, 30); // minusp
#ifdef RECORD_GET
             if (v_3827 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_3827 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_3827 == SPID_NOPROP) v_3827 = nil; }}
#endif
    goto v_3714;
v_3715:
    v_3826 = stack[-3];
    goto v_3716;
v_3717:
    goto v_3713;
v_3714:
    goto v_3715;
v_3716:
    v_3826 = Lapply1(nil, v_3827, v_3826);
    env = stack[-4];
    if (v_3826 == nil) goto v_3711;
    goto v_3727;
v_3723:
    v_3826 = stack[-2];
    v_3826 = qcar(v_3826);
    fn = elt(env, 8); // negf
    stack[0] = (*qfn1(fn))(fn, v_3826);
    env = stack[-4];
    goto v_3724;
v_3725:
    v_3826 = stack[-2];
    v_3826 = qcdr(v_3826);
    fn = elt(env, 8); // negf
    v_3826 = (*qfn1(fn))(fn, v_3826);
    env = stack[-4];
    goto v_3726;
v_3727:
    goto v_3723;
v_3724:
    goto v_3725;
v_3726:
    v_3826 = cons(stack[0], v_3826);
    env = stack[-4];
    stack[-2] = v_3826;
    goto v_3741;
v_3735:
    goto v_3747;
v_3743:
    v_3826 = stack[-3];
    v_3827 = qcar(v_3826);
    goto v_3744;
v_3745:
    v_3826 = elt(env, 2); // difference
    goto v_3746;
v_3747:
    goto v_3743;
v_3744:
    goto v_3745;
v_3746:
    stack[0] = get(v_3827, v_3826);
    env = stack[-4];
    goto v_3736;
v_3737:
    goto v_3756;
v_3752:
    v_3826 = stack[-3];
    v_3826 = qcar(v_3826);
    if (!symbolp(v_3826)) v_3827 = nil;
    else { v_3827 = qfastgets(v_3826);
           if (v_3827 != nil) { v_3827 = elt(v_3827, 34); // i2d
#ifdef RECORD_GET
             if (v_3827 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_3827 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_3827 == SPID_NOPROP) v_3827 = nil; }}
#endif
    goto v_3753;
v_3754:
    v_3826 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3755;
v_3756:
    goto v_3752;
v_3753:
    goto v_3754;
v_3755:
    v_3827 = Lapply1(nil, v_3827, v_3826);
    env = stack[-4];
    goto v_3738;
v_3739:
    v_3826 = stack[-3];
    goto v_3740;
v_3741:
    goto v_3735;
v_3736:
    goto v_3737;
v_3738:
    goto v_3739;
v_3740:
    v_3826 = Lapply2(nil, 3, stack[0], v_3827, v_3826);
    env = stack[-4];
    stack[-3] = v_3826;
    goto v_3673;
v_3711:
v_3673:
    v_3826 = stack[-3];
    if (is_number(v_3826)) goto v_3769;
    goto v_3776;
v_3772:
    v_3827 = qvalue(elt(env, 3)); // dmode!*
    goto v_3773;
v_3774:
    v_3826 = elt(env, 4); // unitsfn
    goto v_3775;
v_3776:
    goto v_3772;
v_3773:
    goto v_3774;
v_3775:
    v_3826 = get(v_3827, v_3826);
    env = stack[-4];
    stack[-1] = v_3826;
    goto v_3767;
v_3769:
    v_3826 = nil;
    goto v_3767;
    v_3826 = nil;
v_3767:
    if (v_3826 == nil) goto v_3765;
    goto v_3789;
v_3783:
    v_3828 = stack[-1];
    goto v_3784;
v_3785:
    v_3827 = stack[-2];
    goto v_3786;
v_3787:
    v_3826 = stack[-3];
    goto v_3788;
v_3789:
    goto v_3783;
v_3784:
    goto v_3785;
v_3786:
    goto v_3787;
v_3788:
        return Lapply2(nil, 3, v_3828, v_3827, v_3826);
v_3765:
    v_3826 = qvalue(elt(env, 3)); // dmode!*
    if (!symbolp(v_3826)) v_3826 = nil;
    else { v_3826 = qfastgets(v_3826);
           if (v_3826 != nil) { v_3826 = elt(v_3826, 3); // field
#ifdef RECORD_GET
             if (v_3826 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_3826 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_3826 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_3826 == SPID_NOPROP) v_3826 = nil; else v_3826 = lisp_true; }}
#endif
    if (v_3826 == nil) goto v_3798;
    v_3826 = lisp_true;
    goto v_3796;
v_3798:
    v_3826 = stack[-3];
    if (!consp(v_3826)) goto v_3807;
    v_3826 = stack[-3];
    v_3826 = qcar(v_3826);
    if (!symbolp(v_3826)) v_3826 = nil;
    else { v_3826 = qfastgets(v_3826);
           if (v_3826 != nil) { v_3826 = elt(v_3826, 3); // field
#ifdef RECORD_GET
             if (v_3826 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_3826 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_3826 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_3826 == SPID_NOPROP) v_3826 = nil; else v_3826 = lisp_true; }}
#endif
    goto v_3805;
v_3807:
    v_3826 = nil;
    goto v_3805;
    v_3826 = nil;
v_3805:
    goto v_3796;
    v_3826 = nil;
v_3796:
    if (v_3826 == nil) goto v_3794;
    goto v_3820;
v_3816:
    v_3827 = stack[-3];
    goto v_3817;
v_3818:
    v_3826 = stack[-2];
    goto v_3819;
v_3820:
    goto v_3816;
v_3817:
    goto v_3818;
v_3819:
    {
        fn = elt(env, 9); // fieldconv
        return (*qfn2(fn))(fn, v_3827, v_3826);
    }
v_3794:
    v_3826 = stack[-2];
    goto v_3763;
    v_3826 = nil;
v_3763:
v_3621:
    goto v_3592;
    v_3826 = nil;
v_3592:
    return onevalue(v_3826);
}



// Code for rassoc

static LispObject CC_rassoc(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3618, v_3619, v_3620, v_3621;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3619 = v_3590;
    v_3620 = v_3589;
// end of prologue
v_3594:
    v_3618 = v_3619;
    if (!consp(v_3618)) goto v_3597;
    else goto v_3598;
v_3597:
    v_3618 = nil;
    goto v_3593;
v_3598:
    goto v_3607;
v_3603:
    v_3621 = v_3620;
    goto v_3604;
v_3605:
    v_3618 = v_3619;
    v_3618 = qcar(v_3618);
    v_3618 = qcdr(v_3618);
    goto v_3606;
v_3607:
    goto v_3603;
v_3604:
    goto v_3605;
v_3606:
    if (equal(v_3621, v_3618)) goto v_3601;
    else goto v_3602;
v_3601:
    v_3618 = v_3619;
    v_3618 = qcar(v_3618);
    goto v_3593;
v_3602:
    v_3618 = v_3619;
    v_3618 = qcdr(v_3618);
    v_3619 = v_3618;
    goto v_3594;
    v_3618 = nil;
v_3593:
    return onevalue(v_3618);
}



// Code for talp_atfp

static LispObject CC_talp_atfp(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3609, v_3610;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3609 = v_3589;
// end of prologue
    v_3610 = v_3609;
    v_3610 = Lconsp(nil, v_3610);
    env = stack[0];
    if (v_3610 == nil) goto v_3593;
    else goto v_3594;
v_3593:
    v_3609 = nil;
    goto v_3592;
v_3594:
    goto v_3604;
v_3600:
    fn = elt(env, 2); // talp_op
    v_3609 = (*qfn1(fn))(fn, v_3609);
    env = stack[0];
    goto v_3601;
v_3602:
    v_3610 = elt(env, 1); // (neq equal)
    goto v_3603;
v_3604:
    goto v_3600;
v_3601:
    goto v_3602;
v_3603:
    v_3609 = Lmemq(nil, v_3609, v_3610);
    goto v_3592;
    v_3609 = nil;
v_3592:
    return onevalue(v_3609);
}



// Code for ibalp_varlat

static LispObject CC_ibalp_varlat(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3603;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3589;
// end of prologue
    goto v_3596;
v_3592:
    v_3603 = stack[0];
    fn = elt(env, 1); // ibalp_arg2l
    v_3603 = (*qfn1(fn))(fn, v_3603);
    env = stack[-2];
    fn = elt(env, 2); // ibalp_varlt
    stack[-1] = (*qfn1(fn))(fn, v_3603);
    env = stack[-2];
    goto v_3593;
v_3594:
    v_3603 = stack[0];
    fn = elt(env, 3); // ibalp_arg2r
    v_3603 = (*qfn1(fn))(fn, v_3603);
    env = stack[-2];
    fn = elt(env, 2); // ibalp_varlt
    v_3603 = (*qfn1(fn))(fn, v_3603);
    env = stack[-2];
    goto v_3595;
v_3596:
    goto v_3592;
v_3593:
    goto v_3594;
v_3595:
    {
        LispObject v_3606 = stack[-1];
        fn = elt(env, 4); // union
        return (*qfn2(fn))(fn, v_3606, v_3603);
    }
}



// Code for checktag

static LispObject CC_checktag(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3612, v_3613;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
// copy arguments values to proper place
    v_3612 = v_3589;
// end of prologue
    goto v_3601;
v_3597:
    v_3613 = qvalue(elt(env, 1)); // char
    goto v_3598;
v_3599:
    goto v_3600;
v_3601:
    goto v_3597;
v_3598:
    goto v_3599;
v_3600:
    if (equal(v_3613, v_3612)) goto v_3596;
    goto v_3609;
v_3605:
    v_3613 = elt(env, 2); // "Problem"
    goto v_3606;
v_3607:
    v_3612 = elt(env, 3); // "problem"
    goto v_3608;
v_3609:
    goto v_3605;
v_3606:
    goto v_3607;
v_3608:
    fn = elt(env, 4); // errorml
    v_3612 = (*qfn2(fn))(fn, v_3613, v_3612);
    goto v_3594;
v_3596:
v_3594:
    v_3612 = nil;
    return onevalue(v_3612);
}



// Code for vevmaptozero1

static LispObject CC_vevmaptozero1(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3613, v_3614;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_3613 = v_3590;
    stack[0] = v_3589;
// end of prologue
v_3594:
    v_3614 = stack[0];
    if (v_3614 == nil) goto v_3597;
    else goto v_3598;
v_3597:
    goto v_3593;
v_3598:
    v_3614 = stack[0];
    v_3614 = qcdr(v_3614);
    stack[0] = v_3614;
    goto v_3610;
v_3606:
    v_3614 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3607;
v_3608:
    goto v_3609;
v_3610:
    goto v_3606;
v_3607:
    goto v_3608;
v_3609:
    v_3613 = cons(v_3614, v_3613);
    env = stack[-1];
    goto v_3594;
    v_3613 = nil;
v_3593:
    return onevalue(v_3613);
}



// Code for physopsim!*

static LispObject CC_physopsimH(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3615, v_3616;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3589;
// end of prologue
    goto v_3600;
v_3596:
    v_3616 = stack[0];
    goto v_3597;
v_3598:
    v_3615 = elt(env, 1); // !:dn!:
    goto v_3599;
v_3600:
    goto v_3596;
v_3597:
    goto v_3598;
v_3599:
    if (!consp(v_3616)) goto v_3594;
    v_3616 = qcar(v_3616);
    if (v_3616 == v_3615) goto v_3593;
    else goto v_3594;
v_3593:
    v_3615 = stack[0];
    fn = elt(env, 2); // simp
    v_3615 = (*qfn1(fn))(fn, v_3615);
    env = stack[-1];
    {
        fn = elt(env, 3); // prepsq
        return (*qfn1(fn))(fn, v_3615);
    }
v_3594:
    v_3615 = stack[0];
    fn = elt(env, 4); // !*physopp!*
    v_3615 = (*qfn1(fn))(fn, v_3615);
    env = stack[-1];
    if (v_3615 == nil) goto v_3607;
    v_3615 = stack[0];
    {
        fn = elt(env, 5); // physopsm!*
        return (*qfn1(fn))(fn, v_3615);
    }
v_3607:
    v_3615 = stack[0];
    goto v_3592;
    v_3615 = nil;
v_3592:
    return onevalue(v_3615);
}



// Code for rread

static LispObject CC_rread(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3593;
    LispObject fn;
    argcheck(nargs, 0, "rread");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
    stack_popper stack_popper_var(1);
// end of prologue
    v_3593 = elt(env, 1); // " '"
    fn = elt(env, 2); // prin2x
    v_3593 = (*qfn1(fn))(fn, v_3593);
    env = stack[0];
    {
        fn = elt(env, 3); // rread1
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for reval2

static LispObject CC_reval2(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3630, v_3631;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3590;
    v_3631 = v_3589;
// end of prologue
    v_3630 = stack[0];
    if (v_3630 == nil) goto v_3596;
    else goto v_3594;
v_3596:
    v_3630 = qvalue(elt(env, 1)); // !*combineexpt
    if (v_3630 == nil) goto v_3601;
    else goto v_3602;
v_3601:
    v_3630 = lisp_true;
    goto v_3600;
v_3602:
    v_3630 = qvalue(elt(env, 2)); // dmode!*
    goto v_3600;
    v_3630 = nil;
v_3600:
    if (v_3630 == nil) goto v_3598;
    else goto v_3594;
v_3598:
    goto v_3595;
v_3594:
    goto v_3613;
v_3609:
    v_3630 = v_3631;
    fn = elt(env, 4); // simp!*
    v_3631 = (*qfn1(fn))(fn, v_3630);
    env = stack[-2];
    goto v_3610;
v_3611:
    v_3630 = stack[0];
    goto v_3612;
v_3613:
    goto v_3609;
v_3610:
    goto v_3611;
v_3612:
    {
        fn = elt(env, 5); // !*q2a1
        return (*qfn2(fn))(fn, v_3631, v_3630);
    }
v_3595:
    goto v_3624;
v_3620:
    v_3630 = nil;
// Binding !*mcd
// FLUIDBIND: reloadenv=2 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 3, -1);
    qvalue(elt(env, 3)) = v_3630; // !*mcd
    v_3630 = v_3631;
    fn = elt(env, 4); // simp!*
    v_3631 = (*qfn1(fn))(fn, v_3630);
    env = stack[-2];
    ;}  // end of a binding scope
    goto v_3621;
v_3622:
    v_3630 = stack[0];
    goto v_3623;
v_3624:
    goto v_3620;
v_3621:
    goto v_3622;
v_3623:
    {
        fn = elt(env, 5); // !*q2a1
        return (*qfn2(fn))(fn, v_3631, v_3630);
    }
    v_3630 = nil;
    return onevalue(v_3630);
}



// Code for divd

static LispObject CC_divd(LispObject env,
                         LispObject v_3589, LispObject v_3590)
{
    env = qenv(env);
    LispObject v_3703, v_3704, v_3705;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3589,v_3590);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3590;
    stack[-2] = v_3589;
// end of prologue
    stack[-3] = nil;
v_3595:
    v_3703 = stack[-1];
    if (v_3703 == nil) goto v_3598;
    else goto v_3599;
v_3598:
    v_3703 = stack[-2];
    if (v_3703 == nil) goto v_3603;
    else goto v_3604;
v_3603:
    goto v_3611;
v_3607:
    stack[0] = stack[-3];
    goto v_3608;
v_3609:
    goto v_3620;
v_3614:
    v_3705 = elt(env, 1); // poly
    goto v_3615;
v_3616:
    v_3704 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3617;
v_3618:
    v_3703 = elt(env, 2); // "0/0 formed"
    goto v_3619;
v_3620:
    goto v_3614;
v_3615:
    goto v_3616;
v_3617:
    goto v_3618;
v_3619:
    fn = elt(env, 4); // rerror
    v_3703 = (*qfnn(fn))(fn, 3, v_3705, v_3704, v_3703);
    env = stack[-4];
    goto v_3610;
v_3611:
    goto v_3607;
v_3608:
    goto v_3609;
v_3610:
    {
        LispObject v_3710 = stack[0];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_3710, v_3703);
    }
v_3604:
    goto v_3631;
v_3627:
    stack[0] = stack[-3];
    goto v_3628;
v_3629:
    goto v_3640;
v_3634:
    v_3705 = elt(env, 1); // poly
    goto v_3635;
v_3636:
    v_3704 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3637;
v_3638:
    v_3703 = elt(env, 3); // "Zero divisor"
    goto v_3639;
v_3640:
    goto v_3634;
v_3635:
    goto v_3636;
v_3637:
    goto v_3638;
v_3639:
    fn = elt(env, 4); // rerror
    v_3703 = (*qfnn(fn))(fn, 3, v_3705, v_3704, v_3703);
    env = stack[-4];
    goto v_3630;
v_3631:
    goto v_3627;
v_3628:
    goto v_3629;
v_3630:
    {
        LispObject v_3711 = stack[0];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_3711, v_3703);
    }
    goto v_3597;
v_3599:
    v_3703 = stack[-2];
    if (v_3703 == nil) goto v_3644;
    else goto v_3645;
v_3644:
    v_3703 = stack[-3];
    {
        fn = elt(env, 5); // nreverse
        return (*qfn1(fn))(fn, v_3703);
    }
v_3645:
    v_3703 = stack[-2];
    if (!consp(v_3703)) goto v_3653;
    else goto v_3654;
v_3653:
    v_3703 = lisp_true;
    goto v_3652;
v_3654:
    v_3703 = stack[-2];
    v_3703 = qcar(v_3703);
    v_3703 = (consp(v_3703) ? nil : lisp_true);
    goto v_3652;
    v_3703 = nil;
v_3652:
    if (v_3703 == nil) goto v_3650;
    goto v_3667;
v_3663:
    stack[0] = stack[-3];
    goto v_3664;
v_3665:
    goto v_3674;
v_3670:
    v_3704 = stack[-2];
    goto v_3671;
v_3672:
    v_3703 = stack[-1];
    goto v_3673;
v_3674:
    goto v_3670;
v_3671:
    goto v_3672;
v_3673:
    fn = elt(env, 6); // divdm
    v_3703 = (*qfn2(fn))(fn, v_3704, v_3703);
    env = stack[-4];
    goto v_3666;
v_3667:
    goto v_3663;
v_3664:
    goto v_3665;
v_3666:
    {
        LispObject v_3712 = stack[0];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_3712, v_3703);
    }
v_3650:
    goto v_3686;
v_3680:
    v_3703 = stack[-2];
    v_3703 = qcar(v_3703);
    stack[0] = qcar(v_3703);
    goto v_3681;
v_3682:
    goto v_3695;
v_3691:
    v_3703 = stack[-2];
    v_3703 = qcar(v_3703);
    v_3704 = qcdr(v_3703);
    goto v_3692;
v_3693:
    v_3703 = stack[-1];
    goto v_3694;
v_3695:
    goto v_3691;
v_3692:
    goto v_3693;
v_3694:
    v_3704 = CC_divd(elt(env, 0), v_3704, v_3703);
    env = stack[-4];
    goto v_3683;
v_3684:
    v_3703 = stack[-3];
    goto v_3685;
v_3686:
    goto v_3680;
v_3681:
    goto v_3682;
v_3683:
    goto v_3684;
v_3685:
    v_3703 = acons(stack[0], v_3704, v_3703);
    env = stack[-4];
    stack[-3] = v_3703;
    v_3703 = stack[-2];
    v_3703 = qcdr(v_3703);
    stack[-2] = v_3703;
    goto v_3595;
v_3597:
    v_3703 = nil;
    return onevalue(v_3703);
}



// Code for bas_make1

static LispObject CC_bas_make1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3616, v_3617;
    LispObject fn;
    LispObject v_3591, v_3590, v_3589;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "bas_make1");
    va_start(aa, nargs);
    v_3589 = va_arg(aa, LispObject);
    v_3590 = va_arg(aa, LispObject);
    v_3591 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3591,v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3589,v_3590,v_3591);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_3591;
    stack[-3] = v_3590;
    v_3616 = v_3589;
// end of prologue
    goto v_3602;
v_3594:
    stack[-4] = v_3616;
    goto v_3595;
v_3596:
    stack[-1] = stack[-3];
    goto v_3597;
v_3598:
    v_3616 = stack[-3];
    stack[0] = Llength(nil, v_3616);
    env = stack[-5];
    goto v_3599;
v_3600:
    goto v_3612;
v_3608:
    v_3616 = stack[-3];
    fn = elt(env, 1); // dp_ecart
    v_3617 = (*qfn1(fn))(fn, v_3616);
    env = stack[-5];
    goto v_3609;
v_3610:
    v_3616 = stack[-2];
    goto v_3611;
v_3612:
    goto v_3608;
v_3609:
    goto v_3610;
v_3611:
    v_3616 = list2(v_3617, v_3616);
    goto v_3601;
v_3602:
    goto v_3594;
v_3595:
    goto v_3596;
v_3597:
    goto v_3598;
v_3599:
    goto v_3600;
v_3601:
    {
        LispObject v_3623 = stack[-4];
        LispObject v_3624 = stack[-1];
        LispObject v_3625 = stack[0];
        return list3star(v_3623, v_3624, v_3625, v_3616);
    }
}



// Code for adddummy1a

static LispObject CC_adddummy1a(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3651, v_3652;
    LispObject fn;
    LispObject v_3591, v_3590, v_3589;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "adddummy1a");
    va_start(aa, nargs);
    v_3589 = va_arg(aa, LispObject);
    v_3590 = va_arg(aa, LispObject);
    v_3591 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3591,v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3589,v_3590,v_3591);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3591;
    v_3651 = v_3590;
    stack[-2] = v_3589;
// end of prologue
v_3596:
    v_3652 = v_3651;
    if (v_3652 == nil) goto v_3599;
    else goto v_3600;
v_3599:
    v_3651 = stack[-1];
    goto v_3595;
v_3600:
    v_3652 = v_3651;
    v_3652 = qcdr(v_3652);
    stack[-3] = v_3652;
    goto v_3612;
v_3608:
    v_3652 = stack[-1];
    if (v_3652 == nil) goto v_3615;
    else goto v_3616;
v_3615:
    v_3652 = stack[-2];
    v_3652 = qcar(v_3652);
    stack[0] = v_3652;
    goto v_3614;
v_3616:
    v_3652 = stack[-1];
    v_3652 = qcar(v_3652);
    stack[0] = v_3652;
    goto v_3614;
    stack[0] = nil;
v_3614:
    goto v_3609;
v_3610:
    goto v_3629;
v_3625:
    goto v_3635;
v_3631:
    v_3652 = qcar(v_3651);
    goto v_3632;
v_3633:
    v_3651 = stack[-2];
    v_3651 = qcdr(v_3651);
    goto v_3634;
v_3635:
    goto v_3631;
v_3632:
    goto v_3633;
v_3634:
    fn = elt(env, 1); // pappl_pv
    v_3652 = (*qfn2(fn))(fn, v_3652, v_3651);
    env = stack[-4];
    goto v_3626;
v_3627:
    v_3651 = stack[-1];
    if (v_3651 == nil) goto v_3642;
    else goto v_3643;
v_3642:
    v_3651 = stack[-1];
    goto v_3641;
v_3643:
    v_3651 = stack[-1];
    v_3651 = qcdr(v_3651);
    goto v_3641;
    v_3651 = nil;
v_3641:
    goto v_3628;
v_3629:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    fn = elt(env, 2); // insert_pv
    v_3651 = (*qfn2(fn))(fn, v_3652, v_3651);
    env = stack[-4];
    goto v_3611;
v_3612:
    goto v_3608;
v_3609:
    goto v_3610;
v_3611:
    v_3651 = cons(stack[0], v_3651);
    env = stack[-4];
    stack[-1] = v_3651;
    v_3651 = stack[-3];
    goto v_3596;
    v_3651 = nil;
v_3595:
    return onevalue(v_3651);
}



// Code for yyreadch

static LispObject CC_yyreadch(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3650, v_3651, v_3652;
    argcheck(nargs, 0, "yyreadch");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
    stack_popper stack_popper_var(1);
// end of prologue
    v_3650 = qvalue(elt(env, 1)); // lex_peek_char
    if (v_3650 == nil) goto v_3593;
    v_3650 = qvalue(elt(env, 1)); // lex_peek_char
    qvalue(elt(env, 2)) = v_3650; // lex_char
    v_3650 = nil;
    qvalue(elt(env, 1)) = v_3650; // lex_peek_char
    v_3650 = qvalue(elt(env, 2)); // lex_char
    goto v_3591;
v_3593:
    v_3650 = Lreadch(nil, 0);
    env = stack[0];
    qvalue(elt(env, 2)) = v_3650; // lex_char
    goto v_3609;
v_3605:
    v_3651 = qvalue(elt(env, 2)); // lex_char
    goto v_3606;
v_3607:
    v_3650 = qvalue(elt(env, 3)); // !$eol!$
    goto v_3608;
v_3609:
    goto v_3605;
v_3606:
    goto v_3607;
v_3608:
    if (equal(v_3651, v_3650)) goto v_3603;
    else goto v_3604;
v_3603:
    v_3650 = qvalue(elt(env, 4)); // which_line
    v_3650 = add1(v_3650);
    env = stack[0];
    qvalue(elt(env, 4)) = v_3650; // which_line
    goto v_3602;
v_3604:
v_3602:
    goto v_3622;
v_3618:
    v_3651 = qvalue(elt(env, 2)); // lex_char
    goto v_3619;
v_3620:
    v_3650 = qvalue(elt(env, 5)); // !$eof!$
    goto v_3621;
v_3622:
    goto v_3618;
v_3619:
    goto v_3620;
v_3621:
    if (equal(v_3651, v_3650)) goto v_3617;
    v_3650 = qvalue(elt(env, 6)); // last64p
    v_3650 = add1(v_3650);
    env = stack[0];
    qvalue(elt(env, 6)) = v_3650; // last64p
    goto v_3635;
v_3631:
    v_3651 = qvalue(elt(env, 6)); // last64p
    goto v_3632;
v_3633:
    v_3650 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_3634;
v_3635:
    goto v_3631;
v_3632:
    goto v_3633;
v_3634:
    if (v_3651 == v_3650) goto v_3629;
    else goto v_3630;
v_3629:
    v_3650 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 6)) = v_3650; // last64p
    goto v_3628;
v_3630:
v_3628:
    goto v_3645;
v_3639:
    v_3652 = qvalue(elt(env, 7)); // last64
    goto v_3640;
v_3641:
    v_3651 = qvalue(elt(env, 6)); // last64p
    goto v_3642;
v_3643:
    v_3650 = qvalue(elt(env, 2)); // lex_char
    goto v_3644;
v_3645:
    goto v_3639;
v_3640:
    goto v_3641;
v_3642:
    goto v_3643;
v_3644:
    *(LispObject *)((char *)v_3652 + (CELL-TAG_VECTOR) + (((intptr_t)v_3651-TAG_FIXNUM)/(16/CELL))) = v_3650;
    goto v_3615;
v_3617:
v_3615:
    v_3650 = qvalue(elt(env, 2)); // lex_char
    goto v_3591;
    v_3650 = nil;
v_3591:
    return onevalue(v_3650);
}



// Code for rat_numrn

static LispObject CC_rat_numrn(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3602, v_3603;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3602 = v_3589;
// end of prologue
    v_3603 = v_3602;
    v_3603 = qcar(v_3603);
    if (v_3603 == nil) goto v_3593;
    else goto v_3594;
v_3593:
    v_3602 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3592;
v_3594:
    v_3602 = qcar(v_3602);
    goto v_3592;
    v_3602 = nil;
v_3592:
    return onevalue(v_3602);
}



// Code for procstat

static LispObject CC_procstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3592;
    LispObject fn;
    argcheck(nargs, 0, "procstat");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_3592 = nil;
    {
        fn = elt(env, 1); // procstat1
        return (*qfn1(fn))(fn, v_3592);
    }
}



// Code for cdarx

static LispObject CC_cdarx(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3600, v_3601;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
// copy arguments values to proper place
    v_3600 = v_3589;
// end of prologue
    goto v_3596;
v_3592:
    v_3601 = v_3600;
    goto v_3593;
v_3594:
    v_3600 = elt(env, 1); // cdar
    goto v_3595;
v_3596:
    goto v_3592;
v_3593:
    goto v_3594;
v_3595:
    fn = elt(env, 2); // carx
    v_3600 = (*qfn2(fn))(fn, v_3601, v_3600);
    v_3600 = qcdr(v_3600);
    return onevalue(v_3600);
}



// Code for talp_smupdknowl1

static LispObject CC_talp_smupdknowl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3669, v_3670, v_3671;
    LispObject fn;
    LispObject v_3592, v_3591, v_3590, v_3589;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_smupdknowl1");
    va_start(aa, nargs);
    v_3589 = va_arg(aa, LispObject);
    v_3590 = va_arg(aa, LispObject);
    v_3591 = va_arg(aa, LispObject);
    v_3592 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_3592,v_3591,v_3590,v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_3589,v_3590,v_3591,v_3592);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_3592;
    stack[-1] = v_3591;
    stack[-2] = v_3590;
    v_3669 = v_3589;
// end of prologue
    goto v_3606;
v_3602:
    v_3670 = v_3669;
    goto v_3603;
v_3604:
    v_3669 = elt(env, 1); // or
    goto v_3605;
v_3606:
    goto v_3602;
v_3603:
    goto v_3604;
v_3605:
    if (v_3670 == v_3669) goto v_3600;
    else goto v_3601;
v_3600:
    v_3669 = stack[-2];
    fn = elt(env, 3); // rl_negateat
    v_3669 = (*qfn1(fn))(fn, v_3669);
    env = stack[-4];
    stack[-3] = v_3669;
    v_3669 = stack[-2];
    goto v_3599;
v_3601:
    v_3669 = stack[-2];
    stack[-3] = v_3669;
    v_3669 = stack[-2];
    fn = elt(env, 3); // rl_negateat
    v_3669 = (*qfn1(fn))(fn, v_3669);
    env = stack[-4];
    goto v_3599;
v_3599:
    goto v_3627;
v_3623:
    v_3670 = v_3669;
    goto v_3624;
v_3625:
    v_3669 = stack[-1];
    goto v_3626;
v_3627:
    goto v_3623;
v_3624:
    goto v_3625;
v_3626:
    v_3669 = Lassoc(nil, v_3670, v_3669);
    if (v_3669 == nil) goto v_3622;
    v_3669 = elt(env, 2); // false
    goto v_3597;
v_3622:
    goto v_3641;
v_3637:
    v_3670 = stack[-3];
    goto v_3638;
v_3639:
    v_3669 = stack[-1];
    goto v_3640;
v_3641:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    fn = elt(env, 4); // talp_chkknowl
    v_3669 = (*qfn2(fn))(fn, v_3670, v_3669);
    env = stack[-4];
    if (v_3669 == nil) goto v_3635;
    v_3669 = elt(env, 2); // false
    goto v_3597;
v_3635:
    goto v_3653;
v_3649:
    v_3670 = stack[-3];
    goto v_3650;
v_3651:
    v_3669 = stack[-1];
    goto v_3652;
v_3653:
    goto v_3649;
v_3650:
    goto v_3651;
v_3652:
    v_3669 = Lassoc(nil, v_3670, v_3669);
    if (v_3669 == nil) goto v_3648;
    v_3669 = stack[-1];
    goto v_3597;
v_3648:
    goto v_3665;
v_3659:
    v_3671 = stack[-3];
    goto v_3660;
v_3661:
    v_3670 = stack[0];
    goto v_3662;
v_3663:
    v_3669 = stack[-1];
    goto v_3664;
v_3665:
    goto v_3659;
v_3660:
    goto v_3661;
v_3662:
    goto v_3663;
v_3664:
    v_3669 = acons(v_3671, v_3670, v_3669);
v_3597:
    return onevalue(v_3669);
}



// Code for subs2f1

static LispObject CC_subs2f1(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_4214, v_4215, v_4216, v_4217, v_4218;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_3589;
// end of prologue
    v_4214 = stack[-8];
    if (!consp(v_4214)) goto v_3597;
    else goto v_3598;
v_3597:
    v_4214 = lisp_true;
    goto v_3596;
v_3598:
    v_4214 = stack[-8];
    v_4214 = qcar(v_4214);
    v_4214 = (consp(v_4214) ? nil : lisp_true);
    goto v_3596;
    v_4214 = nil;
v_3596:
    if (v_4214 == nil) goto v_3594;
    v_4214 = stack[-8];
    {
        fn = elt(env, 10); // !*d2q
        return (*qfn1(fn))(fn, v_4214);
    }
v_3594:
    stack[-2] = nil;
v_3619:
    v_4214 = nil;
    stack[-4] = v_4214;
    v_4214 = stack[-8];
    v_4214 = qcar(v_4214);
    v_4214 = qcar(v_4214);
    v_4214 = qcar(v_4214);
    stack[-9] = v_4214;
    goto v_3641;
v_3637:
    v_4215 = nil;
    goto v_3638;
v_3639:
    v_4214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3640;
v_3641:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    v_4214 = cons(v_4215, v_4214);
    env = stack[-10];
    stack[-3] = v_4214;
v_3620:
    v_4214 = stack[-8];
    if (v_4214 == nil) goto v_3650;
    else goto v_3651;
v_3650:
    v_4214 = lisp_true;
    goto v_3649;
v_3651:
    goto v_3660;
v_3656:
    goto v_3666;
v_3662:
    v_4215 = stack[-8];
    goto v_3663;
v_3664:
    v_4214 = stack[-9];
    goto v_3665;
v_3666:
    goto v_3662;
v_3663:
    goto v_3664;
v_3665:
    fn = elt(env, 11); // degr
    v_4215 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    goto v_3657;
v_3658:
    v_4214 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3659;
v_3660:
    goto v_3656;
v_3657:
    goto v_3658;
v_3659:
    v_4214 = (v_4215 == v_4214 ? lisp_true : nil);
    goto v_3649;
    v_4214 = nil;
v_3649:
    if (v_4214 == nil) goto v_3647;
    goto v_3621;
v_3647:
    goto v_3676;
v_3672:
    v_4214 = stack[-8];
    v_4215 = qcar(v_4214);
    goto v_3673;
v_3674:
    v_4214 = stack[-4];
    goto v_3675;
v_3676:
    goto v_3672;
v_3673:
    goto v_3674;
v_3675:
    v_4214 = cons(v_4215, v_4214);
    env = stack[-10];
    stack[-4] = v_4214;
    v_4214 = stack[-8];
    v_4214 = qcdr(v_4214);
    stack[-8] = v_4214;
    goto v_3620;
v_3621:
    v_4214 = qvalue(elt(env, 1)); // powlis!*
    stack[-5] = v_4214;
v_3622:
    v_4214 = stack[-5];
    if (v_4214 == nil) goto v_3685;
    else goto v_3686;
v_3685:
    goto v_3623;
v_3686:
    goto v_3694;
v_3690:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4214 = qcar(v_4214);
    v_4215 = qcar(v_4214);
    goto v_3691;
v_3692:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcar(v_4214);
    goto v_3693;
v_3694:
    goto v_3690;
v_3691:
    goto v_3692;
v_3693:
    if (equal(v_4215, v_4214)) goto v_3688;
    else goto v_3689;
v_3688:
    goto v_3709;
v_3703:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4216 = qcar(v_4214);
    goto v_3704;
v_3705:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4215 = qcar(v_4214);
    goto v_3706;
v_3707:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    goto v_3708;
v_3709:
    goto v_3703;
v_3704:
    goto v_3705;
v_3706:
    goto v_3707;
v_3708:
    fn = elt(env, 12); // subs2p
    v_4214 = (*qfnn(fn))(fn, 3, v_4216, v_4215, v_4214);
    env = stack[-10];
    stack[-6] = v_4214;
    goto v_3629;
v_3689:
    goto v_3734;
v_3730:
    v_4215 = stack[-9];
    goto v_3731;
v_3732:
    v_4214 = elt(env, 2); // expt
    goto v_3733;
v_3734:
    goto v_3730;
v_3731:
    goto v_3732;
v_3733:
    if (!consp(v_4215)) goto v_3728;
    v_4215 = qcar(v_4215);
    if (v_4215 == v_4214) goto v_3727;
    else goto v_3728;
v_3727:
    goto v_3745;
v_3741:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4215 = qcar(v_4214);
    goto v_3742;
v_3743:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcar(v_4214);
    goto v_3744;
v_3745:
    goto v_3741;
v_3742:
    goto v_3743;
v_3744:
    if (equal(v_4215, v_4214)) goto v_3739;
    else goto v_3740;
v_3739:
    goto v_3761;
v_3757:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4215 = qcar(v_4214);
    goto v_3758;
v_3759:
    v_4214 = elt(env, 3); // quotient
    goto v_3760;
v_3761:
    goto v_3757;
v_3758:
    goto v_3759;
v_3760:
    if (!consp(v_4215)) goto v_3755;
    v_4215 = qcar(v_4215);
    if (v_4215 == v_4214) goto v_3754;
    else goto v_3755;
v_3754:
    goto v_3775;
v_3771:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4215 = qcar(v_4214);
    goto v_3772;
v_3773:
    v_4214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3774;
v_3775:
    goto v_3771;
v_3772:
    goto v_3773;
v_3774:
    if (v_4215 == v_4214) goto v_3769;
    else goto v_3770;
v_3769:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    v_4214 = (is_number(v_4214) ? lisp_true : nil);
    goto v_3768;
v_3770:
    v_4214 = nil;
    goto v_3768;
    v_4214 = nil;
v_3768:
    goto v_3753;
v_3755:
    v_4214 = nil;
    goto v_3753;
    v_4214 = nil;
v_3753:
    goto v_3738;
v_3740:
    v_4214 = nil;
    goto v_3738;
    v_4214 = nil;
v_3738:
    goto v_3726;
v_3728:
    v_4214 = nil;
    goto v_3726;
    v_4214 = nil;
v_3726:
    if (v_4214 == nil) goto v_3724;
    goto v_3808;
v_3804:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4214 = qcar(v_4214);
    v_4215 = qcdr(v_4214);
    goto v_3805;
v_3806:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    goto v_3807;
v_3808:
    goto v_3804;
v_3805:
    goto v_3806;
v_3807:
    v_4214 = Ldivide(nil, v_4215, v_4214);
    env = stack[-10];
    stack[-7] = v_4214;
    goto v_3828;
v_3824:
    v_4214 = stack[-7];
    v_4215 = qcar(v_4214);
    goto v_3825;
v_3826:
    v_4214 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3827;
v_3828:
    goto v_3824;
v_3825:
    goto v_3826;
v_3827:
    if (v_4215 == v_4214) goto v_3823;
    goto v_3837;
v_3833:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    fn = elt(env, 13); // simp
    v_4215 = (*qfn1(fn))(fn, v_4214);
    env = stack[-10];
    goto v_3834;
v_3835:
    v_4214 = stack[-7];
    v_4214 = qcar(v_4214);
    goto v_3836;
v_3837:
    goto v_3833;
v_3834:
    goto v_3835;
v_3836:
    fn = elt(env, 14); // exptsq
    v_4214 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    stack[-6] = v_4214;
    goto v_3821;
v_3823:
    goto v_3851;
v_3847:
    v_4215 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3848;
v_3849:
    v_4214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3850;
v_3851:
    goto v_3847;
v_3848:
    goto v_3849;
v_3850:
    v_4214 = cons(v_4215, v_4214);
    env = stack[-10];
    stack[-6] = v_4214;
    goto v_3821;
v_3821:
    goto v_3862;
v_3858:
    v_4214 = stack[-7];
    v_4215 = qcdr(v_4214);
    goto v_3859;
v_3860:
    v_4214 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3861;
v_3862:
    goto v_3858;
v_3859:
    goto v_3860;
v_3861:
    if (v_4215 == v_4214) goto v_3857;
// Binding alglist!*
// FLUIDBIND: reloadenv=10 litvec-offset=4 saveloc=1
{   bind_fluid_stack bind_fluid_var(-10, 4, -1);
    qvalue(elt(env, 4)) = nil; // alglist!*
// Binding dmode!*
// FLUIDBIND: reloadenv=10 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-10, 5, 0);
    qvalue(elt(env, 5)) = nil; // dmode!*
    v_4214 = nil;
    v_4214 = ncons(v_4214);
    env = stack[-10];
    qvalue(elt(env, 4)) = v_4214; // alglist!*
    goto v_3878;
v_3874:
    v_4214 = stack[-7];
    v_4215 = qcdr(v_4214);
    goto v_3875;
v_3876:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    goto v_3877;
v_3878:
    goto v_3874;
v_3875:
    goto v_3876;
v_3877:
    v_4214 = cons(v_4215, v_4214);
    env = stack[-10];
    fn = elt(env, 15); // cancel
    v_4214 = (*qfn1(fn))(fn, v_4214);
    env = stack[-10];
    stack[-7] = v_4214;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_3893;
v_3889:
    goto v_3899;
v_3895:
    goto v_3907;
v_3901:
    goto v_3913;
v_3909:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4215 = qcar(v_4214);
    goto v_3910;
v_3911:
    v_4214 = stack[-7];
    v_4214 = qcar(v_4214);
    goto v_3912;
v_3913:
    goto v_3909;
v_3910:
    goto v_3911;
v_3912:
    v_4216 = cons(v_4215, v_4214);
    env = stack[-10];
    goto v_3902;
v_3903:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4215 = qcar(v_4214);
    goto v_3904;
v_3905:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    goto v_3906;
v_3907:
    goto v_3901;
v_3902:
    goto v_3903;
v_3904:
    goto v_3905;
v_3906:
    fn = elt(env, 12); // subs2p
    v_4215 = (*qfnn(fn))(fn, 3, v_4216, v_4215, v_4214);
    env = stack[-10];
    goto v_3896;
v_3897:
    v_4214 = stack[-7];
    v_4214 = qcdr(v_4214);
    goto v_3898;
v_3899:
    goto v_3895;
v_3896:
    goto v_3897;
v_3898:
    fn = elt(env, 16); // raddsq
    v_4215 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    goto v_3890;
v_3891:
    v_4214 = stack[-6];
    goto v_3892;
v_3893:
    goto v_3889;
v_3890:
    goto v_3891;
v_3892:
    fn = elt(env, 17); // multsq
    v_4214 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    stack[-6] = v_4214;
    goto v_3855;
v_3857:
v_3855:
    goto v_3629;
v_3724:
    v_4214 = stack[-5];
    v_4214 = qcdr(v_4214);
    stack[-5] = v_4214;
    goto v_3622;
v_3623:
    v_4214 = qvalue(elt(env, 6)); // powlis1!*
    stack[-5] = v_4214;
v_3624:
    v_4214 = stack[-5];
    if (v_4214 == nil) goto v_3937;
    else goto v_3938;
v_3937:
    goto v_3625;
v_3938:
    goto v_3953;
v_3943:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4218 = qcar(v_4214);
    goto v_3944;
v_3945:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4217 = qcar(v_4214);
    goto v_3946;
v_3947:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4216 = qcar(v_4214);
    goto v_3948;
v_3949:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    v_4215 = qcar(v_4214);
    goto v_3950;
v_3951:
    v_4214 = stack[-5];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    goto v_3952;
v_3953:
    goto v_3943;
v_3944:
    goto v_3945;
v_3946:
    goto v_3947;
v_3948:
    goto v_3949;
v_3950:
    goto v_3951;
v_3952:
    fn = elt(env, 18); // mtchp
    v_4214 = (*qfnn(fn))(fn, 5, v_4218, v_4217, v_4216, v_4215, v_4214);
    env = stack[-10];
    stack[-6] = v_4214;
    if (v_4214 == nil) goto v_3941;
    goto v_3629;
v_3941:
    v_4214 = stack[-5];
    v_4214 = qcdr(v_4214);
    stack[-5] = v_4214;
    goto v_3624;
v_3625:
    goto v_3990;
v_3986:
    v_4215 = stack[-9];
    goto v_3987;
v_3988:
    v_4214 = elt(env, 2); // expt
    goto v_3989;
v_3990:
    goto v_3986;
v_3987:
    goto v_3988;
v_3989:
    if (!consp(v_4215)) goto v_3984;
    v_4215 = qcar(v_4215);
    if (v_4215 == v_4214) goto v_3983;
    else goto v_3984;
v_3983:
    v_4214 = qvalue(elt(env, 7)); // !*structure
    v_4214 = (v_4214 == nil ? lisp_true : nil);
    goto v_3982;
v_3984:
    v_4214 = nil;
    goto v_3982;
    v_4214 = nil;
v_3982:
    if (v_4214 == nil) goto v_3980;
    goto v_3630;
v_3980:
    goto v_4003;
v_3999:
    goto v_4009;
v_4005:
    goto v_4015;
v_4011:
    goto v_4022;
v_4018:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4215 = qcar(v_4214);
    goto v_4019;
v_4020:
    v_4214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4021;
v_4022:
    goto v_4018;
v_4019:
    goto v_4020;
v_4021:
    v_4214 = cons(v_4215, v_4214);
    env = stack[-10];
    v_4215 = ncons(v_4214);
    env = stack[-10];
    goto v_4012;
v_4013:
    v_4214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4014;
v_4015:
    goto v_4011;
v_4012:
    goto v_4013;
v_4014:
    stack[0] = cons(v_4215, v_4214);
    env = stack[-10];
    goto v_4006;
v_4007:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = CC_subs2f1(elt(env, 0), v_4214);
    env = stack[-10];
    goto v_4008;
v_4009:
    goto v_4005;
v_4006:
    goto v_4007;
v_4008:
    fn = elt(env, 17); // multsq
    v_4215 = (*qfn2(fn))(fn, stack[0], v_4214);
    env = stack[-10];
    goto v_4000;
v_4001:
    v_4214 = stack[-3];
    goto v_4002;
v_4003:
    goto v_3999;
v_4000:
    goto v_4001;
v_4002:
    fn = elt(env, 19); // addsq
    v_4214 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    stack[-3] = v_4214;
v_3626:
    v_4214 = stack[-4];
    v_4214 = qcdr(v_4214);
    stack[-4] = v_4214;
    v_4214 = stack[-4];
    if (v_4214 == nil) goto v_4038;
    goto v_3621;
v_4038:
v_3627:
    v_4214 = stack[-8];
    if (!consp(v_4214)) goto v_4046;
    else goto v_4047;
v_4046:
    v_4214 = lisp_true;
    goto v_4045;
v_4047:
    v_4214 = stack[-8];
    v_4214 = qcar(v_4214);
    v_4214 = (consp(v_4214) ? nil : lisp_true);
    goto v_4045;
    v_4214 = nil;
v_4045:
    if (v_4214 == nil) goto v_4043;
    v_4214 = stack[-8];
    fn = elt(env, 10); // !*d2q
    v_4214 = (*qfn1(fn))(fn, v_4214);
    env = stack[-10];
    stack[-4] = v_4214;
    goto v_3628;
v_4043:
    goto v_4062;
v_4058:
    v_4215 = stack[-3];
    goto v_4059;
v_4060:
    v_4214 = stack[-2];
    goto v_4061;
v_4062:
    goto v_4058;
v_4059:
    goto v_4060;
v_4061:
    v_4214 = cons(v_4215, v_4214);
    env = stack[-10];
    stack[-2] = v_4214;
    goto v_3619;
v_3628:
    v_4214 = qvalue(elt(env, 8)); // !*exp
    if (v_4214 == nil) goto v_4067;
    else goto v_4068;
v_4067:
    goto v_4075;
v_4071:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    fn = elt(env, 20); // mkprod
    stack[0] = (*qfn1(fn))(fn, v_4214);
    env = stack[-10];
    goto v_4072;
v_4073:
    v_4214 = stack[-4];
    v_4214 = qcdr(v_4214);
    fn = elt(env, 20); // mkprod
    v_4214 = (*qfn1(fn))(fn, v_4214);
    env = stack[-10];
    goto v_4074;
v_4075:
    goto v_4071;
v_4072:
    goto v_4073;
v_4074:
    v_4214 = cons(stack[0], v_4214);
    env = stack[-10];
    stack[-4] = v_4214;
    goto v_4066;
v_4068:
v_4066:
    goto v_4087;
v_4083:
    v_4215 = stack[-3];
    goto v_4084;
v_4085:
    v_4214 = stack[-4];
    goto v_4086;
v_4087:
    goto v_4083;
v_4084:
    goto v_4085;
v_4086:
    fn = elt(env, 19); // addsq
    v_4214 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    stack[-4] = v_4214;
    v_4214 = stack[-2];
    if (v_4214 == nil) goto v_4093;
    v_4214 = stack[-2];
    v_4214 = qcar(v_4214);
    stack[-3] = v_4214;
    v_4214 = stack[-2];
    v_4214 = qcdr(v_4214);
    stack[-2] = v_4214;
    goto v_3628;
v_4093:
    v_4214 = stack[-4];
    goto v_3618;
v_3629:
    goto v_4105;
v_4101:
    goto v_4111;
v_4107:
    stack[0] = stack[-6];
    goto v_4108;
v_4109:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = CC_subs2f1(elt(env, 0), v_4214);
    env = stack[-10];
    goto v_4110;
v_4111:
    goto v_4107;
v_4108:
    goto v_4109;
v_4110:
    fn = elt(env, 17); // multsq
    v_4215 = (*qfn2(fn))(fn, stack[0], v_4214);
    env = stack[-10];
    goto v_4102;
v_4103:
    v_4214 = stack[-3];
    goto v_4104;
v_4105:
    goto v_4101;
v_4102:
    goto v_4103;
v_4104:
    fn = elt(env, 19); // addsq
    v_4214 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    stack[-3] = v_4214;
    goto v_3626;
v_3630:
    goto v_4130;
v_4126:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4214 = qcar(v_4214);
    v_4215 = qcdr(v_4214);
    goto v_4127;
v_4128:
    v_4214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4129;
v_4130:
    goto v_4126;
v_4127:
    goto v_4128;
v_4129:
    if (v_4215 == v_4214) goto v_4124;
    else goto v_4125;
v_4124:
    goto v_4141;
v_4137:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4215 = qcar(v_4214);
    goto v_4138;
v_4139:
    v_4214 = elt(env, 2); // expt
    goto v_4140;
v_4141:
    goto v_4137;
v_4138:
    goto v_4139;
v_4140:
    v_4214 = Leqcar(nil, v_4215, v_4214);
    env = stack[-10];
    v_4214 = (v_4214 == nil ? lisp_true : nil);
    goto v_4123;
v_4125:
    v_4214 = nil;
    goto v_4123;
    v_4214 = nil;
v_4123:
    if (v_4214 == nil) goto v_4121;
    goto v_4155;
v_4151:
    v_4215 = stack[-9];
    goto v_4152;
v_4153:
    v_4214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4154;
v_4155:
    goto v_4151;
v_4152:
    goto v_4153;
v_4154:
    fn = elt(env, 21); // mksq
    v_4214 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    stack[-6] = v_4214;
    goto v_4119;
v_4121:
    goto v_4166;
v_4162:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    stack[0] = qcar(v_4214);
    goto v_4163;
v_4164:
    goto v_4177;
v_4171:
    v_4216 = elt(env, 9); // times
    goto v_4172;
v_4173:
    v_4214 = stack[-9];
    v_4214 = qcdr(v_4214);
    v_4214 = qcdr(v_4214);
    v_4215 = qcar(v_4214);
    goto v_4174;
v_4175:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    goto v_4176;
v_4177:
    goto v_4171;
v_4172:
    goto v_4173;
v_4174:
    goto v_4175;
v_4176:
    v_4214 = list3(v_4216, v_4215, v_4214);
    env = stack[-10];
    goto v_4165;
v_4166:
    goto v_4162;
v_4163:
    goto v_4164;
v_4165:
    v_4214 = list2(stack[0], v_4214);
    env = stack[-10];
    fn = elt(env, 22); // simpexpt
    v_4214 = (*qfn1(fn))(fn, v_4214);
    env = stack[-10];
    stack[-6] = v_4214;
    goto v_4119;
v_4119:
    goto v_4192;
v_4188:
    goto v_4198;
v_4194:
    stack[0] = stack[-6];
    goto v_4195;
v_4196:
    v_4214 = stack[-4];
    v_4214 = qcar(v_4214);
    v_4214 = qcdr(v_4214);
    v_4214 = CC_subs2f1(elt(env, 0), v_4214);
    env = stack[-10];
    goto v_4197;
v_4198:
    goto v_4194;
v_4195:
    goto v_4196;
v_4197:
    fn = elt(env, 17); // multsq
    v_4215 = (*qfn2(fn))(fn, stack[0], v_4214);
    env = stack[-10];
    goto v_4189;
v_4190:
    v_4214 = stack[-3];
    goto v_4191;
v_4192:
    goto v_4188;
v_4189:
    goto v_4190;
v_4191:
    fn = elt(env, 19); // addsq
    v_4214 = (*qfn2(fn))(fn, v_4215, v_4214);
    env = stack[-10];
    stack[-3] = v_4214;
    v_4214 = stack[-4];
    v_4214 = qcdr(v_4214);
    stack[-4] = v_4214;
    v_4214 = stack[-4];
    if (v_4214 == nil) goto v_4210;
    goto v_3630;
v_4210:
    goto v_3627;
    v_4214 = nil;
v_3618:
    goto v_3592;
    v_4214 = nil;
v_3592:
    return onevalue(v_4214);
}



// Code for genp

static LispObject CC_genp(LispObject env,
                         LispObject v_3589)
{
    env = qenv(env);
    LispObject v_3612, v_3613, v_3614;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3589);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3589);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3613 = v_3589;
// end of prologue
    v_3612 = v_3613;
    if (!consp(v_3612)) goto v_3593;
    else goto v_3594;
v_3593:
    goto v_3604;
v_3600:
    v_3614 = v_3613;
    goto v_3601;
v_3602:
    v_3612 = elt(env, 1); // gen
    goto v_3603;
v_3604:
    goto v_3600;
v_3601:
    goto v_3602;
v_3603:
    v_3612 = get(v_3614, v_3612);
    env = stack[0];
    if (v_3612 == nil) goto v_3598;
    else goto v_3597;
v_3598:
    v_3612 = v_3613;
    {
        fn = elt(env, 2); // mgenp
        return (*qfn1(fn))(fn, v_3612);
    }
v_3597:
    goto v_3592;
v_3594:
    v_3612 = nil;
    goto v_3592;
    v_3612 = nil;
v_3592:
    return onevalue(v_3612);
}



setup_type const u08_setup[] =
{
    {"letmtr3",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letmtr3},
    {"bound",                   CC_bound,       TOO_MANY_1,    WRONG_NO_1},
    {"bcsum",                   TOO_FEW_2,      CC_bcsum,      WRONG_NO_2},
    {"vecopp",                  CC_vecopp,      TOO_MANY_1,    WRONG_NO_1},
    {"sroad",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sroad},
    {"list2widestring",         CC_list2widestring,TOO_MANY_1, WRONG_NO_1},
    {"red-weight1",             TOO_FEW_2,      CC_redKweight1,WRONG_NO_2},
    {"dp_times_bc",             TOO_FEW_2,      CC_dp_times_bc,WRONG_NO_2},
    {"dv_skelhead",             CC_dv_skelhead, TOO_MANY_1,    WRONG_NO_1},
    {"general-plus-mod-p",      TOO_FEW_2,      CC_generalKplusKmodKp,WRONG_NO_2},
    {"mcharg2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mcharg2},
    {"times-term-mod-p",        TOO_FEW_2,      CC_timesKtermKmodKp,WRONG_NO_2},
    {"get_first_kernel",        TOO_FEW_2,      CC_get_first_kernel,WRONG_NO_2},
    {"lalr_precedence",         CC_lalr_precedence,TOO_MANY_1, WRONG_NO_1},
    {"anforml",                 CC_anforml,     TOO_MANY_1,    WRONG_NO_1},
    {"totallessp",              TOO_FEW_2,      CC_totallessp, WRONG_NO_2},
    {"talp_varlat",             CC_talp_varlat, TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_commonlenisone",    TOO_FEW_2,      CC_ibalp_commonlenisone,WRONG_NO_2},
    {"vdp_poly",                CC_vdp_poly,    TOO_MANY_1,    WRONG_NO_1},
    {"retattributes",           TOO_FEW_2,      CC_retattributes,WRONG_NO_2},
    {"retimes1",                CC_retimes1,    TOO_MANY_1,    WRONG_NO_1},
    {"variables",               CC_variables,   TOO_MANY_1,    WRONG_NO_1},
    {"worderp",                 TOO_FEW_2,      CC_worderp,    WRONG_NO_2},
    {"evaluate0",               TOO_FEW_2,      CC_evaluate0,  WRONG_NO_2},
    {"eofcheck",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_eofcheck},
    {"simpplus",                CC_simpplus,    TOO_MANY_1,    WRONG_NO_1},
    {"dp_ecart",                CC_dp_ecart,    TOO_MANY_1,    WRONG_NO_1},
    {"pdmult",                  TOO_FEW_2,      CC_pdmult,     WRONG_NO_2},
    {"divide:",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_divideT},
    {"cancel",                  CC_cancel,      TOO_MANY_1,    WRONG_NO_1},
    {"canonsq",                 CC_canonsq,     TOO_MANY_1,    WRONG_NO_1},
    {"rassoc",                  TOO_FEW_2,      CC_rassoc,     WRONG_NO_2},
    {"talp_atfp",               CC_talp_atfp,   TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_varlat",            CC_ibalp_varlat,TOO_MANY_1,    WRONG_NO_1},
    {"checktag",                CC_checktag,    TOO_MANY_1,    WRONG_NO_1},
    {"vevmaptozero1",           TOO_FEW_2,      CC_vevmaptozero1,WRONG_NO_2},
    {"physopsim*",              CC_physopsimH,  TOO_MANY_1,    WRONG_NO_1},
    {"rread",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rread},
    {"reval2",                  TOO_FEW_2,      CC_reval2,     WRONG_NO_2},
    {"divd",                    TOO_FEW_2,      CC_divd,       WRONG_NO_2},
    {"bas_make1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_bas_make1},
    {"adddummy1a",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_adddummy1a},
    {"yyreadch",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_yyreadch},
    {"rat_numrn",               CC_rat_numrn,   TOO_MANY_1,    WRONG_NO_1},
    {"procstat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_procstat},
    {"cdarx",                   CC_cdarx,       TOO_MANY_1,    WRONG_NO_1},
    {"talp_smupdknowl1",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_smupdknowl1},
    {"subs2f1",                 CC_subs2f1,     TOO_MANY_1,    WRONG_NO_1},
    {"genp",                    CC_genp,        TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u08", (two_args *)"154458 8004443 1929159", 0}
};

// end of generated code
