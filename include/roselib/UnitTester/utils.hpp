/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  utils.hpp                                              */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 21, 2024 [10:06 am]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once
#include <sys/types.h>

namespace rose
{
    /// @brief      Enumeration of tested features,
    ///             mostly used by @class UnitTester
    enum class UnitTesterType
    {
        UNKNOWN,                    // Test case is unknown
        FUNCTION,                   // Test case is callable
        OBJECT,                     // Test case is an object
    };

    /// @brief      Enumeration of the possible outcomes
    ///             for the tested features
    enum class UnitTesterOutcome
    {
        SUCCESS,                    // Test passed
        FAIL_DIFFERENCE,            // Test failed because the returned value(s) were different than expected
        FAIL_NO_THROW,              // Test failed because no exception was thrown in an exception test
        FAIL_THROW,                 // Test failed because an exception was thrown in a non-exception test
    };

    /// @brief      Structions which keep track of various informations
    ///             about an on-going test
    struct UnitTesterResult
    {
        /// @brief          Default constructor
        UnitTesterResult() = default;

        /// @brief          Constructs the result struct from pre-defined values
        ///
        /// @param success  Amount of test which returned the expected value(s)
        /// @param fails    Amount of test which didn't return the expected value(s)
        /// @param last     Last test's result (TRUE = Success, FALSE = Failure)
        UnitTesterResult(const size_t &success, const size_t &fails, const size_t &last):
            total(success + fails), success(success), fails(fails), last(last) {}

        size_t      total   = 0;    // Amount of test completed
        size_t      success = 0;    // Amount of test which returned the expected value(s)
        size_t      fails   = 0;    // Amount of test which didn't return the expected value(s)
        bool        last    = true; // Last test's result (TRUE = Success, FALSE = Failure)
    };

    using UnitTesterCallback = void(*)(const UnitTesterOutcome &);
}