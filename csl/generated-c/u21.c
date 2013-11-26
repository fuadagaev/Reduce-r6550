
/* $destdir/u21.c        Machine generated C code */

/* Signature: 00000000 26-Nov-2013 */

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


/* Code for ofsf_vareqnp */

static Lisp_Object CC_ofsf_vareqnp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_vareqnp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0002 = v0001;
    v0003 = v0000;
/* end of prologue */
    v0002 = qcdr(v0002);
    v0002 = qcar(v0002);
    {
        fn = elt(env, 1); /* sfto_varisnump */
        return (*qfn1(fn))(qenv(fn), v0002);
    }
}



/* Code for add_minus */

static Lisp_Object CC_add_minus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add_minus");
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
    v0036 = stack[-1];
    if (!consp(v0036)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0036 = stack[-1];
    v0037 = qcar(v0036);
    v0036 = elt(env, 1); /* !:rd!: */
    if (v0037 == v0036) goto v0038;
    v0036 = qvalue(elt(env, 2)); /* nil */
    goto v0039;

v0039:
    if (!(v0036 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0036 = stack[-1];
    v0037 = qcar(v0036);
    v0036 = elt(env, 1); /* !:rd!: */
    if (v0037 == v0036) goto v0040;
    v0036 = qvalue(elt(env, 2)); /* nil */
    goto v0041;

v0041:
    if (v0036 == nil) goto v0042;
    stack[-2] = elt(env, 3); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    v0036 = Labsval(nil, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0036 = cons(stack[0], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    {
        Lisp_Object v0044 = stack[-2];
        popv(4);
        return list2(v0044, v0036);
    }

v0042:
    v0036 = stack[-1];
    v0037 = qcar(v0036);
    v0036 = elt(env, 3); /* minus */
    if (v0037 == v0036) goto v0045;
    v0036 = qvalue(elt(env, 2)); /* nil */
    goto v0046;

v0046:
    if (!(v0036 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0036 = stack[-1];
    v0037 = qcar(v0036);
    v0036 = elt(env, 3); /* minus */
    if (v0037 == v0036) goto v0047;
    v0036 = qvalue(elt(env, 2)); /* nil */
    goto v0048;

v0048:
    if (v0036 == nil) goto v0049;
    stack[0] = elt(env, 1); /* !:rd!: */
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    v0036 = qcdr(v0036);
    v0036 = Labsval(nil, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    {
        Lisp_Object v0050 = stack[0];
        popv(4);
        return cons(v0050, v0036);
    }

v0049:
    v0036 = stack[-1];
    v0037 = qcar(v0036);
    v0036 = elt(env, 3); /* minus */
    if (v0037 == v0036) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0036 = stack[-1];
    v0037 = qcdr(v0036);
    v0036 = (Lisp_Object)1; /* 0 */
    v0036 = (Lisp_Object)lessp2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0036 = v0036 ? lisp_true : nil;
    env = stack[-3];
    if (v0036 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = elt(env, 3); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    v0036 = Labsval(nil, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0036 = cons(stack[0], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    {
        Lisp_Object v0051 = stack[-2];
        popv(4);
        return list2(v0051, v0036);
    }

v0047:
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    v0037 = qcdr(v0036);
    v0036 = (Lisp_Object)1; /* 0 */
    v0036 = (Lisp_Object)lessp2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0036 = v0036 ? lisp_true : nil;
    env = stack[-3];
    goto v0048;

v0045:
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    v0036 = (is_number(v0036) ? lisp_true : nil);
    goto v0046;

v0040:
    v0036 = stack[-1];
    v0037 = qcdr(v0036);
    v0036 = (Lisp_Object)1; /* 0 */
    v0036 = (Lisp_Object)lessp2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0036 = v0036 ? lisp_true : nil;
    env = stack[-3];
    goto v0041;

v0038:
    v0036 = stack[-1];
    v0037 = qcdr(v0036);
    v0036 = (Lisp_Object)1; /* 0 */
    v0036 = (Lisp_Object)geq2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0036 = v0036 ? lisp_true : nil;
    env = stack[-3];
    goto v0039;
/* error exit handlers */
v0043:
    popv(4);
    return nil;
}



/* Code for vdpvevlcomp */

static Lisp_Object CC_vdpvevlcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpvevlcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0053 = v0001;
    v0054 = v0000;
/* end of prologue */
    v0054 = qcdr(v0054);
    v0054 = qcdr(v0054);
    v0054 = qcdr(v0054);
    v0054 = qcar(v0054);
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0053 = qcar(v0053);
    {
        fn = elt(env, 1); /* dipevlcomp */
        return (*qfn2(fn))(qenv(fn), v0054, v0053);
    }
}



/* Code for gparg1p */

static Lisp_Object CC_gparg1p(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gparg1p");
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

v0055:
    v0034 = stack[0];
    if (v0034 == nil) goto v0056;
    v0034 = stack[0];
    v0034 = qcar(v0034);
    fn = elt(env, 3); /* gpargp */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    if (v0034 == nil) goto v0031;
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0055;

v0031:
    v0034 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0034); }

v0056:
    v0034 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0034); }
/* error exit handlers */
v0038:
    popv(2);
    return nil;
}



/* Code for assert_check1 */

static Lisp_Object MS_CDECL CC_assert_check1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0104, v0105, v0106, v0107, v0108;
    Lisp_Object fn;
    Lisp_Object v0056, v0068, v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "assert_check1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    v0068 = va_arg(aa, Lisp_Object);
    v0056 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_check1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0056,v0068,v0080,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0080,v0068,v0056);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-5] = v0056;
    stack[-6] = v0068;
    stack[-7] = v0080;
    stack[-8] = v0001;
    stack[-9] = v0000;
/* end of prologue */
    stack[-4] = nil;
    v0103 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0103;
    v0103 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v0103 == nil) goto v0109;
    v0104 = stack[-9];
    v0103 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v0103 = Latsoc(nil, v0104, v0103);
    v0104 = v0103;
    v0103 = v0104;
    if (v0103 == nil) goto v0110;
    v0103 = v0104;
    stack[0] = qcdr(v0103);
    v0103 = v0104;
    v0103 = qcdr(v0103);
    v0103 = qcar(v0103);
    v0103 = add1(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    fn = elt(env, 7); /* setcar */
    v0103 = (*qfn2(fn))(qenv(fn), stack[0], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    goto v0109;

v0109:
    v0103 = stack[-6];
    stack[-10] = v0103;
    v0103 = stack[-7];
    stack[-2] = v0103;
    goto v0112;

v0112:
    v0103 = stack[-2];
    if (v0103 == nil) goto v0008;
    v0103 = stack[-2];
    v0103 = qcar(v0103);
    stack[-1] = v0103;
    v0103 = stack[-3];
    v0103 = add1(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    stack[-3] = v0103;
    v0103 = stack[-10];
    v0104 = qcar(v0103);
    v0103 = elt(env, 4); /* assert_dyntypechk */
    v0103 = get(v0104, v0103);
    env = stack[-11];
    v0104 = v0103;
    if (v0103 == nil) goto v0042;
    stack[0] = v0104;
    v0103 = stack[-1];
    v0103 = ncons(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    fn = elt(env, 8); /* apply */
    v0103 = (*qfn2(fn))(qenv(fn), stack[0], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    if (v0103 == nil) goto v0113;
    v0103 = qvalue(elt(env, 3)); /* nil */
    goto v0114;

v0114:
    if (v0103 == nil) goto v0042;
    v0103 = qvalue(elt(env, 6)); /* t */
    stack[-4] = v0103;
    v0108 = stack[-9];
    v0107 = stack[-6];
    v0106 = stack[-5];
    v0105 = stack[-3];
    v0103 = stack[-10];
    v0104 = qcar(v0103);
    v0103 = stack[-1];
    fn = elt(env, 9); /* assert_error */
    v0103 = (*qfnn(fn))(qenv(fn), 6, v0108, v0107, v0106, v0105, v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    goto v0042;

v0042:
    v0103 = stack[-10];
    v0103 = qcdr(v0103);
    stack[-10] = v0103;
    v0103 = stack[-2];
    v0103 = qcdr(v0103);
    stack[-2] = v0103;
    goto v0112;

v0113:
    v0103 = stack[-1];
    v0103 = Lconsp(nil, v0103);
    env = stack[-11];
    if (v0103 == nil) goto v0017;
    v0103 = stack[-1];
    v0104 = qcar(v0103);
    v0103 = elt(env, 5); /* assert_ignore */
    v0103 = Lflagp(nil, v0104, v0103);
    env = stack[-11];
    goto v0018;

v0018:
    v0103 = (v0103 == nil ? lisp_true : nil);
    goto v0114;

v0017:
    v0103 = qvalue(elt(env, 3)); /* nil */
    goto v0018;

v0008:
    v0104 = stack[-8];
    v0103 = stack[-7];
    fn = elt(env, 8); /* apply */
    v0103 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    stack[-1] = v0103;
    v0104 = stack[-5];
    v0103 = elt(env, 4); /* assert_dyntypechk */
    v0103 = get(v0104, v0103);
    env = stack[-11];
    v0104 = v0103;
    if (v0103 == nil) goto v0005;
    stack[0] = v0104;
    v0103 = stack[-1];
    v0103 = ncons(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    fn = elt(env, 8); /* apply */
    v0103 = (*qfn2(fn))(qenv(fn), stack[0], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    if (v0103 == nil) goto v0037;
    v0103 = qvalue(elt(env, 3)); /* nil */
    goto v0036;

v0036:
    if (v0103 == nil) goto v0005;
    v0103 = qvalue(elt(env, 6)); /* t */
    stack[-4] = v0103;
    v0108 = stack[-9];
    v0107 = stack[-6];
    v0106 = stack[-5];
    v0105 = (Lisp_Object)1; /* 0 */
    v0104 = stack[-5];
    v0103 = stack[-1];
    fn = elt(env, 9); /* assert_error */
    v0103 = (*qfnn(fn))(qenv(fn), 6, v0108, v0107, v0106, v0105, v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    goto v0005;

v0005:
    v0103 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v0103 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v0103 = stack[-4];
    if (v0103 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v0104 = stack[-9];
    v0103 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v0103 = Latsoc(nil, v0104, v0103);
    v0103 = qcdr(v0103);
    v0104 = v0103;
    v0103 = v0104;
    stack[0] = qcdr(v0103);
    v0103 = v0104;
    v0103 = qcdr(v0103);
    v0103 = qcar(v0103);
    v0103 = add1(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    fn = elt(env, 7); /* setcar */
    v0103 = (*qfn2(fn))(qenv(fn), stack[0], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }

v0037:
    v0103 = stack[-1];
    v0103 = Lconsp(nil, v0103);
    env = stack[-11];
    if (v0103 == nil) goto v0115;
    v0103 = stack[-1];
    v0104 = qcar(v0103);
    v0103 = elt(env, 5); /* assert_ignore */
    v0103 = Lflagp(nil, v0104, v0103);
    env = stack[-11];
    goto v0116;

v0116:
    v0103 = (v0103 == nil ? lisp_true : nil);
    goto v0036;

v0115:
    v0103 = qvalue(elt(env, 3)); /* nil */
    goto v0116;

v0110:
    stack[0] = stack[-9];
    v0105 = (Lisp_Object)17; /* 1 */
    v0104 = (Lisp_Object)1; /* 0 */
    v0103 = (Lisp_Object)1; /* 0 */
    v0104 = list3(v0105, v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    v0103 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v0103 = acons(stack[0], v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-11];
    qvalue(elt(env, 2)) = v0103; /* assertstatistics!* */
    goto v0109;
/* error exit handlers */
v0111:
    popv(12);
    return nil;
}



/* Code for groeb!=newpair */

static Lisp_Object MS_CDECL CC_groebMnewpair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0030, v0029;
    Lisp_Object fn;
    Lisp_Object v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=newpair");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=newpair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0080,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0080;
    stack[-3] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0110 = stack[-3];
    fn = elt(env, 1); /* bas_dpoly */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-5];
    v0110 = stack[-2];
    fn = elt(env, 1); /* bas_dpoly */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-5];
    fn = elt(env, 3); /* mo_lcm */
    v0110 = (*qfn2(fn))(qenv(fn), stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-5];
    stack[0] = v0110;
    stack[-4] = stack[-1];
    v0029 = stack[0];
    v0030 = stack[-3];
    v0110 = stack[-2];
    fn = elt(env, 4); /* groeb!=weight */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0029, v0030, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-5];
    v0030 = stack[-3];
    v0110 = stack[-2];
    v0110 = list2(v0030, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    {
        Lisp_Object v0124 = stack[-4];
        Lisp_Object v0027 = stack[-1];
        Lisp_Object v0028 = stack[0];
        popv(6);
        return list3star(v0124, v0027, v0028, v0110);
    }
/* error exit handlers */
v0095:
    popv(6);
    return nil;
}



/* Code for klistt */

static Lisp_Object CC_klistt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for klistt");
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
    goto v0128;

v0128:
    v0126 = stack[0];
    if (!consp(v0126)) goto v0003;
    v0126 = stack[0];
    v0126 = qcar(v0126);
    v0127 = qcar(v0126);
    v0126 = stack[-1];
    v0126 = cons(v0127, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    stack[-1] = v0126;
    v0127 = stack[0];
    v0126 = elt(env, 1); /* list */
    fn = elt(env, 2); /* carx */
    v0126 = (*qfn2(fn))(qenv(fn), v0127, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    v0126 = qcdr(v0126);
    stack[0] = v0126;
    goto v0128;

v0003:
    v0126 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0126);
    }
/* error exit handlers */
v0122:
    popv(3);
    return nil;
}



/* Code for get!-denom!-ll */

static Lisp_Object CC_getKdenomKll(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-denom-ll");
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
    stack[-3] = nil;
    goto v0075;

v0075:
    v0122 = stack[-2];
    if (v0122 == nil) goto v0085;
    v0122 = stack[-2];
    stack[0] = qcar(v0122);
    v0122 = stack[-1];
    v0122 = qcar(v0122);
    fn = elt(env, 1); /* get!-denom!-l */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-4];
    fn = elt(env, 2); /* lcmn */
    v0026 = (*qfn2(fn))(qenv(fn), stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-4];
    v0122 = stack[-3];
    v0122 = cons(v0026, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-4];
    stack[-3] = v0122;
    v0122 = stack[-2];
    v0122 = qcdr(v0122);
    stack[-2] = v0122;
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    stack[-1] = v0122;
    goto v0075;

v0085:
    v0122 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0122);
    }
/* error exit handlers */
v0132:
    popv(5);
    return nil;
}



/* Code for tmsf */

static Lisp_Object CC_tmsf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0091, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tmsf");
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
    v0137 = (Lisp_Object)1; /* 0 */
    v0092 = v0137;
    goto v0085;

v0085:
    v0137 = stack[-1];
    if (!consp(v0137)) goto v0109;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = (consp(v0137) ? nil : lisp_true);
    goto v0138;

v0138:
    if (v0137 == nil) goto v0118;
    v0137 = stack[-1];
    if (v0137 == nil) { popv(4); return onevalue(v0092); }
    v0137 = v0092;
    popv(4);
    return add1(v0137);

v0118:
    stack[-2] = v0092;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    stack[0] = v0137;
    fn = elt(env, 3); /* sfp */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    if (v0137 == nil) goto v0029;
    v0137 = stack[0];
    v0137 = CC_tmsf(env, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    stack[0] = v0137;
    goto v0123;

v0123:
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    fn = elt(env, 4); /* tmsf!* */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0137 = plus2(stack[0], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0137 = plus2(stack[-2], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0092 = v0137;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0091 = qcdr(v0137);
    v0137 = (Lisp_Object)17; /* 1 */
    if (v0091 == v0137) goto v0027;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0091 = qcdr(v0137);
    v0137 = (Lisp_Object)33; /* 2 */
    if (v0091 == v0137) goto v0139;
    v0091 = v0092;
    v0137 = (Lisp_Object)33; /* 2 */
    v0137 = plus2(v0091, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0092 = v0137;
    goto v0027;

v0027:
    v0137 = stack[-1];
    v0137 = qcdr(v0137);
    stack[-1] = v0137;
    goto v0085;

v0139:
    v0137 = v0092;
    v0137 = add1(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0092 = v0137;
    goto v0027;

v0029:
    v0137 = (Lisp_Object)17; /* 1 */
    stack[0] = v0137;
    goto v0123;

v0109:
    v0137 = qvalue(elt(env, 1)); /* t */
    goto v0138;
/* error exit handlers */
v0017:
    popv(4);
    return nil;
}



/* Code for qqe_ofsf_simpat */

static Lisp_Object CC_qqe_ofsf_simpat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_simpat");
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
    v0032 = stack[0];
    fn = elt(env, 2); /* qqe_arg2l */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    fn = elt(env, 3); /* qqe_ofsf_chsimpterm */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 4); /* qqe_arg2r */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    fn = elt(env, 3); /* qqe_ofsf_chsimpterm */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 6); /* qqe_op */
    v0033 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    v0032 = elt(env, 1); /* (qequal qneq) */
    v0032 = Lmemq(nil, v0033, v0032);
    if (v0032 == nil) goto v0118;
    v0032 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* qqe_simpat */
        return (*qfn1(fn))(qenv(fn), v0032);
    }

v0118:
    v0032 = stack[0];
    {
        popv(2);
        fn = elt(env, 8); /* ofsf_simpat */
        return (*qfn1(fn))(qenv(fn), v0032);
    }
/* error exit handlers */
v0126:
    popv(2);
    return nil;
}



/* Code for pasf_varlat */

static Lisp_Object CC_pasf_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_varlat");
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
    v0114 = stack[0];
    v0114 = qcdr(v0114);
    v0114 = qcar(v0114);
    fn = elt(env, 4); /* kernels */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0114 = stack[0];
    v0114 = Lconsp(nil, v0114);
    env = stack[-4];
    if (v0114 == nil) goto v0145;
    v0114 = stack[0];
    v0114 = qcar(v0114);
    v0114 = Lconsp(nil, v0114);
    env = stack[-4];
    if (v0114 == nil) goto v0145;
    v0114 = stack[0];
    v0114 = qcar(v0114);
    v0113 = qcar(v0114);
    v0114 = elt(env, 1); /* (cong ncong) */
    v0114 = Lmemq(nil, v0113, v0114);
    if (v0114 == nil) goto v0145;
    v0114 = stack[0];
    v0114 = qcar(v0114);
    v0114 = qcdr(v0114);
    fn = elt(env, 4); /* kernels */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    goto v0085;

v0085:
    v0114 = Lappend(nil, stack[-1], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0113 = v0114;
    v0114 = qvalue(elt(env, 3)); /* !*rlbrkcxk */
    if (v0114 == nil) { popv(5); return onevalue(v0113); }
    v0114 = v0113;
    stack[-3] = v0114;
    goto v0097;

v0097:
    v0114 = stack[-3];
    if (v0114 == nil) goto v0146;
    v0114 = stack[-3];
    v0114 = qcar(v0114);
    fn = elt(env, 5); /* rltools_lpvarl */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    stack[-2] = v0114;
    v0114 = stack[-2];
    fn = elt(env, 6); /* lastpair */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    stack[-1] = v0114;
    v0114 = stack[-3];
    v0114 = qcdr(v0114);
    stack[-3] = v0114;
    v0114 = stack[-1];
    if (!consp(v0114)) goto v0097;
    else goto v0095;

v0095:
    v0114 = stack[-3];
    if (v0114 == nil) goto v0147;
    stack[0] = stack[-1];
    v0114 = stack[-3];
    v0114 = qcar(v0114);
    fn = elt(env, 5); /* rltools_lpvarl */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0114 = Lrplacd(nil, stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0114 = stack[-1];
    fn = elt(env, 6); /* lastpair */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    stack[-1] = v0114;
    v0114 = stack[-3];
    v0114 = qcdr(v0114);
    stack[-3] = v0114;
    goto v0095;

v0147:
    v0114 = stack[-2];
    goto v0148;

v0148:
    v0113 = v0114;
    { popv(5); return onevalue(v0113); }

v0146:
    v0114 = qvalue(elt(env, 2)); /* nil */
    goto v0148;

v0145:
    v0114 = qvalue(elt(env, 2)); /* nil */
    goto v0085;
/* error exit handlers */
v0144:
    popv(5);
    return nil;
}



/* Code for aex_tad */

static Lisp_Object CC_aex_tad(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_tad");
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
    v0053 = stack[0];
    fn = elt(env, 2); /* aex_ex */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    fn = elt(env, 3); /* ratpoly_tad */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    v0053 = stack[0];
    fn = elt(env, 4); /* aex_ctx */
    v0140 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    v0054 = qvalue(elt(env, 1)); /* nil */
    v0053 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0038 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0038, v0140, v0054, v0053);
    }
/* error exit handlers */
v0125:
    popv(3);
    return nil;
}



/* Code for lambdavar */

static Lisp_Object CC_lambdavar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambdavar");
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
    v0085 = v0000;
/* end of prologue */
    v0085 = qcdr(v0085);
    v0085 = qcdr(v0085);
    v0085 = Lreverse(nil, v0085);
    errexit();
    v0085 = qcdr(v0085);
    return onevalue(v0085);
}



/* Code for ps!:value */

static Lisp_Object CC_psTvalue(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0040, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:value");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0135 = v0000;
/* end of prologue */
    v0143 = v0135;
    if (!consp(v0143)) goto v0003;
    v0143 = v0135;
    v0040 = qcar(v0143);
    v0143 = elt(env, 2); /* !:ps!: */
    if (v0040 == v0143) goto v0130;
    v0143 = v0135;
    v0143 = qcar(v0143);
    if (!symbolp(v0143)) v0143 = nil;
    else { v0143 = qfastgets(v0143);
           if (v0143 != nil) { v0143 = elt(v0143, 8); /* dname */
#ifdef RECORD_GET
             if (v0143 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0143 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0143 == SPID_NOPROP) v0143 = nil; }}
#endif
    goto v0002;

v0002:
    if (v0143 == nil) goto v0132;
    v0143 = v0135;
    if (!(v0143 == nil)) return onevalue(v0135);
    v0143 = (Lisp_Object)1; /* 0 */
    return onevalue(v0143);

v0132:
    v0040 = v0135;
    v0143 = (Lisp_Object)65; /* 4 */
    {
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0040, v0143);
    }

v0130:
    v0143 = qvalue(elt(env, 3)); /* nil */
    goto v0002;

v0003:
    v0143 = qvalue(elt(env, 1)); /* t */
    goto v0002;
}



/* Code for dipsimpcont */

static Lisp_Object CC_dipsimpcont(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipsimpcont");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0149 = v0000;
/* end of prologue */
    v0109 = qvalue(elt(env, 1)); /* !*vdpinteger */
    if (!(v0109 == nil)) goto v0056;
    v0109 = qvalue(elt(env, 2)); /* !*groebdivide */
    if (v0109 == nil) goto v0056;
    v0109 = v0149;
    {
        fn = elt(env, 3); /* dipsimpcontr */
        return (*qfn1(fn))(qenv(fn), v0109);
    }

v0056:
    v0109 = v0149;
    {
        fn = elt(env, 4); /* dipsimpconti */
        return (*qfn1(fn))(qenv(fn), v0109);
    }
}



/* Code for replace1_parents */

static Lisp_Object MS_CDECL CC_replace1_parents(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054, v0140;
    Lisp_Object fn;
    Lisp_Object v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace1_parents");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replace1_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0053 = v0080;
    v0054 = v0001;
    v0140 = v0000;
/* end of prologue */
    v0140 = qcar(v0140);
    v0054 = qcar(v0054);
    v0053 = qcdr(v0053);
    v0053 = qcar(v0053);
    {
        fn = elt(env, 1); /* replace2_parents */
        return (*qfnn(fn))(qenv(fn), 3, v0140, v0054, v0053);
    }
}



/* Code for changearg */

static Lisp_Object MS_CDECL CC_changearg(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0112, v0139;
    Lisp_Object fn;
    Lisp_Object v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "changearg");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for changearg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0080,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0080;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0002;

v0002:
    v0151 = stack[0];
    if (!consp(v0151)) goto v0136;
    v0151 = stack[0];
    v0112 = qcar(v0151);
    v0151 = stack[-2];
    v0151 = Lmemq(nil, v0112, v0151);
    if (v0151 == nil) goto v0124;
    stack[-2] = stack[-3];
    v0151 = stack[0];
    v0112 = qcar(v0151);
    v0151 = stack[-1];
    v0151 = cons(v0112, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    {
        Lisp_Object v0153 = stack[-2];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0153, v0151);
    }

v0124:
    v0139 = stack[-2];
    v0112 = stack[-1];
    v0151 = stack[0];
    v0151 = qcar(v0151);
    v0112 = CC_changearg(env, 3, v0139, v0112, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    v0151 = stack[-3];
    v0151 = cons(v0112, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    stack[-3] = v0151;
    v0151 = stack[0];
    v0151 = qcdr(v0151);
    stack[0] = v0151;
    goto v0002;

v0136:
    v0112 = stack[-3];
    v0151 = stack[0];
    {
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0112, v0151);
    }
/* error exit handlers */
v0152:
    popv(5);
    return nil;
}



/* Code for !*di2q0 */

static Lisp_Object CC_Hdi2q0(Lisp_Object env,
                         Lisp_Object v0001, Lisp_Object v0080)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0165, v0166, v0167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *di2q0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0080,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0164 = v0080;
    stack[-3] = v0001;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist!* */
    qvalue(elt(env, 1)) = nil; /* varlist!* */
    qvalue(elt(env, 1)) = v0164; /* varlist!* */
    stack[-2] = nil;
    goto v0031;

v0031:
    v0164 = stack[-3];
    if (v0164 == nil) goto v0018;
    v0164 = stack[-3];
    v0164 = qcar(v0164);
    stack[-1] = qcdr(v0164);
    stack[0] = qvalue(elt(env, 1)); /* varlist!* */
    v0165 = qvalue(elt(env, 2)); /* ordering */
    v0164 = elt(env, 3); /* lex */
    if (v0165 == v0164) goto v0122;
    v0164 = stack[-3];
    fn = elt(env, 5); /* ljet */
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0164 = qcdr(v0164);
    goto v0129;

v0129:
    fn = elt(env, 6); /* pair */
    v0164 = (*qfn2(fn))(qenv(fn), stack[0], v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0167 = stack[-1];
    stack[-1] = v0164;
    goto v0028;

v0028:
    v0164 = stack[-1];
    if (v0164 == nil) goto v0027;
    v0164 = stack[-1];
    v0164 = qcar(v0164);
    v0166 = v0164;
    v0164 = v0166;
    v0165 = qcdr(v0164);
    v0164 = (Lisp_Object)1; /* 0 */
    if (v0165 == v0164) goto v0151;
    stack[0] = v0167;
    v0165 = v0166;
    v0164 = (Lisp_Object)17; /* 1 */
    v0166 = cons(v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0165 = qvalue(elt(env, 4)); /* nil */
    v0164 = (Lisp_Object)17; /* 1 */
    v0164 = acons(v0166, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    fn = elt(env, 7); /* multsq */
    v0164 = (*qfn2(fn))(qenv(fn), stack[0], v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0167 = v0164;
    goto v0151;

v0151:
    v0164 = stack[-1];
    v0164 = qcdr(v0164);
    stack[-1] = v0164;
    goto v0028;

v0027:
    v0165 = v0167;
    v0164 = stack[-2];
    v0164 = cons(v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    stack[-2] = v0164;
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    stack[-3] = v0164;
    goto v0031;

v0122:
    v0164 = stack[-3];
    fn = elt(env, 5); /* ljet */
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    goto v0129;

v0018:
    v0165 = qvalue(elt(env, 4)); /* nil */
    v0164 = (Lisp_Object)17; /* 1 */
    v0164 = cons(v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0165 = v0164;
    goto v0136;

v0136:
    v0164 = stack[-2];
    if (v0164 == nil) goto v0169;
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    fn = elt(env, 8); /* addsq */
    v0164 = (*qfn2(fn))(qenv(fn), v0164, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0165 = v0164;
    v0164 = stack[-2];
    v0164 = qcdr(v0164);
    stack[-2] = v0164;
    goto v0136;

v0169:
    v0164 = v0165;
    qvalue(elt(env, 1)) = stack[-4]; /* varlist!* */
    { popv(6); return onevalue(v0164); }
/* error exit handlers */
v0168:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist!* */
    popv(6);
    return nil;
}



/* Code for rootrnd */

static Lisp_Object CC_rootrnd(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rootrnd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0061 = v0000;
/* end of prologue */
    v0086 = v0061;
    v0061 = qvalue(elt(env, 1)); /* acc!# */
    {
        fn = elt(env, 2); /* rtrnda */
        return (*qfn2(fn))(qenv(fn), v0086, v0061);
    }
}



/* Code for checku */

static Lisp_Object CC_checku(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0122, v0026, v0041;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for checku");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0122 = v0001;
    v0026 = v0000;
/* end of prologue */

v0055:
    v0121 = v0026;
    if (v0121 == nil) goto v0128;
    v0121 = v0122;
    v0041 = qcar(v0121);
    v0121 = v0026;
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    if (equal(v0041, v0121)) goto v0039;
    v0121 = v0026;
    v0026 = qcdr(v0121);
    v0121 = v0122;
    v0122 = v0121;
    goto v0055;

v0039:
    v0121 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0121);

v0128:
    v0121 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0121);
}



/* Code for homogp */

static Lisp_Object CC_homogp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for homogp");
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
    v0159 = stack[0];
    if (!consp(v0159)) goto v0031;
    v0159 = stack[0];
    v0159 = qcar(v0159);
    v0159 = (consp(v0159) ? nil : lisp_true);
    goto v0086;

v0086:
    if (v0159 == nil) goto v0035;
    v0159 = qvalue(elt(env, 1)); /* t */
    goto v0002;

v0002:
    if (v0159 == nil) goto v0128;
    v0159 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0159); }

v0128:
    v0159 = stack[0];
    v0159 = qcdr(v0159);
    v0159 = qcar(v0159);
    v0159 = qcdr(v0159);
    if (v0159 == nil) goto v0122;
    v0159 = stack[0];
    v0159 = qcdr(v0159);
    v0159 = qcar(v0159);
    fn = elt(env, 3); /* lastnondomain */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0159 = qcdr(v0159);
    v0141 = v0159;
    v0159 = v0141;
    if (!consp(v0159)) goto v0097;
    v0159 = v0141;
    v0159 = qcar(v0159);
    v0159 = (consp(v0159) ? nil : lisp_true);
    goto v0148;

v0148:
    if (v0159 == nil) goto v0096;
    v0159 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0159); }

v0096:
    v0159 = stack[0];
    v0159 = qcdr(v0159);
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    fn = elt(env, 4); /* listsum */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0159 = stack[0];
    v0159 = qcdr(v0159);
    v0159 = qcar(v0159);
    fn = elt(env, 3); /* lastnondomain */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    fn = elt(env, 4); /* listsum */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    if (equal(stack[-1], v0159)) goto v0098;
    v0159 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0159); }

v0098:
    v0159 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0159); }

