/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTester.cpp                                         */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 20, 2024 [06:23 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "roselib/UnitTester.hpp"
using namespace rose;

UnitTesterBase::UnitTesterBase(const Type &type, const bool &last) noexcept:
    _result(0, 0, last), _type(type)
{}

UnitTesterBase &UnitTesterBase::operator=(const UnitTesterBase &rhs) noexcept
{
    this->_type           = rhs._type;
    this->_result.last    = rhs._result.last;
    this->_result.total   = rhs._result.total;
    this->_result.success = rhs._result.success;
    this->_result.fails   = rhs._result.fails;
    return *this;
}

const UnitTesterBase::result_type &UnitTesterBase::get_result() const noexcept
{
    return this->_result;
}

const bool &UnitTesterBase::get_last_result() const noexcept
{
    return this->_result.last;
}

const UnitTesterBase::Type &UnitTesterBase::get_type() const noexcept
{
    return this->_type;
}

void UnitTesterBase::clear_result() noexcept
{
    this->_result.total = 0;
    this->_result.success = 0;
    this->_result.fails = 0;
}