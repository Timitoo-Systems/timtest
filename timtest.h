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

#define rcOK 0
#define rcFAILED 1

#define TIM_CPI    (31415)
#define TIM_FILENAME "tim_abcdef.txt"

typedef void*          TBHANDLE;
typedef unsigned short ushort;

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
// returns always 0
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
