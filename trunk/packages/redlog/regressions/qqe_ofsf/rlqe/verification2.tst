off rlabout;

rlset(qqe,ofsf);

% Example from C. Strasser's diploma thesis
% Ch.10. Software Verifikation, p.171
f := ex({a}, ((j > 5 and radd(a,q) == qepsilon) or (radd(a,q) <<>>
qepsilon and lhead(radd(a,q)) > 23 + j)) and lhead(radd(a,q)) = x)$

rlqe f;

end;