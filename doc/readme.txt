
Example that creates a:
shared library (timtest)
and a executable (timapp) that calls the entry-point of timlib

List of entry-points of 'timtest' and defined in the file
'timtest.h'.

TEST0
TEST1
TEST2
TEST3
TEST4
TESTF1
TESTF2
TESTH1
TESTH2
TESTH3

In folder timcob:
tst_timcob.cob
Cobol example program that calls the entry-points of timtest.

The screenshot 
'msstudio.png'
shows how to set a excutable (e.g. cobol)
to that can be used to debug the shared libary when 
called from a cobol application.
The project 'timtest' is set as start application and
the cobol application as the executable 
(configuration is debug).

The screenshot:
'dbg_rel_studio.png'
shows the default CMake configurations for VS Studio 
Projects. The config 'RelWithDgbInfo' creates a
release version with debug symbols (*.pdb files).

--
The expected output of the Cobol application
.\timtest\buildwin64\x64\Debug>tst_cob1.exe

--> TEST0
Returned value=+000031415
Expected value=+000031415

--> TEST1
Returned value=+000062830
Expected value=62830

--> TEST3
Returned value=+000000005
Expected value=5

--> TEST4
Returned value=+000012345
Expected value=12345

Returned value=+000000314
Expected value=314

--> TESTH1
Returned value=+000000000
Expected value=+000000000

Returned value=+000000001
Expected value=+000000001

--> TESTH2
API-HANDLE=0x000007fef4d3a000
Returned value=+000000000
Expected value=+000000000

--> TESTH3
Returned value=+000000000
Expected value=+000000000

--> TESTF1
Returned value=+000000000
Expected value=+000000000

--> TESTF2
Returned value=+000000000
Expected value=+000000000
