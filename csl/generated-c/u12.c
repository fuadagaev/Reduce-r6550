
/* $destdir\u12.c        Machine generated C code */

/* Signature: 00000000 27-Aug-2011 */

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
#define SOCKETS                  1
#endif
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
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
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((uint32_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)
#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
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
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif 
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif 
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
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
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
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
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
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#ifdef OLD_VERSION
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
#else 
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF ((Lisp_Object)(int32_t)0xff000402)
#endif  
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;   
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;   
    Lisp_Object env;     
    intptr_t function1;  
    intptr_t function2;  
    intptr_t functionn;  
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;
#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;
#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_no_longer_used       34      
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
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
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
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
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
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
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *C_stack_limit;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
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
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
#endif
extern int32_t software_ticks, countdown;
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol;
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
#define procstack             BASE[156]
#define procmem               BASE[157]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern char **csl_argv;
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;
extern int boffop;
extern void packbyte(int c);
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
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
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
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
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
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
extern CSLbool open_output(char *s, int len);
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
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
#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32_t);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
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
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
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
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for ratpoly_mvartest */

static Lisp_Object CC_ratpoly_mvartest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_mvartest");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v1;
    v6 = v0;
/* end of prologue */
    v4 = v6;
    v4 = qcar(v4);
    if (v4 == nil) goto v7;
    v4 = v6;
    v4 = qcar(v4);
    if (is_number(v4)) goto v8;
    v4 = v6;
    v4 = qcar(v4);
    v4 = qcar(v4);
    v4 = qcar(v4);
    v4 = qcar(v4);
    v4 = (v4 == v5 ? lisp_true : nil);
    return onevalue(v4);

v8:
    v4 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v4);

v7:
    v4 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v4);
}



/* Code for mathml2 */

static Lisp_Object MS_CDECL CC_mathml2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml2");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    {
        fn = elt(env, 2); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
}



/* Code for spquotematrix */

static Lisp_Object CC_spquotematrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v10;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spquotematrix");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v10 = elt(env, 1); /* sparse */
    return onevalue(v10);
}



/* Code for newenv */

static Lisp_Object CC_newenv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newenv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v13 = v8;
    v8 = elt(env, 1); /* unbound */
    {
        fn = elt(env, 2); /* bind */
        return (*qfn2(fn))(qenv(fn), v13, v8);
    }
}



/* Code for wedgepf */

static Lisp_Object CC_wedgepf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgepf");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v14 = v1;
    v15 = v0;
/* end of prologue */
    stack[0] = v15;
    fn = elt(env, 1); /* !*pf2wedgepf */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    fn = elt(env, 2); /* wedgepf2 */
    v14 = (*qfn2(fn))(qenv(fn), stack[0], v14);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*wedgepf2pf */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for prinfit */

static Lisp_Object MS_CDECL CC_prinfit(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prinfit");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinfit");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v26 = qvalue(elt(env, 1)); /* !*nat */
    if (v26 == nil) goto v14;
    v26 = qvalue(elt(env, 3)); /* testing!-width!* */
    goto v29;

v29:
    if (v26 == nil) goto v30;
    v26 = stack[0];
    if (v26 == nil) goto v31;
    v26 = stack[0];
    fn = elt(env, 4); /* oprin */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    goto v31;

v31:
    v27 = stack[-2];
    v26 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* maprint */
        return (*qfn2(fn))(qenv(fn), v27, v26);
    }

v30:
    v28 = stack[-2];
    v27 = stack[-1];
    v26 = stack[0];
    fn = elt(env, 6); /* layout!-formula */
    v26 = (*qfnn(fn))(qenv(fn), 3, v28, v27, v26);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    v27 = v26;
    v26 = v27;
    if (v26 == nil) goto v33;
    v26 = v27;
    fn = elt(env, 7); /* putpline */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v26 = nil;
    { popv(4); return onevalue(v26); }

v33:
    v26 = stack[0];
    if (v26 == nil) goto v34;
    v26 = stack[0];
    fn = elt(env, 4); /* oprin */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    goto v34;

v34:
    v27 = stack[-2];
    v26 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* maprint */
        return (*qfn2(fn))(qenv(fn), v27, v26);
    }

v14:
    v26 = qvalue(elt(env, 2)); /* t */
    goto v29;
/* error exit handlers */
v32:
    popv(4);
    return nil;
}



/* Code for !:dmpluslst */

static Lisp_Object CC_Tdmpluslst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmpluslst");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v2 = v31;
    if (v2 == nil) goto v18;
    v2 = v31;
    v2 = qcdr(v2);
    if (v2 == nil) goto v11;
    v2 = v31;
    stack[0] = qcar(v2);
    v2 = v31;
    v2 = qcdr(v2);
    v2 = CC_Tdmpluslst(env, v2);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    {
        Lisp_Object v6 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:plus */
        return (*qfn2(fn))(qenv(fn), v6, v2);
    }

v11:
    v2 = v31;
    v2 = qcar(v2);
    { popv(2); return onevalue(v2); }

v18:
    v2 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v2); }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for ptoken */

static Lisp_Object MS_CDECL CC_ptoken(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ptoken");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ptoken");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 7); /* token1 */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    stack[0] = v44;
    v45 = stack[0];
    v44 = elt(env, 1); /* !) */
    if (v45 == v44) goto v47;
    v44 = qvalue(elt(env, 4)); /* nil */
    goto v8;

v8:
    if (v44 == nil) goto v25;
    v44 = qvalue(elt(env, 2)); /* outl!* */
    v44 = qcdr(v44);
    qvalue(elt(env, 2)) = v44; /* outl!* */
    goto v25;

v25:
    v45 = stack[0];
    v44 = qvalue(elt(env, 2)); /* outl!* */
    v44 = cons(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    qvalue(elt(env, 2)) = v44; /* outl!* */
    v45 = stack[0];
    v44 = elt(env, 5); /* !( */
    if (v45 == v44) goto v48;
    v45 = stack[0];
    v44 = elt(env, 1); /* !) */
    v44 = (v45 == v44 ? lisp_true : nil);
    goto v49;

v49:
    if (!(v44 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v45 = elt(env, 3); /* !  */
    v44 = qvalue(elt(env, 2)); /* outl!* */
    v44 = cons(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    qvalue(elt(env, 2)) = v44; /* outl!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v48:
    v44 = qvalue(elt(env, 6)); /* t */
    goto v49;

v47:
    v45 = qvalue(elt(env, 2)); /* outl!* */
    v44 = elt(env, 3); /* !  */
    v44 = Leqcar(nil, v45, v44);
    env = stack[-1];
    goto v8;
/* error exit handlers */
v46:
    popv(2);
    return nil;
}



/* Code for mv!-domainlist!-!- */

static Lisp_Object CC_mvKdomainlistKK(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist--");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v9;

v9:
    v52 = stack[-1];
    if (v52 == nil) goto v12;
    v52 = stack[-1];
    v53 = qcar(v52);
    v52 = stack[0];
    v52 = qcar(v52);
    v53 = difference2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v52 = stack[-2];
    v52 = cons(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    stack[-2] = v52;
    v52 = stack[-1];
    v52 = qcdr(v52);
    stack[-1] = v52;
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v9;

v12:
    v52 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v54:
    popv(4);
    return nil;
}



/* Code for red_better */

static Lisp_Object CC_red_better(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_better");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v14 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bas_dplen */
    stack[-1] = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v14 = stack[0];
    fn = elt(env, 1); /* bas_dplen */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v16;
    {
        Lisp_Object v55 = stack[-1];
        popv(3);
        return Llessp(nil, v55, v14);
    }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for pneg */

static Lisp_Object CC_pneg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pneg");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v58 = v0;
/* end of prologue */
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) goto v13;
    v58 = stack[-4];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[0] = qcar(v58);
    v58 = v59;
    v58 = qcdr(v58);
    fn = elt(env, 2); /* cneg */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v58 = cons(stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    stack[-2] = v58;
    stack[-3] = v58;
    goto v60;

v60:
    v58 = stack[-4];
    v58 = qcdr(v58);
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v58 = stack[-4];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[0] = qcar(v58);
    v58 = v59;
    v58 = qcdr(v58);
    fn = elt(env, 2); /* cneg */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v58 = cons(stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v58 = Lrplacd(nil, stack[-1], v58);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    goto v60;

v13:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v58); }
/* error exit handlers */
v27:
    popv(6);
    return nil;
}



/* Code for dl_get */

static Lisp_Object CC_dl_get(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v13 = v8;
    v8 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* dl_get2 */
        return (*qfn2(fn))(qenv(fn), v13, v8);
    }
}



/* Code for rnminus!: */

static Lisp_Object CC_rnminusT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnminus:");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v42 = stack[0];
    stack[-1] = qcar(v42);
    v42 = stack[0];
    v42 = qcdr(v42);
    v42 = qcar(v42);
    fn = elt(env, 1); /* !:minus */
    v61 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v42 = stack[0];
    v42 = qcdr(v42);
    v42 = qcdr(v42);
    {
        Lisp_Object v36 = stack[-1];
        popv(2);
        return list2star(v36, v61, v42);
    }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for gcref_mkgraph */

static Lisp_Object CC_gcref_mkgraph(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_mkgraph");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v14 = qvalue(elt(env, 1)); /* !*gcrefudg */
    if (v14 == nil) goto v12;
    v14 = v15;
    {
        fn = elt(env, 2); /* gcref_mkgraph!-udg */
        return (*qfn1(fn))(qenv(fn), v14);
    }

v12:
    v14 = v15;
    {
        fn = elt(env, 3); /* gcref_mkgraph!-tgf */
        return (*qfn1(fn))(qenv(fn), v14);
    }
}



/* Code for rl_simpl */

static Lisp_Object MS_CDECL CC_rl_simpl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_simpl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpl");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v50 = v17;
    v35 = v1;
    v36 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simpl!* */
    v50 = list3(v36, v35, v50);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-1];
    {
        Lisp_Object v2 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v2, v50);
    }
/* error exit handlers */
v3:
    popv(2);
    return nil;
}



/* Code for removeg2 */

static Lisp_Object MS_CDECL CC_removeg2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90, v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg2");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v17;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v89 = stack[-4];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v90 = v89;
    v89 = stack[-3];
    v91 = qcar(v89);
    v89 = elt(env, 1); /* g3 */
    if (v91 == v89) goto v93;
    v89 = qvalue(elt(env, 2)); /* t */
    goto v47;

