GnuCobol COMPILE STATEMENT

Using precompiled binaries from:

http://www.kiska.net/opencobol/cpp/index.html
http://www.kiska.net/opencobol/cpp/gnucobolcpp-2.2-win-vb-amd64-bin.zip

 What is the record/byte size of the following PIC statement
https://sourceforge.net/p/open-cobol/discussion/cobol/thread/f6130534/

Path to cobol copy books can be set with -I option

E:\Qt\cobol\GnuCobolCPP>bin\cobc.exe 
  -o E:\github.com\timtest\buildwin64\x64\RelWithDebInfo\tst_cob1.exe
  -free
  -I include
  -I ..
  -L libs
  -l libcob
  -l E:\github.com\timtest\buildwin64\x64\RelWithDebInfo\timtest
  -fstatic
  -x
  -W
  -conf "E:\Qt\cobol\GnuCobolCPP\config\default.conf"
   E:\github.com\timtest\timcob\tst_timcob.cob