identification division.
program-id. timapp.

*>---------------------------------------------------------------*
*> Timitoo Systems test for Cobol Calls                          *
*> Tested with GNUCOBOL 2.2 (64bit)                              *
*>---------------------------------------------------------------*

data division.

file section.

working-storage section.

01  rcOK                   PIC S9(9)  value 0.
01  rcFAILED               PIC S9(9)  value 1.
01  TIM-CPI                PIC S9(9)  value 31415.
01  API-HANDLE             USAGE POINTER.
01  TIM-RET-CODE           PIC S9(9)         value 0.
01  TIM-X                  PIC S9(8)   binary value 2.
01  TIM-DBL                COMP-2  value 0.
01  TIM-STR                PIC X(8)    value nulls.
 
procedure division.

*>---TEST0------------------------------------------------------------*
 call "TEST0"
      RETURNING
        TIM-RET-CODE
 end-call.
 
 display '--> TEST0' end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' TIM-CPI end-display
 display ' ' end-display

 
*>---TEST1------------------------------------------------------------*
 move 0 to TIM-RET-CODE.
 
 call "TEST1" using
      value
        TIM-X
      returning
        TIM-RET-CODE
 end-call.

 display '--> TEST1' end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' 62830 end-display
 display ' ' end-display


*>---TEST3------------------------------------------------------------*
 move 0 to TIM-RET-CODE.
 move z'lorem' to TIM-STR.
 
 call "TEST3" using
      by content
        TIM-STR
      returning
        TIM-RET-CODE
 end-call.

 display '--> TEST3' end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' 5 end-display
 display ' ' end-display

 
*>---TEST4------------------------------------------------------------*
 move 0 to TIM-RET-CODE.
 move 123.45 to TIM-DBL.
 
 call "TEST4" using
      value
        TIM-DBL
      returning
        TIM-RET-CODE
 end-call.
 
 display '--> TEST4' end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' 12345 end-display
 display ' ' end-display

 move 3.1415 to TIM-DBL.
 call "TEST4" using
      value
        TIM-DBL
      returning
        TIM-RET-CODE
 end-call.

 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' 314 end-display
 display ' ' end-display

 
*>---TESTH1------------------------------------------------------------*
move null to API-HANDLE.

 call "TESTH1" using
      by value
        API-HANDLE
      returning
        TIM-RET-CODE
 end-call.

 display '--> TESTH1' end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' rcOK end-display
 display ' ' end-display
 
set API-HANDLE up by 5.

 call "TESTH1" using
      by value
        API-HANDLE
      returning
        TIM-RET-CODE
 end-call.


 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' rcFAILED end-display
 display ' ' end-display

 
*>---TESTH2------------------------------------------------------------*
move null to API-HANDLE.

 call "TESTH2" using
      by reference
        API-HANDLE
      returning
        TIM-RET-CODE
 end-call.

 display '--> TESTH2' end-display
 display 'API-HANDLE=' API-HANDLE end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' rcOK end-display
 display ' ' end-display


*>---TESTH3------------------------------------------------------------*
move null to API-HANDLE.

*> get handle
 call "TESTH2" using
      by reference
        API-HANDLE
      returning
        TIM-RET-CODE
 end-call.

 call "TESTH3" using
     by value
       API-HANDLE
     returning
       TIM-RET-CODE
 end-call.

 display '--> TESTH3' end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' rcOK end-display
 display ' ' end-display
 

*>---TESTF1------------------------------------------------------------*

 call "TESTF1"
      returning
        TIM-RET-CODE
 end-call.

 display '--> TESTF1' end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' rcOK end-display
 display ' ' end-display

*>---TESTF1------------------------------------------------------------*

 move z'lorem' to TIM-STR.
 call "TESTF2" using
      by content
        TIM-STR
      returning
        TIM-RET-CODE
 end-call.

 display '--> TESTF2' end-display
 display 'Returned value=' TIM-RET-CODE end-display
 display 'Expected value=' rcOK end-display
 display ' ' end-display

 
*>---------------------------------------------------------------*
 stop run.

