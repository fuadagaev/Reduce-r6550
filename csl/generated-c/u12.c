
/* $destdir\u12.c        Machine generated C code */

/* Signature: 00000000 22-Jan-2014 */

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
#define TYPE_FOREIGN        TYPE_SPARE 
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
#ifdef DEBUG
#define SHOW_FNAME  (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)
#endif
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
extern Lisp_Object multiplication_buffer;
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem, trap_time;
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
#define trap_time             BASE[158]
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
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
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
extern void *extract_pointer(Lisp_Object a);
extern Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a);
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
#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)
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
extern Lisp_Object make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_lisp_integer32(int32_t n);
extern Lisp_Object make_lisp_integer64(int64_t n);
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
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG    LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG    void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
             kara_sem2a, kara_sem2b, kara_sem2c;
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
#  define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
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
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object Lthrow_one_value(Lisp_Object env, Lisp_Object a, Lisp_Object b);
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


/* Code for monommultiplybyvariable */

static Lisp_Object CC_monommultiplybyvariable(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0021;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monommultiplybyvariable");
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
    v0021 = stack[-2];
    v0020 = (Lisp_Object)17; /* 1 */
    v0020 = *(Lisp_Object *)((char *)v0021 + (CELL-TAG_VECTOR) + ((int32_t)v0020/(16/CELL)));
    stack[-3] = v0020;
    goto v0022;

v0022:
    v0020 = stack[-3];
    v0020 = qcar(v0020);
    if (v0020 == nil) goto v0023;
    v0020 = stack[-3];
    v0021 = qcar(v0020);
    v0020 = stack[-1];
    v0020 = (Lisp_Object)greaterp2(v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    v0020 = v0020 ? lisp_true : nil;
    env = stack[-4];
    if (v0020 == nil) goto v0023;
    v0020 = stack[-3];
    v0020 = qcdr(v0020);
    stack[-3] = v0020;
    goto v0022;

v0023:
    v0020 = stack[-3];
    v0020 = qcar(v0020);
    if (v0020 == nil) goto v0025;
    v0020 = stack[-3];
    v0021 = qcar(v0020);
    v0020 = stack[-1];
    if (!(equal(v0021, v0020))) goto v0025;

v0026:
    v0020 = nil;
    { popv(5); return onevalue(v0020); }

v0025:
    stack[0] = stack[-3];
    v0020 = stack[-3];
    v0021 = qcar(v0020);
    v0020 = stack[-3];
    v0020 = qcdr(v0020);
    v0020 = cons(v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-4];
    v0021 = Lrplacd(nil, stack[0], v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-4];
    v0020 = stack[-1];
    v0020 = Lrplaca(nil, v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-4];
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0021 = stack[-2];
    v0020 = (Lisp_Object)1; /* 0 */
    v0020 = *(Lisp_Object *)((char *)v0021 + (CELL-TAG_VECTOR) + ((int32_t)v0020/(16/CELL)));
    v0020 = add1(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0020;
    goto v0026;
/* error exit handlers */
v0024:
    popv(5);
    return nil;
}



/* Code for matrix!+p */

static Lisp_Object CC_matrixLp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0035;
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
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0034 = stack[0];
    v0035 = Llength(nil, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    v0034 = (Lisp_Object)17; /* 1 */
    v0034 = (Lisp_Object)lessp2(v0035, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    v0034 = v0034 ? lisp_true : nil;
    env = stack[-4];
    if (v0034 == nil) goto v0037;
    v0034 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0034); }

v0037:
    v0034 = stack[0];
    v0034 = qcar(v0034);
    v0034 = Llength(nil, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    stack[-3] = v0034;
    v0034 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v0034;
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[-1] = v0034;
    goto v0038;

v0038:
    v0034 = stack[-1];
    if (v0034 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0034 = stack[-1];
    v0034 = qcar(v0034);
    stack[0] = stack[-3];
    v0034 = Llength(nil, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    if (equal(stack[0], v0034)) goto v0039;
    v0034 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0034;
    goto v0039;

v0039:
    v0034 = stack[-1];
    v0034 = qcdr(v0034);
    stack[-1] = v0034;
    goto v0038;
/* error exit handlers */
v0036:
    popv(5);
    return nil;
}



/* Code for cl_varl2 */

static Lisp_Object MS_CDECL CC_cl_varl2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0105, v0106, v0107;
    Lisp_Object fn;
    Lisp_Object v0013, v0029, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_varl2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    v0013 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_varl2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0013,v0029,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0029,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0029;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */

v0108:
    v0104 = stack[-3];
    if (!consp(v0104)) goto v0109;
    v0104 = stack[-3];
    v0104 = qcar(v0104);
    goto v0110;

v0110:
    v0106 = v0104;
    v0105 = v0106;
    v0104 = elt(env, 1); /* true */
    if (v0105 == v0104) goto v0111;
    v0105 = v0106;
    v0104 = elt(env, 3); /* false */
    v0104 = (v0105 == v0104 ? lisp_true : nil);
    goto v0112;

v0112:
    if (v0104 == nil) goto v0113;
    v0105 = stack[-2];
    v0104 = stack[0];
    popv(6);
    return cons(v0105, v0104);

v0113:
    v0105 = v0106;
    v0104 = elt(env, 4); /* or */
    if (v0105 == v0104) goto v0009;
    v0105 = v0106;
    v0104 = elt(env, 5); /* and */
    v0104 = (v0105 == v0104 ? lisp_true : nil);
    goto v0114;

v0114:
    if (v0104 == nil) goto v0115;
    v0104 = qvalue(elt(env, 2)); /* t */
    goto v0025;

v0025:
    if (v0104 == nil) goto v0116;
    v0104 = qvalue(elt(env, 2)); /* t */
    goto v0035;

v0035:
    if (v0104 == nil) goto v0117;
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    stack[-3] = v0104;
    goto v0118;

v0118:
    v0104 = stack[-3];
    if (v0104 == nil) goto v0119;
    v0104 = stack[-3];
    v0104 = qcar(v0104);
    v0107 = v0104;
    v0106 = stack[-2];
    v0105 = stack[-1];
    v0104 = stack[0];
    v0104 = CC_cl_varl2(env, 4, v0107, v0106, v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-5];
    v0105 = v0104;
    v0104 = v0105;
    v0104 = qcar(v0104);
    stack[-2] = v0104;
    v0104 = v0105;
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    stack[-3] = v0104;
    goto v0118;

v0119:
    v0105 = stack[-2];
    v0104 = stack[0];
    popv(6);
    return cons(v0105, v0104);

v0117:
    v0105 = v0106;
    v0104 = elt(env, 11); /* ex */
    if (v0105 == v0104) goto v0121;
    v0105 = v0106;
    v0104 = elt(env, 12); /* all */
    v0104 = (v0105 == v0104 ? lisp_true : nil);
    goto v0122;

v0122:
    if (v0104 == nil) goto v0123;
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    stack[-4] = qcar(v0104);
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    v0105 = qcar(v0104);
    v0104 = stack[-1];
    fn = elt(env, 15); /* lto_insertq */
    v0105 = (*qfn2(fn))(qenv(fn), v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-5];
    v0104 = stack[0];
    stack[-3] = stack[-4];
    stack[-1] = v0105;
    stack[0] = v0104;
    goto v0108;

v0123:
    v0105 = v0106;
    v0104 = elt(env, 13); /* bex */
    if (v0105 == v0104) goto v0124;
    v0105 = v0106;
    v0104 = elt(env, 14); /* ball */
    v0104 = (v0105 == v0104 ? lisp_true : nil);
    goto v0125;

v0125:
    if (v0104 == nil) goto v0126;
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    v0105 = qcar(v0104);
    v0104 = stack[-1];
    fn = elt(env, 15); /* lto_insertq */
    v0104 = (*qfn2(fn))(qenv(fn), v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-5];
    stack[-1] = v0104;
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    v0107 = qcar(v0104);
    v0106 = stack[-2];
    v0105 = stack[-1];
    v0104 = stack[0];
    v0104 = CC_cl_varl2(env, 4, v0107, v0106, v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-5];
    v0105 = v0104;
    v0104 = v0105;
    v0104 = qcar(v0104);
    stack[-2] = v0104;
    v0104 = v0105;
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    stack[-4] = qcar(v0104);
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    v0105 = qcar(v0104);
    v0104 = stack[-1];
    fn = elt(env, 15); /* lto_insertq */
    v0105 = (*qfn2(fn))(qenv(fn), v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-5];
    v0104 = stack[0];
    stack[-3] = stack[-4];
    stack[-1] = v0105;
    stack[0] = v0104;
    goto v0108;

v0126:
    v0104 = stack[-3];
    fn = elt(env, 16); /* rl_varlat */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-5];
    stack[-3] = v0104;
    goto v0127;

v0127:
    v0104 = stack[-3];
    if (v0104 == nil) goto v0128;
    v0104 = stack[-3];
    v0104 = qcar(v0104);
    v0106 = v0104;
    v0105 = v0106;
    v0104 = stack[-1];
    v0104 = Lmemq(nil, v0105, v0104);
    if (v0104 == nil) goto v0129;
    v0105 = v0106;
    v0104 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    v0104 = (*qfn2(fn))(qenv(fn), v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-5];
    stack[0] = v0104;
    goto v0130;

v0130:
    v0104 = stack[-3];
    v0104 = qcdr(v0104);
    stack[-3] = v0104;
    goto v0127;

v0129:
    v0105 = v0106;
    v0104 = stack[-2];
    fn = elt(env, 15); /* lto_insertq */
    v0104 = (*qfn2(fn))(qenv(fn), v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-5];
    stack[-2] = v0104;
    goto v0130;

v0128:
    v0105 = stack[-2];
    v0104 = stack[0];
    popv(6);
    return cons(v0105, v0104);

v0124:
    v0104 = qvalue(elt(env, 2)); /* t */
    goto v0125;

v0121:
    v0104 = qvalue(elt(env, 2)); /* t */
    goto v0122;

v0116:
    v0105 = v0106;
    v0104 = elt(env, 7); /* impl */
    if (v0105 == v0104) goto v0131;
    v0105 = v0106;
    v0104 = elt(env, 8); /* repl */
    if (v0105 == v0104) goto v0132;
    v0105 = v0106;
    v0104 = elt(env, 9); /* equiv */
    v0104 = (v0105 == v0104 ? lisp_true : nil);
    goto v0035;

v0132:
    v0104 = qvalue(elt(env, 2)); /* t */
    goto v0035;

v0131:
    v0104 = qvalue(elt(env, 2)); /* t */
    goto v0035;

v0115:
    v0105 = v0106;
    v0104 = elt(env, 6); /* not */
    v0104 = (v0105 == v0104 ? lisp_true : nil);
    goto v0025;

v0009:
    v0104 = qvalue(elt(env, 2)); /* t */
    goto v0114;

v0111:
    v0104 = qvalue(elt(env, 2)); /* t */
    goto v0112;

v0109:
    v0104 = stack[-3];
    goto v0110;
/* error exit handlers */
v0120:
    popv(6);
    return nil;
}



/* Code for rat_sgn */

static Lisp_Object CC_rat_sgn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rat_sgn");
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
    v0061 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* rat_numrn */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* sgn */
        return (*qfn1(fn))(qenv(fn), v0061);
    }
/* error exit handlers */
v0133:
    popv(1);
    return nil;
}



/* Code for numeric!-content */

static Lisp_Object CC_numericKcontent(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0025, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numeric-content");
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

v0031:
    v0007 = stack[0];
    if (!consp(v0007)) goto v0018;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0007 = (consp(v0007) ? nil : lisp_true);
    goto v0109;

v0109:
    if (v0007 == nil) goto v0037;
    v0007 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* absf */
        return (*qfn1(fn))(qenv(fn), v0007);
    }