v47:
    if (v89 == nil) goto v59;
    v92 = elt(env, 3); /* "Edge" */
    v91 = v90;
    v90 = elt(env, 4); /* "is absent in vertex" */
    v89 = stack[-3];
    v89 = list4(v92, v91, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    fn = elt(env, 6); /* cerror */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    goto v55;

v55:
    stack[-3] = v89;
    v90 = stack[-3];
    v89 = elt(env, 5); /* qg */
    v89 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = stack[-5];
    stack[0] = qcar(v89);
    v89 = stack[-5];
    v89 = qcdr(v89);
    fn = elt(env, 7); /* mkcopy */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = cons(stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    stack[-6] = v89;
    v90 = stack[-4];
    v89 = stack[-6];
    v89 = Lmember(nil, v90, v89);
    v89 = qcar(v89);
    stack[-1] = v89;
    v90 = stack[-3];
    v89 = stack[-6];
    v89 = Lmember(nil, v90, v89);
    v89 = qcar(v89);
    stack[0] = v89;
    v89 = stack[-4];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    stack[-2] = v89;
    v89 = stack[-4];
    v89 = qcdr(v89);
    v90 = qcdr(v89);
    v89 = stack[-4];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v89 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = stack[-4];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v90 = qcdr(v89);
    v89 = stack[-3];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v89 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = stack[-3];
    v89 = qcdr(v89);
    v90 = qcdr(v89);
    v89 = stack[-2];
    v89 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = qcar(v89);
    stack[-2] = v89;
    v89 = stack[-1];
    v90 = qcdr(v89);
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v89 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v90 = qcdr(v89);
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v89 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = stack[0];
    v89 = qcdr(v89);
    v90 = qcdr(v89);
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v89 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = stack[0];
    v90 = qcdr(v89);
    v89 = stack[-2];
    v89 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    stack[0] = stack[-5];
    v89 = stack[-6];
    v89 = qcar(v89);
    v89 = qcar(v89);
    fn = elt(env, 8); /* negf */
    v90 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    v89 = stack[-6];
    v89 = qcar(v89);
    v89 = qcdr(v89);
    v90 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v89 = stack[-6];
    v89 = qcdr(v89);
    {
        Lisp_Object v95 = stack[0];
        popv(8);
        return list2star(v95, v90, v89);
    }

v59:
    v89 = stack[-3];
    fn = elt(env, 9); /* revv0 */
    v89 = (*qfn2(fn))(qenv(fn), v89, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-7];
    goto v55;

v93:
    v91 = v90;
    v89 = stack[-3];
    v89 = qcdr(v89);
    v89 = Lmemq(nil, v91, v89);
    v89 = (v89 == nil ? lisp_true : nil);
    goto v47;
/* error exit handlers */
v94:
    popv(8);
    return nil;
}



/* Code for rl_susipost */

static Lisp_Object CC_rl_susipost(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susipost");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v43 = v1;
    v42 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susipost!* */
    v43 = list2(v42, v43);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    {
        Lisp_Object v50 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v50, v43);
    }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for cl_varl2 */

static Lisp_Object MS_CDECL CC_cl_varl2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159, v160, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_varl2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_varl2");
#endif
    if (stack >= stacklimit)
    {
        push4(v10,v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v17,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v10;
    stack[0] = v17;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v162:
    v158 = stack[-4];
    if (!consp(v158)) goto v13;
    v158 = stack[-4];
    v158 = qcar(v158);
    goto v8;

v8:
    v160 = v158;
    v159 = v160;
    v158 = elt(env, 1); /* true */
    if (v159 == v158) goto v163;
    v159 = v160;
    v158 = elt(env, 3); /* false */
    v158 = (v159 == v158 ? lisp_true : nil);
    goto v36;

v36:
    if (v158 == nil) goto v27;
    v159 = stack[-3];
    v158 = stack[-2];
    popv(6);
    return cons(v159, v158);

v27:
    v159 = v160;
    v158 = elt(env, 4); /* or */
    if (v159 == v158) goto v164;
    v159 = v160;
    v158 = elt(env, 5); /* and */
    v158 = (v159 == v158 ? lisp_true : nil);
    goto v165;

v165:
    if (v158 == nil) goto v166;
    v158 = qvalue(elt(env, 2)); /* t */
    goto v58;

v58:
    if (v158 == nil) goto v167;
    v158 = qvalue(elt(env, 2)); /* t */
    goto v88;

v88:
    if (v158 == nil) goto v168;
    v158 = stack[-4];
    v158 = qcdr(v158);
    stack[-1] = v158;
    goto v169;

v169:
    v158 = stack[-1];
    if (v158 == nil) goto v71;
    v158 = stack[-1];
    v158 = qcar(v158);
    v161 = v158;
    v160 = stack[-3];
    v159 = stack[0];
    v158 = stack[-2];
    v158 = CC_cl_varl2(env, 4, v161, v160, v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v159 = v158;
    v158 = v159;
    v158 = qcar(v158);
    stack[-3] = v158;
    v158 = v159;
    v158 = qcdr(v158);
    stack[-2] = v158;
    v158 = stack[-1];
    v158 = qcdr(v158);
    stack[-1] = v158;
    goto v169;

v71:
    v159 = stack[-3];
    v158 = stack[-2];
    popv(6);
    return cons(v159, v158);

v168:
    v159 = v160;
    v158 = elt(env, 11); /* ex */
    if (v159 == v158) goto v69;
    v159 = v160;
    v158 = elt(env, 12); /* all */
    v158 = (v159 == v158 ? lisp_true : nil);
    goto v171;

v171:
    if (v158 == nil) goto v172;
    v158 = stack[-4];
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    stack[-1] = qcar(v158);
    v158 = stack[-4];
    v158 = qcdr(v158);
    v159 = qcar(v158);
    v158 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    stack[0] = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v158 = stack[-4];
    v158 = qcdr(v158);
    v159 = qcar(v158);
    v158 = stack[-2];
    v158 = cons(v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-4] = stack[-1];
    stack[-2] = v158;
    goto v162;

v172:
    v159 = v160;
    v158 = elt(env, 13); /* bex */
    if (v159 == v158) goto v173;
    v159 = v160;
    v158 = elt(env, 14); /* ball */
    v158 = (v159 == v158 ? lisp_true : nil);
    goto v174;

v174:
    if (v158 == nil) goto v175;
    v158 = stack[-4];
    v158 = qcdr(v158);
    stack[-1] = qcar(v158);
    v158 = stack[-4];
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v161 = qcar(v158);
    v160 = stack[-3];
    v159 = qvalue(elt(env, 10)); /* nil */
    v158 = qvalue(elt(env, 10)); /* nil */
    v158 = CC_cl_varl2(env, 4, v161, v160, v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v158 = qcar(v158);
    fn = elt(env, 16); /* delq */
    v158 = (*qfn2(fn))(qenv(fn), stack[-1], v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-1] = v158;
    v158 = stack[-4];
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    stack[-3] = qcar(v158);
    v158 = stack[-4];
    v158 = qcdr(v158);
    v159 = qcar(v158);
    v158 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    stack[0] = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v158 = stack[-4];
    v158 = qcdr(v158);
    v159 = qcar(v158);
    v158 = stack[-2];
    v158 = cons(v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v158 = CC_cl_varl2(env, 4, stack[-3], stack[-1], stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-1] = v158;
    v158 = stack[-4];
    v158 = qcdr(v158);
    v159 = qcar(v158);
    v158 = stack[-1];
    v158 = qcar(v158);
    fn = elt(env, 16); /* delq */
    v159 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v158 = stack[-1];
    v158 = qcdr(v158);
    popv(6);
    return cons(v159, v158);

v175:
    v158 = stack[-4];
    fn = elt(env, 17); /* rl_varlat */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-1] = v158;
    goto v176;

v176:
    v158 = stack[-1];
    if (v158 == nil) goto v177;
    v158 = stack[-1];
    v158 = qcar(v158);
    v160 = v158;
    v159 = v160;
    v158 = stack[0];
    v158 = Lmemq(nil, v159, v158);
    if (!(v158 == nil)) goto v178;
    v159 = v160;
    v158 = stack[-3];
    fn = elt(env, 15); /* lto_insertq */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-3] = v158;
    goto v178;

v178:
    v158 = stack[-1];
    v158 = qcdr(v158);
    stack[-1] = v158;
    goto v176;

v177:
    v159 = stack[-3];
    v158 = stack[-2];
    popv(6);
    return cons(v159, v158);

v173:
    v158 = qvalue(elt(env, 2)); /* t */
    goto v174;

v69:
    v158 = qvalue(elt(env, 2)); /* t */
    goto v171;

v167:
    v159 = v160;
    v158 = elt(env, 7); /* impl */
    if (v159 == v158) goto v81;
    v159 = v160;
    v158 = elt(env, 8); /* repl */
    if (v159 == v158) goto v179;
    v159 = v160;
    v158 = elt(env, 9); /* equiv */
    v158 = (v159 == v158 ? lisp_true : nil);
    goto v88;

v179:
    v158 = qvalue(elt(env, 2)); /* t */
    goto v88;

v81:
    v158 = qvalue(elt(env, 2)); /* t */
    goto v88;

v166:
    v159 = v160;
    v158 = elt(env, 6); /* not */
    v158 = (v159 == v158 ? lisp_true : nil);
    goto v58;

v164:
    v158 = qvalue(elt(env, 2)); /* t */
    goto v165;

v163:
    v158 = qvalue(elt(env, 2)); /* t */
    goto v36;

v13:
    v158 = stack[-4];
    goto v8;
/* error exit handlers */
v170:
    popv(6);
    return nil;
}



/* Code for ldt!-tvar */

static Lisp_Object CC_ldtKtvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v163, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v36 = v0;
/* end of prologue */
    v36 = qcar(v36);
    v36 = qcar(v36);
    v163 = v36;
    v36 = v163;
    v3 = elt(env, 1); /* df */
    if (!consp(v36)) return onevalue(v163);
    v36 = qcar(v36);
    if (!(v36 == v3)) return onevalue(v163);
    v36 = v163;
    v36 = qcdr(v36);
    v36 = qcar(v36);
    return onevalue(v36);
}



/* Code for simpindexvar */

static Lisp_Object CC_simpindexvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpindexvar");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitindexvar */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v7);
    }
/* error exit handlers */
v9:
    popv(1);
    return nil;
}



/* Code for mksetq */

static Lisp_Object CC_mksetq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v34, v180, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksetq");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v34 = v1;
    v180 = v0;
/* end of prologue */
    v88 = v180;
    if (!consp(v88)) goto v12;
    v88 = v180;
    v149 = qcar(v88);
    v88 = elt(env, 2); /* setfn */
    v88 = get(v149, v88);
    env = stack[0];
    v149 = v88;
    if (v88 == nil) goto v154;
    v88 = v149;
        popv(1);
        return Lapply2(nil, 3, v88, v180, v34);

v154:
    v34 = v180;
    v88 = elt(env, 3); /* "assignment argument" */
    fn = elt(env, 4); /* typerr */
    v88 = (*qfn2(fn))(qenv(fn), v34, v88);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v88 = nil;
    { popv(1); return onevalue(v88); }

v12:
    v88 = elt(env, 1); /* setq */
    popv(1);
    return list3(v88, v180, v34);
/* error exit handlers */
v58:
    popv(1);
    return nil;
}



/* Code for evalneq */

static Lisp_Object CC_evalneq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalneq");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v1;
    v14 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalequal */
    v29 = (*qfn2(fn))(qenv(fn), v14, v29);
    errexit();
    v29 = (v29 == nil ? lisp_true : nil);
    return onevalue(v29);
}



/* Code for mv!-pow!-!- */

static Lisp_Object CC_mvKpowKK(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow--");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v9;

v9:
    v52 = stack[-1];
    if (v52 == nil) goto v12;
    v52 = stack[-1];
    v53 = qcar(v52);
    v52 = stack[0];
    v52 = qcar(v52);
    v53 = difference2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v52 = stack[-2];
    v52 = cons(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    stack[-2] = v52;
    v52 = stack[-1];
    v52 = qcdr(v52);
    stack[-1] = v52;
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v9;

v12:
    v52 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v54:
    popv(4);
    return nil;
}



/* Code for bc_fi */

static Lisp_Object CC_bc_fi(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v43, v42;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_fi");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v42 = v0;
/* end of prologue */
    v43 = v42;
    v55 = (Lisp_Object)1; /* 0 */
    if (!(v43 == v55)) return onevalue(v42);
    v55 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v55);
}



/* Code for pv_times3 */

static Lisp_Object CC_pv_times3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times3");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v4 = stack[-1];
    v5 = qcar(v4);
    v4 = stack[0];
    v4 = qcar(v4);
    stack[-2] = times2(v5, v4);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v4 = stack[-1];
    v5 = qcdr(v4);
    v4 = stack[0];
    v4 = qcdr(v4);
    fn = elt(env, 1); /* pappend */
    v4 = (*qfn2(fn))(qenv(fn), v5, v4);
    nil = C_nil;
    if (exception_pending()) goto v25;
    {
        Lisp_Object v93 = stack[-2];
        popv(4);
        return cons(v93, v4);
    }
