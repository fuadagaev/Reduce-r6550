// cuckoo-test.cpp                      Copyright (C) A C Norman, 2015-2020


/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
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

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cerrno>

#include "cuckoo.h"

// Here are the items to be hashed... Dummy data for now!

std::uint32_t items[] =
{
#ifdef FULL
    0x0194d8,    0x003c97,    0x0064f0,    0x0194db,    0x0194dc,
    0x00ca71,    0x0064f2,    0x0194df,    0x000008,    0x000009,
    0x00000a,    0x00000b,    0x00000c,    0x00000d,    0x00000e,
    0x00000f,    0x000010,    0x000011,    0x000012,    0x000013,
    0x000014,    0x000015,    0x000016,    0x000017,    0x000018,
    0x000019,    0x00001a,    0x00001b,    0x00001c,    0x00001d,
    0x00001e,    0x00001f,    0x005e52,    0x003ca7,    0x006500,
    0x00ca8f,    0x006501,    0x003ca9,    0x005e54,    0x003caa,
    0x000028,    0x005e55,    0x00002a,    0x00ca97,    0x00ca98,
    0x00002d,    0x00002e,    0x005e57,    0x000030,    0x000031,
    0x005e58,    0x000033,    0x000034,    0x000035,    0x000036,
    0x000037,    0x000038,    0x00caa5,    0x00003a,    0x00003b,
    0x00003c,    0x00003d,    0x00003e,    0x00caab,    0x00650f,
    0x000041,    0x000042,    0x000043,    0x000044,    0x000045,
    0x000046,    0x000047,    0x000048,    0x000049,    0x00004a,
    0x00004b,    0x00004c,    0x00004d,    0x00004e,    0x00004f,
    0x000050,    0x000051,    0x000052,    0x019407,    0x000054,
    0x000055,    0x000056,    0x000057,    0x000058,    0x000059,
    0x00651c,    0x00005b,    0x00005c,    0x00005d,    0x00002f,
    0x00005f,    0x000060,    0x000061,    0x000062,    0x000063,
    0x000064,    0x000065,    0x000066,    0x000067,    0x006523,
    0x000069,    0x00006a,    0x01940f,    0x00006c,    0x00006d,
    0x00006e,    0x00c9f2,    0x006527,    0x005e6d,    0x000039,
    0x000073,    0x000074,    0x000075,    0x00652a,    0x000077,
    0x000078,    0x000079,    0x005e70,    0x000029,    0x00007c,
    0x005e71,    0x00007e,    0x00c9fa,    0x00652f,    0x00002b,
    0x000082,    0x005e73,    0x00002c,    0x000085,    0x000086,
    0x000087,    0x000088,    0x000089,    0x006534,    0x00008b,
    0x01941a,    0x00008d,    0x00008e,    0x005e77,    0x006537,
    0x005e78,    0x000094,    0x000095,    0x000032,    0x000097,
    0x000098,    0x000099,    0x00009a,    0x00009b,    0x00009c,
    0x00009d,    0x00009e,    0x00009f,    0x0000a0,    0x0000a1,
    0x0000a2,    0x0000a3,    0x0000a4,    0x0000a5,    0x0000a6,
    0x005e7f,    0x0000a8,    0x0000a9,    0x019424,    0x0000ab,
    0x0000ac,    0x005e81,    0x006546,    0x0000af,    0x019426,
    0x0000b1,    0x006548,    0x0000b3,    0x00005a,    0x0000b5,
    0x0000b6,    0x0000b7,    0x00654b,    0x005e85,    0x0000ba,
    0x005e86,    0x00003f,    0x0000be,    0x005e87,    0x000040,
    0x0000c2,    0x0000c3,    0x0000c4,    0x01942d,    0x006552,
    0x0000c8,    0x0000c9,    0x0000ca,    0x005e8b,    0x006555,
    0x0000cd,    0x0000ce,    0x0000cf,    0x000068,    0x005e8d,
    0x006558,    0x0000d3,    0x006559,    0x00655a,    0x005e8f,
    0x00655b,    0x005e90,    0x00655d,    0x0000dd,    0x0000de,
    0x0000df,    0x000070,    0x0000e1,    0x0000e2,    0x0000e3,
    0x006561,    0x0000e5,    0x0000e6,    0x0000e7,    0x0000e8,
    0x0000e9,    0x0000ea,    0x0000eb,    0x0000ec,    0x0000ed,
    0x0000ee,    0x01943b,    0x0000f0,    0x0000f1,    0x01943c,
    0x0000f3,    0x006569,    0x005e99,    0x0000f6,    0x0000f7,
    0x0000f8,    0x000053,    0x00656c,    0x01943f,    0x00656d,
    0x0000fd,    0x00656e,    0x00656f,    0x000101,    0x000102,
    0x01002f,    0x005e9e,    0x003d19,    0x010030,    0x000107,
    0x000108,    0x000109,    0x00010a,    0x00010b,    0x00010c,
    0x019445,    0x00010e,    0x00010f,    0x000110,    0x000111,
    0x000112,    0x000113,    0x000114,    0x000115,    0x000116,
    0x000117,    0x019401,    0x019449,    0x00005e,    0x00011b,
    0x01944a,    0x00011d,    0x019404,    0x00011f,    0x019405,
    0x000121,    0x000122,    0x000123,    0x000124,    0x005ea9,
    0x006582,    0x000127,    0x000128,    0x000129,    0x01003c,
    0x01944f,    0x000096,    0x00012d,    0x006586,    0x00012f,
    0x01003e,    0x000131,    0x006588,    0x01003f,    0x019452,
    0x000135,    0x000136,    0x000137,    0x000138,    0x000139,
    0x00013a,    0x00013b,    0x00013c,    0x00013d,    0x00658e,
    0x00013f,    0x005eb2,    0x00006b,    0x006590,    0x019457,
    0x000144,    0x010045,    0x019418,    0x006593,    0x019459,
    0x0029c6,    0x00ca60,    0x01945a,    0x00006f,    0x010048,
    0x005eb7,    0x006597,    0x01941e,    0x000071,    0x0000aa,
    0x01945d,    0x000072,    0x01004b,    0x00659b,    0x003d43,
    0x019422,    0x01945f,    0x0000ae,    0x003d45,    0x005ebc,
    0x003d46,    0x00659f,    0x003d47,    0x0065a0,    0x01004f,
    0x005ebe,    0x00ca6d,    0x0065a2,    0x00ca6e,    0x0000b4,
    0x010051,    0x005ec0,    0x00ca70,    0x010052,    0x019465,
    0x00007a,    0x010053,    0x0000b8,    0x010054,    0x019467,
    0x01942f,    0x010055,    0x005ec4,    0x00007d,    0x0065ab,
    0x01511f,    0x0065ac,    0x010057,    0x005ec6,    0x00007f,
    0x010058,    0x005ec7,    0x000080,    0x010059,    0x005ec8,
    0x000081,    0x01005a,    0x005ec9,    0x019438,    0x01005b,
    0x01946e,    0x000083,    0x0065b4,    0x005ecb,    0x000084,
    0x01005d,    0x0065b6,    0x01943d,    0x00ca83,    0x0065b8,
    0x00ca84,    0x005ece,    0x00ca85,    0x019440,    0x019473,
    0x0065bb,    0x00ca87,    0x019442,    0x018028,    0x019443,
    0x00ca89,    0x0065be,    0x00ca8a,    0x005ed2,    0x00ca8b,
    0x0065c0,    0x01802c,    0x00008c,    0x010065,    0x0065c2,
    0x01802e,    0x010066,    0x019479,    0x0065c4,    0x018030,
    0x01947a,    0x018031,    0x01944c,    0x01947b,    0x0000d8,
    0x00ca86,    0x005ed8,    0x018034,    0x01006a,    0x01947d,
    0x0065ca,    0x00ca88,    0x005eda,    0x018037,    0x0065cc,
    0x005edb,    0x0065cd,    0x00ca99,    0x019454,    0x00ca9a,
    0x0065cf,    0x00ca9b,    0x019456,    0x00ca8c,    0x015138,
    0x01803d,    0x019458,    0x005edf,    0x0000e4,    0x01803f,
    0x01513a,    0x018040,    0x01945b,    0x005ee1,    0x0065d6,
    0x00caa2,    0x018043,    0x008747,    0x018044,    0x0065d9,
    0x018045,    0x019488,    0x018046,    0x019461,    0x018047,
    0x019462,    0x018048,    0x019463,    0x018049,    0x0000ef,
    0x005ee7,    0x0065df,    0x01804b,    0x005ee8,    0x00caac,
    0x0000f2,    0x005ee9,    0x0065e2,    0x01804e,    0x0000f4,
    0x01804f,    0x01946a,    0x01948f,    0x0065e5,    0x00cab1,
    0x005eec,    0x018052,    0x01946d,    0x005eed,    0x0065e8,
    0x00ca9c,    0x005eee,    0x0000a7,    0x019470,    0x018056,
    0x0065eb,    0x018057,    0x005ef0,    0x018058,    0x00ca9f,
    0x019495,    0x019474,    0x01805a,    0x005ef2,    0x01805b,
    0x00caa1,    0x005ef3,    0x0065f1,    0x01805d,    0x005ef4,
    0x0000ad,    0x000104,    0x005ef5,    0x000105,    0x018060,
    0x000106,    0x01947c,    0x018062,    0x0000b0,    0x005ef8,
    0x018064,    0x00caa7,    0x018065,    0x0000b2,    0x018066,
    0x005efa,    0x018067,    0x00010d,    0x005efb,    0x019483,
    0x018069,    0x005efc,    0x01806a,    0x008761,    0x005efd,
    0x019486,    0x008762,    0x005efe,    0x01806d,    0x008763,
    0x01806e,    0x019489,    0x01806f,    0x005f00,    0x0000b9,
    0x00caaf,    0x005f01,    0x006606,    0x008766,    0x0194a6,
    0x003daf,    0x01948e,    0x018740,    0x00011a,    0x008768,
    0x005f04,    0x003db2,    0x003db3,    0x019492,    0x010097,
    0x0194aa,    0x003db5,    0x019494,    0x005f07,    0x0000c0,
    0x003db7,    0x005f08,    0x01807c,    0x01009a,    0x005f09,
    0x019498,    0x01009b,    0x0194ae,    0x01807f,    0x000125,
    0x005f0b,    0x000126,    0x01009d,    0x01949c,    0x01009e,
    0x005f0d,    0x006618,    0x01009f,    0x00012a,    0x00012b,
    0x0194b3,    0x00012c,    0x0100a1,    0x0194a2,    0x018088,
    0x0100a2,    0x005f11,    0x0194a4,    0x0100a3,    0x000130,
    0x0100a4,    0x005f13,    0x000132,    0x0100a5,    0x0194a8,
    0x006623,    0x0194b9,    0x006624,    0x003dcc,    0x005f16,
    0x003dcd,    0x006626,    0x003dce,    0x006627,    0x0100a9,
    0x006628,    0x018094,    0x006629,    0x018095,    0x00662a,
    0x005370,    0x005371,    0x0100ac,    0x005373,    0x00013e,
    0x005375,    0x0194b4,    0x01809a,    0x005378,    0x01809b,
    0x0194b6,    0x00537b,    0x005f1e,    0x01809d,    0x00537e,
    0x01809e,    0x005380,    0x005381,    0x005382,    0x005383,
    0x005384,    0x005f21,    0x005386,    0x005387,    0x005388,
    0x0180a3,    0x0194be,    0x018760,    0x00538c,    0x00538d,
    0x018761,    0x0180a6,    0x0100b6,    0x005391,    0x0194c2,
    0x0180a8,    0x005394,    0x0180a9,    0x0194c4,    0x0194cb,
    0x0194c5,    0x0180ab,    0x00539a,    0x003de8,    0x00539c,
    0x0180ad,    0x0194c8,    0x00539f,    0x0194ce,    0x0053a1,
    0x0194ca,    0x0053a3,    0x0053a4,    0x0180b1,    0x0053a6,
    0x0053a7,    0x0053a8,    0x0053a9,    0x0053aa,    0x0053ab,
    0x0053ac,    0x0053ad,    0x0194d0,    0x0053af,    0x00520d,
    0x0053b1,    0x0194d4,    0x0053b3,    0x0053b4,    0x0053b5,
    0x0053b6,    0x0053b7,    0x0053b8,    0x0053b9,    0x0194d6,
    0x0194d7,    0x006651,    0x0053bd,    0x006652,    0x0053bf,
    0x0194d9,    0x01518f,    0x0194da,    0x0053c3,    0x015190,
    0x0053c5,    0x0053c6,    0x0053c7,    0x0194dd,    0x0180c3,
    0x015192,    0x0180c4,    0x006659,    0x0180c5,    0x00665a,
    0x0180c6,    0x0194de,    0x0180c7,    0x0194e2,    0x015195,
    0x0053d4,    0x0087a0,    0x0194e0,    0x0180ca,    0x0053d8,
    0x0194e1,    0x0194e6,    0x0053db,    0x005f3e,    0x0180cd,
    0x006662,    0x0194e3,    0x0053e0,    0x0053e1,    0x0194e4,
    0x0053e3,    0x0053e4,    0x0194e5,    0x0053e6,    0x0053e7,
    0x0053e8,    0x0053e9,    0x0053ea,    0x0194e7,    0x0053ec,
    0x0053ed,    0x0053ee,    0x0053ef,    0x0053f0,    0x0053f1,
    0x0053f2,    0x0053f3,    0x0053f4,    0x0053f5,    0x0053f6,
    0x005f47,    0x000100,    0x0053f9,    0x0053fa,    0x0053fb,
    0x0053fc,    0x0053fd,    0x0053fe,    0x0053ff,    0x005f4a,
    0x000103,    0x005402,    0x005403,    0x005404,    0x005405,
    0x005406,    0x005407,    0x005408,    0x005409,    0x00540a,
    0x0180e4,    0x00540c,    0x00540d,    0x00540e,    0x005f4f,
    0x005410,    0x005411,    0x005f50,    0x005413,    0x005414,
    0x005415,    0x005416,    0x0100e3,    0x005418,    0x0180eb,
    0x006680,    0x005f53,    0x00541c,    0x0180ed,    0x00541e,
    0x00541f,    0x0100e6,    0x0180ef,    0x005422,    0x005423,
    0x005f56,    0x0180f1,    0x005426,    0x0180f2,    0x005428,
    0x005429,    0x00542a,    0x00542b,    0x00542c,    0x005f59,
    0x00542e,    0x00542f,    0x005430,    0x0180f7,    0x005432,
    0x005433,    0x005434,    0x005435,    0x005f5c,    0x005437,
    0x005438,    0x005439,    0x00543a,    0x0180fc,    0x00543c,
    0x00543d,    0x00543e,    0x00543f,    0x000118,    0x0100f1,
    0x005442,    0x000119,    0x005444,    0x018101,    0x005446,
    0x0100f3,    0x005448,    0x005449,    0x00544a,    0x005f63,
    0x00011c,    0x018105,    0x00544e,    0x018106,    0x005450,
    0x005451,    0x00011e,    0x018108,    0x005454,    0x018109,
    0x005456,    0x005f67,    0x000120,    0x005459,    0x005f68,
    0x00545b,    0x00545c,    0x00545d,    0x00545e,    0x00545f,
    0x005460,    0x005461,    0x010806,    0x005463,    0x005464,
    0x005465,    0x005466,    0x005467,    0x005468,    0x005469,
    0x00546a,    0x00546b,    0x0151c8,    0x018115,    0x01080c,
    0x00546f,    0x0066ab,    0x018117,    0x005472,    0x005473,
    0x01080f,    0x005475,    0x005476,    0x005477,    0x005478,
    0x005479,    0x0066b0,    0x00547b,    0x00547c,    0x00547d,
    0x00547e,    0x00547f,    0x005480,    0x005481,    0x00012e,
    0x005483,    0x005484,    0x005485,    0x005486,    0x00038f,
    0x005488,    0x005489,    0x0151d2,    0x00548b,    0x00548c,
    0x00548d,    0x00548e,    0x00548f,    0x005490,    0x000133,
    0x005492,    0x005493,    0x000134,    0x005495,    0x005496,
    0x005497,    0x01010e,    0x005499,    0x00549a,    0x01010f,
    0x005f7e,    0x00549d,    0x00549e,    0x00549f,    0x0054a0,
    0x0054a1,    0x0054a2,    0x0054a3,    0x010112,    0x0054a5,
    0x0054a6,    0x0054a7,    0x005f82,    0x0054a9,    0x0054aa,
    0x005f83,    0x0054ac,    0x0054ad,    0x0054ae,    0x0054af,
    0x0054b0,    0x005f85,    0x0054b2,    0x0054b3,    0x0054b4,
    0x0054b5,    0x010118,    0x005f87,    0x0147a0,    0x0147a1,
    0x0054ba,    0x0054bb,    0x01011a,    0x005f89,    0x0054be,
    0x0054bf,    0x010835,    0x0054c1,    0x01011c,    0x0151e5,
    0x010837,    0x0054c5,    0x0151e6,    0x0054c7,    0x0054c8,
    0x005f8d,    0x01083a,    0x0054cb,    0x0151e8,    0x0054cd,
    0x0054ce,    0x005f8f,    0x0054d0,    0x0054d1,    0x0054d2,
    0x0054d3,    0x0147bc,    0x0151eb,    0x010840,    0x0054d7,
    0x0151ec,    0x0054d9,    0x0054da,    0x0151ed,    0x0054dc,
    0x0054dd,    0x0151ee,    0x0054df,    0x0066e3,    0x0151ef,
    0x010846,    0x0054e3,    0x0054e4,    0x0054e5,    0x010848,
    0x0054e7,    0x0054e8,    0x0054e9,    0x0151f2,    0x0054eb,
#endif
    0x0054ec,    0x0054ed,    0x0054ee,    0x0054ef,    0x01084d,
    0x0054f2,    0x0054f3,    0x0054f4,    0x0054f5,    0x0054f6
};


