#! /bin/sh

# Usage:
#   $srcdir/create_bundle.sh name ?icon
#
# Sets up name.app with a proper Info.plist etc for use with MacOSX.
# This copies in an icon, and arg2 (if present) specifies its identity
# as an .icns file in $srcdir

P=$1.app/Contents/Info.plist
IC=${2:-fwin}

SetFile -t APPL $1
mkdir -p $1.app/Contents
mkdir -p $1.app/Contents/MacOS
mkdir -p $1.app/Contents/Resources
mkdir -p $1.app/Contents/Resources/Fonts
cp reduce.wxFonts/* $1.app/Contents/Resources/Fonts
echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" > $P
echo "<!DOCTYPE plist SYSTEM \"file://localhost/System/Library/DTDs/PropertyList.dtd\">" >> $P
echo "<plist version=\"0.9\">" >> $P
echo "<dict>" >> $P
echo "<key>CFBundleInfoDictionaryVersion</key>" >> $P
echo "<string>6.0</string>" >> $P
echo "<key>CFBundleIdentifier</key>" >> $P
echo "<string>com.codemist.reduce.$1</string>" >> $P
echo "<key>CFBundleDevelopmentRegion</key>" >> $P
echo "<string>English</string>" >> $P
echo "<key>CFBundleLocalizations</key>" >> $P
echo "<array> <string>en</string> </array>" >> $P
echo "<key>CFBundleExecutable</key>" >> $P
echo "<string>$1</string>" >> $P
echo "<key>CFBundleIconFile</key>" >> $P
echo "<string>$IC.icns</string>" >> $P
echo "<key>CFBundleName</key>" >> $P
echo "<string>$1</string>" >> $P
echo "<key>CFBundlePackageType</key>" >> $P
echo "<string>APPDVI</string>" >> $P
echo "<key>CFBundleSignature</key>" >> $P
echo "<string>????</string>" >> $P
echo "<key>CFBundleVersion</key>" >> $P
echo "<string>1</string>" >> $P
echo "<key>CFBundleShortVersionString</key>" >> $P
echo "<string>1</string>" >> $P
echo "<key>CFBundleGetInfoString</key>" >> $P
echo "<string>$1 version 1, (C) 2010 Codemist Ltd</string>" >> $P
echo "<key>CFBundleLongVersionString</key>" >> $P
echo "<string>1, (C) 2010 Codemist Ltd</string>" >> $P
echo "<key>NSHumanReadableCopyright</key>" >> $P
echo "<string>Copyright 2010 Codemist Ltd</string>" >> $P
echo "<key>LSRequiresCarbon</key>" >> $P
echo "<true/>" >> $P
echo "<key>CSResourcesFileMapped</key>" >> $P
echo "<true/>" >> $P
echo "<key>ATSApplicationFontsPath</key>" >> $P
echo "<string>Fonts</string>" >> $P
echo "</dict>" >> $P
echo "</plist>" >> $P
echo -n "APPL????" >$1.app/Contents/PkgInfo
ln -f $1 $1.app/Contents/MacOS/$1
cp -f $srcdir/$IC.icns $1.app/Contents/Resources/$IC.icns
# Application frawework set up!
