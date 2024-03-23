/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTesterBase.hpp                                     */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [08:41 pm]                */
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
        using Outcome       = UnitTesterOutcome;
        using result_type   = UnitTesterResult;
        using callback_type = UnitTesterCallback;

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

        /// @brief          Retrieves the used callback, called whenever
        ///                 a test is performed
        ///
        /// @return         Pointer to callback function (@class UnitTesterCallback)
        [[nodiscard]] const callback_type& get_callback() const noexcept;

        /// @brief          Retrieves the default callback, called whenever
        ///                 a test is performed and a callback wasn't defined
        ///
        /// @return         Pointer to callback function (@class UnitTesterCallback)
        [[nodiscard]] static const callback_type& get_default_callback() noexcept;

        /// @brief          Define the callback function, called whenever
        ///                 a test is performed
        ///
        /// @param callback Pointer to callback function (@class UnitTesterCallback)
        void set_callback(const callback_type &callback) noexcept;

        /// @brief          Define the default callback function, called whenever
        ///                 a test is performed and a callback wasn't defined
        ///
        /// @param callback Pointer to callback function (@class UnitTesterCallback)
        static void set_default_callback(const callback_type &callback) noexcept;

        /// @brief          Manually adds fails to the counter
        /// @param count    Amount of fails
        void add_fail(const ssize_t &count = 1) noexcept;

        /// @brief          Manually adds success to the counter
        /// @param count    Amount of success
        void add_success(const ssize_t &count = 1) noexcept;

        /// @brief          Manually adds a new result to the counter
        /// @param result   New result
        void add_result(const bool &result) noexcept;

    protected:
        result_type             _result;
        Type                    _type;
        callback_type           _callback;
        static callback_type    _default_callback;
    };
}
