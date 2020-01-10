#! /bin/sh

# Assemble some of the built files & directories  I will want, putting them
# in the current directory where I can see them.

case ${1:-2} in
1 | 3)
  ver=cslwin64
  ;;
2)
  ver=cslwin32
  ;;
*)
  echo argument $1 invalid: should be 1, 2 or 3
  exit 1
  ;;
esac

rm -rf cslbuild
mkdir -p cslbuild

cp $ver/csl/reduce.img cslbuild/reduce.img
cp $ver/csl/bootstrapreduce.img cslbuild/bootstrapreduce.img
cp $ver/csl/csl.img cslbuild/csl.img
cp -r $ver/csl/reduce.fonts cslbuild/reduce.fonts
cp -r $ver/csl/reduce.resources cslbuild/reduce.resources

# stub.c is a stub program that tests the environment it is launched from
# and chains to a suitable version of the code... But I want the stub to
# be able to recover reasonably if not enough cygwin components have been
# installed so I will first sort out just which DLLs the reduce binaries
# rely on.

case `uname -m`
in
i686)
  objdump -p cslcyg32/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll32.c
  x86_64-pc-cygwin-objdump -p cslcyg64/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll64.c
  ;;
x86_64)
  i686-pc-cygwin-objdump -p cslcyg32/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll32.c
  objdump -p cslcyg64/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll64.c
  ;;
*)
  echo Unknown machine `uname -m`
  ;;
esac

if test "x$2" = "xDEBUG"
then
  debugflag="-DDEBUG=1"
else
  debugflag=
fi

i686-w64-mingw32-gcc -DFAT64 -DNAME=red $debugflag -O3 newstub.c \
	--static -lz -o cslbuild/reduce.exe
i686-w64-mingw32-strip cslbuild/reduce.exe

mkdir cslbuild/reduce.resources

# Now I create the real version of a "reduce.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

cp	cslwin32/csl/reduce.com  cslbuild/reduce.resources/redwin32.exe
cp	cslwin64/csl/reduce.com  cslbuild/reduce.resources/redwin64.exe
cp	cslcyg32/csl/reduce.exe  cslbuild/reduce.resources/redcyg32.exe
cp	cslcyg64/csl/reduce.exe  cslbuild/reduce.resources/redcyg64.exe

# Now a rather similar process except that it will be linked as a windows
# not a console binary. As such it will not be useful in a cygwin world,
# but it will be the correct thing to double click on.

i686-w64-mingw32-gcc -DFATWIN -DNAME=wred $debugflag -O3 newstub.c \
	-Wl,--subsystem,windows --static -lz -o cslbuild/winreduce.exe
i686-w64-mingw32-strip cslbuild/winreduce.exe

cp	cslwin32/csl/reduce.exe  cslbuild/reduce.resources/wredwin32.exe
cp	cslwin64/csl/reduce.exe  cslbuild/reduce.resources/wredwin64.exe

# Add the relevant things to this... Observe that actually the only thing
# it has to do that is at all clever is to decide whether it is running
# on a 32 or 64-bit machine. Yes you could make the installer decide whether
# to install a 32 or 64-bit binary, but this way a single binary will be
# good for everybody.

i686-w64-mingw32-gcc -DFAT64 -DNAME=boot $debugflag -O3 newstub.c \
	--static -lz -o cslbuild/bootstrapreduce.exe
i686-w64-mingw32-strip cslbuild/bootstrapreduce.exe

# Also the real version of a "bootstrapreduce.exe"

cp	cslwin32/csl/bootstrapreduce.exe cslbuild/reduce.resources/bootwin32.exe
cp	cslwin64/csl/bootstrapreduce.exe cslbuild/reduce.resources/bootwin64.exe
cp	cslcyg32/csl/bootstrapreduce.exe cslbuild/reduce.resources/bootcyg32.exe
cp	cslcyg64/csl/bootstrapreduce.exe cslbuild/reduce.resources/bootcyg64.exe

i686-w64-mingw32-gcc -DFAT64 -DNAME=csl $debugflag -O3 newstub.c \
	--static -lz -o cslbuild/csl.exe
i686-w64-mingw32-strip cslbuild/csl.exe

# Finally create the real version of a "csl.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

cp	cslwin32/csl/csl.com cslbuild/reduce.resources/cslwin32.exe
cp	cslwin64/csl/csl.com cslbuild/reduce.resources/cslwin64.exe
cp	cslcyg32/csl/csl.exe cslbuild/reduce.resources/cslcyg32.exe
cp	cslcyg64/csl/csl.exe cslbuild/reduce.resources/cslcyg64.exe

# Now a rather similar process except that it will be linked as a windows
# not a console binary. As such it will not be useful in a cygwin world,
# but it will be the correct thing to double click on.

i686-w64-mingw32-gcc -DFATWIN -DNAME=wcsl $debugflag -O3 newstub.c \
	-Wl,--subsystem,windows --static -lz -o cslbuild/wincsl.exe
i686-w64-mingw32-strip cslbuild/wincsl.exe

cp	cslwin32/csl/csl.exe cslbuild/reduce.resources/wcslwin32.exe
cp	cslwin64/csl/csl.exe cslbuild/reduce.resources/wcslwin64.exe

# Inspect the files created.

ls -lhR cslbuild

echo all versions built