v0097:
    v0159 = qvalue(elt(env, 1)); /* t */
    goto v0148;

v0122:
    v0159 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0159); }

v0035:
    v0159 = stack[0];
    v0159 = qcar(v0159);
    if (!consp(v0159)) goto v0102;
    v0159 = stack[0];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0159 = (consp(v0159) ? nil : lisp_true);
    goto v0002;

v0102:
    v0159 = qvalue(elt(env, 1)); /* t */
    goto v0002;

v0031:
    v0159 = qvalue(elt(env, 1)); /* t */
    goto v0086;
/* error exit handlers */
v0020:
    popv(3);
    return nil;
}



/* Code for vdp_setsugar */

static Lisp_Object CC_vdp_setsugar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0034, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_setsugar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0001;
    v0125 = v0000;
/* end of prologue */
    v0034 = qvalue(elt(env, 1)); /* !*cgbsugar */
    if (v0034 == nil) return onevalue(v0125);
    v0034 = elt(env, 2); /* sugar */
    {
        fn = elt(env, 3); /* vdp_putprop */
        return (*qfnn(fn))(qenv(fn), 3, v0125, v0034, v0035);
    }
}



/* Code for getdec */

static Lisp_Object CC_getdec(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getdec");
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
    v0035 = qvalue(elt(env, 1)); /* nil */
    v0140 = stack[0];
    fn = elt(env, 2); /* symtabget */
    v0140 = (*qfn2(fn))(qenv(fn), v0035, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-1];
    v0035 = v0140;
    v0140 = v0035;
    if (!(v0140 == nil)) { popv(2); return onevalue(v0035); }
    v0140 = stack[0];
    fn = elt(env, 3); /* implicitdec */
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    v0035 = v0140;
    { popv(2); return onevalue(v0035); }
/* error exit handlers */
v0125:
    popv(2);
    return nil;
}



