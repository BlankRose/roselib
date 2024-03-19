#include "roselib/predicates.hpp"
#include <iostream>

#define TEST(function, argA, argB)\
    std::cout\
        << #function"("#argA", "#argB") => " \
        << ROSELIB_NAMESPACE::function(argA, argB)\
        << std::endl;

void test_begin_with()
{
    const char *base = "I love turtles";
    std::cout << "BASE = \"" << base << "\"" << std::endl;

    TEST(begin_with, base, "I lov");
    TEST(begin_with, base, "");
    TEST(begin_with, base, "YOLO");
}