/* error exit handlers */
v25:
    popv(4);
    return nil;
}



/* Code for dv_skel2factor1 */

static Lisp_Object CC_dv_skel2factor1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor1");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v86 = stack[-1];
    if (v86 == nil) goto v12;
    v86 = stack[-1];
    fn = elt(env, 3); /* listp */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    if (v86 == nil) goto v49;
    v86 = stack[-1];
    v182 = qcar(v86);
    v86 = stack[0];
    v86 = CC_dv_skel2factor1(env, v182, v86);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    stack[-2] = v86;
    v86 = stack[-1];
    v182 = qcdr(v86);
    v86 = stack[0];
    v86 = CC_dv_skel2factor1(env, v182, v86);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v86 = cons(stack[-2], v86);
    nil = C_nil;
    if (exception_pending()) goto v183;
    { popv(4); return onevalue(v86); }

v49:
    v182 = stack[-1];
    v86 = elt(env, 2); /* !~dv */
    if (!(v182 == v86)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v86 = stack[0];
    v86 = qcar(v86);
    stack[-1] = v86;
    v86 = stack[0];
    v86 = qcdr(v86);
    if (v86 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v182 = stack[0];
    v86 = stack[0];
    v86 = qcdr(v86);
    v86 = qcar(v86);
    v86 = Lrplaca(nil, v182, v86);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v182 = stack[0];
    v86 = stack[0];
    v86 = qcdr(v86);
    v86 = qcdr(v86);
    v86 = Lrplacd(nil, v182, v86);
    nil = C_nil;
    if (exception_pending()) goto v183;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v12:
    v86 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v86); }
/* error exit handlers */
v183:
    popv(4);
    return nil;
}



/* Code for copy!-vector */

static Lisp_Object MS_CDECL CC_copyKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v21, v22, v49, v48, v33, v184, v185;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "copy-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy-vector");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v48 = v17;
    v33 = v1;
    v184 = v0;
/* end of prologue */
    v23 = (Lisp_Object)1; /* 0 */
    v185 = v23;
    goto v14;

v14:
    v21 = v33;
    v23 = v185;
    v23 = (Lisp_Object)(int32_t)((int32_t)v21 - (int32_t)v23 + TAG_FIXNUM);
    v23 = ((intptr_t)(v23) < 0 ? lisp_true : nil);
    if (!(v23 == nil)) return onevalue(v33);
    v49 = v48;
    v22 = v185;
    v21 = v184;
    v23 = v185;
    v23 = *(Lisp_Object *)((char *)v21 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v22/(16/CELL))) = v23;
    v23 = v185;
    v23 = (Lisp_Object)((int32_t)(v23) + 0x10);
    v185 = v23;
    goto v14;
}



/* Code for difference!-mod!-p */

static Lisp_Object CC_differenceKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v29 = v1;
    v14 = v0;
/* end of prologue */
    stack[0] = v14;
    fn = elt(env, 1); /* minus!-mod!-p */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    {
        Lisp_Object v16 = stack[0];
        popv(2);
        fn = elt(env, 2); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v16, v29);
    }
/* error exit handlers */
v87:
    popv(2);
    return nil;
}



/* Code for traput */

static Lisp_Object MS_CDECL CC_traput(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v165, v164, v26;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "traput");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for traput");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v20 = v17;
    v165 = v1;
    v164 = v0;
/* end of prologue */
    v26 = v164;
    v19 = v165;
    v19 = get(v26, v19);
    env = stack[-2];
    v26 = v19;
    if (v19 == nil) goto v187;
    v19 = qvalue(elt(env, 1)); /* toplv!* */
    if (!(v19 == nil)) goto v11;
    v165 = v20;
    v19 = v26;
    v19 = Lmemq(nil, v165, v19);
    if (!(v19 == nil)) goto v11;
    stack[0] = v26;
    v19 = v20;
    v20 = v26;
    v20 = qcdr(v20);
    v19 = cons(v19, v20);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    v19 = Lrplacd(nil, stack[0], v19);
    nil = C_nil;
    if (exception_pending()) goto v188;
    goto v11;

v11:
    v19 = nil;
    { popv(3); return onevalue(v19); }

v187:
    stack[-1] = v164;
    stack[0] = v165;
    v19 = v20;
    v19 = ncons(v19);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    v19 = Lputprop(nil, 3, stack[-1], stack[0], v19);
    nil = C_nil;
    if (exception_pending()) goto v188;
    goto v11;
/* error exit handlers */
v188:
    popv(3);
    return nil;
}



/* Code for sfto_ucontentf */

static Lisp_Object CC_sfto_ucontentf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_ucontentf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    v51 = v6;
    if (!consp(v51)) goto v11;
    v51 = v6;
    v51 = qcar(v51);
    v51 = (consp(v51) ? nil : lisp_true);
    goto v60;

v60:
    if (!(v51 == nil)) return onevalue(v6);
    v51 = v6;
    v6 = qcar(v6);
    v6 = qcar(v6);
    v6 = qcar(v6);
    {
        fn = elt(env, 2); /* sfto_ucontentf1 */
        return (*qfn2(fn))(qenv(fn), v51, v6);
    }

v11:
    v51 = qvalue(elt(env, 1)); /* t */
    goto v60;
}



/* Code for ofsf_prepat */

static Lisp_Object CC_ofsf_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_prepat");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v47 = stack[-1];
    stack[-2] = qcar(v47);
    v47 = stack[-1];
    v47 = qcdr(v47);
    v47 = qcar(v47);
    fn = elt(env, 1); /* prepf */
    stack[0] = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v47 = stack[-1];
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = qcar(v47);
    fn = elt(env, 1); /* prepf */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v163;
    {
        Lisp_Object v3 = stack[-2];
        Lisp_Object v2 = stack[0];
        popv(4);
        return list3(v3, v2, v47);
    }
/* error exit handlers */
v163:
    popv(4);
    return nil;
}



/* Code for attributesml */

