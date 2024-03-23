/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  callback.cpp                                           */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [11:26 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include <iostream>
#include "roselib/UnitTester.hpp"
#include "roselib/AnsiSequence.hpp"

void callback
    (const rose::UnitTesterOutcome&, const rose::UnitTesterBase &tester)
{
    const size_t count = tester.get_result().total;
    const char * prefix = count < 10 ? "0" : "";
    if (tester.get_last_result())
        std::cout << " " ANSI_FG_GREEN << prefix << count << "." ANSI_BOLD "OK" ANSI_RESET;
    else
        std::cout << " " ANSI_FG_RED << prefix << count << "." ANSI_BOLD "KO" ANSI_RESET;
}

void assign_test_callback()
{
    rose::UnitTesterBase::set_default_callback(callback);
}