(setq *echo t)

%(mytrace 'internallycallablep)
%(mytrace 'fastcallablep)
%(mytrace 'saveentry)
%(mytrace 'depositstring)
%(mytrace 'depositbyte)
(mytrace 'depositwordblock)
(mytrace 'depositquadwordexpression)
(mytrace 'depositword)
(mytrace 'putword)
%(mytrace 'compact-bittable)

(mytrace 'binarywrite)
(mytrace 'binarywriteblock)

(mytrace 'instructionlength)
(mytrace 'instructionlength1)
(mytrace 'inlineconstantlength)
(mytrace 'modR/M)
(mytrace 'sibbyte-for-indexed)
(mytrace 'depositextension)
(mytrace 'depositbyte)
(mytrace 'lthmodR/M)
(mytrace 'lth-sibbyte-for-indexed)
(mytrace 'reg2int)
(mytrace 'OP-reg-effa)
(mytrace 'OP-imm-effa)
(mytrace 'OP-imm8-effa)
(mytrace 'OP-reg-effa-2)
(mytrace 'OP2-effa)
(mytrace 'OP-im-EAX)
(mytrace 'OP-im-reg)
(mytrace 'OP-byte)

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(cond
  ((member 'vsl lispsystem*)
   (de putentry (a b c)
     (print (list 'putentry a b c))
     nil)))

(faslout 'foo)

(de arthur (x) "hello")

(faslend)

