off smtabout, smtprompt;
smt();
(set-option :print-success false)      
(set-logic QF_NRA)

; 01-33, no cad

; 01.red
(reset-assertions)
(assert (not (<= (* v5 v6) 0)))
(assert (not (<= 2 v23)))
(assert (not (<= v5 0)))
(assert (not (= 0 v5)))
(assert (not (<= v19 0)))
(assert (not (<= v23 v19)))
(assert (not (<= v5 1)))
(check-sat)

; 02.red
(reset-assertions)
(assert (<= (* v5 (* v5 (+ (- 120000000000000000000) (* v5 (* (- 120000) v5))))) 0))
(assert (not (<= v16 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v16)))
(assert (<= v27 (* (/ 1 3) v16)))
(assert (<= (* (/ 1 4) v16) v27))
(assert (<= v5 120))
(assert (<= 100 v5))
(check-sat)

; 03.red
(reset-assertions)
(assert (<= (* v5 (+ (+ (* (- (/ 306432 125)) v6) (* (/ 12096 25) v12)) (* v5 (+ (+ (* (/ 536256 15625) v6) (* (- (/ 21168 3125)) v12)) (* v5 (+ (+ (* (- (/ 625632 1953125)) v6) (* (/ 24696 390625) v12)) (* v5 (+ (+ (* (/ 957999 488281250) v6) (* (- (/ 151263 390625000)) v12)) (* v5 (+ (+ (* (- (/ 957999 122070312500)) v6) (* (/ 151263 97656250000) v12)) (* v5 (+ (* (/ 2235331 122070312500000) v6) (* (- (/ 352947 97656250000000)) v12))))))))))))) (+ (* (- 87552) v6) (* 17280 v12))))
(assert (<= v5 0))
(assert (not (<= (* v5 (+ (+ (* (/ 306432 125) v6) (* (- (/ 12096 25)) v12)) (* v5 (+ (+ (* (- (/ 536256 15625)) v6) (* (/ 21168 3125) v12)) (* v5 (+ (+ (* (/ 625632 1953125) v6) (* (- (/ 24696 390625)) v12)) (* v5 (+ (+ (* (- (/ 957999 488281250)) v6) (* (/ 151263 390625000) v12)) (* v5 (+ (+ (* (/ 957999 122070312500) v6) (* (- (/ 151263 97656250000)) v12)) (* v5 (+ (* (- (/ 2235331 122070312500000)) v6) (* (/ 352947 97656250000000) v12))))))))))))) (+ (* 87552 v6) (* (- 17280) v12)))))
(assert (= (* v12 v12) (+ 1 (* v6 (* (- 1) v6)))))
(assert (<= v5 75))
(assert (<= 0 v5))
(check-sat)

; 04.red
(reset-assertions)
(assert (not (<= 0 v6)))
(assert (not (<= (* v16 (* (- 1) v6)) (- 1))))
(assert (not (<= (* v22 (+ (+ (/ 471 100) (* v6 (+ (- 3) (* (/ 157 100) v6)))) (* v16 (+ (+ (- 3) (* v6 (+ (- (/ 471 100)) (* v6 (+ 2 (* (- (/ 157 100)) v6)))))) (* v16 (* v6 (+ 3 (* v6 v6)))))))) (+ (+ 3 (* v6 (+ (- (/ 471 100)) (* v6 (+ 4 (* (- (/ 157 100)) v6)))))) (* v16 (+ (+ (- (/ 471 100)) (* v6 (+ 3 (* (- (/ 157 100)) v6)))) (* v16 (+ 3 (* v6 v6)))))))))
(assert (not (<= v22 0)))
(assert (not (<= v6 (- 1))))
(assert (not (<= 1 v16)))
(assert (not (<= v16 v6)))
(check-sat)

; 05.red
(reset-assertions)
(assert (<= (* v14 (+ 3 (* v5 (+ (* (- 3) v8) (* v5 (+ 1 (* v5 (* (- 1) v8)))))))) (+ (* (- 3) v8) (* v5 (+ (- 3) (* v5 (+ (* (- 1) v8) (* (- 1) v5))))))))
(assert (not (<= 0 v5)))
(assert (not (<= (* v14 (+ (- 1) (* v5 v8))) (+ v8 v5))))
(assert (not (<= v14 0)))
(assert (not (<= v8 (- 1))))
(assert (not (<= 1 v5)))
(assert (not (<= v5 v8)))
(check-sat)

; 06.red
(reset-assertions)
(assert (<= (* v5 (+ (- (/ 57 500)) (* (- (/ 361 1000000)) v5))) 12))
(assert (= (* v25 v25) (+ 1 (* v19 (* (- 1) v19)))))
(assert (<= v5 289))
(assert (<= 0 v5))
(assert (<= (* (- (/ 235 42)) v19) v25))
(check-sat)

; 07.red
(reset-assertions)
(assert (not (<= (* v19 (* v19 v5)) (* v5 (* v5 (* (- 1) v5))))))
(assert (not (<= (* v19 (+ (* v5 (* v5 (* (- (/ 157 100)) v5))) (* v19 (+ (* v5 (* v5 (+ 2 (* (- (/ 3 10)) v5)))) (* v19 (+ (* (- (/ 157 100)) v5) (* v19 (+ 1 (* (- (/ 3 10)) v5))))))))) (* v5 (* v5 (* v5 (* (- 1) v16)))))))
(assert (not (<= v5 (* (- 1) v16))))
(assert (not (<= v19 1)))
(assert (not (<= v5 v16)))
(check-sat)

; 08.red
(reset-assertions)
(assert (not (= (* v5 v5) 2)))
(assert (not (<= v10 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v10)))
(assert (<= 0 v21))
(assert (<= 0 v23))
(assert (<= 0 v5))
(assert (not (<= v26 0)))
(assert (not (<= 1 v26)))
(check-sat)

; 09.red
(reset-assertions)
(assert (<= (* v5 (+ (- (/ 8352 625)) (* v5 (+ (- (/ 15138 390625)) (* v5 (+ (- (/ 73167 976562500)) (* v5 (+ (- (/ 14852901 156250000000000)) (* v5 (+ (- (/ 61533447 781250000000000000)) (* (- (/ 594823321 15625000000000000000000)) v5))))))))))) 2304))
(assert (not (<= v5 0)))
(assert (= (* v45 v45) (+ 1 (* v47 (* (- 1) v47)))))
(assert (<= v5 75))
(assert (<= 0 v5))
(check-sat)

; 10.red
(reset-assertions)
(assert (<= v5 1))
(assert (<= v9 2))
(assert (not (<= (* v5 (* v9 (* v9 (+ (* v14 (* v14 (+ (- (/ 15 4)) (* (/ 1 4) v14)))) (* v9 (* v14 (* v14 (+ (/ 1 4) (* (/ 1 4) v14))))))))) (* v9 (+ (* v14 (+ (/ 11 4) (* (- (/ 5 4)) v14))) (* v9 (* v14 (+ (- (/ 5 4)) (* (- (/ 5 4)) v14)))))))))
(assert (not (<= v9 1)))
(assert (<= v5 2))
(assert (<= v14 2))
(assert (<= 1 v5))
(assert (<= 1 v9))
(assert (<= 1 v14))
(assert (not (<= v14 1)))
(assert (not (<= (* v5 (* v9 (+ (* v14 (+ (- (/ 7 2)) (* (/ 1 2) v14))) (* v9 (* v14 (+ (/ 1 2) (* (/ 1 2) v14))))))) (+ (+ (- (/ 1 4)) (* (- (/ 1 4)) v14)) (* v9 (+ (- (/ 1 4)) (* (- (/ 1 4)) v14)))))))
(check-sat)

