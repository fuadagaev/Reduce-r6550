// allocate_test.cpp                       Copyright (C) 1989-2018 Codemist    

//
// Code for testing storage allocation
//

/**************************************************************************
 * Copyright (C) 2018, Codemist.                         A C Norman       *
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

// The code in allocate.cpp involves an experimental change in how storage
// management is done in CSL. The code here is a TEMPORARY framework of
// test code to activate and exercise it. When (and if) everything stablizes
// the new code will be used by the main system and this file will be
// removed. I will have stubs here for all sorts of bits of CSL that are
// referenced from allocate.cpp - only s few of them will be truly relevant
// for the testing.


#include "headers.h"

void global_longjmp()
{   printf("\nglobal_longjmp called\n");
    fflush(stdout);
    abort();
}

void term_printf(const char *fm, ...)
{   abort();
}

LispObject **get_stack_addr()
{   return NULL;
}

jmp_buf **get_global_jb_addr()
{   return NULL;
}

const volatile char *errorset_msg;

intptr_t miscflags;


void garbage_collect()
{
}

void my_abort()
{   abort();
}

//
// I use a Mersenne Twister pseudo-random generator from the C++11 library.
// For seeding it there is a severe misery in that the most obvious source
// of unpredictability, ie std::random_devivce, is deterministic on some
// platforms (including mingw32). So I seed my mersenene twister with
// something based on what it returns AND on the time of day (and on the
// identity of the current thread).
//

static std::random_device genuine_random;

static uint64_t my_genuine_random()
{   uint64_t r = genuine_random();
    r = 1234567*r ^ genuine_random();
    r = 7654321*r ^ genuine_random();
    size_t h1 = std::hash<std::thread::id>()(std::this_thread::get_id());
    size_t h2 = (size_t)time(NULL);
    size_t h3 = std::chrono::high_resolution_clock::
                                        now().time_since_epoch().count();
    return ((h1*UINT64_C(1415926535897932385) +
            h2*UINT64_C(7182818284590452354) +
            h3*UINT64_C(4142135623730950488)) ^ r) >> 21;
}

static std::mt19937 mersenne_twister(my_genuine_random());

int main(int argc, char *argv[])
{
    printf("Allocate test code\n");
    get_page_size();
    printf("page_size = %x\n", (int)page_size);
    set_up_signal_handlers();
    LispObject *m1 = (LispObject *)allocate_segment(4*1024*1024);
    LispObject *m2 = (LispObject *)allocate_segment(4*1024*1024);
    printf("segments at %p %p\n", m1, m2);
    for (int i=0; i<heap_segment_count; i++)
    {   printf("%d) %p %" PRIx64 "  %p\n", i,
            heap_segment[i],
            (uint64_t)heap_segment_size[i],
            heap_dirty_pages_bitmap[i]);
    }
    clear_bitmap(0);
    clear_bitmap(1);
    for (int i=0; i<20; i++)
    {   uintptr_t b = (uintptr_t)heap_segment[0];
        uintptr_t n = ((uintptr_t)mersenne_twister()) % heap_segment_size[0];
        printf("Access at offset %.10" PRIx64 " = %d\n",
               (uint64_t)n, (int)(n/page_size));
        *(char *)(b + n) = 1;
    }
    refresh_bitmap(0);
    uint64_t *w = heap_dirty_pages_bitmap[0];
    size_t nb = heap_segment_size[0]/page_size/64;
    for (size_t i=0; i<nb; i++)
    {   uint64_t k = w[i];
        for (int j=0; j<64; j++)
        {   putchar('0' + (int)(k & 1));
            k = k >> 1;
        }
    }
    printf("\n");
    return 0;
}



// end of allocate_test.cpp
