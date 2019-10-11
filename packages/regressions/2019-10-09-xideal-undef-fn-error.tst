comment xcolor using varpri function instead of assgnpri;

load_package xcolor;

sudim n;

qg(a0,a1,c0)*qg(a1,a2,c1)*qg(a2,a3,c2)*qg(a3,a0,c3);

qg(a0,a1,c0)*qg(a1,a2,c1)*qg(a2,a3,c2)*qg(a3,a0,c3)
 *(qg(b0,b1,c0)*qg(b1,b2,c1)*qg(b2,b3,c2)*qg(b3,b0,c3)
 +qg(b0,b1,c0)*qg(b1,b2,c1)*qg(b2,b3,c3)*qg(b3,b0,c2));

qg(a0,a1,c0)*qg(a1,a2,c1)*qg(a2,a3,c2)*qg(a3,a0,c3)*qg(b0,b1,c0)
 *qg(b1,b2,c1)*qg(b2,b3,c2)*qg(b3,b0,c3)
 +qg(a0,a1,c0)*qg(a1,a2,c1)*qg(a2,a3,c2)*qg(a3,a0,c3)
 *qg(b0,b1,c0)*qg(b1,b2,c1)*qg(b2,b3,c3)*qg(b3,b0,c2);

% Try with factor on

on factor;

qg(a0,a1,c0)*qg(a1,a2,c1)*qg(a2,a3,c2)*qg(a3,a0,c3);

qg(a0,a1,c0)*qg(a1,a2,c1)*qg(a2,a3,c2)*qg(a3,a0,c3)
 *(qg(b0,b1,c0)*qg(b1,b2,c1)*qg(b2,b3,c2)*qg(b3,b0,c3)
 +qg(b0,b1,c0)*qg(b1,b2,c1)*qg(b2,b3,c3)*qg(b3,b0,c2));

qg(a0,a1,c0)*qg(a1,a2,c1)*qg(a2,a3,c2)*qg(a3,a0,c3)*qg(b0,b1,c0)
 *qg(b1,b2,c1)*qg(b2,b3,c2)*qg(b3,b0,c3)
 +qg(a0,a1,c0)*qg(a1,a2,c1)*qg(a2,a3,c2)*qg(a3,a0,c3)
 *qg(b0,b1,c0)*qg(b1,b2,c1)*qg(b2,b3,c3)*qg(b3,b0,c2);


end;
