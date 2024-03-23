/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  callback.cpp                                           */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [08:43 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include <iostream>
#include "roselib/UnitTester.hpp"
#include "roselib/AnsiSequence.hpp"

void callback
    (const rose::UnitTesterOutcome &result, const rose::UnitTesterBase &tester)
{
    const size_t count = tester.get_result().total;
    switch (result)
    {
    case rose::UnitTesterOutcome::SUCCESS:
        std::cout << ' ' << ANSI_FG_GREEN << count << ". [ OK ]" << ANSI_RESET;
        break;
    default:
        std::cout << ' ' << ANSI_FG_RED << count << ". [ KO ]" << ANSI_RESET;
        break;
    }
}

void assign_test_callback()
{
    rose::UnitTesterBase::set_default_callback(callback);
}