
/* $destdir\u18.c        Machine generated C code */

/* Signature: 00000000 24-Aug-2011 */

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


/* Code for qqe_arg!-check */

static Lisp_Object CC_qqe_argKcheck(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check");
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
    v7 = stack[0];
    v7 = qcar(v7);
    stack[-1] = v7;
    v7 = stack[-1];
    fn = elt(env, 4); /* qqe_rqopp */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (v7 == nil) goto v10;
    v7 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check!-lq!-rq */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    goto v11;

v11:
    v7 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v7); }

v10:
    v7 = stack[-1];
    fn = elt(env, 6); /* qqe_rbopp */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (v7 == nil) goto v12;
    v7 = stack[0];
    fn = elt(env, 7); /* qqe_arg!-check!-lb!-rb */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    goto v11;

v12:
    v7 = stack[-1];
    fn = elt(env, 8); /* qqe_qopheadp */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (!(v7 == nil)) goto v13;
    v7 = stack[-1];
    fn = elt(env, 9); /* qqe_qoptailp */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (!(v7 == nil)) goto v13;
    v7 = stack[-1];
    fn = elt(env, 10); /* qqe_qopaddp */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (v7 == nil) goto v14;
    v7 = stack[0];
    fn = elt(env, 11); /* qqe_arg!-check!-lb!-rq */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    goto v11;

v14:
    v7 = stack[0];
    v7 = qcdr(v7);
    stack[-1] = v7;
    goto v15;

v15:
    v7 = stack[-1];
    if (v7 == nil) goto v11;
    v7 = stack[-1];
    v7 = qcar(v7);
    fn = elt(env, 12); /* qqe_arg!-check!-b */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (!(v7 == nil)) goto v16;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v7 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v8 = stack[0];
    v7 = elt(env, 3); /* "some arguments are not of basic type" */
    fn = elt(env, 14); /* typerr */
    v7 = (*qfn2(fn))(qenv(fn), v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    goto v16;

v16:
    v7 = stack[-1];
    v7 = qcdr(v7);
    stack[-1] = v7;
    goto v15;

v13:
    v7 = stack[0];
    v7 = qcdr(v7);
    v7 = qcar(v7);
    fn = elt(env, 15); /* qqe_arg!-check!-q */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (!(v7 == nil)) goto v11;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v7 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v8 = stack[0];
    v7 = elt(env, 1); /* "some arguments are not of queue type" */
    fn = elt(env, 14); /* typerr */
    v7 = (*qfn2(fn))(qenv(fn), v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    goto v11;
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for pasf_varlat */

static Lisp_Object CC_pasf_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_varlat");
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
    v3 = stack[0];
    v3 = qcdr(v3);
    v24 = qcar(v3);
    v3 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v24, v3);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-2];
    v3 = stack[0];
    v3 = Lconsp(nil, v3);
    env = stack[-2];
    if (v3 == nil) goto v26;
    v3 = stack[0];
    v3 = qcar(v3);
    v3 = Lconsp(nil, v3);
    env = stack[-2];
    if (v3 == nil) goto v26;
    v3 = stack[0];
    v3 = qcar(v3);
    v24 = qcar(v3);
    v3 = elt(env, 2); /* (cong ncong) */
    v3 = Lmemq(nil, v24, v3);
    if (v3 == nil) goto v26;
    v3 = stack[0];
    v3 = qcar(v3);
    v24 = qcdr(v3);
    v3 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v3 = (*qfn2(fn))(qenv(fn), v24, v3);
    nil = C_nil;
    if (exception_pending()) goto v25;
    goto v11;

v11:
    {
        Lisp_Object v27 = stack[-1];
        popv(3);
        return Lappend(nil, v27, v3);
    }

v26:
    v3 = qvalue(elt(env, 1)); /* nil */
    goto v11;
/* error exit handlers */
v25:
    popv(3);
    return nil;
}



/* Code for cl_qb */

static Lisp_Object CC_cl_qb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38, v16, v39, v40;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_qb");
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
    v40 = nil;
    v37 = (Lisp_Object)1; /* 0 */
    v39 = v37;
    goto v41;

v41:
    v37 = stack[0];
    if (!consp(v37)) goto v23;
    v37 = stack[0];
    v37 = qcar(v37);
    goto v22;

v22:
    stack[-1] = v37;
    v16 = v37;
    v38 = v16;
    v37 = elt(env, 1); /* ex */
    if (v38 == v37) goto v42;
    v38 = v16;
    v37 = elt(env, 3); /* all */
    v37 = (v38 == v37 ? lisp_true : nil);
    goto v43;

v43:
    if (v37 == nil) { popv(3); return onevalue(v39); }
    v38 = stack[-1];
    v37 = v40;
    if (equal(v38, v37)) goto v19;
    v37 = v39;
    v37 = add1(v37);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v39 = v37;
    v37 = stack[-1];
    v40 = v37;
    goto v19;

v19:
    v37 = stack[0];
    v37 = qcdr(v37);
    v37 = qcdr(v37);
    v37 = qcar(v37);
    stack[0] = v37;
    goto v41;

v42:
    v37 = qvalue(elt(env, 2)); /* t */
    goto v43;

v23:
    v37 = stack[0];
    goto v22;
/* error exit handlers */
v44:
    popv(3);
    return nil;
}



/* Code for reln */

static Lisp_Object CC_reln(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reln");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v0;
/* end of prologue */
    v49 = elt(env, 1); /* "<reln>" */
    fn = elt(env, 6); /* printout */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v49 = elt(env, 2); /* "<" */
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v49 = stack[0];
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v49 = elt(env, 3); /* "/>" */
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v50 = qvalue(elt(env, 4)); /* indent */
    v49 = (Lisp_Object)49; /* 3 */
    v49 = plus2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    qvalue(elt(env, 4)) = v49; /* indent */
    v49 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v50 = qvalue(elt(env, 4)); /* indent */
    v49 = (Lisp_Object)49; /* 3 */
    v49 = difference2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    qvalue(elt(env, 4)) = v49; /* indent */
    v49 = elt(env, 5); /* "</reln>" */
    fn = elt(env, 6); /* printout */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v49 = nil;
    { popv(3); return onevalue(v49); }
/* error exit handlers */
v51:
    popv(3);
    return nil;
}



/* Code for ps!:expansion!-point */

static Lisp_Object CC_psTexpansionKpoint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expansion-point");
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
    v19 = v0;
/* end of prologue */
    v18 = v19;
    if (!consp(v18)) goto v10;
    v18 = v19;
    v26 = qcar(v18);
    v18 = elt(env, 2); /* !:ps!: */
    if (v26 == v18) goto v35;
    v18 = v19;
    v26 = qcar(v18);
    v18 = elt(env, 3); /* dname */
    v18 = get(v26, v18);
    env = stack[0];
    goto v55;

v55:
    if (v18 == nil) goto v56;
    v18 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v18); }

v56:
    v18 = (Lisp_Object)49; /* 3 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v19, v18);
    }

v35:
    v18 = qvalue(elt(env, 4)); /* nil */
    goto v55;

v10:
    v18 = qvalue(elt(env, 1)); /* t */
    goto v55;
}



/* Code for dm!-min */

static Lisp_Object CC_dmKmin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-min");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v0;
/* end of prologue */
    v48 = stack[-1];
    v13 = stack[0];
    fn = elt(env, 1); /* dm!-gt */
    v13 = (*qfn2(fn))(qenv(fn), v48, v13);
    nil = C_nil;
    if (exception_pending()) goto v58;
    if (v13 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v58:
    popv(2);
    return nil;
}



/* Code for mkprod */

static Lisp_Object CC_mkprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprod");
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
    stack[-2] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v91 = stack[-4];
    if (v91 == nil) goto v22;
    v91 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    goto v36;

v36:
    if (v91 == nil) goto v94;
    v91 = stack[-4];
    goto v95;

v95:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    { popv(7); return onevalue(v91); }

