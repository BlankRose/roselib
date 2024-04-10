/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  main.cpp                                               */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [11:26 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include <iostream>

void assign_test_callback();
bool test_unit_tester();
void test_begin_with();
void test_end_with();
void test_logger();

int main()
{
    assign_test_callback();
    if (!test_unit_tester())
    {
        std::cerr << "Flawed unit tested detected!" << std::endl;
        return 1;
    }
    test_begin_with();
    test_end_with();
    test_logger();
}