/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  unit_tester.cpp                                        */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [05:11 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "roselib/UnitTester.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

using storage = std::vector<int>;

bool test_unit_tester()
{
    std::cout << "Testing Unit Tester" << std::endl;
    storage i{0, 3, 2};

    /// FUNCTION UNIT TESTER (with non-void return)
    auto testA = rose::make_tester(std::distance<storage::const_iterator>);
    /* 1 */ testA.run_test(i.cbegin(), i.cend(), i.size());         // SUCCESS
    /* 2 */ testA.run_test(i.cbegin(), i.cend() - 1, i.size() - 1); // SUCCESS
    /* 3 */ testA.run_test(i.cbegin(), i.cend() - 1, i.size());     // FAIL EXPECTED

    /// FUNCTION UNIT TESTER (with void return)
    auto testB = make_tester(std::sort<storage::iterator>, testA);
    /* 4 */ testB.run_test(i.begin(), i.end());                     // SUCCESS

    std::cout << "\nRESULTS: " << testB << std::endl;
    return testB.get_result().fails == 1;                           // ONLY 1 FAIL
}