v0037:
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    if (v0007 == nil) goto v0093;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0007 = qcdr(v0007);
    v0007 = CC_numericKcontent(env, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    v0036 = v0007;
    v0025 = v0036;
    v0007 = (Lisp_Object)17; /* 1 */
    if (v0025 == v0007) { popv(3); return onevalue(v0036); }
    stack[-1] = v0036;
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    v0007 = CC_numericKcontent(env, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    fn = elt(env, 3); /* gcddd */
    v0007 = (*qfn2(fn))(qenv(fn), stack[-1], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0036 = v0007;
    { popv(3); return onevalue(v0036); }

v0093:
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0031;

v0018:
    v0007 = qvalue(elt(env, 1)); /* t */
    goto v0109;
/* error exit handlers */
v0114:
    popv(3);
    return nil;
}



/* Code for omiir */

static Lisp_Object MS_CDECL CC_omiir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omiir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omiir");
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
    fn = elt(env, 2); /* lex */
    v0110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    v0110 = qvalue(elt(env, 1)); /* char */
    v0110 = Lcompress(nil, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    stack[0] = v0110;
    fn = elt(env, 2); /* lex */
    v0110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0018:
    popv(2);
    return nil;
}



/* Code for testredh */

static Lisp_Object CC_testredh(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testredh");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0009 = qvalue(elt(env, 2)); /* maxvar */
    v0114 = stack[0];
    v0114 = plus2(v0009, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-2];
    v0009 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0114/(16/CELL)));
    v0114 = (Lisp_Object)1; /* 0 */
    v0114 = *(Lisp_Object *)((char *)v0009 + (CELL-TAG_VECTOR) + ((int32_t)v0114/(16/CELL)));
    if (v0114 == nil) goto v0061;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0009 = qvalue(elt(env, 2)); /* maxvar */
    v0114 = stack[0];
    v0114 = plus2(v0009, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-2];
    v0009 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0114/(16/CELL)));
    v0114 = (Lisp_Object)17; /* 1 */
    v0114 = *(Lisp_Object *)((char *)v0009 + (CELL-TAG_VECTOR) + ((int32_t)v0114/(16/CELL)));
    v0114 = qcar(v0114);
    v0009 = qcar(v0114);
    v0114 = (Lisp_Object)33; /* 2 */
    v0114 = (Lisp_Object)lessp2(v0009, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    v0114 = v0114 ? lisp_true : nil;
    env = stack[-2];
    if (v0114 == nil) goto v0061;
    v0114 = stack[0];
    fn = elt(env, 3); /* rowdel */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-2];
    v0114 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* testredzz */
        return (*qfn1(fn))(qenv(fn), v0114);
    }

v0061:
    v0114 = nil;
    { popv(3); return onevalue(v0114); }
/* error exit handlers */
v0143:
    popv(3);
    return nil;
}



/* Code for off */

static Lisp_Object CC_off(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for off");
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
    v0144 = v0000;
/* end of prologue */
    stack[0] = v0144;
    goto v0061;

v0061:
    v0144 = stack[0];
    if (v0144 == nil) goto v0110;
    v0144 = stack[0];
    v0144 = qcar(v0144);
    fn = elt(env, 2); /* off1 */
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    v0144 = stack[0];
    v0144 = qcdr(v0144);
    stack[0] = v0144;
    goto v0061;

v0110:
    v0144 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0144); }
/* error exit handlers */
v0093:
    popv(2);
    return nil;
}



/* Code for statep!* */

static Lisp_Object CC_statepH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for statep*");
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
    v0018 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* getphystype */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[0];
    v0019 = elt(env, 1); /* state */
    v0018 = (v0018 == v0019 ? lisp_true : nil);
    { popv(1); return onevalue(v0018); }
/* error exit handlers */
v0146:
    popv(1);
    return nil;
}



/* Code for assert_typesyntaxp */

static Lisp_Object CC_assert_typesyntaxp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_typesyntaxp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0147 = v0000;
/* end of prologue */
    v0146 = qvalue(elt(env, 1)); /* !*assert */
    if (v0146 == nil) goto v0110;
    v0146 = v0147;
    {
        fn = elt(env, 2); /* assert_dyntypep */
        return (*qfn1(fn))(qenv(fn), v0146);
    }

v0110:
    v0146 = v0147;
        return Lsymbolp(nil, v0146);
}



/* Code for bc_fi */

static Lisp_Object CC_bc_fi(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0142, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_fi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0000;
/* end of prologue */
    v0142 = v0033;
    v0032 = (Lisp_Object)1; /* 0 */
    if (!(v0142 == v0032)) return onevalue(v0033);
    v0032 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0032);
}



/* Code for pdif */

static Lisp_Object CC_pdif(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pdif");
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
    v0019 = v0001;
    v0146 = v0000;
/* end of prologue */
    stack[0] = v0146;
    fn = elt(env, 1); /* pneg */
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    {
        Lisp_Object v0022 = stack[0];
        popv(2);
        fn = elt(env, 2); /* psum */
        return (*qfn2(fn))(qenv(fn), v0022, v0019);
    }
/* error exit handlers */
v0023:
    popv(2);
    return nil;
}



/* Code for remflagss */

static Lisp_Object CC_remflagss(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0038, v0148, v0149;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remflagss");
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
    v0141 = v0001;
    v0148 = v0000;
/* end of prologue */
    v0149 = v0141;
    goto v0133;

v0133:
    v0141 = v0149;
    if (v0141 == nil) goto v0109;
    v0141 = v0149;
    v0141 = qcar(v0141);
    v0038 = v0148;
    v0141 = Lremflag(nil, v0038, v0141);
    env = stack[0];
    v0141 = v0149;
    v0141 = qcdr(v0141);
    v0149 = v0141;
    goto v0133;

v0109:
    v0141 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0141); }
}



/* Code for kernp */

static Lisp_Object CC_kernp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0151, v0012;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0151 = v0000;
/* end of prologue */
    v0011 = v0151;
    v0012 = qcdr(v0011);
    v0011 = (Lisp_Object)17; /* 1 */
    if (v0012 == v0011) goto v0031;
    v0011 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0011);

v0031:
    v0011 = v0151;
    v0011 = qcar(v0011);
    v0151 = v0011;
    v0012 = v0011;
    v0011 = v0012;
    if (!consp(v0011)) goto v0112;
    v0011 = v0012;
    v0011 = qcar(v0011);
    v0011 = (consp(v0011) ? nil : lisp_true);
    goto v0093;

v0093:
    if (v0011 == nil) goto v0022;
    v0011 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0011);

v0022:
    v0011 = v0151;
    v0011 = qcdr(v0011);
    if (v0011 == nil) goto v0094;
    v0011 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0011);

v0094:
    v0011 = v0151;
    v0011 = qcar(v0011);
    v0012 = qcdr(v0011);
    v0011 = (Lisp_Object)17; /* 1 */
    if (v0012 == v0011) goto v0092;
    v0011 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0011);

v0092:
    v0011 = v0151;
    v0011 = qcar(v0011);
    v0011 = qcar(v0011);
    v0151 = qcdr(v0011);
    v0011 = (Lisp_Object)17; /* 1 */
    v0011 = (v0151 == v0011 ? lisp_true : nil);
    return onevalue(v0011);

v0112:
    v0011 = qvalue(elt(env, 1)); /* t */
    goto v0093;
}



/* Code for gcdf2 */

static Lisp_Object CC_gcdf2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0051, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf2");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* asymplis!* */
    qvalue(elt(env, 1)) = nil; /* asymplis!* */
    v0050 = qvalue(elt(env, 2)); /* !*anygcd */
    if (v0050 == nil) goto v0147;
    v0050 = stack[-5];
    fn = elt(env, 6); /* num!-exponents */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    if (v0050 == nil) goto v0093;
    v0050 = stack[-4];
    fn = elt(env, 6); /* num!-exponents */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0050 = (v0050 == nil ? lisp_true : nil);
    goto v0146;

v0146:
    if (v0050 == nil) goto v0110;
    v0050 = (Lisp_Object)17; /* 1 */
    goto v0145;

v0145:
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    { popv(8); return onevalue(v0050); }

v0110:
    v0050 = qvalue(elt(env, 4)); /* !*gcd */
    if (v0050 == nil) goto v0180;
    v0051 = stack[-5];
    v0050 = stack[-4];
    fn = elt(env, 7); /* kernord */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-3] = v0050;
    v0051 = Llength(nil, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0050 = (Lisp_Object)17; /* 1 */
    v0050 = (Lisp_Object)greaterp2(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0050 = v0050 ? lisp_true : nil;
    env = stack[-7];
    if (v0050 == nil) goto v0180;
    v0050 = stack[-3];
    fn = elt(env, 8); /* setkorder */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0050 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-3] = v0050;
    v0050 = stack[-5];
    fn = elt(env, 9); /* reorder */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-5] = v0050;
    v0050 = stack[-4];
    fn = elt(env, 9); /* reorder */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-4] = v0050;
    goto v0181;

v0181:
    v0050 = stack[-5];
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0051 = qcar(v0050);
    v0050 = stack[-4];
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    if (v0051 == v0050) goto v0113;
    v0050 = stack[-5];
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    fn = elt(env, 10); /* noncomp */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    if (v0050 == nil) goto v0182;
    v0050 = stack[-4];
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    fn = elt(env, 10); /* noncomp */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    if (v0050 == nil) goto v0182;
    v0096 = stack[-5];
    v0051 = stack[-4];
    v0050 = stack[-4];
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    fn = elt(env, 11); /* gcdfnc */
    v0050 = (*qfnn(fn))(qenv(fn), 3, v0096, v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0010;

v0010:
    v0050 = stack[-3];
    if (v0050 == nil) goto v0099;
    v0050 = stack[-3];
    v0050 = qcar(v0050);
    fn = elt(env, 8); /* setkorder */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0050 = stack[-2];
    fn = elt(env, 9); /* reorder */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0099;

v0099:
    v0050 = stack[-2];
    goto v0145;

v0182:
    v0050 = stack[-5];
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0051 = qcar(v0050);
    v0050 = stack[-4];
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    fn = elt(env, 12); /* ordop */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    if (v0050 == nil) goto v0183;
    v0050 = stack[-5];
    fn = elt(env, 13); /* comfac */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0051 = qcdr(v0050);
    v0050 = stack[-4];
    fn = elt(env, 14); /* gcdf1 */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0010;

v0183:
    v0050 = stack[-4];
    fn = elt(env, 13); /* comfac */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0051 = qcdr(v0050);
    v0050 = stack[-5];
    fn = elt(env, 14); /* gcdf1 */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0010;

v0113:
    v0050 = stack[-5];
    fn = elt(env, 13); /* comfac */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-1] = v0050;
    v0050 = stack[-4];
    fn = elt(env, 13); /* comfac */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[0] = v0050;
    v0050 = stack[-1];
    v0051 = qcdr(v0050);
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    fn = elt(env, 14); /* gcdf1 */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    v0050 = stack[-1];
    fn = elt(env, 15); /* comfac!-to!-poly */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    fn = elt(env, 16); /* quotf1 */
    v0050 = (*qfn2(fn))(qenv(fn), stack[-5], v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-5] = v0050;
    v0050 = stack[0];
    fn = elt(env, 15); /* comfac!-to!-poly */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    fn = elt(env, 16); /* quotf1 */
    v0050 = (*qfn2(fn))(qenv(fn), stack[-4], v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-4] = v0050;
    v0050 = qvalue(elt(env, 4)); /* !*gcd */
    if (v0050 == nil) goto v0184;
    v0051 = stack[-5];
    v0050 = stack[-4];
    fn = elt(env, 17); /* gcdk */
    v0051 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0050 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0185;

