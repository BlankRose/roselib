/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  unit_tester.cpp                                        */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [11:26 pm]                */
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
    /*  1 */ testA.run_test(i.cbegin(), i.cend(), i.size());         // SUCCESS
    /*  2 */ testA.run_test(i.cbegin(), i.cend() - 1, i.size() - 1); // SUCCESS
    /*  3 */ testA.run_test(i.cbegin(), i.cend() - 1, i.size());     // FAIL EXPECTED

    /// FUNCTION UNIT TESTER (with void return)
    auto testB = make_tester(testA, std::sort<storage::iterator>);
    /*  4 */ testB.run_test(i.begin(), i.end());                     // SUCCESS

    /// CONDITIONAL UNIT TESTER
    auto testC = make_tester(testB);
    /*  5 */ testC.run_test(true);                                   // SUCCESS
    /*  6 */ testC.run_test(false);                                  // FAIL EXPECTED
    /*  7 */ testC.run_test(1, 1);                                   // SUCCESS
    /*  8 */ testC.run_unequal_test(true);                           // FAIL EXPECTED
    /*  9 */ testC.run_unequal_test(false);                          // SUCCESS
    /* 10 */ testC.run_unequal_test(0, 1);                           // SUCCESS

    std::cout << "\nRESULTS: " << testC << " [Expecting 3 fails..]" << std::endl;
    return testC.get_result().fails == 3;                           // ONLY 3 FAIL
}