static Lisp_Object CC_attributesml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for attributesml");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v181 = stack[-1];
    if (v181 == nil) goto v60;
    v181 = elt(env, 2); /* " " */
    v181 = Lprinc(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v181 = stack[-1];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = Lprinc(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v181 = elt(env, 3); /* "=""" */
    v181 = Lprinc(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v181 = stack[-1];
    v181 = qcar(v181);
    v190 = qcar(v181);
    v181 = elt(env, 4); /* definitionurl */
    if (v190 == v181) goto v149;
    v181 = stack[-1];
    v181 = qcar(v181);
    v181 = qcdr(v181);
    v190 = qcar(v181);
    v181 = elt(env, 5); /* vectorml */
    if (v190 == v181) goto v40;
    v181 = stack[-1];
    v181 = qcar(v181);
    v181 = qcdr(v181);
    v181 = qcar(v181);
    v181 = Lprinc(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    goto v163;

v163:
    v181 = elt(env, 8); /* """" */
    v181 = Lprinc(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v181 = stack[-1];
    v190 = qcdr(v181);
    v181 = stack[0];
    v181 = CC_attributesml(env, v190, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    goto v9;

v9:
    v181 = nil;
    { popv(3); return onevalue(v181); }

v40:
    v181 = elt(env, 6); /* "vector" */
    v181 = Lprinc(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    goto v163;

v149:
    v181 = stack[-1];
    v181 = qcar(v181);
    v181 = qcdr(v181);
    v181 = qcar(v181);
    fn = elt(env, 9); /* list2string */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    goto v163;

v60:
    v181 = stack[0];
    v181 = Lprinc(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v181 = elt(env, 1); /* ">" */
    v181 = Lprinc(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v151;
    goto v9;
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for groebnormalform */

static Lisp_Object MS_CDECL CC_groebnormalform(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v42, v61, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groebnormalform");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebnormalform");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v17;
    v42 = v1;
    v61 = v0;
/* end of prologue */
    v47 = v61;
    v61 = v42;
    v42 = v43;
    v43 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* groebnormalform0 */
        return (*qfnn(fn))(qenv(fn), 4, v47, v61, v42, v43);
    }
}



/* Code for prop!-simp */

static Lisp_Object CC_propKsimp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v47, v50, v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v61 = v1;
    v47 = v0;
/* end of prologue */
    v36 = v47;
    v35 = v61;
    v50 = qvalue(elt(env, 1)); /* nil */
    v47 = (Lisp_Object)1; /* 0 */
    v61 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 2); /* prop!-simp1 */
        return (*qfnn(fn))(qenv(fn), 5, v36, v35, v50, v47, v61);
    }
}



/* Code for assert_format */

static Lisp_Object MS_CDECL CC_assert_format(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v202, v203;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assert_format");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_format");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v201 = v17;
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    v201 = Lexplode(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    stack[-10] = v201;
    stack[-7] = elt(env, 1); /* !! */
    stack[-6] = elt(env, 2); /* !) */
    stack[-5] = elt(env, 1); /* !! */
    stack[-4] = elt(env, 3); /* !  */
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 4); /* !- */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 5); /* !> */
    v203 = elt(env, 1); /* !! */
    v202 = elt(env, 3); /* !  */
    v201 = stack[-10];
    v201 = list2star(v203, v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = list2star(stack[-1], stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = list2star(stack[-3], stack[-2], v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = list2star(stack[-5], stack[-4], v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = list2star(stack[-7], stack[-6], v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    stack[-10] = v201;
    v201 = stack[-8];
    v201 = Lreverse(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    stack[-2] = v201;
    goto v59;

v59:
    v201 = stack[-2];
    if (v201 == nil) goto v58;
    v201 = stack[-2];
    v201 = qcar(v201);
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 7); /* !, */
    v202 = Lexplode(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = stack[-10];
    v201 = Lnconc(nil, v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = list2star(stack[-1], stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    stack[-10] = v201;
    v201 = stack[-2];
    v201 = qcdr(v201);
    stack[-2] = v201;
    goto v59;

v58:
    v201 = stack[-10];
    v201 = qcdr(v201);
    v201 = qcdr(v201);
    stack[-10] = v201;
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 8); /* !: */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 3); /* !  */
    v203 = elt(env, 1); /* !! */
    v202 = elt(env, 9); /* !( */
    v201 = stack[-10];
    v201 = list2star(v203, v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = list2star(stack[-1], stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = list2star(stack[-3], stack[-2], v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    stack[-10] = v201;
    v201 = stack[-9];
    v202 = Lexplode(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-11];
    v201 = stack[-10];
    v201 = Lnconc(nil, v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v204;
    stack[-10] = v201;
    v201 = stack[-10];
        popv(12);
        return Lcompress(nil, v201);
/* error exit handlers */
v204:
    popv(12);
    return nil;
}



/* Code for aminusp!:1 */

static Lisp_Object CC_aminuspT1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v206, v207, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aminusp:1");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v205 = stack[-1];
    fn = elt(env, 6); /* aeval!* */
    v205 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    stack[-1] = v205;
    v205 = stack[-1];
    stack[-2] = v205;
    v205 = stack[-2];
    v205 = integerp(v205);
    if (v205 == nil) goto v42;
    v205 = stack[-2];
        popv(4);
        return Lminusp(nil, v205);

v42:
    v206 = stack[-2];
    v205 = elt(env, 1); /* !*sq */
    if (!consp(v206)) goto v2;
    v206 = qcar(v206);
    if (!(v206 == v205)) goto v2;

v12:
    v205 = stack[-2];
    v205 = qcdr(v205);
    v205 = qcar(v205);
    stack[-2] = v205;
    v205 = stack[-2];
    v205 = qcar(v205);
    v205 = integerp(v205);
    if (v205 == nil) goto v26;
    v205 = stack[-2];
    v205 = qcdr(v205);
    v205 = integerp(v205);
    if (v205 == nil) goto v26;
    v205 = stack[-2];
    v205 = qcar(v205);
        popv(4);
        return Lminusp(nil, v205);

v26:
    v205 = stack[-2];
    v206 = qcdr(v205);
    v205 = (Lisp_Object)17; /* 1 */
    if (v206 == v205) goto v45;
    v205 = qvalue(elt(env, 4)); /* t */
    goto v20;

v20:
    if (v205 == nil) goto v209;
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v205 = stack[-1];
    fn = elt(env, 7); /* reval */
    v208 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    v207 = elt(env, 3); /* "invalid in FOR statement" */
    v206 = qvalue(elt(env, 2)); /* nil */
    v205 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v205 = (*qfnn(fn))(qenv(fn), 5, stack[0], v208, v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v205 = nil;
    { popv(4); return onevalue(v205); }

v209:
    v206 = elt(env, 5); /* !:minusp */
    v205 = stack[-2];
        popv(4);
        return Lapply1(nil, v206, v205);

v45:
    v205 = stack[-2];
    v205 = qcar(v205);
    stack[-2] = v205;
    if (!consp(v205)) goto v190;
    v205 = stack[-2];
    v205 = qcar(v205);
    v205 = (consp(v205) ? nil : lisp_true);
    goto v181;

v181:
    v205 = (v205 == nil ? lisp_true : nil);
    goto v20;

v190:
    v205 = qvalue(elt(env, 4)); /* t */
    goto v181;

v2:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v205 = stack[-1];
    fn = elt(env, 7); /* reval */
    v208 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    v207 = elt(env, 3); /* "invalid in FOR statement" */
    v206 = qvalue(elt(env, 2)); /* nil */
    v205 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v205 = (*qfnn(fn))(qenv(fn), 5, stack[0], v208, v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    goto v12;
/* error exit handlers */
v198:
    popv(4);
    return nil;
}



/* Code for nzeros */

static Lisp_Object CC_nzeros(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzeros");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v8;

v8:
    v51 = stack[0];
    v6 = (Lisp_Object)1; /* 0 */
    if (v51 == v6) goto v11;
    v51 = (Lisp_Object)1; /* 0 */
    v6 = stack[-1];
    v6 = cons(v51, v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    stack[-1] = v6;
    v6 = stack[0];
    v6 = sub1(v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    stack[0] = v6;
    goto v8;

v11:
    v6 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v6);
    }
/* error exit handlers */
v93:
    popv(3);
    return nil;
}



/* Code for dividef */

static Lisp_Object CC_dividef(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v187, v39, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dividef");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v153 = v1;
    v187 = v0;
/* end of prologue */
    v153 = Ldivide(nil, v187, v153);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[0];
    v38 = v153;
    v153 = v38;
    v187 = qcar(v153);
    v153 = (Lisp_Object)1; /* 0 */
    if (v187 == v153) goto v61;
    v153 = v38;
    v153 = qcar(v153);
    v39 = v153;
    goto v40;

v40:
    v153 = v38;
    v187 = qcdr(v153);
    v153 = (Lisp_Object)1; /* 0 */
    if (v187 == v153) goto v52;
    v153 = v38;
    v153 = qcdr(v153);
    goto v16;

v16:
    popv(1);
    return cons(v39, v153);

v52:
    v153 = qvalue(elt(env, 1)); /* nil */
    goto v16;

v61:
    v153 = qvalue(elt(env, 1)); /* nil */
    v39 = v153;
    goto v40;
/* error exit handlers */
v56:
    popv(1);
    return nil;
}



/* Code for terpri!* */

static Lisp_Object CC_terpriH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v211, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for terpri*");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v210 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v210 == nil) goto v12;
    v211 = qvalue(elt(env, 1)); /* outputhandler!* */
    v212 = elt(env, 2); /* terpri */
    v210 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v211, v212, v210);

v12:
    v210 = qvalue(elt(env, 3)); /* testing!-width!* */
    if (v210 == nil) goto v35;
    v210 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 5)) = v210; /* overflowed!* */
    { popv(3); return onevalue(v210); }

v35:
    v210 = qvalue(elt(env, 6)); /* !*fort */
    if (v210 == nil) goto v2;
    v211 = qvalue(elt(env, 7)); /* posn!* */
    v210 = (Lisp_Object)1; /* 0 */
    if (v211 == v210) goto v22;
    v210 = stack[0];
    goto v25;

v25:
    if (v210 == nil) goto v5;
    v210 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-2];
    goto v5;

v5:
    v210 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v210; /* posn!* */
    { popv(3); return onevalue(v210); }

v22:
    v210 = qvalue(elt(env, 8)); /* nil */
    goto v25;

v2:
    v210 = qvalue(elt(env, 9)); /* !*nat */
    if (v210 == nil) goto v60;
    v210 = qvalue(elt(env, 10)); /* pline!* */
    if (v210 == nil) goto v60;
    v210 = qvalue(elt(env, 10)); /* pline!* */
    v210 = Lreverse(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-2];
    qvalue(elt(env, 10)) = v210; /* pline!* */
    v210 = qvalue(elt(env, 11)); /* ymax!* */
    stack[-1] = v210;
    goto v27;

v27:
    v211 = stack[-1];
    v210 = qvalue(elt(env, 12)); /* ymin!* */
    v210 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-2];
    v210 = Lminusp(nil, v210);
    env = stack[-2];
    if (v210 == nil) goto v189;
    v210 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 10)) = v210; /* pline!* */
    goto v60;

v60:
    v210 = stack[0];
    if (v210 == nil) goto v166;
    v210 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-2];
    goto v166;

v166:
    v210 = qvalue(elt(env, 13)); /* orig!* */
    qvalue(elt(env, 7)) = v210; /* posn!* */
    v210 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v210; /* ymin!* */
    qvalue(elt(env, 11)) = v210; /* ymax!* */
    qvalue(elt(env, 14)) = v210; /* ycoord!* */
    v210 = nil;
    { popv(3); return onevalue(v210); }

v189:
    v211 = qvalue(elt(env, 10)); /* pline!* */
    v210 = stack[-1];
    fn = elt(env, 15); /* scprint */
    v210 = (*qfn2(fn))(qenv(fn), v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-2];
    v210 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-2];
    v210 = stack[-1];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-2];
    stack[-1] = v210;
    goto v27;
/* error exit handlers */
v213:
    popv(3);
    return nil;
}



/* Code for noncomperm */

static Lisp_Object CC_noncomperm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v207, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomperm");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0;
/* end of prologue */
    v206 = stack[-4];
    if (v206 == nil) goto v18;
    v206 = stack[-4];
    stack[-5] = v206;
    goto v16;

v16:
    v206 = stack[-5];
    if (v206 == nil) goto v47;
    v206 = stack[-5];
    v206 = qcar(v206);
    stack[0] = v206;
    v207 = stack[0];
    v206 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v206 = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    v208 = v206;
    v207 = v208;
    v206 = elt(env, 2); /* failed */
    if (v207 == v206) goto v40;
    v206 = v208;
    v207 = CC_noncomperm(env, v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    v206 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v206 = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    goto v53;

v53:
    stack[-3] = v206;
    v206 = stack[-3];
    fn = elt(env, 5); /* lastpair */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    stack[-2] = v206;
    v206 = stack[-5];
    v206 = qcdr(v206);
    stack[-5] = v206;
    v206 = stack[-2];
    if (!consp(v206)) goto v16;
    else goto v55;

v55:
    v206 = stack[-5];
    if (v206 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v206 = stack[-5];
    v206 = qcar(v206);
    stack[0] = v206;
    v207 = stack[0];
    v206 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v206 = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    v208 = v206;
    v207 = v208;
    v206 = elt(env, 2); /* failed */
    if (v207 == v206) goto v150;
    v206 = v208;
    v207 = CC_noncomperm(env, v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    v206 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v206 = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    goto v46;

v46:
    v206 = Lrplacd(nil, stack[-1], v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    v206 = stack[-2];
    fn = elt(env, 5); /* lastpair */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-6];
    stack[-2] = v206;
    v206 = stack[-5];
    v206 = qcdr(v206);
    stack[-5] = v206;
    goto v55;

v150:
    v206 = qvalue(elt(env, 1)); /* nil */
    goto v46;

v40:
    v206 = qvalue(elt(env, 1)); /* nil */
    goto v53;

v47:
    v206 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v206); }

v18:
    v206 = stack[-4];
    popv(7);
    return ncons(v206);
/* error exit handlers */
v217:
    popv(7);
    return nil;
}



/* Code for gcref_mkedges!-tgf */

static Lisp_Object CC_gcref_mkedgesKtgf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_mkedges-tgf");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v2 = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = v2;
    goto v9;

v9:
    v2 = stack[-2];
    if (v2 == nil) goto v8;
    v2 = stack[-2];
    v2 = qcar(v2);
    stack[0] = v2;
    v2 = stack[-1];
    v2 = Lprinc(nil, v2);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v2 = elt(env, 2); /* " " */
    v2 = Lprinc(nil, v2);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v2 = stack[0];
    v2 = Lprinc(nil, v2);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v2 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v2 = stack[-2];
    v2 = qcdr(v2);
    stack[-2] = v2;
    goto v9;

v8:
    v2 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v2); }
/* error exit handlers */
v6:
    popv(4);
    return nil;
}



/* Code for rl_csimpl */

static Lisp_Object CC_rl_csimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v3, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_csimpl");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v163 = qvalue(elt(env, 1)); /* !*rlsimpl */
    if (v163 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v163 = elt(env, 2); /* rl_simpl */
    fn = elt(env, 4); /* getd */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-1];
    if (v163 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v2 = stack[0];
    v3 = qvalue(elt(env, 3)); /* nil */
    v163 = (Lisp_Object)-15; /* -1 */
    {
        popv(2);
        fn = elt(env, 2); /* rl_simpl */
        return (*qfnn(fn))(qenv(fn), 3, v2, v3, v163);
    }
/* error exit handlers */
v4:
    popv(2);
    return nil;
}



/* Code for ibalp_getvar!-zmom */

static Lisp_Object CC_ibalp_getvarKzmom(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getvar-zmom");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v80 = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = nil;
    fn = elt(env, 2); /* ibalp_minclnr */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-6];
    stack[-5] = v80;
    v80 = (Lisp_Object)-15; /* -1 */
    stack[-3] = v80;
    v80 = stack[0];
    stack[-1] = v80;
    goto v16;

v16:
    v80 = stack[-1];
    if (v80 == nil) goto v86;
    v80 = stack[-1];
    v80 = qcar(v80);
    stack[0] = v80;
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcar(v80);
    if (v80 == nil) goto v41;
    v80 = qvalue(elt(env, 1)); /* nil */
    goto v51;

v51:
    if (v80 == nil) goto v31;
    v80 = stack[0];
    v146 = qcdr(v80);
    v80 = stack[-5];
    fn = elt(env, 3); /* ibalp_isinminclause */
    v80 = (*qfn2(fn))(qenv(fn), v146, v80);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-6];
    if (v80 == nil) goto v31;
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[-4] = v80;
    v80 = stack[-2];
    stack[-3] = v80;
    goto v31;

v31:
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v16;

v41:
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v146 = qcar(v80);
    stack[-2] = v146;
    v80 = stack[-3];
    v80 = (Lisp_Object)greaterp2(v146, v80);
    nil = C_nil;
    if (exception_pending()) goto v219;
    v80 = v80 ? lisp_true : nil;
    env = stack[-6];
    goto v51;

v86:
    v80 = stack[-4];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v146 = qcar(v80);
    v80 = stack[-4];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcar(v80);
    v80 = (Lisp_Object)greaterp2(v146, v80);
    nil = C_nil;
    if (exception_pending()) goto v219;
    v80 = v80 ? lisp_true : nil;
    if (v80 == nil) goto v209;
    v80 = (Lisp_Object)17; /* 1 */
    goto v179;