v0185:
    v0050 = stack[-1];
    v0050 = qcar(v0050);
    if (v0050 == nil) goto v0010;
    v0050 = stack[0];
    v0050 = qcar(v0050);
    if (v0050 == nil) goto v0010;
    v0050 = stack[-1];
    v0050 = qcar(v0050);
    v0051 = qcdr(v0050);
    v0050 = stack[0];
    v0050 = qcar(v0050);
    v0050 = qcdr(v0050);
    v0050 = (Lisp_Object)greaterp2(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0050 = v0050 ? lisp_true : nil;
    env = stack[-7];
    if (v0050 == nil) goto v0100;
    v0050 = stack[0];
    v0051 = qcar(v0050);
    v0050 = (Lisp_Object)17; /* 1 */
    v0050 = cons(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0051 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0050 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0010;

v0100:
    v0050 = stack[-1];
    v0051 = qcar(v0050);
    v0050 = (Lisp_Object)17; /* 1 */
    v0050 = cons(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0051 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    v0050 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0010;

v0184:
    v0050 = stack[-4];
    if (v0050 == nil) goto v0186;
    v0051 = stack[-5];
    v0050 = stack[-4];
    fn = elt(env, 16); /* quotf1 */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    if (v0050 == nil) goto v0186;
    v0051 = stack[-4];
    v0050 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0185;

v0186:
    v0050 = stack[-5];
    if (v0050 == nil) goto v0185;
    v0051 = stack[-4];
    v0050 = stack[-5];
    fn = elt(env, 16); /* quotf1 */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    if (v0050 == nil) goto v0185;
    v0051 = stack[-5];
    v0050 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-7];
    stack[-2] = v0050;
    goto v0185;

v0180:
    v0050 = qvalue(elt(env, 5)); /* nil */
    stack[-3] = v0050;
    goto v0181;

v0093:
    v0050 = qvalue(elt(env, 3)); /* t */
    goto v0146;

v0147:
    v0050 = qvalue(elt(env, 3)); /* t */
    goto v0146;
/* error exit handlers */
v0179:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    popv(8);
    return nil;
}



/* Code for ratpoly_red */

static Lisp_Object CC_ratpoly_red(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratpoly_red");
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
    stack[0] = v0000;
/* end of prologue */
    v0146 = stack[0];
    v0146 = qcar(v0146);
    fn = elt(env, 1); /* sfto_redx */
    v0147 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0146 = stack[0];
    v0146 = qcdr(v0146);
    popv(1);
    return cons(v0147, v0146);
/* error exit handlers */
v0022:
    popv(1);
    return nil;
}



/* Code for smtp */

static Lisp_Object CC_smtp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0204, v0163, v0205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smtp");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0203 = stack[0];
    if (!consp(v0203)) goto v0022;
    v0204 = stack[0];
    v0203 = elt(env, 1); /* sparsemat */
    if (!consp(v0204)) goto v0206;
    v0204 = qcar(v0204);
    if (!(v0204 == v0203)) goto v0206;
    v0203 = stack[0];
    stack[-7] = v0203;
    v0203 = stack[-7];
    v0203 = qcdr(v0203);
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    v0204 = v0203;
    goto v0023;

v0023:
    v0203 = v0204;
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    stack[-4] = v0203;
    v0203 = v0204;
    v0203 = qcdr(v0203);
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    stack[-1] = v0203;
    v0163 = elt(env, 2); /* spm */
    v0204 = v0203;
    v0203 = stack[-4];
    v0203 = list3(v0163, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    fn = elt(env, 7); /* mkempspmat */
    v0203 = (*qfn2(fn))(qenv(fn), stack[-1], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-5] = v0203;
    v0204 = stack[-7];
    v0203 = elt(env, 1); /* sparsemat */
    if (!consp(v0204)) goto v0207;
    v0204 = qcar(v0204);
    if (!(v0204 == v0203)) goto v0207;
    v0203 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0203;
    goto v0208;

v0208:
    v0204 = stack[-4];
    v0203 = stack[-1];
    v0203 = difference2(v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0203 = Lminusp(nil, v0203);
    env = stack[-8];
    if (!(v0203 == nil)) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v0204 = stack[-7];
    v0203 = stack[-1];
    fn = elt(env, 8); /* findrow */
    v0203 = (*qfn2(fn))(qenv(fn), v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0204 = v0203;
    v0203 = v0204;
    if (v0203 == nil) goto v0209;
    v0203 = stack[-1];
    stack[-3] = v0203;
    v0203 = v0204;
    v0203 = qcdr(v0203);
    stack[0] = v0203;
    goto v0210;

v0210:
    v0203 = stack[0];
    if (v0203 == nil) goto v0209;
    v0203 = stack[0];
    v0203 = qcar(v0203);
    v0204 = v0203;
    v0203 = v0204;
    v0203 = qcar(v0203);
    v0204 = qcdr(v0204);
    stack[-2] = v0204;
    v0163 = stack[-5];
    v0204 = v0203;
    v0203 = stack[-3];
    v0205 = list3(v0163, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0163 = stack[-2];
    v0204 = stack[-5];
    v0203 = stack[-6];
    fn = elt(env, 9); /* letmtr3 */
    v0203 = (*qfnn(fn))(qenv(fn), 4, v0205, v0163, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0203 = stack[0];
    v0203 = qcdr(v0203);
    stack[0] = v0203;
    goto v0210;

v0209:
    v0203 = stack[-1];
    v0203 = add1(v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-1] = v0203;
    goto v0208;

v0207:
    stack[-2] = elt(env, 3); /* matrix */
    stack[-1] = (Lisp_Object)33; /* 2 */
    v0163 = elt(env, 4); /* "Matrix" */
    v0204 = stack[0];
    v0203 = elt(env, 5); /* "not set" */
    v0203 = list3(v0163, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    fn = elt(env, 10); /* rerror */
    v0203 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }

v0206:
    v0203 = stack[0];
    v0203 = qcdr(v0203);
    v0204 = qcar(v0203);
    v0203 = stack[-6];
    v0203 = CC_smtp(env, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-7] = v0203;
    v0203 = stack[-7];
    v0203 = qcdr(v0203);
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    v0204 = v0203;
    goto v0023;

v0022:
    v0203 = stack[0];
    if (!symbolp(v0203)) v0203 = nil;
    else { v0203 = qfastgets(v0203);
           if (v0203 != nil) { v0203 = elt(v0203, 4); /* avalue */
#ifdef RECORD_GET
             if (v0203 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0203 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0203 == SPID_NOPROP) v0203 = nil; }}
#endif
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    stack[-7] = v0203;
    v0203 = stack[-7];
    v0203 = qcdr(v0203);
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    v0204 = v0203;
    goto v0023;
/* error exit handlers */
v0161:
    popv(9);
    return nil;
}



/* Code for maxtype */

static Lisp_Object CC_maxtype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0150;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxtype");
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
    v0150 = v0000;
/* end of prologue */
    v0144 = v0150;
    if (!consp(v0144)) return onevalue(v0150);
    v0144 = v0150;
    v0144 = qcdr(v0144);
    v0144 = Lconsp(nil, v0144);
    if (v0144 == nil) goto v0022;
    v0144 = v0150;
    v0144 = qcdr(v0144);
    v0144 = qcar(v0144);
    return onevalue(v0144);

v0022:
    v0144 = v0150;
    v0144 = qcar(v0144);
    return onevalue(v0144);
}



/* Code for unbind */

static Lisp_Object CC_unbind(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0022, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unbind");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0022 = v0000;
/* end of prologue */
    v0023 = v0022;
    v0032 = elt(env, 1); /* binding */
    if (!symbolp(v0022)) v0022 = nil;
    else { v0022 = qfastgets(v0022);
           if (v0022 != nil) { v0022 = elt(v0022, 13); /* binding */
#ifdef RECORD_GET
             if (v0022 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v0022 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v0022 == SPID_NOPROP) v0022 = nil; }}
#endif
    v0022 = qcdr(v0022);
        return Lputprop(nil, 3, v0023, v0032, v0022);
}



/* Code for bcquot */

static Lisp_Object CC_bcquot(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0180, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcquot");
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
    v0036 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0036 == nil) goto v0133;
    v0036 = stack[0];
    v0036 = Lmodular_reciprocal(nil, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0036 = times2(stack[-1], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0036);
    }

v0133:
    v0036 = qvalue(elt(env, 2)); /* !*vdpinteger */
    if (v0036 == nil) goto v0134;
    v0088 = stack[-1];
    v0180 = stack[0];
    v0036 = elt(env, 3); /* quotientx */
    fn = elt(env, 5); /* bcint2op */
    v0036 = (*qfnn(fn))(qenv(fn), 3, v0088, v0180, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    if (!(v0036 == nil)) { popv(3); return onevalue(v0036); }
    v0036 = stack[-1];
    v0180 = qcar(v0036);
    v0036 = stack[0];
    v0036 = qcar(v0036);
    fn = elt(env, 6); /* quotfx */
    v0180 = (*qfn2(fn))(qenv(fn), v0180, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    v0036 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0180, v0036);

v0134:
    v0180 = stack[-1];
    v0036 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v0180, v0036);
    }
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for set!-ordp */

static Lisp_Object CC_setKordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0149, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0149 = v0001;
    v0095 = v0000;
/* end of prologue */
    v0148 = v0095;
    if (!(is_number(v0148))) goto v0093;
    v0148 = v0149;
    if (!(is_number(v0148))) goto v0093;
    v0148 = v0095;
        return Llessp(nil, v0148, v0149);

v0093:
    v0148 = v0095;
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0148, v0149);
    }
}



/* Code for revalind */

static Lisp_Object CC_revalind(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0038, v0148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revalind");
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
    stack[0] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v0141 = qvalue(elt(env, 2)); /* nil */
    v0141 = ncons(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0141; /* alglist!* */
    v0141 = qvalue(elt(env, 3)); /* subfg!* */
    stack[-2] = v0141;
    v0141 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v0141; /* subfg!* */
    v0148 = elt(env, 4); /* !0 */
    v0038 = (Lisp_Object)1; /* 0 */
    v0141 = stack[-1];
    v0141 = Lsubst(nil, 3, v0148, v0038, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    stack[-1] = v0141;
    v0141 = stack[-1];
    fn = elt(env, 5); /* simp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    fn = elt(env, 6); /* prepsq */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0038 = v0141;
    v0141 = stack[-2];
    qvalue(elt(env, 3)) = v0141; /* subfg!* */
    v0141 = v0038;
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    { popv(4); return onevalue(v0141); }
/* error exit handlers */
v0017:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for assert_dyntypep */

static Lisp_Object CC_assert_dyntypep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_dyntypep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0000;
/* end of prologue */
    v0142 = v0033;
    if (symbolp(v0142)) goto v0018;
    v0142 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0142);

v0018:
    v0142 = v0033;
    v0033 = elt(env, 2); /* assert_dyntype */
        return Lflagp(nil, v0142, v0033);
}



/* Code for aminusp!: */

static Lisp_Object CC_aminuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aminusp:");
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
    v0007 = qvalue(elt(env, 1)); /* !*modular */
    if (v0007 == nil) goto v0150;
    v0025 = elt(env, 2); /* modular */
    v0007 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 7); /* setdmode */
    v0007 = (*qfn2(fn))(qenv(fn), v0025, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    stack[-2] = v0007;
    goto v0150;

v0150:
    stack[0] = elt(env, 4); /* aminusp!:1 */
    v0007 = stack[-1];
    v0007 = Lmkquote(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    v0007 = list2(stack[0], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    fn = elt(env, 8); /* errorset2 */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    stack[0] = v0007;
    v0007 = stack[-2];
    if (v0007 == nil) goto v0149;
    v0025 = elt(env, 2); /* modular */
    v0007 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 7); /* setdmode */
    v0007 = (*qfn2(fn))(qenv(fn), v0025, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    goto v0149;

v0149:
    v0007 = stack[0];
    fn = elt(env, 9); /* errorp */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    if (v0007 == nil) goto v0034;
    v0025 = stack[-1];
    v0007 = elt(env, 6); /* "arithmetic expression" */
    fn = elt(env, 10); /* typerr */
    v0007 = (*qfn2(fn))(qenv(fn), v0025, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0007 = nil;
    { popv(4); return onevalue(v0007); }

v0034:
    v0007 = stack[0];
    v0007 = qcar(v0007);
    { popv(4); return onevalue(v0007); }
/* error exit handlers */
v0114:
    popv(4);
    return nil;
}



/* Code for dp!=mocompare */

static Lisp_Object CC_dpMmocompare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=mocompare");
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
    v0144 = v0001;
    v0150 = v0000;
/* end of prologue */
    v0150 = qcar(v0150);
    v0144 = qcar(v0144);
    fn = elt(env, 1); /* mo_compare */
    v0150 = (*qfn2(fn))(qenv(fn), v0150, v0144);
    errexit();
    v0144 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v0150, v0144);
}



/* Code for artimes!: */

static Lisp_Object CC_artimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0141, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for artimes:");
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
    v0141 = v0001;
    v0038 = v0000;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v0140 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v0140; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v0140 = v0038;
    v0140 = qcdr(v0140);
    v0141 = qcdr(v0141);
    fn = elt(env, 5); /* multf */
    v0140 = (*qfn2(fn))(qenv(fn), v0140, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    fn = elt(env, 6); /* reducepowers */
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    v0140 = cons(stack[0], v0140);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v0140); }
/* error exit handlers */
v0016:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for remcomma */

static Lisp_Object CC_remcomma(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0150, v0093;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remcomma");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0150 = v0000;
/* end of prologue */
    v0144 = v0150;
    v0093 = elt(env, 1); /* !*comma!* */
    if (!consp(v0144)) goto v0022;
    v0144 = qcar(v0144);
    if (!(v0144 == v0093)) goto v0022;
    v0144 = v0150;
    v0144 = qcdr(v0144);
    return onevalue(v0144);

v0022:
    v0144 = v0150;
    return ncons(v0144);
}



/* Code for var_list */

static Lisp_Object MS_CDECL CC_var_list(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0213;
    Lisp_Object fn;
    Lisp_Object v0029, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "var_list");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for var_list");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0029,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-3] = v0001;
    v0002 = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = v0002;
    goto v0018;

