GnuCobol compile statement
Using precompiled binaries from:

http://www.kiska.net/opencobol/cpp/index.html
http://www.kiska.net/opencobol/cpp/gnucobolcpp-2.2-win-vb-amd64-bin.zip


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