/* Code for expvec2a */

static Lisp_Object CC_expvec2a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expvec2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0061 = v0000;
/* end of prologue */
    v0086 = v0061;
    v0061 = qvalue(elt(env, 1)); /* dipvars!* */
    {
        fn = elt(env, 2); /* expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v0086, v0061);
    }
}



/* Code for memqcar */

static Lisp_Object CC_memqcar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0140, v0035;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for memqcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0140 = v0001;
    v0035 = v0000;
/* end of prologue */
    v0054 = v0035;
    if (!consp(v0054)) goto v0149;
    v0054 = v0035;
    v0054 = qcar(v0054);
    v0054 = Lmemq(nil, v0054, v0140);
    return onevalue(v0054);

v0149:
    v0054 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0054);
}



/* Code for eqexpr */

static Lisp_Object CC_eqexpr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0145, v0170;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for eqexpr");
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
    v0145 = v0000;
/* end of prologue */
    v0101 = v0145;
    if (!consp(v0101)) goto v0122;
    v0101 = v0145;
    v0170 = qcar(v0101);
    v0101 = elt(env, 1); /* equalopr */
    v0101 = Lflagp(nil, v0170, v0101);
    env = stack[0];
    if (v0101 == nil) goto v0127;
    v0101 = v0145;
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    if (v0101 == nil) goto v0035;
    v0101 = v0145;
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = (v0101 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0101); }

v0035:
    v0101 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0101); }

v0127:
    v0101 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0101); }

v0122:
    v0101 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0101); }
}



/* Code for calc_atlas */

static Lisp_Object CC_calc_atlas(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0125, v0038, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_atlas");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0001;
    v0125 = v0000;
/* end of prologue */
    v0038 = v0125;
    v0102 = qcar(v0038);
    v0038 = v0125;
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0125 = qcdr(v0125);
    v0125 = qcar(v0125);
    {
        fn = elt(env, 1); /* calc_map_2d */
        return (*qfnn(fn))(qenv(fn), 4, v0102, v0038, v0125, v0034);
    }
}



/* Code for mo_zero */

static Lisp_Object MS_CDECL CC_mo_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mo_zero");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_zero");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v0061 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* mo!=deglist */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    {
        Lisp_Object v0039 = stack[0];
        popv(1);
        return cons(v0039, v0061);
    }
/* error exit handlers */
v0031:
    popv(1);
    return nil;
}



/* Code for squashsqrt */

static Lisp_Object CC_squashsqrt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0177, v0178, v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for squashsqrt");
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

v0055:
    v0177 = qvalue(elt(env, 1)); /* sqrtflag */
    if (v0177 == nil) goto v0003;
    v0177 = stack[-1];
    if (!consp(v0177)) goto v0109;
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = (consp(v0177) ? nil : lisp_true);
    goto v0002;