v0018:
    v0002 = stack[-1];
    if (v0002 == nil) goto v0109;
    v0002 = stack[-1];
    v0002 = qcar(v0002);
    v0213 = v0002;
    v0002 = elt(env, 2); /* vars */
    v0213 = get(v0213, v0002);
    env = stack[-5];
    v0002 = stack[-4];
    fn = elt(env, 3); /* union */
    v0002 = (*qfn2(fn))(qenv(fn), v0213, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    stack[-4] = v0002;
    v0002 = stack[-1];
    v0002 = qcdr(v0002);
    stack[-1] = v0002;
    goto v0018;

v0109:
    v0002 = stack[0];
    stack[-1] = v0002;
    goto v0094;

v0094:
    v0002 = stack[-1];
    if (v0002 == nil) goto v0039;
    v0002 = stack[-1];
    v0002 = qcar(v0002);
    stack[0] = v0002;
    v0213 = stack[0];
    v0002 = stack[-4];
    v0002 = Lmember(nil, v0213, v0002);
    if (!(v0002 == nil)) goto v0012;
    v0213 = stack[-3];
    v0002 = stack[0];
    fn = elt(env, 4); /* my_freeof */
    v0002 = (*qfn2(fn))(qenv(fn), v0213, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    if (!(v0002 == nil)) goto v0139;

v0012:
    v0213 = stack[0];
    v0002 = stack[-2];
    v0002 = cons(v0213, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    stack[-2] = v0002;
    goto v0139;

v0139:
    v0002 = stack[-1];
    v0002 = qcdr(v0002);
    stack[-1] = v0002;
    goto v0094;

v0039:
    v0002 = stack[-2];
        popv(6);
        return Lreverse(nil, v0002);
/* error exit handlers */
v0006:
    popv(6);
    return nil;
}



/* Code for pasf_smwupdknowl */

static Lisp_Object MS_CDECL CC_pasf_smwupdknowl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0212, v0039, v0094, v0216, v0217;
    Lisp_Object fn;
    Lisp_Object v0013, v0029, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwupdknowl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    v0013 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smwupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0039 = v0013;
    v0094 = v0029;
    v0216 = v0001;
    v0217 = v0000;
/* end of prologue */
    v0212 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0212 == nil) goto v0141;
    v0212 = v0217;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0212, v0216, v0094, v0039);
    }

v0141:
    v0212 = v0217;
    {
        fn = elt(env, 3); /* cl_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0212, v0216, v0094, v0039);
    }
}



/* Code for ibalp_clauselp */

static Lisp_Object CC_ibalp_clauselp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_clauselp");
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

v0108:
    v0112 = stack[0];
    if (v0112 == nil) goto v0031;
    v0112 = stack[0];
    v0112 = qcar(v0112);
    fn = elt(env, 3); /* ibalp_clausep */
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    if (v0112 == nil) goto v0019;
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    stack[0] = v0112;
    goto v0108;

v0019:
    v0112 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0112); }

v0031:
    v0112 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0112); }
/* error exit handlers */
v0030:
    popv(2);
    return nil;
}



/* Code for unchecked_getmatelem */

static Lisp_Object CC_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0088, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unchecked_getmatelem");
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
    v0180 = stack[-1];
    v0088 = qcar(v0180);
    v0114 = v0088;
    v0180 = elt(env, 1); /* mat */
    if (!consp(v0088)) goto v0033;
    v0088 = qcar(v0088);
    if (!(v0088 == v0180)) goto v0033;
    v0180 = v0114;
    v0088 = qcdr(v0180);
    v0180 = stack[-1];
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    fn = elt(env, 5); /* nth */
    v0088 = (*qfn2(fn))(qenv(fn), v0088, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    v0180 = stack[-1];
    v0180 = qcdr(v0180);
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    {
        popv(4);
        fn = elt(env, 5); /* nth */
        return (*qfn2(fn))(qenv(fn), v0088, v0180);
    }

v0033:
    stack[-2] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)17; /* 1 */
    v0114 = elt(env, 3); /* "Matrix" */
    v0180 = stack[-1];
    v0088 = qcar(v0180);
    v0180 = elt(env, 4); /* "not set" */
    v0180 = list3(v0114, v0088, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    fn = elt(env, 6); /* rerror */
    v0180 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    v0180 = nil;
    { popv(4); return onevalue(v0180); }
/* error exit handlers */
v0143:
    popv(4);
    return nil;
}



/* Code for vdplength */

static Lisp_Object CC_vdplength(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdplength");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0037 = v0000;
/* end of prologue */
    v0037 = qcdr(v0037);
    v0037 = qcdr(v0037);
    v0037 = qcdr(v0037);
    v0037 = qcar(v0037);
    {
        fn = elt(env, 1); /* diplength */
        return (*qfn1(fn))(qenv(fn), v0037);
    }
}



/* Code for xord_gradlex */

static Lisp_Object CC_xord_gradlex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0218, v0137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xord_gradlex");
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
    v0218 = stack[-1];
    v0137 = qcar(v0218);
    v0218 = (Lisp_Object)17; /* 1 */
    if (v0137 == v0218) goto v0061;
    v0218 = stack[0];
    v0137 = qcar(v0218);
    v0218 = (Lisp_Object)17; /* 1 */
    if (v0137 == v0218) goto v0022;
    v0218 = stack[-1];
    stack[-2] = Llength(nil, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    v0218 = stack[0];
    v0218 = Llength(nil, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    if (equal(stack[-2], v0218)) goto v0026;
    v0218 = stack[-1];
    stack[-1] = Llength(nil, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    v0218 = stack[0];
    v0218 = Llength(nil, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    {
        Lisp_Object v0088 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v0088, v0218);
    }

v0026:
    v0137 = stack[-1];
    v0218 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v0137, v0218);
    }

v0022:
    v0218 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v0218); }

v0061:
    v0218 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0218); }
/* error exit handlers */
v0180:
    popv(4);
    return nil;
}



/* Code for smemql */

static Lisp_Object CC_smemql(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0212, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemql");
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
    goto v0133;

v0133:
    v0212 = stack[-1];
    if (v0212 == nil) goto v0110;
    v0212 = stack[-1];
    v0039 = qcar(v0212);
    v0212 = stack[0];
    v0212 = Lsmemq(nil, v0039, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    if (v0212 == nil) goto v0201;
    v0212 = stack[-1];
    v0039 = qcar(v0212);
    v0212 = stack[-2];
    v0212 = cons(v0039, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    stack[-2] = v0212;
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    stack[-1] = v0212;
    goto v0133;

v0201:
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    stack[-1] = v0212;
    goto v0133;

v0110:
    v0212 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0212);
    }
/* error exit handlers */
v0206:
    popv(4);
    return nil;
}



/* Code for split!-road */

static Lisp_Object CC_splitKroad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0217, v0206, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split-road");
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
    v0217 = stack[-1];
    stack[-3] = qcar(v0217);
    v0217 = stack[-2];
    v0138 = qcar(v0217);
    v0217 = stack[-2];
    v0206 = qcdr(v0217);
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcar(v0217);
    fn = elt(env, 1); /* sroad */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0138, v0206, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0217 = stack[-2];
    v0138 = qcar(v0217);
    v0217 = stack[-2];
    v0206 = qcdr(v0217);
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    v0217 = qcar(v0217);
    fn = elt(env, 1); /* sroad */
    v0217 = (*qfnn(fn))(qenv(fn), 3, v0138, v0206, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    {
        Lisp_Object v0014 = stack[-3];
        Lisp_Object v0015 = stack[0];
        popv(5);
        return list3(v0014, v0015, v0217);
    }
/* error exit handlers */
v0092:
    popv(5);
    return nil;
}



/* Code for mo!=revlexcomp */

static Lisp_Object CC_moMrevlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=revlexcomp");
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
    v0094 = stack[-1];
    stack[-2] = Llength(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0094 = stack[0];
    v0094 = Llength(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0094))) goto v0061;
    v0094 = stack[0];
    stack[-2] = Llength(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0094 = stack[-1];
    v0094 = Llength(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0094))) goto v0032;
    v0094 = stack[-1];
    stack[-1] = Lreverse(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0094 = stack[0];
    v0094 = Lreverse(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    fn = elt(env, 1); /* mo!=degcomp */
    v0094 = (*qfn2(fn))(qenv(fn), stack[-1], v0094);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    popv(4);
    return negate(v0094);

v0032:
    v0094 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0094); }

v0061:
    v0094 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v0094); }
/* error exit handlers */
v0138:
    popv(4);
    return nil;
}



/* Code for dl_get */

static Lisp_Object CC_dl_get(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dl_get");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0109 = v0000;
/* end of prologue */
    v0018 = v0109;
    v0109 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* dl_get2 */
        return (*qfn2(fn))(qenv(fn), v0018, v0109);
    }
}



/* Code for rempropss */

static Lisp_Object CC_rempropss(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0216, v0217, v0206, v0138, v0135, v0136;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rempropss");
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
    v0135 = v0001;
    v0216 = v0000;
/* end of prologue */
    v0136 = v0216;
    goto v0133;

v0133:
    v0216 = v0136;
    if (v0216 == nil) goto v0109;
    v0216 = v0136;
    v0216 = qcar(v0216);
    v0138 = v0216;
    v0216 = v0135;
    v0206 = v0216;
    goto v0144;

v0144:
    v0216 = v0206;
    if (v0216 == nil) goto v0033;
    v0216 = v0206;
    v0216 = qcar(v0216);
    v0217 = v0138;
    v0216 = Lremprop(nil, v0217, v0216);
    env = stack[0];
    v0216 = v0206;
    v0216 = qcdr(v0216);
    v0206 = v0216;
    goto v0144;

v0033:
    v0216 = v0136;
    v0216 = qcdr(v0216);
    v0136 = v0216;
    goto v0133;

v0109:
    v0216 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0216); }
}



/* Code for removeg1 */

static Lisp_Object MS_CDECL CC_removeg1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0259, v0260, v0261, v0262;
    Lisp_Object fn;
    Lisp_Object v0029, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removeg1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0029,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0029;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    v0260 = stack[-5];
    v0259 = stack[-4];
    fn = elt(env, 9); /* removev */
    v0259 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0260 = stack[-5];
    v0259 = stack[-3];
    fn = elt(env, 9); /* removev */
    v0259 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0260 = qcar(v0259);
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    if (v0260 == v0259) goto v0138;
    v0259 = qvalue(elt(env, 1)); /* nil */
    goto v0095;