v94:
    v91 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v91; /* !*sub2 */
    v92 = stack[-4];
    v91 = (Lisp_Object)17; /* 1 */
    v91 = cons(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    fn = elt(env, 11); /* subs2 */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[0] = v91;
    v91 = stack[0];
    v92 = qcdr(v91);
    v91 = (Lisp_Object)17; /* 1 */
    if (v92 == v91) goto v19;
    v91 = stack[-4];
    goto v95;

v19:
    v91 = stack[0];
    v92 = qcar(v91);
    v91 = stack[-4];
    if (equal(v92, v91)) goto v34;
    v91 = stack[0];
    v91 = qcar(v91);
    stack[-4] = v91;
    v91 = stack[-4];
    if (v91 == nil) goto v96;
    v91 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    goto v97;

v97:
    if (v91 == nil) goto v34;
    v91 = stack[-4];
    goto v95;

v34:
    v91 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v91; /* !*exp */
    v91 = stack[-4];
    fn = elt(env, 12); /* ckrn */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[-5] = v91;
    v92 = stack[-4];
    v91 = stack[-5];
    fn = elt(env, 13); /* quotf */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[-4] = v91;
    v91 = stack[-4];
    fn = elt(env, 14); /* expnd */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[0] = v91;
    v91 = stack[0];
    if (v91 == nil) goto v98;
    v91 = stack[0];
    fn = elt(env, 10); /* kernlp */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    goto v99;

v99:
    if (v91 == nil) goto v8;
    v92 = stack[-5];
    v91 = stack[0];
    fn = elt(env, 15); /* multf */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    goto v95;

v8:
    v91 = qvalue(elt(env, 4)); /* !*mcd */
    if (v91 == nil) goto v100;
    v91 = qvalue(elt(env, 5)); /* !*sqfree */
    if (!(v91 == nil)) goto v101;
    v91 = qvalue(elt(env, 6)); /* !*factor */
    if (!(v91 == nil)) goto v101;
    v91 = qvalue(elt(env, 7)); /* !*gcd */
    if (!(v91 == nil)) goto v101;

v100:
    v91 = stack[0];
    fn = elt(env, 12); /* ckrn */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[-3] = v91;
    v92 = stack[0];
    v91 = stack[-3];
    fn = elt(env, 13); /* quotf */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[0] = v91;
    v92 = stack[0];
    v91 = (Lisp_Object)17; /* 1 */
    v91 = cons(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    v91 = list2(stack[-3], v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[-3] = v91;
    goto v102;

v102:
    v91 = stack[-3];
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v92 = qcdr(v91);
    v91 = (Lisp_Object)17; /* 1 */
    v91 = (Lisp_Object)greaterp2(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    v91 = v91 ? lisp_true : nil;
    env = stack[-6];
    if (!(v91 == nil)) goto v103;
    v91 = stack[-3];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    if (!(v91 == nil)) goto v103;
    v91 = qvalue(elt(env, 9)); /* !*group */
    if (v91 == nil) goto v104;
    v91 = qvalue(elt(env, 8)); /* nil */
    goto v105;

v105:
    if (v91 == nil) goto v106;
    v91 = stack[-3];
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v92 = qcar(v91);
    v91 = stack[-3];
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v91 = qcdr(v91);
    fn = elt(env, 16); /* mksp!* */
    v92 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    v91 = stack[-3];
    v91 = qcar(v91);
    fn = elt(env, 15); /* multf */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[0] = v91;
    goto v107;

v107:
    v92 = stack[-5];
    v91 = stack[0];
    fn = elt(env, 15); /* multf */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    goto v95;

v106:
    v92 = stack[-4];
    v91 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksp!* */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[0] = v91;
    goto v107;

v104:
    v91 = stack[-4];
    fn = elt(env, 17); /* tmsf */
    stack[0] = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    v91 = stack[-3];
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v91 = qcar(v91);
    fn = elt(env, 17); /* tmsf */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    v91 = (Lisp_Object)greaterp2(stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    v91 = v91 ? lisp_true : nil;
    env = stack[-6];
    goto v105;

v103:
    v91 = stack[-3];
    v91 = qcar(v91);
    stack[0] = v91;
    v91 = stack[-3];
    v91 = qcdr(v91);
    stack[-3] = v91;
    goto v108;

v108:
    v91 = stack[-3];
    if (v91 == nil) goto v107;
    v91 = stack[-3];
    v91 = qcar(v91);
    v92 = v91;
    v92 = qcar(v92);
    v91 = qcdr(v91);
    fn = elt(env, 16); /* mksp!* */
    v92 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    v91 = stack[0];
    fn = elt(env, 15); /* multf */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[0] = v91;
    v91 = stack[-3];
    v91 = qcdr(v91);
    stack[-3] = v91;
    goto v108;

v101:
    v91 = stack[0];
    fn = elt(env, 18); /* fctrf */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[-3] = v91;
    goto v102;

v98:
    v91 = qvalue(elt(env, 3)); /* t */
    goto v99;

v96:
    v91 = qvalue(elt(env, 3)); /* t */
    goto v97;

v22:
    v91 = qvalue(elt(env, 3)); /* t */
    goto v36;
/* error exit handlers */
v93:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    popv(7);
    return nil;
}



/* Code for setdmode1 */

static Lisp_Object CC_setdmode1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v139, v140, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdmode1");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v139 = v45;
    stack[-5] = v0;
/* end of prologue */
    v140 = stack[-5];
    v106 = elt(env, 1); /* tag */
    v106 = get(v140, v106);
    env = stack[-7];
    stack[-6] = v106;
    v106 = qvalue(elt(env, 2)); /* dmode!* */
    stack[-4] = v106;
    v106 = v139;
    if (v106 == nil) goto v13;
    v139 = stack[-5];
    v106 = elt(env, 13); /* (rounded complex!-rounded) */
    v106 = Lmemq(nil, v139, v106);
    if (v106 == nil) goto v86;
    fn = elt(env, 21); /* !!mfefix */
    v106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    goto v86;

v86:
    v139 = stack[-6];
    v106 = stack[-4];
    if (v139 == v106) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v139 = stack[-6];
    v106 = elt(env, 14); /* realtype */
    v106 = get(v139, v106);
    env = stack[-7];
    stack[-3] = v106;
    if (!(v106 == nil)) goto v143;
    v106 = stack[-6];
    stack[-3] = v106;
    goto v143;

v143:
    v106 = qvalue(elt(env, 15)); /* domainlist!* */
    stack[-2] = v106;
    goto v144;

v144:
    v106 = stack[-2];
    if (v106 == nil) goto v145;
    v106 = stack[-2];
    v106 = qcar(v106);
    stack[-1] = v106;
    v139 = stack[-1];
    v106 = elt(env, 16); /* !:gi!: */
    if (v139 == v106) goto v78;
    v139 = stack[-1];
    v106 = stack[-3];
    v106 = (v139 == v106 ? lisp_true : nil);
    v106 = (v106 == nil ? lisp_true : nil);
    goto v146;

v146:
    if (v106 == nil) goto v80;
    v106 = elt(env, 17); /* !* */
    stack[0] = Lexplode(nil, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    v139 = stack[-1];
    v106 = elt(env, 4); /* dname */
    v106 = get(v139, v106);
    env = stack[-7];
    v106 = Lexplode(nil, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    v106 = Lappend(nil, stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    v106 = Lcompress(nil, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    v139 = Lintern(nil, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    v106 = qvalue(elt(env, 3)); /* nil */
    v106 = Lset(nil, v139, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    goto v80;

v80:
    v106 = stack[-2];
    v106 = qcdr(v106);
    stack[-2] = v106;
    goto v144;

v78:
    v106 = qvalue(elt(env, 3)); /* nil */
    goto v146;

v145:
    v139 = qvalue(elt(env, 5)); /* !*sqvar!* */
    v106 = qvalue(elt(env, 3)); /* nil */
    v106 = Lrplaca(nil, v139, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    v106 = qvalue(elt(env, 6)); /* t */
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    qvalue(elt(env, 5)) = v106; /* !*sqvar!* */
    v106 = qvalue(elt(env, 3)); /* nil */
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    qvalue(elt(env, 7)) = v106; /* alglist!* */
    v139 = stack[-4];
    v106 = elt(env, 4); /* dname */
    v106 = get(v139, v106);
    env = stack[-7];
    stack[-4] = v106;
    v106 = stack[-4];
    if (v106 == nil) goto v69;
    v106 = qvalue(elt(env, 18)); /* !*msg */
    if (v106 == nil) goto v69;
    stack[0] = elt(env, 9); /* "***" */
    v141 = elt(env, 19); /* "Domain mode" */
    v140 = stack[-4];
    v139 = elt(env, 20); /* "changed to" */
    v106 = stack[-5];
    v106 = list4(v141, v140, v139, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    fn = elt(env, 22); /* lpriw */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    goto v69;

v69:
    v106 = stack[-6];
    qvalue(elt(env, 2)) = v106; /* dmode!* */
    qvalue(elt(env, 8)) = v106; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v13:
    v106 = stack[-4];
    if (v106 == nil) goto v54;
    v140 = stack[-5];
    v139 = stack[-4];
    v106 = elt(env, 4); /* dname */
    v106 = get(v139, v106);
    env = stack[-7];
    stack[-4] = v106;
    if (v140 == v106) goto v52;
    stack[-2] = elt(env, 9); /* "***" */
    stack[-1] = elt(env, 10); /* "Failed attempt to turn off" */
    stack[-3] = stack[-5];
    stack[0] = elt(env, 11); /* "when" */
    v139 = stack[-4];
    v106 = elt(env, 12); /* "is on" */
    v106 = list2(v139, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    v106 = list3star(stack[-1], stack[-3], stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    {
        Lisp_Object v147 = stack[-2];
        popv(8);
        fn = elt(env, 22); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v147, v106);
    }

v52:
    v139 = qvalue(elt(env, 5)); /* !*sqvar!* */
    v106 = qvalue(elt(env, 3)); /* nil */
    v106 = Lrplaca(nil, v139, v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    v106 = qvalue(elt(env, 6)); /* t */
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    qvalue(elt(env, 5)) = v106; /* !*sqvar!* */
    v106 = qvalue(elt(env, 3)); /* nil */
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-7];
    qvalue(elt(env, 7)) = v106; /* alglist!* */
    v106 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v106; /* dmode!* */
    qvalue(elt(env, 8)) = v106; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v54:
    v106 = qvalue(elt(env, 3)); /* nil */
    { popv(8); return onevalue(v106); }
/* error exit handlers */
v142:
    popv(8);
    return nil;
}



/* Code for expvec2a */

static Lisp_Object CC_expvec2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expvec2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */
    v94 = v41;
    v41 = qvalue(elt(env, 1)); /* dipvars!* */
    {
        fn = elt(env, 2); /* expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v94, v41);
    }
}



/* Code for freeindexchk */

static Lisp_Object CC_freeindexchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeindexchk");
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
    v13 = v0;
/* end of prologue */
    v17 = v13;
    if (v17 == nil) goto v36;
    v17 = qvalue(elt(env, 1)); /* indxl!* */
    if (v17 == nil) goto v36;
    v17 = v13;
    fn = elt(env, 4); /* indxchk */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[0];
    if (v17 == nil) goto v36;
    v17 = elt(env, 2); /* form!-with!-free!-indices */
    { popv(1); return onevalue(v17); }

v36:
    v17 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v17); }
/* error exit handlers */
v48:
    popv(1);
    return nil;
}



/* Code for partitexdf */

static Lisp_Object CC_partitexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitexdf");
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
    v11 = v0;
/* end of prologue */
    v11 = qcar(v11);
    fn = elt(env, 1); /* partitop */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* exdfpf */
        return (*qfn1(fn))(qenv(fn), v11);
    }
/* error exit handlers */
v55:
    popv(1);
    return nil;
}



/* Code for fctargs */

static Lisp_Object CC_fctargs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctargs");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v0;
/* end of prologue */
    v23 = qvalue(elt(env, 1)); /* depl!* */
    v23 = Lassoc(nil, v22, v23);
    v22 = v23;
    if (v23 == nil) goto v61;
    v22 = qcdr(v22);
    return onevalue(v22);

v61:
    v22 = nil;
    return onevalue(v22);
}



/* Code for powers4 */

static Lisp_Object CC_powers4(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v192, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers4");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v11;

v11:
    v191 = stack[-1];
    if (v191 == nil) goto v57;
    v191 = stack[0];
    if (v191 == nil) goto v8;
    v191 = stack[-1];
    v191 = qcar(v191);
    v192 = qcar(v191);
    v191 = stack[0];
    v191 = qcar(v191);
    v191 = qcar(v191);
    if (equal(v192, v191)) goto v117;
    v191 = stack[-1];
    v191 = qcar(v191);
    v192 = qcar(v191);
    v191 = stack[0];
    v191 = qcar(v191);
    v191 = qcar(v191);
    fn = elt(env, 2); /* ordop */
    v191 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    if (v191 == nil) goto v195;
    v191 = stack[0];
    v191 = qcar(v191);
    v192 = qcdr(v191);
    v191 = (Lisp_Object)1; /* 0 */
    v191 = Lrplacd(nil, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    stack[-2] = stack[0];
    v192 = stack[-1];
    v191 = stack[0];
    v191 = qcdr(v191);
    v191 = CC_powers4(env, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = Lrplacd(nil, stack[-2], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    {
        Lisp_Object v196 = stack[-3];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v196, v191);
    }

v195:
    v191 = stack[-1];
    v191 = qcar(v191);
    stack[-2] = qcar(v191);
    v191 = stack[-1];
    v191 = qcar(v191);
    v192 = qcdr(v191);
    v191 = (Lisp_Object)1; /* 0 */
    v192 = cons(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = stack[-3];
    v191 = acons(stack[-2], v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    stack[-3] = v191;
    v191 = stack[-1];
    v191 = qcdr(v191);
    stack[-1] = v191;
    goto v11;

v117:
    v191 = stack[-1];
    v191 = qcar(v191);
    v192 = qcdr(v191);
    v191 = stack[0];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = qcar(v191);
    v191 = (Lisp_Object)greaterp2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    v191 = v191 ? lisp_true : nil;
    env = stack[-5];
    if (v191 == nil) goto v72;
    v191 = stack[0];
    v191 = qcar(v191);
    v192 = qcdr(v191);
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = Lrplaca(nil, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    goto v72;

v72:
    v191 = stack[-1];
    v191 = qcar(v191);
    v192 = qcdr(v191);
    v191 = stack[0];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    v191 = (Lisp_Object)lessp2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    v191 = v191 ? lisp_true : nil;
    env = stack[-5];
    if (v191 == nil) goto v64;
    v191 = stack[0];
    v191 = qcar(v191);
    v192 = qcdr(v191);
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = Lrplacd(nil, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    goto v64;

v64:
    stack[-2] = stack[0];
    v191 = stack[-1];
    v192 = qcdr(v191);
    v191 = stack[0];
    v191 = qcdr(v191);
    v191 = CC_powers4(env, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = Lrplacd(nil, stack[-2], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    {
        Lisp_Object v197 = stack[-3];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v197, v191);
    }

v8:
    stack[-4] = stack[-3];
    v191 = stack[-1];
    stack[-3] = v191;
    v191 = stack[-3];
    if (v191 == nil) goto v198;
    v191 = stack[-3];
    v191 = qcar(v191);
    v192 = v191;
    v193 = qcar(v192);
    v192 = qcdr(v191);
    v191 = (Lisp_Object)1; /* 0 */
    v191 = list2star(v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    stack[-1] = v191;
    stack[-2] = v191;
    goto v199;

v199:
    v191 = stack[-3];
    v191 = qcdr(v191);
    stack[-3] = v191;
    v191 = stack[-3];
    if (v191 == nil) goto v200;
    stack[0] = stack[-1];
    v191 = stack[-3];
    v191 = qcar(v191);
    v192 = v191;
    v193 = qcar(v192);
    v192 = qcdr(v191);
    v191 = (Lisp_Object)1; /* 0 */
    v191 = list2star(v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = Lrplacd(nil, stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = stack[-1];
    v191 = qcdr(v191);
    stack[-1] = v191;
    goto v199;

v200:
    v191 = stack[-2];
    goto v9;

v9:
    {
        Lisp_Object v201 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v201, v191);
    }

v198:
    v191 = qvalue(elt(env, 1)); /* nil */
    goto v9;

v57:
    stack[-4] = stack[-3];
    v191 = stack[0];
    stack[-3] = v191;
    v191 = stack[-3];
    if (v191 == nil) goto v42;
    v191 = stack[-3];
    v191 = qcar(v191);
    v192 = v191;
    v193 = qcar(v192);
    v191 = qcdr(v191);
    v192 = qcar(v191);
    v191 = (Lisp_Object)1; /* 0 */
    v191 = list2star(v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    stack[-1] = v191;
    stack[-2] = v191;
    goto v54;

v54:
    v191 = stack[-3];
    v191 = qcdr(v191);
    stack[-3] = v191;
    v191 = stack[-3];
    if (v191 == nil) goto v3;
    stack[0] = stack[-1];
    v191 = stack[-3];
    v191 = qcar(v191);
    v192 = v191;
    v193 = qcar(v192);
    v191 = qcdr(v191);
    v192 = qcar(v191);
    v191 = (Lisp_Object)1; /* 0 */
    v191 = list2star(v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = Lrplacd(nil, stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-5];
    v191 = stack[-1];
    v191 = qcdr(v191);
    stack[-1] = v191;
    goto v54;

v3:
    v191 = stack[-2];
    goto v22;

v22:
    {
        Lisp_Object v202 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v202, v191);
    }

v42:
    v191 = qvalue(elt(env, 1)); /* nil */
    goto v22;
/* error exit handlers */
v194:
    popv(6);
    return nil;
}



/* Code for assert_check1 */

static Lisp_Object MS_CDECL CC_assert_check1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v45,
                         Lisp_Object v28, Lisp_Object v29,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v218, v113, v114, v219, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "assert_check1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_check1");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v29,v28,v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v45,v28,v29,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-5] = v4;
    stack[-6] = v29;
    stack[-7] = v28;
    stack[-8] = v45;
    stack[-9] = v0;
/* end of prologue */
    stack[-4] = nil;
    v104 = (Lisp_Object)1; /* 0 */
    stack[-3] = v104;
    v104 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v104 == nil) goto v22;
    v218 = stack[-9];
    v104 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v104 = Latsoc(nil, v218, v104);
    v218 = v104;
    v104 = v218;
    if (v104 == nil) goto v53;
    v104 = v218;
    stack[0] = qcdr(v104);
    v104 = v218;
    v104 = qcdr(v104);
    v104 = qcar(v104);
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    fn = elt(env, 6); /* setcar */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    goto v22;

v22:
    v104 = stack[-6];
    stack[-10] = v104;
    v104 = stack[-7];
    stack[-2] = v104;
    goto v40;

v40:
    v104 = stack[-2];
    if (v104 == nil) goto v83;
    v104 = stack[-2];
    v104 = qcar(v104);
    stack[-1] = v104;
    v104 = stack[-3];
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    stack[-3] = v104;
    v104 = stack[-10];
    v218 = qcar(v104);
    v104 = elt(env, 4); /* assert_checkfn */
    v104 = get(v218, v104);
    env = stack[-11];
    v218 = v104;
    if (v104 == nil) goto v221;
    stack[0] = v218;
    v104 = stack[-1];
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    fn = elt(env, 7); /* apply */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    if (!(v104 == nil)) goto v221;
    v104 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v104;
    v69 = stack[-9];
    v219 = stack[-6];
    v114 = stack[-5];
    v113 = stack[-3];
    v104 = stack[-10];
    v218 = qcar(v104);
    v104 = stack[-1];
    fn = elt(env, 8); /* assert_error */
    v104 = (*qfnn(fn))(qenv(fn), 6, v69, v219, v114, v113, v218, v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    goto v221;

v221:
    v104 = stack[-10];
    v104 = qcdr(v104);
    stack[-10] = v104;
    v104 = stack[-2];
    v104 = qcdr(v104);
    stack[-2] = v104;
    goto v40;

v83:
    v218 = stack[-8];
    v104 = stack[-7];
    fn = elt(env, 7); /* apply */
    v104 = (*qfn2(fn))(qenv(fn), v218, v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    stack[-1] = v104;
    v218 = stack[-5];
    v104 = elt(env, 4); /* assert_checkfn */
    v104 = get(v218, v104);
    env = stack[-11];
    v218 = v104;
    if (v104 == nil) goto v79;
    stack[0] = v218;
    v104 = stack[-1];
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    fn = elt(env, 7); /* apply */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    if (!(v104 == nil)) goto v79;
    v104 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v104;
    v69 = stack[-9];
    v219 = stack[-6];
    v114 = stack[-5];
    v113 = (Lisp_Object)1; /* 0 */
    v218 = stack[-5];
    v104 = stack[-1];
    fn = elt(env, 8); /* assert_error */
    v104 = (*qfnn(fn))(qenv(fn), 6, v69, v219, v114, v113, v218, v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    goto v79;

v79:
    v104 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v104 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v104 = stack[-4];
    if (v104 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v218 = stack[-9];
    v104 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v104 = Latsoc(nil, v218, v104);
    v104 = qcdr(v104);
    v218 = v104;
    v104 = v218;
    stack[0] = qcdr(v104);
    v104 = v218;
    v104 = qcdr(v104);
    v104 = qcar(v104);
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    fn = elt(env, 6); /* setcar */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }

v53:
    stack[0] = stack[-9];
    v113 = (Lisp_Object)17; /* 1 */
    v218 = (Lisp_Object)1; /* 0 */
    v104 = (Lisp_Object)1; /* 0 */
    v218 = list3(v113, v218, v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    v104 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v104 = acons(stack[0], v218, v104);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-11];
    qvalue(elt(env, 2)) = v104; /* assertstatistics!* */
    goto v22;
/* error exit handlers */
v220:
    popv(12);
    return nil;
}



/* Code for splitlist!: */

static Lisp_Object CC_splitlistT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v217, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitlist:");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v0;
/* end of prologue */
    v5 = nil;
    goto v11;

v11:
    v216 = stack[-1];
    if (v216 == nil) goto v95;
    v216 = stack[-1];
    v217 = qcar(v216);
    v216 = stack[0];
    if (!consp(v217)) goto v34;
    v217 = qcar(v217);
    if (!(v217 == v216)) goto v34;
    v216 = stack[-1];
    v216 = qcar(v216);
    v217 = v5;
    v216 = cons(v216, v217);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v5 = v216;
    v216 = stack[-1];
    v216 = qcdr(v216);
    stack[-1] = v216;
    goto v11;

v34:
    v216 = stack[-1];
    v216 = qcdr(v216);
    stack[-1] = v216;
    goto v11;

v95:
    v216 = v5;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v216);
    }
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_hornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v45,
                         Lisp_Object v28, Lisp_Object v29,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v126, v127, v102, v227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v29,v28,v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v45,v28,v29,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v4;
    stack[-3] = v29;
    stack[-4] = v28;
    v127 = v45;
    v102 = v0;
/* end of prologue */

v228:
    v179 = stack[-4];
    if (!consp(v179)) goto v22;
    v179 = stack[-4];
    v179 = qcar(v179);
    v179 = (consp(v179) ? nil : lisp_true);
    goto v36;

v36:
    if (v179 == nil) goto v42;
    v179 = qvalue(elt(env, 1)); /* t */
    goto v94;

v94:
    if (v179 == nil) goto v136;
    v179 = stack[-3];
    if (v179 == nil) goto v32;
    v179 = stack[-3];
    v179 = (Lisp_Object)zerop(v179);
    v179 = v179 ? lisp_true : nil;
    env = stack[-6];
    goto v31;

v31:
    if (!(v179 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v102;
    v179 = stack[-3];
    v126 = v127;
    fn = elt(env, 2); /* expt!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), v179, v126);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    fn = elt(env, 3); /* times!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), stack[0], v179);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v102 = v179;
    v179 = stack[-4];
    v126 = v102;
    {
        popv(7);
        fn = elt(env, 4); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v179, v126);
    }

v32:
    v179 = qvalue(elt(env, 1)); /* t */
    goto v31;

v136:
    v179 = stack[-4];
    v179 = qcar(v179);
    v179 = qcar(v179);
    v179 = qcdr(v179);
    stack[-5] = v179;
    v179 = stack[-3];
    if (v179 == nil) goto v214;
    v179 = stack[-3];
    v179 = (Lisp_Object)zerop(v179);
    v179 = v179 ? lisp_true : nil;
    env = stack[-6];
    goto v213;

v213:
    if (v179 == nil) goto v186;
    v179 = stack[-4];
    v179 = qcar(v179);
    v179 = qcdr(v179);
    v102 = v179;
    goto v9;

v9:
    v127 = stack[-5];
    v179 = stack[-4];
    v227 = qcdr(v179);
    v126 = stack[-3];
    v179 = stack[-2];
    stack[-4] = v227;
    stack[-3] = v126;
    stack[-2] = v179;
    goto v228;

v186:
    v179 = stack[-4];
    v179 = qcar(v179);
    stack[-1] = qcdr(v179);
    stack[0] = v102;
    v126 = stack[-3];
    v179 = stack[-5];
    v179 = (Lisp_Object)(int32_t)((int32_t)v127 - (int32_t)v179 + TAG_FIXNUM);
    fn = elt(env, 2); /* expt!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), v126, v179);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    fn = elt(env, 3); /* times!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), stack[0], v179);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    fn = elt(env, 4); /* plus!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), stack[-1], v179);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v102 = v179;
    goto v9;

v214:
    v179 = qvalue(elt(env, 1)); /* t */
    goto v213;

v42:
    v179 = stack[-4];
    v179 = qcar(v179);
    v179 = qcar(v179);
    v126 = qcar(v179);
    v179 = stack[-2];
    v179 = (equal(v126, v179) ? lisp_true : nil);
    v179 = (v179 == nil ? lisp_true : nil);
    goto v94;

v22:
    v179 = qvalue(elt(env, 1)); /* t */
    goto v36;
/* error exit handlers */
v77:
    popv(7);
    return nil;
}



/* Code for drnconv */

static Lisp_Object CC_drnconv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v229, v230;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drnconv");
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
    v229 = v0;
/* end of prologue */
    v27 = v229;
    if (v27 == nil) goto v10;
    v27 = v229;
    v27 = (is_number(v27) ? lisp_true : nil);
    if (!(v27 == nil)) goto v55;
    v230 = v229;
    v27 = qvalue(elt(env, 2)); /* dmd!* */
    v27 = Leqcar(nil, v230, v27);
    env = stack[0];
    goto v55;

v55:
    if (!(v27 == nil)) { popv(1); return onevalue(v229); }
    v27 = v229;
    v230 = qcar(v27);
    v27 = qvalue(elt(env, 2)); /* dmd!* */
    v27 = get(v230, v27);
    v230 = v27;
    v27 = v230;
    if (v27 == nil) { popv(1); return onevalue(v229); }
    v27 = v230;
    if (!(!consp(v27))) { popv(1); return onevalue(v229); }
    v27 = v230;
        popv(1);
        return Lapply1(nil, v27, v229);

v10:
    v27 = qvalue(elt(env, 1)); /* t */
    goto v55;
}



/* Code for cl_identifyonoff */

static Lisp_Object CC_cl_identifyonoff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v29;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyonoff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v0;
/* end of prologue */
    v29 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v29; /* cl_identify!-atl!* */
    return onevalue(v29);
}



/* Code for qqe_prepat */

static Lisp_Object CC_qqe_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v29;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_prepat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v0;
/* end of prologue */
    return onevalue(v29);
}



/* Code for ibalp_negatet */

static Lisp_Object CC_ibalp_negatet(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v35, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negatet");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v0;
/* end of prologue */
    v35 = v34;
    v50 = (Lisp_Object)1; /* 0 */
    if (v35 == v50) goto v4;
    v35 = v34;
    v50 = (Lisp_Object)17; /* 1 */
    if (v35 == v50) goto v12;
    v50 = elt(env, 1); /* bnot */
    v35 = v34;
    return list2(v50, v35);

v12:
    v50 = (Lisp_Object)1; /* 0 */
    return onevalue(v50);

v4:
    v50 = (Lisp_Object)17; /* 1 */
    return onevalue(v50);
}



/* Code for makeset */

static Lisp_Object CC_makeset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v217, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeset");
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
    v5 = nil;
    goto v61;

v61:
    v216 = stack[0];
    if (v216 == nil) goto v10;
    v216 = stack[0];
    v217 = qcar(v216);
    v216 = stack[0];
    v216 = qcdr(v216);
    v216 = Lmember(nil, v217, v216);
    if (v216 == nil) goto v47;
    v216 = stack[0];
    v216 = qcdr(v216);
    stack[0] = v216;
    goto v61;

v47:
    v216 = stack[0];
    v216 = qcar(v216);
    v217 = v5;
    v216 = cons(v216, v217);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    v5 = v216;
    v216 = stack[0];
    v216 = qcdr(v216);
    stack[0] = v216;
    goto v61;

v10:
    v216 = v5;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v216);
    }
/* error exit handlers */
v56:
    popv(2);
    return nil;
}



/* Code for onoff */

static Lisp_Object CC_onoff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v84, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for onoff");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v45;
    stack[0] = v0;
/* end of prologue */
    v83 = stack[0];
    if (symbolp(v83)) goto v58;
    v84 = stack[0];
    v83 = elt(env, 1); /* "switch" */
    fn = elt(env, 12); /* typerr */
    v83 = (*qfn2(fn))(qenv(fn), v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    goto v138;

v138:
    v83 = elt(env, 6); /* !* */
    stack[-1] = Lexplode(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v83 = stack[0];
    v83 = Lexplode(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v83 = Lappend(nil, stack[-1], v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v83 = Lcompress(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v83 = Lintern(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    stack[-3] = v83;
    v83 = qvalue(elt(env, 7)); /* !*switchcheck */
    if (v83 == nil) goto v136;
    v83 = stack[-3];
    fn = elt(env, 13); /* eval */
    v84 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v83 = stack[-2];
    if (!(v84 == v83)) goto v136;
    v83 = qvalue(elt(env, 8)); /* nil */
    { popv(5); return onevalue(v83); }

v136:
    v236 = stack[-2];
    v84 = stack[0];
    v83 = elt(env, 9); /* simpfg */
    v83 = get(v84, v83);
    env = stack[-4];
    v83 = Latsoc(nil, v236, v83);
    v84 = v83;
    if (v83 == nil) goto v226;
    stack[-1] = elt(env, 10); /* progn */
    v83 = v84;
    stack[0] = qcdr(v83);
    v83 = qvalue(elt(env, 8)); /* nil */
    v83 = ncons(v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v83 = Lappend(nil, stack[0], v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v83 = cons(stack[-1], v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    fn = elt(env, 13); /* eval */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    goto v226;

v226:
    v83 = stack[-2];
    if (v83 == nil) goto v200;
    v84 = stack[-3];
    v83 = elt(env, 11); /* !*raise */
    if (!(v84 == v83)) goto v200;
    v83 = elt(env, 11); /* !*raise */
    stack[-3] = v83;
    goto v200;

v200:
    v84 = stack[-3];
    v83 = stack[-2];
    v83 = Lset(nil, v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    v83 = nil;
    { popv(5); return onevalue(v83); }

v58:
    v84 = stack[0];
    v83 = elt(env, 2); /* switch */
    v83 = Lflagp(nil, v84, v83);
    env = stack[-4];
    if (!(v83 == nil)) goto v138;
    v84 = stack[0];
    v83 = elt(env, 3); /* "not defined as switch" */
    v83 = list2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v84 = v83;
    v83 = v84;
    qvalue(elt(env, 4)) = v83; /* errmsg!* */
    v83 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v83 == nil)) goto v6;
    v83 = v84;
    fn = elt(env, 14); /* lprie */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    goto v6;

v6:
    v83 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    goto v138;
/* error exit handlers */
v122:
    popv(5);
    return nil;
}



/* Code for indexvarordp */

static Lisp_Object CC_indexvarordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvarordp");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v0;
/* end of prologue */
    v143 = stack[-1];
    v241 = qcar(v143);
    v143 = stack[0];
    v143 = qcar(v143);
    if (v241 == v143) goto v30;
    v143 = qvalue(elt(env, 1)); /* t */
    goto v10;

v10:
    if (v143 == nil) goto v19;
    v241 = stack[-1];
    v143 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v241, v143);
    }

v19:
    v143 = stack[-1];
    v143 = qcdr(v143);
    fn = elt(env, 6); /* flatindxl */
    stack[-2] = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v143 = stack[0];
    v143 = qcdr(v143);
    fn = elt(env, 6); /* flatindxl */
    v241 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v143 = stack[-2];
    stack[-2] = v241;
    v241 = v143;
    v143 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v143 = (*qfn2(fn))(qenv(fn), v241, v143);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    if (v143 == nil) goto v199;
    v241 = stack[-2];
    v143 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v143 = (*qfn2(fn))(qenv(fn), v241, v143);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    if (v143 == nil) goto v98;
    v143 = stack[-1];
    v241 = qcdr(v143);
    v143 = stack[0];
    v143 = qcdr(v143);
    {
        popv(4);
        fn = elt(env, 8); /* indordlp */
        return (*qfn2(fn))(qenv(fn), v241, v143);
    }

v98:
    v143 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v143); }

v199:
    v241 = stack[-2];
    v143 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v143 = (*qfn2(fn))(qenv(fn), v241, v143);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    if (v143 == nil) goto v187;
    v143 = qvalue(elt(env, 4)); /* nil */
    { popv(4); return onevalue(v143); }

v187:
    v241 = stack[-1];
    v143 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v241, v143);
    }

v30:
    v241 = stack[-1];
    v143 = qvalue(elt(env, 2)); /* kord!* */
    v143 = Lmemq(nil, v241, v143);
    if (!(v143 == nil)) goto v10;
    v241 = stack[0];
    v143 = qvalue(elt(env, 2)); /* kord!* */
    v143 = Lmemq(nil, v241, v143);
    goto v10;
/* error exit handlers */
v184:
    popv(4);
    return nil;
}



/* Code for mkfortterpri */

static Lisp_Object MS_CDECL CC_mkfortterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkfortterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkfortterpri");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v29 = elt(env, 1); /* fortterpri */
    return ncons(v29);
}



/* Code for can_be_proved */

static Lisp_Object CC_can_be_proved(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for can_be_proved");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v0;
/* end of prologue */

v61:
    v42 = stack[-1];
    if (v42 == nil) goto v10;
    v42 = stack[-1];
    v46 = qcar(v42);
    v42 = stack[0];
    fn = elt(env, 3); /* can_be_p */
    v42 = (*qfn2(fn))(qenv(fn), v46, v42);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-2];
    if (v42 == nil) goto v33;
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[-1] = v42;
    goto v61;

v33:
    v42 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v42); }

v10:
    v42 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v42); }
/* error exit handlers */
v222:
    popv(3);
    return nil;
}



/* Code for assert_stat1 */

static Lisp_Object MS_CDECL CC_assert_stat1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_stat1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_stat1");
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
    stack[0] = nil;
    fn = elt(env, 9); /* scan */
    v212 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    v185 = elt(env, 1); /* !*lpar!* */
    if (v212 == v185) goto v34;
    v185 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v185 == nil)) goto v17;
    v212 = elt(env, 3); /* "expecting '(' in assert but found" */
    v185 = qvalue(elt(env, 4)); /* cursym!* */
    v185 = list2(v212, v185);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    fn = elt(env, 10); /* lprie */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    goto v17;

v17:
    v185 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    goto v34;

v34:
    fn = elt(env, 9); /* scan */
    v212 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    v185 = elt(env, 5); /* !*rpar!* */
    if (!(v212 == v185)) goto v53;
    v185 = qvalue(elt(env, 6)); /* nil */
    { popv(2); return onevalue(v185); }

v53:
    v212 = qvalue(elt(env, 4)); /* cursym!* */
    v185 = stack[0];
    v185 = cons(v212, v185);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    stack[0] = v185;
    fn = elt(env, 9); /* scan */
    v185 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    v212 = qvalue(elt(env, 4)); /* cursym!* */
    v185 = elt(env, 7); /* !*comma!* */
    if (v212 == v185) goto v137;
    v212 = qvalue(elt(env, 4)); /* cursym!* */
    v185 = elt(env, 5); /* !*rpar!* */
    v185 = Lneq(nil, v212, v185);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    goto v230;

v230:
    if (v185 == nil) goto v232;
    v185 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v185 == nil)) goto v88;
    v212 = elt(env, 8); /* "expecting ',' or ')' in assert but found" */
    v185 = qvalue(elt(env, 4)); /* cursym!* */
    v185 = list2(v212, v185);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    fn = elt(env, 10); /* lprie */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    goto v88;

