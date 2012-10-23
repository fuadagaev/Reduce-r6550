
/* $destdir\u06.c        Machine generated C code */

/* Signature: 00000000 23-Oct-2012 */

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
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
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
extern intptr_t modulus_is_large;
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
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space;
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
#define modulus_is_large      BASE[32]
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
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
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


/* Code for pv_add */

static Lisp_Object CC_pv_add(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020, v0021;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_add");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0019 = stack[-1];
    if (v0019 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0019 = stack[0];
    if (v0019 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v0022;

v0022:
    v0019 = stack[-1];
    if (!(v0019 == nil)) goto v0023;
    v0019 = stack[0];
    if (!(v0019 == nil)) goto v0023;
    v0019 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0019);

v0023:
    v0019 = stack[-1];
    if (v0019 == nil) goto v0024;
    v0019 = stack[0];
    if (v0019 == nil) goto v0024;
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0020 = qcdr(v0019);
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0019 = qcdr(v0019);
    if (!(equal(v0020, v0019))) goto v0024;
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0020 = qcar(v0019);
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    v0019 = plus2(v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    v0021 = v0019;
    v0020 = v0021;
    v0019 = (Lisp_Object)1; /* 0 */
    if (v0020 == v0019) goto v0026;
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0020 = qcdr(v0019);
    v0019 = stack[-2];
    v0019 = acons(v0021, v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    stack[-2] = v0019;
    goto v0026;

v0026:
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    stack[-1] = v0019;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    goto v0022;

v0024:
    v0019 = stack[-1];
    if (v0019 == nil) goto v0027;
    v0019 = stack[0];
    if (!(v0019 == nil)) goto v0027;

v0028:
    v0019 = stack[-1];
    v0020 = qcar(v0019);
    v0019 = stack[-2];
    v0019 = cons(v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    stack[-2] = v0019;
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    stack[-1] = v0019;
    goto v0022;

v0027:
    v0019 = stack[-1];
    if (v0019 == nil) goto v0029;
    v0019 = stack[0];
    if (v0019 == nil) goto v0029;
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0020 = qcdr(v0019);
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0019 = qcdr(v0019);
    v0019 = (Lisp_Object)greaterp2(v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    v0019 = v0019 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0019 == nil)) goto v0028;

v0029:
    v0019 = stack[0];
    v0020 = qcar(v0019);
    v0019 = stack[-2];
    v0019 = cons(v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    stack[-2] = v0019;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    goto v0022;
/* error exit handlers */
v0025:
    popv(4);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_kern");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0032 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v0032 = sub1(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    v0032 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0032/(16/CELL)));
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    { popv(1); return onevalue(v0032); }
/* error exit handlers */
v0012:
    popv(1);
    return nil;
}



/* Code for arzerop!: */

static Lisp_Object CC_arzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arzerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0000;
/* end of prologue */
    v0033 = qcdr(v0033);
    v0033 = (v0033 == nil ? lisp_true : nil);
    return onevalue(v0033);
}



/* Code for lto_catsoc */

static Lisp_Object CC_lto_catsoc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0036;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_catsoc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0001;
    v0036 = v0000;
/* end of prologue */
    v0035 = Latsoc(nil, v0036, v0035);
    v0036 = v0035;
    v0035 = v0036;
    if (v0035 == nil) goto v0004;
    v0035 = v0036;
    v0035 = qcdr(v0035);
    return onevalue(v0035);

v0004:
    v0035 = nil;
    return onevalue(v0035);
}



/* Code for frvarsof */

static Lisp_Object CC_frvarsof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0046, v0016, v0047;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for frvarsof");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0046 = v0001;
    v0016 = v0000;
/* end of prologue */

v0048:
    v0047 = v0016;
    v0045 = qvalue(elt(env, 1)); /* frlis!* */
    v0045 = Lmemq(nil, v0047, v0045);
    if (v0045 == nil) goto v0049;
    v0047 = v0016;
    v0045 = v0046;
    v0045 = Lmemq(nil, v0047, v0045);
    if (!(v0045 == nil)) { popv(2); return onevalue(v0046); }
    stack[0] = v0046;
    v0045 = v0016;
    v0045 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    {
        Lisp_Object v0051 = stack[0];
        popv(2);
        return Lappend(nil, v0051, v0045);
    }

v0049:
    v0045 = v0016;
    if (!consp(v0045)) { popv(2); return onevalue(v0046); }
    v0045 = v0016;
    v0045 = qcdr(v0045);
    stack[0] = v0045;
    v0045 = v0016;
    v0045 = qcar(v0045);
    v0045 = CC_frvarsof(env, v0045, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-1];
    v0046 = v0045;
    v0045 = stack[0];
    v0016 = v0045;
    goto v0048;
/* error exit handlers */
v0050:
    popv(2);
    return nil;
}



/* Code for subs3q */

static Lisp_Object CC_subs3q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0039, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3q");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0040 = qvalue(elt(env, 1)); /* mchfg!* */
    stack[-2] = v0040;
    v0040 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v0040; /* mchfg!* */
    v0040 = stack[-1];
    v0060 = qcar(v0040);
    v0039 = qvalue(elt(env, 3)); /* !*match */
    v0040 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 5); /* subs3f1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0060, v0039, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    v0040 = stack[-1];
    v0060 = qcdr(v0040);
    v0039 = qvalue(elt(env, 3)); /* !*match */
    v0040 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 5); /* subs3f1 */
    v0040 = (*qfnn(fn))(qenv(fn), 3, v0060, v0039, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    fn = elt(env, 6); /* invsq */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    fn = elt(env, 7); /* multsq */
    v0040 = (*qfn2(fn))(qenv(fn), stack[0], v0040);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    stack[-1] = v0040;
    v0040 = stack[-2];
    qvalue(elt(env, 1)) = v0040; /* mchfg!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v0061:
    popv(4);
    return nil;
}



/* Code for tayexp!-difference */

static Lisp_Object CC_tayexpKdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0074, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-difference");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0073 = v0000;
/* end of prologue */
    v0074 = v0073;
    if (!consp(v0074)) goto v0034;
    v0074 = qvalue(elt(env, 1)); /* nil */
    goto v0030;

v0030:
    if (v0074 == nil) goto v0053;
    v0074 = v0073;
    v0073 = stack[0];
    popv(3);
    return difference2(v0074, v0073);

v0053:
    v0074 = v0073;
    if (!consp(v0074)) goto v0076;
    v0074 = stack[0];
    if (!consp(v0074)) goto v0077;
    v0074 = v0073;
    v0073 = stack[0];
    fn = elt(env, 3); /* rndifference!: */
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    goto v0041;

v0041:
    v0075 = v0073;
    v0073 = v0075;
    v0073 = qcdr(v0073);
    v0074 = qcdr(v0073);
    v0073 = (Lisp_Object)17; /* 1 */
    if (!(v0074 == v0073)) { popv(3); return onevalue(v0075); }
    v0073 = v0075;
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    { popv(3); return onevalue(v0073); }

v0077:
    stack[-1] = v0073;
    v0075 = elt(env, 2); /* !:rn!: */
    v0074 = stack[0];
    v0073 = (Lisp_Object)17; /* 1 */
    v0073 = list2star(v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    fn = elt(env, 3); /* rndifference!: */
    v0073 = (*qfn2(fn))(qenv(fn), stack[-1], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    goto v0041;

v0076:
    v0075 = elt(env, 2); /* !:rn!: */
    v0074 = v0073;
    v0073 = (Lisp_Object)17; /* 1 */
    v0074 = list2star(v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    v0073 = stack[0];
    fn = elt(env, 3); /* rndifference!: */
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    goto v0041;

v0034:
    v0074 = stack[0];
    v0074 = (consp(v0074) ? nil : lisp_true);
    goto v0030;
/* error exit handlers */
v0078:
    popv(3);
    return nil;
}



/* Code for rl_prepat */

static Lisp_Object CC_rl_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_prepat");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0048 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_prepat!* */
    v0048 = ncons(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    {
        Lisp_Object v0032 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0032, v0048);
    }
/* error exit handlers */
v0052:
    popv(2);
    return nil;
}



/* Code for ibalp_calcmom */

static Lisp_Object CC_ibalp_calcmom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0077;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_calcmom");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0077 = qcar(v0083);
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcar(v0083);
    v0077 = plus2(v0077, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0083 = (Lisp_Object)513; /* 32 */
    stack[-1] = times2(v0077, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0077 = qcar(v0083);
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcar(v0083);
    v0083 = times2(v0077, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    {
        Lisp_Object v0037 = stack[-1];
        popv(3);
        return plus2(v0037, v0083);
    }
/* error exit handlers */
v0084:
    popv(3);
    return nil;
}



/* Code for rl_ordatp */

static Lisp_Object CC_rl_ordatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_ordatp");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0085 = v0001;
    v0035 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_ordatp!* */
    v0085 = list2(v0035, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    {
        Lisp_Object v0059 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0059, v0085);
    }
/* error exit handlers */
v0022:
    popv(2);
    return nil;
}



/* Code for rationalizei */

static Lisp_Object CC_rationalizei(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0092, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizei");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    stack[-2] = v0007;
    v0092 = v0007;
    v0007 = v0092;
    if (!consp(v0007)) goto v0012;
    v0007 = v0092;
    v0007 = qcar(v0007);
    v0007 = (consp(v0007) ? nil : lisp_true);
    goto v0004;

v0004:
    if (!(v0007 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0092 = elt(env, 2); /* i */
    v0007 = stack[-2];
    v0007 = Lsmemq(nil, v0092, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    if (v0007 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0092 = elt(env, 2); /* i */
    v0007 = qvalue(elt(env, 3)); /* kord!* */
    v0007 = cons(v0092, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 3)); /* kord!* */
    qvalue(elt(env, 3)) = v0007; /* kord!* */
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    fn = elt(env, 6); /* reorder */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    fn = elt(env, 6); /* reorder */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    v0007 = cons(stack[-2], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    stack[-2] = v0007;
    qvalue(elt(env, 3)) = stack[0]; /* kord!* */
    v0007 = stack[-2];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    v0007 = qcar(v0007);
    v0092 = qcar(v0007);
    v0007 = elt(env, 4); /* (i . 1) */
    if (equal(v0092, v0007)) goto v0046;
    v0007 = qvalue(elt(env, 5)); /* nil */
    goto v0045;

v0045:
    if (v0007 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0093 = elt(env, 2); /* i */
    v0092 = (Lisp_Object)17; /* 1 */
    v0007 = (Lisp_Object)17; /* 1 */
    v0007 = acons(v0093, v0092, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-1] = ncons(v0007);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0007 = stack[-2];
    v0007 = qcar(v0007);
    fn = elt(env, 6); /* reorder */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    fn = elt(env, 7); /* multf */
    v0007 = (*qfn2(fn))(qenv(fn), stack[-1], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    fn = elt(env, 8); /* negf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0007 = qcdr(v0007);
    fn = elt(env, 6); /* reorder */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    {
        Lisp_Object v0096 = stack[-1];
        popv(4);
        return cons(v0096, v0007);
    }

v0046:
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    v0007 = (v0007 == nil ? lisp_true : nil);
    goto v0045;

v0012:
    v0007 = qvalue(elt(env, 1)); /* t */
    goto v0004;
/* error exit handlers */
v0095:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[0]; /* kord!* */
    popv(4);
    return nil;
v0094:
    popv(4);
    return nil;
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retimes1");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0033;

v0033:
    v0008 = stack[0];
    if (v0008 == nil) goto v0030;
    v0008 = stack[0];
    v0101 = qcar(v0008);
    v0008 = (Lisp_Object)17; /* 1 */
    if (v0101 == v0008) goto v0052;
    v0008 = stack[0];
    v0008 = qcar(v0008);
    v0008 = Lminusp(nil, v0008);
    env = stack[-2];
    if (v0008 == nil) goto v0102;
    v0008 = qvalue(elt(env, 1)); /* !*bool */
    v0008 = (v0008 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0008; /* !*bool */
    v0008 = stack[0];
    v0008 = qcar(v0008);
    v0101 = negate(v0008);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    v0008 = cons(v0101, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    stack[0] = v0008;
    goto v0033;

v0102:
    v0008 = stack[0];
    v0008 = qcar(v0008);
    if (!consp(v0008)) goto v0017;
    v0008 = stack[0];
    v0008 = qcar(v0008);
    v0101 = qcar(v0008);
    v0008 = elt(env, 2); /* minus */
    if (v0101 == v0008) goto v0037;
    v0008 = stack[0];
    v0008 = qcar(v0008);
    v0101 = qcar(v0008);
    v0008 = elt(env, 3); /* times */
    if (v0101 == v0008) goto v0027;
    v0008 = stack[0];
    v0101 = qcar(v0008);
    v0008 = stack[-1];
    v0008 = cons(v0101, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    stack[-1] = v0008;
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    stack[0] = v0008;
    goto v0033;

v0027:
    v0008 = stack[0];
    v0008 = qcar(v0008);
    v0101 = qcdr(v0008);
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    v0008 = Lappend(nil, v0101, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    stack[0] = v0008;
    goto v0033;

v0037:
    v0008 = qvalue(elt(env, 1)); /* !*bool */
    v0008 = (v0008 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0008; /* !*bool */
    v0008 = stack[0];
    v0008 = qcar(v0008);
    v0008 = qcdr(v0008);
    v0101 = qcar(v0008);
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    v0008 = cons(v0101, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    stack[0] = v0008;
    goto v0033;

v0017:
    v0008 = stack[0];
    v0101 = qcar(v0008);
    v0008 = stack[-1];
    v0008 = cons(v0101, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    stack[-1] = v0008;
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    stack[0] = v0008;
    goto v0033;

v0052:
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    stack[0] = v0008;
    goto v0033;

v0030:
    v0008 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0008);
    }
/* error exit handlers */
v0095:
    popv(3);
    return nil;
}



/* Code for !*collectphysops */

static Lisp_Object CC_Hcollectphysops(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *collectphysops");
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
/* copy arguments values to proper place */
    v0048 = v0000;
/* end of prologue */
    v0103 = v0048;
    v0048 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* !*collectphysops_reversed */
    v0048 = (*qfn2(fn))(qenv(fn), v0103, v0048);
    errexit();
        return Lnreverse(nil, v0048);
}



/* Code for add2resultbuf */

static Lisp_Object CC_add2resultbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0108, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2resultbuf");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0107 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0109 = v0107;
    v0108 = elt(env, 1); /* symbolic */
    if (v0109 == v0108) goto v0048;
    v0108 = stack[0];
    if (v0108 == nil) goto v0042;
    v0108 = qvalue(elt(env, 5)); /* nil */
    goto v0041;

v0041:
    if (v0108 == nil) goto v0083;
    v0108 = qvalue(elt(env, 2)); /* t */
    goto v0049;

v0049:
    if (v0108 == nil) goto v0110;
    v0107 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0107); }

v0110:
    v0108 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0108 == nil) goto v0013;
    v0109 = elt(env, 7); /* ws */
    v0108 = stack[0];
    fn = elt(env, 13); /* putobject */
    v0107 = (*qfnn(fn))(qenv(fn), 3, v0109, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-1];
    goto v0037;

v0037:
    v0107 = qvalue(elt(env, 9)); /* !*int */
    if (v0107 == nil) goto v0065;
    v0107 = qvalue(elt(env, 10)); /* ifl!* */
    if (!(v0107 == nil)) goto v0065;
    v0109 = qvalue(elt(env, 11)); /* statcounter */
    v0108 = stack[0];
    v0107 = qvalue(elt(env, 12)); /* resultbuflis!* */
    v0107 = acons(v0109, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-1];
    qvalue(elt(env, 12)) = v0107; /* resultbuflis!* */
    goto v0065;

v0065:
    v0107 = nil;
    { popv(2); return onevalue(v0107); }

v0013:
    v0107 = qvalue(elt(env, 5)); /* nil */
    v0107 = ncons(v0107);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0107; /* alglist!* */
    v0107 = stack[0];
    qvalue(elt(env, 7)) = v0107; /* ws */
    goto v0037;

v0083:
    v0108 = qvalue(elt(env, 6)); /* !*nosave!* */
    goto v0049;

v0042:
    v0108 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0108 == nil) goto v0024;
    v0109 = v0107;
    v0108 = elt(env, 4); /* empty_list */
    v0108 = (v0109 == v0108 ? lisp_true : nil);
    v0108 = (v0108 == nil ? lisp_true : nil);
    goto v0041;

v0024:
    v0108 = qvalue(elt(env, 2)); /* t */
    goto v0041;

v0048:
    v0108 = qvalue(elt(env, 2)); /* t */
    goto v0049;
/* error exit handlers */
v0073:
    popv(2);
    return nil;
}



/* Code for dp_diff */

static Lisp_Object CC_dp_diff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_diff");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0103 = v0001;
    v0052 = v0000;
/* end of prologue */
    stack[0] = v0052;
    fn = elt(env, 1); /* dp_neg */
    v0103 = (*qfn1(fn))(qenv(fn), v0103);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    {
        Lisp_Object v0012 = stack[0];
        popv(2);
        fn = elt(env, 2); /* dp_sum */
        return (*qfn2(fn))(qenv(fn), v0012, v0103);
    }
/* error exit handlers */
v0004:
    popv(2);
    return nil;
}



/* Code for dquot */

static Lisp_Object CC_dquot(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0018, v0080;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dquot");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0049;

v0049:
    v0090 = stack[-1];
    v0018 = qcar(v0090);
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = difference2(v0018, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-3];
    v0080 = v0090;
    v0018 = v0080;
    v0090 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0018)) < ((int32_t)(v0090))) goto v0022;
    v0018 = v0080;
    v0090 = stack[-2];
    v0090 = cons(v0018, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-3];
    stack[-2] = v0090;
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    stack[0] = v0090;
    v0090 = stack[-1];
    v0090 = qcdr(v0090);
    stack[-1] = v0090;
    v0090 = stack[0];
    if (!(v0090 == nil)) goto v0049;
    v0090 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0090);

v0022:
    v0090 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0090); }
/* error exit handlers */
v0112:
    popv(4);
    return nil;
}



/* Code for pv_sort1 */

static Lisp_Object CC_pv_sort1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort1");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0110:
    v0077 = stack[-1];
    if (v0077 == nil) goto v0034;
    v0077 = stack[-1];
    v0077 = qcar(v0077);
    v0100 = qcdr(v0077);
    v0077 = stack[0];
    v0077 = qcar(v0077);
    v0077 = qcdr(v0077);
    v0077 = (Lisp_Object)lessp2(v0100, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-3];
    if (v0077 == nil) goto v0040;
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    stack[-2] = v0077;
    v0077 = stack[-1];
    v0100 = qcar(v0077);
    v0077 = stack[0];
    v0077 = cons(v0100, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-3];
    stack[0] = v0077;
    v0077 = stack[-2];
    stack[-1] = v0077;
    goto v0110;

v0040:
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    stack[-2] = v0077;
    v0077 = stack[-1];
    v0100 = qcar(v0077);
    v0077 = stack[0];
    fn = elt(env, 1); /* pv_sort2 */
    v0077 = (*qfn2(fn))(qenv(fn), v0100, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-3];
    stack[0] = v0077;
    v0077 = stack[-2];
    stack[-1] = v0077;
    goto v0110;

v0034:
    v0077 = stack[0];
        popv(4);
        return Lnreverse(nil, v0077);
/* error exit handlers */
v0038:
    popv(4);
    return nil;
}



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0100, v0112, v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0077 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v0077 == nil) goto v0039;
    v0100 = stack[0];
    v0077 = (Lisp_Object)1; /* 0 */
    v0077 = (Lisp_Object)lessp2(v0100, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-2];
    if (v0077 == nil) goto v0039;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v0100 = stack[0];
    v0077 = qvalue(elt(env, 2)); /* current!-modulus */
    v0112 = plus2(v0100, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0100 = (Lisp_Object)1; /* 0 */
    v0077 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v0045 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0045, v0112, v0100, v0077);
    }