; 11.red
(reset-assertions)
(assert (<= 0 v5))
(assert (<= 0 v9))
(assert (not (<= (* v18 (+ (+ 3 (* v5 v5)) (* v9 (* v5 (+ (- 3) (* v5 (* (- 1) v5))))))) (+ (* v5 (* v5 (* (- 1) v5))) (* v9 (+ (* v5 (* (- 3) v5)) (* v9 (* v5 (+ (- 3) (* v5 (* (- 1) v5)))))))))))
(assert (not (<= v18 0)))
(assert (not (<= v5 (- 1))))
(assert (not (<= 1 v9)))
(assert (not (<= v9 v5)))
(check-sat)

; 12.red
(reset-assertions)
(assert (not (<= (* v5 (* (- (/ 1 2)) v5)) (- 1))))
(assert (not (<= v13 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v13)))
(assert (not (<= v5 v24)))
(check-sat)

; 13.red
(reset-assertions)
(assert (not (<= (* v5 v6) 0)))
(assert (not (<= (+ (- (/ 1 2000)) (* (/ 1 2) v13)) v5)))
(assert (not (<= v13 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v13)))
(assert (not (<= v6 0)))
(assert (not (<= v5 v6)))
(check-sat)

; 14.red
(reset-assertions)
(assert (<= (+ (* (/ 127 860) v5) (* (/ 493 17200) v10)) v16))
(assert (not (<= (* v16 (+ (+ (* (/ 213 1000) v5) (* (/ 413 10000) v10)) (* (- (/ 18 25)) v16))) (+ (+ (- (/ 1 10)) (* v5 (* (/ 261 100) v5))) (* v10 (+ (* (/ 21 20) v5) (* (/ 141 100) v10)))))))
(assert (not (= 0 v10)))
(assert (not (<= v10 0)))
(assert (not (<= v5 0)))
(assert (not (= 0 v5)))
(assert (not (<= v16 0)))
(assert (not (= 0 v16)))
(check-sat)

; 15.red
(reset-assertions)
(assert (<= 0 v5))
(assert (<= v13 (* (/ 1770 689) v8)))
(assert (= (* v13 v13) (+ 1 (* v8 (* (- 1) v8)))))
(assert (<= v5 289))
(assert (not (<= (* (/ 1770 689) v8) v13)))
(check-sat)

; 16.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (* v5 (* v5 (* v5 (* (/ 1 3) v5)))))) 0)))
(assert (not (<= v5 0)))
(assert (not (<= v18 0)))
(assert (not (<= (/ 31415927 10000000) v24)))
(assert (not (<= v24 (/ 15707963 5000000))))
(assert (not (<= (+ (- (/ 1 10000000)) (* (/ 1 2) v24)) v18)))
(assert (= 3 (* v5 v5)))
(check-sat)

; 17.red
(reset-assertions)
(assert (not (<= v5 0)))
(assert (not (<= v9 0)))
(assert (not (<= (* v9 (+ (* v5 (* (/ 1 6) v5)) (* v9 (* v9 (+ (- (/ 1 6)) (* v9 (* (/ 1 120) v9))))))) 0)))
(assert (not (<= v29 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v29)))
(assert (<= v9 (* (/ 1 2) v29)))
(assert (<= 0 v5))
(assert (not (<= v9 v5)))
(check-sat)

; 18.red
(reset-assertions)
(assert (<= (* v5 (+ (+ (* (- (/ 14958 40625)) v7) (* (/ 560961211379 65000000000) v13)) (* v5 (+ (* (/ 690561 406250000) v7) (* (- (/ 155386255551983 3900000000000000)) v13))))) (+ (* (- (/ 1728 65)) v7) (* (/ 2025130727 3250000) v13))))
(assert (<= v5 0))
(assert (<= (* (/ 86400000 2025130727) v7) v13))
(assert (not (<= v13 (* (/ 86400000 2025130727) v7))))
(assert (= (* v13 v13) (+ 1 (* v7 (* (- 1) v7)))))
(assert (<= v5 75))
(assert (<= 0 v5))
(assert (not (<= (* v5 (+ (+ (+ (- (/ 23 13)) (* (/ 621 8125) v7)) (* (- (/ 46578006721 26000000000)) v13)) (* v5 (+ (+ (- (/ 529 312000)) (* (- (/ 4761 65000000)) v7)) (* (/ 1071294154583 624000000000000) v13))))) (+ (+ (/ 8000 13) (* (/ 1728 65) v7)) (* (- (/ 2025130727 3250000)) v13)))))
(check-sat)

; 20.red
(reset-assertions)
(assert (not (<= (* v7 (* v7 (* v7 (* (/ 1 24) v7)))) (+ (- 3) (* v5 v5)))))
(assert (= (* v5 v5) 3))
(assert (not (<= (+ (- (/ 1 10000000)) (* (/ 1 2) v24)) v7)))
(assert (not (<= v24 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v24)))
(assert (not (<= v7 0)))
(assert (not (<= v5 0)))
(check-sat)

; 21.red
(reset-assertions)
(assert (<= (* (/ 400 441) v10) v16))
(assert (<= (* v5 (+ (/ 21 125) (* (- (/ 49 62500)) v5))) 12))
(assert (<= v5 0))
(assert (not (<= v16 (* (/ 400 441) v10))))
(assert (= (* v16 v16) (+ 1 (* v10 (* (- 1) v10)))))
(assert (<= v5 75))
(assert (<= 0 v5))
(assert (<= 0 v16))
(assert (<= 0 v10))
(assert (not (<= (* v5 (+ (+ (+ (- (/ 667 5500)) (* (/ 116 825) v10)) (* (- (/ 4263 27500)) v16)) (* v5 (+ (+ (- (/ 19343 165000000)) (* (- (/ 841 6187500)) v10)) (* (/ 41209 275000000) v16))))) (+ (+ (/ 460 11) (* (/ 1600 33) v10)) (* (- (/ 588 11)) v16)))))
(check-sat)

; 22.red
(reset-assertions)
(assert (not (<= (* v14 (+ (+ 9 (* v5 (* 3 v5))) (* v19 (+ (* v5 (+ (- 9) (* v5 (* (- 3) v5)))) (* v19 (+ (+ 3 (* v5 v5)) (* v19 (* v5 (+ (- 3) (* v5 (* (- 1) v5))))))))))) (+ (* v5 (* v5 (* (- 3) v5))) (* v19 (+ (* v5 (* (- 9) v5)) (* v19 (+ (* v5 (+ (- 9) (* v5 (* (- 4) v5)))) (* v19 (+ (- 3) (* v5 (* (- 4) v5))))))))))))
(assert (not (<= v14 0)))
(assert (not (<= v5 (- 1))))
(assert (not (<= 1 v19)))
(assert (not (<= v19 v5)))
(check-sat)

; 23.red
(reset-assertions)
(assert (not (<= (* v5 (* (- 1) v6)) 0)))
(assert (not (= 0 v12)))
(assert (not (<= v15 0)))
(assert (not (<= 2 v6)))
(assert (not (<= v6 v15)))
(check-sat)

