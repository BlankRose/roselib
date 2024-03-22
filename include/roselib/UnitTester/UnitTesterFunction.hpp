/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTesterFunction.hpp                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 21, 2024 [11:20 am]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

#include <functional>
#include "UnitTesterBase.hpp"

namespace rose
{
    /// @brief          Unit tester class dedicated to evaluating functions
    ///                 (or any callable objects)
    ///
    /// @tparam Return  Function or callable's return type
    /// @tparam Args    Arguments list of the signature
    template < class Return, class... Args >
    class UnitTesterFunction final:
        public UnitTesterBase
    {
    public:
        using case_type     = std::function<Return(Args...)>;
        using output_type   = typename case_type::result_type;
        using input_type    = typename case_type::argument_type;

        /// @brief          Constructs a function unit tester
        UnitTesterFunction();

        /// @brief          Simply calls the function, using the provided
        ///                 signature and arguments
        ///
        /// @param args     Arguments to apply to the underlaying function
        ///
        /// @return         Underlaying function's return value(s)
        output_type operator()(input_type args);

        /// @brief          Run a new test, by providing the given arguments
        ///                 to tested function, and compare against the given
        ///                 expected output. Finally updates the underlaying
        ///                 result structure.
        ///
        /// @param expected Output expected by the function with given arguments
        /// @param args     Arguments to pass to the tested function
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        const bool& run_test(output_type expected, input_type args);

        /// @brief          Checks if the given function throws the expected
        ///                 exception with the given arguments. Finally updates
        ///                 the underlaying result structure.
        ///
        /// @tparam Exception   Type of the expected exception
        /// @param args         Arguments to pass to the tested function
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        template < class Exception >
        const bool& run_exception_test(input_type args);

        /// @brief          Checks if the given function throws an exeption
        ///                 with the given arguments. Finally updates the underlaying
        ///                 result structure.
        ///
        /// @param args     Arguments to pass to the tested function
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        const bool& run_exception_test(input_type args);

    private:
        const case_type     _function;
    };
}

#include "../impl/UnitTesterFunction.tpp"