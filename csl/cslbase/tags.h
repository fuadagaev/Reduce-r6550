// tags.h                                  Copyright (C) Codemist 1990-2017

//
//   Data-structure and tag bit definitions, also common C macros
//   for Lisp implementation.
//
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$


#ifndef header_tags_h
#define header_tags_h 1

//
// General objects in Lisp are represented as pointer-sized integers
// and the type LispObject reflects this representation and
// not the elaborate tagged union that at some other level exists.
// If I could use "void *" for this type that might give me a bit more
// security since not much can be done with a "void *" object - in particular
// it can not participate in arithmetic.  But when I do that I run into
// trouble in protected mode on a PC if I have items of type LispObject
// that are not valid pointers. I suspect that the same used to be
// the case on a Motorola 68000 with address and data registers.
//
//
// Sometimes the pointer-sized integer will be 64-bits wide, and will be the
// data type for the type LispObject. A result will be that anywhere in
// the code where I am sloppy about putting such an object into an int32_t
// I will have trouble, and anywhere that I use absolute numeric offsets
// instead of multiples of sizeof(LispObject) there can be pain.

typedef intptr_t LispObject;

#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)

// My hope is that writing CSL_IGNORE(x) will cause the compiler to believe
// that x is "used" enough that it does not give any "not used" warnings.

static inline void CSL_IGNORE(LispObject x)
{   (void)x;
}

//
// I allocate memory (using malloc()) in CSL_PAGE_SIZE chunks.
// This was first implemented for the benefit of 16-bit machines
// (in particular MSDOS/286) but now seems generally reasonable.  The biggest
// menace about it is that it limits the size of the largest vector I can ever
// allocate - and this (as of the time of this comment) limits the size of
// the symbol table (object list).
//
// My default at present is to use PAGE_BITS=22, which leads to 4 Mbyte pages.
// I use that size on both 32 and 64-bit machines, which will mean that
// 32 bit systems can support vectors that are longer than will fit into
// a 64-bit system. With the latest revision of the garnage collector and
// checkpoint scheme this arrangement is no longer vital. But I may wish to
// use a variant of it when and if I introduce a multi-threading model!
//

#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif // PAGE_BITS

#define PAGE_POWER_OF_TWO       (((intptr_t)1) << PAGE_BITS)
//
// When I come to allocate memory I do so in chunks that are a little less
// than the power of two suggested here, to allow for malloc() header
// blocks etc.
//
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256)

//
// On 64-bit systems I will limit myself to 512 Gbyte, while on 32-bit
// ones the limit is around 2 Gbyte and in reality will usually be
// rather less than that.
//
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif // MAX_HEAPSIZE

#define MEGABYTE                ((intptr_t)0x100000U)

#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#endif

//
// Windows seems to say it can use file names up to 260 chars, Unix and
// the like may not even have that limit, but I will assume something here.
// There must be a number of cases of potential buffer overflow throughout
// my code caused by this fixed limit.
//
#define LONGEST_LEGAL_FILENAME 1024


// The macro CELL had better have either the value 4 or 8. It is the
// size of the basic unit of memory within which CSL works.

#define CELL ((size_t)sizeof(LispObject))

// LispObject is a datatype where the low 3 bits are used as tags -
// this idea works provided all memory addresses needed can be kept
// doubleword aligned.  The main tag allocation is documented here.

#define TAG_BITS        7
#define XTAG_BITS       15

//                                                       bit-mask in (1<<tag)

#define TAG_CONS        0   // Cons cells                                01
#define TAG_VECTOR      1   // Regular Lisp vectors                      02
#define TAG_HDR_IMMED   2   // Char constants, vechdrs etc               04
#define TAG_FORWARD     3   // For the Garbage Collector                 08
// There are special constraints that mean I want symbols to have
// tag code 4. These apply in the old garbage collector and the way I
// deal with some back-pointers there.
#define TAG_SYMBOL      4   // Symbols                                   10
// Note that tags from 5 up are all for numeric date
#define TAG_NUMBERS     5   // Bignum, Rational, Complex                 20
#define TAG_BOXFLOAT    6   // Boxed floats                              40
#define TAG_FIXNUM      7   // 28/60-bit integers                        80
#define TAG_XBIT        8   // extra bit!
#define XTAG_SFLOAT     15  // Short float, 28+ bits of immediate data   80

// On a 32-bit machine I can pack a 28-bit float (implemented as a 32-bit
// one with the low 4 bits crudely masked off) by putting XTAG_FLOAT as the
// bottom 4 bits. On a 64-bit system I have 64-bit immediate data so if I
// I have XTAG_FLOAT as the low 4 bits then bit 5 could select as between
// a 28 or a 32-bit value and the high 28 or 32-bits could be that value.
// Then single floats as well as short floats would have an immediate
// representation. 
#define XTAG_FLOAT32    16

static inline bool is_forward(LispObject p)
{   return (p & TAG_BITS) == TAG_FORWARD;
}

static inline bool is_number(LispObject p)
{   return (p & TAG_BITS) >= TAG_NUMBERS;
}

static inline bool is_float(LispObject p)
{   return ((0xc040 >> (p & XTAG_BITS)) & 1) != 0;
}

static inline bool is_immed_or_cons(LispObject p)
{   return ((0x85 >> (p & TAG_BITS)) & 1) != 0;
}

static inline bool is_immed_cons_sym(LispObject p)
{   return ((0x95 >> (p & TAG_BITS)) & 1) != 0;
}

static inline bool need_more_than_eq(LispObject p)
{   return ((0x63 >> (p & TAG_BITS)) & 1) != 0;
}

//
// For each of the above tag classes I have a bunch of low-level
// operations that need support - including type identification
// predicates and conversions to and from native C formats.
//

// fixnums now use the whole of an intptr_t, so they have 28 useful bits on
// a 32-bit machine and 60-bits on a 64-bit machine. By doing the left shift
// on an unsigned value I steer clear of C++ undefined behaviour, but then
// when I cast back to a signed value I am in "implementation defined"
// territory.

static inline LispObject fixnum_of_int(intptr_t x)
{   return  (LispObject)((((uintptr_t)x)<<4) + TAG_FIXNUM);
}

// The code here manages to get compiled as a simple arithmetic right shift
// on enough architectures that I will not worry about writing it as a 
// division. My intent here is (x>>4) with the shift being arithmetic in that
// it should replicate the top bit of the word as it shifts. Masking off
// low bits and then doing a signed division should achieve this affect in a
// portable manner. 

static inline intptr_t int_of_fixnum(LispObject x)
{   return ((intptr_t)x & ~(intptr_t)15)/16;
}

