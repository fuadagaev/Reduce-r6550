% ----------------------------------------------------------------------
% $Id: acfsf.red,v 1.9 1999/04/12 09:25:48 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: acfsf.red,v $
% Revision 1.9  1999/04/12 09:25:48  sturm
% Removed procedure acfsf_canegrel and acfsf_anegrel.
% Updated comments for exported procedures.
%
% Revision 1.8  1999/04/04 19:01:52  sturm
% Added fluid declaration for !*gbverbose.
%
% Revision 1.7  1999/03/23 12:26:29  sturm
% Renamed switch rlsisqf to rlsiatadv.
%
% Revision 1.6  1999/03/23 07:54:31  dolzmann
% Changed copyright information.
% Added list of exported procedures and import list.
% Added fluids for the rcsid of the file and for the copyright information.
%
% Revision 1.5  1999/03/21 13:33:02  dolzmann
% Registered acfsf_getineq as the black box implementation for rl_getineq.
% Use cl_bnfsimpl instead of acfsf_bnfsimpl.
% Removed black box rl_zero.
% Added service rlthsimpl.
% Registered service rlqeipo.
% Registered service rlgentheo.
%
% Revision 1.4  1997/10/02 13:14:39  sturm
% The CGB switches have been renamed from gcgb... to cgb...
%
% Revision 1.3  1997/10/01 11:13:42  dolzmann
% Added service rlqe.
%
% Revision 1.2  1997/08/24 16:18:39  sturm
% Added service rl_surep with black box rl_multsurep.
% Added service rl_siaddatl.
%
% Revision 1.1  1997/08/22 17:30:37  sturm
% Created an acfsf context based on ofsf.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(acfsf_rcsid!* acfsf_copyright!*);
   acfsf_rcsid!* := "$Id: acfsf.red,v 1.9 1999/04/12 09:25:48 sturm Exp $";
   acfsf_copyright!* := "Copyright (c) 1995-1999 A. Dolzmann and T. Sturm"
>>;

module acfsf;
% Algebraically closed field standard form. Main module. Algorithms on
% first-order formulas over algebraically closed fields. The language
% contains binary relations ['equal], ['neq].

create!-package(
   '(acfsf acfsfsiat acfsfsism acfsfbnf acfsfgs acfsfmisc acfsfqe),nil);

load!-package 'rltools;
load!-package 'cl;
load!-package 'cgb;

exports acfsf_simpterm,acfsf_prepat,acfsf_resimpat,acfsf_lengthat,
   acfsf_chsimpat,acfsf_simpat,acfsf_op,acfsf_arg2l,acfsf_arg2r,acfsf_argn,
   acfsf_mk2,acfsf_0mk2,acfsf_mkn,acfsf_opp,acfsf_simplat1,acfsf_smrmknowl,
   acfsf_smcpknowl,acfsf_smupdknowl,acfsf_smmkatl,acfsf_dnf,acfsf_cnf,
   acfsf_subsumption,acfsf_sacatlp,acfsf_sacat,acfsf_gsc,acfsf_gsd,acfsf_gsn,
   acfsf_gssimplify,acfsf_gssimplify0,acfsf_termprint,acfsf_clnegrel,
   acfsf_lnegrel,acfsf_fctrat,acfsf_negateat,
   acfsf_varlat,acfsf_varsubstat,acfsf_ordatp,acfsf_a2cdl,acfsf_t2cdl,
   acfsf_subat,acfsf_subalchk,acfsf_eqnrhskernels,acfsf_getineq,acfsf_structat,
   acfsf_ifstructat,acfsf_termmlat,acfsf_decdeg,acfsf_decdeg1,acfsf_multsurep,
   acfsf_gqe,acfsf_qe,acfsf_thsimpl;

imports rltools,cl,cgb;

fluid '(!*rlsiatadv !*rlsiexpl !*rlsiexpla !*rlgssub !*rlsiso !*rlgsrad
   !*rlgsred !*rlgsprod !*rlgserf !*rlverbose !*rlsifac !*rlbnfsac !*rlgsvb
   !*rlgsbnf !*rlgsutord !*rlnzden !*rladdcond !*rlqegen !*cgbgen !*cgbreal
   !*gbverbose);

flag('(acfsf),'rl_package);

