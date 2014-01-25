
/* $destdir\u22.c        Machine generated C code */

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


/* Code for s!:prinl2 */

static Lisp_Object CC_sTprinl2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s:prinl2");
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
    v0055 = qvalue(elt(env, 1)); /* !*print!-level!* */
    v0055 = integerp(v0055);
    if (v0055 == nil) goto v0057;
    v0056 = stack[-2];
    v0055 = qvalue(elt(env, 1)); /* !*print!-level!* */
    v0055 = (Lisp_Object)greaterp2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-5];
    if (v0055 == nil) goto v0057;
    v0055 = elt(env, 2); /* "#" */
        popv(6);
        return Lprinc(nil, v0055);

v0057:
    v0055 = stack[-3];
    if (!consp(v0055)) goto v0059;
    v0055 = qvalue(elt(env, 3)); /* nil */
    goto v0060;

v0060:
    if (v0055 == nil) goto v0061;
    v0056 = qvalue(elt(env, 4)); /* !*prinl!-fn!* */
    v0055 = stack[-3];
        popv(6);
        return Lapply1(nil, v0056, v0055);

v0061:
    v0056 = stack[-3];
    v0055 = qvalue(elt(env, 5)); /* !*prinl!-visited!-nodes!* */
    fn = elt(env, 19); /* gethash */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-1] = v0055;
    v0055 = stack[-1];
    v0055 = (Lisp_Object)zerop(v0055);
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0055 == nil)) goto v0062;
    v0056 = stack[-1];
    v0055 = (Lisp_Object)1; /* 0 */
    v0055 = (Lisp_Object)lessp2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-5];
    if (v0055 == nil) goto v0063;
    v0055 = elt(env, 2); /* "#" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = stack[-1];
    v0055 = negate(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = elt(env, 2); /* "#" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v0055); }

v0063:
    stack[-4] = stack[-3];
    stack[0] = qvalue(elt(env, 5)); /* !*prinl!-visited!-nodes!* */
    v0055 = stack[-1];
    v0055 = negate(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    fn = elt(env, 20); /* puthash */
    v0055 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = elt(env, 2); /* "#" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = stack[-1];
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = elt(env, 6); /* "=" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0062;

v0062:
    v0055 = stack[-3];
    fn = elt(env, 21); /* simple!-vector!-p */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    if (v0055 == nil) goto v0064;
    v0055 = elt(env, 7); /* "%(" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = qvalue(elt(env, 8)); /* !*print!-array!* */
    if (v0055 == nil) goto v0065;
    v0055 = stack[-3];
    v0055 = Lupbv(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-4] = v0055;
    v0055 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0055 = integerp(v0055);
    if (v0055 == nil) goto v0066;
    v0056 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0055 = stack[-4];
    v0055 = (Lisp_Object)lessp2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-5];
    if (v0055 == nil) goto v0066;
    v0055 = qvalue(elt(env, 9)); /* !*print!-length!* */
    stack[-4] = v0055;
    goto v0066;

v0066:
    v0055 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0055;
    goto v0067;

v0067:
    v0056 = stack[-4];
    v0055 = stack[-1];
    v0055 = difference2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = Lminusp(nil, v0055);
    env = stack[-5];
    if (!(v0055 == nil)) goto v0068;
    v0056 = stack[-3];
    v0055 = stack[-1];
    stack[0] = *(Lisp_Object *)((char *)v0056 + (CELL-TAG_VECTOR) + ((int32_t)v0055/(16/CELL)));
    v0055 = stack[-2];
    v0055 = add1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = CC_sTprinl2(env, stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[0] = stack[-1];
    v0055 = stack[-3];
    v0055 = Lupbv(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    if (equal(stack[0], v0055)) goto v0069;
    v0055 = elt(env, 10); /* " " */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0069;

v0069:
    v0055 = stack[-1];
    v0055 = add1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-1] = v0055;
    goto v0067;

v0068:
    v0055 = elt(env, 12); /* ")" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v0055); }

v0065:
    v0055 = elt(env, 11); /* "..." */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0068;

v0064:
    v0055 = stack[-3];
    if (!consp(v0055)) goto v0070;
    v0055 = elt(env, 13); /* "(" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0055;
    goto v0071;

v0071:
    v0055 = stack[-3];
    stack[0] = qcar(v0055);
    v0055 = stack[-2];
    v0055 = add1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = CC_sTprinl2(env, stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = stack[-3];
    v0055 = qcdr(v0055);
    stack[-3] = v0055;
    v0055 = stack[-3];
    if (!consp(v0055)) goto v0072;
    v0055 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0055 = integerp(v0055);
    if (v0055 == nil) goto v0073;
    v0055 = stack[-4];
    v0056 = add1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-4] = v0056;
    v0055 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0055 = (Lisp_Object)greaterp2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-5];
    if (v0055 == nil) goto v0073;
    v0055 = elt(env, 16); /* " ...)" */
        popv(6);
        return Lprinc(nil, v0055);

v0073:
    v0056 = stack[-3];
    v0055 = qvalue(elt(env, 5)); /* !*prinl!-visited!-nodes!* */
    fn = elt(env, 19); /* gethash */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-1] = v0055;
    v0056 = stack[-1];
    v0055 = (Lisp_Object)1; /* 0 */
    if (v0056 == v0055) goto v0074;
    v0056 = stack[-1];
    v0055 = (Lisp_Object)1; /* 0 */
    v0055 = (Lisp_Object)lessp2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-5];
    if (v0055 == nil) goto v0075;
    v0055 = elt(env, 17); /* " . #" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = stack[-1];
    v0055 = negate(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = elt(env, 18); /* "#)" */
        popv(6);
        return Lprinc(nil, v0055);

v0075:
    v0055 = elt(env, 15); /* " . " */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[0] = stack[-3];
    v0055 = stack[-2];
    v0055 = add1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = CC_sTprinl2(env, stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = elt(env, 12); /* ")" */
        popv(6);
        return Lprinc(nil, v0055);

v0074:
    v0055 = elt(env, 10); /* " " */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0071;

v0072:
    v0055 = stack[-3];
    fn = elt(env, 21); /* simple!-vector!-p */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    if (v0055 == nil) goto v0076;
    v0055 = elt(env, 14); /* " . %(" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = qvalue(elt(env, 8)); /* !*print!-array!* */
    if (v0055 == nil) goto v0077;
    v0055 = stack[-3];
    v0055 = Lupbv(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-4] = v0055;
    v0055 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0055 = integerp(v0055);
    if (v0055 == nil) goto v0078;
    v0056 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0055 = stack[-4];
    v0055 = (Lisp_Object)lessp2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-5];
    if (v0055 == nil) goto v0078;
    v0055 = qvalue(elt(env, 9)); /* !*print!-length!* */
    stack[-4] = v0055;
    goto v0078;

v0078:
    v0055 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0055;
    goto v0079;

v0079:
    v0056 = stack[-4];
    v0055 = stack[-1];
    v0055 = difference2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = Lminusp(nil, v0055);
    env = stack[-5];
    if (!(v0055 == nil)) goto v0080;
    v0056 = stack[-3];
    v0055 = stack[-1];
    stack[0] = *(Lisp_Object *)((char *)v0056 + (CELL-TAG_VECTOR) + ((int32_t)v0055/(16/CELL)));
    v0055 = stack[-2];
    v0055 = add1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = CC_sTprinl2(env, stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[0] = stack[-1];
    v0055 = stack[-3];
    v0055 = Lupbv(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    if (equal(stack[0], v0055)) goto v0081;
    v0055 = elt(env, 10); /* " " */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0081;

v0081:
    v0055 = stack[-1];
    v0055 = add1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-1] = v0055;
    goto v0079;

v0080:
    v0055 = elt(env, 12); /* ")" */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0082;

v0082:
    v0055 = elt(env, 12); /* ")" */
        popv(6);
        return Lprinc(nil, v0055);

v0077:
    v0055 = elt(env, 11); /* "..." */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0080;

v0076:
    v0055 = stack[-3];
    if (v0055 == nil) goto v0082;
    v0055 = elt(env, 15); /* " . " */
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0056 = qvalue(elt(env, 4)); /* !*prinl!-fn!* */
    v0055 = stack[-3];
    v0055 = Lapply1(nil, v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0082;

v0070:
    v0056 = qvalue(elt(env, 4)); /* !*prinl!-fn!* */
    v0055 = stack[-3];
        popv(6);
        return Lapply1(nil, v0056, v0055);

v0059:
    v0055 = stack[-3];
    fn = elt(env, 21); /* simple!-vector!-p */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    if (v0055 == nil) goto v0083;
    v0055 = qvalue(elt(env, 3)); /* nil */
    goto v0060;

v0083:
    v0055 = stack[-3];
    fn = elt(env, 22); /* gensymp */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0055 = (v0055 == nil ? lisp_true : nil);
    goto v0060;
/* error exit handlers */
v0058:
    popv(6);
    return nil;
}



/* Code for refprint */

static Lisp_Object CC_refprint(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for refprint");
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
    stack[-3] = v0000;
/* end of prologue */
    v0097 = qvalue(elt(env, 1)); /* cloc!* */
    if (v0097 == nil) goto v0099;
    v0097 = qvalue(elt(env, 1)); /* cloc!* */
    v0097 = qcar(v0097);
    goto v0100;

v0100:
    stack[-4] = v0097;
    v0098 = stack[-4];
    v0097 = qvalue(elt(env, 3)); /* pfiles!* */
    v0097 = Lassoc(nil, v0098, v0097);
    qvalue(elt(env, 4)) = v0097; /* curfun!* */
    if (v0097 == nil) goto v0101;
    v0097 = qvalue(elt(env, 4)); /* curfun!* */
    v0097 = qcar(v0097);
    stack[-4] = v0097;
    v0097 = qvalue(elt(env, 4)); /* curfun!* */
    v0097 = qcdr(v0097);
    qvalue(elt(env, 4)) = v0097; /* curfun!* */
    goto v0053;

v0053:
    v0097 = qvalue(elt(env, 1)); /* cloc!* */
    if (v0097 == nil) goto v0102;
    v0097 = qvalue(elt(env, 1)); /* cloc!* */
    v0097 = qcdr(v0097);
    if (v0097 == nil) goto v0102;
    v0098 = stack[-4];
    v0097 = qvalue(elt(env, 1)); /* cloc!* */
    v0097 = qcdr(v0097);
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-5];
    goto v0104;

v0104:
    qvalue(elt(env, 8)) = v0097; /* curlin!* */
    v0097 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 9)) = v0097; /* locls!* */
    qvalue(elt(env, 10)) = v0097; /* globs!* */
    qvalue(elt(env, 11)) = v0097; /* calls!* */
    v0097 = stack[-3];
    fn = elt(env, 12); /* anform */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-5];
    v0097 = qvalue(elt(env, 4)); /* curfun!* */
    fn = elt(env, 13); /* outrefend */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    v0097 = nil;
    { popv(6); return onevalue(v0097); }

v0102:
    v0097 = qvalue(elt(env, 7)); /* nil */
    goto v0104;

v0101:
    stack[0] = stack[-4];
    v0097 = elt(env, 5); /* g */
    v0098 = Lgensym1(nil, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-5];
    qvalue(elt(env, 4)) = v0098; /* curfun!* */
    v0097 = qvalue(elt(env, 3)); /* pfiles!* */
    v0097 = acons(stack[0], v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-5];
    qvalue(elt(env, 3)) = v0097; /* pfiles!* */
    v0097 = stack[-4];
    v0097 = Lexplode(nil, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-5];
    v0097 = qcdr(v0097);
    v0097 = Lnreverse(nil, v0097);
    env = stack[-5];
    v0097 = qcdr(v0097);
    v0097 = Lnreverse(nil, v0097);
    env = stack[-5];
    stack[-2] = v0097;
    stack[-1] = qvalue(elt(env, 4)); /* curfun!* */
    stack[0] = elt(env, 6); /* rccnam */
    v0097 = stack[-2];
    v0098 = Llength(nil, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-5];
    v0097 = stack[-2];
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-5];
    v0097 = Lputprop(nil, 3, stack[-1], stack[0], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-5];
    goto v0053;

v0099:
    v0097 = elt(env, 2); /* "*TTYINPUT*" */
    goto v0100;
/* error exit handlers */
v0103:
    popv(6);
    return nil;
}



/* Code for cl_atml1 */

static Lisp_Object CC_cl_atml1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atml1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0107 = v0000;
/* end of prologue */
    v0108 = v0107;
    v0107 = elt(env, 1); /* cl_atmlc */
    {
        fn = elt(env, 2); /* cl_f2ml */
        return (*qfn2(fn))(qenv(fn), v0108, v0107);
    }
}



