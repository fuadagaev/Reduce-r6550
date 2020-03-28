% Dispersionless Boussinesq equation: three local Hamiltonian operators
% 2016-01-12
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u,v,w}$
odd_var:={p,q,r,o1,o2,o3}$
deg_indep_var:={-1,-2}$
deg_dep_var:={3,4,2}$
deg_odd_var:={2,3,1,1,2,3}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="bou_sympl1_state.red"$
resname:="bou_sympl1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t,v_t,w_t}$
% right-hand side of the differential equation
de:={w*w_x + v_x, - u*w_x - 3w*u_x,u_x}$

% same constructions for odd coordinates;
principal_odd:={p_t,q_t,r_t,
  o1_t,o1_x,
  o2_t,o2_x,
  o3_t,o3_x}$
de_odd:={q_x + r*w_x + r_x*w, - (p*w_x + 3*p_x*w + 3*r*u_x + r_x*u),p_x,
  p,r,
  q+r*w,p,
  - w*p - u*r,q + 2*w*r}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;
nc:=length(dep_var);

% List of variables ordered by gradings
l_grad_mon:=der_deg_ordering(0,all_parametric_der)$
l_grad_odd:={1} . der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
gradmon:=graded_mon(1,10,l_grad_mon)$
gradmon:={1} . gradmon$
% list of graded monomials which are linear in odd variables
% and have total degree from 1 to 8
linodd:=mkalllinodd(gradmon,l_grad_odd,1,8)$
% Ansatz for local symplectic operators
operator phi;
for i:=1:nc do phi(i):=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% equation for shadows of nonlocal symmetries in \ell^*-covering
mk_superfun(lbou_star_sf,1,3);
lbou_star_sf(1):= - p_t - 2*q*w_x - 3*q_x*w + r_x$
lbou_star_sf(2):=p_x - q_t$
lbou_star_sf(3):=p_x*w + 2*q*u_x - q_x*u - r_t$
conv_superfun2cdiff(lbou_star_sf,lbou_star);

for i:=1:nc do
equ(i):=for j:=1:nc sum lbou_star(i,j,phi(j));

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=3;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,3);

tel2:=splitvars_opequ(equ,4,tel,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i;

off nat$
off echo$
out <<resname>>;
write "operator phi;";
phi(1):=phi(1);
phi(2):=phi(2);
phi(3):=phi(3);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: