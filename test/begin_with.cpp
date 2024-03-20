#include "roselib/Predicates/begin_with.hpp"
#include <iostream>
#include <vector>

#define HEADER(title)\
    std::cout << '\n' << title << std::endl;

#define TEST2(function, argA, argB)\
    std::cout\
        << #function"("#argA", "#argB") => "\
        << rose::function(argA, argB)\
        << std::endl;

#define TEST4(function, argA, argB, argC, argD)\
    std::cout\
        << #function"("#argA", "#argB", "#argC", "#argD") => "\
        << rose::function(argA, argB, argC, argD)\
        << std::endl;

void test_begin_with()
{
    {
        HEADER("== BEGIN_WITH - STRINGS ==");

        const std::string base = "I love turtles";
        const std::string cmpA = "I lov";
        const char *      cmpB = "les";

        std::cout << "BASE (std::string) = \"" << base << "\"" << std::endl;
        std::cout << "CMPA (std::string) = \"" << cmpA << "\"" << std::endl;
        std::cout << "CMPB (const char*) = \"" << cmpB << "\"" << std::endl;

        std::cout << " -- raw c-strings" << std::endl;
        TEST2(begin_with, base.c_str(), cmpA.c_str());
        TEST2(begin_with, base.c_str(), "");
        TEST2(begin_with, base.c_str(), cmpB);
        TEST2(begin_with, base.c_str(), 'I');
        TEST2(begin_with, base.c_str(), 'a');

        std::cout << " -- std::string" << std::endl;
        TEST2(begin_with, base, cmpA);
        TEST2(begin_with, base, std::string(""));
        TEST2(begin_with, base, std::string(cmpB));
        TEST2(begin_with, base, 'I');
        TEST2(begin_with, base, 'a');
    }
    {
        HEADER("== BEGIN_WITH - RAW ARRAYS ==");

        constexpr int base[] = {0, 1, 5, 10, 20, 45};
        constexpr int cmpA[] = {0, 1, 5};
        constexpr int cmpB[] = {20, 45};
        constexpr size_t count_base = sizeof(base) / sizeof(*base);
        constexpr size_t count_cmpA = sizeof(cmpA) / sizeof(*cmpA);
        constexpr size_t count_cmpB = sizeof(cmpB) / sizeof(*cmpB);

        std::cout << "BASE (const int*) = {";
        for (size_t i = 0; i < count_base; i++)
            std::cout << (i != 0 ? ", " : "") << base[i];
        std::cout << "}" << std::endl;
        std::cout << "CMPA (const int*) = {";
        for (size_t i = 0; i < count_cmpA; i++)
            std::cout << (i != 0 ? ", " : "") << cmpA[i];
        std::cout << "}" << std::endl;
        std::cout << "CMPB (const int*) = {";
        for (size_t i = 0; i < count_cmpB; i++)
            std::cout << (i != 0 ? ", " : "") << cmpB[i];
        std::cout << "}" << std::endl;

        TEST4(begin_with, base, count_base, cmpA, count_cmpA);
        TEST4(begin_with, base, count_base, cmpB, count_cmpB);
        TEST4(begin_with, base, count_base, {}, 0);
        TEST2(begin_with, base, 0);
        TEST2(begin_with, base, 1);
    }
    {
        HEADER("== BEGIN_WITH - CONTAINERS ==");

        const std::vector<int> base = {0, 1, 5, 10, 20, 45};
        const std::vector<int> cmpA = {0, 1, 5};
        const std::vector<int> cmpB = {20, 45};

        std::cout << "BASE (std::vector) = {";
        for (size_t i = 0; i < base.size(); i++)
            std::cout << (i != 0 ? ", " : "") << base[i];
        std::cout << "}" << std::endl;
        std::cout << "CMPA (std::vector) = {";
        for (size_t i = 0; i < cmpA.size(); i++)
            std::cout << (i != 0 ? ", " : "") << cmpA[i];
        std::cout << "}" << std::endl;
        std::cout << "CMPB (std::vector) = {";
        for (size_t i = 0; i < cmpB.size(); i++)
            std::cout << (i != 0 ? ", " : "") << cmpB[i];
        std::cout << "}" << std::endl;

        TEST2(begin_with, base, cmpA);
        TEST2(begin_with, base, cmpB);
        TEST2(begin_with, base, {});
        TEST2(begin_with, base, 0);
        TEST2(begin_with, base, 1);
    }
}