/* Code for triplesetprolongset */

static Lisp_Object CC_triplesetprolongset(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0113;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for triplesetprolongset");
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
    v0113 = nil;
    goto v0105;

v0105:
    v0112 = stack[0];
    if (v0112 == nil) goto v0059;
    v0112 = stack[0];
    v0112 = qcar(v0112);
    v0112 = cons(v0112, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0113 = v0112;
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    stack[0] = v0112;
    goto v0105;

v0059:
    stack[0] = (Lisp_Object)49; /* 3 */
    v0112 = v0113;
    v0112 = Lreverse(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0112;
    v0112 = nil;
    { popv(3); return onevalue(v0112); }
/* error exit handlers */
v0093:
    popv(3);
    return nil;
}



/* Code for mkpartitions1 */

static Lisp_Object MS_CDECL CC_mkpartitions1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0137, v0138, v0139;
    Lisp_Object v0120, v0121, v0090, v0085, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "mkpartitions1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0085 = va_arg(aa, Lisp_Object);
    v0090 = va_arg(aa, Lisp_Object);
    v0121 = va_arg(aa, Lisp_Object);
    v0120 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkpartitions1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0120,v0121,v0090,v0085,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0085,v0090,v0121,v0120);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0120;
    stack[-4] = v0121;
    stack[-5] = v0090;
    stack[-6] = v0085;
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */

v0054:
    v0137 = stack[-7];
    v0136 = (Lisp_Object)17; /* 1 */
    if (v0137 == v0136) goto v0140;
    v0137 = stack[-6];
    v0136 = stack[-5];
    v0136 = (Lisp_Object)greaterp2(v0137, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    v0136 = v0136 ? lisp_true : nil;
    env = stack[-10];
    if (!(v0136 == nil)) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0137 = stack[-8];
    v0136 = stack[-6];
    v0136 = difference2(v0137, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    stack[-9] = v0136;
    v0136 = stack[-7];
    v0136 = sub1(v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    stack[-2] = v0136;
    v0137 = stack[-8];
    v0136 = stack[-6];
    stack[0] = difference2(v0137, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    v0136 = stack[-7];
    v0136 = sub1(v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    v0136 = quot2(stack[0], v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    stack[-1] = v0136;
    v0137 = stack[-6];
    v0136 = stack[-4];
    v0136 = cons(v0137, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    stack[0] = v0136;
    v0136 = stack[-6];
    v0139 = add1(v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    v0138 = stack[-5];
    v0137 = stack[-4];
    v0136 = stack[-3];
    v0136 = CC_mkpartitions1(env, 6, stack[-8], stack[-7], v0139, v0138, v0137, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    stack[-3] = v0136;
    v0136 = stack[0];
    stack[-4] = v0136;
    v0136 = stack[-1];
    stack[-5] = v0136;
    v0136 = stack[-2];
    stack[-7] = v0136;
    v0136 = stack[-9];
    stack[-8] = v0136;
    goto v0054;

v0140:
    v0137 = stack[-8];
    v0136 = stack[-6];
    v0136 = (Lisp_Object)geq2(v0137, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    v0136 = v0136 ? lisp_true : nil;
    env = stack[-10];
    if (v0136 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0137 = stack[-8];
    v0136 = stack[-4];
    v0136 = cons(v0137, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-10];
    v0137 = Lreverse(nil, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    v0136 = stack[-3];
    popv(11);
    return cons(v0137, v0136);
/* error exit handlers */
v0141:
    popv(11);
    return nil;
}



/* Code for mkprod */

static Lisp_Object CC_mkprod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkprod");
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
    stack[-2] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v0168 = stack[-4];
    if (v0168 == nil) goto v0169;
    v0168 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    goto v0171;

v0171:
    if (v0168 == nil) goto v0108;
    v0168 = stack[-4];
    goto v0106;

v0106:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    { popv(7); return onevalue(v0168); }

v0108:
    v0168 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v0168; /* !*sub2 */
    v0016 = stack[-4];
    v0168 = (Lisp_Object)17; /* 1 */
    v0168 = cons(v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    fn = elt(env, 11); /* subs2 */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[0] = v0168;
    v0168 = stack[0];
    v0016 = qcdr(v0168);
    v0168 = (Lisp_Object)17; /* 1 */
    if (v0016 == v0168) goto v0133;
    v0168 = stack[-4];
    goto v0106;

v0133:
    v0168 = stack[0];
    v0016 = qcar(v0168);
    v0168 = stack[-4];
    if (equal(v0016, v0168)) goto v0109;
    v0168 = stack[0];
    v0168 = qcar(v0168);
    stack[-4] = v0168;
    v0168 = stack[-4];
    if (v0168 == nil) goto v0172;
    v0168 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    goto v0131;

v0131:
    if (v0168 == nil) goto v0109;
    v0168 = stack[-4];
    goto v0106;

v0109:
    v0168 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v0168; /* !*exp */
    v0168 = stack[-4];
    fn = elt(env, 12); /* ckrn */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-5] = v0168;
    v0016 = stack[-4];
    v0168 = stack[-5];
    fn = elt(env, 13); /* quotf */
    v0168 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-4] = v0168;
    v0168 = stack[-4];
    fn = elt(env, 14); /* expnd */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[0] = v0168;
    v0168 = stack[0];
    if (v0168 == nil) goto v0173;
    v0168 = stack[0];
    fn = elt(env, 10); /* kernlp */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    goto v0125;

v0125:
    if (v0168 == nil) goto v0102;
    v0016 = stack[-5];
    v0168 = stack[0];
    fn = elt(env, 15); /* multf */
    v0168 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    goto v0106;

v0102:
    v0168 = qvalue(elt(env, 4)); /* !*mcd */
    if (v0168 == nil) goto v0174;
    v0168 = qvalue(elt(env, 5)); /* !*sqfree */
    if (!(v0168 == nil)) goto v0175;
    v0168 = qvalue(elt(env, 6)); /* !*factor */
    if (!(v0168 == nil)) goto v0175;
    v0168 = qvalue(elt(env, 7)); /* !*gcd */
    if (!(v0168 == nil)) goto v0175;

v0174:
    v0168 = stack[0];
    fn = elt(env, 12); /* ckrn */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-3] = v0168;
    v0016 = stack[0];
    v0168 = stack[-3];
    fn = elt(env, 13); /* quotf */
    v0168 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[0] = v0168;
    v0016 = stack[0];
    v0168 = (Lisp_Object)17; /* 1 */
    v0168 = cons(v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0168 = list2(stack[-3], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-3] = v0168;
    goto v0067;

v0067:
    v0168 = stack[-3];
    v0168 = qcdr(v0168);
    v0168 = qcar(v0168);
    v0016 = qcdr(v0168);
    v0168 = (Lisp_Object)17; /* 1 */
    v0168 = (Lisp_Object)greaterp2(v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0168 = v0168 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0168 == nil)) goto v0176;
    v0168 = stack[-3];
    v0168 = qcdr(v0168);
    v0168 = qcdr(v0168);
    if (!(v0168 == nil)) goto v0176;
    v0168 = qvalue(elt(env, 9)); /* !*group */
    if (v0168 == nil) goto v0177;
    v0168 = qvalue(elt(env, 8)); /* nil */
    goto v0178;

v0178:
    if (v0168 == nil) goto v0078;
    v0168 = stack[-3];
    v0168 = qcdr(v0168);
    v0168 = qcar(v0168);
    v0016 = qcar(v0168);
    v0168 = stack[-3];
    v0168 = qcdr(v0168);
    v0168 = qcar(v0168);
    v0168 = qcdr(v0168);
    fn = elt(env, 16); /* mksp!* */
    v0016 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0168 = stack[-3];
    v0168 = qcar(v0168);
    fn = elt(env, 15); /* multf */
    v0168 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[0] = v0168;
    goto v0179;

v0179:
    v0016 = stack[-5];
    v0168 = stack[0];
    fn = elt(env, 15); /* multf */
    v0168 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    goto v0106;

v0078:
    v0016 = stack[-4];
    v0168 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksp!* */
    v0168 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[0] = v0168;
    goto v0179;

v0177:
    v0168 = stack[-4];
    fn = elt(env, 17); /* tmsf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0168 = stack[-3];
    v0168 = qcdr(v0168);
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    fn = elt(env, 17); /* tmsf */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0168 = (Lisp_Object)greaterp2(stack[0], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0168 = v0168 ? lisp_true : nil;
    env = stack[-6];
    goto v0178;

v0176:
    v0168 = stack[-3];
    v0168 = qcar(v0168);
    stack[0] = v0168;
    v0168 = stack[-3];
    v0168 = qcdr(v0168);
    stack[-3] = v0168;
    goto v0036;

v0036:
    v0168 = stack[-3];
    if (v0168 == nil) goto v0179;
    v0168 = stack[-3];
    v0168 = qcar(v0168);
    v0016 = v0168;
    v0016 = qcar(v0016);
    v0168 = qcdr(v0168);
    fn = elt(env, 16); /* mksp!* */
    v0016 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0168 = stack[0];
    fn = elt(env, 15); /* multf */
    v0168 = (*qfn2(fn))(qenv(fn), v0016, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[0] = v0168;
    v0168 = stack[-3];
    v0168 = qcdr(v0168);
    stack[-3] = v0168;
    goto v0036;

v0175:
    v0168 = stack[0];
    fn = elt(env, 18); /* fctrf */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-3] = v0168;
    goto v0067;

v0173:
    v0168 = qvalue(elt(env, 3)); /* t */
    goto v0125;

v0172:
    v0168 = qvalue(elt(env, 3)); /* t */
    goto v0131;

v0169:
    v0168 = qvalue(elt(env, 3)); /* t */
    goto v0171;
/* error exit handlers */
v0170:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    popv(7);
    return nil;
}



/* Code for rationalizesq */

static Lisp_Object CC_rationalizesq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0185, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rationalizesq");
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
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* !*structure */
    qvalue(elt(env, 1)) = nil; /* !*structure */
    stack[-2] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v0186 = qvalue(elt(env, 3)); /* dmode!* */
    v0185 = elt(env, 4); /* rationalizefn */
    v0185 = get(v0186, v0185);
    env = stack[-5];
    stack[0] = v0185;
    if (v0185 == nil) goto v0059;
    v0186 = stack[0];
    v0185 = stack[-3];
    v0185 = Lapply1(nil, v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-3] = v0185;
    goto v0059;

v0059:
    v0186 = elt(env, 5); /* (i 2 (nil . t) -1 nil) */
    v0185 = qvalue(elt(env, 6)); /* powlis!* */
    v0185 = cons(v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0185; /* powlis!* */
    v0185 = stack[-3];
    fn = elt(env, 11); /* subs2q */
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = v0185;
    v0185 = qvalue(elt(env, 6)); /* powlis!* */
    v0185 = qcdr(v0185);
    qvalue(elt(env, 6)) = v0185; /* powlis!* */
    v0185 = stack[-1];
    v0185 = qcdr(v0185);
    if (!consp(v0185)) goto v0165;
    v0185 = stack[-1];
    v0185 = qcdr(v0185);
    v0185 = qcar(v0185);
    v0185 = (consp(v0185) ? nil : lisp_true);
    goto v0092;

v0092:
    if (v0185 == nil) goto v0088;
    v0185 = stack[-1];
    goto v0100;

v0100:
    qvalue(elt(env, 2)) = stack[-2]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-4]; /* !*structure */
    { popv(6); return onevalue(v0185); }

v0088:
    v0185 = stack[-1];
    v0185 = qcdr(v0185);
    fn = elt(env, 12); /* rationalizef */
    v0186 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[0] = v0186;
    v0185 = (Lisp_Object)17; /* 1 */
    if (v0186 == v0185) goto v0187;
    v0185 = stack[-1];
    v0186 = qcar(v0185);
    v0185 = stack[0];
    fn = elt(env, 13); /* multf */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0185 = stack[-1];
    v0186 = qcdr(v0185);
    v0185 = stack[0];
    fn = elt(env, 13); /* multf */
    v0185 = (*qfn2(fn))(qenv(fn), v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0185 = cons(stack[-3], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = v0185;
    v0185 = qvalue(elt(env, 8)); /* !*algint */
    if (v0185 == nil) goto v0063;
    v0185 = qvalue(elt(env, 10)); /* nil */
    goto v0098;

v0098:
    if (v0185 == nil) goto v0173;
    v0185 = stack[-1];
    fn = elt(env, 14); /* gcdchk */
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = v0185;
    goto v0173;

v0173:
    v0185 = stack[-1];
    fn = elt(env, 11); /* subs2q */
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    goto v0100;

v0063:
    v0185 = qvalue(elt(env, 9)); /* !*rationalize */
    v0185 = (v0185 == nil ? lisp_true : nil);
    goto v0098;

v0187:
    v0185 = stack[-3];
    goto v0100;

v0165:
    v0185 = qvalue(elt(env, 7)); /* t */
    goto v0092;
/* error exit handlers */
v0116:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-2]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-4]; /* !*structure */
    popv(6);
    return nil;
}



/* Code for meq */

static Lisp_Object CC_meq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0188, v0052, v0166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for meq");
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
    v0188 = stack[-1];
    fn = elt(env, 2); /* binding */
    v0188 = (*qfn1(fn))(qenv(fn), v0188);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    v0052 = v0188;
    v0188 = v0052;
    if (v0188 == nil) goto v0095;
    v0188 = v0052;
    v0166 = elt(env, 1); /* unbound */
    if (v0188 == v0166) goto v0095;
    v0188 = v0052;
    v0052 = v0188;
    goto v0105;

v0105:
    v0188 = stack[0];
    v0188 = (equal(v0052, v0188) ? lisp_true : nil);
    { popv(3); return onevalue(v0188); }

v0095:
    v0188 = stack[-1];
    v0052 = v0188;
    goto v0105;
/* error exit handlers */
v0109:
    popv(3);
    return nil;
}



/* Code for gcompatible */

static Lisp_Object CC_gcompatible(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0051, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcompatible");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0001;
    v0060 = v0000;
/* end of prologue */
    v0095 = qvalue(elt(env, 1)); /* gmodule!* */
    if (v0095 == nil) goto v0120;
    v0095 = v0060;
    v0095 = qcdr(v0095);
    v0060 = qcar(v0095);
    v0095 = v0051;
    v0095 = qcdr(v0095);
    v0051 = qcar(v0095);
    v0095 = qvalue(elt(env, 1)); /* gmodule!* */
    {
        fn = elt(env, 3); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v0060, v0051, v0095);
    }

v0120:
    v0095 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0095);
}



/* Code for rd!:times */

static Lisp_Object CC_rdTtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0199, v0200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:times");
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
    v0032 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0032;
    v0032 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v0032 == nil) goto v0108;
    v0032 = qvalue(elt(env, 1)); /* nil */
    goto v0107;

v0107:
    if (v0032 == nil) goto v0088;
    v0199 = elt(env, 3); /* !:rd!: */
    v0032 = stack[0];
    popv(5);
    return cons(v0199, v0032);

v0088:
    v0199 = stack[-2];
    v0032 = stack[-1];
    fn = elt(env, 6); /* convprc2 */
    v0032 = (*qfn2(fn))(qenv(fn), v0199, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[-3] = v0032;
    v0032 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v0032;
    v0032 = stack[-3];
    if (!consp(v0032)) goto v0126;
    v0199 = stack[-3];
    v0032 = stack[-2];
    fn = elt(env, 7); /* csl_timbf */
    v0032 = (*qfn2(fn))(qenv(fn), v0199, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0089;

v0089:
    {
        popv(5);
        fn = elt(env, 8); /* mkround */
        return (*qfn1(fn))(qenv(fn), v0032);
    }

v0126:
    stack[-1] = elt(env, 5); /* times2 */
    v0032 = stack[-3];
    stack[0] = Lmkquote(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0032 = stack[-2];
    v0032 = Lmkquote(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0199 = list3(stack[-1], stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0032 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 9); /* errorset!* */
    v0032 = (*qfn2(fn))(qenv(fn), v0199, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[0] = v0032;
    v0032 = stack[0];
    fn = elt(env, 10); /* errorp */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    if (v0032 == nil) goto v0153;
    fn = elt(env, 11); /* rndbfon */
    v0032 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0032 = stack[-3];
    v0032 = Lfloatp(nil, v0032);
    env = stack[-4];
    if (v0032 == nil) goto v0068;
    v0032 = stack[-3];
    fn = elt(env, 12); /* fl2bf */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[0] = v0032;
    goto v0185;

v0185:
    v0032 = stack[-2];
    v0032 = Lfloatp(nil, v0032);
    env = stack[-4];
    if (v0032 == nil) goto v0202;
    v0032 = stack[-2];
    fn = elt(env, 12); /* fl2bf */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0186;

v0186:
    fn = elt(env, 7); /* csl_timbf */
    v0032 = (*qfn2(fn))(qenv(fn), stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0089;

v0202:
    v0032 = stack[-2];
    if (!consp(v0032)) goto v0155;
    v0032 = stack[-2];
    goto v0039;

v0039:
    fn = elt(env, 13); /* normbf */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0186;

v0155:
    v0032 = stack[-2];
    v0032 = integerp(v0032);
    if (v0032 == nil) goto v0203;
    v0200 = elt(env, 3); /* !:rd!: */
    v0199 = stack[-2];
    v0032 = (Lisp_Object)1; /* 0 */
    v0032 = list2star(v0200, v0199, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0039;

v0203:
    v0032 = stack[-2];
    fn = elt(env, 14); /* read!:num */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0039;

v0068:
    v0032 = stack[-3];
    if (!consp(v0032)) goto v0139;
    v0032 = stack[-3];
    goto v0137;

v0137:
    fn = elt(env, 13); /* normbf */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[0] = v0032;
    goto v0185;

v0139:
    v0032 = stack[-3];
    v0032 = integerp(v0032);
    if (v0032 == nil) goto v0204;
    v0200 = elt(env, 3); /* !:rd!: */
    v0199 = stack[-3];
    v0032 = (Lisp_Object)1; /* 0 */
    v0032 = list2star(v0200, v0199, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0137;

v0204:
    v0032 = stack[-3];
    fn = elt(env, 14); /* read!:num */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0137;

v0153:
    v0032 = stack[0];
    v0032 = qcar(v0032);
    goto v0089;

v0108:
    v0032 = stack[-2];
    v0032 = qcdr(v0032);
    if (!consp(v0032)) goto v0169;
    v0032 = qvalue(elt(env, 1)); /* nil */
    goto v0107;

v0169:
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    if (!consp(v0032)) goto v0051;
    v0032 = qvalue(elt(env, 1)); /* nil */
    goto v0107;

v0051:
    v0032 = stack[-2];
    v0199 = qcdr(v0032);
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    fn = elt(env, 15); /* safe!-fp!-times */
    v0032 = (*qfn2(fn))(qenv(fn), v0199, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[0] = v0032;
    goto v0107;
/* error exit handlers */
v0201:
    popv(5);
    return nil;
}



/* Code for subla!-q */

static Lisp_Object CC_sublaKq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0191, v0190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subla-q");
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
    v0191 = stack[-1];
    if (v0191 == nil) goto v0215;
    v0191 = stack[0];
    v0191 = (v0191 == nil ? lisp_true : nil);
    goto v0108;

v0108:
    if (!(v0191 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0191 = stack[0];
    if (!consp(v0191)) goto v0060;
    v0191 = stack[0];
    v0190 = qcar(v0191);
    v0191 = elt(env, 2); /* quote */
    if (v0190 == v0191) goto v0092;
    v0191 = stack[0];
    v0190 = qcar(v0191);
    v0191 = elt(env, 3); /* go */
    v0191 = (v0190 == v0191 ? lisp_true : nil);
    goto v0183;

v0183:
    if (!(v0191 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0190 = stack[0];
    v0191 = elt(env, 4); /* lambda */
    if (!consp(v0190)) goto v0194;
    v0190 = qcar(v0190);
    if (!(v0190 == v0191)) goto v0194;
    v0191 = qvalue(elt(env, 1)); /* t */
    goto v0128;

v0128:
    if (v0191 == nil) goto v0122;
    v0191 = stack[0];
    v0191 = qcdr(v0191);
    v0191 = (consp(v0191) ? nil : lisp_true);
    v0191 = (v0191 == nil ? lisp_true : nil);
    goto v0062;

v0062:
    if (v0191 == nil) goto v0039;
    v0191 = stack[0];
    v0191 = qcdr(v0191);
    v0191 = qcar(v0191);
    stack[-2] = v0191;
    goto v0216;

v0216:
    v0191 = stack[-2];
    if (v0191 == nil) goto v0217;
    v0191 = stack[-2];
    v0191 = qcar(v0191);
    v0190 = v0191;
    v0191 = stack[-1];
    fn = elt(env, 7); /* delasc */
    v0191 = (*qfn2(fn))(qenv(fn), v0190, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    stack[-1] = v0191;
    v0191 = stack[-2];
    v0191 = qcdr(v0191);
    stack[-2] = v0191;
    goto v0216;

v0217:
    v0190 = stack[-1];
    v0191 = stack[0];
    v0191 = qcar(v0191);
    stack[-2] = CC_sublaKq(env, v0190, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0190 = stack[-1];
    v0191 = stack[0];
    v0191 = qcdr(v0191);
    v0191 = CC_sublaKq(env, v0190, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    {
        Lisp_Object v0219 = stack[-2];
        popv(4);
        return cons(v0219, v0191);
    }

v0039:
    v0190 = stack[-1];
    v0191 = stack[0];
    v0191 = qcar(v0191);
    stack[-2] = CC_sublaKq(env, v0190, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0190 = stack[-1];
    v0191 = stack[0];
    v0191 = qcdr(v0191);
    v0191 = CC_sublaKq(env, v0190, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    {
        Lisp_Object v0153 = stack[-2];
        popv(4);
        return cons(v0153, v0191);
    }

v0122:
    v0191 = qvalue(elt(env, 6)); /* nil */
    goto v0062;

v0194:
    v0190 = stack[0];
    v0191 = elt(env, 5); /* prog */
    v0191 = Leqcar(nil, v0190, v0191);
    env = stack[-3];
    goto v0128;

v0092:
    v0191 = qvalue(elt(env, 1)); /* t */
    goto v0183;

v0060:
    v0190 = stack[0];
    v0191 = stack[-1];
    v0190 = Latsoc(nil, v0190, v0191);
    v0191 = v0190;
    if (v0190 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0191 = qcdr(v0191);
    { popv(4); return onevalue(v0191); }

v0215:
    v0191 = qvalue(elt(env, 1)); /* t */
    goto v0108;
/* error exit handlers */
v0218:
    popv(4);
    return nil;
}



/* Code for mo_equal!? */

static Lisp_Object CC_mo_equalW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_equal?");
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
    v0171 = v0000;
/* end of prologue */
    v0171 = qcar(v0171);
    fn = elt(env, 1); /* mo!=shorten */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0171 = stack[0];
    v0171 = qcar(v0171);
    fn = elt(env, 1); /* mo!=shorten */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    v0171 = (equal(stack[-1], v0171) ? lisp_true : nil);
    { popv(3); return onevalue(v0171); }
/* error exit handlers */
v0054:
    popv(3);
    return nil;
}



/* Code for outref */

static Lisp_Object MS_CDECL CC_outref(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0221, v0185, v0186;
    Lisp_Object fn;
    Lisp_Object v0090, v0085, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "outref");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0085 = va_arg(aa, Lisp_Object);
    v0090 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for outref");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0090,v0085,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0085,v0090);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0090;
    stack[-6] = v0085;
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* curfun!* */
    qvalue(elt(env, 1)) = nil; /* curfun!* */
    stack[-4] = qvalue(elt(env, 2)); /* calls!* */
    qvalue(elt(env, 2)) = nil; /* calls!* */
    stack[-3] = qvalue(elt(env, 3)); /* globs!* */
    qvalue(elt(env, 3)) = nil; /* globs!* */
    stack[-2] = qvalue(elt(env, 4)); /* locls!* */
    qvalue(elt(env, 4)) = nil; /* locls!* */
    stack[-1] = qvalue(elt(env, 5)); /* toplv!* */
    qvalue(elt(env, 5)) = nil; /* toplv!* */
    v0185 = stack[-7];
    v0221 = elt(env, 6); /* (anp!!atom anp!!idb anp!!eq anp!!unknown) */
    v0221 = Lmemq(nil, v0185, v0221);
    if (v0221 == nil) goto v0095;
    v0221 = qvalue(elt(env, 7)); /* nil */
    goto v0167;

v0167:
    stack[0] = v0221;
    v0186 = stack[-8];
    v0185 = stack[-5];
    v0221 = stack[0];
    if (v0221 == nil) goto v0165;
    v0221 = stack[0];
    goto v0109;

v0109:
    fn = elt(env, 12); /* outrdefun */
    v0221 = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    stack[-8] = v0221;
    v0221 = stack[0];
    if (v0221 == nil) goto v0050;
    v0221 = stack[-7];
    fn = elt(env, 13); /* add2locs */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    v0221 = stack[-6];
    fn = elt(env, 14); /* anform */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    v0221 = stack[-7];
    fn = elt(env, 15); /* remlocs */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    goto v0134;

v0134:
    v0221 = stack[-8];
    fn = elt(env, 16); /* outrefend */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    v0221 = nil;
    qvalue(elt(env, 5)) = stack[-1]; /* toplv!* */
    qvalue(elt(env, 4)) = stack[-2]; /* locls!* */
    qvalue(elt(env, 3)) = stack[-3]; /* globs!* */
    qvalue(elt(env, 2)) = stack[-4]; /* calls!* */
    qvalue(elt(env, 1)) = stack[-9]; /* curfun!* */
    { popv(11); return onevalue(v0221); }

v0050:
    v0221 = stack[-6];
    if (v0221 == nil) goto v0131;
    v0221 = stack[-6];
    v0221 = Lsymbolp(nil, v0221);
    env = stack[-10];
    v0221 = (v0221 == nil ? lisp_true : nil);
    goto v0130;

v0130:
    if (!(v0221 == nil)) goto v0134;
    v0185 = stack[-7];
    v0221 = elt(env, 9); /* anp!!eq */
    if (v0185 == v0221) goto v0124;
    v0221 = stack[-6];
    fn = elt(env, 17); /* add2calls */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    goto v0134;

v0124:
    stack[-5] = stack[-8];
    stack[0] = elt(env, 10); /* sameas */
    v0221 = stack[-6];
    v0221 = ncons(v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    v0221 = Lputprop(nil, 3, stack[-5], stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    v0186 = stack[-6];
    v0185 = elt(env, 11); /* alsois */
    v0221 = stack[-8];
    fn = elt(env, 18); /* traput */
    v0221 = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    goto v0134;

v0131:
    v0221 = qvalue(elt(env, 8)); /* t */
    goto v0130;

v0165:
    v0221 = stack[-6];
    if (!symbolp(v0221)) v0221 = nil;
    else { v0221 = qfastgets(v0221);
           if (v0221 != nil) { v0221 = elt(v0221, 42); /* number!-of!-args 
*/
#ifdef RECORD_GET
             if (v0221 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v0221 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v0221 == SPID_NOPROP) v0221 = nil; }}
#endif
    goto v0109;

v0095:
    v0221 = stack[-7];
    v0221 = Llength(nil, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-10];
    goto v0167;
/* error exit handlers */
v0174:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[-1]; /* toplv!* */
    qvalue(elt(env, 4)) = stack[-2]; /* locls!* */
    qvalue(elt(env, 3)) = stack[-3]; /* globs!* */
    qvalue(elt(env, 2)) = stack[-4]; /* calls!* */
    qvalue(elt(env, 1)) = stack[-9]; /* curfun!* */
    popv(11);
    return nil;
}



/* Code for tripleisprolongedby */

static Lisp_Object CC_tripleisprolongedby(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0086;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tripleisprolongedby");
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
    v0088 = v0000;
/* end of prologue */
    v0086 = v0088;
    v0088 = (Lisp_Object)49; /* 3 */
    v0088 = *(Lisp_Object *)((char *)v0086 + (CELL-TAG_VECTOR) + ((int32_t)v0088/(16/CELL)));
    stack[-1] = v0088;
    goto v0169;

v0169:
    v0088 = stack[-1];
    v0088 = qcar(v0088);
    if (v0088 == nil) goto v0171;
    v0088 = stack[-1];
    v0086 = qcar(v0088);
    v0088 = stack[0];
    v0088 = (Lisp_Object)greaterp2(v0086, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-2];
    if (v0088 == nil) goto v0171;
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-1] = v0088;
    goto v0169;

v0171:
    v0088 = stack[-1];
    v0088 = qcar(v0088);
    if (v0088 == nil) goto v0164;
    v0088 = stack[-1];
    v0086 = qcar(v0088);
    v0088 = stack[0];
    if (!(equal(v0086, v0088))) goto v0164;
    v0088 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v0088); }

v0164:
    v0088 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0088); }
/* error exit handlers */
v0130:
    popv(3);
    return nil;
}



/* Code for cl_flip */

static Lisp_Object CC_cl_flip(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0213, v0214, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_flip");
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
    v0097 = v0000;
/* end of prologue */
    v0214 = v0097;
    v0213 = elt(env, 1); /* and */
    if (v0214 == v0213) goto v0121;
    v0214 = v0097;
    v0213 = elt(env, 2); /* or */
    if (v0214 == v0213) goto v0167;
    v0214 = v0097;
    v0213 = elt(env, 3); /* all */
    if (v0214 == v0213) goto v0135;
    v0214 = v0097;
    v0213 = elt(env, 4); /* ex */
    if (v0214 == v0213) goto v0083;
    v0214 = v0097;
    v0213 = elt(env, 5); /* ball */
    if (v0214 == v0213) goto v0183;
    v0214 = v0097;
    v0213 = elt(env, 6); /* bex */
    if (v0214 == v0213) goto v0049;
    v0214 = v0097;
    v0213 = elt(env, 7); /* true */
    if (v0214 == v0213) goto v0130;
    v0214 = v0097;
    v0213 = elt(env, 8); /* false */
    if (v0214 == v0213) goto v0212;
    v0213 = elt(env, 9); /* "cl_flip(): don't know" */
    v0214 = v0097;
    v0213 = list2(v0213, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 10); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0213);
    }

v0212:
    v0213 = elt(env, 7); /* true */
    { popv(1); return onevalue(v0213); }

v0130:
    v0213 = elt(env, 8); /* false */
    { popv(1); return onevalue(v0213); }

v0049:
    v0213 = elt(env, 5); /* ball */
    { popv(1); return onevalue(v0213); }

v0183:
    v0213 = elt(env, 6); /* bex */
    { popv(1); return onevalue(v0213); }

v0083:
    v0213 = elt(env, 3); /* all */
    { popv(1); return onevalue(v0213); }

v0135:
    v0213 = elt(env, 4); /* ex */
    { popv(1); return onevalue(v0213); }

v0167:
    v0213 = elt(env, 1); /* and */
    { popv(1); return onevalue(v0213); }

v0121:
    v0213 = elt(env, 2); /* or */
    { popv(1); return onevalue(v0213); }
/* error exit handlers */
v0098:
    popv(1);
    return nil;
}



/* Code for simpcv */

static Lisp_Object CC_simpcv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpcv");
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
    v0129 = stack[-1];
    v0225 = Llength(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-2];
    v0129 = (Lisp_Object)49; /* 3 */
    if (v0225 == v0129) goto v0140;
    v0225 = elt(env, 1); /* "Invalid number of edges in vertex" */
    v0129 = stack[-1];
    v0129 = list2(v0225, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* cerror */
        return (*qfn1(fn))(qenv(fn), v0129);
    }

v0140:
    v0225 = elt(env, 2); /* simpcgraph */
    v0129 = qvalue(elt(env, 3)); /* mul!* */
    v0129 = Lmemq(nil, v0225, v0129);
    if (!(v0129 == nil)) goto v0172;
    v0225 = qvalue(elt(env, 3)); /* mul!* */
    v0129 = elt(env, 2); /* simpcgraph */
    fn = elt(env, 5); /* aconc!* */
    v0129 = (*qfn2(fn))(qenv(fn), v0225, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0129; /* mul!* */
    goto v0172;

v0172:
    v0225 = stack[0];
    v0129 = stack[-1];
    v0225 = cons(v0225, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-2];
    v0129 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* to */
    v0225 = (*qfn2(fn))(qenv(fn), v0225, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-2];
    v0129 = (Lisp_Object)17; /* 1 */
    v0129 = cons(v0225, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-2];
    v0225 = ncons(v0129);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    v0129 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0225, v0129);
/* error exit handlers */
v0196:
    popv(3);
    return nil;
}



/* Code for drop_pde_from_idties */

static Lisp_Object MS_CDECL CC_drop_pde_from_idties(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0246, v0247, v0248, v0249;
    Lisp_Object fn;
    Lisp_Object v0085, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "drop_pde_from_idties");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0085 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for drop_pde_from_idties");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0085,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0085);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0085;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    v0246 = stack[-4];
    stack[-6] = v0246;
    goto v0215;

v0215:
    v0246 = stack[-6];
    if (v0246 == nil) goto v0108;
    v0246 = stack[-6];
    v0246 = qcar(v0246);
    stack[-2] = v0246;
    v0247 = stack[-2];
    v0246 = stack[-5];
    if (equal(v0247, v0246)) goto v0135;
    v0247 = stack[-2];
    v0246 = elt(env, 2); /* histry_ */
    v0247 = get(v0247, v0246);
    env = stack[-7];
    v0246 = stack[-5];
    fn = elt(env, 13); /* freeof */
    v0246 = (*qfn2(fn))(qenv(fn), v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    if (!(v0246 == nil)) goto v0135;
    stack[-1] = stack[-2];
    stack[0] = elt(env, 2); /* histry_ */
    v0246 = stack[-3];
    if (v0246 == nil) goto v0131;
    v0249 = stack[-3];
    v0248 = stack[-5];
    v0247 = stack[-2];
    v0246 = elt(env, 2); /* histry_ */
    v0246 = get(v0247, v0246);
    env = stack[-7];
    v0246 = Lsubst(nil, 3, v0249, v0248, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    goto v0223;

v0223:
    v0246 = Lputprop(nil, 3, stack[-1], stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    goto v0135;

v0135:
    v0246 = stack[-6];
    v0246 = qcdr(v0246);
    stack[-6] = v0246;
    goto v0215;

v0131:
    v0246 = stack[-2];
    goto v0223;

v0108:
    v0246 = qvalue(elt(env, 3)); /* record_hist */
    if (v0246 == nil) goto v0127;
    v0246 = elt(env, 4); /* show_id */
    fn = elt(env, 14); /* getd */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    if (v0246 == nil) goto v0127;
    v0246 = qvalue(elt(env, 5)); /* idnties_ */
    stack[0] = v0246;
    goto v0195;

v0195:
    v0246 = stack[0];
    if (v0246 == nil) goto v0123;
    v0246 = stack[0];
    v0247 = qcar(v0246);
    v0246 = elt(env, 6); /* val */
    v0247 = get(v0247, v0246);
    env = stack[-7];
    v0246 = stack[-5];
    fn = elt(env, 13); /* freeof */
    v0246 = (*qfn2(fn))(qenv(fn), v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    if (!(v0246 == nil)) goto v0187;
    v0246 = stack[-3];
    if (v0246 == nil) goto v0066;
    v0249 = stack[-3];
    v0248 = stack[-5];
    v0246 = stack[0];
    v0247 = qcar(v0246);
    v0246 = elt(env, 6); /* val */
    v0246 = get(v0247, v0246);
    env = stack[-7];
    v0246 = Lsubst(nil, 3, v0249, v0248, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    fn = elt(env, 15); /* reval */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    stack[-1] = v0246;
    v0247 = stack[-4];
    v0246 = stack[-1];
    fn = elt(env, 16); /* trivial_idty */
    v0246 = (*qfn2(fn))(qenv(fn), v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    if (v0246 == nil) goto v0036;
    v0246 = stack[0];
    v0246 = qcar(v0246);
    fn = elt(env, 17); /* drop_idty */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    goto v0187;

v0187:
    v0246 = stack[0];
    v0246 = qcdr(v0246);
    stack[0] = v0246;
    goto v0195;

v0036:
    v0246 = stack[0];
    v0248 = qcar(v0246);
    v0247 = elt(env, 6); /* val */
    v0246 = stack[-1];
    v0246 = Lputprop(nil, 3, v0248, v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    v0246 = stack[0];
    v0246 = qcar(v0246);
    v0247 = ncons(v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    v0246 = elt(env, 7); /* to_subst */
    v0246 = Lflag(nil, v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    v0246 = stack[0];
    v0246 = qcar(v0246);
    v0247 = ncons(v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    v0246 = elt(env, 8); /* to_int */
    v0246 = Lflag(nil, v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    goto v0187;

v0066:
    v0246 = stack[0];
    v0246 = qcar(v0246);
    fn = elt(env, 17); /* drop_idty */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    goto v0187;

v0123:
    v0246 = stack[-3];
    if (v0246 == nil) goto v0127;
    v0246 = stack[-3];
    v0246 = (Lisp_Object)zerop(v0246);
    v0246 = v0246 ? lisp_true : nil;
    env = stack[-7];
    if (v0246 == nil) goto v0071;
    v0246 = qvalue(elt(env, 1)); /* nil */
    goto v0030;

v0030:
    if (v0246 == nil) goto v0127;
    stack[0] = elt(env, 9); /* plus */
    v0247 = stack[-5];
    v0246 = elt(env, 2); /* histry_ */
    stack[-1] = get(v0247, v0246);
    env = stack[-7];
    v0247 = elt(env, 10); /* minus */
    v0246 = stack[-3];
    v0246 = list2(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    v0246 = list3(stack[0], stack[-1], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    fn = elt(env, 15); /* reval */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    stack[0] = v0246;
    v0246 = stack[0];
    v0246 = Lconsp(nil, v0246);
    env = stack[-7];
    if (v0246 == nil) goto v0251;
    v0246 = stack[0];
    v0247 = qcar(v0246);
    v0246 = elt(env, 11); /* quotient */
    if (!(v0247 == v0246)) goto v0251;
    v0246 = stack[0];
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    stack[0] = v0246;
    goto v0251;

v0251:
    v0246 = stack[0];
    v0246 = (Lisp_Object)zerop(v0246);
    v0246 = v0246 ? lisp_true : nil;
    env = stack[-7];
    if (!(v0246 == nil)) goto v0127;
    v0248 = stack[0];
    v0247 = stack[-4];
    v0246 = stack[-4];
    if (v0246 == nil) goto v0081;
    v0246 = qvalue(elt(env, 12)); /* t */
    goto v0252;

v0252:
    fn = elt(env, 18); /* new_idty */
    v0246 = (*qfnn(fn))(qenv(fn), 3, v0248, v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    goto v0127;

v0127:
    v0246 = nil;
    { popv(8); return onevalue(v0246); }

v0081:
    v0246 = qvalue(elt(env, 1)); /* nil */
    goto v0252;

v0071:
    v0248 = stack[-5];
    v0247 = stack[-5];
    v0246 = elt(env, 2); /* histry_ */
    v0246 = get(v0247, v0246);
    env = stack[-7];
    v0246 = Lneq(nil, v0248, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-7];
    goto v0030;
/* error exit handlers */
v0250:
    popv(8);
    return nil;
}



/* Code for mml2ir */

static Lisp_Object MS_CDECL CC_mml2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131, v0172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mml2ir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mml2ir");
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
    v0131 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0131;
    v0131 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0131; /* mmlatts */
    v0172 = elt(env, 3); /* !! */
    v0131 = (Lisp_Object)513; /* 32 */
    v0131 = list2(v0172, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    v0131 = Lcompress(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0131; /* space */
    v0131 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v0131; /* count */
    v0131 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    qvalue(elt(env, 6)) = v0131; /* ch */
    v0131 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v0131; /* temp2 */
    fn = elt(env, 13); /* lex */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    v0172 = qvalue(elt(env, 8)); /* char */
    v0131 = elt(env, 9); /* (m a t h) */
    if (equal(v0172, v0131)) goto v0057;
    v0172 = elt(env, 10); /* "<math>" */
    v0131 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 14); /* errorml */
    v0131 = (*qfn2(fn))(qenv(fn), v0172, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    goto v0198;

v0198:
    fn = elt(env, 13); /* lex */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    v0172 = qvalue(elt(env, 8)); /* char */
    v0131 = elt(env, 11); /* (!/ m a t h) */
    if (equal(v0172, v0131)) goto v0183;
    v0172 = elt(env, 12); /* "</math>" */
    v0131 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 14); /* errorml */
    v0131 = (*qfn2(fn))(qenv(fn), v0172, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0183:
    v0131 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0057:
    fn = elt(env, 15); /* mathml */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    stack[0] = v0131;
    goto v0198;
/* error exit handlers */
v0047:
    popv(2);
    return nil;
}



/* Code for dipprod */

static Lisp_Object CC_dipprod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipprod");
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
    v0101 = stack[-1];
    fn = elt(env, 1); /* diplength */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    v0101 = stack[0];
    fn = elt(env, 1); /* diplength */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    v0101 = (Lisp_Object)lesseq2(stack[-2], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    v0101 = v0101 ? lisp_true : nil;
    env = stack[-3];
    if (v0101 == nil) goto v0060;
    v0109 = stack[-1];
    v0101 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* dipprodin */
        return (*qfn2(fn))(qenv(fn), v0109, v0101);
    }

v0060:
    v0109 = stack[0];
    v0101 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* dipprodin */
        return (*qfn2(fn))(qenv(fn), v0109, v0101);
    }
/* error exit handlers */
v0180:
    popv(4);
    return nil;
}



/* Code for aconc */

static Lisp_Object CC_aconc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0099;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aconc");
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
    v0215 = v0001;
    v0099 = v0000;
/* end of prologue */
    stack[0] = v0099;
    v0215 = ncons(v0215);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    {
        Lisp_Object v0169 = stack[0];
        popv(1);
        return Lnconc(nil, v0169, v0215);
    }
/* error exit handlers */
v0171:
    popv(1);
    return nil;
}



/* Code for def_edge */

static Lisp_Object CC_def_edge(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0166, v0083, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for def_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0101 = v0001;
    v0052 = v0000;
/* end of prologue */
    v0052 = qcdr(v0052);
    v0052 = qcar(v0052);
    v0083 = v0052;
    v0052 = v0083;
    v0166 = qcar(v0052);
    v0052 = v0101;
    v0052 = Lassoc(nil, v0166, v0052);
    if (v0052 == nil) goto v0106;
    v0052 = v0083;
    v0052 = qcdr(v0052);
    v0166 = v0101;
    v0052 = Lassoc(nil, v0052, v0166);
    return onevalue(v0052);

v0106:
    v0052 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0052);
}



/* Code for repeats */

static Lisp_Object CC_repeats(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0222, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repeats");
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
    v0093 = nil;
    goto v0120;

v0120:
    v0180 = stack[0];
    if (v0180 == nil) goto v0105;
    v0180 = stack[0];
    v0222 = qcar(v0180);
    v0180 = stack[0];
    v0180 = qcdr(v0180);
    v0180 = Lmember(nil, v0222, v0180);
    if (v0180 == nil) goto v0109;
    v0180 = stack[0];
    v0180 = qcar(v0180);
    v0222 = v0093;
    v0180 = cons(v0180, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-1];
    v0093 = v0180;
    v0180 = stack[0];
    v0180 = qcdr(v0180);
    stack[0] = v0180;
    goto v0120;

v0109:
    v0180 = stack[0];
    v0180 = qcdr(v0180);
    stack[0] = v0180;
    goto v0120;

v0105:
    v0180 = v0093;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0180);
    }
/* error exit handlers */
v0183:
    popv(2);
    return nil;
}



/* Code for st_sorttree */

static Lisp_Object MS_CDECL CC_st_sorttree(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0053, v0054;
    Lisp_Object fn;
    Lisp_Object v0085, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0085 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for st_sorttree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0085,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0085);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0169 = v0085;
    v0053 = v0001;
    v0054 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* st_sorttree1 */
    v0169 = (*qfnn(fn))(qenv(fn), 3, v0054, v0053, v0169);
    errexit();
    v0169 = qcdr(v0169);
    return onevalue(v0169);
}



/* Code for decprec2internal */

static Lisp_Object CC_decprec2internal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for decprec2internal");
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
    v0054 = v0000;
/* end of prologue */
    v0184 = v0054;
    v0054 = qvalue(elt(env, 1)); /* log2of10 */
    v0054 = times2(v0184, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[0];
    fn = elt(env, 2); /* ceiling */
    v0184 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0054 = (Lisp_Object)49; /* 3 */
    popv(1);
    return plus2(v0184, v0054);
/* error exit handlers */
v0198:
    popv(1);
    return nil;
}



/* Code for xremainder!-mod!-p */

static Lisp_Object MS_CDECL CC_xremainderKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0257, v0155, v0156;
    Lisp_Object fn;
    Lisp_Object v0085, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremainder-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0085 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xremainder-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0085,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0085);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0085;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0258:
    v0257 = stack[-2];
    if (!consp(v0257)) goto v0167;
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = (consp(v0257) ? nil : lisp_true);
    goto v0099;

v0099:
    if (v0257 == nil) goto v0140;
    v0257 = qvalue(elt(env, 1)); /* t */
    goto v0106;

v0106:
    if (!(v0257 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    fn = elt(env, 2); /* minus!-mod!-p */
    v0155 = (*qfn1(fn))(qenv(fn), v0257);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-4];
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    fn = elt(env, 3); /* quotient!-mod!-p */
    v0257 = (*qfn2(fn))(qenv(fn), v0155, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-4];
    stack[-3] = v0257;
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0155 = qcdr(v0257);
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    v0257 = (Lisp_Object)(int32_t)((int32_t)v0155 - (int32_t)v0257 + TAG_FIXNUM);
    v0156 = v0257;
    v0155 = v0156;
    v0257 = (Lisp_Object)1; /* 0 */
    if (v0155 == v0257) goto v0195;
    v0257 = stack[-2];
    stack[-2] = qcdr(v0257);
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0155 = v0156;
    fn = elt(env, 4); /* mksp */
    v0155 = (*qfn2(fn))(qenv(fn), v0257, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-4];
    v0257 = stack[-3];
    v0155 = cons(v0155, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-4];
    v0257 = stack[-1];
    v0257 = qcdr(v0257);
    fn = elt(env, 5); /* times!-term!-mod!-p */
    v0257 = (*qfn2(fn))(qenv(fn), v0155, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-4];
    fn = elt(env, 6); /* plus!-mod!-p */
    v0257 = (*qfn2(fn))(qenv(fn), stack[-2], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-4];
    stack[-2] = v0257;
    goto v0259;

v0259:
    v0156 = stack[-2];
    v0155 = stack[-1];
    v0257 = stack[0];
    stack[-2] = v0156;
    stack[-1] = v0155;
    stack[0] = v0257;
    goto v0258;

v0195:
    v0257 = stack[-2];
    stack[-2] = qcdr(v0257);
    v0257 = stack[-1];
    v0155 = qcdr(v0257);
    v0257 = stack[-3];
    fn = elt(env, 7); /* multiply!-by!-constant!-mod!-p */
    v0257 = (*qfn2(fn))(qenv(fn), v0155, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-4];
    fn = elt(env, 6); /* plus!-mod!-p */
    v0257 = (*qfn2(fn))(qenv(fn), stack[-2], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-4];
    stack[-2] = v0257;
    goto v0259;

v0140:
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0155 = qcar(v0257);
    v0257 = stack[0];
    if (equal(v0155, v0257)) goto v0091;
    v0257 = qvalue(elt(env, 1)); /* t */
    goto v0106;

v0091:
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0155 = qcdr(v0257);
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    v0257 = ((intptr_t)v0155 < (intptr_t)v0257) ? lisp_true : nil;
    goto v0106;

v0167:
    v0257 = qvalue(elt(env, 1)); /* t */
    goto v0099;
/* error exit handlers */
v0205:
    popv(5);
    return nil;
}



/* Code for begin11 */

static Lisp_Object CC_begin11(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0299, v0300;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for begin11");
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
    stack[-5] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-3] = nil;
    stack[-2] = qvalue(elt(env, 2)); /* newrule!* */
    qvalue(elt(env, 2)) = nil; /* newrule!* */
    v0300 = qvalue(elt(env, 3)); /* cursym!* */
    v0299 = elt(env, 4); /* end */
    if (v0300 == v0299) goto v0107;
    v0299 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v0299 == nil) goto v0301;
    v0299 = stack[-4];
    v0300 = v0299;
    goto v0180;

v0180:
    v0299 = elt(env, 11); /* retry */
    if (!consp(v0300)) goto v0106;
    v0300 = qcar(v0300);
    if (!(v0300 == v0299)) goto v0106;
    v0299 = qvalue(elt(env, 12)); /* programl!* */
    if (v0299 == nil) goto v0086;
    v0299 = qvalue(elt(env, 12)); /* programl!* */
    stack[-4] = v0299;
    goto v0106;

v0106:
    v0299 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (!(v0299 == nil)) goto v0302;
    v0299 = stack[-4];
    v0299 = qcar(v0299);
    stack[-3] = v0299;
    v0299 = stack[-4];
    v0299 = qcdr(v0299);
    v0299 = qcar(v0299);
    stack[-4] = v0299;
    goto v0302;

v0302:
    v0299 = stack[-4];
    qvalue(elt(env, 14)) = v0299; /* program!* */
    fn = elt(env, 48); /* eofcheck */
    v0299 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    if (v0299 == nil) goto v0182;
    v0299 = elt(env, 15); /* c */
    goto v0100;

v0100:
    qvalue(elt(env, 2)) = stack[-2]; /* newrule!* */
    qvalue(elt(env, 1)) = stack[-5]; /* errmsg!* */
    { popv(7); return onevalue(v0299); }

v0182:
    v0299 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 16)) = v0299; /* eof!* */
    v0300 = stack[-4];
    v0299 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v0299 == nil) goto v0063;
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0194;

v0194:
    fn = elt(env, 49); /* add2inputbuf */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = stack[-4];
    if (!consp(v0299)) goto v0211;
    v0299 = stack[-4];
    v0300 = qcar(v0299);
    v0299 = elt(env, 17); /* (bye quit) */
    v0299 = Lmemq(nil, v0300, v0299);
    goto v0042;

v0042:
    if (v0299 == nil) goto v0220;
    v0299 = elt(env, 18); /* bye */
    fn = elt(env, 50); /* getd */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    if (v0299 == nil) goto v0304;
    v0299 = stack[-4];
    fn = elt(env, 51); /* lispeval */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v0299; /* !*nosave!* */
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0304:
    v0299 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 19)) = v0299; /* !*byeflag!* */
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0220:
    v0299 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v0299 == nil) goto v0040;
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0305;

v0305:
    if (v0299 == nil) goto v0217;
    v0299 = elt(env, 21); /* cedit */
    fn = elt(env, 50); /* getd */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    if (v0299 == nil) goto v0155;
    fn = elt(env, 52); /* terminalp */
    v0299 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    if (v0299 == nil) goto v0155;
    v0299 = stack[-4];
    v0299 = qcdr(v0299);
    fn = elt(env, 21); /* cedit */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    goto v0259;

v0259:
    v0299 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v0299; /* !*nosave!* */
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0155:
    v0299 = elt(env, 22); /* "ED not supported" */
    fn = elt(env, 53); /* lprim */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    goto v0259;

v0217:
    v0299 = qvalue(elt(env, 23)); /* !*defn */
    if (v0299 == nil) goto v0195;
    v0299 = qvalue(elt(env, 24)); /* erfg!* */
    if (v0299 == nil) goto v0153;
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0153:
    v0300 = qvalue(elt(env, 25)); /* key!* */
    v0299 = elt(env, 26); /* ignore */
    v0299 = Lflagp(nil, v0300, v0299);
    env = stack[-6];
    if (v0299 == nil) goto v0306;
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0203;

v0203:
    if (v0299 == nil) goto v0195;
    v0299 = stack[-4];
    if (v0299 == nil) goto v0307;
    v0299 = stack[-4];
    fn = elt(env, 54); /* dfprint */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    goto v0307;

v0307:
    v0300 = qvalue(elt(env, 25)); /* key!* */
    v0299 = elt(env, 28); /* eval */
    v0299 = Lflagp(nil, v0300, v0299);
    env = stack[-6];
    if (!(v0299 == nil)) goto v0195;
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0195:
    v0299 = qvalue(elt(env, 29)); /* !*output */
    if (v0299 == nil) goto v0028;
    v0299 = qvalue(elt(env, 30)); /* ifl!* */
    if (v0299 == nil) goto v0028;
    v0299 = qvalue(elt(env, 31)); /* !*echo */
    if (v0299 == nil) goto v0028;
    v0299 = qvalue(elt(env, 32)); /* !*lessspace */
    if (!(v0299 == nil)) goto v0028;
    v0299 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    goto v0028;

v0028:
    v0299 = qvalue(elt(env, 33)); /* ulimit!* */
    v0299 = integerp(v0299);
    if (v0299 == nil) goto v0025;
    v0300 = qvalue(elt(env, 33)); /* ulimit!* */
    v0299 = stack[-4];
    fn = elt(env, 55); /* errorset_with_timeout */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[0] = v0299;
    v0299 = stack[0];
    if (!consp(v0299)) goto v0145;
    v0299 = stack[0];
    v0299 = qcar(v0299);
    stack[0] = v0299;
    goto v0145;

v0145:
    v0299 = stack[0];
    fn = elt(env, 56); /* errorp */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    if (!(v0299 == nil)) goto v0308;
    v0299 = qvalue(elt(env, 24)); /* erfg!* */
    if (!(v0299 == nil)) goto v0308;
    v0299 = qvalue(elt(env, 23)); /* !*defn */
    if (v0299 == nil) goto v0309;
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0309:
    v0299 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v0299 == nil) goto v0310;
    v0299 = stack[0];
    v0299 = qcar(v0299);
    stack[0] = v0299;
    v0299 = stack[0];
    if (!(v0299 == nil)) goto v0311;
    v0300 = qvalue(elt(env, 9)); /* nil */
    v0299 = elt(env, 36); /* noval */
    fn = elt(env, 57); /* mkobject */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[0] = v0299;
    goto v0311;

v0311:
    v0299 = stack[0];
    fn = elt(env, 58); /* type */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[-3] = v0299;
    v0299 = stack[0];
    fn = elt(env, 59); /* value */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[0] = v0299;
    goto v0312;

v0312:
    v0299 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v0299 == nil) goto v0313;
    v0299 = stack[0];
    v0300 = v0299;
    goto v0314;

v0314:
    v0299 = stack[-3];
    fn = elt(env, 60); /* add2resultbuf */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = qvalue(elt(env, 29)); /* !*output */
    if (v0299 == nil) goto v0315;
    v0300 = qvalue(elt(env, 37)); /* semic!* */
    v0299 = elt(env, 38); /* !$ */
    if (v0300 == v0299) goto v0316;
    v0299 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v0299 == nil) goto v0002;
    v0299 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0300 = stack[-3];
    v0299 = elt(env, 36); /* noval */
    if (v0300 == v0299) goto v0316;
    v0299 = qvalue(elt(env, 39)); /* !*debug */
    if (v0299 == nil) goto v0317;
    v0299 = elt(env, 40); /* "Value:" */
    fn = elt(env, 61); /* prin2t */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    goto v0317;

v0317:
    stack[-1] = elt(env, 41); /* print */
    v0300 = stack[-3];
    v0299 = stack[0];
    v0299 = list2(v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = ncons(v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    fn = elt(env, 62); /* rapply1 */
    v0299 = (*qfn2(fn))(qenv(fn), stack[-1], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    goto v0316;

v0316:
    v0299 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v0299 == nil) goto v0318;
    v0300 = qvalue(elt(env, 42)); /* !*mode */
    v0299 = elt(env, 36); /* noval */
    if (v0300 == v0299) goto v0319;
    v0299 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = elt(env, 47); /* "of type: " */
    v0299 = Lprinc(nil, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = stack[-3];
    v0299 = Lprint(nil, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    goto v0319;

v0319:
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0318:
    v0299 = stack[0];
    fn = elt(env, 56); /* errorp */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    if (v0299 == nil) goto v0320;
    v0299 = elt(env, 46); /* err3 */
    goto v0100;

v0320:
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0002:
    v0300 = stack[-3];
    v0299 = elt(env, 35); /* symbolic */
    if (v0300 == v0299) goto v0321;
    v0299 = stack[0];
    v0299 = qcar(v0299);
    if (v0299 == nil) goto v0316;
    stack[-1] = elt(env, 43); /* assgnpri */
    v0299 = stack[0];
    v0299 = qcar(v0299);
    stack[0] = Lmkquote(nil, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = stack[-4];
    if (v0299 == nil) goto v0322;
    v0300 = elt(env, 44); /* list */
    v0299 = stack[-4];
    v0299 = cons(v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[-4] = v0299;
    goto v0323;

v0323:
    v0299 = elt(env, 45); /* only */
    v0299 = Lmkquote(nil, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0300 = list4(stack[-1], stack[0], stack[-4], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 63); /* errorset!* */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[0] = v0299;
    goto v0316;

v0322:
    v0299 = qvalue(elt(env, 9)); /* nil */
    stack[-4] = v0299;
    goto v0323;

v0321:
    v0299 = stack[0];
    v0299 = qcar(v0299);
    if (v0299 == nil) goto v0324;
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0325;

v0325:
    if (!(v0299 == nil)) goto v0316;
    v0299 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[-1] = elt(env, 41); /* print */
    v0299 = stack[0];
    v0299 = qcar(v0299);
    v0299 = Lmkquote(nil, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0300 = list2(stack[-1], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 63); /* errorset!* */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[0] = v0299;
    goto v0316;

v0324:
    v0300 = qvalue(elt(env, 42)); /* !*mode */
    v0299 = elt(env, 35); /* symbolic */
    v0299 = (v0300 == v0299 ? lisp_true : nil);
    v0299 = (v0299 == nil ? lisp_true : nil);
    goto v0325;

v0315:
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0313:
    v0299 = stack[0];
    v0299 = qcar(v0299);
    v0300 = v0299;
    goto v0314;

v0310:
    v0300 = stack[-3];
    v0299 = elt(env, 35); /* symbolic */
    if (v0300 == v0299) goto v0312;
    v0299 = stack[-4];
    fn = elt(env, 64); /* getsetvars */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[-4] = v0299;
    goto v0312;

v0308:
    v0300 = stack[-3];
    v0299 = stack[-4];
    v0299 = list2(v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    qvalue(elt(env, 12)) = v0299; /* programl!* */
    v0299 = elt(env, 34); /* err2 */
    goto v0100;

v0025:
    v0300 = stack[-4];
    v0299 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 63); /* errorset!* */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    stack[0] = v0299;
    goto v0145;

v0306:
    v0300 = stack[-4];
    v0299 = elt(env, 27); /* quote */
    v0299 = Leqcar(nil, v0300, v0299);
    env = stack[-6];
    v0299 = (v0299 == nil ? lisp_true : nil);
    goto v0203;

v0040:
    v0300 = stack[-4];
    v0299 = elt(env, 20); /* ed */
    v0299 = Leqcar(nil, v0300, v0299);
    env = stack[-6];
    goto v0305;

v0211:
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0042;

v0063:
    v0299 = stack[-3];
    goto v0194;

v0086:
    v0299 = elt(env, 13); /* "No previous expression" */
    fn = elt(env, 53); /* lprim */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0301:
    v0299 = stack[-4];
    v0299 = qcdr(v0299);
    v0299 = qcar(v0299);
    v0300 = v0299;
    goto v0180;

v0107:
    fn = elt(env, 52); /* terminalp */
    v0299 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    if (v0299 == nil) goto v0140;
    v0299 = qvalue(elt(env, 5)); /* !*lisp_hook */
    if (!(v0299 == nil)) goto v0140;
    v0299 = elt(env, 6); /* !*semicol!* */
    qvalue(elt(env, 3)) = v0299; /* cursym!* */
    v0299 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v0299; /* !*nosave!* */
    v0299 = qvalue(elt(env, 9)); /* nil */
    goto v0100;

v0140:
    v0299 = elt(env, 4); /* end */
    fn = elt(env, 65); /* comm1 */
    v0299 = (*qfn1(fn))(qenv(fn), v0299);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-6];
    v0299 = elt(env, 4); /* end */
    goto v0100;
/* error exit handlers */
v0303:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; /* newrule!* */
    qvalue(elt(env, 1)) = stack[-5]; /* errmsg!* */
    popv(7);
    return nil;
}



/* Code for gcref_mkgraph!-tgf */

static Lisp_Object CC_gcref_mkgraphKtgf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcref_mkgraph-tgf");
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
    v0049 = stack[0];
    stack[-1] = v0049;
    goto v0120;

v0120:
    v0049 = stack[-1];
    if (v0049 == nil) goto v0121;
    v0049 = stack[-1];
    v0049 = qcar(v0049);
    fn = elt(env, 4); /* gcref_mknode!-tgf */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0049 = stack[-1];
    v0049 = qcdr(v0049);
    stack[-1] = v0049;
    goto v0120;

v0121:
    v0049 = elt(env, 2); /* "#" */
    fn = elt(env, 5); /* prin2t */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0049 = stack[0];
    stack[-1] = v0049;
    goto v0094;

v0094:
    v0049 = stack[-1];
    if (v0049 == nil) goto v0059;
    v0049 = stack[-1];
    v0049 = qcar(v0049);
    stack[0] = v0049;
    v0192 = v0049;
    v0049 = elt(env, 3); /* calls */
    v0049 = get(v0192, v0049);
    env = stack[-2];
    fn = elt(env, 6); /* gcref_select */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    fn = elt(env, 7); /* gcref_mkedges!-tgf */
    v0049 = (*qfn2(fn))(qenv(fn), stack[0], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0049 = stack[-1];
    v0049 = qcdr(v0049);
    stack[-1] = v0049;
    goto v0094;

v0059:
    v0049 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0049); }
/* error exit handlers */
v0013:
    popv(3);
    return nil;
}



/* Code for ofsf_smmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smmkatl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133, v0134, v0132, v0050;
    Lisp_Object fn;
    Lisp_Object v0090, v0085, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smmkatl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0085 = va_arg(aa, Lisp_Object);
    v0090 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0090,v0085,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0085,v0090);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0133 = v0090;
    stack[0] = v0085;
    v0134 = v0001;
    v0050 = v0000;
/* end of prologue */
    v0132 = qvalue(elt(env, 1)); /* !*rlsippatl */
    if (v0132 == nil) goto v0113;
    stack[-1] = v0050;
    v0132 = v0134;
    v0134 = stack[0];
    fn = elt(env, 2); /* ofsf_smmkatl1 */
    v0134 = (*qfnn(fn))(qenv(fn), 4, v0050, v0132, v0134, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-2];
    v0133 = stack[0];
    {
        Lisp_Object v0004 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* ofsf_sippatl */
        return (*qfnn(fn))(qenv(fn), 3, v0004, v0134, v0133);
    }

v0113:
    v0132 = v0134;
    v0134 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* ofsf_smmkatl1 */
        return (*qfnn(fn))(qenv(fn), 4, v0050, v0132, v0134, v0133);
    }
/* error exit handlers */
v0164:
    popv(3);
    return nil;
}



/* Code for findremainder */

static Lisp_Object CC_findremainder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0109, v0328;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findremainder");
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
    v0101 = v0001;
    v0109 = v0000;
/* end of prologue */
    stack[0] = v0101;
    goto v0096;

v0096:
    v0101 = stack[0];
    if (v0101 == nil) { popv(2); return onevalue(v0109); }
    v0101 = stack[0];
    v0101 = qcar(v0101);
    v0328 = v0109;
    v0109 = v0101;
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 2); /* wupseudodivide */
    v0101 = (*qfnn(fn))(qenv(fn), 3, v0328, v0109, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-1];
    v0101 = qcdr(v0101);
    v0109 = v0101;
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0096;
/* error exit handlers */
v0113:
    popv(2);
    return nil;
}



/* Code for qqe_arg!-check!-q */

static Lisp_Object CC_qqe_argKcheckKq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check-q");
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
    v0132 = stack[0];
    fn = elt(env, 3); /* qqe_id!-nyt!-branchq */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    if (v0132 == nil) goto v0096;
    v0132 = stack[0];
    if (!consp(v0132)) goto v0171;
    v0132 = qvalue(elt(env, 1)); /* nil */
    goto v0167;

v0167:
    if (v0132 == nil) goto v0215;
    v0132 = stack[0];
    fn = elt(env, 4); /* qqe_btidp */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    if (v0132 == nil) goto v0051;
    v0132 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0132); }

v0051:
    v0132 = stack[0];
    fn = elt(env, 5); /* qqe_nytidp */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    if (v0132 == nil) goto v0222;
    v0132 = stack[0];
    fn = elt(env, 6); /* qqe_qtid */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0132 = stack[0];
    fn = elt(env, 7); /* qqe_add2rollbackids */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0132 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0132); }

v0222:
    v0132 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0132); }

v0215:
    v0132 = stack[0];
    if (is_number(v0132)) goto v0120;
    v0132 = stack[0];
    fn = elt(env, 8); /* qqe_arg!-check */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0132 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0132); }

v0120:
    v0132 = nil;
    { popv(2); return onevalue(v0132); }

v0171:
    v0132 = stack[0];
    v0132 = (is_number(v0132) ? lisp_true : nil);
    v0132 = (v0132 == nil ? lisp_true : nil);
    goto v0167;

v0096:
    v0132 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0132); }