v88:
    v185 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    goto v232;

v232:
    v212 = qvalue(elt(env, 4)); /* cursym!* */
    v185 = elt(env, 7); /* !*comma!* */
    if (!(v212 == v185)) goto v132;
    fn = elt(env, 9); /* scan */
    v185 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    goto v132;

v132:
    v212 = qvalue(elt(env, 4)); /* cursym!* */
    v185 = elt(env, 5); /* !*rpar!* */
    if (!(v212 == v185)) goto v53;
    v185 = stack[0];
        popv(2);
        return Lnreverse(nil, v185);

v137:
    v185 = qvalue(elt(env, 6)); /* nil */
    goto v230;
/* error exit handlers */
v129:
    popv(2);
    return nil;
}



/* Code for no_dum_varp */

static Lisp_Object CC_no_dum_varp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no_dum_varp");
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
    v34 = stack[0];
    v34 = qcdr(v34);
    if (v34 == nil) goto v10;
    v34 = stack[0];
    v51 = qcdr(v34);
    v34 = elt(env, 2); /* list */
    fn = elt(env, 4); /* splitlist!: */
    v51 = (*qfn2(fn))(qenv(fn), v51, v34);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    v34 = stack[0];
    v34 = qcdr(v34);
    v34 = (equal(v51, v34) ? lisp_true : nil);
    goto v55;

