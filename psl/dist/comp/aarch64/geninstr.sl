%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         GENINSTR
% Description:  armv8/aarch64 Generate instruction set
% Author:       Rainer Sch�pf
% Created:
% Modified:
% Mode:         Lisp
% Package:
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% Note form of DefOpcode, similar to DefAnyreg or DefCmacro
%      A trailing OpFailure will be appended unless (T is used)
%      Currently TESTs require arguments and explicit AND
 
% (DefOpCode OP (ARGS)
%   ( (tests) (actions))
%   ( (tests) (actions))
% ....
% )
 
(fluid '(lengthfunctions))
(setq lengthfunctions
      '((OP-reg-imm8 . lth-reg-imm8 )
%	(OP-regn-imm8 . lth-regn-imm8 )
%	(OP-regd-imm8 . lth-regd-imm8 )
	(OP-reg-shifter . lth-reg-shifter )
%	(OP-regn-shifter . lth-regn-shifter )
%	(OP-regd-shifter . lth-regd-shifter )
	(OP-reg3 . lth-reg3)
	(OP-mul3 . lth-mul3)
	(OP-mul4 . lth-mul4)
	(OP-ld-st . lth-ld-st)
%	(OP-ld-st-misc . lth-ld-st-misc)
%	(OP-ldm-stm . lth-ldm-stm)
	(OP-streg . lth-streg)
	(OP-clz . lth-clz)
	(OP-branch-imm . lth-branch-imm)
	(OP-branch-imm19 . lth-branch-imm19)
	(OP-branch-reg . lth-branch-reg)
%	(OP-mov-imm16 . lth-mov-imm16)
	(OP-reg-imm16 . lth-reg-imm16)
	(OP-reg-imm12 . lth-reg-imm12)	
	(OP-reg-logical . lth-reg-logical)
	(OP-reg-regsp . lth-reg-regsp)
	(OP-regsp-reg . lth-regsp-reg)
	(OP-reg-reg . lth-reg-reg)
	(OP-reg-extended . lth-reg-extended)
	(OP-reg2 . lth-reg2)
	(OP-reg3-lsb . lth-reg3-lsb)
	(OP-ldp-stp . lth-ldp-stp)
	(OP-reg-Xbfm . lth-reg-Xbfm)
	(OP-reg-Xbfx . lth-reg-Xbfx)
	(OP-reg-Xbfiz . lth-reg-Xbfiz)
	(OP-reg-XxtX . lth-reg-XxtX)
	(OP-reg-Xsl . lth-reg-Xsl)
	(OP-reg-Xsr . lth-reg-Xsr)
	(OP-bfm . lth-bfm)
	(OP-bfc . lth-bfc)
	(OP-bfi . lth-bfi)
	(OP-bfxil . lth-bfxil)
	(OP-fcvt . lth-fcvt)
	(OP-fp-arith . lth-fp-arith)
	(OP-fcmp . lth-fcmp)
      ))
 
(load strings compiler)
(DE SORT (LST FN)
   (PROG (TREE)
      (COND ((OR (NULL LST) (NULL (CDR LST))) (RETURN LST)))
      (SETQ TREE (LIST (CAR LST) NIL))
      (WHILE (PAIRP (SETQ LST (CDR LST))) (TREEADD (CAR LST) TREE FN))
      (RETURN (TREE2LIST TREE NIL))))
(DE TREE2LIST (TREE LST)
   (COND
      ((NULL TREE) LST)
      (T (TREE2LIST
	    (CADR TREE)
	    (CONS (CAR TREE) (TREE2LIST (CDDR TREE) LST)))) ))
(DE TREEADD (ITEM NODE FN)
   (COND
      ((APPLY FN (list ITEM (CAR NODE)))
	 (COND
	    ((CADR NODE) (TREEADD ITEM (CADR NODE) FN))
	    (T (RPLACA (CDR NODE) (LIST ITEM NIL)))) )
      ((CDDR NODE) (TREEADD ITEM (CDDR NODE) FN))
      (T (RPLACD (CDR NODE) (LIST ITEM NIL)))) )
 
% instructions are generated by a patterns:
%
% each instruction ID has a slot INSTRCASES where the different
% possible cases are collected. When all instructions are complete,
% the final defOpCode calls are generated from these slots
 