v0002:
    if (!(v0177 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0178 = qcar(v0177);
    v0177 = elt(env, 3); /* sqrt */
    if (v0178 == v0177) goto v0119;
    v0177 = qvalue(elt(env, 4)); /* nil */
    goto v0032;

v0032:
    if (v0177 == nil) goto v0020;
    v0177 = stack[-1];
    v0177 = qcdr(v0177);
    stack[0] = CC_squashsqrt(env, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0179 = qcar(v0177);
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0178 = qcdr(v0177);
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcdr(v0177);
    fn = elt(env, 6); /* !*multfsqrt */
    v0177 = (*qfnn(fn))(qenv(fn), 3, v0179, v0178, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    {
        Lisp_Object v0181 = stack[0];
        popv(4);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v0181, v0177);
    }

v0020:
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0178 = qcar(v0177);
    v0177 = elt(env, 5); /* expt */
    if (v0178 == v0177) goto v0182;
    v0177 = qvalue(elt(env, 4)); /* nil */
    goto v0141;

v0141:
    if (v0177 == nil) goto v0005;
    v0177 = stack[-1];
    v0177 = qcdr(v0177);
    stack[0] = CC_squashsqrt(env, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0179 = qcar(v0177);
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0178 = qcdr(v0177);
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcdr(v0177);
    fn = elt(env, 8); /* !*multfexpt */
    v0177 = (*qfnn(fn))(qenv(fn), 3, v0179, v0178, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    {
        Lisp_Object v0183 = stack[0];
        popv(4);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v0183, v0177);
    }

v0005:
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcdr(v0177);
    v0177 = CC_squashsqrt(env, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    v0178 = v0177;
    v0177 = v0178;
    if (v0177 == nil) goto v0184;
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    stack[-2] = qcar(v0177);
    stack[0] = v0178;
    v0177 = stack[-1];
    v0177 = qcdr(v0177);
    v0177 = CC_squashsqrt(env, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    {
        Lisp_Object v0185 = stack[-2];
        Lisp_Object v0071 = stack[0];
        popv(4);
        return acons(v0185, v0071, v0177);
    }

v0184:
    v0177 = stack[-1];
    v0177 = qcdr(v0177);
    stack[-1] = v0177;
    goto v0055;

v0182:
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcdr(v0177);
    v0177 = qcdr(v0177);
    v0177 = qcar(v0177);
    fn = elt(env, 9); /* prefix!-rational!-numberp */
    v0177 = (*qfn1(fn))(qenv(fn), v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    if (v0177 == nil) goto v0160;
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0178 = qcdr(v0177);
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcdr(v0177);
    v0177 = qcdr(v0177);
    v0177 = qcar(v0177);
    v0177 = qcdr(v0177);
    v0177 = qcdr(v0177);
    v0177 = qcar(v0177);
    v0177 = (Lisp_Object)geq2(v0178, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    v0177 = v0177 ? lisp_true : nil;
    env = stack[-3];
    goto v0141;

v0160:
    v0177 = qvalue(elt(env, 4)); /* nil */
    goto v0141;

v0119:
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0178 = qcdr(v0177);
    v0177 = (Lisp_Object)17; /* 1 */
    v0177 = (Lisp_Object)greaterp2(v0178, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    v0177 = v0177 ? lisp_true : nil;
    env = stack[-3];
    goto v0032;

v0109:
    v0177 = qvalue(elt(env, 2)); /* t */
    goto v0002;

v0003:
    v0177 = qvalue(elt(env, 2)); /* t */
    goto v0002;
/* error exit handlers */
v0180:
    popv(4);
    return nil;
}



/* Code for get!-denom!-l */

static Lisp_Object CC_getKdenomKl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0135, v0148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-denom-l");
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
    v0135 = v0000;
/* end of prologue */
    v0040 = v0135;
    v0040 = qcar(v0040);
    if (!consp(v0040)) goto v0056;
    v0040 = v0135;
    v0040 = qcar(v0040);
    v0040 = qcdr(v0040);
    v0040 = qcdr(v0040);
    goto v0068;

v0068:
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    goto v0053;

v0053:
    v0135 = stack[0];
    if (v0135 == nil) { popv(2); return onevalue(v0040); }
    v0135 = stack[0];
    v0135 = qcar(v0135);
    v0148 = v0135;
    v0135 = v0040;
    v0040 = v0148;
    if (!consp(v0040)) goto v0041;
    v0040 = v0148;
    v0040 = qcdr(v0040);
    v0040 = qcdr(v0040);
    goto v0127;

v0127:
    fn = elt(env, 2); /* lcmn */
    v0040 = (*qfn2(fn))(qenv(fn), v0135, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    goto v0053;

v0041:
    v0040 = (Lisp_Object)17; /* 1 */
    goto v0127;

v0056:
    v0040 = (Lisp_Object)17; /* 1 */
    goto v0068;
/* error exit handlers */
v0095:
    popv(2);
    return nil;
}



/* Code for dip_fmon */

static Lisp_Object CC_dip_fmon(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0138, v0109;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip_fmon");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0138 = v0001;
    v0136 = v0000;
/* end of prologue */
    v0109 = qvalue(elt(env, 1)); /* nil */
    return list2star(v0138, v0136, v0109);
}



/* Code for lambdaom */

static Lisp_Object CC_lambdaom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambdaom");
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
    v0122 = v0000;
/* end of prologue */
    v0121 = v0122;
    v0121 = qcdr(v0121);
    v0121 = qcdr(v0121);
    v0121 = qcar(v0121);
    v0121 = qcdr(v0121);
    v0121 = qcar(v0121);
    stack[-1] = v0121;
    v0121 = v0122;
    v0121 = Lreverse(nil, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = qcar(v0121);
    stack[0] = v0121;
    v0121 = elt(env, 1); /* "<OMBIND>" */
    fn = elt(env, 8); /* printout */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 9); /* indent!* */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = elt(env, 3); /* "<OMS cd=""fns1"" name=""lambda""/>" */
    fn = elt(env, 8); /* printout */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = elt(env, 4); /* "<OMBVAR>" */
    fn = elt(env, 8); /* printout */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 9); /* indent!* */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = stack[-1];
    fn = elt(env, 10); /* objectom */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 9); /* indent!* */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = elt(env, 6); /* "</OMBVAR>" */
    fn = elt(env, 8); /* printout */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = stack[0];
    fn = elt(env, 10); /* objectom */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 9); /* indent!* */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0121 = elt(env, 7); /* "</OMBIND>" */
    fn = elt(env, 8); /* printout */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    v0121 = nil;
    { popv(3); return onevalue(v0121); }
/* error exit handlers */
v0101:
    popv(3);
    return nil;
}



/* Code for reform!-minus */

static Lisp_Object CC_reformKminus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0088, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reform-minus");
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
    v0186 = stack[0];
    if (v0186 == nil) goto v0085;
    v0186 = stack[-1];
    v0186 = (v0186 == nil ? lisp_true : nil);
    goto v0003;

v0003:
    if (!(v0186 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    v0088 = stack[0];
    v0018 = qcar(v0088);
    v0088 = elt(env, 2); /* minus */
    if (!consp(v0018)) goto v0151;
    v0018 = qcar(v0018);
    if (!(v0018 == v0088)) goto v0151;
    v0018 = v0186;
    v0088 = elt(env, 3); /* quotient */
    if (!consp(v0018)) goto v0150;
    v0018 = qcar(v0018);
    if (!(v0018 == v0088)) goto v0150;
    v0088 = v0186;
    v0088 = qcdr(v0088);
    v0018 = qcar(v0088);
    v0088 = elt(env, 2); /* minus */
    v0088 = Leqcar(nil, v0018, v0088);
    env = stack[-3];
    goto v0126;

v0126:
    if (v0088 == nil) goto v0187;
    stack[-2] = elt(env, 2); /* minus */
    v0018 = elt(env, 3); /* quotient */
    v0088 = v0186;
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    v0186 = qcdr(v0186);
    v0186 = qcdr(v0186);
    v0186 = qcar(v0186);
    v0186 = list3(v0018, v0088, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    v0186 = list2(stack[-2], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    stack[-2] = v0186;
    goto v0161;

v0161:
    v0186 = stack[-1];
    v0088 = qcdr(v0186);
    v0186 = stack[0];
    v0186 = qcdr(v0186);
    v0186 = CC_reformKminus(env, v0088, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    {
        Lisp_Object v0156 = stack[-2];
        popv(4);
        return cons(v0156, v0186);
    }

v0187:
    stack[-2] = v0186;
    goto v0161;

v0150:
    v0088 = qvalue(elt(env, 4)); /* nil */
    goto v0126;

v0151:
    v0088 = qvalue(elt(env, 4)); /* nil */
    goto v0126;

v0085:
    v0186 = qvalue(elt(env, 1)); /* t */
    goto v0003;
/* error exit handlers */
v0188:
    popv(4);
    return nil;
}



/* Code for ps!:depvar */

static Lisp_Object CC_psTdepvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170, v0132, v0163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:depvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0163 = v0000;
/* end of prologue */
    v0170 = v0163;
    if (!consp(v0170)) goto v0003;
    v0170 = v0163;
    v0132 = qcar(v0170);
    v0170 = elt(env, 2); /* !:ps!: */
    if (v0132 == v0170) goto v0130;
    v0170 = v0163;
    v0170 = qcar(v0170);
    if (!symbolp(v0170)) v0170 = nil;
    else { v0170 = qfastgets(v0170);
           if (v0170 != nil) { v0170 = elt(v0170, 8); /* dname */
#ifdef RECORD_GET
             if (v0170 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0170 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0170 == SPID_NOPROP) v0170 = nil; }}
#endif
    goto v0002;

v0002:
    if (v0170 == nil) goto v0123;
    v0170 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0170);

v0123:
    v0132 = v0163;
    v0170 = (Lisp_Object)33; /* 2 */
    {
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0132, v0170);
    }

v0130:
    v0170 = qvalue(elt(env, 3)); /* nil */
    goto v0002;

v0003:
    v0170 = qvalue(elt(env, 1)); /* t */
    goto v0002;
}



/* Code for doublep */

static Lisp_Object CC_doublep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0140, v0035;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for doublep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0000;
/* end of prologue */
    v0140 = v0035;
    v0054 = elt(env, 1); /* !:rd!: */
    if (!consp(v0140)) goto v0149;
    v0140 = qcar(v0140);
    if (!(v0140 == v0054)) goto v0149;
    v0054 = v0035;
    v0054 = qcdr(v0054);
        return Lconsp(nil, v0054);

v0149:
    v0054 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0054);
}



/* Code for oldmtch */

static Lisp_Object CC_oldmtch(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0139, v0190, v0191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oldmtch");
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
    stack[-3] = nil;
    v0139 = stack[-2];
    v0191 = qcdr(v0139);
    v0139 = stack[-1];
    v0190 = qcar(v0139);
    v0139 = stack[-2];
    v0139 = qcar(v0139);
    fn = elt(env, 2); /* mcharg */
    v0139 = (*qfnn(fn))(qenv(fn), 3, v0191, v0190, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[0] = v0139;
    goto v0034;

v0034:
    v0139 = stack[0];
    if (v0139 == nil) goto v0035;
    v0139 = stack[-3];
    if (!(v0139 == nil)) goto v0035;
    v0139 = stack[0];
    v0190 = qcar(v0139);
    v0139 = stack[-1];
    v0139 = qcdr(v0139);
    v0139 = qcar(v0139);
    v0139 = qcdr(v0139);
    v0139 = Lsubla(nil, v0190, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    fn = elt(env, 3); /* eval */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    if (v0139 == nil) goto v0123;
    v0139 = stack[0];
    v0190 = qcar(v0139);
    v0139 = stack[-1];
    v0139 = qcdr(v0139);
    v0139 = qcdr(v0139);
    v0139 = qcar(v0139);
    v0139 = Lsubla(nil, v0190, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    goto v0126;

v0126:
    stack[-3] = v0139;
    v0139 = stack[0];
    v0139 = qcdr(v0139);
    stack[0] = v0139;
    goto v0034;

v0123:
    v0139 = nil;
    goto v0126;

v0035:
    v0139 = stack[-3];
    if (v0139 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    else { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v0147:
    popv(5);
    return nil;
}



/* Code for evinvlexcomp */

static Lisp_Object CC_evinvlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0158, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evinvlexcomp");
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

v0128:
    v0158 = stack[-1];
    if (v0158 == nil) goto v0003;
    v0158 = stack[0];
    if (v0158 == nil) goto v0125;
    v0158 = stack[-1];
    v0159 = qcar(v0158);
    v0158 = stack[0];
    v0158 = qcar(v0158);
    fn = elt(env, 2); /* iequal */
    v0158 = (*qfn2(fn))(qenv(fn), v0159, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    if (v0158 == nil) goto v0029;
    v0158 = stack[-1];
    v0158 = qcdr(v0158);
    stack[-1] = v0158;
    v0158 = stack[0];
    v0158 = qcdr(v0158);
    stack[0] = v0158;
    goto v0128;

v0029:
    v0158 = stack[-1];
    v0159 = qcdr(v0158);
    v0158 = stack[0];
    v0158 = qcdr(v0158);
    v0158 = CC_evinvlexcomp(env, v0159, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    stack[-2] = v0158;
    v0159 = stack[-2];
    v0158 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* iequal */
    v0158 = (*qfn2(fn))(qenv(fn), v0159, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    if (v0158 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0158 = stack[0];
    v0159 = qcar(v0158);
    v0158 = stack[-1];
    v0158 = qcar(v0158);
    if (((int32_t)(v0159)) > ((int32_t)(v0158))) goto v0139;
    v0158 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v0158); }

v0139:
    v0158 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0158); }

v0125:
    v0159 = stack[-1];
    v0158 = elt(env, 1); /* (0) */
    {
        popv(4);
        fn = elt(env, 3); /* evlexcomp */
        return (*qfn2(fn))(qenv(fn), v0159, v0158);
    }

v0003:
    v0158 = stack[0];
    if (v0158 == nil) goto v0039;
    v0158 = elt(env, 1); /* (0) */
    stack[-1] = v0158;
    goto v0128;

v0039:
    v0158 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v0158); }
/* error exit handlers */
v0020:
    popv(4);
    return nil;
}



/* Code for evgradlexcomp */

static Lisp_Object CC_evgradlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evgradlexcomp");
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

v0128:
    v0019 = stack[-2];
    if (v0019 == nil) goto v0003;
    v0019 = stack[-1];
    if (v0019 == nil) goto v0031;
    v0019 = stack[-2];
    v0046 = qcar(v0019);
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    fn = elt(env, 2); /* iequal */
    v0019 = (*qfn2(fn))(qenv(fn), v0046, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    if (v0019 == nil) goto v0033;
    v0019 = stack[-2];
    v0019 = qcdr(v0019);
    stack[-2] = v0019;
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    stack[-1] = v0019;
    goto v0128;

v0033:
    v0019 = stack[-2];
    fn = elt(env, 3); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    v0019 = stack[-1];
    fn = elt(env, 3); /* evtdeg */
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0019;
    v0046 = stack[-3];
    v0019 = stack[0];
    fn = elt(env, 2); /* iequal */
    v0019 = (*qfn2(fn))(qenv(fn), v0046, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    if (v0019 == nil) goto v0151;
    v0019 = stack[-2];
    v0046 = qcar(v0019);
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    if (((int32_t)(v0046)) > ((int32_t)(v0019))) goto v0148;
    v0019 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0019); }

v0148:
    v0019 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0019); }

v0151:
    v0046 = stack[-3];
    v0019 = stack[0];
    if (((int32_t)(v0046)) > ((int32_t)(v0019))) goto v0023;
    v0019 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0019); }

v0023:
    v0019 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0019); }

v0031:
    v0019 = elt(env, 1); /* (0) */
    stack[-1] = v0019;
    goto v0128;

v0003:
    v0019 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0019); }
/* error exit handlers */
v0158:
    popv(5);
    return nil;
}



/* Code for xriterion_1 */

static Lisp_Object MS_CDECL CC_xriterion_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0198, v0069;
    Lisp_Object fn;
    Lisp_Object v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xriterion_1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xriterion_1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0080,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0080;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0055:
    v0077 = stack[-1];
    if (v0077 == nil) goto v0075;
    v0077 = stack[-2];
    v0077 = qcdr(v0077);
    v0198 = qcar(v0077);
    v0077 = elt(env, 2); /* spoly_pair */
    if (v0198 == v0077) goto v0035;
    v0077 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0077); }

