#! /bin/bash 

if test $# = 3; then
    root=$1
    date=$2
    rootedp=$3
else
    echo "rltest1.sh root date context/service/test.tst"
    exit 1
fi

timings=$root/$date/timings
trunk=$root/$date/trunk
regressions=$trunk/packages/redlog/regressions
d=$(dirname $rootedp)
p=$(basename $rootedp .tst)

mc="$(uname -n) running $(uname -srm)"

# Always use the external time command, even if the shell has a time builtin. Do
# not collect times if no external time command can be found.
timecmd=`type -P time`
if test "x$timecmd" != "x"
then
    timecmd="$timecmd -p"
fi

f="$regressions/$d/$p.tst"

# The idea behind applying a ulimit here is to avoid trouble when and if a test
# script loops.
ulimit -c 1800

# CSL test
mkdir -p $timings/csl-times/$d

howlong=$timings/csl-times/$d/$p.howlong.tmp

$timecmd sh -c "$trunk/bin/redcsl -w > $timings/csl-times/$d/$p.rlg.tmp" <<XXX 2>$howlong
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
lisp (testdirectory:="$d");
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN ON $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat $howlong >> $timings/csl-times/$d/$p.rlg.tmp

sed -e "/^Tested on /,//d" <$regressions/$d/$p.rlg |
    sed -e '/^Total time taken:/d; /^Number of garbage/d' \
	-e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
	-e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
	-e '/^Request to set constant bitsperword/d' \
	-e '/^time to formulate/d; /\*\*\* turned off switch/d' \
	>$timings/csl-times/$d/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
    -e "/OMIT/,/TIMO/d" <$timings/csl-times/$d/$p.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e '/^Total time taken:/d; /^Number of garbage/d' \
	-e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
	-e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
	-e '/^Request to set constant bitsperword/d' \
	-e '/^time to formulate/d; /\*\*\* turned off switch/d' \
	>$timings/csl-times/$d/$p.rlg
diff -B -w $timings/csl-times/$d/$p.rlg.orig $timings/csl-times/$d/$p.rlg \
     >$timings/csl-times/$d/$p.rlg.diff

if test -s $timings/csl-times/$d/$p.rlg.diff; then
    cslresult="failed"
else
    cslresult="ok"
    rm -f $timings/csl-times/$d/$p.rlg.diff $timings/csl-times/$d/$p.rlg.orig
fi

echo "Tested on $mc CSL" > $timings/csl-times/$d/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <$timings/csl-times/$d/$p.rlg.tmp | \
    sed -e '/^1: *$/d;' >>$timings/csl-times/$d/$p.time
rm -f $timings/csl-times/$d/$p.rlg.tmp

rm -f $howlong
# end of CSL test

# PSL test
mkdir -p $timings/psl-times/$d

howlong=$timings/psl-times/$d/$p.howlong.tmp

$timecmd sh -c "$trunk/bin/redpsl > $timings/psl-times/$d/$p.rlg.tmp" <<XXX 2>$howlong
off int;
symbolic linelength 80;
symbolic(!*redefmsg := nil);
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
lisp (testdirectory:="$d");
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN on $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat $howlong >> $timings/psl-times/$d/$p.rlg.tmp
#printf "PSL..."
sed -e "/^Tested on /,//d" <$regressions/$d/$p.rlg | \
    sed -e '/^Total time taken:/d; /^Number of garbage/d' \
	-e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
	-e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
	-e '/^Request to set constant bitsperword/d' \
	-e '/^time to formulate/d; /\*\*\* turned off switch/d' \
	>$timings/psl-times/$d/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
    -e "/OMIT/,/TIMO/d" <$timings/psl-times/$d/$p.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e '/^Total time taken:/d; /^Number of garbage/d' \
	-e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
	-e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
	-e '/^Request to set constant bitsperword/d' \
	-e '/^time to formulate/d; /\*\*\* turned off switch/d' \
	>$timings/psl-times/$d/$p.rlg
diff -B -w $timings/psl-times/$d/$p.rlg.orig $timings/psl-times/$d/$p.rlg >$timings/psl-times/$d/$p.rlg.diff

if test -s $timings/psl-times/$d/$p.rlg.diff; then
    pslresult="failed"
else
    pslresult="ok"
    rm -f $timings/psl-times/$d/$p.rlg.diff $timings/psl-times/$d/$p.rlg.orig
fi

echo "Tested on $mc PSL" > $timings/psl-times/$d/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <$timings/psl-times/$d/$p.rlg.tmp | \
    sed -e '/^1: /d;' >>$timings/psl-times/$d/$p.time
rm -f $timings/psl-times/$d/$p.rlg.tmp

rm -f $howlong
# end of PSL test

csltime=$(grep ^Time $timings/csl-times/$d/$p.time | awk '{print $4}')
psltime=$(grep ^Time $timings/psl-times/$d/$p.time | awk '{print $4}')
let ratio=100*$csltime/$psltime
ratioresult="${ratio}%"

mkdir -p $timings/csl-psl-times-comparison/$d
diff -B -w $timings/csl-times/$d/$p.rlg $timings/psl-times/$d/$p.rlg \
     > $timings/csl-psl-times-comparison/$d/$p.rlg.diff
if test -s $timings/csl-psl-times-comparison/$d/$p.rlg.diff; then
    resultlispdiff=", CSL and PSL test logs differ"
else
    resultlispdiff=""
    rm -f $timings/csl-psl-times-comparison/$d/$p.rlg.diff
fi

if [ "$cslresult" = failed ] || [ "$pslresult" = failed ]; then
    printf "test %-35s CSL %s, PSL %s\n" "$d/$p:" "$cslresult" "$pslresult"
else
    printf "test %-35s CSL %s, PSL %s, CSL/PSL = %4s %s\n" "$d/$p:" \
	   "$cslresult" "$pslresult" "$ratioresult" "$resultlispdiff"
fi