v0095:
    if (v0259 == nil) goto v0199;
    v0260 = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v0259 = stack[-5];
    v0259 = qcar(v0259);
    fn = elt(env, 10); /* multsq */
    v0260 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-5];
    v0259 = qcdr(v0259);
    v0259 = cons(v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    popv(8);
    return ncons(v0259);

v0199:
    v0259 = stack[-5];
    v0260 = qcdr(v0259);
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    fn = elt(env, 11); /* finde */
    v0259 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    stack[-6] = v0259;
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0260 = qcar(v0259);
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    if (v0260 == v0259) goto v0006;
    v0259 = stack[-5];
    v0260 = qcdr(v0259);
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    fn = elt(env, 11); /* finde */
    v0259 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    stack[-2] = v0259;
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0260 = qcar(v0259);
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    if (v0260 == v0259) goto v0264;
    v0259 = stack[-6];
    if (v0259 == nil) goto v0265;
    v0259 = stack[-2];
    v0259 = (v0259 == nil ? lisp_true : nil);
    goto v0266;

v0266:
    if (v0259 == nil) goto v0267;
    stack[0] = elt(env, 7); /* "Invalid structure of c-graph" */
    v0259 = stack[-5];
    if (v0259 == nil) goto v0157;
    v0259 = stack[-5];
    v0259 = qcdr(v0259);
    if (v0259 == nil) goto v0052;
    v0260 = elt(env, 8); /* times */
    v0259 = stack[-5];
    v0259 = cons(v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    goto v0268;

v0268:
    v0259 = list2(stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    goto v0267;

v0267:
    v0259 = stack[-6];
    v0259 = qcar(v0259);
    stack[-6] = v0259;
    v0259 = stack[-2];
    v0259 = qcar(v0259);
    stack[-2] = v0259;
    v0259 = stack[-6];
    v0260 = qcdr(v0259);
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    v0259 = Lrplaca(nil, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-2];
    v0260 = qcdr(v0259);
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    v0259 = Lrplaca(nil, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-5];
    stack[0] = qcar(v0259);
    v0259 = stack[-5];
    v0259 = qcdr(v0259);
    fn = elt(env, 13); /* mkcopy */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = cons(stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    stack[-1] = v0259;
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    stack[0] = v0259;
    v0260 = stack[-6];
    v0259 = stack[0];
    v0259 = Lmember(nil, v0260, v0259);
    v0259 = qcar(v0259);
    stack[-6] = v0259;
    v0260 = stack[-2];
    v0259 = stack[0];
    v0259 = Lmember(nil, v0260, v0259);
    v0259 = qcar(v0259);
    stack[-2] = v0259;
    v0259 = stack[-6];
    v0260 = qcdr(v0259);
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    v0259 = Lrplaca(nil, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-2];
    v0260 = qcdr(v0259);
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    v0259 = Lrplaca(nil, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    stack[-2] = stack[-5];
    v0260 = (Lisp_Object)-15; /* -1 */
    v0259 = (Lisp_Object)17; /* 1 */
    v0260 = cons(v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* quotsq */
    v0260 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-1];
    v0259 = qcar(v0259);
    fn = elt(env, 10); /* multsq */
    v0260 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    v0259 = stack[0];
    {
        Lisp_Object v0269 = stack[-2];
        popv(8);
        return list2star(v0269, v0260, v0259);
    }

v0052:
    v0259 = stack[-5];
    v0259 = qcar(v0259);
    goto v0268;

v0157:
    v0259 = qvalue(elt(env, 1)); /* nil */
    goto v0268;

v0265:
    v0259 = qvalue(elt(env, 6)); /* t */
    goto v0266;

v0264:
    v0259 = stack[-2];
    if (v0259 == nil) goto v0270;
    v0259 = stack[-2];
    v0259 = qcar(v0259);
    v0260 = qcdr(v0259);
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    v0259 = Lrplaca(nil, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    goto v0271;

v0271:
    v0260 = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v0259 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* quotsq */
    v0260 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-5];
    v0259 = qcar(v0259);
    fn = elt(env, 10); /* multsq */
    v0260 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-5];
    v0259 = qcdr(v0259);
    v0259 = cons(v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    popv(8);
    return ncons(v0259);

v0270:
    v0262 = elt(env, 3); /* "Free edge" */
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0261 = qcar(v0259);
    v0260 = elt(env, 4); /* "in vertex" */
    v0259 = stack[-3];
    v0259 = list4(v0262, v0261, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    goto v0271;

v0006:
    v0259 = stack[-6];
    if (v0259 == nil) goto v0208;
    v0259 = stack[-6];
    v0259 = qcar(v0259);
    v0260 = qcdr(v0259);
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    v0259 = Lrplaca(nil, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    goto v0169;

v0169:
    v0260 = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v0259 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* quotsq */
    v0260 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-5];
    v0259 = qcar(v0259);
    fn = elt(env, 10); /* multsq */
    v0260 = (*qfn2(fn))(qenv(fn), v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    v0259 = stack[-5];
    v0259 = qcdr(v0259);
    v0259 = cons(v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    popv(8);
    return ncons(v0259);

v0208:
    v0262 = elt(env, 3); /* "Free edge" */
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0261 = qcar(v0259);
    v0260 = elt(env, 4); /* "in vertex" */
    v0259 = stack[-4];
    v0259 = list4(v0262, v0261, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-7];
    goto v0169;

v0138:
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0260 = qcar(v0259);
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    v0259 = (v0260 == v0259 ? lisp_true : nil);
    goto v0095;
/* error exit handlers */
v0263:
    popv(8);
    return nil;
}



/* Code for smemberl */

static Lisp_Object CC_smemberl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemberl");
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
    goto v0133;

v0133:
    v0135 = stack[-1];
    if (v0135 == nil) goto v0216;
    v0135 = stack[0];
    if (v0135 == nil) goto v0216;
    v0135 = stack[-1];
    v0136 = qcar(v0135);
    v0135 = stack[0];
    fn = elt(env, 1); /* smember */
    v0135 = (*qfn2(fn))(qenv(fn), v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    if (v0135 == nil) goto v0026;
    v0135 = stack[-1];
    v0136 = qcar(v0135);
    v0135 = stack[-2];
    v0135 = cons(v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[-2] = v0135;
    v0135 = stack[-1];
    v0135 = qcdr(v0135);
    stack[-1] = v0135;
    goto v0133;

v0026:
    v0135 = stack[-1];
    v0135 = qcdr(v0135);
    stack[-1] = v0135;
    goto v0133;

v0216:
    v0135 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0135);
    }
/* error exit handlers */
v0014:
    popv(4);
    return nil;
}



/* Code for tayexp!-times2 */

static Lisp_Object CC_tayexpKtimes2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0090, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-times2");
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
    v0090 = v0000;
/* end of prologue */
    v0089 = v0090;
    if (!consp(v0089)) goto v0110;
    v0089 = qvalue(elt(env, 1)); /* nil */
    goto v0037;

v0037:
    if (v0089 == nil) goto v0030;
    v0089 = stack[0];
    popv(3);
    return times2(v0090, v0089);

v0030:
    v0089 = v0090;
    if (!consp(v0089)) goto v0017;
    v0089 = stack[0];
    if (!consp(v0089)) goto v0206;
    v0089 = stack[0];
    fn = elt(env, 2); /* rntimes!: */
    v0089 = (*qfn2(fn))(qenv(fn), v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    goto v0038;

v0038:
    v0003 = v0089;
    v0089 = v0003;
    v0089 = qcdr(v0089);
    v0090 = qcdr(v0089);
    v0089 = (Lisp_Object)17; /* 1 */
    if (!(v0090 == v0089)) { popv(3); return onevalue(v0003); }
    v0089 = v0003;
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    { popv(3); return onevalue(v0089); }

v0206:
    stack[-1] = v0090;
    v0089 = stack[0];
    fn = elt(env, 3); /* !*i2rn */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    fn = elt(env, 2); /* rntimes!: */
    v0089 = (*qfn2(fn))(qenv(fn), stack[-1], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    goto v0038;

v0017:
    v0089 = v0090;
    fn = elt(env, 3); /* !*i2rn */
    v0090 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    v0089 = stack[0];
    fn = elt(env, 2); /* rntimes!: */
    v0089 = (*qfn2(fn))(qenv(fn), v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    goto v0038;

v0110:
    v0089 = stack[0];
    v0089 = (consp(v0089) ? nil : lisp_true);
    goto v0037;
/* error exit handlers */
v0213:
    popv(3);
    return nil;
}



/* Code for qqe_ofsf_chsimpterm */

static Lisp_Object CC_qqe_ofsf_chsimpterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_chsimpterm");
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
    v0006 = v0000;
/* end of prologue */
    v0005 = v0006;
    if (!consp(v0005)) { popv(3); return onevalue(v0006); }
    v0005 = v0006;
    v0005 = qcdr(v0005);
    stack[-1] = v0005;
    goto v0032;

v0032:
    v0005 = stack[-1];
    if (v0005 == nil) goto v0133;
    v0005 = stack[-1];
    v0005 = qcar(v0005);
    v0005 = Lconsp(nil, v0005);
    env = stack[-2];
    if (v0005 == nil) goto v0141;
    v0005 = stack[-1];
    v0005 = qcar(v0005);
    fn = elt(env, 4); /* qqe_op */
    v0006 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0005 = elt(env, 2); /* expt */
    if (v0006 == v0005) goto v0202;
    v0005 = qvalue(elt(env, 1)); /* nil */
    goto v0211;

v0211:
    if (v0005 == nil) goto v0141;
    stack[0] = stack[-1];
    v0005 = stack[-1];
    v0005 = qcar(v0005);
    fn = elt(env, 5); /* qqe_chsimpterm */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    fn = elt(env, 6); /* setcar */
    v0005 = (*qfn2(fn))(qenv(fn), stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    goto v0030;

v0030:
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    stack[-1] = v0005;
    goto v0032;

v0141:
    v0005 = stack[-1];
    v0005 = qcar(v0005);
    v0005 = Lconsp(nil, v0005);
    env = stack[-2];
    if (v0005 == nil) goto v0030;
    v0005 = stack[-1];
    v0005 = qcar(v0005);
    v0005 = CC_qqe_ofsf_chsimpterm(env, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    goto v0030;

v0202:
    v0005 = stack[-1];
    v0005 = qcar(v0005);
    fn = elt(env, 7); /* qqe_arg2l */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0005 = Lconsp(nil, v0005);
    env = stack[-2];
    if (v0005 == nil) goto v0136;
    v0005 = stack[-1];
    v0005 = qcar(v0005);
    fn = elt(env, 7); /* qqe_arg2l */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    fn = elt(env, 4); /* qqe_op */
    v0006 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0005 = elt(env, 3); /* (ltail rtail) */
    v0005 = Lmemq(nil, v0006, v0005);
    goto v0211;

v0136:
    v0005 = qvalue(elt(env, 1)); /* nil */
    goto v0211;

v0133:
    v0005 = nil;
    { popv(3); return onevalue(v0005); }
/* error exit handlers */
v0020:
    popv(3);
    return nil;
}



/* Code for ibalp_getvar!-zmom */

static Lisp_Object CC_ibalp_getvarKzmom(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_getvar-zmom");
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
    v0083 = v0001;
    stack[0] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = nil;
    fn = elt(env, 2); /* ibalp_minclnr */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-6];
    stack[-5] = v0083;
    v0083 = (Lisp_Object)-15; /* -1 */
    stack[-3] = v0083;
    v0083 = stack[0];
    stack[-1] = v0083;
    goto v0022;

v0022:
    v0083 = stack[-1];
    if (v0083 == nil) goto v0004;
    v0083 = stack[-1];
    v0083 = qcar(v0083);
    stack[0] = v0083;
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcar(v0083);
    if (v0083 == nil) goto v0212;
    v0083 = qvalue(elt(env, 1)); /* nil */
    goto v0016;

v0016:
    if (v0083 == nil) goto v0038;
    v0083 = stack[0];
    v0273 = qcdr(v0083);
    v0083 = stack[-5];
    fn = elt(env, 3); /* ibalp_isinminclause */
    v0083 = (*qfn2(fn))(qenv(fn), v0273, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-6];
    if (v0083 == nil) goto v0038;
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    stack[-4] = v0083;
    v0083 = stack[-2];
    stack[-3] = v0083;
    goto v0038;

v0038:
    v0083 = stack[-1];
    v0083 = qcdr(v0083);
    stack[-1] = v0083;
    goto v0022;

v0212:
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0273 = qcar(v0083);
    stack[-2] = v0273;
    v0083 = stack[-3];
    v0083 = (Lisp_Object)greaterp2(v0273, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    v0083 = v0083 ? lisp_true : nil;
    env = stack[-6];
    goto v0016;

v0004:
    v0083 = stack[-4];
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0273 = qcar(v0083);
    v0083 = stack[-4];
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcar(v0083);
    v0083 = (Lisp_Object)greaterp2(v0273, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    v0083 = v0083 ? lisp_true : nil;
    if (v0083 == nil) goto v0196;
    v0083 = (Lisp_Object)17; /* 1 */
    goto v0174;

v0174:
    v0273 = stack[-4];
    popv(7);
    return cons(v0273, v0083);

v0196:
    v0083 = (Lisp_Object)1; /* 0 */
    goto v0174;
/* error exit handlers */
v0274:
    popv(7);
    return nil;
}



/* Code for aex_mvartest */

static Lisp_Object CC_aex_mvartest(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_mvartest");
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
    stack[0] = v0001;
    v0019 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0146 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    v0019 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_mvartest */
        return (*qfn2(fn))(qenv(fn), v0146, v0019);
    }
/* error exit handlers */
v0023:
    popv(2);
    return nil;
}



/* Code for quotdd */

static Lisp_Object CC_quotdd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0002, v0213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotdd");
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
    v0004 = stack[-1];
    if (!(!consp(v0004))) goto v0012;
    v0004 = stack[0];
    if (!consp(v0004)) goto v0032;
    v0004 = stack[0];
    v0004 = qcar(v0004);
    if (!symbolp(v0004)) v0004 = nil;
    else { v0004 = qfastgets(v0004);
           if (v0004 != nil) { v0004 = elt(v0004, 34); /* i2d */
#ifdef RECORD_GET
             if (v0004 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0004 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0004 == SPID_NOPROP) v0004 = nil; }}
#endif
    v0213 = v0004;
    if (v0004 == nil) goto v0094;
    v0002 = v0213;
    v0004 = stack[-1];
    v0004 = Lapply1(nil, v0002, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-2];
    stack[-1] = v0004;
    goto v0012;

v0012:
    v0213 = stack[-1];
    v0002 = stack[0];
    v0004 = elt(env, 2); /* quotient */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0213, v0002, v0004);
    }

v0094:
    v0004 = stack[0];
    if (!consp(v0004)) goto v0218;
    v0004 = qvalue(elt(env, 1)); /* nil */
    goto v0035;

v0035:
    if (v0004 == nil) goto v0012;
    v0002 = v0213;
    v0004 = stack[0];
    v0004 = Lapply1(nil, v0002, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-2];
    stack[0] = v0004;
    goto v0012;

v0218:
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    if (!symbolp(v0004)) v0004 = nil;
    else { v0004 = qfastgets(v0004);
           if (v0004 != nil) { v0004 = elt(v0004, 34); /* i2d */
#ifdef RECORD_GET
             if (v0004 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0004 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0004 == SPID_NOPROP) v0004 = nil; }}
#endif
    v0213 = v0004;
    goto v0035;

v0032:
    v0002 = stack[-1];
    v0004 = stack[0];
    v0004 = Ldivide(nil, v0002, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-2];
    v0213 = v0004;
    v0004 = v0213;
    v0002 = qcdr(v0004);
    v0004 = (Lisp_Object)1; /* 0 */
    if (v0002 == v0004) goto v0140;
    v0004 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0004); }

v0140:
    v0004 = v0213;
    v0004 = qcar(v0004);
    { popv(3); return onevalue(v0004); }
/* error exit handlers */
v0257:
    popv(3);
    return nil;
}



/* Code for maprin */

static Lisp_Object CC_maprin(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0149, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maprin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0149 = v0000;
/* end of prologue */
    v0148 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v0148 == nil) goto v0061;
    v0148 = qvalue(elt(env, 1)); /* outputhandler!* */
    v0095 = elt(env, 0); /* maprin */
        return Lapply2(nil, 3, v0148, v0095, v0149);

v0061:
    v0148 = qvalue(elt(env, 2)); /* overflowed!* */
    if (v0148 == nil) goto v0111;
    v0148 = nil;
    return onevalue(v0148);

v0111:
    v0148 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 3); /* maprint */
        return (*qfn2(fn))(qenv(fn), v0149, v0148);
    }
}



/* Code for wedgepf */

static Lisp_Object CC_wedgepf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgepf");
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
    v0146 = v0001;
    v0147 = v0000;
/* end of prologue */
    stack[0] = v0147;
    fn = elt(env, 1); /* !*pf2wedgepf */
    v0146 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    fn = elt(env, 2); /* wedgepf2 */
    v0146 = (*qfn2(fn))(qenv(fn), stack[0], v0146);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*wedgepf2pf */
        return (*qfn1(fn))(qenv(fn), v0146);
    }
