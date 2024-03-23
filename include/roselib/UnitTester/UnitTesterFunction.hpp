/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTesterFunction.hpp                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [08:41 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once
#include "UnitTesterBase.hpp"
#include "../impl/tester.tpp"

namespace rose
{
    /// @brief              Unit tester class dedicated to evaluating functions
    ///                     (or any callable objects)
    ///
    /// @tparam Signature   Function or callable's signature
    template < class Signature >
    class UnitTesterFunction;

    /// @brief              Unit tester class dedicated to evaluating functions
    ///                     (or any callable objects)
    ///
    /// @tparam Return      Function or callable's return type
    /// @tparam Args        Function or callable's arguments type
    template < class Return, class... Args >
    class UnitTesterFunction<Return(Args...)> final:
        public UnitTesterBase
    {
    public:
        using case_type = Return(Args...);
        using return_type = typename std::conditional<std::is_void<Return>::value, bool, Return>::type;

        /// @brief          Constructs a function unit tester
        explicit UnitTesterFunction(const case_type &function):
            UnitTesterBase(Type::FUNCTION), _function(function) {}

        /// @brief          Creates a copy of the provided function unit tester
        ///
        /// @param rhs      Element to copy
        UnitTesterFunction(const UnitTesterFunction &rhs):
            UnitTesterBase(rhs), _function(rhs._function) {}

        /// @brief          Constructs a function unit tester, from the provided
        ///                 base to allow continuity of tests
        ///
        /// @param function Function or callable to test
        /// @param rhs      Unit tester to take reference from
        UnitTesterFunction(const case_type &function, const UnitTesterBase &rhs):
            UnitTesterBase(rhs), _function(function)
        { this->_type = Type::FUNCTION; }

        /// @brief          Destroys the unit tester
        ~UnitTesterFunction() override = default;

        /// @brief          Simply calls the function, using the provided
        ///                 signature and arguments
        ///
        /// @param args     Arguments to apply to the underlaying function
        ///
        /// @return         Underlaying function's return value(s)
        Return operator()(Args... args)
        { return this->_function(std::forward<Args>(args)...); }

        /// @brief          Run a new test, by providing the given arguments
        ///                 to tested function, and checks that it doesn't throws
        ///                 any exception. Finally updates the underlaying
        ///                 result structure.
        ///
        /// @param args     Arguments to pass to the tested function
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        const bool& run_test(Args... args)
        { return _impl::run_test<Return, Args...>(*this, this->_function, std::forward<Args>(args)...); }

        /// @brief          Run a new test, by providing the given arguments
        ///                 to tested function, and compare against the given
        ///                 expected output. Finally updates the underlaying
        ///                 result structure.
        ///                 @note Return type must not be void
        ///
        /// @param args     Arguments to pass to the tested function
        /// @param expected Output expected by the function with given arguments
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        /// @note           Cannot be used if return type is void
        template < class R = Return >
        typename std::enable_if<!std::is_void<R>::value, const bool &>::type
            run_test(Args... args, const return_type &expected)
        { return _impl::run_expect_test<Return, Args...>(*this, this->_function, expected, std::forward<Args>(args)...); }

        /// @brief          Checks if the given function throws an exeption
        ///                 with the given arguments. Finally updates the underlaying
        ///                 result structure.
        ///
        /// @param args     Arguments to pass to the tested function
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        const bool& run_exception_test(Args... args)
        { return _impl::run_exception_test<Return, Args...>(*this, this->_function, std::forward<Args>(args)...); }

        /// @brief          Checks if the given function throws the expected
        ///                 exception with the given arguments. Finally updates
        ///                 the underlaying result structure.
        ///
        /// @tparam Exception   Type of the expected exception
        /// @param args         Arguments to pass to the tested function
        /// @param expected     Exception expected by the function with given arguments
        ///
        /// @return         TRUE when the test pass, otherwise FALSE
        template < class Exception >
        const bool& run_exception_test(Args... args, Exception expected)
        { return _impl::run_exception_test<Return, Args...>(*this, this->_function, expected, std::forward<Args>(args)...); }

    private:
        const std::function<case_type>    _function;
    };

    /// @brief              Helper function to create a new function unit tester
    ///
    /// @tparam Signature   Function or callable's signature
    /// @param function     Target function or callable to test
    ///
    /// @return             Function unit tester ready for usage
    template < class Signature >
    typename std::enable_if<std::is_function<Signature>::value, UnitTesterFunction<Signature>>::type
        make_tester(const Signature &function)
    { return UnitTesterFunction<Signature>(function); }

    /// @brief              Helper function to create a new function unit tester,
    ///                     from the results of another tester for continious testing
    ///
    /// @tparam Signature   Function or callable's signature
    /// @param function     Target function or callable to test
    /// @param tester       Other tester to copy results from
    ///
    /// @return             Function unit tester ready for usage
    template < class Signature >
    typename std::enable_if<std::is_function<Signature>::value, UnitTesterFunction<Signature>>::type
        make_tester(const UnitTesterBase &tester, const Signature &function)
    { return UnitTesterFunction<Signature>(function, tester); }
}