v0039:
    v0084 = qvalue(elt(env, 2)); /* current!-modulus */
    v0112 = stack[0];
    v0100 = (Lisp_Object)1; /* 0 */
    v0077 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0084, v0112, v0100, v0077);
    }
/* error exit handlers */
v0015:
    popv(3);
    return nil;
}



/* Code for noncomdel */

static Lisp_Object CC_noncomdel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomdel");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0038 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0038 == nil) goto v0035;
    v0038 = stack[-1];
    fn = elt(env, 4); /* noncomp1 */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    if (!(v0038 == nil)) goto v0080;

v0035:
    v0015 = stack[-1];
    v0038 = elt(env, 2); /* expt */
    if (!consp(v0015)) goto v0070;
    v0015 = qcar(v0015);
    if (!(v0015 == v0038)) goto v0070;
    v0038 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0038 == nil) goto v0041;
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    fn = elt(env, 4); /* noncomp1 */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    goto v0004;

v0004:
    if (!(v0038 == nil)) goto v0080;
    v0015 = stack[-1];
    v0038 = stack[0];
        popv(3);
        return Ldelete(nil, v0015, v0038);

v0080:
    v0015 = stack[-1];
    v0038 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* noncomdel1 */
        return (*qfn2(fn))(qenv(fn), v0015, v0038);
    }

v0041:
    v0038 = qvalue(elt(env, 3)); /* nil */
    goto v0004;

v0070:
    v0038 = qvalue(elt(env, 3)); /* nil */
    goto v0004;
/* error exit handlers */
v0016:
    popv(3);
    return nil;
}



/* Code for anform1 */

static Lisp_Object CC_anform1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anform1");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    stack[-2] = v0116;
    v0116 = stack[-1];
    v0116 = qcdr(v0116);
    stack[-1] = v0116;
    v0116 = stack[-2];
    if (!consp(v0116)) goto v0048;
    v0116 = stack[-2];
    v0116 = CC_anform1(env, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0116 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0116);
    }

v0048:
    v0116 = stack[-2];
    if (symbolp(v0116)) goto v0041;
    v0116 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0116); }

v0041:
    v0117 = stack[-2];
    v0116 = elt(env, 2); /* dclglb */
    v0116 = Lflagp(nil, v0117, v0116);
    env = stack[-3];
    if (v0116 == nil) goto v0069;
    v0117 = stack[-2];
    v0116 = elt(env, 3); /* glb2rf */
    v0116 = Lflagp(nil, v0117, v0116);
    env = stack[-3];
    if (!(v0116 == nil)) goto v0055;
    v0116 = stack[-2];
    v0117 = ncons(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0116 = elt(env, 3); /* glb2rf */
    v0116 = Lflag(nil, v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0117 = stack[-2];
    v0116 = qvalue(elt(env, 4)); /* globs!* */
    v0116 = cons(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    qvalue(elt(env, 4)) = v0116; /* globs!* */
    goto v0055;

v0055:
    v0116 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0116);
    }

v0069:
    v0117 = stack[-2];
    v0116 = qvalue(elt(env, 5)); /* locls!* */
    v0116 = Lassoc(nil, v0117, v0116);
    if (v0116 == nil) goto v0036;
    v0116 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0116);
    }

v0036:
    v0116 = stack[-2];
    fn = elt(env, 9); /* add2calls */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    stack[0] = stack[-2];
    v0116 = stack[-1];
    v0116 = Llength(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    fn = elt(env, 10); /* checkargcount */
    v0116 = (*qfn2(fn))(qenv(fn), stack[0], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0117 = stack[-2];
    v0116 = elt(env, 6); /* noanl */
    v0116 = Lflagp(nil, v0117, v0116);
    env = stack[-3];
    if (!(v0116 == nil)) goto v0119;
    v0117 = stack[-2];
    v0116 = elt(env, 7); /* anlfn */
    v0116 = get(v0117, v0116);
    env = stack[-3];
    v0117 = v0116;
    if (v0116 == nil) goto v0028;
    v0116 = stack[-1];
    v0116 = Lapply1(nil, v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    goto v0119;

v0119:
    v0116 = nil;
    { popv(4); return onevalue(v0116); }

v0028:
    v0116 = stack[-1];
    fn = elt(env, 8); /* anforml */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    goto v0119;
/* error exit handlers */
v0118:
    popv(4);
    return nil;
}



/* Code for gcddd */

static Lisp_Object CC_gcddd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0025, v0130, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcddd");
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
/* copy arguments values to proper place */
    v0025 = v0001;
    v0130 = v0000;
/* end of prologue */
    v0131 = v0130;
    v0129 = (Lisp_Object)17; /* 1 */
    if (v0131 == v0129) goto v0034;
    v0131 = v0025;
    v0129 = (Lisp_Object)17; /* 1 */
    v0129 = (v0131 == v0129 ? lisp_true : nil);
    goto v0030;

v0030:
    if (v0129 == nil) goto v0110;
    v0129 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0129); }