; 24.red
(reset-assertions)
(assert (not (<= 0 v5)))
(assert (<= (* v9 (* (- 1) v9)) 3))
(assert (<= (* v17 (+ 1 (* v5 (* (- 1) v9)))) (+ (+ 1 (* (- 1) v9)) (* v5 (+ (- 1) (* (- 1) v9))))))
(assert (not (<= v17 0)))
(assert (not (<= v9 (- 1))))
(assert (not (<= 1 v5)))
(assert (not (<= v5 v9)))
(check-sat)

; 25.red
(reset-assertions)
(assert (<= (* (/ 86400000 2025130727) v7) v13))
(assert (not (<= (* v5 (+ (- (/ 8832 13)) (* v5 (+ (- (/ 3174 1625)) (* v5 (+ (- (/ 12167 3250000)) (* v5 (+ (- (/ 1958887 416000000000)) (* v5 (+ (- (/ 6436343 1664000000000000)) (* (- (/ 148035889 79872000000000000000)) v5))))))))))) (+ (+ (/ 1536000 13) (* (/ 331776 65) v7)) (* (- (/ 24301568724 203125)) v13)))))
(assert (<= v5 0))
(assert (not (<= v13 (* (/ 86400000 2025130727) v7))))
(assert (= (* v13 v13) (+ 1 (* v7 (* (- 1) v7)))))
(assert (<= v5 75))
(assert (<= 0 v5))
(assert (not (<= (* v5 (+ (+ (+ (- (/ 23 13)) (* (/ 621 8125) v7)) (* (- (/ 46578006721 26000000000)) v13)) (* v5 (+ (+ (- (/ 529 312000)) (* (- (/ 4761 65000000)) v7)) (* (/ 1071294154583 624000000000000) v13))))) (+ (+ (/ 8000 13) (* (/ 1728 65) v7)) (* (- (/ 2025130727 3250000)) v13)))))
(check-sat)

; 26.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* (/ 1 3) v5)))))))))) 0)))
(assert (= 3 (* v5 v5)))
(assert (not (<= (+ (- (/ 1 10000000)) (* (/ 1 2) v25)) v30)))
(assert (not (<= v25 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v25)))
(assert (not (<= v30 0)))
(assert (not (<= v5 0)))
(check-sat)

; 27.red
(reset-assertions)
(assert (not (<= (* v5 (+ 2 (* 4 v7))) (+ (- 1) (* (- 2) v7)))))
(assert (not (<= v5 (/ 1 20))))
(assert (not (<= v7 (/ 1 20))))
(assert (not (<= v24 (/ 1 20))))
(assert (not (<= 15 v5)))
(assert (not (<= 15 v7)))
(assert (not (<= 15 v24)))
(check-sat)

; 28.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* 2 v5))))))))))))))) 0)))
(assert (not (<= v24 2)))
(assert (not (<= v27 0)))
(assert (not (<= v5 0)))
(assert (not (<= v32 0)))
(assert (not (<= 10 v24)))
(check-sat)

; 29.red
(reset-assertions)
(assert (<= (+ (* v5 v5) (* (- 1) (+ (* (- 1) v5) (* v8 (* v8 v5))))) (/ 33 32)))
(assert (<= (+ (* (- 1) v5) (* v8 (* v8 v5))) 2))
(assert (<= (/ 3 2) (+ (* (- 1) v5) (* v8 (* v8 v5)))))
(assert (<= 1 (+ (* v5 v5) (* (- 1) (+ (* (- 1) v5) (* v8 (* v8 v5)))))))
(assert (<= 0 v8))
(assert (<= 0 v5))
(check-sat)

; 30.red
(reset-assertions)
(assert (not (<= 0 v5)))
(assert (not (<= 0 v8)))
(assert (not (<= (* v11 (+ (- 1) (* v8 v5))) (+ v5 v8))))
(assert (not (<= v11 0)))
(assert (not (<= v5 (- 1))))
(assert (not (<= 1 v8)))
(assert (not (<= v8 v5)))
(check-sat)

; 31.red
(reset-assertions)
(assert (<= (* v5 (* (- (/ 1 3)) v5)) 0))
(assert (not (<= v5 0)))
(assert (not (<= v14 0)))
(assert (not (<= (/ 31415927 10000000) v20)))
(assert (not (<= v20 (/ 15707963 5000000))))
(assert (not (<= (+ (- (/ 1 10000000)) (* (/ 1 2) v20)) v14)))
(assert (= 3 (* v5 v5)))
(check-sat)

; 32.red
(reset-assertions)
(assert (<= 0 v5))
(assert (not (<= v8 (- 1))))
(assert (not (<= 0 v8)))
(assert (not (<= (* v28 (+ 1 (* v5 (* (- 1) v8)))) (+ (+ 1 (* (- 1) v8)) (* v5 (+ (- 1) (* (- 1) v8)))))))
(assert (not (<= (* v28 (+ (+ (/ 471 100) (* v8 (+ (- 3) (* (/ 157 100) v8)))) (* v5 (+ (+ (- 3) (* v8 (+ (- (/ 471 100)) (* v8 (+ 2 (* (- (/ 157 100)) v8)))))) (* v5 (* v8 (+ 3 (* v8 v8)))))))) (+ (+ 3 (* v8 (+ (- (/ 471 100)) (* v8 (+ 4 (* (- (/ 157 100)) v8)))))) (* v5 (+ (+ (- (/ 471 100)) (* v8 (+ 3 (* (- (/ 157 100)) v8)))) (* v5 (+ 3 (* v8 v8)))))))))
(assert (not (<= v28 0)))
(assert (not (<= 1 v5)))
(assert (not (<= v5 v8)))
(assert (<= (* v28 (+ (- 1) (* v5 v8))) (+ v8 v5)))
(check-sat)

; 33.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (* v5 (* 3 v5)))) 0)))
(assert (= 3 (* v5 v5)))
(assert (not (<= (+ (- (/ 1 10000000)) (* (/ 1 2) v18)) v23)))
(assert (not (<= v18 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v18)))
(assert (not (<= v23 0)))
(assert (not (<= v5 0)))
(check-sat)

; 67-99, all using fallback cad   

; 67.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (+ (- (/ 1 2)) (* v5 (* (/ 1 24) v5))))) (- 1))))
(assert (not (<= v18 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v18)))
(assert (not (<= v5 v29)))
(check-sat)

; 68.red
(reset-assertions)
(assert (not (<= (* v5 (+ 12 (* v5 (+ (- 60) (* 120 v5))))) 1)))
(assert (not (= 0 v17)))
(assert (not (<= v20 1)))
(assert (not (<= v5 0)))
(assert (not (<= v17 0)))
(check-sat)

; 69.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (* v5 v5))) 0)))
(assert (not (<= (* v12 (* v12 (* v12 (* v12 (+ (* v5 (* v5 (+ (- (/ 1 24)) (* v5 (* (/ 1 24) v5))))) (* v12 (* (/ 1 720) v12))))))) (* v5 (* v5 (* v5 (* v5 (+ (- 3) (* v5 v5)))))))))
(assert (not (<= v5 0)))
(assert (not (<= v12 0)))
(assert (not (<= (/ 31415927 10000000) v47)))
(assert (not (<= v47 (/ 15707963 5000000))))
(assert (not (<= (+ (- (/ 1 10000000)) (* (/ 1 2) v47)) v12)))
(assert (= (* v5 v5) 3))
(check-sat)