v0035:
    v0077 = stack[-1];
    v0077 = qcar(v0077);
    stack[-3] = v0077;
    v0198 = stack[-3];
    v0077 = stack[-2];
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    if (equal(v0198, v0077)) goto v0199;
    v0198 = stack[-3];
    v0077 = stack[-2];
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    if (equal(v0198, v0077)) goto v0009;
    v0077 = stack[-3];
    fn = elt(env, 7); /* xval */
    v0198 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    v0077 = stack[-2];
    v0077 = qcar(v0077);
    fn = elt(env, 8); /* xdiv */
    v0077 = (*qfn2(fn))(qenv(fn), v0198, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    if (v0077 == nil) goto v0189;
    v0198 = stack[-3];
    v0077 = stack[-2];
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    fn = elt(env, 9); /* make_spoly_pair */
    v0077 = (*qfn2(fn))(qenv(fn), v0198, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    v0198 = v0077;
    v0077 = v0198;
    if (v0077 == nil) goto v0142;
    v0077 = stack[0];
    fn = elt(env, 10); /* find_item */
    v0077 = (*qfn2(fn))(qenv(fn), v0198, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    v0077 = (v0077 == nil ? lisp_true : nil);
    goto v0020;

v0020:
    if (v0077 == nil) goto v0152;
    v0198 = stack[-3];
    v0077 = stack[-2];
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    fn = elt(env, 9); /* make_spoly_pair */
    v0077 = (*qfn2(fn))(qenv(fn), v0198, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    v0198 = v0077;
    v0077 = v0198;
    if (v0077 == nil) goto v0201;
    v0077 = stack[0];
    fn = elt(env, 10); /* find_item */
    v0077 = (*qfn2(fn))(qenv(fn), v0198, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    v0077 = (v0077 == nil ? lisp_true : nil);
    goto v0090;

v0090:
    if (v0077 == nil) goto v0018;
    v0077 = qvalue(elt(env, 4)); /* !*trxideal */
    if (v0077 == nil) goto v0011;
    v0198 = elt(env, 5); /* "criterion 1 hit" */
    v0077 = elt(env, 6); /* last */
    fn = elt(env, 11); /* writepri */
    v0077 = (*qfn2(fn))(qenv(fn), v0198, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    goto v0011;

v0011:
    v0077 = qvalue(elt(env, 3)); /* t */
    goto v0032;

v0032:
    if (!(v0077 == nil)) { popv(5); return onevalue(v0077); }
    v0069 = stack[-2];
    v0077 = stack[-1];
    v0198 = qcdr(v0077);
    v0077 = stack[0];
    stack[-2] = v0069;
    stack[-1] = v0198;
    stack[0] = v0077;
    goto v0055;

v0018:
    v0077 = qvalue(elt(env, 1)); /* nil */
    goto v0032;

v0201:
    v0077 = qvalue(elt(env, 3)); /* t */
    goto v0090;

v0152:
    v0077 = qvalue(elt(env, 1)); /* nil */
    goto v0032;

v0142:
    v0077 = qvalue(elt(env, 3)); /* t */
    goto v0020;

v0189:
    v0077 = qvalue(elt(env, 1)); /* nil */
    goto v0032;

v0009:
    v0077 = qvalue(elt(env, 1)); /* nil */
    goto v0032;

v0199:
    v0077 = qvalue(elt(env, 1)); /* nil */
    goto v0032;

v0075:
    v0077 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0077); }
/* error exit handlers */
v0200:
    popv(5);
    return nil;
}



/* Code for gftimesn */

static Lisp_Object CC_gftimesn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0045, v0202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gftimesn");
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
    v0045 = v0001;
    v0202 = v0000;
/* end of prologue */
    v0046 = v0202;
    v0046 = qcar(v0046);
    if (!consp(v0046)) goto v0061;
    v0046 = v0202;
    v0046 = qcar(v0046);
    stack[-4] = v0046;
    v0046 = v0202;
    v0046 = qcdr(v0046);
    stack[-3] = v0046;
    v0046 = v0045;
    v0046 = qcar(v0046);
    stack[-2] = v0046;
    v0046 = v0045;
    v0046 = qcdr(v0046);
    stack[-1] = v0046;
    v0045 = stack[-4];
    v0046 = stack[-2];
    fn = elt(env, 1); /* times!: */
    stack[0] = (*qfn2(fn))(qenv(fn), v0045, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    v0045 = stack[-3];
    v0046 = stack[-1];
    fn = elt(env, 1); /* times!: */
    v0046 = (*qfn2(fn))(qenv(fn), v0045, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    fn = elt(env, 2); /* difference!: */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    v0045 = stack[-4];
    v0046 = stack[-1];
    fn = elt(env, 1); /* times!: */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0045, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    v0045 = stack[-3];
    v0046 = stack[-2];
    fn = elt(env, 1); /* times!: */
    v0046 = (*qfn2(fn))(qenv(fn), v0045, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    fn = elt(env, 3); /* plus!: */
    v0046 = (*qfn2(fn))(qenv(fn), stack[-1], v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    {
        Lisp_Object v0021 = stack[0];
        popv(6);
        return cons(v0021, v0046);
    }

v0061:
    v0046 = v0202;
    {
        popv(6);
        fn = elt(env, 4); /* gfftimes */
        return (*qfn2(fn))(qenv(fn), v0046, v0045);
    }
/* error exit handlers */
v0182:
    popv(6);
    return nil;
}



/* Code for all_edge */

static Lisp_Object CC_all_edge(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0101, v0145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for all_edge");
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
    v0145 = nil;
    goto v0075;

v0075:
    v0041 = stack[0];
    if (v0041 == nil) goto v0085;
    v0101 = stack[-1];
    v0041 = stack[0];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    if (v0101 == v0041) goto v0102;
    v0041 = stack[0];
    v0041 = qcdr(v0041);
    stack[0] = v0041;
    goto v0075;

v0102:
    v0041 = stack[0];
    v0041 = qcar(v0041);
    v0101 = v0145;
    v0041 = cons(v0041, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-2];
    v0145 = v0041;
    v0041 = stack[0];
    v0041 = qcdr(v0041);
    stack[0] = v0041;
    goto v0075;

v0085:
    v0041 = v0145;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0041);
    }
/* error exit handlers */
v0163:
    popv(3);
    return nil;
}



/* Code for pasf_zcong */

static Lisp_Object CC_pasf_zcong(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0207, v0208, v0209;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_zcong");
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
    v0208 = v0000;
/* end of prologue */
    v0207 = v0208;
    v0207 = Lconsp(nil, v0207);
    env = stack[0];
    if (v0207 == nil) { popv(1); return onevalue(v0208); }
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0207 = Lconsp(nil, v0207);
    env = stack[0];
    if (v0207 == nil) { popv(1); return onevalue(v0208); }
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0209 = qcar(v0207);
    v0207 = elt(env, 1); /* (cong ncong) */
    v0207 = Lmemq(nil, v0209, v0207);
    if (v0207 == nil) { popv(1); return onevalue(v0208); }
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0207 = qcdr(v0207);
    if (v0207 == nil) goto v0124;
    v0207 = v0208;
    v0207 = qcdr(v0207);
    v0207 = qcar(v0207);
    if (v0207 == nil) goto v0156;
    v0207 = qvalue(elt(env, 8)); /* nil */
    goto v0087;

v0087:
    if (v0207 == nil) goto v0094;
    v0207 = elt(env, 2); /* true */
    { popv(1); return onevalue(v0207); }

v0094:
    v0207 = v0208;
    v0207 = qcdr(v0207);
    v0207 = qcar(v0207);
    if (v0207 == nil) goto v0007;
    v0207 = qvalue(elt(env, 8)); /* nil */
    goto v0210;

v0210:
    if (v0207 == nil) { popv(1); return onevalue(v0208); }
    v0207 = elt(env, 4); /* false */
    { popv(1); return onevalue(v0207); }

v0007:
    v0209 = v0208;
    v0207 = elt(env, 2); /* true */
    if (v0209 == v0207) goto v0172;
    v0209 = v0208;
    v0207 = elt(env, 4); /* false */
    v0207 = (v0209 == v0207 ? lisp_true : nil);
    goto v0211;

v0211:
    if (v0207 == nil) goto v0212;
    v0207 = v0208;
    v0209 = v0207;
    goto v0078;

v0078:
    v0207 = elt(env, 9); /* ncong */
    v0207 = (v0209 == v0207 ? lisp_true : nil);
    goto v0210;

v0212:
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0207 = Lconsp(nil, v0207);
    env = stack[0];
    if (v0207 == nil) goto v0213;
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0207 = qcar(v0207);
    v0209 = v0207;
    goto v0078;

v0213:
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0209 = v0207;
    goto v0078;

v0172:
    v0207 = qvalue(elt(env, 3)); /* t */
    goto v0211;

v0156:
    v0209 = v0208;
    v0207 = elt(env, 2); /* true */
    if (v0209 == v0207) goto v0047;
    v0209 = v0208;
    v0207 = elt(env, 4); /* false */
    v0207 = (v0209 == v0207 ? lisp_true : nil);
    goto v0214;

v0214:
    if (v0207 == nil) goto v0018;
    v0207 = v0208;
    v0209 = v0207;
    goto v0215;

v0215:
    v0207 = elt(env, 5); /* cong */
    v0207 = (v0209 == v0207 ? lisp_true : nil);
    goto v0087;

v0018:
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0207 = Lconsp(nil, v0207);
    env = stack[0];
    if (v0207 == nil) goto v0216;
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0207 = qcar(v0207);
    v0209 = v0207;
    goto v0215;

v0216:
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0209 = v0207;
    goto v0215;

v0047:
    v0207 = qvalue(elt(env, 3)); /* t */
    goto v0214;

v0124:
    v0209 = v0208;
    v0207 = elt(env, 2); /* true */
    if (v0209 == v0207) goto v0097;
    v0209 = v0208;
    v0207 = elt(env, 4); /* false */
    v0207 = (v0209 == v0207 ? lisp_true : nil);
    goto v0148;

v0148:
    if (v0207 == nil) goto v0040;
    v0207 = v0208;
    v0209 = v0207;
    goto v0119;

v0119:
    v0207 = elt(env, 5); /* cong */
    if (v0209 == v0207) goto v0145;
    v0207 = elt(env, 7); /* neq */
    goto v0127;

v0127:
    v0208 = qcdr(v0208);
    v0208 = qcar(v0208);
    v0209 = qvalue(elt(env, 8)); /* nil */
    popv(1);
    return list3(v0207, v0208, v0209);

v0145:
    v0207 = elt(env, 6); /* equal */
    goto v0127;

v0040:
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0207 = Lconsp(nil, v0207);
    env = stack[0];
    if (v0207 == nil) goto v0045;
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0207 = qcar(v0207);
    v0209 = v0207;
    goto v0119;

v0045:
    v0207 = v0208;
    v0207 = qcar(v0207);
    v0209 = v0207;
    goto v0119;

v0097:
    v0207 = qvalue(elt(env, 3)); /* t */
    goto v0148;
}



/* Code for aex_subrp */

static Lisp_Object MS_CDECL CC_aex_subrp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131, v0032, v0033;
    Lisp_Object fn;
    Lisp_Object v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_subrp");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_subrp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0080,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0080;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0131 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v0033 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0032 = stack[-1];
    v0131 = stack[0];
    fn = elt(env, 3); /* ratpoly_subrp */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0033, v0032, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0131 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v0033 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0032 = qvalue(elt(env, 1)); /* nil */
    v0131 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0121 = stack[0];
        popv(4);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0121, v0033, v0032, v0131);
    }
/* error exit handlers */
v0123:
    popv(4);
    return nil;
}



/* Code for get!-height */

static Lisp_Object CC_getKheight(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-height");
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
    v0117 = stack[0];
    if (v0117 == nil) goto v0056;
    v0117 = stack[0];
    if (is_number(v0117)) goto v0003;
    v0117 = stack[0];
    v0117 = qcar(v0117);
    v0117 = qcdr(v0117);
    stack[-1] = CC_getKheight(env, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    v0117 = CC_getKheight(env, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    {
        Lisp_Object v0033 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* max */
        return (*qfn2(fn))(qenv(fn), v0033, v0117);
    }

v0003:
    v0117 = stack[0];
        popv(3);
        return Labsval(nil, v0117);

v0056:
    v0117 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0117); }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for relnrd */

static Lisp_Object MS_CDECL CC_relnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0189, v0192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "relnrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for relnrd");
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
    stack[0] = nil;
    fn = elt(env, 5); /* lex */
    v0189 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0189 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v0192 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0189 = qvalue(elt(env, 2)); /* rdreln!* */
    v0192 = Lassoc(nil, v0192, v0189);
    v0189 = v0192;
    if (v0192 == nil) goto v0126;
    v0192 = v0189;
    v0192 = qcdr(v0192);
    v0192 = qcar(v0192);
    v0189 = qcdr(v0189);
    v0189 = qcdr(v0189);
    fn = elt(env, 7); /* apply */
    v0189 = (*qfn2(fn))(qenv(fn), v0192, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    stack[0] = v0189;
    goto v0119;

v0119:
    v0192 = stack[0];
    v0189 = qvalue(elt(env, 3)); /* t */
    if (equal(v0192, v0189)) goto v0132;
    v0189 = stack[0];
    if (!(v0189 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0189 = elt(env, 4); /* false */
    { popv(2); return onevalue(v0189); }

v0132:
    v0189 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v0189); }

v0126:
    v0189 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v0192 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0189 = (Lisp_Object)289; /* 18 */
    fn = elt(env, 8); /* errorml */
    v0189 = (*qfn2(fn))(qenv(fn), v0192, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    goto v0119;
/* error exit handlers */
v0100:
    popv(2);
    return nil;
}



/* Code for multdf */

static Lisp_Object CC_multdf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0150, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multdf");
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
    v0150 = stack[-1];
    if (v0150 == nil) goto v0085;
    v0150 = stack[0];
    v0150 = (v0150 == nil ? lisp_true : nil);
    goto v0003;

v0003:
    if (v0150 == nil) goto v0125;
    v0150 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0150); }

