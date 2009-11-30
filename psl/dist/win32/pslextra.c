/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:PSLEXTRAS.C
% Description:  Miscellaneous support routines.
% Author:       RAM, HP/FSD
% Created:      9-Mar-84
% Modified:     21-Mar-85 11:25:52
% Mode:         Text
% Package:
% Status:       Experimental (Do Not Distribute)
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%

%

% (c) Copyright 1982, University of Utah

%

% Redistribution and use in source and binary forms, with or without

% modification, are permitted provided that the following conditions are met:
%

%
    * Redistributions of source code must retain the relevant copyright

%      notice, this list of conditions and the following disclaimer.

%
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
% 
%
% Revisions:
%
% 05-Apr-88 (Julian Padget)
%  Reinstated alarm and ualarm (again)
% 29-May-87 (Leigh Stoller & Harold Carr)
%  Added external_setenv and friends.
% 21-Mar-85 11:09:00 (Scott Marovich)
%  Rewrite "timc()" to return time since 1st call, and never cream LISP tag.
% 21-Feb-85 09:02:49 (Vicki O'Day)
%  Fixed bug in uxwritefloat - it was setting the length field of the printable
%  string incorrectly.
% 18-Jul-84 11:14:24 (RAM)
%  Added external_time.  Put call to expand_file_name in external_stat,
%  external_link, and external_unlink.
% 10-Jul-84 (Vicki O'Day)
%  Added external_stat, external_link and external_unlink.
% 29-Jun-84 14:15:53 (RAM)
%  Removed hp_quit (obsolete).
% 27-Jun-84 (Vicki O'Day)
%  Added external_strlen and external_getenv.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
 
#ifdef ALPHA
#define LONG __int64
#else
#define LONG long
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h> 


int external_alarm(sec)
unsigned LONG sec;
{
}
 
int external_ualarm(usec,repeat)
unsigned LONG usec,repeat;
{
}
 
char *expand_file_name();    /* from unix-io.c */


LONG external_time(tloc)
LONG *tloc;
{
  return ((LONG)time(tloc));
}
 
    
int external_stat(path, buf)
char *path;
struct stat *buf;
{
    return stat(expand_file_name(path), buf);
}
 

int external_link (path1, path2)
char *path1, *path2;
{
}
 

int external_unlink (path)
char *path;
{
}
 

int external_strlen (s)
     char *s;
{
    return strlen(s);
}
 

char *external_getenv (name)
     char *name;
{
   return (char *)getenv(name);
}
 
 
int external_setenv (var, val)
    char *var, *val;
{
 return(0); 
}
 
/*
 * sets the value of var to be arg in the Unix environment env.
 * Var should end with '=' (bindings are of the form "var=value").
 * This procedure assumes the memory for the first level of environ
 * was allocated using calloc, with enough extra room at the end so not
 * to have to do a realloc().
 */
setenv (var, value)
     char *var, *value;
{
    
}
 
block_copy (b1, b2, length)
     char *b1, *b2;
     int length;
{
  while (length-- > 0)
    *b2++ = *b1++;
}
 
#define LISPEOF  4      /* Lisp uses ctrl-D for end of file */
 
int unixreadrecord(fp, buf)
     FILE *fp;
     char *buf;
{
  int i;
  char c;
  for (i=0, c=' '; ((c != LISPEOF) && (c != '\n')); i++)
    {
      c = fgetc(fp);
      if (c == EOF )
    c = LISPEOF;
      *buf++ = c;
    }
  return i;
}
 
/* Tag( unixwriterecord )
 */
int unixwriterecord(fp, buf, count)
     FILE *fp;
     char *buf;
int  count;
{
  int i;
  for (i=0; i<count; i++, buf++)
    fputc(*buf, fp);
}
  

#ifdef ALPHA
sleep(LONG n){ Sleep(n*1000);}
#else 
sleep(LONG n){ _sleep(n*1000);}
#endif

fork(){}

int sbrk(){return(4711);}

LONG cremainder (x,y)
LONG x,y;

{ LONG cquotient ();
  return (x - y * cquotient (x,y));}

/* Error in C library, e.g. 156250000000000000/390625;
 2814749767106560 % 1125899906842624 */

LONG cquotient (x,y)
LONG x,y;

{ if (abs(x % y) == abs(y)) { if(x>0) x = x +1; else x = x-1;
                                 return (x/y);}
                  else return (x/y); } 


#ifdef ALPHA
LONG cflush(LONG adr,LONG len,LONG inv)
     {
       int n;
       n=FlushInstructionCache(GetCurrentProcess(),adr,len);
       /* printf("flush: %Lx,%Lx,%d\n",adr,len,n); */
      }
#endif    