% Parameters
put('acfsf,'rl_params,'(
   (rl_subat!* . acfsf_subat)
   (rl_subalchk!* . acfsf_subalchk)
   (rl_eqnrhskernels!* . acfsf_eqnrhskernels)
   (rl_ordatp!* . acfsf_ordatp)
   (rl_simplat1!* . acfsf_simplat1)
   (rl_smupdknowl!* . acfsf_smupdknowl)
   (rl_smrmknowl!* . acfsf_smrmknowl)
   (rl_smcpknowl!* . acfsf_smcpknowl)
   (rl_smmkatl!* . acfsf_smmkatl)
   (rl_smsimpl!-impl!* . cl_smsimpl!-impl)
   (rl_smsimpl!-equiv1!* . cl_smsimpl!-equiv1)
   (rl_negateat!* . acfsf_negateat)
   (rl_varlat!* . acfsf_varlat)
   (rl_varsubstat!* . acfsf_varsubstat)
   (rl_subsumption!* . acfsf_subsumption)
   (rl_bnfsimpl!* . cl_bnfsimpl)
   (rl_sacat!* . acfsf_sacat)
   (rl_sacatlp!* . acfsf_sacatlp)
   (rl_fctrat!* . acfsf_fctrat)
   (rl_tordp!* . ordp)
   (rl_a2cdl!* . acfsf_a2cdl)
   (rl_t2cdl!* . acfsf_t2cdl)
   (rl_getineq!* . acfsf_getineq)
   (rl_structat!* . acfsf_structat)
   (rl_ifstructat!* . acfsf_ifstructat)
   (rl_termmlat!* . acfsf_termmlat)
   (rl_multsurep!* . acfsf_multsurep)));

% Services
put('acfsf,'rl_services,'(
   (rl_subfof!* . cl_subfof)
   (rl_identifyonoff!* . cl_identifyonoff)
   (rl_simpl!* . cl_simpl)
   (rl_thsimpl!* . acfsf_thsimpl)
   (rl_nnf!* . cl_nnf)
   (rl_nnfnot!* . cl_nnfnot)
   (rl_pnf!* . cl_pnf)
   (rl_cnf!* . acfsf_cnf)
   (rl_dnf!* . acfsf_dnf)
   (rl_all!* . cl_all)
   (rl_ex!* . cl_ex)
   (rl_atnum!* . cl_atnum)
   (rl_tab!* . cl_tab)
   (rl_atab!* . cl_atab)
   (rl_itab!* . cl_itab)
   (rl_gsc!* . acfsf_gsc)
   (rl_gsd!* . acfsf_gsd)
   (rl_gsn!* . acfsf_gsn)
   (rl_ifacl!* . cl_ifacl)
   (rl_ifacml!* . cl_ifacml)
   (rl_matrix!* . cl_matrix)
   (rl_apnf!* . cl_apnf)
   (rl_atml!* . cl_atml)
   (rl_tnf!* . cl_tnf)
   (rl_atl!* . cl_atl)
   (rl_struct!* . cl_struct)
   (rl_ifstruct!* . cl_ifstruct)
   (rl_termml!* . cl_termml)
   (rl_terml!* . cl_terml)
   (rl_varl!* . cl_varl)
   (rl_fvarl!* . cl_fvarl)
   (rl_bvarl!* . cl_bvarl)
   (rl_gentheo!* . cl_gentheo)
   (rl_decdeg!* . acfsf_decdeg)
   (rl_decdeg1!* . acfsf_decdeg1)
   (rl_surep!* . cl_surep)
   (rl_qe!* . acfsf_qe)
   (rl_qeipo!* . cl_qeipo)
   (rl_siaddatl!* . cl_siaddatl)));