v0110:
    v0129 = v0130;
    if (!consp(v0129)) goto v0132;
    v0129 = v0025;
    if (!consp(v0129)) goto v0010;
    v0129 = v0130;
    v0131 = qcar(v0129);
    v0129 = elt(env, 2); /* field */
    v0129 = Lflagp(nil, v0131, v0129);
    env = stack[0];
    if (v0129 == nil) goto v0133;
    v0129 = qvalue(elt(env, 1)); /* t */
    goto v0134;

v0134:
    if (v0129 == nil) goto v0135;
    v0129 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0129); }

v0135:
    v0129 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0130, v0025, v0129);
    }

v0133:
    v0129 = v0025;
    v0131 = qcar(v0129);
    v0129 = elt(env, 2); /* field */
    v0129 = Lflagp(nil, v0131, v0129);
    env = stack[0];
    goto v0134;

v0010:
    v0129 = v0130;
    v0131 = qcar(v0129);
    v0129 = elt(env, 2); /* field */
    v0129 = Lflagp(nil, v0131, v0129);
    env = stack[0];
    if (v0129 == nil) goto v0075;
    v0129 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0129); }

v0075:
    v0129 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0130, v0025, v0129);
    }

v0132:
    v0129 = v0025;
    if (!consp(v0129)) goto v0076;
    v0129 = v0025;
    if (!consp(v0129)) goto v0046;
    v0129 = v0025;
    v0131 = qcar(v0129);
    v0129 = elt(env, 2); /* field */
    v0129 = Lflagp(nil, v0131, v0129);
    env = stack[0];
    goto v0071;

v0071:
    if (v0129 == nil) goto v0013;
    v0129 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0129); }

v0013:
    v0129 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0130, v0025, v0129);
    }

v0046:
    v0129 = qvalue(elt(env, 3)); /* nil */
    goto v0071;

v0076:
    v0129 = v0130;
        popv(1);
        return Lgcd(nil, v0129, v0025);

v0034:
    v0129 = qvalue(elt(env, 1)); /* t */
    goto v0030;
}



/* Code for gcdf1 */

static Lisp_Object CC_gcdf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf1");
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
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0152 = stack[-2];
    if (v0152 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0152 = stack[-1];
    if (v0152 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0153 = stack[-2];
    v0152 = (Lisp_Object)17; /* 1 */
    if (v0153 == v0152) goto v0036;
    v0153 = stack[-1];
    v0152 = (Lisp_Object)17; /* 1 */
    v0152 = (v0153 == v0152 ? lisp_true : nil);
    goto v0035;

v0035:
    if (v0152 == nil) goto v0043;
    v0152 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0152); }

v0043:
    v0152 = stack[-2];
    if (!consp(v0152)) goto v0079;
    v0152 = stack[-2];
    v0152 = qcar(v0152);
    v0152 = (consp(v0152) ? nil : lisp_true);
    goto v0128;

v0128:
    if (v0152 == nil) goto v0060;
    v0153 = qvalue(elt(env, 2)); /* dmode!* */
    v0152 = elt(env, 3); /* field */
    v0152 = Lflagp(nil, v0153, v0152);
    env = stack[-4];
    if (v0152 == nil) goto v0068;
    v0152 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0152); }

v0068:
    v0153 = stack[-2];
    v0152 = stack[-1];
    {
        popv(5);
        fn = elt(env, 10); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v0153, v0152);
    }

v0060:
    v0152 = stack[-1];
    if (!consp(v0152)) goto v0063;
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = (consp(v0152) ? nil : lisp_true);
    goto v0066;

v0066:
    if (v0152 == nil) goto v0127;
    v0153 = qvalue(elt(env, 2)); /* dmode!* */
    v0152 = elt(env, 3); /* field */
    v0152 = Lflagp(nil, v0153, v0152);
    env = stack[-4];
    if (v0152 == nil) goto v0078;
    v0152 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0152); }

v0078:
    v0153 = stack[-1];
    v0152 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v0153, v0152);
    }

v0127:
    v0152 = qvalue(elt(env, 4)); /* !*anygcd */
    if (v0152 == nil) goto v0093;
    v0152 = stack[-2];
    fn = elt(env, 11); /* num!-exponents */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    if (v0152 == nil) goto v0117;
    v0152 = stack[-1];
    fn = elt(env, 11); /* num!-exponents */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0152 = (v0152 == nil ? lisp_true : nil);
    goto v0092;

v0092:
    if (v0152 == nil) goto v0002;
    v0152 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0152); }

