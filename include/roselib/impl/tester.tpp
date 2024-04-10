/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  tester.tpp                                             */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [08:40 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

#include <functional>
#include "roselib/UnitTester/UnitTesterBase.hpp"

namespace rose
{
    namespace _impl
    {
        template < class Result, class... Args >
        const bool &run_test
            (UnitTesterBase &results,
             std::function<Result(Args...)> function,
             Args... args)
        {
            bool exception;
            try
            {
                function(std::forward<Args>(args)...);
                exception = false;
            }
            catch (...)
            {
                exception = true;
            }

            results.add_result(!exception);
            const UnitTesterCallback &callback = results.get_callback();

            if (callback)
            {
                if (!exception)
                    callback(UnitTesterOutcome::SUCCESS, results);
                else
                    callback(UnitTesterOutcome::FAIL_THROW, results);
            }
            return results.get_last_result();
        }

        template < class Return, class... Args >
        const bool &run_expect_test
            (UnitTesterBase &results,
             std::function<Return(Args...)> function,
             const Return &expected, Args... args)
        {
            bool result;
            bool exception;
            try
            {
                const Return output = function(std::forward<Args>(args)...);
                result = expected == output;
                exception = false;
            }
            catch (...)
            {
                result = false;
                exception = true;
            }

            results.add_result(result);
            const UnitTesterCallback &callback = results.get_callback();

            if (callback)
            {
                if (result)
                    callback(UnitTesterOutcome::SUCCESS, results);
                else if (exception)
                    callback(UnitTesterOutcome::FAIL_THROW, results);
                else
                    callback(UnitTesterOutcome::FAIL_DIFFERENCE, results);
            }
            return results.get_last_result();
        }

        template < class Return, class... Args >
        const bool &run_exception_test
            (UnitTesterBase &results,
             std::function<Return(Args...)> function,
             Args... args)
        {
            bool exception;
            try
            {
                function(std::forward<Args>(args)...);
                exception = false;
            }
            catch (...)
            {
                exception = true;
            }

            results.add_result(exception);
            const UnitTesterCallback &callback = results.get_callback();

            if (callback)
            {
                if (exception)
                    callback(UnitTesterOutcome::SUCCESS, results);
                else
                    callback(UnitTesterOutcome::FAIL_NO_THROW, results);
            }
            return results.get_last_result();
        }

        template < class Return, class... Args, class Exception >
        const bool &run_exception_test
            (UnitTesterBase &results,
             std::function<Return(Args...)> function,
             const Exception&, Args... args)
        {
            bool result = false;
            bool exception;
            try
            {
                function(std::forward<Args>(args)...);
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

            results.add_result(result);
            const UnitTesterCallback &callback = results.get_callback();

            if (callback)
            {
                if (result)
                    callback(UnitTesterOutcome::SUCCESS, results);
                else if (exception)
                    callback(UnitTesterOutcome::FAIL_DIFFERENCE, results);
                else
                    callback(UnitTesterOutcome::FAIL_NO_THROW, results);
            }
            return results.get_last_result();
        }
    }
}