

#include "timtest.h"

#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>

// Expected result returns a int
int TK_CALLING_CONVENTION TEST0(
)
{
    return TIM_CPI;
}

// Expected result returns a int multiplied by x
int TK_CALLING_CONVENTION TEST1(int x
)
{
    int rc = TIM_CPI * x;
    return rc;
}

// Expected result returns TIM_CPI plus x
int TK_CALLING_CONVENTION TEST2(ushort x
)
{
    return TIM_CPI + x;
}

// Returns length of string (single byte codepage assumed)
// in_test must be null terminated
int TK_CALLING_CONVENTION TEST3(const char * in_test
)
{
    size_t rc =  std::strlen(in_test);
    return static_cast<int>(rc);
}

// multpliples nbr by 100
long TK_CALLING_CONVENTION TEST4(double nbr
)
{
    int szlong = sizeof(long);

    double x = (nbr * 100.0);
    long rc = std::lround(x);
    return rc;
}

// ---------------------------------------
// HANDLE tests
// ---------------------------------------

//      returns rcOK if in handle is NULL; 
// else returns rcFAILED
int TK_CALLING_CONVENTION TESTH1(
    TBHANDLE in_Handle
)
{
    if (in_Handle == nullptr) {
        return rcOK;
    }

    return rcFAILED;
}

// dummy handle
static char SOMESTRING[] = { "HELLO" };

char * getDummyHandle() {
    return &SOMESTRING[0];
}

// Pass by reference test 
// returns always 0
// in_Handle is set to a valid memory address
int TK_CALLING_CONVENTION TESTH2(
    TBHANDLE * in_Handle
)
{
    (*in_Handle) = getDummyHandle();
    return rcOK;
}



// Returns rcOK of the handle has the same value set by 
// TESTH2
// else the function returns rcFAILED
int TK_CALLING_CONVENTION TESTH3(
    TBHANDLE in_Handle
)
{
    if (in_Handle == getDummyHandle()) {
        return rcOK;
    }

    return rcFAILED;
}


// Creates a file and writes a dummy text
int TK_CALLING_CONVENTION TESTF1(
)
{
    // Create and open a text file
    std::ofstream aFile;
    aFile.open(TIM_FILENAME, std::ios::out | std::ios::trunc);
    if (aFile.good()) {
        // Write to the file
        aFile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit\n";

        // Close the file
        aFile.close();
        return rcOK;
    }

    return rcFAILED;
}

// Write line to file
int TK_CALLING_CONVENTION TESTF2(char * line
)
{
    if (std::strlen(line) == 0) {
        return rcFAILED;
    }

    // Create and open a text file
    std::ofstream aFile;
    aFile.open(TIM_FILENAME, std::ios::out | std::ios::trunc);
    if (aFile.good()) {
        // Write to the file
        aFile << line;
        aFile << "\n";

        // Close the file
        aFile.close();
        return rcOK;
    }

    return rcFAILED;
}