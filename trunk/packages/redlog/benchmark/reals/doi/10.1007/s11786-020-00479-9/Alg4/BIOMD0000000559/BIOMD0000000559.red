off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 76715997*x1*x58 - 6865455081*x1*x59 - 6865455081*x1*x60 - 40000000000*x1*x61 - 40000000000*x1*x64 - 40000000000*x1*x65 - 40000000000*x1*x69 - 40000000000*x1*x71 - 40000000000*x1*x72 + 3044571674000*x16 + 3044571674000*x17 + 3044571674000*x18 + 3044571674000*x19 + 3044571674000*x20 + 40000000000*x21*x70 + 3044571674000*x21 + 3044571674000*x22 + 99955800000000*x4 + 99531200000000*x5,  - 5000000*x2 + 499779*x4,  - 625000*x3 + 62207*x5, 137309101620*x1*x59 - 292588203*x4*x59 - 1999116000000000*x4, 137309101620*x1*x60 + 292588203*x4*x59 - 6700994384*x5*x59 - 1990624000000000*x5, x3, x2, 292588203*x23*x58 - 6700994384*x58*x8, 418812149*x58*x8 - 418812149*x58*x9,  - 418812149*x10*x58 + 418812149*x58*x9,  - 418812149*x11*x58 + 418812149*x12*x58,  - 418812149*x12*x58 + 418812149*x13*x58, 418812149*x10*x58 - 418812149*x13*x58, 418812149*x11*x58 - 418812149*x14*x58, 418812149*x14*x58, 50000000000*x1*x61 - 418812149*x16*x59 - 3805714592500*x16 + 418812149*x5*x59, 50000000000*x1*x65 + 418812149*x16*x59 - 418812149*x17*x59 - 3805714592500*x17, 50000000000*x1*x64 + 418812149*x17*x59 - 418812149*x18*x59 - 3805714592500*x18, 50000000000*x1*x72 + 418812149*x18*x59 - 418812149*x19*x59 - 3805714592500*x19, 50000000000*x1*x71 + 418812149*x19*x59 - 418812149*x20*x59 - 3805714592500*x20, 418812149*x20*x59 - 418812149*x21*x59 - 50000000000*x21*x70 - 3805714592500*x21, 50000000000*x1*x69 + 418812149*x21*x59 - 3805714592500*x22, 1534319940*x1*x58 - 292588203*x23*x58, x40 + x50, x39, x36, x37, x38, x41, x42, x51 + x52, x49, x48, x47, x44,  - 1000000000000000*x36 + 239034347*x65,  - 1000000000000000*x37 + 239034347*x64,  - 1000000000000000*x38 + 239034347*x72,  - 1000000000000000*x39 + 239034347*x61,  - 1000000000000000*x40 + 239034347*x60,  - 1000000000000000*x41 + 239034347*x71,  - 1000000000000000*x42 + 239034347*x70, x45 + x46,  - 1000000000000000*x44 + 239034347*x67,  - 1000000000000000*x45 + 239034347*x66,  - 1000000000000000*x46 + 239034347*x62,  - 1000000000000000*x47 + 239034347*x53,  - 1000000000000000*x48 + 239034347*x54,  - 1000000000000000*x49 + 239034347*x56,  - 1000000000000000*x50 + 239034347*x59,  - 1000000000000000*x51 + 239034347*x58,  - 1000000000000000*x52 + 239034347*x57,  - 8376242980*x53*x58 - 856173418*x53*x74 - 130964202375*x53 + 8376242980*x54*x58 + 124988343700*x62, 124988343700*x53 - 8376242980*x54*x58 - 856173418*x54*x74 - 130964202375*x54 + 8376242980*x56*x58, 0, 124988343700*x54 - 8376242980*x56*x58 - 856173418*x56*x74 - 130964202375*x56 + 8376242980*x57*x58, 99990674960*x56 - 6700994384*x57*x58 - 104771361900*x57 + 292588203*x58**2,  - 1534319940*x1*x58 - 6700994384*x10*x58 - 6700994384*x11*x58 - 6700994384*x12*x58 - 6700994384*x13*x58 - 6700994384*x14*x58 - 292588203*x23*x58 - 6700994384*x53*x58 + 99990674960*x53 - 6700994384*x54*x58 + 99990674960*x54 - 6700994384*x56*x58 + 99990674960*x56 - 6700994384*x57*x58 + 199981349920*x57 - 585176406*x58**2 - 6700994384*x58*x62 - 6700994384*x58*x66 - 6700994384*x58*x67 - 6700994384*x58*x8 - 6700994384*x58*x9 - 4780686940*x58 + 134953600000*x59*x63 + 99990674960*x62 + 99990674960*x66 + 99990674960*x67 + 99990674960*x68,  - 137309101620*x1*x59 - 6700994384*x16*x59 - 6700994384*x17*x59 - 6700994384*x18*x59 - 6700994384*x19*x59 - 6700994384*x20*x59 - 6700994384*x21*x59 - 292588203*x4*x59 - 6700994384*x5*x59 - 585176406*x59**2 - 6700994384*x59*x60 - 6700994384*x59*x61 - 134953600000*x59*x63 - 6700994384*x59*x64 - 6700994384*x59*x65 - 6700994384*x59*x69 - 6700994384*x59*x70 - 6700994384*x59*x71 - 6700994384*x59*x72 - 98111200000*x59*x73 - 4780686940*x59 + 199981349920*x60 + 99990674960*x61 + 99990674960*x64 + 99990674960*x65 + 99990674960*x69 + 99990674960*x70 + 99990674960*x71 + 99990674960*x72 + 5884380000000000,  - 137309101620*x1*x60 + 292588203*x59**2 - 6700994384*x59*x60 - 104771361900*x60 + 99990674960*x61,  - 1000000000000*x1*x61 + 76114291850000*x16 + 8376242980*x59*x60 - 8376242980*x59*x61 - 856173418*x61*x74 - 130964202375*x61 + 124988343700*x65, 8376242980*x53*x58 - 8376242980*x58*x62 - 856173418*x62*x74 - 130964202375*x62 + 124988343700*x66,  - 42173*x59*x63 - 424688125*x63 + 4948893750,  - 1000000000000*x1*x64 + 76114291850000*x18 - 8376242980*x59*x64 + 8376242980*x59*x65 - 856173418*x64*x74 - 130964202375*x64 + 124988343700*x72,  - 1000000000000*x1*x65 + 76114291850000*x17 + 8376242980*x59*x61 - 8376242980*x59*x65 + 124988343700*x64 - 856173418*x65*x74 - 130964202375*x65, 8376242980*x58*x62 - 8376242980*x58*x66 - 856173418*x66*x74 - 130964202375*x66 + 124988343700*x67, 8376242980*x58*x66 - 8376242980*x58*x67 - 856173418*x67*x74 - 130964202375*x67 + 124988343700*x68, 4188121490*x58*x67 - 428086709*x68*x74 - 62494171850*x68,  - 500000000000*x1*x69 + 38057145925000*x22 - 4188121490*x59*x69 + 4188121490*x59*x70 - 428086709*x69*x74 - 62494171850*x69,  - 1000000000000*x21*x70 + 76114291850000*x21 - 8376242980*x59*x70 + 8376242980*x59*x71 + 124988343700*x69 - 856173418*x70*x74 - 130964202375*x70,  - 1000000000000*x1*x71 + 76114291850000*x20 - 8376242980*x59*x71 + 8376242980*x59*x72 + 124988343700*x70 - 856173418*x71*x74 - 130964202375*x71,  - 1000000000000*x1*x72 + 76114291850000*x19 + 8376242980*x59*x64 - 8376242980*x59*x72 + 124988343700*x71 - 856173418*x72*x74 - 130964202375*x72, 4188121490*x59*x69 - 428086709*x73*x74,  - 428086709*x53*x74 - 428086709*x54*x74 - 428086709*x56*x74 - 428086709*x61*x74 - 428086709*x62*x74 - 428086709*x64*x74 - 428086709*x65*x74 - 428086709*x66*x74 - 428086709*x67*x74 - 428086709*x68*x74 - 428086709*x69*x74 - 428086709*x70*x74 - 428086709*x71*x74 - 428086709*x72*x74 - 428086709*x73*x74 + 46262000000000*x76 + 46262000000000*x77 + 46262000000000*x78 + 46262000000000*x79 + 46262000000000*x80 + 46262000000000*x81 + 46262000000000*x82 + 46262000000000*x83 + 46262000000000*x84 + 46262000000000*x85 + 46262000000000*x86 + 46262000000000*x87 + 46262000000000*x88 + 46262000000000*x89, 679501*x63, 428086709*x61*x74 - 46262000000000*x76, 428086709*x65*x74 - 46262000000000*x77, 428086709*x64*x74 - 46262000000000*x78, 428086709*x72*x74 - 46262000000000*x79, 428086709*x71*x74 - 46262000000000*x80, 428086709*x70*x74 - 46262000000000*x81, 428086709*x69*x74 - 46262000000000*x82, 428086709*x56*x74 - 46262000000000*x83, 428086709*x54*x74 - 46262000000000*x84, 428086709*x53*x74 - 46262000000000*x85, 428086709*x62*x74 - 46262000000000*x86, 428086709*x66*x74 - 46262000000000*x87, 428086709*x67*x74 - 46262000000000*x88, 428086709*x68*x74 - 46262000000000*x89, 428086709*x73*x74};

classifyComponents {basis};

end;