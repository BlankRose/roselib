/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  main.cpp                                               */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 20, 2024 [06:11 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include <iostream>

void assign_test_callback();
bool test_unit_tester();
void test_begin_with();

int main()
{
    assign_test_callback();
    if (!test_unit_tester())
    {
        std::cerr << "Flawed unit tested detected!" << std::endl;
        return 1;
    }
    test_begin_with();
}