v0002:
    v0153 = stack[-2];
    v0152 = stack[-1];
    fn = elt(env, 12); /* quotf1 */
    v0152 = (*qfn2(fn))(qenv(fn), v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    if (!(v0152 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0153 = stack[-1];
    v0152 = stack[-2];
    fn = elt(env, 12); /* quotf1 */
    v0152 = (*qfn2(fn))(qenv(fn), v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    if (!(v0152 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0153 = stack[-2];
    v0152 = stack[-1];
    fn = elt(env, 13); /* gcdf2 */
    v0152 = (*qfn2(fn))(qenv(fn), v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    stack[-3] = v0152;
    v0152 = qvalue(elt(env, 5)); /* !*gcd */
    if (v0152 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0153 = qvalue(elt(env, 2)); /* dmode!* */
    v0152 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v0152 = Lmemq(nil, v0153, v0152);
    if (v0152 == nil) goto v0155;
    v0152 = qvalue(elt(env, 7)); /* nil */
    goto v0156;

v0156:
    if (v0152 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0152 = qvalue(elt(env, 8)); /* !*ncmp */
    if (v0152 == nil) goto v0157;
    v0152 = stack[-2];
    fn = elt(env, 14); /* noncomfp1 */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    if (!(v0152 == nil)) goto v0158;

v0157:
    v0152 = qvalue(elt(env, 8)); /* !*ncmp */
    if (v0152 == nil) goto v0159;
    v0152 = stack[-1];
    fn = elt(env, 14); /* noncomfp1 */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    if (!(v0152 == nil)) goto v0158;

v0159:
    stack[0] = elt(env, 9); /* "gcdf failed" */
    v0152 = stack[-2];
    fn = elt(env, 15); /* prepf */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0152 = stack[-1];
    fn = elt(env, 15); /* prepf */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0152 = list3(stack[0], stack[-2], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    fn = elt(env, 16); /* errach */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0158:
    v0152 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0152); }

v0155:
    v0153 = stack[-2];
    v0152 = stack[-3];
    fn = elt(env, 12); /* quotf1 */
    v0152 = (*qfn2(fn))(qenv(fn), v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    if (v0152 == nil) goto v0160;
    v0153 = stack[-1];
    v0152 = stack[-3];
    fn = elt(env, 12); /* quotf1 */
    v0152 = (*qfn2(fn))(qenv(fn), v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0152 = (v0152 == nil ? lisp_true : nil);
    goto v0156;

v0160:
    v0152 = qvalue(elt(env, 1)); /* t */
    goto v0156;

v0117:
    v0152 = qvalue(elt(env, 1)); /* t */
    goto v0092;

v0093:
    v0152 = qvalue(elt(env, 1)); /* t */
    goto v0092;

v0063:
    v0152 = qvalue(elt(env, 1)); /* t */
    goto v0066;

v0079:
    v0152 = qvalue(elt(env, 1)); /* t */
    goto v0128;

v0036:
    v0152 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0154:
    popv(5);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp1");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0161 = stack[0];
    v0082 = qcar(v0161);
    v0161 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0082, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0161 = stack[0];
    v0082 = qcdr(v0161);
    v0161 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v0161 = (*qfn2(fn))(qenv(fn), v0082, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    fn = elt(env, 5); /* invsq */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    fn = elt(env, 6); /* multsq */
    v0161 = (*qfn2(fn))(qenv(fn), stack[-1], v0161);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    stack[0] = v0161;
    v0161 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v0161; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for ibalp_varlat */

static Lisp_Object CC_ibalp_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlat");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0032 = stack[0];
    fn = elt(env, 1); /* ibalp_arg2l */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    v0032 = stack[0];
    fn = elt(env, 3); /* ibalp_arg2r */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    {
        Lisp_Object v0085 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* union */
        return (*qfn2(fn))(qenv(fn), v0085, v0032);
    }
/* error exit handlers */
v0043:
    popv(3);
    return nil;
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0054, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0069, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powers2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0054,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0054);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0054;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0031:
    v0051 = stack[-2];
    if (!consp(v0051)) goto v0032;
    v0051 = stack[-2];
    v0051 = qcar(v0051);
    v0051 = (consp(v0051) ? nil : lisp_true);
    goto v0052;

v0052:
    if (v0051 == nil) goto v0076;
    v0051 = stack[-2];
    if (v0051 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0069 = stack[0];
    v0051 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v0069, v0051);
    }

v0076:
    v0051 = stack[-2];
    v0051 = qcar(v0051);
    v0051 = qcdr(v0051);
    stack[-3] = v0051;
    v0051 = stack[-2];
    v0067 = qcdr(v0051);
    v0069 = stack[-1];
    v0051 = stack[0];
    v0051 = CC_powers2(env, 3, v0067, v0069, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    stack[-1] = v0051;
    v0051 = stack[-2];
    v0051 = qcar(v0051);
    v0069 = qcar(v0051);
    v0051 = stack[0];
    v0051 = cons(v0069, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    stack[0] = v0051;
    v0051 = stack[-3];
    stack[-2] = v0051;
    goto v0031;

v0032:
    v0051 = qvalue(elt(env, 1)); /* t */
    goto v0052;
/* error exit handlers */
v0014:
    popv(5);
    return nil;
}



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retattributes");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0162:
    v0047 = stack[0];
    if (v0047 == nil) goto v0031;
    v0026 = stack[-1];
    v0047 = stack[0];
    v0047 = qcar(v0047);
    fn = elt(env, 2); /* find */
    v0047 = (*qfn2(fn))(qenv(fn), v0026, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    v0026 = v0047;
    if (v0026 == nil) goto v0100;
    v0026 = stack[0];
    v0026 = qcar(v0026);
    stack[-2] = list2(v0026, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    v0026 = stack[-1];
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    v0047 = CC_retattributes(env, v0026, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    {
        Lisp_Object v0068 = stack[-2];
        popv(4);
        return cons(v0068, v0047);
    }

v0100:
    v0026 = stack[-1];
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[-1] = v0026;
    stack[0] = v0047;
    goto v0162;

v0031:
    v0047 = nil;
    { popv(4); return onevalue(v0047); }
/* error exit handlers */
v0067:
    popv(4);
    return nil;
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mintype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0103 = v0000;
/* end of prologue */
    v0052 = v0103;
    if (!consp(v0052)) return onevalue(v0103);
    v0103 = qcar(v0103);
    return onevalue(v0103);
}



/* Code for ident */

static Lisp_Object CC_ident(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0044;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ident");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0044 = v0000;
/* end of prologue */
    return onevalue(v0044);
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0091, v0128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcsum");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0060 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0060 == nil) goto v0023;
    v0091 = stack[-1];
    v0060 = stack[0];
    v0060 = plus2(v0091, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0060);
    }

v0023:
    v0128 = stack[-1];
    v0091 = stack[0];
    v0060 = elt(env, 2); /* plus2 */
    fn = elt(env, 4); /* bcint2op */
    v0060 = (*qfnn(fn))(qenv(fn), 3, v0128, v0091, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    if (!(v0060 == nil)) { popv(3); return onevalue(v0060); }
    v0091 = stack[-1];
    v0060 = stack[0];
    fn = elt(env, 5); /* addsq */
    v0060 = (*qfn2(fn))(qenv(fn), v0091, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v0060);
    }
/* error exit handlers */
v0072:
    popv(3);
    return nil;
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0102, v0106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evtdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0102 = v0000;
/* end of prologue */
    v0053 = (Lisp_Object)1; /* 0 */
    goto v0110;

v0110:
    v0106 = v0102;
    if (v0106 == nil) return onevalue(v0053);
    v0106 = v0102;
    v0106 = qcar(v0106);
    v0053 = (Lisp_Object)(int32_t)((int32_t)v0106 + (int32_t)v0053 - TAG_FIXNUM);
    v0102 = qcdr(v0102);
    goto v0110;
}



/* Code for worderp */

static Lisp_Object CC_worderp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0145, v0146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for worderp");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0033:
    v0168 = stack[-1];
    if (!consp(v0168)) goto v0017;
    v0168 = stack[-1];
    v0145 = qcar(v0168);
    v0168 = elt(env, 1); /* indexvar */
    v0168 = Lflagp(nil, v0145, v0168);
    env = stack[-2];
    if (v0168 == nil) goto v0079;
    v0168 = stack[0];
    if (!consp(v0168)) goto v0060;
    v0168 = stack[0];
    v0145 = qcar(v0168);
    v0168 = elt(env, 1); /* indexvar */
    v0168 = Lflagp(nil, v0145, v0168);
    env = stack[-2];
    goto v0048;

v0048:
    if (v0168 == nil) goto v0034;
    v0145 = stack[-1];
    v0168 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* indexvarordp */
        return (*qfn2(fn))(qenv(fn), v0145, v0168);
    }

v0034:
    v0168 = stack[-1];
    if (!consp(v0168)) goto v0016;
    v0145 = stack[-1];
    v0168 = qvalue(elt(env, 4)); /* kord!* */
    v0168 = Lmemq(nil, v0145, v0168);
    goto v0046;

v0046:
    if (v0168 == nil) goto v0015;
    v0168 = stack[0];
    if (!consp(v0168)) goto v0011;
    v0145 = stack[0];
    v0168 = qvalue(elt(env, 4)); /* kord!* */
    v0168 = Lmemq(nil, v0145, v0168);
    goto v0099;

v0099:
    if (v0168 == nil) goto v0087;
    v0145 = stack[-1];
    v0168 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0145, v0168);
    }

v0087:
    v0168 = stack[0];
    fn = elt(env, 7); /* peel */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    v0146 = v0168;
    v0145 = stack[-1];
    v0168 = v0146;
    if (v0145 == v0168) goto v0134;
    v0168 = stack[-1];
    v0145 = v0146;
    stack[-1] = v0168;
    stack[0] = v0145;
    goto v0033;

v0134:
    v0168 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v0168); }

v0011:
    v0168 = qvalue(elt(env, 3)); /* t */
    goto v0099;

v0015:
    v0168 = stack[0];
    if (!consp(v0168)) goto v0170;
    v0145 = stack[0];
    v0168 = qvalue(elt(env, 4)); /* kord!* */
    v0168 = Lmemq(nil, v0145, v0168);
    goto v0123;

v0123:
    if (v0168 == nil) goto v0171;
    v0168 = stack[-1];
    fn = elt(env, 7); /* peel */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    v0146 = v0168;
    v0145 = v0146;
    v0168 = stack[0];
    if (v0145 == v0168) goto v0149;
    v0145 = v0146;
    v0168 = stack[0];
    stack[-1] = v0145;
    stack[0] = v0168;
    goto v0033;

v0149:
    v0168 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0168); }

v0171:
    v0168 = stack[-1];
    fn = elt(env, 7); /* peel */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    stack[-1] = v0168;
    v0168 = stack[0];
    fn = elt(env, 7); /* peel */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    stack[0] = v0168;
    goto v0033;

v0170:
    v0168 = qvalue(elt(env, 3)); /* t */
    goto v0123;

v0016:
    v0168 = qvalue(elt(env, 3)); /* t */
    goto v0046;

v0060:
    v0168 = qvalue(elt(env, 2)); /* nil */
    goto v0048;

v0079:
    v0168 = qvalue(elt(env, 2)); /* nil */
    goto v0048;

v0017:
    v0168 = qvalue(elt(env, 2)); /* nil */
    goto v0048;
/* error exit handlers */
v0169:
    popv(3);
    return nil;
}



/* Code for algid */

static Lisp_Object CC_algid(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0161, v0082;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algid");
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
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0132 = v0001;
    v0082 = v0000;
/* end of prologue */
    v0161 = v0082;
    v0132 = Latsoc(nil, v0161, v0132);
    if (!(v0132 == nil)) return onevalue(v0082);
    v0161 = v0082;
    v0132 = elt(env, 1); /* share */
    v0132 = Lflagp(nil, v0161, v0132);
    if (!(v0132 == nil)) return onevalue(v0082);
    v0132 = v0082;
        return Lmkquote(nil, v0132);
}



/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0054, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for layout-formula");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0054,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0054);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0054;
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* ycoord!* */
    qvalue(elt(env, 1)) = nil; /* ycoord!* */
    stack[-5] = qvalue(elt(env, 2)); /* ymin!* */
    qvalue(elt(env, 2)) = nil; /* ymin!* */
    stack[-4] = qvalue(elt(env, 3)); /* ymax!* */
    qvalue(elt(env, 3)) = nil; /* ymax!* */
    stack[-3] = qvalue(elt(env, 4)); /* posn!* */
    qvalue(elt(env, 4)) = nil; /* posn!* */
    stack[-2] = qvalue(elt(env, 5)); /* pline!* */
    qvalue(elt(env, 5)) = nil; /* pline!* */
    stack[-1] = qvalue(elt(env, 6)); /* testing!-width!* */
    qvalue(elt(env, 6)) = nil; /* testing!-width!* */
    stack[0] = qvalue(elt(env, 7)); /* overflowed!* */
    qvalue(elt(env, 7)) = nil; /* overflowed!* */
    v0062 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 7)) = v0062; /* overflowed!* */
    qvalue(elt(env, 5)) = v0062; /* pline!* */
    v0062 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0062; /* ymax!* */
    qvalue(elt(env, 2)) = v0062; /* ymin!* */
    qvalue(elt(env, 1)) = v0062; /* ycoord!* */
    v0062 = qvalue(elt(env, 9)); /* orig!* */
    qvalue(elt(env, 4)) = v0062; /* posn!* */
    v0062 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 6)) = v0062; /* testing!-width!* */
    v0062 = stack[-6];
    if (v0062 == nil) goto v0040;
    v0064 = stack[-6];
    v0062 = elt(env, 11); /* inbrackets */
    if (v0064 == v0062) goto v0058;
    v0062 = stack[-6];
    fn = elt(env, 14); /* oprin */
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-10];
    goto v0040;

v0040:
    v0064 = stack[-8];
    v0062 = stack[-7];
    fn = elt(env, 15); /* maprint */
    v0062 = (*qfn2(fn))(qenv(fn), v0064, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-10];
    v0064 = stack[-6];
    v0062 = elt(env, 11); /* inbrackets */
    if (!(v0064 == v0062)) goto v0017;
    v0062 = elt(env, 13); /* ")" */
    fn = elt(env, 16); /* prin2!* */
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-10];
    goto v0017;

v0017:
    v0062 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v0062 == nil) goto v0067;
    v0062 = qvalue(elt(env, 8)); /* nil */
    goto v0103;

v0103:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v0062); }

v0067:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v0064 = qvalue(elt(env, 4)); /* posn!* */
    v0062 = qvalue(elt(env, 9)); /* orig!* */
    stack[-6] = difference2(v0064, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-10];
    v0064 = qvalue(elt(env, 2)); /* ymin!* */
    v0062 = qvalue(elt(env, 3)); /* ymax!* */
    v0062 = cons(v0064, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-10];
    v0062 = acons(stack[-7], stack[-6], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-10];
    goto v0103;

v0058:
    v0062 = elt(env, 12); /* "(" */
    fn = elt(env, 16); /* prin2!* */
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-10];
    goto v0040;
/* error exit handlers */
v0087:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    popv(11);
    return nil;
}



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0047, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecopp");
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
/* copy arguments values to proper place */
    v0047 = v0000;
/* end of prologue */
    v0016 = v0047;
    if (symbolp(v0016)) goto v0035;
    v0016 = qvalue(elt(env, 1)); /* nil */
    goto v0110;

v0110:
    if (!(v0016 == nil)) { popv(1); return onevalue(v0016); }
    v0016 = v0047;
    if (!consp(v0016)) goto v0015;
    v0016 = v0047;
    v0026 = qcar(v0016);
    v0016 = elt(env, 2); /* phystype */
    v0026 = get(v0026, v0016);
    env = stack[0];
    v0016 = elt(env, 3); /* vector */
    if (v0026 == v0016) goto v0057;
    v0016 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0016); }

v0057:
    v0016 = v0047;
    v0016 = qcdr(v0016);
    v0016 = qcar(v0016);
    fn = elt(env, 4); /* isanindex */
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    v0016 = (v0016 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0016); }

v0015:
    v0016 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0016); }

v0035:
    v0026 = v0047;
    v0016 = elt(env, 2); /* phystype */
    v0026 = get(v0026, v0016);
    env = stack[0];
    v0016 = elt(env, 3); /* vector */
    v0016 = (v0026 == v0016 ? lisp_true : nil);
    goto v0110;
/* error exit handlers */
v0050:
    popv(1);
    return nil;
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0054, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0046;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0054,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0054);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0054;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v0045 = stack[-2];
    v0045 = Llength(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    if (stack[-3] == v0045) goto v0036;
    v0045 = nil;
    { popv(5); return onevalue(v0045); }

v0036:
    v0046 = stack[0];
    v0045 = stack[-2];
    v0045 = qcar(v0045);
    if (equal(v0046, v0045)) goto v0042;
    v0046 = stack[0];
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    v0045 = qcar(v0045);
    if (equal(v0046, v0045)) goto v0090;
    v0045 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0045); }

v0090:
    v0045 = stack[-2];
    v0046 = qcar(v0045);
    v0045 = stack[-1];
    popv(5);
    return cons(v0046, v0045);

v0042:
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    v0046 = qcar(v0045);
    v0045 = stack[-1];
    popv(5);
    return cons(v0046, v0045);
/* error exit handlers */
v0051:
    popv(5);
    return nil;
}



/* Code for form */

static Lisp_Object CC_form(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0175, v0029, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form");
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
/* copy arguments values to proper place */
    v0029 = v0000;
/* end of prologue */
    v0175 = v0029;
    if (!consp(v0175)) goto v0036;
    v0175 = v0029;
    v0122 = qcar(v0175);
    v0175 = elt(env, 1); /* always_nform */
    v0175 = Lflagp(nil, v0122, v0175);
    env = stack[0];
    goto v0031;

v0031:
    if (v0175 == nil) goto v0033;
    v0175 = v0029;
    {
        popv(1);
        fn = elt(env, 11); /* n_form */
        return (*qfn1(fn))(qenv(fn), v0175);
    }

v0033:
    v0175 = qvalue(elt(env, 3)); /* !*rlisp88 */
    if (v0175 == nil) goto v0042;
    v0122 = qvalue(elt(env, 5)); /* !*mode */
    v0175 = elt(env, 6); /* symbolic */
    if (v0122 == v0175) goto v0047;
    v0175 = qvalue(elt(env, 7)); /* t */
    goto v0060;

v0060:
    if (v0175 == nil) goto v0095;
    v0029 = elt(env, 9); /* "algebraic expression" */
    v0175 = elt(env, 10); /* "Rlisp88 form" */
    {
        popv(1);
        fn = elt(env, 12); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0029, v0175);
    }

v0095:
    v0122 = v0029;
    v0029 = qvalue(elt(env, 4)); /* !*vars!* */
    v0175 = qvalue(elt(env, 5)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 13); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v0122, v0029, v0175);
    }