(fluid '(allInstrs!* allInstrPatterns!* formalParameters!* instr* instrlist!*))
 
(setq formalParameters!* '(par1 par2 par3 par4))
 
(ds newInstruction (i) (when (not (memq i allInstrs!*)) (push i allInstrs!*)))

    
(df instr (l)
     (prog (name operands format namelist)
       (setq instr* l)
       (setq name (pop l))
       (setq operands (pop l))
       (setq format (pop l))
       (when (null (assoc format lengthfunctions))
	 (prin2t "unknown format : ") (print format))
       (return (instr1 l name  operands format)))
     )


(de instr1 (l name operands format)
    (prog (gname code n pat)
    % instruction list
       (push (list l name operands format) instrlist*)
       (put name 'argno (length operands))
    % simple instruction
       (newInstruction name)
       (setq code (mkquote l))
       (setq pat (mktest format code operands NIL))
       (push pat (get name 'INSTRCASES))
       (push (subla lengthfunctions pat) (get name 'LENGTHCASES))
       (setq gname name)
       (setq code (cdr l))
       (push (list name (car l) format operands) allInstrPatterns!*)
    %  (set format (cons (mkdisass code name operands) (eval format)))
       (return nil)
))


(de mktest (format code operands rev)
   (prog (params lhs rhs type val)
      (setq params formalParameters!*)
  loop (when (null operands) (go ready))
      (setq type (operandtype (pop operands)))
      (if   (not (eqcar type 'UNQUOTE))
	    (push (append type (list (car params))) lhs)
	    (progn
	       (setq params (cons(cadr type) (cdr params))) % artific. param
	       (setq type '(QUOTE))))
      (if   (not (eqcar type 'EQUAL))
	    (setq rhs(append rhs (list (pop params))))
	    (pop params))
      (go loop)
  ready
     (if (null lhs)(setq lhs '(T)))
     (when rev (setq rhs (reverse  rhs)))
     (return (if (cdr lhs)
		`((and .,(reversip lhs))(,format ,code ., rhs))
		`(,(car lhs)(,format ,code ., rhs))))
    ))

(de operandtype (op)
    (cond ((eqcar op 'QUOTE) (list 'EQUAL op))
	  ((eqcar op 'UNQUOTE) op)
	  ((eq op 'reg)'(REGP))
	  ((eq op 'reg32)'(REG32P))	
	  ((eq op 'reg-nonzero)'(reg-nonzero-p))
	  ((eq op 'reg32-nonzero)'(reg32-nonzero-P))	
	  ((eq op 'reg)'(REGP))
	  ((eq op 'reg32)'(REG32P))	
	  ((eq op 'reg-or-sp) '(reg-or-sp-p))
	  ((eq op 'reg32-or-sp) '(reg32-or-sp-p))
	  ((eq op 'reg-sp) '(reg-sp-p))
	  ((eq op 'reg32-sp) '(reg32-sp-p))
	  ((eq op 'regfp8) '(regfp8p))
	  ((eq op 'regfp16) '(regfp16p))
	  ((eq op 'regfp32) '(regfp32p))
	  ((eq op 'regfp64) '(regfp64p))
	  ((eq op 'regfp128) '(regfp128p))
%	  ((eq op 'evenreg)'(evenREGP)) 
	  ((eq op 'streg)'(streg-p))
	  ((eq op 'imm) '(STDIMMEDIATEP))
%	  ((eq op 'imm16) '(sixteenbit-p))
	  ((eq op 'imm19) '(nineteenbit-p))
	  ((eq op 'imm8-rotated) '(imm8-rotatedp))
	  ((eq op 'imm12-shifted) '(imm12-shiftedp))
	  ((eq op 'imm16-shifted) '(imm16-shiftedp))
	  ((eq op 'imm-logical) '(imm-logical-p))
	  ((eq op 'imm7) '(imm7-p))
	  ((eq op 'reg-or-sp-imm9-post) '(reg-or-sp-imm9-post-p))
	  ((eq op 'reg-or-sp-imm9-pre) '(reg-or-sp-imm9-pre-p))
	  ((eq op 'reg-or-sp-imm9) '(reg-or-sp-imm9-p))
	  ((eq op 'reg-or-sp-imm10-post) '(reg-or-sp-imm10-post-p))
	  ((eq op 'reg-or-sp-imm10-pre) '(reg-or-sp-imm10-pre-p))
	  ((eq op 'reg-or-sp-imm10) '(reg-or-sp-imm10-p))
	  ((eq op 'reg-or-sp-simm9-post) '(reg-or-sp-simm9-post-p))
	  ((eq op 'reg-or-sp-simm9-pre) '(reg-or-sp-simm9-pre-p))
	  ((eq op 'reg-or-sp-simm9) '(reg-or-sp-simm9-p))
	  ((eq op 'reg-or-sp-pimm12) '(reg-or-sp-pimm12-p))
	  ((eq op 'reg-or-sp-pimm13) '(reg-or-sp-pimm13-p))
	  ((eq op 'reg-or-sp-pimm14) '(reg-or-sp-pimm14-p))
	  ((eq op 'reg-or-sp-pimm15) '(reg-or-sp-pimm15-p))
	  ((eq op 'reg-or-sp-pimm16) '(reg-or-sp-pimm16-p))
	  ((eq op 'lsb) '(lsb-p))
	  ((eq op 'reg-or-sp-shifter) '(reg-or-sp-shifter-p))
	  ((eq op 'reg-shifter) '(reg-shifter-p))
	  ((eq op 'reg32-shifter) '(reg32-shifter-p))
	  ((eq op 'reg-extended) '(reg-extended-p))
	  ((eq op 'reg32-extended) '(reg32-extended-p))
	  ((eq op 'reg-offset8) '(reg-offset8-p))
	  ((eq op 'reg-offset12) '(reg-offset12-p))
	  ((eq op 'offset19) '(offset19-p))
	  ((eq op 'offset26) '(offset26-p))
	  ((eq op 'pm-reg-shifter) '(pm-reg-shifter-p))
	  ((eq op 'reg-indirect) '(reg-indirect-p))
	  ((eq op 'idloc) '(idlocp))
	  ((eq op 'effa) '(EFFAP))
	  ((eq op 'mem) '(MEMORYP))
	  ((eq op 'shortlabel) '(SHORTLABELP))
	  ((eq op 'adr) '(adrp))
	  ((eq op 'indadr) '(indirectadrp))
	  ((eq op 'five-bit) '(five-bit-p))
	  ((eq op 'six-bit) '(six-bit-p))
	  (t (prin2t "unknown operand type during instruction generation:")
	     (prin2t op)
	     (prin2t instr*)
	     (error  nil))))


(de parameterlist (n) (parameterlist1 n formalParameters!*))
 
(de parameterlist1(n l)
   (if (eqn n 0) nil (cons (car l)(parameterlist1(difference n 1)(cdr l)))))
 
% clear all instructions
(de clearInstructions ()
    (setq allInstrPatterns!* nil)
    (mapc allInstrs!* (function(lambda(u)(remprop u 'INSTRCASES))))
    (setq allInstrs!* nil))
 
% make a disassemble-record
(de mkdisass(code gname operands)
    `(,code (NAME . ,gname) (PAT . ,(dissasemblepat operands))))
 
(de dissasemblepat(o)  % special handling for quotes
   (cond ((atom o) o)
	 ((eqcar (car o) 'QUOTE) (cons (cadr (car o)) (cdr o)))
	 ((eqcar (car o) 'UNQUOTE) (cdr o))
	 (T (cons (car o) (dissasemblepat (cdr o))))))
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% 1st application: generation of defOpcode file
%
 
(de collectInstructions (file)
   (when file (setq file (open file 'OUTPUT)) (wrs file))
   (setq allInstrs!* (sort allInstrs!* (function string-lessp)))
   (mapc allInstrs!* (function makeOneInstruction))
   (when file (wrs nil) (close file)))
 
(de makeOneInstruction (u)
  (prog(v vv)
  (setq v
   `(DefOpcode ,u 
                  ,(parameterlist (get u 'ARGNO))
		 .,(reverse (get u 'INSTRCASES))))
  (eval (list 'pp v))
  
  (setq v
   `(DefOpLength ,u 
                    ,(parameterlist (get u 'ARGNO))
		 .,(reverse (get u 'LENGTHCASES))))
  (eval (list 'pp v))
 (terpri)))
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% 2nd  application: generation of conversion hexcode -> opcode
%

(de displayInstructions(f)
    (prog (u v)
       (setq u (sort instrlist* (function instrcmp)))
       (when f (setq v (wrs (open f 'OUTPUT))))
       (prin2t "   Aarch64 instructions sorted by opcode")
       (prin2t "   =====================================")
       (terpri)
       (mapc u (function printinstr))
       (terpri)(terpri)
       (prin2t "   Aarch64 instructions sorted by name")
       (prin2t "   ===================================")
       (setq u (sort instrlist* (function instrcmpalpha)))
       (mapc u (function printinstr))
       (terpri)

       (when f (wrs v))))
 
(de instrcmp (u v) 
     (or (lessp (caar u)(caar v))
	 (and (equal (caar u)(caar v)) (cdar u)(cdar v)
	      (lessp (cadar u)(cadar v)))))
 
(de instrcmpalpha(u v)
     (or (string-lessp (cadr u) (cadr v))
	 (and (equal (cadr u) (cadr v))
	      (instrcmp u v))))

(de printinstr (l)
	    (prininstrhex (caar l))
    (tab 3) (when (cdar l) (prininstrhex (cadar l))
			   (prin2 " /") (prin2 (land (lsh (cadar l)-3) 7)))
    (tab 10) (prin2 (cadr l))
    (tab 18) (when (caddr l) (prin2l (caddr l)))
    (tab 40) (print (cdddr l)))
 
(de prininstrhex (n)
   (if (eq n 'rex) (prin2 'rex)
      (prininstrhex1 (land 15 (lshift n -4))) (prininstrhex1 (land n 15))))
 
(de prininstrhex1 (n) (prin2 (getv [0 1 2 3 4 5 6 7 8 9 a b c d e f] n)))
 
	      


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% the instructions in the sequence defined by the 
%% Programmer's Reference Manual
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(clearInstructions)

(instr ADC (reg32 reg32 reg32)     OP-reg3 2#00011010000)
(instr ADC (reg reg reg)           OP-reg3 2#10011010000)
(instr ADCS (reg32 reg32 reg32)    OP-reg3 2#00111010000)
(instr ADCS (reg reg reg)          OP-reg3 2#10111010000)

(instr ADD (reg32-or-sp reg32-or-sp reg32-extended)  OP-reg-extended  2#00001011001)
(instr ADD (reg-or-sp reg-or-sp reg-extended)        OP-reg-extended  2#10001011001)
(instr ADD (reg32-or-sp reg32-or-sp imm12-shifted)   OP-reg-imm12     2#000100010)
(instr ADD (reg-or-sp reg-or-sp imm12-shifted)   OP-reg-imm12     2#100100010)
(instr ADD (reg32 reg32 reg32-shifter)     OP-reg-shifter   2#00001011000)
(instr ADD (reg reg reg-shifter)     OP-reg-shifter   2#10001011000)
(instr ADDS (reg32 reg32-or-sp reg32-extended)    OP-reg-extended  2#00101011001)
(instr ADDS (reg32 reg32-or-sp imm12-shifted)   OP-reg-imm12     2#001100010)
(instr ADDS (reg reg-or-sp imm12-shifted)   OP-reg-imm12     2#101100010)
(instr ADDS (reg32 reg32 reg32-shifter)     OP-reg-shifter   2#00101011000)
(instr ADDS (reg reg reg-shifter)     OP-reg-shifter   2#10101011000)

% ADR
% ADRP

(instr AND (reg32-or-sp reg32 imm-logical)      OP-reg-logical     2#000100100)
(instr AND (reg-or-sp reg imm-logical)      OP-reg-logical     2#100100100)
(instr AND (reg32 reg32 reg32-shifter)      OP-reg-shifter   2#00001010000)
(instr AND (reg reg reg-shifter)      OP-reg-shifter   2#10001010000)
(instr ANDS (reg32 reg32 imm-logical)     OP-reg-logical     2#011100100)
(instr ANDS (reg reg imm-logical)     OP-reg-logical     2#111100100)
(instr ANDS (reg32 reg32 reg32-shifter)     OP-reg-shifter   2#01101010000)
(instr ANDS (reg reg reg-shifter)     OP-reg-shifter   2#11101010000)

% ASR
% ASRV

(instr B!.EQ (offset19)    OP-branch-imm19 2#01010100 2#0000)
(instr B!.NE (offset19)    OP-branch-imm19 2#01010100 2#0001)
(instr B!.CS (offset19)    OP-branch-imm19 2#01010100 2#0010)
(instr B!.CC (offset19)    OP-branch-imm19 2#01010100 2#0011)
(instr B!.MI (offset19)    OP-branch-imm19 2#01010100 2#0100)
(instr B!.PL (offset19)    OP-branch-imm19 2#01010100 2#0101)
(instr B!.VS (offset19)    OP-branch-imm19 2#01010100 2#0110)
(instr B!.VC (offset19)    OP-branch-imm19 2#01010100 2#0111)
(instr B!.HI (offset19)    OP-branch-imm19 2#01010100 2#1000)
(instr B!.LS (offset19)    OP-branch-imm19 2#01010100 2#1001)
(instr B!.GE (offset19)    OP-branch-imm19 2#01010100 2#1010)
(instr B!.LT (offset19)    OP-branch-imm19 2#01010100 2#1011)
(instr B!.GT (offset19)    OP-branch-imm19 2#01010100 2#1100)
(instr B!.LE (offset19)    OP-branch-imm19 2#01010100 2#1101)
(instr B!.AL (offset19)    OP-branch-imm19 2#01010100 2#1111)

(instr B  (offset26)         OP-branch-imm 2#000101)

(instr BFM (reg32 reg32 five-bit five-bit) OP-bfm 2#0011001100)
(instr BFM (reg reg six-bit six-bit)       OP-bfm 2#1011001101)

%% Aliases of BFM
(instr BFC (reg32 five-bit five-bit) OP-bfc 2#0011001100)
(instr BFC (reg six-bit six-bit)       OP-bfc 2#1011001101)
(instr BFI (reg32 reg32-nonzero five-bit five-bit) OP-bfi 2#0011001100)
(instr BFI (reg reg-nonzero six-bit six-bit)       OP-bfi 2#1011001101)
(instr BFXIL (reg32 reg32 five-bit five-bit) OP-bfxil 2#0011001100)
(instr BFXIL (reg reg six-bit six-bit)       OP-bfxil 2#1011001101)

(instr BIC  (reg32 reg32 reg32-shifter)     OP-reg-shifter 2#00001010001)
(instr BIC  (reg reg reg-shifter)     OP-reg-shifter 2#10001010001)
(instr BICS  (reg32 reg32 reg32-shifter)     OP-reg-shifter 2#01101010001)
(instr BICS  (reg reg reg-shifter)     OP-reg-shifter 2#11101010001)

(instr BL  (offset26)        OP-branch-imm 2#100101)

(instr BLR (reg)            OP-branch-reg 2#11010110001)
(instr BR (reg)              OP-branch-reg 2#11010110000)

% CBNZ
% CBZ

% CCMN
% CCMP

% CFINV
% CINC
% CINV

(instr CLS (reg32 reg32) OP-clz 2#01011010110 2#00000 2#000101)
(instr CLS (reg reg)     OP-clz 2#11011010110 2#00000 2#000101)
(instr CLZ (reg32 reg32) OP-clz 2#01011010110 2#00000 2#000100)
(instr CLZ (reg reg)     OP-clz 2#11011010110 2#00000 2#000100)

(instr CMN   (reg32-or-sp reg32-extended)        OP-reg-extended 2#00101011001)
(instr CMN   (reg-or-sp reg-extended)        OP-reg-extended 2#10101011001)
(instr CMN   (reg32-or-sp imm12-shifted)        OP-reg-imm12  2#001100010)
(instr CMN   (reg32 imm12-shifted)        OP-reg-imm12  2#101100010)
(instr CMN   (reg32 reg32-shifter)         OP-reg-shifter 2#00101011000)
(instr CMN   (reg reg-shifter)         OP-reg-shifter 2#10101011000)

(instr CMP   (reg32 reg32-extended)        OP-reg-extended 2#01101011000)
(instr CMP   (reg reg-extended)        OP-reg-extended 2#11101011000)
(instr CMP   (reg32 imm12-shifted)        OP-reg-imm12    2#011100010)
(instr CMP   (reg imm12-shifted)        OP-reg-imm12    2#111100010)
(instr CMP   (reg32 reg32-shifter)         OP-reg-shifter 2#01101011000)
(instr CMP   (reg reg-shifter)         OP-reg-shifter 2#11101011000)

% CMPP
% CNEG

% CSEL
% CSET
% CSETM
% CSINC
% CSINV
% CSNEG

(instr EON  (reg32 reg32 reg32-shifter)     OP-reg-shifter 2#01001010001)
(instr EON  (reg reg reg-shifter)     OP-reg-shifter 2#11001010001)

(instr EOR  (reg32 reg32 imm-logical)     OP-reg-logical    2#0101001000)
(instr EOR  (reg reg imm-logical)     OP-reg-logical    2#0101001000)
(instr EOR  (reg32 reg32 reg32-shifter)     OP-reg-shifter 2#11001010000)
(instr EOR  (reg reg reg-shifter)     OP-reg-shifter 2#11001010000)

(instr EXTR   (reg32 reg32 reg32 lsb)        OP-reg3-lsb   2#0100100111)
(instr EXTR   (reg reg reg lsb)        OP-reg3-lsb   2#100100111)

% LDP Xt1, Xt2, [Xn], #imm7 (post-index)
(instr LDP  (reg32 reg32 reg-or-sp-imm9-post)  OP-ldp-stp 2#0010100011)
(instr STP  (reg32 reg32 reg-or-sp-imm9-post)  OP-ldp-stp 2#0010100010)
(instr LDP  (reg reg reg-or-sp-imm10-post)     OP-ldp-stp 2#1010100011)
(instr STP  (reg reg reg-or-sp-imm10-post)     OP-ldp-stp 2#1010100010)

% LDP Xt1, Xt2, [Xn, #imm7]! (pre-index)
(instr LDP  (reg32 reg32 reg-or-sp-imm9-pre)   OP-ldp-stp 2#0010100111)
(instr LDP  (reg reg reg-or-sp-imm10-pre)      OP-ldp-stp 2#1010100111)
(instr STP  (reg32 reg32 reg-or-sp-imm9-pre)   OP-ldp-stp 2#0010100110)
(instr STP  (reg reg reg-or-sp-imm10-pre)      OP-ldp-stp 2#1010100110)

% LDP Xt1, Xt2, [Xn, #imm7] (signed offset)
(instr LDP  (reg32 reg32 reg-or-sp-imm9)       OP-ldp-stp 2#0010100101)
(instr LDP  (reg reg reg-or-sp-imm10)          OP-ldp-stp 2#1010100101)
(instr STP  (reg32 reg32 reg-or-sp-imm9)       OP-ldp-stp 2#0010100100)
(instr STP  (reg reg reg-or-sp-imm10)          OP-ldp-stp 2#1010100100)

% LDPSW Xt1, Xt2, Xn, #imm (post-index)
(instr LDPSW  (reg reg reg-or-sp-simm9-post)   OP-ldp-stp 2#0110100011)

% LDPSW Xt1, Xt2, [Xn, #imm]! (pre-index)
(instr LDPSW  (reg reg reg-or-sp-simm9-pre)    OP-ldp-stp 2#0110100111)

% LDPSW Xt1, Xt2, Xn, #imm (signed offset)
(instr LDPSW  (reg reg reg-or-sp-simm9)        OP-ldp-stp 2#0110100101)

% LDR Xt, [Xn], #simm9 - post-index
% (LDR (reg t) (postindex (reg n) +/-number))
(instr LDR (reg32 reg-or-sp-simm9-post)      OP-ld-st 2#10111000010 2#01)
(instr LDR (reg reg-or-sp-simm9-post)      OP-ld-st 2#11111000010 2#01)
(instr STR (reg32 reg-or-sp-simm9-post)      OP-ld-st 2#10111000000 2#01)
(instr STR (reg reg-or-sp-simm9-post)      OP-ld-st 2#11111000000 2#01)
% LDR Xt,[Xn,#simm9]! - pre-index
% (LDR (reg t) (preindex (reg n) +/-number))
(instr LDR (reg32 reg-or-sp-simm9-pre)      OP-ld-st 2#10111000010 2#11)
(instr LDR (reg reg-or-sp-simm9-pre)      OP-ld-st 2#11111000010 2#11)
(instr STR (reg32 reg-or-sp-simm9-pre)      OP-ld-st 2#10111000000 2#11)
(instr STR (reg reg-or-sp-simm9-pre)      OP-ld-st 2#11111000000 2#11)

% LDR Xt,[Xn,#pimm14/15] - unsigned offset
% (LDR (reg t) (displacement (reg n) +number))
(instr LDR (reg32 reg-or-sp-pimm14)      OP-ld-st 2#1011100101 nil)
(instr LDR (reg reg-or-sp-pimm15)      OP-ld-st 2#1111100101 nil)
(instr STR (reg32 reg-or-sp-pimm14)      OP-ld-st 2#1011100100 nil)
(instr STR (reg reg-or-sp-pimm15)      OP-ld-st 2#1111100100 nil)

% LDR Xt, <label> - literal
(instr LDR (reg32 offset19)       OP-ld-st 2#00011000)
(instr LDR (reg offset19)       OP-ld-st 2#01011000)

% LDR Xt,[Xn]
% (LDR (reg t) (indirect (reg n)))
% (LDR (reg t) (displacement (reg n) 0))
(instr LDR (reg32 reg-indirect)       OP-ld-ST 2#1011100101 nil)
(instr LDR (reg reg-indirect)       OP-ld-ST 2#1111100101 nil)
(instr STR (reg32 reg-indirect)       OP-ld-ST 2#1011100100 nil)
(instr STR (reg reg-indirect)       OP-ld-ST 2#1111100100 nil)

% LDR Xt,[Xn,Xm]
% (LDR (reg t) (indexed (reg n) (reg m)))
% LDR Xt,[Xn,Xm,lsl #3]
% LDR Xt,[Xn,Wm,sxtw/uxtw]
% (LDR (reg t) (indexed (reg n) (regshifted m LSL amount)))
(instr LDR (reg32 reg-or-sp-shifter)   OP-ld-st 2#10111000011 2#10)
(instr LDR (reg reg-or-sp-shifter)   OP-ld-st 2#11111000011 2#10)
(instr STR (reg32 reg-or-sp-shifter)   OP-ld-st 2#10111000001 2#10)
(instr STR (reg reg-or-sp-shifter)   OP-ld-st 2#11111000001 2#10)

% LDUR
% LDURB
% LDURH
% LDURSB
% LDURSH
% LDURSW

% LSL
% LSLV
% LSR
% LSRV

(instr MADD   (reg32 reg32 reg32 reg32)  OP-mul4      2#00011011000 0)
(instr MADD   (reg reg reg reg)          OP-mul4      2#10011011000 0)

(instr MSUB   (reg32 reg32 reg32 reg32)  OP-mul4      2#00011011000 1)
(instr MSUB   (reg reg reg reg)          OP-mul4      2#10011011000 1)

(instr MNEG   (reg32 reg32 reg32)        OP-mul3      2#00011011000 1 2#11111)
(instr MNEG   (reg reg reg)              OP-mul3      2#10011011000 1 2#11111)

(instr NEG   (reg reg reg-shifter)     OP-reg-shifter 2#11001011000)
(instr NEGS  (reg reg reg-shifter)     OP-reg-shifter 2#11101011000)

(instr NGC   (reg reg reg-shifter)     OP-reg-shifter 2#11011010000)
(instr NGCS  (reg reg reg-shifter)     OP-reg-shifter 2#11111010000)

(instr ORN   (reg reg reg-shifter)     OP-reg-shifter 2#10101010001)

(instr ORR   (reg reg imm-logical)      OP-reg-logical 2#1011001000)
(instr ORR   (reg reg reg-shifter)     OP-reg-shifter 2#10101010000)

(instr SUB   (reg reg reg-extended)     OP-reg-extended  2#11001011001)
(instr SUB   (reg reg reg-shifter)     OP-reg-shifter  2#11001011000)
(instr SUB   (reg32-or-sp reg32-or-sp imm12-shifted) OP-reg-imm12     2#010100010)
(instr SUB   (reg-or-sp reg-or-sp imm12-shifted)     OP-reg-imm12     2#110100010)

(instr SBC   (reg reg reg-shifter)     OP-reg-shifter  2#1101101000)

(instr TST   (reg reg-shifter)         OP-reg-shifter 2#1101010000)
(instr TST   (reg imm-logical)         OP-reg-logical   2#11100100)

(instr UBFM  (reg32 reg32 five-bit five-bit) OP-reg-Xbfm     2#0101001100)
(instr UBFM  (reg reg six-bit six-bit)       OP-reg-Xbfm     2#1101001101)

%% Aliases of UBFM
(instr UBFX  (reg32 reg32 five-bit five-bit) OP-reg-Xbfx     2#0101001100)
(instr UBFX  (reg reg six-bit six-bit)       OP-reg-Xbfx     2#1101001101)
(instr UBFIZ (reg32 reg32 five-bit five-bit) OP-reg-Xbfiz    2#0101001100)
(instr UBFIZ (reg reg six-bit six-bit)       OP-reg-Xbfiz    2#1101001101)
(instr UXTB  (reg32 reg32)                   OP-reg-XxtX     2#0001001100 7)
(instr UXTH  (reg32 reg32)                   OP-reg-XxtX     2#0001001100 15)
(instr LSL   (reg32 reg32 five-bit)          OP-reg-Xsl      2#0101001100)
(instr LSL   (reg reg five-bit)              OP-reg-Xsl      2#1101001101)
(instr LSR   (reg32 reg32 five-bit)          OP-reg-Xsr      2#0101001100)
(instr LSR   (reg reg five-bit)              OP-reg-Xsr      2#1101001101)

(instr SBFM  (reg32 reg32 five-bit five-bit) OP-reg-Xbfm     2#0001001100)
(instr SBFM  (reg reg six-bit six-bit)       OP-reg-Xbfm     2#1001001101)

%% Aliases of SBFM
(instr SBFX  (reg32 reg32 five-bit five-bit) OP-reg-Xbfx     2#0001001100)
(instr SBFX  (reg reg six-bit six-bit)       OP-reg-Xbfx     2#1001001101)
(instr SBFIZ (reg32 reg32 five-bit five-bit) OP-reg-Xbfiz    2#0001001100)
(instr SBFIZ (reg reg six-bit six-bit)       OP-reg-Xbfiz    2#1001001101)
(instr SXTB  (reg32 reg32)                   OP-reg-XxtX     2#0001001100 7)
(instr SXTB  (reg reg)                       OP-reg-XxtX     2#1001001101 7)
(instr SXTH  (reg32 reg32)                   OP-reg-XxtX     2#0001001100 15)
(instr SXTH  (reg reg)                       OP-reg-XxtX     2#1001001101 15)
(instr SXTW  (reg reg32)                     OP-reg-XxtX     2#1001001101 31)
(instr ASR   (reg32 reg32 five-bit)          OP-reg-Xsr      2#0001001100)
(instr ASR   (reg reg five-bit)              OP-reg-Xsr      2#1001001101)

(instr MOV   (reg32 reg32-sp)          OP-reg-regsp  2#000100010)
(instr MOV   (reg reg-sp)              OP-reg-regsp  2#100100010)
(instr MOV   (reg32-sp reg32)          OP-regsp-reg  2#000100010)
(instr MOV   (reg-sp reg)              OP-regsp-reg  2#100100010)
(instr MOV   (reg32 reg32)             OP-reg-reg    2#00101010000)
(instr MOV   (reg reg)                 OP-reg-reg    2#10101010000)
(instr MOV   (reg imm16-shifted)       OP-reg-imm16   2#010100101)
(instr MVN   (reg32 reg32-shifter)     OP-reg-shifter 2#001010100)
(instr MVN   (reg reg-shifter)         OP-reg-shifter 2#101010100)

(instr MOVN  (reg32 imm16-shifted)     OP-reg-imm16    2#000100101)
(instr MOVN  (reg imm16-shifted)       OP-reg-imm16    2#100100101)
(instr MOVZ  (reg32 imm16-shifted)     OP-reg-imm16    2#010100101)
(instr MOVZ  (reg imm16-shifted)       OP-reg-imm16    2#110100101)

(instr SDIV  (reg32 reg32 reg32)        OP-mul3      2#00011010110 0 2#00011)
(instr SDIV  (reg reg reg)              OP-mul3      2#10011010110 0 2#00011)
(instr UDIV   (reg32 reg32 reg32)       OP-mul3      2#00011010110 0 2#00010)
(instr UDIV   (reg reg reg)             OP-mul3      2#10011010110 0 2#00010)

(instr MUL    (reg32 reg32 reg32)             OP-mul3      2#00011011000 0 2#11111)
(instr MUL    (reg reg reg)             OP-mul3      2#10011011000 0 2#11111)
(instr UMADDL (reg reg32 reg32 reg)         OP-mul4      2#10011011101 0)
(instr UMSUBL (reg reg32 reg32 reg)         OP-mul4      2#10011011101 1)
(instr UMNEG (reg reg32 reg32)              OP-mul3      2#10011011101 1 2#11111)
(instr UMULL  (reg reg32 reg32)             OP-mul3      2#10011011101 0 2#11111)
(instr UMULH  (reg reg reg)             OP-mul3      2#10011011110 0 2#11111)
(instr SMADDL (reg reg32 reg32 reg)         OP-mul4      2#10011011001 0)
(instr SMSUBL (reg reg32 reg32 reg)         OP-mul4      2#10011011001 1)
(instr SMNEGL (reg reg32 reg32)         OP-mul3      2#10011011001 1 2#11111)
(instr SMULL  (reg reg32 reg32)             OP-mul3      2#10011011001 0 2#11111)
(instr SMULH  (reg reg reg)             OP-mul3      2#10011011010 0 2#11111)

(instr RBIT   (reg reg)                 OP-reg2      2#11011010110)
(instr RET    ()                 OP-branch-reg    2#11010110010 X30)
(instr RET    (reg)                 OP-branch-reg    2#11010110010)
(instr REV    (reg reg)                 OP-reg2      2#11011010110)


(instr MRS (reg streg)   OP-streg 2#110101010011)
%(instr MSR (MSR *cond*) (streg imm8-rotated) OP-MSR 2#0011001 0  ... ) 
%(instr MSR (MSR *cond*) (streg reg)      OP-MSR 2#0001001 0 2#0000)

(instr LDRB (reg32 reg-or-sp-simm9-post)  OP-ld-st 2#00111000010 2#01)
(instr STRB (reg32 reg-or-sp-simm9-post)  OP-ld-st 2#00111000000 2#01)
(instr LDRB (reg32 reg-or-sp-simm9-pre)   OP-ld-st 2#00111000010 2#11)
(instr STRB (reg32 reg-or-sp-simm9-pre)   OP-ld-st 2#00111000000 2#11)
(instr LDRB (reg32 reg-or-sp-pimm12)      OP-ld-st 2#0011100101 nil)
(instr STRB (reg32 reg-or-sp-pimm12)      OP-ld-st 2#0011100100 nil)
(instr LDRB (reg32 reg-indirect)          OP-ld-st 2#0011100101 nil)
(instr STRB (reg32 reg-indirect)          OP-ld-st 2#0011100100 nil)
(instr LDRB (reg32 reg-or-sp-shifter)     OP-ld-st 2#00111000011 2#10)
(instr STRB (reg32 reg-or-sp-shifter)     OP-ld-st 2#00111000001 2#10)

(instr LDRH (reg32 reg-or-sp-simm9-post)  OP-ld-st 2#01111000010 2#01)
(instr STRH (reg32 reg-or-sp-simm9-post)  OP-ld-st 2#01111000000 2#01)
(instr LDRH (reg32 reg-or-sp-simm9-pre)   OP-ld-st 2#01111000010 2#11)
(instr STRH (reg32 reg-or-sp-simm9-pre)   OP-ld-st 2#01111000000 2#11)
(instr LDRH (reg32 reg-or-sp-pimm13)      OP-ld-st 2#0111100101 nil)
(instr STRH (reg32 reg-or-sp-pimm13)      OP-ld-st 2#0111100100 nil)
(instr LDRH (reg32 reg-indirect)          OP-ld-st 2#0111100101 nil)
(instr STRH (reg32 reg-indirect)          OP-ld-st 2#0111100100 nil)
(instr LDRH (reg32 reg-or-sp-shifter)     OP-ld-st 2#01111000011 2#10)
(instr STRH (reg32 reg-or-sp-shifter)     OP-ld-st 2#01111000001 2#10)

(instr LDRSB (reg32 reg-or-sp-simm9-post) OP-ld-st 2#00111000110 2#01)
(instr LDRSB (reg reg-or-sp-simm9-post)   OP-ld-st 2#00111000100 2#01)
(instr LDRSB (reg32 reg-or-sp-simm9-pre)  OP-ld-st 2#00111000110 2#11)
(instr LDRSB (reg reg-or-sp-simm9-pre)    OP-ld-st 2#00111000100 2#11)
(instr LDRSB (reg32 reg-or-sp-pimm12)     OP-ld-st 2#0011100111 nil)
(instr LDRSB (reg reg-or-sp-pimm12)       OP-ld-st 2#0011100110 nil)
(instr LDRSB (reg32 reg-indirect)         OP-ld-st 2#0011100111 nil)
(instr LDRSB (reg reg-indirect)           OP-ld-st 2#0011100110 nil)
(instr LDRSB (reg32 reg-or-sp-shifter)    OP-ld-st 2#00111000111 2#10)
(instr LDRSB (reg reg-or-sp-shifter)      OP-ld-st 2#00111000101 2#10)

(instr LDRSH (reg32 reg-or-sp-simm9-post) OP-ld-st 2#01111000110 2#01)
(instr LDRSH (reg reg-or-sp-simm9-post)   OP-ld-st 2#01111000100 2#01)
(instr LDRSH (reg32 reg-or-sp-simm9-pre)  OP-ld-st 2#01111000110 2#11)
(instr LDRSH (reg reg-or-sp-simm9-pre)    OP-ld-st 2#01111000100 2#11)
(instr LDRSH (reg32 reg-or-sp-pimm13)     OP-ld-st 2#0111100111 nil)
(instr LDRSH (reg reg-or-sp-pimm13)       OP-ld-st 2#0111100110 nil)
(instr LDRSH (reg32 reg-indirect)         OP-ld-st 2#0111100111 nil)
(instr LDRSH (reg reg-indirect)           OP-ld-st 2#0111100110 nil)
(instr LDRSH (reg32 reg-or-sp-shifter)    OP-ld-st 2#01111000111 2#10)
(instr LDRSH (reg reg-or-sp-shifter)      OP-ld-st 2#01111000101 2#10)

(instr LDRSW (reg reg-or-sp-simm9-post)   OP-ld-st 2#10111000100 2#01)
(instr LDRSW (reg reg-or-sp-simm9-pre)    OP-ld-st 2#10111000100 2#11)
(instr LDRSW (reg reg-or-sp-pimm14)       OP-ld-st 2#1011100110 nil)
(instr LDRSW (reg reg-indirect)           OP-ld-st 2#1011100110 nil)
(instr LDRSW (reg offset19)               OP-ld-st 2#10011000)
(instr LDRSW (reg reg-or-sp-shifter)      OP-ld-st 2#10111000101 2#10)

%% Floating point instructions

% LDR Dt, [Xn], #simm9 - post-index
% (LDR (reg Dt) (postindex (reg n) +/-number))
(instr LDR (regfp8 reg-or-sp-simm9-post)       OP-ld-st 2#00111100010 2#01)
(instr LDR (regfp16 reg-or-sp-simm9-post)      OP-ld-st 2#01111100010 2#01)
(instr LDR (regfp32 reg-or-sp-simm9-post)      OP-ld-st 2#10111100010 2#01)
(instr LDR (regfp64 reg-or-sp-simm9-post)      OP-ld-st 2#11111100010 2#01)
(instr LDR (regfp128 reg-or-sp-simm9-post)     OP-ld-st 2#00111100110 2#01)
(instr STR (regfp8 reg-or-sp-simm9-post)       OP-ld-st 2#00111100000 2#01)
(instr STR (regfp16 reg-or-sp-simm9-post)      OP-ld-st 2#01111100000 2#01)
(instr STR (regfp32 reg-or-sp-simm9-post)      OP-ld-st 2#10111100000 2#01)
(instr STR (regfp64 reg-or-sp-simm9-post)      OP-ld-st 2#11111100000 2#01)
(instr STR (regfp128 reg-or-sp-simm9-post)     OP-ld-st 2#00111100100 2#01)

% LDR Dt, [Xn, #simm9]! - pre-index
% (LDR (reg Dt) (preindex (reg n) +/-number))
(instr LDR (regfp8 reg-or-sp-simm9-pre)        OP-ld-st 2#00111100010 2#11)
(instr LDR (regfp16 reg-or-sp-simm9-pre)       OP-ld-st 2#01111100010 2#11)
(instr LDR (regfp32 reg-or-sp-simm9-pre)       OP-ld-st 2#10111100010 2#11)
(instr LDR (regfp64 reg-or-sp-simm9-pre)       OP-ld-st 2#11111100010 2#11)
(instr LDR (regfp128 reg-or-sp-simm9-pre)      OP-ld-st 2#00111100110 2#11)
(instr STR (regfp8 reg-or-sp-simm9-pre)        OP-ld-st 2#00111100000 2#11)
(instr STR (regfp16 reg-or-sp-simm9-pre)       OP-ld-st 2#01111100000 2#11)
(instr STR (regfp32 reg-or-sp-simm9-pre)       OP-ld-st 2#10111100000 2#11)
(instr STR (regfp64 reg-or-sp-simm9-pre)       OP-ld-st 2#11111100000 2#11)
(instr STR (regfp128 reg-or-sp-simm9-pre)      OP-ld-st 2#00111100100 2#11)

% LDR Dt,[Xn,#pimm14/15] - unsigned offset
% (LDR (reg Dt) (displacement (reg n) +number))
(instr LDR (regfp8 reg-or-sp-pimm12)           OP-ld-st 2#0011110101 nil)
(instr LDR (regfp16 reg-or-sp-pimm13)          OP-ld-st 2#0111110101 nil)
(instr LDR (regfp32 reg-or-sp-pimm14)          OP-ld-st 2#1011110101 nil)
(instr LDR (regfp64 reg-or-sp-pimm15)          OP-ld-st 2#1111110101 nil)
(instr LDR (regfp128 reg-or-sp-pimm16)         OP-ld-st 2#0011110111 nil)
(instr STR (regfp8 reg-or-sp-pimm12)           OP-ld-st 2#0011110100 nil)
(instr STR (regfp16 reg-or-sp-pimm13)          OP-ld-st 2#0111110100 nil)
(instr STR (regfp32 reg-or-sp-pimm14)          OP-ld-st 2#1011110100 nil)
(instr STR (regfp64 reg-or-sp-pimm15)          OP-ld-st 2#1111110100 nil)
(instr STR (regfp128 reg-or-sp-pimm16)         OP-ld-st 2#0011110110 nil)

% LDR Xt,[Xn]
% (LDR (reg t) (indirect (reg n)))
(instr LDR (regfp8 reg-indirect)               OP-ld-ST 2#0011110101 nil)
(instr LDR (regfp16 reg-indirect)              OP-ld-ST 2#0111110101 nil)
(instr LDR (regfp32 reg-indirect)              OP-ld-ST 2#1011110101 nil)
(instr LDR (regfp64 reg-indirect)              OP-ld-ST 2#1111110101 nil)
(instr LDR (regfp128 reg-indirect)             OP-ld-ST 2#0011110111 nil)
(instr STR (regfp8 reg-indirect)               OP-ld-ST 2#0011110100 nil)
(instr STR (regfp16 reg-indirect)              OP-ld-ST 2#0111110100 nil)
(instr STR (regfp32 reg-indirect)              OP-ld-ST 2#1011110100 nil)
(instr STR (regfp64 reg-indirect)              OP-ld-ST 2#1111110100 nil)
(instr STR (regfp128 reg-indirect)             OP-ld-ST 2#0011110110 nil)

% LDR Xt,[Xn,Xm]
% (LDR (reg t) (indexed (reg n) (reg m)))
% LDR Xt,[Xn,Xm,lsl #3]
% LDR Xt,[Xn,Wm,sxtw/uxtw]
% (LDR (reg t) (indexed (reg n) (regshifted m LSL amount)))
(instr LDR (regfp8 reg-or-sp-shifter)         OP-ld-st 2#00111100001 2#10)
(instr LDR (regfp16 reg-or-sp-shifter)        OP-ld-st 2#01111100001 2#10)
(instr LDR (regfp32 reg-or-sp-shifter)        OP-ld-st 2#10111100001 2#10)
(instr LDR (regfp64 reg-or-sp-shifter)        OP-ld-st 2#11111100001 2#10)
(instr LDR (regfp128 reg-or-sp-shifter)       OP-ld-st 2#00111100101 2#10)
(instr STR (regfp8 reg-or-sp-shifter)         OP-ld-st 2#00111100000 2#10)
(instr STR (regfp16 reg-or-sp-shifter)        OP-ld-st 2#01111100000 2#10)
(instr STR (regfp32 reg-or-sp-shifter)        OP-ld-st 2#10111100000 2#10)
(instr STR (regfp64 reg-or-sp-shifter)        OP-ld-st 2#11111100000 2#10)
(instr STR (regfp128 reg-or-sp-shifter)       OP-ld-st 2#00111100100 2#10)

%% Conversion of floating point to signed integer
(instr FCVTAS (reg32 regfp16)                 OP-fcvt 2#00011110111 2#00100)
(instr FCVTAS (reg regfp16)                   OP-fcvt 2#10011110111 2#00100)
(instr FCVTAS (reg32 regfp32)                 OP-fcvt 2#00011110001 2#00100)
(instr FCVTAS (reg regfp32)                   OP-fcvt 2#10011110001 2#00100)
(instr FCVTAS (reg32 regfp64)                 OP-fcvt 2#00011110011 2#00100)
(instr FCVTAS (reg regfp64)                   OP-fcvt 2#10011110011 2#00100)

(instr FCVTNS (reg32 regfp16)                 OP-fcvt 2#00011110111 2#00000)
(instr FCVTNS (reg regfp16)                   OP-fcvt 2#10011110111 2#00000)
(instr FCVTNS (reg32 regfp32)                 OP-fcvt 2#00011110001 2#00000)
(instr FCVTNS (reg regfp32)                   OP-fcvt 2#10011110001 2#00000)
(instr FCVTNS (reg32 regfp64)                 OP-fcvt 2#00011110011 2#00000)
(instr FCVTNS (reg regfp64)                   OP-fcvt 2#10011110011 2#00000)

(instr FCVTZS (reg32 regfp16)                 OP-fcvt 2#00011110111 2#11000)
(instr FCVTZS (reg regfp16)                   OP-fcvt 2#10011110111 2#11000)
(instr FCVTZS (reg32 regfp32)                 OP-fcvt 2#00011110001 2#11000)
(instr FCVTZS (reg regfp32)                   OP-fcvt 2#10011110001 2#11000)
(instr FCVTZS (reg32 regfp64)                 OP-fcvt 2#00011110011 2#11000)
(instr FCVTZS (reg regfp64)                   OP-fcvt 2#10011110011 2#11000)

(instr SCVTF (regfp16 reg32)                 OP-fcvt 2#00011110111 2#00010)
(instr SCVTF (regfp16 reg)                   OP-fcvt 2#10011110111 2#00010)
(instr SCVTF (regfp32 reg32)                 OP-fcvt 2#00011110001 2#00010)
(instr SCVTF (regfp32 reg)                   OP-fcvt 2#10011110001 2#00010)
(instr SCVTF (regfp64 reg32)                 OP-fcvt 2#00011110011 2#00010)
(instr SCVTF (regfp64 reg)                   OP-fcvt 2#10011110011 2#00010)

%% Floating point arithmetic and comparison
(instr FADD (regfp16 regfp16 regfp16)      OP-fp-arith 2#00011110111 2#001010)
(instr FADD (regfp32 regfp32 regfp32)      OP-fp-arith 2#00011110001 2#001010)
(instr FADD (regfp64 regfp64 regfp64)      OP-fp-arith 2#00011110011 2#001010)

(instr FSUB (regfp16 regfp16 regfp16)      OP-fp-arith 2#00011110111 2#001110)
(instr FSUB (regfp32 regfp32 regfp32)      OP-fp-arith 2#00011110001 2#001110)
(instr FSUB (regfp64 regfp64 regfp64)      OP-fp-arith 2#00011110011 2#001110)

(instr FMUL (regfp16 regfp16 regfp16)      OP-fp-arith 2#00011110111 2#000010)
(instr FMUL (regfp32 regfp32 regfp32)      OP-fp-arith 2#00011110001 2#000010)
(instr FMUL (regfp64 regfp64 regfp64)      OP-fp-arith 2#00011110011 2#000010)

(instr FDIV (regfp16 regfp16 regfp16)      OP-fp-arith 2#00011110111 2#000110)
(instr FDIV (regfp32 regfp32 regfp32)      OP-fp-arith 2#00011110001 2#000110)
(instr FDIV (regfp64 regfp64 regfp64)      OP-fp-arith 2#00011110011 2#000110)

(instr FCMP (regfp16 regfp16)      OP-fcmp 2#00011110111 2#001000)
(instr FCMP (regfp32 regfp32)      OP-fcmp 2#00011110001 2#001000)
(instr FCMP (regfp64 regfp64)      OP-fcmp 2#00011110011 2#001000)


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% now we generate the aarch64-inst.dat file
(off usermode) (de linelength (x) 1000)
(reload chars)
(pp nil)
(collectInstructions "aarch64-inst.dat")
% (disassembletables "disasstb")

(exitlisp)