// The following test will see if an intptr_t value can be reduced to
// a Lisp fixnum without loss. I think that the logic is pretty clearly
// expressed here, but I want the code to run fast. Well I observe that
// using g++ on the computers that most matter to me this compiles
// rather as if it has been ((x<<4)>>4 == x), i.e. as two shifts followed
// by a comparison. This probably does well compared with some previous
// code I had that things like (x < 0x08000000 && x >= -0x08000000)
// which involves referring to two literal values and performing two
// comparisons. Of perhaps { t = (x & fix_mask); if (t==0 | t == fix_mask) ..}
// which is comparable. If you had a compiler that was less clever the
// resulting code here could be horrible!

// I need to overload these to cover various integer widths.

static inline bool valid_as_fixnum(int32_t x)
{   if (SIXTY_FOUR_BIT) return true;
    else return int_of_fixnum(fixnum_of_int(x)) == x;
}

static inline bool valid_as_fixnum(int64_t x)
{   return int_of_fixnum(fixnum_of_int(x)) == x;
}

static inline bool valid_as_fixnum(int128_t x)
{   return int_of_fixnum(fixnum_of_int(NARROW128(x))) == x;
}

// The following has given me some pain wrt the overloading where gcc and
// clang disagree about validity. Until I have read the C++ standard carefully
// enough I use this non-overloaded version in a few places. This issue is
// that intptr_t is liable to be either similar to int32_t or similar to
// int64_t. So if I try to provide overloads that accept all of int32_t,
// intptr_t and int64_t there is scope for confusion between the 3 versions. 

static inline bool intptr_valid_as_fixnum(intptr_t x)
{   return int_of_fixnum(fixnum_of_int(x)) == x;
}

static inline bool valid_as_fixnum(uint32_t x)
{   if (SIXTY_FOUR_BIT) return true;
    else return x < (((uintptr_t)1) << 28);
}

static inline bool valid_as_fixnum(uint64_t x)
{   return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}

static inline bool uint128_valid_as_fixnum(uint128_t x)
{   return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}

#define MOST_POSITIVE_FIXVAL (((intptr_t)1 << (8*sizeof(LispObject)-5)) - 1)
#define MOST_NEGATIVE_FIXVAL (-((intptr_t)1 << (8*sizeof(LispObject)-5)))

#define MOST_POSITIVE_FIXNUM fixnum_of_int(MOST_POSITIVE_FIXVAL)
#define MOST_NEGATIVE_FIXNUM fixnum_of_int(MOST_NEGATIVE_FIXVAL)

static inline bool is_cons(LispObject p)
{   return ((((int)(p)) & TAG_BITS)  == TAG_CONS);
}

static inline bool is_fixnum(LispObject p)
{   return ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM);
}

static inline bool is_odds(LispObject p)
{   return ((((int)(p)) & TAG_BITS)  == TAG_HDR_IMMED); // many subcases
}

static inline bool is_sfloat(LispObject p)
{   return ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT);
}

static inline bool is_symbol(LispObject p)
{   return ((((int)(p)) & TAG_BITS)  == TAG_SYMBOL);
}

static inline bool is_numbers(LispObject p)
{   return ((((int)(p)) & TAG_BITS)  == TAG_NUMBERS);
}

static inline bool is_vector(LispObject p)
{   return ((((int)(p)) & TAG_BITS)  == TAG_VECTOR);
}

static inline bool is_bfloat(LispObject p)
{   return ((((int)(p)) & TAG_BITS)  == TAG_BOXFLOAT);
}

static inline bool consp(LispObject p)
{   return is_cons(p);
}
static inline bool symbolp(LispObject p)
{   return is_symbol(p);
}

// For Common Lisp it would be necessary to detect and trap any attempt
// to take CAR or CDR of NIL and do something special.

static inline bool car_legal(LispObject p)
{   return is_cons(p);
}

typedef struct Cons_Cell
{   LispObject car;
    LispObject cdr;
} Cons_Cell;

static inline LispObject& qcar(LispObject p)
{   return ((Cons_Cell *)p)->car;
}

static inline LispObject& qcdr(LispObject p)
{   return ((Cons_Cell *)p)->cdr;
}

static inline LispObject& qcar(char * p)
{   return ((Cons_Cell *)p)->car;
}

static inline LispObject& qcdr(char * p)
{   return ((Cons_Cell *)p)->cdr;
}

//
// car32(p) refers to the 32-bit integer pointed at by p. It is
// used to cope with various bits of junk at the start and end of
// "pages" of memory where (eg) the amount of the page that is in
// use needs to be recorded.
//

static inline int32_t& car32(LispObject p)
{   return ((int32_t *)p)[0];
}

//
// cdr32(p) reads the next 32-bit word after that used by car32(p), and
// is used in related circumstances where I explicitly wish to work using
// just 32-bit values..
//

static inline int32_t& cdr32(LispObject p)
{   return ((int32_t *)p)[1];
}

static inline int32_t& car32(char * p)
{   return ((int32_t *)p)[0];
}

static inline int32_t& cdr32(char * p)
{   return ((int32_t *)p)[1];
}


typedef LispObject Special_Form(LispObject, LispObject);

// The original CSL uses entries for 1, 2 and n arguments, where the general
// case has an argument count and uses va_args.
// A newer scheme will have entries for 0, 1, 2, 3 and more than that. For
// 4 or more arguments a count is passed. For exactly four arguments the
// final argument is passed directly.
//   (F 4 a1 a2 a3 a4)
// For the 5 up case arguments 4, 5, ...
// are passed as a list much as if the call had been
//   (F n a1 a2 a3 (list a4 a5 a6 ... an))

