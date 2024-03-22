/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTesterFunction.tpp                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 21, 2024 [01:32 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once
#include "roselib/UnitTester/UnitTesterFunction.hpp"

#define IUnitTesterFunction UnitTesterFunction<Return, Args...> // Helper define
namespace rose
{
    template < class Return, class... Args >
    IUnitTesterFunction::UnitTesterFunction():
        UnitTesterBase(Type::FUNCTION)
    {}

    template < class Return, class... Args >
    typename IUnitTesterFunction::output_type
        IUnitTesterFunction::operator()(input_type args)
    {
        return this->_function(std::forward<Args>(args)...);
    }

    template < class Return, class... Args >
    const bool &IUnitTesterFunction::run_test
        (output_type expected, input_type args)
    {
        bool result;
        bool exception;
        try
        {
            const output_type output = this->operator()(std::forward<Args>(args)...);
            result = expected == output;
            exception = false;
        }
        catch (...)
        {
            result = false;
            exception = true;
        }

        add_result(result);
        if (this->_callback)
        {
            if (result)
                this->_callback(UnitTesterOutcome::SUCCESS);
            else if (exception)
                this->_callback(UnitTesterOutcome::FAIL_THROW);
            else
                this->_callback(UnitTesterOutcome::FAIL_DIFFERENCE);
        }
        return get_last_result();
    }

    template < class Return, class... Args >
    template < class Exception >
    const bool &
        IUnitTesterFunction::run_exception_test(input_type args)
    {
        bool result = false;
        bool exception;
        try
        {
            const output_type output = this->operator()(std::forward<Args>(args)...);
            exception = false;
        }
        catch (const Exception &)
        {
            result = true;
            exception = true;
        }
        catch (...)
        {
            exception = true;
        }

        add_result(result);
        if (this->_callback)
        {
            if (result)
                this->_callback(UnitTesterOutcome::SUCCESS);
            else if (exception)
                this->_callback(UnitTesterOutcome::FAIL_DIFFERENCE);
            else
                this->_callback(UnitTesterOutcome::FAIL_NO_THROW);
        }
        return get_last_result();
    }

    template < class Return, class... Args >
    const bool &IUnitTesterFunction::run_exception_test(input_type args)
    {
        bool exception;
        try
        {
            const output_type output = this->operator()(std::forward<Args>(args)...);
            exception = false;
        }
        catch (...)
        {
            exception = true;
        }

        add_result(exception);
        if (this->_callback)
        {
            if (exception)
                this->_callback(UnitTesterOutcome::SUCCESS);
            else
                this->_callback(UnitTesterOutcome::FAIL_NO_THROW);
        }
        return get_last_result();
    }

}
#undef IUnitTesterFunction