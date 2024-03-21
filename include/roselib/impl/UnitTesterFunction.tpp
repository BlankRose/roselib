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
    bool IUnitTesterFunction::run_test
        (output_type expected, input_type args)
    {
        const output_type output = this->operator()(std::forward<Args>(args)...);
        return get_last_result();
    }
}
#undef IUnitTesterFunction