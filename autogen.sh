#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# when the machine being used does not have the same versions of autoconf
# and automake as the machine used by the developer.

#
# Usage:
#     autogen.sh [options as for the configure script]
#
# If no arguments are passed the script will rebuild everything. If
# --with-csl or --with-psl is specified only that section of the tree
# will be processed. In the CSL case "--with-wx", "--withoug-gui",
# and perhaps other sub-options will be checked to try to save reworking
# directories that would not be used.
#

# I used to have an option (enabled by default) to do the autoconf-ing
# concurrently in all relevant source directories. However libtoolize
# seems to be able to be upset if you use it at the same time in several
# directories where one is contained within the other, so despite that
# having been a good time-saver I have removed it.

# I want this script to be one I can launch from anywhere.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

save=`pwd`
cd $here

# On the Mac with macports the command needed here is glibtoolize rather than
# libtoolize.

if which libtoolize > /dev/null
then
  LIBTOOLIZE=libtoolize
else
  LIBTOOLIZE=glibtoolize
fi

if ! which autoconf > /dev/null || \
   ! which automake > /dev/null || \
   ! which $LIBTOOLIZE > /dev/null
then
  printf "You need to have autoconf, automake and $LIBTOOLIZE installed.\n"
  printf "I seem not to be able to find them.\n"
  printf "Note that on some Linux systems it is in a package called libtool-bin\n"
  printf "Stopping...\n"
  exit 1
fi

# Here I list all the directories that might be relevant. Note that in
# some circumstances some may not be present!

# There are some directories that I have chosen not to process here:
#  ./csl/foxtests
#  ./generic/libreduce/src
# taking a view that people who wish to build those already have to take
# special steps... and so they can run autoconf etc for themselves if it
# is needed. If I did so here it would slow things down for everybody in
# a way I would view as unhelpful. And this is already slow enough!

printf "autogen.sh arguments: $*\n"

if test $# -eq 0
then
  a="--with-psl --with-csl --with-fox"
else
  a="$*"
fi


# I will re-process the top level first before any lower level
rm -rf ltmain.sh config.cache autom4te.cache m4/libtool.m4 \
       m4/lt-obsolete.m4 m4/ltoptions.m4 m4/ltsugar.m4 m4/ltversion.m4
mkdir -p m4
$LIBTOOLIZE --force --copy
aclocal --force
autoreconf -f -i -v

# Here are the directories that I will always process...

L="./scripts ./libraries/crlibm ./libraries/libedit-20140620-3.1 \
   ./generic/newfront"

case $a in
*--without-psl* | *with-psl=no*)
  ;;
*--with-psl*)
  L="$L ./psl"
  ;;
*)
  ;;
esac

# I want "--with-wx" to imply "--without-fox". At present I do not
# feel the need for the converse because this script does not try to
# autoreconf wxWidgets anyway.
case $a in
*--with-wx=no* | "--without-wx*")
  ;;
*--with-wx*)
  a="$a --without-fox"
  ;;
*)
  ;;
esac

case $a in
*--without-csl* | *with-csl=no*)
  ;;
*--with-csl*)
  L="$L ./csl ./csl/cslbase ./libraries/SoftFloat-3a/source ./libraries/libffi"
  case $a in
  *--without-fox* | *with-fox=no* | \
  *--without-gui* | *with-gui=no*)
    ;;
  *)
    L="$L ./csl/fox"
    ;;
  esac
  ;;
*)
  ;;
esac

printf "@@@@ About to process $L @@@@\n"

# At least as an experiment I will make the use of libtoolize run
# sequentially rather than processing directories in parallel.

s="$sequential"
sequential=no

for d in $L
do
  printf "\nlibtoolize in directory '%s'\n" $d
  if test -d $d
  then
    cd $d
    printf "$LIBTOOLIZE --force --copy; aclocal --force\n"
    mkdir -p m4
    rm -rf ltmain.sh config.cache autom4te.cache m4/libtool.m4 \
           m4/lt-obsolete.m4 m4/ltoptions.m4 m4/ltsugar.m4 m4/ltversion.m4
    $LIBTOOLIZE --force --copy
    aclocal --force
    printf "autoreconf -f -i -v\n"
    autoreconf -f -i -v
    cd $here
  fi
done

scripts/resetall.sh

cd $save
printf "\nAll autoconf files now up to date\n"

exit 0

# end of autogen.sh
