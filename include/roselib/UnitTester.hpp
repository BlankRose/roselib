/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTester.hpp                                         */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 20, 2024 [06:21 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

#include <functional>
#include "UnitTester/UnitTesterBase.hpp"

namespace rose
{
    /// @brief      Provides an easy interface for unit testing various
    ///             functions, classes and other various features
    template < class Signature >
    class UnitTesterFunction
    {
    public:
        using case_type     = Signature;
        using result_type   = UnitTesterResult;

        void set_test(const case_type &function);
        template < class... Args >
        void run_test(Args... args) const;
        void remove_test() noexcept;

        const result_type &get_result() const noexcept;
        void reset_results();

    protected:
        case_type           tested;
        result_type         result;
    };

    template < class Signature >
    void UnitTesterFunction<Signature>::set_test(const case_type &function)
    {
        reset_results();
    }

    template < class Signature >
    template < class... Args >
    void UnitTesterFunction<Signature>::run_test(Args... args) const
    {
        this->tested(std::forward<Args>(args)...);
    }
}