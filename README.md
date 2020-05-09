# Project 'timtest'
Simple DLL with __cdecl Calling Conventions.


# Project 'timapp'
An executable that is dynamically linked with 'timtest'
It includes catch.hpp for unit test call.




A 64 bit DLL is always defined with __cdecl and not __stdcall. The Microsoft article below shows that information that a __stdcall is accepted, but is ignored when it is 64 bit.

https://docs.microsoft.com/en-us/cpp/cpp/stdcall?view=vs-2019
