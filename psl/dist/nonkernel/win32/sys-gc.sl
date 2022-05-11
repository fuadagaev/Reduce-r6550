%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:SYSTEM-GC.SL                                             
% Title:          System dependent before and after GC hooks               
%                 Based on VAX version.                                    
% Author:         Eric Benson                                              
% Created:        5 March 1982                                             
% Modified:       29-Oct-84 09:08:15 (Vicki O'Day)
% Mode:           Lisp
% Status:         Open Source: BSD License
% Package:        Kernel                                                   
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                          
% Revisions:                                                               
%                                                                          
% 9-Jul-84 (Vicki O'Day)
%  Changed hooks be defined bothtimes instead of compiletime.
% 27-Feb-84 17:29:47 (RAM)                                                 
%  Changed File entry in header.                                           
%  Made the hooks just nil.                                                
% 2-Dec-83  16:00:00 (Brian Beach)                                         
%   Translated from Rlisp to Lisp.                                         
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
%                                                                          

(de beforegcsystemhook nil nil)

(de aftergcsystemhook nil nil)

(de alloc!-more!-heap (heap alloc min)
           (cond ((wlessp alloc  min) (error 5678 "Heap space low"))
                 (t min)))

(de printgcchainanchor()
  (prin2  "free memory block chain : ") (prin2t (wgetv gcchainanchor* 1))
  (prin2  "was ist das nur         : ") (prin2t (wgetv gcchainanchor* 2))
  (prin2  "heap min size           : ") (prin2t (wgetv gcchainanchor* 3))
  (prin2  "heap current size       : ") (prin2t (wgetv gcchainanchor* 4))
  (prin2  "heap max size           : ") (prin2t (wgetv gcchainanchor* 5))
  (prin2  "heap warn size          : ") (prin2t (wgetv gcchainanchor* 6))
  (prin2  "heap extend size        : ") (prin2t (wgetv gcchainanchor* 7))
  (prin2  "heap-alloc-size         : ") (prin2t (wgetv gcchainanchor* 8))
)

(de set_heap_extend_size (xx)
  (wputv gcchainanchor* 6 xx)
  (wputv gcchainanchor* 7 xx))
