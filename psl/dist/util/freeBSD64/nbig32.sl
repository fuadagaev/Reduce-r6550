%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXU:NBIG32.SL 
% Description:  Vector based BIGNUM package with INUM operations 
% Author:       Winfried Neun
% Created:      25 December 2004
% Modified:	
% Mode:         Lisp 
% Package:      Utilities 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(load vector-fix double32 nbig32a) %% mbarith)

(de gcdn(u v)
%  U and v are integers. Value is absolute value of gcd of u and v.
   (if (eqn v 0) (abs u)
     (gcdn v (remainder u v))))

(de fix (x)
        (case (wand (wplus2 (tag x) 1) 31)  
           ((0 1 2 3) x)                % posint negint fixnum bignum
           ((4)   (floatfix x))               %floatnum            
           (nil   (nonnumber1error x 'fix))
))


