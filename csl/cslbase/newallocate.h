// newallocate.h                          Copyright (C) Codemist, 1990-2019


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

#ifndef header_newallocate_h
#define header_newallocate_h 1

// alloc_segment grabs a chunk of memory of the given size, which must
// be a multiple of CSL_PAGE_SIZE. The memory block is recorded in a table
// that can hold up to 32 segments.

extern void set_up_signal_handlers();
extern void *allocate_segment(size_t);

// These arrays record information about allocated segments. heap_segment[i]
// is the base address of a segment. (heap_segment_count keeps track of
// how many have been allocated). and heap_segment_size[i] records the
// amount of user data in it.

extern size_t heap_segment_count;
extern void *heap_segment[32];
extern size_t heap_segment_size[32];

extern size_t free_pages_count, active_pages_count;

// Given an arbitrary bit-pattern the find_heap_segment() function tests
// if it could be an address within one of the allocated segments, and if so
// it returns the index into heap_segments[] that is relevant. If it is not
// a valid address the value -1 is returned.

int find_heap_segment(uintptr_t p);

// Low level functions for allocating objects.

// Entry to a garbage collector.

extern void garbage_collect();

#endif // header_newallocate_h

// end of newallocate.h