; 70.red
(reset-assertions)
(assert (<= (* v5 (+ (+ (* (/ 2891855167488 125) v6) (* (- (/ 114152177664 25)) v11)) (* v5 (+ (+ (* (- (/ 5060746543104 15625)) v6) (* (/ 199766310912 3125) v11)) (* v5 (+ (+ (* (/ 5904204300288 1953125) v6) (* (- (/ 233060696064 390625)) v11)) (* v5 (+ (+ (* (- (/ 5085457219584 244140625)) v6) (* (/ 200741732352 48828125) v11)) (* v5 (+ (+ (* (/ 3390304813056 30517578125) v6) (* (- (/ 133827821568 6103515625)) v11)) (* v5 (+ (+ (* (- (/ 1792270513152 3814697265625)) v6) (* (/ 70747520256 762939453125) v11)) (* v5 (+ (+ (* (/ 757079785728 476837158203125) v6) (* (- (/ 29884728384 95367431640625)) v11)) (* v5 (+ (+ (* (- (/ 254331490518 59604644775390625)) v6) (* (/ 20078801883 23841857910156250) v11)) (* v5 (+ (+ (* (/ 66704512371 7450580596923828125) v6) (* (- (/ 10532291427 5960464477539062500)) v11)) (* v5 (+ (+ (* (- (/ 209314159509 14901161193847656250000)) v6) (* (/ 33049604133 11920928955078125000000) v11)) (* v5 (+ (+ (* (/ 112707624351 7450580596923828125000000) v6) (* (- (/ 17795940687 5960464477539062500000000)) v11)) (* v5 (+ (* (- (/ 262984456819 29802322387695312500000000000)) v6) (* (/ 41523861603 23841857910156250000000000000) v11))))))))))))))))))))))))) (+ (* 826244333568 v6) (* (- 163074539520) v11))))
(assert (not (<= (* v5 (+ (+ (* (- (/ 2891855167488 125)) v6) (* (/ 114152177664 25) v11)) (* v5 (+ (+ (* (/ 5060746543104 15625) v6) (* (- (/ 199766310912 3125)) v11)) (* v5 (+ (+ (* (- (/ 5904204300288 1953125)) v6) (* (/ 233060696064 390625) v11)) (* v5 (+ (+ (* (/ 5085457219584 244140625) v6) (* (- (/ 200741732352 48828125)) v11)) (* v5 (+ (+ (* (- (/ 3390304813056 30517578125)) v6) (* (/ 133827821568 6103515625) v11)) (* v5 (+ (+ (* (/ 1792270513152 3814697265625) v6) (* (- (/ 70747520256 762939453125)) v11)) (* v5 (+ (+ (* (- (/ 757079785728 476837158203125)) v6) (* (/ 29884728384 95367431640625) v11)) (* v5 (+ (+ (* (/ 254331490518 59604644775390625) v6) (* (- (/ 20078801883 23841857910156250)) v11)) (* v5 (+ (+ (* (- (/ 66704512371 7450580596923828125)) v6) (* (/ 10532291427 5960464477539062500) v11)) (* v5 (+ (+ (* (/ 209314159509 14901161193847656250000) v6) (* (- (/ 33049604133 11920928955078125000000)) v11)) (* v5 (+ (+ (* (- (/ 112707624351 7450580596923828125000000)) v6) (* (/ 17795940687 5960464477539062500000000) v11)) (* v5 (+ (* (/ 262984456819 29802322387695312500000000000) v6) (* (- (/ 41523861603 23841857910156250000000000000)) v11))))))))))))))))))))))))) (+ (* (- 826244333568) v6) (* 163074539520 v11)))))
(assert (not (<= v5 0)))
(assert (= (* v11 v11) (+ 1 (* v6 (* (- 1) v6)))))
(assert (<= v5 75))
(assert (<= 0 v5))
(check-sat)

; 71.red
(reset-assertions)
(assert (not (<= (* v5 (+ (* v11 (* (/ 5 4) v8)) (* v5 (* v11 (* v11 (* v8 (* (/ 1 4) v8))))))) 0)))
(assert (<= 1 v8))
(assert (<= 1 v11))
(assert (<= 1 v5))
(assert (<= v8 2))
(assert (<= v11 2))
(assert (<= v5 2))
(assert (not (<= (* v5 (* v11 (+ (* v8 (+ (- (/ 7 2)) (* (/ 1 2) v8))) (* v11 (* v8 (+ (/ 1 2) (* (/ 1 2) v8))))))) (+ (+ (- (/ 1 4)) (* (- (/ 1 4)) v8)) (* v11 (+ (- (/ 1 4)) (* (- (/ 1 4)) v8)))))))
(assert (not (<= v11 1)))
(assert (not (<= v8 1)))
(assert (not (<= v5 1)))
(check-sat)

; 72.red
(reset-assertions)
(assert (not (<= (* v14 (+ (+ (+ (- 2) (* v5 (* (/ 1 2) v5))) (* v9 (+ v5 (* (/ 1 2) v9)))) (* v14 (+ (+ (* (/ 1 2) v5) (* (/ 1 2) v9)) (* v14 (+ (/ 1 3) (* v14 (* v14 (+ (- (/ 1 120)) (* v14 (* (/ 1 5040) v14))))))))))) (+ (* v5 (+ 2 (* v5 (* (- (/ 1 3)) v5)))) (* v9 (+ (+ 2 (* v5 (* (- (/ 1 2)) v5))) (* v9 (+ (* (- (/ 1 2)) v5) (* (- (/ 1 3)) v9)))))))))
(assert (not (<= 3 v5)))
(assert (not (<= 3 v9)))
(assert (not (<= 3 v14)))
(assert (not (<= v5 (/ 1 10))))
(assert (not (<= v9 (/ 1 10))))
(assert (not (<= v14 (/ 1 10))))
(check-sat)

; 73.red
(reset-assertions)
(assert (not (<= (* v5 (* 3600000000 v5)) (- 3600000000000000000000000))))
(assert (not (<= (* v13 (* v13 (+ (+ (- 1800000000000000000000000) (* v5 (* (- 1800000000) v5))) (* v13 (* v13 (+ 150000000000000000000000 (* v5 (* 150000000 v5)))))))) (+ (- 3600120000000000000000000) (* v5 (* (- 3600120000) v5))))))
(assert (not (<= v40 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v40)))
(check-sat)

; 74.red
(reset-assertions)
(assert (<= (* v5 (* v5 (+ (/ 1 2) (* v5 (* (- (/ 1 24)) v5))))) 1))
(assert (not (<= v5 v17)))
(assert (<= (/ 1 20) v17))
(assert (<= v5 (* (/ 1 2) v23)))
(assert (not (<= (/ 31415927 10000000) v23)))
(assert (not (<= v23 (/ 15707963 5000000))))
(check-sat)

