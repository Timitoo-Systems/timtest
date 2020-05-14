      $ set sourceformat"FREE" DefaultByte"00"
       special-names.
           call-convention 8 is static.

       identification division.
       program-id. mftest.

      *>---------------------------------------------------------------*
      *> Timitoo Systems Test for Microfocus Cobol                     *
      *> UNTESTED CODE                                                 *
      *>---------------------------------------------------------------*
       environment division.

       configuration section.

       data division.

       file section.

       working-storage section.
       01  rcOK                   pic s9(8)  value 0.
       01  rcFAILED               pic s9(8)  value 1.
       01  API-HANDLE             usage pointer.
       01  TIM-RET-CODE           pic s9(8)  comp-5       value 0.

       01  TIM-CPI                pic s9(9)  value 31415.
       01  TIM-X                  pic s9(9)  binary       value 2.
       01  TIM-DBL                comp-2  value 0.
       01  TIM-STR                pic x(8)    value nulls.
       01  TIM-TMP                pic s9(9)   value zero.

       procedure division.

*>---- AFPBgnSession --------------------------------------------*
       move rcFAILED to TIM-RET-CODE.
       move null to API-HANDLE.
       
       display 'TIM-RET-CODE (before): ' TIM-RET-CODE upon console end-display.
       display 'API-HANDLE   (before): ' API-HANDLE upon console end-display.
       call static "AFPBgnSession" using
            by reference
              API-HANDLE
            returning
              TIM-RET-CODE
       end-call.

       display 'TIM-RET-CODE (after): ' TIM-RET-CODE upon console end-display.
       display 'API-HANDLE   (after): ' API-HANDLE upon console end-display.

*>---------------------------------------------------------------*
       stop run.