/* error exit handlers */
v0049:
    popv(2);
    return nil;
}



/* Code for aex_fromrp */

static Lisp_Object CC_aex_fromrp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_fromrp");
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
    v0111 = v0000;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v0111;
    fn = elt(env, 3); /* ctx_new */
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0135 = qvalue(elt(env, 2)); /* t */
    v0111 = qvalue(elt(env, 2)); /* t */
    v0111 = list2(v0135, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    {
        Lisp_Object v0059 = stack[-2];
        Lisp_Object v0140 = stack[-1];
        Lisp_Object v0188 = stack[0];
        popv(4);
        return list3star(v0059, v0140, v0188, v0111);
    }
/* error exit handlers */
v0060:
    popv(4);
    return nil;
}



/* Code for om2ir */

static Lisp_Object MS_CDECL CC_om2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2ir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for om2ir");
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
    v0047 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0047;
    v0047 = elt(env, 2); /* (safe_atts char ch atts count temp space temp2) 
*/
    fn = elt(env, 13); /* fluid */
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0048 = elt(env, 3); /* !! */
    v0047 = (Lisp_Object)513; /* 32 */
    v0047 = list2(v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0047 = Lcompress(nil, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0047; /* space */
    v0047 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v0047; /* count */
    v0047 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    qvalue(elt(env, 6)) = v0047; /* ch */
    v0047 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v0047; /* temp2 */
    fn = elt(env, 14); /* lex */
    v0047 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0048 = qvalue(elt(env, 8)); /* char */
    v0047 = elt(env, 9); /* (o m o b j) */
    if (equal(v0048, v0047)) goto v0110;
    v0048 = elt(env, 10); /* "<omobj>" */
    v0047 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 15); /* errorml */
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    goto v0057;

v0057:
    fn = elt(env, 14); /* lex */
    v0047 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0048 = qvalue(elt(env, 8)); /* char */
    v0047 = elt(env, 11); /* (!/ o m o b j) */
    if (equal(v0048, v0047)) goto v0326;
    v0048 = elt(env, 12); /* "</omobj>" */
    v0047 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 15); /* errorml */
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0326:
    v0047 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0110:
    fn = elt(env, 14); /* lex */
    v0047 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    fn = elt(env, 16); /* omobj */
    v0047 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    stack[0] = v0047;
    goto v0057;