; 75.red
(reset-assertions)
(assert (not (<= (* v5 (+ (* v16 (* v16 (+ (/ 1 6) (* v16 (* v16 (+ (- (/ 1 120)) (* v16 (* v16 (+ (/ 1 5040) (* v16 (* v16 (+ (- (/ 1 362880)) (* v16 (* (/ 1 39916800) v16)))))))))))))) (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* (/ 1 120) v5))))))) 0)))
(assert (not (<= (* v5 (* v5 (+ (* (- (/ 1 6)) v16) (* v5 (* v5 (+ (* (/ 1 120) v16) (* v5 (* v5 (+ (* (- (/ 1 5040)) v16) (* v5 (* v5 (* (/ 1 362880) v16)))))))))))) (* v16 (* v16 (* v16 (+ (- (/ 1 6)) (* v16 (* v16 (+ (/ 1 120) (* v16 (* v16 (+ (- (/ 1 5040)) (* v16 (* v16 (+ (/ 1 362880) (* v16 (* (- (/ 1 39916800)) v16))))))))))))))))))
(assert (not (<= (* v5 (+ (* v16 (* v16 (+ (/ 1 6) (* v16 (* v16 (+ (- (/ 1 120)) (* v16 (* (/ 1 5040) v16)))))))) (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* v5 (+ (/ 1 120) (* v5 (* v5 (+ (- (/ 1 5040)) (* v5 (* (/ 1 362880) v5))))))))))))) 0)))
(assert (not (<= (* v5 (* v5 (+ (* (- (/ 1 6)) v16) (* v5 (* v5 (* (/ 1 120) v16)))))) (* v16 (* v16 (* v16 (+ (- (/ 1 6)) (* v16 (* v16 (+ (/ 1 120) (* v16 (* (- (/ 1 5040)) v16))))))))))))
(assert (not (<= (* v5 (+ (* v16 (* (/ 1 6) v16)) (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* (/ 1 120) v5))))))) 0)))
(assert (not (<= v16 0)))
(assert (not (<= v128 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v128)))
(assert (not (<= v5 v16)))
(check-sat)

; 76.red
(reset-assertions)
(assert (not (<= (* v10 (+ (* v5 (* (/ 1 6) v5)) (* v10 (* v10 (+ (- (/ 1 6)) (* v10 (* v10 (+ (/ 1 120) (* v10 (* v10 (+ (- (/ 1 5040)) (* v10 (* (/ 1 362880) v10))))))))))))) 0)))
(assert (not (<= (* v10 (* v10 (+ (* (- (/ 1 6)) v5) (* v10 (* v10 (* (/ 1 120) v5)))))) (* v5 (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* v5 (+ (/ 1 120) (* v5 (* (- (/ 1 5040)) v5))))))))))))
(assert (not (<= (* v10 (+ (* v5 (* (/ 1 6) v5)) (* v10 (* v10 (+ (- (/ 1 6)) (* v10 (* (/ 1 120) v10))))))) 0)))
(assert (not (<= v5 0)))
(assert (not (<= v64 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v64)))
(assert (<= v10 (* (/ 1 2) v64)))
(assert (<= 0 v5))
(assert (not (<= v10 v5)))
(check-sat)

; 77.red
(reset-assertions)
(assert (not (<= (* v5 (+ (- (/ 345344 175)) (* v5 (+ (- (/ 410096 21875)) (* v5 (+ (- (/ 973978 8203125)) (* v5 (+ (- (/ 9252791 18750000000)) (* v5 (+ (- (/ 175803029 131250000000000)) (* (- (/ 3340257551 1575000000000000000)) v5))))))))))) (/ 710912 7))))
(assert (not (<= (* v5 (+ (/ 5472 125) (* v5 (+ (/ 6498 15625) (* v5 (+ (/ 20577 7812500) (* v5 (+ (/ 2736741 250000000000) (* v5 (+ (/ 7428297 250000000000000) (* (/ 47045881 1000000000000000000) v5))))))))))) (- 2304))))
(assert (not (<= v79 (* (/ 1770 689) v80))))
(check-sat)

; 78.red
(reset-assertions)
(assert (not (<= v8 (* (- 1) v5))))
(assert (not (<= v20 1)))
(assert (not (<= v8 v5)))
(assert (<= (* (- 1) v5) v20))
(assert (not (<= (* v20 (+ (* v8 (* v8 (* (- (/ 157 100)) v8))) (* v20 (+ (* v8 (* v8 (+ 2 (* (- (/ 3 10)) v8)))) (* v20 (+ (* (- (/ 157 100)) v8) (* v20 (+ 1 (* (- (/ 3 10)) v8))))))))) (* v8 (* v8 (* v8 (* (- 1) v5)))))))
(assert (not (<= 0 v5)))
(assert (<= v5 0))
(check-sat)

; 79.red
(reset-assertions)
(assert (<= (* v5 (* v5 (+ (- 1) (* v5 (* v5 (+ (/ 7 24) (* v5 (* v5 (+ (- (/ 1 45)) (* v5 (* v5 (+ (/ 29 40320) (* v5 (* v5 (+ (- (/ 23 1814400)) (* v5 (* v5 (+ (/ 67 479001600) (* v5 (* v5 (+ (- (/ 23 21794572800)) (* v5 (* v5 (+ (/ 11 1902071808000) (* v5 (* v5 (+ (- (/ 1 41573855232000)) (* v5 (* v5 (+ (/ 191 2432902008176640000) (* v5 (* v5 (+ (- (/ 29 140500090972200960000)) (* v5 (* (/ 1 2248001455555215360000) v5))))))))))))))))))))))))))))))))))) 0))
(assert (not (<= (* v5 (* v5 (+ (- (/ 1 2)) (* v5 (* v5 (+ (/ 1 24) (* v5 (* v5 (+ (- (/ 1 720)) (* v5 (* v5 (+ (/ 1 40320) (* v5 (* v5 (+ (- (/ 1 3628800)) (* v5 (* v5 (+ (/ 1 479001600) (* v5 (* v5 (+ (- (/ 1 87178291200)) (* v5 (* v5 (+ (/ 1 20922789888000) (* v5 (* v5 (+ (- (/ 1 6402373705728000)) (* v5 (* v5 (+ (/ 1 2432902008176640000) (* v5 (* (- (/ 1 1124000727777607680000)) v5)))))))))))))))))))))))))))))))) (- 1))))
(assert (<= v125 (+ (- (/ 1 5)) (* (/ 1 2) v128))))
(assert (not (<= v128 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v128)))
(assert (<= (/ 1 10) v5))
(assert (not (<= v125 v5)))
(check-sat)

; 80.red
(reset-assertions)
(assert (not (<= (* v5 (+ 2 (* v5 (* v8 (* 2 v13))))) 0)))
(assert (<= v5 2))
(assert (<= v8 2))
(assert (<= v13 2))
(assert (<= 1 v5))
(assert (<= 1 v8))
(assert (<= 1 v13))
(assert (not (<= (* v5 (* v8 (* v8 (+ (* v13 (* v13 (+ (- (/ 15 4)) (* (/ 1 4) v13)))) (* v8 (* v13 (* v13 (+ (/ 1 4) (* (/ 1 4) v13))))))))) (* v8 (+ (* v13 (+ (/ 11 4) (* (- (/ 5 4)) v13))) (* v8 (* v13 (+ (- (/ 5 4)) (* (- (/ 5 4)) v13)))))))))
(assert (not (<= (* v5 (* v8 (+ (* v13 (+ (- (/ 7 2)) (* (/ 1 2) v13))) (* v8 (* v13 (+ (/ 1 2) (* (/ 1 2) v13))))))) (+ (+ (- (/ 1 4)) (* (- (/ 1 4)) v13)) (* v8 (+ (- (/ 1 4)) (* (- (/ 1 4)) v13)))))))
(assert (not (<= v13 1)))
(assert (not (<= v8 1)))
(assert (not (<= v5 1)))
(check-sat)