/* error exit handlers */
v0022:
    popv(2);
    return nil;
}



/* Code for simptimes */

static Lisp_Object CC_simptimes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0174, v0187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simptimes");
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
    v0174 = stack[-1];
    if (v0174 == nil) goto v0022;
    v0187 = qvalue(elt(env, 1)); /* tstack!* */
    v0174 = (Lisp_Object)1; /* 0 */
    if (v0187 == v0174) goto v0026;
    v0174 = qvalue(elt(env, 2)); /* t */
    goto v0038;

v0038:
    if (!(v0174 == nil)) goto v0133;
    v0174 = qvalue(elt(env, 3)); /* mul!* */
    stack[-2] = v0174;
    v0174 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 3)) = v0174; /* mul!* */
    goto v0133;

v0133:
    v0174 = qvalue(elt(env, 1)); /* tstack!* */
    v0174 = add1(v0174);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0174; /* tstack!* */
    v0174 = stack[-1];
    fn = elt(env, 6); /* simpcar */
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    stack[0] = v0174;
    goto v0145;

v0145:
    v0174 = stack[-1];
    v0174 = qcdr(v0174);
    stack[-1] = v0174;
    v0174 = stack[0];
    v0174 = qcar(v0174);
    if (v0174 == nil) goto v0110;
    v0174 = stack[-1];
    if (v0174 == nil) goto v0037;
    v0174 = stack[-1];
    fn = elt(env, 6); /* simpcar */
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    fn = elt(env, 7); /* multsq */
    v0174 = (*qfn2(fn))(qenv(fn), stack[0], v0174);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    stack[0] = v0174;
    goto v0145;

v0037:
    v0174 = qvalue(elt(env, 3)); /* mul!* */
    if (v0174 == nil) goto v0151;
    v0187 = qvalue(elt(env, 1)); /* tstack!* */
    v0174 = (Lisp_Object)17; /* 1 */
    v0174 = (Lisp_Object)greaterp2(v0187, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-3];
    goto v0011;

v0011:
    if (!(v0174 == nil)) goto v0110;
    v0174 = qvalue(elt(env, 3)); /* mul!* */
    v0187 = qcar(v0174);
    v0174 = stack[0];
    v0174 = Lapply1(nil, v0187, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    stack[0] = v0174;
    v0174 = qvalue(elt(env, 4)); /* nil */
    v0174 = ncons(v0174);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0174; /* alglist!* */
    v0174 = qvalue(elt(env, 3)); /* mul!* */
    v0174 = qcdr(v0174);
    qvalue(elt(env, 3)) = v0174; /* mul!* */
    goto v0037;

v0110:
    v0174 = qvalue(elt(env, 1)); /* tstack!* */
    v0174 = sub1(v0174);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0174; /* tstack!* */
    v0187 = qvalue(elt(env, 1)); /* tstack!* */
    v0174 = (Lisp_Object)1; /* 0 */
    if (!(v0187 == v0174)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0174 = stack[-2];
    qvalue(elt(env, 3)) = v0174; /* mul!* */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0151:
    v0174 = qvalue(elt(env, 2)); /* t */
    goto v0011;

v0026:
    v0174 = qvalue(elt(env, 3)); /* mul!* */
    v0174 = (v0174 == nil ? lisp_true : nil);
    goto v0038;

v0022:
    v0187 = (Lisp_Object)17; /* 1 */
    v0174 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0187, v0174);
/* error exit handlers */
v0184:
    popv(4);
    return nil;
}



/* Code for eqdummy */

static Lisp_Object CC_eqdummy(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0111, v0030;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for eqdummy");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0111 = v0001;
    v0030 = v0000;
/* end of prologue */
    v0112 = v0030;
    if (v0112 == nil) goto v0061;
    v0112 = v0030;
    if (!symbolp(v0112)) v0112 = nil;
    else { v0112 = qfastgets(v0112);
           if (v0112 != nil) { v0112 = elt(v0112, 32); /* dummy */
#ifdef RECORD_GET
             if (v0112 != SPID_NOPROP)
                record_get(elt(fastget_names, 32), 1);
             else record_get(elt(fastget_names, 32), 0),
                v0112 = nil; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v0112 == SPID_NOPROP) v0112 = nil; }}
#endif
    v0112 = qcar(v0112);
    if (!symbolp(v0111)) v0111 = nil;
    else { v0111 = qfastgets(v0111);
           if (v0111 != nil) { v0111 = elt(v0111, 32); /* dummy */
#ifdef RECORD_GET
             if (v0111 != SPID_NOPROP)
                record_get(elt(fastget_names, 32), 1);
             else record_get(elt(fastget_names, 32), 0),
                v0111 = nil; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v0111 == SPID_NOPROP) v0111 = nil; }}
#endif
    v0111 = qcar(v0111);
    v0112 = (v0112 == v0111 ? lisp_true : nil);
    return onevalue(v0112);

v0061:
    v0112 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0112);
}



/* Code for b!:extadd */

static Lisp_Object CC_bTextadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0193, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:extadd");
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
    stack[0] = nil;
    goto v0133;

v0133:
    v0082 = stack[-2];
    if (v0082 == nil) goto v0146;
    v0082 = stack[-1];
    if (v0082 == nil) goto v0111;
    v0082 = stack[-2];
    v0082 = qcar(v0082);
    v0193 = qcar(v0082);
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    v0082 = qcar(v0082);
    if (equal(v0193, v0082)) goto v0206;
    v0082 = stack[-2];
    v0082 = qcar(v0082);
    v0193 = qcar(v0082);
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    v0082 = qcar(v0082);
    fn = elt(env, 1); /* b!:ordexp */
    v0082 = (*qfn2(fn))(qenv(fn), v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-4];
    if (v0082 == nil) goto v0083;
    v0082 = stack[-2];
    v0193 = qcar(v0082);
    v0082 = stack[0];
    v0082 = cons(v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-4];
    stack[0] = v0082;
    v0082 = stack[-2];
    v0082 = qcdr(v0082);
    stack[-2] = v0082;
    goto v0133;

v0083:
    v0082 = stack[-1];
    v0193 = qcar(v0082);
    v0082 = stack[0];
    v0082 = cons(v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-4];
    stack[0] = v0082;
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    stack[-1] = v0082;
    goto v0133;

v0206:
    stack[-3] = stack[0];
    v0082 = stack[-2];
    v0082 = qcar(v0082);
    v0193 = qcdr(v0082);
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    v0082 = qcdr(v0082);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-4];
    v0082 = stack[-2];
    v0193 = qcdr(v0082);
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    v0082 = CC_bTextadd(env, v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-4];
    v0193 = stack[0];
    v0078 = v0193;
    if (v0078 == nil) goto v0136;
    v0078 = stack[-2];
    v0078 = qcar(v0078);
    v0078 = qcar(v0078);
    v0082 = acons(v0078, v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-4];
    goto v0136;

v0136:
    {
        Lisp_Object v0255 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0255, v0082);
    }

v0111:
    v0193 = stack[0];
    v0082 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0193, v0082);
    }

v0146:
    v0193 = stack[0];
    v0082 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0193, v0082);
    }
/* error exit handlers */
v0277:
    popv(5);
    return nil;
}



/* Code for mkkl */

static Lisp_Object CC_mkkl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0148, v0149;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkkl");
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
    v0038 = v0001;
    v0148 = v0000;
/* end of prologue */

v0133:
    v0149 = v0148;
    if (v0149 == nil) { popv(2); return onevalue(v0038); }
    v0149 = v0148;
    v0149 = qcdr(v0149);
    stack[0] = v0149;
    v0148 = qcar(v0148);
    v0038 = cons(v0148, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0038 = ncons(v0038);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0148 = stack[0];
    goto v0133;
/* error exit handlers */
v0016:
    popv(2);
    return nil;
}



/* Code for quotfail1 */

static Lisp_Object MS_CDECL CC_quotfail1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0211, v0202;
    Lisp_Object fn;
    Lisp_Object v0029, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "quotfail1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfail1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0029,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    v0211 = v0001;
    v0202 = v0000;
/* end of prologue */
    v0017 = v0202;
    if (v0017 == nil) goto v0133;
    v0017 = v0202;
    fn = elt(env, 2); /* quotf */
    v0017 = (*qfn2(fn))(qenv(fn), v0017, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-1];
    v0211 = v0017;
    v0017 = v0211;
    if (!(v0017 == nil)) { popv(2); return onevalue(v0211); }
    v0017 = stack[0];
    fn = elt(env, 3); /* errorf */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0017 = nil;
    { popv(2); return onevalue(v0017); }

v0133:
    v0017 = qvalue(elt(env, 1)); /* polyzero */
    { popv(2); return onevalue(v0017); }
/* error exit handlers */
v0214:
    popv(2);
    return nil;
}



/* Code for setunion */

static Lisp_Object CC_setunion(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0212, v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setunion");
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
    v0212 = v0000;
/* end of prologue */

v0061:
    v0026 = stack[0];
    if (v0026 == nil) { popv(3); return onevalue(v0212); }
    v0026 = stack[0];
    v0039 = qcar(v0026);
    v0026 = v0212;
    v0026 = Lmember(nil, v0039, v0026);
    if (v0026 == nil) goto v0038;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    stack[0] = v0026;
    goto v0061;

v0038:
    stack[-1] = v0212;
    v0026 = stack[0];
    v0026 = qcar(v0026);
    v0026 = ncons(v0026);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0026 = Lappend(nil, stack[-1], v0026);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0212 = v0026;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    stack[0] = v0026;
    goto v0061;
/* error exit handlers */
v0217:
    popv(3);
    return nil;
}



/* Code for rl_simpbop */

static Lisp_Object CC_rl_simpbop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simpbop");
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
/* copy arguments values to proper place */
    v0139 = v0000;
/* end of prologue */
    v0015 = v0139;
    stack[-4] = qcar(v0015);
    v0015 = v0139;
    v0015 = qcdr(v0015);
    stack[-3] = v0015;
    v0015 = stack[-3];
    if (v0015 == nil) goto v0144;
    v0015 = stack[-3];
    v0015 = qcar(v0015);
    fn = elt(env, 2); /* rl_simp1 */
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-5];
    v0015 = ncons(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-5];
    stack[-1] = v0015;
    stack[-2] = v0015;
    goto v0023;

v0023:
    v0015 = stack[-3];
    v0015 = qcdr(v0015);
    stack[-3] = v0015;
    v0015 = stack[-3];
    if (v0015 == nil) goto v0211;
    stack[0] = stack[-1];
    v0015 = stack[-3];
    v0015 = qcar(v0015);
    fn = elt(env, 2); /* rl_simp1 */
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-5];
    v0015 = ncons(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-5];
    v0015 = Lrplacd(nil, stack[0], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-5];
    v0015 = stack[-1];
    v0015 = qcdr(v0015);
    stack[-1] = v0015;
    goto v0023;

v0211:
    v0015 = stack[-2];
    goto v0133;

v0133:
    {
        Lisp_Object v0025 = stack[-4];
        popv(6);
        return cons(v0025, v0015);
    }

v0144:
    v0015 = qvalue(elt(env, 1)); /* nil */
    goto v0133;
/* error exit handlers */
v0007:
    popv(6);
    return nil;
}



/* Code for aex_reducedtag */

static Lisp_Object CC_aex_reducedtag(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0037;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_reducedtag");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0037 = v0000;
/* end of prologue */
    v0037 = qcdr(v0037);
    v0037 = qcdr(v0037);
    v0037 = qcdr(v0037);
    v0037 = qcdr(v0037);
    v0037 = qcar(v0037);
    return onevalue(v0037);
}



