/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  begin_with.cpp                                         */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [11:26 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "roselib/Predicates/begin_with.hpp"
#include "roselib/UnitTester.hpp"
#include <iostream>
#include <vector>

void test_begin_with()
{
    std::cout << "\nPredicates - begin_with()" << std::endl;
    rose::UnitTesterBase store(rose::UnitTesterType::UNKNOWN);
    {
        /// BEGIN_WITH ( STRINGS )
        const std::string base = "I love turtles";
        const std::string cmpA = "I lov";
        const char *      cmpB = "les";

        std::cout << "Strings    :";
        auto testA = rose::make_tester<bool(const char*, const char*)>(rose::begin_with);
        /*  1 */ testA.run_test(base.c_str(), cmpA.c_str(), true);
        /*  2 */ testA.run_test(base.c_str(), "", true);
        /*  3 */ testA.run_test(base.c_str(), cmpB, false);
        auto testB = rose::make_tester<bool(const char*, const char &)>(testA, rose::begin_with);
        /*  4 */ testB.run_test(base.c_str(), 'I', true);
        /*  5 */ testB.run_test(base.c_str(), 'a', false);
        auto testC = rose::make_tester<bool(const std::string&, const std::string&)>(testB, rose::begin_with);
        /*  6 */ testC.run_test(base, cmpA, true);
        /*  7 */ testC.run_test(base, std::string(""), true);
        /*  8 */ testC.run_test(base, std::string(cmpB), false);
        auto testD = rose::make_tester<bool(const std::string&, const char&)>(testC, rose::begin_with);
        /*  9 */ testD.run_test(base, 'I', true);
        /* 10 */ testD.run_test(base, 'a', false);
        std::cout << std::endl;
        store = testD;
    }
    {
        /// BEGIN_WITH ( RAW ARRAYS )
        constexpr int base[] = {0, 1, 5, 10, 20, 45};
        constexpr int cmpA[] = {0, 1, 5};
        constexpr int cmpB[] = {20, 45};
        constexpr size_t count_base = sizeof(base) / sizeof(*base);
        constexpr size_t count_cmpA = sizeof(cmpA) / sizeof(*cmpA);
        constexpr size_t count_cmpB = sizeof(cmpB) / sizeof(*cmpB);

        std::cout << "Raw Arrays :";
        auto testA = rose::make_tester<bool(const int[], const size_t&, const int[], const size_t&)>(store, rose::begin_with);
        /* 11 */ testA.run_test(base, count_base, cmpA, count_cmpA, true);
        /* 12 */ testA.run_test(base, count_base, cmpB, count_cmpB, false);
        /* 13 */ testA.run_test(base, count_base, {}, 0, true);
        auto testB = rose::make_tester<bool(const int[], const int&)>(testA, rose::begin_with);
        /* 14 */ testB.run_test(base, 0, true);
        /* 15 */ testB.run_test(base, 1, false);
        std::cout << std::endl;
        store = testB;
    }
    {
        /// BEGIN_WITH ( CONTAINERS )
        const std::vector<int> base = {0, 1, 5, 10, 20, 45};
        const std::vector<int> cmpA = {0, 1, 5};
        const std::vector<int> cmpB = {20, 45};

        std::cout << "Containers :";
        auto testA = rose::make_tester<bool(const std::vector<int>&, const std::vector<int>&)>(store, rose::begin_with);
        /* 16 */ testA.run_test(base, cmpA, true);
        /* 17 */ testA.run_test(base, cmpB, false);
        /* 18 */ testA.run_test(base, {}, true);
        auto testB = rose::make_tester<bool(const std::vector<int>&, const int&)>(testA, rose::begin_with);
        /* 19 */ testB.run_test(base, 0);
        /* 20 */ testB.run_test(base, 1);
        std::cout << std::endl;
        store = testB;
    }
    std::cout << "RESULTS: " << store << std::endl;
}