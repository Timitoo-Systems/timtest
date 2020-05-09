

#include "timtest.h"

#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>

// dummy handle
static char SOMESTRING[] = { "HELLO" };

char * getDummyHandle() {
    return &SOMESTRING[0];
}

/*
Dummy function
returns 0 if handle == nullptr
returns 1 if handle != nullptr
*/
int TK_CALLING_CONVENTION AFPTest(
    TBHANDLE handle
)
{
    if (handle == nullptr) {
        return 0;
    }
    return 1;
}

/*
*/
int TK_CALLING_CONVENTION AFPBgnSession(
    TBHANDLE* outp_sessHandle
)
{
    (*outp_sessHandle) = getDummyHandle();
    return rcOK;
}

/*
*/
int TK_CALLING_CONVENTION AFPEndSession(
    TBHANDLE* inp_sessHandle
)
{
    return rcOK;
}



int TK_CALLING_CONVENTION AFPBgnDoc(
    TBHANDLE in_sessHandle,
    char* in_docName,
    char* in_comment,
    OUTTYPE in_outputtype,
    char* in_outputfilename,
    byte* in_outputbuffer,
    TBHANDLE* outp_docHandle
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPEndDoc(
    TBHANDLE* inp_docHandle
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION  AFPBgnPage(
    TBHANDLE in_docHandle,
    char* in_pageName,
    TBHANDLE* outp_pageHandle
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION AFPEndPage(
    TBHANDLE* inp_pageHandle
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION AFPBgnShade(
    TBHANDLE in_pageHandle,
    ushort in_shade_width,
    ushort in_shade_percent,
    TBHANDLE* outp_shadeHandle
)
{
    return rcOK;
}

int AFPEndShade(
    TBHANDLE in_pageHandle,
    TBHANDLE* inp_shadeHandle
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPDefineFontByAttr(
    char* in_codePage,
    char* in_descriptiveName,
    ushort in_pointSize,
    FDSWeights in_weight,
    FDSWidths in_width,
    FontStyle in_style,
    FontID* out_fontID
)
{
    return rcOK;
}

int TK_FUNCTION AFPDefineFontByName(
    char* in_codePage,
    char* in_characterSet,
    char* in_codedFont,
    FontID out_fontID
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION AFPDeletePage(
    TBHANDLE* inp_pageHandle
)
{
    return rcOK;
}


int TK_FUNCTION AFPBgnGroup(
    TBHANDLE in_docHandle,
    char* in_groupName
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPEndGroup(
    TBHANDLE in_docHandle
)
{
    return rcOK;
}


/*
*/
int TK_CALLING_CONVENTION AFPInclPSeg(
    TBHANDLE in_pageHandle,
    char* in_pageSegmentName,
    boolean in_reuseOption
)
{
    return rcOK;
}

/*
*/
int TK_CALLING_CONVENTION AFPMeasureString(
    FontID in_fontID,
    char* in_inputString,
    long* outp_stringWidth,
    ushort in_vinc,
    ushort in_cadj,
    int* outp_varspaces,
    int* outp_icspaces
)
{
    return rcOK;
}

/*
*/
int TK_CALLING_CONVENTION AFPNextLine(
    TBHANDLE in_pageHandle
)
{
    return rcOK;
}


/*
*/
int TK_CALLING_CONVENTION  AFPPutTag(
    TBHANDLE in_currentHandle,
    char* in_attrName,
    char* in_attrValue
)
{
    return rcOK;
}

/*
*/
int TK_CALLING_CONVENTION AFPQuery(
    TBHANDLE in_pageHandle,
    long* outp_xCoordinate,
    long* outp_yCoordinate,
    MODCAColors* outp_color,
    FontID* outp_fontID,
    long* outp_fontlinesp
)
{
    return rcOK;
}


/*
*/
int TK_CALLING_CONVENTION AFPSetFont(
    TBHANDLE in_pageHandle,
    FontID in_font_id
)
{
    return rcOK;
}

/*
*/
int TK_CALLING_CONVENTION AFPSetMediaSize(
    TBHANDLE in_docHandle,
    long in_pageWidth,
    long in_pageLength
)
{
    return rcOK;
}

/*
*/
int TK_CALLING_CONVENTION AFPSetPos(
    TBHANDLE in_pageHandle,
    short in_inlinePosition,
    POSTYPE in_inlineReference,
    short in_baselinePosition,
    POSTYPE in_baselineReference
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPHMoveTo(
    TBHANDLE in_pageHandle,
    ushort in_inlinePosition
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPVMoveTo(
    TBHANDLE in_pageHandle,
    short in_baselinePosition
)
{
    return rcOK;
}



int TK_CALLING_CONVENTION AFPHMove(
    TBHANDLE in_pageHandle,
    short in_inlinePosition
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION AFPVMove(
    TBHANDLE in_pageHandle,
    short in_baselinePosition
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPWriteString(
    TBHANDLE in_pageHandle,
    char* in_inputString,
    short in_variableIncrement,
    short in_intercharacterSpacing,
    AlignmentOption in_alignment_option,
    char in_alignment_char,
    boolean in_same_pos
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPSetInputCodepage(
    TBHANDLE in_sessHandle,
    char*    in_codepage,
    char     in_spacechar
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPSetICUInputCodepage(
    TBHANDLE in_sessHandle,
    char*    in_convname
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPSetTextOrientation(
    TBHANDLE in_pageHandle,
    TextOrientation in_inlinebaseline
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPOutputComment(
    TBHANDLE in_currHandle,
    char* in_commentString
)
{
    return rcOK;
}

int TK_CALLING_CONVENTION AFPPutHRule(
    TBHANDLE in_pageHandle,
    short in_ruleLength,
    short in_ruleThickness
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION AFPPutVRule(
    TBHANDLE in_pageHandle,
    short in_ruleLength,
    short in_ruleThickness
)
{
    return rcOK;
}



int TK_CALLING_CONVENTION AFPBgnPgraph(
    TBHANDLE in_pageHandle,
    ushort in_paragraph_width,
    AlignmentOption in_text_alignment,
    ushort in_linespacing,
    ushort in_max_pdepth
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION AFPEndPgraph(
    TBHANDLE in_pageHandle
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION AFPPutText(
    TBHANDLE in_pageHandle,
    char* in_textstring,
    FontID in_textfont,
    char** outp_remainstr
)
{
    return rcOK;
}


int TK_CALLING_CONVENTION IN_2_MM(double x) { return  ((int)(x * 25.4)); }
int TK_CALLING_CONVENTION IN_2_CM(double x) { return  (IN_2_MM(x) / 10); }
int TK_CALLING_CONVENTION IN_2_U240(double x) { return  ((int)(x * 240)); }
int TK_CALLING_CONVENTION IN_2_U1440(double x) { return  ((int)(x * 1440)); }
int TK_CALLING_CONVENTION IN_2_U72000(double x) { return  ((int)(x * 72000)); }

/* mm to inches, cm, u240, u1440 */

int TK_CALLING_CONVENTION MM_2_IN(double x) { return (x / 25.4); }
int TK_CALLING_CONVENTION MM_2_CM(double x) { return (x / 10.0); }
int TK_CALLING_CONVENTION MM_2_U240(double x) { return (IN_2_U240(MM_2_IN(x))); }
int TK_CALLING_CONVENTION MM_2_U1440(double x) { return (((x * 1440) + 12.7) / 25.4); }
int TK_CALLING_CONVENTION MM_2_U72000(double x) { return (IN_2_U72000(MM_2_IN(x))); }

/* cm to mm, inches, u240, u1440 */

int TK_CALLING_CONVENTION CM_2_MM(double x) { return (x * 10); }
int TK_CALLING_CONVENTION CM_2_IN(double x) { return (MM_2_IN(CM_2_MM(x))); }
int TK_CALLING_CONVENTION CM_2_U240(double x) { return (IN_2_U240(CM_2_IN(x))); }
int TK_CALLING_CONVENTION CM_2_U1440(double x) { return (IN_2_U1440(CM_2_IN(x))); }
int TK_CALLING_CONVENTION CM_2_U72000(double x) { return (IN_2_U72000(CM_2_IN(x))); }

/* u240 to inches, mm, cm, u1440 */

int TK_CALLING_CONVENTION U240_2_IN(double x) { return (x / 240.0); }
int TK_CALLING_CONVENTION U240_2_MM(double x) { return (IN_2_MM(U240_2_IN(x))); }
int TK_CALLING_CONVENTION U240_2_CM(double x) { return (MM_2_CM(U240_2_MM(x))); }
int TK_CALLING_CONVENTION U240_2_U1440(double x) { return (IN_2_U1440(U240_2_IN(x))); }
int TK_CALLING_CONVENTION U240_2_U72000(double x) { return (IN_2_U72000(U240_2_IN(x))); }

/* u1440 to inches, mm, cm, u240 */

int TK_CALLING_CONVENTION U1440_2_IN(double x) { return (x / 1440.0); }
int TK_CALLING_CONVENTION U1440_2_MM(double x) { return int(((x*25.4) + 720) / 1440); }
int TK_CALLING_CONVENTION U1440_2_CM(double x) { return (MM_2_CM(U1440_2_MM(x))); }
int TK_CALLING_CONVENTION U1440_2_U240(double x) { return (IN_2_U240(U1440_2_IN(x))); }
int TK_CALLING_CONVENTION U1440_2_U72000(double x) { return (IN_2_U72000(U1440_2_IN(x))); }



/* --- some extra functions */


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