/* Code for quotodd */

static Lisp_Object CC_quotodd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0214, v0215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotodd");
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
    v0214 = v0001;
    v0215 = v0000;
/* end of prologue */
    v0201 = v0215;
    if (!consp(v0201)) goto v0110;
    v0201 = qvalue(elt(env, 1)); /* nil */
    goto v0037;

v0037:
    if (v0201 == nil) goto v0148;
    v0201 = v0215;
    fn = elt(env, 2); /* mkrn */
    v0201 = (*qfn2(fn))(qenv(fn), v0201, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v0201);
    }

v0148:
    v0201 = v0215;
    {
        popv(1);
        fn = elt(env, 4); /* lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v0201, v0214);
    }

v0110:
    v0201 = v0214;
    v0201 = (consp(v0201) ? nil : lisp_true);
    goto v0037;
/* error exit handlers */
v0026:
    popv(1);
    return nil;
}



/* Code for termordp!! */

static Lisp_Object CC_termordpB(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0038, v0148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termordp!");
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
    v0148 = v0000;
/* end of prologue */
    v0038 = v0148;
    v0141 = stack[0];
    if (equal(v0038, v0141)) goto v0111;
    v0141 = v0148;
    fn = elt(env, 2); /* guesspftype */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    v0141 = stack[0];
    fn = elt(env, 2); /* guesspftype */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    {
        Lisp_Object v0017 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* termordp */
        return (*qfn2(fn))(qenv(fn), v0017, v0141);
    }

v0111:
    v0141 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0141); }
/* error exit handlers */
v0016:
    popv(3);
    return nil;
}



/* Code for mkid */

static Lisp_Object CC_mkid(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkid");
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
    v0010 = v0000;
/* end of prologue */
    v0113 = v0010;
    if (symbolp(v0113)) goto v0133;
    v0113 = v0010;
    v0010 = elt(env, 1); /* "MKID root" */
    {
        popv(3);
        fn = elt(env, 4); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0113, v0010);
    }

v0133:
    v0113 = stack[0];
    if (!consp(v0113)) goto v0144;
    v0113 = qvalue(elt(env, 2)); /* nil */
    goto v0033;

v0033:
    if (v0113 == nil) goto v0007;
    fn = elt(env, 5); /* get!-print!-name */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    stack[-1] = Lexplode(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0010 = stack[0];
    fn = elt(env, 5); /* get!-print!-name */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0010 = Lexplode(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0010 = Lnconc(nil, stack[-1], v0010);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0010 = Lcompress(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0197;
        popv(3);
        return Lintern(nil, v0010);

v0007:
    v0113 = stack[0];
    v0010 = elt(env, 3); /* "MKID index" */
    {
        popv(3);
        fn = elt(env, 4); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0113, v0010);
    }

v0144:
    v0113 = stack[0];
    v0113 = Lsymbolp(nil, v0113);
    env = stack[-2];
    if (!(v0113 == nil)) goto v0033;
    v0113 = stack[0];
    v0113 = integerp(v0113);
    if (v0113 == nil) goto v0149;
    v0113 = stack[0];
    v0113 = Lminusp(nil, v0113);
    env = stack[-2];
    v0113 = (v0113 == nil ? lisp_true : nil);
    goto v0033;

v0149:
    v0113 = qvalue(elt(env, 2)); /* nil */
    goto v0033;
/* error exit handlers */
v0197:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-chk */

static Lisp_Object CC_mvKpowKchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-chk");
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
    v0149 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0095 = v0149;
    if (v0095 == nil) goto v0141;
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    v0149 = qcar(v0149);
    v0149 = qcar(v0149);
    fn = elt(env, 2); /* mv!-pow!-!- */
    v0149 = (*qfn2(fn))(qenv(fn), v0095, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    stack[0] = v0149;
    if (v0149 == nil) goto v0141;
    v0149 = stack[0];
    fn = elt(env, 3); /* mv!-pow!-minusp */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    if (v0149 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v0141;

v0141:
    v0149 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0149); }
/* error exit handlers */
v0017:
    popv(2);
    return nil;
}



/* Code for bc_inv */

static Lisp_Object CC_bc_inv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0139, v0134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_inv");
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
    v0134 = v0000;
/* end of prologue */
    v0139 = v0134;
    v0015 = (Lisp_Object)17; /* 1 */
    if (v0139 == v0015) goto v0037;
    v0139 = v0134;
    v0015 = (Lisp_Object)-15; /* -1 */
    v0015 = (v0139 == v0015 ? lisp_true : nil);
    goto v0145;

v0145:
    if (!(v0015 == nil)) { popv(1); return onevalue(v0134); }
    v0015 = (Lisp_Object)17; /* 1 */
    v0139 = v0134;
    fn = elt(env, 3); /* qremf */
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[0];
    v0139 = v0015;
    v0015 = v0139;
    v0015 = qcdr(v0015);
    if (v0015 == nil) goto v0028;
    v0015 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0015); }

v0028:
    v0015 = v0139;
    v0015 = qcar(v0015);
    { popv(1); return onevalue(v0015); }

v0037:
    v0015 = qvalue(elt(env, 1)); /* t */
    goto v0145;
/* error exit handlers */
v0034:
    popv(1);
    return nil;
}



/* Code for janettreefind */

static Lisp_Object CC_janettreefind(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for janettreefind");
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
    v0082 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    if (v0082 == nil) goto v0031;
    stack[-5] = nil;
    v0082 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    stack[-3] = v0082;
    v0193 = stack[-4];
    v0082 = (Lisp_Object)1; /* 0 */
    v0082 = *(Lisp_Object *)((char *)v0193 + (CELL-TAG_VECTOR) + ((int32_t)v0082/(16/CELL)));
    stack[-2] = v0082;
    v0082 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0082;
    goto v0202;

v0202:
    v0193 = stack[-2];
    v0082 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v0193)) > ((int32_t)(v0082)))) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }

v0014:
    v0082 = stack[-3];
    v0082 = qcar(v0082);
    stack[0] = qcar(v0082);
    v0193 = stack[-4];
    v0082 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0082 = (*qfn2(fn))(qenv(fn), v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-6];
    v0082 = (Lisp_Object)lessp2(stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    v0082 = v0082 ? lisp_true : nil;
    env = stack[-6];
    if (v0082 == nil) goto v0199;
    v0082 = stack[-3];
    v0082 = qcdr(v0082);
    v0082 = qcar(v0082);
    if (v0082 == nil) goto v0199;
    v0082 = stack[-3];
    v0082 = qcdr(v0082);
    v0082 = qcar(v0082);
    stack[-3] = v0082;
    goto v0014;

v0199:
    v0082 = stack[-3];
    v0082 = qcar(v0082);
    stack[0] = qcar(v0082);
    v0193 = stack[-4];
    v0082 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0082 = (*qfn2(fn))(qenv(fn), v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-6];
    if (equal(stack[0], v0082)) goto v0200;
    v0082 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0082;
    goto v0202;

v0200:
    v0082 = stack[-3];
    v0082 = qcdr(v0082);
    v0082 = qcdr(v0082);
    if (v0082 == nil) goto v0273;
    stack[0] = stack[-2];
    v0193 = stack[-4];
    v0082 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0082 = (*qfn2(fn))(qenv(fn), v0193, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-6];
    v0082 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v0082 + TAG_FIXNUM);
    stack[-2] = v0082;
    v0082 = stack[-1];
    v0082 = (Lisp_Object)((int32_t)(v0082) + 0x10);
    stack[-1] = v0082;
    v0082 = stack[-3];
    v0082 = qcdr(v0082);
    v0082 = qcdr(v0082);
    stack[-3] = v0082;
    goto v0202;

v0273:
    v0082 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0082;
    v0082 = stack[-3];
    v0082 = qcar(v0082);
    v0082 = qcdr(v0082);
    stack[-5] = v0082;
    goto v0202;

v0031:
    v0082 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0082); }
/* error exit handlers */
v0255:
    popv(7);
    return nil;
}



/* Code for qqe_id!-nyt!-branchq */

static Lisp_Object CC_qqe_idKnytKbranchq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchq");
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
    v0030 = stack[0];
    if (!consp(v0030)) goto v0031;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    fn = elt(env, 1); /* qqe_qopaddp */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-1];
    if (!(v0030 == nil)) { popv(2); return onevalue(v0030); }
    v0030 = stack[0];
    v0030 = qcar(v0030);
    {
        popv(2);
        fn = elt(env, 2); /* qqe_qoptailp */
        return (*qfn1(fn))(qenv(fn), v0030);
    }

v0031:
    v0030 = stack[0];
    fn = elt(env, 3); /* qqe_qtidp */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-1];
    if (!(v0030 == nil)) { popv(2); return onevalue(v0030); }
    v0030 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* qqe_nytidp */
        return (*qfn1(fn))(qenv(fn), v0030);
    }
/* error exit handlers */
v0141:
    popv(2);
    return nil;
}



/* Code for ibalp_clausep */

static Lisp_Object CC_ibalp_clausep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_clausep");
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
    v0017 = stack[0];
    fn = elt(env, 3); /* ibalp_litp */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-1];
    if (!(v0017 == nil)) { popv(2); return onevalue(v0017); }
    v0017 = stack[0];
    if (!consp(v0017)) goto v0142;
    v0017 = stack[0];
    v0017 = qcar(v0017);
    v0211 = v0017;
    goto v0146;

v0146:
    v0017 = elt(env, 1); /* or */
    if (v0211 == v0017) goto v0110;
    v0017 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0017); }

v0110:
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    {
        popv(2);
        fn = elt(env, 4); /* ibalp_litlp */
        return (*qfn1(fn))(qenv(fn), v0017);
    }

v0142:
    v0017 = stack[0];
    v0211 = v0017;
    goto v0146;
/* error exit handlers */
v0201:
    popv(2);
    return nil;
}



/* Code for aminusp!:1 */

static Lisp_Object CC_aminuspT1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0185, v0256, v0184, v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aminusp:1");
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
    v0185 = stack[-1];
    fn = elt(env, 6); /* aeval!* */
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-3];
    stack[-1] = v0185;
    v0185 = stack[-1];
    stack[-2] = v0185;
    v0185 = stack[-2];
    v0185 = integerp(v0185);
    if (v0185 == nil) goto v0033;
    v0185 = stack[-2];
        popv(4);
        return Lminusp(nil, v0185);

v0033:
    v0256 = stack[-2];
    v0185 = elt(env, 1); /* !*sq */
    if (!consp(v0256)) goto v0141;
    v0256 = qcar(v0256);
    if (!(v0256 == v0185)) goto v0141;

v0110:
    v0185 = stack[-2];
    v0185 = qcdr(v0185);
    v0185 = qcar(v0185);
    stack[-2] = v0185;
    v0185 = stack[-2];
    v0185 = qcar(v0185);
    v0185 = integerp(v0185);
    if (v0185 == nil) goto v0113;
    v0185 = stack[-2];
    v0185 = qcdr(v0185);
    v0185 = integerp(v0185);
    if (v0185 == nil) goto v0113;
    v0185 = stack[-2];
    v0185 = qcar(v0185);
        popv(4);
        return Lminusp(nil, v0185);

v0113:
    v0185 = stack[-2];
    v0256 = qcdr(v0185);
    v0185 = (Lisp_Object)17; /* 1 */
    if (v0256 == v0185) goto v0008;
    v0185 = qvalue(elt(env, 4)); /* t */
    goto v0114;

v0114:
    if (v0185 == nil) goto v0196;
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0185 = stack[-1];
    fn = elt(env, 7); /* reval */
    v0084 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-3];
    v0184 = elt(env, 3); /* "invalid in FOR statement" */
    v0256 = qvalue(elt(env, 2)); /* nil */
    v0185 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v0185 = (*qfnn(fn))(qenv(fn), 5, stack[0], v0084, v0184, v0256, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    v0185 = nil;
    { popv(4); return onevalue(v0185); }

v0196:
    v0256 = elt(env, 5); /* !:minusp */
    v0185 = stack[-2];
        popv(4);
        return Lapply1(nil, v0256, v0185);

v0008:
    v0185 = stack[-2];
    v0185 = qcar(v0185);
    stack[-2] = v0185;
    if (!consp(v0185)) goto v0199;
    v0185 = stack[-2];
    v0185 = qcar(v0185);
    v0185 = (consp(v0185) ? nil : lisp_true);
    goto v0200;

v0200:
    v0185 = (v0185 == nil ? lisp_true : nil);
    goto v0114;

v0199:
    v0185 = qvalue(elt(env, 4)); /* t */
    goto v0200;

v0141:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0185 = stack[-1];
    fn = elt(env, 7); /* reval */
    v0084 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-3];
    v0184 = elt(env, 3); /* "invalid in FOR statement" */
    v0256 = qvalue(elt(env, 2)); /* nil */
    v0185 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v0185 = (*qfnn(fn))(qenv(fn), 5, stack[0], v0084, v0184, v0256, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-3];
    goto v0110;