v179:
    v146 = stack[-4];
    popv(7);
    return cons(v146, v80);

v209:
    v80 = (Lisp_Object)1; /* 0 */
    goto v179;
/* error exit handlers */
v219:
    popv(7);
    return nil;
}



/* Code for ratpoly_ratp */

static Lisp_Object CC_ratpoly_ratp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ratp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v0;
/* end of prologue */
    v29 = v13;
    v29 = qcar(v29);
    v29 = (is_number(v29) ? lisp_true : nil);
    if (!(v29 == nil)) return onevalue(v29);
    v13 = qcar(v13);
    v13 = (v13 == nil ? lisp_true : nil);
    return onevalue(v13);
}



/* Code for matrixrowrd */

static Lisp_Object MS_CDECL CC_matrixrowrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrowrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 2); /* mathml */
    v50 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    v35 = v50;
    v50 = v35;
    if (v50 == nil) goto v11;
    stack[0] = v35;
    v50 = CC_matrixrowrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v163;
    {
        Lisp_Object v3 = stack[0];
        popv(2);
        return cons(v3, v50);
    }

v11:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }
/* error exit handlers */
v163:
    popv(2);
    return nil;
}



/* Code for floatprop */

static Lisp_Object CC_floatprop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for floatprop");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v87 = v0;
/* end of prologue */
    v16 = v87;
    v16 = Lfloatp(nil, v16);
    env = stack[0];
    if (!(v16 == nil)) { popv(1); return onevalue(v16); }
    v16 = elt(env, 1); /* !:rd!: */
        popv(1);
        return Leqcar(nil, v87, v16);
}



/* Code for noncommuting */

static Lisp_Object CC_noncommuting(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v189, v46, v181;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncommuting");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v189 = v1;
    v46 = v0;
/* end of prologue */
    v181 = nil;
    v45 = v46;
    if (!consp(v45)) goto v12;
    v45 = v46;
    v45 = qcar(v45);
    goto v11;

v11:
    v46 = v45;
    v45 = v189;
    if (!consp(v45)) goto v42;
    v45 = v189;
    v45 = qcar(v45);
    goto v43;

v43:
    v189 = v45;
    v45 = v46;
    if (!consp(v45)) goto v25;
    v45 = v46;
    v45 = qcar(v45);
    if (!symbolp(v45)) v45 = nil;
    else { v45 = qfastgets(v45);
           if (v45 != nil) { v45 = elt(v45, 0); /* noncom */
#ifdef RECORD_GET
             if (v45 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v45 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v45 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v45 == SPID_NOPROP) v45 = nil; else v45 = lisp_true; }}
#endif
    goto v24;

v24:
    if (v45 == nil) return onevalue(v181);
    v45 = v189;
    if (!consp(v45)) goto v48;
    v45 = v189;
    v45 = qcar(v45);
    if (!symbolp(v45)) v45 = nil;
    else { v45 = qfastgets(v45);
           if (v45 != nil) { v45 = elt(v45, 0); /* noncom */
#ifdef RECORD_GET
             if (v45 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v45 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v45 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v45 == SPID_NOPROP) v45 = nil; else v45 = lisp_true; }}
#endif
    goto v49;

v49:
    if (v45 == nil) return onevalue(v181);
    v45 = elt(env, 2); /* noncommutes */
    v45 = get(v46, v45);
    v45 = Lmember(nil, v189, v45);
    v181 = v45;
    return onevalue(v181);

v48:
    v45 = v189;
    if (!symbolp(v45)) v45 = nil;
    else { v45 = qfastgets(v45);
           if (v45 != nil) { v45 = elt(v45, 0); /* noncom */
#ifdef RECORD_GET
             if (v45 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v45 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v45 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v45 == SPID_NOPROP) v45 = nil; else v45 = lisp_true; }}
#endif
    goto v49;

v25:
    v45 = v46;
    if (!symbolp(v45)) v45 = nil;
    else { v45 = qfastgets(v45);
           if (v45 != nil) { v45 = elt(v45, 0); /* noncom */
#ifdef RECORD_GET
             if (v45 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v45 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v45 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v45 == SPID_NOPROP) v45 = nil; else v45 = lisp_true; }}
#endif
    goto v24;

v42:
    v45 = v189;
    goto v43;

v12:
    v45 = v46;
    goto v11;
}



/* Code for one!-entry!-listp */

static Lisp_Object CC_oneKentryKlistp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for one-entry-listp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v162:
    v30 = stack[-1];
    if (v30 == nil) goto v7;
    v30 = stack[-1];
    v52 = qcar(v30);
    v30 = stack[0];
    fn = elt(env, 3); /* one!-entryp */
    v30 = (*qfn2(fn))(qenv(fn), v52, v30);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    if (v30 == nil) goto v14;
    v30 = stack[-1];
    v52 = qcdr(v30);
    v30 = stack[0];
    stack[-1] = v52;
    stack[0] = v30;
    goto v162;

v14:
    v30 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v30); }

v7:
    v30 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v30); }
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for dp!=mocompare */

static Lisp_Object CC_dpMmocompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=mocompare");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v61 = v1;
    v47 = v0;
/* end of prologue */
    v47 = qcar(v47);
    v61 = qcar(v61);
    fn = elt(env, 1); /* mo_compare */
    v47 = (*qfn2(fn))(qenv(fn), v47, v61);
    errexit();
    v61 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v47, v61);
}



/* Code for pv_intequiv */

static Lisp_Object CC_pv_intequiv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_intequiv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v14 = v15;
    v14 = qcdr(v14);
    if (!consp(v14)) goto v18;
    v14 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v14);

v18:
    v14 = v15;
    v14 = qcdr(v14);
    return onevalue(v14);
}



/* Code for st_sorttree */

static Lisp_Object MS_CDECL CC_st_sorttree(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v55, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v17;
    v55 = v1;
    v43 = v0;
/* end of prologue */
    fn = elt(env, 1); /* st_sorttree1 */
    v16 = (*qfnn(fn))(qenv(fn), 3, v43, v55, v16);
    errexit();
    v16 = qcdr(v16);
    return onevalue(v16);
}



/* Code for degree!-in!-variable */

static Lisp_Object CC_degreeKinKvariable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degree-in-variable");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v152 = stack[-1];
    if (!consp(v152)) goto v12;
    v152 = stack[-1];
    v152 = qcar(v152);
    v152 = (consp(v152) ? nil : lisp_true);
    goto v11;

v11:
    if (v152 == nil) goto v47;
    v152 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v152); }

v47:
    v152 = stack[-1];
    v152 = qcar(v152);
    v44 = qcdr(v152);
    v152 = (Lisp_Object)1; /* 0 */
    if (v44 == v152) goto v42;
    v44 = stack[0];
    v152 = stack[-1];
    v152 = qcar(v152);
    v152 = qcar(v152);
    v152 = qcar(v152);
    if (equal(v44, v152)) goto v51;
    v152 = stack[-1];
    v152 = qcar(v152);
    v44 = qcdr(v152);
    v152 = stack[0];
    stack[-2] = CC_degreeKinKvariable(env, v44, v152);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    v152 = stack[-1];
    v44 = qcdr(v152);
    v152 = stack[0];
    v152 = CC_degreeKinKvariable(env, v44, v152);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    {
        Lisp_Object v190 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* max */
        return (*qfn2(fn))(qenv(fn), v190, v152);
    }

v51:
    v152 = stack[-1];
    v152 = qcar(v152);
    v152 = qcar(v152);
    v152 = qcdr(v152);
    { popv(4); return onevalue(v152); }

v42:
    v152 = elt(env, 2); /* "Polynomial with a zero coefficient found" */
    {
        popv(4);
        fn = elt(env, 4); /* errorf */
        return (*qfn1(fn))(qenv(fn), v152);
    }

v12:
    v152 = qvalue(elt(env, 1)); /* t */
    goto v11;
/* error exit handlers */
v181:
    popv(4);
    return nil;
}



/* Code for hasarg */

static Lisp_Object CC_hasarg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v180, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hasarg");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v180 = stack[-1];
    v34 = qvalue(elt(env, 1)); /* haveargs!* */
    v34 = cons(v180, v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    qvalue(elt(env, 1)) = v34; /* haveargs!* */
    v180 = stack[0];
    v34 = qvalue(elt(env, 2)); /* maxarg!* */
    v34 = (Lisp_Object)greaterp2(v180, v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v34 = v34 ? lisp_true : nil;
    env = stack[-2];
    if (v34 == nil) goto v186;
    v34 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 8); /* qerline */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v34 = elt(env, 3); /* "**** " */
    v34 = Lprinc(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v34 = stack[-1];
    v34 = Lprin(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v34 = elt(env, 4); /* " has " */
    v34 = Lprinc(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v34 = stack[0];
    v34 = Lprinc(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v34 = elt(env, 5); /* " arguments" */
    v34 = Lprinc(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v34 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 9); /* newline */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    goto v186;

v186:
    v180 = stack[-1];
    v34 = elt(env, 6); /* bldmsg */
    if (v180 == v34) goto v41;
    v180 = stack[-1];
    v149 = elt(env, 7); /* number!-of!-args */
    v34 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v180, v149, v34);

v41:
    v34 = nil;
    { popv(3); return onevalue(v34); }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for lto_almerge */

static Lisp_Object CC_lto_almerge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v207, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_almerge");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    v206 = v0;
/* end of prologue */

v162:
    v207 = v206;
    if (v207 == nil) goto v12;
    v207 = v206;
    v207 = qcdr(v207);
    if (v207 == nil) goto v87;
    v207 = v206;
    v207 = qcdr(v207);
    v207 = qcdr(v207);
    if (v207 == nil) goto v35;
    v207 = v206;
    stack[0] = qcar(v207);
    v207 = qcdr(v206);
    v206 = stack[-3];
    v206 = CC_lto_almerge(env, v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    v206 = list2(stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    v207 = stack[-3];
    stack[-3] = v207;
    goto v162;

v35:
    v207 = v206;
    v207 = qcdr(v207);
    v207 = qcar(v207);
    stack[-4] = v207;
    v206 = qcar(v206);
    stack[-2] = v206;
    goto v25;

v25:
    v206 = stack[-2];
    if (v206 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v206 = stack[-2];
    v206 = qcar(v206);
    v207 = v206;
    v206 = v207;
    v208 = qcar(v206);
    v206 = stack[-4];
    v206 = Lassoc(nil, v208, v206);
    v208 = v206;
    v206 = v208;
    if (v206 == nil) goto v220;
    stack[-1] = v208;
    stack[0] = stack[-3];
    v206 = v207;
    v206 = qcdr(v206);
    v207 = v208;
    v207 = qcdr(v207);
    v206 = list2(v206, v207);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    fn = elt(env, 2); /* apply */
    v206 = (*qfn2(fn))(qenv(fn), stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v206 = (*qfn2(fn))(qenv(fn), stack[-1], v206);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    goto v56;

v56:
    v206 = stack[-2];
    v206 = qcdr(v206);
    stack[-2] = v206;
    goto v25;

v220:
    v206 = stack[-4];
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    stack[-4] = v206;
    goto v56;

v87:
    v206 = qcar(v206);
    { popv(6); return onevalue(v206); }

v12:
    v206 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v206); }
/* error exit handlers */
v197:
    popv(6);
    return nil;
}



/* Code for updtemplate */

static Lisp_Object MS_CDECL CC_updtemplate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v146, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "updtemplate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for updtemplate");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v17;
    v80 = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = v80;
    v80 = stack[-4];
    if (v80 == nil) goto v55;
    v80 = stack[-4];
    v80 = qcar(v80);
    stack[0] = v80;
    v146 = stack[-6];
    v80 = stack[0];
    v146 = Lsubla(nil, v146, v80);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-8];
    stack[-7] = v146;
    v80 = stack[0];
    if (equal(v146, v80)) goto v2;
    v146 = stack[-7];
    v80 = stack[-5];
    fn = elt(env, 2); /* reval!-without */
    v146 = (*qfn2(fn))(qenv(fn), v146, v80);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-8];
    v222 = v146;
    v80 = stack[-7];
    if (equal(v146, v80)) goto v149;
    v80 = v222;
    goto v3;

v3:
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-8];
    stack[-2] = v80;
    stack[-3] = v80;
    goto v14;

v14:
    v80 = stack[-4];
    v80 = qcdr(v80);
    stack[-4] = v80;
    v80 = stack[-4];
    if (v80 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v80 = stack[-4];
    v80 = qcar(v80);
    stack[0] = v80;
    v146 = stack[-6];
    v80 = stack[0];
    v146 = Lsubla(nil, v146, v80);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-8];
    stack[-7] = v146;
    v80 = stack[0];
    if (equal(v146, v80)) goto v85;
    v146 = stack[-7];
    v80 = stack[-5];
    fn = elt(env, 2); /* reval!-without */
    v146 = (*qfn2(fn))(qenv(fn), v146, v80);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-8];
    v222 = v146;
    v80 = stack[-7];
    if (equal(v146, v80)) goto v79;
    v80 = v222;
    goto v151;