% Admin
put('acfsf,'simpfnname,'acfsf_simpfn);
put('acfsf,'simpdefault,'acfsf_simprel);

put('acfsf,'rl_prepat,'acfsf_prepat);
put('acfsf,'rl_resimpat,'acfsf_resimpat);
put('acfsf,'rl_lengthat,'acfsf_lengthat);

put('acfsf,'rl_prepterm,'prepf);
put('acfsf,'rl_simpterm,'acfsf_simpterm);

algebraic infix equal;
put('equal,'acfsf_simpfn,'acfsf_chsimpat);
put('equal,'number!-of!-args,2);

algebraic infix neq;
put('neq,'acfsf_simpfn,'acfsf_chsimpat);
put('neq,'number!-of!-args,2);
put('neq,'rtypefn,'quotelog);
newtok '((!< !>) neq);

flag('(equal neq),'spaced);
flag('(acfsf_chsimpat),'full);

procedure acfsf_simpterm(u);
   % Algebraically closed field simp term. [u] is Lisp Prefix. Returns
   % the [u] as an ACFSF term.
   numr simp u;

procedure acfsf_prepat(f);
   % Algebraically closed field prep atomic formula. [f] is an ACFSF
   % atomic formula. Returns [f] in Lisp prefix form.
   {acfsf_op f,prepf acfsf_arg2l f,prepf acfsf_arg2r f};

procedure acfsf_resimpat(f);
   % Algebraically closed field resimp atomic formula. [f] is an ACFSF
   % atomic formula. Returns the atomic formula [f] with resimplified
   % terms.
   acfsf_mk2(acfsf_op f,
      numr resimp !*f2q acfsf_arg2l f,numr resimp !*f2q acfsf_arg2r f);

procedure acfsf_lengthat(f);
   % Algebraically closed field length of atomic formula. [f] is an
   % atomic formula. Returns a number, the length of [f].
   2;

procedure acfsf_chsimpat(u);
   % Algebraically closed field chain simp atomic formula. [u] is the
   % Lisp prefix representation of a chain of atomic formulas, i.e.,
   % the operators are nested right associatively. Returns a formula,
   % which is the corresponding conjunction.
   rl_smkn('and,for each x in acfsf_chsimpat1 u collect acfsf_simpat x);

procedure acfsf_chsimpat1(u);
   % Algebraically closed field chain simp atomic formula. [u] is the
   % Lisp prefix representation of a chain of atomic formulas, i.e.,
   % the operators are nested right associatively.
   begin scalar leftl,rightl,lhs,rhs;
      lhs := cadr u;
      if pairp lhs and acfsf_opp car lhs then <<
	 leftl := acfsf_chsimpat1 lhs;
	 lhs := caddr lastcar leftl
      >>;
      rhs := caddr u;
      if pairp rhs and acfsf_opp car rhs then <<
	 rightl := acfsf_chsimpat1 rhs;
	 rhs := cadr car rightl
      >>;
      return nconc(leftl,{car u,lhs,rhs} . rightl)
   end;

procedure acfsf_simpat(u);
   % Algebraically closed field simp atomic formula. [u] is Lisp
   % prefix. Returns [u] as an atomic formula.
   begin scalar op,lhs,rhs,nlhs,f;
      op := car u;
      lhs := simp cadr u;
      if not (!*rlnzden or (domainp denr lhs)) then
 	 typerr(u,"atomic formula");
      rhs := simp caddr u;
      if not (!*rlnzden or (domainp denr rhs)) then
 	 typerr(u,"atomic formula");
      lhs := subtrsq(lhs,rhs);
      nlhs := numr lhs;
      if !*rlnzden and not domainp denr lhs then <<
	 f := acfsf_0mk2(op,nlhs);
	 if !*rladdcond then
	    f := rl_mkn('and,{acfsf_0mk2('neq,denr lhs),f});
	 return f
      >>;
      return acfsf_0mk2(op,nlhs)
   end;

procedure acfsf_op(atf);
   % Algebraically closed field operator. [atf] is an atomic formula
   % $R(t_1,t_2)$. Returns $R$.
   car atf;

procedure acfsf_arg2l(atf);
   % Algebraically closed field binary operator left hand side
   % argument. [atf] is an atomic formula $R(t_1,t_2)$. Returns $t_1$.
   cadr atf;

procedure acfsf_arg2r(atf);
   % Algebraically closed field binary operator right hand side
   % argument. [atf] is an atomic formula $R(t_1,t_2)$. Returns $t_2$.
   caddr atf;

procedure acfsf_argn(atf);
   % Algebraically closed field n-ary operator argument list. [atf] is
   % an atomic formula $R(t_1,t_2)$. Returns the list $(t_1,t_2)$.
   {cadr atf,caddr atf};

procedure acfsf_mk2(op,lhs,rhs);
   % Algebraically closed field make atomic formula for binary
   % operator. [op] is a relation; [lhs] and [rhs] are terms. Returns
   % the atomic formula $[op]([lhs],[rhs])$.
   {op,lhs,rhs};

procedure acfsf_0mk2(op,lhs);
   % Algebraically closed field make zero right hand side atomic
   % formula for binary operator. [op] is a relation [lhs] is a term.
   % Returns the atomic formula $[op]([lhs],0)$.
   {op,lhs,nil};

procedure acfsf_mkn(op,argl);
   % Algebraically closed field make atomic formula for n-ary
   % operator. [op] is a relation; [argl] is a list $(t_1,t_2)$ of
   % terms. Returns the atomic formula $[op](t_1,t_2)$.
   {op,car argl,cadr argl};

procedure acfsf_opp(op);
   % Algebraically closed field operator predicate. [op] is an
   % S-expression. Returns non-[nil] iff op is a relation.
   op memq '(equal neq);

endmodule;  % [acfsf]

end;  % of file
