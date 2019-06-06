;;; sl-on-cl.lisp --- Standard Lisp on Common Lisp

;; Copyright (C) 2018, 2019 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: 4 November 2018

;; Current target implementations of Common Lisp:
;; - Windows SBCL (Steel Bank Common Lisp) 1.4.14; see http://www.sbcl.org/
;; - Cygwin CLISP 2.49 (2010-07-07); see https://clisp.sourceforge.io/

;; This file implements a superset of Standard Lisp that is a subset
;; of PSL and CSL in a package called STANDARD-LISP with nickname SL.
;; It does not provide a Standard Lisp REPL and is intended primarily
;; for running REDUCE (which provides its own REPL) on Common Lisp.

;; (declaim (optimize (speed 3) (safety 0)))
#+SBCL (declaim (optimize debug))       ; same as (debug 3)
;; CLISP seems to be *very* slow, so...
#+CLISP (declaim (optimize speed))

#+SBCL (declaim (sb-ext:muffle-conditions sb-ext:compiler-note style-warning))
#+CLISP (setq custom:*suppress-check-redefinition* t
              custom:*compile-warnings* nil)


;; Support case-sensitive and case-inverting Common Lisp on
;; implementations other than CLISP, modelled on that in CLISP.

#-CLISP
(defpackage :cs-common-lisp
  (:nicknames :cs-cl)
  (:documentation "Case-sensitive and case-inverting Common Lisp")
  (:use :common-lisp)
  (:shadow :symbol-name :intern :find-symbol
           :princ-to-string :prin1-to-string))

#-CLISP
(eval-when (:compile-toplevel :load-toplevel :execute)
  ;; Based on CLISP source file "case-sensitive.lisp":
  (let ((cs-cl-package (find-package :cs-common-lisp)))
    ;; For each symbol standard-sym in CL find the same symbol cs-sym in
    ;; CS-CL and export it:
    (do-external-symbols (standard-sym :common-lisp)
      (let ((cs-sym (find-symbol (symbol-name standard-sym) cs-cl-package)))
        ;; (print cs-sym)
        (export (list cs-sym) cs-cl-package)))))

;; #-CLISP
;; (defpackage :cs-common-lisp-user
;;   (:nicknames :cs-cl-user)
;;   (:documentation "Case-sensitive and case-inverting Common Lisp user")
;;   (:use :common-lisp-user))

;; The CLISP "CS-COMMON-LISP" package provides several case-inverted
;; functions, among which I only use the following:

;; cs-cl:symbol-name
;;   returns the case-inverted symbol name.
;; cs-cl:intern
;; cs-cl:find-symbol
;;   work consistently with cs-cl:symbol-name.
;; cs-cl:shadow
;;   converts a SYMBOL to a STRING and therefore exist in a variant
;;   that uses cs-cl:symbol-name instead of SYMBOL-NAME.

;; (in-package :cs-common-lisp)

#-CLISP
(eval-when (:compile-toplevel :load-toplevel :execute)

(defun cs-cl::%string-invert-case (s)
  "Invert the case of each letter in a string."
  ;; The consequences are undefined if a symbol name is ever modified.
  ;; Hence the following copy is necessary, at least in SBCL...
  (setq s (copy-seq s))
  (loop for i below (length s) with c do
       (setq c (aref s i))
       (if (both-case-p c)
           (setf (aref s i)
                 (if (lower-case-p c) (char-upcase c) (char-downcase c)))))
  s)

(defun cs-cl:symbol-name (s)
  "symbol-name symbol => name"
  (cs-cl::%string-invert-case (cl:symbol-name s)))

(defun cs-cl:intern (s)
  "intern string => symbol"
  (cl:intern (cs-cl::%string-invert-case s)))

(defun cs-cl:find-symbol (s)
  "find-symbol string => symbol"
  (cl:find-symbol (cs-cl::%string-invert-case s)))

(defun cs-cl:princ-to-string (u)
  "As cl:princ-to-string but invert case of a symbol."
  (if (symbolp u) (cs-cl::%string-invert-case (cl:princ-to-string u))
      (cl:princ-to-string u)))

(defun cs-cl:prin1-to-string (u)
  "As cl:prin1-to-string but invert case of a symbol."
  (if (symbolp u) (cs-cl::%string-invert-case (cl:prin1-to-string u))
      (cl:prin1-to-string u)))
)                               ; end progn setting up :cs-common-lisp


#+SBCL (eval-when (:compile-toplevel :load-toplevel :execute)
         (require :sb-posix))

(defpackage :standard-lisp
  (:nicknames :sl)
  (:documentation "Lower-case Standard Lisp on Common Lisp")
  #+CLISP (:case-sensitive t) #+CLISP (:case-inverted t)
  (:use :cs-common-lisp)

  ;; Best to use the shadow option here and not separate calls of the
  ;; shadow function, mainly because the shadow function is not
  ;; evaluated at compile time!
  (:shadow :constantp :equal :minusp :vectorp :zerop :nth :pnth
           :gensym :intern :get :remprop :error :expt :float :map
           :mapc :mapcan :mapcar :mapcon :maplist :append :assoc
           :delete :length :member :sublis :subst :rassoc :apply :eval
           :function :close :open :princ :print :prin1 :read
           :terpri :complexp :union :compile-file :load :time
           :char-downcase :char-upcase :string-downcase :mod
           :char-code)

  #+SBCL (:import-from :sb-ext :exit :quit :save-lisp-and-die :gc)
  #+SBCL (:import-from :sb-posix :getenv)

  #+CLISP (:import-from :ext :exit :quit :saveinitmem :gc :getenv)
  )

(in-package :standard-lisp)

(eval-when (:compile-toplevel :load-toplevel :execute)
  (defun %intern-character (c)
    "Convert character C to an interned symbol."
    (cs-cl:intern (string c))))

;; The following definitions roughly follow the order in the Standard
;; Lisp Report.

;;; System GLOBAL Variables
;;; =======================

