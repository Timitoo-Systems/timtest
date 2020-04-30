
Example that creates a:
shared library (timtest)
executeable (timapp) that call the entry-point of timlib

List of entry-points of timtest
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
cobol example program that calls the entry-points of timtest.

The image 
msstudio.png 
shows how to set a excutable (e.g. cobol)
to that can be used to debug the shared libary when 
called from a cobol application.
The project 'timtest' is set as start application and
the cobol application as the executable 
(configuration is debug).
