off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 1000*x1*x2 + 250*x10 + x12*x9 + 1000*x3 + 2500*x33,  - 100*x1*x2 - 100*x2*x20 - 100*x2*x8 + x28*x31 + 100*x3 + 100*x7, 2*x1*x2 - 5*x3 + 3000000*x4, 3*x3 - 13000000*x4 + 2*x7, 0, 0, x2*x8 + 5000000*x4 - 2*x7,  - x11*x8 - 1000*x2*x8 - 1250*x32*x8 + 1000*x7 - 10*x8*x9, 250*x10 - x20*x9 + 10000*x32 - 10*x8*x9,  - 25*x10 + x8*x9,  - x11*x8 + x12*x9, x11*x8 - x12*x9, 0, 5040000*x12 - x14*x15 - x14*x16 - x14*x17 - x14*x18 - 10000*x14*x25 - 10*x14*x29 + 10000*x16 + 10000*x17 + 10000*x18 + 10000*x19 + 200000*x21 + 10000*x26 + 100000*x30,  - x14*x15 + 10000*x16 + 50000*x23**2 - 50000*x23, x14*x15 - x14*x16 - 10000*x16 + 10000*x17, x14*x16 - x14*x17 - 10000*x17 + 10000*x18, x14*x17 - x14*x18 - 10000*x18 + 10000*x19, x14*x18 - 110000*x19, 8*x19 - 3*x20*x22, 2*x19 - x21,  - 3*x20*x22 + 4*x21, 3*x20*x22 - 4*x23**2 + 4*x23,  - x20*x24 + 100*x25*x28,  - 100000*x14*x25 + x20*x24 - 100*x25*x28 + 7600000*x26, x14*x25 - 76*x26, 75*x26 + 17*x30, 0,  - x14*x29 + 27000*x30, x14*x29 - 27000*x30, 100*x2*x20 - x28*x31, x20*x9 - 1250*x32*x8 - 10000*x32 + 2500*x33, 5*x32*x8 - 10*x33};

classifyComponents {basis};

end;