v151:
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-8];
    v80 = Lrplacd(nil, stack[-1], v80);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-8];
    v80 = stack[-2];
    v80 = qcdr(v80);
    stack[-2] = v80;
    goto v14;

v79:
    v80 = stack[-7];
    goto v151;

v85:
    v80 = stack[0];
    goto v151;

v149:
    v80 = stack[-7];
    goto v3;

v2:
    v80 = stack[0];
    goto v3;

v55:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v80); }
/* error exit handlers */
v145:
    popv(9);
    return nil;
}



/* Code for qqe_ofsf_chsimpterm */

static Lisp_Object CC_qqe_ofsf_chsimpterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_chsimpterm");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v83 = v0;
/* end of prologue */
    v200 = v83;
    if (!consp(v200)) { popv(3); return onevalue(v83); }
    v200 = v83;
    v200 = qcdr(v200);
    stack[-1] = v200;
    goto v55;

v55:
    v200 = stack[-1];
    if (v200 == nil) goto v9;
    v200 = stack[-1];
    v200 = qcar(v200);
    v200 = Lconsp(nil, v200);
    env = stack[-2];
    if (v200 == nil) goto v2;
    v200 = stack[-1];
    v200 = qcar(v200);
    fn = elt(env, 4); /* qqe_op */
    v83 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    v200 = elt(env, 2); /* expt */
    if (v83 == v200) goto v93;
    v200 = qvalue(elt(env, 1)); /* nil */
    goto v25;

v25:
    if (v200 == nil) goto v2;
    stack[0] = stack[-1];
    v200 = stack[-1];
    v200 = qcar(v200);
    fn = elt(env, 5); /* qqe_chsimpterm */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    fn = elt(env, 6); /* setcar */
    v200 = (*qfn2(fn))(qenv(fn), stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    goto v163;

v163:
    v200 = stack[-1];
    v200 = qcdr(v200);
    stack[-1] = v200;
    goto v55;

v2:
    v200 = stack[-1];
    v200 = qcar(v200);
    v200 = Lconsp(nil, v200);
    env = stack[-2];
    if (v200 == nil) goto v163;
    v200 = stack[-1];
    v200 = qcar(v200);
    v200 = CC_qqe_ofsf_chsimpterm(env, v200);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    goto v163;

v93:
    v200 = stack[-1];
    v200 = qcar(v200);
    fn = elt(env, 7); /* qqe_arg2l */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    v200 = Lconsp(nil, v200);
    env = stack[-2];
    if (v200 == nil) goto v33;
    v200 = stack[-1];
    v200 = qcar(v200);
    fn = elt(env, 7); /* qqe_arg2l */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    fn = elt(env, 4); /* qqe_op */
    v83 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    v200 = elt(env, 3); /* (ltail rtail) */
    v200 = Lmemq(nil, v83, v200);
    goto v25;

v33:
    v200 = qvalue(elt(env, 1)); /* nil */
    goto v25;

v9:
    v200 = nil;
    { popv(3); return onevalue(v200); }
/* error exit handlers */
v210:
    popv(3);
    return nil;
}



/* Code for pasf_smwmkatl */

static Lisp_Object MS_CDECL CC_pasf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v186, v54, v23, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v186 = v10;
    v54 = v17;
    v23 = v1;
    v21 = v0;
/* end of prologue */
    v41 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v41 == nil) goto v2;
    v41 = v21;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v41, v23, v54, v186);
    }

v2:
    v41 = v21;
    {
        fn = elt(env, 3); /* cl_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v41, v23, v54, v186);
    }
}



/* Code for rl_simpbop */

static Lisp_Object CC_rl_simpbop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpbop");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v39 = v0;
/* end of prologue */
    v187 = v39;
    stack[-4] = qcar(v187);
    v187 = v39;
    v187 = qcdr(v187);
    stack[-3] = v187;
    v187 = stack[-3];
    if (v187 == nil) goto v61;
    v187 = stack[-3];
    v187 = qcar(v187);
    fn = elt(env, 2); /* rl_simp1 */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v187 = ncons(v187);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    stack[-1] = v187;
    stack[-2] = v187;
    goto v87;

v87:
    v187 = stack[-3];
    v187 = qcdr(v187);
    stack[-3] = v187;
    v187 = stack[-3];
    if (v187 == nil) goto v25;
    stack[0] = stack[-1];
    v187 = stack[-3];
    v187 = qcar(v187);
    fn = elt(env, 2); /* rl_simp1 */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v187 = ncons(v187);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v187 = Lrplacd(nil, stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v187 = stack[-1];
    v187 = qcdr(v187);
    stack[-1] = v187;
    goto v87;

v25:
    v187 = stack[-2];
    goto v9;

v9:
    {
        Lisp_Object v149 = stack[-4];
        popv(6);
        return cons(v149, v187);
    }

v61:
    v187 = qvalue(elt(env, 1)); /* nil */
    goto v9;
/* error exit handlers */
v180:
    popv(6);
    return nil;
}



/* Code for cird */

static Lisp_Object MS_CDECL CC_cird(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cird");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cird");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    v57 = qvalue(elt(env, 2)); /* atts */
    v56 = elt(env, 3); /* (type) */
    fn = elt(env, 6); /* retattributes */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    stack[0] = v56;
    fn = elt(env, 7); /* lex */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v56 = qvalue(elt(env, 4)); /* char */
    stack[-1] = v56;
    fn = elt(env, 7); /* lex */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v56 = stack[-1];
    v56 = Lcompress(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v57 = v56;
    v56 = v57;
    if (!(is_number(v56))) goto v163;
    v56 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 8); /* errorml */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    goto v163;

v163:
    v56 = stack[-1];
    fn = elt(env, 9); /* compress!* */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v57 = v56;
    v56 = stack[0];
    if (v56 == nil) { popv(3); return onevalue(v57); }
    v88 = elt(env, 5); /* ci */
    v56 = stack[0];
    popv(3);
    return list3(v88, v56, v57);
/* error exit handlers */
v149:
    popv(3);
    return nil;
}



/* Code for guesspftype */

static Lisp_Object CC_guesspftype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v154, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for guesspftype");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v185 = stack[0];
    if (!consp(v185)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v185 = stack[0];
    v154 = qcar(v185);
    v185 = elt(env, 1); /* (wedge d partdf hodge innerprod liedf) */
    v185 = Lmemq(nil, v154, v185);
    if (!(v185 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v185 = stack[0];
    v185 = qcdr(v185);
    v153 = Llength(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v185 = stack[0];
    v154 = qcar(v185);
    v185 = elt(env, 2); /* ifdegree */
    v185 = get(v154, v185);
    env = stack[-1];
    v185 = Lassoc(nil, v153, v185);
    if (v185 == nil) goto v49;
    v185 = stack[0];
    v185 = qcdr(v185);
    fn = elt(env, 3); /* xvarlistp */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    if (v185 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v49;

v49:
    v185 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mknwedge */
        return (*qfn1(fn))(qenv(fn), v185);
    }
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for equalreplaceby */

static Lisp_Object CC_equalreplaceby(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equalreplaceby");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v13 = elt(env, 1); /* replaceby */
    return cons(v13, v8);
}



/* Code for inttovec */

static Lisp_Object CC_inttovec(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v42 = v1;
    v43 = v0;
/* end of prologue */
    stack[0] = v42;
    fn = elt(env, 1); /* inttovec!-solve */
    v43 = (*qfn2(fn))(qenv(fn), v42, v43);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    {
        Lisp_Object v50 = stack[0];
        popv(2);
        fn = elt(env, 2); /* inttovec1 */
        return (*qfn2(fn))(qenv(fn), v50, v43);
    }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for assert_uninstall_all */

static Lisp_Object MS_CDECL CC_assert_uninstall_all(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall_all");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v11 = qvalue(elt(env, 1)); /* !*assert */
    if (v11 == nil) goto v18;
    v11 = qvalue(elt(env, 2)); /* assert_functionl!* */
    {
        fn = elt(env, 3); /* assert_uninstall */
        return (*qfn1(fn))(qenv(fn), v11);
    }

v18:
    v11 = nil;
    return onevalue(v11);
}



/* Code for eqdummy */

static Lisp_Object CC_eqdummy(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v30, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eqdummy");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v93 = v1;
    v52 = v0;
/* end of prologue */
    v30 = v52;
    if (v30 == nil) goto v7;
    v30 = elt(env, 2); /* dummy */
    v30 = get(v52, v30);
    env = stack[0];
    v52 = qcar(v30);
    v30 = v93;
    v93 = elt(env, 2); /* dummy */
    v93 = get(v30, v93);
    v93 = qcar(v93);
    v93 = (v52 == v93 ? lisp_true : nil);
    { popv(1); return onevalue(v93); }

v7:
    v93 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v93); }
}



/* Code for numlist_ordp */

static Lisp_Object CC_numlist_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v87, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlist_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v1;
    v87 = v0;
/* end of prologue */
    v16 = v87;
    v87 = v15;
    v15 = elt(env, 1); /* lambda_lqlbvc_2 */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v16, v87, v15);
    }
}



/* Code for lambda_lqlbvc_2 */

static Lisp_Object CC_lambda_lqlbvc_2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqlbvc_2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v1;
    v29 = v0;
/* end of prologue */
        return Lleq(nil, v29, v13);
}



/* Code for extmult */

static Lisp_Object CC_extmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v191 = stack[-3];
    if (v191 == nil) goto v12;
    v191 = stack[-2];
    v191 = (v191 == nil ? lisp_true : nil);
    goto v11;

v11:
    if (v191 == nil) goto v47;
    v191 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v191); }

v47:
    v191 = stack[-3];
    v191 = qcar(v191);
    v191 = qcar(v191);
    v142 = qcar(v191);
    v191 = stack[-2];
    v191 = qcar(v191);
    v191 = qcar(v191);
    fn = elt(env, 3); /* ordexn */
    v191 = (*qfn2(fn))(qenv(fn), v142, v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    v142 = v191;
    v191 = v142;
    if (v191 == nil) goto v179;
    v191 = v142;
    stack[-4] = qcdr(v191);
    v191 = v142;
    v191 = qcar(v191);
    if (v191 == nil) goto v188;
    v191 = stack[-3];
    v191 = qcar(v191);
    v142 = qcdr(v191);
    v191 = stack[-2];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    fn = elt(env, 4); /* c!:subs2multf */
    v191 = (*qfn2(fn))(qenv(fn), v142, v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    fn = elt(env, 5); /* negf */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    stack[-1] = v191;
    goto v220;

v220:
    v191 = stack[-3];
    v191 = qcar(v191);
    v142 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    v191 = stack[-2];
    v191 = qcdr(v191);
    stack[0] = CC_extmult(env, v142, v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    v191 = stack[-3];
    v142 = qcdr(v191);
    v191 = stack[-2];
    v191 = CC_extmult(env, v142, v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    fn = elt(env, 6); /* extadd */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    {
        Lisp_Object v226 = stack[-4];
        Lisp_Object v227 = stack[-1];
        popv(6);
        return acons(v226, v227, v191);
    }

v188:
    v191 = stack[-3];
    v191 = qcar(v191);
    v142 = qcdr(v191);
    v191 = stack[-2];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    fn = elt(env, 4); /* c!:subs2multf */
    v191 = (*qfn2(fn))(qenv(fn), v142, v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    stack[-1] = v191;
    goto v220;

v179:
    v191 = stack[-3];
    v142 = qcdr(v191);
    v191 = stack[-2];
    stack[0] = CC_extmult(env, v142, v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    v191 = stack[-3];
    v191 = qcar(v191);
    v142 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    v191 = stack[-2];
    v191 = qcdr(v191);
    v191 = CC_extmult(env, v142, v191);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    {
        Lisp_Object v228 = stack[0];
        popv(6);
        fn = elt(env, 6); /* extadd */
        return (*qfn2(fn))(qenv(fn), v228, v191);
    }

v12:
    v191 = qvalue(elt(env, 1)); /* t */
    goto v11;
/* error exit handlers */
v203:
    popv(6);
    return nil;
}



/* Code for simp!*sq */

static Lisp_Object CC_simpHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v61 = v0;
/* end of prologue */
    v42 = v61;
    v42 = qcdr(v42);
    v42 = qcar(v42);
    if (v42 == nil) goto v15;
    v42 = qvalue(elt(env, 1)); /* !*resimp */
    if (!(v42 == nil)) goto v15;
    v42 = v61;
    v42 = qcar(v42);
    return onevalue(v42);

v15:
    v42 = v61;
    v42 = qcar(v42);
    {
        fn = elt(env, 2); /* resimp1 */
        return (*qfn1(fn))(qenv(fn), v42);
    }
}



/* Code for mkzl */

static Lisp_Object CC_mkzl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkzl");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v8;

v8:
    v51 = stack[0];
    v6 = (Lisp_Object)17; /* 1 */
    if (v51 == v6) goto v11;
    v51 = (Lisp_Object)1; /* 0 */
    v6 = stack[-1];
    v6 = cons(v51, v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    stack[-1] = v6;
    v6 = stack[0];
    v6 = sub1(v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    stack[0] = v6;
    goto v8;

v11:
    v6 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v6);
    }
/* error exit handlers */
v93:
    popv(3);
    return nil;
}



/* Code for ibalp_clausep */

static Lisp_Object CC_ibalp_clausep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clausep");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v24 = stack[0];
    fn = elt(env, 3); /* ibalp_litp */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    if (!(v24 == nil)) { popv(2); return onevalue(v24); }
    v24 = stack[0];
    if (!consp(v24)) goto v43;
    v24 = stack[0];
    v24 = qcar(v24);
    v25 = v24;
    goto v14;

v14:
    v24 = elt(env, 1); /* or */
    if (v25 == v24) goto v12;
    v24 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v24); }

v12:
    v24 = stack[0];
    v24 = qcdr(v24);
    {
        popv(2);
        fn = elt(env, 4); /* ibalp_litlp */
        return (*qfn1(fn))(qenv(fn), v24);
    }

v43:
    v24 = stack[0];
    v25 = v24;
    goto v14;
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for aex_mvaroccurtest */

static Lisp_Object CC_aex_mvaroccurtest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mvaroccurtest");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v29 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v14 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    v29 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_mvartest */
        return (*qfn2(fn))(qenv(fn), v14, v29);
    }
/* error exit handlers */
v87:
    popv(2);
    return nil;
}



/* Code for ofsf_sacatlp */

static Lisp_Object CC_ofsf_sacatlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53, v40, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacatlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v52 = v1;
    v41 = v0;
/* end of prologue */
    v52 = qcar(v52);
    v40 = v52;
    v52 = v41;
    v52 = qcdr(v52);
    v53 = qcar(v52);
    v52 = v40;
    v52 = qcdr(v52);
    v52 = qcar(v52);
    if (equal(v53, v52)) goto v24;
    v52 = v41;
    v52 = qcdr(v52);
    v52 = qcar(v52);
    v53 = v40;
    v53 = qcdr(v53);
    v53 = qcar(v53);
    fn = elt(env, 2); /* ordp */
    v52 = (*qfn2(fn))(qenv(fn), v52, v53);
    errexit();
    goto v60;

v60:
    v52 = (v52 == nil ? lisp_true : nil);
    return onevalue(v52);

v24:
    v52 = qvalue(elt(env, 1)); /* nil */
    goto v60;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:prep");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v51 = elt(env, 1); /* !:rd!: */
    v6 = stack[0];
    v6 = qcdr(v6);
    v6 = qcar(v6);
    v6 = cons(v51, v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    v51 = elt(env, 1); /* !:rd!: */
    v6 = stack[0];
    v6 = qcdr(v6);
    v6 = qcdr(v6);
    v6 = cons(v51, v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    v6 = cons(stack[-1], v6);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v6);
    }
/* error exit handlers */
v93:
    popv(3);
    return nil;
}



/* Code for initwght */

static Lisp_Object CC_initwght(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v232, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initwght");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0;
/* end of prologue */
    v231 = (Lisp_Object)1; /* 0 */
    stack[-5] = v231;
    stack[0] = v231;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v232 = qvalue(elt(env, 2)); /* maxvar */
    v231 = stack[-3];
    v231 = plus2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v232 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v231/(16/CELL)));
    v231 = (Lisp_Object)65; /* 4 */
    v231 = *(Lisp_Object *)((char *)v232 + (CELL-TAG_VECTOR) + ((int32_t)v231/(16/CELL)));
    stack[-4] = v231;
    goto v8;

v8:
    v231 = stack[-4];
    if (v231 == nil) goto v215;
    v231 = stack[-4];
    v231 = qcar(v231);
    stack[-2] = v231;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v232 = qvalue(elt(env, 2)); /* maxvar */
    v231 = stack[-2];
    v231 = qcar(v231);
    v231 = plus2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v232 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v231/(16/CELL)));
    v231 = (Lisp_Object)1; /* 0 */
    v231 = *(Lisp_Object *)((char *)v232 + (CELL-TAG_VECTOR) + ((int32_t)v231/(16/CELL)));
    if (v231 == nil) goto v23;
    v231 = stack[-2];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    fn = elt(env, 5); /* dm!-abs */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v73 = v231;
    v231 = v73;
    if (!consp(v231)) goto v181;
    v231 = v73;
    v232 = qcar(v231);
    v231 = elt(env, 4); /* onep */
    v231 = get(v232, v231);
    env = stack[-6];
    v232 = v73;
    v231 = Lapply1(nil, v231, v232);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    goto v46;

v46:
    if (!(v231 == nil)) goto v28;
    v231 = stack[-5];
    v231 = add1(v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    stack[-5] = v231;
    goto v28;

v28:
    v231 = stack[0];
    v231 = add1(v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    stack[0] = v231;
    goto v23;

v23:
    v231 = stack[-4];
    v231 = qcdr(v231);
    stack[-4] = v231;
    goto v8;

v181:
    v231 = v73;
    v231 = Lonep(nil, v231);
    env = stack[-6];
    goto v46;

v215:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v232 = qvalue(elt(env, 2)); /* maxvar */
    v231 = stack[-3];
    v231 = plus2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v231/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v232 = (Lisp_Object)49; /* 3 */
    v231 = stack[-5];
    v231 = times2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v231 = plus2(stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v231 = acons(stack[-2], stack[-1], v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v231;
    v231 = nil;
    { popv(7); return onevalue(v231); }
/* error exit handlers */
v233:
    popv(7);
    return nil;
}



/* Code for bcplus!? */

static Lisp_Object CC_bcplusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v50;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcplus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v0;
/* end of prologue */
    v47 = qcar(v47);
    v50 = v47;
    v47 = v50;
    if (is_number(v47)) goto v16;
    v47 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v47);

v16:
    v47 = (Lisp_Object)1; /* 0 */
        return Lgreaterp(nil, v50, v47);
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v163;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevmaptozero1");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v36 = v1;
    stack[0] = v0;
/* end of prologue */

v7:
    v163 = stack[0];
    if (v163 == nil) { popv(2); return onevalue(v36); }
    v163 = stack[0];
    v163 = qcdr(v163);
    stack[0] = v163;
    v163 = (Lisp_Object)1; /* 0 */
    v36 = cons(v163, v36);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    goto v7;
/* error exit handlers */
v2:
    popv(2);
    return nil;
}



/* Code for physopaeval */

static Lisp_Object CC_physopaeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v234, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopaeval");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v219 = stack[0];
    fn = elt(env, 7); /* physopp */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    if (v219 == nil) goto v11;
    v234 = stack[0];
    v219 = elt(env, 1); /* rvalue */
    v219 = get(v234, v219);
    env = stack[-1];
    v77 = v219;
    if (v219 == nil) goto v15;
    v219 = v77;
    v234 = qcar(v219);
    v219 = elt(env, 2); /* !*sq */
    if (!(v234 == v219)) { popv(2); return onevalue(v77); }
    v219 = qvalue(elt(env, 3)); /* !*nosq */
    if (v219 == nil) goto v52;
    v219 = v77;
    v219 = qcdr(v219);
    v219 = qcar(v219);
    {
        popv(2);
        fn = elt(env, 8); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v219);
    }

v52:
    v219 = v77;
    v219 = qcdr(v219);
    v219 = qcar(v219);
    {
        popv(2);
        fn = elt(env, 9); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v219);
    }

v15:
    v219 = stack[0];
    if (!consp(v219)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v219 = stack[0];
    v234 = qcar(v219);
    v219 = elt(env, 4); /* psimpfn */
    v219 = get(v234, v219);
    env = stack[-1];
    v77 = v219;
    if (v219 == nil) goto v181;
    v234 = v77;
    v219 = stack[0];
        popv(2);
        return Lapply1(nil, v234, v219);

v181:
    v219 = stack[0];
    v234 = qcar(v219);
    v219 = elt(env, 5); /* opmtch */
    v219 = get(v234, v219);
    env = stack[-1];
    if (v219 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v219 = stack[0];
    fn = elt(env, 10); /* opmtch!* */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v191;
    v77 = v219;
    if (v219 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v77); }

v11:
    v219 = stack[0];
    if (!consp(v219)) goto v147;
    v219 = stack[0];
    v234 = qcar(v219);
    v219 = elt(env, 2); /* !*sq */
    v219 = (v234 == v219 ? lisp_true : nil);
    goto v211;

v211:
    if (v219 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v219 = qvalue(elt(env, 3)); /* !*nosq */
    if (v219 == nil) goto v215;
    v219 = stack[0];
    v219 = qcdr(v219);
    v219 = qcar(v219);
    {
        popv(2);
        fn = elt(env, 8); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v219);
    }

v215:
    v219 = stack[0];
    v219 = qcdr(v219);
    v219 = qcar(v219);
    {
        popv(2);
        fn = elt(env, 9); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v219);
    }

v147:
    v219 = qvalue(elt(env, 6)); /* nil */
    goto v211;
/* error exit handlers */
v191:
    popv(2);
    return nil;
}