/* error exit handlers */
v0279:
    popv(4);
    return nil;
}



/* Code for make!-term */

static Lisp_Object MS_CDECL CC_makeKterm(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0286, v0287, v0288;
    Lisp_Object fn;
    Lisp_Object v0029, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-term");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0029,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0029;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    v0286 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0286;
    v0286 = (Lisp_Object)1; /* 0 */
    stack[0] = v0286;
    goto v0093;

v0093:
    v0287 = stack[-4];
    v0286 = stack[0];
    v0287 = *(Lisp_Object *)((char *)v0287 + (CELL-TAG_VECTOR) + ((int32_t)v0286/(16/CELL)));
    v0286 = (Lisp_Object)1; /* 0 */
    v0286 = (Lisp_Object)lessp2(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0286 = v0286 ? lisp_true : nil;
    env = stack[-7];
    if (v0286 == nil) goto v0212;
    v0286 = (Lisp_Object)-15; /* -1 */
    stack[-2] = v0286;
    goto v0146;

v0146:
    v0286 = (Lisp_Object)49; /* 3 */
    v0286 = Lmkvect(nil, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-7];
    stack[-6] = v0286;
    v0287 = stack[-2];
    v0286 = (Lisp_Object)17; /* 1 */
    if (v0287 == v0286) goto v0089;
    v0287 = stack[-5];
    v0286 = elt(env, 4); /* cos */
    v0286 = (v0287 == v0286 ? lisp_true : nil);
    goto v0177;

v0177:
    if (v0286 == nil) goto v0195;
    v0288 = stack[-6];
    v0287 = (Lisp_Object)1; /* 0 */
    v0286 = stack[-3];
    *(Lisp_Object *)((char *)v0288 + (CELL-TAG_VECTOR) + ((int32_t)v0287/(16/CELL))) = v0286;
    goto v0274;

v0274:
    v0288 = stack[-6];
    v0287 = (Lisp_Object)17; /* 1 */
    v0286 = stack[-5];
    *(Lisp_Object *)((char *)v0288 + (CELL-TAG_VECTOR) + ((int32_t)v0287/(16/CELL))) = v0286;
    v0287 = stack[-2];
    v0286 = (Lisp_Object)-15; /* -1 */
    if (!(v0287 == v0286)) goto v0251;
    v0286 = (Lisp_Object)113; /* 7 */
    v0286 = Lmkvect(nil, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-7];
    stack[-2] = v0286;
    v0286 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0286;
    goto v0073;

v0073:
    v0287 = (Lisp_Object)113; /* 7 */
    v0286 = stack[-3];
    v0286 = difference2(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-7];
    v0286 = Lminusp(nil, v0286);
    env = stack[-7];
    if (v0286 == nil) goto v0290;
    v0286 = stack[-2];
    stack[-4] = v0286;
    goto v0251;

v0251:
    v0288 = stack[-6];
    v0287 = (Lisp_Object)33; /* 2 */
    v0286 = stack[-4];
    *(Lisp_Object *)((char *)v0288 + (CELL-TAG_VECTOR) + ((int32_t)v0287/(16/CELL))) = v0286;
    v0287 = stack[-6];
    v0286 = (Lisp_Object)49; /* 3 */
    v0288 = qvalue(elt(env, 2)); /* nil */
    *(Lisp_Object *)((char *)v0287 + (CELL-TAG_VECTOR) + ((int32_t)v0286/(16/CELL))) = v0288;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v0290:
    stack[-1] = stack[-2];
    stack[0] = stack[-3];
    v0287 = stack[-4];
    v0286 = stack[-3];
    v0286 = *(Lisp_Object *)((char *)v0287 + (CELL-TAG_VECTOR) + ((int32_t)v0286/(16/CELL)));
    v0286 = negate(v0286);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0286;
    v0286 = stack[-3];
    v0286 = add1(v0286);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-7];
    stack[-3] = v0286;
    goto v0073;

v0195:
    stack[-1] = stack[-6];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0287 = elt(env, 5); /* (-1 . 1) */
    v0286 = stack[-3];
    fn = elt(env, 6); /* multsq */
    v0286 = (*qfn2(fn))(qenv(fn), v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0286;
    goto v0274;

v0089:
    v0286 = qvalue(elt(env, 3)); /* t */
    goto v0177;

v0212:
    v0287 = stack[-4];
    v0286 = stack[0];
    v0287 = *(Lisp_Object *)((char *)v0287 + (CELL-TAG_VECTOR) + ((int32_t)v0286/(16/CELL)));
    v0286 = (Lisp_Object)1; /* 0 */
    v0286 = (Lisp_Object)greaterp2(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0286 = v0286 ? lisp_true : nil;
    env = stack[-7];
    if (v0286 == nil) goto v0014;
    v0286 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0286;
    goto v0146;

v0014:
    v0287 = stack[0];
    v0286 = (Lisp_Object)113; /* 7 */
    if (v0287 == v0286) goto v0180;
    v0286 = stack[0];
    v0286 = (Lisp_Object)((int32_t)(v0286) + 0x10);
    stack[0] = v0286;
    goto v0093;

v0180:
    v0287 = stack[-5];
    v0286 = elt(env, 1); /* sin */
    if (!(v0287 == v0286)) goto v0146;
    v0286 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v0286); }
/* error exit handlers */
v0289:
    popv(8);
    return nil;
}



/* Code for subsetp */

static Lisp_Object CC_subsetp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0214, v0215, v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subsetp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0214 = v0001;
    v0215 = v0000;
/* end of prologue */

v0108:
    v0201 = v0215;
    if (v0201 == nil) goto v0061;
    v0201 = v0215;
    v0026 = qcar(v0201);
    v0201 = v0214;
    v0201 = Lmember(nil, v0026, v0201);
    if (v0201 == nil) goto v0146;
    v0201 = v0215;
    v0215 = qcdr(v0201);
    v0201 = v0214;
    v0214 = v0201;
    goto v0108;

v0146:
    v0201 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0201);

v0061:
    v0201 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0201);
}



/* Code for rnminus!: */

static Lisp_Object CC_rnminusT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnminus:");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0033 = stack[0];
    stack[-1] = qcar(v0033);
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0033 = qcar(v0033);
    fn = elt(env, 1); /* !:minus */
    v0144 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0033 = qcdr(v0033);
    {
        Lisp_Object v0111 = stack[-1];
        popv(2);
        return list2star(v0111, v0144, v0033);
    }
/* error exit handlers */
v0112:
    popv(2);
    return nil;
}



/* Code for !*i2gi */

static Lisp_Object CC_Hi2gi(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2gi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0146 = v0000;
/* end of prologue */
    v0023 = elt(env, 1); /* !:gi!: */
    v0147 = v0146;
    v0146 = (Lisp_Object)1; /* 0 */
    return list2star(v0023, v0147, v0146);
}



/* Code for mkprogn */

static Lisp_Object CC_mkprogn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0212, v0039, v0094, v0216;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkprogn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0094 = v0001;
    v0216 = v0000;
/* end of prologue */
    v0039 = v0094;
    v0212 = elt(env, 1); /* progn */
    if (!consp(v0039)) goto v0149;
    v0039 = qcar(v0039);
    if (!(v0039 == v0212)) goto v0149;
    v0212 = elt(env, 1); /* progn */
    v0039 = v0216;
    v0094 = qcdr(v0094);
    return list2star(v0212, v0039, v0094);

v0149:
    v0212 = elt(env, 1); /* progn */
    v0039 = v0216;
    return list3(v0212, v0039, v0094);
}



setup_type const u12_setup[] =
{
    {"monommultiplybyvariable", too_few_2,      CC_monommultiplybyvariable,wrong_no_2},
    {"matrix+p",                CC_matrixLp,    too_many_1,    wrong_no_1},
    {"cl_varl2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_varl2},
    {"rat_sgn",                 CC_rat_sgn,     too_many_1,    wrong_no_1},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"omiir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omiir},
    {"testredh",                CC_testredh,    too_many_1,    wrong_no_1},
    {"off",                     CC_off,         too_many_1,    wrong_no_1},
    {"statep*",                 CC_statepH,     too_many_1,    wrong_no_1},
    {"assert_typesyntaxp",      CC_assert_typesyntaxp,too_many_1,wrong_no_1},
    {"bc_fi",                   CC_bc_fi,       too_many_1,    wrong_no_1},
    {"pdif",                    too_few_2,      CC_pdif,       wrong_no_2},
    {"remflagss",               too_few_2,      CC_remflagss,  wrong_no_2},
    {"kernp",                   CC_kernp,       too_many_1,    wrong_no_1},
    {"gcdf2",                   too_few_2,      CC_gcdf2,      wrong_no_2},
    {"ratpoly_red",             CC_ratpoly_red, too_many_1,    wrong_no_1},
    {"smtp",                    too_few_2,      CC_smtp,       wrong_no_2},
    {"maxtype",                 CC_maxtype,     too_many_1,    wrong_no_1},
    {"unbind",                  CC_unbind,      too_many_1,    wrong_no_1},
    {"bcquot",                  too_few_2,      CC_bcquot,     wrong_no_2},
    {"set-ordp",                too_few_2,      CC_setKordp,   wrong_no_2},
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"assert_dyntypep",         CC_assert_dyntypep,too_many_1, wrong_no_1},
    {"aminusp:",                CC_aminuspT,    too_many_1,    wrong_no_1},
    {"dp=mocompare",            too_few_2,      CC_dpMmocompare,wrong_no_2},
    {"artimes:",                too_few_2,      CC_artimesT,   wrong_no_2},
    {"remcomma",                CC_remcomma,    too_many_1,    wrong_no_1},
    {"var_list",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_var_list},
    {"pasf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwupdknowl},
    {"ibalp_clauselp",          CC_ibalp_clauselp,too_many_1,  wrong_no_1},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"vdplength",               CC_vdplength,   too_many_1,    wrong_no_1},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"smemql",                  too_few_2,      CC_smemql,     wrong_no_2},
    {"split-road",              too_few_2,      CC_splitKroad, wrong_no_2},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"dl_get",                  CC_dl_get,      too_many_1,    wrong_no_1},
    {"rempropss",               too_few_2,      CC_rempropss,  wrong_no_2},
    {"removeg1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg1},
    {"smemberl",                too_few_2,      CC_smemberl,   wrong_no_2},
    {"tayexp-times2",           too_few_2,      CC_tayexpKtimes2,wrong_no_2},
    {"qqe_ofsf_chsimpterm",     CC_qqe_ofsf_chsimpterm,too_many_1,wrong_no_1},
    {"ibalp_getvar-zmom",       too_few_2,      CC_ibalp_getvarKzmom,wrong_no_2},
    {"aex_mvartest",            too_few_2,      CC_aex_mvartest,wrong_no_2},
    {"quotdd",                  too_few_2,      CC_quotdd,     wrong_no_2},
    {"maprin",                  CC_maprin,      too_many_1,    wrong_no_1},
    {"wedgepf",                 too_few_2,      CC_wedgepf,    wrong_no_2},
    {"simptimes",               CC_simptimes,   too_many_1,    wrong_no_1},
    {"eqdummy",                 too_few_2,      CC_eqdummy,    wrong_no_2},
    {"b:extadd",                too_few_2,      CC_bTextadd,   wrong_no_2},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {"quotfail1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfail1},
    {"setunion",                too_few_2,      CC_setunion,   wrong_no_2},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"aex_reducedtag",          CC_aex_reducedtag,too_many_1,  wrong_no_1},
    {"quotodd",                 too_few_2,      CC_quotodd,    wrong_no_2},
    {"termordp!",               too_few_2,      CC_termordpB,  wrong_no_2},
    {"mkid",                    too_few_2,      CC_mkid,       wrong_no_2},
    {"mv-pow-chk",              too_few_2,      CC_mvKpowKchk, wrong_no_2},
    {"bc_inv",                  CC_bc_inv,      too_many_1,    wrong_no_1},
    {"janettreefind",           CC_janettreefind,too_many_1,   wrong_no_1},
    {"qqe_id-nyt-branchq",      CC_qqe_idKnytKbranchq,too_many_1,wrong_no_1},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"aminusp:1",               CC_aminuspT1,   too_many_1,    wrong_no_1},
    {"make-term",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKterm},
    {"subsetp",                 too_few_2,      CC_subsetp,    wrong_no_2},
    {"rnminus:",                CC_rnminusT,    too_many_1,    wrong_no_1},
    {"*i2gi",                   CC_Hi2gi,       too_many_1,    wrong_no_1},
    {"mkprogn",                 too_few_2,      CC_mkprogn,    wrong_no_2},
    {NULL, (one_args *)"u12", (two_args *)"2223 54844 2513044", 0}
};

/* end of generated code */
