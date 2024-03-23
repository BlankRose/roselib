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

void callback(const rose::UnitTesterOutcome &out)
{
    switch (out)
    {
    case rose::UnitTesterOutcome::SUCCESS:
        break;
    default:
        break;
    }
}

void assign_test_callback()
{
    rose::UnitTesterBase::set_default_callback(callback);
}