/* error exit handlers */
v0062:
    popv(2);
    return nil;
}



/* Code for subs4q */

static Lisp_Object CC_subs4q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0193, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs4q");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0000;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v0041 = elt(env, 1); /* slash */
    if (!symbolp(v0041)) v0041 = nil;
    else { v0041 = qfastgets(v0041);
           if (v0041 != nil) { v0041 = elt(v0041, 9); /* opmtch */
#ifdef RECORD_GET
             if (v0041 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0041 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0041 == SPID_NOPROP) v0041 = nil; }}
#endif
    stack[-6] = v0041;
    if (v0041 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0041 = stack[-5];
    fn = elt(env, 7); /* prepsq */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-4] = v0041;
    v0193 = elt(env, 1); /* slash */
    v0041 = elt(env, 2); /* opmtch */
    v0041 = Lremprop(nil, v0193, v0041);
    env = stack[-7];
    v0031 = elt(env, 3); /* slash!* */
    v0193 = elt(env, 2); /* opmtch */
    v0041 = stack[-6];
    v0041 = Lputprop(nil, 3, v0031, v0193, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    goto v0112;

v0112:
    v0041 = stack[-4];
    if (v0041 == nil) goto v0328;
    v0193 = stack[-4];
    stack[-3] = v0193;
    v0041 = elt(env, 4); /* quotient */
    if (!consp(v0193)) goto v0328;
    v0193 = qcar(v0193);
    if (!(v0193 == v0041)) goto v0328;
    v0193 = elt(env, 3); /* slash!* */
    v0041 = stack[-4];
    v0041 = qcdr(v0041);
    v0041 = cons(v0193, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 2); /* opmtch */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    if (!(v0041 == nil)) goto v0164;
    v0193 = elt(env, 6); /* minus */
    v0041 = stack[-4];
    v0041 = qcdr(v0041);
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    v0041 = Lsmemq(nil, v0193, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    if (v0041 == nil) goto v0089;
    stack[-1] = elt(env, 3); /* slash!* */
    v0193 = elt(env, 6); /* minus */
    v0041 = stack[-4];
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    v0041 = list2(v0193, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 8); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    v0193 = elt(env, 6); /* minus */
    v0041 = stack[-4];
    v0041 = qcdr(v0041);
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    v0041 = list2(v0193, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 8); /* reval */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    v0041 = list3(stack[-1], stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 2); /* opmtch */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    goto v0164;

v0164:
    stack[-4] = v0041;
    v0041 = stack[-2];
    if (!(v0041 == nil)) goto v0211;
    v0041 = stack[-4];
    goto v0211;

v0211:
    stack[-2] = v0041;
    goto v0112;

v0089:
    v0041 = qvalue(elt(env, 5)); /* nil */
    goto v0164;

v0328:
    v0041 = stack[-2];
    if (v0041 == nil) goto v0139;
    v0041 = stack[-3];
    fn = elt(env, 9); /* simp!* */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    goto v0068;

v0068:
    stack[-5] = v0041;
    v0031 = elt(env, 1); /* slash */
    v0193 = elt(env, 2); /* opmtch */
    v0041 = stack[-6];
    v0041 = Lputprop(nil, 3, v0031, v0193, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v0139:
    v0041 = stack[-5];
    goto v0068;
/* error exit handlers */
v0259:
    popv(8);
    return nil;
}



/* Code for nextcomb */

static Lisp_Object CC_nextcomb(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0193, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nextcomb");
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
    stack[0] = v0001;
    v0031 = v0000;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v0193 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0193; /* i */
    v0193 = v0031;
    v0193 = qcar(v0193);
    stack[-3] = v0193;
    v0193 = v0031;
    v0193 = qcdr(v0193);
    stack[-1] = v0193;
    v0031 = stack[0];
    v0193 = (Lisp_Object)1; /* 0 */
    if (v0031 == v0193) goto v0169;
    v0193 = stack[-3];
    v0031 = Llength(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0193 = stack[0];
    v0031 = difference2(v0031, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0031; /* i */
    v0193 = (Lisp_Object)1; /* 0 */
    v0193 = (Lisp_Object)lessp2(v0031, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    v0193 = v0193 ? lisp_true : nil;
    env = stack[-4];
    if (v0193 == nil) goto v0301;
    v0193 = qvalue(elt(env, 2)); /* nil */
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0105;

v0105:
    qvalue(elt(env, 1)) = stack[-2]; /* i */
    { popv(5); return onevalue(v0193); }

v0301:
    v0031 = qvalue(elt(env, 1)); /* i */
    v0193 = (Lisp_Object)1; /* 0 */
    if (v0031 == v0193) goto v0326;
    v0193 = stack[-1];
    if (v0193 == nil) goto v0220;
    v0193 = stack[0];
    v0193 = sub1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0193 = CC_nextcomb(env, stack[-1], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0031 = stack[-3];
    stack[-1] = qcar(v0031);
    v0031 = v0193;
    stack[0] = qcar(v0031);
    v0031 = v0193;
    v0031 = qcdr(v0031);
    if (v0031 == nil) goto v0097;
    v0031 = stack[-3];
    v0193 = qcdr(v0193);
    v0193 = cons(v0031, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0129;

v0129:
    v0193 = acons(stack[-1], stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0105;

v0097:
    v0193 = stack[-3];
    v0193 = qcdr(v0193);
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0129;

v0220:
    v0193 = stack[-3];
    v0193 = qcdr(v0193);
    fn = elt(env, 3); /* initcomb */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0193 = stack[0];
    v0193 = sub1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0193 = CC_nextcomb(env, stack[-1], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0031 = stack[-3];
    stack[-1] = qcar(v0031);
    v0031 = v0193;
    stack[0] = qcar(v0031);
    v0031 = v0193;
    v0031 = qcdr(v0031);
    if (v0031 == nil) goto v0141;
    v0031 = stack[-3];
    v0193 = qcdr(v0193);
    v0193 = cons(v0031, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0116;

v0116:
    v0193 = acons(stack[-1], stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0105;

v0141:
    v0193 = stack[-3];
    v0193 = qcdr(v0193);
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0116;

v0326:
    v0193 = stack[-3];
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0105;

v0169:
    v0193 = qvalue(elt(env, 2)); /* nil */
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0105;
/* error exit handlers */
v0189:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-2]; /* i */
    popv(5);
    return nil;
}



/* Code for groebsavelterm */

static Lisp_Object CC_groebsavelterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebsavelterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0059 = v0000;
/* end of prologue */
    v0060 = qvalue(elt(env, 1)); /* !*groelterms */
    if (v0060 == nil) goto v0120;
    v0060 = v0059;
    if (v0060 == nil) goto v0108;
    v0060 = v0059;
    v0060 = qcdr(v0060);
    v0060 = qcdr(v0060);
    v0060 = qcdr(v0060);
    v0060 = qcar(v0060);
    v0060 = (v0060 == nil ? lisp_true : nil);
    goto v0107;

v0107:
    if (!(v0060 == nil)) goto v0120;
    v0060 = v0059;
    v0060 = qcdr(v0060);
    v0060 = qcdr(v0060);
    v0060 = qcar(v0060);
    {
        fn = elt(env, 3); /* groebsaveltermbc */
        return (*qfn1(fn))(qenv(fn), v0060);
    }

v0120:
    v0060 = nil;
    return onevalue(v0060);

v0108:
    v0060 = qvalue(elt(env, 2)); /* t */
    goto v0107;
}



/* Code for physopordchk!* */

static Lisp_Object CC_physopordchkH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopordchk*");
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
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0258:
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    stack[-4] = v0031;
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    v0031 = stack[-1];
    if (v0031 == nil) goto v0167;
    v0031 = stack[-4];
    v0204 = ncons(v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-5];
    v0031 = stack[0];
    v0031 = CC_physopordchkH(env, v0204, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-5];
    if (v0031 == nil) goto v0174;
    v0204 = stack[-1];
    v0031 = stack[0];
    stack[-1] = v0204;
    stack[0] = v0031;
    goto v0258;

v0174:
    v0031 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0031); }

v0167:
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    if (v0031 == nil) goto v0060;
    v0031 = stack[0];
    stack[-3] = v0031;
    v0031 = stack[-3];
    if (v0031 == nil) goto v0086;
    v0031 = stack[-3];
    v0031 = qcar(v0031);
    v0204 = stack[-4];
    fn = elt(env, 3); /* ncmpchk */
    v0031 = (*qfn2(fn))(qenv(fn), v0204, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-5];
    v0031 = ncons(v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-5];
    stack[-1] = v0031;
    stack[-2] = v0031;
    goto v0004;

v0004:
    v0031 = stack[-3];
    v0031 = qcdr(v0031);
    stack[-3] = v0031;
    v0031 = stack[-3];
    if (v0031 == nil) goto v0197;
    stack[0] = stack[-1];
    v0031 = stack[-3];
    v0031 = qcar(v0031);
    v0204 = stack[-4];
    fn = elt(env, 3); /* ncmpchk */
    v0031 = (*qfn2(fn))(qenv(fn), v0204, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-5];
    v0031 = ncons(v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-5];
    v0031 = Lrplacd(nil, stack[0], v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-5];
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    goto v0004;

v0197:
    v0031 = stack[-2];
    goto v0216;

v0216:
    v0204 = qvalue(elt(env, 1)); /* nil */
    v0031 = Lmember(nil, v0204, v0031);
    if (v0031 == nil) goto v0118;
    v0031 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0031); }

v0118:
    v0031 = qvalue(elt(env, 2)); /* t */
    { popv(6); return onevalue(v0031); }

v0086:
    v0031 = qvalue(elt(env, 1)); /* nil */
    goto v0216;

v0060:
    v0204 = stack[-4];
    v0031 = stack[0];
    v0031 = qcar(v0031);
    fn = elt(env, 3); /* ncmpchk */
    v0031 = (*qfn2(fn))(qenv(fn), v0204, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-5];
    if (v0031 == nil) goto v0094;
    v0031 = stack[-4];
    fn = elt(env, 4); /* invp */
    v0204 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    v0031 = stack[0];
    v0031 = qcar(v0031);
    v0031 = (equal(v0204, v0031) ? lisp_true : nil);
    v0031 = (v0031 == nil ? lisp_true : nil);
    { popv(6); return onevalue(v0031); }

v0094:
    v0031 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0031); }
/* error exit handlers */
v0176:
    popv(6);
    return nil;
}



/* Code for comblog */

static Lisp_Object CC_comblog(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comblog");
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
    goto v0120;

v0120:
    v0068 = stack[0];
    if (!consp(v0068)) goto v0215;
    v0068 = stack[0];
    v0174 = qcar(v0068);
    v0068 = qvalue(elt(env, 2)); /* domainlist!* */
    v0068 = Lmemq(nil, v0174, v0068);
    goto v0108;

v0108:
    if (v0068 == nil) goto v0222;
    v0174 = stack[-1];
    v0068 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0174, v0068);
    }

v0222:
    v0068 = stack[0];
    v0174 = qcar(v0068);
    v0068 = elt(env, 3); /* plus */
    if (v0174 == v0068) goto v0113;
    v0068 = stack[0];
    v0174 = qcar(v0068);
    v0068 = elt(env, 4); /* times */
    if (v0174 == v0068) goto v0049;
    v0068 = qvalue(elt(env, 6)); /* nil */
    goto v0112;

v0112:
    if (v0068 == nil) goto v0185;
    v0068 = stack[0];
    fn = elt(env, 8); /* simp!* */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    fn = elt(env, 9); /* clogsq */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    fn = elt(env, 10); /* prepsq!* */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    {
        Lisp_Object v0138 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0138, v0068);
    }