v0047:
    v0122 = v0029;
    v0175 = elt(env, 8); /* modefn */
    v0175 = Lflagp(nil, v0122, v0175);
    env = stack[0];
    if (v0175 == nil) goto v0066;
    v0122 = v0029;
    v0175 = elt(env, 6); /* symbolic */
    v0175 = (v0122 == v0175 ? lisp_true : nil);
    v0175 = (v0175 == nil ? lisp_true : nil);
    goto v0015;

v0015:
    if (v0175 == nil) goto v0173;
    v0175 = qvalue(elt(env, 7)); /* t */
    goto v0060;

v0173:
    v0122 = v0029;
    v0175 = elt(env, 8); /* modefn */
    v0175 = Lflagpcar(nil, v0122, v0175);
    env = stack[0];
    if (v0175 == nil) goto v0176;
    v0175 = v0029;
    v0122 = qcar(v0175);
    v0175 = elt(env, 6); /* symbolic */
    v0175 = (v0122 == v0175 ? lisp_true : nil);
    v0175 = (v0175 == nil ? lisp_true : nil);
    goto v0060;

v0176:
    v0175 = qvalue(elt(env, 2)); /* nil */
    goto v0060;

v0066:
    v0175 = qvalue(elt(env, 2)); /* nil */
    goto v0015;

v0042:
    v0122 = v0029;
    v0029 = qvalue(elt(env, 4)); /* !*vars!* */
    v0175 = qvalue(elt(env, 5)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 13); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v0122, v0029, v0175);
    }

v0036:
    v0175 = qvalue(elt(env, 2)); /* nil */
    goto v0031;
}



/* Code for errorset2 */

static Lisp_Object CC_errorset2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0085, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0085 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*protfg */
    qvalue(elt(env, 1)) = nil; /* !*protfg */
    v0043 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0043; /* !*protfg */
    v0035 = v0085;
    v0085 = qvalue(elt(env, 3)); /* nil */
    v0043 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* errorset */
    v0043 = (*qfnn(fn))(qenv(fn), 3, v0035, v0085, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    { popv(2); return onevalue(v0043); }
/* error exit handlers */
v0022:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    popv(2);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0102;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-minusp");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0162:
    v0053 = stack[0];
    if (v0053 == nil) goto v0111;
    v0053 = stack[0];
    v0102 = qcar(v0053);
    v0053 = (Lisp_Object)1; /* 0 */
    v0053 = (Lisp_Object)lessp2(v0102, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    v0053 = v0053 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0053 == nil)) { popv(2); return onevalue(v0053); }
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    stack[0] = v0053;
    goto v0162;

v0111:
    v0053 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0053); }
/* error exit handlers */
v0041:
    popv(2);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0048 = v0001;
    v0103 = v0000;
/* end of prologue */
    return cons(v0048, v0103);
}



/* Code for pcmult */

static Lisp_Object CC_pcmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pcmult");
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
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0001;
    v0151 = v0000;
/* end of prologue */
    stack[-5] = v0151;
    v0151 = stack[-5];
    if (v0151 == nil) goto v0103;
    v0151 = stack[-5];
    v0151 = qcar(v0151);
    v0125 = v0151;
    stack[0] = qcar(v0125);
    v0125 = stack[-4];
    v0151 = qcdr(v0151);
    fn = elt(env, 2); /* cprod */
    v0151 = (*qfn2(fn))(qenv(fn), v0125, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-6];
    v0151 = cons(stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-6];
    v0151 = ncons(v0151);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-6];
    stack[-2] = v0151;
    stack[-3] = v0151;
    goto v0030;

v0030:
    v0151 = stack[-5];
    v0151 = qcdr(v0151);
    stack[-5] = v0151;
    v0151 = stack[-5];
    if (v0151 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0151 = stack[-5];
    v0151 = qcar(v0151);
    v0125 = v0151;
    stack[0] = qcar(v0125);
    v0125 = stack[-4];
    v0151 = qcdr(v0151);
    fn = elt(env, 2); /* cprod */
    v0151 = (*qfn2(fn))(qenv(fn), v0125, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-6];
    v0151 = cons(stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-6];
    v0151 = ncons(v0151);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-6];
    v0151 = Lrplacd(nil, stack[-1], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-6];
    v0151 = stack[-2];
    v0151 = qcdr(v0151);
    stack[-2] = v0151;
    goto v0030;

v0103:
    v0151 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0151); }
/* error exit handlers */
v0011:
    popv(7);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0125 = stack[0];
    v0151 = elt(env, 1); /* prtch */
    v0151 = get(v0125, v0151);
    env = stack[-2];
    stack[-1] = v0151;
    v0151 = stack[-1];
    if (v0151 == nil) goto v0052;
    v0151 = qvalue(elt(env, 3)); /* !*fort */
    if (v0151 == nil) goto v0023;
    v0151 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0151);
    }

v0023:
    v0151 = qvalue(elt(env, 4)); /* !*list */
    if (v0151 == nil) goto v0037;
    v0151 = qvalue(elt(env, 5)); /* obrkp!* */
    if (v0151 == nil) goto v0037;
    v0125 = stack[0];
    v0151 = elt(env, 6); /* (plus minus) */
    v0151 = Lmemq(nil, v0125, v0151);
    if (v0151 == nil) goto v0037;
    v0151 = qvalue(elt(env, 7)); /* testing!-width!* */
    if (v0151 == nil) goto v0071;
    v0151 = qvalue(elt(env, 8)); /* t */
    qvalue(elt(env, 9)) = v0151; /* overflowed!* */
    { popv(3); return onevalue(v0151); }

v0071:
    v0151 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 12); /* terpri!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0151 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0151);
    }

v0037:
    v0125 = stack[0];
    v0151 = elt(env, 10); /* spaced */
    v0151 = Lflagp(nil, v0125, v0151);
    env = stack[-2];
    if (v0151 == nil) goto v0105;
    v0151 = elt(env, 2); /* " " */
    fn = elt(env, 11); /* prin2!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0151 = stack[-1];
    fn = elt(env, 11); /* prin2!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0151 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0151);
    }

v0105:
    v0151 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0151);
    }

v0052:
    v0151 = elt(env, 2); /* " " */
    fn = elt(env, 11); /* prin2!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0151 = stack[0];
    fn = elt(env, 11); /* prin2!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0151 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0151);
    }
/* error exit handlers */
v0065:
    popv(3);
    return nil;
}



/* Code for pv_applp */

static Lisp_Object CC_pv_applp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_applp");
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
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0001;
    v0125 = v0000;
/* end of prologue */
    stack[-5] = v0125;
    v0125 = stack[-5];
    if (v0125 == nil) goto v0052;
    v0125 = stack[-5];
    v0125 = qcar(v0125);
    v0126 = v0125;
    v0125 = v0126;
    stack[0] = qcar(v0125);
    v0125 = v0126;
    v0126 = qcdr(v0125);
    v0125 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v0125 = (*qfn2(fn))(qenv(fn), v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-6];
    v0125 = cons(stack[0], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-6];
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-6];
    stack[-2] = v0125;
    stack[-3] = v0125;
    goto v0034;

v0034:
    v0125 = stack[-5];
    v0125 = qcdr(v0125);
    stack[-5] = v0125;
    v0125 = stack[-5];
    if (v0125 == nil) goto v0060;
    stack[-1] = stack[-2];
    v0125 = stack[-5];
    v0125 = qcar(v0125);
    v0126 = v0125;
    v0125 = v0126;
    stack[0] = qcar(v0125);
    v0125 = v0126;
    v0126 = qcdr(v0125);
    v0125 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v0125 = (*qfn2(fn))(qenv(fn), v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-6];
    v0125 = cons(stack[0], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-6];
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-6];
    v0125 = Lrplacd(nil, stack[-1], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-6];
    v0125 = stack[-2];
    v0125 = qcdr(v0125);
    stack[-2] = v0125;
    goto v0034;

v0060:
    v0125 = stack[-3];
    goto v0030;

v0030:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v0125);
    }

v0052:
    v0125 = qvalue(elt(env, 1)); /* nil */
    goto v0030;
/* error exit handlers */
v0174:
    popv(7);
    return nil;
}



/* Code for !*id2num */

static Lisp_Object CC_Hid2num(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0036;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *id2num");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0000;
/* end of prologue */
    v0036 = qvalue(elt(env, 1)); /* pair_id_num!* */
    v0035 = Lassoc(nil, v0035, v0036);
    v0036 = v0035;
    if (v0035 == nil) goto v0110;
    v0035 = v0036;
    v0035 = qcdr(v0035);
    return onevalue(v0035);

v0110:
    v0035 = nil;
    return onevalue(v0035);
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aronep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0048 = v0000;
/* end of prologue */
    v0103 = qcdr(v0048);
    v0048 = (Lisp_Object)17; /* 1 */
    v0048 = (v0103 == v0048 ? lisp_true : nil);
    return onevalue(v0048);
}



/* Code for exptmod!: */

static Lisp_Object CC_exptmodT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptmod:");
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
/* copy arguments values to proper place */
    v0052 = v0001;
    v0032 = v0000;
/* end of prologue */
    v0032 = qcdr(v0032);
    fn = elt(env, 1); /* general!-modular!-expt */
    v0052 = (*qfn2(fn))(qenv(fn), v0032, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
/* error exit handlers */
v0004:
    popv(1);
    return nil;
}



/* Code for minus!-mod!-p */

static Lisp_Object CC_minusKmodKp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minus-mod-p");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0033;

v0033:
    v0100 = stack[-1];
    if (v0100 == nil) goto v0030;
    v0100 = stack[-1];
    if (!consp(v0100)) goto v0043;
    v0100 = stack[-1];
    v0100 = qcar(v0100);
    v0100 = (consp(v0100) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0100 == nil) goto v0070;
    v0112 = stack[-2];
    v0100 = stack[-1];
    {   int32_t w = int_of_fixnum(v0100);
        if (w != 0) w = current_modulus - w;
        v0100 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0112, v0100);
    }

v0070:
    v0100 = stack[-1];
    v0100 = qcar(v0100);
    stack[0] = qcar(v0100);
    v0100 = stack[-1];
    v0100 = qcar(v0100);
    v0100 = qcdr(v0100);
    v0112 = CC_minusKmodKp(env, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0100 = stack[-2];
    v0100 = acons(stack[0], v0112, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[-2] = v0100;
    v0100 = stack[-1];
    v0100 = qcdr(v0100);
    stack[-1] = v0100;
    goto v0033;

v0043:
    v0100 = qvalue(elt(env, 1)); /* t */
    goto v0012;

v0030:
    v0100 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0100);
    }
/* error exit handlers */
v0015:
    popv(4);
    return nil;
}



/* Code for prepsq!*2 */

static Lisp_Object CC_prepsqH2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0004, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*2");
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
/* copy arguments values to proper place */
    v0032 = v0000;
/* end of prologue */
    v0012 = v0032;
    v0004 = (Lisp_Object)17; /* 1 */
    v0032 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepsq!*1 */
    v0032 = (*qfnn(fn))(qenv(fn), 3, v0012, v0004, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v0032);
    }
/* error exit handlers */
v0043:
    popv(1);
    return nil;
}



/* Code for mri_2pasfat */

static Lisp_Object CC_mri_2pasfat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_2pasfat");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0004 = stack[0];
    fn = elt(env, 2); /* mri_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    v0004 = stack[0];
    fn = elt(env, 3); /* mri_arg2l */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    v0012 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0036 = stack[-1];
        popv(3);
        return list3(v0036, v0004, v0012);
    }
/* error exit handlers */
v0035:
    popv(3);
    return nil;
}



/* Code for qqe_qtidp */

static Lisp_Object CC_qqe_qtidp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0085;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qtidp");
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
/* copy arguments values to proper place */
    v0043 = v0000;
/* end of prologue */
    v0085 = v0043;
    v0043 = elt(env, 1); /* idtype */
    v0043 = get(v0085, v0043);
    env = stack[0];
    v0085 = elt(env, 2); /* qt */
    v0043 = (v0043 == v0085 ? lisp_true : nil);
    { popv(1); return onevalue(v0043); }
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0112, v0084, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symtabget");
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
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0037 = v0001;
    v0084 = v0000;
