## Project 'timtest'
Simple DLL with __cdecl Calling Conventions.


## Project 'timapp'
An executable that is dynamically linked with 'timtest'
It includes catch.hpp for unit test call.

### CMake commands to create VS Studio Project files
 `cd project_dir`<br>
 `mkdir build`<br>
 `cd build`<br>
 `cmake -G  "Visual Studio 14 2015 Win64" ..`<br>
[Other cmake generator names](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)

### Link Collection

#### Microsoft
A 64 bit DLL is always defined with __cdecl and not __stdcall. The Microsoft article below shows that __stdcall is accepted, but ignored by the compiler on x64. (The __stdcall calling convention is used to call Win32 API functions
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

#### Mickael Andrieu - awesome-cobol

[awesome-cobol](https://github.com/mickaelandrieu/awesome-cobol)

#### Some C++ handle fun
```cpp
    // TBHANDLE (which is a typedef of a void *) version 
    (*outp_sessHandle) = nullptr;
    (*outp_sessHandle) = (TBHANDLE)0xDEADBEEFDEADBEEF;
    printf("%p\n", *outp_sessHandle);

    // bad style - sets only the first 4 bytes (works on 32 bit systems only)
    (*outp_sessHandle) = nullptr;
    *(int*)outp_sessHandle = 0xDEADBEEFDEADBEEF;
    printf("%p\n", *outp_sessHandle);

    // char * version
    (*outp_sessHandle) = nullptr;
    *(char**)(outp_sessHandle) = reinterpret_cast<char *>(0xDEADBEEFDEADBEEF);
    printf("%p\n", *outp_sessHandle);

    // uint64_t* version
    (*outp_sessHandle) = nullptr;
    *(uint64_t*)outp_sessHandle = 0xDEADBEEFDEADBEEF;
    printf("%p\n", *outp_sessHandle);

    // void* version
    (*outp_sessHandle) = nullptr;
    (*outp_sessHandle) = reinterpret_cast<void *>(0xDEADBEEFDEADBEEF);
    printf("%p\n", *outp_sessHandle);

    // memcpy version
    (*outp_sessHandle) = nullptr;
    TBHANDLE handle = (TBHANDLE)0xDEADBEEFDEADBEEF;
    std::memcpy(outp_sessHandle, &handle, sizeof(TBHANDLE));
    printf("%p\n", *outp_sessHandle);
```
