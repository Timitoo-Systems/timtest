/****************************************************************************
** (C) Copyright 2016-20 Timitoo Systems GmbH. All Rights Reserved.
**
** Written by Thomas Krenn, 2020
**
****************************************************************************/


#if !defined(TIM_TEST_20200430_H_)
#define TIM_TEST_20200430_H_ 1

#if defined(_MSC_VER)
#  define TIM_CC_MSVC (_MSC_VER)
#  define TIM_COMPILER_MANGLES_RETURN_TYPE
#  define TIM_FUNC_INFO __FUNCSIG__
#  define TIM_ALIGNOF(type) __alignof(type)
#  define TIM_DECL_ALIGN(n) __declspec(align(n))
#  define TIM_ASSUME_IMPL(expr) __assume(expr)
#  define TIM_UNREACHABLE_IMPL() __assume(0)
#  define TIM_NORETURN __declspec(noreturn)
#  define TIM_DECL_DEPRECATED __declspec(deprecated)
#  define TIM_DECL_DEPRECATED_X(text) __declspec(deprecated(text))
#  define TIM_DECL_EXPORT __declspec(dllexport)
#  define TIM_DECL_IMPORT __declspec(dllimport)
#endif


#ifdef TIM_CC_MSVC
      /*  __stdcall convention is ignored on x64 */
#    define TK_CALLING_CONVENTION __cdecl
#    ifdef TIM_TEST_LIB
#     define TK_FUNCTION TIM_DECL_EXPORT TK_CALLING_CONVENTION
#    else
#     define TK_FUNCTION TIM_DECL_IMPORT TK_CALLING_CONVENTION
#    endif


#else
#    define TK_FUNCTION
#    define TK_CALLING_CONVENTION
#endif

