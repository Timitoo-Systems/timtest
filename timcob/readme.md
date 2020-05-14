### Microfocus 
COBOL and 'C' 64bit, mixed language application interface example.

The 'C' program must be compiled first to provide an import library
needed to complete the COBOL program.

#### How to resolve 'Call' statements at link time
By default Cobol compiler will not resolve calls to native code at link time. The MF documentation for passing parameters, and other details of the interface between the two programs.
can be found here:

[Call Conventions for Interfacing with Mixed Languages](https://www.microfocus.com/documentation/visual-cobol/vc50pu3/DevHub/HHMXCHMIXL19.html)

  * Bit 3
    - 0 Normal linking behavior 
    - 1  Call is resolved at link time

In the special-names section a call convention needs to be added:
```
special-names.
  call-convention 8 is static.
```

Now the special name 'static' can be used for calls with are implemented in a shared object.
Example:
```
    call static "AFPBgnSession" ....
```

With the call-convention 8 the cbllink command must not be able to resolve
the calls without an import library. The statement below must generate 
unresolved 'call' errors.
```
    cbllink -v -k -l -d -o tst_mfcob.dll tst_mfcob.cob
```
On Windows an import library must be used resolve calls at link time
```
    cbllink -v -k -l -d -o tst_mfcob.dll tst_mfcob.cob timtest.lib
```

(For brevity the path information has been omitted.)

### GnuCobol COMPILE STATEMENT

Using precompiled binaries from:

http://www.kiska.net/opencobol/cpp/index.html
http://www.kiska.net/opencobol/cpp/gnucobolcpp-2.2-win-vb-amd64-bin.zip

 What is the record/byte size of the following PIC statement
https://sourceforge.net/p/open-cobol/discussion/cobol/thread/f6130534/

Path to cobol copy books can be set with -I option

.\cobc.exe 
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