/* end of prologue */
    v0100 = v0037;
    if (v0100 == nil) goto v0111;
    v0100 = v0084;
    if (!(v0100 == nil)) goto v0034;
    v0100 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v0100 = qcar(v0100);
    goto v0034;

v0034:
    v0084 = v0100;
    goto v0111;

v0111:
    v0100 = v0084;
    if (v0100 == nil) goto v0012;
    v0112 = v0037;
    v0100 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v0100 = Lmemq(nil, v0112, v0100);
    if (v0100 == nil) goto v0040;
    v0100 = v0084;
    v0112 = v0037;
    return get(v0100, v0112);

v0040:
    v0112 = v0037;
    v0100 = elt(env, 3); /* !*decs!* */
    v0100 = get(v0084, v0100);
    v0100 = Lassoc(nil, v0112, v0100);
    return onevalue(v0100);

v0012:
    v0100 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v0100);
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0052 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* wedgefax */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0052 = stack[0];
    fn = elt(env, 1); /* wedgefax */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    {
        Lisp_Object v0043 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* monordp */
        return (*qfn2(fn))(qenv(fn), v0043, v0052);
    }
/* error exit handlers */
v0012:
    popv(3);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0124, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putpline");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0124 = qvalue(elt(env, 1)); /* posn!* */
    v0078 = stack[0];
    v0078 = qcar(v0078);
    v0078 = qcdr(v0078);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v0124 + (int32_t)v0078 - TAG_FIXNUM);
    v0078 = qvalue(elt(env, 2)); /* nil */
    v0124 = Llinelength(nil, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    v0078 = qvalue(elt(env, 3)); /* spare!* */
    v0078 = (Lisp_Object)(int32_t)((int32_t)v0124 - (int32_t)v0078 + TAG_FIXNUM);
    v0078 = (Lisp_Object)greaterp2(stack[-1], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0078 = v0078 ? lisp_true : nil;
    env = stack[-2];
    if (v0078 == nil) goto v0071;
    v0078 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    goto v0071;

v0071:
    v0124 = qvalue(elt(env, 1)); /* posn!* */
    v0078 = qvalue(elt(env, 5)); /* orig!* */
    v0086 = (Lisp_Object)(int32_t)((int32_t)v0124 - (int32_t)v0078 + TAG_FIXNUM);
    v0124 = qvalue(elt(env, 6)); /* ycoord!* */
    v0078 = stack[0];
    v0078 = qcar(v0078);
    v0078 = qcar(v0078);
    fn = elt(env, 11); /* update!-pline */
    v0124 = (*qfnn(fn))(qenv(fn), 3, v0086, v0124, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    v0078 = qvalue(elt(env, 7)); /* pline!* */
    v0078 = Lappend(nil, v0124, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    qvalue(elt(env, 7)) = v0078; /* pline!* */
    v0124 = qvalue(elt(env, 1)); /* posn!* */
    v0078 = stack[0];
    v0078 = qcar(v0078);
    v0078 = qcdr(v0078);
    v0078 = (Lisp_Object)(int32_t)((int32_t)v0124 + (int32_t)v0078 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v0078; /* posn!* */
    v0086 = qvalue(elt(env, 8)); /* ymin!* */
    v0078 = stack[0];
    v0078 = qcdr(v0078);
    v0124 = qcar(v0078);
    v0078 = qvalue(elt(env, 6)); /* ycoord!* */
    v0078 = (Lisp_Object)(int32_t)((int32_t)v0124 + (int32_t)v0078 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v0078 = (*qfn2(fn))(qenv(fn), v0086, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0078; /* ymin!* */
    v0086 = qvalue(elt(env, 9)); /* ymax!* */
    v0078 = stack[0];
    v0078 = qcdr(v0078);
    v0124 = qcdr(v0078);
    v0078 = qvalue(elt(env, 6)); /* ycoord!* */
    v0078 = (Lisp_Object)(int32_t)((int32_t)v0124 + (int32_t)v0078 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v0078 = (*qfn2(fn))(qenv(fn), v0086, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    qvalue(elt(env, 9)) = v0078; /* ymax!* */
    v0078 = nil;
    { popv(3); return onevalue(v0078); }
/* error exit handlers */
v0114:
    popv(3);
    return nil;
}



/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0081;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domain*p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0000;
/* end of prologue */
    v0082 = v0081;
    if (v0082 == nil) goto v0111;
    v0082 = v0081;
    v0082 = (is_number(v0082) ? lisp_true : nil);
    if (!(v0082 == nil)) return onevalue(v0082);
    v0082 = v0081;
    if (!consp(v0082)) goto v0042;
    v0082 = v0081;
    v0082 = qcar(v0082);
    v0081 = qvalue(elt(env, 2)); /* domainlist!* */
    v0082 = Lmemq(nil, v0082, v0081);
    return onevalue(v0082);

v0042:
    v0082 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0082);

v0111:
    v0082 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0082);
}



/* Code for assert_analyze */

static Lisp_Object MS_CDECL CC_assert_analyze(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_analyze");
#ifdef DEBUG
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
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    v0186 = (Lisp_Object)1; /* 0 */
    stack[0] = v0186;
    v0186 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0186;
    v0186 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0186;
    v0187 = qvalue(elt(env, 1)); /* assertstatistics!* */
    v0186 = elt(env, 2); /* lambda_mcd3pw_1 */
    fn = elt(env, 8); /* sort */
    v0186 = (*qfn2(fn))(qenv(fn), v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0186; /* assertstatistics!* */
    v0186 = qvalue(elt(env, 1)); /* assertstatistics!* */
    stack[-3] = v0186;
    goto v0059;

v0059:
    v0186 = stack[-3];
    if (v0186 == nil) goto v0022;
    v0186 = stack[-3];
    v0186 = qcar(v0186);
    stack[-1] = v0186;
    v0187 = stack[0];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = plus2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = v0186;
    v0187 = stack[-4];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = plus2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[-4] = v0186;
    v0187 = stack[-2];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = plus2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[-2] = v0186;
    v0186 = stack[-3];
    v0186 = qcdr(v0186);
    stack[-3] = v0186;
    goto v0059;

v0022:
    v0186 = elt(env, 4); /* (function !#calls !#bad! calls !#assertion! violations) 
*/
    stack[-3] = v0186;
    stack[-1] = elt(env, 5); /* sum */
    v0187 = stack[-4];
    v0186 = stack[-2];
    v0186 = list2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = list2star(stack[-1], stack[0], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[-4] = qvalue(elt(env, 3)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* nil */
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    stack[0] = v0186;
    v0187 = qvalue(elt(env, 3)); /* nil */
    v0186 = qvalue(elt(env, 1)); /* assertstatistics!* */
    v0186 = cons(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = list2star(stack[-1], stack[0], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Lnreverse(nil, v0186);
    env = stack[-5];
    v0186 = cons(stack[-2], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = list2star(stack[-4], stack[-3], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0186; /* assertstatistics!* */
    v0186 = qvalue(elt(env, 1)); /* assertstatistics!* */
    stack[-2] = v0186;
    goto v0005;

v0005:
    v0186 = stack[-2];
    if (v0186 == nil) goto v0117;
    v0186 = stack[-2];
    v0186 = qcar(v0186);
    stack[-1] = v0186;
    v0186 = stack[-1];
    if (v0186 == nil) goto v0189;
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    v0186 = Lexplodec(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = Llength(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = Lexplodec(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Llength(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = plus2(stack[0], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = v0186;
    goto v0190;

v0190:
    v0187 = (Lisp_Object)369; /* 23 */
    v0186 = stack[0];
    v0186 = difference2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Lminusp(nil, v0186);
    env = stack[-5];
    if (v0186 == nil) goto v0148;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = Lexplodec(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Llength(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = v0186;
    goto v0191;

v0191:
    v0187 = (Lisp_Object)369; /* 23 */
    v0186 = stack[0];
    v0186 = difference2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Lminusp(nil, v0186);
    env = stack[-5];
    if (v0186 == nil) goto v0192;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = Lexplodec(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Llength(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = v0186;
    goto v0193;

v0193:
    v0187 = (Lisp_Object)369; /* 23 */
    v0186 = stack[0];
    v0186 = difference2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Lminusp(nil, v0186);
    env = stack[-5];
    if (v0186 == nil) goto v0194;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    goto v0195;

v0195:
    v0186 = stack[-2];
    v0186 = qcdr(v0186);
    stack[-2] = v0186;
    goto v0005;

v0194:
    v0186 = elt(env, 6); /* " " */
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = stack[0];
    v0186 = add1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = v0186;
    goto v0193;

v0192:
    v0186 = elt(env, 6); /* " " */
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = stack[0];
    v0186 = add1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = v0186;
    goto v0191;

v0148:
    v0186 = elt(env, 6); /* " " */
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = stack[0];
    v0186 = add1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = v0186;
    goto v0190;

v0189:
    v0186 = (Lisp_Object)17; /* 1 */
    stack[0] = v0186;
    goto v0196;

v0196:
    v0187 = (Lisp_Object)1153; /* 72 */
    v0186 = stack[0];
    v0186 = difference2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = Lminusp(nil, v0186);
    env = stack[-5];
    if (v0186 == nil) goto v0197;
    v0186 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    goto v0195;

v0197:
    v0186 = elt(env, 7); /* "-" */
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0186 = stack[0];
    v0186 = add1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    stack[0] = v0186;
    goto v0196;

v0117:
    v0186 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v0186; /* assertstatistics!* */
    v0186 = nil;
    { popv(6); return onevalue(v0186); }
/* error exit handlers */
v0188:
    popv(6);
    return nil;
}



/* Code for lambda_mcd3pw_1 */

static Lisp_Object CC_lambda_mcd3pw_1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_mcd3pw_1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0032 = v0001;
    v0052 = v0000;
/* end of prologue */
    v0032 = qcar(v0032);
    v0052 = qcar(v0052);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0032, v0052);
    }
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0036 = v0000;
/* end of prologue */
    v0022 = v0036;
    v0036 = stack[0];
    v0036 = qcar(v0036);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v0022 = (*qfn2(fn))(qenv(fn), v0022, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    v0036 = stack[0];
    v0036 = qcdr(v0036);
    popv(1);
    return cons(v0022, v0036);
/* error exit handlers */
v0023:
    popv(1);
    return nil;
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0054, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "insert_pv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0054,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0054);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0054;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0031:
    v0064 = stack[-1];
    if (v0064 == nil) goto v0049;
    v0064 = stack[-2];
    if (v0064 == nil) goto v0161;
    v0064 = stack[-1];
    v0064 = qcar(v0064);
    v0064 = qcar(v0064);
    v0027 = qcdr(v0064);
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = qcdr(v0064);
    v0064 = (Lisp_Object)greaterp2(v0027, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    v0064 = v0064 ? lisp_true : nil;
    env = stack[-4];
    if (v0064 == nil) goto v0099;
    v0064 = stack[-1];
    v0064 = qcdr(v0064);
    stack[-3] = v0064;
    v0064 = stack[-1];
    v0027 = qcar(v0064);
    v0064 = stack[-2];
    fn = elt(env, 2); /* reduce_pv */
    v0064 = (*qfn2(fn))(qenv(fn), v0027, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    fn = elt(env, 3); /* pv_renorm */
    v0027 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0064 = stack[0];
    v0064 = cons(v0027, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    stack[0] = v0064;
    v0064 = stack[-3];
    stack[-1] = v0064;
    goto v0031;

v0099:
    v0064 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0064;
    v0027 = stack[-2];
    v0064 = stack[0];
    v0064 = cons(v0027, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    stack[0] = v0064;
    v0064 = stack[-3];
    stack[-2] = v0064;
    goto v0031;

v0161:
    v0064 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0064;
    v0064 = stack[-1];
    v0064 = qcdr(v0064);
    stack[-3] = v0064;
    v0064 = stack[-1];
    v0027 = qcar(v0064);
    v0064 = stack[0];
    v0064 = cons(v0027, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    stack[0] = v0064;
    v0064 = stack[-3];
    stack[-1] = v0064;
    goto v0031;

v0049:
    v0064 = stack[-2];
    if (v0064 == nil) goto v0004;
    v0027 = stack[-2];
    v0064 = stack[0];
    v0064 = cons(v0027, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0115;
        popv(5);
        return Lnreverse(nil, v0064);

v0004:
    v0064 = stack[0];
        popv(5);
        return Lnreverse(nil, v0064);
/* error exit handlers */
v0115:
    popv(5);
    return nil;
}



/* Code for undefdchk */

static Lisp_Object CC_undefdchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0023, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for undefdchk");
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
/* copy arguments values to proper place */
    v0023 = v0000;
/* end of prologue */
    v0058 = v0023;
    v0059 = elt(env, 1); /* defd */
    v0059 = Lflagp(nil, v0058, v0059);
    env = stack[0];
    if (v0059 == nil) goto v0043;
    v0059 = nil;
    { popv(1); return onevalue(v0059); }

v0043:
    v0059 = qvalue(elt(env, 2)); /* undefns!* */
    v0059 = cons(v0023, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[0];
    qvalue(elt(env, 2)) = v0059; /* undefns!* */
    { popv(1); return onevalue(v0059); }
/* error exit handlers */
v0053:
    popv(1);
    return nil;
}



/* Code for polynomclone */

static Lisp_Object CC_polynomclone(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomclone");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0161 = v0000;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v0161;
    goto v0034;

v0034:
    v0161 = stack[0];
    if (v0161 == nil) goto v0030;
    v0161 = stack[0];
    v0161 = qcar(v0161);
    fn = elt(env, 2); /* monomclone */
    v0082 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0161 = stack[-1];
    v0161 = cons(v0082, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    stack[-1] = v0161;
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    stack[0] = v0161;
    goto v0034;

v0030:
    v0161 = stack[-1];
        popv(3);
        return Lreverse(nil, v0161);
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for ofsf_smwcpknowl */

static Lisp_Object CC_ofsf_smwcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0032 = v0000;
/* end of prologue */
    v0052 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0052 == nil) goto v0034;
    v0052 = v0032;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v0052);
    }

v0034:
    v0052 = v0032;
    {
        fn = elt(env, 3); /* ofsf_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
}



/* Code for stable!-sortip */

static Lisp_Object CC_stableKsortip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0206, v0207, v0208;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stable-sortip");
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
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0206 = stack[-3];
    if (v0206 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0206 = stack[-3];
    stack[-4] = v0206;
    v0206 = stack[-3];
    v0206 = qcdr(v0206);
    stack[-1] = v0206;
    v0206 = stack[-1];
    if (v0206 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0206 = stack[-1];
    v0206 = qcdr(v0206);
    stack[-3] = v0206;
    v0206 = stack[-3];
    if (v0206 == nil) goto v0057;
    v0206 = stack[-4];
    stack[-3] = v0206;
    goto v0068;

v0068:
    v0206 = stack[-1];
    if (v0206 == nil) goto v0067;
    v0208 = stack[-2];
    v0206 = stack[-1];
    v0207 = qcar(v0206);
    v0206 = stack[-3];
    v0206 = qcar(v0206);
    v0206 = Lapply2(nil, 3, v0208, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    if (!(v0206 == nil)) goto v0067;
    v0206 = stack[-1];
    stack[-3] = v0206;
    v0206 = stack[-1];
    v0206 = qcdr(v0206);
    stack[-1] = v0206;
    goto v0068;

v0067:
    v0206 = stack[-1];
    if (v0206 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0206 = stack[-4];
    stack[-1] = v0206;
    v0206 = stack[-1];
    v0206 = qcdr(v0206);
    v0206 = qcdr(v0206);
    stack[-3] = v0206;
    goto v0124;

v0124:
    v0206 = stack[-3];
    if (v0206 == nil) goto v0078;
    v0206 = stack[-3];
    v0206 = qcdr(v0206);
    if (v0206 == nil) goto v0078;
    v0206 = stack[-1];
    v0206 = qcdr(v0206);
    stack[-1] = v0206;
    v0206 = stack[-3];
    v0206 = qcdr(v0206);
    v0206 = qcdr(v0206);
    stack[-3] = v0206;
    goto v0124;

v0078:
    v0206 = stack[-1];
    stack[-3] = v0206;
    v0206 = stack[-1];
    v0206 = qcdr(v0206);
    stack[-1] = v0206;
    v0207 = stack[-3];
    v0206 = qvalue(elt(env, 1)); /* nil */
    v0206 = Lrplacd(nil, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    v0207 = stack[-4];
    v0206 = stack[-2];
    v0206 = CC_stableKsortip(env, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    stack[-4] = v0206;
    v0207 = stack[-1];
    v0206 = stack[-2];
    v0206 = CC_stableKsortip(env, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    stack[-1] = v0206;
    v0206 = qvalue(elt(env, 1)); /* nil */
    v0206 = ncons(v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    stack[0] = v0206;
    stack[-3] = v0206;
    goto v0210;

v0210:
    v0206 = stack[-4];
    if (v0206 == nil) goto v0131;
    v0206 = stack[-1];
    if (v0206 == nil) goto v0131;
    v0208 = stack[-2];
    v0206 = stack[-1];
    v0207 = qcar(v0206);
    v0206 = stack[-4];
    v0206 = qcar(v0206);
    v0206 = Lapply2(nil, 3, v0208, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    if (v0206 == nil) goto v0143;
    v0207 = stack[0];
    v0206 = stack[-1];
    v0206 = Lrplacd(nil, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    v0206 = stack[-1];
    stack[0] = v0206;
    v0206 = stack[-1];
    v0206 = qcdr(v0206);
    stack[-1] = v0206;
    goto v0210;

v0143:
    v0207 = stack[0];
    v0206 = stack[-4];
    v0206 = Lrplacd(nil, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    v0206 = stack[-4];
    stack[0] = v0206;
    v0206 = stack[-4];
    v0206 = qcdr(v0206);
    stack[-4] = v0206;
    goto v0210;

v0131:
    v0206 = stack[-4];
    if (v0206 == nil) goto v0211;
    v0206 = stack[-4];
    stack[-1] = v0206;
    goto v0211;

v0211:
    v0207 = stack[0];
    v0206 = stack[-1];
    v0206 = Lrplacd(nil, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    v0206 = stack[-3];
    v0206 = qcdr(v0206);
    { popv(6); return onevalue(v0206); }

v0057:
    v0208 = stack[-2];
    v0206 = stack[-1];
    v0207 = qcar(v0206);
    v0206 = stack[-4];
    v0206 = qcar(v0206);
    v0206 = Lapply2(nil, 3, v0208, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    if (v0206 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0206 = stack[-4];
    v0206 = qcar(v0206);
    stack[-3] = v0206;
    v0207 = stack[-4];
    v0206 = stack[-1];
    v0206 = qcar(v0206);
    v0206 = Lrplaca(nil, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    v0207 = stack[-1];
    v0206 = stack[-3];
    v0206 = Lrplaca(nil, v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v0209:
    popv(6);
    return nil;
}



/* Code for kernord */

static Lisp_Object CC_kernord(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0023 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0058 = stack[0];
    fn = elt(env, 1); /* kernord!-split */
    v0023 = (*qfn2(fn))(qenv(fn), v0058, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    stack[0] = v0023;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    fn = elt(env, 2); /* kernord!-sort */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    fn = elt(env, 2); /* kernord!-sort */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    {
        Lisp_Object v0041 = stack[-1];
        popv(3);
        return Lappend(nil, v0041, v0023);
    }
/* error exit handlers */
v0106:
    popv(3);
    return nil;
}



/* Code for ibalp_mk2 */

static Lisp_Object MS_CDECL CC_ibalp_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0054, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0012, v0043;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0054;
    v0012 = v0001;
    v0043 = v0000;
/* end of prologue */
    return list3(v0043, v0012, v0004);
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobjs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobjs");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    v0128 = qvalue(elt(env, 1)); /* char */
    v0091 = elt(env, 2); /* (!/ o m a) */
    if (equal(v0128, v0091)) goto v0110;
    fn = elt(env, 4); /* omobj */
    v0091 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    stack[0] = v0091;
    fn = elt(env, 5); /* lex */
    v0091 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    v0091 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    v0128 = stack[0];
    if (v0128 == nil) goto v0053;
    v0128 = stack[0];
    popv(2);
    return cons(v0128, v0091);

v0053:
    v0128 = stack[0];
        popv(2);
        return Lappend(nil, v0128, v0091);

v0110:
    v0091 = nil;
    { popv(2); return onevalue(v0091); }
/* error exit handlers */
v0061:
    popv(2);
    return nil;
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0003, v0205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difff");
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
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0002 = stack[-2];
    if (!consp(v0002)) goto v0034;
    v0002 = stack[-2];
    v0002 = qcar(v0002);
    if (!consp(v0002)) goto v0022;
    v0002 = stack[-2];
    v0002 = qcar(v0002);
    v0003 = qcar(v0002);
    v0002 = (Lisp_Object)17; /* 1 */
    v0002 = cons(v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    v0003 = ncons(v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    v0002 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    v0002 = stack[-2];
    v0002 = qcar(v0002);
    v0003 = qcdr(v0002);
    v0002 = stack[-1];
    v0002 = CC_difff(env, v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    v0002 = stack[-2];
    v0002 = qcar(v0002);
    v0003 = qcar(v0002);
    v0002 = stack[-1];
    fn = elt(env, 4); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    v0002 = stack[-2];
    v0002 = qcar(v0002);
    v0003 = qcdr(v0002);
    v0002 = (Lisp_Object)17; /* 1 */
    v0002 = cons(v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0002 = (*qfn2(fn))(qenv(fn), stack[0], v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    fn = elt(env, 5); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    v0002 = stack[-2];
    v0003 = qcdr(v0002);
    v0002 = stack[-1];
    v0002 = CC_difff(env, v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-4];
    {
        Lisp_Object v0021 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0021, v0002);
    }

v0022:
    v0002 = stack[-2];
    v0003 = qcar(v0002);
    v0002 = elt(env, 2); /* domain!-diff!-fn */
    v0002 = get(v0003, v0002);
    env = stack[-4];
    v0003 = v0002;
    v0002 = v0003;
    if (v0002 == nil) goto v0071;
    v0205 = v0003;
    v0003 = stack[-2];
    v0002 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v0205, v0003, v0002);

v0071:
    v0003 = qvalue(elt(env, 1)); /* nil */
    v0002 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0003, v0002);

v0034:
    v0003 = qvalue(elt(env, 1)); /* nil */
    v0002 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0003, v0002);
/* error exit handlers */
v0020:
    popv(5);
    return nil;
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*");
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
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* !*asymp!* */
    qvalue(elt(env, 1)) = nil; /* !*asymp!* */
    v0019 = stack[-2];
    v0135 = elt(env, 2); /* !*sq */
    if (!consp(v0019)) goto v0057;
    v0019 = qcar(v0019);
    if (!(v0019 == v0135)) goto v0057;
    v0135 = stack[-2];
    v0135 = qcdr(v0135);
    v0135 = qcdr(v0135);
    v0135 = qcar(v0135);
    if (v0135 == nil) goto v0058;
    v0135 = qvalue(elt(env, 4)); /* !*resimp */
    v0135 = (v0135 == nil ? lisp_true : nil);
    goto v0048;

v0048:
    if (v0135 == nil) goto v0060;
    v0135 = stack[-2];
    v0135 = qcdr(v0135);
    v0135 = qcar(v0135);
    goto v0033;

v0033:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v0135); }

v0060:
    v0019 = qvalue(elt(env, 5)); /* mul!* */
    v0135 = qvalue(elt(env, 6)); /* !*sub2 */
    v0135 = cons(v0019, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-1] = v0135;
    v0135 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 5)) = v0135; /* mul!* */
    v0135 = stack[-2];
    fn = elt(env, 14); /* simp */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-2] = v0135;
    v0135 = qvalue(elt(env, 7)); /* !*nospurp */
    if (v0135 == nil) goto v0083;
    v0019 = qvalue(elt(env, 5)); /* mul!* */
    v0135 = elt(env, 8); /* (isimpq) */
    fn = elt(env, 15); /* union */
    v0135 = (*qfn2(fn))(qenv(fn), v0019, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    qvalue(elt(env, 5)) = v0135; /* mul!* */
    goto v0083;

v0083:
    v0135 = qvalue(elt(env, 5)); /* mul!* */
    stack[0] = v0135;
    goto v0069;

v0069:
    v0135 = stack[0];
    if (v0135 == nil) goto v0051;
    v0135 = stack[0];
    v0135 = qcar(v0135);
    v0019 = v0135;
    v0135 = stack[-2];
    v0135 = Lapply1(nil, v0019, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-2] = v0135;
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    goto v0069;

v0051:
    v0135 = stack[-1];
    v0135 = qcar(v0135);
    qvalue(elt(env, 5)) = v0135; /* mul!* */
    v0135 = stack[-2];
    fn = elt(env, 16); /* subs2 */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-2] = v0135;
    v0135 = qvalue(elt(env, 9)); /* !*combinelogs */
    if (v0135 == nil) goto v0086;
    v0135 = stack[-2];
    fn = elt(env, 17); /* clogsq!* */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-2] = v0135;
    goto v0086;

v0086:
    v0019 = qvalue(elt(env, 10)); /* dmode!* */
    v0135 = elt(env, 11); /* !:gi!: */
    if (v0019 == v0135) goto v0078;
    v0135 = qvalue(elt(env, 3)); /* nil */
    goto v0087;

v0087:
    if (v0135 == nil) goto v0075;
    v0135 = stack[-2];
    fn = elt(env, 18); /* girationalize!: */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-2] = v0135;
    goto v0073;

v0073:
    v0135 = stack[-1];
    v0135 = qcdr(v0135);
    qvalue(elt(env, 6)) = v0135; /* !*sub2 */
    v0135 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v0135 == nil) goto v0122;
    v0135 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0135 == nil) goto v0122;
    v0135 = stack[-2];
    fn = elt(env, 19); /* gcdchk */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-2] = v0135;
    goto v0122;

v0122:
    v0135 = stack[-2];
    goto v0033;

v0075:
    v0135 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0135 == nil) goto v0006;
    v0135 = stack[-2];
    fn = elt(env, 20); /* rationalizesq */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-2] = v0135;
    goto v0073;

v0006:
    v0135 = stack[-2];
    fn = elt(env, 21); /* rationalizei */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    stack[-2] = v0135;
    goto v0073;

v0078:
    v0135 = qvalue(elt(env, 12)); /* !*norationalgi */
    v0135 = (v0135 == nil ? lisp_true : nil);
    goto v0087;

v0058:
    v0135 = qvalue(elt(env, 3)); /* nil */
    goto v0048;

v0057:
    v0135 = qvalue(elt(env, 3)); /* nil */
    goto v0048;
/* error exit handlers */
v0129:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsetsugar");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0082 = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0161 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0161 == nil) goto v0030;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 3); /* sugar */
    v0161 = v0082;
    if (!(v0161 == nil)) goto v0036;
    v0161 = stack[-1];
    fn = elt(env, 4); /* vdptdeg */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-3];
    goto v0036;

v0036:
    fn = elt(env, 5); /* vdpputprop */
    v0161 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0161);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    goto v0031;

v0031:
    if (v0161 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v0161); }

v0030:
    v0161 = qvalue(elt(env, 2)); /* nil */
    goto v0031;
/* error exit handlers */
v0055:
    popv(4);
    return nil;
}



/* Code for physopsim!* */

static Lisp_Object CC_physopsimH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsim*");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0128 = stack[0];
    v0091 = elt(env, 1); /* !:dn!: */
    if (!consp(v0128)) goto v0033;
    v0128 = qcar(v0128);
    if (!(v0128 == v0091)) goto v0033;
    v0091 = stack[0];
    fn = elt(env, 3); /* simp */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    v0128 = v0091;
    v0091 = v0128;
    v0091 = qcar(v0091);
    if (v0091 == nil) goto v0035;
    v0091 = elt(env, 2); /* prepf */
    {
        popv(2);
        fn = elt(env, 4); /* sqform */
        return (*qfn2(fn))(qenv(fn), v0128, v0091);
    }

v0035:
    v0091 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0091); }

v0033:
    v0091 = stack[0];
    fn = elt(env, 5); /* !*physopp!* */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    if (v0091 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0091 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* physopsm!* */
        return (*qfn1(fn))(qenv(fn), v0091);
    }
/* error exit handlers */
v0061:
    popv(2);
    return nil;
}



/* Code for argnochk */

static Lisp_Object CC_argnochk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0217, v0141, v0142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for argnochk");
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
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0000;
/* end of prologue */
    v0217 = qvalue(elt(env, 1)); /* !*argnochk */
    if (v0217 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0217 = stack[-4];
    v0141 = qcar(v0217);
    v0217 = elt(env, 2); /* number!-of!-args */
    v0217 = get(v0141, v0217);
    env = stack[-6];
    stack[-5] = v0217;
    if (v0217 == nil) goto v0218;
    stack[0] = stack[-5];
    v0217 = stack[-4];
    v0217 = qcdr(v0217);
    v0217 = Llength(nil, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    if (equal(stack[0], v0217)) goto v0013;
    v0217 = stack[-4];
    v0141 = qcar(v0217);
    v0217 = elt(env, 3); /* simpfn */
    v0217 = get(v0141, v0217);
    env = stack[-6];
    if (!(v0217 == nil)) goto v0040;
    v0217 = stack[-4];
    v0141 = qcar(v0217);
    v0217 = elt(env, 4); /* psopfn */
    v0217 = get(v0141, v0217);
    env = stack[-6];
    if (!(v0217 == nil)) goto v0040;
    v0217 = stack[-4];
    v0141 = qcar(v0217);
    v0217 = elt(env, 5); /* variadic */
    v0217 = Lflagp(nil, v0141, v0217);
    env = stack[-6];
    goto v0040;

v0040:
    v0217 = (v0217 == nil ? lisp_true : nil);
    goto v0106;

v0106:
    if (v0217 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0217 = qvalue(elt(env, 7)); /* !*strict_argcount */
    if (v0217 == nil) goto v0003;
    v0217 = elt(env, 8); /* "+++++ " */
    v0217 = Lprinc(nil, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0217 = stack[-4];
    v0217 = Lprint(nil, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0217 = stack[-4];
    stack[-2] = qcar(v0217);
    stack[-1] = elt(env, 9); /* "called with" */
    v0217 = stack[-4];
    v0217 = qcdr(v0217);
    stack[0] = Llength(nil, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0217 = stack[-4];
    v0217 = qcdr(v0217);
    v0141 = Llength(nil, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0217 = (Lisp_Object)17; /* 1 */
    if (v0141 == v0217) goto v0114;
    v0217 = elt(env, 11); /* "arguments" */
    v0142 = v0217;
    goto v0088;

v0088:
    v0141 = elt(env, 12); /* "instead of" */
    v0217 = stack[-5];
    v0217 = list3(v0142, v0141, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0217 = list3star(stack[-2], stack[-1], stack[0], v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0141 = v0217;
    v0217 = v0141;
    qvalue(elt(env, 13)) = v0217; /* errmsg!* */
    v0217 = qvalue(elt(env, 14)); /* !*protfg */
    if (!(v0217 == nil)) goto v0029;
    v0217 = v0141;
    fn = elt(env, 17); /* lprie */
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    goto v0029;

v0029:
    v0217 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    v0217 = nil;
    { popv(7); return onevalue(v0217); }

v0114:
    v0217 = elt(env, 10); /* "argument" */
    v0142 = v0217;
    goto v0088;

v0003:
    v0217 = qvalue(elt(env, 15)); /* !*msg */
    if (v0217 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-3] = elt(env, 16); /* "***" */
    v0217 = stack[-4];
    stack[-2] = qcar(v0217);
    stack[-1] = elt(env, 9); /* "called with" */
    v0217 = stack[-4];
    v0217 = qcdr(v0217);
    stack[0] = Llength(nil, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0142 = elt(env, 12); /* "instead of" */
    v0141 = stack[-5];
    v0217 = elt(env, 11); /* "arguments" */
    v0217 = list3(v0142, v0141, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0217 = list3star(stack[-2], stack[-1], stack[0], v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    fn = elt(env, 18); /* lpriw */
    v0217 = (*qfn2(fn))(qenv(fn), stack[-3], v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v0013:
    v0217 = qvalue(elt(env, 6)); /* nil */
    goto v0106;

v0218:
    v0217 = stack[-4];
    stack[-1] = qcar(v0217);
    stack[0] = elt(env, 2); /* number!-of!-args */
    v0217 = stack[-4];
    v0217 = qcdr(v0217);
    v0217 = Llength(nil, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-6];
    v0217 = Lputprop(nil, 3, stack[-1], stack[0], v0217);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
/* error exit handlers */
v0158:
    popv(7);
    return nil;
}



/* Code for groeb!=testa */

static Lisp_Object CC_groebMtesta(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testa");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0106 = v0000;
/* end of prologue */
    v0041 = v0106;
    v0106 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v0106 = (*qfn2(fn))(qenv(fn), v0041, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-2];
    stack[-1] = qcar(v0106);
    v0041 = stack[0];
    v0106 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v0106 = (*qfn2(fn))(qenv(fn), v0041, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-2];
    v0106 = qcar(v0106);
    {
        Lisp_Object v0082 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v0082, v0106);
    }
/* error exit handlers */
v0161:
    popv(3);
    return nil;
}



setup_type const u06_setup[] =
{
    {"pv_add",                  too_few_2,      CC_pv_add,     wrong_no_2},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"arzerop:",                CC_arzeropT,    too_many_1,    wrong_no_1},
    {"lto_catsoc",              too_few_2,      CC_lto_catsoc, wrong_no_2},
    {"frvarsof",                too_few_2,      CC_frvarsof,   wrong_no_2},
    {"subs3q",                  CC_subs3q,      too_many_1,    wrong_no_1},
    {"tayexp-difference",       too_few_2,      CC_tayexpKdifference,wrong_no_2},
    {"rl_prepat",               CC_rl_prepat,   too_many_1,    wrong_no_1},
    {"ibalp_calcmom",           CC_ibalp_calcmom,too_many_1,   wrong_no_1},
    {"rl_ordatp",               too_few_2,      CC_rl_ordatp,  wrong_no_2},
    {"rationalizei",            CC_rationalizei,too_many_1,    wrong_no_1},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"*collectphysops",         CC_Hcollectphysops,too_many_1, wrong_no_1},
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"dquot",                   too_few_2,      CC_dquot,      wrong_no_2},
    {"pv_sort1",                too_few_2,      CC_pv_sort1,   wrong_no_2},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"noncomdel",               too_few_2,      CC_noncomdel,  wrong_no_2},
    {"anform1",                 CC_anform1,     too_many_1,    wrong_no_1},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"algid",                   too_few_2,      CC_algid,      wrong_no_2},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"form",                    CC_form,        too_many_1,    wrong_no_1},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"prepsq*2",                CC_prepsqH2,    too_many_1,    wrong_no_1},
    {"mri_2pasfat",             CC_mri_2pasfat, too_many_1,    wrong_no_1},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"assert_analyze",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_analyze},
    {"lambda_mcd3pw_1",         too_few_2,      CC_lambda_mcd3pw_1,wrong_no_2},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"undefdchk",               CC_undefdchk,   too_many_1,    wrong_no_1},
    {"polynomclone",            CC_polynomclone,too_many_1,    wrong_no_1},
    {"ofsf_smwcpknowl",         CC_ofsf_smwcpknowl,too_many_1, wrong_no_1},
    {"stable-sortip",           too_few_2,      CC_stableKsortip,wrong_no_2},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"ibalp_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_mk2},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"physopsim*",              CC_physopsimH,  too_many_1,    wrong_no_1},
    {"argnochk",                CC_argnochk,    too_many_1,    wrong_no_1},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {NULL, (one_args *)"u06", (two_args *)"19713 7039157 6948611", 0}
};

/* end of generated code */
