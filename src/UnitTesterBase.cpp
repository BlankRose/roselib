/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTesterBase.cpp                                     */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 21, 2024 [07:29 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "roselib/UnitTester.hpp"
using namespace rose;

UnitTesterCallback UnitTesterBase::_default_callback = nullptr;

UnitTesterBase::UnitTesterBase(const Type &type, const bool &last) noexcept:
    _result(0, 0, last), _type(type), _callback(nullptr)
{}

UnitTesterBase::UnitTesterBase(const Type &type, const size_t &success, const size_t &fails, const bool &last) noexcept:
    _result(success, fails, last), _type(type), _callback(nullptr)
{}

UnitTesterBase &UnitTesterBase::operator=(const UnitTesterBase &rhs) noexcept
{
    this->_type           = rhs._type;
    this->_result.last    = rhs._result.last;
    this->_result.total   = rhs._result.total;
    this->_result.success = rhs._result.success;
    this->_result.fails   = rhs._result.fails;
    this->_callback       = rhs._callback;
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

const UnitTesterBase::callback_type &UnitTesterBase::get_callback() const noexcept
{
    if (this->_callback)
        return this->_callback;
    return _default_callback;
}

const UnitTesterBase::callback_type &UnitTesterBase::get_default_callback() noexcept
{
    return _default_callback;
}

void UnitTesterBase::set_callback(const callback_type &callback) noexcept
{
    this->_callback = callback;
}

void UnitTesterBase::set_default_callback(const callback_type &callback) noexcept
{
    _default_callback = callback;
}

void UnitTesterBase::clear_result() noexcept
{
    this->_result.total = 0;
    this->_result.success = 0;
    this->_result.fails = 0;
}

void UnitTesterBase::add_fail(const ssize_t &count) noexcept
{
    this->_result.fails += count;
    this->_result.total += count;
    this->_result.last = false;
}

void UnitTesterBase::add_success(const ssize_t &count) noexcept
{
    this->_result.success += count;
    this->_result.total += count;
    this->_result.last = true;
}

void UnitTesterBase::add_result(const bool &result) noexcept
{
    if (result)
        ++this->_result.success;
    else
        ++this->_result.fails;
    ++this->_result.total;
    this->_result.last = result;
}