; 81.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (+ 315 (* v5 (* v5 (+ 105 (* v5 (* 5 v5)))))))) (- 231))))
(assert (not (<= (* v27 (+ (+ (- 231) (* v5 (* v5 (+ (- 315) (* v5 (* v5 (+ (- 105) (* v5 (* (- 5) v5))))))))) (* v18 (* v5 (+ 231 (* v5 (* v5 (+ 315 (* v5 (* v5 (+ 105 (* v5 (* 5 v5))))))))))))) (+ (+ (/ 231 4) (* v5 (* v5 (+ (/ 315 4) (* v5 (+ 77 (* v5 (+ (/ 105 4) (* v5 (+ (/ 294 5) (* v5 (+ (/ 5 4) (* 5 v5))))))))))))) (* v18 (+ (* v5 (+ (- (/ 231 4)) (* v5 (+ 231 (* v5 (+ (- (/ 315 4)) (* v5 (+ 238 (* v5 (+ (- (/ 105 4)) (* v5 (+ (/ 231 5) (* (- (/ 5 4)) v5))))))))))))) (* v18 (* v5 (+ 231 (* v5 (* v5 (+ 315 (* v5 (* v5 (+ 105 (* v5 (* 5 v5)))))))))))))))))
(assert (not (<= 0 v5)))
(assert (not (<= v27 0)))
(assert (not (<= v5 (- 1))))
(assert (not (<= 1 v18)))
(assert (not (<= v18 v5)))
(check-sat)

; 82.red
(reset-assertions)
(assert (<= (* v19 (+ (+ (* (- 6) v5) (* v13 (+ (+ (- 6) (* v5 (* 6 v5))) (* v13 (+ (* 4 v5) (* v13 (+ (+ (- 2) (* v5 (* 2 v5))) (* v13 (* 2 v5))))))))) (* v19 (+ (- 3) (* v13 (+ (* 6 v5) (* v13 (+ (+ (- 1) (* v5 (* (- 3) v5))) (* v13 (+ (* 2 v5) (* v13 (* v5 (* (- 1) v5))))))))))))) (+ (+ 9 (* v5 (* 3 v5))) (* v13 (+ (* (- 12) v5) (* v13 (+ (+ 6 (* v5 (* 10 v5))) (* v13 (+ (* (- 4) v5) (* v13 (+ 1 (* v5 (* 3 v5)))))))))))))
(assert (not (<= 0 v13)))
(assert (<= (* v19 (+ 1 (* v13 (* (- 1) v5)))) (+ (+ 1 (* (- 1) v5)) (* v13 (+ (- 1) (* (- 1) v5))))))
(assert (not (<= v19 0)))
(assert (not (<= v5 (- 1))))
(assert (not (<= 1 v13)))
(assert (not (<= v13 v5)))
(check-sat)

; 83.red
(reset-assertions)
(assert (not (<= 0 v15)))
(assert (not (<= (* v18 (+ (- (/ 273 50)) (* v15 (+ (+ 3 (* (/ 273 50) v5)) (* v15 (+ (+ (- (/ 91 50)) (* (- 3) v5)) (* v15 (* (/ 91 50) v5)))))))) (+ (+ (- 3) (* (/ 273 50) v5)) (* v15 (+ (/ 273 50) (* v15 (+ (+ (- 4) (* (/ 91 50) v5)) (* v15 (+ (/ 91 50) v5))))))))))
(assert (not (<= (* v18 (+ 1 (* v15 (* (- 1) v5)))) (+ (* (- 1) v5) (* (- 1) v15)))))
(assert (not (<= v18 0)))
(assert (not (<= v5 (- 1))))
(assert (not (<= 1 v15)))
(assert (not (<= v15 v5)))
(check-sat)

; 84.red
(reset-assertions)
(assert (not (<= v6 0)))
(assert (not (<= v47 (/ 15707963 5000000))))
(assert (not (<= (* v5 (+ (* v6 (* v6 (* v6 (+ (- (/ 1 6)) (* v6 (* (/ 1 120) v6)))))) (* v5 (* v5 (* (/ 1 6) v6))))) (* v6 (* v6 (+ (/ 1 2000) (* v6 (* v6 (+ (- (/ 1 12000)) (* v6 (* (/ 1 240000) v6)))))))))))
(assert (not (<= (/ 31415927 10000000) v47)))
(assert (not (<= (* (/ 1 2) v47) v6)))
(assert (not (<= v5 0)))
(assert (not (<= v6 v5)))
(assert (<= (* (/ 1 2000) v6) v5))
(assert (not (<= v5 (* (/ 1 2000) v6))))
(assert (not (<= (* v5 (* v5 (* v5 (* (/ 1 6) v6)))) (* v6 (* (/ 1 2000) v6)))))
(check-sat)

; 85.red
(reset-assertions)
(assert (<= (* v5 (+ (* v26 (* v26 (+ (/ 1 6) (* v26 (* v26 (+ (- (/ 1 120)) (* v26 (* v26 (+ (/ 1 5040) (* v26 (* v26 (+ (- (/ 1 362880)) (* v26 (* v26 (+ (/ 1 39916800) (* v26 (* v26 (+ (- (/ 1 6227020800)) (* v26 (* (/ 1 1307674368000) v26)))))))))))))))))))) (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* v5 (+ (/ 1 120) (* v5 (* v5 (+ (- (/ 1 5040)) (* v5 (* (/ 1 362880) v5))))))))))))) 0))
(assert (not (<= (* v5 (* v5 (+ (* (- (/ 1 6)) v26) (* v5 (* v5 (+ (* (/ 1 120) v26) (* v5 (* v5 (+ (* (- (/ 1 5040)) v26) (* v5 (* v5 (* (/ 1 362880) v26)))))))))))) (* v26 (* v26 (* v26 (+ (- (/ 1 6)) (* v26 (* v26 (+ (/ 1 120) (* v26 (* v26 (+ (- (/ 1 5040)) (* v26 (* v26 (+ (/ 1 362880) (* v26 (* (- (/ 1 39916800)) v26))))))))))))))))))
(assert (not (<= (* v5 (+ (* v26 (* v26 (+ (/ 1 6) (* v26 (* v26 (+ (- (/ 1 120)) (* v26 (* (/ 1 5040) v26)))))))) (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* v5 (+ (/ 1 120) (* v5 (* v5 (+ (- (/ 1 5040)) (* v5 (* (/ 1 362880) v5))))))))))))) 0)))
(assert (not (<= (* v5 (* v5 (+ (* (- (/ 1 6)) v26) (* v5 (* v5 (* (/ 1 120) v26)))))) (* v26 (* v26 (* v26 (+ (- (/ 1 6)) (* v26 (* v26 (+ (/ 1 120) (* v26 (* (- (/ 1 5040)) v26))))))))))))
(assert (not (<= (* v5 (+ (* v26 (* (/ 1 6) v26)) (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* (/ 1 120) v5))))))) 0)))
(assert (not (<= v26 0)))
(assert (not (<= v137 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v137)))
(assert (<= v5 (* (/ 1 2) v137)))
(assert (<= 0 v26))
(assert (not (<= v5 v26)))
(check-sat)

