## Process this file with automake to produce Makefile.in

# For non-gcc compilers, change the options to "no-dependencies"
AUTOMAKE_OPTIONS = foreign dist-zip

# ACN avoids the tests, shutterbug etc directories here because they are
# GPL not LGPL and so building any of them would lead to a risk of
# accidental distribution of binaries and hence GPL obligations regarding
# in particular need to be ready to ship source to anybody on demand. I
# intends to keep all source code used available to everybody (eg on the
# repository at sourceforge where this lives) but also as much as possible
# wants to keep licensing of things used by Reduce as close to the BSD
# ideal of flexibility and freedom as possible: LGPL 2.1 meets that at
# a level that I am happy with but GPL (and version) and LGPL 3 do not if
# only because anybody taking them seriously has a seriously long document
# that they must read and comprehend the implications of.

#SUBDIRS    = utils include src chart doc tests shutterbug adie pathfinder calculator windows
SUBDIRS    = utils include src

EXTRA_DIST = ADDITIONS AUTHORS INSTALL LICENSE LICENSE_ADDENDUM TRACING README fox.lsm index.html aclocal.m4

ACLOCAL_AMFLAGS = -I m4

bin_SCRIPTS = fox-config

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = fox.pc

CLEANFILES = fox.tar.gz

snapshot: dist-all
	cp $(distdir).tar.gz /net/linkyftp/pub/fox-snapshot.tar.gz
	cp $(distdir).zip /net/linkyftp/pub/fox-snapshot.zip



web: distdir
	cd $(distdir)/doc && doxygen doxygen.cfg
	cp -r $(distdir)/doc/* /net/linky/mnt/html

drop: dist-all
	cp $(distdir).tar.gz /net/webby/ftp/pub
	cp $(distdir).zip /net/webby/ftp/pub

# The following is a dummy target that helps a higher level build-system
fox:
	echo "building fox"