v0185:
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0174 = CC_comblog(env, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    v0068 = stack[-1];
    v0068 = cons(v0174, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    stack[-1] = v0068;
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0120;

v0049:
    v0068 = stack[0];
    fn = elt(env, 8); /* simp!* */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    v0068 = qcar(v0068);
    v0174 = v0068;
    v0068 = v0174;
    if (!consp(v0068)) goto v0212;
    v0068 = v0174;
    v0068 = qcar(v0068);
    v0068 = (consp(v0068) ? nil : lisp_true);
    goto v0224;

v0224:
    if (v0068 == nil) goto v0163;
    v0068 = qvalue(elt(env, 6)); /* nil */
    goto v0112;

v0163:
    v0068 = v0174;
    v0068 = qcar(v0068);
    v0068 = qcar(v0068);
    v0174 = qcar(v0068);
    v0068 = elt(env, 5); /* log */
    v0068 = Leqcar(nil, v0174, v0068);
    env = stack[-2];
    goto v0112;

v0212:
    v0068 = qvalue(elt(env, 1)); /* t */
    goto v0224;

v0113:
    v0068 = qvalue(elt(env, 1)); /* t */
    goto v0112;

v0215:
    v0068 = qvalue(elt(env, 1)); /* t */
    goto v0108;
/* error exit handlers */
v0137:
    popv(3);
    return nil;
}



/* Code for assert_error */

static Lisp_Object MS_CDECL CC_assert_error(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0210, v0136, v0137;
    Lisp_Object fn;
    Lisp_Object v0120, v0121, v0090, v0085, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "assert_error");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0085 = va_arg(aa, Lisp_Object);
    v0090 = va_arg(aa, Lisp_Object);
    v0121 = va_arg(aa, Lisp_Object);
    v0120 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_error");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0120,v0121,v0090,v0085,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0085,v0090,v0121,v0120);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0120;
    v0210 = v0121;
    stack[-2] = v0090;
    stack[-3] = v0085;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*lower */
    qvalue(elt(env, 1)) = nil; /* !*lower */
    v0210 = qvalue(elt(env, 2)); /* !*assertstatistics */
    if (v0210 == nil) goto v0092;
    v0136 = stack[-5];
    v0210 = qvalue(elt(env, 3)); /* assertstatistics!* */
    v0210 = Latsoc(nil, v0136, v0210);
    v0210 = qcdr(v0210);
    v0136 = v0210;
    v0210 = v0136;
    v0210 = qcdr(v0210);
    stack[0] = qcdr(v0210);
    v0210 = v0136;
    v0210 = qcdr(v0210);
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
    v0210 = add1(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    fn = elt(env, 9); /* setcar */
    v0210 = (*qfn2(fn))(qenv(fn), stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0092;

v0092:
    v0136 = stack[-2];
    v0210 = (Lisp_Object)1; /* 0 */
    v0210 = Leqn(nil, v0136, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    if (v0210 == nil) goto v0245;
    stack[0] = elt(env, 4); /* "declaration" */
    v0137 = stack[-5];
    v0136 = stack[-4];
    v0210 = stack[-3];
    fn = elt(env, 10); /* assert_format */
    v0137 = (*qfnn(fn))(qenv(fn), 3, v0137, v0136, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0136 = elt(env, 5); /* "violated by result" */
    v0210 = stack[-1];
    v0210 = list4(stack[0], v0137, v0136, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0222;

v0222:
    v0136 = v0210;
    v0210 = qvalue(elt(env, 8)); /* !*assertbreak */
    if (v0210 == nil) goto v0115;
    v0210 = v0136;
    fn = elt(env, 11); /* rederr */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0119;

v0119:
    v0210 = nil;
    qvalue(elt(env, 1)) = stack[-6]; /* !*lower */
    { popv(8); return onevalue(v0210); }

v0115:
    v0210 = v0136;
    fn = elt(env, 12); /* lprim */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0119;

v0245:
    stack[0] = elt(env, 4); /* "declaration" */
    v0137 = stack[-5];
    v0136 = stack[-4];
    v0210 = stack[-3];
    fn = elt(env, 10); /* assert_format */
    stack[-4] = (*qfnn(fn))(qenv(fn), 3, v0137, v0136, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    stack[-3] = elt(env, 6); /* "violated by" */
    v0136 = elt(env, 7); /* arg */
    v0210 = stack[-2];
    fn = elt(env, 13); /* mkid */
    v0136 = (*qfn2(fn))(qenv(fn), v0136, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0210 = stack[-1];
    v0210 = list2(v0136, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0210 = list3star(stack[0], stack[-4], stack[-3], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0222;
/* error exit handlers */
v0161:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*lower */
    popv(8);
    return nil;
}



setup_type const u22_setup[] =
{
    {"s:prinl2",                too_few_2,      CC_sTprinl2,   wrong_no_2},
    {"refprint",                CC_refprint,    too_many_1,    wrong_no_1},
    {"cl_atml1",                CC_cl_atml1,    too_many_1,    wrong_no_1},
    {"triplesetprolongset",     too_few_2,      CC_triplesetprolongset,wrong_no_2},
    {"mkpartitions1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkpartitions1},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"rationalizesq",           CC_rationalizesq,too_many_1,   wrong_no_1},
    {"meq",                     too_few_2,      CC_meq,        wrong_no_2},
    {"gcompatible",             too_few_2,      CC_gcompatible,wrong_no_2},
    {"rd:times",                too_few_2,      CC_rdTtimes,   wrong_no_2},
    {"subla-q",                 too_few_2,      CC_sublaKq,    wrong_no_2},
    {"mo_equal?",               too_few_2,      CC_mo_equalW,  wrong_no_2},
    {"outref",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_outref},
    {"tripleisprolongedby",     too_few_2,      CC_tripleisprolongedby,wrong_no_2},
    {"cl_flip",                 CC_cl_flip,     too_many_1,    wrong_no_1},
    {"simpcv",                  too_few_2,      CC_simpcv,     wrong_no_2},
    {"drop_pde_from_idties",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_drop_pde_from_idties},
    {"mml2ir",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mml2ir},
    {"dipprod",                 too_few_2,      CC_dipprod,    wrong_no_2},
    {"aconc",                   too_few_2,      CC_aconc,      wrong_no_2},
    {"def_edge",                too_few_2,      CC_def_edge,   wrong_no_2},
    {"repeats",                 CC_repeats,     too_many_1,    wrong_no_1},
    {"st_sorttree",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree},
    {"decprec2internal",        CC_decprec2internal,too_many_1,wrong_no_1},
    {"xremainder-mod-p",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremainderKmodKp},
    {"begin11",                 CC_begin11,     too_many_1,    wrong_no_1},
    {"gcref_mkgraph-tgf",       CC_gcref_mkgraphKtgf,too_many_1,wrong_no_1},
    {"ofsf_smmkatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatl},
    {"findremainder",           too_few_2,      CC_findremainder,wrong_no_2},
    {"qqe_arg-check-q",         CC_qqe_argKcheckKq,too_many_1, wrong_no_1},
    {"aex_fromrp",              CC_aex_fromrp,  too_many_1,    wrong_no_1},
    {"om2ir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2ir},
    {"subs4q",                  CC_subs4q,      too_many_1,    wrong_no_1},
    {"nextcomb",                too_few_2,      CC_nextcomb,   wrong_no_2},
    {"groebsavelterm",          CC_groebsavelterm,too_many_1,  wrong_no_1},
    {"physopordchk*",           too_few_2,      CC_physopordchkH,wrong_no_2},
    {"comblog",                 CC_comblog,     too_many_1,    wrong_no_1},
    {"assert_error",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_error},
    {NULL, (one_args *)"u22", (two_args *)"2871 829654 9340571", 0}
};

/* end of generated code */
