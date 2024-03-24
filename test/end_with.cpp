/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  end_with.cpp                                           */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 24, 2024 [01:52 am]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "roselib/Predicates/end_with.hpp"
#include "roselib/UnitTester.hpp"
#include <iostream>
#include <vector>

void test_end_with()
{
    std::cout << "\nPredicates - end_with()" << std::endl;
    rose::UnitTesterBase store(rose::UnitTesterType::UNKNOWN);
    {
        /// END_WITH ( STRINGS )
        const std::string base = "I love turtles";
        const std::string cmpA = "I lov";
        const char *      cmpB = "les";

        std::cout << "Strings    :";
        auto testA = rose::make_tester<bool(const char*, const char*)>(rose::end_with);
        /*  1 */ testA.run_test(base.c_str(), cmpA.c_str(), false);
        /*  2 */ testA.run_test(base.c_str(), "", true);
        /*  3 */ testA.run_test(base.c_str(), cmpB, true);
        auto testB = rose::make_tester<bool(const char*, const size_t&, const char &)>(testA, rose::end_with);
        /*  4 */ testB.run_test(base.c_str(), base.size(), 's', true);
        /*  5 */ testB.run_test(base.c_str(), base.size(), 'a', false);
        auto testC = rose::make_tester<bool(const std::string&, const std::string&)>(testB, rose::end_with);
        /*  6 */ testC.run_test(base, cmpA, false);
        /*  7 */ testC.run_test(base, std::string(""), true);
        /*  8 */ testC.run_test(base, std::string(cmpB), true);
        auto testD = rose::make_tester<bool(const std::string&, const char&)>(testC, rose::end_with);
        /*  9 */ testD.run_test(base, 's', true);
        /* 10 */ testD.run_test(base, 'a', false);
        std::cout << std::endl;
        store = testD;
    }
    {
        /// END_WITH ( RAW ARRAYS )
        constexpr int base[] = {0, 1, 5, 10, 20, 45};
        constexpr int cmpA[] = {0, 1, 5};
        constexpr int cmpB[] = {20, 45};
        constexpr size_t count_base = sizeof(base) / sizeof(*base);
        constexpr size_t count_cmpA = sizeof(cmpA) / sizeof(*cmpA);
        constexpr size_t count_cmpB = sizeof(cmpB) / sizeof(*cmpB);

        std::cout << "Raw Arrays :";
        auto testA = rose::make_tester<bool(const int[], const size_t&, const int[], const size_t&)>(store, rose::end_with);
        /* 11 */ testA.run_test(base, count_base, cmpA, count_cmpA, false);
        /* 12 */ testA.run_test(base, count_base, cmpB, count_cmpB, true);
        /* 13 */ testA.run_test(base, count_base, {}, 0, true);
        auto testB = rose::make_tester<bool(const int[], const size_t&, const int&)>(testA, rose::end_with);
        /* 14 */ testB.run_test(base, count_base, 45, true);
        /* 15 */ testB.run_test(base, count_base, 1, false);
        std::cout << std::endl;
        store = testB;
    }
    {
        /// END_WITH ( CONTAINERS )
        const std::vector<int> base = {0, 1, 5, 10, 20, 45};
        const std::vector<int> cmpA = {0, 1, 5};
        const std::vector<int> cmpB = {20, 45};

        std::cout << "Containers :";
        auto testA = rose::make_tester<bool(const std::vector<int>&, const std::vector<int>&)>(store, rose::end_with);
        /* 16 */ testA.run_test(base, cmpA, false);
        /* 17 */ testA.run_test(base, cmpB, true);
        /* 18 */ testA.run_test(base, {}, true);
        auto testB = rose::make_tester<bool(const std::vector<int>&, const int&)>(testA, rose::end_with);
        /* 19 */ testB.run_test(base, 45, true);
        /* 20 */ testB.run_test(base, 1, false);
        std::cout << std::endl;
        store = testB;
    }
    std::cout << "RESULTS: " << store << std::endl;
}