v0125:
    v0150 = stack[-1];
    v0023 = qcar(v0150);
    v0150 = stack[0];
    v0150 = qcar(v0150);
    fn = elt(env, 3); /* multerm */
    v0150 = (*qfn2(fn))(qenv(fn), v0023, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    stack[-2] = v0150;
    v0150 = stack[-1];
    v0023 = qcdr(v0150);
    v0150 = stack[0];
    v0150 = CC_multdf(env, v0023, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    fn = elt(env, 4); /* plusdf */
    v0150 = (*qfn2(fn))(qenv(fn), stack[-2], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    stack[-2] = v0150;
    v0150 = stack[-1];
    v0150 = qcar(v0150);
    v0023 = ncons(v0150);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    v0150 = stack[0];
    v0150 = qcdr(v0150);
    v0150 = CC_multdf(env, v0023, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    {
        Lisp_Object v0190 = stack[-2];
        popv(4);
        fn = elt(env, 4); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v0190, v0150);
    }

v0085:
    v0150 = qvalue(elt(env, 1)); /* t */
    goto v0003;
/* error exit handlers */
v0139:
    popv(4);
    return nil;
}



/* Code for derad */

static Lisp_Object CC_derad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0166, v0167, v0217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for derad");
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
    goto v0075;

v0075:
    v0166 = stack[0];
    if (v0166 == nil) goto v0039;
    v0166 = stack[0];
    v0166 = qcar(v0166);
    if (is_number(v0166)) goto v0102;
    v0167 = stack[-1];
    v0166 = stack[0];
    v0166 = qcar(v0166);
    if (equal(v0167, v0166)) goto v0123;
    v0167 = stack[-1];
    v0166 = stack[0];
    v0166 = qcar(v0166);
    fn = elt(env, 1); /* ordp */
    v0166 = (*qfn2(fn))(qenv(fn), v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    if (v0166 == nil) goto v0090;
    v0167 = stack[-1];
    v0166 = stack[0];
    v0166 = cons(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    {
        Lisp_Object v0168 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0168, v0166);
    }

v0090:
    v0166 = stack[0];
    v0167 = qcar(v0166);
    v0166 = stack[-2];
    v0166 = cons(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    stack[-2] = v0166;
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    stack[0] = v0166;
    goto v0075;

v0123:
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    if (v0166 == nil) goto v0141;
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    if (!(is_number(v0166))) goto v0141;
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    v0167 = add1(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    v0166 = qcdr(v0166);
    v0166 = list2star(stack[-1], v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    {
        Lisp_Object v0173 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0173, v0166);
    }

v0141:
    v0217 = stack[-1];
    v0167 = (Lisp_Object)33; /* 2 */
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    v0166 = list2star(v0217, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    {
        Lisp_Object v0218 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0218, v0166);
    }

v0102:
    v0166 = stack[0];
    v0167 = qcar(v0166);
    v0166 = stack[-2];
    v0166 = cons(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    stack[-2] = v0166;
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    stack[0] = v0166;
    goto v0075;

v0039:
    stack[0] = stack[-2];
    v0166 = stack[-1];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    {
        Lisp_Object v0011 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0011, v0166);
    }
/* error exit handlers */
v0216:
    popv(4);
    return nil;
}



/* Code for chkint!* */

static Lisp_Object CC_chkintH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0215, v0137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chkint*");
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
    v0144 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v0144 == nil) goto v0170;
    v0144 = stack[0];
    v0144 = Lfloatp(nil, v0144);
    env = stack[-1];
    if (v0144 == nil) goto v0138;
    v0144 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0138:
    v0144 = stack[0];
    if (!consp(v0144)) goto v0140;
    v0144 = stack[0];
    goto v0053;

v0053:
    {
        popv(2);
        fn = elt(env, 5); /* normbf */
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0140:
    v0144 = stack[0];
    v0144 = integerp(v0144);
    if (v0144 == nil) goto v0026;
    v0137 = elt(env, 2); /* !:rd!: */
    v0215 = stack[0];
    v0144 = (Lisp_Object)1; /* 0 */
    v0144 = list2star(v0137, v0215, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    goto v0053;

v0026:
    v0144 = stack[0];
    fn = elt(env, 6); /* read!:num */
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    goto v0053;

v0170:
    v0144 = stack[0];
    v0144 = Labsval(nil, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0215 = v0144;
    v0144 = stack[0];
    v0144 = Lfloatp(nil, v0144);
    env = stack[-1];
    if (!(v0144 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0144 = v0215;
    fn = elt(env, 7); /* msd */
    v0215 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0144 = qvalue(elt(env, 3)); /* !!maxbflexp */
    v0144 = (Lisp_Object)lesseq2(v0215, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    v0144 = v0144 ? lisp_true : nil;
    env = stack[-1];
    if (v0144 == nil) goto v0150;
    v0144 = stack[0];
        popv(2);
        return Lfloat(nil, v0144);

v0150:
    fn = elt(env, 8); /* rndbfon */
    v0144 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0144 = stack[0];
    v0144 = Lfloatp(nil, v0144);
    env = stack[-1];
    if (v0144 == nil) goto v0153;
    v0144 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0153:
    v0144 = stack[0];
    if (!consp(v0144)) goto v0202;
    v0144 = stack[0];
    goto v0046;

v0046:
    {
        popv(2);
        fn = elt(env, 5); /* normbf */
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0202:
    v0144 = stack[0];
    v0144 = integerp(v0144);
    if (v0144 == nil) goto v0161;
    v0137 = elt(env, 2); /* !:rd!: */
    v0215 = stack[0];
    v0144 = (Lisp_Object)1; /* 0 */
    v0144 = list2star(v0137, v0215, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    goto v0046;

v0161:
    v0144 = stack[0];
    fn = elt(env, 6); /* read!:num */
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    goto v0046;
/* error exit handlers */
v0092:
    popv(2);
    return nil;
}



/* Code for actual_alst */

static Lisp_Object CC_actual_alst(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0145, v0170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for actual_alst");
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
    v0170 = nil;
    goto v0075;

v0075:
    v0101 = stack[-1];
    if (v0101 == nil) goto v0085;
    v0101 = stack[-1];
    v0101 = qcar(v0101);
    v0145 = qcar(v0101);
    v0101 = stack[0];
    v0101 = Lmemq(nil, v0145, v0101);
    if (v0101 == nil) goto v0121;
    v0101 = stack[-1];
    v0101 = qcar(v0101);
    v0145 = v0170;
    v0101 = cons(v0101, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    v0170 = v0101;
    v0101 = stack[-1];
    v0101 = qcdr(v0101);
    stack[-1] = v0101;
    goto v0075;

v0121:
    v0101 = stack[-1];
    v0101 = qcdr(v0101);
    stack[-1] = v0101;
    goto v0075;

v0085:
    v0101 = v0170;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0101);
    }
/* error exit handlers */
v0119:
    popv(3);
    return nil;
}



/* Code for quotpri */

static Lisp_Object CC_quotpri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0027, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotpri");
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
    v0027 = v0000;
/* end of prologue */
    stack[0] = nil;
    v0124 = qvalue(elt(env, 1)); /* !*ratpri */
    if (v0124 == nil) goto v0086;
    v0124 = qvalue(elt(env, 3)); /* !*nat */
    if (v0124 == nil) goto v0053;
    v0124 = qvalue(elt(env, 4)); /* !*fort */
    if (!(v0124 == nil)) goto v0061;
    v0124 = qvalue(elt(env, 5)); /* !*list */
    if (!(v0124 == nil)) goto v0061;
    v0124 = qvalue(elt(env, 6)); /* !*mcd */
    v0124 = (v0124 == nil ? lisp_true : nil);
    goto v0061;

v0061:
    if (v0124 == nil) goto v0026;
    v0124 = elt(env, 7); /* failed */
    { popv(2); return onevalue(v0124); }

v0026:
    v0028 = qvalue(elt(env, 8)); /* dmode!* */
    v0124 = elt(env, 9); /* ratmode */
    v0124 = Lflagp(nil, v0028, v0124);
    env = stack[-1];
    if (v0124 == nil) goto v0075;
    v0124 = qvalue(elt(env, 8)); /* dmode!* */
    stack[0] = v0124;
    v0124 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 8)) = v0124; /* dmode!* */
    goto v0075;

v0075:
    v0124 = v0027;
    fn = elt(env, 11); /* ratfunpri1 */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-1];
    v0027 = v0124;
    v0124 = stack[0];
    if (v0124 == nil) { popv(2); return onevalue(v0027); }
    v0124 = stack[0];
    qvalue(elt(env, 8)) = v0124; /* dmode!* */
    { popv(2); return onevalue(v0027); }

v0053:
    v0124 = qvalue(elt(env, 2)); /* t */
    goto v0061;

v0086:
    v0124 = qvalue(elt(env, 2)); /* t */
    goto v0061;
/* error exit handlers */
v0189:
    popv(2);
    return nil;
}



/* Code for reduce!-mod!-p!* */

static Lisp_Object CC_reduceKmodKpH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-p*");
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
    v0002 = v0001;
    v0003 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* current!-modulus */
    qvalue(elt(env, 1)) = v0002; /* current!-modulus */
    v0002 = v0003;
    fn = elt(env, 2); /* general!-reduce!-mod!-p */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* current!-modulus */
    { popv(2); return onevalue(v0002); }
/* error exit handlers */
v0061:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* current!-modulus */
    popv(2);
    return nil;
}



/* Code for cl_susiupdknowl */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0206, v0100, v0098, v0099;
    Lisp_Object fn;
    Lisp_Object v0068, v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    v0068 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0068,v0080,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0080,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0068;
    v0206 = v0080;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0061;

v0061:
    v0100 = stack[-1];
    if (v0100 == nil) goto v0040;
    v0100 = stack[-1];
    v0100 = qcar(v0100);
    stack[-3] = v0100;
    v0100 = stack[-1];
    v0100 = qcdr(v0100);
    stack[-1] = v0100;
    v0099 = stack[-2];
    v0098 = stack[-3];
    v0100 = v0206;
    v0206 = stack[0];
    fn = elt(env, 4); /* cl_susiupdknowl1 */
    v0206 = (*qfnn(fn))(qenv(fn), 4, v0099, v0098, v0100, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    v0098 = v0206;
    v0100 = elt(env, 2); /* false */
    if (!(v0098 == v0100)) goto v0061;
    v0100 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0100;
    v0100 = elt(env, 3); /* break */
    stack[-3] = v0100;
    goto v0061;

v0040:
    v0098 = stack[-3];
    v0100 = elt(env, 3); /* break */
    if (!(v0098 == v0100)) { popv(5); return onevalue(v0206); }
    v0206 = elt(env, 2); /* false */
    { popv(5); return onevalue(v0206); }
/* error exit handlers */
v0151:
    popv(5);
    return nil;
}



/* Code for sfto_b!:extmult */

static Lisp_Object CC_sfto_bTextmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0216, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_b:extmult");
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
    v0216 = stack[-3];
    if (v0216 == nil) goto v0085;
    v0216 = stack[-2];
    v0216 = (v0216 == nil ? lisp_true : nil);
    goto v0003;

v0003:
    if (v0216 == nil) goto v0054;
    v0216 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0216); }

v0054:
    v0168 = stack[-2];
    v0216 = (Lisp_Object)17; /* 1 */
    if (v0168 == v0216) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0216 = stack[-3];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0168 = qcar(v0216);
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    fn = elt(env, 3); /* sfto_b!:ordexn */
    v0216 = (*qfn2(fn))(qenv(fn), v0168, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    v0168 = v0216;
    v0216 = v0168;
    if (v0216 == nil) goto v0197;
    v0216 = v0168;
    stack[-4] = qcdr(v0216);
    v0216 = v0168;
    v0216 = qcar(v0216);
    if (v0216 == nil) goto v0162;
    v0216 = stack[-3];
    v0216 = qcar(v0216);
    v0168 = qcdr(v0216);
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = qcdr(v0216);
    fn = elt(env, 4); /* multf */
    v0216 = (*qfn2(fn))(qenv(fn), v0168, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    fn = elt(env, 5); /* negf */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    stack[-1] = v0216;
    goto v0187;

v0187:
    v0216 = stack[-3];
    v0216 = qcar(v0216);
    v0168 = ncons(v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    v0216 = stack[-2];
    v0216 = qcdr(v0216);
    stack[0] = CC_sfto_bTextmult(env, v0168, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    v0216 = stack[-3];
    v0168 = qcdr(v0216);
    v0216 = stack[-2];
    v0216 = CC_sfto_bTextmult(env, v0168, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    fn = elt(env, 6); /* sfto_b!:extadd */
    v0216 = (*qfn2(fn))(qenv(fn), stack[0], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    {
        Lisp_Object v0221 = stack[-4];
        Lisp_Object v0081 = stack[-1];
        popv(6);
        return acons(v0221, v0081, v0216);
    }

v0162:
    v0216 = stack[-3];
    v0216 = qcar(v0216);
    v0168 = qcdr(v0216);
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = qcdr(v0216);
    fn = elt(env, 4); /* multf */
    v0216 = (*qfn2(fn))(qenv(fn), v0168, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    stack[-1] = v0216;
    goto v0187;

v0197:
    v0216 = stack[-3];
    v0168 = qcdr(v0216);
    v0216 = stack[-2];
    stack[0] = CC_sfto_bTextmult(env, v0168, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    v0216 = stack[-3];
    v0216 = qcar(v0216);
    v0168 = ncons(v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    v0216 = stack[-2];
    v0216 = qcdr(v0216);
    v0216 = CC_sfto_bTextmult(env, v0168, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-5];
    {
        Lisp_Object v0082 = stack[0];
        popv(6);
        fn = elt(env, 6); /* sfto_b!:extadd */
        return (*qfn2(fn))(qenv(fn), v0082, v0216);
    }

v0085:
    v0216 = qvalue(elt(env, 1)); /* t */
    goto v0003;
/* error exit handlers */
v0083:
    popv(6);
    return nil;
}



/* Code for ps!:evaluate!-next */

static Lisp_Object CC_psTevaluateKnext(Lisp_Object env,
                         Lisp_Object v0001, Lisp_Object v0080)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:evaluate-next");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0080,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0080;
    v0095 = v0001;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v0095; /* ps */
    v0124 = qvalue(elt(env, 1)); /* ps */
    v0095 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 3); /* ps!:getv */
    v0095 = (*qfn2(fn))(qenv(fn), v0124, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0124 = qcar(v0095);
    v0095 = elt(env, 2); /* ps!:erule */
    stack[0] = get(v0124, v0095);
    env = stack[-4];
    v0095 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:expression */
    v0124 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0095 = stack[-2];
    v0095 = list2(v0124, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    fn = elt(env, 5); /* apply */
    v0095 = (*qfn2(fn))(qenv(fn), stack[0], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-1] = v0095;
    stack[0] = qvalue(elt(env, 1)); /* ps */
    v0095 = stack[-1];
    fn = elt(env, 6); /* prepsqxx */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    fn = elt(env, 7); /* simp!* */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-1] = v0095;
    fn = elt(env, 8); /* ps!:set!-term */
    v0095 = (*qfnn(fn))(qenv(fn), 3, stack[0], stack[-2], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0095 = stack[-1];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v0095); }
/* error exit handlers */
v0192:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for crprimp */

static Lisp_Object CC_crprimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0163, v0119;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crprimp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0119 = v0000;
/* end of prologue */
    v0163 = v0119;
    v0132 = (Lisp_Object)17; /* 1 */
    if (v0163 == v0132) goto v0056;
    v0163 = v0119;
    v0132 = (Lisp_Object)-15; /* -1 */
    if (v0163 == v0132) goto v0125;
    v0132 = elt(env, 3); /* times */
    v0163 = v0119;
    v0119 = elt(env, 1); /* i */
    return list3(v0132, v0163, v0119);

v0125:
    v0132 = elt(env, 2); /* minus */
    v0163 = elt(env, 1); /* i */
    return list2(v0132, v0163);

v0056:
    v0132 = elt(env, 1); /* i */
    return onevalue(v0132);
}



/* Code for ft!:zerop */

static Lisp_Object CC_ftTzerop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170, v0132;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ft:zerop");
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
    v0170 = v0000;
/* end of prologue */
    stack[0] = v0170;
    v0132 = (Lisp_Object)161; /* 10 */
    v0170 = qvalue(elt(env, 1)); /* !:prec!: */
    v0170 = Lexpt(nil, v0132, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-1];
    v0170 = times2(stack[0], v0170);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-1];
    stack[0] = v0170;
    v0132 = stack[0];
    v0170 = (Lisp_Object)-799; /* -50 */
    v0170 = (Lisp_Object)greaterp2(v0132, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    v0170 = v0170 ? lisp_true : nil;
    env = stack[-1];
    if (v0170 == nil) goto v0035;
    v0132 = stack[0];
    v0170 = (Lisp_Object)801; /* 50 */
        popv(2);
        return Llessp(nil, v0132, v0170);

v0035:
    v0170 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0170); }
/* error exit handlers */
v0119:
    popv(2);
    return nil;
}



/* Code for !:dmtimeslst */

static Lisp_Object CC_Tdmtimeslst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :dmtimeslst");
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
    v0117 = v0000;
/* end of prologue */
    v0118 = v0117;
    if (v0118 == nil) goto v0056;
    v0118 = v0117;
    v0118 = qcdr(v0118);
    if (v0118 == nil) goto v0003;
    v0118 = v0117;
    stack[0] = qcar(v0118);
    v0118 = v0117;
    v0118 = qcdr(v0118);
    v0118 = CC_Tdmtimeslst(env, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    {
        Lisp_Object v0032 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:times */
        return (*qfn2(fn))(qenv(fn), v0032, v0118);
    }

v0003:
    v0118 = v0117;
    v0118 = qcar(v0118);
    { popv(2); return onevalue(v0118); }

v0056:
    v0118 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0118); }
/* error exit handlers */
v0131:
    popv(2);
    return nil;
}



/* Code for formde */

static Lisp_Object MS_CDECL CC_formde(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0022, v0151;
    Lisp_Object fn;
    Lisp_Object v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formde");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formde");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0080,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0080;
    stack[-5] = v0001;
    v0023 = v0000;
/* end of prologue */
    stack[-6] = elt(env, 1); /* procedure */
    v0022 = v0023;
    v0022 = qcdr(v0022);
    stack[-3] = qcar(v0022);
    stack[-2] = elt(env, 2); /* symbolic */
    stack[-1] = elt(env, 3); /* expr */
    v0022 = v0023;
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    stack[0] = qcar(v0022);
    v0022 = v0023;
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    if (v0022 == nil) goto v0145;
    v0022 = elt(env, 4); /* progn */
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = cons(v0022, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-7];
    goto v0129;

v0129:
    v0023 = list3(stack[-1], stack[0], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-7];
    v0151 = list3star(stack[-6], stack[-3], stack[-2], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-7];
    v0022 = stack[-5];
    v0023 = stack[-4];
    {
        popv(8);
        fn = elt(env, 5); /* formproc */
        return (*qfnn(fn))(qenv(fn), 3, v0151, v0022, v0023);
    }

v0145:
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    goto v0129;
/* error exit handlers */
v0153:
    popv(8);
    return nil;
}



/* Code for mv!-domainlist */

static Lisp_Object CC_mvKdomainlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-domainlist");
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
    v0117 = nil;
    goto v0128;

v0128:
    v0118 = stack[0];
    if (v0118 == nil) goto v0003;
    v0118 = stack[0];
    v0118 = qcar(v0118);
    v0118 = qcdr(v0118);
    v0118 = cons(v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0117 = v0118;
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    stack[0] = v0118;
    goto v0128;

v0003:
    v0118 = v0117;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0118);
    }
/* error exit handlers */
v0131:
    popv(2);
    return nil;
}