; 86.red
(reset-assertions)
(assert (<= (* v5 (+ (- 12) (* v5 (+ 60 (* (- 120) v5))))) (- 1)))
(assert (= (+ 1 (* v5 (* v5 v5))) (+ (- 1) (* v18 (* v18 v18)))))
(assert (= (* v28 (* v28 v28)) (+ (- 1) (* v18 (* v18 v18)))))
(assert (not (<= (+ (- 1) (* v18 (* v18 v18))) 2)))
(assert (not (<= v18 0)))
(assert (not (<= v5 0)))
(assert (not (<= v28 0)))
(assert (not (<= 10 (+ (- 1) (* v18 (* v18 v18))))))
(check-sat)

; 87.red
(reset-assertions)
(assert (not (<= (* v5 (+ (/ 24909642641661470452192641024 12341362258596589055135468582520347) (* (- (/ 25677719677173760 3119868895908289175433)) v10))) (* (- 20) v10))))
(assert (not (<= v5 0)))
(assert (= (* v5 v5) (/ 1325421053866224634595698711821825 295147905179352825856)))
(assert (= (* v5 v5) (+ 277555600 (* v51 (* v51 (+ 15328072984 (* v51 (* v51 (+ 129098541721 (* v51 (* v51 (+ 21404723599 (* v51 (* v51 (+ 1024027285 (* v51 (* 15132100 v51)))))))))))))))))
(assert (not (<= v10 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v10)))
(assert (<= 0 v5))
(check-sat)

; 88.red
(reset-assertions)
(assert (<= (* v8 (+ 12 (* v8 (+ (- 60) (* 120 v8))))) 1))
(assert (not (<= v5 0)))
(assert (= (+ 1 (* v8 v8)) (+ (- 1) (* v5 v5))))
(assert (= (* v28 v28) (+ (- 1) (* v5 v5))))
(assert (not (<= (+ (- 1) (* v5 v5)) 1)))
(assert (not (<= v8 0)))
(assert (not (<= v28 0)))
(assert (not (<= 5 (+ (- 1) (* v5 v5)))))
(check-sat)

; 89.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* (/ 1 3) v5)))))))))) 0)))
(assert (not (<= (* v20 (* v20 (+ (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (+ (/ 1 2) (* v5 (* (- (/ 1 6)) v5))))))))))) (* v20 (* v20 (+ (* v5 (* v5 (* v5 (* v5 (* v5 (* v5 (+ (- (/ 1 24)) (* v5 (* v5 (* v5 (* (/ 1 72) v5))))))))))) (* v20 (* v20 (+ (* v5 (* v5 (* v5 (* (/ 1 720) v5)))) (* v20 (* v20 (+ (* v5 (* (- (/ 1 40320)) v5)) (* v20 (* (/ 1 3628800) v20)))))))))))))) 0)))
(assert (not (<= v5 0)))
(assert (not (<= v20 0)))
(assert (not (<= (/ 31415927 10000000) v87)))
(assert (not (<= v87 (/ 15707963 5000000))))
(assert (not (<= (+ (- (/ 1 10000000)) (* (/ 1 2) v87)) v20)))
(assert (= 3 (* v5 v5)))
(check-sat)

; 90.red
(reset-assertions)
(assert (not (<= (* v19 (+ (* v5 (* (/ 1 6) v5)) (* v19 (* v19 (+ (- (/ 1 6)) (* v19 (* v19 (+ (/ 1 120) (* v19 (* v19 (+ (- (/ 1 5040)) (* v19 (* v19 (+ (/ 1 362880) (* v19 (* (- (/ 1 39916800)) v19)))))))))))))))) 0)))
(assert (not (<= (* v19 (* v19 (+ (* (- (/ 1 6)) v5) (* v19 (* v19 (+ (* (/ 1 120) v5) (* v19 (* v19 (+ (* (- (/ 1 5040)) v5) (* v19 (* v19 (* (/ 1 362880) v5)))))))))))) (* v5 (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* v5 (+ (/ 1 120) (* v5 (* v5 (+ (- (/ 1 5040)) (* v5 (* v5 (+ (/ 1 362880) (* v5 (* (- (/ 1 39916800)) v5))))))))))))))))))
(assert (not (<= (* v19 (+ (* v5 (* v5 (+ (/ 1 6) (* v5 (* v5 (+ (- (/ 1 120)) (* v5 (* (/ 1 5040) v5)))))))) (* v19 (* v19 (+ (- (/ 1 6)) (* v19 (* v19 (+ (/ 1 120) (* v19 (* v19 (+ (- (/ 1 5040)) (* v19 (* (/ 1 362880) v19))))))))))))) 0)))
(assert (not (<= (* v19 (* v19 (+ (* (- (/ 1 6)) v5) (* v19 (* v19 (* (/ 1 120) v5)))))) (* v5 (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* v5 (+ (/ 1 120) (* v5 (* (- (/ 1 5040)) v5))))))))))))
(assert (not (<= (* v19 (+ (* v5 (* (/ 1 6) v5)) (* v19 (* v19 (+ (- (/ 1 6)) (* v19 (* (/ 1 120) v19))))))) 0)))
(assert (not (<= v5 0)))
(assert (not (<= v126 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v126)))
(assert (not (<= v19 v5)))
(check-sat)

; 91.red
(reset-assertions)
(assert (not (<= v5 0)))
(assert (not (<= (* v5 (* v5 (* (/ 1 6) v5))) (+ (+ (/ 1 10) (* v15 (* v15 (* (- (/ 1 6)) v15)))) (* v22 (* v22 (* (- (/ 1 6)) v22)))))))
(assert (not (<= v5 (/ 1 10))))
(assert (not (<= v22 (/ 1 10))))
(assert (not (<= v15 (/ 1 10))))
(assert (not (<= (/ 11 10) v5)))
(assert (not (<= (/ 11 10) v22)))
(assert (not (<= (/ 11 10) v15)))
(check-sat)

; 92.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (+ (- 1) (* v5 (* v5 (+ (/ 1 3) (* v5 (* v5 (+ (- (/ 1 24)) (* v5 (* (/ 1 576) v5))))))))))) 0)))
(assert (not (<= v26 v5)))
(assert (not (<= (/ 31415927 10000000) v32)))
(assert (not (<= v32 (/ 15707963 5000000))))
(check-sat)

; 93.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (* v5 (* v5 (+ (/ 1 24) (* v5 (* v5 (+ (- (/ 1 720)) (* v5 (* v5 (+ (/ 1 40320) (* v5 (* v5 (+ (- (/ 1 3628800)) (* v5 (* v5 (+ (/ 1 479001600) (* v5 (* v5 (+ (- (/ 1 87178291200)) (* v5 (* (/ 1 20922789888000) v5)))))))))))))))))))))) 0)))
(assert (not (<= v45 0)))
(assert (not (<= v5 0)))
(assert (not (<= (/ 31415927 10000000) v53)))
(assert (not (<= v53 (/ 15707963 5000000))))
(assert (not (<= (+ (- (/ 1 10000000)) (* (/ 1 2) v53)) v5)))
(check-sat)

