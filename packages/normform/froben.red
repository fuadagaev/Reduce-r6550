module froben; % Computation of the frobenius normal form of a matrix.                                                              %

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

% $Id$

% The function frobenius computes the Frobenius normal form F of a
% matrix A, the transformation matrix P and its inverse P^(-1).
%
% Specifically:
%
% - frobenius(A) will return {F,P,Pinv} where F, P, and Pinv
%   are such that P*F*Pinv=A.

% Global description of the algorithm:
%
% For a given n by n matrix A over a field K, let L be the linear
% transformation of K^n induced by A. A polycyclic basis of K^n with
% respect to L is a basis of the following form:
% v1,L*v1,.,L^(d1-1)*v1,v2,L*v2,.,L^(d2-1)*v2,.,vr,L*vr,., L^(dr-1)*vr
% such that v1,L*v1,..,L^(d1-1)*v1,..,vi,L*vi,..,L^(di-1)*vi,L^di*vi
% are linearly dependent for i=1..r.
% It is easy to see that the matrix B of L with respect to a polycyclic
% basis is of the form plist_to_polycompanion(plist,x), where plist is
% a list of monic elements of K[x] of strictly increasing degree (for
% a description of plist_to_polycompanion see below).
% The computation of a polycyclic basis of K^n and the transformation
% matrix from A to B is performed in the function cyclic_vectors.
% Next we view K^n as a K[x]-module via x*v=B*v. Suppose that
% B=plist_to_polycompanion(plist,x), where plist=[p1,..,pr] and
% degree(pi)=di. Let G be the r by r upper triangular matrix such that
% G(i,j) satisfies:
%  pj=G(1,j)+G(2,j)*x^d1+G(3,j)*x^d2+..+G(j,j)*x^d(j-1),
% where degree(G(j,j))=dj-d(j-1) and degree(G(i,j))<di-d(i-1) (d0=0).
% Let R be the K[x]-submodule of K[x]^r generated by the columns of G.
% Representants for the elements of the quotient module K[x]^r/R are
% the vectors [L1,L2,..,Lr] where degree(Li)<di-d(i-1). By taking the
% coefficients of the Li the quotient module is identified with K^n.
% The multiplication by x on the quotient module is identified with
% the multiplication by B on K^n.
% Next we compute the Smith normal form S of G. Say L*S*R=G. If R' is
% the K[x]-submodule of K[x]^r generated by the columns of S we get
% the following diagram:
%
%            ~                 ~                 ~
%    K^n <------- K[x]^r/R' -------> K[x]^r/R -------> K^n
%                              L
%     |               |                  |              |
%     |               |                  |              |
%     |F              |x                 |x             |B
%     |               |                  |              |
%     |               |                  |              |
%    \ /             \ /                \ /            \ /
%            ~                 ~                 ~
%    K^n <------- K[x]^r/R' -------> K[x]^r/R -------> K^n
%                              L
%
% Here F is in Frobenius normal form and thus it is the Frobenius
% normal form of B (and thus of A). The computation of the Smith
% normal form of G is performed in the function cyclic_to_frobenius.