(defvar *comp nil
  "*COMP = NIL global
The value of !*COMP controls whether or not PUTD compiles the
function defined in its arguments before defining it. If !*COMP is
NIL the function is defined as an EXPR. If !*COMP is something
else the function is first compiled. Compilation will produce certain
changes in the semantics of functions particularly FLUID type access.")

(defvar emsg* nil
  "EMSG* = NIL global
Will contain the MESSAGE generated by the last ERROR call.")

(defconstant $eof$ '$eof$
  "$EOF$ = <an uninterned identifier> global
The value of !$EOF!$ is returned by all input functions when the end
of the currently selected input file is reached.")

(defconstant $eol$ (%intern-character #\Newline) ; cf. PSL & CSL
  "$EOL$ = <an uninterned identifier> global
The value of !$EOL!$ is returned by READCH when it reaches the
end of a logical input record. Likewise PRINC will terminate its
current line (like a call to TERPRI) when !$EOL!$ is its argument.")

(defvar *gc nil
  "*GC = NIL global
!*GC controls the printing of garbage collector messages. If NIL
no indication of garbage collection may occur. If non-NIL various
system dependent messages may be displayed.")

(import '(nil))                         ; this list form is necessary!
;; NIL = NIL global
;; NIL is a special global variable. It is protected from being modifed
;; by SET or SETQ.

;; **********************************************************************
;; Make REDUCE case-insensitive for now to facilitate comparison
;; with the test output from CSL/PSL REDUCE.  Later, could make it
;; case-sensitive with a switch *legacy that enables *raise for
;; compatibility with legacy REDUCE.
;; **********************************************************************

(defvar *raise t
  "*RAISE = NIL global
Follow the PSL convention: If !*RAISE is non-NIL all characters input
through Standard LISP input functions will be converted to a standard
case.  Currently, this is upper case on SBCL and lower case on CLISP.
If !*RAISE is NIL characters will be input as is.")

(defvar *printlower nil
  ;; Calling this variable *lower causes problems bootstrapping rlisp
  ;; that I don't understand, but this switch is different from the
  ;; PSL/CSL lower switch anyway!
  "If non-nil then all identifiers are printed using lower case.")

(import 't)
;; T = T global
;; T is a special global variable. It is protected from being modifed by
;; SET or SETQ.

;; Not Standard LISP but PSL and assumed by REDUCE:

(defvar *echo nil
  "*echo = [Initially: nil] switch
The switch echo is used to control the echoing of input. When (on echo)
is placed in an input file, the contents of the file are echoed on the standard
output device. Dskin does not change the value of *echo, so one may say
(on echo) before calling dskin, and the input will be echoed.")

(defvar *redefmsg t
  "*redefmsg = [Initially: t] switch
If *redefmsg is not nil, the message
*** Function `FOO' has been redefined
is printed whenever a function is redefined by PUTD.")
;; Also applies to DE & DM.

(defun %%redefmsg (fname)
  "Optionally warn about function redefinition."
  ;; Assume fname is input quoted.
  (when (and *redefmsg (fboundp fname))
    ;; (warn "Function ~a has been redefined" fname)
    ;; Warnings are currently suppressed!
    ;; (format t "~&*** Function `~(~a~)' has been redefined~%" fname)
    (format t "~&*** Function `~a' has been redefined~%"
            (%%prin1-id-to-string fname))))

;;; FUNCTIONS
;;; =========

(defmacro defalias (symbol definition &optional docstring)
  "Set SYMBOL's function definition to DEFINITION.
The optional third argument DOCSTRING specifies the documentation string
for SYMBOL; if it is omitted or nil, SYMBOL uses the documentation string
determined by DEFINITION.  The return value is undefined."
  `(setf ,@(if docstring `((documentation ,symbol 'cs-cl:function) ,docstring))
         (symbol-function ,symbol) (symbol-function ,definition)))

(eval-when (:compile-toplevel :load-toplevel :execute)
  ;; Needed to expand macros fluid and global when compiling.
  (defun eqcar (u v)
    "Return true if U is a cons cell and its car is eq to V."
    (and (consp u) (eq (car u) v))))


;;; Elementary Predicates
;;; =====================

(import 'cs-cl:atom)
;; ATOM(U:any):boolean eval, spread
;; Returns T if U is not a pair.
;; EXPR PROCEDURE ATOM(U);
;;    NULL PAIRP U;

(defalias 'codep 'cs-cl:compiled-function-p
  "CODEP(U:any):boolean eval, spread
Returns T if U is a function-pointer.")
;; This means compiled code only!

(defun constantp (u)
  "CONSTANTP(U:any):boolean eval, spread
Returns T if U is a constant (a number, string, function-pointer, or vector).
EXPR PROCEDURE CONSTANTP(U);
   NULL OR(PAIRP U, IDP U);"
  (null (or (consp u) (symbolp u))))

(import 'cs-cl:eq)
;; EQ(U:any, V:any):boolean eval, spread
;; Returns T if U points to the same object as V. EQ is not a reliable
;; comparison between numeric arguments.

;; The following code seems to cause problems if used in eq or equal.

;; (defun eq (u v)
;;   "EQ(U:any, V:any):boolean eval, spread
;; Returns T if U points to the same object as V. EQ is not a reliable
;; comparison between numeric arguments."
;;   ;; After evaluating (setq gg intern(setq g (gensym))) in PSL/CSL
;;   ;; then (eq g gg) gives true, but in Common Lisp the equivalent
;;   ;; gives false, so...
;;   (if (and (cs-cl:symbolp u) (cs-cl:symbolp v)) ; both symbols
;;       ;; Look for both symbols NOW in the current package:
;;       (let ((uu (find-symbol (symbol-name u)))
;;             (vv (find-symbol (symbol-name v))))
;;         (and uu vv (cs-cl:eq uu vv)))
;;       (cs-cl:eq u v)))

(defun eqn (u v)
  "EQN(U:any, V:any):boolean eval, spread
Returns T if U and V are EQ or if U and V are numbers and have
the same value and type."               ; i.e. the same SL type!
  (or (eql u v)
      ;;  eql may not be true of two floats even when they represent
      ;;  the same value. = is used to compare mathematical values.
      (and (floatp u) (floatp v) (= u v))))

;; (defun equal (u v)
;;   "EQUAL(U:any, V:any):boolean eval, spread
;; Returns T if U and V are the same. Dotted-pairs are compared
;; recursively to the bottom levels of their trees. Vectors must
;; have identical dimensions and EQUAL values in all
;; positions. Strings must have identical characters. Function
;; pointers must have EQ values. Other atoms must be EQN equal."
;;   (or (cs-cl:equal u v)
;;    ;;  equal may not be true of two floats even when they represent
;;    ;;  the same value. = is used to compare mathematical values.
;;    (and (floatp u) (floatp v) (= u v))
;;    (and (vectorp u) (vectorp v) (equalp u v))))

(defun equal (u v)
  "EQUAL(U:any, V:any):boolean eval, spread
Returns T if U and V are the same. Dotted-pairs are compared
recursively to the bottom levels of their trees. Vectors must
have identical dimensions and EQUAL values in all
positions. Strings must have identical characters. Function
pointers must have EQ values. Other atoms must be EQN equal."
  (and (cs-cl:equal (type-of u) (type-of v))
       (if (atom u) (cond ((cs-cl:symbolp u) (eq u v))
                          ((cs-cl:floatp u) (= u v))
                          ((cs-cl:numberp u) (eql u v))
                          ((cs-cl:stringp u) (string= u v))
                          ((cs-cl:vectorp u) (equalp u v)))
           (and (equal (car u) (car v)) (equal (cdr u) (cdr v))))))

(defalias 'fixp 'cs-cl:integerp
  "FIXP(U:any):boolean eval, spread
Returns T if U is an integer (a fixed number).")

(import 'cs-cl:floatp)
;; FLOATP(U:any):boolean eval, spread
;; Returns T if U is a floating point number.

(defalias 'idp 'cs-cl:symbolp
  "IDP(U:any):boolean eval, spread
Returns T if U is an id.")

(defun minusp (u)
  "MINUSP(U:any):boolean eval, spread
Returns T if U is a number and less than 0. If U is not a number
or is a positive number, NIL is returned.
EXPR PROCEDURE MINUSP(U);
   IF NUMBERP U THEN LESSP(U, 0) ELSE NIL;"
  (and (realp u) (cs-cl:minusp u)))

(import 'cs-cl:null)
;; NULL(U:any):boolean eval, spread
;; Returns T if U is NIL.
;; EXPR PROCEDURE NULL(U);
;;    U EQ NIL;

(import 'cs-cl:numberp)
;; NUMBERP(U:any):boolean eval, spread
;; Returns T if U is a number (integer or floating).
;; EXPR PROCEDURE NUMBERP(U);
;;    IF OR(FIXP U, FLOATP U) THEN T ELSE NIL;

(defun onep (u)
  "ONEP(U:any):boolean eval, spread.
Returns T if U is a number and has the value 1 or 1.0. Returns NIL
otherwise.
EXPR PROCEDURE ONEP(U);
   OR(EQN(U, 1), EQN(U, 1.0));"
  (equalp u 1))

(defalias 'pairp 'cs-cl:consp
  "PAIRP(U:any):boolean eval, spread
Returns T if U is a dotted-pair.")

(import 'cs-cl:stringp)
;; STRINGP(U:any):boolean eval, spread
;; Returns T if U is a string.

(defun vectorp (u)
  "VECTORP(U:any):boolean eval, spread
Returns T if U is a vector."
  ;; Must exclude strings, which are also vectors in CL.
  ;; (and (vectorp u) (not (stringp u)))
  (typep u '(vector t)))

(defun zerop (u)
  "ZEROP(U:any):boolean eval, spread
Returns T if U is a number and has the value 0 or 0.0. Returns
NIL otherwise.
EXPR PROCEDURE ZEROP(U);
   OR(EQN(U, 0), EQN(U, 0.0));"
  (and (numberp u) (cs-cl:zerop u)))


;;; Functions on Dotted-Pairs
;;; =========================

(import 'cs-cl:car)
;; CAR(U:dotted-pair):any eval, spread
;; CAR(CONS(a, b)) --> a. The left part of U is returned. The type
;; mismatch error occurs if U is not a dotted-pair.

(import 'cs-cl:cdr)
;; CDR(U:dotted-pair):any eval, spread
;; CDR(CONS(a, b)) --> b. The right part of U is returned. The type
;; mismatch error occurs if U is not a dotted-pair.

;; The composites of CAR and CDR are supported up to 4 levels:
(import '(cs-cl:caar cs-cl:cadr cs-cl:cdar cs-cl:cddr cs-cl:caaar cs-cl:caadr cs-cl:cadar
          cs-cl:caddr cs-cl:cdaar cs-cl:cdadr cs-cl:cddar cs-cl:cdddr cs-cl:caaaar
          cs-cl:caaadr cs-cl:caadar cs-cl:caaddr cs-cl:cadaar cs-cl:cadadr cs-cl:caddar
          cs-cl:cadddr cs-cl:cdaaar cs-cl:cdaadr cs-cl:cdadar cs-cl:cdaddr cs-cl:cddaar
          cs-cl:cddadr cs-cl:cdddar cs-cl:cddddr))

(import 'cs-cl:cons)
;; CONS(U:any, V:any):dotted-pair eval, spread
;; Returns a dotted-pair which is not EQ to anything and has U as its
;; CAR part and V as its CDR part.

(import 'cs-cl:list)
;; LIST([U:any]):list noeval, nospread, or macro
;; A list of the evaluation of each element of U is returned. The order of
;; evaluation need not be first to last as the following definition implies.
;; FEXPR PROCEDURE LIST(U);
;;    EVLIS U;

(import 'cs-cl:rplaca)
;; RPLACA(U:pair, V:any):pair eval, spread
;; The car of the pair U is replaced by V and the modified pair U is
;; returned.  A type mismatch error occurs if U is not a pair.

(import 'cs-cl:rplacd)
;; RPLACD(U:pair, V:any):pair eval, spread
;; The cdr of the pair U is replaced by V and the modified pair U is
;; returned.  A type mismatch error occurs if U is not a pair.

;; PSL functions:

(import '(cs-cl:first cs-cl:second cs-cl:third cs-cl:fourth cs-cl:rest))

(declaim (inline lastpair lastcar nth pnth))

(defun lastpair (l)
  "(lastpair L:pair): any expr
Returns the last pair of a L. It is often useful to think of this as a
pointer to the last element for use with destructive functions such as
rplaca. If L is not a pair then a type mismatch error occurs.
\(de lastpair (l)
  (if (or (atom l) (atom (cdr l)))
    l
    (lastpair (cdr l))))"
  ;; The inconsistent description above is from the PSL manual!
  (if (atom l) l (cs-cl:last l)))

(defun lastcar (l)                      ; inlined
  "(lastcar L:pair): any expr
Returns the last element of the pair L. A type mismatch error results
if L is not a pair.
\(de lastcar (l)
  (if (atom l) l (car (lastpair l))))"
  ;; The inconsistent description above is from the PSL manual!
  (if (atom l) l (car (cs-cl:last l))))

(defun nth (l n)                        ; inlined
  "(nth L:pair N:integer): any expr
Returns the Nth element of the list L. If L is atomic or contains
fewer than N elements, an out of range error occurs.
\(de nth (l n)
    (cond ((null l) (range-error))
          ((onep n) (first l))
          (t (nth (rest l) (sub1 n)))))
Note that this definition is not compatible with Common LISP. The
Common LISP definition reverses the arguments and defines the car
of a list to be the \"zeroth\" element."
  (cs-cl:nth (1- n) l))

(defun pnth (l n)                       ; inlined
  "(pnth L:list N:integer): any expr
Returns a list starting with the nth element of the list L. Note
that the result is a pointer to the nth element of L, a
destructive function like rplaca can be used to modify the
structure of L. If L is atomic or contains fewer than N elements,
an out of range error occurs.
\(de pnth (l n)
    (cond ((onep n) l)
          ((not (pairp l)) (range-error))
          (t (pnth (rest l) (sub1 n)))))"
  (nthcdr (1- n) l))


;;; Identifiers
;;; ===========

(defun %compress-list-to-string (u)
  "Convert a list of single-character symbols to a string."
  (cs-cl:map 'string #'character u))

(defun %character-inverted (c)
  "As `character', but case-inverted."
  (setq c (character c))
  (if (alpha-char-p c)
      (if (lower-case-p c) (cs-cl:char-upcase c) (cs-cl:char-downcase c))
      c))

(defun %compress-list-to-inverted-string (u)
  "Convert a list of single-character symbols to a case-inverted string."
  (cs-cl:map 'string #'%character-inverted u))

(defun compress (u)                     ; PSL spec
  "COMPRESS(U:id-list):{atom-vector} eval, spread
U is a list of single character identifiers which is built into a
Standard LISP entity and returned.  Recognized are lists, numbers,
strings, and identifiers with the escape character prefixing special
characters.  Identifiers are not interned.  Function pointers may not
be compressed.  If an entity cannot be parsed out of U an error
occurs:
***** Poorly formed atom in COMPRESS"
  (labels
      ((compress () ; This internal function recursively process lists.
         ;; Concatenate the characters into a string and then handle any !
         ;; characters as follows:
         ;; A string begins with " and should retain any ! characters without
         ;; change.
         ;; A number begins with - or a digit and should not contain any !
         ;; characters.
         ;; Otherwise, assume an identifier and replace ! by \, but !! by \!
         (let (u0)                      ; first element
           (compress-skip-spaces)       ; skip leading spaces
           (if (or (null u)
                   (cs-cl:member (setq u0 (car u))
                                 '(\' \) \, \% \[ \\ \`))) ; PSL
               (cs-cl:error "Poorly formed S-expression in COMPRESS"))
           (cond
             ;; LIST?
             ((eq u0 '|(|) (setq u (cdr u))
              (compress-skip-spaces)    ; skip leading spaces
              (loop
                 while (not (eq (car u) '|)|))
                 collect (compress)
                 do (compress-skip-spaces)))
             ;; STRING?
             ((eq u0 '\")
              ;; In Standard Lisp, "" in a string represents ":
              (loop with newu while (setq u (cdr u)) do
                   (when (eq (car u) '\")
                     (setq u (cdr u))
                     (if (not (and u (eq (car u) '\"))) ; end of string
                         (return-from compress
                           (%compress-list-to-inverted-string (nreverse newu)))))
                   (push (car u) newu))
              ;; String not terminated:
              (cs-cl:error "Poorly formed S-expression in COMPRESS"))
             ;; NUMBER?
             ((or (digit u0) (char= (character u0) #\-))
              ;; (eq u0 '-) fails because u0 is in SL but - is (an operator) in CL.
              (multiple-value-bind (obj pos)
                  (read-from-string (%compress-list-to-string u))
                (setq u (nthcdr pos u))
                obj))
             ;; IDENTIFIER
             (t
              ;; Delete a single ! but replace !! by !
              ;; In PSL, an identifier can contain any of the special characters
              ;; + - $ & * / : ; | < = > ? ^ _ { } ~ @
              ;; and hence not any of
              ;; space ! " ' ( ) , . # % [ \ ] `
              ;; unless they are escaped with ! (which must be handled specially).
              (loop with newu do
                   (cond ((or (null u)
                              (cs-cl:member (car u)
                                            '(\  \" \' \( \) \, \% \[ \\ \] \`)))
                          (return
                            (make-symbol ; uninterned symbol
                             (%compress-list-to-string (nreverse newu)))))
                         ((eq (car u) '!) ; ignore ! but keep WHATEVER follows it
                          (if (setf u (cdr u))
                              (push (car u) newu)))
                         (t (push (car u) newu)))
                   (setf u (cdr u)))))))
       ;;
       (compress-skip-spaces ()
         (loop while (eq (car u) '| |) do (setq u (cdr u)))))
    ;;
    (compress)))

(defun explode (u)                      ; PSL spec
  "(explode U:any): id-list expr
Explode returns a list of interned single-character identifiers
representing the characters required to print the S-expression U in a
way that could be read by Lisp.  It is implemented by effectively
printing (using prin1) to a list.  E.g.
1 lisp> (explode 'foo)
\(f o o)
2 lisp> (explode '(a . b))
\(!( a !  !. !  b !))"
  ;; Add support for vectors?  Share code with print routines?
  (if (consp u)
      ;; Exploding a cons:
      (let ((ll (list (explode (car u)) (list '|(|))))
        (loop while (consp (setq u (cdr u)))
           do (push (list '| |) ll)
           do (push (explode (car u)) ll))
        (when u
          (push (list '| | '|.| '| |) ll)
          (push (explode u) ll))
        (push (list '|)|) ll)
        (cs-cl:apply #'nconc (nreverse ll)))
      ;; Exploding an atom:
      (cs-cl:map
       'list
       #'%intern-character
       (cond ((or (stringp u) (numberp u)) (prin1-to-string u))
             ;; Assume identifier -- must insert ! before a leading digit and
             ;; before any special characters in string without \ escapes:
             (t (loop with s = (princ-to-string u) and ss and e
                   for i below (cs-cl:length s) do
                     (setf e (aref s i))
                     (if (not (or (and (not (eql i 0)) (digit-char-p e))
                                  (alpha-char-p e)))
                         (push #\! ss))
                     (push e ss)
                   finally (return (nreverse ss))))))))

(defalias 'gensym 'cs-cl:gensym)
;; GENSYM():identifier eval, spread
;; Creates an identifier which is not interned on the OBLIST and
;; consequently not EQ to anything else.
;; Defined this way so that I can overwrite it in faslout.

(defun gensymp (u)                      ; from pslrend
  (and (symbolp u) (not (find-symbol (symbol-name u)))))

(defun intern (u)
  "INTERN(U:{id,string}):id eval, spread
INTERN searches the OBLIST for an identifier with the same print
name as U and returns the identifier on the OBLIST if a match is
found. Any properties and global values associated with U may be
lost. If U does not match any entry, a new one is created and
returned. If U has more than the maximum number of characters
permitted by the implementation (the minimum number is 24) an
error occurs:
***** Too many characters to INTERN"
  (cs-cl:intern (if (symbolp u) (symbol-name u) u)))

(defun remob (u)
  "REMOB(U:id):id eval, spread
If U is present on the OBLIST it is removed. This does not affect U
having properties, flags, functions and the like. U is returned."
  (unintern u)
  u)


;;; Property List Functions
;;; =======================

;; In file "rlisp/superv.red" is the statement
;;
;; FLAG('(DEFLIST FLAG FLUID GLOBAL REMFLAG REMPROP UNFLUID),'EVAL);
;;
;; which (I think) means that the functions listed are evaluated even
;; after `ON DEFN', which is necessary to ensure that some source code
;; reads correctly.  However, `REMPROP' is usually followed by `PUT'
;; to reinstate whatever property was removed, but `PUT' is not
;; flagged `EVAL', so this reinstatement doesn't happen because
;; evaluating `PUT' at the wrong time can cause similar problems,
;; e.g. with `rlisp88'.  Hence, viewing code with `ON DEFN' can break
;; subsequent code.  For example, inputting "rlisp/module.red" with
;; `ON DEFN' removes the `STAT' property from `LOAD_PACKAGE', which
;; then no longer works correctly.  This is a major problem for the
;; way I generate fasl files!
;;
;; I therefore provide a workaround to make the functions DEFLIST,
;; FLAG, REMFLAG and REMPROP save the property list of any identifier
;; before modifying it if it has not already been saved, and provide a
;; function to reinstate the saved property list.  I use this facility
;; when generating fasl files and in `OFF DEFN' (see "eslrend.red"),
;; so that ESL REDUCE should be immune to this `ON DEFN' side-effect.
;;
;; However, this facility only applies to reading REDUCE code and must
;; be disabled when loading a Lisp file, i.e. when the variable
;; `*load-pathname*' is non-nil.  This is particularly important when
;; building REDUCE.

(defvar *defn nil)

(defvar %%saved-plist-alist nil
  "Association list of symbols and their saved property lists.
Its value should normally be nil, except while ON DEFN.")

(defun %%save-plist (symbol)
  "Save property list of symbol SYMBOL if not already saved.
Do not do this if Lisp file load in progress."
  (or *load-pathname*
      (cs-cl:assoc symbol %%saved-plist-alist :test #'eq)
      (push (cons symbol (cs-cl:copy-tree (symbol-plist symbol)))
            %%saved-plist-alist)))

(defun %reinstate-plists ()
  "Reinstate all saved property lists.
Do not do this if Lisp file load in progress."
  (unless *load-pathname*
    (cs-cl:mapc #'(lambda (s) (setf (symbol-plist (car s)) (cdr s)))
             %%saved-plist-alist)
    (setf %%saved-plist-alist nil)))

(defun flag (u v)
  "FLAG(U:id-list, V:id):NIL eval, spread
U is a list of ids which are flagged with V. The effect of FLAG is
that FLAGP will have the value T for those ids of U which were
flagged. Both V and all the elements of U must be identifiers or the
type mismatch error occurs."
  (if *defn (cs-cl:mapc #'%%save-plist u))
  (cs-cl:mapc #'(lambda (x) (put x v t)) u)
  nil)

(defun flagp (u v)
  "FLAGP(U:any, V:any):boolean eval, spread
Returns T if U has been previously flagged with V, else NIL. Returns
NIL if either U or V is not an id."
  (if (and (symbolp u) (symbolp v)) (cs-cl:get u v)))

(defun get (u ind)
  "GET(U:any, IND:id):any eval, spread
Returns the property associated with indicator IND from the
property list of U. If U does not have indicator IND, NIL is
returned.  GET cannot be used to access functions (use GETD
instead)."
  ;; MUST return nil if u is not a symbol.
  (if (symbolp u) (cs-cl:get u ind)))

(defun put (u ind prop)
  "PUT(U:id, IND:id, PROP:any):any eval, spread
The indicator IND with the property PROP is placed on the
property list of the id U. If the action of PUT occurs, the value
of PROP is returned. If either of U and IND are not ids the type
mismatch error will occur and no property will be placed. PUT
cannot be used to define functions (use PUTD instead)."
  (setf (cs-cl:get u ind) prop))

(defun remflag (u v)
  "REMFLAG(U:any-list, V:id):NIL eval, spread
Removes the flag V from the property list of each member of the
list U. Both V and all the elements of U must be ids or the type
mismatch error will occur."
  (if *defn (cs-cl:mapc #'%%save-plist u))
  (cs-cl:mapc #'(lambda (x) (cs-cl:remprop x v)) u)
  nil)

(defun remprop (u ind)
  "REMPROP(U:any, IND:any):any eval, spread
Removes the property with indicator IND from the property list of U.
Returns the removed property or NIL if there was no such indicator."
  (prog1
      (get u ind)
    (if *defn (%%save-plist u))
    (cs-cl:remprop u ind)))


;;; Function Definition
;;; ===================

;; NOTE that Standard Lisp macros are nospread and therefore take a
;; single parameter that gets the list of actual arguments, so `DM'
;; and `PUTD' must convert the macro parameter into an &rest
;; parameter.  Also, when a Standard Lisp macro is called it receives
;; its name as its first argument, i.e. the single parameter evaluates
;; to the COMPLETE function call, so `DM' and `PUTD' must modify the
;; macro argument list within the body lambda expression.

;; Ref. Standard LISP Report, page 9: "When a macro invocation is
;; encountered, the body of the macro, a lambda expression, is invoked
;; as a NOEVAL, NOSPREAD function with the macro's invocation bound as
;; a list to the macros single formal parameter."

;; REDUCE handles macros specially, assuming they are Standard LISP
;; macros, whereas SL functions that are actually defined as Common
;; Lisp macros need to be handled by REDUCE as if they were
;; EXPRs. Therefore, it is important that the function type defaults
;; to EXPR, so only macros defined using DM or PUTD are given the
;; property %%FTYPE with value MACRO. The %%FTYPE property is required
;; so that macros defined in REDUCE can be distinguished from Common
;; Lisp macros. Normal functions defined using DE or PUTD are given
;; the property %%FTYPE with value EXPR just for symmetry, but this
;; property value is not actually used by GETD.

(defmacro de (fname params &rest fn)    ; PSL definition
  "(de Fname:id PARAMS:id-list [FN:form]): id macro
Defines the function named FNAME, of type expr. The forms FN are made
into a lambda expression with the formal parameter list PARAMS, and
this is used as the body of the function.  Previous definitions of the
function are lost. The name of the defined function, FNAME, is
returned."
  `(progn
     (%%redefmsg ',fname)
     (put ',fname '%%ftype 'expr)
     (defun ,fname ,params ,@fn)
     ;; It makes no sense to include code to compile this function
     ;; when the function definition is being compiled into a fasl
     ;; file, so examine *COMP when the macro is expanded/compiled and
     ;; ensure that *COMP is nil when fasl files are being generated.
     ;; Splice in *list* of content or nil.
     ,@(if *comp `((compile ',fname)))))

;; *** I'm hoping df is not actually required! ***
;; DF(FNAME:id, PARAM:id-list, FN:any):id noeval, nospread
;; The function FN with formal parameter PARAM is added to the set
;; of defined functions with the name FNAME. Any previous definitions
;; of the function are lost. The function created is of type FEXPR. If
;; the !*COMP variable is T the FEXPR is first compiled. The name
;; of the defined function is returned.
;; FEXPR PROCEDURE DF(U);
;;    PUTD(CAR U, 'FEXPR, LIST('LAMBDA, CADR U, CADDR U));

(defmacro dm (mname param fn)
  "DM(MNAME:id, PARAM:id-list, FN:any):id noeval, nospread
The macro FN with the formal parameter PARAM is added to the set
of defined functions with the name MNAME. Any previous
definitions of the function are overwritten. The function created
is of type MACRO. The name of the macro is returned.
FEXPR PROCEDURE DM(U);
   PUTD(CAR U, 'MACRO, LIST('LAMBDA, CADR U, CADDR U));"
  `(progn
     (%%redefmsg ',mname)
     (put ',mname '%%ftype 'macro)
     ;; Save the (uncompiled) SL macro form:
     ;; (put ',mname '%%macro '(macro lambda ,param ,fn)) ; not currently used
     ;; param must be a list containing a single identifier, which
     ;; must therefore be spliced into the macro definition.
     ;; Spread the arguments and include macro name as first arg:
     (defmacro ,mname (&whole ,@param &rest r)
       ;; The parameter r should probably be a gensym to avoid
       ;; potential name clashes!
       (declare (ignore r))
       ,fn)
     ,@(if *comp `((compile ',mname))))) ; see DE

(defun getd (fname)
  "GETD(FNAME:any):{NIL, dotted-pair} eval, spread
If FNAME is not the name of a defined function, NIL is returned. If
FNAME is a defined function then the dotted-pair
\(TYPE:ftype . DEF:{function-pointer, lambda})
is returned."
  (and (symbolp fname) (fboundp fname)
       ;; Assume expr unless fname was defined using SL dm macro.
       (cond ((eq (cs-cl:get fname '%%ftype) 'macro)
              ;; ;; Return the (uncompiled) SL macro form:
              ;; (cs-cl:get fname '%%macro)
              ;; This may need more work.
              ;; A CL macro expansion needs an environment.
              ;; Try the null environment (nil) initially.
              ;; (The parameter x should perhaps be a gensym.)
              (cons 'macro
                    `(lambda (x)
                       (funcall ,(macro-function fname) x nil))))
             (t
              ;; Return a lambda expression if possible, since this is
              ;; most useful (although perhaps not most efficient in
              ;; some cases):
              (let (f)
                ;; Note that a CL function definition may contain
                ;; declarations and a documentation string, and the
                ;; body MAY BE wrapped in a block form, i.e.
                ;; (lambda params [decls] [doc] (block name body))
                ;; [A compiled CLISP function may not contain a block!]
                ;; Extract the function body:
                (when (and (functionp (setq fname (symbol-function fname)))
                           (setq f (function-lambda-expression fname)))
                  (setq fname (car (last f))) ; block or body form
                  (if (eqcar fname 'block) (setq fname (caddr fname)))
                  (setq fname `(lambda ,(cadr f) ,fname))))
              (cons 'expr fname)))))

(defun putd (fname type body)
  "PUTD(FNAME:id, TYPE:ftype, BODY:function):id eval, spread
Creates a function with name FNAME and definition BODY of type
TYPE. If PUTD succeeds the name of the defined function is
returned. The effect of PUTD is that GETD will return a
dotted-pair with the functions type and definition. Likewise the
GLOBALP predicate will return T when queried with the function
name. If the function FNAME has already been declared as a
GLOBAL or FLUID variable the error:
***** FNAME is a non-local variable
occurs and the function will not be defined. If function FNAME
already exists a warning message will appear:
*** FNAME redefined
The function defined by PUTD will be compiled before definition if
the !*COMP global variable is non-NIL."
  (if (or (cs-cl:get fname 'global)        ; only if explicitly declared
          (fluidp fname))
      (cs-cl:error "~a is a non-local variable" fname))
  (%%redefmsg fname)
  ;; body = (lambda (u) body-form) or function-pointer
  (let (*redefmsg)                  ; don't report redefinitions twice
    (cond ((eq type 'expr)
           (cond ((eqcar body 'lambda)
                  (eval `(de ,fname ,(cadr body) ,@(cddr body))))
                 ((functionp body)
                  (setf (symbol-function fname) body)
                  (put fname '%%ftype 'expr))
                 (t (cs-cl:error "Invalid expr body in PUTD"))))
          ((eq type 'macro)
           (cond ((eqcar body 'lambda)
                  (if (eq (car (caddr body)) 'funcall)
                      ;; This "hybrid form" is returned by getd.
                      (progn
                        (setf (macro-function fname) (cadr (caddr body)))
                        (put fname '%%ftype 'macro))
                      ;; This "pure source form" is used in "rlisp/block.red".
                      (eval `(dm ,fname ,(cadr body) ,@(cddr body)))))
                 ;; ((functionp body)       ; This case should not happen!
                 ;;  (setf (macro-function fname) body)
                 ;;  (put fname '%%ftype 'macro))
                 (t (cs-cl:error "Invalid macro body in PUTD"))))
          (t (cs-cl:error "Invalid type in PUTD"))))
  fname)

(defun remd (fname)
  "REMD(FNAME:id):{NIL, dotted-pair} eval, spread
Removes the function named FNAME from the set of defined
functions. Returns the (ftype . function) dotted-pair or NIL as
does GETD. The global/function attribute of FNAME is removed and
the name may be used subsequently as a variable."
  (let ((def (getd fname)))
    (when def
      (fmakunbound fname)
      (cs-cl:remprop fname '%%ftype))
    def))


;;; Variables and Bindings
;;; ======================

(defun %%fluid (x)
  "If id X is already GLOBAL then display a warning; otherwise flag X as FLUID."
  (unless (fluidp x)
    (if (globalp x)
        (warn "GLOBAL ~a cannot be changed to FLUID" x)
      (progn
        ;; defvar is a macro, so ...
        (cs-cl:eval `(defvar ,x nil "Standard LISP fluid variable."))
        (put x 'fluid t)))))

(defmacro fluid (idlist)
  "FLUID(IDLIST:id-list):NIL eval, spread
The ids in IDLIST are declared as FLUID type variables (ids not
previously declared are initialized to NIL). Variables in IDLIST
already declared FLUID are ignored. Changing a variable's type
from GLOBAL to FLUID is not permissible and results in the error:
***** ID cannot be changed to FLUID"
  ;; A warning, as for PSL, is more convenient than an error!
  (if (eqcar idlist 'quote)
      ;; Assume a top-level call that needs to output `defvar' forms
      ;; at compile time.
      (cons 'prog1
            (cons nil
                  (cs-cl:mapcan
                   #'(lambda (x) `((%%fluid ',x)))
                   (cs-cl:eval idlist))))
    ;; Assume a run-time call.
    `(prog1 nil
       (cs-cl:mapc #'%%fluid ,idlist))))

(defun fluidp (u)
  "FLUIDP(U:any):boolean eval, spread
If U has been declared fluid then t is returned, otherwise nil is returned."
  (get u 'fluid))

(defun %%global (x)
  "If id X is already FLUID then display a warning; otherwise flag X as GLOBAL."
  (unless (globalp x)
    (if (fluidp x)
        (warn "FLUID ~a cannot be changed to GLOBAL" x)
      (progn
        ;; defvar is a macro, so ...
        (unless (cs-cl:constantp x)        ; nil, t, $eol$, $eof$, etc.
          (cs-cl:eval `(defvar ,x nil "Standard LISP global variable.")))
        (put x 'global t)))))

(defmacro global (idlist)
  "GLOBAL(IDLIST:id-list):NIL eval, spread
The ids of IDLIST are declared GLOBAL type variables. If an id
has not been declared previously it is initialized to
NIL. Variables already declared GLOBAL are ignored. Changing a
variables type from FLUID to GLOBAL is not permissible and
results in the error:
***** ID cannot be changed to GLOBAL"
  ;; A warning, as for PSL, is more convenient than an error!
  (if (eqcar idlist 'quote)
      ;; Assume a top-level call that needs to output `defvar' forms
      ;; at compile time.
      (cons 'prog1
            (cons nil
                  (cs-cl:mapcan
                   #'(lambda (x) `((%%global ',x)))
                   (cs-cl:eval idlist))))
    ;; Assume a run-time call.
    `(prog1 nil
       (cs-cl:mapc #'%%global ,idlist))))

(defun globalp (u)
  "GLOBALP(U:any):boolean eval, spread
If U has been declared global then t is returned, otherwise nil is returned."
  (get u 'global))                      ; PSL/CSL definition

(import 'cs-cl:set)
;; Auto fluid not implemented!
;; SET(EXP:id, VALUE:any):any eval, spread
;; EXP must be an identifier or a type mismatch error occurs. The
;; effect of SET is replacement of the item bound to the identifier
;; by VALUE. If the identifier is not a local variable or has not
;; been declared GLOBAL it is automatically declared FLUID with the
;; resulting warning message:
;; *** EXP declared FLUID
;; EXP must not evaluate to T or NIL or an error occurs:
;; ***** Cannot change T or NIL

(import 'cs-cl:setq)
;; Auto fluid not implemented!
;; SETQ(VARIABLE:id, VALUE:any):any noeval, nospread
;; If VARIABLE is not local or GLOBAL it is by default declared
;; FLUID and the warning message:
;; *** VARIABLE declared FLUID
;; appears. The value of the current binding of VARIABLE is replaced
;; by the value of VALUE. VARIABLE must not be T or NIL or an
;; error occurs:
;; ***** Cannot change T or NIL
;; MACRO PROCEDURE SETQ(X);
;;    LIST('SET, LIST('QUOTE, CADR X), CADDR X);

(defun unfluid (idlist)
  "UNFLUID(IDLIST:id-list):NIL eval, spread
The variables in IDLIST that have been declared as FLUID
variables are no longer considered as fluid variables. Others are
ignored. This affects only compiled functions as free variables
in interpreted functions are automatically considered fluid."
  (cs-cl:mapc #'(lambda (x) (if (fluidp x) (cs-cl:remprop x 'fluid)))
           idlist)
  nil)

;; SL declarations for special variables defined above:
(fluid '(*comp *gc *raise))
(global '(emsg*))


;;; Program Feature Functions
;;; =========================

(import 'cs-cl:go)
;; GO(LABEL:id) noeval, nospread
;; GO alters the normal flow of control within a PROG function. The
;; next statement of a PROG function to be evaluated is immediately
;; preceded by LABEL. A GO may only appear in the following situations:
;; 1. At the top level of a PROG referencing a label which also
;;    appears at the top level of the same PROG.
;; 2. As the consequent of a COND item of a COND appearing on the
;;    top level of a PROG.
;; 3. As the consequent of a COND item which appears as the
;;    consequent of a COND item to any level.
;; 4. As the last statement of a PROGN which appears at the top
;;    level of a PROG or in a PROGN appearing in the consequent of a
;;    COND to any level subject to the restrictions of 2 and 3.
;; 5. As the last statement of a PROGN within a PROGN or as the
;;    consequent of a COND in a PROGN to any level subject to the
;;    restrictions of 2, 3 and 4.
;; If LABEL does not appear at the top level of the PROG in which
;; the GO appears, an error occurs:
;; ***** LABEL is not a known label
;; If the GO has been placed in a position not defined by rules 1-5,
;; another error is detected:
;; ***** Illegal use of GO to LABEL

(import 'cs-cl:prog)
;; PROG(VARS:id-list, [PROGRAM:{id, any}]):any noeval, nospread
;; VARS is a list of ids which are considered fluid when the PROG is
;; interpreted and local when compiled. The PROGs variables are
;; allocated space when the PROG form is invoked and are deallocated
;; when the PROG is exited. PROG variables are initialized to
;; NIL. The PROGRAM is a set of expressions to be evaluated in order
;; of their appearance in the PROG function. Identifiers appearing
;; in the top level of the PROGRAM are labels which can be
;; referenced by GO. The value returned by the PROG function is
;; determined by a RETURN function or NIL if the PROG "falls
;; through".

(import 'cs-cl:progn)
;; PROGN([U:any]):any noeval, nospread
;; U is a set of expressions which are executed sequentially. The
;; value returned is the value of the last expression.

(import 'cs-cl:prog1)                      ; PSL
;; (prog1 [U:form]): any macro
;; Prog1 evaluates its arguments in order, like progn, but returns the
;; value of the first.

(import 'cs-cl:prog2)
;; PROG2(A:any, B:any)any eval, spread
;; Returns the value of B.
;; EXPR PROCEDURE PROG2(A, B);
;;    B;

(import 'cs-cl:return)
;; RETURN(U:any) eval, spread
;; Within a PROG, RETURN terminates the evaluation of a PROG
;; and returns U as the value of the PROG. The restrictions on the
;; placement of RETURN are exactly those of GO. Improper placement
;; of RETURN results in the error:
;; ***** Illegal use of RETURN


;;; Error Handling
;;; ==============

;; THIS CODE COULD BE IMPROVED!

(defun error (number message)
  "ERROR(NUMBER:integer, MESSAGE:any) eval, spread
NUMBER and MESSAGE are passed back to a surrounding ERRORSET (the
Standard LISP reader has an ERRORSET). MESSAGE is placed in the
global variable EMSG!* and the error number becomes the value of
the surrounding ERRORSET. FLUID variables and local bindings are
unbound to return to the environment of the ERRORSET. Global
variables are not affected by the process."
  (if (consp message)
      (setq message
            (let ((*print-case* :downcase))
              (cs-cl:apply #'concatenate 'string
                        (cons (princ-to-string (car message))
                              (loop
                                 for x in (cdr message)
                                 collect " "
                                 collect (princ-to-string x)))))))
  (setf emsg* message)
  ;; (cs-cl:error "***** SL error ~a: ~a" number message)
  ;; Do not include number in the output:
  (cs-cl:error "***** ~*~a" number message))

(defun error1 ()
  "This is the simplest error return, without a message printed.
It can be defined as ERROR(99,NIL) if necessary.
In PSL it is throw('!$error!$,99)."
  (cs-cl:error "***** SL no-message error"))

(defvar *debug nil
  "If non-nil then errorset does not catch errors,
so they fall through to the debugger.")

;; See also invoke-debugger in the CLHS.

(defun errorset (u msgp tr)
  "ERRORSET(U:any, MSGP:boolean, TR:boolean):any eval, spread
If an error occurs during the evaluation of U, the value of
NUMBER from the ERROR call is returned as the value of
ERRORSET. In addition, if the value of MSGP is non-NIL, the
MESSAGE from the ERROR call is displayed upon both the standard
output device and the currently selected output device unless the
standard output device is not open. The message appears prefixed
with 5 asterisks. The MESSAGE list is displayed without top level
parentheses. The MESSAGE from the ERROR call will be available in
the global variable EMSG!*. The exact format of error messages
generated by Standard LISP functions described in this document
are not fixed and should not be relied upon to be in any
particular form. Likewise, error numbers generated by Standard
LISP functions are implementation dependent.
If no error occurs during the evaluation of U, the value of
  (LIST (EVAL U)) is returned.
If an error has been signaled and the value of TR is non-NIL a
trace-back sequence will be initiated on the selected output
device. The traceback will display information such as unbindings
of FLUID variables, argument lists and so on in an implementation
dependent format."
  (if (or *debug tr)
      ;; Enter the debugger if an error arises.
      ;; Probably not the optimal way to generate a traceback!
      (list (eval u))
      ;; Handle any error that arises.
      (handler-case (list (eval u))     ; protected form
        (simple-error
            (err)
          (let ((fmt (simple-condition-format-control err))
                (args (simple-condition-format-arguments err)))
            (if (and msgp (cdr args))
                (progn
                  (fresh-line)
                  (cs-cl:apply #'format t fmt args)
                  (cs-cl:terpri)))
            (car args)))
        (cs-cl:error
            (err)
          (if msgp (format t "~&***** CL error: ~a~%" err))
          ;; This doesn't really work because it breaks in the context
          ;; of the errorset rather than the error!
          ;; It also breaks building bootstrap REDUCE on SBCL!
          ;; (break "errorset(~a)" u)
          999))))


;;; Vectors
;;; =======

(defalias 'getv 'aref
  "GETV(V:vector, INDEX:integer):any eval, spread
Returns the value stored at position INDEX of the vector V. The
type mismatch error may occur. An error occurs if the INDEX does
not lie within 0...UPBV(V) inclusive:
***** INDEX subscript is out of range")

(defalias 'igetv 'aref)

(defun mkvect (uplim)
  "MKVECT(UPLIM:integer):vector eval, spread
Defines and allocates space for a vector with UPLIM+1 elements
accessed as 0...UPLIM. Each element is initialized to NIL. An error
will occur if UPLIM is < 0 or there is not enough space for a vector
of this size:
***** A vector of size UPLIM cannot be allocated"
  (make-array (1+ uplim) :initial-element nil))

(defun putv (v index value)
  "PUTV(V:vector, INDEX:integer, VALUE:any):any eval, spread
Stores VALUE into the vector V at position INDEX. VALUE is
returned. The type mismatch error may occur. If INDEX does not
lie in 0...UPBV(V) an error occurs:
***** INDEX subscript is out of range"
  (setf (aref v index) value))

(defalias 'iputv 'putv)

(defun upbv (u)
  "UPBV(U:any):NIL,integer eval, spread
Returns the upper limit of U if U is a vector, or NIL if it is not."
  (if (vectorp u) (1- (cs-cl:length u))))

(defun mkvect8 (uplim)                  ; CSL
  "Make a vector of 8-bit signed integers, cf. mkvect."
  (make-array (1+ uplim) :element-type '(signed-byte 8) :initial-element 0))
(defalias 'getv8 'aref)                 ; CSL
(defalias 'putv8 'putv)                 ; CSL

(defun mkvect16 (uplim)                 ; CSL
  "Make a vector of 16-bit signed integers, cf. mkvect."
  (make-array (1+ uplim) :element-type '(signed-byte 16) :initial-element 0))
(defalias 'getv16 'aref)                ; CSL
(defalias 'putv16 'putv)                ; CSL


;;; Boolean Functions and Conditionals
;;; ==================================

(import 'cs-cl:and)
;; AND([U:any]):extra-boolean noeval, nospread
;; AND evaluates each U until a value of NIL is found or the end of the
;; list is encountered. If a non-NIL value is the last value it is returned,
;; or NIL is returned.
;; FEXPR PROCEDURE AND(U);
;; BEGIN
;;    IF NULL U THEN RETURN NIL;
;; LOOP: IF NULL CDR U THEN RETURN EVAL CAR U
;;       ELSE IF NULL EVAL CAR U THEN RETURN NIL;
;;    U := CDR U;
;;    GO LOOP
;; END;

(import 'cs-cl:cond)
;; COND([U:cond-form]):any noeval, nospread
;; The antecedents of all U's are evaluated in order of their
;; appearance until a non-NIL value is encountered. The consequent
;; of the selected U is evaluated and becomes the value of the
;; COND. The consequent may also contain the special functions GO
;; and RETURN subject to the restraints given for these functions in
;; \"Program Feature Functions\", section 3.7 on page 22. In these
;; cases COND does not have a defined value, but rather an
;; effect. If no antecedent is non-NIL the value of COND is NIL. An
;; error is detected if a U is improperly formed:
;; ***** Improper cond-form as argument of COND

(import 'cs-cl:not)
;; NOT(U:any):boolean eval, spread
;; If U is NIL, return T else return NIL (same as function NULL).
;; EXPR PROCEDURE NOT(U);
;;    U EQ NIL;

(import 'cs-cl:or)
;; OR([U:any]):extra-boolean noeval, nospread
;; U is any number of expressions which are evaluated in order of their
;; appearance. When one is found to be non-NIL it is returned as the
;; value of OR. If all are NIL, NIL is returned.
;; FEXPR PROCEDURE OR(U);
;; BEGIN SCALAR X;
;; LOOP: IF NULL U THEN RETURN NIL
;;        ELSE IF (X := EVAL CAR U) THEN RETURN X;
;;    U := CDR U;
;;    GO LOOP
;; END;


;;; Arithmetic Functions
;;; ====================

;; Use double precision floats.

(import 'cs-cl:abs)
;; ABS(U:number):number eval, spread
;; Returns the absolute value of its argument.
;; EXPR PROCEDURE ABS(U);
;;    IF LESSP(U, 0) THEN MINUS(U) ELSE U;

(defalias 'add1 'cs-cl:1+
  "ADD1(U:number):number eval, spread
Returns the value of U plus 1 of the same type as U (fixed or floating).
EXPR PROCEDURE ADD1(U);
   PLUS2(U, 1);")

(defalias 'difference 'cs-cl:-
  "DIFFERENCE(U:number, V:number):number eval, spread
The value U - V is returned.")

;; The Euclidean division property of the integers state that for u, v
;; in Z, v /= 0, there exist a unique quotient q and remainder r such
;; that u = qv + r (0 <= |r| < |v|).

;; In PSL:
;; divide( 5,  3) = ( 1 .  2)
;; divide( 5, -3) = (-1 .  2)
;; divide(-5,  3) = (-1 . -2)
;; divide(-5, -3) = ( 1 . -2)

;; If u and v have the same sign then the quotient q is positive; if u
;; and v have opposite signs then q is negative.  The remainder r has
;; the same sign as u.

;; The following definition agrees with that above:

(defun divide (u v)
  "DIVIDE(U:number, V:number):dotted-pair eval, spread
The dotted-pair (quotient . remainder) is returned. The quotient
part is computed the same as by QUOTIENT and the remainder
the same as by REMAINDER. An error occurs if division by zero is
attempted:
***** Attempt to divide by 0 in DIVIDE
EXPR PROCEDURE DIVIDE(U, V);
   (QUOTIENT(U, V) . REMAINDER(U, V));"
  (multiple-value-call #'cons (truncate u v)))

(defun expt (u v)
  ;; Defined explicitly so that it can be redefined in arith/math
  "EXPT(U:number, V:integer):number eval, spread
Returns U raised to the V power. A floating point U to an integer
power V does not have V changed to a floating number before
exponentiation."
  (cs-cl:expt u v))

(defalias 'fix 'cs-cl:truncate
  "FIX(U:number):integer eval, spread
Returns an integer which corresponds to the truncated value of U.
The result of conversion must retain all significant portions of U. If
U is an integer it is returned unchanged.")

(defun float (u)
  "FLOAT(U:number):floating eval, spread
The floating point number corresponding to the value of the
argument U is returned.  Some of the least significant digits of
an integer may be lost do to the implementation of floating point
numbers.  FLOAT of a floating point number returns the number
unchanged.  If U is too large to represent in floating point an
error occurs:
***** Argument to FLOAT is too large"
  ;; Floats must be double precision:
  (cs-cl:float u 1d0))

(defalias 'greaterp 'cs-cl:>
  "GREATERP(U:number, V:number):boolean eval, spread
Returns T if U is strictly greater than V, otherwise returns NIL.")

(defalias 'lessp 'cs-cl:<
  "LESSP(U:number, V:number):boolean eval, spread
Returns T if U is strictly less than V, otherwise returns NIL.")

;; The definitions in REDUCE don't work correctly with mixed integer
;; and float arguments, so...
(defalias 'geq 'cs-cl:>=)
(defalias 'leq 'cs-cl:<=)

(import 'cs-cl:max)
;; MAX([U:number]):number noeval, nospread, or macro
;; Returns the largest of the values in U. If two or more values are the
;; same the first is returned.
;; MACRO PROCEDURE MAX(U);
;;    EXPAND(CDR U, 'MAX2);

(defalias 'max2 'cs-cl:max
  "MAX2(U:number, V:number):number eval, spread
Returns the larger of U and V. If U and V are the same value U is
returned (U and V might be of different types).
EXPR PROCEDURE MAX2(U, V);
   IF LESSP(U, V) THEN V ELSE U;")

(import 'cs-cl:min)
;; MIN([U:number]):number noeval, nospread, or macro
;; Returns the smallest of the values in U. If two or more values are the
;; same the first of these is returned.
;; MACRO PROCEDURE MIN(U);
;;    EXPAND(CDR U, 'MIN2);

(defalias 'min2 'cs-cl:min
  "MIN2(U:number, V:number):number eval, spread
Returns the smaller of its arguments. If U and V are the same value,
U is returned (U and V might be of different types).
EXPR PROCEDURE MIN2(U, V);
   IF GREATERP(U, V) THEN V ELSE U;")

(defalias 'minus 'cs-cl:-
  "MINUS(U:number):number eval, spread
Returns -U.
EXPR PROCEDURE MINUS(U);
   DIFFERENCE(0, U);")

(defalias 'plus 'cs-cl:+
  "PLUS([U:number]):number noeval, nospread, or macro
Forms the sum of all its arguments.
MACRO PROCEDURE PLUS(U);
   EXPAND(CDR U, 'PLUS2);")

(defalias 'plus2 'cs-cl:+
  "PLUS2(U:number, V:number):number eval, spread
Returns the sum of U and V.")

(defun quotient (u v)
  "QUOTIENT(U:number, V:number):number eval, spread
The quotient of U divided by V is returned. Division of two positive
or two negative integers is conventional. When both U and V are
integers and exactly one of them is negative the value returned is
the negative truncation of the absolute value of U divided by the
absolute value of V. An error occurs if division by zero is attempted:
***** Attempt to divide by 0 in QUOTIENT"
  ;; Can probably implement this better using generic functions!
  (if (or (floatp u) (floatp v))
      (/ u v)
      (cs-cl:truncate u v)))

(defalias 'remainder 'cs-cl:rem
  "REMAINDER(U:number, V:number):number eval, spread
If both U and V are integers the result is the integer remainder of
U divided by V. If either parameter is floating point, the result is
the difference between U and V*(U/V) all in floating point. If either
number is negative the remainder is negative. If both are positive or
both are negative the remainder is positive. An error occurs if V is
zero:
***** Attempt to divide by 0 in REMAINDER
EXPR PROCEDURE REMAINDER(U, V);
   DIFFERENCE(U, TIMES2(QUOTIENT(U, V), V));")

(defalias 'sub1 'cs-cl:1-
  "SUB1(U:number):number eval, spread
Returns the value of U less 1. If U is a FLOAT type number, the
value returned is U less 1.0.
EXPR PROCEDURE SUB1(U);
   DIFFERENCE(U, 1);")

(defalias 'times 'cs-cl:*
  "TIMES([U:number]):number noeval, nospread, or macro
Returns the product of all its arguments.
MACRO PROCEDURE TIMES(U);
   EXPAND(CDR U, 'TIMES2);")

(defalias 'times2 'cs-cl:*
  "TIMES2(U:number, V:number):number eval, spread
Returns the product of U and V.")

;; Small integer (fixnum) arithmetic operators defined in
;; alg/farith.red:

(defun iplus2 (u v)
  (declare (fixnum u v))
  (the fixnum (+ u v)))

(defun itimes2 (u v)
  (declare (fixnum u v))
  (the fixnum (* u v)))

(defun isub1 (u)
  (declare (fixnum u))
  (the fixnum (1- u)))

(defun iadd1 (u)
  (declare (fixnum u))
  (the fixnum (1+ u)))

(defun iminus (u)
  (declare (fixnum u))
  (the fixnum (- u)))

(defun idifference (u v)
  (declare (fixnum u v))
  (the fixnum (- u v)))

(defun iquotient (u v)
  (declare (fixnum u v))
  (the fixnum (truncate u v)))

(defun iremainder (u v)
  (declare (fixnum u v))
  (the fixnum (rem u v)))

(defun igreaterp (u v)
  (declare (fixnum u v))
  (> u v))

(defun ilessp (u v)
  (declare (fixnum u v))
  (< u v))

(defun iminusp (u)
  (declare (fixnum u))
  (cs-cl:minusp u))

;; (defun iequal (u v)
;;   (declare (fixnum u v))
;;   (eql u v))

;; iequal is defined in CSL (but not PSL).  It is called with a list
;; as its first argument in sqrt2top in int/df2q.red, so it does not
;; always have integer arguments!  But I assume it will not be called
;; with float arguments.

(defalias 'iequal 'eql)

;; Small integer (fixnum) arithmetic operators required but not defined:

(defun itimes (u v)       ; used as a binary operator in dipoly/torder
  (declare (fixnum u v))
  (the fixnum (* u v)))

(defun izerop (u)                       ; used in plot/plotexp3
  (declare (fixnum u))
  (cs-cl:zerop u))

;; Fast built-in floating point functions:

;; (defalias 'ACOS 'acos)
;; (defalias 'ASIN 'asin)
;; (defalias 'ATAN 'atan)
;; (defalias 'ATAN2 'atan)
;; (defalias 'COS 'cos)
;; (defalias 'EXP 'exp)
;; (defalias 'LN 'log)
;; (defalias 'LOG 'log)
;; (defalias 'LOGB 'log)
;; (defsubst LOG10 (x) (log x 10))
;; (defalias 'SIN 'sin)
;; (defalias 'SQRT 'sqrt)
;; (defalias 'TAN 'tan)
;; ;; The following will fail for floats with very large magnitudes since
;; ;; they return fixnums rather than big integers.  If that is a problem
;; ;; then remove these aliases and in particular remove the lose flags
;; ;; in "eslrend.red".
;; (defalias 'CEILING 'ceiling)
;; (defalias 'FLOOR 'floor)
;; (defalias 'ROUND 'round)

;; The above cause errors in the arith test file when trig results or
;; arguments are complex so all commented out for now.


;;; Map Composite Functions
;;; =======================

(defun %%lam2fn (fn)
  "Make a lambda expression acceptable as a function by evaluating it."
  (if (eqcar fn 'lambda) (eval fn) fn))

(defun map (x fn)
  "MAP(X:list, FN:function):any eval, spread
Applies FN to successive CDR segments of X. NIL is returned.
EXPR PROCEDURE MAP(X, FN);
   WHILE X DO << FN X; X := CDR X >>;"
  (cs-cl:mapl fn x)
  nil)

(defun mapc (x fn)
  "MAPC(X:list, FN:function):any eval, spread
FN is applied to successive CAR segments of list X. NIL is returned.
EXPR PROCEDURE MAPC(X, FN);
   WHILE X DO << FN CAR X; X := CDR X >>;"
  (cs-cl:mapc fn x)
  nil)

(defun mapcan (x fn)
  "MAPCAN(X:list, FN:function):any eval, spread
A concatenated list of FN applied to successive CAR elements of X
is returned.
EXPR PROCEDURE MAPCAN(X, FN);
   IF NULL X THEN NIL
      ELSE NCONC(FN CAR X, MAPCAN(CDR X, FN));"
  (cs-cl:mapcan fn x))

(defun mapcar (x fn)
  "MAPCAR(X:list, FN:function):any eval, spread
Returned is a constructed list of FN applied to each CAR of list X.
EXPR PROCEDURE MAPCAR(X, FN);
   IF NULL X THEN NIL
      ELSE FN CAR X . MAPCAR(CDR X, FN);"
  (cs-cl:mapcar fn x))

(defun mapcon (x fn)
  "MAPCON(X:list, FN:function):any eval, spread
Returned is a concatenated list of FN applied to successive CDR
segments of X.
EXPR PROCEDURE MAPCON(X, FN);
   IF NULL X THEN NIL
      ELSE NCONC(FN X, MAPCON(CDR X, FN));"
  (cs-cl:mapcon fn x))

(defun maplist (x fn)
  "MAPLIST(X:list, FN:function):any eval, spread
Returns a constructed list of FN applied to successive CDR segments
of X.
EXPR PROCEDURE MAPLIST(X, FN);
   IF NULL X THEN NIL
      ELSE FN X . MAPLIST(CDR X, FN);"
  (cs-cl:maplist fn x))


;;; Composite Functions
;;; ===================

;; Common Lisp uses the test function eql by default
;; (see the CLHS 17.2.1 Satisfying a Two-Argument Test,
;; e.g. http://www.lispworks.com/documentation/HyperSpec/Body/17_ba.htm),
;; whereas Standard Lisp uses the test function equal, which must
;; therefore always be supplied to CL functions as the :test keyword
;; argument.

(defun append (u v)
  "(append U:list V:list): list expr
Returns a constructed list in which the last element of U is followed by the
first element of V. The list U is copied, but V is not."
  ;; Some REDUCE code assumes the PSL definition, which allows U to
  ;; have any type:
  (if (consp u) (cs-cl:append u v) v))

(defun assoc (u v)                      ; PSL definition
  "(assoc U:any V:any): pair, nil expr
If U occurs as the car portion of an element of the a-list V, the pair in which
U occurred is returned, otherwise nil is returned. The function equal is used
to test for equality.
\(de assoc (u v)
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (equal u (caar v))) (car v))
        (t (assoc u (cdr v)))))"
  (and (consp v)
       (loop for x in v do
            (if (and (consp x) (equal u (car x)))
                (return x)))))

(defun deflist (u ind)
  "DEFLIST(U:dlist, IND:id):list eval, spread
A \"dlist\" is a list in which each element is a two element list: (ID:id
PROP:any). Each ID in U has the indicator IND with property
PROP placed on its property list by the PUT function. The value
of DEFLIST is a list of the first elements of each two element list.
Like PUT, DEFLIST may not be used to define functions.
EXPR PROCEDURE DEFLIST(U, IND);
   IF NULL U THEN NIL
      ELSE << PUT(CAAR U, IND, CADAR U);
              CAAR U >> . DEFLIST(CDR U, IND);"
  (cs-cl:mapcar #'(lambda (x)
                 (if *defn (%%save-plist (car x)))
                 (put (car x) ind (cadr x))
                 (car x))
             u))

(defun delete (u v)
  "DELETE(U:any, V:list ):list eval, spread
Returns V with the first top level occurrence of U removed from it.
EXPR PROCEDURE DELETE(U, V);
   IF NULL V THEN NIL
      ELSE IF CAR V = U THEN CDR V
      ELSE CAR V . DELETE(U, CDR V);"
  (cs-cl:remove u v :test #'equal :count 1))

(defun digit (u)
  "DIGIT(U:any):boolean eval, spread
Returns T if U is a digit, otherwise NIL.
EXPR PROCEDURE DIGIT(U);
   IF MEMQ(U, '(!0 !1 !2 !3 !4 !5 !6 !7 !8 !9))
      THEN T ELSE NIL;"
  (cs-cl:member u '(\0 \1 \2 \3 \4 \5 \6 \7 \8 \9) :test #'eq))

(defun length (x)
  "LENGTH(X:any):integer eval, spread
The top level length of the list X is returned.
EXPR PROCEDURE LENGTH(X);
   IF ATOM X THEN 0
      ELSE PLUS(1, LENGTH CDR X);"
  ;; The above recursive definition uses too much stack.
  ;; The CL length function cannot be used because it does not accept
  ;; atoms or dotted pairs!
  ;; This iterative implementation is based on the description of
  ;; list-length in the CLHS:
  (do ((n 0 (1+ n))    ; counter
       (p x (cdr p)))  ; pointer
      ;; When pointer hits an atom, return the count:
      ((atom p) n)))

(defun liter (u)
  "LITER(U:any):boolean eval, spread
Returns T if U is a character of the alphabet, NIL otherwise.
EXPR PROCEDURE LITER(U);
   IF MEMQ(U, '(!A !B !C !D !E !F !G !H !I !J !K !L !M
                !N !O !P !Q !R !S !T !U !V !W !X !Y !Z
                !a !b !c !d !e !f !g !h !i !j !k !l !m
                !n !o !p !q !r !s !t !u !v !w !x !y !z))
      THEN T ELSE NIL;"
  (cs-cl:member u '(\A \B \C \D \E \F \G \H \I \J \K \L \M
                 \N \O \P \Q \R \S \T \U \V \W \X \Y \Z
                 \a \b \c \d \e \f \g \h \i \j \k \l \m
                 \n \o \p \q \r \s \t \u \v \w \x \y \z) :test #'eq))

(defun member (a l)
  "(member A:any L:any): extra-boolean expr
Returns nil if A is not equal to some top level element of the list L;
otherwise it returns the remainder of L whose first element is equal
to A."
  ;; This is the PSl definition, which accepts *anything* as its second argument!
  ;; REDUCE (crack in particular) requires this flexibility.
  ;; In Common Lisp, the second argument must be a proper list.
  (cond ((atom l) nil)
        ((equal a (car l)) l)
        (t (member a (cdr l)))))

(defun memq (a l)
  "(memq A:any L:any): extra-boolean expr
Returns nil if A is not eq to some top level element of the list L;
otherwise it returns the remainder of L whose first element is equal
to A."
  ;; This is the PSl definition, which accepts *anything* as its second argument!
  ;; REDUCE probably requires this flexibility.
  ;; In Common Lisp, the second argument must be a proper list.
  (cond ((atom l) nil)
        ((eq a (car l)) l)
        (t (memq a (cdr l)))))

(import 'cs-cl:nconc)
;; NCONC(U:list, V:list):list eval, spread
;; Concatenates V to U without copying U. The last CDR of U is
;; modified to point to V.
;; EXPR PROCEDURE NCONC(U, V);
;; BEGIN SCALAR W;
;;    IF NULL U THEN RETURN V;
;;    W := U;
;;    WHILE CDR W DO W := CDR W;
;;    RPLACD(W, V);
;;    RETURN U
;; END;

(defun pair (u v)
  ;; Could implement as pairlis, but pairlis doesn't guarantee the
  ;; ordering in the result list.
  "PAIR(U:list, V:list):alist eval, spread
U and V are lists which must have an identical number of elements.
If not, an error occurs (the 000 used in the ERROR call is arbitrary
and need not be adhered to). Returned is a list where each element
is a dotted-pair, the CAR of the pair being from U, and the CDR
the corresponding element from V.
EXPR PROCEDURE PAIR(U, V);
   IF AND(U, V) THEN (CAR U . CAR V) . PAIR(CDR U, CDR V)
      ELSE IF OR(U, V) THEN ERROR(000,
         \"Different length lists in PAIR\")
      ELSE NIL;"
  (if (/= (cs-cl:length u) (cs-cl:length v))
      (cs-cl:error "000 Different length lists in PAIR")
      (cs-cl:map 'cs-cl:list #'cs-cl:cons u v)))

(import 'cs-cl:reverse)
;; REVERSE(U:list):list eval, spread
;; Returns a copy of the top level of U in reverse order.
;; EXPR PROCEDURE REVERSE(U);
;; BEGIN SCALAR W;
;;    WHILE U DO << W := CAR U . W;
;;                  U := CDR U >>;
;;    RETURN W
;; END;

(defalias 'reversip 'cs-cl:nreverse)           ; PSL function

(defun sassoc (u v fn)
  "SASSOC(U:any, V:alist, FN:function):any eval, spread
Searches the alist V for an occurrence of U. If U is not in the alist
the evaluation of function FN is returned.
EXPR PROCEDURE SASSOC(U, V, FN);
   IF NULL V THEN FN()
      ELSE IF U = CAAR V THEN CAR V
      ELSE SASSOC(U, CDR V, FN);"
  (or (cs-cl:assoc u v :test #'equal) (funcall fn)))

(defun sublis (x y)
  "SUBLIS(X:alist, Y:any):any eval, spread
The value returned is the result of substituting the CDR of each
element of the alist X for every occurrence of the CAR part of that
element in Y.
EXPR PROCEDURE SUBLIS(X, Y);
   IF NULL X THEN Y
      ELSE BEGIN SCALAR U;
                 U := ASSOC(Y, X);
                 RETURN IF U THEN CDR U
                        ELSE IF ATOM Y THEN Y
                        ELSE SUBLIS(X, CAR Y) .
                             SUBLIS(X, CDR Y)
                 END;"
  (cs-cl:sublis x y :test #'equal))

(defun subst (u v w)
  "SUBST(U:any, V:any, W:any):any eval, spread
The value returned is the result of substituting U for all occurrences
of V in W.
EXPR PROCEDURE SUBST(U, V, W);
   IF NULL W THEN NIL
      ELSE IF V = W THEN U
      ELSE IF ATOM W THEN W
      ELSE SUBST(U, V, CAR W) . SUBST(U, V, CDR W);"
  (cs-cl:subst u v w :test #'equal))

;; This function is used in several places in REDUCE, but I can't find
;; a reference to it anywhere!  The documentation string below is
;; based on that in Emacs Lisp:
(defun rassoc (key list)
  "Return non-nil if KEY is equal to the cdr of an element of LIST.
The value is actually the first element of LIST whose cdr equals KEY."
  (cs-cl:rassoc key list :test #'equal))


;;; The Interpreter
;;; ===============

;; In "alg/reval.red" is the code
;; deflist('( ... (!*sq (lambda (x) nil))),'rtypefn);
;; which leads in "alg/elem.red" to (apply (lambda (x) nil) (!*sq ...))
;; and this fails in Common Lisp because a lambda form is not a function!
;; It might be better to add the function call to the code in reval,
;; but try this for now...

(defun apply (fn args)
  "Treat a lambda expression as an operator.
Otherwise revert to the Common Lisp apply."
  (cs-cl:apply (%%lam2fn fn) args))

;; APPLY(FN:{id,function}, ARGS:any-list):any eval, spread
;; APPLY returns the value of FN with actual parameters ARGS. The
;; actual parameters in ARGS are already in the form required for
;; binding to the formal parameters of FN. Implementation specific
;; portions described in English are enclosed in boxes.
;; EXPR PROCEDURE APPLY(FN, ARGS);
;; BEGIN SCALAR DEFN;
;;    IF CODEP FN THEN RETURN
;;       | Spread the actual parameters in ARGS
;;    | following the conventions: for calling
;;    | functions, transfer to the entry point
;;    | of the function, and return the value
;;    | returned by the function.;
;;    IF IDP FN THEN RETURN
;;    IF NULL(DEFN := GETD FN) THEN
;;       ERROR(000, LIST(FN, \"is an undefined function\"))
;;    ELSE IF CAR DEFN EQ 'EXPR THEN
;;       APPLY(CDR DEFN, ARGS)
;;    ELSE ERROR(000,
;;       LIST(FN, \"cannot be evaluated by APPLY\"));
;;    IF OR(ATOM FN, NOT(CAR FN EQ 'LAMBDA)) THEN
;;       ERROR(000,
;;          LIST(FN, \"cannot be evaluated by APPLY\"));
;;    RETURN
;;       | Bind the actual parameters in ARGS to
;;       | the formal parameters of the lambda
;;       | expression. If the two lists are not
;;       | of equal length then ERROR(000, \"Number
;;       | of parameters do not match\"); The value
;;       | returned is EVAL CADDR FN.
;; END;

(defun eval (u)
  "Treat (function foo) the same as the operator foo.
Otherwise revert to the Common Lisp eval."
  (if (and (consp u) (functionp (car u)))
      (cs-cl:apply (car u) (evlis (cdr u)))
      (cs-cl:eval u)))

;; EVAL(U:any):any eval, spread
;; The value of the expression U is computed. Error numbers are
;; arbitrary. Portions of EVAL involving machine specific coding are
;; expressed in English enclosed in boxes.
;; EXPR PROCEDURE EVAL(U);
;; BEGIN SCALAR FN;
;;    IF CONSTANTP U THEN RETURN U;
;;    IF IDP U THEN RETURN
;;       | U is an id. Return the value most
;;       | currently bound to U or if there
;;       | is no such binding: ERROR(000,
;;       | LIST(\"Unbound:\", U));
;;    IF PAIRP CAR U THEN RETURN
;;    IF CAAR U EQ 'LAMBDA THEN APPLY(CAR U, EVLIS CDR U)
;;    ELSE ERROR(000, LIST(CAR U,
;;       \"improperly formed LAMBDA expression\"))
;;    ELSE IF CODEP CAR U THEN
;;       RETURN APPLY(CAR U, EVLIS CDR U);
;;    FN := GETD CAR U;
;;    IF NULL FN THEN
;;       ERROR(000, LIST(CAR U, \"is an undefined function\"))
;;    ELSE IF CAR FN EQ 'EXPR THEN
;;       RETURN APPLY(CDR FN, EVLIS CDR U)
;;    ELSE IF CAR FN EQ 'FEXPR THEN
;;       RETURN APPLY(CDR FN, LIST CDR U)
;;    ELSE IF CAR FN EQ 'MACRO THEN
;;       RETURN EVAL APPLY(CDR FN, LIST U)
;; END;

(defun evlis (u)
  "EVLIS(U:any-list):any-list eval, spread
EVLIS returns a list of the evaluation of each element of U.
EXPR PROCEDURE EVLIS(U);
   IF NULL U THEN NIL
      ELSE EVAL CAR U . EVLIS CDR U;"
  (cs-cl:mapcar #'eval u))

(defun expand (l fn)
  "EXPAND(L:list, FN:function):list eval, spread
FN is a defined function of two arguments to be used in the expansion
of a MACRO. EXPAND returns a list in the form:
   (FN L0 (FN L1 ... (FN Ln-1 Ln) ... ))
where n is the number of elements in L, Li is the ith element of L.
EXPR PROCEDURE EXPAND(L,FN);
   IF NULL CDR L THEN CAR L
      ELSE LIST(FN, CAR L, EXPAND(CDR L, FN));"
  (if (null (cdr l))
      (car l)
    (list fn (car l) (expand (cdr l) fn))))

(defmacro function (fn)
  "FUNCTION(FN:function):function noeval, nospread
The function FN is to be passed to another function. If FN is to have
side effects its free variables must be fluid or global. FUNCTION is
like QUOTE but its argument may be affected by compilation. We
do not consider FUNARGs in this report."
  ;; In Common Lisp, fn must be a *defined* function or a lambda
  ;; expression.  The symbol car satisfies fboundp and (lambda ...)
  ;; satisfies functionp, so
  ;; (if (or (eqcar fn 'lambda) (fboundp `,fn))
  ;; But with the test above, the eds package will not build because
  ;; (function list) evaluates to #<FUNCTION LIST>, which cannot be
  ;; serialized so faslout fails.  At least temporarily, this should
  ;; work:
  (if (eqcar fn 'lambda)
      `(cs-cl:function ,fn)
      `(cs-cl:quote ,fn)))

(import 'cs-cl:quote)
;; QUOTE(U:any):any noeval, nospread
;; Stops evaluation and returns U unevaluated.
;; FEXPR PROCEDURE QUOTE(U);
;;    CAR U;


;;; Input and Output
;;; ================

;; An output filehandle is a (possibly dotted) list of the form
;; ('file output-stream) or ('pipe output-stream . process).
;; On CLISP, process is nil.

;; An input filehandle is a pair of the form
;; (input-stream . echo-stream).

;; Filehandles should probably be structures rather than lists!

(defun close (filehandle)
  "CLOSE(FILEHANDLE:any):any eval, spread
Closes the file with the internal name FILEHANDLE writing any
necessary end of file marks and such. The value of FILEHANDLE
is that returned by the corresponding OPEN. The value returned is
the value of FILEHANDLE. An error occurs if the file can not be
closed.
***** FILEHANDLE could not be closed"
  ;; A null filehandle represents standard IO; ignore it.
  (if filehandle
      (prog1 filehandle
        (cond
          ((eq (car filehandle) 'file)
           ;; Output file stream ('file output-stream):
           (cs-cl:close (cadr filehandle)))
          #+SBCL
          ((eq (car filehandle) 'pipe)
           ;; Output pipe stream ('pipe output-stream . process):
           (sb-ext:process-close (cddr filehandle)) ; closes output-stream
           (sb-ext:process-kill (cddr filehandle) 9)) ; 9 = SIGKILL
          #+CLISP
          ((eq (car filehandle) 'pipe)
           ;; Output pipe stream ('pipe output-stream):
           (cs-cl:close (cadr filehandle))) ; closes output-stream
          (t
           ;; Input filehandle -- close echo stream then input stream:
           (cs-cl:close (cdr filehandle))
           (cs-cl:close (car filehandle)))))))

(defun eject ()
  "EJECT():NIL eval, spread
Skip to the top of the next output page. Automatic EJECTs are
executed by the print functions when the length set by the PAGE-
LENGTH function is exceeded."
  nil)

(defvar %%linelength 80
  "Current Standard LISP line length accessed via function `LINELENGTH'.")

(defun linelength (len)
  "LINELENGTH(LEN:{integer, NIL}):integer eval, spread
If LEN is an integer the maximum line length to be printed before
the print functions initiate an automatic TERPRI is set to the value
LEN. No initial Standard LISP line length is assumed. The previous
line length is returned except when LEN is NIL. This special case
returns the current line length and does not cause it to be reset. An
error occurs if the requested line length is too large for the currently
selected output file or LEN is negative or zero.
***** LEN is an invalid line length"
  (if len
      (if (or (not (integerp len)) (<= len 0))
          (cs-cl:error "~a is an invalid line length" len)
        (prog1 %%linelength (setq %%linelength len)))
    %%linelength))

(defun lposn ()
  "LPOSN():integer eval, spread
Returns the number of lines printed on the current page. At the top
of a page, 0 is returned."
  0)

(defun substitute-in-file-name (filename)
  "Return a copy of FILENAME with all environment variables expanded.
Replace every substring of the form `$name' terminated by a
non-alphanumeric character by its value.  Called by `open'."
  ;; A simplified version of the Elisp function
  ;; `substitute-in-file-name'.
  ;; Replace environment variables with their values:
  (loop
     with beg and end = 0 and l
     while
       (and end (setq beg (position #\$ filename :start end)))
     do
       (push (subseq filename end beg) l)
       (setq end (position-if-not #'alphanumericp filename :start (1+ beg)))
       (push (getenv (subseq filename (1+ beg) end)) l)
     finally
       (if l (setq filename
                   (cs-cl:apply #'concatenate 'string
                             (nreverse
                              (if end
                                  (push (subseq filename end) l)
                                  l))))))
  filename)

(defun expand-file-name (filename)
  "Return a copy of FILENAME with a leading `.'  replaced by the
current working directory and each leading `..' replaced by its
parent.  Called by `open' on SBCL."
  ;; A simplified version of the Elisp function `expand-file-name'.
  ;; sb-ext:native-pathname seems necessary to preserve odd characters
  ;; such as ^ in a filename:
  #+SBCL (setq filename (sb-ext:native-pathname filename))
  (let ((d (pathname-directory filename)))
    (when (eq (car d) :relative)
      ;; Replace a leading "." with the current working directory:
      (when (equal (cadr d) ".")
        (setf (cdr d) (cddr d))         ; remove "." component
        (setq filename (merge-pathnames
                        (make-pathname :directory d :defaults filename))))
      ;; Replace each leading ".." with the parent directory:
      (loop with cwd = (pathname-directory *default-pathname-defaults*)
         while (cs-cl:member (cadr d) '(".." :up :back))
         do
           (setf (cdr d) (cddr d))      ; remove ".." component
           (setq cwd (butlast cwd))
           (setq filename (merge-pathnames
                           (make-pathname :directory d :defaults filename)
                           (make-pathname :directory cwd))))))
  filename)

;; CLISP user variable CUSTOM:*DEVICE-PREFIX* controls translation
;; between Cygwin pathnames (e.g., #P"/cygdrive/c/gnu/clisp/") and
;; native Win32 pathnames (e.g., #P"C:\\gnu\\clisp\\").

(defun open (file how)
  "OPEN(FILE:any, HOW:id):any eval, spread
Open the file with the system dependent name FILE for output if
HOW is EQ to OUTPUT, or input if HOW is EQ to INPUT. If the
file is opened successfully, a value which is internally associated with
the file is returned. This value must be saved for use by RDS and
WRS. An error occurs if HOW is something other than INPUT or
OUTPUT or the file can't be opened.
***** HOW is not option for OPEN
***** FILE could not be opened"
  (setq file (substitute-in-file-name file)) ; substitute environment variables
  #+SBCL (setq file (expand-file-name file)) ; expand . and ..
  ;; #+cygwin (setq file (win-to-cyg file))
  #+cygwin (setq file (parse-namestring file)) ; convert Windows filename to Cygwin format
  (cond ((eq how 'input)
         (let ((fh (cs-cl:open file :direction :input)))
           ;; An input filehandle is a pair of the form
           ;; (input-stream . echo-stream):
           (cons fh (make-echo-stream fh *standard-output*))))
        ((eq how 'output)
         (list 'file
               (cs-cl:open file :direction :output
                           :if-exists :supersede :if-does-not-exist :create)))
        (t (cs-cl:error "~a is not option for OPEN" how))))

(defun pagelength (len)
  (declare (ignore len))
  "PAGELENGTH(LEN:{integer, NIL}):integer eval, spread
Sets the vertical length (in lines) of an output page. Automatic page
EJECTs are executed by the print functions when this length is
reached. The initial vertical length is implementation specific. The
previous page length is returned. If LEN is 0, no automatic page
ejects will occur."
  nil)

(defvar %%posn 0
  "Number of characters in the current line output by Standard LISP.
Accessed (read-only) via the function `POSN'.
It's value should be between 0 and `%%linelength' inclusive.")

(defun posn ()
  "POSN():integer eval, spread
Returns the number of characters in the output buffer. When the
buffer is empty, 0 is returned."
  %%posn)

(defvar %%prin-space-maybe nil
  "True if there is a pending space to print.")

(defun %%prin-space-maybe ()
  "Record that a space should be printed unless at the beginning or
end of a line."
  (if (> %%posn 0)
      (setq %%prin-space-maybe t)))

(defun %%prin-string (s)
  "Print string S preceded by a space or newline if necessary.
Check and update `%%posn' to keep it <= `%%linelength'.
This is the only function that actually produces graphical output."
  (let ((len (cs-cl:length s)))
    (if %%prin-space-maybe (incf %%posn))
    (incf %%posn len)                   ; posn after printing s
    (if (> %%posn %%linelength)
        (progn
          (cs-cl:terpri)
          (setq %%posn len))            ; posn after printing s
        (if %%prin-space-maybe (cs-cl:princ #\Space)))
    (setq %%prin-space-maybe nil)
    (cs-cl:princ s)))

(defun princ (u)
  "PRINC(U:id):id eval, spread
U must be a single character id such as produced by EXPLODE or
read by READCH or the value of !$EOL!$. The effect is the character
U displayed upon the currently selected output device. The value of
!$EOL!$ causes termination of the current line like a call to TERPRI."
  (cond ((eq u $eol$) (terpri))
        (t (%%prin-string (princ-to-string u))))
  u)

(defun print (u)
  "PRINT(U:any):any eval, spread
Displays U in READ readable format and terminates the print line.
The value of U is returned.
EXPR PROCEDURE PRINT(U);
<< PRIN1 U; TERPRI(); U >>;"
  (prin1 u)
  (terpri)
  u)

(defun prin1 (u)
  "PRIN1(U:any):any eval, spread
U is displayed in a READ readable form. The format of display is the
result of EXPLODE expansion; special characters are prefixed with the
escape character !, and strings are enclosed in \"...\".  Lists are
displayed in list-notation and vectors in vector-notation.  The value
of U is returned."
  (cond ((symbolp u) (%%prin-string (%%prin1-id-to-string u)))
        ((stringp u) (%%prin-string (%%prin1-string-to-string u)))
        ((floatp u) (%%prin-string (%%prin-float-to-string u)))
        ((vectorp u) (%%prin-vector u #'prin1))
        ((atom u) (%%prin-string (prin1-to-string u)))
        ((eq (car u) 'quote) (%%prin-string "'") (prin1 (cadr u)))
        (t (%%prin-cons u #'prin1)))
  u)

(defun prin2 (u)
  "PRIN2(U:any):any eval, spread
U is displayed upon the currently selected print device but output is
not READ readable.  The value of U is returned. Items are displayed as
described in the EXPLODE function with the exceptions that the escape
character does not prefix special characters and strings are not
enclosed in \"...\".  Lists are displayed in list-notation and vectors
in vector-notation.  The value of U is returned."
  (cond ((symbolp u) (%%prin-string (%%prin2-id-to-string u)))
        ((floatp u) (%%prin-string (%%prin-float-to-string u)))
        ((vectorp u) (%%prin-vector u #'prin2))
        ((atom u) (%%prin-string (princ-to-string u)))
        ((eq (car u) 'quote) (%%prin-string "'") (prin2 (cadr u)))
        (t (%%prin-cons u #'prin2)))
  u)

(defun %%prin1-id-to-string (u)
  "Convert identifier U to a string including appropriate `!' escapes.
Convert to lower case if *printlower is non-nil; otherwise to upper case."
  (setf u (%%princ-to-string u))
  (loop with newu and c
     for i below (cs-cl:length u) do
       (setf c (aref u i))
       (unless (or (alpha-char-p c)
                   (and (> i 0) (digit-char-p c))
                   (char= c #\_))
         (push #\! newu))
       (push c newu)
     finally (return (coerce (nreverse newu) 'string))))

(defun %%prin2-id-to-string (u)
  "Convert identifier U to a string excluding inappropriate `!' escapes.
Convert to lower case if *printlower is non-nil; otherwise to upper case."
  (setf u (%%princ-to-string u))
  (if (string= "!:" u :end2 1) (subseq u 1) u))

(defun %%princ-to-string (u)
  "Print identifier U to a string without any escapes.
Convert to lower case if *printlower is non-nil; otherwise to upper case."
  (let ((*print-case* (if *printlower :downcase :upcase)))
    (cs-cl:princ-to-string u)))

(defun %%prin1-string-to-string (u)
  "Add delimiting \"s and escape internal \"s as \"\" in string U."
  (loop with p = 0 and q and v = (list "\"")
     ;; v must be a new cons to allow destructive reverse
     do
       (setq q (position #\" u :start p))
       (if q (incf q))
       (setq v (cons "\"" (cons (subseq u p q) v))
             p q)
     while q
     finally (return
               (cs-cl:apply #'concatenate 'string (nreverse v)))))

(defparameter *float-print-precision* 12
  ;; The choice of 12 is somewhat arbitrary.  Algebraic output seems
  ;; to default to 6.  13 or less makes arith.tst agree with its
  ;; reference output.  Should perhaps try to compute this; cf. !!nfpd
  ;; defined in the REDUCE source file "arith/paraset.red".
  "Number of significant decimal digits to include when printing floats, or nil.
If nil then floats are printed without any additional rounding.")

;; (defun %%prin-float-to-string (u)
;;   "Print a float to a string rounded to include only significant digits."
;;   ;; Rescale u so that the significant digits form the integer part,
;;   ;; round that and then undo the rescaling.
;;   (princ-to-string
;;    (if (and *float-print-precision* (not (zerop u)))
;;        (let* ((e (floor (log (abs u) 10d0))) ; decimal exponent
;;               ;; |u| = m 10^e, where 0 <= m < 10, so (for e >= 0) the
;;               ;; integer part of u contains e+1 digits.  To make u
;;               ;; contain d significant digits, multiply by a scale
;;               ;; factor s = 10^(d-e-1), round and divide s out again:
;;               (s (expt 10d0 (- *float-print-precision* e 1))))
;;          (setq u (/ (fround (* u s)) s)))
;;        u)))

;; Using `format' instead of `princ-to-string' below might be better.
;; (format nil "~,,,,,,'ee" 1e10) -> "1.0e+10"
;; But deciding between ~f and ~e format to emulate Standard Lisp
;; print output might not be so easy.  So, at least for now, use the
;; following hack!

(defun %%prin-float-to-string (u)
  "Print a float to a string rounded to include only significant digits."
  ;; Rescale u so that the significant digits form the integer part,
  ;; round that and then undo the rescaling.
  (let ((s (princ-to-string
            (if (and *float-print-precision* (not (zerop u)))
                (let* ((e (floor (log (abs u) 10d0))) ; decimal exponent
                       ;; |u| = m 10^e, where 0 <= m < 10, so (for e >= 0) the
                       ;; integer part of u contains e+1 digits.  To make u
                       ;; contain d significant digits, multiply by a scale
                       ;; factor s = 10^(d-e-1), round and divide s out again:
                       (s (expt 10d0 (- *float-print-precision* e 1))))
                  (setq u (/ (fround (* u s)) s)))
                u)))
        p)
    ;; Lower-case an E if necessary and follow e with + unless there is already a -.
    (when (setq p (position #+SBCL #\e #+CLISP #\E s))
      #+CLISP (setf (aref s p) #\e)
      (incf p)
      (unless (char-equal (aref s p) #\-)
        (setq s (concatenate 'string (subseq s 0 p) "+" (subseq s p)))))
    s))

(defun %%prin-vector (u prinfn)
  "Print vector U delimited by [ and ] using PRINFN to print each element."
  (loop
     initially (%%prin-string "[") (funcall prinfn (aref u 0))
     for i from 1 below (cs-cl:length u) do
       (%%prin-space-maybe) (funcall prinfn (aref u i))
     finally (%%prin-string "]")))

(defun %%prin-cons (u prinfn)
  "Print cons cell U using PRINFN."
  (%%prin-string "(")
  (funcall prinfn (car u))
  (%%prin-cdr (cdr u) prinfn)
  (%%prin-string ")"))

(defun %%prin-cdr (u prinfn)
  "If U is non-nil then print it or its elements spaced appropriately.
U is the cdr of a cons cell: nil, an atom or another cons cell.
Cons cell elements are printed using PRINFN."
  (cond ((null u))                      ; do nothing
        ((atom u)
         (%%prin-space-maybe) (%%prin-string ".")
         (%%prin-space-maybe) (funcall prinfn u))
        (t (%%prin-space-maybe)
           (funcall prinfn (car u))
           (%%prin-cdr (cdr u) prinfn))))

(defun %%default-read-stream ()
  "The default read stream using the current value of *standard-input*."
  (cons *standard-input* *standard-input*))

(defparameter +default-read-stream+ (%%default-read-stream)
  "The default read stream using the initial value of *standard-input*.
This must be re-set when Standard Lisp is started to work in a saved
CLISP memory image.")

(defvar %%read-stream +default-read-stream+
  "The current input filehandle: a cons pair of the form
\(input-stream . echo-stream).
This must be re-set when Standard Lisp is started to work in a saved
CLISP memory image.")

(defun %%read-stream ()
  "Return the appropriate input stream depending on the value of *echo."
  (or (and *echo (cdr %%read-stream)) (car %%read-stream)))

(defun rds (filehandle)
  "RDS(FILEHANDLE:any):any eval, spread
Input from the currently selected input file is suspended and
further input comes from the file named. FILEHANDLE is a system
dependent internal name which is a value returned by OPEN. If
FILEHANDLE is NIL the standard input device is selected. When end
of file is reached on a non-standard input device, the standard
input device is reselected. When end of file occurs on the
standard input device the Standard LISP reader terminates. RDS
returns the internal name of the previously selected input file.
***** FILEHANDLE could not be selected for input"
  (prog1
      %%read-stream
    (setq %%read-stream
          (if (and filehandle (open-stream-p (car filehandle)))
              filehandle
              +default-read-stream+))))

(defparameter *sl-readtable* (copy-readtable)
  "Readtable implementing Standard Lisp syntax.
% introduces a comment and ! is the single-escape character.")
;; Cannot redefine *readtable* directly because it would come into
;; effect immediately during a load of the uncompiled file and break
;; the syntax below!
(set-syntax-from-char #\% #\; *sl-readtable*)
(set-syntax-from-char #\; #\A *sl-readtable*)
(set-syntax-from-char #\! #\\ *sl-readtable*)
(set-syntax-from-char #\\ #\A *sl-readtable*)
(set-syntax-from-char #\# #\A *sl-readtable*)
(set-syntax-from-char #\| #\A *sl-readtable*)

(defparameter *string-readtable* (copy-readtable *sl-readtable*)
  "Readtable implementing Standard Lisp string syntax.
No escape characters are defined.")
(set-syntax-from-char #\! #\A *string-readtable*)

(unless (fboundp '%%cl-read-string)
  (setf (symbol-function '%%cl-read-string)
        (get-macro-character #\" *sl-readtable*)))

(defun %%sl-read-string (stream closech)
  ;; This accumulates chars until it sees same char that invoked it,
  ;; namely closech. See the function read-string in
  ;; "sbcl-1.4.14/src/code/reader.lisp".
  (declare (character closech))
  (let* ((*readtable* *string-readtable*)
         (s (%%cl-read-string stream closech)))
    (loop while ;; following character is "
         (char= (peek-char nil stream nil $eof$ t) closech)
       do ;; read and ignore it
         (read-char stream nil $eof$ t)
       ;; then read and concatenate the following string
         (setq s (concatenate 'string s (string closech)
                              (%%cl-read-string stream closech))))
    s))

(set-macro-character #\" #'%%sl-read-string nil *sl-readtable*)

;; The read functions (rather than open or rds) must select the echo
;; stream dynamically because REDUCE sets *echo AFTER open and rds
;; have been called.  They do this by calling the function
;; %%read-stream, which returns either the input stream or the echo
;; stream depending on the value of *echo.

(defun read ()
  "READ():any
The next expression from the file currently selected for
input. Valid input forms are: vector-notation, dot-notation,
list-notation, numbers, function-pointers, strings, and
identifiers with escape characters. Identifiers are interned on
the OBLIST (see the INTERN function in \"Identifiers\"). READ
returns the value of !$EOF!$ when the end of the currently
selected input file is reached."
  (let* ((*readtable* *sl-readtable*))
    ;; The case sensitivity mode is one of the symbols :upcase,
    ;; :downcase, :preserve, or :invert.
    ;; (setf (readtable-case *readtable*)
    ;;       (if *raise :downcase :preserve))
    ;; Using read-preserving-whitespace rather than read seems to be
    ;; more consistent with PSL and CSL: it leaves the EOL to be read
    ;; by REDUCE, which counts input lines in each file into the value
    ;; of curline* and this is used in rlisp88.tst.
    (cs-cl:read-preserving-whitespace (%%read-stream) nil $eof$)))

(defvar %%readch-escape nil
  "True if the next character to be read by READCH should be escaped.")

(defun readch ()
  "READCH():id
Returns the next interned character from the file currently selected
for input. Two special cases occur. If all the characters in an input
record have been read, the value of !$EOL!$ is returned. If the file
selected for input has all been read the value of !$EOF!$ is returned.
Comments delimited by % and end-of-line are not transparent to READCH."
  ;; This function must perform any required case change.
  (let ((c (read-char (%%read-stream) nil $eof$)))
    (if (eq c $eof$)
        (progn
          (setq %%readch-escape nil)
          $eof$)
        (cond ((eq c #\!)
               (setq %%readch-escape (not %%readch-escape)) '!)
              (%%readch-escape
               (setq %%readch-escape nil) (%intern-character c))
              (*raise (%intern-character (cs-cl:char-downcase c)))
              (t (%intern-character c))))))

(defun terpri ()
  "TERPRI():NIL
The current print line is terminated."
  (setf %%posn 0)
  (cs-cl:terpri)
  nil)

(defun %%default-write-stream ()
  "The default write stream using the current value of *standard-output*."
  (list 'file *standard-output*))

(defparameter +default-write-stream+ (%%default-write-stream)
  "The default write stream using the initial value of *standard-output*.
This must be re-set when Standard Lisp is started to work in a saved
CLISP memory image.")

(defvar %%write-stream +default-write-stream+
  "The current output filehandle: a dotted-list of the form
\('file . output-stream) or ('pipe output-stream . process).
This must be re-set when Standard Lisp is started to work in a saved
CLISP memory image.")

(defun wrs (filehandle)
  "WRS(FILEHANDLE:any):any eval, spread
Output to the currently active output file is suspended and further
output is directed to the file named. FILEHANDLE is an internal
name which is returned by OPEN. The file named must have been
opened for output. If FILEHANDLE is NIL the standard output
device is selected. WRS returns the internal name of the previously
selected output file.
***** FILEHANDLE could not be selected for output"
  (prog1
      %%write-stream
    ;; This fails to compile (report as SBCL bug?):
    ;; (setq *standard-output* (cdr +default-write-stream+)
    ;;    %%write-stream +default-write-stream+)
    ;; But this version compiles OK:
    (setq %%write-stream +default-write-stream+
          *standard-output* (cadr %%write-stream))
    (when filehandle
      (cond
        ((eq (car filehandle) 'file)
         ;; Output file stream ('file output-stream):
         (if (open-stream-p (cadr filehandle))
             (setq *standard-output* (cadr filehandle)
                   %%write-stream filehandle)))
        ((eq (car filehandle) 'pipe)
         ;; Output pipe stream ('pipe output-stream . process):
         (if (open-stream-p (cadr filehandle))
             (setq *standard-output* (cadr filehandle)
                   %%write-stream filehandle)))))))

(defun pipe-open (command how)
  "Run COMMAND asynchronously with input via the pipe returned as a
stream by this function."
  (cond ((eq how 'output)
         #+SBCL
         ;; An output filehandle is a dotted-list of the form ('file .
         ;; output-stream) or ('pipe output-stream . process):
         (let ((p (sb-ext:run-program "cmd" (list "/c" command)
                                      :wait nil :search t :input :stream
                                      :escape-arguments nil)))
           (cons 'pipe (cons (sb-ext:process-input p) p)))
         #+CLISP
         ;; An output filehandle is a dotted-list of the form ('file .
         ;; output-stream) or ('pipe output-stream . nil):
         ;; (list 'pipe (ext:run-shell-command command :input :stream :wait nil)))
         (list 'pipe (ext:make-pipe-output-stream command)))
        (t (cs-cl:error "~a is not (currently) an option for PIPE-OPEN" how))))

(defun channelflush (filehandle)        ; PSL
  "Flush FILEHANDLE if it is a pipe stream."
  ;; filehandle = ('pipe output-stream . process)
  (if (eq (car filehandle) 'pipe)
      (finish-output (cadr filehandle))))

(defun flush ()                         ; CSL
  "Flush the current output stream."
  (finish-output (cadr %%write-stream)))


;;; PSL/CSL functions and some other required functions
;;; ===================================================

;; In the Standard Lisp world, "character" means either a symbol whose
;; name is one character long or an ASCII character code.

(defconstant +short-day-names+
  #("Mon" "Tue" "Wed" "Thu" "Fri" "Sat" "Sun")
  "A vector of names of the days abbreviated to 3 letters.")

(defconstant +short-month-names+
  #("Jan" "Feb" "Mar" "Apr" "May" "Jun" "Jul" "Aug" "Sep" "Oct" "Nov" "Dec")
  "A vector of names of the months abbreviated to 3 letters.")

(defun date-and-time ()                 ; CSL
  "Return a string of the form \"Fri Feb 01 18:38:36 2019\"."
  (multiple-value-bind
        (second minute hour date month year day)
      (get-decoded-time)
    (format nil "~a ~a ~2,'0d ~2,'0d:~2,'0d:~2,'0d ~d"
            (aref +short-day-names+ day)
            (aref +short-month-names+ (1- month))
            date hour minute second year)))

(defun date ()                          ; PSL
  "(date): string expr
The date in the form \"day-month-year\"
1 lisp> (date)
\"21-Jan-1997\""
  (multiple-value-bind
        (second minute hour date month year)
      (get-decoded-time)
    (declare (ignore second minute hour))
    (format nil "~2,'0d-~a-~d"
            date (aref +short-month-names+ (1- month)) year)))

(defalias 'datestamp 'get-universal-time
  "The number of seconds that have elapsed since some epoch.
This version uses the Common Lisp epoch at the beginning of the year
1900, whereas the CSL version uses the \"Unix time\" epoch at the
beginning of the year 1970.  The difference of 70 years is
70*31,536,000 = 2,207,520,000 seconds.  This function should not be
used to determine an absolute date or time!")

(defconstant +milliseconds-per-internal-time-unit+
  (/ 1000 internal-time-units-per-second)
  "Multiplier to convert internal time units to milliseconds.")

(defun time ()                          ; PSL
  "(time): integer expr
Elapsed time from some arbitrary initial point in milliseconds."
  ;; This is used for timing computations, so use run time.
  (round (* (get-internal-run-time) +milliseconds-per-internal-time-unit+)))

#+CLISP
(defun %%nth-room-value (n)
  "Return the Nth multiple value provided by CLISP `room' function.
Suppress the printed output."
  (let ((*standard-output* (make-broadcast-stream)))
    (nth-value n (room nil))))

(defun gctime ()
  "The total time (in milliseconds) spent in garbage collection."
  (round (*
          #+SBCL sb-ext:*gc-run-time*
          #+CLISP (%%nth-room-value 5)
          +milliseconds-per-internal-time-unit+)))

(defvar gcknt* 0
  "gcknt* = [Initially: 0] global
Records the number of times that the garbage collector has been
invoked.  Gcknt* may be reset to another value to record counts
incrementally, as desired.")

(defvar *previous-gc-run-time* 0
  "Total (internal) GC time up to previous garbage collection.")

#+SBCL
(defun %%gc-reporting ()
  "Increment garbage collection count and optionally output a report.
A function hung on the garbage collection hook."
  (incf gcknt*)
  (if *gc
      (format t "*** Garbage collection number ~a completed in ~ams.~%"
              gcknt*
              (round (* (- sb-ext:*gc-run-time* *previous-gc-run-time*)
                        +milliseconds-per-internal-time-unit+))))
  (setq *previous-gc-run-time* sb-ext:*gc-run-time*))

#+SBCL (pushnew '%%gc-reporting sb-ext:*after-gc-hooks*)

(defun gtheap ()
  "Size of the free dynamic space in bytes."
  #+SBCL (- (sb-ext:dynamic-space-size) (sb-ext:get-bytes-consed))
  #+CLISP (%%nth-room-value 1))

(defun explode2 (u)                     ; PSL
  "(explode2 U:atom-vector): id-list expr
PRIN2-like version of EXPLODE without escapes or double quotes."
  (cs-cl:map 'list #'%intern-character (princ-to-string u)))

(defun explode2uc (u)                   ; defined in "pslrend.red"
  "Upper-case version of explode2."
  ;; NB: downcase because of symbol name case inversion!
  (cl:map 'list
          #'(lambda (c) (cl:intern (cl:string c)))
          (cl:string-downcase (cl:princ-to-string u))))

(defun concat2 (s1 s2)
  "Concatenates its two string arguments, returning the newly created string."
  (concatenate 'string s1 s2))

(defun concat (&rest s)
  "Concatenates all of its string arguments, returning the newly created string."
  ;; Flagged variadic in clprolo.
  (cs-cl:apply #'concatenate 'string s))

;; (defalias 'allocate-string 'cs-cl:make-string ; PSL
;;   "(allocate-string SIZE:integer): string expr
;; Constructs and returns a string with SIZE characters. The contents of
;; the string are not initialized.")

(defun string2list (s)                  ; PSL
  "(string2list S:string): inum-list expr
Creates a list of length (add1 (size S)), converting the ASCII
characters into small integers.
lisp> (string2list \"STRING\")
\(83 84 82 73 78 71)"
  (cs-cl:map 'list
             #'(lambda (x) (cs-cl:char-code x))
             s))

(defun %%character (x)
  "Generalize cs-cl:character to accept also a character code."
  (if (integerp x)
      (if (and (<= 0 x) (<= x 255))
          ;; Was 127, but then reading rlisp/tok.red fails!
          ;; Should 128 -> nil as specified for PSL?
          (code-char x)
          (cs-cl:error
           "***** SL error in `%%character': ~d is not a character code" x))
      (%character-inverted x)))

(defun list2string (l)                  ; PSL
  "(list2string L:inum-list): string expr
Allocates a string of the same size as L, and converts small integers
into characters according to their ASCII code. An integer outside the
range of 0 ... 127 will result in an error.
lisp> (list2string '(83 84 82 73 78 71))
\"STRING\"
Identifiers are case-inverted."
  (cs-cl:map 'string #'%%character l))

(defun list2widestring (u)
  "Take a list U of integers (each in the range 0-0x0010ffff) and turn
it into a string encoding those using UTF-8.  It will also support use
of identifiers or strings as well as integers, and will use the first
character (N.B. not octet) as the code concerned.
Identifiers are case-inverted."
  ;; This is a re-implementation of the procedure in rlisp/tok.red.
  ;; It must be flagged lose in clprolo.
  ;; It should make string!-store etc. redundant.
  (cs-cl:map 'string
             #'(lambda (x) (if (integerp x) (code-char x) (%character-inverted x)))
             u))

(defun widestring2list (u)
  "Given a string U that may contain bytes that are over 127, return a
list of positive integers corresponding to the characters in it if it
is interpreted as being encoded in UTF-8.  The behaviour if the bytes
are not valid UTF-8 is to be considered undefined."
  ;; This is a re-implementation of the procedure in rlisp/tok.red.
  ;; It must be flagged lose in clprolo.
  ;; It should make moan!-if!-truncated etc. redundant.
  (cs-cl:map 'list #'cs-cl:char-code u))

;; (defun string-store (s i x)              ; PSL
;;   "(string-store S:string I:integer X:char): None Returned expr
;; Stores into a PSL string. String indexes start with 0."
;;   (setf (aref s i) (%%character x)))

(defalias 'string-length 'cs-cl:length  ; PSL
  "(string-length S:string): integer expr
Returns the number of elements in a PSL string. Since indexes start with
index 0, the size is one larger than the greatest legal index. Compare this
function with string-upper-bound, documented below.")

(defun char-downcase (c)                ; CSL
  "Convert single-character identifier C to lower case."
  (cs-cl:intern (cs-cl:string-downcase (symbol-name c))))

(defalias 'red-char-downcase 'char-downcase) ; PSL

(defun char-upcase (c)                  ; CSL
  "Convert single-character identifier C to lower case."
  (cs-cl:intern (cs-cl:string-upcase (symbol-name c))))

(defun int2id (i)                       ; PSL
  "(int2id I:integer): id expr
Converts an integer to an id; this refers to the I'th id in the id space. Since
0 ... 255 correspond to ASCII characters, int2id with an argument in this
range converts an ASCII code to the corresponding single character id. The
id NIL is always found by (int2id 128)."
  ;; Defined in csl.red as
  ;; inline procedure int2id x; % Turns 8-bit value into name. Only OK is under 0x80
  ;;   intern list2string list x;
  ;; (unless (= i 128) (%intern-character (code-char i)))
  (%intern-character (code-char i)))

(defun id2int (d)                       ; PSL
  "(id2int D:id): integer expr
Returns the id space position of D as a LISP integer."
  ;; Defined in csl.red as
  ;; inline procedure id2int x; % Gets first octet of UTF-8 form of name
  ;;   car string2list x;
  ;; (if d (cs-cl:char-code (aref (symbol-name d) 0)) 128)
  (cs-cl:char-code (aref (symbol-name d) 0)))

(defun char-code (c)                    ; PSL
  "Returns the code attribute of C. (In PSL this function is an identity function.)"
  (cs-cl:char-code (character c)))

(defalias 'id2string 'symbol-name       ; PSL
  "(id2string D:id): string expr
Get name from id space. Id2string returns the print name of its argument
as a string. This is not a copy, so destructive operations should not be performed
on the result. PSL uses an escape convention for notating identifiers
which contain special characters. Any character which follows the character
! is considered to be an alphabetic character. In the example, notice that the
character ! does not appear in the result.
1 lisp> (id2string 'is-!%)
\"is-%\"")

(defun string-downcase (u)
  "Convert identifier or string U to a lower-case string."
  (cs-cl:string-downcase (if (symbolp u) (symbol-name u) u)))

(defalias 'land 'cs-cl:logand           ; PSL
  "(land U:integer V:integer): integer expr
Bitwise or logical and. Each bit of the result is independently
determined from the corresponding bits of the operands.")

(defalias 'lshift 'cs-cl:ash            ; PSL
  ;; Not quite right for negative integers N!
  "(lshift N:integer K:integer): integer expr
Shifts N to the left by K bits. The effect is similar to multiplying
by 2 to the K power. Negative values are acceptable for K, and cause a
right shift (in the usual manner). Lshift is a logical shift, so right
shifts do not resemble division by a power of 2.")

(defun list2vector (l)                  ; PSL
  "(list2vector L:list): vector expr
Copy the elements of the list into a vector of the same size.
1 lisp> (list2vector '(V E C T O R))
[V E C T O R]"
  (cs-cl:apply #'cs-cl:vector l))

(defalias 'list-to-vector 'list2vector)

(defun vector2list (v)                  ; PSL (should be flagged lose!)
  "(vector2list V:vector): list expr
Create a list of the same size as V, the elements are copied in a left to right
order.
1 lisp> (vector2list [L I S T])
\(L I S T)"
  (cs-cl:map 'list #'cs-cl:identity v))

(defalias 'copy 'cs-cl:copy-tree        ; PSL
  "(copy X:any): any expr
This function returns a copy of X. While each pair is copied, atomic
elements (for example ids, strings, and vectors) are not.")

;; REDUCE needs complexp in various places but also needs to be able
;; to overwrite it, as in rlisp88.tst:
(defalias 'complexp 'cs-cl:complexp)

;; The next three PSL definitions are based on those at the end of
;; support/csl.red:

(defmacro bothtimes (u)                 ; PSL
  "Evaluate the expression U at both compile time and load time."
  `(eval-when (:compile-toplevel :load-toplevel :execute) ,u))

(defmacro compiletime (u)               ; PSL
  "Evaluate the expression U at compile time only."
  `(eval-when (:compile-toplevel :execute) ,u))

(defmacro loadtime (u)                  ; PSL
  "Evaluate the expression U at load time only."
  `(eval-when (:load-toplevel :execute) ,u))

(defalias 'prop 'cs-cl:symbol-plist)    ; PSL
(defalias 'plist 'cs-cl:symbol-plist)   ; CSL

(defun setprop (u l)                    ; PSL
  "(setprop U:id L:any): L:any expr
Store item L as the property list of U."
  (setf (symbol-plist u) l))

;; CL union and intersection return different orderings that those in
;; the REDUCE source, which leads to different (although probably not
;; incorrect) results, so don't use them.  However, union is needed in
;; the build process before it is defined in the rlisp module, so
;; define an initial version here, which will be replaced when
;; building rlisp:

(defun union (x y)                      ; PSL
  "(union X:list Y:list): list expr
Returns the union of sets X and Y."
  (cs-cl:union x y :test #'equal))

(defalias 'mod 'cs-cl:mod) ; not just imported because cali redefines mod
(defalias 'gcdn 'cs-cl:gcd)
(defalias 'lcmn 'cs-cl:lcm)
(defalias 'yesp1 'cs-cl:y-or-n-p)


;;; Operating system interface
;;; ==========================

;; (defun system (command)                  ; PSL
;;   "(system COMMAND:string):undefined expr
;; Run a (system specific) command interpreter synchronously, pass
;; COMMAND to the interpreter and return the process exit code."
;;   ;; Split off the arguments:
;;   (setq command
;;      (loop with beg and end = 0
;;         while end
;;         do (setq beg (position-if #'(lambda (x) (char/= x #\Space))
;;                                   command :start end))
;;           (unless beg (loop-finish))
;;           (setq end (position #\Space command :start beg))
;;         collect (subseq command beg end)))
;;   (sb-ext:process-exit-code
;;    (sb-ext:run-program "cmd" (cons "/c" command)
;;                     :search t :output t :escape-arguments nil)))

(defun system (command)                 ; PSL
  "(system COMMAND:string):undefined expr
Run a (system specific) command interpreter synchronously, pass
COMMAND to the interpreter and return the process exit code."
  #+SBCL (sb-ext:process-exit-code
          (sb-ext:run-program "cmd" (list "/c" command)
                              :search t :output t :escape-arguments nil))
  ;; Cygwin CLISP behaves as if running on Unix, not Windows.
  ;; ext:shell returns nil for normal exit with status 0!
  #+CLISP (or (ext:shell command) 0))

#+SBCL
(defun system-to-string (command)       ; experimental - not tested!
  (with-output-to-string (*standard-output*)
    (system command)))

#+CLISP
(defun system-to-string (command)       ; experimental - doesn't seem to work
  (let ((s (ext:run-shell-command command :output :stream)))
    (get-output-stream-string s)))

(defun pwd ()                           ; PSL
  "(pwd):STRING expr
Return the current working directory in system specific format."
  #+SBCL (sb-ext:native-namestring *default-pathname-defaults*)
  #+CLISP (namestring (ext:cd)))

#+SBCL
(defun cd (dir)                         ; PSL
  "(cd DIR:string):BOOLEAN expr
Set the current working directory to DIR after expanding the filename
according to the rules of the operating system.  If this operation is
not sucessful, the value Nil is returned."
  (setq dir (pathname dir))
  ;; Allow dir not to end with a separator:
  (if (string/= (file-namestring dir) "")
      (setq dir (make-pathname :directory
                               (append (or (pathname-directory dir) '(:relative))
                                       (list (file-namestring dir))))))
  ;; Expand environment variables, "." and "..":
  (setq dir (substitute-in-file-name (namestring dir)))
  (setq dir (expand-file-name dir))
  (setq dir (merge-pathnames dir))
  (and (probe-file dir)
       ;; Return a more useful value than t:
       (sb-ext:native-namestring
        (setq *default-pathname-defaults* dir))))

#+CLISP
(defun cd (dir)                         ; PSL
  "(cd DIR:string):BOOLEAN expr
Set the current working directory to DIR after expanding the filename
according to the rules of the operating system.  If this operation is
not sucessful, the value Nil is returned."
  ;; Expand environment variables, "." and "..":
  ;; In CLISP, MAKE-PATHNAME canonicalizes the PATHNAME directory component.
  (namestring (ext:cd (expand-file-name dir))))

(defalias 'filep 'probe-file)           ; PSL

#+SBCL (import 'sb-posix:getpid)
#+CLISP (defalias 'getpid 'os:process-id)


;;; Compile and load
;;; ================

(defun compile-file (input-file &rest other-args)
  ;; (compile-file input-file &key output-file verbose print
  ;; external-format)
  "Compile a \".sl\" file using Standard Lisp read syntax."
  (let ((*readtable*
         (if (string-equal (pathname-type input-file) "sl")
             *sl-readtable*
             (copy-readtable nil))))    ; normal CL syntax
    (cs-cl:apply #'cs-cl:compile-file input-file other-args)))

(defvar *verboseload nil
  "*verboseload = [Initially: nil] switch
If non-nil, a message is displayed when a request is made to load a
file which has already been loaded, when a file is about to be loaded,
and when the loading of a file is complete.  Since *redefmsg is set to
the value of *verboseload within `load', a non-nil value will also
cause a message to be printed whenever a function is redefined during
a load.")

(defvar options* nil
  "A list of loaded `modules', which are loaded only once.
These are files referenced by symbols rather than strings.")

(defun load (file)             ; currently only supports a single file
  "(load [FILE:{string, id}]): nil macro
For each argument FILE, an attempt is made to locate a corresponding
file.  If a file is found then it will be loaded by a call on an
appropriate function.  A full file name is constructed by using the
directory specifications in loaddirectories* and the extensions in
loadextensions*.  The strings from each list are used in a left to
right order, for a given string from loaddirectories* each extension
from loadextensions* is used.

Load a \".sl\" file using Standard Lisp read syntax."
  ;; filename defaults are taken from *default-pathname-defaults*,
  ;; which defaults to the directory in which SBCL was started.
  (let ((*readtable* (copy-readtable nil)) ; normal CL syntax
        (*load-verbose* *verboseload)
        (*redefmsg *verboseload))
    (if (symbolp file)
        (progn
          (if (cs-cl:member file options*) (return-from load)) ; already loaded
          (push file options*)
          (setq file (cs-cl:string-downcase (symbol-name file))))
        (if (string-equal (pathname-type file) "sl")
            (setq *readtable* *sl-readtable*)))
    ;; Look in "." and "./fasl" and if not found then throw an error:
    (or (cs-cl:load file :if-does-not-exist nil)
        (cs-cl:load (concat2 "fasl/" file)))))


;;; Faslout/faslend interface
;;; =========================

(defvar *writingfaslfile nil
  "REDUCE variable set to t by FASLOUT and reset to nil by FASLEND.")
(defvar *int)

(defvar %%faslout-name.lisp)
(defvar %%faslout-stream)

(defun prettyprint (u)
  "Default prettyprint function, required for bootstrapping.
Redefined later as an autoload for the real prettyprinter."
  (print u))

(defun %%faslout-prettyprint (u)
  "The prettyprint function used for faslout generation.
It prints Common Lisp syntax to %%faslout-stream."
  (let (*print-gensym* ; inhibit printing #: prefix for uninterned symbols
        (*readtable* (copy-readtable nil))) ; needed for CLISP
    (cs-cl:print u %%faslout-stream)))

(defvar %%faslout-saved-prettyprint nil
  "The saved current global definition of the function prettyprint.
It is replaced during faslout.")

(defun faslout (name)
  "Compile subsequent input into Common Lisp FASL file \"NAME.fasl\".
NAME should be an identifier or string.  (The actual extension of fasl
files depends on the version of Common Lisp.)"
  ;; Output subsequent code as Common Lisp to a temporary file until
  ;; FASLEND evaluated.
  (setq name (string-downcase name))
  (if *int
      (format t "FASLOUT ~a: IN files$ or type in expressions.
When all done, execute FASLEND;~2%" name))
  (unless
      (setq %%faslout-stream
            (cs-cl:open (setq %%faslout-name.lisp (concat2 name ".lisp"))
                     :direction :output :if-exists :supersede
                     :external-format #+SBCL :UTF-8 #+CLISP charset:UTF-8))
    (cs-cl:error "Faslout: cannot open ~a" %%faslout-name.lisp))

  (setf %%faslout-saved-prettyprint (symbol-function 'prettyprint)
        (symbol-function 'prettyprint) (symbol-function '%%faslout-prettyprint))

  (setq *defn t
        *writingfaslfile t))

(flag '(faslout) 'opfn)
(flag '(faslout) 'noval)

;; SBCL outputs more detailed and useful messages than those that I
;; have therefore temporarily commented out below.  Delete them unless
;; they prove useful with other versions of Common Lisp.

(defun faslend ()
  "Terminate a previous FASLOUT and generate the compiled file."
  (unless *writingfaslfile
    (cs-cl:error "FASLEND is only allowed after a previous FASLOUT"))
  ;; First, tidy up after the call of FASLOUT:
  (unless
      (cs-cl:close %%faslout-stream)
    (cs-cl:error "Faslend: cannot close ~a" %%faslout-name.lisp))
  (setq *writingfaslfile nil
        *defn nil) ; necessary here if faslend not input as a statement

  (setf (symbol-function 'prettyprint) %%faslout-saved-prettyprint)

  ;; Now compile the Lisp output generated by FASLOUT:
  ;; (format t  "Compiling ~a..." %%faslout-name.lisp)
  ;; (if
  (compile-file %%faslout-name.lisp
                :external-format #+SBCL :UTF-8 #+CLISP charset:UTF-8)
  ;;      ;; (progn
  ;;      ;; (delete-file %%faslout-name.lisp) ; keep to aid debugging ???
  ;;      (format t "Compiling ~a...done" %%faslout-name.lisp)
  ;;      ;; nil)
  ;;      (cs-cl:error "Error compiling ~a" %%faslout-name.lisp))
  )

(defvar cursym*)

(defun faslendstat ()
  "Terminate reading faslend and turn defn off."
  ;; Modelled on endstat in rlisp/parser.
  (let ((x cursym*))
    (setq *defn nil)                    ; must do this ASAP!
    (comm1 'end)
    (list x)))

(put 'faslend 'stat 'faslendstat)       ; cf. endstat
(flag '(faslendstat) 'endstatfn)        ; ditto

(flag '(faslend) 'ignore)               ; to stop it getting compiled!


;;; User interface
;;; ==============

(defun standard-lisp ()
  "Switch to STANDARD LISP mode."
  (prog1
      (in-package :sl)
    (setq *readtable* *sl-readtable*
          ;; The REDUCE source code implies that 64-bit IEEE
          ;; arithmetic is expected and it seems to be necessary to
          ;; read the constant 1.0e300 in arith/paraset.red:
          *read-default-float-format* 'double-float
          ;; These must be re-set when Standard Lisp is started to
          ;; work in a saved CLISP memory image:
          +default-read-stream+ (%%default-read-stream)
          %%read-stream +default-read-stream+
          +default-write-stream+ (%%default-write-stream)
          %%write-stream +default-write-stream+)))

(defun start-reduce ()
  "Switch to STANDARD LISP mode and start REDUCE."
  (standard-lisp)
  (begin))

(import '(standard-lisp start-reduce) #+CLISP :cs-cl-user #+SBCL :cl-user)

(defun reset-readtable ()
  "Switch to Common Lisp read syntax."
  (setq *readtable* (copy-readtable nil)))

(pushnew :standard-lisp *features*)

(defparameter lispsystem* '(common-lisp)
  "Information about the Lisp system supporting REDUCE.
A list of identifiers indicating system properties.")

#+SBCL (pushnew 'sbcl lispsystem*)
#+CLISP (pushnew 'clisp lispsystem*)
#+win32 (pushnew 'win32 lispsystem*)
#+cygwin (pushnew 'cygwin lispsystem*)  ; together with unix
#+unix (pushnew 'unix lispsystem*)

#+SBCL
(defun compilation (on)
  "Set the SBCL evaluation mode to compile if ON is non-nil and to
interpret otherwise.  The default is compile."
  (setq sb-ext:*evaluator-mode*
        (if on :compile :interpret)))

;; In SBCL, inhibit printing of package prefixes in the debugger
;; (which doesn't seem to work):
#+SBCL (setq sb-ext:*debug-print-variable-alist* '((*print-escape* . nil)))

;; Common Lisp symbols used in REDUCE source code:
(import
 '(lambda warning
   unwind-protect evenp oddp
   string-not-greaterp symbol-name y-or-n-p ; used in clprolo
   force-output                             ; used in clrend
   file-write-date                          ; used in remake
   catch throw                              ; used in rubi_red
   sleep                                    ; used in crack
   ))

;; Cease inheriting the external symbols of :common-lisp except for
;; those that have been explicitly imported:
;; (unuse-package :common-lisp)

;; Unfortunately, the above does not work in reduce.img.  So try
;; shadowing all external CL symbols:
(do-external-symbols (s :cl)
  (multiple-value-bind (symbol status)
      (find-symbol (symbol-name s))
    ;; (if (eq status :internal) (print symbol))
    (if (eq status :inherited) (shadow symbol))))

;;; sl-on-cl.lisp ends here
