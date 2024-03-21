/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTesterBase.hpp                                     */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 21, 2024 [11:22 am]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"

namespace rose
{
    /// @brief      Base implementation of a specialized unit tester class
    class UnitTesterBase
    {
    public:
        using Type          = UnitTesterType;
        using result_type   = UnitTesterResult;

        /// @brief          Default base constructor (DISABLED)
        UnitTesterBase() = delete;

        /// @brief          Construct and define its type
        ///
        /// @param type     Type of the unit tester
        /// @param last     [Optional] Define the value of last test result
        explicit UnitTesterBase(const Type &type, const bool &last = true) noexcept;

        /// @brief          Construct and pre-define the whole result
        ///
        /// @param type     Type of the unit tester
        /// @param success  How many success it should starts with
        /// @param fails    How many failures it should starts with
        /// @param last     [Optional] Define the value of last test result
        UnitTesterBase(const Type &type, const size_t &success, const size_t &fails, const bool &last = true) noexcept;

        /// @brief          Construct the base using another base
        /// @param rhs      Element to copy
        UnitTesterBase(const UnitTesterBase &rhs) noexcept = default;

        /// @brief          Base desctructor
        virtual ~UnitTesterBase() = default;

        /// @brief          Copies right hand side element into the element
        ///
        /// @param rhs      Element to copy
        /// @return         This base object
        UnitTesterBase& operator=(const UnitTesterBase &rhs) noexcept;

        /// @brief          Clear the currently stored results
        void clear_result() noexcept;

        /// @brief          Retrieves the current information about the on-going tests
        ///
        /// @return         Structure containing various information (@class UnitTesterResult)
        [[nodiscard]] const result_type& get_result() const noexcept;

        /// @brief          Retrieves the status of the last test
        ///                 (always returns TRUE when no test was complete yet)
        ///
        /// @return         TRUE on Success, or FALSE on Failure
        [[nodiscard]] const bool& get_last_result() const noexcept;

        /// @brief          Retrieves the type of the the unit tester
        ///
        /// @return         Enum value (@class UnitTesterType)
        [[nodiscard]] const Type& get_type() const noexcept;

        void add_fail() noexcept;
        void add_fail(const size_t &count) noexcept;

        void add_success() noexcept;
        void add_success(const size_t &count) noexcept;

    protected:
        result_type         _result;
        Type                _type;
    };
}