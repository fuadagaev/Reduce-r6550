off rlabout;

rlset ibalp;

% Formula ii32e4.cnf of the Dimacs II benchmark set
% http://www.cs.ubc.ca/~hoos/SATLIB/benchm.html
ii32e4 :=
(var1 = 1 or var2 = 1) and (var3 = 1 or var4 = 1) and (var5 = 1 or var6 = 1) and
 (var7 = 1 or var8 = 1) and (var9 = 1 or var10 = 1) and (var11 = 1 or var12 = 1)
 and (var13 = 1 or var14 = 1) and (var15 = 1 or var16 = 1) and (var17 = 1 or
var18 = 1) and (var19 = 1 or var20 = 1) and (var21 = 1 or var22 = 1) and (var23
= 1 or var24 = 1) and (var25 = 1 or var26 = 1) and (var27 = 1 or var28 = 1) and
(var29 = 1 or var30 = 1) and (var31 = 1 or var32 = 1) and (var33 = 1 or var34 =
1) and (var35 = 1 or var36 = 1) and (var37 = 1 or var38 = 1) and (var39 = 1 or
var40 = 1) and (var41 = 1 or var42 = 1) and (var43 = 1 or var44 = 1) and (var45
= 1 or var46 = 1) and (var47 = 1 or var48 = 1) and (var49 = 1 or var50 = 1) and
(var51 = 1 or var52 = 1) and (var53 = 1 or var54 = 1) and (var55 = 1 or var56 =
1) and (var57 = 1 or var58 = 1) and (var59 = 1 or var60 = 1) and (var61 = 1 or
var62 = 1) and (var63 = 1 or var64 = 1) and (var65 = 1 or var66 = 1) and (var67
= 1 or var68 = 1) and (var69 = 1 or var70 = 1) and (var71 = 1 or var72 = 1) and
(var73 = 1 or var74 = 1) and (var75 = 1 or var76 = 1) and (var77 = 1 or var78 =
1) and (var79 = 1 or var80 = 1) and (var81 = 1 or var82 = 1) and (var83 = 1 or
var84 = 1) and (var85 = 1 or var86 = 1) and (var87 = 1 or var88 = 1) and (var89
= 1 or var90 = 1) and (var91 = 1 or var92 = 1) and (var93 = 1 or var94 = 1) and
(var95 = 1 or var96 = 1) and (var97 = 1 or var98 = 1) and (var99 = 1 or var100 =
 1) and (var101 = 1 or var102 = 1) and (var103 = 1 or var104 = 1) and (var105 =
1 or var106 = 1) and (var107 = 1 or var108 = 1) and (var109 = 1 or var110 = 1)
and (var111 = 1 or var112 = 1) and (var113 = 1 or var114 = 1) and (var115 = 1 or
 var116 = 1) and (var117 = 1 or var118 = 1) and (var119 = 1 or var120 = 1) and (
var121 = 1 or var122 = 1) and (var123 = 1 or var124 = 1) and (var125 = 1 or
var126 = 1) and (var127 = 1 or var128 = 1) and (var129 = 1 or var130 = 1) and (
var131 = 1 or var132 = 1) and (var133 = 1 or var134 = 1) and (var135 = 1 or
var136 = 1) and (var137 = 1 or var138 = 1) and (var139 = 1 or var140 = 1) and (
var141 = 1 or var142 = 1) and (var143 = 1 or var144 = 1) and (var145 = 1 or
var146 = 1) and (var147 = 1 or var148 = 1) and (var149 = 1 or var150 = 1) and (
var151 = 1 or var152 = 1) and (var153 = 1 or var154 = 1) and (var155 = 1 or
var156 = 1) and (var157 = 1 or var158 = 1) and (var159 = 1 or var160 = 1) and (
var161 = 1 or var162 = 1) and (var163 = 1 or var164 = 1) and (var165 = 1 or
var166 = 1) and (var167 = 1 or var168 = 1) and (var169 = 1 or var170 = 1) and (
var171 = 1 or var172 = 1) and (var173 = 1 or var174 = 1) and (var175 = 1 or
var176 = 1) and (var177 = 1 or var178 = 1) and (var179 = 1 or var180 = 1) and (
var181 = 1 or var182 = 1) and (var183 = 1 or var184 = 1) and (var185 = 1 or
var186 = 1) and (var187 = 1 or var188 = 1) and (var189 = 1 or var190 = 1) and (
var191 = 1 or var192 = 1) and (not(var1 = 1) or not(var3 = 1) or not(var5 = 1)
or not(var7 = 1) or not(var9 = 1) or not(var12 = 1) or not(var13 = 1) or not(
var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(var21 = 1) or not(var24 =
1) or not(var25 = 1) or not(var28 = 1) or not(var30 = 1) or not(var31 = 1) or
not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or not(var39 = 1) or not(
var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(var48 = 1) or not(var50 =
1) or not(var52 = 1) or not(var54 = 1) or not(var55 = 1) or not(var58 = 1) or
not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and (not(var65 = 1) or not(
var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(var73 = 1) or not(var76 =
1) or not(var77 = 1) or not(var79 = 1) or not(var81 = 1) or not(var83 = 1) or
not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or not(var92 = 1) or not(
var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(var99 = 1) or not(var101 =
 1) or not(var103 = 1) or not(var105 = 1) or not(var108 = 1) or not(var109 = 1)
or not(var112 = 1) or not(var114 = 1) or not(var116 = 1) or not(var118 = 1) or
not(var119 = 1) or not(var122 = 1) or not(var123 = 1) or not(var126 = 1) or not(
var127 = 1)) and (not(var129 = 1) or not(var131 = 1) or not(var133 = 1) or not(
var135 = 1) or not(var137 = 1) or not(var140 = 1) or not(var141 = 1) or not(
var143 = 1) or not(var145 = 1) or not(var147 = 1) or not(var149 = 1) or not(
var152 = 1) or not(var153 = 1) or not(var156 = 1) or not(var158 = 1) or not(
var159 = 1) or not(var162 = 1) or not(var163 = 1) or not(var165 = 1) or not(
var167 = 1) or not(var169 = 1) or not(var172 = 1) or not(var173 = 1) or not(
var176 = 1) or not(var178 = 1) or not(var180 = 1) or not(var182 = 1) or not(
var183 = 1) or not(var186 = 1) or not(var187 = 1) or not(var190 = 1) or not(
var191 = 1)) and (not(var2 = 1) or not(var3 = 1) or not(var5 = 1) or not(var8 =
1) or not(var10 = 1) or not(var11 = 1) or not(var14 = 1) or not(var15 = 1) or
not(var17 = 1) or not(var20 = 1) or not(var22 = 1) or not(var24 = 1) or not(
var25 = 1) or not(var27 = 1) or not(var29 = 1) or not(var32 = 1) or not(var33 =
1) or not(var36 = 1) or not(var37 = 1) or not(var40 = 1) or not(var41 = 1) or
not(var44 = 1) or not(var45 = 1) or not(var47 = 1) or not(var50 = 1) or not(
var51 = 1) or not(var54 = 1) or not(var55 = 1) or not(var58 = 1) or not(var60 =
1) or not(var62 = 1) or not(var63 = 1)) and (not(var66 = 1) or not(var67 = 1) or
 not(var69 = 1) or not(var72 = 1) or not(var74 = 1) or not(var75 = 1) or not(
var78 = 1) or not(var79 = 1) or not(var81 = 1) or not(var84 = 1) or not(var86 =
1) or not(var88 = 1) or not(var89 = 1) or not(var91 = 1) or not(var93 = 1) or
not(var96 = 1) or not(var97 = 1) or not(var100 = 1) or not(var101 = 1) or not(
var104 = 1) or not(var105 = 1) or not(var108 = 1) or not(var109 = 1) or not(
var111 = 1) or not(var114 = 1) or not(var115 = 1) or not(var118 = 1) or not(
var119 = 1) or not(var122 = 1) or not(var124 = 1) or not(var126 = 1) or not(
var127 = 1)) and (not(var130 = 1) or not(var131 = 1) or not(var133 = 1) or not(
var136 = 1) or not(var138 = 1) or not(var139 = 1) or not(var142 = 1) or not(
var143 = 1) or not(var145 = 1) or not(var148 = 1) or not(var150 = 1) or not(
var152 = 1) or not(var153 = 1) or not(var155 = 1) or not(var157 = 1) or not(
var160 = 1) or not(var161 = 1) or not(var164 = 1) or not(var165 = 1) or not(
var168 = 1) or not(var169 = 1) or not(var172 = 1) or not(var173 = 1) or not(
var175 = 1) or not(var178 = 1) or not(var179 = 1) or not(var182 = 1) or not(
var183 = 1) or not(var186 = 1) or not(var188 = 1) or not(var190 = 1) or not(
var191 = 1)) and (not(var2 = 1) or not(var4 = 1) or not(var6 = 1) or not(var8 =
1) or not(var9 = 1) or not(var11 = 1) or not(var13 = 1) or not(var15 = 1) or not
(var17 = 1) or not(var20 = 1) or not(var22 = 1) or not(var23 = 1) or not(var25 =
 1) or not(var27 = 1) or not(var30 = 1) or not(var31 = 1) or not(var34 = 1) or
not(var35 = 1) or not(var37 = 1) or not(var39 = 1) or not(var41 = 1) or not(
var43 = 1) or not(var45 = 1) or not(var48 = 1) or not(var50 = 1) or not(var51 =
1) or not(var53 = 1) or not(var55 = 1) or not(var57 = 1) or not(var59 = 1) or
not(var61 = 1) or not(var64 = 1)) and (not(var66 = 1) or not(var68 = 1) or not(
var70 = 1) or not(var72 = 1) or not(var73 = 1) or not(var75 = 1) or not(var77 =
1) or not(var79 = 1) or not(var81 = 1) or not(var84 = 1) or not(var86 = 1) or
not(var87 = 1) or not(var89 = 1) or not(var91 = 1) or not(var94 = 1) or not(
var95 = 1) or not(var98 = 1) or not(var99 = 1) or not(var101 = 1) or not(var103
= 1) or not(var105 = 1) or not(var107 = 1) or not(var109 = 1) or not(var112 = 1)
 or not(var114 = 1) or not(var115 = 1) or not(var117 = 1) or not(var119 = 1) or
not(var121 = 1) or not(var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (
not(var130 = 1) or not(var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(
var137 = 1) or not(var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(
var145 = 1) or not(var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(
var153 = 1) or not(var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(
var162 = 1) or not(var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(
var169 = 1) or not(var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(
var178 = 1) or not(var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(
var185 = 1) or not(var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(
var2 = 1) or not(var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1)
or not(var12 = 1) or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(
var19 = 1) or not(var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 =
1) or not(var29 = 1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or
not(var38 = 1) or not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(
var45 = 1) or not(var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 =
1) or not(var55 = 1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or
not(var63 = 1)) and (not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(
var72 = 1) or not(var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 =
1) or not(var82 = 1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or
not(var90 = 1) or not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(
var98 = 1) or not(var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106
 = 1) or not(var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1
) or not(var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or
 not(var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or
not(var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var5 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var133 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var1 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var68 = 1) or not(var69 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var18 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var82 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var34 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var40 = 1) or not(var41 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var78 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var104 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var168 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var29 =
1) or not(var32 = 1) or not(var34 = 1) or not(var36 = 1) or not(var38 = 1) or
not(var40 = 1) or not(var42 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var76 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var93 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var100 = 1) or not(var102 = 1) or not(var104 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var157 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var164 = 1) or not(var166 = 1) or not(var168 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var43 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var77 = 1) or not(var79 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var107 = 1) or not(var110 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var141 = 1) or not(var143 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var171 = 1) or not(var174 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var1 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var27 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var60 = 1) or not(var61 = 1) or not(var64 = 1)) and
(not(var65 = 1) or not(var67 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var128 = 1)) and (not(var129 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var5 = 1) or not(var7 = 1) or not(var10 = 1) or not(var12 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var22 = 1) or not(var23 = 1) or not(var25 = 1) or not(var28 = 1) or not(var30 =
1) or not(var31 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var47 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var55 =
1) or not(var57 = 1) or not(var59 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var69 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var76 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var84 = 1) or not(var86 = 1) or not(var87 = 1) or not(var89 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var95 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var111 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var119 = 1) or not(var121 = 1) or not(
var123 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var133 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var140 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var150 = 1) or not(var151 = 1) or not(var153 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var159 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var175 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var183 = 1) or not(var185 = 1) or not(
var187 = 1) or not(var189 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var3 = 1) or not(var6 = 1) or not(var7 = 1) or not(var10 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var33 = 1) or not(var36 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var46 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var58 = 1) or not(var60 = 1) or not(var62 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var67 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var74 = 1) or not(var75 = 1) or not(var77 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var97 = 1) or not(
var100 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var110 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var122 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var131 = 1) or not(var134 = 1) or not(var135 = 1) or not(var138 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var161 = 1) or not(
var164 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var174 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var186 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var191 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var14 = 1) or not(var15 = 1) or not(var17 = 1) or not(var19 = 1) or not(
var22 = 1) or not(var24 = 1) or not(var26 = 1) or not(var27 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var38 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var43 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var51 = 1) or not(var53 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var78 = 1) or not(var79 = 1) or not(var81 =
1) or not(var83 = 1) or not(var86 = 1) or not(var88 = 1) or not(var90 = 1) or
not(var91 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var102 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var107 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var115 = 1) or not(var117 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var142 = 1) or not(var143 = 1) or not(var145 = 1) or not(
var147 = 1) or not(var150 = 1) or not(var152 = 1) or not(var154 = 1) or not(
var155 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var166 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var171 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var179 = 1) or not(var181 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var8 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var18 = 1) or not(var19 = 1) or not(
var21 = 1) or not(var24 = 1) or not(var25 = 1) or not(var27 = 1) or not(var29 =
1) or not(var31 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var41 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var49 = 1) or not(var52 = 1) or not(var54 = 1) or not(var55 =
1) or not(var58 = 1) or not(var59 = 1) or not(var62 = 1) or not(var64 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var72 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var82 =
1) or not(var83 = 1) or not(var85 = 1) or not(var88 = 1) or not(var89 = 1) or
not(var91 = 1) or not(var93 = 1) or not(var95 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var105 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var113 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var119 = 1) or not(var122 = 1) or not(
var123 = 1) or not(var126 = 1) or not(var128 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var136 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var146 = 1) or not(
var147 = 1) or not(var149 = 1) or not(var152 = 1) or not(var153 = 1) or not(
var155 = 1) or not(var157 = 1) or not(var159 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var169 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var177 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var183 = 1) or not(var186 = 1) or not(
var187 = 1) or not(var190 = 1) or not(var192 = 1)) and (not(var2 = 1) or not(
var4 = 1) or not(var6 = 1) or not(var7 = 1) or not(var9 = 1) or not(var11 = 1)
or not(var13 = 1) or not(var16 = 1) or not(var17 = 1) or not(var20 = 1) or not(
var21 = 1) or not(var23 = 1) or not(var26 = 1) or not(var28 = 1) or not(var30 =
1) or not(var32 = 1) or not(var34 = 1) or not(var35 = 1) or not(var37 = 1) or
not(var39 = 1) or not(var42 = 1) or not(var44 = 1) or not(var45 = 1) or not(
var48 = 1) or not(var50 = 1) or not(var52 = 1) or not(var54 = 1) or not(var56 =
1) or not(var57 = 1) or not(var60 = 1) or not(var61 = 1) or not(var63 = 1)) and
(not(var66 = 1) or not(var68 = 1) or not(var70 = 1) or not(var71 = 1) or not(
var73 = 1) or not(var75 = 1) or not(var77 = 1) or not(var80 = 1) or not(var81 =
1) or not(var84 = 1) or not(var85 = 1) or not(var87 = 1) or not(var90 = 1) or
not(var92 = 1) or not(var94 = 1) or not(var96 = 1) or not(var98 = 1) or not(
var99 = 1) or not(var101 = 1) or not(var103 = 1) or not(var106 = 1) or not(
var108 = 1) or not(var109 = 1) or not(var112 = 1) or not(var114 = 1) or not(
var116 = 1) or not(var118 = 1) or not(var120 = 1) or not(var121 = 1) or not(
var124 = 1) or not(var125 = 1) or not(var127 = 1)) and (not(var130 = 1) or not(
var132 = 1) or not(var134 = 1) or not(var135 = 1) or not(var137 = 1) or not(
var139 = 1) or not(var141 = 1) or not(var144 = 1) or not(var145 = 1) or not(
var148 = 1) or not(var149 = 1) or not(var151 = 1) or not(var154 = 1) or not(
var156 = 1) or not(var158 = 1) or not(var160 = 1) or not(var162 = 1) or not(
var163 = 1) or not(var165 = 1) or not(var167 = 1) or not(var170 = 1) or not(
var172 = 1) or not(var173 = 1) or not(var176 = 1) or not(var178 = 1) or not(
var180 = 1) or not(var182 = 1) or not(var184 = 1) or not(var185 = 1) or not(
var188 = 1) or not(var189 = 1) or not(var191 = 1)) and (var1 = 1 or not(var193 =
 1)) and (var4 = 1 or not(var193 = 1)) and (var5 = 1 or not(var193 = 1)) and (
var8 = 1 or not(var193 = 1)) and (var10 = 1 or not(var193 = 1)) and (var11 = 1
or not(var193 = 1)) and (var13 = 1 or not(var193 = 1)) and (var16 = 1 or not(
var193 = 1)) and (var17 = 1 or not(var193 = 1)) and (var20 = 1 or not(var193 = 1
)) and (var21 = 1 or not(var193 = 1)) and (var23 = 1 or not(var193 = 1)) and (
var26 = 1 or not(var193 = 1)) and (var28 = 1 or not(var193 = 1)) and (var30 = 1
or not(var193 = 1)) and (var32 = 1 or not(var193 = 1)) and (var34 = 1 or not(
var193 = 1)) and (var36 = 1 or not(var193 = 1)) and (var37 = 1 or not(var193 = 1
)) and (var40 = 1 or not(var193 = 1)) and (var41 = 1 or not(var193 = 1)) and (
var43 = 1 or not(var193 = 1)) and (var46 = 1 or not(var193 = 1)) and (var48 = 1
or not(var193 = 1)) and (var49 = 1 or not(var193 = 1)) and (var51 = 1 or not(
var193 = 1)) and (var54 = 1 or not(var193 = 1)) and (var55 = 1 or not(var193 = 1
)) and (var58 = 1 or not(var193 = 1)) and (var60 = 1 or not(var193 = 1)) and (
var61 = 1 or not(var193 = 1)) and (var63 = 1 or not(var193 = 1)) and (var65 = 1
or not(var194 = 1)) and (var68 = 1 or not(var194 = 1)) and (var69 = 1 or not(
var194 = 1)) and (var72 = 1 or not(var194 = 1)) and (var74 = 1 or not(var194 = 1
)) and (var75 = 1 or not(var194 = 1)) and (var77 = 1 or not(var194 = 1)) and (
var80 = 1 or not(var194 = 1)) and (var81 = 1 or not(var194 = 1)) and (var84 = 1
or not(var194 = 1)) and (var85 = 1 or not(var194 = 1)) and (var87 = 1 or not(
var194 = 1)) and (var90 = 1 or not(var194 = 1)) and (var92 = 1 or not(var194 = 1
)) and (var94 = 1 or not(var194 = 1)) and (var96 = 1 or not(var194 = 1)) and (
var98 = 1 or not(var194 = 1)) and (var100 = 1 or not(var194 = 1)) and (var101 =
1 or not(var194 = 1)) and (var104 = 1 or not(var194 = 1)) and (var105 = 1 or not
(var194 = 1)) and (var107 = 1 or not(var194 = 1)) and (var110 = 1 or not(var194
= 1)) and (var112 = 1 or not(var194 = 1)) and (var113 = 1 or not(var194 = 1))
and (var115 = 1 or not(var194 = 1)) and (var118 = 1 or not(var194 = 1)) and (
var119 = 1 or not(var194 = 1)) and (var122 = 1 or not(var194 = 1)) and (var124 =
 1 or not(var194 = 1)) and (var125 = 1 or not(var194 = 1)) and (var127 = 1 or
not(var194 = 1)) and (var129 = 1 or not(var195 = 1)) and (var132 = 1 or not(
var195 = 1)) and (var133 = 1 or not(var195 = 1)) and (var136 = 1 or not(var195 =
 1)) and (var138 = 1 or not(var195 = 1)) and (var139 = 1 or not(var195 = 1)) and
 (var141 = 1 or not(var195 = 1)) and (var144 = 1 or not(var195 = 1)) and (var145
 = 1 or not(var195 = 1)) and (var148 = 1 or not(var195 = 1)) and (var149 = 1 or
not(var195 = 1)) and (var151 = 1 or not(var195 = 1)) and (var154 = 1 or not(
var195 = 1)) and (var156 = 1 or not(var195 = 1)) and (var158 = 1 or not(var195 =
 1)) and (var160 = 1 or not(var195 = 1)) and (var162 = 1 or not(var195 = 1)) and
 (var164 = 1 or not(var195 = 1)) and (var165 = 1 or not(var195 = 1)) and (var168
 = 1 or not(var195 = 1)) and (var169 = 1 or not(var195 = 1)) and (var171 = 1 or
not(var195 = 1)) and (var174 = 1 or not(var195 = 1)) and (var176 = 1 or not(
var195 = 1)) and (var177 = 1 or not(var195 = 1)) and (var179 = 1 or not(var195 =
 1)) and (var182 = 1 or not(var195 = 1)) and (var183 = 1 or not(var195 = 1)) and
 (var186 = 1 or not(var195 = 1)) and (var188 = 1 or not(var195 = 1)) and (var189
 = 1 or not(var195 = 1)) and (var191 = 1 or not(var195 = 1)) and (var2 = 1 or
not(var196 = 1)) and (var4 = 1 or not(var196 = 1)) and (var6 = 1 or not(var196 =
 1)) and (var8 = 1 or not(var196 = 1)) and (var10 = 1 or not(var196 = 1)) and (
var12 = 1 or not(var196 = 1)) and (var13 = 1 or not(var196 = 1)) and (var15 = 1
or not(var196 = 1)) and (var18 = 1 or not(var196 = 1)) and (var19 = 1 or not(
var196 = 1)) and (var22 = 1 or not(var196 = 1)) and (var24 = 1 or not(var196 = 1
)) and (var25 = 1 or not(var196 = 1)) and (var28 = 1 or not(var196 = 1)) and (
var30 = 1 or not(var196 = 1)) and (var31 = 1 or not(var196 = 1)) and (var33 = 1
or not(var196 = 1)) and (var35 = 1 or not(var196 = 1)) and (var37 = 1 or not(
var196 = 1)) and (var40 = 1 or not(var196 = 1)) and (var41 = 1 or not(var196 = 1
)) and (var43 = 1 or not(var196 = 1)) and (var45 = 1 or not(var196 = 1)) and (
var48 = 1 or not(var196 = 1)) and (var49 = 1 or not(var196 = 1)) and (var52 = 1
or not(var196 = 1)) and (var54 = 1 or not(var196 = 1)) and (var56 = 1 or not(
var196 = 1)) and (var58 = 1 or not(var196 = 1)) and (var60 = 1 or not(var196 = 1
)) and (var61 = 1 or not(var196 = 1)) and (var63 = 1 or not(var196 = 1)) and (
var66 = 1 or not(var197 = 1)) and (var68 = 1 or not(var197 = 1)) and (var70 = 1
or not(var197 = 1)) and (var72 = 1 or not(var197 = 1)) and (var74 = 1 or not(
var197 = 1)) and (var76 = 1 or not(var197 = 1)) and (var77 = 1 or not(var197 = 1
)) and (var79 = 1 or not(var197 = 1)) and (var82 = 1 or not(var197 = 1)) and (
var83 = 1 or not(var197 = 1)) and (var86 = 1 or not(var197 = 1)) and (var88 = 1
or not(var197 = 1)) and (var89 = 1 or not(var197 = 1)) and (var92 = 1 or not(
var197 = 1)) and (var94 = 1 or not(var197 = 1)) and (var95 = 1 or not(var197 = 1
)) and (var97 = 1 or not(var197 = 1)) and (var99 = 1 or not(var197 = 1)) and (
var101 = 1 or not(var197 = 1)) and (var104 = 1 or not(var197 = 1)) and (var105 =
 1 or not(var197 = 1)) and (var107 = 1 or not(var197 = 1)) and (var109 = 1 or
not(var197 = 1)) and (var112 = 1 or not(var197 = 1)) and (var113 = 1 or not(
var197 = 1)) and (var116 = 1 or not(var197 = 1)) and (var118 = 1 or not(var197 =
 1)) and (var120 = 1 or not(var197 = 1)) and (var122 = 1 or not(var197 = 1)) and
 (var124 = 1 or not(var197 = 1)) and (var125 = 1 or not(var197 = 1)) and (var127
 = 1 or not(var197 = 1)) and (var130 = 1 or not(var198 = 1)) and (var132 = 1 or
not(var198 = 1)) and (var134 = 1 or not(var198 = 1)) and (var136 = 1 or not(
var198 = 1)) and (var138 = 1 or not(var198 = 1)) and (var140 = 1 or not(var198 =
 1)) and (var141 = 1 or not(var198 = 1)) and (var143 = 1 or not(var198 = 1)) and
 (var146 = 1 or not(var198 = 1)) and (var147 = 1 or not(var198 = 1)) and (var150
 = 1 or not(var198 = 1)) and (var152 = 1 or not(var198 = 1)) and (var153 = 1 or
not(var198 = 1)) and (var156 = 1 or not(var198 = 1)) and (var158 = 1 or not(
var198 = 1)) and (var159 = 1 or not(var198 = 1)) and (var161 = 1 or not(var198 =
 1)) and (var163 = 1 or not(var198 = 1)) and (var165 = 1 or not(var198 = 1)) and
 (var168 = 1 or not(var198 = 1)) and (var169 = 1 or not(var198 = 1)) and (var171
 = 1 or not(var198 = 1)) and (var173 = 1 or not(var198 = 1)) and (var176 = 1 or
not(var198 = 1)) and (var177 = 1 or not(var198 = 1)) and (var180 = 1 or not(
var198 = 1)) and (var182 = 1 or not(var198 = 1)) and (var184 = 1 or not(var198 =
 1)) and (var186 = 1 or not(var198 = 1)) and (var188 = 1 or not(var198 = 1)) and
 (var189 = 1 or not(var198 = 1)) and (var191 = 1 or not(var198 = 1)) and (var2 =
 1 or not(var199 = 1)) and (var3 = 1 or not(var199 = 1)) and (var6 = 1 or not(
var199 = 1)) and (var7 = 1 or not(var199 = 1)) and (var9 = 1 or not(var199 = 1))
 and (var12 = 1 or not(var199 = 1)) and (var14 = 1 or not(var199 = 1)) and (
var16 = 1 or not(var199 = 1)) and (var18 = 1 or not(var199 = 1)) and (var20 = 1
or not(var199 = 1)) and (var21 = 1 or not(var199 = 1)) and (var24 = 1 or not(
var199 = 1)) and (var25 = 1 or not(var199 = 1)) and (var27 = 1 or not(var199 = 1
)) and (var29 = 1 or not(var199 = 1)) and (var32 = 1 or not(var199 = 1)) and (
var33 = 1 or not(var199 = 1)) and (var35 = 1 or not(var199 = 1)) and (var37 = 1
or not(var199 = 1)) and (var39 = 1 or not(var199 = 1)) and (var41 = 1 or not(
var199 = 1)) and (var43 = 1 or not(var199 = 1)) and (var46 = 1 or not(var199 = 1
)) and (var47 = 1 or not(var199 = 1)) and (var50 = 1 or not(var199 = 1)) and (
var51 = 1 or not(var199 = 1)) and (var53 = 1 or not(var199 = 1)) and (var56 = 1
or not(var199 = 1)) and (var58 = 1 or not(var199 = 1)) and (var60 = 1 or not(
var199 = 1)) and (var61 = 1 or not(var199 = 1)) and (var64 = 1 or not(var199 = 1
)) and (var66 = 1 or not(var200 = 1)) and (var67 = 1 or not(var200 = 1)) and (
var70 = 1 or not(var200 = 1)) and (var71 = 1 or not(var200 = 1)) and (var73 = 1
or not(var200 = 1)) and (var76 = 1 or not(var200 = 1)) and (var78 = 1 or not(
var200 = 1)) and (var80 = 1 or not(var200 = 1)) and (var82 = 1 or not(var200 = 1
)) and (var84 = 1 or not(var200 = 1)) and (var85 = 1 or not(var200 = 1)) and (
var88 = 1 or not(var200 = 1)) and (var89 = 1 or not(var200 = 1)) and (var91 = 1
or not(var200 = 1)) and (var93 = 1 or not(var200 = 1)) and (var96 = 1 or not(
var200 = 1)) and (var97 = 1 or not(var200 = 1)) and (var99 = 1 or not(var200 = 1
)) and (var101 = 1 or not(var200 = 1)) and (var103 = 1 or not(var200 = 1)) and (
var105 = 1 or not(var200 = 1)) and (var107 = 1 or not(var200 = 1)) and (var110 =
 1 or not(var200 = 1)) and (var111 = 1 or not(var200 = 1)) and (var114 = 1 or
not(var200 = 1)) and (var115 = 1 or not(var200 = 1)) and (var117 = 1 or not(
var200 = 1)) and (var120 = 1 or not(var200 = 1)) and (var122 = 1 or not(var200 =
 1)) and (var124 = 1 or not(var200 = 1)) and (var125 = 1 or not(var200 = 1)) and
 (var128 = 1 or not(var200 = 1)) and (var130 = 1 or not(var201 = 1)) and (var131
 = 1 or not(var201 = 1)) and (var134 = 1 or not(var201 = 1)) and (var135 = 1 or
not(var201 = 1)) and (var137 = 1 or not(var201 = 1)) and (var140 = 1 or not(
var201 = 1)) and (var142 = 1 or not(var201 = 1)) and (var144 = 1 or not(var201 =
 1)) and (var146 = 1 or not(var201 = 1)) and (var148 = 1 or not(var201 = 1)) and
 (var149 = 1 or not(var201 = 1)) and (var152 = 1 or not(var201 = 1)) and (var153
 = 1 or not(var201 = 1)) and (var155 = 1 or not(var201 = 1)) and (var157 = 1 or
not(var201 = 1)) and (var160 = 1 or not(var201 = 1)) and (var161 = 1 or not(
var201 = 1)) and (var163 = 1 or not(var201 = 1)) and (var165 = 1 or not(var201 =
 1)) and (var167 = 1 or not(var201 = 1)) and (var169 = 1 or not(var201 = 1)) and
 (var171 = 1 or not(var201 = 1)) and (var174 = 1 or not(var201 = 1)) and (var175
 = 1 or not(var201 = 1)) and (var178 = 1 or not(var201 = 1)) and (var179 = 1 or
not(var201 = 1)) and (var181 = 1 or not(var201 = 1)) and (var184 = 1 or not(
var201 = 1)) and (var186 = 1 or not(var201 = 1)) and (var188 = 1 or not(var201 =
 1)) and (var189 = 1 or not(var201 = 1)) and (var192 = 1 or not(var201 = 1)) and
 (var1 = 1 or not(var202 = 1)) and (var4 = 1 or not(var202 = 1)) and (var6 = 1
or not(var202 = 1)) and (var7 = 1 or not(var202 = 1)) and (var10 = 1 or not(
var202 = 1)) and (var12 = 1 or not(var202 = 1)) and (var13 = 1 or not(var202 = 1
)) and (var15 = 1 or not(var202 = 1)) and (var17 = 1 or not(var202 = 1)) and (
var19 = 1 or not(var202 = 1)) and (var21 = 1 or not(var202 = 1)) and (var24 = 1
or not(var202 = 1)) and (var25 = 1 or not(var202 = 1)) and (var28 = 1 or not(
var202 = 1)) and (var30 = 1 or not(var202 = 1)) and (var32 = 1 or not(var202 = 1
)) and (var34 = 1 or not(var202 = 1)) and (var36 = 1 or not(var202 = 1)) and (
var37 = 1 or not(var202 = 1)) and (var39 = 1 or not(var202 = 1)) and (var42 = 1
or not(var202 = 1)) and (var44 = 1 or not(var202 = 1)) and (var46 = 1 or not(
var202 = 1)) and (var47 = 1 or not(var202 = 1)) and (var49 = 1 or not(var202 = 1
)) and (var51 = 1 or not(var202 = 1)) and (var53 = 1 or not(var202 = 1)) and (
var55 = 1 or not(var202 = 1)) and (var58 = 1 or not(var202 = 1)) and (var59 = 1
or not(var202 = 1)) and (var61 = 1 or not(var202 = 1)) and (var64 = 1 or not(
var202 = 1)) and (var65 = 1 or not(var203 = 1)) and (var68 = 1 or not(var203 = 1
)) and (var70 = 1 or not(var203 = 1)) and (var71 = 1 or not(var203 = 1)) and (
var74 = 1 or not(var203 = 1)) and (var76 = 1 or not(var203 = 1)) and (var77 = 1
or not(var203 = 1)) and (var79 = 1 or not(var203 = 1)) and (var81 = 1 or not(
var203 = 1)) and (var83 = 1 or not(var203 = 1)) and (var85 = 1 or not(var203 = 1
)) and (var88 = 1 or not(var203 = 1)) and (var89 = 1 or not(var203 = 1)) and (
var92 = 1 or not(var203 = 1)) and (var94 = 1 or not(var203 = 1)) and (var96 = 1
or not(var203 = 1)) and (var98 = 1 or not(var203 = 1)) and (var100 = 1 or not(
var203 = 1)) and (var101 = 1 or not(var203 = 1)) and (var103 = 1 or not(var203 =
 1)) and (var106 = 1 or not(var203 = 1)) and (var108 = 1 or not(var203 = 1)) and
 (var110 = 1 or not(var203 = 1)) and (var111 = 1 or not(var203 = 1)) and (var113
 = 1 or not(var203 = 1)) and (var115 = 1 or not(var203 = 1)) and (var117 = 1 or
not(var203 = 1)) and (var119 = 1 or not(var203 = 1)) and (var122 = 1 or not(
var203 = 1)) and (var123 = 1 or not(var203 = 1)) and (var125 = 1 or not(var203 =
 1)) and (var128 = 1 or not(var203 = 1)) and (var129 = 1 or not(var204 = 1)) and
 (var132 = 1 or not(var204 = 1)) and (var134 = 1 or not(var204 = 1)) and (var135
 = 1 or not(var204 = 1)) and (var138 = 1 or not(var204 = 1)) and (var140 = 1 or
not(var204 = 1)) and (var141 = 1 or not(var204 = 1)) and (var143 = 1 or not(
var204 = 1)) and (var145 = 1 or not(var204 = 1)) and (var147 = 1 or not(var204 =
 1)) and (var149 = 1 or not(var204 = 1)) and (var152 = 1 or not(var204 = 1)) and
 (var153 = 1 or not(var204 = 1)) and (var156 = 1 or not(var204 = 1)) and (var158
 = 1 or not(var204 = 1)) and (var160 = 1 or not(var204 = 1)) and (var162 = 1 or
not(var204 = 1)) and (var164 = 1 or not(var204 = 1)) and (var165 = 1 or not(
var204 = 1)) and (var167 = 1 or not(var204 = 1)) and (var170 = 1 or not(var204 =
 1)) and (var172 = 1 or not(var204 = 1)) and (var174 = 1 or not(var204 = 1)) and
 (var175 = 1 or not(var204 = 1)) and (var177 = 1 or not(var204 = 1)) and (var179
 = 1 or not(var204 = 1)) and (var181 = 1 or not(var204 = 1)) and (var183 = 1 or
not(var204 = 1)) and (var186 = 1 or not(var204 = 1)) and (var187 = 1 or not(
var204 = 1)) and (var189 = 1 or not(var204 = 1)) and (var192 = 1 or not(var204 =
 1)) and (var2 = 1 or not(var205 = 1)) and (var4 = 1 or not(var205 = 1)) and (
var6 = 1 or not(var205 = 1)) and (var7 = 1 or not(var205 = 1)) and (var10 = 1 or
 not(var205 = 1)) and (var12 = 1 or not(var205 = 1)) and (var14 = 1 or not(
var205 = 1)) and (var16 = 1 or not(var205 = 1)) and (var18 = 1 or not(var205 = 1
)) and (var20 = 1 or not(var205 = 1)) and (var21 = 1 or not(var205 = 1)) and (
var24 = 1 or not(var205 = 1)) and (var25 = 1 or not(var205 = 1)) and (var28 = 1
or not(var205 = 1)) and (var30 = 1 or not(var205 = 1)) and (var31 = 1 or not(
var205 = 1)) and (var33 = 1 or not(var205 = 1)) and (var35 = 1 or not(var205 = 1
)) and (var37 = 1 or not(var205 = 1)) and (var40 = 1 or not(var205 = 1)) and (
var42 = 1 or not(var205 = 1)) and (var44 = 1 or not(var205 = 1)) and (var46 = 1
or not(var205 = 1)) and (var48 = 1 or not(var205 = 1)) and (var50 = 1 or not(
var205 = 1)) and (var52 = 1 or not(var205 = 1)) and (var54 = 1 or not(var205 = 1
)) and (var56 = 1 or not(var205 = 1)) and (var58 = 1 or not(var205 = 1)) and (
var59 = 1 or not(var205 = 1)) and (var61 = 1 or not(var205 = 1)) and (var63 = 1
or not(var205 = 1)) and (var66 = 1 or not(var206 = 1)) and (var68 = 1 or not(
var206 = 1)) and (var70 = 1 or not(var206 = 1)) and (var71 = 1 or not(var206 = 1
)) and (var74 = 1 or not(var206 = 1)) and (var76 = 1 or not(var206 = 1)) and (
var78 = 1 or not(var206 = 1)) and (var80 = 1 or not(var206 = 1)) and (var82 = 1
or not(var206 = 1)) and (var84 = 1 or not(var206 = 1)) and (var85 = 1 or not(
var206 = 1)) and (var88 = 1 or not(var206 = 1)) and (var89 = 1 or not(var206 = 1
)) and (var92 = 1 or not(var206 = 1)) and (var94 = 1 or not(var206 = 1)) and (
var95 = 1 or not(var206 = 1)) and (var97 = 1 or not(var206 = 1)) and (var99 = 1
or not(var206 = 1)) and (var101 = 1 or not(var206 = 1)) and (var104 = 1 or not(
var206 = 1)) and (var106 = 1 or not(var206 = 1)) and (var108 = 1 or not(var206 =
 1)) and (var110 = 1 or not(var206 = 1)) and (var112 = 1 or not(var206 = 1)) and
 (var114 = 1 or not(var206 = 1)) and (var116 = 1 or not(var206 = 1)) and (var118
 = 1 or not(var206 = 1)) and (var120 = 1 or not(var206 = 1)) and (var122 = 1 or
not(var206 = 1)) and (var123 = 1 or not(var206 = 1)) and (var125 = 1 or not(
var206 = 1)) and (var127 = 1 or not(var206 = 1)) and (var130 = 1 or not(var207 =
 1)) and (var132 = 1 or not(var207 = 1)) and (var134 = 1 or not(var207 = 1)) and
 (var135 = 1 or not(var207 = 1)) and (var138 = 1 or not(var207 = 1)) and (var140
 = 1 or not(var207 = 1)) and (var142 = 1 or not(var207 = 1)) and (var144 = 1 or
not(var207 = 1)) and (var146 = 1 or not(var207 = 1)) and (var148 = 1 or not(
var207 = 1)) and (var149 = 1 or not(var207 = 1)) and (var152 = 1 or not(var207 =
 1)) and (var153 = 1 or not(var207 = 1)) and (var156 = 1 or not(var207 = 1)) and
 (var158 = 1 or not(var207 = 1)) and (var159 = 1 or not(var207 = 1)) and (var161
 = 1 or not(var207 = 1)) and (var163 = 1 or not(var207 = 1)) and (var165 = 1 or
not(var207 = 1)) and (var168 = 1 or not(var207 = 1)) and (var170 = 1 or not(
var207 = 1)) and (var172 = 1 or not(var207 = 1)) and (var174 = 1 or not(var207 =
 1)) and (var176 = 1 or not(var207 = 1)) and (var178 = 1 or not(var207 = 1)) and
 (var180 = 1 or not(var207 = 1)) and (var182 = 1 or not(var207 = 1)) and (var184
 = 1 or not(var207 = 1)) and (var186 = 1 or not(var207 = 1)) and (var187 = 1 or
not(var207 = 1)) and (var189 = 1 or not(var207 = 1)) and (var191 = 1 or not(
var207 = 1)) and (var1 = 1 or not(var208 = 1)) and (var4 = 1 or not(var208 = 1))
 and (var5 = 1 or not(var208 = 1)) and (var8 = 1 or not(var208 = 1)) and (var10
= 1 or not(var208 = 1)) and (var12 = 1 or not(var208 = 1)) and (var14 = 1 or not
(var208 = 1)) and (var15 = 1 or not(var208 = 1)) and (var17 = 1 or not(var208 =
1)) and (var19 = 1 or not(var208 = 1)) and (var21 = 1 or not(var208 = 1)) and (
var24 = 1 or not(var208 = 1)) and (var26 = 1 or not(var208 = 1)) and (var28 = 1
or not(var208 = 1)) and (var29 = 1 or not(var208 = 1)) and (var31 = 1 or not(
var208 = 1)) and (var34 = 1 or not(var208 = 1)) and (var36 = 1 or not(var208 = 1
)) and (var38 = 1 or not(var208 = 1)) and (var40 = 1 or not(var208 = 1)) and (
var41 = 1 or not(var208 = 1)) and (var43 = 1 or not(var208 = 1)) and (var46 = 1
or not(var208 = 1)) and (var47 = 1 or not(var208 = 1)) and (var50 = 1 or not(
var208 = 1)) and (var51 = 1 or not(var208 = 1)) and (var54 = 1 or not(var208 = 1
)) and (var56 = 1 or not(var208 = 1)) and (var58 = 1 or not(var208 = 1)) and (
var60 = 1 or not(var208 = 1)) and (var61 = 1 or not(var208 = 1)) and (var64 = 1
or not(var208 = 1)) and (var65 = 1 or not(var209 = 1)) and (var68 = 1 or not(
var209 = 1)) and (var69 = 1 or not(var209 = 1)) and (var72 = 1 or not(var209 = 1
)) and (var74 = 1 or not(var209 = 1)) and (var76 = 1 or not(var209 = 1)) and (
var78 = 1 or not(var209 = 1)) and (var79 = 1 or not(var209 = 1)) and (var81 = 1
or not(var209 = 1)) and (var83 = 1 or not(var209 = 1)) and (var85 = 1 or not(
var209 = 1)) and (var88 = 1 or not(var209 = 1)) and (var90 = 1 or not(var209 = 1
)) and (var92 = 1 or not(var209 = 1)) and (var93 = 1 or not(var209 = 1)) and (
var95 = 1 or not(var209 = 1)) and (var98 = 1 or not(var209 = 1)) and (var100 = 1
 or not(var209 = 1)) and (var102 = 1 or not(var209 = 1)) and (var104 = 1 or not(
var209 = 1)) and (var105 = 1 or not(var209 = 1)) and (var107 = 1 or not(var209 =
 1)) and (var110 = 1 or not(var209 = 1)) and (var111 = 1 or not(var209 = 1)) and
 (var114 = 1 or not(var209 = 1)) and (var115 = 1 or not(var209 = 1)) and (var118
 = 1 or not(var209 = 1)) and (var120 = 1 or not(var209 = 1)) and (var122 = 1 or
not(var209 = 1)) and (var124 = 1 or not(var209 = 1)) and (var125 = 1 or not(
var209 = 1)) and (var128 = 1 or not(var209 = 1)) and (var129 = 1 or not(var210 =
 1)) and (var132 = 1 or not(var210 = 1)) and (var133 = 1 or not(var210 = 1)) and
 (var136 = 1 or not(var210 = 1)) and (var138 = 1 or not(var210 = 1)) and (var140
 = 1 or not(var210 = 1)) and (var142 = 1 or not(var210 = 1)) and (var143 = 1 or
not(var210 = 1)) and (var145 = 1 or not(var210 = 1)) and (var147 = 1 or not(
var210 = 1)) and (var149 = 1 or not(var210 = 1)) and (var152 = 1 or not(var210 =
 1)) and (var154 = 1 or not(var210 = 1)) and (var156 = 1 or not(var210 = 1)) and
 (var157 = 1 or not(var210 = 1)) and (var159 = 1 or not(var210 = 1)) and (var162
 = 1 or not(var210 = 1)) and (var164 = 1 or not(var210 = 1)) and (var166 = 1 or
not(var210 = 1)) and (var168 = 1 or not(var210 = 1)) and (var169 = 1 or not(
var210 = 1)) and (var171 = 1 or not(var210 = 1)) and (var174 = 1 or not(var210 =
 1)) and (var175 = 1 or not(var210 = 1)) and (var178 = 1 or not(var210 = 1)) and
 (var179 = 1 or not(var210 = 1)) and (var182 = 1 or not(var210 = 1)) and (var184
 = 1 or not(var210 = 1)) and (var186 = 1 or not(var210 = 1)) and (var188 = 1 or
not(var210 = 1)) and (var189 = 1 or not(var210 = 1)) and (var192 = 1 or not(
var210 = 1)) and (var1 = 1 or not(var211 = 1)) and (var4 = 1 or not(var211 = 1))
 and (var5 = 1 or not(var211 = 1)) and (var8 = 1 or not(var211 = 1)) and (var10
= 1 or not(var211 = 1)) and (var12 = 1 or not(var211 = 1)) and (var13 = 1 or not
(var211 = 1)) and (var16 = 1 or not(var211 = 1)) and (var18 = 1 or not(var211 =
1)) and (var19 = 1 or not(var211 = 1)) and (var21 = 1 or not(var211 = 1)) and (
var24 = 1 or not(var211 = 1)) and (var26 = 1 or not(var211 = 1)) and (var27 = 1
or not(var211 = 1)) and (var30 = 1 or not(var211 = 1)) and (var31 = 1 or not(
var211 = 1)) and (var34 = 1 or not(var211 = 1)) and (var36 = 1 or not(var211 = 1
)) and (var37 = 1 or not(var211 = 1)) and (var39 = 1 or not(var211 = 1)) and (
var41 = 1 or not(var211 = 1)) and (var44 = 1 or not(var211 = 1)) and (var45 = 1
or not(var211 = 1)) and (var48 = 1 or not(var211 = 1)) and (var50 = 1 or not(
var211 = 1)) and (var51 = 1 or not(var211 = 1)) and (var53 = 1 or not(var211 = 1
)) and (var55 = 1 or not(var211 = 1)) and (var58 = 1 or not(var211 = 1)) and (
var60 = 1 or not(var211 = 1)) and (var61 = 1 or not(var211 = 1)) and (var63 = 1
or not(var211 = 1)) and (var65 = 1 or not(var212 = 1)) and (var68 = 1 or not(
var212 = 1)) and (var69 = 1 or not(var212 = 1)) and (var72 = 1 or not(var212 = 1
)) and (var74 = 1 or not(var212 = 1)) and (var76 = 1 or not(var212 = 1)) and (
var77 = 1 or not(var212 = 1)) and (var80 = 1 or not(var212 = 1)) and (var82 = 1
or not(var212 = 1)) and (var83 = 1 or not(var212 = 1)) and (var85 = 1 or not(
var212 = 1)) and (var88 = 1 or not(var212 = 1)) and (var90 = 1 or not(var212 = 1
)) and (var91 = 1 or not(var212 = 1)) and (var94 = 1 or not(var212 = 1)) and (
var95 = 1 or not(var212 = 1)) and (var98 = 1 or not(var212 = 1)) and (var100 = 1
 or not(var212 = 1)) and (var101 = 1 or not(var212 = 1)) and (var103 = 1 or not(
var212 = 1)) and (var105 = 1 or not(var212 = 1)) and (var108 = 1 or not(var212 =
 1)) and (var109 = 1 or not(var212 = 1)) and (var112 = 1 or not(var212 = 1)) and
 (var114 = 1 or not(var212 = 1)) and (var115 = 1 or not(var212 = 1)) and (var117
 = 1 or not(var212 = 1)) and (var119 = 1 or not(var212 = 1)) and (var122 = 1 or
not(var212 = 1)) and (var124 = 1 or not(var212 = 1)) and (var125 = 1 or not(
var212 = 1)) and (var127 = 1 or not(var212 = 1)) and (var129 = 1 or not(var213 =
 1)) and (var132 = 1 or not(var213 = 1)) and (var133 = 1 or not(var213 = 1)) and
 (var136 = 1 or not(var213 = 1)) and (var138 = 1 or not(var213 = 1)) and (var140
 = 1 or not(var213 = 1)) and (var141 = 1 or not(var213 = 1)) and (var144 = 1 or
not(var213 = 1)) and (var146 = 1 or not(var213 = 1)) and (var147 = 1 or not(
var213 = 1)) and (var149 = 1 or not(var213 = 1)) and (var152 = 1 or not(var213 =
 1)) and (var154 = 1 or not(var213 = 1)) and (var155 = 1 or not(var213 = 1)) and
 (var158 = 1 or not(var213 = 1)) and (var159 = 1 or not(var213 = 1)) and (var162
 = 1 or not(var213 = 1)) and (var164 = 1 or not(var213 = 1)) and (var165 = 1 or
not(var213 = 1)) and (var167 = 1 or not(var213 = 1)) and (var169 = 1 or not(
var213 = 1)) and (var172 = 1 or not(var213 = 1)) and (var173 = 1 or not(var213 =
 1)) and (var176 = 1 or not(var213 = 1)) and (var178 = 1 or not(var213 = 1)) and
 (var179 = 1 or not(var213 = 1)) and (var181 = 1 or not(var213 = 1)) and (var183
 = 1 or not(var213 = 1)) and (var186 = 1 or not(var213 = 1)) and (var188 = 1 or
not(var213 = 1)) and (var189 = 1 or not(var213 = 1)) and (var191 = 1 or not(
var213 = 1)) and (var2 = 1 or not(var214 = 1)) and (var4 = 1 or not(var214 = 1))
 and (var6 = 1 or not(var214 = 1)) and (var8 = 1 or not(var214 = 1)) and (var10
= 1 or not(var214 = 1)) and (var12 = 1 or not(var214 = 1)) and (var13 = 1 or not
(var214 = 1)) and (var15 = 1 or not(var214 = 1)) and (var17 = 1 or not(var214 =
1)) and (var19 = 1 or not(var214 = 1)) and (var21 = 1 or not(var214 = 1)) and (
var23 = 1 or not(var214 = 1)) and (var25 = 1 or not(var214 = 1)) and (var27 = 1
or not(var214 = 1)) and (var30 = 1 or not(var214 = 1)) and (var32 = 1 or not(
var214 = 1)) and (var33 = 1 or not(var214 = 1)) and (var35 = 1 or not(var214 = 1
)) and (var38 = 1 or not(var214 = 1)) and (var40 = 1 or not(var214 = 1)) and (
var42 = 1 or not(var214 = 1)) and (var43 = 1 or not(var214 = 1)) and (var46 = 1
or not(var214 = 1)) and (var47 = 1 or not(var214 = 1)) and (var50 = 1 or not(
var214 = 1)) and (var51 = 1 or not(var214 = 1)) and (var54 = 1 or not(var214 = 1
)) and (var56 = 1 or not(var214 = 1)) and (var58 = 1 or not(var214 = 1)) and (
var59 = 1 or not(var214 = 1)) and (var61 = 1 or not(var214 = 1)) and (var64 = 1
or not(var214 = 1)) and (var66 = 1 or not(var215 = 1)) and (var68 = 1 or not(
var215 = 1)) and (var70 = 1 or not(var215 = 1)) and (var72 = 1 or not(var215 = 1
)) and (var74 = 1 or not(var215 = 1)) and (var76 = 1 or not(var215 = 1)) and (
var77 = 1 or not(var215 = 1)) and (var79 = 1 or not(var215 = 1)) and (var81 = 1
or not(var215 = 1)) and (var83 = 1 or not(var215 = 1)) and (var85 = 1 or not(
var215 = 1)) and (var87 = 1 or not(var215 = 1)) and (var89 = 1 or not(var215 = 1
)) and (var91 = 1 or not(var215 = 1)) and (var94 = 1 or not(var215 = 1)) and (
var96 = 1 or not(var215 = 1)) and (var97 = 1 or not(var215 = 1)) and (var99 = 1
or not(var215 = 1)) and (var102 = 1 or not(var215 = 1)) and (var104 = 1 or not(
var215 = 1)) and (var106 = 1 or not(var215 = 1)) and (var107 = 1 or not(var215 =
 1)) and (var110 = 1 or not(var215 = 1)) and (var111 = 1 or not(var215 = 1)) and
 (var114 = 1 or not(var215 = 1)) and (var115 = 1 or not(var215 = 1)) and (var118
 = 1 or not(var215 = 1)) and (var120 = 1 or not(var215 = 1)) and (var122 = 1 or
not(var215 = 1)) and (var123 = 1 or not(var215 = 1)) and (var125 = 1 or not(
var215 = 1)) and (var128 = 1 or not(var215 = 1)) and (var130 = 1 or not(var216 =
 1)) and (var132 = 1 or not(var216 = 1)) and (var134 = 1 or not(var216 = 1)) and
 (var136 = 1 or not(var216 = 1)) and (var138 = 1 or not(var216 = 1)) and (var140
 = 1 or not(var216 = 1)) and (var141 = 1 or not(var216 = 1)) and (var143 = 1 or
not(var216 = 1)) and (var145 = 1 or not(var216 = 1)) and (var147 = 1 or not(
var216 = 1)) and (var149 = 1 or not(var216 = 1)) and (var151 = 1 or not(var216 =
 1)) and (var153 = 1 or not(var216 = 1)) and (var155 = 1 or not(var216 = 1)) and
 (var158 = 1 or not(var216 = 1)) and (var160 = 1 or not(var216 = 1)) and (var161
 = 1 or not(var216 = 1)) and (var163 = 1 or not(var216 = 1)) and (var166 = 1 or
not(var216 = 1)) and (var168 = 1 or not(var216 = 1)) and (var170 = 1 or not(
var216 = 1)) and (var171 = 1 or not(var216 = 1)) and (var174 = 1 or not(var216 =
 1)) and (var175 = 1 or not(var216 = 1)) and (var178 = 1 or not(var216 = 1)) and
 (var179 = 1 or not(var216 = 1)) and (var182 = 1 or not(var216 = 1)) and (var184
 = 1 or not(var216 = 1)) and (var186 = 1 or not(var216 = 1)) and (var187 = 1 or
not(var216 = 1)) and (var189 = 1 or not(var216 = 1)) and (var192 = 1 or not(
var216 = 1)) and (var2 = 1 or not(var217 = 1)) and (var4 = 1 or not(var217 = 1))
 and (var6 = 1 or not(var217 = 1)) and (var7 = 1 or not(var217 = 1)) and (var10
= 1 or not(var217 = 1)) and (var11 = 1 or not(var217 = 1)) and (var13 = 1 or not
(var217 = 1)) and (var15 = 1 or not(var217 = 1)) and (var18 = 1 or not(var217 =
1)) and (var19 = 1 or not(var217 = 1)) and (var21 = 1 or not(var217 = 1)) and (
var24 = 1 or not(var217 = 1)) and (var25 = 1 or not(var217 = 1)) and (var27 = 1
or not(var217 = 1)) and (var29 = 1 or not(var217 = 1)) and (var32 = 1 or not(
var217 = 1)) and (var33 = 1 or not(var217 = 1)) and (var36 = 1 or not(var217 = 1
)) and (var37 = 1 or not(var217 = 1)) and (var40 = 1 or not(var217 = 1)) and (
var42 = 1 or not(var217 = 1)) and (var43 = 1 or not(var217 = 1)) and (var45 = 1
or not(var217 = 1)) and (var47 = 1 or not(var217 = 1)) and (var49 = 1 or not(
var217 = 1)) and (var51 = 1 or not(var217 = 1)) and (var53 = 1 or not(var217 = 1
)) and (var56 = 1 or not(var217 = 1)) and (var58 = 1 or not(var217 = 1)) and (
var60 = 1 or not(var217 = 1)) and (var61 = 1 or not(var217 = 1)) and (var64 = 1
or not(var217 = 1)) and (var66 = 1 or not(var218 = 1)) and (var68 = 1 or not(
var218 = 1)) and (var70 = 1 or not(var218 = 1)) and (var71 = 1 or not(var218 = 1
)) and (var74 = 1 or not(var218 = 1)) and (var75 = 1 or not(var218 = 1)) and (
var77 = 1 or not(var218 = 1)) and (var79 = 1 or not(var218 = 1)) and (var82 = 1
or not(var218 = 1)) and (var83 = 1 or not(var218 = 1)) and (var85 = 1 or not(
var218 = 1)) and (var88 = 1 or not(var218 = 1)) and (var89 = 1 or not(var218 = 1
)) and (var91 = 1 or not(var218 = 1)) and (var93 = 1 or not(var218 = 1)) and (
var96 = 1 or not(var218 = 1)) and (var97 = 1 or not(var218 = 1)) and (var100 = 1
 or not(var218 = 1)) and (var101 = 1 or not(var218 = 1)) and (var104 = 1 or not(
var218 = 1)) and (var106 = 1 or not(var218 = 1)) and (var107 = 1 or not(var218 =
 1)) and (var109 = 1 or not(var218 = 1)) and (var111 = 1 or not(var218 = 1)) and
 (var113 = 1 or not(var218 = 1)) and (var115 = 1 or not(var218 = 1)) and (var117
 = 1 or not(var218 = 1)) and (var120 = 1 or not(var218 = 1)) and (var122 = 1 or
not(var218 = 1)) and (var124 = 1 or not(var218 = 1)) and (var125 = 1 or not(
var218 = 1)) and (var128 = 1 or not(var218 = 1)) and (var130 = 1 or not(var219 =
 1)) and (var132 = 1 or not(var219 = 1)) and (var134 = 1 or not(var219 = 1)) and
 (var135 = 1 or not(var219 = 1)) and (var138 = 1 or not(var219 = 1)) and (var139
 = 1 or not(var219 = 1)) and (var141 = 1 or not(var219 = 1)) and (var143 = 1 or
not(var219 = 1)) and (var146 = 1 or not(var219 = 1)) and (var147 = 1 or not(
var219 = 1)) and (var149 = 1 or not(var219 = 1)) and (var152 = 1 or not(var219 =
 1)) and (var153 = 1 or not(var219 = 1)) and (var155 = 1 or not(var219 = 1)) and
 (var157 = 1 or not(var219 = 1)) and (var160 = 1 or not(var219 = 1)) and (var161
 = 1 or not(var219 = 1)) and (var164 = 1 or not(var219 = 1)) and (var165 = 1 or
not(var219 = 1)) and (var168 = 1 or not(var219 = 1)) and (var170 = 1 or not(
var219 = 1)) and (var171 = 1 or not(var219 = 1)) and (var173 = 1 or not(var219 =
 1)) and (var175 = 1 or not(var219 = 1)) and (var177 = 1 or not(var219 = 1)) and
 (var179 = 1 or not(var219 = 1)) and (var181 = 1 or not(var219 = 1)) and (var184
 = 1 or not(var219 = 1)) and (var186 = 1 or not(var219 = 1)) and (var188 = 1 or
not(var219 = 1)) and (var189 = 1 or not(var219 = 1)) and (var192 = 1 or not(
var219 = 1)) and (var2 = 1 or not(var220 = 1)) and (var4 = 1 or not(var220 = 1))
 and (var6 = 1 or not(var220 = 1)) and (var8 = 1 or not(var220 = 1)) and (var10
= 1 or not(var220 = 1)) and (var12 = 1 or not(var220 = 1)) and (var14 = 1 or not
(var220 = 1)) and (var15 = 1 or not(var220 = 1)) and (var18 = 1 or not(var220 =
1)) and (var19 = 1 or not(var220 = 1)) and (var21 = 1 or not(var220 = 1)) and (
var24 = 1 or not(var220 = 1)) and (var26 = 1 or not(var220 = 1)) and (var28 = 1
or not(var220 = 1)) and (var29 = 1 or not(var220 = 1)) and (var31 = 1 or not(
var220 = 1)) and (var33 = 1 or not(var220 = 1)) and (var36 = 1 or not(var220 = 1
)) and (var38 = 1 or not(var220 = 1)) and (var40 = 1 or not(var220 = 1)) and (
var41 = 1 or not(var220 = 1)) and (var43 = 1 or not(var220 = 1)) and (var46 = 1
or not(var220 = 1)) and (var48 = 1 or not(var220 = 1)) and (var50 = 1 or not(
var220 = 1)) and (var52 = 1 or not(var220 = 1)) and (var54 = 1 or not(var220 = 1
)) and (var56 = 1 or not(var220 = 1)) and (var58 = 1 or not(var220 = 1)) and (
var60 = 1 or not(var220 = 1)) and (var61 = 1 or not(var220 = 1)) and (var63 = 1
or not(var220 = 1)) and (var66 = 1 or not(var221 = 1)) and (var68 = 1 or not(
var221 = 1)) and (var70 = 1 or not(var221 = 1)) and (var72 = 1 or not(var221 = 1
)) and (var74 = 1 or not(var221 = 1)) and (var76 = 1 or not(var221 = 1)) and (
var78 = 1 or not(var221 = 1)) and (var79 = 1 or not(var221 = 1)) and (var82 = 1
or not(var221 = 1)) and (var83 = 1 or not(var221 = 1)) and (var85 = 1 or not(
var221 = 1)) and (var88 = 1 or not(var221 = 1)) and (var90 = 1 or not(var221 = 1
)) and (var92 = 1 or not(var221 = 1)) and (var93 = 1 or not(var221 = 1)) and (
var95 = 1 or not(var221 = 1)) and (var97 = 1 or not(var221 = 1)) and (var100 = 1
 or not(var221 = 1)) and (var102 = 1 or not(var221 = 1)) and (var104 = 1 or not(
var221 = 1)) and (var105 = 1 or not(var221 = 1)) and (var107 = 1 or not(var221 =
 1)) and (var110 = 1 or not(var221 = 1)) and (var112 = 1 or not(var221 = 1)) and
 (var114 = 1 or not(var221 = 1)) and (var116 = 1 or not(var221 = 1)) and (var118
 = 1 or not(var221 = 1)) and (var120 = 1 or not(var221 = 1)) and (var122 = 1 or
not(var221 = 1)) and (var124 = 1 or not(var221 = 1)) and (var125 = 1 or not(
var221 = 1)) and (var127 = 1 or not(var221 = 1)) and (var130 = 1 or not(var222 =
 1)) and (var132 = 1 or not(var222 = 1)) and (var134 = 1 or not(var222 = 1)) and
 (var136 = 1 or not(var222 = 1)) and (var138 = 1 or not(var222 = 1)) and (var140
 = 1 or not(var222 = 1)) and (var142 = 1 or not(var222 = 1)) and (var143 = 1 or
not(var222 = 1)) and (var146 = 1 or not(var222 = 1)) and (var147 = 1 or not(
var222 = 1)) and (var149 = 1 or not(var222 = 1)) and (var152 = 1 or not(var222 =
 1)) and (var154 = 1 or not(var222 = 1)) and (var156 = 1 or not(var222 = 1)) and
 (var157 = 1 or not(var222 = 1)) and (var159 = 1 or not(var222 = 1)) and (var161
 = 1 or not(var222 = 1)) and (var164 = 1 or not(var222 = 1)) and (var166 = 1 or
not(var222 = 1)) and (var168 = 1 or not(var222 = 1)) and (var169 = 1 or not(
var222 = 1)) and (var171 = 1 or not(var222 = 1)) and (var174 = 1 or not(var222 =
 1)) and (var176 = 1 or not(var222 = 1)) and (var178 = 1 or not(var222 = 1)) and
 (var180 = 1 or not(var222 = 1)) and (var182 = 1 or not(var222 = 1)) and (var184
 = 1 or not(var222 = 1)) and (var186 = 1 or not(var222 = 1)) and (var188 = 1 or
not(var222 = 1)) and (var189 = 1 or not(var222 = 1)) and (var191 = 1 or not(
var222 = 1)) and (var1 = 1 or not(var223 = 1)) and (var4 = 1 or not(var223 = 1))
 and (var6 = 1 or not(var223 = 1)) and (var7 = 1 or not(var223 = 1)) and (var10
= 1 or not(var223 = 1)) and (var12 = 1 or not(var223 = 1)) and (var13 = 1 or not
(var223 = 1)) and (var15 = 1 or not(var223 = 1)) and (var18 = 1 or not(var223 =
1)) and (var20 = 1 or not(var223 = 1)) and (var21 = 1 or not(var223 = 1)) and (
var23 = 1 or not(var223 = 1)) and (var26 = 1 or not(var223 = 1)) and (var27 = 1
or not(var223 = 1)) and (var30 = 1 or not(var223 = 1)) and (var32 = 1 or not(
var223 = 1)) and (var34 = 1 or not(var223 = 1)) and (var35 = 1 or not(var223 = 1
)) and (var38 = 1 or not(var223 = 1)) and (var39 = 1 or not(var223 = 1)) and (
var41 = 1 or not(var223 = 1)) and (var44 = 1 or not(var223 = 1)) and (var46 = 1
or not(var223 = 1)) and (var47 = 1 or not(var223 = 1)) and (var49 = 1 or not(
var223 = 1)) and (var52 = 1 or not(var223 = 1)) and (var54 = 1 or not(var223 = 1
)) and (var55 = 1 or not(var223 = 1)) and (var57 = 1 or not(var223 = 1)) and (
var59 = 1 or not(var223 = 1)) and (var61 = 1 or not(var223 = 1)) and (var63 = 1
or not(var223 = 1)) and (var65 = 1 or not(var224 = 1)) and (var68 = 1 or not(
var224 = 1)) and (var70 = 1 or not(var224 = 1)) and (var71 = 1 or not(var224 = 1
)) and (var74 = 1 or not(var224 = 1)) and (var76 = 1 or not(var224 = 1)) and (
var77 = 1 or not(var224 = 1)) and (var79 = 1 or not(var224 = 1)) and (var82 = 1
or not(var224 = 1)) and (var84 = 1 or not(var224 = 1)) and (var85 = 1 or not(
var224 = 1)) and (var87 = 1 or not(var224 = 1)) and (var90 = 1 or not(var224 = 1
)) and (var91 = 1 or not(var224 = 1)) and (var94 = 1 or not(var224 = 1)) and (
var96 = 1 or not(var224 = 1)) and (var98 = 1 or not(var224 = 1)) and (var99 = 1
or not(var224 = 1)) and (var102 = 1 or not(var224 = 1)) and (var103 = 1 or not(
var224 = 1)) and (var105 = 1 or not(var224 = 1)) and (var108 = 1 or not(var224 =
 1)) and (var110 = 1 or not(var224 = 1)) and (var111 = 1 or not(var224 = 1)) and
 (var113 = 1 or not(var224 = 1)) and (var116 = 1 or not(var224 = 1)) and (var118
 = 1 or not(var224 = 1)) and (var119 = 1 or not(var224 = 1)) and (var121 = 1 or
not(var224 = 1)) and (var123 = 1 or not(var224 = 1)) and (var125 = 1 or not(
var224 = 1)) and (var127 = 1 or not(var224 = 1)) and (var129 = 1 or not(var225 =
 1)) and (var132 = 1 or not(var225 = 1)) and (var134 = 1 or not(var225 = 1)) and
 (var135 = 1 or not(var225 = 1)) and (var138 = 1 or not(var225 = 1)) and (var140
 = 1 or not(var225 = 1)) and (var141 = 1 or not(var225 = 1)) and (var143 = 1 or
not(var225 = 1)) and (var146 = 1 or not(var225 = 1)) and (var148 = 1 or not(
var225 = 1)) and (var149 = 1 or not(var225 = 1)) and (var151 = 1 or not(var225 =
 1)) and (var154 = 1 or not(var225 = 1)) and (var155 = 1 or not(var225 = 1)) and
 (var158 = 1 or not(var225 = 1)) and (var160 = 1 or not(var225 = 1)) and (var162
 = 1 or not(var225 = 1)) and (var163 = 1 or not(var225 = 1)) and (var166 = 1 or
not(var225 = 1)) and (var167 = 1 or not(var225 = 1)) and (var169 = 1 or not(
var225 = 1)) and (var172 = 1 or not(var225 = 1)) and (var174 = 1 or not(var225 =
 1)) and (var175 = 1 or not(var225 = 1)) and (var177 = 1 or not(var225 = 1)) and
 (var180 = 1 or not(var225 = 1)) and (var182 = 1 or not(var225 = 1)) and (var183
 = 1 or not(var225 = 1)) and (var185 = 1 or not(var225 = 1)) and (var187 = 1 or
not(var225 = 1)) and (var189 = 1 or not(var225 = 1)) and (var191 = 1 or not(
var225 = 1)) and (var1 = 1 or not(var226 = 1)) and (var4 = 1 or not(var226 = 1))
 and (var6 = 1 or not(var226 = 1)) and (var8 = 1 or not(var226 = 1)) and (var10
= 1 or not(var226 = 1)) and (var11 = 1 or not(var226 = 1)) and (var14 = 1 or not
(var226 = 1)) and (var16 = 1 or not(var226 = 1)) and (var17 = 1 or not(var226 =
1)) and (var20 = 1 or not(var226 = 1)) and (var21 = 1 or not(var226 = 1)) and (
var24 = 1 or not(var226 = 1)) and (var25 = 1 or not(var226 = 1)) and (var27 = 1
or not(var226 = 1)) and (var29 = 1 or not(var226 = 1)) and (var32 = 1 or not(
var226 = 1)) and (var34 = 1 or not(var226 = 1)) and (var36 = 1 or not(var226 = 1
)) and (var38 = 1 or not(var226 = 1)) and (var40 = 1 or not(var226 = 1)) and (
var41 = 1 or not(var226 = 1)) and (var44 = 1 or not(var226 = 1)) and (var45 = 1
or not(var226 = 1)) and (var48 = 1 or not(var226 = 1)) and (var50 = 1 or not(
var226 = 1)) and (var51 = 1 or not(var226 = 1)) and (var54 = 1 or not(var226 = 1
)) and (var55 = 1 or not(var226 = 1)) and (var58 = 1 or not(var226 = 1)) and (
var60 = 1 or not(var226 = 1)) and (var61 = 1 or not(var226 = 1)) and (var63 = 1
or not(var226 = 1)) and (var65 = 1 or not(var227 = 1)) and (var68 = 1 or not(
var227 = 1)) and (var70 = 1 or not(var227 = 1)) and (var72 = 1 or not(var227 = 1
)) and (var74 = 1 or not(var227 = 1)) and (var75 = 1 or not(var227 = 1)) and (
var78 = 1 or not(var227 = 1)) and (var80 = 1 or not(var227 = 1)) and (var81 = 1
or not(var227 = 1)) and (var84 = 1 or not(var227 = 1)) and (var85 = 1 or not(
var227 = 1)) and (var88 = 1 or not(var227 = 1)) and (var89 = 1 or not(var227 = 1
)) and (var91 = 1 or not(var227 = 1)) and (var93 = 1 or not(var227 = 1)) and (
var96 = 1 or not(var227 = 1)) and (var98 = 1 or not(var227 = 1)) and (var100 = 1
 or not(var227 = 1)) and (var102 = 1 or not(var227 = 1)) and (var104 = 1 or not(
var227 = 1)) and (var105 = 1 or not(var227 = 1)) and (var108 = 1 or not(var227 =
 1)) and (var109 = 1 or not(var227 = 1)) and (var112 = 1 or not(var227 = 1)) and
 (var114 = 1 or not(var227 = 1)) and (var115 = 1 or not(var227 = 1)) and (var118
 = 1 or not(var227 = 1)) and (var119 = 1 or not(var227 = 1)) and (var122 = 1 or
not(var227 = 1)) and (var124 = 1 or not(var227 = 1)) and (var125 = 1 or not(
var227 = 1)) and (var127 = 1 or not(var227 = 1)) and (var129 = 1 or not(var228 =
 1)) and (var132 = 1 or not(var228 = 1)) and (var134 = 1 or not(var228 = 1)) and
 (var136 = 1 or not(var228 = 1)) and (var138 = 1 or not(var228 = 1)) and (var139
 = 1 or not(var228 = 1)) and (var142 = 1 or not(var228 = 1)) and (var144 = 1 or
not(var228 = 1)) and (var145 = 1 or not(var228 = 1)) and (var148 = 1 or not(
var228 = 1)) and (var149 = 1 or not(var228 = 1)) and (var152 = 1 or not(var228 =
 1)) and (var153 = 1 or not(var228 = 1)) and (var155 = 1 or not(var228 = 1)) and
 (var157 = 1 or not(var228 = 1)) and (var160 = 1 or not(var228 = 1)) and (var162
 = 1 or not(var228 = 1)) and (var164 = 1 or not(var228 = 1)) and (var166 = 1 or
not(var228 = 1)) and (var168 = 1 or not(var228 = 1)) and (var169 = 1 or not(
var228 = 1)) and (var172 = 1 or not(var228 = 1)) and (var173 = 1 or not(var228 =
 1)) and (var176 = 1 or not(var228 = 1)) and (var178 = 1 or not(var228 = 1)) and
 (var179 = 1 or not(var228 = 1)) and (var182 = 1 or not(var228 = 1)) and (var183
 = 1 or not(var228 = 1)) and (var186 = 1 or not(var228 = 1)) and (var188 = 1 or
not(var228 = 1)) and (var189 = 1 or not(var228 = 1)) and (var191 = 1 or not(
var228 = 1)) and (var2 = 1 or not(var229 = 1)) and (var4 = 1 or not(var229 = 1))
 and (var6 = 1 or not(var229 = 1)) and (var8 = 1 or not(var229 = 1)) and (var9 =
 1 or not(var229 = 1)) and (var11 = 1 or not(var229 = 1)) and (var13 = 1 or not(
var229 = 1)) and (var16 = 1 or not(var229 = 1)) and (var18 = 1 or not(var229 = 1
)) and (var20 = 1 or not(var229 = 1)) and (var21 = 1 or not(var229 = 1)) and (
var24 = 1 or not(var229 = 1)) and (var25 = 1 or not(var229 = 1)) and (var27 = 1
or not(var229 = 1)) and (var30 = 1 or not(var229 = 1)) and (var32 = 1 or not(
var229 = 1)) and (var33 = 1 or not(var229 = 1)) and (var35 = 1 or not(var229 = 1
)) and (var38 = 1 or not(var229 = 1)) and (var40 = 1 or not(var229 = 1)) and (
var41 = 1 or not(var229 = 1)) and (var43 = 1 or not(var229 = 1)) and (var46 = 1
or not(var229 = 1)) and (var48 = 1 or not(var229 = 1)) and (var50 = 1 or not(
var229 = 1)) and (var51 = 1 or not(var229 = 1)) and (var54 = 1 or not(var229 = 1
)) and (var55 = 1 or not(var229 = 1)) and (var57 = 1 or not(var229 = 1)) and (
var59 = 1 or not(var229 = 1)) and (var61 = 1 or not(var229 = 1)) and (var64 = 1
or not(var229 = 1)) and (var66 = 1 or not(var230 = 1)) and (var68 = 1 or not(
var230 = 1)) and (var70 = 1 or not(var230 = 1)) and (var72 = 1 or not(var230 = 1
)) and (var73 = 1 or not(var230 = 1)) and (var75 = 1 or not(var230 = 1)) and (
var77 = 1 or not(var230 = 1)) and (var80 = 1 or not(var230 = 1)) and (var82 = 1
or not(var230 = 1)) and (var84 = 1 or not(var230 = 1)) and (var85 = 1 or not(
var230 = 1)) and (var88 = 1 or not(var230 = 1)) and (var89 = 1 or not(var230 = 1
)) and (var91 = 1 or not(var230 = 1)) and (var94 = 1 or not(var230 = 1)) and (
var96 = 1 or not(var230 = 1)) and (var97 = 1 or not(var230 = 1)) and (var99 = 1
or not(var230 = 1)) and (var102 = 1 or not(var230 = 1)) and (var104 = 1 or not(
var230 = 1)) and (var105 = 1 or not(var230 = 1)) and (var107 = 1 or not(var230 =
 1)) and (var110 = 1 or not(var230 = 1)) and (var112 = 1 or not(var230 = 1)) and
 (var114 = 1 or not(var230 = 1)) and (var115 = 1 or not(var230 = 1)) and (var118
 = 1 or not(var230 = 1)) and (var119 = 1 or not(var230 = 1)) and (var121 = 1 or
not(var230 = 1)) and (var123 = 1 or not(var230 = 1)) and (var125 = 1 or not(
var230 = 1)) and (var128 = 1 or not(var230 = 1)) and (var130 = 1 or not(var231 =
 1)) and (var132 = 1 or not(var231 = 1)) and (var134 = 1 or not(var231 = 1)) and
 (var136 = 1 or not(var231 = 1)) and (var137 = 1 or not(var231 = 1)) and (var139
 = 1 or not(var231 = 1)) and (var141 = 1 or not(var231 = 1)) and (var144 = 1 or
not(var231 = 1)) and (var146 = 1 or not(var231 = 1)) and (var148 = 1 or not(
var231 = 1)) and (var149 = 1 or not(var231 = 1)) and (var152 = 1 or not(var231 =
 1)) and (var153 = 1 or not(var231 = 1)) and (var155 = 1 or not(var231 = 1)) and
 (var158 = 1 or not(var231 = 1)) and (var160 = 1 or not(var231 = 1)) and (var161
 = 1 or not(var231 = 1)) and (var163 = 1 or not(var231 = 1)) and (var166 = 1 or
not(var231 = 1)) and (var168 = 1 or not(var231 = 1)) and (var169 = 1 or not(
var231 = 1)) and (var171 = 1 or not(var231 = 1)) and (var174 = 1 or not(var231 =
 1)) and (var176 = 1 or not(var231 = 1)) and (var178 = 1 or not(var231 = 1)) and
 (var179 = 1 or not(var231 = 1)) and (var182 = 1 or not(var231 = 1)) and (var183
 = 1 or not(var231 = 1)) and (var185 = 1 or not(var231 = 1)) and (var187 = 1 or
not(var231 = 1)) and (var189 = 1 or not(var231 = 1)) and (var192 = 1 or not(
var231 = 1)) and (var2 = 1 or not(var232 = 1)) and (var3 = 1 or not(var232 = 1))
 and (var5 = 1 or not(var232 = 1)) and (var7 = 1 or not(var232 = 1)) and (var10
= 1 or not(var232 = 1)) and (var11 = 1 or not(var232 = 1)) and (var13 = 1 or not
(var232 = 1)) and (var16 = 1 or not(var232 = 1)) and (var18 = 1 or not(var232 =
1)) and (var20 = 1 or not(var232 = 1)) and (var21 = 1 or not(var232 = 1)) and (
var23 = 1 or not(var232 = 1)) and (var26 = 1 or not(var232 = 1)) and (var28 = 1
or not(var232 = 1)) and (var29 = 1 or not(var232 = 1)) and (var31 = 1 or not(
var232 = 1)) and (var33 = 1 or not(var232 = 1)) and (var36 = 1 or not(var232 = 1
)) and (var38 = 1 or not(var232 = 1)) and (var40 = 1 or not(var232 = 1)) and (
var41 = 1 or not(var232 = 1)) and (var43 = 1 or not(var232 = 1)) and (var46 = 1
or not(var232 = 1)) and (var48 = 1 or not(var232 = 1)) and (var49 = 1 or not(
var232 = 1)) and (var52 = 1 or not(var232 = 1)) and (var54 = 1 or not(var232 = 1
)) and (var56 = 1 or not(var232 = 1)) and (var57 = 1 or not(var232 = 1)) and (
var60 = 1 or not(var232 = 1)) and (var62 = 1 or not(var232 = 1)) and (var63 = 1
or not(var232 = 1)) and (var66 = 1 or not(var233 = 1)) and (var67 = 1 or not(
var233 = 1)) and (var69 = 1 or not(var233 = 1)) and (var71 = 1 or not(var233 = 1
)) and (var74 = 1 or not(var233 = 1)) and (var75 = 1 or not(var233 = 1)) and (
var77 = 1 or not(var233 = 1)) and (var80 = 1 or not(var233 = 1)) and (var82 = 1
or not(var233 = 1)) and (var84 = 1 or not(var233 = 1)) and (var85 = 1 or not(
var233 = 1)) and (var87 = 1 or not(var233 = 1)) and (var90 = 1 or not(var233 = 1
)) and (var92 = 1 or not(var233 = 1)) and (var93 = 1 or not(var233 = 1)) and (
var95 = 1 or not(var233 = 1)) and (var97 = 1 or not(var233 = 1)) and (var100 = 1
 or not(var233 = 1)) and (var102 = 1 or not(var233 = 1)) and (var104 = 1 or not(
var233 = 1)) and (var105 = 1 or not(var233 = 1)) and (var107 = 1 or not(var233 =
 1)) and (var110 = 1 or not(var233 = 1)) and (var112 = 1 or not(var233 = 1)) and
 (var113 = 1 or not(var233 = 1)) and (var116 = 1 or not(var233 = 1)) and (var118
 = 1 or not(var233 = 1)) and (var120 = 1 or not(var233 = 1)) and (var121 = 1 or
not(var233 = 1)) and (var124 = 1 or not(var233 = 1)) and (var126 = 1 or not(
var233 = 1)) and (var127 = 1 or not(var233 = 1)) and (var130 = 1 or not(var234 =
 1)) and (var131 = 1 or not(var234 = 1)) and (var133 = 1 or not(var234 = 1)) and
 (var135 = 1 or not(var234 = 1)) and (var138 = 1 or not(var234 = 1)) and (var139
 = 1 or not(var234 = 1)) and (var141 = 1 or not(var234 = 1)) and (var144 = 1 or
not(var234 = 1)) and (var146 = 1 or not(var234 = 1)) and (var148 = 1 or not(
var234 = 1)) and (var149 = 1 or not(var234 = 1)) and (var151 = 1 or not(var234 =
 1)) and (var154 = 1 or not(var234 = 1)) and (var156 = 1 or not(var234 = 1)) and
 (var157 = 1 or not(var234 = 1)) and (var159 = 1 or not(var234 = 1)) and (var161
 = 1 or not(var234 = 1)) and (var164 = 1 or not(var234 = 1)) and (var166 = 1 or
not(var234 = 1)) and (var168 = 1 or not(var234 = 1)) and (var169 = 1 or not(
var234 = 1)) and (var171 = 1 or not(var234 = 1)) and (var174 = 1 or not(var234 =
 1)) and (var176 = 1 or not(var234 = 1)) and (var177 = 1 or not(var234 = 1)) and
 (var180 = 1 or not(var234 = 1)) and (var182 = 1 or not(var234 = 1)) and (var184
 = 1 or not(var234 = 1)) and (var185 = 1 or not(var234 = 1)) and (var188 = 1 or
not(var234 = 1)) and (var190 = 1 or not(var234 = 1)) and (var191 = 1 or not(
var234 = 1)) and (var1 = 1 or not(var235 = 1)) and (var3 = 1 or not(var235 = 1))
 and (var6 = 1 or not(var235 = 1)) and (var7 = 1 or not(var235 = 1)) and (var10
= 1 or not(var235 = 1)) and (var12 = 1 or not(var235 = 1)) and (var14 = 1 or not
(var235 = 1)) and (var15 = 1 or not(var235 = 1)) and (var18 = 1 or not(var235 =
1)) and (var20 = 1 or not(var235 = 1)) and (var22 = 1 or not(var235 = 1)) and (
var24 = 1 or not(var235 = 1)) and (var26 = 1 or not(var235 = 1)) and (var28 = 1
or not(var235 = 1)) and (var30 = 1 or not(var235 = 1)) and (var31 = 1 or not(
var235 = 1)) and (var33 = 1 or not(var235 = 1)) and (var35 = 1 or not(var235 = 1
)) and (var37 = 1 or not(var235 = 1)) and (var40 = 1 or not(var235 = 1)) and (
var41 = 1 or not(var235 = 1)) and (var44 = 1 or not(var235 = 1)) and (var46 = 1
or not(var235 = 1)) and (var48 = 1 or not(var235 = 1)) and (var49 = 1 or not(
var235 = 1)) and (var52 = 1 or not(var235 = 1)) and (var54 = 1 or not(var235 = 1
)) and (var55 = 1 or not(var235 = 1)) and (var57 = 1 or not(var235 = 1)) and (
var59 = 1 or not(var235 = 1)) and (var61 = 1 or not(var235 = 1)) and (var63 = 1
or not(var235 = 1)) and (var65 = 1 or not(var236 = 1)) and (var67 = 1 or not(
var236 = 1)) and (var70 = 1 or not(var236 = 1)) and (var71 = 1 or not(var236 = 1
)) and (var74 = 1 or not(var236 = 1)) and (var76 = 1 or not(var236 = 1)) and (
var78 = 1 or not(var236 = 1)) and (var79 = 1 or not(var236 = 1)) and (var82 = 1
or not(var236 = 1)) and (var84 = 1 or not(var236 = 1)) and (var86 = 1 or not(
var236 = 1)) and (var88 = 1 or not(var236 = 1)) and (var90 = 1 or not(var236 = 1
)) and (var92 = 1 or not(var236 = 1)) and (var94 = 1 or not(var236 = 1)) and (
var95 = 1 or not(var236 = 1)) and (var97 = 1 or not(var236 = 1)) and (var99 = 1
or not(var236 = 1)) and (var101 = 1 or not(var236 = 1)) and (var104 = 1 or not(
var236 = 1)) and (var105 = 1 or not(var236 = 1)) and (var108 = 1 or not(var236 =
 1)) and (var110 = 1 or not(var236 = 1)) and (var112 = 1 or not(var236 = 1)) and
 (var113 = 1 or not(var236 = 1)) and (var116 = 1 or not(var236 = 1)) and (var118
 = 1 or not(var236 = 1)) and (var119 = 1 or not(var236 = 1)) and (var121 = 1 or
not(var236 = 1)) and (var123 = 1 or not(var236 = 1)) and (var125 = 1 or not(
var236 = 1)) and (var127 = 1 or not(var236 = 1)) and (var129 = 1 or not(var237 =
 1)) and (var131 = 1 or not(var237 = 1)) and (var134 = 1 or not(var237 = 1)) and
 (var135 = 1 or not(var237 = 1)) and (var138 = 1 or not(var237 = 1)) and (var140
 = 1 or not(var237 = 1)) and (var142 = 1 or not(var237 = 1)) and (var143 = 1 or
not(var237 = 1)) and (var146 = 1 or not(var237 = 1)) and (var148 = 1 or not(
var237 = 1)) and (var150 = 1 or not(var237 = 1)) and (var152 = 1 or not(var237 =
 1)) and (var154 = 1 or not(var237 = 1)) and (var156 = 1 or not(var237 = 1)) and
 (var158 = 1 or not(var237 = 1)) and (var159 = 1 or not(var237 = 1)) and (var161
 = 1 or not(var237 = 1)) and (var163 = 1 or not(var237 = 1)) and (var165 = 1 or
not(var237 = 1)) and (var168 = 1 or not(var237 = 1)) and (var169 = 1 or not(
var237 = 1)) and (var172 = 1 or not(var237 = 1)) and (var174 = 1 or not(var237 =
 1)) and (var176 = 1 or not(var237 = 1)) and (var177 = 1 or not(var237 = 1)) and
 (var180 = 1 or not(var237 = 1)) and (var182 = 1 or not(var237 = 1)) and (var183
 = 1 or not(var237 = 1)) and (var185 = 1 or not(var237 = 1)) and (var187 = 1 or
not(var237 = 1)) and (var189 = 1 or not(var237 = 1)) and (var191 = 1 or not(
var237 = 1)) and (var2 = 1 or not(var238 = 1)) and (var4 = 1 or not(var238 = 1))
 and (var6 = 1 or not(var238 = 1)) and (var8 = 1 or not(var238 = 1)) and (var9 =
 1 or not(var238 = 1)) and (var11 = 1 or not(var238 = 1)) and (var14 = 1 or not(
var238 = 1)) and (var16 = 1 or not(var238 = 1)) and (var18 = 1 or not(var238 = 1
)) and (var20 = 1 or not(var238 = 1)) and (var22 = 1 or not(var238 = 1)) and (
var23 = 1 or not(var238 = 1)) and (var26 = 1 or not(var238 = 1)) and (var27 = 1
or not(var238 = 1)) and (var29 = 1 or not(var238 = 1)) and (var31 = 1 or not(
var238 = 1)) and (var33 = 1 or not(var238 = 1)) and (var36 = 1 or not(var238 = 1
)) and (var37 = 1 or not(var238 = 1)) and (var39 = 1 or not(var238 = 1)) and (
var42 = 1 or not(var238 = 1)) and (var44 = 1 or not(var238 = 1)) and (var46 = 1
or not(var238 = 1)) and (var47 = 1 or not(var238 = 1)) and (var49 = 1 or not(
var238 = 1)) and (var51 = 1 or not(var238 = 1)) and (var53 = 1 or not(var238 = 1
)) and (var55 = 1 or not(var238 = 1)) and (var57 = 1 or not(var238 = 1)) and (
var59 = 1 or not(var238 = 1)) and (var61 = 1 or not(var238 = 1)) and (var64 = 1
or not(var238 = 1)) and (var66 = 1 or not(var239 = 1)) and (var68 = 1 or not(
var239 = 1)) and (var70 = 1 or not(var239 = 1)) and (var72 = 1 or not(var239 = 1
)) and (var73 = 1 or not(var239 = 1)) and (var75 = 1 or not(var239 = 1)) and (
var78 = 1 or not(var239 = 1)) and (var80 = 1 or not(var239 = 1)) and (var82 = 1
or not(var239 = 1)) and (var84 = 1 or not(var239 = 1)) and (var86 = 1 or not(
var239 = 1)) and (var87 = 1 or not(var239 = 1)) and (var90 = 1 or not(var239 = 1
)) and (var91 = 1 or not(var239 = 1)) and (var93 = 1 or not(var239 = 1)) and (
var95 = 1 or not(var239 = 1)) and (var97 = 1 or not(var239 = 1)) and (var100 = 1
 or not(var239 = 1)) and (var101 = 1 or not(var239 = 1)) and (var103 = 1 or not(
var239 = 1)) and (var106 = 1 or not(var239 = 1)) and (var108 = 1 or not(var239 =
 1)) and (var110 = 1 or not(var239 = 1)) and (var111 = 1 or not(var239 = 1)) and
 (var113 = 1 or not(var239 = 1)) and (var115 = 1 or not(var239 = 1)) and (var117
 = 1 or not(var239 = 1)) and (var119 = 1 or not(var239 = 1)) and (var121 = 1 or
not(var239 = 1)) and (var123 = 1 or not(var239 = 1)) and (var125 = 1 or not(
var239 = 1)) and (var128 = 1 or not(var239 = 1)) and (var130 = 1 or not(var240 =
 1)) and (var132 = 1 or not(var240 = 1)) and (var134 = 1 or not(var240 = 1)) and
 (var136 = 1 or not(var240 = 1)) and (var137 = 1 or not(var240 = 1)) and (var139
 = 1 or not(var240 = 1)) and (var142 = 1 or not(var240 = 1)) and (var144 = 1 or
not(var240 = 1)) and (var146 = 1 or not(var240 = 1)) and (var148 = 1 or not(
var240 = 1)) and (var150 = 1 or not(var240 = 1)) and (var151 = 1 or not(var240 =
 1)) and (var154 = 1 or not(var240 = 1)) and (var155 = 1 or not(var240 = 1)) and
 (var157 = 1 or not(var240 = 1)) and (var159 = 1 or not(var240 = 1)) and (var161
 = 1 or not(var240 = 1)) and (var164 = 1 or not(var240 = 1)) and (var165 = 1 or
not(var240 = 1)) and (var167 = 1 or not(var240 = 1)) and (var170 = 1 or not(
var240 = 1)) and (var172 = 1 or not(var240 = 1)) and (var174 = 1 or not(var240 =
 1)) and (var175 = 1 or not(var240 = 1)) and (var177 = 1 or not(var240 = 1)) and
 (var179 = 1 or not(var240 = 1)) and (var181 = 1 or not(var240 = 1)) and (var183
 = 1 or not(var240 = 1)) and (var185 = 1 or not(var240 = 1)) and (var187 = 1 or
not(var240 = 1)) and (var189 = 1 or not(var240 = 1)) and (var192 = 1 or not(
var240 = 1)) and (var1 = 1 or not(var241 = 1)) and (var3 = 1 or not(var241 = 1))
 and (var5 = 1 or not(var241 = 1)) and (var7 = 1 or not(var241 = 1)) and (var10
= 1 or not(var241 = 1)) and (var12 = 1 or not(var241 = 1)) and (var14 = 1 or not
(var241 = 1)) and (var15 = 1 or not(var241 = 1)) and (var18 = 1 or not(var241 =
1)) and (var20 = 1 or not(var241 = 1)) and (var21 = 1 or not(var241 = 1)) and (
var24 = 1 or not(var241 = 1)) and (var25 = 1 or not(var241 = 1)) and (var28 = 1
or not(var241 = 1)) and (var30 = 1 or not(var241 = 1)) and (var31 = 1 or not(
var241 = 1)) and (var33 = 1 or not(var241 = 1)) and (var36 = 1 or not(var241 = 1
)) and (var37 = 1 or not(var241 = 1)) and (var40 = 1 or not(var241 = 1)) and (
var42 = 1 or not(var241 = 1)) and (var44 = 1 or not(var241 = 1)) and (var46 = 1
or not(var241 = 1)) and (var48 = 1 or not(var241 = 1)) and (var50 = 1 or not(
var241 = 1)) and (var52 = 1 or not(var241 = 1)) and (var54 = 1 or not(var241 = 1
)) and (var55 = 1 or not(var241 = 1)) and (var58 = 1 or not(var241 = 1)) and (
var60 = 1 or not(var241 = 1)) and (var62 = 1 or not(var241 = 1)) and (var64 = 1
or not(var241 = 1)) and (var65 = 1 or not(var242 = 1)) and (var67 = 1 or not(
var242 = 1)) and (var69 = 1 or not(var242 = 1)) and (var71 = 1 or not(var242 = 1
)) and (var74 = 1 or not(var242 = 1)) and (var76 = 1 or not(var242 = 1)) and (
var78 = 1 or not(var242 = 1)) and (var79 = 1 or not(var242 = 1)) and (var82 = 1
or not(var242 = 1)) and (var84 = 1 or not(var242 = 1)) and (var85 = 1 or not(
var242 = 1)) and (var88 = 1 or not(var242 = 1)) and (var89 = 1 or not(var242 = 1
)) and (var92 = 1 or not(var242 = 1)) and (var94 = 1 or not(var242 = 1)) and (
var95 = 1 or not(var242 = 1)) and (var97 = 1 or not(var242 = 1)) and (var100 = 1
 or not(var242 = 1)) and (var101 = 1 or not(var242 = 1)) and (var104 = 1 or not(
var242 = 1)) and (var106 = 1 or not(var242 = 1)) and (var108 = 1 or not(var242 =
 1)) and (var110 = 1 or not(var242 = 1)) and (var112 = 1 or not(var242 = 1)) and
 (var114 = 1 or not(var242 = 1)) and (var116 = 1 or not(var242 = 1)) and (var118
 = 1 or not(var242 = 1)) and (var119 = 1 or not(var242 = 1)) and (var122 = 1 or
not(var242 = 1)) and (var124 = 1 or not(var242 = 1)) and (var126 = 1 or not(
var242 = 1)) and (var128 = 1 or not(var242 = 1)) and (var129 = 1 or not(var243 =
 1)) and (var131 = 1 or not(var243 = 1)) and (var133 = 1 or not(var243 = 1)) and
 (var135 = 1 or not(var243 = 1)) and (var138 = 1 or not(var243 = 1)) and (var140
 = 1 or not(var243 = 1)) and (var142 = 1 or not(var243 = 1)) and (var143 = 1 or
not(var243 = 1)) and (var146 = 1 or not(var243 = 1)) and (var148 = 1 or not(
var243 = 1)) and (var149 = 1 or not(var243 = 1)) and (var152 = 1 or not(var243 =
 1)) and (var153 = 1 or not(var243 = 1)) and (var156 = 1 or not(var243 = 1)) and
 (var158 = 1 or not(var243 = 1)) and (var159 = 1 or not(var243 = 1)) and (var161
 = 1 or not(var243 = 1)) and (var164 = 1 or not(var243 = 1)) and (var165 = 1 or
not(var243 = 1)) and (var168 = 1 or not(var243 = 1)) and (var170 = 1 or not(
var243 = 1)) and (var172 = 1 or not(var243 = 1)) and (var174 = 1 or not(var243 =
 1)) and (var176 = 1 or not(var243 = 1)) and (var178 = 1 or not(var243 = 1)) and
 (var180 = 1 or not(var243 = 1)) and (var182 = 1 or not(var243 = 1)) and (var183
 = 1 or not(var243 = 1)) and (var186 = 1 or not(var243 = 1)) and (var188 = 1 or
not(var243 = 1)) and (var190 = 1 or not(var243 = 1)) and (var192 = 1 or not(
var243 = 1)) and (var1 = 1 or not(var244 = 1)) and (var3 = 1 or not(var244 = 1))
 and (var6 = 1 or not(var244 = 1)) and (var7 = 1 or not(var244 = 1)) and (var10
= 1 or not(var244 = 1)) and (var12 = 1 or not(var244 = 1)) and (var14 = 1 or not
(var244 = 1)) and (var16 = 1 or not(var244 = 1)) and (var18 = 1 or not(var244 =
1)) and (var20 = 1 or not(var244 = 1)) and (var22 = 1 or not(var244 = 1)) and (
var24 = 1 or not(var244 = 1)) and (var26 = 1 or not(var244 = 1)) and (var27 = 1
or not(var244 = 1)) and (var29 = 1 or not(var244 = 1)) and (var31 = 1 or not(
var244 = 1)) and (var34 = 1 or not(var244 = 1)) and (var36 = 1 or not(var244 = 1
)) and (var37 = 1 or not(var244 = 1)) and (var40 = 1 or not(var244 = 1)) and (
var42 = 1 or not(var244 = 1)) and (var43 = 1 or not(var244 = 1)) and (var46 = 1
or not(var244 = 1)) and (var48 = 1 or not(var244 = 1)) and (var49 = 1 or not(
var244 = 1)) and (var52 = 1 or not(var244 = 1)) and (var54 = 1 or not(var244 = 1
)) and (var56 = 1 or not(var244 = 1)) and (var57 = 1 or not(var244 = 1)) and (
var60 = 1 or not(var244 = 1)) and (var61 = 1 or not(var244 = 1)) and (var64 = 1
or not(var244 = 1)) and (var65 = 1 or not(var245 = 1)) and (var67 = 1 or not(
var245 = 1)) and (var70 = 1 or not(var245 = 1)) and (var71 = 1 or not(var245 = 1
)) and (var74 = 1 or not(var245 = 1)) and (var76 = 1 or not(var245 = 1)) and (
var78 = 1 or not(var245 = 1)) and (var80 = 1 or not(var245 = 1)) and (var82 = 1
or not(var245 = 1)) and (var84 = 1 or not(var245 = 1)) and (var86 = 1 or not(
var245 = 1)) and (var88 = 1 or not(var245 = 1)) and (var90 = 1 or not(var245 = 1
)) and (var91 = 1 or not(var245 = 1)) and (var93 = 1 or not(var245 = 1)) and (
var95 = 1 or not(var245 = 1)) and (var98 = 1 or not(var245 = 1)) and (var100 = 1
 or not(var245 = 1)) and (var101 = 1 or not(var245 = 1)) and (var104 = 1 or not(
var245 = 1)) and (var106 = 1 or not(var245 = 1)) and (var107 = 1 or not(var245 =
 1)) and (var110 = 1 or not(var245 = 1)) and (var112 = 1 or not(var245 = 1)) and
 (var113 = 1 or not(var245 = 1)) and (var116 = 1 or not(var245 = 1)) and (var118
 = 1 or not(var245 = 1)) and (var120 = 1 or not(var245 = 1)) and (var121 = 1 or
not(var245 = 1)) and (var124 = 1 or not(var245 = 1)) and (var125 = 1 or not(
var245 = 1)) and (var128 = 1 or not(var245 = 1)) and (var129 = 1 or not(var246 =
 1)) and (var131 = 1 or not(var246 = 1)) and (var134 = 1 or not(var246 = 1)) and
 (var135 = 1 or not(var246 = 1)) and (var138 = 1 or not(var246 = 1)) and (var140
 = 1 or not(var246 = 1)) and (var142 = 1 or not(var246 = 1)) and (var144 = 1 or
not(var246 = 1)) and (var146 = 1 or not(var246 = 1)) and (var148 = 1 or not(
var246 = 1)) and (var150 = 1 or not(var246 = 1)) and (var152 = 1 or not(var246 =
 1)) and (var154 = 1 or not(var246 = 1)) and (var155 = 1 or not(var246 = 1)) and
 (var157 = 1 or not(var246 = 1)) and (var159 = 1 or not(var246 = 1)) and (var162
 = 1 or not(var246 = 1)) and (var164 = 1 or not(var246 = 1)) and (var165 = 1 or
not(var246 = 1)) and (var168 = 1 or not(var246 = 1)) and (var170 = 1 or not(
var246 = 1)) and (var171 = 1 or not(var246 = 1)) and (var174 = 1 or not(var246 =
 1)) and (var176 = 1 or not(var246 = 1)) and (var177 = 1 or not(var246 = 1)) and
 (var180 = 1 or not(var246 = 1)) and (var182 = 1 or not(var246 = 1)) and (var184
 = 1 or not(var246 = 1)) and (var185 = 1 or not(var246 = 1)) and (var188 = 1 or
not(var246 = 1)) and (var189 = 1 or not(var246 = 1)) and (var192 = 1 or not(
var246 = 1)) and (var2 = 1 or not(var247 = 1)) and (var4 = 1 or not(var247 = 1))
 and (var5 = 1 or not(var247 = 1)) and (var7 = 1 or not(var247 = 1)) and (var10
= 1 or not(var247 = 1)) and (var12 = 1 or not(var247 = 1)) and (var13 = 1 or not
(var247 = 1)) and (var16 = 1 or not(var247 = 1)) and (var18 = 1 or not(var247 =
1)) and (var19 = 1 or not(var247 = 1)) and (var22 = 1 or not(var247 = 1)) and (
var23 = 1 or not(var247 = 1)) and (var26 = 1 or not(var247 = 1)) and (var27 = 1
or not(var247 = 1)) and (var29 = 1 or not(var247 = 1)) and (var31 = 1 or not(
var247 = 1)) and (var33 = 1 or not(var247 = 1)) and (var36 = 1 or not(var247 = 1
)) and (var37 = 1 or not(var247 = 1)) and (var39 = 1 or not(var247 = 1)) and (
var42 = 1 or not(var247 = 1)) and (var44 = 1 or not(var247 = 1)) and (var45 = 1
or not(var247 = 1)) and (var48 = 1 or not(var247 = 1)) and (var50 = 1 or not(
var247 = 1)) and (var51 = 1 or not(var247 = 1)) and (var54 = 1 or not(var247 = 1
)) and (var55 = 1 or not(var247 = 1)) and (var58 = 1 or not(var247 = 1)) and (
var59 = 1 or not(var247 = 1)) and (var61 = 1 or not(var247 = 1)) and (var64 = 1
or not(var247 = 1)) and (var66 = 1 or not(var248 = 1)) and (var68 = 1 or not(
var248 = 1)) and (var69 = 1 or not(var248 = 1)) and (var71 = 1 or not(var248 = 1
)) and (var74 = 1 or not(var248 = 1)) and (var76 = 1 or not(var248 = 1)) and (
var77 = 1 or not(var248 = 1)) and (var80 = 1 or not(var248 = 1)) and (var82 = 1
or not(var248 = 1)) and (var83 = 1 or not(var248 = 1)) and (var86 = 1 or not(
var248 = 1)) and (var87 = 1 or not(var248 = 1)) and (var90 = 1 or not(var248 = 1
)) and (var91 = 1 or not(var248 = 1)) and (var93 = 1 or not(var248 = 1)) and (
var95 = 1 or not(var248 = 1)) and (var97 = 1 or not(var248 = 1)) and (var100 = 1
 or not(var248 = 1)) and (var101 = 1 or not(var248 = 1)) and (var103 = 1 or not(
var248 = 1)) and (var106 = 1 or not(var248 = 1)) and (var108 = 1 or not(var248 =
 1)) and (var109 = 1 or not(var248 = 1)) and (var112 = 1 or not(var248 = 1)) and
 (var114 = 1 or not(var248 = 1)) and (var115 = 1 or not(var248 = 1)) and (var118
 = 1 or not(var248 = 1)) and (var119 = 1 or not(var248 = 1)) and (var122 = 1 or
not(var248 = 1)) and (var123 = 1 or not(var248 = 1)) and (var125 = 1 or not(
var248 = 1)) and (var128 = 1 or not(var248 = 1)) and (var130 = 1 or not(var249 =
 1)) and (var132 = 1 or not(var249 = 1)) and (var133 = 1 or not(var249 = 1)) and
 (var135 = 1 or not(var249 = 1)) and (var138 = 1 or not(var249 = 1)) and (var140
 = 1 or not(var249 = 1)) and (var141 = 1 or not(var249 = 1)) and (var144 = 1 or
not(var249 = 1)) and (var146 = 1 or not(var249 = 1)) and (var147 = 1 or not(
var249 = 1)) and (var150 = 1 or not(var249 = 1)) and (var151 = 1 or not(var249 =
 1)) and (var154 = 1 or not(var249 = 1)) and (var155 = 1 or not(var249 = 1)) and
 (var157 = 1 or not(var249 = 1)) and (var159 = 1 or not(var249 = 1)) and (var161
 = 1 or not(var249 = 1)) and (var164 = 1 or not(var249 = 1)) and (var165 = 1 or
not(var249 = 1)) and (var167 = 1 or not(var249 = 1)) and (var170 = 1 or not(
var249 = 1)) and (var172 = 1 or not(var249 = 1)) and (var173 = 1 or not(var249 =
 1)) and (var176 = 1 or not(var249 = 1)) and (var178 = 1 or not(var249 = 1)) and
 (var179 = 1 or not(var249 = 1)) and (var182 = 1 or not(var249 = 1)) and (var183
 = 1 or not(var249 = 1)) and (var186 = 1 or not(var249 = 1)) and (var187 = 1 or
not(var249 = 1)) and (var189 = 1 or not(var249 = 1)) and (var192 = 1 or not(
var249 = 1)) and (var2 = 1 or not(var250 = 1)) and (var3 = 1 or not(var250 = 1))
 and (var6 = 1 or not(var250 = 1)) and (var7 = 1 or not(var250 = 1)) and (var10
= 1 or not(var250 = 1)) and (var12 = 1 or not(var250 = 1)) and (var13 = 1 or not
(var250 = 1)) and (var15 = 1 or not(var250 = 1)) and (var18 = 1 or not(var250 =
1)) and (var20 = 1 or not(var250 = 1)) and (var22 = 1 or not(var250 = 1)) and (
var24 = 1 or not(var250 = 1)) and (var26 = 1 or not(var250 = 1)) and (var27 = 1
or not(var250 = 1)) and (var29 = 1 or not(var250 = 1)) and (var31 = 1 or not(
var250 = 1)) and (var33 = 1 or not(var250 = 1)) and (var35 = 1 or not(var250 = 1
)) and (var38 = 1 or not(var250 = 1)) and (var40 = 1 or not(var250 = 1)) and (
var42 = 1 or not(var250 = 1)) and (var44 = 1 or not(var250 = 1)) and (var46 = 1
or not(var250 = 1)) and (var48 = 1 or not(var250 = 1)) and (var49 = 1 or not(
var250 = 1)) and (var51 = 1 or not(var250 = 1)) and (var54 = 1 or not(var250 = 1
)) and (var56 = 1 or not(var250 = 1)) and (var57 = 1 or not(var250 = 1)) and (
var59 = 1 or not(var250 = 1)) and (var62 = 1 or not(var250 = 1)) and (var63 = 1
or not(var250 = 1)) and (var66 = 1 or not(var251 = 1)) and (var67 = 1 or not(
var251 = 1)) and (var70 = 1 or not(var251 = 1)) and (var71 = 1 or not(var251 = 1
)) and (var74 = 1 or not(var251 = 1)) and (var76 = 1 or not(var251 = 1)) and (
var77 = 1 or not(var251 = 1)) and (var79 = 1 or not(var251 = 1)) and (var82 = 1
or not(var251 = 1)) and (var84 = 1 or not(var251 = 1)) and (var86 = 1 or not(
var251 = 1)) and (var88 = 1 or not(var251 = 1)) and (var90 = 1 or not(var251 = 1
)) and (var91 = 1 or not(var251 = 1)) and (var93 = 1 or not(var251 = 1)) and (
var95 = 1 or not(var251 = 1)) and (var97 = 1 or not(var251 = 1)) and (var99 = 1
or not(var251 = 1)) and (var102 = 1 or not(var251 = 1)) and (var104 = 1 or not(
var251 = 1)) and (var106 = 1 or not(var251 = 1)) and (var108 = 1 or not(var251 =
 1)) and (var110 = 1 or not(var251 = 1)) and (var112 = 1 or not(var251 = 1)) and
 (var113 = 1 or not(var251 = 1)) and (var115 = 1 or not(var251 = 1)) and (var118
 = 1 or not(var251 = 1)) and (var120 = 1 or not(var251 = 1)) and (var121 = 1 or
not(var251 = 1)) and (var123 = 1 or not(var251 = 1)) and (var126 = 1 or not(
var251 = 1)) and (var127 = 1 or not(var251 = 1)) and (var130 = 1 or not(var252 =
 1)) and (var131 = 1 or not(var252 = 1)) and (var134 = 1 or not(var252 = 1)) and
 (var135 = 1 or not(var252 = 1)) and (var138 = 1 or not(var252 = 1)) and (var140
 = 1 or not(var252 = 1)) and (var141 = 1 or not(var252 = 1)) and (var143 = 1 or
not(var252 = 1)) and (var146 = 1 or not(var252 = 1)) and (var148 = 1 or not(
var252 = 1)) and (var150 = 1 or not(var252 = 1)) and (var152 = 1 or not(var252 =
 1)) and (var154 = 1 or not(var252 = 1)) and (var155 = 1 or not(var252 = 1)) and
 (var157 = 1 or not(var252 = 1)) and (var159 = 1 or not(var252 = 1)) and (var161
 = 1 or not(var252 = 1)) and (var163 = 1 or not(var252 = 1)) and (var166 = 1 or
not(var252 = 1)) and (var168 = 1 or not(var252 = 1)) and (var170 = 1 or not(
var252 = 1)) and (var172 = 1 or not(var252 = 1)) and (var174 = 1 or not(var252 =
 1)) and (var176 = 1 or not(var252 = 1)) and (var177 = 1 or not(var252 = 1)) and
 (var179 = 1 or not(var252 = 1)) and (var182 = 1 or not(var252 = 1)) and (var184
 = 1 or not(var252 = 1)) and (var185 = 1 or not(var252 = 1)) and (var187 = 1 or
not(var252 = 1)) and (var190 = 1 or not(var252 = 1)) and (var191 = 1 or not(
var252 = 1)) and (var1 = 1 or not(var253 = 1)) and (var4 = 1 or not(var253 = 1))
 and (var5 = 1 or not(var253 = 1)) and (var7 = 1 or not(var253 = 1)) and (var9 =
 1 or not(var253 = 1)) and (var11 = 1 or not(var253 = 1)) and (var13 = 1 or not(
var253 = 1)) and (var16 = 1 or not(var253 = 1)) and (var18 = 1 or not(var253 = 1
)) and (var20 = 1 or not(var253 = 1)) and (var22 = 1 or not(var253 = 1)) and (
var24 = 1 or not(var253 = 1)) and (var26 = 1 or not(var253 = 1)) and (var27 = 1
or not(var253 = 1)) and (var29 = 1 or not(var253 = 1)) and (var31 = 1 or not(
var253 = 1)) and (var33 = 1 or not(var253 = 1)) and (var35 = 1 or not(var253 = 1
)) and (var38 = 1 or not(var253 = 1)) and (var40 = 1 or not(var253 = 1)) and (
var42 = 1 or not(var253 = 1)) and (var43 = 1 or not(var253 = 1)) and (var46 = 1
or not(var253 = 1)) and (var47 = 1 or not(var253 = 1)) and (var49 = 1 or not(
var253 = 1)) and (var51 = 1 or not(var253 = 1)) and (var54 = 1 or not(var253 = 1
)) and (var56 = 1 or not(var253 = 1)) and (var58 = 1 or not(var253 = 1)) and (
var60 = 1 or not(var253 = 1)) and (var61 = 1 or not(var253 = 1)) and (var63 = 1
or not(var253 = 1)) and (var65 = 1 or not(var254 = 1)) and (var68 = 1 or not(
var254 = 1)) and (var69 = 1 or not(var254 = 1)) and (var71 = 1 or not(var254 = 1
)) and (var73 = 1 or not(var254 = 1)) and (var75 = 1 or not(var254 = 1)) and (
var77 = 1 or not(var254 = 1)) and (var80 = 1 or not(var254 = 1)) and (var82 = 1
or not(var254 = 1)) and (var84 = 1 or not(var254 = 1)) and (var86 = 1 or not(
var254 = 1)) and (var88 = 1 or not(var254 = 1)) and (var90 = 1 or not(var254 = 1
)) and (var91 = 1 or not(var254 = 1)) and (var93 = 1 or not(var254 = 1)) and (
var95 = 1 or not(var254 = 1)) and (var97 = 1 or not(var254 = 1)) and (var99 = 1
or not(var254 = 1)) and (var102 = 1 or not(var254 = 1)) and (var104 = 1 or not(
var254 = 1)) and (var106 = 1 or not(var254 = 1)) and (var107 = 1 or not(var254 =
 1)) and (var110 = 1 or not(var254 = 1)) and (var111 = 1 or not(var254 = 1)) and
 (var113 = 1 or not(var254 = 1)) and (var115 = 1 or not(var254 = 1)) and (var118
 = 1 or not(var254 = 1)) and (var120 = 1 or not(var254 = 1)) and (var122 = 1 or
not(var254 = 1)) and (var124 = 1 or not(var254 = 1)) and (var125 = 1 or not(
var254 = 1)) and (var127 = 1 or not(var254 = 1)) and (var129 = 1 or not(var255 =
 1)) and (var132 = 1 or not(var255 = 1)) and (var133 = 1 or not(var255 = 1)) and
 (var135 = 1 or not(var255 = 1)) and (var137 = 1 or not(var255 = 1)) and (var139
 = 1 or not(var255 = 1)) and (var141 = 1 or not(var255 = 1)) and (var144 = 1 or
not(var255 = 1)) and (var146 = 1 or not(var255 = 1)) and (var148 = 1 or not(
var255 = 1)) and (var150 = 1 or not(var255 = 1)) and (var152 = 1 or not(var255 =
 1)) and (var154 = 1 or not(var255 = 1)) and (var155 = 1 or not(var255 = 1)) and
 (var157 = 1 or not(var255 = 1)) and (var159 = 1 or not(var255 = 1)) and (var161
 = 1 or not(var255 = 1)) and (var163 = 1 or not(var255 = 1)) and (var166 = 1 or
not(var255 = 1)) and (var168 = 1 or not(var255 = 1)) and (var170 = 1 or not(
var255 = 1)) and (var171 = 1 or not(var255 = 1)) and (var174 = 1 or not(var255 =
 1)) and (var175 = 1 or not(var255 = 1)) and (var177 = 1 or not(var255 = 1)) and
 (var179 = 1 or not(var255 = 1)) and (var182 = 1 or not(var255 = 1)) and (var184
 = 1 or not(var255 = 1)) and (var186 = 1 or not(var255 = 1)) and (var188 = 1 or
not(var255 = 1)) and (var189 = 1 or not(var255 = 1)) and (var191 = 1 or not(
var255 = 1)) and (var2 = 1 or not(var256 = 1)) and (var4 = 1 or not(var256 = 1))
 and (var6 = 1 or not(var256 = 1)) and (var7 = 1 or not(var256 = 1)) and (var10
= 1 or not(var256 = 1)) and (var12 = 1 or not(var256 = 1)) and (var13 = 1 or not
(var256 = 1)) and (var16 = 1 or not(var256 = 1)) and (var17 = 1 or not(var256 =
1)) and (var19 = 1 or not(var256 = 1)) and (var21 = 1 or not(var256 = 1)) and (
var24 = 1 or not(var256 = 1)) and (var25 = 1 or not(var256 = 1)) and (var28 = 1
or not(var256 = 1)) and (var30 = 1 or not(var256 = 1)) and (var32 = 1 or not(
var256 = 1)) and (var34 = 1 or not(var256 = 1)) and (var36 = 1 or not(var256 = 1
)) and (var37 = 1 or not(var256 = 1)) and (var39 = 1 or not(var256 = 1)) and (
var42 = 1 or not(var256 = 1)) and (var44 = 1 or not(var256 = 1)) and (var46 = 1
or not(var256 = 1)) and (var48 = 1 or not(var256 = 1)) and (var50 = 1 or not(
var256 = 1)) and (var51 = 1 or not(var256 = 1)) and (var54 = 1 or not(var256 = 1
)) and (var56 = 1 or not(var256 = 1)) and (var58 = 1 or not(var256 = 1)) and (
var59 = 1 or not(var256 = 1)) and (var61 = 1 or not(var256 = 1)) and (var63 = 1
or not(var256 = 1)) and (var66 = 1 or not(var257 = 1)) and (var68 = 1 or not(
var257 = 1)) and (var70 = 1 or not(var257 = 1)) and (var71 = 1 or not(var257 = 1
)) and (var74 = 1 or not(var257 = 1)) and (var76 = 1 or not(var257 = 1)) and (
var77 = 1 or not(var257 = 1)) and (var80 = 1 or not(var257 = 1)) and (var81 = 1
or not(var257 = 1)) and (var83 = 1 or not(var257 = 1)) and (var85 = 1 or not(
var257 = 1)) and (var88 = 1 or not(var257 = 1)) and (var89 = 1 or not(var257 = 1
)) and (var92 = 1 or not(var257 = 1)) and (var94 = 1 or not(var257 = 1)) and (
var96 = 1 or not(var257 = 1)) and (var98 = 1 or not(var257 = 1)) and (var100 = 1
 or not(var257 = 1)) and (var101 = 1 or not(var257 = 1)) and (var103 = 1 or not(
var257 = 1)) and (var106 = 1 or not(var257 = 1)) and (var108 = 1 or not(var257 =
 1)) and (var110 = 1 or not(var257 = 1)) and (var112 = 1 or not(var257 = 1)) and
 (var114 = 1 or not(var257 = 1)) and (var115 = 1 or not(var257 = 1)) and (var118
 = 1 or not(var257 = 1)) and (var120 = 1 or not(var257 = 1)) and (var122 = 1 or
not(var257 = 1)) and (var123 = 1 or not(var257 = 1)) and (var125 = 1 or not(
var257 = 1)) and (var127 = 1 or not(var257 = 1)) and (var130 = 1 or not(var258 =
 1)) and (var132 = 1 or not(var258 = 1)) and (var134 = 1 or not(var258 = 1)) and
 (var135 = 1 or not(var258 = 1)) and (var138 = 1 or not(var258 = 1)) and (var140
 = 1 or not(var258 = 1)) and (var141 = 1 or not(var258 = 1)) and (var144 = 1 or
not(var258 = 1)) and (var145 = 1 or not(var258 = 1)) and (var147 = 1 or not(
var258 = 1)) and (var149 = 1 or not(var258 = 1)) and (var152 = 1 or not(var258 =
 1)) and (var153 = 1 or not(var258 = 1)) and (var156 = 1 or not(var258 = 1)) and
 (var158 = 1 or not(var258 = 1)) and (var160 = 1 or not(var258 = 1)) and (var162
 = 1 or not(var258 = 1)) and (var164 = 1 or not(var258 = 1)) and (var165 = 1 or
not(var258 = 1)) and (var167 = 1 or not(var258 = 1)) and (var170 = 1 or not(
var258 = 1)) and (var172 = 1 or not(var258 = 1)) and (var174 = 1 or not(var258 =
 1)) and (var176 = 1 or not(var258 = 1)) and (var178 = 1 or not(var258 = 1)) and
 (var179 = 1 or not(var258 = 1)) and (var182 = 1 or not(var258 = 1)) and (var184
 = 1 or not(var258 = 1)) and (var186 = 1 or not(var258 = 1)) and (var187 = 1 or
not(var258 = 1)) and (var189 = 1 or not(var258 = 1)) and (var191 = 1 or not(
var258 = 1)) and (var1 = 1 or not(var259 = 1)) and (var4 = 1 or not(var259 = 1))
 and (var5 = 1 or not(var259 = 1)) and (var7 = 1 or not(var259 = 1)) and (var10
= 1 or not(var259 = 1)) and (var11 = 1 or not(var259 = 1)) and (var14 = 1 or not
(var259 = 1)) and (var15 = 1 or not(var259 = 1)) and (var17 = 1 or not(var259 =
1)) and (var20 = 1 or not(var259 = 1)) and (var22 = 1 or not(var259 = 1)) and (
var24 = 1 or not(var259 = 1)) and (var26 = 1 or not(var259 = 1)) and (var27 = 1
or not(var259 = 1)) and (var30 = 1 or not(var259 = 1)) and (var32 = 1 or not(
var259 = 1)) and (var34 = 1 or not(var259 = 1)) and (var35 = 1 or not(var259 = 1
)) and (var37 = 1 or not(var259 = 1)) and (var40 = 1 or not(var259 = 1)) and (
var41 = 1 or not(var259 = 1)) and (var44 = 1 or not(var259 = 1)) and (var46 = 1
or not(var259 = 1)) and (var48 = 1 or not(var259 = 1)) and (var49 = 1 or not(
var259 = 1)) and (var51 = 1 or not(var259 = 1)) and (var54 = 1 or not(var259 = 1
)) and (var56 = 1 or not(var259 = 1)) and (var58 = 1 or not(var259 = 1)) and (
var59 = 1 or not(var259 = 1)) and (var61 = 1 or not(var259 = 1)) and (var63 = 1
or not(var259 = 1)) and (var65 = 1 or not(var260 = 1)) and (var68 = 1 or not(
var260 = 1)) and (var69 = 1 or not(var260 = 1)) and (var71 = 1 or not(var260 = 1
)) and (var74 = 1 or not(var260 = 1)) and (var75 = 1 or not(var260 = 1)) and (
var78 = 1 or not(var260 = 1)) and (var79 = 1 or not(var260 = 1)) and (var81 = 1
or not(var260 = 1)) and (var84 = 1 or not(var260 = 1)) and (var86 = 1 or not(
var260 = 1)) and (var88 = 1 or not(var260 = 1)) and (var90 = 1 or not(var260 = 1
)) and (var91 = 1 or not(var260 = 1)) and (var94 = 1 or not(var260 = 1)) and (
var96 = 1 or not(var260 = 1)) and (var98 = 1 or not(var260 = 1)) and (var99 = 1
or not(var260 = 1)) and (var101 = 1 or not(var260 = 1)) and (var104 = 1 or not(
var260 = 1)) and (var105 = 1 or not(var260 = 1)) and (var108 = 1 or not(var260 =
 1)) and (var110 = 1 or not(var260 = 1)) and (var112 = 1 or not(var260 = 1)) and
 (var113 = 1 or not(var260 = 1)) and (var115 = 1 or not(var260 = 1)) and (var118
 = 1 or not(var260 = 1)) and (var120 = 1 or not(var260 = 1)) and (var122 = 1 or
not(var260 = 1)) and (var123 = 1 or not(var260 = 1)) and (var125 = 1 or not(
var260 = 1)) and (var127 = 1 or not(var260 = 1)) and (var129 = 1 or not(var261 =
 1)) and (var132 = 1 or not(var261 = 1)) and (var133 = 1 or not(var261 = 1)) and
 (var135 = 1 or not(var261 = 1)) and (var138 = 1 or not(var261 = 1)) and (var139
 = 1 or not(var261 = 1)) and (var142 = 1 or not(var261 = 1)) and (var143 = 1 or
not(var261 = 1)) and (var145 = 1 or not(var261 = 1)) and (var148 = 1 or not(
var261 = 1)) and (var150 = 1 or not(var261 = 1)) and (var152 = 1 or not(var261 =
 1)) and (var154 = 1 or not(var261 = 1)) and (var155 = 1 or not(var261 = 1)) and
 (var158 = 1 or not(var261 = 1)) and (var160 = 1 or not(var261 = 1)) and (var162
 = 1 or not(var261 = 1)) and (var163 = 1 or not(var261 = 1)) and (var165 = 1 or
not(var261 = 1)) and (var168 = 1 or not(var261 = 1)) and (var169 = 1 or not(
var261 = 1)) and (var172 = 1 or not(var261 = 1)) and (var174 = 1 or not(var261 =
 1)) and (var176 = 1 or not(var261 = 1)) and (var177 = 1 or not(var261 = 1)) and
 (var179 = 1 or not(var261 = 1)) and (var182 = 1 or not(var261 = 1)) and (var184
 = 1 or not(var261 = 1)) and (var186 = 1 or not(var261 = 1)) and (var187 = 1 or
not(var261 = 1)) and (var189 = 1 or not(var261 = 1)) and (var191 = 1 or not(
var261 = 1)) and (var2 = 1 or not(var262 = 1)) and (var4 = 1 or not(var262 = 1))
 and (var6 = 1 or not(var262 = 1)) and (var7 = 1 or not(var262 = 1)) and (var10
= 1 or not(var262 = 1)) and (var12 = 1 or not(var262 = 1)) and (var14 = 1 or not
(var262 = 1)) and (var15 = 1 or not(var262 = 1)) and (var17 = 1 or not(var262 =
1)) and (var19 = 1 or not(var262 = 1)) and (var22 = 1 or not(var262 = 1)) and (
var24 = 1 or not(var262 = 1)) and (var25 = 1 or not(var262 = 1)) and (var27 = 1
or not(var262 = 1)) and (var29 = 1 or not(var262 = 1)) and (var31 = 1 or not(
var262 = 1)) and (var34 = 1 or not(var262 = 1)) and (var35 = 1 or not(var262 = 1
)) and (var37 = 1 or not(var262 = 1)) and (var39 = 1 or not(var262 = 1)) and (
var42 = 1 or not(var262 = 1)) and (var43 = 1 or not(var262 = 1)) and (var46 = 1
or not(var262 = 1)) and (var48 = 1 or not(var262 = 1)) and (var50 = 1 or not(
var262 = 1)) and (var52 = 1 or not(var262 = 1)) and (var53 = 1 or not(var262 = 1
)) and (var55 = 1 or not(var262 = 1)) and (var58 = 1 or not(var262 = 1)) and (
var59 = 1 or not(var262 = 1)) and (var61 = 1 or not(var262 = 1)) and (var63 = 1
or not(var262 = 1)) and (var66 = 1 or not(var263 = 1)) and (var68 = 1 or not(
var263 = 1)) and (var70 = 1 or not(var263 = 1)) and (var71 = 1 or not(var263 = 1
)) and (var74 = 1 or not(var263 = 1)) and (var76 = 1 or not(var263 = 1)) and (
var78 = 1 or not(var263 = 1)) and (var79 = 1 or not(var263 = 1)) and (var81 = 1
or not(var263 = 1)) and (var83 = 1 or not(var263 = 1)) and (var86 = 1 or not(
var263 = 1)) and (var88 = 1 or not(var263 = 1)) and (var89 = 1 or not(var263 = 1
)) and (var91 = 1 or not(var263 = 1)) and (var93 = 1 or not(var263 = 1)) and (
var95 = 1 or not(var263 = 1)) and (var98 = 1 or not(var263 = 1)) and (var99 = 1
or not(var263 = 1)) and (var101 = 1 or not(var263 = 1)) and (var103 = 1 or not(
var263 = 1)) and (var106 = 1 or not(var263 = 1)) and (var107 = 1 or not(var263 =
 1)) and (var110 = 1 or not(var263 = 1)) and (var112 = 1 or not(var263 = 1)) and
 (var114 = 1 or not(var263 = 1)) and (var116 = 1 or not(var263 = 1)) and (var117
 = 1 or not(var263 = 1)) and (var119 = 1 or not(var263 = 1)) and (var122 = 1 or
not(var263 = 1)) and (var123 = 1 or not(var263 = 1)) and (var125 = 1 or not(
var263 = 1)) and (var127 = 1 or not(var263 = 1)) and (var130 = 1 or not(var264 =
 1)) and (var132 = 1 or not(var264 = 1)) and (var134 = 1 or not(var264 = 1)) and
 (var135 = 1 or not(var264 = 1)) and (var138 = 1 or not(var264 = 1)) and (var140
 = 1 or not(var264 = 1)) and (var142 = 1 or not(var264 = 1)) and (var143 = 1 or
not(var264 = 1)) and (var145 = 1 or not(var264 = 1)) and (var147 = 1 or not(
var264 = 1)) and (var150 = 1 or not(var264 = 1)) and (var152 = 1 or not(var264 =
 1)) and (var153 = 1 or not(var264 = 1)) and (var155 = 1 or not(var264 = 1)) and
 (var157 = 1 or not(var264 = 1)) and (var159 = 1 or not(var264 = 1)) and (var162
 = 1 or not(var264 = 1)) and (var163 = 1 or not(var264 = 1)) and (var165 = 1 or
not(var264 = 1)) and (var167 = 1 or not(var264 = 1)) and (var170 = 1 or not(
var264 = 1)) and (var171 = 1 or not(var264 = 1)) and (var174 = 1 or not(var264 =
 1)) and (var176 = 1 or not(var264 = 1)) and (var178 = 1 or not(var264 = 1)) and
 (var180 = 1 or not(var264 = 1)) and (var181 = 1 or not(var264 = 1)) and (var183
 = 1 or not(var264 = 1)) and (var186 = 1 or not(var264 = 1)) and (var187 = 1 or
not(var264 = 1)) and (var189 = 1 or not(var264 = 1)) and (var191 = 1 or not(
var264 = 1)) and (var2 = 1 or not(var265 = 1)) and (var3 = 1 or not(var265 = 1))
 and (var5 = 1 or not(var265 = 1)) and (var7 = 1 or not(var265 = 1)) and (var10
= 1 or not(var265 = 1)) and (var11 = 1 or not(var265 = 1)) and (var13 = 1 or not
(var265 = 1)) and (var16 = 1 or not(var265 = 1)) and (var18 = 1 or not(var265 =
1)) and (var20 = 1 or not(var265 = 1)) and (var22 = 1 or not(var265 = 1)) and (
var23 = 1 or not(var265 = 1)) and (var26 = 1 or not(var265 = 1)) and (var27 = 1
or not(var265 = 1)) and (var30 = 1 or not(var265 = 1)) and (var32 = 1 or not(
var265 = 1)) and (var33 = 1 or not(var265 = 1)) and (var35 = 1 or not(var265 = 1
)) and (var37 = 1 or not(var265 = 1)) and (var40 = 1 or not(var265 = 1)) and (
var41 = 1 or not(var265 = 1)) and (var43 = 1 or not(var265 = 1)) and (var46 = 1
or not(var265 = 1)) and (var48 = 1 or not(var265 = 1)) and (var49 = 1 or not(
var265 = 1)) and (var51 = 1 or not(var265 = 1)) and (var53 = 1 or not(var265 = 1
)) and (var55 = 1 or not(var265 = 1)) and (var57 = 1 or not(var265 = 1)) and (
var60 = 1 or not(var265 = 1)) and (var62 = 1 or not(var265 = 1)) and (var64 = 1
or not(var265 = 1)) and (var66 = 1 or not(var266 = 1)) and (var67 = 1 or not(
var266 = 1)) and (var69 = 1 or not(var266 = 1)) and (var71 = 1 or not(var266 = 1
)) and (var74 = 1 or not(var266 = 1)) and (var75 = 1 or not(var266 = 1)) and (
var77 = 1 or not(var266 = 1)) and (var80 = 1 or not(var266 = 1)) and (var82 = 1
or not(var266 = 1)) and (var84 = 1 or not(var266 = 1)) and (var86 = 1 or not(
var266 = 1)) and (var87 = 1 or not(var266 = 1)) and (var90 = 1 or not(var266 = 1
)) and (var91 = 1 or not(var266 = 1)) and (var94 = 1 or not(var266 = 1)) and (
var96 = 1 or not(var266 = 1)) and (var97 = 1 or not(var266 = 1)) and (var99 = 1
or not(var266 = 1)) and (var101 = 1 or not(var266 = 1)) and (var104 = 1 or not(
var266 = 1)) and (var105 = 1 or not(var266 = 1)) and (var107 = 1 or not(var266 =
 1)) and (var110 = 1 or not(var266 = 1)) and (var112 = 1 or not(var266 = 1)) and
 (var113 = 1 or not(var266 = 1)) and (var115 = 1 or not(var266 = 1)) and (var117
 = 1 or not(var266 = 1)) and (var119 = 1 or not(var266 = 1)) and (var121 = 1 or
not(var266 = 1)) and (var124 = 1 or not(var266 = 1)) and (var126 = 1 or not(
var266 = 1)) and (var128 = 1 or not(var266 = 1)) and (var130 = 1 or not(var267 =
 1)) and (var131 = 1 or not(var267 = 1)) and (var133 = 1 or not(var267 = 1)) and
 (var135 = 1 or not(var267 = 1)) and (var138 = 1 or not(var267 = 1)) and (var139
 = 1 or not(var267 = 1)) and (var141 = 1 or not(var267 = 1)) and (var144 = 1 or
not(var267 = 1)) and (var146 = 1 or not(var267 = 1)) and (var148 = 1 or not(
var267 = 1)) and (var150 = 1 or not(var267 = 1)) and (var151 = 1 or not(var267 =
 1)) and (var154 = 1 or not(var267 = 1)) and (var155 = 1 or not(var267 = 1)) and
 (var158 = 1 or not(var267 = 1)) and (var160 = 1 or not(var267 = 1)) and (var161
 = 1 or not(var267 = 1)) and (var163 = 1 or not(var267 = 1)) and (var165 = 1 or
not(var267 = 1)) and (var168 = 1 or not(var267 = 1)) and (var169 = 1 or not(
var267 = 1)) and (var171 = 1 or not(var267 = 1)) and (var174 = 1 or not(var267 =
 1)) and (var176 = 1 or not(var267 = 1)) and (var177 = 1 or not(var267 = 1)) and
 (var179 = 1 or not(var267 = 1)) and (var181 = 1 or not(var267 = 1)) and (var183
 = 1 or not(var267 = 1)) and (var185 = 1 or not(var267 = 1)) and (var188 = 1 or
not(var267 = 1)) and (var190 = 1 or not(var267 = 1)) and (var192 = 1 or not(
var267 = 1)) and (var1 = 1 or not(var268 = 1)) and (var4 = 1 or not(var268 = 1))
 and (var6 = 1 or not(var268 = 1)) and (var7 = 1 or not(var268 = 1)) and (var10
= 1 or not(var268 = 1)) and (var12 = 1 or not(var268 = 1)) and (var14 = 1 or not
(var268 = 1)) and (var15 = 1 or not(var268 = 1)) and (var18 = 1 or not(var268 =
1)) and (var20 = 1 or not(var268 = 1)) and (var22 = 1 or not(var268 = 1)) and (
var24 = 1 or not(var268 = 1)) and (var26 = 1 or not(var268 = 1)) and (var28 = 1
or not(var268 = 1)) and (var30 = 1 or not(var268 = 1)) and (var31 = 1 or not(
var268 = 1)) and (var33 = 1 or not(var268 = 1)) and (var36 = 1 or not(var268 = 1
)) and (var38 = 1 or not(var268 = 1)) and (var39 = 1 or not(var268 = 1)) and (
var42 = 1 or not(var268 = 1)) and (var44 = 1 or not(var268 = 1)) and (var46 = 1
or not(var268 = 1)) and (var47 = 1 or not(var268 = 1)) and (var49 = 1 or not(
var268 = 1)) and (var52 = 1 or not(var268 = 1)) and (var54 = 1 or not(var268 = 1
)) and (var55 = 1 or not(var268 = 1)) and (var57 = 1 or not(var268 = 1)) and (
var59 = 1 or not(var268 = 1)) and (var61 = 1 or not(var268 = 1)) and (var63 = 1
or not(var268 = 1)) and (var65 = 1 or not(var269 = 1)) and (var68 = 1 or not(
var269 = 1)) and (var70 = 1 or not(var269 = 1)) and (var71 = 1 or not(var269 = 1
)) and (var74 = 1 or not(var269 = 1)) and (var76 = 1 or not(var269 = 1)) and (
var78 = 1 or not(var269 = 1)) and (var79 = 1 or not(var269 = 1)) and (var82 = 1
or not(var269 = 1)) and (var84 = 1 or not(var269 = 1)) and (var86 = 1 or not(
var269 = 1)) and (var88 = 1 or not(var269 = 1)) and (var90 = 1 or not(var269 = 1
)) and (var92 = 1 or not(var269 = 1)) and (var94 = 1 or not(var269 = 1)) and (
var95 = 1 or not(var269 = 1)) and (var97 = 1 or not(var269 = 1)) and (var100 = 1
 or not(var269 = 1)) and (var102 = 1 or not(var269 = 1)) and (var103 = 1 or not(
var269 = 1)) and (var106 = 1 or not(var269 = 1)) and (var108 = 1 or not(var269 =
 1)) and (var110 = 1 or not(var269 = 1)) and (var111 = 1 or not(var269 = 1)) and
 (var113 = 1 or not(var269 = 1)) and (var116 = 1 or not(var269 = 1)) and (var118
 = 1 or not(var269 = 1)) and (var119 = 1 or not(var269 = 1)) and (var121 = 1 or
not(var269 = 1)) and (var123 = 1 or not(var269 = 1)) and (var125 = 1 or not(
var269 = 1)) and (var127 = 1 or not(var269 = 1)) and (var129 = 1 or not(var270 =
 1)) and (var132 = 1 or not(var270 = 1)) and (var134 = 1 or not(var270 = 1)) and
 (var135 = 1 or not(var270 = 1)) and (var138 = 1 or not(var270 = 1)) and (var140
 = 1 or not(var270 = 1)) and (var142 = 1 or not(var270 = 1)) and (var143 = 1 or
not(var270 = 1)) and (var146 = 1 or not(var270 = 1)) and (var148 = 1 or not(
var270 = 1)) and (var150 = 1 or not(var270 = 1)) and (var152 = 1 or not(var270 =
 1)) and (var154 = 1 or not(var270 = 1)) and (var156 = 1 or not(var270 = 1)) and
 (var158 = 1 or not(var270 = 1)) and (var159 = 1 or not(var270 = 1)) and (var161
 = 1 or not(var270 = 1)) and (var164 = 1 or not(var270 = 1)) and (var166 = 1 or
not(var270 = 1)) and (var167 = 1 or not(var270 = 1)) and (var170 = 1 or not(
var270 = 1)) and (var172 = 1 or not(var270 = 1)) and (var174 = 1 or not(var270 =
 1)) and (var175 = 1 or not(var270 = 1)) and (var177 = 1 or not(var270 = 1)) and
 (var180 = 1 or not(var270 = 1)) and (var182 = 1 or not(var270 = 1)) and (var183
 = 1 or not(var270 = 1)) and (var185 = 1 or not(var270 = 1)) and (var187 = 1 or
not(var270 = 1)) and (var189 = 1 or not(var270 = 1)) and (var191 = 1 or not(
var270 = 1)) and (var1 = 1 or not(var271 = 1)) and (var4 = 1 or not(var271 = 1))
 and (var5 = 1 or not(var271 = 1)) and (var8 = 1 or not(var271 = 1)) and (var10
= 1 or not(var271 = 1)) and (var11 = 1 or not(var271 = 1)) and (var13 = 1 or not
(var271 = 1)) and (var16 = 1 or not(var271 = 1)) and (var18 = 1 or not(var271 =
1)) and (var19 = 1 or not(var271 = 1)) and (var22 = 1 or not(var271 = 1)) and (
var24 = 1 or not(var271 = 1)) and (var26 = 1 or not(var271 = 1)) and (var27 = 1
or not(var271 = 1)) and (var29 = 1 or not(var271 = 1)) and (var31 = 1 or not(
var271 = 1)) and (var34 = 1 or not(var271 = 1)) and (var36 = 1 or not(var271 = 1
)) and (var38 = 1 or not(var271 = 1)) and (var39 = 1 or not(var271 = 1)) and (
var42 = 1 or not(var271 = 1)) and (var43 = 1 or not(var271 = 1)) and (var46 = 1
or not(var271 = 1)) and (var47 = 1 or not(var271 = 1)) and (var50 = 1 or not(
var271 = 1)) and (var51 = 1 or not(var271 = 1)) and (var54 = 1 or not(var271 = 1
)) and (var55 = 1 or not(var271 = 1)) and (var58 = 1 or not(var271 = 1)) and (
var59 = 1 or not(var271 = 1)) and (var61 = 1 or not(var271 = 1)) and (var63 = 1
or not(var271 = 1)) and (var65 = 1 or not(var272 = 1)) and (var68 = 1 or not(
var272 = 1)) and (var69 = 1 or not(var272 = 1)) and (var72 = 1 or not(var272 = 1
)) and (var74 = 1 or not(var272 = 1)) and (var75 = 1 or not(var272 = 1)) and (
var77 = 1 or not(var272 = 1)) and (var80 = 1 or not(var272 = 1)) and (var82 = 1
or not(var272 = 1)) and (var83 = 1 or not(var272 = 1)) and (var86 = 1 or not(
var272 = 1)) and (var88 = 1 or not(var272 = 1)) and (var90 = 1 or not(var272 = 1
)) and (var91 = 1 or not(var272 = 1)) and (var93 = 1 or not(var272 = 1)) and (
var95 = 1 or not(var272 = 1)) and (var98 = 1 or not(var272 = 1)) and (var100 = 1
 or not(var272 = 1)) and (var102 = 1 or not(var272 = 1)) and (var103 = 1 or not(
var272 = 1)) and (var106 = 1 or not(var272 = 1)) and (var107 = 1 or not(var272 =
 1)) and (var110 = 1 or not(var272 = 1)) and (var111 = 1 or not(var272 = 1)) and
 (var114 = 1 or not(var272 = 1)) and (var115 = 1 or not(var272 = 1)) and (var118
 = 1 or not(var272 = 1)) and (var119 = 1 or not(var272 = 1)) and (var122 = 1 or
not(var272 = 1)) and (var123 = 1 or not(var272 = 1)) and (var125 = 1 or not(
var272 = 1)) and (var127 = 1 or not(var272 = 1)) and (var129 = 1 or not(var273 =
 1)) and (var132 = 1 or not(var273 = 1)) and (var133 = 1 or not(var273 = 1)) and
 (var136 = 1 or not(var273 = 1)) and (var138 = 1 or not(var273 = 1)) and (var139
 = 1 or not(var273 = 1)) and (var141 = 1 or not(var273 = 1)) and (var144 = 1 or
not(var273 = 1)) and (var146 = 1 or not(var273 = 1)) and (var147 = 1 or not(
var273 = 1)) and (var150 = 1 or not(var273 = 1)) and (var152 = 1 or not(var273 =
 1)) and (var154 = 1 or not(var273 = 1)) and (var155 = 1 or not(var273 = 1)) and
 (var157 = 1 or not(var273 = 1)) and (var159 = 1 or not(var273 = 1)) and (var162
 = 1 or not(var273 = 1)) and (var164 = 1 or not(var273 = 1)) and (var166 = 1 or
not(var273 = 1)) and (var167 = 1 or not(var273 = 1)) and (var170 = 1 or not(
var273 = 1)) and (var171 = 1 or not(var273 = 1)) and (var174 = 1 or not(var273 =
 1)) and (var175 = 1 or not(var273 = 1)) and (var178 = 1 or not(var273 = 1)) and
 (var179 = 1 or not(var273 = 1)) and (var182 = 1 or not(var273 = 1)) and (var183
 = 1 or not(var273 = 1)) and (var186 = 1 or not(var273 = 1)) and (var187 = 1 or
not(var273 = 1)) and (var189 = 1 or not(var273 = 1)) and (var191 = 1 or not(
var273 = 1)) and (var1 = 1 or not(var274 = 1)) and (var4 = 1 or not(var274 = 1))
 and (var6 = 1 or not(var274 = 1)) and (var7 = 1 or not(var274 = 1)) and (var9 =
 1 or not(var274 = 1)) and (var12 = 1 or not(var274 = 1)) and (var13 = 1 or not(
var274 = 1)) and (var16 = 1 or not(var274 = 1)) and (var18 = 1 or not(var274 = 1
)) and (var19 = 1 or not(var274 = 1)) and (var21 = 1 or not(var274 = 1)) and (
var24 = 1 or not(var274 = 1)) and (var25 = 1 or not(var274 = 1)) and (var27 = 1
or not(var274 = 1)) and (var30 = 1 or not(var274 = 1)) and (var31 = 1 or not(
var274 = 1)) and (var33 = 1 or not(var274 = 1)) and (var35 = 1 or not(var274 = 1
)) and (var38 = 1 or not(var274 = 1)) and (var39 = 1 or not(var274 = 1)) and (
var41 = 1 or not(var274 = 1)) and (var44 = 1 or not(var274 = 1)) and (var46 = 1
or not(var274 = 1)) and (var48 = 1 or not(var274 = 1)) and (var49 = 1 or not(
var274 = 1)) and (var51 = 1 or not(var274 = 1)) and (var54 = 1 or not(var274 = 1
)) and (var56 = 1 or not(var274 = 1)) and (var58 = 1 or not(var274 = 1)) and (
var59 = 1 or not(var274 = 1)) and (var61 = 1 or not(var274 = 1)) and (var63 = 1
or not(var274 = 1)) and (var65 = 1 or not(var275 = 1)) and (var68 = 1 or not(
var275 = 1)) and (var70 = 1 or not(var275 = 1)) and (var71 = 1 or not(var275 = 1
)) and (var73 = 1 or not(var275 = 1)) and (var76 = 1 or not(var275 = 1)) and (
var77 = 1 or not(var275 = 1)) and (var80 = 1 or not(var275 = 1)) and (var82 = 1
or not(var275 = 1)) and (var83 = 1 or not(var275 = 1)) and (var85 = 1 or not(
var275 = 1)) and (var88 = 1 or not(var275 = 1)) and (var89 = 1 or not(var275 = 1
)) and (var91 = 1 or not(var275 = 1)) and (var94 = 1 or not(var275 = 1)) and (
var95 = 1 or not(var275 = 1)) and (var97 = 1 or not(var275 = 1)) and (var99 = 1
or not(var275 = 1)) and (var102 = 1 or not(var275 = 1)) and (var103 = 1 or not(
var275 = 1)) and (var105 = 1 or not(var275 = 1)) and (var108 = 1 or not(var275 =
 1)) and (var110 = 1 or not(var275 = 1)) and (var112 = 1 or not(var275 = 1)) and
 (var113 = 1 or not(var275 = 1)) and (var115 = 1 or not(var275 = 1)) and (var118
 = 1 or not(var275 = 1)) and (var120 = 1 or not(var275 = 1)) and (var122 = 1 or
not(var275 = 1)) and (var123 = 1 or not(var275 = 1)) and (var125 = 1 or not(
var275 = 1)) and (var127 = 1 or not(var275 = 1)) and (var129 = 1 or not(var276 =
 1)) and (var132 = 1 or not(var276 = 1)) and (var134 = 1 or not(var276 = 1)) and
 (var135 = 1 or not(var276 = 1)) and (var137 = 1 or not(var276 = 1)) and (var140
 = 1 or not(var276 = 1)) and (var141 = 1 or not(var276 = 1)) and (var144 = 1 or
not(var276 = 1)) and (var146 = 1 or not(var276 = 1)) and (var147 = 1 or not(
var276 = 1)) and (var149 = 1 or not(var276 = 1)) and (var152 = 1 or not(var276 =
 1)) and (var153 = 1 or not(var276 = 1)) and (var155 = 1 or not(var276 = 1)) and
 (var158 = 1 or not(var276 = 1)) and (var159 = 1 or not(var276 = 1)) and (var161
 = 1 or not(var276 = 1)) and (var163 = 1 or not(var276 = 1)) and (var166 = 1 or
not(var276 = 1)) and (var167 = 1 or not(var276 = 1)) and (var169 = 1 or not(
var276 = 1)) and (var172 = 1 or not(var276 = 1)) and (var174 = 1 or not(var276 =
 1)) and (var176 = 1 or not(var276 = 1)) and (var177 = 1 or not(var276 = 1)) and
 (var179 = 1 or not(var276 = 1)) and (var182 = 1 or not(var276 = 1)) and (var184
 = 1 or not(var276 = 1)) and (var186 = 1 or not(var276 = 1)) and (var187 = 1 or
not(var276 = 1)) and (var189 = 1 or not(var276 = 1)) and (var191 = 1 or not(
var276 = 1)) and (var2 = 1 or not(var277 = 1)) and (var3 = 1 or not(var277 = 1))
 and (var6 = 1 or not(var277 = 1)) and (var8 = 1 or not(var277 = 1)) and (var9 =
 1 or not(var277 = 1)) and (var12 = 1 or not(var277 = 1)) and (var13 = 1 or not(
var277 = 1)) and (var15 = 1 or not(var277 = 1)) and (var18 = 1 or not(var277 = 1
)) and (var20 = 1 or not(var277 = 1)) and (var21 = 1 or not(var277 = 1)) and (
var24 = 1 or not(var277 = 1)) and (var25 = 1 or not(var277 = 1)) and (var27 = 1
or not(var277 = 1)) and (var29 = 1 or not(var277 = 1)) and (var31 = 1 or not(
var277 = 1)) and (var34 = 1 or not(var277 = 1)) and (var35 = 1 or not(var277 = 1
)) and (var37 = 1 or not(var277 = 1)) and (var40 = 1 or not(var277 = 1)) and (
var41 = 1 or not(var277 = 1)) and (var43 = 1 or not(var277 = 1)) and (var46 = 1
or not(var277 = 1)) and (var47 = 1 or not(var277 = 1)) and (var49 = 1 or not(
var277 = 1)) and (var51 = 1 or not(var277 = 1)) and (var54 = 1 or not(var277 = 1
)) and (var55 = 1 or not(var277 = 1)) and (var58 = 1 or not(var277 = 1)) and (
var59 = 1 or not(var277 = 1)) and (var61 = 1 or not(var277 = 1)) and (var63 = 1
or not(var277 = 1)) and (var66 = 1 or not(var278 = 1)) and (var67 = 1 or not(
var278 = 1)) and (var70 = 1 or not(var278 = 1)) and (var72 = 1 or not(var278 = 1
)) and (var73 = 1 or not(var278 = 1)) and (var76 = 1 or not(var278 = 1)) and (
var77 = 1 or not(var278 = 1)) and (var79 = 1 or not(var278 = 1)) and (var82 = 1
or not(var278 = 1)) and (var84 = 1 or not(var278 = 1)) and (var85 = 1 or not(
var278 = 1)) and (var88 = 1 or not(var278 = 1)) and (var89 = 1 or not(var278 = 1
)) and (var91 = 1 or not(var278 = 1)) and (var93 = 1 or not(var278 = 1)) and (
var95 = 1 or not(var278 = 1)) and (var98 = 1 or not(var278 = 1)) and (var99 = 1
or not(var278 = 1)) and (var101 = 1 or not(var278 = 1)) and (var104 = 1 or not(
var278 = 1)) and (var105 = 1 or not(var278 = 1)) and (var107 = 1 or not(var278 =
 1)) and (var110 = 1 or not(var278 = 1)) and (var111 = 1 or not(var278 = 1)) and
 (var113 = 1 or not(var278 = 1)) and (var115 = 1 or not(var278 = 1)) and (var118
 = 1 or not(var278 = 1)) and (var119 = 1 or not(var278 = 1)) and (var122 = 1 or
not(var278 = 1)) and (var123 = 1 or not(var278 = 1)) and (var125 = 1 or not(
var278 = 1)) and (var127 = 1 or not(var278 = 1)) and (var130 = 1 or not(var279 =
 1)) and (var131 = 1 or not(var279 = 1)) and (var134 = 1 or not(var279 = 1)) and
 (var136 = 1 or not(var279 = 1)) and (var137 = 1 or not(var279 = 1)) and (var140
 = 1 or not(var279 = 1)) and (var141 = 1 or not(var279 = 1)) and (var143 = 1 or
not(var279 = 1)) and (var146 = 1 or not(var279 = 1)) and (var148 = 1 or not(
var279 = 1)) and (var149 = 1 or not(var279 = 1)) and (var152 = 1 or not(var279 =
 1)) and (var153 = 1 or not(var279 = 1)) and (var155 = 1 or not(var279 = 1)) and
 (var157 = 1 or not(var279 = 1)) and (var159 = 1 or not(var279 = 1)) and (var162
 = 1 or not(var279 = 1)) and (var163 = 1 or not(var279 = 1)) and (var165 = 1 or
not(var279 = 1)) and (var168 = 1 or not(var279 = 1)) and (var169 = 1 or not(
var279 = 1)) and (var171 = 1 or not(var279 = 1)) and (var174 = 1 or not(var279 =
 1)) and (var175 = 1 or not(var279 = 1)) and (var177 = 1 or not(var279 = 1)) and
 (var179 = 1 or not(var279 = 1)) and (var182 = 1 or not(var279 = 1)) and (var183
 = 1 or not(var279 = 1)) and (var186 = 1 or not(var279 = 1)) and (var187 = 1 or
not(var279 = 1)) and (var189 = 1 or not(var279 = 1)) and (var191 = 1 or not(
var279 = 1)) and (var1 = 1 or not(var280 = 1)) and (var4 = 1 or not(var280 = 1))
 and (var6 = 1 or not(var280 = 1)) and (var7 = 1 or not(var280 = 1)) and (var9 =
 1 or not(var280 = 1)) and (var12 = 1 or not(var280 = 1)) and (var13 = 1 or not(
var280 = 1)) and (var15 = 1 or not(var280 = 1)) and (var17 = 1 or not(var280 = 1
)) and (var19 = 1 or not(var280 = 1)) and (var22 = 1 or not(var280 = 1)) and (
var24 = 1 or not(var280 = 1)) and (var25 = 1 or not(var280 = 1)) and (var27 = 1
or not(var280 = 1)) and (var30 = 1 or not(var280 = 1)) and (var32 = 1 or not(
var280 = 1)) and (var34 = 1 or not(var280 = 1)) and (var36 = 1 or not(var280 = 1
)) and (var38 = 1 or not(var280 = 1)) and (var39 = 1 or not(var280 = 1)) and (
var41 = 1 or not(var280 = 1)) and (var43 = 1 or not(var280 = 1)) and (var46 = 1
or not(var280 = 1)) and (var48 = 1 or not(var280 = 1)) and (var50 = 1 or not(
var280 = 1)) and (var51 = 1 or not(var280 = 1)) and (var54 = 1 or not(var280 = 1
)) and (var55 = 1 or not(var280 = 1)) and (var58 = 1 or not(var280 = 1)) and (
var59 = 1 or not(var280 = 1)) and (var62 = 1 or not(var280 = 1)) and (var63 = 1
or not(var280 = 1)) and (var65 = 1 or not(var281 = 1)) and (var68 = 1 or not(
var281 = 1)) and (var70 = 1 or not(var281 = 1)) and (var71 = 1 or not(var281 = 1
)) and (var73 = 1 or not(var281 = 1)) and (var76 = 1 or not(var281 = 1)) and (
var77 = 1 or not(var281 = 1)) and (var79 = 1 or not(var281 = 1)) and (var81 = 1
or not(var281 = 1)) and (var83 = 1 or not(var281 = 1)) and (var86 = 1 or not(
var281 = 1)) and (var88 = 1 or not(var281 = 1)) and (var89 = 1 or not(var281 = 1
)) and (var91 = 1 or not(var281 = 1)) and (var94 = 1 or not(var281 = 1)) and (
var96 = 1 or not(var281 = 1)) and (var98 = 1 or not(var281 = 1)) and (var100 = 1
 or not(var281 = 1)) and (var102 = 1 or not(var281 = 1)) and (var103 = 1 or not(
var281 = 1)) and (var105 = 1 or not(var281 = 1)) and (var107 = 1 or not(var281 =
 1)) and (var110 = 1 or not(var281 = 1)) and (var112 = 1 or not(var281 = 1)) and
 (var114 = 1 or not(var281 = 1)) and (var115 = 1 or not(var281 = 1)) and (var118
 = 1 or not(var281 = 1)) and (var119 = 1 or not(var281 = 1)) and (var122 = 1 or
not(var281 = 1)) and (var123 = 1 or not(var281 = 1)) and (var126 = 1 or not(
var281 = 1)) and (var127 = 1 or not(var281 = 1)) and (var129 = 1 or not(var282 =
 1)) and (var132 = 1 or not(var282 = 1)) and (var134 = 1 or not(var282 = 1)) and
 (var135 = 1 or not(var282 = 1)) and (var137 = 1 or not(var282 = 1)) and (var140
 = 1 or not(var282 = 1)) and (var141 = 1 or not(var282 = 1)) and (var143 = 1 or
not(var282 = 1)) and (var145 = 1 or not(var282 = 1)) and (var147 = 1 or not(
var282 = 1)) and (var150 = 1 or not(var282 = 1)) and (var152 = 1 or not(var282 =
 1)) and (var153 = 1 or not(var282 = 1)) and (var155 = 1 or not(var282 = 1)) and
 (var158 = 1 or not(var282 = 1)) and (var160 = 1 or not(var282 = 1)) and (var162
 = 1 or not(var282 = 1)) and (var164 = 1 or not(var282 = 1)) and (var166 = 1 or
not(var282 = 1)) and (var167 = 1 or not(var282 = 1)) and (var169 = 1 or not(
var282 = 1)) and (var171 = 1 or not(var282 = 1)) and (var174 = 1 or not(var282 =
 1)) and (var176 = 1 or not(var282 = 1)) and (var178 = 1 or not(var282 = 1)) and
 (var179 = 1 or not(var282 = 1)) and (var182 = 1 or not(var282 = 1)) and (var183
 = 1 or not(var282 = 1)) and (var186 = 1 or not(var282 = 1)) and (var187 = 1 or
not(var282 = 1)) and (var190 = 1 or not(var282 = 1)) and (var191 = 1 or not(
var282 = 1)) and (var2 = 1 or not(var283 = 1)) and (var3 = 1 or not(var283 = 1))
 and (var5 = 1 or not(var283 = 1)) and (var8 = 1 or not(var283 = 1)) and (var10
= 1 or not(var283 = 1)) and (var12 = 1 or not(var283 = 1)) and (var13 = 1 or not
(var283 = 1)) and (var16 = 1 or not(var283 = 1)) and (var18 = 1 or not(var283 =
1)) and (var20 = 1 or not(var283 = 1)) and (var21 = 1 or not(var283 = 1)) and (
var23 = 1 or not(var283 = 1)) and (var25 = 1 or not(var283 = 1)) and (var28 = 1
or not(var283 = 1)) and (var29 = 1 or not(var283 = 1)) and (var32 = 1 or not(
var283 = 1)) and (var34 = 1 or not(var283 = 1)) and (var35 = 1 or not(var283 = 1
)) and (var38 = 1 or not(var283 = 1)) and (var39 = 1 or not(var283 = 1)) and (
var41 = 1 or not(var283 = 1)) and (var43 = 1 or not(var283 = 1)) and (var46 = 1
or not(var283 = 1)) and (var48 = 1 or not(var283 = 1)) and (var50 = 1 or not(
var283 = 1)) and (var52 = 1 or not(var283 = 1)) and (var53 = 1 or not(var283 = 1
)) and (var55 = 1 or not(var283 = 1)) and (var58 = 1 or not(var283 = 1)) and (
var59 = 1 or not(var283 = 1)) and (var62 = 1 or not(var283 = 1)) and (var64 = 1
or not(var283 = 1)) and (var66 = 1 or not(var284 = 1)) and (var67 = 1 or not(
var284 = 1)) and (var69 = 1 or not(var284 = 1)) and (var72 = 1 or not(var284 = 1
)) and (var74 = 1 or not(var284 = 1)) and (var76 = 1 or not(var284 = 1)) and (
var77 = 1 or not(var284 = 1)) and (var80 = 1 or not(var284 = 1)) and (var82 = 1
or not(var284 = 1)) and (var84 = 1 or not(var284 = 1)) and (var85 = 1 or not(
var284 = 1)) and (var87 = 1 or not(var284 = 1)) and (var89 = 1 or not(var284 = 1
)) and (var92 = 1 or not(var284 = 1)) and (var93 = 1 or not(var284 = 1)) and (
var96 = 1 or not(var284 = 1)) and (var98 = 1 or not(var284 = 1)) and (var99 = 1
or not(var284 = 1)) and (var102 = 1 or not(var284 = 1)) and (var103 = 1 or not(
var284 = 1)) and (var105 = 1 or not(var284 = 1)) and (var107 = 1 or not(var284 =
 1)) and (var110 = 1 or not(var284 = 1)) and (var112 = 1 or not(var284 = 1)) and
 (var114 = 1 or not(var284 = 1)) and (var116 = 1 or not(var284 = 1)) and (var117
 = 1 or not(var284 = 1)) and (var119 = 1 or not(var284 = 1)) and (var122 = 1 or
not(var284 = 1)) and (var123 = 1 or not(var284 = 1)) and (var126 = 1 or not(
var284 = 1)) and (var128 = 1 or not(var284 = 1)) and (var130 = 1 or not(var285 =
 1)) and (var131 = 1 or not(var285 = 1)) and (var133 = 1 or not(var285 = 1)) and
 (var136 = 1 or not(var285 = 1)) and (var138 = 1 or not(var285 = 1)) and (var140
 = 1 or not(var285 = 1)) and (var141 = 1 or not(var285 = 1)) and (var144 = 1 or
not(var285 = 1)) and (var146 = 1 or not(var285 = 1)) and (var148 = 1 or not(
var285 = 1)) and (var149 = 1 or not(var285 = 1)) and (var151 = 1 or not(var285 =
 1)) and (var153 = 1 or not(var285 = 1)) and (var156 = 1 or not(var285 = 1)) and
 (var157 = 1 or not(var285 = 1)) and (var160 = 1 or not(var285 = 1)) and (var162
 = 1 or not(var285 = 1)) and (var163 = 1 or not(var285 = 1)) and (var166 = 1 or
not(var285 = 1)) and (var167 = 1 or not(var285 = 1)) and (var169 = 1 or not(
var285 = 1)) and (var171 = 1 or not(var285 = 1)) and (var174 = 1 or not(var285 =
 1)) and (var176 = 1 or not(var285 = 1)) and (var178 = 1 or not(var285 = 1)) and
 (var180 = 1 or not(var285 = 1)) and (var181 = 1 or not(var285 = 1)) and (var183
 = 1 or not(var285 = 1)) and (var186 = 1 or not(var285 = 1)) and (var187 = 1 or
not(var285 = 1)) and (var190 = 1 or not(var285 = 1)) and (var192 = 1 or not(
var285 = 1)) and (var1 = 1 or not(var286 = 1)) and (var4 = 1 or not(var286 = 1))
 and (var6 = 1 or not(var286 = 1)) and (var7 = 1 or not(var286 = 1)) and (var10
= 1 or not(var286 = 1)) and (var12 = 1 or not(var286 = 1)) and (var13 = 1 or not
(var286 = 1)) and (var15 = 1 or not(var286 = 1)) and (var18 = 1 or not(var286 =
1)) and (var20 = 1 or not(var286 = 1)) and (var22 = 1 or not(var286 = 1)) and (
var23 = 1 or not(var286 = 1)) and (var26 = 1 or not(var286 = 1)) and (var28 = 1
or not(var286 = 1)) and (var29 = 1 or not(var286 = 1)) and (var31 = 1 or not(
var286 = 1)) and (var33 = 1 or not(var286 = 1)) and (var35 = 1 or not(var286 = 1
)) and (var37 = 1 or not(var286 = 1)) and (var40 = 1 or not(var286 = 1)) and (
var42 = 1 or not(var286 = 1)) and (var43 = 1 or not(var286 = 1)) and (var46 = 1
or not(var286 = 1)) and (var47 = 1 or not(var286 = 1)) and (var50 = 1 or not(
var286 = 1)) and (var51 = 1 or not(var286 = 1)) and (var53 = 1 or not(var286 = 1
)) and (var56 = 1 or not(var286 = 1)) and (var57 = 1 or not(var286 = 1)) and (
var59 = 1 or not(var286 = 1)) and (var61 = 1 or not(var286 = 1)) and (var64 = 1
or not(var286 = 1)) and (var65 = 1 or not(var287 = 1)) and (var68 = 1 or not(
var287 = 1)) and (var70 = 1 or not(var287 = 1)) and (var71 = 1 or not(var287 = 1
)) and (var74 = 1 or not(var287 = 1)) and (var76 = 1 or not(var287 = 1)) and (
var77 = 1 or not(var287 = 1)) and (var79 = 1 or not(var287 = 1)) and (var82 = 1
or not(var287 = 1)) and (var84 = 1 or not(var287 = 1)) and (var86 = 1 or not(
var287 = 1)) and (var87 = 1 or not(var287 = 1)) and (var90 = 1 or not(var287 = 1
)) and (var92 = 1 or not(var287 = 1)) and (var93 = 1 or not(var287 = 1)) and (
var95 = 1 or not(var287 = 1)) and (var97 = 1 or not(var287 = 1)) and (var99 = 1
or not(var287 = 1)) and (var101 = 1 or not(var287 = 1)) and (var104 = 1 or not(
var287 = 1)) and (var106 = 1 or not(var287 = 1)) and (var107 = 1 or not(var287 =
 1)) and (var110 = 1 or not(var287 = 1)) and (var111 = 1 or not(var287 = 1)) and
 (var114 = 1 or not(var287 = 1)) and (var115 = 1 or not(var287 = 1)) and (var117
 = 1 or not(var287 = 1)) and (var120 = 1 or not(var287 = 1)) and (var121 = 1 or
not(var287 = 1)) and (var123 = 1 or not(var287 = 1)) and (var125 = 1 or not(
var287 = 1)) and (var128 = 1 or not(var287 = 1)) and (var129 = 1 or not(var288 =
 1)) and (var132 = 1 or not(var288 = 1)) and (var134 = 1 or not(var288 = 1)) and
 (var135 = 1 or not(var288 = 1)) and (var138 = 1 or not(var288 = 1)) and (var140
 = 1 or not(var288 = 1)) and (var141 = 1 or not(var288 = 1)) and (var143 = 1 or
not(var288 = 1)) and (var146 = 1 or not(var288 = 1)) and (var148 = 1 or not(
var288 = 1)) and (var150 = 1 or not(var288 = 1)) and (var151 = 1 or not(var288 =
 1)) and (var154 = 1 or not(var288 = 1)) and (var156 = 1 or not(var288 = 1)) and
 (var157 = 1 or not(var288 = 1)) and (var159 = 1 or not(var288 = 1)) and (var161
 = 1 or not(var288 = 1)) and (var163 = 1 or not(var288 = 1)) and (var165 = 1 or
not(var288 = 1)) and (var168 = 1 or not(var288 = 1)) and (var170 = 1 or not(
var288 = 1)) and (var171 = 1 or not(var288 = 1)) and (var174 = 1 or not(var288 =
 1)) and (var175 = 1 or not(var288 = 1)) and (var178 = 1 or not(var288 = 1)) and
 (var179 = 1 or not(var288 = 1)) and (var181 = 1 or not(var288 = 1)) and (var184
 = 1 or not(var288 = 1)) and (var185 = 1 or not(var288 = 1)) and (var187 = 1 or
not(var288 = 1)) and (var189 = 1 or not(var288 = 1)) and (var192 = 1 or not(
var288 = 1)) and (var1 = 1 or not(var289 = 1)) and (var4 = 1 or not(var289 = 1))
 and (var5 = 1 or not(var289 = 1)) and (var7 = 1 or not(var289 = 1)) and (var10
= 1 or not(var289 = 1)) and (var12 = 1 or not(var289 = 1)) and (var13 = 1 or not
(var289 = 1)) and (var15 = 1 or not(var289 = 1)) and (var17 = 1 or not(var289 =
1)) and (var19 = 1 or not(var289 = 1)) and (var21 = 1 or not(var289 = 1)) and (
var24 = 1 or not(var289 = 1)) and (var25 = 1 or not(var289 = 1)) and (var27 = 1
or not(var289 = 1)) and (var30 = 1 or not(var289 = 1)) and (var32 = 1 or not(
var289 = 1)) and (var34 = 1 or not(var289 = 1)) and (var35 = 1 or not(var289 = 1
)) and (var38 = 1 or not(var289 = 1)) and (var40 = 1 or not(var289 = 1)) and (
var41 = 1 or not(var289 = 1)) and (var44 = 1 or not(var289 = 1)) and (var45 = 1
or not(var289 = 1)) and (var48 = 1 or not(var289 = 1)) and (var49 = 1 or not(
var289 = 1)) and (var51 = 1 or not(var289 = 1)) and (var53 = 1 or not(var289 = 1
)) and (var56 = 1 or not(var289 = 1)) and (var57 = 1 or not(var289 = 1)) and (
var59 = 1 or not(var289 = 1)) and (var62 = 1 or not(var289 = 1)) and (var63 = 1
or not(var289 = 1)) and (var65 = 1 or not(var290 = 1)) and (var68 = 1 or not(
var290 = 1)) and (var69 = 1 or not(var290 = 1)) and (var71 = 1 or not(var290 = 1
)) and (var74 = 1 or not(var290 = 1)) and (var76 = 1 or not(var290 = 1)) and (
var77 = 1 or not(var290 = 1)) and (var79 = 1 or not(var290 = 1)) and (var81 = 1
or not(var290 = 1)) and (var83 = 1 or not(var290 = 1)) and (var85 = 1 or not(
var290 = 1)) and (var88 = 1 or not(var290 = 1)) and (var89 = 1 or not(var290 = 1
)) and (var91 = 1 or not(var290 = 1)) and (var94 = 1 or not(var290 = 1)) and (
var96 = 1 or not(var290 = 1)) and (var98 = 1 or not(var290 = 1)) and (var99 = 1
or not(var290 = 1)) and (var102 = 1 or not(var290 = 1)) and (var104 = 1 or not(
var290 = 1)) and (var105 = 1 or not(var290 = 1)) and (var108 = 1 or not(var290 =
 1)) and (var109 = 1 or not(var290 = 1)) and (var112 = 1 or not(var290 = 1)) and
 (var113 = 1 or not(var290 = 1)) and (var115 = 1 or not(var290 = 1)) and (var117
 = 1 or not(var290 = 1)) and (var120 = 1 or not(var290 = 1)) and (var121 = 1 or
not(var290 = 1)) and (var123 = 1 or not(var290 = 1)) and (var126 = 1 or not(
var290 = 1)) and (var127 = 1 or not(var290 = 1)) and (var129 = 1 or not(var291 =
 1)) and (var132 = 1 or not(var291 = 1)) and (var133 = 1 or not(var291 = 1)) and
 (var135 = 1 or not(var291 = 1)) and (var138 = 1 or not(var291 = 1)) and (var140
 = 1 or not(var291 = 1)) and (var141 = 1 or not(var291 = 1)) and (var143 = 1 or
not(var291 = 1)) and (var145 = 1 or not(var291 = 1)) and (var147 = 1 or not(
var291 = 1)) and (var149 = 1 or not(var291 = 1)) and (var152 = 1 or not(var291 =
 1)) and (var153 = 1 or not(var291 = 1)) and (var155 = 1 or not(var291 = 1)) and
 (var158 = 1 or not(var291 = 1)) and (var160 = 1 or not(var291 = 1)) and (var162
 = 1 or not(var291 = 1)) and (var163 = 1 or not(var291 = 1)) and (var166 = 1 or
not(var291 = 1)) and (var168 = 1 or not(var291 = 1)) and (var169 = 1 or not(
var291 = 1)) and (var172 = 1 or not(var291 = 1)) and (var173 = 1 or not(var291 =
 1)) and (var176 = 1 or not(var291 = 1)) and (var177 = 1 or not(var291 = 1)) and
 (var179 = 1 or not(var291 = 1)) and (var181 = 1 or not(var291 = 1)) and (var184
 = 1 or not(var291 = 1)) and (var185 = 1 or not(var291 = 1)) and (var187 = 1 or
not(var291 = 1)) and (var190 = 1 or not(var291 = 1)) and (var191 = 1 or not(
var291 = 1)) and (var2 = 1 or not(var292 = 1)) and (var3 = 1 or not(var292 = 1))
 and (var6 = 1 or not(var292 = 1)) and (var8 = 1 or not(var292 = 1)) and (var10
= 1 or not(var292 = 1)) and (var12 = 1 or not(var292 = 1)) and (var13 = 1 or not
(var292 = 1)) and (var16 = 1 or not(var292 = 1)) and (var18 = 1 or not(var292 =
1)) and (var20 = 1 or not(var292 = 1)) and (var22 = 1 or not(var292 = 1)) and (
var24 = 1 or not(var292 = 1)) and (var26 = 1 or not(var292 = 1)) and (var28 = 1
or not(var292 = 1)) and (var29 = 1 or not(var292 = 1)) and (var31 = 1 or not(
var292 = 1)) and (var33 = 1 or not(var292 = 1)) and (var36 = 1 or not(var292 = 1
)) and (var37 = 1 or not(var292 = 1)) and (var39 = 1 or not(var292 = 1)) and (
var42 = 1 or not(var292 = 1)) and (var44 = 1 or not(var292 = 1)) and (var46 = 1
or not(var292 = 1)) and (var48 = 1 or not(var292 = 1)) and (var50 = 1 or not(
var292 = 1)) and (var52 = 1 or not(var292 = 1)) and (var53 = 1 or not(var292 = 1
)) and (var56 = 1 or not(var292 = 1)) and (var57 = 1 or not(var292 = 1)) and (
var59 = 1 or not(var292 = 1)) and (var62 = 1 or not(var292 = 1)) and (var64 = 1
or not(var292 = 1)) and (var66 = 1 or not(var293 = 1)) and (var67 = 1 or not(
var293 = 1)) and (var70 = 1 or not(var293 = 1)) and (var72 = 1 or not(var293 = 1
)) and (var74 = 1 or not(var293 = 1)) and (var76 = 1 or not(var293 = 1)) and (
var77 = 1 or not(var293 = 1)) and (var80 = 1 or not(var293 = 1)) and (var82 = 1
or not(var293 = 1)) and (var84 = 1 or not(var293 = 1)) and (var86 = 1 or not(
var293 = 1)) and (var88 = 1 or not(var293 = 1)) and (var90 = 1 or not(var293 = 1
)) and (var92 = 1 or not(var293 = 1)) and (var93 = 1 or not(var293 = 1)) and (
var95 = 1 or not(var293 = 1)) and (var97 = 1 or not(var293 = 1)) and (var100 = 1
 or not(var293 = 1)) and (var101 = 1 or not(var293 = 1)) and (var103 = 1 or not(
var293 = 1)) and (var106 = 1 or not(var293 = 1)) and (var108 = 1 or not(var293 =
 1)) and (var110 = 1 or not(var293 = 1)) and (var112 = 1 or not(var293 = 1)) and
 (var114 = 1 or not(var293 = 1)) and (var116 = 1 or not(var293 = 1)) and (var117
 = 1 or not(var293 = 1)) and (var120 = 1 or not(var293 = 1)) and (var121 = 1 or
not(var293 = 1)) and (var123 = 1 or not(var293 = 1)) and (var126 = 1 or not(
var293 = 1)) and (var128 = 1 or not(var293 = 1)) and (var130 = 1 or not(var294 =
 1)) and (var131 = 1 or not(var294 = 1)) and (var134 = 1 or not(var294 = 1)) and
 (var136 = 1 or not(var294 = 1)) and (var138 = 1 or not(var294 = 1)) and (var140
 = 1 or not(var294 = 1)) and (var141 = 1 or not(var294 = 1)) and (var144 = 1 or
not(var294 = 1)) and (var146 = 1 or not(var294 = 1)) and (var148 = 1 or not(
var294 = 1)) and (var150 = 1 or not(var294 = 1)) and (var152 = 1 or not(var294 =
 1)) and (var154 = 1 or not(var294 = 1)) and (var156 = 1 or not(var294 = 1)) and
 (var157 = 1 or not(var294 = 1)) and (var159 = 1 or not(var294 = 1)) and (var161
 = 1 or not(var294 = 1)) and (var164 = 1 or not(var294 = 1)) and (var165 = 1 or
not(var294 = 1)) and (var167 = 1 or not(var294 = 1)) and (var170 = 1 or not(
var294 = 1)) and (var172 = 1 or not(var294 = 1)) and (var174 = 1 or not(var294 =
 1)) and (var176 = 1 or not(var294 = 1)) and (var178 = 1 or not(var294 = 1)) and
 (var180 = 1 or not(var294 = 1)) and (var181 = 1 or not(var294 = 1)) and (var184
 = 1 or not(var294 = 1)) and (var185 = 1 or not(var294 = 1)) and (var187 = 1 or
not(var294 = 1)) and (var190 = 1 or not(var294 = 1)) and (var192 = 1 or not(
var294 = 1)) and (var2 = 1 or not(var295 = 1)) and (var3 = 1 or not(var295 = 1))
 and (var5 = 1 or not(var295 = 1)) and (var8 = 1 or not(var295 = 1)) and (var10
= 1 or not(var295 = 1)) and (var11 = 1 or not(var295 = 1)) and (var13 = 1 or not
(var295 = 1)) and (var16 = 1 or not(var295 = 1)) and (var18 = 1 or not(var295 =
1)) and (var20 = 1 or not(var295 = 1)) and (var21 = 1 or not(var295 = 1)) and (
var23 = 1 or not(var295 = 1)) and (var26 = 1 or not(var295 = 1)) and (var27 = 1
or not(var295 = 1)) and (var29 = 1 or not(var295 = 1)) and (var31 = 1 or not(
var295 = 1)) and (var33 = 1 or not(var295 = 1)) and (var36 = 1 or not(var295 = 1
)) and (var38 = 1 or not(var295 = 1)) and (var40 = 1 or not(var295 = 1)) and (
var42 = 1 or not(var295 = 1)) and (var43 = 1 or not(var295 = 1)) and (var46 = 1
or not(var295 = 1)) and (var48 = 1 or not(var295 = 1)) and (var50 = 1 or not(
var295 = 1)) and (var52 = 1 or not(var295 = 1)) and (var53 = 1 or not(var295 = 1
)) and (var55 = 1 or not(var295 = 1)) and (var58 = 1 or not(var295 = 1)) and (
var59 = 1 or not(var295 = 1)) and (var61 = 1 or not(var295 = 1)) and (var64 = 1
or not(var295 = 1)) and (var66 = 1 or not(var296 = 1)) and (var67 = 1 or not(
var296 = 1)) and (var69 = 1 or not(var296 = 1)) and (var72 = 1 or not(var296 = 1
)) and (var74 = 1 or not(var296 = 1)) and (var75 = 1 or not(var296 = 1)) and (
var77 = 1 or not(var296 = 1)) and (var80 = 1 or not(var296 = 1)) and (var82 = 1
or not(var296 = 1)) and (var84 = 1 or not(var296 = 1)) and (var85 = 1 or not(
var296 = 1)) and (var87 = 1 or not(var296 = 1)) and (var90 = 1 or not(var296 = 1
)) and (var91 = 1 or not(var296 = 1)) and (var93 = 1 or not(var296 = 1)) and (
var95 = 1 or not(var296 = 1)) and (var97 = 1 or not(var296 = 1)) and (var100 = 1
 or not(var296 = 1)) and (var102 = 1 or not(var296 = 1)) and (var104 = 1 or not(
var296 = 1)) and (var106 = 1 or not(var296 = 1)) and (var107 = 1 or not(var296 =
 1)) and (var110 = 1 or not(var296 = 1)) and (var112 = 1 or not(var296 = 1)) and
 (var114 = 1 or not(var296 = 1)) and (var116 = 1 or not(var296 = 1)) and (var117
 = 1 or not(var296 = 1)) and (var119 = 1 or not(var296 = 1)) and (var122 = 1 or
not(var296 = 1)) and (var123 = 1 or not(var296 = 1)) and (var125 = 1 or not(
var296 = 1)) and (var128 = 1 or not(var296 = 1)) and (var130 = 1 or not(var297 =
 1)) and (var131 = 1 or not(var297 = 1)) and (var133 = 1 or not(var297 = 1)) and
 (var136 = 1 or not(var297 = 1)) and (var138 = 1 or not(var297 = 1)) and (var139
 = 1 or not(var297 = 1)) and (var141 = 1 or not(var297 = 1)) and (var144 = 1 or
not(var297 = 1)) and (var146 = 1 or not(var297 = 1)) and (var148 = 1 or not(
var297 = 1)) and (var149 = 1 or not(var297 = 1)) and (var151 = 1 or not(var297 =
 1)) and (var154 = 1 or not(var297 = 1)) and (var155 = 1 or not(var297 = 1)) and
 (var157 = 1 or not(var297 = 1)) and (var159 = 1 or not(var297 = 1)) and (var161
 = 1 or not(var297 = 1)) and (var164 = 1 or not(var297 = 1)) and (var166 = 1 or
not(var297 = 1)) and (var168 = 1 or not(var297 = 1)) and (var170 = 1 or not(
var297 = 1)) and (var171 = 1 or not(var297 = 1)) and (var174 = 1 or not(var297 =
 1)) and (var176 = 1 or not(var297 = 1)) and (var178 = 1 or not(var297 = 1)) and
 (var180 = 1 or not(var297 = 1)) and (var181 = 1 or not(var297 = 1)) and (var183
 = 1 or not(var297 = 1)) and (var186 = 1 or not(var297 = 1)) and (var187 = 1 or
not(var297 = 1)) and (var189 = 1 or not(var297 = 1)) and (var192 = 1 or not(
var297 = 1)) and (var2 = 1 or not(var298 = 1)) and (var4 = 1 or not(var298 = 1))
 and (var6 = 1 or not(var298 = 1)) and (var8 = 1 or not(var298 = 1)) and (var10
= 1 or not(var298 = 1)) and (var11 = 1 or not(var298 = 1)) and (var14 = 1 or not
(var298 = 1)) and (var16 = 1 or not(var298 = 1)) and (var18 = 1 or not(var298 =
1)) and (var20 = 1 or not(var298 = 1)) and (var22 = 1 or not(var298 = 1)) and (
var23 = 1 or not(var298 = 1)) and (var25 = 1 or not(var298 = 1)) and (var27 = 1
or not(var298 = 1)) and (var29 = 1 or not(var298 = 1)) and (var32 = 1 or not(
var298 = 1)) and (var33 = 1 or not(var298 = 1)) and (var35 = 1 or not(var298 = 1
)) and (var38 = 1 or not(var298 = 1)) and (var39 = 1 or not(var298 = 1)) and (
var42 = 1 or not(var298 = 1)) and (var43 = 1 or not(var298 = 1)) and (var46 = 1
or not(var298 = 1)) and (var47 = 1 or not(var298 = 1)) and (var50 = 1 or not(
var298 = 1)) and (var52 = 1 or not(var298 = 1)) and (var54 = 1 or not(var298 = 1
)) and (var55 = 1 or not(var298 = 1)) and (var57 = 1 or not(var298 = 1)) and (
var59 = 1 or not(var298 = 1)) and (var62 = 1 or not(var298 = 1)) and (var64 = 1
or not(var298 = 1)) and (var66 = 1 or not(var299 = 1)) and (var68 = 1 or not(
var299 = 1)) and (var70 = 1 or not(var299 = 1)) and (var72 = 1 or not(var299 = 1
)) and (var74 = 1 or not(var299 = 1)) and (var75 = 1 or not(var299 = 1)) and (
var78 = 1 or not(var299 = 1)) and (var80 = 1 or not(var299 = 1)) and (var82 = 1
or not(var299 = 1)) and (var84 = 1 or not(var299 = 1)) and (var86 = 1 or not(
var299 = 1)) and (var87 = 1 or not(var299 = 1)) and (var89 = 1 or not(var299 = 1
)) and (var91 = 1 or not(var299 = 1)) and (var93 = 1 or not(var299 = 1)) and (
var96 = 1 or not(var299 = 1)) and (var97 = 1 or not(var299 = 1)) and (var99 = 1
or not(var299 = 1)) and (var102 = 1 or not(var299 = 1)) and (var103 = 1 or not(
var299 = 1)) and (var106 = 1 or not(var299 = 1)) and (var107 = 1 or not(var299 =
 1)) and (var110 = 1 or not(var299 = 1)) and (var111 = 1 or not(var299 = 1)) and
 (var114 = 1 or not(var299 = 1)) and (var116 = 1 or not(var299 = 1)) and (var118
 = 1 or not(var299 = 1)) and (var119 = 1 or not(var299 = 1)) and (var121 = 1 or
not(var299 = 1)) and (var123 = 1 or not(var299 = 1)) and (var126 = 1 or not(
var299 = 1)) and (var128 = 1 or not(var299 = 1)) and (var130 = 1 or not(var300 =
 1)) and (var132 = 1 or not(var300 = 1)) and (var134 = 1 or not(var300 = 1)) and
 (var136 = 1 or not(var300 = 1)) and (var138 = 1 or not(var300 = 1)) and (var139
 = 1 or not(var300 = 1)) and (var142 = 1 or not(var300 = 1)) and (var144 = 1 or
not(var300 = 1)) and (var146 = 1 or not(var300 = 1)) and (var148 = 1 or not(
var300 = 1)) and (var150 = 1 or not(var300 = 1)) and (var151 = 1 or not(var300 =
 1)) and (var153 = 1 or not(var300 = 1)) and (var155 = 1 or not(var300 = 1)) and
 (var157 = 1 or not(var300 = 1)) and (var160 = 1 or not(var300 = 1)) and (var161
 = 1 or not(var300 = 1)) and (var163 = 1 or not(var300 = 1)) and (var166 = 1 or
not(var300 = 1)) and (var167 = 1 or not(var300 = 1)) and (var170 = 1 or not(
var300 = 1)) and (var171 = 1 or not(var300 = 1)) and (var174 = 1 or not(var300 =
 1)) and (var175 = 1 or not(var300 = 1)) and (var178 = 1 or not(var300 = 1)) and
 (var180 = 1 or not(var300 = 1)) and (var182 = 1 or not(var300 = 1)) and (var183
 = 1 or not(var300 = 1)) and (var185 = 1 or not(var300 = 1)) and (var187 = 1 or
not(var300 = 1)) and (var190 = 1 or not(var300 = 1)) and (var192 = 1 or not(
var300 = 1)) and (var1 = 1 or not(var301 = 1)) and (var4 = 1 or not(var301 = 1))
 and (var5 = 1 or not(var301 = 1)) and (var7 = 1 or not(var301 = 1)) and (var10
= 1 or not(var301 = 1)) and (var11 = 1 or not(var301 = 1)) and (var13 = 1 or not
(var301 = 1)) and (var15 = 1 or not(var301 = 1)) and (var17 = 1 or not(var301 =
1)) and (var20 = 1 or not(var301 = 1)) and (var21 = 1 or not(var301 = 1)) and (
var23 = 1 or not(var301 = 1)) and (var25 = 1 or not(var301 = 1)) and (var28 = 1
or not(var301 = 1)) and (var29 = 1 or not(var301 = 1)) and (var31 = 1 or not(
var301 = 1)) and (var33 = 1 or not(var301 = 1)) and (var35 = 1 or not(var301 = 1
)) and (var38 = 1 or not(var301 = 1)) and (var39 = 1 or not(var301 = 1)) and (
var41 = 1 or not(var301 = 1)) and (var43 = 1 or not(var301 = 1)) and (var45 = 1
or not(var301 = 1)) and (var47 = 1 or not(var301 = 1)) and (var50 = 1 or not(
var301 = 1)) and (var52 = 1 or not(var301 = 1)) and (var54 = 1 or not(var301 = 1
)) and (var56 = 1 or not(var301 = 1)) and (var58 = 1 or not(var301 = 1)) and (
var59 = 1 or not(var301 = 1)) and (var61 = 1 or not(var301 = 1)) and (var64 = 1
or not(var301 = 1)) and (var65 = 1 or not(var302 = 1)) and (var68 = 1 or not(
var302 = 1)) and (var69 = 1 or not(var302 = 1)) and (var71 = 1 or not(var302 = 1
)) and (var74 = 1 or not(var302 = 1)) and (var75 = 1 or not(var302 = 1)) and (
var77 = 1 or not(var302 = 1)) and (var79 = 1 or not(var302 = 1)) and (var81 = 1
or not(var302 = 1)) and (var84 = 1 or not(var302 = 1)) and (var85 = 1 or not(
var302 = 1)) and (var87 = 1 or not(var302 = 1)) and (var89 = 1 or not(var302 = 1
)) and (var92 = 1 or not(var302 = 1)) and (var93 = 1 or not(var302 = 1)) and (
var95 = 1 or not(var302 = 1)) and (var97 = 1 or not(var302 = 1)) and (var99 = 1
or not(var302 = 1)) and (var102 = 1 or not(var302 = 1)) and (var103 = 1 or not(
var302 = 1)) and (var105 = 1 or not(var302 = 1)) and (var107 = 1 or not(var302 =
 1)) and (var109 = 1 or not(var302 = 1)) and (var111 = 1 or not(var302 = 1)) and
 (var114 = 1 or not(var302 = 1)) and (var116 = 1 or not(var302 = 1)) and (var118
 = 1 or not(var302 = 1)) and (var120 = 1 or not(var302 = 1)) and (var122 = 1 or
not(var302 = 1)) and (var123 = 1 or not(var302 = 1)) and (var125 = 1 or not(
var302 = 1)) and (var128 = 1 or not(var302 = 1)) and (var129 = 1 or not(var303 =
 1)) and (var132 = 1 or not(var303 = 1)) and (var133 = 1 or not(var303 = 1)) and
 (var135 = 1 or not(var303 = 1)) and (var138 = 1 or not(var303 = 1)) and (var139
 = 1 or not(var303 = 1)) and (var141 = 1 or not(var303 = 1)) and (var143 = 1 or
not(var303 = 1)) and (var145 = 1 or not(var303 = 1)) and (var148 = 1 or not(
var303 = 1)) and (var149 = 1 or not(var303 = 1)) and (var151 = 1 or not(var303 =
 1)) and (var153 = 1 or not(var303 = 1)) and (var156 = 1 or not(var303 = 1)) and
 (var157 = 1 or not(var303 = 1)) and (var159 = 1 or not(var303 = 1)) and (var161
 = 1 or not(var303 = 1)) and (var163 = 1 or not(var303 = 1)) and (var166 = 1 or
not(var303 = 1)) and (var167 = 1 or not(var303 = 1)) and (var169 = 1 or not(
var303 = 1)) and (var171 = 1 or not(var303 = 1)) and (var173 = 1 or not(var303 =
 1)) and (var175 = 1 or not(var303 = 1)) and (var178 = 1 or not(var303 = 1)) and
 (var180 = 1 or not(var303 = 1)) and (var182 = 1 or not(var303 = 1)) and (var184
 = 1 or not(var303 = 1)) and (var186 = 1 or not(var303 = 1)) and (var187 = 1 or
not(var303 = 1)) and (var189 = 1 or not(var303 = 1)) and (var192 = 1 or not(
var303 = 1)) and (var1 = 1 or not(var304 = 1)) and (var4 = 1 or not(var304 = 1))
 and (var6 = 1 or not(var304 = 1)) and (var7 = 1 or not(var304 = 1)) and (var9 =
 1 or not(var304 = 1)) and (var12 = 1 or not(var304 = 1)) and (var14 = 1 or not(
var304 = 1)) and (var16 = 1 or not(var304 = 1)) and (var17 = 1 or not(var304 = 1
)) and (var20 = 1 or not(var304 = 1)) and (var21 = 1 or not(var304 = 1)) and (
var23 = 1 or not(var304 = 1)) and (var25 = 1 or not(var304 = 1)) and (var28 = 1
or not(var304 = 1)) and (var30 = 1 or not(var304 = 1)) and (var31 = 1 or not(
var304 = 1)) and (var33 = 1 or not(var304 = 1)) and (var36 = 1 or not(var304 = 1
)) and (var38 = 1 or not(var304 = 1)) and (var40 = 1 or not(var304 = 1)) and (
var42 = 1 or not(var304 = 1)) and (var44 = 1 or not(var304 = 1)) and (var45 = 1
or not(var304 = 1)) and (var47 = 1 or not(var304 = 1)) and (var49 = 1 or not(
var304 = 1)) and (var52 = 1 or not(var304 = 1)) and (var54 = 1 or not(var304 = 1
)) and (var56 = 1 or not(var304 = 1)) and (var58 = 1 or not(var304 = 1)) and (
var60 = 1 or not(var304 = 1)) and (var61 = 1 or not(var304 = 1)) and (var64 = 1
or not(var304 = 1)) and (var65 = 1 or not(var305 = 1)) and (var68 = 1 or not(
var305 = 1)) and (var70 = 1 or not(var305 = 1)) and (var71 = 1 or not(var305 = 1
)) and (var73 = 1 or not(var305 = 1)) and (var76 = 1 or not(var305 = 1)) and (
var78 = 1 or not(var305 = 1)) and (var80 = 1 or not(var305 = 1)) and (var81 = 1
or not(var305 = 1)) and (var84 = 1 or not(var305 = 1)) and (var85 = 1 or not(
var305 = 1)) and (var87 = 1 or not(var305 = 1)) and (var89 = 1 or not(var305 = 1
)) and (var92 = 1 or not(var305 = 1)) and (var94 = 1 or not(var305 = 1)) and (
var95 = 1 or not(var305 = 1)) and (var97 = 1 or not(var305 = 1)) and (var100 = 1
 or not(var305 = 1)) and (var102 = 1 or not(var305 = 1)) and (var104 = 1 or not(
var305 = 1)) and (var106 = 1 or not(var305 = 1)) and (var108 = 1 or not(var305 =
 1)) and (var109 = 1 or not(var305 = 1)) and (var111 = 1 or not(var305 = 1)) and
 (var113 = 1 or not(var305 = 1)) and (var116 = 1 or not(var305 = 1)) and (var118
 = 1 or not(var305 = 1)) and (var120 = 1 or not(var305 = 1)) and (var122 = 1 or
not(var305 = 1)) and (var124 = 1 or not(var305 = 1)) and (var125 = 1 or not(
var305 = 1)) and (var128 = 1 or not(var305 = 1)) and (var129 = 1 or not(var306 =
 1)) and (var132 = 1 or not(var306 = 1)) and (var134 = 1 or not(var306 = 1)) and
 (var135 = 1 or not(var306 = 1)) and (var137 = 1 or not(var306 = 1)) and (var140
 = 1 or not(var306 = 1)) and (var142 = 1 or not(var306 = 1)) and (var144 = 1 or
not(var306 = 1)) and (var145 = 1 or not(var306 = 1)) and (var148 = 1 or not(
var306 = 1)) and (var149 = 1 or not(var306 = 1)) and (var151 = 1 or not(var306 =
 1)) and (var153 = 1 or not(var306 = 1)) and (var156 = 1 or not(var306 = 1)) and
 (var158 = 1 or not(var306 = 1)) and (var159 = 1 or not(var306 = 1)) and (var161
 = 1 or not(var306 = 1)) and (var164 = 1 or not(var306 = 1)) and (var166 = 1 or
not(var306 = 1)) and (var168 = 1 or not(var306 = 1)) and (var170 = 1 or not(
var306 = 1)) and (var172 = 1 or not(var306 = 1)) and (var173 = 1 or not(var306 =
 1)) and (var175 = 1 or not(var306 = 1)) and (var177 = 1 or not(var306 = 1)) and
 (var180 = 1 or not(var306 = 1)) and (var182 = 1 or not(var306 = 1)) and (var184
 = 1 or not(var306 = 1)) and (var186 = 1 or not(var306 = 1)) and (var188 = 1 or
not(var306 = 1)) and (var189 = 1 or not(var306 = 1)) and (var192 = 1 or not(
var306 = 1)) and (var1 = 1 or not(var307 = 1)) and (var4 = 1 or not(var307 = 1))
 and (var6 = 1 or not(var307 = 1)) and (var7 = 1 or not(var307 = 1)) and (var10
= 1 or not(var307 = 1)) and (var11 = 1 or not(var307 = 1)) and (var13 = 1 or not
(var307 = 1)) and (var16 = 1 or not(var307 = 1)) and (var18 = 1 or not(var307 =
1)) and (var20 = 1 or not(var307 = 1)) and (var21 = 1 or not(var307 = 1)) and (
var23 = 1 or not(var307 = 1)) and (var25 = 1 or not(var307 = 1)) and (var28 = 1
or not(var307 = 1)) and (var29 = 1 or not(var307 = 1)) and (var32 = 1 or not(
var307 = 1)) and (var33 = 1 or not(var307 = 1)) and (var35 = 1 or not(var307 = 1
)) and (var37 = 1 or not(var307 = 1)) and (var40 = 1 or not(var307 = 1)) and (
var42 = 1 or not(var307 = 1)) and (var43 = 1 or not(var307 = 1)) and (var46 = 1
or not(var307 = 1)) and (var47 = 1 or not(var307 = 1)) and (var49 = 1 or not(
var307 = 1)) and (var51 = 1 or not(var307 = 1)) and (var53 = 1 or not(var307 = 1
)) and (var56 = 1 or not(var307 = 1)) and (var58 = 1 or not(var307 = 1)) and (
var59 = 1 or not(var307 = 1)) and (var61 = 1 or not(var307 = 1)) and (var64 = 1
or not(var307 = 1)) and (var65 = 1 or not(var308 = 1)) and (var68 = 1 or not(
var308 = 1)) and (var70 = 1 or not(var308 = 1)) and (var71 = 1 or not(var308 = 1
)) and (var74 = 1 or not(var308 = 1)) and (var75 = 1 or not(var308 = 1)) and (
var77 = 1 or not(var308 = 1)) and (var80 = 1 or not(var308 = 1)) and (var82 = 1
or not(var308 = 1)) and (var84 = 1 or not(var308 = 1)) and (var85 = 1 or not(
var308 = 1)) and (var87 = 1 or not(var308 = 1)) and (var89 = 1 or not(var308 = 1
)) and (var92 = 1 or not(var308 = 1)) and (var93 = 1 or not(var308 = 1)) and (
var96 = 1 or not(var308 = 1)) and (var97 = 1 or not(var308 = 1)) and (var99 = 1
or not(var308 = 1)) and (var101 = 1 or not(var308 = 1)) and (var104 = 1 or not(
var308 = 1)) and (var106 = 1 or not(var308 = 1)) and (var107 = 1 or not(var308 =
 1)) and (var110 = 1 or not(var308 = 1)) and (var111 = 1 or not(var308 = 1)) and
 (var113 = 1 or not(var308 = 1)) and (var115 = 1 or not(var308 = 1)) and (var117
 = 1 or not(var308 = 1)) and (var120 = 1 or not(var308 = 1)) and (var122 = 1 or
not(var308 = 1)) and (var123 = 1 or not(var308 = 1)) and (var125 = 1 or not(
var308 = 1)) and (var128 = 1 or not(var308 = 1)) and (var129 = 1 or not(var309 =
 1)) and (var132 = 1 or not(var309 = 1)) and (var134 = 1 or not(var309 = 1)) and
 (var135 = 1 or not(var309 = 1)) and (var138 = 1 or not(var309 = 1)) and (var139
 = 1 or not(var309 = 1)) and (var141 = 1 or not(var309 = 1)) and (var144 = 1 or
not(var309 = 1)) and (var146 = 1 or not(var309 = 1)) and (var148 = 1 or not(
var309 = 1)) and (var149 = 1 or not(var309 = 1)) and (var151 = 1 or not(var309 =
 1)) and (var153 = 1 or not(var309 = 1)) and (var156 = 1 or not(var309 = 1)) and
 (var157 = 1 or not(var309 = 1)) and (var160 = 1 or not(var309 = 1)) and (var161
 = 1 or not(var309 = 1)) and (var163 = 1 or not(var309 = 1)) and (var165 = 1 or
not(var309 = 1)) and (var168 = 1 or not(var309 = 1)) and (var170 = 1 or not(
var309 = 1)) and (var171 = 1 or not(var309 = 1)) and (var174 = 1 or not(var309 =
 1)) and (var175 = 1 or not(var309 = 1)) and (var177 = 1 or not(var309 = 1)) and
 (var179 = 1 or not(var309 = 1)) and (var181 = 1 or not(var309 = 1)) and (var184
 = 1 or not(var309 = 1)) and (var186 = 1 or not(var309 = 1)) and (var187 = 1 or
not(var309 = 1)) and (var189 = 1 or not(var309 = 1)) and (var192 = 1 or not(
var309 = 1)) and (var2 = 1 or not(var310 = 1)) and (var4 = 1 or not(var310 = 1))
 and (var5 = 1 or not(var310 = 1)) and (var8 = 1 or not(var310 = 1)) and (var10
= 1 or not(var310 = 1)) and (var12 = 1 or not(var310 = 1)) and (var13 = 1 or not
(var310 = 1)) and (var16 = 1 or not(var310 = 1)) and (var17 = 1 or not(var310 =
1)) and (var20 = 1 or not(var310 = 1)) and (var22 = 1 or not(var310 = 1)) and (
var23 = 1 or not(var310 = 1)) and (var26 = 1 or not(var310 = 1)) and (var27 = 1
or not(var310 = 1)) and (var30 = 1 or not(var310 = 1)) and (var32 = 1 or not(
var310 = 1)) and (var34 = 1 or not(var310 = 1)) and (var35 = 1 or not(var310 = 1
)) and (var37 = 1 or not(var310 = 1)) and (var40 = 1 or not(var310 = 1)) and (
var42 = 1 or not(var310 = 1)) and (var43 = 1 or not(var310 = 1)) and (var46 = 1
or not(var310 = 1)) and (var47 = 1 or not(var310 = 1)) and (var50 = 1 or not(
var310 = 1)) and (var52 = 1 or not(var310 = 1)) and (var54 = 1 or not(var310 = 1
)) and (var55 = 1 or not(var310 = 1)) and (var58 = 1 or not(var310 = 1)) and (
var59 = 1 or not(var310 = 1)) and (var61 = 1 or not(var310 = 1)) and (var63 = 1
or not(var310 = 1)) and (var66 = 1 or not(var311 = 1)) and (var68 = 1 or not(
var311 = 1)) and (var69 = 1 or not(var311 = 1)) and (var72 = 1 or not(var311 = 1
)) and (var74 = 1 or not(var311 = 1)) and (var76 = 1 or not(var311 = 1)) and (
var77 = 1 or not(var311 = 1)) and (var80 = 1 or not(var311 = 1)) and (var81 = 1
or not(var311 = 1)) and (var84 = 1 or not(var311 = 1)) and (var86 = 1 or not(
var311 = 1)) and (var87 = 1 or not(var311 = 1)) and (var90 = 1 or not(var311 = 1
)) and (var91 = 1 or not(var311 = 1)) and (var94 = 1 or not(var311 = 1)) and (
var96 = 1 or not(var311 = 1)) and (var98 = 1 or not(var311 = 1)) and (var99 = 1
or not(var311 = 1)) and (var101 = 1 or not(var311 = 1)) and (var104 = 1 or not(
var311 = 1)) and (var106 = 1 or not(var311 = 1)) and (var107 = 1 or not(var311 =
 1)) and (var110 = 1 or not(var311 = 1)) and (var111 = 1 or not(var311 = 1)) and
 (var114 = 1 or not(var311 = 1)) and (var116 = 1 or not(var311 = 1)) and (var118
 = 1 or not(var311 = 1)) and (var119 = 1 or not(var311 = 1)) and (var122 = 1 or
not(var311 = 1)) and (var123 = 1 or not(var311 = 1)) and (var125 = 1 or not(
var311 = 1)) and (var127 = 1 or not(var311 = 1)) and (var130 = 1 or not(var312 =
 1)) and (var132 = 1 or not(var312 = 1)) and (var133 = 1 or not(var312 = 1)) and
 (var136 = 1 or not(var312 = 1)) and (var138 = 1 or not(var312 = 1)) and (var140
 = 1 or not(var312 = 1)) and (var141 = 1 or not(var312 = 1)) and (var144 = 1 or
not(var312 = 1)) and (var145 = 1 or not(var312 = 1)) and (var148 = 1 or not(
var312 = 1)) and (var150 = 1 or not(var312 = 1)) and (var151 = 1 or not(var312 =
 1)) and (var154 = 1 or not(var312 = 1)) and (var155 = 1 or not(var312 = 1)) and
 (var158 = 1 or not(var312 = 1)) and (var160 = 1 or not(var312 = 1)) and (var162
 = 1 or not(var312 = 1)) and (var163 = 1 or not(var312 = 1)) and (var165 = 1 or
not(var312 = 1)) and (var168 = 1 or not(var312 = 1)) and (var170 = 1 or not(
var312 = 1)) and (var171 = 1 or not(var312 = 1)) and (var174 = 1 or not(var312 =
 1)) and (var175 = 1 or not(var312 = 1)) and (var178 = 1 or not(var312 = 1)) and
 (var180 = 1 or not(var312 = 1)) and (var182 = 1 or not(var312 = 1)) and (var183
 = 1 or not(var312 = 1)) and (var186 = 1 or not(var312 = 1)) and (var187 = 1 or
not(var312 = 1)) and (var189 = 1 or not(var312 = 1)) and (var191 = 1 or not(
var312 = 1)) and (var1 = 1 or not(var313 = 1)) and (var4 = 1 or not(var313 = 1))
 and (var6 = 1 or not(var313 = 1)) and (var8 = 1 or not(var313 = 1)) and (var10
= 1 or not(var313 = 1)) and (var12 = 1 or not(var313 = 1)) and (var13 = 1 or not
(var313 = 1)) and (var15 = 1 or not(var313 = 1)) and (var18 = 1 or not(var313 =
1)) and (var19 = 1 or not(var313 = 1)) and (var22 = 1 or not(var313 = 1)) and (
var23 = 1 or not(var313 = 1)) and (var25 = 1 or not(var313 = 1)) and (var28 = 1
or not(var313 = 1)) and (var29 = 1 or not(var313 = 1)) and (var32 = 1 or not(
var313 = 1)) and (var34 = 1 or not(var313 = 1)) and (var35 = 1 or not(var313 = 1
)) and (var38 = 1 or not(var313 = 1)) and (var39 = 1 or not(var313 = 1)) and (
var42 = 1 or not(var313 = 1)) and (var43 = 1 or not(var313 = 1)) and (var45 = 1
or not(var313 = 1)) and (var48 = 1 or not(var313 = 1)) and (var50 = 1 or not(
var313 = 1)) and (var52 = 1 or not(var313 = 1)) and (var53 = 1 or not(var313 = 1
)) and (var56 = 1 or not(var313 = 1)) and (var58 = 1 or not(var313 = 1)) and (
var59 = 1 or not(var313 = 1)) and (var61 = 1 or not(var313 = 1)) and (var63 = 1
or not(var313 = 1)) and (var65 = 1 or not(var314 = 1)) and (var68 = 1 or not(
var314 = 1)) and (var70 = 1 or not(var314 = 1)) and (var72 = 1 or not(var314 = 1
)) and (var74 = 1 or not(var314 = 1)) and (var76 = 1 or not(var314 = 1)) and (
var77 = 1 or not(var314 = 1)) and (var79 = 1 or not(var314 = 1)) and (var82 = 1
or not(var314 = 1)) and (var83 = 1 or not(var314 = 1)) and (var86 = 1 or not(
var314 = 1)) and (var87 = 1 or not(var314 = 1)) and (var89 = 1 or not(var314 = 1
)) and (var92 = 1 or not(var314 = 1)) and (var93 = 1 or not(var314 = 1)) and (
var96 = 1 or not(var314 = 1)) and (var98 = 1 or not(var314 = 1)) and (var99 = 1
or not(var314 = 1)) and (var102 = 1 or not(var314 = 1)) and (var103 = 1 or not(
var314 = 1)) and (var106 = 1 or not(var314 = 1)) and (var107 = 1 or not(var314 =
 1)) and (var109 = 1 or not(var314 = 1)) and (var112 = 1 or not(var314 = 1)) and
 (var114 = 1 or not(var314 = 1)) and (var116 = 1 or not(var314 = 1)) and (var117
 = 1 or not(var314 = 1)) and (var120 = 1 or not(var314 = 1)) and (var122 = 1 or
not(var314 = 1)) and (var123 = 1 or not(var314 = 1)) and (var125 = 1 or not(
var314 = 1)) and (var127 = 1 or not(var314 = 1)) and (var129 = 1 or not(var315 =
 1)) and (var132 = 1 or not(var315 = 1)) and (var134 = 1 or not(var315 = 1)) and
 (var136 = 1 or not(var315 = 1)) and (var138 = 1 or not(var315 = 1)) and (var140
 = 1 or not(var315 = 1)) and (var141 = 1 or not(var315 = 1)) and (var143 = 1 or
not(var315 = 1)) and (var146 = 1 or not(var315 = 1)) and (var147 = 1 or not(
var315 = 1)) and (var150 = 1 or not(var315 = 1)) and (var151 = 1 or not(var315 =
 1)) and (var153 = 1 or not(var315 = 1)) and (var156 = 1 or not(var315 = 1)) and
 (var157 = 1 or not(var315 = 1)) and (var160 = 1 or not(var315 = 1)) and (var162
 = 1 or not(var315 = 1)) and (var163 = 1 or not(var315 = 1)) and (var166 = 1 or
not(var315 = 1)) and (var167 = 1 or not(var315 = 1)) and (var170 = 1 or not(
var315 = 1)) and (var171 = 1 or not(var315 = 1)) and (var173 = 1 or not(var315 =
 1)) and (var176 = 1 or not(var315 = 1)) and (var178 = 1 or not(var315 = 1)) and
 (var180 = 1 or not(var315 = 1)) and (var181 = 1 or not(var315 = 1)) and (var184
 = 1 or not(var315 = 1)) and (var186 = 1 or not(var315 = 1)) and (var187 = 1 or
not(var315 = 1)) and (var189 = 1 or not(var315 = 1)) and (var191 = 1 or not(
var315 = 1)) and (var2 = 1 or not(var316 = 1)) and (var4 = 1 or not(var316 = 1))
 and (var6 = 1 or not(var316 = 1)) and (var8 = 1 or not(var316 = 1)) and (var9 =
 1 or not(var316 = 1)) and (var12 = 1 or not(var316 = 1)) and (var14 = 1 or not(
var316 = 1)) and (var15 = 1 or not(var316 = 1)) and (var18 = 1 or not(var316 = 1
)) and (var20 = 1 or not(var316 = 1)) and (var21 = 1 or not(var316 = 1)) and (
var23 = 1 or not(var316 = 1)) and (var25 = 1 or not(var316 = 1)) and (var28 = 1
or not(var316 = 1)) and (var29 = 1 or not(var316 = 1)) and (var32 = 1 or not(
var316 = 1)) and (var33 = 1 or not(var316 = 1)) and (var35 = 1 or not(var316 = 1
)) and (var37 = 1 or not(var316 = 1)) and (var39 = 1 or not(var316 = 1)) and (
var42 = 1 or not(var316 = 1)) and (var43 = 1 or not(var316 = 1)) and (var46 = 1
or not(var316 = 1)) and (var48 = 1 or not(var316 = 1)) and (var50 = 1 or not(
var316 = 1)) and (var52 = 1 or not(var316 = 1)) and (var53 = 1 or not(var316 = 1
)) and (var55 = 1 or not(var316 = 1)) and (var58 = 1 or not(var316 = 1)) and (
var59 = 1 or not(var316 = 1)) and (var61 = 1 or not(var316 = 1)) and (var63 = 1
or not(var316 = 1)) and (var66 = 1 or not(var317 = 1)) and (var68 = 1 or not(
var317 = 1)) and (var70 = 1 or not(var317 = 1)) and (var72 = 1 or not(var317 = 1
)) and (var73 = 1 or not(var317 = 1)) and (var76 = 1 or not(var317 = 1)) and (
var78 = 1 or not(var317 = 1)) and (var79 = 1 or not(var317 = 1)) and (var82 = 1
or not(var317 = 1)) and (var84 = 1 or not(var317 = 1)) and (var85 = 1 or not(
var317 = 1)) and (var87 = 1 or not(var317 = 1)) and (var89 = 1 or not(var317 = 1
)) and (var92 = 1 or not(var317 = 1)) and (var93 = 1 or not(var317 = 1)) and (
var96 = 1 or not(var317 = 1)) and (var97 = 1 or not(var317 = 1)) and (var99 = 1
or not(var317 = 1)) and (var101 = 1 or not(var317 = 1)) and (var103 = 1 or not(
var317 = 1)) and (var106 = 1 or not(var317 = 1)) and (var107 = 1 or not(var317 =
 1)) and (var110 = 1 or not(var317 = 1)) and (var112 = 1 or not(var317 = 1)) and
 (var114 = 1 or not(var317 = 1)) and (var116 = 1 or not(var317 = 1)) and (var117
 = 1 or not(var317 = 1)) and (var119 = 1 or not(var317 = 1)) and (var122 = 1 or
not(var317 = 1)) and (var123 = 1 or not(var317 = 1)) and (var125 = 1 or not(
var317 = 1)) and (var127 = 1 or not(var317 = 1)) and (var130 = 1 or not(var318 =
 1)) and (var132 = 1 or not(var318 = 1)) and (var134 = 1 or not(var318 = 1)) and
 (var136 = 1 or not(var318 = 1)) and (var137 = 1 or not(var318 = 1)) and (var140
 = 1 or not(var318 = 1)) and (var142 = 1 or not(var318 = 1)) and (var143 = 1 or
not(var318 = 1)) and (var146 = 1 or not(var318 = 1)) and (var148 = 1 or not(
var318 = 1)) and (var149 = 1 or not(var318 = 1)) and (var151 = 1 or not(var318 =
 1)) and (var153 = 1 or not(var318 = 1)) and (var156 = 1 or not(var318 = 1)) and
 (var157 = 1 or not(var318 = 1)) and (var160 = 1 or not(var318 = 1)) and (var161
 = 1 or not(var318 = 1)) and (var163 = 1 or not(var318 = 1)) and (var165 = 1 or
not(var318 = 1)) and (var167 = 1 or not(var318 = 1)) and (var170 = 1 or not(
var318 = 1)) and (var171 = 1 or not(var318 = 1)) and (var174 = 1 or not(var318 =
 1)) and (var176 = 1 or not(var318 = 1)) and (var178 = 1 or not(var318 = 1)) and
 (var180 = 1 or not(var318 = 1)) and (var181 = 1 or not(var318 = 1)) and (var183
 = 1 or not(var318 = 1)) and (var186 = 1 or not(var318 = 1)) and (var187 = 1 or
not(var318 = 1)) and (var189 = 1 or not(var318 = 1)) and (var191 = 1 or not(
var318 = 1)) and (var1 = 1 or not(var319 = 1)) and (var4 = 1 or not(var319 = 1))
 and (var6 = 1 or not(var319 = 1)) and (var8 = 1 or not(var319 = 1)) and (var10
= 1 or not(var319 = 1)) and (var11 = 1 or not(var319 = 1)) and (var14 = 1 or not
(var319 = 1)) and (var15 = 1 or not(var319 = 1)) and (var17 = 1 or not(var319 =
1)) and (var20 = 1 or not(var319 = 1)) and (var22 = 1 or not(var319 = 1)) and (
var24 = 1 or not(var319 = 1)) and (var25 = 1 or not(var319 = 1)) and (var27 = 1
or not(var319 = 1)) and (var30 = 1 or not(var319 = 1)) and (var31 = 1 or not(
var319 = 1)) and (var34 = 1 or not(var319 = 1)) and (var35 = 1 or not(var319 = 1
)) and (var38 = 1 or not(var319 = 1)) and (var40 = 1 or not(var319 = 1)) and (
var41 = 1 or not(var319 = 1)) and (var43 = 1 or not(var319 = 1)) and (var45 = 1
or not(var319 = 1)) and (var48 = 1 or not(var319 = 1)) and (var50 = 1 or not(
var319 = 1)) and (var51 = 1 or not(var319 = 1)) and (var53 = 1 or not(var319 = 1
)) and (var55 = 1 or not(var319 = 1)) and (var58 = 1 or not(var319 = 1)) and (
var59 = 1 or not(var319 = 1)) and (var61 = 1 or not(var319 = 1)) and (var63 = 1
or not(var319 = 1)) and (var65 = 1 or not(var320 = 1)) and (var68 = 1 or not(
var320 = 1)) and (var70 = 1 or not(var320 = 1)) and (var72 = 1 or not(var320 = 1
)) and (var74 = 1 or not(var320 = 1)) and (var75 = 1 or not(var320 = 1)) and (
var78 = 1 or not(var320 = 1)) and (var79 = 1 or not(var320 = 1)) and (var81 = 1
or not(var320 = 1)) and (var84 = 1 or not(var320 = 1)) and (var86 = 1 or not(
var320 = 1)) and (var88 = 1 or not(var320 = 1)) and (var89 = 1 or not(var320 = 1
)) and (var91 = 1 or not(var320 = 1)) and (var94 = 1 or not(var320 = 1)) and (
var95 = 1 or not(var320 = 1)) and (var98 = 1 or not(var320 = 1)) and (var99 = 1
or not(var320 = 1)) and (var102 = 1 or not(var320 = 1)) and (var104 = 1 or not(
var320 = 1)) and (var105 = 1 or not(var320 = 1)) and (var107 = 1 or not(var320 =
 1)) and (var109 = 1 or not(var320 = 1)) and (var112 = 1 or not(var320 = 1)) and
 (var114 = 1 or not(var320 = 1)) and (var115 = 1 or not(var320 = 1)) and (var117
 = 1 or not(var320 = 1)) and (var119 = 1 or not(var320 = 1)) and (var122 = 1 or
not(var320 = 1)) and (var123 = 1 or not(var320 = 1)) and (var125 = 1 or not(
var320 = 1)) and (var127 = 1 or not(var320 = 1)) and (var129 = 1 or not(var321 =
 1)) and (var132 = 1 or not(var321 = 1)) and (var134 = 1 or not(var321 = 1)) and
 (var136 = 1 or not(var321 = 1)) and (var138 = 1 or not(var321 = 1)) and (var139
 = 1 or not(var321 = 1)) and (var142 = 1 or not(var321 = 1)) and (var143 = 1 or
not(var321 = 1)) and (var145 = 1 or not(var321 = 1)) and (var148 = 1 or not(
var321 = 1)) and (var150 = 1 or not(var321 = 1)) and (var152 = 1 or not(var321 =
 1)) and (var153 = 1 or not(var321 = 1)) and (var155 = 1 or not(var321 = 1)) and
 (var158 = 1 or not(var321 = 1)) and (var159 = 1 or not(var321 = 1)) and (var162
 = 1 or not(var321 = 1)) and (var163 = 1 or not(var321 = 1)) and (var166 = 1 or
not(var321 = 1)) and (var168 = 1 or not(var321 = 1)) and (var169 = 1 or not(
var321 = 1)) and (var171 = 1 or not(var321 = 1)) and (var173 = 1 or not(var321 =
 1)) and (var176 = 1 or not(var321 = 1)) and (var178 = 1 or not(var321 = 1)) and
 (var179 = 1 or not(var321 = 1)) and (var181 = 1 or not(var321 = 1)) and (var183
 = 1 or not(var321 = 1)) and (var186 = 1 or not(var321 = 1)) and (var187 = 1 or
not(var321 = 1)) and (var189 = 1 or not(var321 = 1)) and (var191 = 1 or not(
var321 = 1)) and (var1 = 1 or not(var322 = 1)) and (var4 = 1 or not(var322 = 1))
 and (var5 = 1 or not(var322 = 1)) and (var7 = 1 or not(var322 = 1)) and (var9 =
 1 or not(var322 = 1)) and (var12 = 1 or not(var322 = 1)) and (var13 = 1 or not(
var322 = 1)) and (var16 = 1 or not(var322 = 1)) and (var18 = 1 or not(var322 = 1
)) and (var19 = 1 or not(var322 = 1)) and (var22 = 1 or not(var322 = 1)) and (
var23 = 1 or not(var322 = 1)) and (var25 = 1 or not(var322 = 1)) and (var28 = 1
or not(var322 = 1)) and (var30 = 1 or not(var322 = 1)) and (var32 = 1 or not(
var322 = 1)) and (var34 = 1 or not(var322 = 1)) and (var36 = 1 or not(var322 = 1
)) and (var38 = 1 or not(var322 = 1)) and (var39 = 1 or not(var322 = 1)) and (
var42 = 1 or not(var322 = 1)) and (var43 = 1 or not(var322 = 1)) and (var45 = 1
or not(var322 = 1)) and (var47 = 1 or not(var322 = 1)) and (var49 = 1 or not(
var322 = 1)) and (var52 = 1 or not(var322 = 1)) and (var53 = 1 or not(var322 = 1
)) and (var56 = 1 or not(var322 = 1)) and (var58 = 1 or not(var322 = 1)) and (
var59 = 1 or not(var322 = 1)) and (var61 = 1 or not(var322 = 1)) and (var63 = 1
or not(var322 = 1)) and (var65 = 1 or not(var323 = 1)) and (var68 = 1 or not(
var323 = 1)) and (var69 = 1 or not(var323 = 1)) and (var71 = 1 or not(var323 = 1
)) and (var73 = 1 or not(var323 = 1)) and (var76 = 1 or not(var323 = 1)) and (
var77 = 1 or not(var323 = 1)) and (var80 = 1 or not(var323 = 1)) and (var82 = 1
or not(var323 = 1)) and (var83 = 1 or not(var323 = 1)) and (var86 = 1 or not(
var323 = 1)) and (var87 = 1 or not(var323 = 1)) and (var89 = 1 or not(var323 = 1
)) and (var92 = 1 or not(var323 = 1)) and (var94 = 1 or not(var323 = 1)) and (
var96 = 1 or not(var323 = 1)) and (var98 = 1 or not(var323 = 1)) and (var100 = 1
 or not(var323 = 1)) and (var102 = 1 or not(var323 = 1)) and (var103 = 1 or not(
var323 = 1)) and (var106 = 1 or not(var323 = 1)) and (var107 = 1 or not(var323 =
 1)) and (var109 = 1 or not(var323 = 1)) and (var111 = 1 or not(var323 = 1)) and
 (var113 = 1 or not(var323 = 1)) and (var116 = 1 or not(var323 = 1)) and (var117
 = 1 or not(var323 = 1)) and (var120 = 1 or not(var323 = 1)) and (var122 = 1 or
not(var323 = 1)) and (var123 = 1 or not(var323 = 1)) and (var125 = 1 or not(
var323 = 1)) and (var127 = 1 or not(var323 = 1)) and (var129 = 1 or not(var324 =
 1)) and (var132 = 1 or not(var324 = 1)) and (var133 = 1 or not(var324 = 1)) and
 (var135 = 1 or not(var324 = 1)) and (var137 = 1 or not(var324 = 1)) and (var140
 = 1 or not(var324 = 1)) and (var141 = 1 or not(var324 = 1)) and (var144 = 1 or
not(var324 = 1)) and (var146 = 1 or not(var324 = 1)) and (var147 = 1 or not(
var324 = 1)) and (var150 = 1 or not(var324 = 1)) and (var151 = 1 or not(var324 =
 1)) and (var153 = 1 or not(var324 = 1)) and (var156 = 1 or not(var324 = 1)) and
 (var158 = 1 or not(var324 = 1)) and (var160 = 1 or not(var324 = 1)) and (var162
 = 1 or not(var324 = 1)) and (var164 = 1 or not(var324 = 1)) and (var166 = 1 or
not(var324 = 1)) and (var167 = 1 or not(var324 = 1)) and (var170 = 1 or not(
var324 = 1)) and (var171 = 1 or not(var324 = 1)) and (var173 = 1 or not(var324 =
 1)) and (var175 = 1 or not(var324 = 1)) and (var177 = 1 or not(var324 = 1)) and
 (var180 = 1 or not(var324 = 1)) and (var181 = 1 or not(var324 = 1)) and (var184
 = 1 or not(var324 = 1)) and (var186 = 1 or not(var324 = 1)) and (var187 = 1 or
not(var324 = 1)) and (var189 = 1 or not(var324 = 1)) and (var191 = 1 or not(
var324 = 1)) and (var1 = 1 or not(var325 = 1)) and (var4 = 1 or not(var325 = 1))
 and (var5 = 1 or not(var325 = 1)) and (var7 = 1 or not(var325 = 1)) and (var10
= 1 or not(var325 = 1)) and (var11 = 1 or not(var325 = 1)) and (var14 = 1 or not
(var325 = 1)) and (var16 = 1 or not(var325 = 1)) and (var17 = 1 or not(var325 =
1)) and (var20 = 1 or not(var325 = 1)) and (var21 = 1 or not(var325 = 1)) and (
var24 = 1 or not(var325 = 1)) and (var26 = 1 or not(var325 = 1)) and (var28 = 1
or not(var325 = 1)) and (var30 = 1 or not(var325 = 1)) and (var31 = 1 or not(
var325 = 1)) and (var34 = 1 or not(var325 = 1)) and (var36 = 1 or not(var325 = 1
)) and (var38 = 1 or not(var325 = 1)) and (var39 = 1 or not(var325 = 1)) and (
var42 = 1 or not(var325 = 1)) and (var44 = 1 or not(var325 = 1)) and (var45 = 1
or not(var325 = 1)) and (var48 = 1 or not(var325 = 1)) and (var50 = 1 or not(
var325 = 1)) and (var51 = 1 or not(var325 = 1)) and (var53 = 1 or not(var325 = 1
)) and (var55 = 1 or not(var325 = 1)) and (var58 = 1 or not(var325 = 1)) and (
var59 = 1 or not(var325 = 1)) and (var61 = 1 or not(var325 = 1)) and (var63 = 1
or not(var325 = 1)) and (var65 = 1 or not(var326 = 1)) and (var68 = 1 or not(
var326 = 1)) and (var69 = 1 or not(var326 = 1)) and (var71 = 1 or not(var326 = 1
)) and (var74 = 1 or not(var326 = 1)) and (var75 = 1 or not(var326 = 1)) and (
var78 = 1 or not(var326 = 1)) and (var80 = 1 or not(var326 = 1)) and (var81 = 1
or not(var326 = 1)) and (var84 = 1 or not(var326 = 1)) and (var85 = 1 or not(
var326 = 1)) and (var88 = 1 or not(var326 = 1)) and (var90 = 1 or not(var326 = 1
)) and (var92 = 1 or not(var326 = 1)) and (var94 = 1 or not(var326 = 1)) and (
var95 = 1 or not(var326 = 1)) and (var98 = 1 or not(var326 = 1)) and (var100 = 1
 or not(var326 = 1)) and (var102 = 1 or not(var326 = 1)) and (var103 = 1 or not(
var326 = 1)) and (var106 = 1 or not(var326 = 1)) and (var108 = 1 or not(var326 =
 1)) and (var109 = 1 or not(var326 = 1)) and (var112 = 1 or not(var326 = 1)) and
 (var114 = 1 or not(var326 = 1)) and (var115 = 1 or not(var326 = 1)) and (var117
 = 1 or not(var326 = 1)) and (var119 = 1 or not(var326 = 1)) and (var122 = 1 or
not(var326 = 1)) and (var123 = 1 or not(var326 = 1)) and (var125 = 1 or not(
var326 = 1)) and (var127 = 1 or not(var326 = 1)) and (var129 = 1 or not(var327 =
 1)) and (var132 = 1 or not(var327 = 1)) and (var133 = 1 or not(var327 = 1)) and
 (var135 = 1 or not(var327 = 1)) and (var138 = 1 or not(var327 = 1)) and (var139
 = 1 or not(var327 = 1)) and (var142 = 1 or not(var327 = 1)) and (var144 = 1 or
not(var327 = 1)) and (var145 = 1 or not(var327 = 1)) and (var148 = 1 or not(
var327 = 1)) and (var149 = 1 or not(var327 = 1)) and (var152 = 1 or not(var327 =
 1)) and (var154 = 1 or not(var327 = 1)) and (var156 = 1 or not(var327 = 1)) and
 (var158 = 1 or not(var327 = 1)) and (var159 = 1 or not(var327 = 1)) and (var162
 = 1 or not(var327 = 1)) and (var164 = 1 or not(var327 = 1)) and (var166 = 1 or
not(var327 = 1)) and (var167 = 1 or not(var327 = 1)) and (var170 = 1 or not(
var327 = 1)) and (var172 = 1 or not(var327 = 1)) and (var173 = 1 or not(var327 =
 1)) and (var176 = 1 or not(var327 = 1)) and (var178 = 1 or not(var327 = 1)) and
 (var179 = 1 or not(var327 = 1)) and (var181 = 1 or not(var327 = 1)) and (var183
 = 1 or not(var327 = 1)) and (var186 = 1 or not(var327 = 1)) and (var187 = 1 or
not(var327 = 1)) and (var189 = 1 or not(var327 = 1)) and (var191 = 1 or not(
var327 = 1)) and (var1 = 1 or not(var328 = 1)) and (var4 = 1 or not(var328 = 1))
 and (var5 = 1 or not(var328 = 1)) and (var8 = 1 or not(var328 = 1)) and (var10
= 1 or not(var328 = 1)) and (var11 = 1 or not(var328 = 1)) and (var14 = 1 or not
(var328 = 1)) and (var15 = 1 or not(var328 = 1)) and (var17 = 1 or not(var328 =
1)) and (var19 = 1 or not(var328 = 1)) and (var22 = 1 or not(var328 = 1)) and (
var24 = 1 or not(var328 = 1)) and (var25 = 1 or not(var328 = 1)) and (var27 = 1
or not(var328 = 1)) and (var30 = 1 or not(var328 = 1)) and (var32 = 1 or not(
var328 = 1)) and (var34 = 1 or not(var328 = 1)) and (var35 = 1 or not(var328 = 1
)) and (var37 = 1 or not(var328 = 1)) and (var39 = 1 or not(var328 = 1)) and (
var42 = 1 or not(var328 = 1)) and (var43 = 1 or not(var328 = 1)) and (var46 = 1
or not(var328 = 1)) and (var47 = 1 or not(var328 = 1)) and (var49 = 1 or not(
var328 = 1)) and (var52 = 1 or not(var328 = 1)) and (var54 = 1 or not(var328 = 1
)) and (var56 = 1 or not(var328 = 1)) and (var58 = 1 or not(var328 = 1)) and (
var60 = 1 or not(var328 = 1)) and (var61 = 1 or not(var328 = 1)) and (var64 = 1
or not(var328 = 1)) and (var65 = 1 or not(var329 = 1)) and (var68 = 1 or not(
var329 = 1)) and (var69 = 1 or not(var329 = 1)) and (var72 = 1 or not(var329 = 1
)) and (var74 = 1 or not(var329 = 1)) and (var75 = 1 or not(var329 = 1)) and (
var78 = 1 or not(var329 = 1)) and (var79 = 1 or not(var329 = 1)) and (var81 = 1
or not(var329 = 1)) and (var83 = 1 or not(var329 = 1)) and (var86 = 1 or not(
var329 = 1)) and (var88 = 1 or not(var329 = 1)) and (var89 = 1 or not(var329 = 1
)) and (var91 = 1 or not(var329 = 1)) and (var94 = 1 or not(var329 = 1)) and (
var96 = 1 or not(var329 = 1)) and (var98 = 1 or not(var329 = 1)) and (var99 = 1
or not(var329 = 1)) and (var101 = 1 or not(var329 = 1)) and (var103 = 1 or not(
var329 = 1)) and (var106 = 1 or not(var329 = 1)) and (var107 = 1 or not(var329 =
 1)) and (var110 = 1 or not(var329 = 1)) and (var111 = 1 or not(var329 = 1)) and
 (var113 = 1 or not(var329 = 1)) and (var116 = 1 or not(var329 = 1)) and (var118
 = 1 or not(var329 = 1)) and (var120 = 1 or not(var329 = 1)) and (var122 = 1 or
not(var329 = 1)) and (var124 = 1 or not(var329 = 1)) and (var125 = 1 or not(
var329 = 1)) and (var128 = 1 or not(var329 = 1)) and (var129 = 1 or not(var330 =
 1)) and (var132 = 1 or not(var330 = 1)) and (var133 = 1 or not(var330 = 1)) and
 (var136 = 1 or not(var330 = 1)) and (var138 = 1 or not(var330 = 1)) and (var139
 = 1 or not(var330 = 1)) and (var142 = 1 or not(var330 = 1)) and (var143 = 1 or
not(var330 = 1)) and (var145 = 1 or not(var330 = 1)) and (var147 = 1 or not(
var330 = 1)) and (var150 = 1 or not(var330 = 1)) and (var152 = 1 or not(var330 =
 1)) and (var153 = 1 or not(var330 = 1)) and (var155 = 1 or not(var330 = 1)) and
 (var158 = 1 or not(var330 = 1)) and (var160 = 1 or not(var330 = 1)) and (var162
 = 1 or not(var330 = 1)) and (var163 = 1 or not(var330 = 1)) and (var165 = 1 or
not(var330 = 1)) and (var167 = 1 or not(var330 = 1)) and (var170 = 1 or not(
var330 = 1)) and (var171 = 1 or not(var330 = 1)) and (var174 = 1 or not(var330 =
 1)) and (var175 = 1 or not(var330 = 1)) and (var177 = 1 or not(var330 = 1)) and
 (var180 = 1 or not(var330 = 1)) and (var182 = 1 or not(var330 = 1)) and (var184
 = 1 or not(var330 = 1)) and (var186 = 1 or not(var330 = 1)) and (var188 = 1 or
not(var330 = 1)) and (var189 = 1 or not(var330 = 1)) and (var192 = 1 or not(
var330 = 1)) and (var2 = 1 or not(var331 = 1)) and (var4 = 1 or not(var331 = 1))
 and (var6 = 1 or not(var331 = 1)) and (var8 = 1 or not(var331 = 1)) and (var9 =
 1 or not(var331 = 1)) and (var11 = 1 or not(var331 = 1)) and (var13 = 1 or not(
var331 = 1)) and (var15 = 1 or not(var331 = 1)) and (var18 = 1 or not(var331 = 1
)) and (var19 = 1 or not(var331 = 1)) and (var22 = 1 or not(var331 = 1)) and (
var24 = 1 or not(var331 = 1)) and (var25 = 1 or not(var331 = 1)) and (var28 = 1
or not(var331 = 1)) and (var30 = 1 or not(var331 = 1)) and (var31 = 1 or not(
var331 = 1)) and (var34 = 1 or not(var331 = 1)) and (var36 = 1 or not(var331 = 1
)) and (var38 = 1 or not(var331 = 1)) and (var39 = 1 or not(var331 = 1)) and (
var41 = 1 or not(var331 = 1)) and (var43 = 1 or not(var331 = 1)) and (var45 = 1
or not(var331 = 1)) and (var48 = 1 or not(var331 = 1)) and (var50 = 1 or not(
var331 = 1)) and (var52 = 1 or not(var331 = 1)) and (var54 = 1 or not(var331 = 1
)) and (var55 = 1 or not(var331 = 1)) and (var58 = 1 or not(var331 = 1)) and (
var59 = 1 or not(var331 = 1)) and (var61 = 1 or not(var331 = 1)) and (var64 = 1
or not(var331 = 1)) and (var66 = 1 or not(var332 = 1)) and (var68 = 1 or not(
var332 = 1)) and (var70 = 1 or not(var332 = 1)) and (var72 = 1 or not(var332 = 1
)) and (var73 = 1 or not(var332 = 1)) and (var75 = 1 or not(var332 = 1)) and (
var77 = 1 or not(var332 = 1)) and (var79 = 1 or not(var332 = 1)) and (var82 = 1
or not(var332 = 1)) and (var83 = 1 or not(var332 = 1)) and (var86 = 1 or not(
var332 = 1)) and (var88 = 1 or not(var332 = 1)) and (var89 = 1 or not(var332 = 1
)) and (var92 = 1 or not(var332 = 1)) and (var94 = 1 or not(var332 = 1)) and (
var95 = 1 or not(var332 = 1)) and (var98 = 1 or not(var332 = 1)) and (var100 = 1
 or not(var332 = 1)) and (var102 = 1 or not(var332 = 1)) and (var103 = 1 or not(
var332 = 1)) and (var105 = 1 or not(var332 = 1)) and (var107 = 1 or not(var332 =
 1)) and (var109 = 1 or not(var332 = 1)) and (var112 = 1 or not(var332 = 1)) and
 (var114 = 1 or not(var332 = 1)) and (var116 = 1 or not(var332 = 1)) and (var118
 = 1 or not(var332 = 1)) and (var119 = 1 or not(var332 = 1)) and (var122 = 1 or
not(var332 = 1)) and (var123 = 1 or not(var332 = 1)) and (var125 = 1 or not(
var332 = 1)) and (var128 = 1 or not(var332 = 1)) and (var130 = 1 or not(var333 =
 1)) and (var132 = 1 or not(var333 = 1)) and (var134 = 1 or not(var333 = 1)) and
 (var136 = 1 or not(var333 = 1)) and (var137 = 1 or not(var333 = 1)) and (var139
 = 1 or not(var333 = 1)) and (var141 = 1 or not(var333 = 1)) and (var143 = 1 or
not(var333 = 1)) and (var146 = 1 or not(var333 = 1)) and (var147 = 1 or not(
var333 = 1)) and (var150 = 1 or not(var333 = 1)) and (var152 = 1 or not(var333 =
 1)) and (var153 = 1 or not(var333 = 1)) and (var156 = 1 or not(var333 = 1)) and
 (var158 = 1 or not(var333 = 1)) and (var159 = 1 or not(var333 = 1)) and (var162
 = 1 or not(var333 = 1)) and (var164 = 1 or not(var333 = 1)) and (var166 = 1 or
not(var333 = 1)) and (var167 = 1 or not(var333 = 1)) and (var169 = 1 or not(
var333 = 1)) and (var171 = 1 or not(var333 = 1)) and (var173 = 1 or not(var333 =
 1)) and (var176 = 1 or not(var333 = 1)) and (var178 = 1 or not(var333 = 1)) and
 (var180 = 1 or not(var333 = 1)) and (var182 = 1 or not(var333 = 1)) and (var183
 = 1 or not(var333 = 1)) and (var186 = 1 or not(var333 = 1)) and (var187 = 1 or
not(var333 = 1)) and (var189 = 1 or not(var333 = 1)) and (var192 = 1 or not(
var333 = 1)) and (var2 = 1 or not(var334 = 1)) and (var4 = 1 or not(var334 = 1))
 and (var5 = 1 or not(var334 = 1)) and (var8 = 1 or not(var334 = 1)) and (var10
= 1 or not(var334 = 1)) and (var12 = 1 or not(var334 = 1)) and (var13 = 1 or not
(var334 = 1)) and (var15 = 1 or not(var334 = 1)) and (var18 = 1 or not(var334 =
1)) and (var20 = 1 or not(var334 = 1)) and (var21 = 1 or not(var334 = 1)) and (
var23 = 1 or not(var334 = 1)) and (var26 = 1 or not(var334 = 1)) and (var28 = 1
or not(var334 = 1)) and (var30 = 1 or not(var334 = 1)) and (var31 = 1 or not(
var334 = 1)) and (var33 = 1 or not(var334 = 1)) and (var35 = 1 or not(var334 = 1
)) and (var37 = 1 or not(var334 = 1)) and (var40 = 1 or not(var334 = 1)) and (
var41 = 1 or not(var334 = 1)) and (var44 = 1 or not(var334 = 1)) and (var46 = 1
or not(var334 = 1)) and (var47 = 1 or not(var334 = 1)) and (var49 = 1 or not(
var334 = 1)) and (var51 = 1 or not(var334 = 1)) and (var54 = 1 or not(var334 = 1
)) and (var56 = 1 or not(var334 = 1)) and (var58 = 1 or not(var334 = 1)) and (
var60 = 1 or not(var334 = 1)) and (var62 = 1 or not(var334 = 1)) and (var64 = 1
or not(var334 = 1)) and (var66 = 1 or not(var335 = 1)) and (var68 = 1 or not(
var335 = 1)) and (var69 = 1 or not(var335 = 1)) and (var72 = 1 or not(var335 = 1
)) and (var74 = 1 or not(var335 = 1)) and (var76 = 1 or not(var335 = 1)) and (
var77 = 1 or not(var335 = 1)) and (var79 = 1 or not(var335 = 1)) and (var82 = 1
or not(var335 = 1)) and (var84 = 1 or not(var335 = 1)) and (var85 = 1 or not(
var335 = 1)) and (var87 = 1 or not(var335 = 1)) and (var90 = 1 or not(var335 = 1
)) and (var92 = 1 or not(var335 = 1)) and (var94 = 1 or not(var335 = 1)) and (
var95 = 1 or not(var335 = 1)) and (var97 = 1 or not(var335 = 1)) and (var99 = 1
or not(var335 = 1)) and (var101 = 1 or not(var335 = 1)) and (var104 = 1 or not(
var335 = 1)) and (var105 = 1 or not(var335 = 1)) and (var108 = 1 or not(var335 =
 1)) and (var110 = 1 or not(var335 = 1)) and (var111 = 1 or not(var335 = 1)) and
 (var113 = 1 or not(var335 = 1)) and (var115 = 1 or not(var335 = 1)) and (var118
 = 1 or not(var335 = 1)) and (var120 = 1 or not(var335 = 1)) and (var122 = 1 or
not(var335 = 1)) and (var124 = 1 or not(var335 = 1)) and (var126 = 1 or not(
var335 = 1)) and (var128 = 1 or not(var335 = 1)) and (var130 = 1 or not(var336 =
 1)) and (var132 = 1 or not(var336 = 1)) and (var133 = 1 or not(var336 = 1)) and
 (var136 = 1 or not(var336 = 1)) and (var138 = 1 or not(var336 = 1)) and (var140
 = 1 or not(var336 = 1)) and (var141 = 1 or not(var336 = 1)) and (var143 = 1 or
not(var336 = 1)) and (var146 = 1 or not(var336 = 1)) and (var148 = 1 or not(
var336 = 1)) and (var149 = 1 or not(var336 = 1)) and (var151 = 1 or not(var336 =
 1)) and (var154 = 1 or not(var336 = 1)) and (var156 = 1 or not(var336 = 1)) and
 (var158 = 1 or not(var336 = 1)) and (var159 = 1 or not(var336 = 1)) and (var161
 = 1 or not(var336 = 1)) and (var163 = 1 or not(var336 = 1)) and (var165 = 1 or
not(var336 = 1)) and (var168 = 1 or not(var336 = 1)) and (var169 = 1 or not(
var336 = 1)) and (var172 = 1 or not(var336 = 1)) and (var174 = 1 or not(var336 =
 1)) and (var175 = 1 or not(var336 = 1)) and (var177 = 1 or not(var336 = 1)) and
 (var179 = 1 or not(var336 = 1)) and (var182 = 1 or not(var336 = 1)) and (var184
 = 1 or not(var336 = 1)) and (var186 = 1 or not(var336 = 1)) and (var188 = 1 or
not(var336 = 1)) and (var190 = 1 or not(var336 = 1)) and (var192 = 1 or not(
var336 = 1)) and (var2 = 1 or not(var337 = 1)) and (var4 = 1 or not(var337 = 1))
 and (var5 = 1 or not(var337 = 1)) and (var7 = 1 or not(var337 = 1)) and (var10
= 1 or not(var337 = 1)) and (var11 = 1 or not(var337 = 1)) and (var14 = 1 or not
(var337 = 1)) and (var16 = 1 or not(var337 = 1)) and (var17 = 1 or not(var337 =
1)) and (var19 = 1 or not(var337 = 1)) and (var22 = 1 or not(var337 = 1)) and (
var23 = 1 or not(var337 = 1)) and (var25 = 1 or not(var337 = 1)) and (var27 = 1
or not(var337 = 1)) and (var30 = 1 or not(var337 = 1)) and (var31 = 1 or not(
var337 = 1)) and (var34 = 1 or not(var337 = 1)) and (var35 = 1 or not(var337 = 1
)) and (var38 = 1 or not(var337 = 1)) and (var40 = 1 or not(var337 = 1)) and (
var41 = 1 or not(var337 = 1)) and (var43 = 1 or not(var337 = 1)) and (var46 = 1
or not(var337 = 1)) and (var48 = 1 or not(var337 = 1)) and (var50 = 1 or not(
var337 = 1)) and (var51 = 1 or not(var337 = 1)) and (var53 = 1 or not(var337 = 1
)) and (var56 = 1 or not(var337 = 1)) and (var58 = 1 or not(var337 = 1)) and (
var59 = 1 or not(var337 = 1)) and (var61 = 1 or not(var337 = 1)) and (var64 = 1
or not(var337 = 1)) and (var66 = 1 or not(var338 = 1)) and (var68 = 1 or not(
var338 = 1)) and (var69 = 1 or not(var338 = 1)) and (var71 = 1 or not(var338 = 1
)) and (var74 = 1 or not(var338 = 1)) and (var75 = 1 or not(var338 = 1)) and (
var78 = 1 or not(var338 = 1)) and (var80 = 1 or not(var338 = 1)) and (var81 = 1
or not(var338 = 1)) and (var83 = 1 or not(var338 = 1)) and (var86 = 1 or not(
var338 = 1)) and (var87 = 1 or not(var338 = 1)) and (var89 = 1 or not(var338 = 1
)) and (var91 = 1 or not(var338 = 1)) and (var94 = 1 or not(var338 = 1)) and (
var95 = 1 or not(var338 = 1)) and (var98 = 1 or not(var338 = 1)) and (var99 = 1
or not(var338 = 1)) and (var102 = 1 or not(var338 = 1)) and (var104 = 1 or not(
var338 = 1)) and (var105 = 1 or not(var338 = 1)) and (var107 = 1 or not(var338 =
 1)) and (var110 = 1 or not(var338 = 1)) and (var112 = 1 or not(var338 = 1)) and
 (var114 = 1 or not(var338 = 1)) and (var115 = 1 or not(var338 = 1)) and (var117
 = 1 or not(var338 = 1)) and (var120 = 1 or not(var338 = 1)) and (var122 = 1 or
not(var338 = 1)) and (var123 = 1 or not(var338 = 1)) and (var125 = 1 or not(
var338 = 1)) and (var128 = 1 or not(var338 = 1)) and (var130 = 1 or not(var339 =
 1)) and (var132 = 1 or not(var339 = 1)) and (var133 = 1 or not(var339 = 1)) and
 (var135 = 1 or not(var339 = 1)) and (var138 = 1 or not(var339 = 1)) and (var139
 = 1 or not(var339 = 1)) and (var142 = 1 or not(var339 = 1)) and (var144 = 1 or
not(var339 = 1)) and (var145 = 1 or not(var339 = 1)) and (var147 = 1 or not(
var339 = 1)) and (var150 = 1 or not(var339 = 1)) and (var151 = 1 or not(var339 =
 1)) and (var153 = 1 or not(var339 = 1)) and (var155 = 1 or not(var339 = 1)) and
 (var158 = 1 or not(var339 = 1)) and (var159 = 1 or not(var339 = 1)) and (var162
 = 1 or not(var339 = 1)) and (var163 = 1 or not(var339 = 1)) and (var166 = 1 or
not(var339 = 1)) and (var168 = 1 or not(var339 = 1)) and (var169 = 1 or not(
var339 = 1)) and (var171 = 1 or not(var339 = 1)) and (var174 = 1 or not(var339 =
 1)) and (var176 = 1 or not(var339 = 1)) and (var178 = 1 or not(var339 = 1)) and
 (var179 = 1 or not(var339 = 1)) and (var181 = 1 or not(var339 = 1)) and (var184
 = 1 or not(var339 = 1)) and (var186 = 1 or not(var339 = 1)) and (var187 = 1 or
not(var339 = 1)) and (var189 = 1 or not(var339 = 1)) and (var192 = 1 or not(
var339 = 1)) and (var2 = 1 or not(var340 = 1)) and (var4 = 1 or not(var340 = 1))
 and (var5 = 1 or not(var340 = 1)) and (var7 = 1 or not(var340 = 1)) and (var10
= 1 or not(var340 = 1)) and (var12 = 1 or not(var340 = 1)) and (var14 = 1 or not
(var340 = 1)) and (var16 = 1 or not(var340 = 1)) and (var18 = 1 or not(var340 =
1)) and (var20 = 1 or not(var340 = 1)) and (var22 = 1 or not(var340 = 1)) and (
var24 = 1 or not(var340 = 1)) and (var26 = 1 or not(var340 = 1)) and (var27 = 1
or not(var340 = 1)) and (var29 = 1 or not(var340 = 1)) and (var31 = 1 or not(
var340 = 1)) and (var34 = 1 or not(var340 = 1)) and (var36 = 1 or not(var340 = 1
)) and (var37 = 1 or not(var340 = 1)) and (var39 = 1 or not(var340 = 1)) and (
var41 = 1 or not(var340 = 1)) and (var44 = 1 or not(var340 = 1)) and (var46 = 1
or not(var340 = 1)) and (var47 = 1 or not(var340 = 1)) and (var50 = 1 or not(
var340 = 1)) and (var52 = 1 or not(var340 = 1)) and (var53 = 1 or not(var340 = 1
)) and (var56 = 1 or not(var340 = 1)) and (var58 = 1 or not(var340 = 1)) and (
var60 = 1 or not(var340 = 1)) and (var61 = 1 or not(var340 = 1)) and (var64 = 1
or not(var340 = 1)) and (var66 = 1 or not(var341 = 1)) and (var68 = 1 or not(
var341 = 1)) and (var69 = 1 or not(var341 = 1)) and (var71 = 1 or not(var341 = 1
)) and (var74 = 1 or not(var341 = 1)) and (var76 = 1 or not(var341 = 1)) and (
var78 = 1 or not(var341 = 1)) and (var80 = 1 or not(var341 = 1)) and (var82 = 1
or not(var341 = 1)) and (var84 = 1 or not(var341 = 1)) and (var86 = 1 or not(
var341 = 1)) and (var88 = 1 or not(var341 = 1)) and (var90 = 1 or not(var341 = 1
)) and (var91 = 1 or not(var341 = 1)) and (var93 = 1 or not(var341 = 1)) and (
var95 = 1 or not(var341 = 1)) and (var98 = 1 or not(var341 = 1)) and (var100 = 1
 or not(var341 = 1)) and (var101 = 1 or not(var341 = 1)) and (var103 = 1 or not(
var341 = 1)) and (var105 = 1 or not(var341 = 1)) and (var108 = 1 or not(var341 =
 1)) and (var110 = 1 or not(var341 = 1)) and (var111 = 1 or not(var341 = 1)) and
 (var114 = 1 or not(var341 = 1)) and (var116 = 1 or not(var341 = 1)) and (var117
 = 1 or not(var341 = 1)) and (var120 = 1 or not(var341 = 1)) and (var122 = 1 or
not(var341 = 1)) and (var124 = 1 or not(var341 = 1)) and (var125 = 1 or not(
var341 = 1)) and (var128 = 1 or not(var341 = 1)) and (var130 = 1 or not(var342 =
 1)) and (var132 = 1 or not(var342 = 1)) and (var133 = 1 or not(var342 = 1)) and
 (var135 = 1 or not(var342 = 1)) and (var138 = 1 or not(var342 = 1)) and (var140
 = 1 or not(var342 = 1)) and (var142 = 1 or not(var342 = 1)) and (var144 = 1 or
not(var342 = 1)) and (var146 = 1 or not(var342 = 1)) and (var148 = 1 or not(
var342 = 1)) and (var150 = 1 or not(var342 = 1)) and (var152 = 1 or not(var342 =
 1)) and (var154 = 1 or not(var342 = 1)) and (var155 = 1 or not(var342 = 1)) and
 (var157 = 1 or not(var342 = 1)) and (var159 = 1 or not(var342 = 1)) and (var162
 = 1 or not(var342 = 1)) and (var164 = 1 or not(var342 = 1)) and (var165 = 1 or
not(var342 = 1)) and (var167 = 1 or not(var342 = 1)) and (var169 = 1 or not(
var342 = 1)) and (var172 = 1 or not(var342 = 1)) and (var174 = 1 or not(var342 =
 1)) and (var175 = 1 or not(var342 = 1)) and (var178 = 1 or not(var342 = 1)) and
 (var180 = 1 or not(var342 = 1)) and (var181 = 1 or not(var342 = 1)) and (var184
 = 1 or not(var342 = 1)) and (var186 = 1 or not(var342 = 1)) and (var188 = 1 or
not(var342 = 1)) and (var189 = 1 or not(var342 = 1)) and (var192 = 1 or not(
var342 = 1)) and (var1 = 1 or not(var343 = 1)) and (var3 = 1 or not(var343 = 1))
 and (var5 = 1 or not(var343 = 1)) and (var8 = 1 or not(var343 = 1)) and (var9 =
 1 or not(var343 = 1)) and (var11 = 1 or not(var343 = 1)) and (var14 = 1 or not(
var343 = 1)) and (var15 = 1 or not(var343 = 1)) and (var18 = 1 or not(var343 = 1
)) and (var20 = 1 or not(var343 = 1)) and (var21 = 1 or not(var343 = 1)) and (
var23 = 1 or not(var343 = 1)) and (var26 = 1 or not(var343 = 1)) and (var28 = 1
or not(var343 = 1)) and (var30 = 1 or not(var343 = 1)) and (var31 = 1 or not(
var343 = 1)) and (var33 = 1 or not(var343 = 1)) and (var36 = 1 or not(var343 = 1
)) and (var37 = 1 or not(var343 = 1)) and (var39 = 1 or not(var343 = 1)) and (
var41 = 1 or not(var343 = 1)) and (var44 = 1 or not(var343 = 1)) and (var46 = 1
or not(var343 = 1)) and (var47 = 1 or not(var343 = 1)) and (var50 = 1 or not(
var343 = 1)) and (var52 = 1 or not(var343 = 1)) and (var54 = 1 or not(var343 = 1
)) and (var55 = 1 or not(var343 = 1)) and (var57 = 1 or not(var343 = 1)) and (
var59 = 1 or not(var343 = 1)) and (var61 = 1 or not(var343 = 1)) and (var64 = 1
or not(var343 = 1)) and (var65 = 1 or not(var344 = 1)) and (var67 = 1 or not(
var344 = 1)) and (var69 = 1 or not(var344 = 1)) and (var72 = 1 or not(var344 = 1
)) and (var73 = 1 or not(var344 = 1)) and (var75 = 1 or not(var344 = 1)) and (
var78 = 1 or not(var344 = 1)) and (var79 = 1 or not(var344 = 1)) and (var82 = 1
or not(var344 = 1)) and (var84 = 1 or not(var344 = 1)) and (var85 = 1 or not(
var344 = 1)) and (var87 = 1 or not(var344 = 1)) and (var90 = 1 or not(var344 = 1
)) and (var92 = 1 or not(var344 = 1)) and (var94 = 1 or not(var344 = 1)) and (
var95 = 1 or not(var344 = 1)) and (var97 = 1 or not(var344 = 1)) and (var100 = 1
 or not(var344 = 1)) and (var101 = 1 or not(var344 = 1)) and (var103 = 1 or not(
var344 = 1)) and (var105 = 1 or not(var344 = 1)) and (var108 = 1 or not(var344 =
 1)) and (var110 = 1 or not(var344 = 1)) and (var111 = 1 or not(var344 = 1)) and
 (var114 = 1 or not(var344 = 1)) and (var116 = 1 or not(var344 = 1)) and (var118
 = 1 or not(var344 = 1)) and (var119 = 1 or not(var344 = 1)) and (var121 = 1 or
not(var344 = 1)) and (var123 = 1 or not(var344 = 1)) and (var125 = 1 or not(
var344 = 1)) and (var128 = 1 or not(var344 = 1)) and (var129 = 1 or not(var345 =
 1)) and (var131 = 1 or not(var345 = 1)) and (var133 = 1 or not(var345 = 1)) and
 (var136 = 1 or not(var345 = 1)) and (var137 = 1 or not(var345 = 1)) and (var139
 = 1 or not(var345 = 1)) and (var142 = 1 or not(var345 = 1)) and (var143 = 1 or
not(var345 = 1)) and (var146 = 1 or not(var345 = 1)) and (var148 = 1 or not(
var345 = 1)) and (var149 = 1 or not(var345 = 1)) and (var151 = 1 or not(var345 =
 1)) and (var154 = 1 or not(var345 = 1)) and (var156 = 1 or not(var345 = 1)) and
 (var158 = 1 or not(var345 = 1)) and (var159 = 1 or not(var345 = 1)) and (var161
 = 1 or not(var345 = 1)) and (var164 = 1 or not(var345 = 1)) and (var165 = 1 or
not(var345 = 1)) and (var167 = 1 or not(var345 = 1)) and (var169 = 1 or not(
var345 = 1)) and (var172 = 1 or not(var345 = 1)) and (var174 = 1 or not(var345 =
 1)) and (var175 = 1 or not(var345 = 1)) and (var178 = 1 or not(var345 = 1)) and
 (var180 = 1 or not(var345 = 1)) and (var182 = 1 or not(var345 = 1)) and (var183
 = 1 or not(var345 = 1)) and (var185 = 1 or not(var345 = 1)) and (var187 = 1 or
not(var345 = 1)) and (var189 = 1 or not(var345 = 1)) and (var192 = 1 or not(
var345 = 1)) and (var1 = 1 or not(var346 = 1)) and (var3 = 1 or not(var346 = 1))
 and (var5 = 1 or not(var346 = 1)) and (var8 = 1 or not(var346 = 1)) and (var9 =
 1 or not(var346 = 1)) and (var11 = 1 or not(var346 = 1)) and (var14 = 1 or not(
var346 = 1)) and (var15 = 1 or not(var346 = 1)) and (var18 = 1 or not(var346 = 1
)) and (var20 = 1 or not(var346 = 1)) and (var22 = 1 or not(var346 = 1)) and (
var24 = 1 or not(var346 = 1)) and (var25 = 1 or not(var346 = 1)) and (var28 = 1
or not(var346 = 1)) and (var29 = 1 or not(var346 = 1)) and (var32 = 1 or not(
var346 = 1)) and (var33 = 1 or not(var346 = 1)) and (var35 = 1 or not(var346 = 1
)) and (var37 = 1 or not(var346 = 1)) and (var39 = 1 or not(var346 = 1)) and (
var41 = 1 or not(var346 = 1)) and (var43 = 1 or not(var346 = 1)) and (var46 = 1
or not(var346 = 1)) and (var48 = 1 or not(var346 = 1)) and (var49 = 1 or not(
var346 = 1)) and (var52 = 1 or not(var346 = 1)) and (var53 = 1 or not(var346 = 1
)) and (var55 = 1 or not(var346 = 1)) and (var58 = 1 or not(var346 = 1)) and (
var60 = 1 or not(var346 = 1)) and (var62 = 1 or not(var346 = 1)) and (var64 = 1
or not(var346 = 1)) and (var65 = 1 or not(var347 = 1)) and (var67 = 1 or not(
var347 = 1)) and (var69 = 1 or not(var347 = 1)) and (var72 = 1 or not(var347 = 1
)) and (var73 = 1 or not(var347 = 1)) and (var75 = 1 or not(var347 = 1)) and (
var78 = 1 or not(var347 = 1)) and (var79 = 1 or not(var347 = 1)) and (var82 = 1
or not(var347 = 1)) and (var84 = 1 or not(var347 = 1)) and (var86 = 1 or not(
var347 = 1)) and (var88 = 1 or not(var347 = 1)) and (var89 = 1 or not(var347 = 1
)) and (var92 = 1 or not(var347 = 1)) and (var93 = 1 or not(var347 = 1)) and (
var96 = 1 or not(var347 = 1)) and (var97 = 1 or not(var347 = 1)) and (var99 = 1
or not(var347 = 1)) and (var101 = 1 or not(var347 = 1)) and (var103 = 1 or not(
var347 = 1)) and (var105 = 1 or not(var347 = 1)) and (var107 = 1 or not(var347 =
 1)) and (var110 = 1 or not(var347 = 1)) and (var112 = 1 or not(var347 = 1)) and
 (var113 = 1 or not(var347 = 1)) and (var116 = 1 or not(var347 = 1)) and (var117
 = 1 or not(var347 = 1)) and (var119 = 1 or not(var347 = 1)) and (var122 = 1 or
not(var347 = 1)) and (var124 = 1 or not(var347 = 1)) and (var126 = 1 or not(
var347 = 1)) and (var128 = 1 or not(var347 = 1)) and (var129 = 1 or not(var348 =
 1)) and (var131 = 1 or not(var348 = 1)) and (var133 = 1 or not(var348 = 1)) and
 (var136 = 1 or not(var348 = 1)) and (var137 = 1 or not(var348 = 1)) and (var139
 = 1 or not(var348 = 1)) and (var142 = 1 or not(var348 = 1)) and (var143 = 1 or
not(var348 = 1)) and (var146 = 1 or not(var348 = 1)) and (var148 = 1 or not(
var348 = 1)) and (var150 = 1 or not(var348 = 1)) and (var152 = 1 or not(var348 =
 1)) and (var153 = 1 or not(var348 = 1)) and (var156 = 1 or not(var348 = 1)) and
 (var157 = 1 or not(var348 = 1)) and (var160 = 1 or not(var348 = 1)) and (var161
 = 1 or not(var348 = 1)) and (var163 = 1 or not(var348 = 1)) and (var165 = 1 or
not(var348 = 1)) and (var167 = 1 or not(var348 = 1)) and (var169 = 1 or not(
var348 = 1)) and (var171 = 1 or not(var348 = 1)) and (var174 = 1 or not(var348 =
 1)) and (var176 = 1 or not(var348 = 1)) and (var177 = 1 or not(var348 = 1)) and
 (var180 = 1 or not(var348 = 1)) and (var181 = 1 or not(var348 = 1)) and (var183
 = 1 or not(var348 = 1)) and (var186 = 1 or not(var348 = 1)) and (var188 = 1 or
not(var348 = 1)) and (var190 = 1 or not(var348 = 1)) and (var192 = 1 or not(
var348 = 1)) and (var2 = 1 or not(var349 = 1)) and (var4 = 1 or not(var349 = 1))
 and (var5 = 1 or not(var349 = 1)) and (var7 = 1 or not(var349 = 1)) and (var9 =
 1 or not(var349 = 1)) and (var11 = 1 or not(var349 = 1)) and (var13 = 1 or not(
var349 = 1)) and (var16 = 1 or not(var349 = 1)) and (var18 = 1 or not(var349 = 1
)) and (var20 = 1 or not(var349 = 1)) and (var22 = 1 or not(var349 = 1)) and (
var24 = 1 or not(var349 = 1)) and (var25 = 1 or not(var349 = 1)) and (var28 = 1
or not(var349 = 1)) and (var30 = 1 or not(var349 = 1)) and (var32 = 1 or not(
var349 = 1)) and (var34 = 1 or not(var349 = 1)) and (var36 = 1 or not(var349 = 1
)) and (var37 = 1 or not(var349 = 1)) and (var40 = 1 or not(var349 = 1)) and (
var41 = 1 or not(var349 = 1)) and (var44 = 1 or not(var349 = 1)) and (var46 = 1
or not(var349 = 1)) and (var47 = 1 or not(var349 = 1)) and (var49 = 1 or not(
var349 = 1)) and (var52 = 1 or not(var349 = 1)) and (var54 = 1 or not(var349 = 1
)) and (var55 = 1 or not(var349 = 1)) and (var58 = 1 or not(var349 = 1)) and (
var59 = 1 or not(var349 = 1)) and (var61 = 1 or not(var349 = 1)) and (var63 = 1
or not(var349 = 1)) and (var66 = 1 or not(var350 = 1)) and (var68 = 1 or not(
var350 = 1)) and (var69 = 1 or not(var350 = 1)) and (var71 = 1 or not(var350 = 1
)) and (var73 = 1 or not(var350 = 1)) and (var75 = 1 or not(var350 = 1)) and (
var77 = 1 or not(var350 = 1)) and (var80 = 1 or not(var350 = 1)) and (var82 = 1
or not(var350 = 1)) and (var84 = 1 or not(var350 = 1)) and (var86 = 1 or not(
var350 = 1)) and (var88 = 1 or not(var350 = 1)) and (var89 = 1 or not(var350 = 1
)) and (var92 = 1 or not(var350 = 1)) and (var94 = 1 or not(var350 = 1)) and (
var96 = 1 or not(var350 = 1)) and (var98 = 1 or not(var350 = 1)) and (var100 = 1
 or not(var350 = 1)) and (var101 = 1 or not(var350 = 1)) and (var104 = 1 or not(
var350 = 1)) and (var105 = 1 or not(var350 = 1)) and (var108 = 1 or not(var350 =
 1)) and (var110 = 1 or not(var350 = 1)) and (var111 = 1 or not(var350 = 1)) and
 (var113 = 1 or not(var350 = 1)) and (var116 = 1 or not(var350 = 1)) and (var118
 = 1 or not(var350 = 1)) and (var119 = 1 or not(var350 = 1)) and (var122 = 1 or
not(var350 = 1)) and (var123 = 1 or not(var350 = 1)) and (var125 = 1 or not(
var350 = 1)) and (var127 = 1 or not(var350 = 1)) and (var130 = 1 or not(var351 =
 1)) and (var132 = 1 or not(var351 = 1)) and (var133 = 1 or not(var351 = 1)) and
 (var135 = 1 or not(var351 = 1)) and (var137 = 1 or not(var351 = 1)) and (var139
 = 1 or not(var351 = 1)) and (var141 = 1 or not(var351 = 1)) and (var144 = 1 or
not(var351 = 1)) and (var146 = 1 or not(var351 = 1)) and (var148 = 1 or not(
var351 = 1)) and (var150 = 1 or not(var351 = 1)) and (var152 = 1 or not(var351 =
 1)) and (var153 = 1 or not(var351 = 1)) and (var156 = 1 or not(var351 = 1)) and
 (var158 = 1 or not(var351 = 1)) and (var160 = 1 or not(var351 = 1)) and (var162
 = 1 or not(var351 = 1)) and (var164 = 1 or not(var351 = 1)) and (var165 = 1 or
not(var351 = 1)) and (var168 = 1 or not(var351 = 1)) and (var169 = 1 or not(
var351 = 1)) and (var172 = 1 or not(var351 = 1)) and (var174 = 1 or not(var351 =
 1)) and (var175 = 1 or not(var351 = 1)) and (var177 = 1 or not(var351 = 1)) and
 (var180 = 1 or not(var351 = 1)) and (var182 = 1 or not(var351 = 1)) and (var183
 = 1 or not(var351 = 1)) and (var186 = 1 or not(var351 = 1)) and (var187 = 1 or
not(var351 = 1)) and (var189 = 1 or not(var351 = 1)) and (var191 = 1 or not(
var351 = 1)) and (var1 = 1 or not(var352 = 1)) and (var4 = 1 or not(var352 = 1))
 and (var5 = 1 or not(var352 = 1)) and (var7 = 1 or not(var352 = 1)) and (var9 =
 1 or not(var352 = 1)) and (var11 = 1 or not(var352 = 1)) and (var13 = 1 or not(
var352 = 1)) and (var16 = 1 or not(var352 = 1)) and (var18 = 1 or not(var352 = 1
)) and (var19 = 1 or not(var352 = 1)) and (var21 = 1 or not(var352 = 1)) and (
var23 = 1 or not(var352 = 1)) and (var25 = 1 or not(var352 = 1)) and (var27 = 1
or not(var352 = 1)) and (var29 = 1 or not(var352 = 1)) and (var32 = 1 or not(
var352 = 1)) and (var33 = 1 or not(var352 = 1)) and (var36 = 1 or not(var352 = 1
)) and (var38 = 1 or not(var352 = 1)) and (var39 = 1 or not(var352 = 1)) and (
var42 = 1 or not(var352 = 1)) and (var44 = 1 or not(var352 = 1)) and (var45 = 1
or not(var352 = 1)) and (var47 = 1 or not(var352 = 1)) and (var50 = 1 or not(
var352 = 1)) and (var52 = 1 or not(var352 = 1)) and (var53 = 1 or not(var352 = 1
)) and (var55 = 1 or not(var352 = 1)) and (var58 = 1 or not(var352 = 1)) and (
var60 = 1 or not(var352 = 1)) and (var61 = 1 or not(var352 = 1)) and (var64 = 1
or not(var352 = 1)) and (var65 = 1 or not(var353 = 1)) and (var68 = 1 or not(
var353 = 1)) and (var69 = 1 or not(var353 = 1)) and (var71 = 1 or not(var353 = 1
)) and (var73 = 1 or not(var353 = 1)) and (var75 = 1 or not(var353 = 1)) and (
var77 = 1 or not(var353 = 1)) and (var80 = 1 or not(var353 = 1)) and (var82 = 1
or not(var353 = 1)) and (var83 = 1 or not(var353 = 1)) and (var85 = 1 or not(
var353 = 1)) and (var87 = 1 or not(var353 = 1)) and (var89 = 1 or not(var353 = 1
)) and (var91 = 1 or not(var353 = 1)) and (var93 = 1 or not(var353 = 1)) and (
var96 = 1 or not(var353 = 1)) and (var97 = 1 or not(var353 = 1)) and (var100 = 1
 or not(var353 = 1)) and (var102 = 1 or not(var353 = 1)) and (var103 = 1 or not(
var353 = 1)) and (var106 = 1 or not(var353 = 1)) and (var108 = 1 or not(var353 =
 1)) and (var109 = 1 or not(var353 = 1)) and (var111 = 1 or not(var353 = 1)) and
 (var114 = 1 or not(var353 = 1)) and (var116 = 1 or not(var353 = 1)) and (var117
 = 1 or not(var353 = 1)) and (var119 = 1 or not(var353 = 1)) and (var122 = 1 or
not(var353 = 1)) and (var124 = 1 or not(var353 = 1)) and (var125 = 1 or not(
var353 = 1)) and (var128 = 1 or not(var353 = 1)) and (var129 = 1 or not(var354 =
 1)) and (var132 = 1 or not(var354 = 1)) and (var133 = 1 or not(var354 = 1)) and
 (var135 = 1 or not(var354 = 1)) and (var137 = 1 or not(var354 = 1)) and (var139
 = 1 or not(var354 = 1)) and (var141 = 1 or not(var354 = 1)) and (var144 = 1 or
not(var354 = 1)) and (var146 = 1 or not(var354 = 1)) and (var147 = 1 or not(
var354 = 1)) and (var149 = 1 or not(var354 = 1)) and (var151 = 1 or not(var354 =
 1)) and (var153 = 1 or not(var354 = 1)) and (var155 = 1 or not(var354 = 1)) and
 (var157 = 1 or not(var354 = 1)) and (var160 = 1 or not(var354 = 1)) and (var161
 = 1 or not(var354 = 1)) and (var164 = 1 or not(var354 = 1)) and (var166 = 1 or
not(var354 = 1)) and (var167 = 1 or not(var354 = 1)) and (var170 = 1 or not(
var354 = 1)) and (var172 = 1 or not(var354 = 1)) and (var173 = 1 or not(var354 =
 1)) and (var175 = 1 or not(var354 = 1)) and (var178 = 1 or not(var354 = 1)) and
 (var180 = 1 or not(var354 = 1)) and (var181 = 1 or not(var354 = 1)) and (var183
 = 1 or not(var354 = 1)) and (var186 = 1 or not(var354 = 1)) and (var188 = 1 or
not(var354 = 1)) and (var189 = 1 or not(var354 = 1)) and (var192 = 1 or not(
var354 = 1)) and (var1 = 1 or not(var355 = 1)) and (var4 = 1 or not(var355 = 1))
 and (var5 = 1 or not(var355 = 1)) and (var8 = 1 or not(var355 = 1)) and (var10
= 1 or not(var355 = 1)) and (var11 = 1 or not(var355 = 1)) and (var13 = 1 or not
(var355 = 1)) and (var15 = 1 or not(var355 = 1)) and (var18 = 1 or not(var355 =
1)) and (var20 = 1 or not(var355 = 1)) and (var21 = 1 or not(var355 = 1)) and (
var24 = 1 or not(var355 = 1)) and (var25 = 1 or not(var355 = 1)) and (var27 = 1
or not(var355 = 1)) and (var30 = 1 or not(var355 = 1)) and (var31 = 1 or not(
var355 = 1)) and (var33 = 1 or not(var355 = 1)) and (var36 = 1 or not(var355 = 1
)) and (var38 = 1 or not(var355 = 1)) and (var39 = 1 or not(var355 = 1)) and (
var42 = 1 or not(var355 = 1)) and (var44 = 1 or not(var355 = 1)) and (var46 = 1
or not(var355 = 1)) and (var47 = 1 or not(var355 = 1)) and (var50 = 1 or not(
var355 = 1)) and (var52 = 1 or not(var355 = 1)) and (var53 = 1 or not(var355 = 1
)) and (var55 = 1 or not(var355 = 1)) and (var57 = 1 or not(var355 = 1)) and (
var59 = 1 or not(var355 = 1)) and (var62 = 1 or not(var355 = 1)) and (var63 = 1
or not(var355 = 1)) and (var65 = 1 or not(var356 = 1)) and (var68 = 1 or not(
var356 = 1)) and (var69 = 1 or not(var356 = 1)) and (var72 = 1 or not(var356 = 1
)) and (var74 = 1 or not(var356 = 1)) and (var75 = 1 or not(var356 = 1)) and (
var77 = 1 or not(var356 = 1)) and (var79 = 1 or not(var356 = 1)) and (var82 = 1
or not(var356 = 1)) and (var84 = 1 or not(var356 = 1)) and (var85 = 1 or not(
var356 = 1)) and (var88 = 1 or not(var356 = 1)) and (var89 = 1 or not(var356 = 1
)) and (var91 = 1 or not(var356 = 1)) and (var94 = 1 or not(var356 = 1)) and (
var95 = 1 or not(var356 = 1)) and (var97 = 1 or not(var356 = 1)) and (var100 = 1
 or not(var356 = 1)) and (var102 = 1 or not(var356 = 1)) and (var103 = 1 or not(
var356 = 1)) and (var106 = 1 or not(var356 = 1)) and (var108 = 1 or not(var356 =
 1)) and (var110 = 1 or not(var356 = 1)) and (var111 = 1 or not(var356 = 1)) and
 (var114 = 1 or not(var356 = 1)) and (var116 = 1 or not(var356 = 1)) and (var117
 = 1 or not(var356 = 1)) and (var119 = 1 or not(var356 = 1)) and (var121 = 1 or
not(var356 = 1)) and (var123 = 1 or not(var356 = 1)) and (var126 = 1 or not(
var356 = 1)) and (var127 = 1 or not(var356 = 1)) and (var129 = 1 or not(var357 =
 1)) and (var132 = 1 or not(var357 = 1)) and (var133 = 1 or not(var357 = 1)) and
 (var136 = 1 or not(var357 = 1)) and (var138 = 1 or not(var357 = 1)) and (var139
 = 1 or not(var357 = 1)) and (var141 = 1 or not(var357 = 1)) and (var143 = 1 or
not(var357 = 1)) and (var146 = 1 or not(var357 = 1)) and (var148 = 1 or not(
var357 = 1)) and (var149 = 1 or not(var357 = 1)) and (var152 = 1 or not(var357 =
 1)) and (var153 = 1 or not(var357 = 1)) and (var155 = 1 or not(var357 = 1)) and
 (var158 = 1 or not(var357 = 1)) and (var159 = 1 or not(var357 = 1)) and (var161
 = 1 or not(var357 = 1)) and (var164 = 1 or not(var357 = 1)) and (var166 = 1 or
not(var357 = 1)) and (var167 = 1 or not(var357 = 1)) and (var170 = 1 or not(
var357 = 1)) and (var172 = 1 or not(var357 = 1)) and (var174 = 1 or not(var357 =
 1)) and (var175 = 1 or not(var357 = 1)) and (var178 = 1 or not(var357 = 1)) and
 (var180 = 1 or not(var357 = 1)) and (var181 = 1 or not(var357 = 1)) and (var183
 = 1 or not(var357 = 1)) and (var185 = 1 or not(var357 = 1)) and (var187 = 1 or
not(var357 = 1)) and (var190 = 1 or not(var357 = 1)) and (var191 = 1 or not(
var357 = 1)) and (var1 = 1 or not(var358 = 1)) and (var4 = 1 or not(var358 = 1))
 and (var5 = 1 or not(var358 = 1)) and (var8 = 1 or not(var358 = 1)) and (var10
= 1 or not(var358 = 1)) and (var12 = 1 or not(var358 = 1)) and (var14 = 1 or not
(var358 = 1)) and (var16 = 1 or not(var358 = 1)) and (var17 = 1 or not(var358 =
1)) and (var19 = 1 or not(var358 = 1)) and (var22 = 1 or not(var358 = 1)) and (
var24 = 1 or not(var358 = 1)) and (var26 = 1 or not(var358 = 1)) and (var28 = 1
or not(var358 = 1)) and (var30 = 1 or not(var358 = 1)) and (var31 = 1 or not(
var358 = 1)) and (var34 = 1 or not(var358 = 1)) and (var35 = 1 or not(var358 = 1
)) and (var38 = 1 or not(var358 = 1)) and (var40 = 1 or not(var358 = 1)) and (
var42 = 1 or not(var358 = 1)) and (var43 = 1 or not(var358 = 1)) and (var45 = 1
or not(var358 = 1)) and (var48 = 1 or not(var358 = 1)) and (var50 = 1 or not(
var358 = 1)) and (var52 = 1 or not(var358 = 1)) and (var54 = 1 or not(var358 = 1
)) and (var55 = 1 or not(var358 = 1)) and (var58 = 1 or not(var358 = 1)) and (
var59 = 1 or not(var358 = 1)) and (var61 = 1 or not(var358 = 1)) and (var63 = 1
or not(var358 = 1)) and (var65 = 1 or not(var359 = 1)) and (var68 = 1 or not(
var359 = 1)) and (var69 = 1 or not(var359 = 1)) and (var72 = 1 or not(var359 = 1
)) and (var74 = 1 or not(var359 = 1)) and (var76 = 1 or not(var359 = 1)) and (
var78 = 1 or not(var359 = 1)) and (var80 = 1 or not(var359 = 1)) and (var81 = 1
or not(var359 = 1)) and (var83 = 1 or not(var359 = 1)) and (var86 = 1 or not(
var359 = 1)) and (var88 = 1 or not(var359 = 1)) and (var90 = 1 or not(var359 = 1
)) and (var92 = 1 or not(var359 = 1)) and (var94 = 1 or not(var359 = 1)) and (
var95 = 1 or not(var359 = 1)) and (var98 = 1 or not(var359 = 1)) and (var99 = 1
or not(var359 = 1)) and (var102 = 1 or not(var359 = 1)) and (var104 = 1 or not(
var359 = 1)) and (var106 = 1 or not(var359 = 1)) and (var107 = 1 or not(var359 =
 1)) and (var109 = 1 or not(var359 = 1)) and (var112 = 1 or not(var359 = 1)) and
 (var114 = 1 or not(var359 = 1)) and (var116 = 1 or not(var359 = 1)) and (var118
 = 1 or not(var359 = 1)) and (var119 = 1 or not(var359 = 1)) and (var122 = 1 or
not(var359 = 1)) and (var123 = 1 or not(var359 = 1)) and (var125 = 1 or not(
var359 = 1)) and (var127 = 1 or not(var359 = 1)) and (var129 = 1 or not(var360 =
 1)) and (var132 = 1 or not(var360 = 1)) and (var133 = 1 or not(var360 = 1)) and
 (var136 = 1 or not(var360 = 1)) and (var138 = 1 or not(var360 = 1)) and (var140
 = 1 or not(var360 = 1)) and (var142 = 1 or not(var360 = 1)) and (var144 = 1 or
not(var360 = 1)) and (var145 = 1 or not(var360 = 1)) and (var147 = 1 or not(
var360 = 1)) and (var150 = 1 or not(var360 = 1)) and (var152 = 1 or not(var360 =
 1)) and (var154 = 1 or not(var360 = 1)) and (var156 = 1 or not(var360 = 1)) and
 (var158 = 1 or not(var360 = 1)) and (var159 = 1 or not(var360 = 1)) and (var162
 = 1 or not(var360 = 1)) and (var163 = 1 or not(var360 = 1)) and (var166 = 1 or
not(var360 = 1)) and (var168 = 1 or not(var360 = 1)) and (var170 = 1 or not(
var360 = 1)) and (var171 = 1 or not(var360 = 1)) and (var173 = 1 or not(var360 =
 1)) and (var176 = 1 or not(var360 = 1)) and (var178 = 1 or not(var360 = 1)) and
 (var180 = 1 or not(var360 = 1)) and (var182 = 1 or not(var360 = 1)) and (var183
 = 1 or not(var360 = 1)) and (var186 = 1 or not(var360 = 1)) and (var187 = 1 or
not(var360 = 1)) and (var189 = 1 or not(var360 = 1)) and (var191 = 1 or not(
var360 = 1)) and (var1 = 1 or not(var361 = 1)) and (var4 = 1 or not(var361 = 1))
 and (var6 = 1 or not(var361 = 1)) and (var8 = 1 or not(var361 = 1)) and (var10
= 1 or not(var361 = 1)) and (var11 = 1 or not(var361 = 1)) and (var14 = 1 or not
(var361 = 1)) and (var15 = 1 or not(var361 = 1)) and (var18 = 1 or not(var361 =
1)) and (var19 = 1 or not(var361 = 1)) and (var21 = 1 or not(var361 = 1)) and (
var24 = 1 or not(var361 = 1)) and (var26 = 1 or not(var361 = 1)) and (var27 = 1
or not(var361 = 1)) and (var30 = 1 or not(var361 = 1)) and (var31 = 1 or not(
var361 = 1)) and (var34 = 1 or not(var361 = 1)) and (var36 = 1 or not(var361 = 1
)) and (var38 = 1 or not(var361 = 1)) and (var39 = 1 or not(var361 = 1)) and (
var41 = 1 or not(var361 = 1)) and (var44 = 1 or not(var361 = 1)) and (var45 = 1
or not(var361 = 1)) and (var47 = 1 or not(var361 = 1)) and (var49 = 1 or not(
var361 = 1)) and (var51 = 1 or not(var361 = 1)) and (var54 = 1 or not(var361 = 1
)) and (var55 = 1 or not(var361 = 1)) and (var58 = 1 or not(var361 = 1)) and (
var60 = 1 or not(var361 = 1)) and (var61 = 1 or not(var361 = 1)) and (var63 = 1
or not(var361 = 1)) and (var65 = 1 or not(var362 = 1)) and (var68 = 1 or not(
var362 = 1)) and (var70 = 1 or not(var362 = 1)) and (var72 = 1 or not(var362 = 1
)) and (var74 = 1 or not(var362 = 1)) and (var75 = 1 or not(var362 = 1)) and (
var78 = 1 or not(var362 = 1)) and (var79 = 1 or not(var362 = 1)) and (var82 = 1
or not(var362 = 1)) and (var83 = 1 or not(var362 = 1)) and (var85 = 1 or not(
var362 = 1)) and (var88 = 1 or not(var362 = 1)) and (var90 = 1 or not(var362 = 1
)) and (var91 = 1 or not(var362 = 1)) and (var94 = 1 or not(var362 = 1)) and (
var95 = 1 or not(var362 = 1)) and (var98 = 1 or not(var362 = 1)) and (var100 = 1
 or not(var362 = 1)) and (var102 = 1 or not(var362 = 1)) and (var103 = 1 or not(
var362 = 1)) and (var105 = 1 or not(var362 = 1)) and (var108 = 1 or not(var362 =
 1)) and (var109 = 1 or not(var362 = 1)) and (var111 = 1 or not(var362 = 1)) and
 (var113 = 1 or not(var362 = 1)) and (var115 = 1 or not(var362 = 1)) and (var118
 = 1 or not(var362 = 1)) and (var119 = 1 or not(var362 = 1)) and (var122 = 1 or
not(var362 = 1)) and (var124 = 1 or not(var362 = 1)) and (var125 = 1 or not(
var362 = 1)) and (var127 = 1 or not(var362 = 1)) and (var129 = 1 or not(var363 =
 1)) and (var132 = 1 or not(var363 = 1)) and (var134 = 1 or not(var363 = 1)) and
 (var136 = 1 or not(var363 = 1)) and (var138 = 1 or not(var363 = 1)) and (var139
 = 1 or not(var363 = 1)) and (var142 = 1 or not(var363 = 1)) and (var143 = 1 or
not(var363 = 1)) and (var146 = 1 or not(var363 = 1)) and (var147 = 1 or not(
var363 = 1)) and (var149 = 1 or not(var363 = 1)) and (var152 = 1 or not(var363 =
 1)) and (var154 = 1 or not(var363 = 1)) and (var155 = 1 or not(var363 = 1)) and
 (var158 = 1 or not(var363 = 1)) and (var159 = 1 or not(var363 = 1)) and (var162
 = 1 or not(var363 = 1)) and (var164 = 1 or not(var363 = 1)) and (var166 = 1 or
not(var363 = 1)) and (var167 = 1 or not(var363 = 1)) and (var169 = 1 or not(
var363 = 1)) and (var172 = 1 or not(var363 = 1)) and (var173 = 1 or not(var363 =
 1)) and (var175 = 1 or not(var363 = 1)) and (var177 = 1 or not(var363 = 1)) and
 (var179 = 1 or not(var363 = 1)) and (var182 = 1 or not(var363 = 1)) and (var183
 = 1 or not(var363 = 1)) and (var186 = 1 or not(var363 = 1)) and (var188 = 1 or
not(var363 = 1)) and (var189 = 1 or not(var363 = 1)) and (var191 = 1 or not(
var363 = 1)) and (var2 = 1 or not(var364 = 1)) and (var4 = 1 or not(var364 = 1))
 and (var6 = 1 or not(var364 = 1)) and (var8 = 1 or not(var364 = 1)) and (var9 =
 1 or not(var364 = 1)) and (var11 = 1 or not(var364 = 1)) and (var14 = 1 or not(
var364 = 1)) and (var16 = 1 or not(var364 = 1)) and (var18 = 1 or not(var364 = 1
)) and (var20 = 1 or not(var364 = 1)) and (var22 = 1 or not(var364 = 1)) and (
var24 = 1 or not(var364 = 1)) and (var26 = 1 or not(var364 = 1)) and (var27 = 1
or not(var364 = 1)) and (var29 = 1 or not(var364 = 1)) and (var31 = 1 or not(
var364 = 1)) and (var33 = 1 or not(var364 = 1)) and (var36 = 1 or not(var364 = 1
)) and (var37 = 1 or not(var364 = 1)) and (var39 = 1 or not(var364 = 1)) and (
var41 = 1 or not(var364 = 1)) and (var44 = 1 or not(var364 = 1)) and (var46 = 1
or not(var364 = 1)) and (var47 = 1 or not(var364 = 1)) and (var49 = 1 or not(
var364 = 1)) and (var52 = 1 or not(var364 = 1)) and (var54 = 1 or not(var364 = 1
)) and (var55 = 1 or not(var364 = 1)) and (var57 = 1 or not(var364 = 1)) and (
var60 = 1 or not(var364 = 1)) and (var61 = 1 or not(var364 = 1)) and (var64 = 1
or not(var364 = 1)) and (var66 = 1 or not(var365 = 1)) and (var68 = 1 or not(
var365 = 1)) and (var70 = 1 or not(var365 = 1)) and (var72 = 1 or not(var365 = 1
)) and (var73 = 1 or not(var365 = 1)) and (var75 = 1 or not(var365 = 1)) and (
var78 = 1 or not(var365 = 1)) and (var80 = 1 or not(var365 = 1)) and (var82 = 1
or not(var365 = 1)) and (var84 = 1 or not(var365 = 1)) and (var86 = 1 or not(
var365 = 1)) and (var88 = 1 or not(var365 = 1)) and (var90 = 1 or not(var365 = 1
)) and (var91 = 1 or not(var365 = 1)) and (var93 = 1 or not(var365 = 1)) and (
var95 = 1 or not(var365 = 1)) and (var97 = 1 or not(var365 = 1)) and (var100 = 1
 or not(var365 = 1)) and (var101 = 1 or not(var365 = 1)) and (var103 = 1 or not(
var365 = 1)) and (var105 = 1 or not(var365 = 1)) and (var108 = 1 or not(var365 =
 1)) and (var110 = 1 or not(var365 = 1)) and (var111 = 1 or not(var365 = 1)) and
 (var113 = 1 or not(var365 = 1)) and (var116 = 1 or not(var365 = 1)) and (var118
 = 1 or not(var365 = 1)) and (var119 = 1 or not(var365 = 1)) and (var121 = 1 or
not(var365 = 1)) and (var124 = 1 or not(var365 = 1)) and (var125 = 1 or not(
var365 = 1)) and (var128 = 1 or not(var365 = 1)) and (var130 = 1 or not(var366 =
 1)) and (var132 = 1 or not(var366 = 1)) and (var134 = 1 or not(var366 = 1)) and
 (var136 = 1 or not(var366 = 1)) and (var137 = 1 or not(var366 = 1)) and (var139
 = 1 or not(var366 = 1)) and (var142 = 1 or not(var366 = 1)) and (var144 = 1 or
not(var366 = 1)) and (var146 = 1 or not(var366 = 1)) and (var148 = 1 or not(
var366 = 1)) and (var150 = 1 or not(var366 = 1)) and (var152 = 1 or not(var366 =
 1)) and (var154 = 1 or not(var366 = 1)) and (var155 = 1 or not(var366 = 1)) and
 (var157 = 1 or not(var366 = 1)) and (var159 = 1 or not(var366 = 1)) and (var161
 = 1 or not(var366 = 1)) and (var164 = 1 or not(var366 = 1)) and (var165 = 1 or
not(var366 = 1)) and (var167 = 1 or not(var366 = 1)) and (var169 = 1 or not(
var366 = 1)) and (var172 = 1 or not(var366 = 1)) and (var174 = 1 or not(var366 =
 1)) and (var175 = 1 or not(var366 = 1)) and (var177 = 1 or not(var366 = 1)) and
 (var180 = 1 or not(var366 = 1)) and (var182 = 1 or not(var366 = 1)) and (var183
 = 1 or not(var366 = 1)) and (var185 = 1 or not(var366 = 1)) and (var188 = 1 or
not(var366 = 1)) and (var189 = 1 or not(var366 = 1)) and (var192 = 1 or not(
var366 = 1)) and (var2 = 1 or not(var367 = 1)) and (var4 = 1 or not(var367 = 1))
 and (var6 = 1 or not(var367 = 1)) and (var7 = 1 or not(var367 = 1)) and (var10
= 1 or not(var367 = 1)) and (var11 = 1 or not(var367 = 1)) and (var14 = 1 or not
(var367 = 1)) and (var16 = 1 or not(var367 = 1)) and (var18 = 1 or not(var367 =
1)) and (var20 = 1 or not(var367 = 1)) and (var21 = 1 or not(var367 = 1)) and (
var23 = 1 or not(var367 = 1)) and (var25 = 1 or not(var367 = 1)) and (var27 = 1
or not(var367 = 1)) and (var29 = 1 or not(var367 = 1)) and (var31 = 1 or not(
var367 = 1)) and (var33 = 1 or not(var367 = 1)) and (var35 = 1 or not(var367 = 1
)) and (var37 = 1 or not(var367 = 1)) and (var40 = 1 or not(var367 = 1)) and (
var41 = 1 or not(var367 = 1)) and (var43 = 1 or not(var367 = 1)) and (var46 = 1
or not(var367 = 1)) and (var48 = 1 or not(var367 = 1)) and (var50 = 1 or not(
var367 = 1)) and (var51 = 1 or not(var367 = 1)) and (var54 = 1 or not(var367 = 1
)) and (var55 = 1 or not(var367 = 1)) and (var57 = 1 or not(var367 = 1)) and (
var59 = 1 or not(var367 = 1)) and (var61 = 1 or not(var367 = 1)) and (var63 = 1
or not(var367 = 1)) and (var66 = 1 or not(var368 = 1)) and (var68 = 1 or not(
var368 = 1)) and (var70 = 1 or not(var368 = 1)) and (var71 = 1 or not(var368 = 1
)) and (var74 = 1 or not(var368 = 1)) and (var75 = 1 or not(var368 = 1)) and (
var78 = 1 or not(var368 = 1)) and (var80 = 1 or not(var368 = 1)) and (var82 = 1
or not(var368 = 1)) and (var84 = 1 or not(var368 = 1)) and (var85 = 1 or not(
var368 = 1)) and (var87 = 1 or not(var368 = 1)) and (var89 = 1 or not(var368 = 1
)) and (var91 = 1 or not(var368 = 1)) and (var93 = 1 or not(var368 = 1)) and (
var95 = 1 or not(var368 = 1)) and (var97 = 1 or not(var368 = 1)) and (var99 = 1
or not(var368 = 1)) and (var101 = 1 or not(var368 = 1)) and (var104 = 1 or not(
var368 = 1)) and (var105 = 1 or not(var368 = 1)) and (var107 = 1 or not(var368 =
 1)) and (var110 = 1 or not(var368 = 1)) and (var112 = 1 or not(var368 = 1)) and
 (var114 = 1 or not(var368 = 1)) and (var115 = 1 or not(var368 = 1)) and (var118
 = 1 or not(var368 = 1)) and (var119 = 1 or not(var368 = 1)) and (var121 = 1 or
not(var368 = 1)) and (var123 = 1 or not(var368 = 1)) and (var125 = 1 or not(
var368 = 1)) and (var127 = 1 or not(var368 = 1)) and (var130 = 1 or not(var369 =
 1)) and (var132 = 1 or not(var369 = 1)) and (var134 = 1 or not(var369 = 1)) and
 (var135 = 1 or not(var369 = 1)) and (var138 = 1 or not(var369 = 1)) and (var139
 = 1 or not(var369 = 1)) and (var142 = 1 or not(var369 = 1)) and (var144 = 1 or
not(var369 = 1)) and (var146 = 1 or not(var369 = 1)) and (var148 = 1 or not(
var369 = 1)) and (var149 = 1 or not(var369 = 1)) and (var151 = 1 or not(var369 =
 1)) and (var153 = 1 or not(var369 = 1)) and (var155 = 1 or not(var369 = 1)) and
 (var157 = 1 or not(var369 = 1)) and (var159 = 1 or not(var369 = 1)) and (var161
 = 1 or not(var369 = 1)) and (var163 = 1 or not(var369 = 1)) and (var165 = 1 or
not(var369 = 1)) and (var168 = 1 or not(var369 = 1)) and (var169 = 1 or not(
var369 = 1)) and (var171 = 1 or not(var369 = 1)) and (var174 = 1 or not(var369 =
 1)) and (var176 = 1 or not(var369 = 1)) and (var178 = 1 or not(var369 = 1)) and
 (var179 = 1 or not(var369 = 1)) and (var182 = 1 or not(var369 = 1)) and (var183
 = 1 or not(var369 = 1)) and (var185 = 1 or not(var369 = 1)) and (var187 = 1 or
not(var369 = 1)) and (var189 = 1 or not(var369 = 1)) and (var191 = 1 or not(
var369 = 1)) and (var2 = 1 or not(var370 = 1)) and (var4 = 1 or not(var370 = 1))
 and (var5 = 1 or not(var370 = 1)) and (var8 = 1 or not(var370 = 1)) and (var9 =
 1 or not(var370 = 1)) and (var12 = 1 or not(var370 = 1)) and (var14 = 1 or not(
var370 = 1)) and (var15 = 1 or not(var370 = 1)) and (var18 = 1 or not(var370 = 1
)) and (var19 = 1 or not(var370 = 1)) and (var21 = 1 or not(var370 = 1)) and (
var23 = 1 or not(var370 = 1)) and (var26 = 1 or not(var370 = 1)) and (var28 = 1
or not(var370 = 1)) and (var30 = 1 or not(var370 = 1)) and (var32 = 1 or not(
var370 = 1)) and (var34 = 1 or not(var370 = 1)) and (var36 = 1 or not(var370 = 1
)) and (var38 = 1 or not(var370 = 1)) and (var39 = 1 or not(var370 = 1)) and (
var41 = 1 or not(var370 = 1)) and (var44 = 1 or not(var370 = 1)) and (var46 = 1
or not(var370 = 1)) and (var48 = 1 or not(var370 = 1)) and (var50 = 1 or not(
var370 = 1)) and (var51 = 1 or not(var370 = 1)) and (var53 = 1 or not(var370 = 1
)) and (var55 = 1 or not(var370 = 1)) and (var58 = 1 or not(var370 = 1)) and (
var60 = 1 or not(var370 = 1)) and (var61 = 1 or not(var370 = 1)) and (var64 = 1
or not(var370 = 1)) and (var66 = 1 or not(var371 = 1)) and (var68 = 1 or not(
var371 = 1)) and (var69 = 1 or not(var371 = 1)) and (var72 = 1 or not(var371 = 1
)) and (var73 = 1 or not(var371 = 1)) and (var76 = 1 or not(var371 = 1)) and (
var78 = 1 or not(var371 = 1)) and (var79 = 1 or not(var371 = 1)) and (var82 = 1
or not(var371 = 1)) and (var83 = 1 or not(var371 = 1)) and (var85 = 1 or not(
var371 = 1)) and (var87 = 1 or not(var371 = 1)) and (var90 = 1 or not(var371 = 1
)) and (var92 = 1 or not(var371 = 1)) and (var94 = 1 or not(var371 = 1)) and (
var96 = 1 or not(var371 = 1)) and (var98 = 1 or not(var371 = 1)) and (var100 = 1
 or not(var371 = 1)) and (var102 = 1 or not(var371 = 1)) and (var103 = 1 or not(
var371 = 1)) and (var105 = 1 or not(var371 = 1)) and (var108 = 1 or not(var371 =
 1)) and (var110 = 1 or not(var371 = 1)) and (var112 = 1 or not(var371 = 1)) and
 (var114 = 1 or not(var371 = 1)) and (var115 = 1 or not(var371 = 1)) and (var117
 = 1 or not(var371 = 1)) and (var119 = 1 or not(var371 = 1)) and (var122 = 1 or
not(var371 = 1)) and (var124 = 1 or not(var371 = 1)) and (var125 = 1 or not(
var371 = 1)) and (var128 = 1 or not(var371 = 1)) and (var130 = 1 or not(var372 =
 1)) and (var132 = 1 or not(var372 = 1)) and (var133 = 1 or not(var372 = 1)) and
 (var136 = 1 or not(var372 = 1)) and (var137 = 1 or not(var372 = 1)) and (var140
 = 1 or not(var372 = 1)) and (var142 = 1 or not(var372 = 1)) and (var143 = 1 or
not(var372 = 1)) and (var146 = 1 or not(var372 = 1)) and (var147 = 1 or not(
var372 = 1)) and (var149 = 1 or not(var372 = 1)) and (var151 = 1 or not(var372 =
 1)) and (var154 = 1 or not(var372 = 1)) and (var156 = 1 or not(var372 = 1)) and
 (var158 = 1 or not(var372 = 1)) and (var160 = 1 or not(var372 = 1)) and (var162
 = 1 or not(var372 = 1)) and (var164 = 1 or not(var372 = 1)) and (var166 = 1 or
not(var372 = 1)) and (var167 = 1 or not(var372 = 1)) and (var169 = 1 or not(
var372 = 1)) and (var172 = 1 or not(var372 = 1)) and (var174 = 1 or not(var372 =
 1)) and (var176 = 1 or not(var372 = 1)) and (var178 = 1 or not(var372 = 1)) and
 (var179 = 1 or not(var372 = 1)) and (var181 = 1 or not(var372 = 1)) and (var183
 = 1 or not(var372 = 1)) and (var186 = 1 or not(var372 = 1)) and (var188 = 1 or
not(var372 = 1)) and (var189 = 1 or not(var372 = 1)) and (var192 = 1 or not(
var372 = 1)) and (var1 = 1 or not(var373 = 1)) and (var4 = 1 or not(var373 = 1))
 and (var5 = 1 or not(var373 = 1)) and (var7 = 1 or not(var373 = 1)) and (var10
= 1 or not(var373 = 1)) and (var11 = 1 or not(var373 = 1)) and (var14 = 1 or not
(var373 = 1)) and (var16 = 1 or not(var373 = 1)) and (var18 = 1 or not(var373 =
1)) and (var20 = 1 or not(var373 = 1)) and (var21 = 1 or not(var373 = 1)) and (
var24 = 1 or not(var373 = 1)) and (var25 = 1 or not(var373 = 1)) and (var28 = 1
or not(var373 = 1)) and (var29 = 1 or not(var373 = 1)) and (var32 = 1 or not(
var373 = 1)) and (var34 = 1 or not(var373 = 1)) and (var36 = 1 or not(var373 = 1
)) and (var38 = 1 or not(var373 = 1)) and (var40 = 1 or not(var373 = 1)) and (
var42 = 1 or not(var373 = 1)) and (var43 = 1 or not(var373 = 1)) and (var46 = 1
or not(var373 = 1)) and (var48 = 1 or not(var373 = 1)) and (var49 = 1 or not(
var373 = 1)) and (var51 = 1 or not(var373 = 1)) and (var54 = 1 or not(var373 = 1
)) and (var56 = 1 or not(var373 = 1)) and (var58 = 1 or not(var373 = 1)) and (
var60 = 1 or not(var373 = 1)) and (var61 = 1 or not(var373 = 1)) and (var63 = 1
or not(var373 = 1)) and (var65 = 1 or not(var374 = 1)) and (var68 = 1 or not(
var374 = 1)) and (var69 = 1 or not(var374 = 1)) and (var71 = 1 or not(var374 = 1
)) and (var74 = 1 or not(var374 = 1)) and (var75 = 1 or not(var374 = 1)) and (
var78 = 1 or not(var374 = 1)) and (var80 = 1 or not(var374 = 1)) and (var82 = 1
or not(var374 = 1)) and (var84 = 1 or not(var374 = 1)) and (var85 = 1 or not(
var374 = 1)) and (var88 = 1 or not(var374 = 1)) and (var89 = 1 or not(var374 = 1
)) and (var92 = 1 or not(var374 = 1)) and (var93 = 1 or not(var374 = 1)) and (
var96 = 1 or not(var374 = 1)) and (var98 = 1 or not(var374 = 1)) and (var100 = 1
 or not(var374 = 1)) and (var102 = 1 or not(var374 = 1)) and (var104 = 1 or not(
var374 = 1)) and (var106 = 1 or not(var374 = 1)) and (var107 = 1 or not(var374 =
 1)) and (var110 = 1 or not(var374 = 1)) and (var112 = 1 or not(var374 = 1)) and
 (var113 = 1 or not(var374 = 1)) and (var115 = 1 or not(var374 = 1)) and (var118
 = 1 or not(var374 = 1)) and (var120 = 1 or not(var374 = 1)) and (var122 = 1 or
not(var374 = 1)) and (var124 = 1 or not(var374 = 1)) and (var125 = 1 or not(
var374 = 1)) and (var127 = 1 or not(var374 = 1)) and (var129 = 1 or not(var375 =
 1)) and (var132 = 1 or not(var375 = 1)) and (var133 = 1 or not(var375 = 1)) and
 (var135 = 1 or not(var375 = 1)) and (var138 = 1 or not(var375 = 1)) and (var139
 = 1 or not(var375 = 1)) and (var142 = 1 or not(var375 = 1)) and (var144 = 1 or
not(var375 = 1)) and (var146 = 1 or not(var375 = 1)) and (var148 = 1 or not(
var375 = 1)) and (var149 = 1 or not(var375 = 1)) and (var152 = 1 or not(var375 =
 1)) and (var153 = 1 or not(var375 = 1)) and (var156 = 1 or not(var375 = 1)) and
 (var157 = 1 or not(var375 = 1)) and (var160 = 1 or not(var375 = 1)) and (var162
 = 1 or not(var375 = 1)) and (var164 = 1 or not(var375 = 1)) and (var166 = 1 or
not(var375 = 1)) and (var168 = 1 or not(var375 = 1)) and (var170 = 1 or not(
var375 = 1)) and (var171 = 1 or not(var375 = 1)) and (var174 = 1 or not(var375 =
 1)) and (var176 = 1 or not(var375 = 1)) and (var177 = 1 or not(var375 = 1)) and
 (var179 = 1 or not(var375 = 1)) and (var182 = 1 or not(var375 = 1)) and (var184
 = 1 or not(var375 = 1)) and (var186 = 1 or not(var375 = 1)) and (var188 = 1 or
not(var375 = 1)) and (var189 = 1 or not(var375 = 1)) and (var191 = 1 or not(
var375 = 1)) and (var2 = 1 or not(var376 = 1)) and (var3 = 1 or not(var376 = 1))
 and (var5 = 1 or not(var376 = 1)) and (var7 = 1 or not(var376 = 1)) and (var9 =
 1 or not(var376 = 1)) and (var12 = 1 or not(var376 = 1)) and (var13 = 1 or not(
var376 = 1)) and (var15 = 1 or not(var376 = 1)) and (var18 = 1 or not(var376 = 1
)) and (var20 = 1 or not(var376 = 1)) and (var21 = 1 or not(var376 = 1)) and (
var23 = 1 or not(var376 = 1)) and (var25 = 1 or not(var376 = 1)) and (var27 = 1
or not(var376 = 1)) and (var29 = 1 or not(var376 = 1)) and (var31 = 1 or not(
var376 = 1)) and (var33 = 1 or not(var376 = 1)) and (var36 = 1 or not(var376 = 1
)) and (var37 = 1 or not(var376 = 1)) and (var39 = 1 or not(var376 = 1)) and (
var42 = 1 or not(var376 = 1)) and (var44 = 1 or not(var376 = 1)) and (var46 = 1
or not(var376 = 1)) and (var48 = 1 or not(var376 = 1)) and (var50 = 1 or not(
var376 = 1)) and (var51 = 1 or not(var376 = 1)) and (var53 = 1 or not(var376 = 1
)) and (var55 = 1 or not(var376 = 1)) and (var58 = 1 or not(var376 = 1)) and (
var59 = 1 or not(var376 = 1)) and (var62 = 1 or not(var376 = 1)) and (var63 = 1
or not(var376 = 1)) and (var66 = 1 or not(var377 = 1)) and (var67 = 1 or not(
var377 = 1)) and (var69 = 1 or not(var377 = 1)) and (var71 = 1 or not(var377 = 1
)) and (var73 = 1 or not(var377 = 1)) and (var76 = 1 or not(var377 = 1)) and (
var77 = 1 or not(var377 = 1)) and (var79 = 1 or not(var377 = 1)) and (var82 = 1
or not(var377 = 1)) and (var84 = 1 or not(var377 = 1)) and (var85 = 1 or not(
var377 = 1)) and (var87 = 1 or not(var377 = 1)) and (var89 = 1 or not(var377 = 1
)) and (var91 = 1 or not(var377 = 1)) and (var93 = 1 or not(var377 = 1)) and (
var95 = 1 or not(var377 = 1)) and (var97 = 1 or not(var377 = 1)) and (var100 = 1
 or not(var377 = 1)) and (var101 = 1 or not(var377 = 1)) and (var103 = 1 or not(
var377 = 1)) and (var106 = 1 or not(var377 = 1)) and (var108 = 1 or not(var377 =
 1)) and (var110 = 1 or not(var377 = 1)) and (var112 = 1 or not(var377 = 1)) and
 (var114 = 1 or not(var377 = 1)) and (var115 = 1 or not(var377 = 1)) and (var117
 = 1 or not(var377 = 1)) and (var119 = 1 or not(var377 = 1)) and (var122 = 1 or
not(var377 = 1)) and (var123 = 1 or not(var377 = 1)) and (var126 = 1 or not(
var377 = 1)) and (var127 = 1 or not(var377 = 1)) and (var130 = 1 or not(var378 =
 1)) and (var131 = 1 or not(var378 = 1)) and (var133 = 1 or not(var378 = 1)) and
 (var135 = 1 or not(var378 = 1)) and (var137 = 1 or not(var378 = 1)) and (var140
 = 1 or not(var378 = 1)) and (var141 = 1 or not(var378 = 1)) and (var143 = 1 or
not(var378 = 1)) and (var146 = 1 or not(var378 = 1)) and (var148 = 1 or not(
var378 = 1)) and (var149 = 1 or not(var378 = 1)) and (var151 = 1 or not(var378 =
 1)) and (var153 = 1 or not(var378 = 1)) and (var155 = 1 or not(var378 = 1)) and
 (var157 = 1 or not(var378 = 1)) and (var159 = 1 or not(var378 = 1)) and (var161
 = 1 or not(var378 = 1)) and (var164 = 1 or not(var378 = 1)) and (var165 = 1 or
not(var378 = 1)) and (var167 = 1 or not(var378 = 1)) and (var170 = 1 or not(
var378 = 1)) and (var172 = 1 or not(var378 = 1)) and (var174 = 1 or not(var378 =
 1)) and (var176 = 1 or not(var378 = 1)) and (var178 = 1 or not(var378 = 1)) and
 (var179 = 1 or not(var378 = 1)) and (var181 = 1 or not(var378 = 1)) and (var183
 = 1 or not(var378 = 1)) and (var186 = 1 or not(var378 = 1)) and (var187 = 1 or
not(var378 = 1)) and (var190 = 1 or not(var378 = 1)) and (var191 = 1 or not(
var378 = 1)) and (var1 = 1 or not(var379 = 1)) and (var4 = 1 or not(var379 = 1))
 and (var6 = 1 or not(var379 = 1)) and (var7 = 1 or not(var379 = 1)) and (var10
= 1 or not(var379 = 1)) and (var12 = 1 or not(var379 = 1)) and (var13 = 1 or not
(var379 = 1)) and (var15 = 1 or not(var379 = 1)) and (var18 = 1 or not(var379 =
1)) and (var20 = 1 or not(var379 = 1)) and (var22 = 1 or not(var379 = 1)) and (
var24 = 1 or not(var379 = 1)) and (var25 = 1 or not(var379 = 1)) and (var27 = 1
or not(var379 = 1)) and (var30 = 1 or not(var379 = 1)) and (var31 = 1 or not(
var379 = 1)) and (var33 = 1 or not(var379 = 1)) and (var35 = 1 or not(var379 = 1
)) and (var38 = 1 or not(var379 = 1)) and (var39 = 1 or not(var379 = 1)) and (
var42 = 1 or not(var379 = 1)) and (var43 = 1 or not(var379 = 1)) and (var46 = 1
or not(var379 = 1)) and (var47 = 1 or not(var379 = 1)) and (var50 = 1 or not(
var379 = 1)) and (var52 = 1 or not(var379 = 1)) and (var54 = 1 or not(var379 = 1
)) and (var56 = 1 or not(var379 = 1)) and (var57 = 1 or not(var379 = 1)) and (
var60 = 1 or not(var379 = 1)) and (var61 = 1 or not(var379 = 1)) and (var64 = 1
or not(var379 = 1)) and (var65 = 1 or not(var380 = 1)) and (var68 = 1 or not(
var380 = 1)) and (var70 = 1 or not(var380 = 1)) and (var71 = 1 or not(var380 = 1
)) and (var74 = 1 or not(var380 = 1)) and (var76 = 1 or not(var380 = 1)) and (
var77 = 1 or not(var380 = 1)) and (var79 = 1 or not(var380 = 1)) and (var82 = 1
or not(var380 = 1)) and (var84 = 1 or not(var380 = 1)) and (var86 = 1 or not(
var380 = 1)) and (var88 = 1 or not(var380 = 1)) and (var89 = 1 or not(var380 = 1
)) and (var91 = 1 or not(var380 = 1)) and (var94 = 1 or not(var380 = 1)) and (
var95 = 1 or not(var380 = 1)) and (var97 = 1 or not(var380 = 1)) and (var99 = 1
or not(var380 = 1)) and (var102 = 1 or not(var380 = 1)) and (var103 = 1 or not(
var380 = 1)) and (var106 = 1 or not(var380 = 1)) and (var107 = 1 or not(var380 =
 1)) and (var110 = 1 or not(var380 = 1)) and (var111 = 1 or not(var380 = 1)) and
 (var114 = 1 or not(var380 = 1)) and (var116 = 1 or not(var380 = 1)) and (var118
 = 1 or not(var380 = 1)) and (var120 = 1 or not(var380 = 1)) and (var121 = 1 or
not(var380 = 1)) and (var124 = 1 or not(var380 = 1)) and (var125 = 1 or not(
var380 = 1)) and (var128 = 1 or not(var380 = 1)) and (var129 = 1 or not(var381 =
 1)) and (var132 = 1 or not(var381 = 1)) and (var134 = 1 or not(var381 = 1)) and
 (var135 = 1 or not(var381 = 1)) and (var138 = 1 or not(var381 = 1)) and (var140
 = 1 or not(var381 = 1)) and (var141 = 1 or not(var381 = 1)) and (var143 = 1 or
not(var381 = 1)) and (var146 = 1 or not(var381 = 1)) and (var148 = 1 or not(
var381 = 1)) and (var150 = 1 or not(var381 = 1)) and (var152 = 1 or not(var381 =
 1)) and (var153 = 1 or not(var381 = 1)) and (var155 = 1 or not(var381 = 1)) and
 (var158 = 1 or not(var381 = 1)) and (var159 = 1 or not(var381 = 1)) and (var161
 = 1 or not(var381 = 1)) and (var163 = 1 or not(var381 = 1)) and (var166 = 1 or
not(var381 = 1)) and (var167 = 1 or not(var381 = 1)) and (var170 = 1 or not(
var381 = 1)) and (var171 = 1 or not(var381 = 1)) and (var174 = 1 or not(var381 =
 1)) and (var175 = 1 or not(var381 = 1)) and (var178 = 1 or not(var381 = 1)) and
 (var180 = 1 or not(var381 = 1)) and (var182 = 1 or not(var381 = 1)) and (var184
 = 1 or not(var381 = 1)) and (var185 = 1 or not(var381 = 1)) and (var188 = 1 or
not(var381 = 1)) and (var189 = 1 or not(var381 = 1)) and (var192 = 1 or not(
var381 = 1)) and (var2 = 1 or not(var382 = 1)) and (var4 = 1 or not(var382 = 1))
 and (var6 = 1 or not(var382 = 1)) and (var7 = 1 or not(var382 = 1)) and (var10
= 1 or not(var382 = 1)) and (var12 = 1 or not(var382 = 1)) and (var13 = 1 or not
(var382 = 1)) and (var15 = 1 or not(var382 = 1)) and (var17 = 1 or not(var382 =
1)) and (var20 = 1 or not(var382 = 1)) and (var22 = 1 or not(var382 = 1)) and (
var24 = 1 or not(var382 = 1)) and (var25 = 1 or not(var382 = 1)) and (var28 = 1
or not(var382 = 1)) and (var30 = 1 or not(var382 = 1)) and (var31 = 1 or not(
var382 = 1)) and (var33 = 1 or not(var382 = 1)) and (var35 = 1 or not(var382 = 1
)) and (var37 = 1 or not(var382 = 1)) and (var39 = 1 or not(var382 = 1)) and (
var41 = 1 or not(var382 = 1)) and (var43 = 1 or not(var382 = 1)) and (var46 = 1
or not(var382 = 1)) and (var48 = 1 or not(var382 = 1)) and (var50 = 1 or not(
var382 = 1)) and (var51 = 1 or not(var382 = 1)) and (var54 = 1 or not(var382 = 1
)) and (var56 = 1 or not(var382 = 1)) and (var58 = 1 or not(var382 = 1)) and (
var59 = 1 or not(var382 = 1)) and (var61 = 1 or not(var382 = 1)) and (var64 = 1
or not(var382 = 1)) and (var66 = 1 or not(var383 = 1)) and (var68 = 1 or not(
var383 = 1)) and (var70 = 1 or not(var383 = 1)) and (var71 = 1 or not(var383 = 1
)) and (var74 = 1 or not(var383 = 1)) and (var76 = 1 or not(var383 = 1)) and (
var77 = 1 or not(var383 = 1)) and (var79 = 1 or not(var383 = 1)) and (var81 = 1
or not(var383 = 1)) and (var84 = 1 or not(var383 = 1)) and (var86 = 1 or not(
var383 = 1)) and (var88 = 1 or not(var383 = 1)) and (var89 = 1 or not(var383 = 1
)) and (var92 = 1 or not(var383 = 1)) and (var94 = 1 or not(var383 = 1)) and (
var95 = 1 or not(var383 = 1)) and (var97 = 1 or not(var383 = 1)) and (var99 = 1
or not(var383 = 1)) and (var101 = 1 or not(var383 = 1)) and (var103 = 1 or not(
var383 = 1)) and (var105 = 1 or not(var383 = 1)) and (var107 = 1 or not(var383 =
 1)) and (var110 = 1 or not(var383 = 1)) and (var112 = 1 or not(var383 = 1)) and
 (var114 = 1 or not(var383 = 1)) and (var115 = 1 or not(var383 = 1)) and (var118
 = 1 or not(var383 = 1)) and (var120 = 1 or not(var383 = 1)) and (var122 = 1 or
not(var383 = 1)) and (var123 = 1 or not(var383 = 1)) and (var125 = 1 or not(
var383 = 1)) and (var128 = 1 or not(var383 = 1)) and (var130 = 1 or not(var384 =
 1)) and (var132 = 1 or not(var384 = 1)) and (var134 = 1 or not(var384 = 1)) and
 (var135 = 1 or not(var384 = 1)) and (var138 = 1 or not(var384 = 1)) and (var140
 = 1 or not(var384 = 1)) and (var141 = 1 or not(var384 = 1)) and (var143 = 1 or
not(var384 = 1)) and (var145 = 1 or not(var384 = 1)) and (var148 = 1 or not(
var384 = 1)) and (var150 = 1 or not(var384 = 1)) and (var152 = 1 or not(var384 =
 1)) and (var153 = 1 or not(var384 = 1)) and (var156 = 1 or not(var384 = 1)) and
 (var158 = 1 or not(var384 = 1)) and (var159 = 1 or not(var384 = 1)) and (var161
 = 1 or not(var384 = 1)) and (var163 = 1 or not(var384 = 1)) and (var165 = 1 or
not(var384 = 1)) and (var167 = 1 or not(var384 = 1)) and (var169 = 1 or not(
var384 = 1)) and (var171 = 1 or not(var384 = 1)) and (var174 = 1 or not(var384 =
 1)) and (var176 = 1 or not(var384 = 1)) and (var178 = 1 or not(var384 = 1)) and
 (var179 = 1 or not(var384 = 1)) and (var182 = 1 or not(var384 = 1)) and (var184
 = 1 or not(var384 = 1)) and (var186 = 1 or not(var384 = 1)) and (var187 = 1 or
not(var384 = 1)) and (var189 = 1 or not(var384 = 1)) and (var192 = 1 or not(
var384 = 1)) and (var1 = 1 or not(var385 = 1)) and (var4 = 1 or not(var385 = 1))
 and (var6 = 1 or not(var385 = 1)) and (var8 = 1 or not(var385 = 1)) and (var9 =
 1 or not(var385 = 1)) and (var12 = 1 or not(var385 = 1)) and (var13 = 1 or not(
var385 = 1)) and (var15 = 1 or not(var385 = 1)) and (var18 = 1 or not(var385 = 1
)) and (var20 = 1 or not(var385 = 1)) and (var21 = 1 or not(var385 = 1)) and (
var24 = 1 or not(var385 = 1)) and (var25 = 1 or not(var385 = 1)) and (var27 = 1
or not(var385 = 1)) and (var30 = 1 or not(var385 = 1)) and (var32 = 1 or not(
var385 = 1)) and (var34 = 1 or not(var385 = 1)) and (var36 = 1 or not(var385 = 1
)) and (var38 = 1 or not(var385 = 1)) and (var40 = 1 or not(var385 = 1)) and (
var41 = 1 or not(var385 = 1)) and (var43 = 1 or not(var385 = 1)) and (var46 = 1
or not(var385 = 1)) and (var47 = 1 or not(var385 = 1)) and (var50 = 1 or not(
var385 = 1)) and (var51 = 1 or not(var385 = 1)) and (var53 = 1 or not(var385 = 1
)) and (var55 = 1 or not(var385 = 1)) and (var57 = 1 or not(var385 = 1)) and (
var59 = 1 or not(var385 = 1)) and (var62 = 1 or not(var385 = 1)) and (var64 = 1
or not(var385 = 1)) and (var65 = 1 or not(var386 = 1)) and (var68 = 1 or not(
var386 = 1)) and (var70 = 1 or not(var386 = 1)) and (var72 = 1 or not(var386 = 1
)) and (var73 = 1 or not(var386 = 1)) and (var76 = 1 or not(var386 = 1)) and (
var77 = 1 or not(var386 = 1)) and (var79 = 1 or not(var386 = 1)) and (var82 = 1
or not(var386 = 1)) and (var84 = 1 or not(var386 = 1)) and (var85 = 1 or not(
var386 = 1)) and (var88 = 1 or not(var386 = 1)) and (var89 = 1 or not(var386 = 1
)) and (var91 = 1 or not(var386 = 1)) and (var94 = 1 or not(var386 = 1)) and (
var96 = 1 or not(var386 = 1)) and (var98 = 1 or not(var386 = 1)) and (var100 = 1
 or not(var386 = 1)) and (var102 = 1 or not(var386 = 1)) and (var104 = 1 or not(
var386 = 1)) and (var105 = 1 or not(var386 = 1)) and (var107 = 1 or not(var386 =
 1)) and (var110 = 1 or not(var386 = 1)) and (var111 = 1 or not(var386 = 1)) and
 (var114 = 1 or not(var386 = 1)) and (var115 = 1 or not(var386 = 1)) and (var117
 = 1 or not(var386 = 1)) and (var119 = 1 or not(var386 = 1)) and (var121 = 1 or
not(var386 = 1)) and (var123 = 1 or not(var386 = 1)) and (var126 = 1 or not(
var386 = 1)) and (var128 = 1 or not(var386 = 1)) and (var129 = 1 or not(var387 =
 1)) and (var132 = 1 or not(var387 = 1)) and (var134 = 1 or not(var387 = 1)) and
 (var136 = 1 or not(var387 = 1)) and (var137 = 1 or not(var387 = 1)) and (var140
 = 1 or not(var387 = 1)) and (var141 = 1 or not(var387 = 1)) and (var143 = 1 or
not(var387 = 1)) and (var146 = 1 or not(var387 = 1)) and (var148 = 1 or not(
var387 = 1)) and (var149 = 1 or not(var387 = 1)) and (var152 = 1 or not(var387 =
 1)) and (var153 = 1 or not(var387 = 1)) and (var155 = 1 or not(var387 = 1)) and
 (var158 = 1 or not(var387 = 1)) and (var160 = 1 or not(var387 = 1)) and (var162
 = 1 or not(var387 = 1)) and (var164 = 1 or not(var387 = 1)) and (var166 = 1 or
not(var387 = 1)) and (var168 = 1 or not(var387 = 1)) and (var169 = 1 or not(
var387 = 1)) and (var171 = 1 or not(var387 = 1)) and (var174 = 1 or not(var387 =
 1)) and (var175 = 1 or not(var387 = 1)) and (var178 = 1 or not(var387 = 1)) and
 (var179 = 1 or not(var387 = 1)) and (var181 = 1 or not(var387 = 1)) and (var183
 = 1 or not(var387 = 1)) and (var185 = 1 or not(var387 = 1)) and (var187 = 1 or
not(var387 = 1)) and (var190 = 1 or not(var387 = 1)) and (var192 = 1 or not(
var387 = 1)) and (var193 = 1 or var194 = 1 or var195 = 1) and (var196 = 1 or
var197 = 1 or var198 = 1) and (var199 = 1 or var200 = 1 or var201 = 1) and (
var202 = 1 or var203 = 1 or var204 = 1) and (var205 = 1 or var206 = 1 or var207
= 1) and (var208 = 1 or var209 = 1 or var210 = 1) and (var211 = 1 or var212 = 1
or var213 = 1) and (var214 = 1 or var215 = 1 or var216 = 1) and (var217 = 1 or
var218 = 1 or var219 = 1) and (var220 = 1 or var221 = 1 or var222 = 1) and (
var223 = 1 or var224 = 1 or var225 = 1) and (var226 = 1 or var227 = 1 or var228
= 1) and (var229 = 1 or var230 = 1 or var231 = 1) and (var232 = 1 or var233 = 1
or var234 = 1) and (var235 = 1 or var236 = 1 or var237 = 1) and (var238 = 1 or
var239 = 1 or var240 = 1) and (var241 = 1 or var242 = 1 or var243 = 1) and (
var244 = 1 or var245 = 1 or var246 = 1) and (var247 = 1 or var248 = 1 or var249
= 1) and (var250 = 1 or var251 = 1 or var252 = 1) and (var253 = 1 or var254 = 1
or var255 = 1) and (var256 = 1 or var257 = 1 or var258 = 1) and (var259 = 1 or
var260 = 1 or var261 = 1) and (var262 = 1 or var263 = 1 or var264 = 1) and (
var265 = 1 or var266 = 1 or var267 = 1) and (var268 = 1 or var269 = 1 or var270
= 1) and (var271 = 1 or var272 = 1 or var273 = 1) and (var274 = 1 or var275 = 1
or var276 = 1) and (var277 = 1 or var278 = 1 or var279 = 1) and (var280 = 1 or
var281 = 1 or var282 = 1) and (var283 = 1 or var284 = 1 or var285 = 1) and (
var286 = 1 or var287 = 1 or var288 = 1) and (var289 = 1 or var290 = 1 or var291
= 1) and (var292 = 1 or var293 = 1 or var294 = 1) and (var295 = 1 or var296 = 1
or var297 = 1) and (var298 = 1 or var299 = 1 or var300 = 1) and (var301 = 1 or
var302 = 1 or var303 = 1) and (var304 = 1 or var305 = 1 or var306 = 1) and (
var307 = 1 or var308 = 1 or var309 = 1) and (var310 = 1 or var311 = 1 or var312
= 1) and (var313 = 1 or var314 = 1 or var315 = 1) and (var316 = 1 or var317 = 1
or var318 = 1) and (var319 = 1 or var320 = 1 or var321 = 1) and (var322 = 1 or
var323 = 1 or var324 = 1) and (var325 = 1 or var326 = 1 or var327 = 1) and (
var328 = 1 or var329 = 1 or var330 = 1) and (var331 = 1 or var332 = 1 or var333
= 1) and (var334 = 1 or var335 = 1 or var336 = 1) and (var337 = 1 or var338 = 1
or var339 = 1) and (var340 = 1 or var341 = 1 or var342 = 1) and (var343 = 1 or
var344 = 1 or var345 = 1) and (var346 = 1 or var347 = 1 or var348 = 1) and (
var349 = 1 or var350 = 1 or var351 = 1) and (var352 = 1 or var353 = 1 or var354
= 1) and (var355 = 1 or var356 = 1 or var357 = 1) and (var358 = 1 or var359 = 1
or var360 = 1) and (var361 = 1 or var362 = 1 or var363 = 1) and (var364 = 1 or
var365 = 1 or var366 = 1) and (var367 = 1 or var368 = 1 or var369 = 1) and (
var370 = 1 or var371 = 1 or var372 = 1) and (var373 = 1 or var374 = 1 or var375
= 1) and (var376 = 1 or var377 = 1 or var378 = 1) and (var379 = 1 or var380 = 1
or var381 = 1) and (var382 = 1 or var383 = 1 or var384 = 1) and (var385 = 1 or
var386 = 1 or var387 = 1)$

rlqsat ii32e4;

end;
