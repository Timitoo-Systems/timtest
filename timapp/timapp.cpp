
#define CATCH_CONFIG_COLOUR_NONE 1
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <stdlib.h>

#include <timtest.h>

char xx[] = { "DUMMY VALUE" };
void * getDummyPtr() {
    return &xx[0];
}

TEST_CASE("TEST0 returns TIM_CPI (success)", "[timlib]") {
    REQUIRE( TEST0() == TIM_CPI );
}

TEST_CASE("TEST1 returns TIM_CPI * x (success)", "[timlib]") {
    int x = 2;
    int result = (TIM_CPI * x);
    REQUIRE(TEST1(x) == result);
}

TEST_CASE("TEST3 returns strlen of char * in (success)", "[timlib]") {
    char lorem[] = { "lorem" };
    int lenLorem = static_cast<int>(strlen(&lorem[0]));

    REQUIRE(TEST3(&lorem[0]) == lenLorem);

    char ipsum[] = { "IPSUM" };
    int lenIpsum = static_cast<int>(strlen(&ipsum[0]));

    REQUIRE(TEST3(&ipsum[0]) == lenIpsum);
}

TEST_CASE("TEST4 returns long (success)", "[timlib]") {
    double in = 123.45;
    REQUIRE(TEST4(in) == 12345);

    in = 3.1415;
    REQUIRE(TEST4(in) == 314);
}


TEST_CASE("TESTH1 return rcOK and rcFAILED (success)", "[timlib]") {

    // pass null
    TBHANDLE in_Handle = nullptr;
    REQUIRE(TESTH1(in_Handle) == rcOK);


    // pass non-null
    std::memset(&in_Handle, (int)0x20, sizeof(TBHANDLE));
    REQUIRE(TESTH1(in_Handle) == rcFAILED);
}


TEST_CASE("TESTH2 set TBHANDLE (success)", "[timlib]") {

    // pass null
    TBHANDLE in_Handle = nullptr;

    // Sets in_Handle and returns rcOK
    int rc = TESTH2(&in_Handle);

    // require non-null
    REQUIRE( ((in_Handle != nullptr) && (rc == rcOK)) );
}


TEST_CASE("TESTH3 test if TBHANDLE is valid (success)", "[timlib]") {

    // set null
    TBHANDLE in_Handle = nullptr;

    // set in_Handle
    TESTH2(&in_Handle);

    // test if a valid in_Handle
    REQUIRE( TESTH3(in_Handle) == rcOK );


    // test if handle is invalid
    std::memset(&in_Handle, (int)0x20, sizeof(TBHANDLE));

    REQUIRE(TESTH3(in_Handle) == rcFAILED);
}

TEST_CASE("TESTF1 create file write dummy string", "[timlib]") {

    REQUIRE(TESTF1() == rcOK);
}


TEST_CASE("TESTF2 create file and write string", "[timlib]") {

    char helloText[] = { "Hello World!"};
    REQUIRE( TESTF2(helloText) == rcOK );
}