#ifdef __cplusplus
extern "C" {
#endif

    /*-------------------------------------------------------------------
    // Return codes
    /-------------------------------------------------------------------*/
#define rcOK 0
#define rcFAILED   1
#define rcCODEPAGE_FILE_NOT_FOUND          1
    /* the specified codepage file could not be located.
    the font is still usable, however no codepage translations can
    be performed and unless the datastream codepage and default input
    codepage are identical, incorrect results will likely occur.
    */

#define rcAFM_FILE_NOT_FOUND               2
    /*  the AFM file specified in the font index could not be located.
    run fliplist to find the name and see if the file exists and
    has appropriate read permissions.
    */

#define rcCHAR_SET_FILE_NOT_FOUND          3
    /* the character set file specified in the font index or define font
    by name call could not be located.
    run fliplist to find the name of the character set and determine
    if the file exists and has appropriate read permissions.
    */

#define rcMETRICS_FILES_NOT_FOUND          4
    /* neither the character set file nor the corresponding AFM file
    could be found.
    the font is still usable, however no metrics are available, thus
    right, center, and character aligned text, next line operations,
    and any other operation involving measured text will fail.
    */

#define rcSBCS_CODEPAGE_FOUND              5           
    /* this codepage is SBCS. */

#define rcDBCS_CODEPAGE_FOUND              6           
    /* this codepage is DBCS. */

#define rcFONT_INDEX_FILE_NOT_FOUND        -1
    /* the AFRCORE.FIN file could not be located. */

#define rcFONT_FAMILY_NOT_FOUND_IN_INDEX   -2
    /* the font family name was not found in the font index.
    run fliplist to see if the family name is correctly specified. */

#define rcFONT_PARTICULARS_NOT_FOUND       -3
    /* the combination of point size, weight, width, and attributes was
    not defined within the specified font family.
    run fliplist to see if the font particulars were correctly
    specified. */

#define rcFONT_CHAR_SET_NOT_FOUND_IN_INDEX -4
    /* the font character set was not defined within the specified font
    family or the character set was not found in the font index.
    run fliplist to see if the font character set was correctly
    specified. */

#define rcFONT_FGID_GCSGID_NOT_FOUND       -5
    /* the font FGID/GCSGID combination was not defined within the
    specified font family.
    run fliplist to see if the font FGID/GCSCID combination was
    correctly specified.
    */

#define rcFONT_INDICES_NOT_FOUND           -6
    /* the font i and j indexes were located but the interal font
    information could not be located in the font tables.  This
    is an internal error that could be caused by memory corruption.
    */

#define rcNO_HANDLES_AVAILABLE             -7
    /* there are no font handles available to define a new font.
    delete some fonts with AFPDeleteFont to make handles available. */

#define rcMISSING_CODEPAGE                 -8
    /* the codepage file specification is missing on the define font
    operation.
    check to ensure that a valid codepage file was passed as a
    parameter on one of the AFPDefineFont calls.
    */

#define rcINVALID_HANDLE                   -9
    /* the font handle specified is not valid.
    font handles must be obtained from a successful call to
    AFPDefineFontByName or AFPDefineFontByAttr.
    */

#define rcREQUIRED_PARM_NULL               -10
    /* a NULL or 0 value was passed as a required parameter.
    pass in a non-NULL value of the correct type for this parameter.
    */

#define rcFILE_NOT_FOUND                   -11
    /* some unknown file was not found.
    */

#define rcINVALID_CODEPAGE_FILE_FONT       -12
    /* the specified codepage is invalid.
    most likely the file in question is an AFP Character Set file, not
    a Code Page.
    */

#define rcINVALID_CODEPAGE_FILE_DOC        -13
    /* the specified codepage is invalid.
    most likely the file in question is an AFP Document file, not
    a Code Page.
    */

#define rcINVALID_CODEPAGE_FILE_CONTENTS   -14
    /* the specified codepage is invalid.
    the contents of the codepage are incorrect.  use the afpdmp utility
    to display the file contents & determine if the file is in error.
    */

#define rcMISSING_INPUT_CODEPAGE           -15
    /* the input codepage file on a translate operation was not found
    */

#define rcMISSING_OUTPUT_CODEPAGE          -16
    /* the output codepage file on a translate operation was not found
    */

#define rcINVALID_FONT_TYPE_SPECIFIED      -17
    /* the specified font type is invalid.
    the value specified for font type must be one of the enumeration
    values defined in the FontCSType data type. */

#define rcINVALID_CODEPAGE_SPECIFIED        -18         
    /* the specified codepage is invalid. the first       */
    /* codepage must be SBCS and the second codepage DBCS. */

#define rcINVALID_FONT_FILE                 -19          
    /* The specified font is invalid. The value of        */
    /* space width is zero. Check the contents of the     */
    /* character set and codepage files.                  */

#define rcIS_ERROR(x)    ((x) < rcOK)


    typedef void*          TBHANDLE;
    typedef unsigned char  byte;
    typedef unsigned short ushort;

    /* -------------------------------------------------------------------
    // Boolean
    / ------------------------------------------------------------------*/
#undef FALSE
#undef TRUE
#undef OFF
#undef ON
#undef NO
#undef YES
#undef BOOLERR
    typedef enum
    {
        FALSE = 0,
        TRUE = 1,
        OFF = 0,
        ON = 1,
        NO = 0,
        YES = 1,
        BOOLERR = -1
    } boolean;

    typedef enum {
        TO_OUTPUT_FILE = 0,
        TO_OUTPUT_BUFFER = 1,
        TO_MVS_FILE = 2,
        TO_BIT_BUCKET = 3
    } OUTTYPE;


    typedef enum {
        ULTRA_LIGHT_WT = 0x01,
        EXTRA_LIGHT_WT = 0x02,
        LIGHT_WT = 0x03,
        SEMI_LIGHT_WT = 0x04,
        MEDIUM_WT = 0x05,
        SEMI_BOLD_WT = 0x06,
        BOLD_WT = 0x07,
        EXTRA_BOLD_WT = 0x08,
        ULTRA_BOLD_WT = 0x09
    } FDSWeights;

    typedef enum {
        ULTRA_CONDENSED_WD = 0x01,
        EXTRA_CONDENSED_WD = 0x02,
        CONDENSED_WD = 0x03,
        SEMI_CONDENSED_WD = 0x04,
        MEDIUM_WD = 0x05,
        SEMI_EXPANDED_WD = 0x06,
        EXPANDED_WD = 0x07,
        EXTRA_EXPANDED_WD = 0x08,
        ULTRA_EXPANDED_WD = 0x09
    } FDSWidths;


    typedef enum {
        NORMAL_FS = 0x0000,
        OVERSTRUCK_FS = 0x0800,
        OUTLINE_FS = 0x1000,
        UNDERSCORE_FS = 0x4000,
        ITALIC_FS = 0x8000
    } FontStyle;


    typedef enum {
        DEVICE_DEFAULT = 0x00,
        RGB_COLOR = 0x01,  /* RGB-COLOR     */
        YCRCB_COLOR = 0x02,
        CMYK_COLOR = 0x04,  /* CMYK-COLOR    */
        HILIGHT_COLOR = 0x06,  /* HILIGHT-COLOR */
        CIELAB_COLOR = 0x08,  /* CIELAB-COLOR  */
        YCBCR_COLOR = 0x12,
        OCA_COLOR = 0x40    /* OCA-COLOR     */
    } ColorSpace;


    typedef enum {
        BLUE = 0x0001,
        BLUE1 = 0xFF01,
        RED = 0x0002,
        RED1 = 0xFF02,
        PINK = 0x0003,
        PINK1 = 0xFF03,
        MAGENTA = 0x0003,
        MAGENTA1 = 0xFF03,
        GREEN = 0x0004,
        GREEN1 = 0xFF04,
        TURQUOISE = 0x0005,
        TURQUOISE1 = 0xFF05,
        CYAN = 0x0005,
        CYAN1 = 0xFF05,
        YELLOW = 0x0006,
        YELLOW1 = 0xFF06,
        NEUTRAL_WHITE = 0xFF07,
        BLACK = 0x0008,
        DARKBLUE = 0x0009,
        ORANGE = 0x000A,
        PURPLE = 0x000B,
        DARKGREEN = 0x000C,
        DARKTURQ = 0x000D,
        DARKCYAN = 0x000D,
        MUSTARD = 0x000E,
        GRAY = 0x000F,
        BROWN = 0x0010,
        MEDIUM_COLOR = 0xFF08,
        DEFAULT_COLOR = 0xFFFF
    } MODCAColors;

    typedef unsigned short FontID;

    typedef enum {
        ABSOLUTE_POS,
        RELATIVE_POS
    } POSTYPE;

    typedef enum {
        LEFT_ALIGN,                     /* left aligned */
        RIGHT_ALIGN,                    /* right aligned */
        CENTER_ALIGN,                   /* centered */
        CHAR_ALIGN,                     /* align on 1st occurrence of character */
        FIRST_CHAR_ALIGN = CHAR_ALIGN,
        LAST_CHAR_ALIGN,                /* align on last occurrence of character */
        JUSTIFY_ALIGN                   /* justify  (Blocksatz) */
    } AlignmentOption;

    typedef enum
    {
        I0B90_TO,
        I0B270_TO,
        I90B180_TO,
        I90B0_TO,
        I180B270_TO,
        I180B90_TO,
        I270B0_TO,
        I270B180_TO
    } TextOrientation;

    /* default line spacing */
#define DEFAULT_LSP -1

    /* default variable increment */
#define DEFAULT_WS  -1

    /* default character spacing */
#define DEFAULT_ICS -1

    /* --------------------------------------------------------------------
    // unit conversion macros
    // inches to mm, cm, u240, u1440
    / --------------------------------------------------------------------*/

    int TK_FUNCTION IN_2_MM(double x);
    int TK_FUNCTION IN_2_CM(double x);
    int TK_FUNCTION IN_2_U240(double x);
    int TK_FUNCTION IN_2_U1440(double x);
    int TK_FUNCTION IN_2_U72000(double x);

    /* mm to inches, cm, u240, u1440 */

    int TK_FUNCTION  MM_2_IN(double x);
    int TK_FUNCTION  MM_2_CM(double x);
    int TK_FUNCTION  MM_2_U240(double x);
    int TK_FUNCTION  MM_2_U1440(double x);
    int TK_FUNCTION  MM_2_U72000(double x);

    /* cm to mm, inches, u240, u1440 */

    int TK_FUNCTION CM_2_MM(double x);
    int TK_FUNCTION CM_2_IN(double x);
    int TK_FUNCTION CM_2_U240(double x);
    int TK_FUNCTION CM_2_U1440(double x);
    int TK_FUNCTION CM_2_U72000(double x);

    /* u240 to inches, mm, cm, u1440 */

    int TK_FUNCTION U240_2_IN(double x);
    int TK_FUNCTION U240_2_MM(double x);
    int TK_FUNCTION U240_2_CM(double x);
    int TK_FUNCTION U240_2_U1440(double x);
    int TK_FUNCTION U240_2_U72000(double x);

    /* u1440 to inches, mm, cm, u240 */

    int TK_FUNCTION U1440_2_IN(double x);
    int TK_FUNCTION U1440_2_MM(double x);
    int TK_FUNCTION U1440_2_CM(double x);
    int TK_FUNCTION U1440_2_U240(double x);
    int TK_FUNCTION U1440_2_U72000(double x);

    /*
    Dummy function
    returns 0 if handle == nullptr
    returns 1 if handle != nullptr
    */
    int TK_FUNCTION AFPTest(
        TBHANDLE handle
    );

    /*
    Initializes the AFP Toolbox session. You cannot issue any other AFP Toolbox
    procedure call until you have successfully executed Begin Session.
    */

    int TK_FUNCTION AFPBgnSession(
        TBHANDLE* outp_sessHandle
    );

    /*
    Normal termination of the AFP Toolbox session. You cannot issue any other AFP
    Toolbox procedure call after End Session has been issued except for another Begin
    Session
    */

    int TK_FUNCTION AFPEndSession(
        TBHANDLE* inp_sessHandle
    );

    /*
    Begins a document and specifies the name of the document used in the output
    data stream as well as the type of output produced.
    */

    int TK_FUNCTION AFPBgnDoc(
        TBHANDLE in_sessHandle,
        char* in_docName,
        char* in_comment,
        OUTTYPE in_outputtype,
        char* in_outputfilename,
        byte* in_outputbuffer,
        TBHANDLE* outp_docHandle
    );

    /*
    Begins a logical page and names it.
    */
    int TK_FUNCTION AFPBgnPage(
        TBHANDLE in_docHandle,
        char* in_pageName,
        TBHANDLE* outp_pageHandle
    );

    /*
    Begins a shaded rectangle of specified width at the current location.
    */
    int TK_FUNCTION AFPBgnShade(
        TBHANDLE in_pageHandle,
        ushort in_shade_width,
        ushort in_shade_percent,
        TBHANDLE* outp_shadeHandle
    );

    /*
    Finds a font on your system that matches specified attributes and returns a font ID
    corresponding to this font. The font ID is used on subsequent Set Font calls.
    */
    int TK_FUNCTION AFPDefineFontByAttr(
        char* in_codePage,
        char* in_descriptiveName,
        ushort in_pointSize,
        FDSWeights in_weight,
        FDSWidths in_width,
        FontStyle in_style,
        FontID* out_fontID
    );

    /*
    Finds a font on your system that matches the specified character set and code page
    combination and returns a font ID. The font ID is used on subsequent Set Font
    calls.
    */
    int TK_FUNCTION AFPDefineFontByName(
        char* in_codePage,
        char* in_characterSet,
        char* in_codedFont,
        FontID out_fontID
    );

    /*
    Deletes the page whose handle is passed in the first parameter. No AFP output is
    produced for the given page. The purpose of the Delete Page function is to allow
    you to format and count pages without actually producing output
    */
    int TK_FUNCTION AFPDeletePage(
        TBHANDLE* inp_pageHandle
    );

    /*
    Ends the document and causes the remainder of the data stream to be written to
    the output destination.
    */
    int TK_FUNCTION AFPEndDoc(
        TBHANDLE* inp_docHandle
    );

    /*
    Begins a logical grouping of pages
    */
    int TK_FUNCTION AFPBgnGroup(
        TBHANDLE in_docHandle,
        char* in_groupName
    );

    /*
    Ends a logical group of pages previously started with Begin Group. If no group is
    active this request is ignored.
    */
    int TK_FUNCTION AFPEndGroup(
        TBHANDLE in_docHandle
    );


    /*
    Ends the page. If output is being buffered (returned to the program), then you
    need to follow End Page with repeated Get Buffer calls until “outp_moreData” is
    false. If not buffered, the page is output to the appropriate file (or spool) after this
    call has been received. No more data can be placed in the page once it is ended.
    See the example in “Get Buffer” on page 154 for more information.
    */
    int TK_FUNCTION AFPEndPage(
        TBHANDLE* inp_pageHandle
    );

    /*
    Ends a shaded rectangle at the current location. The shaded area must have been
    previously started with a Begin Shade request.
    */
    int TK_FUNCTION AFPEndShade(
        TBHANDLE in_pageHandle,
        TBHANDLE* inp_shadeHandle
    );

    /*
    Creates a reference to a page segment at the current location.
    */
    int TK_FUNCTION AFPInclPSeg(
        TBHANDLE in_pageHandle,
        char* in_pageSegmentName,
        boolean in_reuseOption
    );

    /*
    Measures the width of the specified string in the given font and returns the width.
    */
    int TK_FUNCTION AFPMeasureString(
        FontID in_fontID,
        char* in_inputString,
        long* outp_stringWidth,
        ushort in_vinc,
        ushort in_cadj,
        int* outp_varspaces,
        int* outp_icspaces
    );

    /*
    Advance one line in the current font. The horizontal position is not changed by
    this call.
    */
    int TK_FUNCTION AFPNextLine(
        TBHANDLE in_pageHandle
    );

    /*
    Creates an indexing tag in the document for use by presentation systems such as
    the AFP Workbench or postprocessor applications such as OnDemand. This call
    generates a Tag Logical Element (TLE) structured field at either the group or the
    page level depending on which handle is specified.
    */
    int TK_FUNCTION AFPPutTag(
        TBHANDLE in_currentHandle,
        char* in_attrName,
        char* in_attrValue
    );

    /*
    Returns the current values for position, color, and font information.
    */
    int TK_FUNCTION AFPQuery(
        TBHANDLE in_pageHandle,
        long* outp_xCoordinate,
        long* outp_yCoordinate,
        MODCAColors* outp_color,
        FontID* outp_fontID,
        long* outp_fontlinesp
    );


    /*
    Specifies the font for subsequent text data. Do not issue this call within a
    paragraph or a table
    */
    int TK_FUNCTION AFPSetFont(
        TBHANDLE in_pageHandle,
        FontID in_font_id
    );

    /*
    Set the size of the media (printable area) for subsequent pages in the document. If
    this call is not specified, the default of 8.5 x 11 inches is used for all pages.
    */
    int TK_FUNCTION AFPSetMediaSize(
        TBHANDLE in_docHandle,
        long in_pageWidth,
        long in_pageLength
    );

    /*
    Sets the new position for output on the page. The initial position on the page is at
    (0,0). Do not issue this call within a paragraph or a table.
    */
    int TK_FUNCTION AFPSetPos(
        TBHANDLE in_pageHandle,
        short in_inlinePosition,
        POSTYPE in_inlineReference,
        short in_baselinePosition,
        POSTYPE in_baselineReference
    );

    /*
    Move inline horizontally to a specified position. The new current position is at the specified position inline,
    and unchanged in the baseline direction.
    */
    int TK_FUNCTION AFPHMoveTo(
        TBHANDLE in_pageHandle,
        ushort in_inlinePosition
    );

    /*
    Move vertically (baseline) to a specified position. The new current position is at the specified position
    (baseline) and unchanged in the inline direction
    */
    int TK_FUNCTION AFPVMoveTo(
        TBHANDLE in_pageHandle,
        short in_baselinePosition
    );


    /*
    Move inline horizontally relative to the current inline coordinate position
    */
    int TK_FUNCTION AFPHMove(
        TBHANDLE in_pageHandle,
        short in_inlinePosition
    );

    /*
    Move vertically, that is, move the baseline position, relative to the current position.
    */
    int TK_FUNCTION AFPVMove(
        TBHANDLE in_pageHandle,
        short in_baselinePosition
    );


    /*
    Places text in the current page at the current position.

    Write String - AFPWRITE?
    Toolbox also supports DBCS strings. Underscoring is done with Begin
    Underscore (AFPBUSC) and End Underscore (AFPEUSC) functions.
    */
    int TK_FUNCTION AFPWriteString(
        TBHANDLE in_pageHandle,
        char* in_inputString,
        short in_variableIncrement,
        short in_intercharacterSpacing,
        AlignmentOption in_alignment_option,
        char in_alignment_char,
        boolean in_same_pos
    );

    /*
    Specifies the code page name that is used for encoding all input character strings,
    such as names and text, that are parameters on the AFP Toolbox functions. This
    code page is used for all input character strings unless it is changed with another
    Set Input Codepage request or temporarily overridden (for text only) within a page
    by Set Text Codepage.
    Default: IBM-850 on workstations; IBM-500 on host
    */
    int TK_FUNCTION AFPSetInputCodepage(
        TBHANDLE in_sessHandle,
        char*    in_codepage,
        char     in_spacechar
    );

    /*
    Specifies the code page name that is used for encoding all input character strings,
    such as names and text, that are parameters on the AFP Toolbox functions.

    */
    int TK_FUNCTION AFPSetICUInputCodepage(
        TBHANDLE in_sessHandle,
        char*    in_convname
    );

    /*
    This function call moves the text origin and coordinate system for all subsequent
    TEXT and RULE
    operations on this page. However, it does not affect the positioning or
    rotation of any image, overlay, bar code, or other data objects or resources
    */
    int TK_FUNCTION AFPSetTextOrientation(
        TBHANDLE in_pageHandle,
        TextOrientation in_inlinebaseline
    );

    /*
    Lets users to put comments in the data stream for use with postprocessors or other
    user-defined applications. (NOP record)
    IN
    The handle for the current document or page returned
    */
    int TK_FUNCTION AFPOutputComment(
        TBHANDLE in_currHandle,
        char* in_commentString
    );


    int TK_FUNCTION AFPPutHRule(
        TBHANDLE in_pageHandle,
        short in_ruleLength,
        short in_ruleThickness
    );

    /*
    Draws a rule from the current position extending in the y direction using the
    specified rule thickness. The rule thickness extends to the right of vertical rules
    (the current position is at the top left corner of the rule or the bottom left corner if
    the length is negative). The rule must be ended before you end the page. Ensure
    that the rule you have specified fits on the logical page.
    */
    int TK_FUNCTION AFPPutVRule(
        TBHANDLE in_pageHandle,
        short in_ruleLength,
        short in_ruleThickness
    );


    /*
    Begins a paragraph and specifies the formatting information used when placing
    text into the paragraph with Put Text calls
    */
    int TK_FUNCTION AFPBgnPgraph(
        TBHANDLE in_pageHandle,
        ushort in_paragraph_width,
        AlignmentOption in_text_alignment,
        ushort in_linespacing,
        ushort in_max_pdepth
    );

    /*
    Ends the previous paragraph started with the Begin Paragraph call.
    */
    int TK_FUNCTION AFPEndPgraph(
        TBHANDLE in_pageHandle
    );

    /*
    Add a string of text to the current paragraph, using the formatting characteristics
    specified on the Begin Paragraph call. The text must be ended before you end the
    page. Ensure that the text you have specified fits on the logical page
    */
    int TK_FUNCTION AFPPutText(
        TBHANDLE in_pageHandle,
        char* in_textstring,
        FontID in_textfont,
        char** outp_remainstr
    );

#define TIM_CPI    (31415)
#define TIM_FILENAME "tim_abcdef.txt"



// Expected result returns TIM_CPI
int TK_FUNCTION TEST0(
);

// Expected result returns TIM_CPI multiplied by x
int TK_FUNCTION TEST1(int x
);

// Expected result returns 314 plus x
int TK_FUNCTION TEST2(ushort x
);

// Returns length of string (single byte codepage assumed)
// in_test must be null terminated
int TK_FUNCTION TEST3( const char * in_test 
);

// multpliples nbr by 100
long TK_FUNCTION TEST4(double nbr
);

//returns rcOK if in handle is NULL; 
// else it returns rcFAILED
int TK_FUNCTION TESTH1(
    TBHANDLE in_Handle
);

// Pass by reference test 
// returns always rcOK
// in_Handle is set to a valid memory address
int TK_FUNCTION TESTH2(
    TBHANDLE * in_Handle
);


// Returns rcOK of the handle has the same value set by 
// TESTH2
// else the function returns rcFAILED
int TK_FUNCTION TESTH3(
    TBHANDLE in_Handle
);


// Creates/truncates file: TIM_FILENAME and writes dummy text
// returns rcOK on success 
// else rcFAILED
int TK_FUNCTION TESTF1(
);

// Creates a file write line to file TIM_FILENAME
// returns rcOK on success 
// else rcFAILED
int TK_FUNCTION TESTF2( char * line 
);

#ifdef __cplusplus
}
#endif

/* TIM_TEST_20200430_H_ */
#endif
