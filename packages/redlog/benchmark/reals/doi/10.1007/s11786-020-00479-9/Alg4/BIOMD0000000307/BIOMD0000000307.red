off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 100*x1 + x2,  - x2, 0, 0, 0};

classifyComponents {basis};

end;