symbolic procedure frobenius(a);
  begin
    scalar aa,p,pinv,ans,tmp,full_coeff_list,rule_list,input_mode;

    matrix_input_test(a);
    if (car size_of_matrix(a)) neq (cadr size_of_matrix(a))
     then rederr "ERROR: expecting a square matrix. ";

    input_mode := get(dmode!*,'dname);
    %
    % If modular or arnum are on then we keep them on else we want
    % rational on.
    %
    if input_mode neq 'modular and input_mode neq 'arnum and
     input_mode neq 'rational then on rational;
    on combineexpt;

    tmp := nest_input(a);
    aa := car tmp;
    full_coeff_list := cadr tmp;

    tmp := frobeniusform(aa);
    ans := car tmp;
    p := cadr tmp;
    pinv := caddr tmp;
    %
    %  Set up rule list for removing nests.
    %
    rule_list := {'co,2,{'~,'int}}=>'int when numberp(int);
    for each elt in full_coeff_list do
    <<
      tmp := {'co,2,{'~,elt}}=>elt;
      rule_list := append (tmp,rule_list);
    >>;
    %
    %  Remove nests.
    %
    let rule_list;
    ans := de_nest_mat(ans);
    p := de_nest_mat(p);
    pinv := de_nest_mat(pinv);
    clearrules rule_list;
    %
    % Return to original mode.
    %
    if input_mode neq 'modular and input_mode neq 'arnum and
     input_mode neq 'rational then
       <<
         % onoff('nil,t) doesn't work so ...
         if input_mode = 'nil then off rational
         else onoff(input_mode,t);
       >>;
    off combineexpt;

    return {'list,ans,p,pinv};
  end;

flag ('(frobenius),'opfn);  %  So it can be used from algebraic mode.



symbolic procedure frobeniusform(a);
  begin
    scalar ans,plist,tmp,p,pinv,inv_fact,t1,tinv,v,vinv,x;

    x := mkid('x,0);

    tmp := cyclic_vectors(a,x);
    plist := car tmp;
    v := cadr tmp;
    vinv := caddr tmp;

    tmp := cyclic_to_frobenius(plist,x);
    inv_fact := car tmp;
    t1 := cadr tmp;
    tinv := caddr tmp;

    p:= reval {'times,v,t1};
    pinv:= reval {'times,tinv,vinv};

    ans := invfact_to_frobenius(inv_fact,x);

    return {ans,p,pinv};
  end;




symbolic procedure basis(n,i);
  %
  % Basis creates an element of the natural basis of a vector space.
  %
  begin
    scalar vv;
    vv := mkmatrix(1,n);
    setmat(vv,1,i,1);
    return vv;
  end;




symbolic procedure calc_exgcd(poly1,poly2,x);
  %
  % Extended Euclidean algorithm for polynomials.
  % poly1, and poly2 are polynomials in x.
  % Returns gcd, s1, and t1 such that s1 * poly1 + t1 * poly2 = gcd,
  % with degree(s1,x)<degree(poly2,x) and degree(t1,x)<degree(poly1,x).
  %
  begin
    scalar gcd,c,c1,c2,d,d1,d2,q,r,r1,r2,s1,t1;

    if poly1 = 0 and poly2 = 0 then return {0,0,0} else
    <<

      poly1 := reval poly1;
      poly2 := reval poly2;

      c := reval norm(poly1,x);
      d := reval norm(poly2,x);

      c1 := 1;
      d1 := 0;
      c2 := 0;
      d2 := 1;

      while reval d neq 0 do
      <<
        q  := reval get_quo(c,d);
        r  := reval {'plus,c,{'minus,{'times,q,d}}};
        r1 := reval {'plus,c1,{'minus,{'times,q,d1}}};
        r2 := reval {'plus,c2,{'minus,{'times,q,d2}}};
        c  := reval d;
        c1 := reval d1;
        c2 := reval d2;
        d  := reval r;
        d1 := reval r1;
        d2 := reval r2;
      >>;

      gcd := reval norm(c,x);
      s1  := reval{'quotient,c1,{'times,normform_unit(poly1,x),normform_unit(c,x)}};
      t1  := reval{'quotient,c2,{'times,normform_unit(poly2,x),normform_unit(c,x)}};

    return {gcd,s1,t1};
    >>;
  end;



symbolic procedure norm(poly,x);
  begin
    scalar normal;
    if poly = 0 then normal := 0
    else if lcof(poly,x) = 0 then normal := 1
    else normal := reval{'quotient,poly,lcof(poly,x)};
    return normal;
  end;



symbolic procedure normform_unit(poly,x);
  begin
    scalar unit1;
    if poly = 0 then unit1 := 1
    else if lcof(poly,x) = 0 then unit1 := poly
    else unit1 := reval lcof(poly,x);
    return unit1;
  end;




symbolic procedure companion(poly,x);
  %
  % Takes as input a monic univariate polynomial in a variable x.
  % Returns a companion matrix associated with the polynomial poly(x).
  % If C := companion(p,x) and p is a0+a1*x+...+x^n (a univariate monic
  % polynomial), them C(i,n) = -coeff(p,x,i-1), C(i,i-1) = 1 (i=2..n)
  % and C(i,j) = 0 for all other i and j.
  %
  % Can be used independently from algebraic mode.
  %
   begin
    scalar mat1;
    integer n;

    n := deg(poly,x);

    if de_nest(reval coeffn(poly,x,n)) neq 1
     then rederr {"ERROR: polynomial",poly," is not monic."};

    mat1 := mkmatrix(n,n);
    setmat(mat1,1,n,{'minus,coeffn(poly,x,0)});

    for i:=2:n do
    <<
      setmat(mat1,i,i-1,1);
    >>;

    for j:=2:n do
    <<
      setmat(mat1,j,n,{'minus,coeffn(poly,x,j-1)});
    >>;

    return mat1;
  end;

flag('(companion),'opfn);  %  So it can be used independently from
                           %  algebraic mode.



symbolic procedure compute_g(r,dd,plist,x);
  begin
    scalar g,tmp,new_elt;

    g := mkmatrix(r,r);

    for j:=1:r do
    <<
      for i:=1:j-1 do
      <<
        new_elt := 0;
        for k:=getmat(dd,1,i):getmat(dd,1,i+1)-1 do
        <<
          tmp := {'times,coeffn(nth(plist,j),x,k),{'expt,x,{'plus,k,
                  {'minus,getmat(dd,1,i)}}}};
          new_elt := {'plus,new_elt,tmp};
        >>;
        setmat(g,i,j,new_elt);
      >>;

      new_elt := 0;
      for k:=getmat(dd,1,j):getmat(dd,1,j+1) do
      <<
        tmp := {'times,coeffn(nth(plist,j),x,k),{'expt,x,{'plus,k,
                {'minus,getmat(dd,1,j)}}}};
        new_elt := {'plus,new_elt,tmp};
      >>;

      setmat(g,j,j,new_elt);

    >>;

    return g;
  end;




symbolic procedure copy_mat(a);
  %
  % Creates a copy of the input and returns it;
  %
  begin
    scalar c;
    integer row_dim,col_dim;

    matrix_input_test(a);

    row_dim := car size_of_matrix(a);
    col_dim := cadr size_of_matrix(a);

    c := mkmatrix(row_dim,col_dim);

    for i:=1:row_dim do
    <<
      for j:=1:col_dim do
      <<
        setmat(c,i,j,getmat(a,i,j));
      >>;
    >>;

    return c;
  end;




symbolic procedure cyclic_to_frobenius(plist,x);
  %
  % A matrix B=plist_to_polycompanion(plist,x) is transformed to its
  % Frobenius normal form F.
  % If F=diag(C1,..,Cr) where Ci is the companion matrix associated with
  % pi, then cyclic_to_frobenius will return {p1,..,pr}.
  % Let G be the matrix as described before. We compute the Smith normal
  % form S of G. Then S=diag(p1,..,pr), where pi in K[x] such that pi
  % pi divides p(i+1) for i=1..(r-1), and
  % F=invfact_to_frobenius({p1,..,pr},x) is the frobenius normal form of
  % B (for description of invfact_to_frobenius see invfact_to_frobenius)
  % .
  % Remark: to compute the smith normal form of G we car simplify G
  % using the fact that G is upper triangular. Then we use a modified
  % version of smithex.
  begin
    scalar dd,d,us,s,g,c,t1,tinv,inv_fact,l,linv,columnt,rowt,rr,q,
           columntinv,rowtinv,tmp,tmp1;
    integer r,n;

    r := length plist;

    dd := mkmatrix(1,r+1);
    for j:=1:r do
    <<
      setmat(dd,1,j+1,deg(nth(plist,j),x));
    >>;

    n:= getmat(dd,1,r+1);

    %%%%%%%%%%%%%%%%%%%
    % Compute matrix G.
    %%%%%%%%%%%%%%%%%%%
    g:=compute_g(r,dd,plist,x);
    %%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%
    % Compute smith normal form of G.
    %%%%%%%%%%%%%%%%%%%
    tmp := uppersmith(g,x);
    us:=car tmp;
    l := cadr tmp;
    linv := caddr tmp;

    tmp:=mysmith(us,l,linv,x);
    s:=car tmp;
    l := cadr tmp;
    linv := caddr tmp;
    %%%%%%%%%%%%%%%%%%%

    d := mkmatrix(1,r);
    for i:=1:r do
    <<
      setmat(d,1,i,deg(getmat(s,i,i),x));
    >>;

    %%%%%%%%%%%%%%%%%%%
    % Compute transformation matrix.
    %%%%%%%%%%%%%%%%%%%
    c := mkmatrix(1,r);
    t1 := mkmatrix(n,n);
    columnt:=0;

    for i:=1:r do
    <<
      for k:=1:r do
      <<
        setmat(c,1,k,getmat(l,k,i));
      >>;
      for j:=1:getmat(d,1,i) do
      <<
        columnt:=columnt+1;
        for ii:=r step -1 until 1 do
        <<
          q:=get_quo(getmat(c,1,ii),getmat(g,ii,ii));
          rr:=get_rem(getmat(c,1,ii),getmat(g,ii,ii));
          setmat(c,1,ii,rr);
          for jj:=1:(ii-1) do
          <<
            setmat(c,1,jj,reval {'plus,reval getmat(c,1,jj),{'times,
                   {'minus,q},reval getmat(g,jj,ii)}});
          >>;
        >>;
        rowt:=0;
        for ii:=1:r do
        <<
          tmp := reval{'plus,getmat(dd,1,ii+1),{'minus,
                       getmat(dd,1,ii)}};
          for jj:=1:tmp do
          <<
            rowt:=rowt+1;
            tmp1 := coeffn(getmat(c,1,ii),x,jj-1);
            setmat(t1,rowt,columnt,tmp1);
          >>;
        >>;
        for ii:=1:r do setmat(c,1,ii,{'times,getmat(c,1,ii),x});
      >>;
    >>;
    %%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%
    % Compute inverse transformation matrix
    %%%%%%%%%%%%%%%%%%%
    <<
      tinv := mkmatrix(n,n);
      columntinv:=0;

      for i:=1:r do
      <<
        for k:=1:r do setmat(c,1,k,getmat(linv,k,i));
        for j:=1:reval {'plus,getmat(dd,1,i+1),{'minus,
                        getmat(dd,1,i)}} do
        <<
          columntinv:=columntinv+1;
          rowtinv:=0;
          for ii:=1:r do
          <<
            setmat(c,1,ii,get_rem(getmat(c,1,ii),getmat(s,ii,ii)));
            for jj:=1:reval getmat(d,1,ii) do
            <<
              rowtinv:=rowtinv+1;
              setmat(tinv,rowtinv,columntinv,reval
                     coeffn(getmat(c,1,ii),x,jj-1));
            >>;
          >>;
          for ii:=1:r do setmat(c,1,ii,{'times,getmat(c,1,ii),x});
        >>;
      >>;

    >>;
    %%%%%%%%%%%%%%%%%%%

    inv_fact := {};

    for i:=1:r do
    <<
      if getmat(d,1,i)>0 then
      <<
        inv_fact := append(inv_fact,{getmat(s,i,i)});
      >>;
    >>;

    return {inv_fact,t1,tinv};
  end;




symbolic procedure cyclic_vectors(a,x);
  %
  % cyclic_vectors computes a polycyclic basis of K^n with respect to A.
  % If this basis is (b1,..,bn)=
  % (v1,A*v1,..,A^(d1-1)*v1,v2,A*v2,.,A*(d2-1)*v2,..,vr,A*vr,..,A^(dr-1)
  % *vr)  and a1*b1+..+a(d1+..+di)*b(d1+..+di)+A^di*vi=0 we set
  % pi=a1+a2*x+..+a(d1+..+di)*x^(d1+..+di-1)+x^(d1+..di).
  % cyclic_vectors returns {p1,..,pr}.
  % The matrix of A on this basis (b1,..,bn) is
  % plist_to_polycompanion([p1,..,pr],x).
  %
  begin
    scalar v,vinv,plist,u,uinv,s,carrier,lincomb,vv,uu,ss,l,car,c,
           tmp,ans,q,break;
    integer n,r;

    n := car size_of_matrix(a);

    u := mkmatrix(n,n);
    s := mkmatrix(n,n);
    plist := {};
    v := mkmatrix(n,n);
    vinv := mkmatrix(n,n);
    carrier := mkvect(n);
    lincomb := mkvect(n);

    r := 0;  %  No. of elements already computed.

    while r<n do
    <<

      %%%%%%%%%%%%%%%%%%%
      % Start new cycle.
      %%%%%%%%%%%%%%%%%%%
      q := 1;
      while getv(carrier,q) neq nil do q:=q+1;  %  Find car gap.
      vv := basis(n,q);
      %%%%%%%%%%%%%%%%%%%

      break := nil; %  Controls break out of loop.
      while not break do
      <<
        uu := copy_mat(vv);
        for i:=1:n do putv(lincomb,i,0);

        %  Always VV=UU+U*lincomb.
        for i:=1:n do
        <<
          car:= getv(carrier,i);

          if car neq nil and getmat(uu,1,i) neq 0 then
          <<
            c := {'quotient,getmat(uu,1,i),getmat(u,i,car)};
            setmat(uu,1,i,0);

            for j:=i+1:n do
            <<
              tmp := {'times,c,getmat(u,j,car)};
              setmat(uu,1,j,reval {'plus,getmat(uu,1,j),{'minus,{'times,
                     c,getmat(u,j,car)}}});
            >>;

            putv(lincomb,car,c);
          >>;

        >>;

        q := 1;
        while q<=n and reval getmat(uu,1,q)=0 do
        <<
          q:=q+1;
        >>;

        if q<=n then
        <<

          %  New element of basis.
          r:=r+1;
          putv(carrier,q,r); % This basis-element carries coordinates q.

          %  Always U=V*S.
          for j:=q:n do setmat(u,j,r,getmat(uu,1,j));
          for j:=1:n do setmat(v,j,r,getmat(vv,1,j));

          for j:=1:r-1 do
          <<
            tmp:=getv(lincomb,j);
            for l:=j+1:r-1 do tmp:={'plus,tmp,{'times,getmat(s,j,l),
                                    getv(lincomb,l)}};
            setmat(s,j,r,{'minus,tmp});
          >>;
          setmat(s,r,r,1);

          %  Compute A*VV.
          for i:=1:n do
          <<
            tmp:=0;
            for j:=1:n do
            <<
             tmp:=reval{'plus,tmp,reval{'times,reval getmat(a,i,j),
                        reval getmat(vv,1,j)}};
            >>;
            setmat(uu,1,i,tmp);
          >>;

          for i:=1: cadr size_of_matrix(uu) do
          <<
            setmat(vv,1,i,getmat(uu,1,i));
          >>;

        >>
        else
        <<
          break := t;
        >>;

      >>;

      %%%%%%%%%%%%%%%%%%%
      % New cycle found
      %%%%%%%%%%%%%%%%%%%
      ss := mkmatrix(1,r);

      for j:=1:r do
      <<
        tmp:=reval getv(lincomb,j);

        for l:=j+1:r do
        <<
          tmp:=reval{'plus,tmp,{'times,reval getmat(s,j,l),
                     reval getv(lincomb,l)}};
        >>;

        setmat(ss,1,j,tmp);
      >>;

      ans := nil;
      for j:=1:r do
      <<
        tmp := {'times,getmat(ss,1,r+1-j),{'expt,x,r-j}};
        ans := reval{'plus,ans,tmp};
      >>;

      tmp := reval{'plus,{'expt,x,r},{'minus,ans}};
      plist := append(plist,{tmp});
      %%%%%%%%%%%%%%%%%%%

    >>; %  End while r<n.

    uinv := inv(u,carrier);

    for i:=1:n do
    <<
      for j:=1:n do
      <<
        tmp:=0;
        for l:=i:n do
        <<
          tmp:=reval {'plus,tmp,{'times,reval getmat(s,i,l),
                      reval getmat(uinv,l,j)}};
         >>;
        setmat(vinv,i,j,tmp);
      >>;
    >>;

    return {plist,v,vinv};
  end;




symbolic procedure de_nest(input);
  %
  % Takes simple nested input and de-nests it.
  %
  begin
    scalar output;
    if atom input then output := input
    else if car input neq 'co then output := input
    else output := caddr input;
    return output;
  end;




symbolic procedure de_nest_mat(mat1);
  %
  % Removes nests from each elt of input matrix.
  % Rules being applied from outside.
  %
  begin
    integer row_dim,col_dim;

    row_dim := car size_of_matrix(mat1);
    col_dim := cadr size_of_matrix(mat1);

    for i:=1:row_dim do
    <<
      for j:=1:col_dim do
      <<
        setmat(mat1,i,j,getmat(mat1,i,j));
      >>;
    >>;

    return mat1;
  end;




%  Allow variable input.
put('diagi,'psopfn,'diag);
symbolic procedure diag(uu);
  %
  % Takes square or scalar matrix entries and creates a matrix with
  % these matrices on the diagonal.
  %
  begin
    scalar bigA,arg,input,u;
    integer nargs,n,aidx,stp,bigsize,smallsize;

    u := car uu;
    input := u;
    bigsize:=0;

    nargs:=length input;
    for i:=1:nargs do
    <<
      arg:=car input;
      % If scalar entry.
      if algebraic length(arg) = 1 then bigsize:=bigsize+1
      else
      <<
        bigsize:=bigsize+car size_of_matrix(arg);
      >>;
      input := cdr input;
    >>;

    bigA := mkmatrix(bigsize,bigsize);
    aidx:=1;
    input := u;
    for k:=1:nargs do
    <<
      arg:=car input;
      % If scalar entry.
      if algebraic length(arg) = 1 then
      <<
        setmat(bigA,aidx,aidx,arg);
        aidx:=aidx+1;
        input := cdr input;
      >>
      else
      <<
        smallsize:= car size_of_matrix(arg);
        stp:=smallsize+aidx-1;
        for i:=aidx:stp do
        <<
          for j:=aidx:stp do
          <<
            arg:=car input;
            % Find (i-Aidx+1)'th row.
            arg := cdr arg;
            <<
              n:=1;
              while n < (i-aidx+1) do
              <<
                arg := cdr arg;
                n:=n+1;
              >>;
            >>;
            arg := car arg;
            %
            %  Find (j-Aidx+1)'th column elt of i'th row.
            %
            <<
              n:=1;
              while n < (j-aidx+1) do
              <<
                arg := cdr arg;
                n:=n+1;
              >>;
            >>;
            arg := car arg;

            setmat(bigA,i,j,arg);
          >>;
        >>;
        aidx := aidx+smallsize;
        input := cdr input;
      >>;
    >>;

    return bigA;
  end;





symbolic procedure get_coeffs(poly);
  %
  % Gets all kernels in a poly.
  %
  begin
    scalar ker_list_num,ker_list_den;

    ker_list_num := kernels !*q2f simp reval num poly;
    ker_list_den := kernels !*q2f simp reval den poly;

    ker_list_num := union(ker_list_num,ker_list_den);

    return ker_list_num;
  end;




symbolic procedure get_quo(poly1,poly2);
  %
  % Gets quotient of two polys.
  %
  begin
    scalar quo1,input1,input2;

    if input1 = 0 and input2 = 0 then return 0
    else
    <<
      input1 := reval poly1;
      input2 := reval poly2;
      algebraic (quo1 := (input1-remainder(input1,input2))/input2);
      quo1 := reval quo1;
      return quo1;
    >>;
  end;




symbolic procedure get_rem(poly1,poly2);
  %
  % Gets remainder of two polys.
  %
  begin
    scalar rem1,input1,input2;

    input1 := reval poly1;
    input2 := reval poly2;

    algebraic (rem1 := remainder(input1,input2));
    rem1 := reval rem1;

    return rem1;
  end;




symbolic procedure inv(u,carrier);
  %
  % inv computes the inverse of a permuted upper triangular matrix. The
  % permutation is given by carrier.
  %
  begin
    scalar uinv,tmp;
    integer n;

    n:= car size_of_matrix(u);
    uinv := mkmatrix(n,n);

    for i:=1:n do
    <<

      for j:=1:i-1 do
      <<
        tmp:=0;

        for k:=j:i-1 do
        <<
          tmp := {'plus,tmp,{'times,getmat(u,i,getv(carrier,k)),
                  getmat(uinv,getv(carrier,k),j)}};
        >>;

        setmat(uinv,getv(carrier,i),j,{'quotient,{'minus,tmp},
               getmat(u,i,getv(carrier,i))});
      >>;

      setmat(uinv,getv(carrier,i),i,{'quotient,1,getmat(u,i,
             getv(carrier,i))});
      for j:=i+1:n do setmat(uinv,getv(carrier,i),j,0);
    >>;

    return uinv;
  end;




symbolic procedure invfact_to_frobenius(inv_fact,x);
  %
  % For plist={p1,..,pr] where pi is a monic polynomial in x,
  % invfact_to_frobenius(plist,x) makes a square matrix with diagonal
  % blocks C1,..,Cr where Ci is the companion matrix to pi.
  %
  begin
    scalar diag_mat,tmp;
    integer num;
    num := length inv_fact;
    tmp:=for i:=1:num collect companion(nth(inv_fact,i),x);
    diag_mat := reval{'diagi, tmp};
    return diag_mat;
  end;




symbolic procedure make_identity(row_dim,col_dim);
  %
  % Creates identity matrix.
  %
  begin
    scalar a;
    a := mkmatrix(row_dim,col_dim);
    for i:=1:row_dim do
    <<
      for j:=1:col_dim do
      <<
        if i=j then setmat(a,i,i,1);
      >>
    >>;
    return a;
  end;





symbolic procedure matrix_input_test(a);
  begin
    if not eqcar(a,'mat) then rederr
     {"ERROR: `",a,"' is non matrix input."}
    else return a;
  end;




symbolic procedure mysmith(us,l,linv,x);
  %
  % The Smith normal form S of a matrix US is computed. L and Linv are
  % also computed where L*S*R=US.
  % For description of mysmith see smithex.
  %
  begin
    scalar s,a,b,g,jj,s1,t1,tmp,isclear,q,lc,poly1,poly2,input1,input2;
    integer n,r;

    n:= car size_of_matrix(us);

    s := copy_mat(us);

    for k:=1:n do
    <<

      isclear := nil;
      while not isclear do
      <<
        for i:= k+1:n do
        <<

          if getmat(s,i,k) = 0 then <<>>
          else
          <<

            poly1 := getmat(s,k,k);
            poly2 := getmat(s,i,k);
            tmp := calc_exgcd(poly1,poly2,x);
            g := car tmp;
            s1 := cadr tmp ;
            t1 := caddr tmp ;
            a := get_quo(poly1,g);
            b := get_quo(poly2,g);
            for j:=k+1:n do
            <<
              input1 := getmat(s,k,j);
              input2 := getmat(s,i,j);
              tmp := {'plus,{'times,s1,input1},{'times,t1,input2}};
              setmat(s,i,j,{'plus,{'times,a,input2},{'minus,{'times,b,
                     input1}}});
              setmat(s,k,j,tmp);
            >>;

            for j:=1:n do
            <<
              tmp := reval{'plus,{'times,a,getmat(l,j,k)},{'times,b,
                           getmat(l,j,i)}};
              setmat (l,j,i,reval{'plus,{'times,{'minus,t1},
                      getmat(l,j,k)},{'times,s1,getmat(l,j,i)}});
              setmat (l,j,k,tmp);
            >>;

            for j:=1:n do
            <<
              tmp := reval{'plus,{'times,s1,getmat(linv,k,j)},
                           {'times,t1,getmat(linv,i,j)}};
              setmat (linv,i,j,reval{'plus,{'times,a,getmat(linv,i,j)},
                      {'times,{'minus,b},getmat(linv,k,j)}});
              setmat (linv,k,j,tmp);
            >>;

            setmat(s,k,k,g);
            setmat(s,i,k,0);

          >>;

        >>;
        isclear := t;

        for i:=k+1:n do
        <<
          poly1:=getmat(s,k,i);
          poly2:=getmat(s,k,k);
          setmat(s,k,i,get_rem(poly1,poly2));
          q := get_quo(poly1,poly2);
        >>;

        for i:=k+1:n do
        <<
          if getmat(s,k,i) = 0 then <<>>
          else
          <<
            poly1:=getmat(s,k,k);
            poly2:=getmat(s,k,i);
            tmp := calc_exgcd(poly1,poly2,x);
            g:= car tmp;
            s1 := cadr tmp;
            t1 := caddr tmp;
            a:=get_quo(poly1,g);
            b:=get_quo(poly2,g);

            for j:=k+1:n do
            <<
              input1 := getmat(s,j,k);
              input2 := getmat(s,j,i);
              tmp := {'plus,{'times,s1,input1},{'times,t1,input2}};
              setmat(s,j,i,{'plus,{'times,a,input2},{'minus,{'times,b,
                     input1}}});
              setmat(s,j,k,tmp);
            >>;

            setmat(s,k,k,g);
            setmat(s,k,i,0);
            isclear := nil;
          >>;
        >>;

      >>;
    >>;

    r:=0;
    for i:=1:n do
    <<

      if getmat(s,i,i) neq 0 then
      <<
        r:=r+1;
        %  Watch out for integers giving lc = 0.
        if off_mod_lcof(getmat(s,i,i),x) = 0 then lc := getmat(s,i,i)
        else lc := off_mod_lcof(getmat(s,i,i),x);
        setmat(s,r,r,{'quotient,getmat(s,i,i),lc});
        if i neq r then
        <<
          setmat(s,i,i,0);

          for j:=1:n do
          <<
            tmp := reval getmat(l,j,r);
            setmat(l,j,r,reval getmat(l,i,j));

            setmat(l,j,i,tmp);
          >>;

          for j:=1:n do
          <<
            tmp := reval getmat(linv,r,j);
            setmat(linv,r,j,reval getmat(linv,i,j));
            setmat(linv,i,j,tmp);
          >>;

        >>;
      >>;

    >>;



    for i:=1:r-1 do
    <<
      jj:=i+1;
      <<
        while reval getmat(s,i,i) neq 1 and jj <= r do
        <<
          poly1:=reval getmat(s,i,i);
          poly2:=reval getmat(s,jj,jj);
          tmp := calc_exgcd(poly1,poly2,x);
          g:= car tmp;
          s1 := cadr tmp;
          t1 := caddr tmp;
          a:=get_quo(poly1,g);
          b:=get_quo(poly2,g);
          setmat(s,i,i,g);
          setmat(s,jj,jj,{'times,a,poly2});

          for k:=1:n do
          <<
            tmp := reval {'plus,{'times,a,getmat(l,k,i)},{'times,b,
                          getmat(l,k,jj)}};
            setmat (l,k,jj,reval {'plus,{'times,{'minus,t1},
                    getmat(l,k,i)},{'times,s1,getmat(l,k,jj)}});
            setmat (l,k,i,tmp);
          >>;

          for k:=1:n do
          <<
            tmp := reval {'plus,{'times,s1,getmat(linv,i,k)},{'times,t1,
                          getmat(linv,jj,k)}};
            setmat(linv,jj,k,reval {'plus,{'times,a,getmat(linv,jj,k)},
                   {'times,{'minus,b},getmat(linv,i,k)}});
            setmat(linv,i,k,tmp);
          >>;

          jj:=jj+1;
        >>;
      >>;
    >>;

    return {s,l,linv};
  end;




symbolic procedure nest_input(a);
  %
  % Takes a matrix and converts all elements into nested form.
  % Also finds union of all coefficients in all elements and
  % returns them in a list, along with the new matrix.
  %
  begin
    scalar tmp,coeff_list,full_coeff_list,aa;
    integer row_dim,col_dim;

    full_coeff_list := nil;
    coeff_list := nil;

    aa := copy_mat(a);

    row_dim := car size_of_matrix(aa);
    col_dim := cadr size_of_matrix(aa);

    for i := 1:row_dim do
    <<
      for j := 1:col_dim do
      <<
        coeff_list := get_coeffs(getmat(aa,i,j));
        if coeff_list = nil then <<>>
        else full_coeff_list := union(coeff_list,full_coeff_list);
        for each elt in coeff_list do
        <<
          tmp := {'co,2,elt};
          setmat(aa,i,j,algebraic (sub(elt=tmp,getmat(aa,i,j))));
        >>;
      >>;
    >>;


    return {aa,full_coeff_list};
  end;




symbolic procedure off_mod_lcof(input,x);
  begin
    if !*modular then
    <<
      off modular;
      input := lcof (input,x);
      on modular;
    >>
    else input := lcof (input,x);
    return input;
  end;




symbolic procedure off_mod_reval(input);
  %
  %  In certain cases it is required to reval with modular off,
  %  eg: when calculating degrees of polys.
  %
  begin
    if !*modular then
    <<
      off modular;
      input := reval input;
      on modular;
    >>
    else input := reval input;
    return input;
  end;

flag('(off_mod_reval),'opfn);  %  So it can be used from
                               %  algebraic mode.



symbolic procedure plist_to_polycompanion(plist,x);
  %
  % This is not used.
  % It is here to help explain what's going on.
  %
  % If a=a0+a1*x+x^2, b=b0+b1*x+b2*x^2+x^3 and
  % c=c0+c1*x+c2*x^2+c3*x^3+c4*x^4+x^5, then
  % plist_to_polycompanion({a,b,c},x) yields
  %
  %      [ 0  -a0  -b0   0   -c0 ]
  %      [                       ]
  %      [ 1  -a1  -b1   0   -c1 ]
  %      [                       ]
  %      [ 0   0   -b2   0   -c2 ]
  %      [                       ]
  %      [ 0   0    0    0   -c3 ]
  %      [                       ]
  %      [ 0   0    0    1   -c4 ]
  %
  begin
    scalar d,a;
    integer r,n;

    r := length plist;
    d := mkvect(r);
    putv(d,0,0);

    for i:=1:r do putv(d,i,deg(nth(plist,i),x));

    n := getv(d,r);
    a := mkmatrix(n,n);

    for i:=1:r do
    <<
      for j:=getv(d,i-1)+2:getv(d,i) do setmat(a,j,j-1,1);
      for j:=i:r do
      <<
        for k:=getv(d,i-1)+1:getv(d,i) do
        <<
          setmat(a,k,getv(d,j),{'minus,coeffn(nth(plist,j),x,k-1)});
        >>;
      >>;
    >>;

    return a;
  end;




symbolic procedure size_of_matrix(a);
  %
  % Takes matrix and returns list {no. of rows, no. of columns).
  %
  begin
    integer row_dim,col_dim;
    matrix_input_test(a);
    row_dim := -1 + length a;
    col_dim := length cadr a;
    return {row_dim,col_dim};
  end;




symbolic procedure uppersmith(g,x);
  %
  % An upper triangular matrix G is simplified. Entry G(i,j) is reduced
  % modulo gcd(G(i,i),G(j,j)). L and L^(-1) are also comnputed where
  % L*G'*R=G, where G' is the reduced matrix.
  %
  begin

    scalar us,l,linv,g,s1,t1,q,r,tmp;
    integer n;

    n:= car size_of_matrix(g);

    us:=copy_mat(g);

    l := make_identity(n,n);
    linv := make_identity(n,n);

    for j:=2:n do
    <<
      for i:=1:j-1 do
      <<
        tmp:=calc_exgcd(getmat(us,i,i),getmat(us,j,j),x);
        g:= car tmp;
        s1:= cadr tmp;
        t1 := caddr tmp;
        q := get_quo(getmat(us,i,j),g);
        r := get_rem(getmat(us,i,j),g);

        setmat(us,i,j,r);

        for k:=1:i-1 do
        <<
          tmp := getmat(us,k,i);
          setmat(us,k,j,{'plus,getmat(us,k,j),{'times,{'minus,q},s1,
                 getmat(us,k,i)}});
        >>;

        for k:=j+1:n do
        <<
          setmat(us,i,k,{'plus,getmat(us,i,k),{'times,{'minus,q},t1,
                 getmat(us,j,k)}});
        >>;

        for k:=1:i do
        <<
          setmat(l,k,j,{'plus,getmat(l,k,j),{'times,q,t1,
                 getmat(l,k,i)}});
        >>;

        setmat(linv,i,j,{'times,{'minus,q},t1});
      >>;
    >>;

    return {us,l,linv};
  end;

endmodule;

end;