/* Code for zero!-roads */

static Lisp_Object CC_zeroKroads(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero-roads");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v162:
    v25 = stack[0];
    if (v25 == nil) goto v18;
    v25 = stack[0];
    v25 = qcar(v25);
    fn = elt(env, 2); /* z!-roads */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v93 = v25;
    v25 = v93;
    if (v25 == nil) goto v4;
    stack[-1] = v93;
    v25 = stack[0];
    v25 = qcdr(v25);
    v25 = CC_zeroKroads(env, v25);
    nil = C_nil;
    if (exception_pending()) goto v53;
    {
        Lisp_Object v40 = stack[-1];
        popv(3);
        return cons(v40, v25);
    }

v4:
    v25 = stack[0];
    v25 = qcdr(v25);
    stack[0] = v25;
    goto v162;

v18:
    v25 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v25); }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for assert_install */

static Lisp_Object CC_assert_install(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_install");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v163 = qvalue(elt(env, 1)); /* !*assert */
    if (v163 == nil) goto v7;
    v163 = v3;
    stack[0] = v163;
    goto v8;

v8:
    v163 = stack[0];
    if (v163 == nil) goto v15;
    v163 = stack[0];
    v163 = qcar(v163);
    fn = elt(env, 3); /* assert_install1 */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v163 = stack[0];
    v163 = qcdr(v163);
    stack[0] = v163;
    goto v8;

v15:
    v163 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v163); }

v7:
    v163 = nil;
    { popv(2); return onevalue(v163); }
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for mo!=revlexcomp */

static Lisp_Object CC_moMrevlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=revlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v54 = stack[-1];
    stack[-2] = Llength(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v54 = stack[0];
    v54 = Llength(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v54))) goto v7;
    v54 = stack[0];
    stack[-2] = Llength(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v54 = stack[-1];
    v54 = Llength(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v54))) goto v55;
    v54 = stack[-1];
    stack[-1] = Lreverse(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v54 = stack[0];
    v54 = Lreverse(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    fn = elt(env, 1); /* mo!=degcomp */
    v54 = (*qfn2(fn))(qenv(fn), stack[-1], v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    popv(4);
    return negate(v54);

v55:
    v54 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v54); }

v7:
    v54 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v54); }
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_cambhead");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v162:
    v23 = stack[0];
    fn = elt(env, 4); /* listp */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    if (v23 == nil) goto v7;
    v23 = stack[0];
    stack[-1] = qcar(v23);
    v21 = elt(env, 1); /* expt */
    v23 = elt(env, 2); /* minus */
    v23 = list2(v21, v23);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v23 = Lmember(nil, stack[-1], v23);
    if (v23 == nil) goto v13;
    v23 = stack[0];
    v23 = qcdr(v23);
    v23 = qcar(v23);
    stack[0] = v23;
    goto v162;

v13:
    v23 = stack[0];
    fn = elt(env, 4); /* listp */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v48;
    if (v23 == nil) goto v7;
    v23 = stack[0];
    v23 = qcar(v23);
    { popv(3); return onevalue(v23); }

v7:
    v23 = nil;
    { popv(3); return onevalue(v23); }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for expt!-mod!-p */

static Lisp_Object CC_exptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v189, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v46 = v1;
    stack[0] = v0;
/* end of prologue */
    v189 = v46;
    v45 = (Lisp_Object)1; /* 0 */
    if (v189 == v45) goto v7;
    v189 = v46;
    v45 = (Lisp_Object)17; /* 1 */
    if (v189 == v45) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v189 = v46;
    v45 = (Lisp_Object)33; /* 2 */
    v45 = Ldivide(nil, v189, v45);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-2];
    stack[-1] = v45;
    v189 = stack[0];
    v45 = stack[-1];
    v45 = qcar(v45);
    v45 = CC_exptKmodKp(env, v189, v45);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-2];
    v46 = v45;
    v45 = v46;
    v189 = v46;
    fn = elt(env, 1); /* times!-mod!-p */
    v45 = (*qfn2(fn))(qenv(fn), v45, v189);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-2];
    v46 = v45;
    v45 = stack[-1];
    v189 = qcdr(v45);
    v45 = (Lisp_Object)1; /* 0 */
    if (v189 == v45) { popv(3); return onevalue(v46); }
    v189 = v46;
    v45 = stack[0];
    fn = elt(env, 1); /* times!-mod!-p */
    v45 = (*qfn2(fn))(qenv(fn), v189, v45);
    nil = C_nil;
    if (exception_pending()) goto v221;
    v46 = v45;
    { popv(3); return onevalue(v46); }

v7:
    v45 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v45); }
/* error exit handlers */
v221:
    popv(3);
    return nil;
}



/* Code for get_group_in */

static Lisp_Object CC_get_group_in(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_group_in");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v9 = qcar(v9);
    return onevalue(v9);
}



/* Code for qqe_ofsf_simplat1 */

static Lisp_Object CC_qqe_ofsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v186 = stack[-1];
    v41 = stack[0];
    fn = elt(env, 2); /* qqe_simplat1 */
    v41 = (*qfn2(fn))(qenv(fn), v186, v41);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[-2] = v41;
    v186 = stack[-2];
    v41 = elt(env, 1); /* (true false) */
    v41 = Lmemq(nil, v186, v41);
    if (!(v41 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v41 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    fn = elt(env, 4); /* qqe_rqopp */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    if (!(v41 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v186 = stack[-2];
    v41 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ofsf_simplat1 */
        return (*qfn2(fn))(qenv(fn), v186, v41);
    }
/* error exit handlers */
v22:
    popv(4);
    return nil;
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_negateat");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v13 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v13 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    {
        Lisp_Object v15 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v15, v13);
    }
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



setup_type const u12_setup[] =
{
    {"ratpoly_mvartest",        too_few_2,      CC_ratpoly_mvartest,wrong_no_2},
    {"mathml2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml2},
    {"spquotematrix",           CC_spquotematrix,too_many_1,   wrong_no_1},
    {"newenv",                  CC_newenv,      too_many_1,    wrong_no_1},
    {"wedgepf",                 too_few_2,      CC_wedgepf,    wrong_no_2},
    {"prinfit",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_prinfit},
    {":dmpluslst",              CC_Tdmpluslst,  too_many_1,    wrong_no_1},
    {"ptoken",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_ptoken},
    {"mv-domainlist--",         too_few_2,      CC_mvKdomainlistKK,wrong_no_2},
    {"red_better",              too_few_2,      CC_red_better, wrong_no_2},
    {"pneg",                    CC_pneg,        too_many_1,    wrong_no_1},
    {"dl_get",                  CC_dl_get,      too_many_1,    wrong_no_1},
    {"rnminus:",                CC_rnminusT,    too_many_1,    wrong_no_1},
    {"gcref_mkgraph",           CC_gcref_mkgraph,too_many_1,   wrong_no_1},
    {"rl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_simpl},
    {"removeg2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg2},
    {"rl_susipost",             too_few_2,      CC_rl_susipost,wrong_no_2},
    {"cl_varl2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_varl2},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"simpindexvar",            CC_simpindexvar,too_many_1,    wrong_no_1},
    {"mksetq",                  too_few_2,      CC_mksetq,     wrong_no_2},
    {"evalneq",                 too_few_2,      CC_evalneq,    wrong_no_2},
    {"mv-pow--",                too_few_2,      CC_mvKpowKK,   wrong_no_2},
    {"bc_fi",                   CC_bc_fi,       too_many_1,    wrong_no_1},
    {"pv_times3",               too_few_2,      CC_pv_times3,  wrong_no_2},
    {"dv_skel2factor1",         too_few_2,      CC_dv_skel2factor1,wrong_no_2},
    {"copy-vector",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_copyKvector},
    {"difference-mod-p",        too_few_2,      CC_differenceKmodKp,wrong_no_2},
    {"traput",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_traput},
    {"sfto_ucontentf",          CC_sfto_ucontentf,too_many_1,  wrong_no_1},
    {"ofsf_prepat",             CC_ofsf_prepat, too_many_1,    wrong_no_1},
    {"attributesml",            too_few_2,      CC_attributesml,wrong_no_2},
    {"groebnormalform",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebnormalform},
    {"prop-simp",               too_few_2,      CC_propKsimp,  wrong_no_2},
    {"assert_format",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_format},
    {"aminusp:1",               CC_aminuspT1,   too_many_1,    wrong_no_1},
    {"nzeros",                  CC_nzeros,      too_many_1,    wrong_no_1},
    {"dividef",                 too_few_2,      CC_dividef,    wrong_no_2},
    {"terpri*",                 CC_terpriH,     too_many_1,    wrong_no_1},
    {"noncomperm",              CC_noncomperm,  too_many_1,    wrong_no_1},
    {"gcref_mkedges-tgf",       too_few_2,      CC_gcref_mkedgesKtgf,wrong_no_2},
    {"rl_csimpl",               CC_rl_csimpl,   too_many_1,    wrong_no_1},
    {"ibalp_getvar-zmom",       too_few_2,      CC_ibalp_getvarKzmom,wrong_no_2},
    {"ratpoly_ratp",            CC_ratpoly_ratp,too_many_1,    wrong_no_1},
    {"matrixrowrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrowrd},
    {"floatprop",               CC_floatprop,   too_many_1,    wrong_no_1},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"one-entry-listp",         too_few_2,      CC_oneKentryKlistp,wrong_no_2},
    {"dp=mocompare",            too_few_2,      CC_dpMmocompare,wrong_no_2},
    {"pv_intequiv",             CC_pv_intequiv, too_many_1,    wrong_no_1},
    {"st_sorttree",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree},
    {"degree-in-variable",      too_few_2,      CC_degreeKinKvariable,wrong_no_2},
    {"hasarg",                  too_few_2,      CC_hasarg,     wrong_no_2},
    {"lto_almerge",             too_few_2,      CC_lto_almerge,wrong_no_2},
    {"updtemplate",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_updtemplate},
    {"qqe_ofsf_chsimpterm",     CC_qqe_ofsf_chsimpterm,too_many_1,wrong_no_1},
    {"pasf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwmkatl},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"cird",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cird},
    {"guesspftype",             CC_guesspftype, too_many_1,    wrong_no_1},
    {"equalreplaceby",          CC_equalreplaceby,too_many_1,  wrong_no_1},
    {"inttovec",                too_few_2,      CC_inttovec,   wrong_no_2},
    {"assert_uninstall_all",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_uninstall_all},
    {"eqdummy",                 too_few_2,      CC_eqdummy,    wrong_no_2},
    {"numlist_ordp",            too_few_2,      CC_numlist_ordp,wrong_no_2},
    {"lambda_lqlbvc_2",         too_few_2,      CC_lambda_lqlbvc_2,wrong_no_2},
    {"extmult",                 too_few_2,      CC_extmult,    wrong_no_2},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"mkzl",                    CC_mkzl,        too_many_1,    wrong_no_1},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"aex_mvaroccurtest",       too_few_2,      CC_aex_mvaroccurtest,wrong_no_2},
    {"ofsf_sacatlp",            too_few_2,      CC_ofsf_sacatlp,wrong_no_2},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"physopaeval",             CC_physopaeval, too_many_1,    wrong_no_1},
    {"zero-roads",              CC_zeroKroads,  too_many_1,    wrong_no_1},
    {"assert_install",          CC_assert_install,too_many_1,  wrong_no_1},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"expt-mod-p",              too_few_2,      CC_exptKmodKp, wrong_no_2},
    {"get_group_in",            CC_get_group_in,too_many_1,    wrong_no_1},
    {"qqe_ofsf_simplat1",       too_few_2,      CC_qqe_ofsf_simplat1,wrong_no_2},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u12", (two_args *)"11574 4433184 287530", 0}
};

/* end of generated code */
