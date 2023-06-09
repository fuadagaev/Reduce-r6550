# Makefile for "Jlisp"
# Now using a reasonably standard "make" syntax.


all:	reduce.jar minireduce.jar jlisp.jar

.PHONY:	clean
clean:
	-rm -rf *.jar *.class *.img *.log *.bak *~ uk inline*

# I use the "unifdef" utility here so I can have a SINGLE master source
# file for my bytecode interpreter.

core/Bytecode.java:	core/Bytecode.java.base
	unifdef -x2 -UINSTRUMENTED < core/Bytecode.java.base \
		> core/Bytecode.java

core/InstrumentedBytecode.java:	core/Bytecode.java.base
	unifdef -x2 -DINSTRUMENTED < core/Bytecode.java.base \
		> core/InstrumentedBytecode.java

# The idea here is that the jar file contains EVERYTHING needed for
# Reduce, and so "java -jar reduce.jar" will launch the system with its
# default image file.

bootstrapreduce.jar:	core/*.java bootstrapreduce_manifest bootstrapreduce.img
	javac -d . core/*.java
	rm -f default.img
	cp bootstrapreduce.img default.img
	-rm -f bootstrapreduce.jar
	jar cmf bootstrapreduce_manifest bootstrapreduce.jar uk default.img
	rm -f default.img

reduce.jar:	core/*.java reduce_manifest reduce.img
	javac -d . core/*.java
	rm -f default.img
	cp reduce.img default.img
	-rm -f reduce.jar
	jar cmf reduce_manifest reduce.jar uk default.img
	rm -f default.img

# minireduce.jar is a cut-down system not containing all the Reduce modules.
# It will thus be smaller (albeit less capable of performing advanced
# operations).

minireduce.jar:	core/*.java reduce_manifest minireduce.img
	javac -d . core/*.java
	rm -f default.img
	cp minireduce.img default.img
	-rm -f minireduce.jar
	jar cmf reduce_manifest minireduce.jar uk default.img
	rm -f default.img

# jlisp.jar is merely the Lisp system without any algebra. If may sometimes
# be easier to work with this smaller system while developing or interfacing?

jlisp.jar:	core/*.java jlisp_manifest jlisp.img
	javac -d . core/*.java
	rm -f default.img
	cp jlisp.img default.img
	-rm -f jlisp.jar
	jar cmf jlisp_manifest jlisp.jar uk default.img
	rm -f default.img


JLISP   = java -jar jlisp.jar
MEM=300M
STK=8M
# FLAGS=-g would switch on a debugging mode that makes all backtraces noisy.
#   Eg "make testall FLAGS=-g"
REDUCE	= java -Xmx$(MEM) -Xms$(MEM) -Xss$(STK) -jar reduce.jar $(FLAGS)


###########################################################################

# Part of redlog does load-time calculation based on the path passed
# here that probably requires it to be an absolute path...

ifeq ($(findstring Windows, "$(OS)"), Windows)
C = $(shell cygpath -m "$(abspath ../csl/cslbase)")
else
C = $(abspath ../csl/cslbase)
endif

# I make the targets here .PHONY so that (eg) "make reduce.img" always
# rebuilds the image even though I have not got careful dependencies set up
# to make it clear why this is necessary.

.PHONY:	jlisp.img
jlisp.img:
	javac -d . core/*.java
	-rm -f jlisp.img
	java uk.co.codemist.jlisp.core.Jlisp -w -v -z -o jlisp.img \
	"$(C)/buildcsl.lsp" -D@cslbase="$(C)" -- jlispimg.log



# .PHONY:	bootstrapreduce.img
# If you want bootstrapreduce.img remade then delete it first...
bootstrapreduce.img:
	javac -d . core/*.java
	-rm -f bootstrapreduce.img
	java uk.co.codemist.jlisp.core.Jlisp -w -v -z -o bootstrapreduce.img \
	"$(C)/buildreduce.lsp" -D@srcdir="$(C)" -D@reduce="$(C)/../.." \
	-- bootstrapreduce.log


.PHONY:	reduce.img
reduce.img:
	javac -d . core/*.java
	-rm -f reduce.img
	java uk.co.codemist.jlisp.core.Reduce -w -v -z -o reduce.img \
	"$(C)/buildreduce.lsp" -D@srcdir="$(C)" -D@reduce="$(C)/../.." \
	-- reduce.log


.PHONY:	minireduce.img
minireduce.img:
	javac -d . core/*.java
	-rm -f minireduce.img
	java uk.co.codemist.jlisp.core.Reduce -w -v -z -o minireduce.img \
	"$(C)/buildreduce.lsp" -Dminireduce -D@srcdir="$(C)" \
	-D@reduce="$(C)/../.." -- reduce.log


.PHONY:	profile
# Please remake bootstrapreduce.jar ahead of this.
profile:
	java -jar bootstrapreduce.jar -w "$(C)/profile.red" \
		-Dcpulimit= -Dconslimit= -Dno_init_file \
		-D@srcdir="$(C)" -D@reduce="$(C)/../.." -L profile.log

specialprofile:
	java -jar bootstrapreduce.jar -w "$(C)/profile.red" \
		-Dtracefluid -Dcpulimit= -Dconslimit= -Dno_init_file \
		-D@srcdir="$(C)" -D@reduce="$(C)/../.." -L profile.log

.PHONY:	smallprofile
# Please remake bootstrapreduce.jar ahead of this.
smallprofile:
	java -jar bootstrapreduce.jar -w profile.red \
		-Dcpulimit= -Dconslimit= -Dno_init_file \
		-D@srcdir="$(C)" -D@reduce="$(C)/../.." -L smallprofile.log

.PHONY:	testall
testall:
	mkdir -p testlogs
	$(REDUCE) -w "$(C)/testall.red" -D@srcdir="$(C)" \
		-D@reduce="$(C)/../.." -- testlogs/testreduce.log
	$(REDUCE) -w "$(C)/checkall.red" -D@srcdir="$(C)" \
		-D@reduce="$(C)/../.." -- testlogs/checkall.log

.PHONY:	test1
# Use:    make test1 which=modulename
test1:
	mkdir -p testlogs
	$(REDUCE) -w -v "$(C)/testall.red" -D@srcdir="$(C)" \
		-D@reduce="$(C)/../.." -Dwhich=$(which) -- testlogs/test$(which).log

.PHONY:	debug1
# Use:    make debug1 which=modulename
#         as test1 but passes the "-g" flag that makes all backtraces noisy.
debug1:
	mkdir -p testlogs
	$(REDUCE) -w -v -g "$(C)/testall.red" -D@srcdir="$(C)" \
		-D@reduce="$(C)/../.." -Dwhich=$(which) -- testlogs/test$(which).log

.PHONY:	checkall
checkall:
	mkdir -p testlogs
	$(REDUCE) -w "$(C)/checkall.red" -D@srcdir="$(C)" \
		-D@reduce="$(C)/../.." -- testlogs/checkall.log

# end of Makefile