v55:
    if (v34 == nil) goto v49;
    v34 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v34); }

v49:
    v34 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v34); }

v10:
    v34 = qvalue(elt(env, 1)); /* t */
    goto v55;
/* error exit handlers */
v21:
    popv(2);
    return nil;
}



/* Code for ratn */

static Lisp_Object CC_ratn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v3, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratn");
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
    v24 = v0;
/* end of prologue */
    v138 = v24;
    if (v138 == nil) goto v10;
    v138 = v24;
    if (!consp(v138)) goto v13;
    v138 = v24;
    v3 = qcar(v138);
    v138 = elt(env, 1); /* !:rn!: */
    if (v3 == v138) goto v30;
    v138 = elt(env, 2); /* "Illegal domain in :ar:" */
    v3 = v138;
    v138 = v3;
    qvalue(elt(env, 3)) = v138; /* errmsg!* */
    v138 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v138 == nil)) goto v32;
    v138 = v3;
    fn = elt(env, 5); /* lprie */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[0];
    goto v32;

v32:
    v138 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v138 = nil;
    { popv(1); return onevalue(v138); }

v30:
    v138 = v24;
    v138 = qcdr(v138);
    { popv(1); return onevalue(v138); }

v13:
    v3 = v24;
    v138 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v3, v138);

v10:
    v3 = (Lisp_Object)1; /* 0 */
    v138 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v3, v138);
/* error exit handlers */
v90:
    popv(1);
    return nil;
}



/* Code for cl_fvarl1 */

static Lisp_Object CC_cl_fvarl1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_fvarl1");
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
/* copy arguments values to proper place */
    v61 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cl_varl1 */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    errexit();
    v61 = qcar(v61);
    return onevalue(v61);
}



