### Microfocus 
COBOL and 'C' 64bit, mixed language application interface example.

The 'C' program must be compiled first to provide an import library
needed to complete the COBOL program.

#### How to resolve 'Call' statements at link time
By default CALL uses 'dynamic loading'. The special name call-convention can be used to tweak the linker tool chain to include object code. The MF documentation for passing parameters, and other details of the interface between two programs can be found here:

[Call Conventions for Interfacing with Mixed Languages](https://www.microfocus.com/documentation/visual-cobol/vc50pu3/DevHub/HHMXCHMIXL19.html)

  * Bit 3
    - 0 Normal linking behavior 
    - 1  Call is resolved at link time

In the special-names section a call convention needs to be added:
```
special-names.
  call-convention 8 is static.
```

Now the special name 'static' can be used for calls which are implemented in a shared object.
Example:
```
  call static "AFPBgnSession" ....
```

With the call-convention 8 the cbllink command must not be able to resolve
the calls without an import library. The statement below must generate 
unresolved 'call' errors.
```
  cbllink -v -k -l -d -o tst_mfcob.dll tst_mfcob.cbl
```
On Windows an import library must be used to resolve calls at link time.
```
  cbllink -v -k -l -d -o tst_mfcob.dll tst_mfcob.cbl timtest.lib
```

(For brevity the path information has been omitted.)

Here you can find a screenshot showing the dependency of the compiled application (GNUCobol version).

[dependencywalker_tst_cob1.png](https://github.com/Timitoo-Systems/timtest/tree/master/doc/dependencywalker_tst_cob1.png)

Depending on the CASE generator directive also Bit 9 might be relevant.

  * Bit 9
    - 0  The case of the program or call name is disregarded  
    - 1  The case of the program or call name is significant

### GnuCobol COMPILE STATEMENT

Using precompiled binaries from:

[www.kiska.net/opencobol/cpp/index.html](http://www.kiska.net/opencobol/cpp/index.html)
[gnucobolcpp](http://www.kiska.net/opencobol/cpp/gnucobolcpp-2.2-win-vb-amd64-bin.zip)

What is the record/byte size of the following PIC statement:
[discussion/cobol](https://sourceforge.net/p/open-cobol/discussion/cobol/thread/f6130534/)

For 64 bit use vcvars64.bat

```
cd GnuCobol
bin\cobc.exe
```

Path to cobol copy books can be set with -I option
```
bin\cobc.exe 
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
   E:\github.com\timtest\cobol\tst_timcob.cbl
```

With debug support:<br> 
 -g                 enable C compiler debug / stack check / trace<br> 
 -d, -debug         enable all run-time error checking<br> 
  -ftraceall        generate trace code<br> 
                    executed SECTION/PARAGRAPH/STATEMENTS<br> 
                    turned on by -debug<br> 
 
```
cobc -x -g -debug -ftraceall
```

[GNUCobol](https://devdocs.io/gnu_cobol/index#CALL)<br>