/* Code for dv_ind2var */

static Lisp_Object CC_dv_ind2var(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_ind2var");
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
    stack[-1] = stack[0];
    v0126 = qvalue(elt(env, 1)); /* g_dvnames */
    fn = elt(env, 3); /* upbve */
    v0126 = (*qfn1(fn))(qenv(fn), v0126);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    v0126 = (Lisp_Object)lesseq2(stack[-1], v0126);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    v0126 = v0126 ? lisp_true : nil;
    env = stack[-2];
    if (v0126 == nil) goto v0118;
    stack[-1] = qvalue(elt(env, 1)); /* g_dvnames */
    v0126 = stack[0];
    v0126 = sub1(v0126);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    v0126 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0126/(16/CELL)));
    { popv(3); return onevalue(v0126); }

v0118:
    v0127 = qvalue(elt(env, 2)); /* g_dvbase */
    v0126 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v0127, v0126);
    }
/* error exit handlers */
v0122:
    popv(3);
    return nil;
}



/* Code for !:expt */

static Lisp_Object CC_Texpt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0225, v0226, v0227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :expt");
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
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */
    v0225 = stack[-4];
    if (v0225 == nil) goto v0031;
    v0226 = stack[-3];
    v0225 = (Lisp_Object)1; /* 0 */
    if (v0226 == v0225) goto v0129;
    v0226 = stack[-3];
    v0225 = (Lisp_Object)17; /* 1 */
    if (v0226 == v0225) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0226 = stack[-4];
    v0225 = (Lisp_Object)17; /* 1 */
    if (v0226 == v0225) goto v0135;
    v0226 = stack[-3];
    v0225 = (Lisp_Object)1; /* 0 */
    v0225 = (Lisp_Object)lessp2(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-6];
    if (v0225 == nil) goto v0100;
    v0225 = stack[-4];
    fn = elt(env, 5); /* fieldp */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    if (v0225 == nil) goto v0019;
    v0225 = stack[-4];
    stack[0] = v0225;
    goto v0025;

v0025:
    v0225 = stack[-3];
    v0225 = negate(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    v0225 = CC_Texpt(env, stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 6); /* !:recip */
        return (*qfn1(fn))(qenv(fn), v0225);
    }

v0019:
    v0225 = stack[-4];
    fn = elt(env, 7); /* mkratnum */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    stack[0] = v0225;
    goto v0025;

v0100:
    v0225 = stack[-4];
    if (!consp(v0225)) goto v0093;
    v0225 = stack[-4];
    v0226 = qcar(v0225);
    v0225 = elt(env, 4); /* expt */
    v0225 = get(v0226, v0225);
    env = stack[-6];
    stack[-2] = v0225;
    if (v0225 == nil) goto v0012;
    v0227 = stack[-2];
    v0226 = stack[-4];
    v0225 = stack[-3];
        popv(7);
        return Lapply2(nil, 3, v0227, v0226, v0225);

v0012:
    v0225 = stack[-4];
    v0225 = qcar(v0225);
    if (!symbolp(v0225)) v0226 = nil;
    else { v0226 = qfastgets(v0225);
           if (v0226 != nil) { v0226 = elt(v0226, 34); /* i2d */
#ifdef RECORD_GET
             if (v0226 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0226 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0226 == SPID_NOPROP) v0226 = nil; }}
#endif
    v0225 = (Lisp_Object)17; /* 1 */
    v0225 = Lapply1(nil, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    stack[-5] = v0225;
    v0225 = stack[-4];
    v0225 = qcar(v0225);
    if (!symbolp(v0225)) v0225 = nil;
    else { v0225 = qfastgets(v0225);
           if (v0225 != nil) { v0225 = elt(v0225, 54); /* times */
#ifdef RECORD_GET
             if (v0225 != SPID_NOPROP)
                record_get(elt(fastget_names, 54), 1);
             else record_get(elt(fastget_names, 54), 0),
                v0225 = nil; }
           else record_get(elt(fastget_names, 54), 0); }
#else
             if (v0225 == SPID_NOPROP) v0225 = nil; }}
#endif
    stack[-2] = v0225;
    goto v0092;

v0092:
    v0225 = stack[-3];
    stack[-1] = v0225;
    stack[0] = (Lisp_Object)33; /* 2 */
    v0226 = stack[-3];
    v0225 = (Lisp_Object)33; /* 2 */
    v0225 = quot2(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    stack[-3] = v0225;
    v0225 = times2(stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    v0226 = difference2(stack[-1], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    v0225 = (Lisp_Object)1; /* 0 */
    if (v0226 == v0225) goto v0116;
    v0227 = stack[-2];
    v0226 = stack[-4];
    v0225 = stack[-5];
    v0225 = Lapply2(nil, 3, v0227, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    stack[-5] = v0225;
    goto v0116;

v0116:
    v0226 = stack[-3];
    v0225 = (Lisp_Object)1; /* 0 */
    if (v0226 == v0225) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v0227 = stack[-2];
    v0226 = stack[-4];
    v0225 = stack[-4];
    v0225 = Lapply2(nil, 3, v0227, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-6];
    stack[-4] = v0225;
    goto v0092;

v0093:
    v0226 = stack[-4];
    v0225 = stack[-3];
        popv(7);
        return Lexpt(nil, v0226, v0225);

v0135:
    v0225 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v0225); }

v0129:
    v0225 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v0225); }

v0031:
    v0226 = stack[-3];
    v0225 = (Lisp_Object)1; /* 0 */
    if (v0226 == v0225) goto v0054;
    v0225 = qvalue(elt(env, 3)); /* nil */
    { popv(7); return onevalue(v0225); }

v0054:
    v0227 = elt(env, 1); /* poly */
    v0226 = (Lisp_Object)177; /* 11 */
    v0225 = elt(env, 2); /* "0/0 formed" */
    {
        popv(7);
        fn = elt(env, 8); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0227, v0226, v0225);
    }
/* error exit handlers */
v0228:
    popv(7);
    return nil;
}



/* Code for bndtst */

static Lisp_Object CC_bndtst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bndtst");
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
    v0086 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* abs!: */
    v0031 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[0];
    v0086 = qvalue(elt(env, 1)); /* tentothetenth!*!* */
    {
        popv(1);
        fn = elt(env, 3); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v0031, v0086);
    }
/* error exit handlers */
v0039:
    popv(1);
    return nil;
}



/* Code for n_nary */

