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

#include <algorithm>

#include "roselib/UnitTester.hpp"
#include <vector>

using storage = std::vector<int>;

bool test_unit_tester()
{
    storage i{0, 3, 2};

    auto test = rose::make_tester(std::distance<storage::const_iterator>);
    test.run_test(i.cbegin(), i.cend(), i.size());

    auto test2 = rose::make_tester(std::sort<storage::iterator>);
    test2.run_test(i.begin(), i.end());

    return true;
}