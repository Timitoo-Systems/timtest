## Project 'timtest'
Simple DLL with __cdecl Calling Conventions.


## Project 'timapp'
An executable that is dynamically linked with 'timtest'
It includes catch.hpp for unit test call.

### CMAKE commands to create VS Studio Project files
 `cd project_dir`<br>
 `mkdir build`<br>
 `cd build`<br>
 `cmake -G  "Visual Studio 14 2015 Win64" ..`<br>
[Other cmake generator names](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)

### Link Collection

### Microsoft
A 64 bit DLL is always defined with __cdecl and not __stdcall. The Microsoft article below shows that information that a __stdcall is accepted, but ignored by the compiler on x64. (The __stdcall calling convention is used to call Win32 API functions
only!)

[Microsoft stdcall](https://docs.microsoft.com/en-us/cpp/cpp/stdcall?view=vs-2019)


#### Microfocus

[Linking from the Command Line](https://www.microfocus.com/documentation/visual-cobol/vc40pu1/VS2017/GUID-374EE44A-4500-4673-9F1B-E7BC62E0CBD5.html)

[Microfocus - Header-to-COPY Utility](https://www.microfocus.com/documentation/visual-cobol/vc50pu3/DevHub/BKPRPRH2CP.html)

[Microfocus - Mixed Language Programming](https://www.microfocus.com/documentation/visual-cobol/VC40/EclWin/GUID-A39ABE98-B22F-4115-BB6C-0CE9A9444A12.html)

[Microfocus - Call Conventions for Interfacing with Mixed Languages](https://www.microfocus.com/documentation/visual-cobol/vc50pu3/DevHub/HHMXCHMIXL19.html)

[Microfocus - CALL Statement](https://www.microfocus.com/documentation/visual-cobol/vc40pu2/DevHub/HRLHLHPDF804.html)

#### GnuCOBOL Documentation

[GnuCobol Dokumentation](https://devdocs.io/gnu_cobol/)