; 94.red
(reset-assertions)
(assert (not (<= (* (+ 1 (* v7 (* (- 1) v7))) (+ (+ 128 (* 24 v7)) (* (+ 1 (* v7 (* (- 1) v7))) (+ (+ 60 (* 10 v7)) (* (+ 1 (* v7 (* (- 1) v7))) (+ (+ 8 v7) (* (/ 1 8) (+ 1 (* v7 (* (- 1) v7)))))))))) (+ (- 80) (* (- 16) v7)))))
(assert (<= (* (+ 1 (* v7 (* (- 1) v7))) (+ (+ (+ (/ 1543 500) v7) (* (- (/ 957 1000)) v37)) (* (/ 1 2) (+ 1 (* v7 (* (- 1) v7)))))) (+ (+ (/ 957 250) (* (- (/ 957 250)) v7)) (* v37 (+ (/ 957 500) (* (- (/ 957 500)) v7))))))
(assert (not (<= 1 (+ 1 (* v7 (* (- 1) v7))))))
(assert (not (<= (+ 1 (* v7 (* (- 1) v7))) 0)))
(assert (<= 0 v7))
(assert (<= 0 v37))
(assert (= (+ 1 (* v37 (* (- 1) v37))) (* (+ 1 (* v7 (* (- 1) v7))) (+ 1 (* v7 (* (- 1) v7))))))
(check-sat)

; 95.red
(reset-assertions)
(assert (<= (* v8 (+ 1 (* v9 (+ (- (/ 207 100)) v5)))) (* v9 (+ v5 (* (- 1) v9)))))
(assert (not (<= v9 1)))
(assert (= (* v8 v8) (+ (+ 1 (* v5 v5)) (* v9 (* v9 (+ 1 (* v5 v5)))))))
(assert (not (<= v8 0)))
(assert (not (<= v5 0)))
(assert (not (<= 2 v9)))
(assert (not (<= v9 v5)))
(check-sat)

; 96.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (+ (+ (- 900000000000000000000000) (* v8 (* (- 900000000) v8))) (* v5 (* v5 (+ (+ 75000000000000000000000 (* v8 (* 75000000 v8))) (* v5 (* v5 (+ (+ (- 2500000000000000000000) (* v8 (* (- 2500000) v8))) (* v5 (* v5 (+ (+ (/ 312500000000000000000 7) (* v8 (* (/ 312500 7) v8))) (* v5 (* v5 (+ (+ (- (/ 31250000000000000000 63)) (* v8 (* (- (/ 31250 63)) v8))) (* v5 (* v5 (+ (/ 7812500000000000000 2079) (* v8 (* (/ 15625 4158) v8)))))))))))))))))))) (+ (- 1800060000000000000000000) (* v8 (* (- 1800060000) v8))))))
(assert (not (<= v79 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v79)))
(assert (<= v5 (* (/ 1 3) v79)))
(assert (<= (* (/ 1 4) v79) v5))
(assert (<= v8 120))
(assert (<= 100 v8))
(check-sat)

; 97.red
(reset-assertions)
(assert (not (<= (* v25 (* v25 (+ (* (- (/ 1 6)) v5) (* v25 (* v25 (+ (* (/ 1 120) v5) (* v25 (* v25 (+ (* (- (/ 1 5040)) v5) (* v25 (* v25 (* (/ 1 362880) v5)))))))))))) (* v5 (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* v5 (+ (/ 1 120) (* v5 (* (- (/ 1 5040)) v5))))))))))))
(assert (not (<= (* v25 (+ (* v5 (* v5 (+ (/ 1 6) (* v5 (* v5 (+ (- (/ 1 120)) (* v5 (* (/ 1 5040) v5)))))))) (* v25 (* v25 (+ (- (/ 1 6)) (* v25 (* v25 (+ (/ 1 120) (* v25 (* v25 (+ (- (/ 1 5040)) (* v25 (* (/ 1 362880) v25))))))))))))) 0)))
(assert (not (<= (* v25 (* v25 (+ (* (- (/ 1 6)) v5) (* v25 (* v25 (* (/ 1 120) v5)))))) (* v5 (* v5 (* v5 (+ (- (/ 1 6)) (* v5 (* v5 (+ (/ 1 120) (* v5 (* (- (/ 1 5040)) v5))))))))))))
(assert (not (<= (* v25 (+ (* v5 (* (/ 1 6) v5)) (* v25 (* v25 (+ (- (/ 1 6)) (* v25 (* (/ 1 120) v25))))))) 0)))
(assert (not (<= v5 0)))
(assert (not (<= v91 (/ 15707963 5000000))))
(assert (not (<= (/ 31415927 10000000) v91)))
(assert (<= v25 (* (/ 1 2) v91)))
(assert (<= 0 v5))
(assert (not (<= v25 v5)))
(check-sat)

; 98.red
(reset-assertions)
(assert (not (<= (* v5 (* v5 (+ (- (/ 1 2)) (* v5 (* v5 (+ (/ 1 24) (* v5 (* v5 (+ (- (/ 1 720)) (* v5 (* v5 (+ (/ 1 40320) (* v5 (* v5 (+ (- (/ 1 3628800)) (* v5 (* v5 (+ (/ 1 479001600) (* v5 (* (- (/ 1 87178291200)) v5)))))))))))))))))))) (- 1))))
(assert (not (<= (* v5 (* v5 (+ 1 (* v5 (* v5 (+ (- (/ 1 3)) (* v5 (* v5 (+ (/ 2 45) (* v5 (* v5 (+ (- (/ 1 315)) (* v5 (* v5 (+ (/ 2 14175) (* v5 (* v5 (+ (- (/ 2047 479001600)) (* v5 (* v5 (+ (/ 1 10762752) (* v5 (* v5 (+ (- (/ 15413 10461394944000)) (* v5 (* v5 (+ (/ 107 6276836966400) (* v5 (* v5 (+ (- (/ 541 3766102179840000)) (* v5 (* v5 (+ (/ 17 19772036444160000) (* v5 (* (- (/ 1 316352583106560000)) v5))))))))))))))))))))))))))))))))))) 0)))
(assert (not (<= v5 v109)))
(assert (not (<= (/ 31415927 10000000) v115)))
(assert (not (<= v115 (/ 15707963 5000000))))
(check-sat)

; 99.red
(reset-assertions)
(assert (<= 0 v5))
(assert (<= 1 v8))
(assert (<= v11 2))
(assert (<= 1 v11))
(assert (<= 1 v5))
(assert (<= v8 2))
(assert (<= v5 2))
(assert (not (<= (* v5 (* v11 (+ (* v8 (+ (- (/ 7 2)) (* (/ 1 2) v8))) (* v11 (* v8 (+ (/ 1 2) (* (/ 1 2) v8))))))) (+ (+ (- (/ 1 4)) (* (- (/ 1 4)) v8)) (* v11 (+ (- (/ 1 4)) (* (- (/ 1 4)) v8)))))))
(assert (not (<= (* v5 (* v11 (* v11 (+ (* v8 (* v8 (+ (- (/ 15 4)) (* (/ 1 4) v8)))) (* v11 (* v8 (* v8 (+ (/ 1 4) (* (/ 1 4) v8))))))))) (* v11 (+ (* v8 (+ (/ 11 4) (* (- (/ 5 4)) v8))) (* v11 (* v8 (+ (- (/ 5 4)) (* (- (/ 5 4)) v8)))))))))
(assert (not (<= v11 1)))
(assert (not (<= v8 1)))
(assert (not (<= v5 1)))
(check-sat)
(exit)

end;