/* Code for wusort */

static Lisp_Object CC_wusort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wusort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */
    v94 = v41;
    v41 = elt(env, 1); /* wulessp!* */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v94, v41);
    }
}



/* Code for cl_sacat */

static Lisp_Object MS_CDECL CC_cl_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v45,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v48, v190;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sacat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v28;
    v48 = v45;
    v190 = v0;
/* end of prologue */
    v13 = v190;
    if (equal(v13, v48)) goto v11;
    v13 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v13);

v11:
    v13 = elt(env, 1); /* keep */
    return onevalue(v13);
}



/* Code for ibalp_renewwl */

static Lisp_Object CC_ibalp_renewwl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v258;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_renewwl");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v150 = v0;
/* end of prologue */
    stack[-2] = v150;
    goto v10;

v10:
    v150 = stack[-2];
    if (v150 == nil) goto v55;
    v150 = stack[-2];
    v150 = qcar(v150);
    stack[-1] = v150;
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    if (!(v150 == nil)) goto v48;
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v258 = Llength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v150 = (Lisp_Object)17; /* 1 */
    v150 = Leqn(nil, v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    if (v150 == nil) goto v222;
    v150 = stack[-1];
    v150 = qcar(v150);
    stack[0] = Llength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = Llength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v258 = plus2(stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v150 = (Lisp_Object)17; /* 1 */
    v150 = (Lisp_Object)greaterp2(v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    v150 = v150 ? lisp_true : nil;
    env = stack[-4];
    if (v150 == nil) goto v222;
    v150 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    stack[-3] = v150;
    v150 = stack[-3];
    if (v150 == nil) goto v48;
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    stack[0] = qcdr(v150);
    v258 = stack[-3];
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = cons(v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    stack[0] = qcdr(v150);
    v258 = stack[-1];
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = cons(v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    goto v48;

v48:
    v150 = stack[-2];
    v150 = qcdr(v150);
    stack[-2] = v150;
    goto v10;

v222:
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    if (v150 == nil) goto v124;
    v150 = qvalue(elt(env, 1)); /* nil */
    goto v260;

v260:
    if (v150 == nil) goto v48;
    v150 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    stack[-3] = v150;
    v150 = stack[-3];
    if (v150 == nil) goto v205;
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    stack[0] = qcdr(v150);
    v258 = stack[-3];
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = cons(v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    stack[0] = qcdr(v150);
    v258 = stack[-1];
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = cons(v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    goto v205;

v205:
    v150 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    stack[-3] = v150;
    v150 = stack[-3];
    if (v150 == nil) goto v48;
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    stack[0] = qcdr(v150);
    v258 = stack[-3];
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = cons(v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    stack[0] = qcdr(v150);
    v258 = stack[-1];
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = cons(v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    goto v48;

v124:
    v150 = stack[-1];
    v150 = qcar(v150);
    stack[0] = Llength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v150 = stack[-1];
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = Llength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v258 = plus2(stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-4];
    v150 = (Lisp_Object)17; /* 1 */
    v150 = (Lisp_Object)greaterp2(v258, v150);
    nil = C_nil;
    if (exception_pending()) goto v259;
    v150 = v150 ? lisp_true : nil;
    env = stack[-4];
    goto v260;

v55:
    v150 = nil;
    { popv(5); return onevalue(v150); }
/* error exit handlers */
v259:
    popv(5);
    return nil;
}



/* Code for ratpoly_deg */

static Lisp_Object CC_ratpoly_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v33 = v45;
    stack[0] = v0;
/* end of prologue */
    v30 = stack[0];
    fn = elt(env, 1); /* ratpoly_mvartest */
    v33 = (*qfn2(fn))(qenv(fn), v30, v33);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    if (v33 == nil) goto v11;
    v33 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_ldeg */
        return (*qfn1(fn))(qenv(fn), v33);
    }

v11:
    v33 = stack[0];
    fn = elt(env, 3); /* ratpoly_nullp */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v42;
    if (v33 == nil) goto v188;
    v33 = (Lisp_Object)-15; /* -1 */
    { popv(2); return onevalue(v33); }

v188:
    v33 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v33); }
/* error exit handlers */
v42:
    popv(2);
    return nil;
}



/* Code for vintersection */

static Lisp_Object CC_vintersection(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v212;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vintersection");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v0;
/* end of prologue */

v228:
    v185 = stack[-1];
    if (v185 == nil) goto v10;
    v185 = stack[-1];
    v185 = qcar(v185);
    v212 = qcar(v185);
    v185 = stack[0];
    v185 = Lassoc(nil, v212, v185);
    stack[-2] = v185;
    if (v185 == nil) goto v33;
    v185 = stack[-1];
    v185 = qcar(v185);
    v212 = qcdr(v185);
    v185 = stack[-2];
    v185 = qcdr(v185);
    v185 = (Lisp_Object)greaterp2(v212, v185);
    nil = C_nil;
    if (exception_pending()) goto v200;
    v185 = v185 ? lisp_true : nil;
    env = stack[-3];
    if (v185 == nil) goto v261;
    v185 = stack[-2];
    v212 = qcdr(v185);
    v185 = (Lisp_Object)1; /* 0 */
    if (v212 == v185) goto v27;
    v185 = stack[-1];
    v212 = qcdr(v185);
    v185 = stack[0];
    v185 = CC_vintersection(env, v212, v185);
    nil = C_nil;
    if (exception_pending()) goto v200;
    {
        Lisp_Object v128 = stack[-2];
        popv(4);
        return cons(v128, v185);
    }

v27:
    v185 = stack[-1];
    v212 = qcdr(v185);
    v185 = stack[0];
    stack[-1] = v212;
    stack[0] = v185;
    goto v228;

v261:
    v185 = stack[-1];
    v185 = qcar(v185);
    v212 = qcdr(v185);
    v185 = (Lisp_Object)1; /* 0 */
    if (v212 == v185) goto v182;
    v185 = stack[-1];
    stack[-2] = qcar(v185);
    v185 = stack[-1];
    v212 = qcdr(v185);
    v185 = stack[0];
    v185 = CC_vintersection(env, v212, v185);
    nil = C_nil;
    if (exception_pending()) goto v200;
    {
        Lisp_Object v262 = stack[-2];
        popv(4);
        return cons(v262, v185);
    }

v182:
    v185 = stack[-1];
    v212 = qcdr(v185);
    v185 = stack[0];
    stack[-1] = v212;
    stack[0] = v185;
    goto v228;

v33:
    v185 = stack[-1];
    v212 = qcdr(v185);
    v185 = stack[0];
    stack[-1] = v212;
    stack[0] = v185;
    goto v228;

v10:
    v185 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v185); }
/* error exit handlers */
v200:
    popv(4);
    return nil;
}



/* Code for row */

static Lisp_Object CC_row(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for row");
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
    v22 = stack[0];
    if (v22 == nil) goto v61;
    v22 = stack[0];
    v22 = qcar(v22);
    fn = elt(env, 2); /* expression */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v22 = stack[0];
    v22 = qcdr(v22);
    v22 = CC_row(env, v22);
    nil = C_nil;
    if (exception_pending()) goto v17;
    goto v61;

v61:
    v22 = nil;
    { popv(2); return onevalue(v22); }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for subs4q */

static Lisp_Object CC_subs4q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v78, v254;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs4q");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v78 = elt(env, 1); /* slash */
    v77 = elt(env, 2); /* opmtch */
    v77 = get(v78, v77);
    env = stack[-7];
    stack[-6] = v77;
    if (v77 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v77 = stack[-5];
    v77 = qcar(v77);
    if (v77 == nil) goto v58;
    v78 = stack[-5];
    v77 = elt(env, 3); /* prepf */
    fn = elt(env, 8); /* sqform */
    v77 = (*qfn2(fn))(qenv(fn), v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    goto v188;

v188:
    stack[-4] = v77;
    v78 = elt(env, 1); /* slash */
    v77 = elt(env, 2); /* opmtch */
    v77 = Lremprop(nil, v78, v77);
    env = stack[-7];
    v254 = elt(env, 4); /* slash!* */
    v78 = elt(env, 2); /* opmtch */
    v77 = stack[-6];
    v77 = Lputprop(nil, 3, v254, v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    goto v27;

v27:
    v77 = stack[-4];
    if (v77 == nil) goto v25;
    v78 = stack[-4];
    stack[-3] = v78;
    v77 = elt(env, 5); /* quotient */
    if (!consp(v78)) goto v25;
    v78 = qcar(v78);
    if (!(v78 == v77)) goto v25;
    v78 = elt(env, 4); /* slash!* */
    v77 = stack[-4];
    v77 = qcdr(v77);
    v77 = cons(v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    fn = elt(env, 2); /* opmtch */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    if (!(v77 == nil)) goto v243;
    v78 = elt(env, 7); /* minus */
    v77 = stack[-4];
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcar(v77);
    v77 = Lsmemq(nil, v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    if (v77 == nil) goto v239;
    stack[-1] = elt(env, 4); /* slash!* */
    v78 = elt(env, 7); /* minus */
    v77 = stack[-4];
    v77 = qcdr(v77);
    v77 = qcar(v77);
    v77 = list2(v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    fn = elt(env, 9); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v78 = elt(env, 7); /* minus */
    v77 = stack[-4];
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcar(v77);
    v77 = list2(v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    fn = elt(env, 9); /* reval */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v77 = list3(stack[-1], stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    fn = elt(env, 2); /* opmtch */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    goto v243;

v243:
    stack[-4] = v77;
    v77 = stack[-2];
    if (!(v77 == nil)) goto v210;
    v77 = stack[-4];
    goto v210;

v210:
    stack[-2] = v77;
    goto v27;

v239:
    v77 = qvalue(elt(env, 6)); /* nil */
    goto v243;

v25:
    v77 = stack[-2];
    if (v77 == nil) goto v82;
    v77 = stack[-3];
    fn = elt(env, 10); /* simp!* */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    goto v260;

v260:
    stack[-5] = v77;
    v254 = elt(env, 1); /* slash */
    v78 = elt(env, 2); /* opmtch */
    v77 = stack[-6];
    v77 = Lputprop(nil, 3, v254, v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v117;
    { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v82:
    v77 = stack[-5];
    goto v260;

v58:
    v77 = (Lisp_Object)1; /* 0 */
    goto v188;
/* error exit handlers */
v117:
    popv(8);
    return nil;
}



/* Code for nextcomb */

static Lisp_Object CC_nextcomb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v266, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextcomb");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    v123 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v266 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v266; /* i */
    v266 = v123;
    v266 = qcar(v266);
    stack[-3] = v266;
    v266 = v123;
    v266 = qcdr(v266);
    stack[-1] = v266;
    v123 = stack[0];
    v266 = (Lisp_Object)1; /* 0 */
    if (v123 == v266) goto v22;
    v266 = stack[-3];
    v123 = Llength(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v266 = stack[0];
    v123 = difference2(v123, v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    qvalue(elt(env, 1)) = v123; /* i */
    v266 = (Lisp_Object)1; /* 0 */
    v266 = (Lisp_Object)lessp2(v123, v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    v266 = v266 ? lisp_true : nil;
    env = stack[-4];
    if (v266 == nil) goto v18;
    v266 = qvalue(elt(env, 2)); /* nil */
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v10;

v10:
    qvalue(elt(env, 1)) = stack[-2]; /* i */
    { popv(5); return onevalue(v266); }

v18:
    v123 = qvalue(elt(env, 1)); /* i */
    v266 = (Lisp_Object)1; /* 0 */
    if (v123 == v266) goto v52;
    v266 = stack[-1];
    if (v266 == nil) goto v225;
    v266 = stack[0];
    v266 = sub1(v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v266 = CC_nextcomb(env, stack[-1], v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v123 = stack[-3];
    stack[-1] = qcar(v123);
    v123 = v266;
    stack[0] = qcar(v123);
    v123 = v266;
    v123 = qcdr(v123);
    if (v123 == nil) goto v182;
    v123 = stack[-3];
    v266 = qcdr(v266);
    v266 = cons(v123, v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v235;

v235:
    v266 = acons(stack[-1], stack[0], v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v10;

v182:
    v266 = stack[-3];
    v266 = qcdr(v266);
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v235;

v225:
    v266 = stack[-3];
    v266 = qcdr(v266);
    fn = elt(env, 3); /* initcomb */
    stack[-1] = (*qfn1(fn))(qenv(fn), v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v266 = stack[0];
    v266 = sub1(v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v266 = CC_nextcomb(env, stack[-1], v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v123 = stack[-3];
    stack[-1] = qcar(v123);
    v123 = v266;
    stack[0] = qcar(v123);
    v123 = v266;
    v123 = qcdr(v123);
    if (v123 == nil) goto v211;
    v123 = stack[-3];
    v266 = qcdr(v266);
    v266 = cons(v123, v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v186;

v186:
    v266 = acons(stack[-1], stack[0], v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v10;

v211:
    v266 = stack[-3];
    v266 = qcdr(v266);
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v186;

v52:
    v266 = stack[-3];
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v10;

v22:
    v266 = qvalue(elt(env, 2)); /* nil */
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v10;
/* error exit handlers */
v180:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-2]; /* i */
    popv(5);
    return nil;
}



/* Code for bfplusn */

static Lisp_Object CC_bfplusn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v43, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfplusn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v45;
    v42 = v0;
/* end of prologue */
    v30 = v42;
    if (!consp(v30)) goto v95;
    v30 = v42;
    {
        fn = elt(env, 1); /* plus!: */
        return (*qfn2(fn))(qenv(fn), v30, v43);
    }

v95:
    v30 = v42;
    return plus2(v30, v43);
}



/* Code for indordp */

static Lisp_Object CC_indordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v230, v267, v226, v89;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v226 = v45;
    v89 = v0;
/* end of prologue */
    v229 = qvalue(elt(env, 1)); /* indxl!* */
    v267 = v229;
    v230 = v89;
    v229 = v267;
    v229 = Lmemq(nil, v230, v229);
    if (!(v229 == nil)) goto v11;
    v229 = qvalue(elt(env, 2)); /* t */
    return onevalue(v229);

v11:
    v229 = v267;
    if (v229 == nil) goto v43;
    v230 = v89;
    v229 = v267;
    v229 = qcar(v229);
    if (v230 == v229) goto v34;
    v230 = v226;
    v229 = v267;
    v229 = qcar(v229);
    if (v230 == v229) goto v52;
    v229 = v267;
    v229 = qcdr(v229);
    v267 = v229;
    goto v11;

v52:
    v229 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v229);

v34:
    v229 = qvalue(elt(env, 2)); /* t */
    return onevalue(v229);

v43:
    v229 = v89;
    v230 = v226;
        return Lorderp(nil, v229, v230);
}



/* Code for assert_stat!-parse */

static Lisp_Object MS_CDECL CC_assert_statKparse(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v186, v256;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_stat-parse");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_stat-parse");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    fn = elt(env, 11); /* scan */
    v242 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    stack[-2] = v242;
    fn = elt(env, 11); /* scan */
    v186 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    v242 = elt(env, 1); /* !*colon!* */
    if (v186 == v242) goto v10;
    v242 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v242 == nil)) goto v190;
    v186 = elt(env, 3); /* "expecting ':' in assert but found" */
    v242 = qvalue(elt(env, 4)); /* cursym!* */
    v242 = list2(v186, v242);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    fn = elt(env, 12); /* lprie */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    goto v190;

v190:
    v242 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    goto v10;

v10:
    fn = elt(env, 13); /* assert_stat1 */
    v242 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    stack[-1] = v242;
    fn = elt(env, 11); /* scan */
    v186 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    v242 = elt(env, 5); /* difference */
    if (v186 == v242) goto v24;
    v242 = qvalue(elt(env, 6)); /* t */
    goto v217;

v217:
    if (v242 == nil) goto v51;
    v242 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v242 == nil)) goto v97;
    v186 = elt(env, 8); /* "expecting '->' in assert but found" */
    v242 = qvalue(elt(env, 4)); /* cursym!* */
    v242 = list2(v186, v242);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    fn = elt(env, 12); /* lprie */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    goto v97;

v97:
    v242 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    goto v51;

v51:
    fn = elt(env, 11); /* scan */
    v242 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    stack[0] = v242;
    fn = elt(env, 11); /* scan */
    v186 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    v242 = elt(env, 9); /* delim */
    v242 = Lflagp(nil, v186, v242);
    env = stack[-3];
    if (!(v242 == nil)) goto v233;
    v242 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v242 == nil)) goto v181;
    v186 = elt(env, 10); /* "expecting end of assert but found" */
    v242 = qvalue(elt(env, 4)); /* cursym!* */
    v242 = list2(v186, v242);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    fn = elt(env, 12); /* lprie */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    goto v181;

v181:
    v242 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    goto v233;

v233:
    v256 = stack[-2];
    v186 = stack[-1];
    v242 = stack[0];
    popv(4);
    return list3(v256, v186, v242);

v24:
    fn = elt(env, 11); /* scan */
    v186 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    v242 = elt(env, 7); /* greaterp */
    v242 = Lneq(nil, v186, v242);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    goto v217;
/* error exit handlers */
v100:
    popv(4);
    return nil;
}



/* Code for mo_times_ei */

static Lisp_Object CC_mo_times_ei(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_times_ei");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v56 = v45;
    v6 = v0;
/* end of prologue */
    v5 = v56;
    v5 = qcar(v5);
    if (v5 == nil) goto v61;
    v5 = v56;
    v5 = qcar(v5);
    v5 = qcar(v5);
    v5 = (Lisp_Object)(int32_t)((int32_t)v6 + (int32_t)v5 - TAG_FIXNUM);
    v6 = v56;
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v5 = cons(v5, v6);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    goto v50;

v50:
    stack[0] = v5;
    fn = elt(env, 1); /* mo!=deglist */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v32;
    {
        Lisp_Object v52 = stack[0];
        popv(2);
        return cons(v52, v5);
    }

v61:
    v5 = v6;
    v5 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    goto v50;
/* error exit handlers */
v32:
    popv(2);
    return nil;
}



/* Code for quotof */

static Lisp_Object CC_quotof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v279, v159, v280;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotof");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v45;
    stack[-3] = v0;
/* end of prologue */
    v279 = stack[-3];
    if (v279 == nil) goto v61;
    v159 = stack[-3];
    v279 = stack[-2];
    if (equal(v159, v279)) goto v95;
    v159 = stack[-2];
    v279 = (Lisp_Object)17; /* 1 */
    if (v159 == v279) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v279 = stack[-2];
    if (!consp(v279)) goto v49;
    v279 = stack[-2];
    v279 = qcar(v279);
    v279 = (consp(v279) ? nil : lisp_true);
    goto v222;

v222:
    if (v279 == nil) goto v47;
    v159 = stack[-3];
    v279 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* quotofd */
        return (*qfn2(fn))(qenv(fn), v159, v279);
    }

v47:
    v279 = stack[-3];
    if (!consp(v279)) goto v3;
    v279 = stack[-3];
    v279 = qcar(v279);
    v279 = (consp(v279) ? nil : lisp_true);
    goto v138;

v138:
    if (v279 == nil) goto v241;
    v279 = stack[-2];
    v279 = qcar(v279);
    v279 = qcar(v279);
    v279 = qcdr(v279);
    stack[-1] = v279;
    v279 = stack[-2];
    v279 = qcar(v279);
    v279 = qcar(v279);
    v279 = qcar(v279);
    fn = elt(env, 6); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = stack[-1];
    if (is_number(v279)) goto v7;
    v159 = elt(env, 3); /* minus */
    v279 = stack[-1];
    v279 = list2(v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    goto v137;

v137:
    fn = elt(env, 7); /* getpower */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    stack[-1] = stack[-3];
    v159 = stack[-2];
    v279 = elt(env, 4); /* lcx */
    fn = elt(env, 8); /* carx */
    v279 = (*qfn2(fn))(qenv(fn), v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = qcdr(v279);
    v279 = CC_quotof(env, stack[-1], v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = cons(stack[0], v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    popv(6);
    return ncons(v279);

v7:
    v279 = stack[-1];
    v279 = negate(v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    goto v137;

v241:
    v279 = stack[-3];
    v279 = qcar(v279);
    v159 = qcar(v279);
    v279 = stack[-2];
    v279 = qcar(v279);
    v279 = qcar(v279);
    stack[0] = v159;
    stack[-4] = v279;
    v279 = stack[0];
    v159 = qcar(v279);
    v279 = stack[-4];
    v279 = qcar(v279);
    if (v159 == v279) goto v122;
    v279 = stack[0];
    v159 = qcar(v279);
    v279 = stack[-4];
    v279 = qcar(v279);
    fn = elt(env, 9); /* ordop */
    v279 = (*qfn2(fn))(qenv(fn), v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    if (v279 == nil) goto v91;
    stack[-1] = stack[0];
    v279 = stack[-3];
    v279 = qcar(v279);
    v159 = qcdr(v279);
    v279 = stack[-2];
    stack[0] = CC_quotof(env, v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = stack[-3];
    v159 = qcdr(v279);
    v279 = stack[-2];
    v279 = CC_quotof(env, v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    {
        Lisp_Object v282 = stack[-1];
        Lisp_Object v246 = stack[0];
        popv(6);
        return acons(v282, v246, v279);
    }

v91:
    v279 = stack[-4];
    v279 = qcar(v279);
    fn = elt(env, 6); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = stack[-4];
    v279 = qcdr(v279);
    v279 = negate(v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    fn = elt(env, 7); /* getpower */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    stack[-1] = stack[-3];
    v159 = stack[-2];
    v279 = elt(env, 4); /* lcx */
    fn = elt(env, 8); /* carx */
    v279 = (*qfn2(fn))(qenv(fn), v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = qcdr(v279);
    v279 = CC_quotof(env, stack[-1], v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = cons(stack[0], v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    popv(6);
    return ncons(v279);

v122:
    v279 = stack[0];
    v159 = qcdr(v279);
    v279 = stack[-4];
    v279 = qcdr(v279);
    stack[-1] = difference2(v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = stack[-3];
    v279 = qcar(v279);
    stack[0] = qcdr(v279);
    v159 = stack[-2];
    v279 = elt(env, 4); /* lcx */
    fn = elt(env, 8); /* carx */
    v279 = (*qfn2(fn))(qenv(fn), v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = qcdr(v279);
    stack[0] = CC_quotof(env, stack[0], v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v279 = stack[-3];
    v159 = qcdr(v279);
    v279 = stack[-2];
    v279 = CC_quotof(env, v159, v279);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-5];
    v280 = stack[-1];
    stack[-1] = stack[0];
    stack[0] = v279;
    v159 = v280;
    v279 = (Lisp_Object)1; /* 0 */
    if (v159 == v279) goto v120;
    v279 = stack[-4];
    v279 = qcar(v279);
    v159 = v280;
    v280 = cons(v279, v159);
    nil = C_nil;
    if (exception_pending()) goto v281;
    v159 = stack[-1];
    v279 = stack[0];
    popv(6);
    return acons(v280, v159, v279);

v120:
    v159 = stack[-1];
    v279 = stack[0];
    {
        popv(6);
        fn = elt(env, 10); /* raddf */
        return (*qfn2(fn))(qenv(fn), v159, v279);
    }

v3:
    v279 = qvalue(elt(env, 2)); /* t */
    goto v138;

v49:
    v279 = qvalue(elt(env, 2)); /* t */
    goto v222;

v95:
    v279 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v279); }

v61:
    v279 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v279); }
/* error exit handlers */
v281:
    popv(6);
    return nil;
}



/* Code for cons_ordp */

static Lisp_Object MS_CDECL CC_cons_ordp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v45,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40, v264, v234, v44;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cons_ordp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cons_ordp");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v45,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v40 = v28;
    v264 = v45;
    v234 = v0;
/* end of prologue */

v11:
    v39 = v234;
    if (v39 == nil) goto v95;
    v39 = v264;
    if (v39 == nil) goto v57;
    v39 = v234;
    v39 = Lconsp(nil, v39);
    env = stack[0];
    if (v39 == nil) goto v17;
    v39 = v264;
    v39 = Lconsp(nil, v39);
    env = stack[0];
    if (v39 == nil) goto v19;
    v39 = v234;
    v44 = qcar(v39);
    v39 = v264;
    v39 = qcar(v39);
    if (equal(v44, v39)) goto v46;
    v39 = v234;
    v39 = qcar(v39);
    v234 = v39;
    v39 = v264;
    v39 = qcar(v39);
    v264 = v39;
    goto v11;

v46:
    v39 = v234;
    v39 = qcdr(v39);
    v234 = v39;
    v39 = v264;
    v39 = qcdr(v39);
    v264 = v39;
    goto v11;

v19:
    v39 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v39); }

v17:
    v39 = v264;
    v39 = Lconsp(nil, v39);
    env = stack[0];
    if (v39 == nil) goto v230;
    v39 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v39); }

v230:
    v39 = v40;
    v40 = v234;
        popv(1);
        return Lapply2(nil, 3, v39, v40, v264);

v57:
    v39 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v39); }

v95:
    v39 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v39); }
}



/* Code for sqhorner!* */

static Lisp_Object CC_sqhornerH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqhorner*");
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
    v49 = qvalue(elt(env, 1)); /* !*horner */
    if (v49 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v50 = qvalue(elt(env, 2)); /* ordl!* */
    v49 = qvalue(elt(env, 3)); /* kord!* */
    v49 = Lappend(nil, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    stack[-2] = qvalue(elt(env, 3)); /* kord!* */
    qvalue(elt(env, 3)) = v49; /* kord!* */
    v49 = stack[-1];
    v49 = qcar(v49);
    fn = elt(env, 4); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v49 = stack[-1];
    v49 = qcdr(v49);
    fn = elt(env, 4); /* reorder */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    fn = elt(env, 5); /* hornerf */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v49 = cons(stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    fn = elt(env, 6); /* hornersq */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* kord!* */
    { popv(4); return onevalue(v49); }
/* error exit handlers */
v21:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* kord!* */
    popv(4);
    return nil;
v20:
    popv(4);
    return nil;
}



/* Code for sq2sspl */

static Lisp_Object CC_sq2sspl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sspl");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v55;

v55:
    v230 = stack[-1];
    if (!consp(v230)) goto v22;
    v230 = stack[-1];
    v230 = qcar(v230);
    v230 = (consp(v230) ? nil : lisp_true);
    goto v36;

v36:
    if (v230 == nil) goto v222;
    v230 = stack[-1];
    v267 = v230;
    goto v95;

v95:
    v230 = stack[-2];
    if (v230 == nil) { popv(4); return onevalue(v267); }
    v230 = stack[-2];
    v230 = qcar(v230);
    v230 = Lappend(nil, v230, v267);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    v267 = v230;
    v230 = stack[-2];
    v230 = qcdr(v230);
    stack[-2] = v230;
    goto v95;

v222:
    v230 = stack[-1];
    v267 = qcar(v230);
    v230 = stack[0];
    fn = elt(env, 2); /* sq2sstm */
    v267 = (*qfn2(fn))(qenv(fn), v267, v230);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    v230 = stack[-2];
    v230 = cons(v267, v230);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[-2] = v230;
    v230 = stack[-1];
    v230 = qcdr(v230);
    stack[-1] = v230;
    goto v55;

v22:
    v230 = qvalue(elt(env, 1)); /* t */
    goto v36;
/* error exit handlers */
v96:
    popv(4);
    return nil;
}



/* Code for ibalp_tvb */

static Lisp_Object CC_ibalp_tvb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_tvb");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v45;
    v26 = v0;
/* end of prologue */
    stack[-2] = v26;
    goto v11;

v11:
    v26 = stack[-2];
    if (v26 == nil) goto v41;
    v26 = stack[-2];
    v26 = qcar(v26);
    stack[0] = v26;
    v26 = stack[0];
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v14 = qcar(v26);
    v26 = stack[-1];
    v26 = (Lisp_Object)geq2(v14, v26);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v26 = v26 ? lisp_true : nil;
    env = stack[-3];
    if (v26 == nil) goto v17;
    v26 = stack[0];
    v14 = qcdr(v26);
    v26 = stack[0];
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v26 = qcar(v26);
    fn = elt(env, 2); /* ibalp_var!-unset */
    v26 = (*qfn2(fn))(qenv(fn), v14, v26);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    goto v17;

v17:
    v26 = stack[-2];
    v26 = qcdr(v26);
    stack[-2] = v26;
    goto v11;

v41:
    v26 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v26); }
/* error exit handlers */
v90:
    popv(4);
    return nil;
}



/* Code for unaryrd */

static Lisp_Object MS_CDECL CC_unaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "unaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unaryrd");
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
    fn = elt(env, 1); /* mathml */
    v10 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    stack[0] = v10;
    fn = elt(env, 2); /* lex */
    v10 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v10 = stack[0];
    popv(2);
    return ncons(v10);
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for diffsq */

static Lisp_Object CC_diffsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v45;
    stack[-2] = v0;
/* end of prologue */
    v230 = stack[-2];
    v267 = qcar(v230);
    v230 = stack[-1];
    fn = elt(env, 1); /* difff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v267, v230);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    stack[0] = stack[-2];
    v230 = stack[-2];
    v267 = qcdr(v230);
    v230 = stack[-1];
    fn = elt(env, 1); /* difff */
    v230 = (*qfn2(fn))(qenv(fn), v267, v230);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    v230 = (*qfn2(fn))(qenv(fn), stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    stack[0] = v230;
    v230 = stack[0];
    v230 = qcar(v230);
    fn = elt(env, 3); /* negf */
    v267 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    v230 = stack[0];
    v230 = qcdr(v230);
    v230 = cons(v267, v230);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v230);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    v267 = (Lisp_Object)17; /* 1 */
    v230 = stack[-2];
    v230 = qcdr(v230);
    v230 = cons(v267, v230);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    {
        Lisp_Object v37 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v37, v230);
    }
/* error exit handlers */
v215:
    popv(5);
    return nil;
}



/* Code for dm!-mkfloat */

static Lisp_Object CC_dmKmkfloat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v43, v42;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-mkfloat");
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
    v43 = v0;
/* end of prologue */
    v30 = v43;
    v30 = Lintegerp(nil, v30);
    env = stack[0];
    if (v30 == nil) { popv(1); return onevalue(v43); }
    v42 = elt(env, 1); /* !:rd!: */
    v30 = elt(env, 2); /* i2d */
    v30 = get(v42, v30);
        popv(1);
        return Lapply1(nil, v30, v43);
}



/* Code for vdpvevlcomp */

static Lisp_Object CC_vdpvevlcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpvevlcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v45;
    v48 = v0;
/* end of prologue */
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    v48 = qcar(v48);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcar(v13);
    {
        fn = elt(env, 1); /* dipevlcomp */
        return (*qfn2(fn))(qenv(fn), v48, v13);
    }
}



/* Code for vevstrictlydivides!? */

static Lisp_Object CC_vevstrictlydividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v30, v43, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevstrictlydivides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v45;
    v42 = v0;
/* end of prologue */
    v30 = v42;
    v33 = v43;
    if (equal(v30, v33)) goto v188;
    v33 = v43;
    v30 = v42;
    {
        fn = elt(env, 2); /* vevmtest!? */
        return (*qfn2(fn))(qenv(fn), v33, v30);
    }

v188:
    v33 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v33);
}



/* Code for wedgek2 */

static Lisp_Object MS_CDECL CC_wedgek2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v45,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v249, v274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wedgek2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgek2");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v45,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v28;
    stack[-3] = v45;
    stack[-4] = v0;
/* end of prologue */

v36:
    v249 = stack[-4];
    v248 = stack[-3];
    v248 = qcar(v248);
    if (v249 == v248) goto v54;
    v248 = qvalue(elt(env, 2)); /* nil */
    goto v148;

v148:
    if (v248 == nil) goto v235;
    v248 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v249 = v248;
    v248 = v249;
    v248 = integerp(v248);
    if (v248 == nil) goto v56;
    v248 = v249;
    v248 = Loddp(nil, v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    goto v6;

v6:
    if (v248 == nil) goto v89;
    v248 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v248); }

v89:
    v249 = stack[-4];
    v248 = stack[-3];
    v248 = cons(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v248 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    {
        Lisp_Object v110 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v110, v248);
    }

v56:
    v248 = qvalue(elt(env, 2)); /* nil */
    goto v6;

v235:
    v248 = stack[-3];
    v249 = qcar(v248);
    v248 = elt(env, 1); /* wedge */
    if (!consp(v249)) goto v257;
    v249 = qcar(v249);
    if (!(v249 == v248)) goto v257;
    v248 = stack[-3];
    v248 = qcar(v248);
    v248 = qcdr(v248);
    stack[-3] = v248;
    goto v36;

v257:
    v249 = stack[-4];
    v248 = elt(env, 1); /* wedge */
    if (!consp(v249)) goto v238;
    v249 = qcar(v249);
    if (!(v249 == v248)) goto v238;
    v248 = stack[-4];
    v249 = qcdr(v248);
    v248 = stack[-3];
    fn = elt(env, 7); /* wedgewedge */
    stack[0] = (*qfn2(fn))(qenv(fn), v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v248 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    {
        Lisp_Object v272 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v272, v248);
    }

v238:
    v249 = stack[-4];
    v248 = stack[-3];
    v248 = qcar(v248);
    fn = elt(env, 8); /* worderp */
    v248 = (*qfn2(fn))(qenv(fn), v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    if (v248 == nil) goto v132;
    v249 = stack[-4];
    v248 = stack[-3];
    v248 = cons(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v248 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    {
        Lisp_Object v166 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v166, v248);
    }

v132:
    v248 = stack[-3];
    v248 = qcdr(v248);
    if (v248 == nil) goto v287;
    v248 = stack[-3];
    v274 = qcar(v248);
    v249 = (Lisp_Object)17; /* 1 */
    v248 = (Lisp_Object)17; /* 1 */
    v248 = list2star(v274, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    stack[-5] = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    stack[-1] = stack[-4];
    v248 = stack[-3];
    stack[0] = qcdr(v248);
    v248 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-4] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v248 = stack[-3];
    v248 = qcar(v248);
    fn = elt(env, 3); /* deg!*form */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v248 = (*qfn2(fn))(qenv(fn), stack[-4], v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v248 = (*qfn2(fn))(qenv(fn), stack[-2], v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v248 = CC_wedgek2(env, 3, stack[-1], stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    {
        Lisp_Object v167 = stack[-5];
        popv(7);
        fn = elt(env, 11); /* wedgepf2 */
        return (*qfn2(fn))(qenv(fn), v167, v248);
    }

v287:
    v248 = stack[-3];
    v249 = qcar(v248);
    v248 = stack[-4];
    v248 = list2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    stack[-1] = stack[-2];
    v248 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-2] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v248 = stack[-3];
    v248 = qcar(v248);
    fn = elt(env, 3); /* deg!*form */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v248 = (*qfn2(fn))(qenv(fn), stack[-2], v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v248 = (*qfn2(fn))(qenv(fn), stack[-1], v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 5); /* mksgnsq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    {
        Lisp_Object v288 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v288, v248);
    }

v54:
    v249 = stack[-4];
    v248 = elt(env, 1); /* wedge */
    v248 = Leqcar(nil, v249, v248);
    env = stack[-6];
    v248 = (v248 == nil ? lisp_true : nil);
    goto v148;
/* error exit handlers */
v109:
    popv(7);
    return nil;
}



/* Code for physopordchk */

static Lisp_Object CC_physopordchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v25, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopordchk");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    v15 = v0;
/* end of prologue */
    fn = elt(env, 4); /* !*collectphysops */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-2];
    stack[-1] = v15;
    v15 = stack[0];
    fn = elt(env, 4); /* !*collectphysops */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-2];
    v27 = v15;
    v15 = stack[-1];
    if (v15 == nil) goto v17;
    v15 = v27;
    if (v15 == nil) goto v188;
    v25 = elt(env, 3); /* unit */
    v15 = stack[-1];
    v15 = Lmember(nil, v25, v15);
    if (!(v15 == nil)) goto v30;
    v25 = elt(env, 3); /* unit */
    v15 = v27;
    v15 = Lmember(nil, v25, v15);
    if (!(v15 == nil)) goto v30;
    v15 = stack[-1];
    v25 = v27;
    {
        popv(3);
        fn = elt(env, 6); /* physopordchk!* */
        return (*qfn2(fn))(qenv(fn), v15, v25);
    }

v30:
    v15 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v15); }

