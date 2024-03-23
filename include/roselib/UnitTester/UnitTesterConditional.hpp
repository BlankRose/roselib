/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTesterConditional.hpp                              */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [10:17 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once
#include "UnitTesterBase.hpp"

namespace rose
{
    /// @brief              Unit tester class dedicated to evaluation any given
    ///                     conditionals, being the most simple unit tester of all
    class UnitTesterConditional final:
        public UnitTesterBase
    {
    public:
        /// @brief          Construct a conditional unit tester
        UnitTesterConditional();

        /// @brief          Creates a copy of the provided conditional unit tester
        ///
        /// @param rhs      Element to copy
        UnitTesterConditional(const UnitTesterConditional &rhs) = default;

        /// @brief          Constructs a conditional unit tester, from the provided
        ///                 base to allow continuity of tests
        ///
        /// @param rhs      Unit tester to take reference from
        explicit UnitTesterConditional(const UnitTesterBase &rhs);

        /// @brief          Destroys the unit tester
        ~UnitTesterConditional() override = default;

        /// @brief          Uses the condition result to updates properly
        ///                 the underlaying result structure.
        ///
        /// @param value    Condition to provide to the unit tester
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        const bool& run_test(const bool &value);

        /// @brief              Run a new test, by comparing the provided value
        ///                     to the expected value, and check if they're equal
        ///
        /// @tparam TypeLeft    Type of the first value
        /// @tparam TypeRight   Type of the second value
        /// @param lhs          First value to compare against
        /// @param rhs          Second value to compare against
        ///
        /// @return             TRUE when the test pass, otherwise FALSE
        template < class TypeLeft, class TypeRight >
        const bool& run_test(const TypeLeft &lhs, const TypeRight &rhs)
        { return this->run_test(lhs == rhs); }

        /// @brief          Uses the condition result to updates properly
        ///                 the underlaying result structure.
        ///
        /// @param value    Condition to provide to the unit tester
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        const bool& run_unequal_test(const bool &value);

        /// @brief              Run a new test, by comparing the provided value
        ///                     to the expected value, and check if they're NOT equal
        ///
        /// @tparam TypeLeft    Type of the first value
        /// @tparam TypeRight   Type of the second value
        /// @param lhs          First value to compare against
        /// @param rhs          Second value to compare against
        ///
        /// @return             TRUE when the test pass, otherwise FALSE
        template < class TypeLeft, class TypeRight >
        const bool& run_unequal_test(const TypeLeft &lhs, const TypeRight &rhs)
        { return this->run_unequal_test(lhs == rhs); }
    };

    /// @brief              Helper function to create a new conditional unit tester
    ///
    /// @return             Conditional unit tester ready for usage
    UnitTesterConditional make_tester();

    /// @brief              Helper function to create a new conditional unit tester,
    ///                     from the results of another tester for continious testing
    ///
    /// @param tester       Other tester to copy results from
    ///
    /// @return             Conditional unit tester ready for usage
    UnitTesterConditional make_tester(const UnitTesterBase &tester);
}