typedef LispObject no_args(LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef LispObject four_args(LispObject, size_t, LispObject, LispObject,
                                                 LispObject, LispObject);

//
// Headers are also LispObjects, but I give them a separate typedef
// name to help me keep their identity separate.  There is only any
// chance of headers and other objects getting confused during
// garbage collection, and the code there has to be rather on the
// careful side.  By making Headers unsigned I help the length
// calculation on them.
//

typedef uintptr_t Header;

//
// Objects will have a header word with the following format:
//   xxxx:xxxx:xxxx:xxxx:xxxx:xx  yy:yyy z:z 010
//             22-bits            5-bits  2   3
// The low 3 bits are always TAG_HDR_IMMED.
//
// I will use a shift by Tw to cope with the width of 010 with
// Tw=3 so that the offset to where yyyy/zz starts is kept just a little
// bit abstract. 

#define Tw (3)

//
// The zz bits are
//        00    symbol header, character literal, special identifier (Spid)
//        01    vector containing Lisp pointers
//        10    bit-vectors
//        11    vector containing binary data
//
// The bits yyyyy are used to indicate which case within each above category
// applies. For class "00" only the two low bits are used, so there are then
// 25 bits of payload available.
// For the other cases the field xx(22)xx gives the number of (4-byte) words
// of data used in the object. Note that this count does not include the
// size of the header itself. Because this is in 32-bit words rather than bytes
// this allows the largest object to be 16 Mbytes if your word length is 32
// bits. That limit larger than the previous CSL tagging scheme permitted.
//
// For vectors of bits, bytes and halfwords the high bits of yyyyy indicate the
// number of bits used in the final 32-bit word that is indicated by xxx.
// Consider the case for bytes (as used for strings). If there are n characters
// in a string then xxx must show ((n + 3) & ~3) [suitably shifted]. The two
// bits in yy will be ((n + 3) & 3) so that 0 indicates just one character in
// the final word and 3 denotes the final word being full.
// Now given w = xxxxxyy (the packed length) just subtracting 3 should
// recover the length n.

// It took me some while to get my head around the full consequences here!
// because the length code is the length of active data (from 0 upwards)
// lengths can be from 0 to 0xffffff. A byte-vector can then have a length
// stored as up to 0xffffff:3 which stands for a length 0x3ffffc. This is a
// string that fills all the words of the vector. [these are described as for
// a 32-bit machine]. Note that if one includes the header word the total size
// of the object becomes 0x1000000.

// I have considered making the length code just the length of DATA not
// including the size of the header. In some respects that would be tidier,
// but at present I do not believe that the widespread code changes needed to
// move to it would be cost-effective.

#define header_mask                (0x7f<<Tw)

//
// Bit, byte and halfword-vectors need extra information held here so that
// their exact can be determined.  Generally headers hold length information
// measured in words, so a few more bits are required here.
// Bitvectors will now supported even in Standard Lisp mode.
//

#define TYPE_BITVEC_1     ( 0x02 <<Tw)  // subtypes encode length mod 32
#define TYPE_BITVEC_2     ( 0x06 <<Tw)  // BITVEC_n has n bits in use in its...
#define TYPE_BITVEC_3     ( 0x0a <<Tw)  // ... final 32-bit word.
#define TYPE_BITVEC_4     ( 0x0c <<Tw)  //
#define TYPE_BITVEC_5     ( 0x12 <<Tw)  //
#define TYPE_BITVEC_6     ( 0x16 <<Tw)  //
#define TYPE_BITVEC_7     ( 0x1a <<Tw)  //
#define TYPE_BITVEC_8     ( 0x1c <<Tw)  //
#define TYPE_BITVEC_9     ( 0x22 <<Tw)  //
#define TYPE_BITVEC_10    ( 0x26 <<Tw)  //
#define TYPE_BITVEC_11    ( 0x2a <<Tw)  //
#define TYPE_BITVEC_12    ( 0x2c <<Tw)  //
#define TYPE_BITVEC_13    ( 0x32 <<Tw)  //
#define TYPE_BITVEC_14    ( 0x36 <<Tw)  //
#define TYPE_BITVEC_15    ( 0x3a <<Tw)  //
#define TYPE_BITVEC_16    ( 0x3c <<Tw)  //
#define TYPE_BITVEC_17    ( 0x42 <<Tw)  //
#define TYPE_BITVEC_18    ( 0x46 <<Tw)  //
#define TYPE_BITVEC_19    ( 0x4a <<Tw)  //
#define TYPE_BITVEC_20    ( 0x4c <<Tw)  //
#define TYPE_BITVEC_21    ( 0x52 <<Tw)  //
#define TYPE_BITVEC_22    ( 0x56 <<Tw)  //
#define TYPE_BITVEC_23    ( 0x5a <<Tw)  //
#define TYPE_BITVEC_24    ( 0x5c <<Tw)  //
#define TYPE_BITVEC_25    ( 0x62 <<Tw)  //
#define TYPE_BITVEC_26    ( 0x66 <<Tw)  //
#define TYPE_BITVEC_27    ( 0x6a <<Tw)  //
#define TYPE_BITVEC_28    ( 0x6c <<Tw)  //
#define TYPE_BITVEC_29    ( 0x72 <<Tw)  //
#define TYPE_BITVEC_30    ( 0x76 <<Tw)  //
#define TYPE_BITVEC_31    ( 0x7a <<Tw)  //
#define TYPE_BITVEC_32    ( 0x7c <<Tw)  //

// A string is not really a vector of characters since it is in utf-8 so
// access to the nth characters or updating characters within it is
// hard. You should use a vector of 32-bit codepoints if you want
// a genuine vector of characters, but then you will not have a string!

#define TYPE_STRING_1    ( 0x07 <<Tw) // simple (narrow) character vector
#define TYPE_STRING_2    ( 0x27 <<Tw) // Strings are in UTF8
#define TYPE_STRING_3    ( 0x47 <<Tw) //
#define TYPE_STRING_4    ( 0x67 <<Tw) //

#define TYPE_VEC8_1      ( 0x03 <<Tw) // vector of 8 bit values
#define TYPE_VEC8_2      ( 0x23 <<Tw) //
#define TYPE_VEC8_3      ( 0x43 <<Tw) //
#define TYPE_VEC8_4      ( 0x63 <<Tw) //

#define TYPE_BPS_1       ( 0x0b <<Tw) // Bytecodes
#define TYPE_BPS_2       ( 0x2b <<Tw) //
#define TYPE_BPS_3       ( 0x4b <<Tw) //
#define TYPE_BPS_4       ( 0x6b <<Tw) //

// #define TYPE_NATIVECODE  ( 0x6f <<Tw) // (not implemented)

#define TYPE_VEC16_1     ( 0x0f <<Tw) // vector of 16 bit values
#define TYPE_VEC16_2     ( 0x4f <<Tw) //

#if 0
#define TYPE_MAPLEREF    ( 0x2f <<Tw) // hook for interface to Maple ...
                                      // ... note this was an EXPERIMENT
#endif
#define TYPE_FOREIGN     ( 0x33 <<Tw) // entrypoint to foreign function
#define TYPE_SP          ( 0x37 <<Tw) // Encapsulated stack ptr
#define TYPE_ENCAPSULATE ( 0x3b <<Tw) // SAME TAG AS SP AT PRESENT@@@

#define vector_holds_binary(h) (((h) & (0x2<<Tw)) != 0)

#define TYPE_SIMPLE_VEC   ( 0x01 <<Tw) // simple general vector
#define TYPE_INDEXVEC     ( 0x11 <<Tw) // used for huge vectors
#define TYPE_NEWHASH      ( 0x15 <<Tw) // new style hash table
#define TYPE_NEWHASHX     ( 0x19 <<Tw) // new hash table in need of re-hashing
#define TYPE_HASH         ( 0x21 <<Tw) // old style hash table.
#define TYPE_ARRAY        ( 0x05 <<Tw) // header record for general array
#define TYPE_STRUCTURE    ( 0x09 <<Tw) // .. includes packages etc possibly
#define TYPE_OBJECT       ( 0x0d <<Tw) // .. and "object"

#define TYPE_VEC32        ( 0x13 <<Tw) // contains 32-bit integers
#define TYPE_VEC64        ( 0x17 <<Tw) // contains 32-bit integers
#define TYPE_VEC128       ( 0x1b <<Tw) // contains 32-bit integers
#define TYPE_VECFLOAT32   ( 0x53 <<Tw) // contains single-precision floats
#define TYPE_VECFLOAT64   ( 0x57 <<Tw) // contains double-precision floats
#define TYPE_VECFLOAT128  ( 0x5b <<Tw) // contains long double floats

// The next items live amongst the vectors that hold Lisp pointers, but only
// the first three items are pointers - the rest of the stuff is binary
// data. This arrangements was required for streams, and the three other
// "mixed" cases are just in case anybody finds them useful.
#define is_mixed_header(h) (((h) & (0x73<<Tw)) == TYPE_MIXED1)

#define TYPE_MIXED1       ( 0x41 <<Tw) // general, but limited to 3 pointers
#define TYPE_MIXED2       ( 0x45 <<Tw) // general, but limited to 3 pointers
#define TYPE_MIXED3       ( 0x49 <<Tw) // only 3 pointers
#define TYPE_STREAM       ( 0x4d <<Tw) // 3 pointers then binary data

#define VIRTUAL_TYPE_CONS ( 0x7d <<Tw) // what a header for a CONS would be!

#define HDR_IMMED_MASK    (( 0xf <<Tw) | TAG_BITS)
#define TAG_CHAR          (( 0x4 <<Tw) | TAG_HDR_IMMED) // 25 bits payload
#define TAG_SPID          (( 0xc <<Tw) | TAG_HDR_IMMED) // Internal flag values

#define SPID_NIL        (TAG_SPID+(0x00<<(Tw+4)))  // NIL in checkpoint file
#define SPID_FBIND      (TAG_SPID+(0x01<<(Tw+4)))  // Fluid binding on stack
#define SPID_CATCH      (TAG_SPID+(0x02<<(Tw+4)))  // CATCH frame on stack
#define SPID_PROTECT    (TAG_SPID+(0x03<<(Tw+4)))  // UNWIND_PROTECT on stack
#define SPID_HASHEMPTY  (TAG_SPID+(0x04<<(Tw+4)))  // Empty hash slot
#define SPID_HASHTOMB   (TAG_SPID+(0x05<<(Tw+4)))  // Deleted hash item (tombstone)
#define SPID_GCMARK     (TAG_SPID+(0x06<<(Tw+4)))  // Used by GC as sentinel
#define SPID_NOINPUT    (TAG_SPID+(0x07<<(Tw+4)))  // Used by (read) in #X()
#define SPID_ERROR      (TAG_SPID+(0x08<<(Tw+4)))  // Used to indicate error
#define SPID_PVBIND     (TAG_SPID+(0x09<<(Tw+4)))  // PROGV binding on stack
#define SPID_NOARG      (TAG_SPID+(0x0a<<(Tw+4)))  // Missing &OPTIONAL arg
#define SPID_NOPROP     (TAG_SPID+(0x0b<<(Tw+4)))  // fastget entry is empty
#define SPID_LIBRARY    (TAG_SPID+(0x0c<<(Tw+4)))  // + 0xnnn00000 offset

static Header& vechdr(LispObject v)
{   return *(Header *)((char *)(v) - TAG_VECTOR);
}

static inline unsigned int type_of_header(Header h)
{   return ((unsigned int)h) & header_mask;
}

// length_of_header returns the length of a word or doubleword oriented
// object in bytes. NOT in words.

static inline size_t length_of_header(Header h)
{   return (((size_t)h) >> (Tw+7)) << 2;
}

// length_of_bitheader returns a length in bits.
static inline size_t length_of_bitheader(Header h)
{   return (((size_t)h) >> (Tw+2)) - 31;
}

// length_of_byteheader returns a length in bytes, and so compatible with what
// length_of_header used to do on byte arrays (and hence strings)


static inline size_t length_of_byteheader(Header h)
{   return (((size_t)h) >> (Tw+5))  - 3;
}

// length_of_hwordheader gives the number of halfwords used.
static inline size_t length_of_hwordheader(Header h)
{   return (((size_t)h) >> (Tw+6)) - 1;
}

static inline Header bitvechdr_(size_t n)
{   return TYPE_BITVEC_1 + (((n+31)&31)<<(Tw+2));
}

// Values for the type field in a header

//
// Symbols are so important that they have 25+ bits used to sub-classify them.
// These are used by the interpreter to identify special variables, special
// forms, and those symbols which are defined as macros.  The bits live where
// other items would store a length, but since all symbol headers are the
// same size an explicit length field is not necessary - but missing one out
// means that I have to do a special check for the SYMBOL case whenever I
// scan the vector heap, which is a bit messy. Well when I say "25 bits" what
// I mean is that even on a 32-bit machine there are 25 bits available. On a
// 64-bit system there are an extra 32 (which at present I do not use).
//

#define TYPE_SYMBOL         0x00000000 
#define  SYM_SPECIAL_VAR    0x00000080       // (fluid '(xxx))
#define  SYM_FLUID_VAR      0x00000080       // (fluid '(xxx))
#define  SYM_GLOBAL_VAR     0x00000100       // (global '(xxx))
// I will set both SPECIAL and GLOBAL for "keywords" and those will be
// initialised to have themselves as their value and then neither be
// bindable or settable.
#define  SYM_KEYWORD_VAR    0x00000180       // (keyword '(xxx))
#define  SYM_SPECIAL_FORM   0x00000200       // eg. COND, QUOTE
#define  SYM_MACRO          0x00000400       // (putd 'xxx 'macro ...)
#define  SYM_C_DEF          0x00000800       // has definition from C kernel
#define  SYM_CODEPTR        0x00001000       // just carries code pointer
#define  SYM_ANY_GENSYM     0x00002000       // gensym, printed or not
#define  SYM_TRACED         0x00004000       // function is traced.
#define  SYM_TRACESET       0x00008000       // traceset support
#define  SYM_TAGGED         0x00010000       // used for special versions
#define  SYM_FASTGET_MASK   0x007e0000       // used to support "fast" gets
#define  SYM_FASTGET_SHIFT  17
//
//
#ifdef COMMON
// In Common Lisp mode I use the rest of the header to help speed up
// test for the availability of a symbol in a package (while I am printing).
// Note that on a 32-bit machine I have just 8 bits for that. I think that
// will help with the first 8 packages I come across (or many more on a
// 64-bit machine). If I ever enable package support!
#define  SYM_EXTERN_IN_HOME 0x00800000      // external in its home package
#define  SYM_IN_PACKAGE     0xff000000U     // availability in 8 packages
#define  SYM_IN_PKG_SHIFT   24
#define  SYM_IN_PKG_COUNT   8
#else // COMMON
// In Standard Lisp mode I only allocate a print-name to a gensym when I
// first print it, so I have a bit that tells me when a gensym is still
// not printed.
#define  SYM_UNPRINTED_GENSYM 0x00800000    // not-yet-printed gensym
// Here in Standard Lisp mode I have 8 bits left in a symbol header even
// on a 32-bit system.
#endif // COMMON

#define symhdr_length       (doubleword_align_up(sizeof(Symbol_Head)))
static inline bool is_symbol_header(Header h)
{   return ((int)h & (0xf<<Tw)) == TYPE_SYMBOL;
}

static inline bool is_symbol_header_full_test(Header h)
{   return ((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED);
}

static inline int header_fastget(Header h)
{   return (h >> SYM_FASTGET_SHIFT) & 0x3f;
}

static inline bool is_number_header_full_test(Header h)
{   return ((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED);
}

// The "vector" case here includes vector-like number cases
static inline bool is_vector_header_full_test(Header h)
{   return is_odds(h) && (((int)h & (0x3<<Tw)) != 0);
}

static inline bool is_array_header(Header h)
{   return type_of_header(h) == TYPE_ARRAY;
}

// The codes for yyyyy are as follows:

//   xx:x00 0:0 010  symbol header
//   xx:x01 0:0 010  character
//   xx:x10 0:0 010  handle for bytecode. Why do I do it this way?
//   xx:x11 0:0 010  special marker identifier (Spid) for internal use
//
//   00:000 0:1 010  simple vector
//   00:001 0:1 010  array
//   00:010 0:1 010  structure
//   00:011 0:1 010  object
//   00:100 0:1 010  indexvec (used to implement huge vectors)
//   00:101 0:1 010  new style hash table
//   00:110 0:1 010  new hash table with rehash pending
//   00:111 0:1 010  rational number  *
//   01:000 0:1 010  old style hash table
//   01:0xx 0:1 010  (spare: 3 codes, one a "number")
//   01:111 0:1 010  complex number   *
//   10:0xx 0:1 010  stream and mixed1, 2 and 3
//   1x:111 0:1 010  (spare, but classifies as a number: 2 codes)
//   1x:xxx 0:1 010  (spare: 14 codes)
//   11:111 0:1 010  used when calculating hash codes as if it was the
//                   header for a CONS cell.

//   yyy:yy 10 010  bit-vector with yyyyy (1 to 32) bits in final word.

// The final column here explains what size units of storage fit within
// the object. For (eg) "encapsulated general pointer" I have made it
// 64 and I should pad 32-bit cases to that width - but I do not expect
// those sorts of data to survive serialization, so I annotate them here
// as "64?".

//   00:000 1:1 010  vec8-1                         8
//   00:001 1:1 010  string-1                       8
//   00:010 1:1 010  bytecode-1                     8
//   00:011 1:1 010  vec16-1                        16
//   00:100 1:1 010  vec32                          32
//   00:101 1:1 010  vec64                          64
//   00:110 1:1 010  vec128                         128
//   00:111 1:1 010  bignum            *            32
//   01:000 1:1 010  vec8-2                         8
//   01:001 1:1 010  string-2                       8
//   01:010 1:1 010  bytecode-2                     8
//   01:011 1:1 010  maple-ref                      64?
//   01:100 1:1 010  foreign                        64?
//   01:101 1:1 010  encapsulated-sp                64?
//   01:110 1:1 010  encapsulated eneral pointer   64?
//   01:111 1:1 010  float32           *            F32
//   10:000 1:1 010  vec8-2                         8
//   10:001 1:1 010  string-3                       8
//   10:010 1:1 010  bytecode-3                     8
//   10:011 1:1 010  vec16-2                        16
//   10:100 1:1 010  vecflt32                       F32
//   10:101 1:1 010  vecflt64                       F64
//   10:110 1:1 010  vecflt128                      F128
//   10:111 1:1 010  float64           *            F64
//   11:000 1:1 010  vec8-3                         8
//   11:001 1:1 010  string-4                       8
//   11:010 1:1 010  bytecode-4                     8
// [[11:011 1:1 010  nativecode                     8]] NOT USED
//   11:100 1:1 010  (spare: 1 code)                X
//   11:101 1:1 010  (spare: 1 code)                X
//   11:110 1:1 010  (spare: 1 code)                X
//   11:111 1:1 010  float128          *            F128

// I have tests that let me discern the size of storage units within a
// vector. This matters for serialization and deserialization because the
// source and target machines may use different ordering for bytes within
// words etc.

// I use a bitmap scheme for all of these because that gives me uniformity
// and because I do not believe that special treatment of any of the
// case would do much better. I expect that strings and bignums will be
// the most common cases.

static inline bool vector_i8(Header h)
{   return ((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

static inline bool vector_i16(Header h)
{   return ((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

static inline bool vector_i32(Header h)
{   return ((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

static inline bool vector_i64(Header h)
{   return ((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

static inline bool vector_i128(Header h)
{   return ((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

static inline bool vector_f32(Header h)
{   return ((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

static inline bool vector_f64(Header h)
{   return ((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

static inline bool vector_f128(Header h)
{   return ((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

// I have made the allocation so that any header of the form xx1:11x1:g010
// is the header of a number.


#define TYPE_BIGNUM         ( 0x1f <<Tw)
#define TYPE_RATNUM         ( 0x1d <<Tw)
#define TYPE_COMPLEX_NUM    ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT   ( 0x3f <<Tw)
#define TYPE_DOUBLE_FLOAT   ( 0x5f <<Tw)
#define TYPE_LONG_FLOAT     ( 0x7f <<Tw)

static inline Header& numhdr(LispObject v)
{   return *(Header *)((char *)(v) - TAG_NUMBERS);
}

static inline Header& flthdr(LispObject v)
{   return *(Header *)((char *)(v) - TAG_BOXFLOAT);
}

//
// The following tests are valid provided that n is already known to
// have tag TAG_NUMBERS, i.e. it is a bignum, ratio or complex.
//
static inline bool is_ratio(LispObject n)
{   return type_of_header(numhdr(n)) == TYPE_RATNUM;
}

static inline bool is_complex(LispObject n)
{   return type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM;
}

static inline bool is_bignum_header(Header h)
{   return type_of_header(h) == TYPE_BIGNUM;
}

static inline bool is_bignum(LispObject n)
{   return is_bignum_header(numhdr(n));
}

static inline bool is_string_header(Header h)
{   return (type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1;
}

static inline bool is_string(LispObject n)
{   return is_string_header(vechdr(n));
}

static inline bool is_vec8_header(Header h)
{   return (type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1;
}

static inline bool is_vec8(LispObject n)
{   return is_vec8_header(vechdr(n));
}

static inline bool is_bps_header(Header h)
{   return (type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1;
}

static inline bool is_bps(LispObject n)
{   return is_bps_header(vechdr(n));
}

static inline bool is_vec16_header(Header h)
{   return (type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1;
}

static inline bool is_vec16(LispObject n)
{   return is_vec16_header(vechdr(n));
}

static inline bool is_bitvec_header(Header h)
{   return  (type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1;
}

static inline bool is_bitvec(LispObject n)
{   return is_bitvec_header(vechdr(n));
}

static inline LispObject& elt(LispObject v, size_t n)
{   return *(LispObject *)((char *)v +
                           (CELL-TAG_VECTOR) +
                           (n*sizeof(LispObject)));
}

static inline char& celt(LispObject v, size_t n)
{   return *((char *)(v) + (CELL-TAG_VECTOR) + n);
}

static inline unsigned char& ucelt(LispObject v, size_t n)
{   return *((unsigned char *)v + (CELL-TAG_VECTOR) + n);
}

static inline signed char& scelt(LispObject v, size_t n)
{   return *((signed char *)v + (CELL-TAG_VECTOR) + n);
}

#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)

static inline unsigned char* data_of_bps(LispObject v)
{   return (unsigned char *)v + BPS_DATA_OFFSET;
}


// In the serialization code I want to access the fields in a symbol as
// if that symbol was a vector and the fields were indexed as follows:
//  vselt(p, -1) : qheader(p)
//  vselt(p, 0)  : qvalue(p)
//  vselt(p, 1)  : qenv(p)
//  vselt(p, 2)  : qplist(p)
//  vselt(p, 3)  : qfastgets(p)
//  vselt(p, 4)  : qpackage(p)
//  vselt(p, 5)  : qpname(p)
// and I want vselt to apply to vectors too and do just what elt does in
// that case. I will also use vselt on things tagged as numbers (specifically
// RATIO and COMPLEX.

static inline LispObject& vselt(LispObject v, size_t n)
{   return *(LispObject *)(((intptr_t)v & ~((intptr_t)TAG_BITS)) +
                            ((1 + n)*sizeof(LispObject)));
}

//
// The next are for 16-bit & 32 bit values and single-float & double-float
// access. Note that halfwords are signed.
//
//
// In days of ancient history some systems did not support 16-bit values.
// Specifically the DEC Alpha compilers did not have a 16-bit data type and
// ARM did not support 16-bit usage at all well. However these days I intend
// to expect that int16_t will exist and will be something I can rely on.
//
static inline int16_t& helt(LispObject v, size_t n)
{   return *(int16_t *)((char *)v +
                        (CELL-TAG_VECTOR) +
                        n*sizeof(int16_t));
}

static inline intptr_t& ielt(LispObject v, size_t n)
{   return  *(intptr_t *)((char *)v +
                         (CELL-TAG_VECTOR) +
                         n*sizeof(intptr_t));
}

//
// Even on a 64-bit machine I will support packed arrays of 32-bit
// ints or short-floats.
//
static inline int32_t& ielt32(LispObject v, size_t n)
{   return *(int32_t *)((char *)v +
                        (CELL-TAG_VECTOR) +
                        n*sizeof(int32_t));
}

static inline float& felt(LispObject v, size_t n)
{   return *(float *)((char *)v +
                      (CELL-TAG_VECTOR) +
                      n*sizeof(float));
}

static inline double& delt(LispObject v, size_t n)
{   return *(double *)((char *)v +
                       (8-TAG_VECTOR) +
                       n*sizeof(double));
}

static inline bool is_header(LispObject x)
{   return ((int)x & (0x3<<Tw)) != 0; // valid if TAG_HDR_IMMED
}

static inline bool is_char(LispObject x)
{   return ((int)x & HDR_IMMED_MASK) == TAG_CHAR;
}

static inline bool is_spid(LispObject x)
{   return ((int)x & HDR_IMMED_MASK) == TAG_SPID;
}

static inline bool is_library(LispObject x)
{   return ((int)x & 0xfffff) == SPID_LIBRARY;
}

static inline unsigned int library_number(LispObject x)
{   return (x >> 20) & 0xfff;
}

//
// I will now support the full range of Unicode from U+0000 to U+10FFFF.
//
// Note that pack_char now takes a 21-bit code but only values up to
// 0x0010ffff are valid for Unicode. Internally I will generally pack
// things using utf-8 encoded strings.
//

// The absolute shift values here reflect the fact that I have (at least)
// 25 bits of payload in a CHAR object. It is not at all obvious to me that
// the Common Lisp "font" component of characters was a good idea to start
// with or that it has any respectable purpose today, and I only support
// 16 distinct "Font" codes when I am on 32-bit hardware.

static inline int font_of_char(LispObject n)
{   return ((int32_t)n >> (21+4+Tw)) & 0xf;
}

// The Common Lisp "bits" part of a character object no longer makes any sense!
static inline int bits_of_char(LispObject n)
{   return 0;
}

static inline unsigned int code_of_char(LispObject n)
{   return   ((uint32_t)(n) >>  (4+Tw)) & 0x001fffff;
}

static inline LispObject pack_char(int font, unsigned int code)
{   return (LispObject)((((uint32_t)(font)) << (21+4+Tw)) |
                        (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR);
}

//
// For internal purposes here I will use a pseudo-character with code
// 0x0010ffff to stand for an end of file marker. This can be packed as
// 4 bytes in utf-8 (f4/8f/bf/bf) and it is the last codepoint in the
// Unicode range and is reserved in Unicode as not being a valid
// character.
//
#define CHAR_EOF pack_char(0, 0x0010ffff)

typedef int32_t junk;      // Unused 4-byte field for structures (for padding)
typedef intptr_t junkxx;   // Unused cell-sized field for structures

typedef struct Symbol_Head
{
//
// TAG_SYMBOL has the value 4, so on a 32-bit system a pointer
// to a symbol points at the second word of it, ie the value cell. The
// effect in that case is that the selector CAR would access the value
// cell. For 64-bit addresses this pun will not work so easily.
//
// The fields marked with a "*" are pending a re-work.
    Header header;       // Standard format header for vector types
    LispObject value;    // Global or special value cell

    LispObject env;      // Extra stuff to help function cell
    LispObject plist;    // A list

    LispObject fastgets; // to speed up flagp and get
    LispObject package;  // Home package - a package object                  *

    LispObject pname;    // A string (always)
    intptr_t function0;  // Executable code always (no arguments)            *

    intptr_t function1;  // Executable code always (just 1 arg)
    intptr_t function2;  // Executable code always (just 2 args)

    intptr_t function3;  // Executable code always (just 3 args)             *
    union {
    intptr_t functionn;  // Executable code always (0, or >= 3 args)
    intptr_t function4;  // Executable code always (just 4 args)             *
    intptr_t function5up;// Executable code always (3 args + vector for rest)*
          };

    uint64_t count;      // for statistics
} Symbol_Head;


#define MAX_FASTGET_SIZE  63
// I have up to 63 "fast" tags for PUT/GET/FLAG/FLAGP

//
// The access macros are coded this way rather than using -> and
// a structure since this reveals directly what offsets are involved
// in the addressing, and so gives the C compiler an easier job!
// There are so many casts anyway that this is not so very bad really!
// I also use absolute numeric offsets (and do not use the offsetof
// macro) to stress that I view the store layout as fixed, and because
// offsetof is badly supported by some C compilers I have come across.
//
static inline Header& qheader(LispObject p)
{   return *(Header *)((char *)p + (0*CELL-TAG_SYMBOL));
}

static inline LispObject& qvalue(LispObject p)
{   return *(LispObject *)((char *)p + (1*CELL-TAG_SYMBOL));
}

static inline LispObject& qenv(LispObject p)
{   return *(LispObject *)((char *)p + (2*CELL-TAG_SYMBOL));
}

static inline LispObject& qplist(LispObject p)
{   return *(LispObject *)((char *)p + (3*CELL-TAG_SYMBOL));
}

static inline LispObject& qfastgets(LispObject p)
{   return *(LispObject *)((char *)p + (4*CELL-TAG_SYMBOL));
}

static inline LispObject& qpackage(LispObject p)
{   return *(LispObject *)((char *)p + (5*CELL-TAG_SYMBOL));
}

static inline LispObject& qpname(LispObject p)
{   return *(LispObject *)((char *)p + (6*CELL-TAG_SYMBOL));
}

// The ifn() selector gives access to the qfn() cell, but treating its
// contents as (intptr_t).
//
static inline intptr_t& ifn0(LispObject p)
{   return *(intptr_t *)((char *)p + (7*CELL-TAG_SYMBOL));
}

static inline intptr_t& ifn1(LispObject p)
{   return *(intptr_t *)((char *)p + (8*CELL-TAG_SYMBOL));
}

static inline intptr_t& ifn2(LispObject p)
{   return *(intptr_t *)((char *)p + (9*CELL-TAG_SYMBOL));
}

static inline intptr_t& ifn3(LispObject p)
{   return *(intptr_t *)((char *)p + (10*CELL-TAG_SYMBOL));
}

static inline intptr_t& ifnn(LispObject p)
{   return *(intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}

static inline intptr_t& ifn4(LispObject p)
{   return *(intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}

static inline no_args*& qfn0(LispObject p)
{   return *(no_args **)((char *)p + (7*CELL-TAG_SYMBOL));
}

static inline one_args*& qfn1(LispObject p)
{   return *(one_args **)((char *)p + (8*CELL-TAG_SYMBOL));
}

static inline two_args*& qfn2(LispObject p)
{   return *(two_args **)((char *)p + (9*CELL-TAG_SYMBOL));
}

static inline three_args*& qfn3(LispObject p)
{   return *(three_args **)((char *)p + (10*CELL-TAG_SYMBOL));
}

static inline n_args*& qfnn(LispObject p)
{   return *(n_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}

static inline four_args*& qfn4(LispObject p)
{   return *(four_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}

static inline uint64_t& qcount(LispObject p)
{   return *(uint64_t *)((char *)p + (12*CELL-TAG_SYMBOL));
}

typedef union _Float_union
{   float f;
    uint32_t i;
    float32_t f32;
} Float_union;

// The following macro clears any bits in a LispObject above the
// bottom 32.

static inline LispObject low32(LispObject a)
{   return (LispObject)(uint32_t)a;
}

typedef struct Big_Number
{
// see "arith.h" for a description of bignum formats
    Header h;
//
// EVEN when I have 64-bit addresses I will represent
// big-numbers as arrays of 32-bit values.  So I will still have to
// ensure that I end up with a rounded number of digits - but in the
// 64-bit case it will need to be an even number because the
// header word at the front of a bignum becomes 64-bits long.
//
    uint32_t d[1];  // generally more digits than this
} Big_Number;

static inline size_t bignum_length(LispObject b)
{   return length_of_header(numhdr(b));
}

static inline uint32_t* bignum_digits(LispObject b)
{   return (uint32_t *)((char *)b  + (CELL-TAG_NUMBERS));
}

// For work on bignums when I have a 64-bit machine I frequently need the
// top word of a bignum as a 64-bit (signed) value...
static inline int64_t bignum_digits64(LispObject b, size_t n)
{   return (int64_t)((int32_t *)((char *)b+(CELL-TAG_NUMBERS)))[n];
}


// make_bighdr takes an argument measured in 32-bit units, including space
// for the header word. This is the natural space unit used in the tagging
// scheme so I just need to shift the count to where it has to live.
static inline Header make_bighdr(size_t n)
{   return TAG_HDR_IMMED+TYPE_BIGNUM+(n<<(Tw+7));
}

// pack_hdrlength takes a length in 32-bit words (including the size of
// the header). NOTE VERY WELL that although the other header length packers
// take a count of items this one takes a length in 32-bit words!
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))

// pack_hdrlengthbytes takes a number of 32-bit words as an argument and
// adjusts it to go in a header.

//@#define pack_hdrlengthbits(n) ((31+(intptr_t)(n))<<(Tw+2))
//@#define pack_hdrlengthbytes(n) ((3+(intptr_t)(n))<<(Tw+5))
//@#define pack_hdrlengthhwords(n) ((1+(intptr_t)(n))<<(Tw+4))

#define make_padder(n) (pack_hdrlength((n)/4) + TYPE_VEC8_1 + TAG_HDR_IMMED)

typedef struct Rational_Number
{   Header header;
    LispObject num;
    LispObject den;
} Rational_Number;

static inline LispObject& numerator(LispObject r)
{   return ((Rational_Number *)((char *)r-TAG_NUMBERS))->num;
}

static inline LispObject& denominator(LispObject r)
{   return ((Rational_Number *)((char *)r-TAG_NUMBERS))->den;
}

typedef struct Complex_Number
{   Header header;
    LispObject real;
    LispObject imag;
} Complex_Number;

static inline LispObject& real_part(LispObject r)
{   return ((Complex_Number *)((char *)r-TAG_NUMBERS))->real;
}

static inline LispObject& imag_part(LispObject r)
{   return ((Complex_Number *)((char *)r-TAG_NUMBERS))->imag;
}

typedef struct Single_Float
{   Header header;
    union float_or_int
    {   float f;
        float32_t f32;
        int32_t i;
    } f;
} Single_Float;

static inline float& single_float_val(LispObject v)
{   return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f;
}

static inline float32_t& float32_t_val(LispObject v)
{   return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f32;
}

static inline int32_t& intfloat32_t_val(LispObject v)
{   return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.i;
}

//
// The structures here are not actually used - because I can not get
// as strong control of alignment as I would like. So I use macros that
// do address arithmetic explicitly for me...
//
//  typedef struct Double_Float
//  {
//      Header header;
//                            // SIXTY_FOUR_BIT is not a compile-time constant
//  #ifndef SIXTY_FOUR_BIT    // Can not do this #ifdef!!
//      junk padding;         // for 64-bit the header was 64 bits wide
//  #endif
//      union double_or_ints {
//          double f;         // padded to doubleword align the data.
//          float64_t f64;
//          int32_t i[2];
//          int64_t ii;
//      } f;
//  } Double_Float;
//

typedef union _Double_union
{   double f;
    uint32_t i[2];
    uint64_t i64;
    float64_t f64;

} Double_union;

#define SIZEOF_DOUBLE_FLOAT     16
static inline double *double_float_addr(LispObject v)
{   return (double *)((char *)v + (8-TAG_BOXFLOAT));
}

// on 32-bit machines there has to be a padding work in a double_float,
// and this lets me clear it out.
static inline int32_t& double_float_pad(LispObject v)
{   return *(int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}

static inline double& double_float_val(LispObject v)
{   return *(double *)((char *)v + (8-TAG_BOXFLOAT));
}

static inline float64_t& float64_t_val(LispObject v)
{   return *(float64_t *)((char *)v + (8-TAG_BOXFLOAT));
}

static inline int64_t& intfloat64_t_val(LispObject v)
{   return *(int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}

//
// Again I do not actually introduce the struct...
//
// For "long double" I use float128_t as implemented in the SoftFloat_3a
// library. This represents each float with 16-bits of exponent and 113
// bits of mantissa (including the hidden bit). Basic arithmetic is
// supported, but not the elemantary functions. I am going to ASSUME that
// everything can be aligned at 8-byte boundaries.
//
//  typedef struct Long_Float
//  {
//      Header header;
//  #ifndef SIXTY_FOUR_BIT  // Illegal #ifdef here!
//      junk padding;
//  #endif
//  What follows ALWAYS starts exactly 8 bytes on from the start
//  of the object, ie (8-TAG_BOXFLOAT) bytes on from the tagged pointer
//  that identifies it.
//      union long_or_ints {
//          float128_t f128;
//          int32_t i[4];
//          int64_t ii[2];
//      } f;
//  } Long_Float;
//

#define SIZEOF_LONG_FLOAT       24
static inline float128_t *long_float_addr(LispObject v)
{   return (float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}

static inline int32_t& long_float_pad(LispObject v)
{   return *(int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}

static inline float128_t& long_float_val(LispObject v)
{   return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}

static inline float128_t& float128_t_val(LispObject v)
{   return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}

static inline int64_t& intfloat128_t_val0(LispObject v)
{   return *(int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}

static inline int64_t& intfloat128_t_val1(LispObject v)
{   return *(int64_t *)((char *)v + (16-TAG_BOXFLOAT));
}

static inline uintptr_t word_align_up(uintptr_t n)
{   return (LispObject)((n + 3) & (-(uintptr_t)4U));
}

static inline uintptr_t doubleword_align_up(uintptr_t n)
{   return (uintptr_t)((n + 7) & (-(uintptr_t)8U));
}

static inline LispObject doubleword_align_up(LispObject n)
{   return (LispObject)(((uintptr_t)n + 7) & (-(uintptr_t)8U));
}

static inline uintptr_t doubleword_align_down(uintptr_t n)
{   return (uintptr_t)((intptr_t)n & (-(uintptr_t)8U));
}

static inline uintptr_t object_align_up(uintptr_t n)
{   return (uintptr_t)((n + sizeof(LispObject) - 1) &
                       (-(uintptr_t)sizeof(LispObject)));
}

static inline uintptr_t quadword_align_up(uintptr_t n)
{   return (uintptr_t)((n + 15) & (-(uintptr_t)16U));
}

static inline uintptr_t quadword_align_down(uintptr_t n)
{   return (uintptr_t)(n & (-(uintptr_t)16U));
}

//
// values to go in exit_reason at times when exceptions are being thrown.
//

#define UNWIND_NULL       0x0         // no error or action at all
#define UNWIND_GO         0x1         // GO, to support non-local case
#define UNWIND_RETURN     0x2         // RETURN, to support non-local
#define UNWIND_THROW      0x3         // THROW is obvious
#define UNWIND_RESTART    0x4         // (restart!-csl ...)
#define UNWIND_RESOURCE   0x5         // used with (resource!-limit ...)
#define UNWIND_SIGNAL     0x6         // SIGSEGV or other random signal
#define UNWIND_SIGINT     0x7         // SIGINT

#define UNWIND_FNAME      0x100       // at least short backtrace is needed
#define UNWIND_ARGS       0x200       // produce long form backtrace
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       // no backtrace, still an error

#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)

#endif // header_tags_h

// end of tags.h