static Lisp_Object CC_n_nary(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for n_nary");
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
    v0151 = stack[-1];
    v0112 = qcar(v0151);
    v0151 = elt(env, 1); /* e */
    if (v0112 == v0151) goto v0140;
    v0151 = qvalue(elt(env, 3)); /* nil */
    goto v0061;

v0061:
    if (v0151 == nil) goto v0101;
    v0151 = stack[-1];
    v0112 = qcdr(v0151);
    v0151 = elt(env, 4); /* exp */
    fn = elt(env, 10); /* unary */
    v0151 = (*qfn2(fn))(qenv(fn), v0112, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    goto v0075;

v0075:
    v0151 = nil;
    { popv(3); return onevalue(v0151); }

v0101:
    v0151 = elt(env, 5); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    v0151 = elt(env, 6); /* "<" */
    v0151 = Lprinc(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    v0151 = stack[0];
    v0151 = Lprinc(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    v0151 = elt(env, 7); /* "/>" */
    v0151 = Lprinc(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    v0112 = qvalue(elt(env, 8)); /* indent */
    v0151 = (Lisp_Object)49; /* 3 */
    v0151 = plus2(v0112, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0151; /* indent */
    v0151 = stack[-1];
    fn = elt(env, 12); /* multi_elem */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    v0112 = qvalue(elt(env, 8)); /* indent */
    v0151 = (Lisp_Object)49; /* 3 */
    v0151 = difference2(v0112, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0151; /* indent */
    v0151 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    goto v0075;

v0140:
    v0112 = stack[0];
    v0151 = elt(env, 2); /* power */
    v0151 = (v0112 == v0151 ? lisp_true : nil);
    goto v0061;
/* error exit handlers */
v0191:
    popv(3);
    return nil;
}



/* Code for recaliasbacksubst */

static Lisp_Object CC_recaliasbacksubst(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for recaliasbacksubst");
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
    stack[-3] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0093 = stack[0];
    if (!consp(v0093)) goto v0085;
    v0093 = stack[0];
    fn = elt(env, 3); /* constp */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-5];
    goto v0003;

v0003:
    if (v0093 == nil) goto v0101;
    v0094 = stack[0];
    v0093 = stack[-3];
    v0093 = Lassoc(nil, v0094, v0093);
    if (v0093 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0094 = stack[0];
    v0093 = stack[-3];
    v0093 = Lassoc(nil, v0094, v0093);
    v0093 = qcdr(v0093);
    { popv(6); return onevalue(v0093); }

v0101:
    v0093 = stack[0];
    stack[-4] = v0093;
    v0093 = stack[-4];
    if (v0093 == nil) goto v0040;
    v0093 = stack[-4];
    v0093 = qcar(v0093);
    v0094 = v0093;
    v0093 = stack[-3];
    v0093 = CC_recaliasbacksubst(env, v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-5];
    v0093 = ncons(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-5];
    stack[-1] = v0093;
    stack[-2] = v0093;
    goto v0110;

v0110:
    v0093 = stack[-4];
    v0093 = qcdr(v0093);
    stack[-4] = v0093;
    v0093 = stack[-4];
    if (v0093 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0093 = stack[-4];
    v0093 = qcar(v0093);
    v0094 = v0093;
    v0093 = stack[-3];
    v0093 = CC_recaliasbacksubst(env, v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-5];
    v0093 = ncons(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-5];
    v0093 = Lrplacd(nil, stack[0], v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-5];
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    goto v0110;

v0040:
    v0093 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0093); }

v0085:
    v0093 = qvalue(elt(env, 1)); /* t */
    goto v0003;
/* error exit handlers */
v0014:
    popv(6);
    return nil;
}



/* Code for make!-unique!-freevars */

static Lisp_Object CC_makeKuniqueKfreevars(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0088, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-unique-freevars");
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
    v0088 = v0000;
/* end of prologue */
    v0186 = v0088;
    if (!consp(v0186)) goto v0031;
    v0186 = v0088;
    stack[-3] = v0186;
    v0186 = stack[-3];
    if (v0186 == nil) goto v0153;
    v0186 = stack[-3];
    v0186 = qcar(v0186);
    v0186 = CC_makeKuniqueKfreevars(env, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0186 = ncons(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    stack[-1] = v0186;
    stack[-2] = v0186;
    goto v0191;

v0191:
    v0186 = stack[-3];
    v0186 = qcdr(v0186);
    stack[-3] = v0186;
    v0186 = stack[-3];
    if (v0186 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0186 = stack[-3];
    v0186 = qcar(v0186);
    v0186 = CC_makeKuniqueKfreevars(env, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0186 = ncons(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0186 = Lrplacd(nil, stack[0], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[-1] = v0186;
    goto v0191;

v0153:
    v0186 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v0186); }

v0031:
    v0018 = v0088;
    v0186 = elt(env, 1); /* gen */
    v0186 = get(v0018, v0186);
    env = stack[-4];
    if (v0186 == nil) { popv(5); return onevalue(v0088); }
    v0018 = v0088;
    v0186 = qvalue(elt(env, 2)); /* freevarlist!* */
    v0186 = Latsoc(nil, v0018, v0186);
    stack[0] = v0186;
    v0186 = stack[0];
    if (!(v0186 == nil)) goto v0032;
    stack[0] = v0088;
    fn = elt(env, 5); /* pm!:gensym */
    v0186 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0186 = cons(stack[0], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    stack[0] = v0186;
    v0186 = stack[0];
    v0018 = qcdr(v0186);
    v0088 = elt(env, 1); /* gen */
    v0186 = qvalue(elt(env, 3)); /* t */
    v0186 = Lputprop(nil, 3, v0018, v0088, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0088 = stack[0];
    v0186 = qvalue(elt(env, 2)); /* freevarlist!* */
    v0186 = cons(v0088, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0186; /* freevarlist!* */
    goto v0032;

v0032:
    v0186 = stack[0];
    v0186 = qcdr(v0186);
    { popv(5); return onevalue(v0186); }
/* error exit handlers */
v0156:
    popv(5);
    return nil;
}



/* Code for noncomexpf */

static Lisp_Object CC_noncomexpf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomexpf");
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

v0055:
    v0122 = stack[0];
    if (!consp(v0122)) goto v0003;
    v0122 = stack[0];
    v0122 = qcar(v0122);
    v0122 = (consp(v0122) ? nil : lisp_true);
    goto v0002;

v0002:
    if (v0122 == nil) goto v0056;
    v0122 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0122); }

v0056:
    v0122 = stack[0];
    v0122 = qcar(v0122);
    v0122 = qcar(v0122);
    v0122 = qcar(v0122);
    fn = elt(env, 3); /* noncomp */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    if (!(v0122 == nil)) { popv(2); return onevalue(v0122); }
    v0122 = stack[0];
    v0122 = qcar(v0122);
    v0122 = qcdr(v0122);
    v0122 = CC_noncomexpf(env, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    if (!(v0122 == nil)) { popv(2); return onevalue(v0122); }
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    stack[0] = v0122;
    goto v0055;

v0003:
    v0122 = qvalue(elt(env, 1)); /* t */
    goto v0002;
/* error exit handlers */
v0041:
    popv(2);
    return nil;
}



/* Code for my_letmtr */

static Lisp_Object MS_CDECL CC_my_letmtr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0082, v0229;
    Lisp_Object fn;
    Lisp_Object v0080, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "my_letmtr");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0080 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for my_letmtr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0080,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0080;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    stack[-2] = nil;
    v0082 = stack[-3];
    v0081 = elt(env, 1); /* mat */
    if (!consp(v0082)) goto v0054;
    v0082 = qcar(v0082);
    if (!(v0082 == v0081)) goto v0054;
    v0081 = stack[-5];
    v0081 = qcdr(v0081);
    stack[-6] = v0081;
    v0081 = stack[-6];
    if (v0081 == nil) goto v0027;
    v0081 = stack[-6];
    v0081 = qcar(v0081);
    v0082 = v0081;
    v0081 = v0082;
    v0081 = integerp(v0081);
    if (v0081 == nil) goto v0139;
    v0081 = v0082;
    goto v0096;

v0096:
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    stack[-1] = v0081;
    stack[-2] = v0081;
    goto v0135;

v0135:
    v0081 = stack[-6];
    v0081 = qcdr(v0081);
    stack[-6] = v0081;
    v0081 = stack[-6];
    if (v0081 == nil) goto v0162;
    stack[0] = stack[-1];
    v0081 = stack[-6];
    v0081 = qcar(v0081);
    v0082 = v0081;
    v0081 = v0082;
    v0081 = integerp(v0081);
    if (v0081 == nil) goto v0161;
    v0081 = v0082;
    goto v0093;

v0093:
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    v0081 = Lrplacd(nil, stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    v0081 = stack[-1];
    v0081 = qcdr(v0081);
    stack[-1] = v0081;
    goto v0135;

v0161:
    v0081 = v0082;
    fn = elt(env, 8); /* reval */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    goto v0093;

v0162:
    v0081 = stack[-2];
    goto v0040;

v0040:
    stack[-2] = v0081;
    fn = elt(env, 9); /* numlis */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    if (v0081 == nil) goto v0163;
    v0081 = stack[-2];
    v0082 = Llength(nil, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    v0081 = (Lisp_Object)33; /* 2 */
    v0081 = Lneq(nil, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    goto v0132;

v0132:
    if (v0081 == nil) goto v0217;
    v0082 = stack[-5];
    v0081 = elt(env, 7); /* hold */
    {
        popv(8);
        fn = elt(env, 10); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0082, v0081);
    }

v0217:
    v0081 = stack[-3];
    v0082 = qcdr(v0081);
    v0081 = stack[-2];
    v0081 = qcar(v0081);
    fn = elt(env, 11); /* nth */
    v0082 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    v0081 = stack[-2];
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    fn = elt(env, 12); /* pnth */
    v0082 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    v0081 = stack[-4];
    v0081 = Lrplaca(nil, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    v0081 = nil;
    { popv(8); return onevalue(v0081); }

v0163:
    v0081 = qvalue(elt(env, 6)); /* t */
    goto v0132;

v0139:
    v0081 = v0082;
    fn = elt(env, 8); /* reval */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    goto v0096;

v0027:
    v0081 = qvalue(elt(env, 5)); /* nil */
    goto v0040;

v0054:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0229 = elt(env, 3); /* "Matrix" */
    v0081 = stack[-5];
    v0082 = qcar(v0081);
    v0081 = elt(env, 4); /* "not set" */
    v0081 = list3(v0229, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0081 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-7];
    goto v0217;
/* error exit handlers */
v0174:
    popv(8);
    return nil;
}



/* Code for nconc2 */

static Lisp_Object CC_nconc2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127, v0123, v0121;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nconc2");
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
    v0123 = v0001;
    v0121 = v0000;
/* end of prologue */
    v0127 = v0121;
    if (!consp(v0127)) { popv(2); return onevalue(v0123); }
    v0127 = v0121;
    stack[0] = v0127;
    goto v0138;

v0138:
    v0127 = stack[0];
    v0127 = qcdr(v0127);
    v0127 = Lconsp(nil, v0127);
    env = stack[-1];
    if (v0127 == nil) goto v0118;
    v0127 = stack[0];
    v0127 = qcdr(v0127);
    stack[0] = v0127;
    goto v0138;

v0118:
    v0127 = stack[0];
    v0127 = Lrplacd(nil, v0127, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0026:
    popv(2);
    return nil;
}



/* Code for fortexp */

static Lisp_Object CC_fortexp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fortexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0061 = v0000;
/* end of prologue */
    v0086 = v0061;
    v0061 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* fortexp1 */
        return (*qfn2(fn))(qenv(fn), v0086, v0061);
    }
}



setup_type const u21_setup[] =
{
    {"ofsf_vareqnp",            too_few_2,      CC_ofsf_vareqnp,wrong_no_2},
    {"add_minus",               CC_add_minus,   too_many_1,    wrong_no_1},
    {"vdpvevlcomp",             too_few_2,      CC_vdpvevlcomp,wrong_no_2},
    {"gparg1p",                 CC_gparg1p,     too_many_1,    wrong_no_1},
    {"assert_check1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_check1},
    {"groeb=newpair",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMnewpair},
    {"klistt",                  CC_klistt,      too_many_1,    wrong_no_1},
    {"get-denom-ll",            too_few_2,      CC_getKdenomKll,wrong_no_2},
    {"tmsf",                    CC_tmsf,        too_many_1,    wrong_no_1},
    {"qqe_ofsf_simpat",         CC_qqe_ofsf_simpat,too_many_1, wrong_no_1},
    {"pasf_varlat",             CC_pasf_varlat, too_many_1,    wrong_no_1},
    {"aex_tad",                 CC_aex_tad,     too_many_1,    wrong_no_1},
    {"lambdavar",               CC_lambdavar,   too_many_1,    wrong_no_1},
    {"ps:value",                CC_psTvalue,    too_many_1,    wrong_no_1},
    {"dipsimpcont",             CC_dipsimpcont, too_many_1,    wrong_no_1},
    {"replace1_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace1_parents},
    {"changearg",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_changearg},
    {"*di2q0",                  too_few_2,      CC_Hdi2q0,     wrong_no_2},
    {"rootrnd",                 CC_rootrnd,     too_many_1,    wrong_no_1},
    {"checku",                  too_few_2,      CC_checku,     wrong_no_2},
    {"homogp",                  CC_homogp,      too_many_1,    wrong_no_1},
    {"vdp_setsugar",            too_few_2,      CC_vdp_setsugar,wrong_no_2},
    {"getdec",                  CC_getdec,      too_many_1,    wrong_no_1},
    {"expvec2a",                CC_expvec2a,    too_many_1,    wrong_no_1},
    {"memqcar",                 too_few_2,      CC_memqcar,    wrong_no_2},
    {"eqexpr",                  CC_eqexpr,      too_many_1,    wrong_no_1},
    {"calc_atlas",              too_few_2,      CC_calc_atlas, wrong_no_2},
    {"mo_zero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mo_zero},
    {"squashsqrt",              CC_squashsqrt,  too_many_1,    wrong_no_1},
    {"get-denom-l",             CC_getKdenomKl, too_many_1,    wrong_no_1},
    {"dip_fmon",                too_few_2,      CC_dip_fmon,   wrong_no_2},
    {"lambdaom",                CC_lambdaom,    too_many_1,    wrong_no_1},
    {"reform-minus",            too_few_2,      CC_reformKminus,wrong_no_2},
    {"ps:depvar",               CC_psTdepvar,   too_many_1,    wrong_no_1},
    {"doublep",                 CC_doublep,     too_many_1,    wrong_no_1},
    {"oldmtch",                 too_few_2,      CC_oldmtch,    wrong_no_2},
    {"evinvlexcomp",            too_few_2,      CC_evinvlexcomp,wrong_no_2},
    {"evgradlexcomp",           too_few_2,      CC_evgradlexcomp,wrong_no_2},
    {"xriterion_1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_xriterion_1},
    {"gftimesn",                too_few_2,      CC_gftimesn,   wrong_no_2},
    {"all_edge",                too_few_2,      CC_all_edge,   wrong_no_2},
    {"pasf_zcong",              CC_pasf_zcong,  too_many_1,    wrong_no_1},
    {"aex_subrp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrp},
    {"get-height",              CC_getKheight,  too_many_1,    wrong_no_1},
    {"relnrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_relnrd},
    {"multdf",                  too_few_2,      CC_multdf,     wrong_no_2},
    {"derad",                   too_few_2,      CC_derad,      wrong_no_2},
    {"chkint*",                 CC_chkintH,     too_many_1,    wrong_no_1},
    {"actual_alst",             too_few_2,      CC_actual_alst,wrong_no_2},
    {"quotpri",                 CC_quotpri,     too_many_1,    wrong_no_1},
    {"reduce-mod-p*",           too_few_2,      CC_reduceKmodKpH,wrong_no_2},
    {"cl_susiupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl},
    {"sfto_b:extmult",          too_few_2,      CC_sfto_bTextmult,wrong_no_2},
    {"ps:evaluate-next",        too_few_2,      CC_psTevaluateKnext,wrong_no_2},
    {"crprimp",                 CC_crprimp,     too_many_1,    wrong_no_1},
    {"ft:zerop",                CC_ftTzerop,    too_many_1,    wrong_no_1},
    {":dmtimeslst",             CC_Tdmtimeslst, too_many_1,    wrong_no_1},
    {"formde",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_formde},
    {"mv-domainlist",           CC_mvKdomainlist,too_many_1,   wrong_no_1},
    {"dv_ind2var",              CC_dv_ind2var,  too_many_1,    wrong_no_1},
    {":expt",                   too_few_2,      CC_Texpt,      wrong_no_2},
    {"bndtst",                  CC_bndtst,      too_many_1,    wrong_no_1},
    {"n_nary",                  too_few_2,      CC_n_nary,     wrong_no_2},
    {"recaliasbacksubst",       too_few_2,      CC_recaliasbacksubst,wrong_no_2},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,too_many_1,wrong_no_1},
    {"noncomexpf",              CC_noncomexpf,  too_many_1,    wrong_no_1},
    {"my_letmtr",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_my_letmtr},
    {"nconc2",                  too_few_2,      CC_nconc2,     wrong_no_2},
    {"fortexp",                 CC_fortexp,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u21", (two_args *)"11088 6978673 9214703", 0}
};

/* end of generated code */
