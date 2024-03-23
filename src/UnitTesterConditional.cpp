/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTesterConditional.cpp                              */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [10:19 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "roselib/UnitTester/UnitTesterConditional.hpp"

using namespace rose;

UnitTesterConditional::UnitTesterConditional():
    UnitTesterBase(UnitTesterType::CONDITIONAL)
{}

UnitTesterConditional::UnitTesterConditional(const UnitTesterBase &rhs):
    UnitTesterBase(rhs)
{
    this->_type = Type::CONDITIONAL;
}

const bool &UnitTesterConditional::run_test(const bool &value)
{
    this->add_result(value);
    const UnitTesterCallback &callback = this->get_callback();

    if (callback)
    {
        if (value)
            callback(UnitTesterOutcome::SUCCESS, *this);
        else
            callback(UnitTesterOutcome::FAIL_DIFFERENCE, *this);
    }
    return this->get_last_result();
}

const bool &UnitTesterConditional::run_unequal_test(const bool &value)
{
    this->add_result(!value);
    const UnitTesterCallback &callback = this->get_callback();

    if (callback)
    {
        if (!value)
            callback(UnitTesterOutcome::SUCCESS, *this);
        else
            callback(UnitTesterOutcome::FAIL_SAME, *this);
    }
    return this->get_last_result();
}

UnitTesterConditional rose::make_tester()
{
    return {};
}

UnitTesterConditional rose::make_tester(const UnitTesterBase &tester)
{
    return UnitTesterConditional(tester);
}