v188:
    v15 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v15); }

v17:
    v15 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v15); }
/* error exit handlers */
v267:
    popv(3);
    return nil;
}



/* Code for edge_new_parent */

static Lisp_Object CC_edge_new_parent(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v217, v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edge_new_parent");
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
    push(nil);
/* copy arguments values to proper place */
    v217 = v0;
/* end of prologue */

v228:
    v216 = v217;
    if (v216 == nil) goto v4;
    v216 = v217;
    v5 = qcar(v216);
    v216 = qvalue(elt(env, 2)); /* new_edge_list */
    v216 = Lassoc(nil, v5, v216);
    v5 = v216;
    v216 = v5;
    if (v216 == nil) goto v35;
    stack[0] = v5;
    v216 = v217;
    v216 = qcdr(v216);
    v216 = CC_edge_new_parent(env, v216);
    nil = C_nil;
    if (exception_pending()) goto v56;
    {
        Lisp_Object v31 = stack[0];
        popv(1);
        return cons(v31, v216);
    }

v35:
    v216 = v217;
    v216 = qcdr(v216);
    v217 = v216;
    goto v228;

v4:
    v216 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v216); }
/* error exit handlers */
v56:
    popv(1);
    return nil;
}



/* Code for assert_install1 */

static Lisp_Object CC_assert_install1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_install1");
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
    v132 = stack[0];
    v131 = elt(env, 1); /* assert_installed */
    v131 = get(v132, v131);
    env = stack[-2];
    if (v131 == nil) goto v216;
    v131 = qvalue(elt(env, 2)); /* !*msg */
    if (v131 == nil) goto v22;
    stack[-1] = elt(env, 4); /* "***" */
    v132 = elt(env, 5); /* "assert already installed for" */
    v131 = stack[0];
    v131 = list2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    {
        Lisp_Object v242 = stack[-1];
        popv(3);
        fn = elt(env, 11); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v242, v131);
    }

