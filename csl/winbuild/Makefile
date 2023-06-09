#
# multi-target packed executable for Reduce
#

.PHONY:	all all32 all64 clean fullclean

all:
	case `uname` in \
	*WOW*) $(MAKE) all64; ;; \
	*) $(MAKE) all32; ;; \
	esac

# The clean target does not
clean:
	rm -rf *.exe *.img reduce.fonts *.log

fullclean:	clean
	rm -rf cyg32 cyg64 win32 win64

all32:	reduce32.exe winreduce32.exe reduce.img reduce.fonts
	ls -lhd *reduce*.exe reduce.img reduce.fonts
	echo all 32-bit versions built

all64:	reduce32.exe reduce.exe winreduce32.exe winreduce.exe reduce.img reduce.fonts
	ls -lhd *reduce*.exe reduce.img reduce.fonts
	echo all 64 and 32-bit versions built

# Note that it is vital that when resources are added here that they are
# added in the order shown.

WIN32=win32/csl/reduce.com
WIN64=win64/csl/reduce.com
CYG32=cyg32/csl/reduce.exe
CYG64=cyg64/csl/reduce.exe
WWIN32=win32/csl/reduce.exe
WWIN64=win64/csl/reduce.exe

# Reduce for 32-bit machines, suitable for Windowed or console use
# I may end up believeing that there is no point in having this one
# in that just reduce64.exe may serve well for everybody
#
reduce32.exe:	addresources.exe stub.c cygwin32-isatty.exe $(WIN32) $(CYG32)
	i686-w64-mingw32-gcc -DFAT32 -O2 stub.c --static -lz -o reduce32.exe
	i686-w64-mingw32-strip reduce32.exe
	./addresources reduce32.exe cygwin32-isatty.exe $(WIN32) $(CYG32)

# Reduce for 32 or 64-bit machines, Windowed or console use. ie
# as general as I can make it!
#
reduce.exe:	addresources.exe stub.c cygwin32-isatty.exe \
		cygwin64-isatty.exe $(WIN32) $(WIN64) $(CYG32) $(CYG64)
	i686-w64-mingw32-gcc -DFAT64 -O2 stub.c --static -lz -o reduce.exe
	i686-w64-mingw32-strip reduce.exe
	./addresources reduce.exe cygwin32-isatty.exe cygwin64-isatty.exe \
		$(WIN32) $(WIN64) $(CYG32) $(CYG64)

# Reduce for 32 or 64 bit machines for launching by double-clicking.
# This differs from reduce.exe in that it will not create a console if
# double-clicked, and will detach from the console if you try launching
# it from there. It does not support cygwin or X11.
#
winreduce.exe:	addresources.exe stub.c $(WWIN32) $(WWIN64)
	i686-w64-mingw32-gcc -DFATWIN -O2 stub.c \
		-Wl,--subsystem,windows --static -lz -o winreduce.exe
	i686-w64-mingw32-strip winreduce.exe
	./addresources winreduce.exe $(WWIN32) $(WWIN64)

winreduce32.exe:	$(WWIN32)
	cp $(WWIN32) winreduce32.exe

reduce.img:	win32/csl/reduce.img
	case `uname` in \
	 *WOW*) cp win64/csl/reduce.img .; ;; \
	 *) cp win32/csl/reduce.img .; ;; \
	esac

reduce.fonts:	win32/csl/reduce.fonts
	cp -r win32/csl/reduce.fonts .

addresources.exe:	addresources.c
	gcc addresources.c -lz -oaddresources.exe

cygwin32-isatty.exe:	cygwin-isatty.c
	gcc -O2 cygwin-isatty.c -o cygwin32-isatty.exe
	strip cygwin32-isatty.exe

cygwin64-isatty.exe:	cygwin-isatty.c
	x86_64-pc-cygwin-gcc -O2 cygwin-isatty.c -o cygwin64-isatty.exe
	x86_64-pc-cygwin-strip cygwin64-isatty.exe

# End of Makefile

