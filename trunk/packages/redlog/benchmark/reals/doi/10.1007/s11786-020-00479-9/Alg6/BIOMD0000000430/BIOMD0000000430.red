off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x10, x11, x12, x13, x14, x16, x17, x19, x2, x21, x22, x24, x25, x3, x5, x8, x9}, {x10, x11, x12, x13, x14, x17, x18, x19, x2, x21, x22, x24, x25, x3, x5, x8, x9}, {x10, x11, x12, x13, x14, x2, x21, x22, x24, x25, x3, x5, x7, x9, 43*x19-500*x17, x16*x18-100*x17, 43*x20*x8-27150*x17}, {x11, x12, x13, x14, x16, x17, x19, x2, x20, x21, x22, x24, x25, x3, x5, x8, x9}, {x11, x12, x13, x14, x17, x18, x19, x2, x20, x21, x22, x24, x25, x3, x5, x8, x9}, {x1, x11, x12, x13, x14, x16, x17, x19, x20, x21, x22, x24, x25, x3, x4, x5, x8, x9}, {x1, x11, x12, x13, x14, x17, x18, x19, x20, x21, x22, x24, x25, x3, x4, x5, x8, x9}, {x10, x11, x12, x13, x14, x16, x17, x19, x2, x20, x21, x22, x24, x25, x3, x5, x7, x9}, {x10, x11, x12, x13, x14, x17, x18, x19, x2, x20, x21, x22, x24, x25, x3, x5, x7, x9}, {x10, x11, x12, x14, x16, x17, x19, x2, x21, x22, x24, x25, x3, x4, x5, x6, x8, x9}, {x10, x11, x12, x14, x17, x18, x19, x2, x21, x22, x24, x25, x3, x4, x5, x6, x8, x9}, {x10, x11, x12, x14, x2, x21, x22, x24, x25, x3, x4, x5, x6, x7, x9, 43*x19-500*x17, x16*x18-100*x17, 43*x20*x8-27150*x17}, {x1, x11, x16, x17, x19, x21, x22, x3, x4, x5, x6, x8, x9, x13+x20, x14+x25, x24+x12, 5*x10*x13-543*x14, 15*x13*x2-364*x12, -364*x10*x12+1629*x14*x2}, {x1, x11, x17, x18, x19, x21, x22, x3, x4, x5, x6, x8, x9, x13+x20, x14+x25, x24+x12, 5*x10*x20+543*x14, 15*x2*x20+364*x12, -364*x10*x12+1629*x14*x2}, {x1, x12, x13, x14, x21, x22, x3, x4, x5, 43*x19-500*x17, 23*x24-3750*x11, 5*x9-43*x25, x10*x8-500*x11, -395213*x10^2+12489*x2*x7, 5*x10*x20-543*x25, 23*x2*x20-91000*x11, x16*x18-100*x17, 43*x20*x8-27150*x17, 10*x7*x8-4343*x25, -455000*x10*x11+12489*x2*x25, -4343*x10*x25+5000*x11*x7, 250*x10*x17-43*x25*x8, -78260*x11*x8+12489*x17*x2, 43*x25*x8^2-125000*x11*x17, 2500*x11*x20-543*x25*x8, 271500*x17*x7-186749*x20*x25}, {x11, x16, x17, x19, x8, x9, x13+x20, x14+x25, 23*x21-3750*x5, x24+x12, 5*x3-43*x22, 10*x1*x2-4343*x22, 12489*x1*x6-395213*x4^2, 5*x10*x13-543*x14, 15*x13*x2-364*x12, 5*x13*x4-543*x22, 23*x13*x6-91000*x5, x2*x4-500*x5, 728*x1*x12-13029*x13*x22, 5000*x1*x5-4343*x22*x4, 364*x10*x12-1629*x14*x2, x10*x22-x14*x4, -455000*x10*x5+12489*x14*x6, 3125*x13^2*x5-16471*x12*x22, 91*x12*x4-1875*x13*x5, 23*x12*x6-3750*x2*x5, -2500*x13*x5+543*x2*x22, 12489*x22*x6-455000*x4*x5}, {x11, x17, x18, x19, x8, x9, x13+x20, x14+x25, 23*x21-3750*x5, x24+x12, 5*x3-43*x22, 10*x1*x2-4343*x22, 12489*x1*x6-395213*x4^2, 5*x10*x13-543*x14, 15*x13*x2-364*x12, 5*x13*x4-543*x22, 23*x13*x6-91000*x5, x2*x4-500*x5, 728*x1*x12-13029*x13*x22, 5000*x1*x5-4343*x22*x4, 364*x10*x12-1629*x14*x2, x10*x22-x14*x4, -455000*x10*x5+12489*x14*x6, 3125*x13^2*x5-16471*x12*x22, 91*x12*x4-1875*x13*x5, 23*x12*x6-3750*x2*x5, -2500*x13*x5+543*x2*x22, 12489*x22*x6-455000*x4*x5}, {x10, x11, x14, x25, x7, x9, x13+x20, 43*x19-500*x17, 23*x21-3750*x5, x24+x12, 5*x3-43*x22, 10*x1*x2-4343*x22, 12489*x1*x6-395213*x4^2, 15*x13*x2-364*x12, 43*x13*x8+27150*x17, 5*x13*x4-543*x22, 23*x13*x6-91000*x5, x16*x18-100*x17, x2*x4-500*x5, 728*x1*x12-13029*x13*x22, 5000*x1*x5-4343*x22*x4, 3125*x13^2*x5-16471*x12*x22, 91*x12*x4-1875*x13*x5, 7826*x12*x8+203625*x17*x2, 23*x12*x6-3750*x2*x5, -2500*x13*x5+543*x2*x22, 250*x17*x4+43*x22*x8, 12489*x17*x6+78260*x5*x8, 12489*x22*x6-455000*x4*x5}, {x1, x21, x22, x3, x4, x5, x6, 43*x19-500*x17, 23*x12+23*x24-3750*x11, 5*x9-43*x25-43*x14, x10*x8-500*x11, 5*x10*x13-543*x14, -395213*x10^2+12489*x2*x7, 5*x10*x20-543*x25, 15*x13*x2-364*x12, x16*x18-100*x17, 43*x20*x8-27150*x17, 543*x10*x17-430*x11*x20, -364*x10*x12+1629*x14*x2, -13029*x10*x14+92*x12*x7, 2500*x11*x13-543*x14*x8, 2150*x11*x20^2-294849*x17*x25, -2500*x11*x20+543*x25*x8, x13*x25-x14*x20, -3750*x11*x14+23*x12*x14+23*x12*x25, 345*x2*x20-1365000*x11+8372*x12, 10*x7*x8-4343*x14-4343*x25, -1365000*x10*x11+8372*x10*x12+37467*x2*x25, -4343*x10*x14-4343*x10*x25+5000*x11*x7, 57500*x11*x12*x20-2036250*x11*x14*x8+12489*x12*x14*x8, -29347500*x11*x8+179998*x12*x8+4683375*x17*x2, 46*x12*x13+46*x12*x20-1629*x14*x8, -186749*x14*x20+271500*x17*x7-186749*x20*x25}, {43*x19-500*x17, 23*x21-3750*x5, 5*x3-43*x22, 23*x12+23*x24-3750*x11, 43*x14-5*x9+43*x25, 10*x1*x2-4343*x22, 12489*x1*x6-395213*x4^2, x10*x8-500*x11, 5*x10*x13-543*x14, -395213*x10^2+12489*x2*x7, 15*x13*x2-364*x12, 5*x13*x4-543*x22, 23*x13*x6-91000*x5, x16*x18-100*x17, 43*x20*x8-27150*x17, x2*x4-500*x5, 2*x7*x8-101*x9, 910*x1*x10^2-12489*x22*x7, 728*x1*x12-13029*x13*x22, 5000*x1*x5-4343*x22*x4, -543*x10*x17+430*x11*x20, -3913000*x10*x11+12489*x2*x9, -101*x10*x9+1000*x11*x7, -364*x10*x12+1629*x14*x2, -13029*x10*x14+92*x12*x7, -x10*x22+x14*x4, -455000*x10*x5+12489*x14*x6, 395213*x10^2*x4-6244500*x5*x7, -32250*x11*x14+23*x12*x9, 2500*x11*x13-543*x14*x8, 364*x12*x4-1629*x2*x22, 1629*x2^2*x22-182000*x12*x5, 23*x12*x6-3750*x2*x5, 2500*x13*x5-543*x2*x22, -54300*x17*x7+4343*x20*x9, 12489*x22*x6-455000*x4*x5, 910000*x1*x10*x11-1261389*x22*x9, 7826*x10*x11*x4-12489*x5*x9, 91*x10^2*x12*x22-203625*x14^2*x5, x10*x2*x22-500*x14*x5, 395213*x10^3*x22-6244500*x14*x5*x7, -182*x1*x10*x14+23*x13*x22*x7, 182000*x1*x11*x14-2323*x13*x22*x9, -197652*x1*x14^2*x8+11615*x13^2*x22*x9, 7826*x10^2*x11*x22-12489*x14*x5*x9, x11*x2*x22-x14*x5*x8, 215*x10*x20+23349*x14-2715*x9, 345*x2*x20-1365000*x11+8372*x12, 43*x13*x14-5*x13*x9+43*x14*x20, -910000*x1*x11+99889*x13*x22+99889*x20*x22, x10^2*x17+86*x11*x14-10*x11*x9, 500*x10*x17*x7+4343*x14*x9-505*x9^2, -250*x10*x17-43*x14*x8+5*x8*x9, -29347500*x11*x8+179998*x12*x8+4683375*x17*x2, 1978*x12*x13*x8-70047*x14*x8^2+1248900*x12*x17, 46*x12*x13+46*x12*x20-1629*x14*x8, 4343*x13*x14*x9-505*x13*x9^2+54300*x14*x17*x7, 910000*x1*x11*x8-99889*x13*x22*x8-63069450*x17*x22, -197652*x1*x14*x8^2+99889*x13^2*x22*x8+63069450*x13*x17*x22, 5750*x10*x12*x17-161250*x11*x14*x8+989*x12*x14*x8, -29347500*x11^2*x22+179998*x11*x12*x22+4683375*x14*x17*x5, -673036*x11^2*x14*x22+78260*x11^2*x22*x9-12489*x14*x17*x5*x9, -455000*x11*x4+12489*x2*x22+57500*x20*x5, 2275000000*x1*x11^2-315347250*x10*x17*x22-54239727*x14*x22*x8, -910000*x1*x11*x9+99889*x13*x22*x9+1248900*x17*x22*x7, -19565000*x10*x11^2*x22+3122250*x10*x14*x17*x5+537027*x14^2*x5*x8, -3122250*x10*x17*x5+19565000*x11^2*x4-537027*x14*x5*x8, 19565000*x11*x4*x8-537027*x2*x22*x8-1561125000*x17*x5, 989*x12*x2*x22*x8-161250*x14*x5*x8^2+2875000*x12*x17*x5, 16994159*x10*x11*x22-1976065*x11*x4*x9+3122250*x17*x5*x7, -2366142187500*x11^2*x22*x8^2+89009011*x12^2*x22*x8^2+755194218750*x14*x17*x5*x8^2-6732351562500*x12*x17^2*x5}};

classifyComponents P;

end;