v22:
    v131 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v131); }

v216:
    v131 = stack[0];
    fn = elt(env, 12); /* getd */
    v132 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    v131 = elt(env, 6); /* expr */
    if (!consp(v132)) goto v51;
    v132 = qcar(v132);
    if (!(v132 == v131)) goto v51;
    v132 = stack[0];
    v131 = elt(env, 8); /* assert_noassertfn */
    v132 = get(v132, v131);
    env = stack[-2];
    v131 = stack[0];
    fn = elt(env, 13); /* copyd */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    v237 = stack[0];
    v132 = stack[0];
    v131 = elt(env, 9); /* assert_assertfn */
    v131 = get(v132, v131);
    env = stack[-2];
    fn = elt(env, 13); /* copyd */
    v131 = (*qfn2(fn))(qenv(fn), v237, v131);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    v132 = stack[0];
    v131 = elt(env, 1); /* assert_installed */
    v237 = qvalue(elt(env, 10)); /* t */
        popv(3);
        return Lputprop(nil, 3, v132, v131, v237);

v51:
    v131 = qvalue(elt(env, 2)); /* !*msg */
    if (v131 == nil) goto v19;
    stack[-1] = elt(env, 4); /* "***" */
    v132 = stack[0];
    v131 = elt(env, 7); /* "is not an expr procedure - ignoring assert" 
*/
    v131 = list2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    {
        Lisp_Object v186 = stack[-1];
        popv(3);
        fn = elt(env, 11); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v186, v131);
    }

