off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{41203*x2-25000000000, 148163896062120425407230271*x3-490435908710000000000, 4472956477*x4-233129250000000000}};

classifyComponents P;

end;