static std::uint32_t cuckoo_inline get_key(void *p)
{   return (*reinterpret_cast<std::uintptr_t *>(p)) & 0x0007ffff;
}

static void cuckoo_inline set_key(void *p, std::uint32_t v)
{   *reinterpret_cast<std::uint32_t *>(p) = (v & 0x0007ffff) |
                                            (*reinterpret_cast<std::uint32_t *>(p) & 0xfff80000);
}

// Here I make my largest possible table size such that it would only
// end up with 50% occupancy. This should be hideously pessimistic.

std::uint32_t table[2*sizeof(items)/sizeof(items[0])];

static int cuckoo_inline importance(std::uint32_t key)
{   if (key <= 0x40) return CUCKOO_VITAL;
    else if (key <= 0x4000 || key >= 0x010000 ) return CUCKOO_IMPORTANT;
    else return CUCKOO_STANDARD;
}

int main(int argc, char *argv[])
{   int i;
    CREATEMUTEX;
    CREATELOGMUTEX;
    cuckoo_parameters r = cuckoo_binary_optimise(
                              items,
                              sizeof(items)/sizeof(items[0]),
                              importance,
                              table,
                              sizeof(table[0]),
                              sizeof(items)/sizeof(items[0])-1, // initial table size = item_count-1
                              sizeof(table)/sizeof(table[0]),   // max table size
                              get_key,
                              set_key,
                              1);
    if (r.table_size == -1)
    {   std::printf("Failed. Extra info = %d\n", r.modulus2);
        return 1;
    }
    std::printf("For %d items the table is %d long (%.2f%% full)\n",
                static_cast<int>(sizeof(items)/sizeof(items[0])),
                r.table_size,
                (100.0*sizeof(items))/(r.table_size*sizeof(items[0])));
    std::printf("modulus2 = %d offset2 = %d\n", r.modulus2, r.offset2);
    for (i=0; i<r.table_size; i++)
        std::printf("%5d: %.8x\n", i, table[i]);
    return 0;
}

// end of cuckoo-test.cpp