v19:
    v131 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v131); }
/* error exit handlers */
v241:
    popv(3);
    return nil;
}



/* Code for setk0 */

static Lisp_Object CC_setk0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v45)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v128, v262, v289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setk0");
#endif
    if (stack >= stacklimit)
    {
        push2(v45,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v45;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* frasc!* */
    qvalue(elt(env, 1)) = nil; /* frasc!* */
    v200 = stack[-1];
    fn = elt(env, 8); /* getrtype */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    stack[-3] = v200;
    if (v200 == nil) goto v41;
    v128 = stack[-3];
    v200 = elt(env, 2); /* setelemfn */
    v200 = get(v128, v200);
    env = stack[-4];
    if (v200 == nil) goto v41;
    v200 = qvalue(elt(env, 3)); /* nil */
    v200 = ncons(v200);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    qvalue(elt(env, 4)) = v200; /* alglist!* */
    v289 = stack[-2];
    v262 = stack[-1];
    v128 = qvalue(elt(env, 3)); /* nil */
    v200 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 9); /* let2 */
    v200 = (*qfnn(fn))(qenv(fn), 4, v289, v262, v128, v200);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    goto v10;

v10:
    v200 = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* frasc!* */
    { popv(5); return onevalue(v200); }

v41:
    v200 = stack[-2];
    if (!consp(v200)) goto v183;
    v200 = stack[-2];
    v200 = qcar(v200);
    if (symbolp(v200)) goto v138;
    v200 = qvalue(elt(env, 3)); /* nil */
    goto v5;

v5:
    if (v200 == nil) goto v132;
    v200 = qvalue(elt(env, 3)); /* nil */
    v200 = ncons(v200);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    qvalue(elt(env, 4)) = v200; /* alglist!* */
    v262 = stack[-3];
    v128 = stack[-2];
    v200 = stack[-1];
    v200 = Lapply2(nil, 3, v262, v128, v200);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    goto v10;

v132:
    v289 = stack[-2];
    v262 = stack[-1];
    v128 = qvalue(elt(env, 3)); /* nil */
    v200 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 9); /* let2 */
    v200 = (*qfnn(fn))(qenv(fn), 4, v289, v262, v128, v200);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    goto v10;

v138:
    v200 = stack[-2];
    fn = elt(env, 8); /* getrtype */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    if (!(v200 == nil)) goto v226;
    v200 = stack[-2];
    v128 = qcar(v200);
    v200 = elt(env, 6); /* rtype */
    v200 = get(v128, v200);
    env = stack[-4];
    goto v226;

v226:
    stack[-3] = v200;
    if (v200 == nil) goto v229;
    v128 = stack[-3];
    v200 = elt(env, 2); /* setelemfn */
    v200 = get(v128, v200);
    env = stack[-4];
    stack[-3] = v200;
    goto v27;

v27:
    if (!(v200 == nil)) goto v5;
    v200 = stack[-2];
    v128 = qcar(v200);
    v200 = elt(env, 7); /* setkfn */
    v200 = get(v128, v200);
    env = stack[-4];
    stack[-3] = v200;
    goto v5;

v229:
    v200 = qvalue(elt(env, 3)); /* nil */
    goto v27;

v183:
    v200 = qvalue(elt(env, 3)); /* nil */
    goto v5;
/* error exit handlers */
v84:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* frasc!* */
    popv(5);
    return nil;
}



setup_type const u18_setup[] =
{
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"pasf_varlat",             CC_pasf_varlat, too_many_1,    wrong_no_1},
    {"cl_qb",                   CC_cl_qb,       too_many_1,    wrong_no_1},
    {"reln",                    too_few_2,      CC_reln,       wrong_no_2},
    {"ps:expansion-point",      CC_psTexpansionKpoint,too_many_1,wrong_no_1},
    {"dm-min",                  too_few_2,      CC_dmKmin,     wrong_no_2},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"setdmode1",               too_few_2,      CC_setdmode1,  wrong_no_2},
    {"expvec2a",                CC_expvec2a,    too_many_1,    wrong_no_1},
    {"freeindexchk",            CC_freeindexchk,too_many_1,    wrong_no_1},
    {"partitexdf",              CC_partitexdf,  too_many_1,    wrong_no_1},
    {"fctargs",                 CC_fctargs,     too_many_1,    wrong_no_1},
    {"powers4",                 too_few_2,      CC_powers4,    wrong_no_2},
    {"assert_check1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_check1},
    {"splitlist:",              too_few_2,      CC_splitlistT, wrong_no_2},
    {"horner-rule-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKmodKp},
    {"drnconv",                 CC_drnconv,     too_many_1,    wrong_no_1},
    {"cl_identifyonoff",        CC_cl_identifyonoff,too_many_1,wrong_no_1},
    {"qqe_prepat",              CC_qqe_prepat,  too_many_1,    wrong_no_1},
    {"ibalp_negatet",           CC_ibalp_negatet,too_many_1,   wrong_no_1},
    {"makeset",                 CC_makeset,     too_many_1,    wrong_no_1},
    {"onoff",                   too_few_2,      CC_onoff,      wrong_no_2},
    {"indexvarordp",            too_few_2,      CC_indexvarordp,wrong_no_2},
    {"mkfortterpri",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkfortterpri},
    {"can_be_proved",           too_few_2,      CC_can_be_proved,wrong_no_2},
    {"assert_stat1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_stat1},
    {"no_dum_varp",             CC_no_dum_varp, too_many_1,    wrong_no_1},
    {"ratn",                    CC_ratn,        too_many_1,    wrong_no_1},
    {"cl_fvarl1",               CC_cl_fvarl1,   too_many_1,    wrong_no_1},
    {"wusort",                  CC_wusort,      too_many_1,    wrong_no_1},
    {"cl_sacat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_sacat},
    {"ibalp_renewwl",           CC_ibalp_renewwl,too_many_1,   wrong_no_1},
    {"ratpoly_deg",             too_few_2,      CC_ratpoly_deg,wrong_no_2},
    {"vintersection",           too_few_2,      CC_vintersection,wrong_no_2},
    {"row",                     CC_row,         too_many_1,    wrong_no_1},
    {"subs4q",                  CC_subs4q,      too_many_1,    wrong_no_1},
    {"nextcomb",                too_few_2,      CC_nextcomb,   wrong_no_2},
    {"bfplusn",                 too_few_2,      CC_bfplusn,    wrong_no_2},
    {"indordp",                 too_few_2,      CC_indordp,    wrong_no_2},
    {"assert_stat-parse",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_statKparse},
    {"mo_times_ei",             too_few_2,      CC_mo_times_ei,wrong_no_2},
    {"quotof",                  too_few_2,      CC_quotof,     wrong_no_2},
    {"cons_ordp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cons_ordp},
    {"sqhorner*",               CC_sqhornerH,   too_many_1,    wrong_no_1},
    {"sq2sspl",                 too_few_2,      CC_sq2sspl,    wrong_no_2},
    {"ibalp_tvb",               too_few_2,      CC_ibalp_tvb,  wrong_no_2},
    {"unaryrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_unaryrd},
    {"diffsq",                  too_few_2,      CC_diffsq,     wrong_no_2},
    {"dm-mkfloat",              CC_dmKmkfloat,  too_many_1,    wrong_no_1},
    {"vdpvevlcomp",             too_few_2,      CC_vdpvevlcomp,wrong_no_2},
    {"vevstrictlydivides?",     too_few_2,      CC_vevstrictlydividesW,wrong_no_2},
    {"wedgek2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_wedgek2},
    {"physopordchk",            too_few_2,      CC_physopordchk,wrong_no_2},
    {"edge_new_parent",         CC_edge_new_parent,too_many_1, wrong_no_1},
    {"assert_install1",         CC_assert_install1,too_many_1, wrong_no_1},
    {"setk0",                   too_few_2,      CC_setk0,      wrong_no_2},
    {NULL, (one_args *)"u18", (two_args *)"5100 396317 8162030", 0}
};

/* end of generated code */
