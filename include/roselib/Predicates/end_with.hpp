/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  end_with.hpp                                           */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 24, 2024 [01:55 am]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iterator>
#include "../impl/predicates.tpp"

namespace rose
{
    /// @brief                  Checks if the given array BASE ends with the
    ///                         same content as the other array COMPARE
    ///
    /// @tparam Array           Type of the arrays
    /// @param  base            Array to check the condition on
    /// @param  size_base       Size of the BASE array
    /// @param  compare         Reference array to check condition from
    /// @param  size_compare    Size of the COMPARE array
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Array >
    bool end_with
        (const Array *base, const size_t &size_base,
         const Array *compare, const size_t &size_compare)
    { return _impl::end_with<Array>(base, size_base, compare, size_compare); }

    /// @brief                  Checks if the given array BASE ends with the
    ///                         exact provided VALUE
    ///
    /// @tparam Array           Type of the array
    /// @tparam Value           Type of the reference value
    /// @param base             Array to check the condition on
    /// @param size_base        Size of the BASE array
    /// @param value            Reference value to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Array, class Value >
    bool end_with
        (const Array *base, const size_t &size_base, const Value &value)
    { return base[size_base - 1] == value; }

    /// @brief                  Checks if the given CONTAINER ends with the
    ///                         same content as the provided reference COMPARE
    ///
    /// @tparam Container       Type of the container
    /// @param base             Container to check the condition on
    /// @param compare          Reference container to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Container >
    bool end_with
        (const Container &base, const Container &compare)
    { return _impl::begin_with(base.crbegin(), base.crend(), compare.crbegin(), compare.crend()); }

    /// @brief                  Checks if the given CONTAINER ends with the
    ///                         exact provided VALUE
    ///
    /// @tparam Container       Type of the container
    /// @param base             Container to check the condition on
    /// @param value            Reference value to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Container >
    bool end_with
        (const Container &base, const typename Container::value_type &value)
    { return *base.crbegin() == value; }

    /// @brief                  Iterates throught iterator ranges to check if
    ///                         BASE range ends with the same content as the
    ///                         ones provided within the COMPARE range
    ///
    /// @tparam Iterator        Type of the iterators
    /// @param base_begin       Start of the base's range
    /// @param base_end         End of the base's range
    /// @param compare_begin    Start of the comparator range
    /// @param compare_end      End of te comparator's range
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Iterator >
    bool end_with
        (const Iterator &base_begin, const Iterator &base_end,
         const Iterator &compare_begin, const Iterator &compare_end)
    {
        return _impl::begin_with
            (std::reverse_iterator<Iterator>(base_end),    std::reverse_iterator<Iterator>(base_begin),
             std::reverse_iterator<Iterator>(compare_end), std::reverse_iterator<Iterator>(compare_begin));
    }

    /// @brief                  Checks if the given BASE string ends with the
    ///                         same characters as the one provided in the COMPARE's
    ///                         string (std::String to std::String)
    ///
    /// @tparam Char            Type of the character for the string
    /// @tparam Traits          Traits of character CHAR
    /// @tparam Alloc           Allocator type, used by std::basic_string
    /// @param base             String to check the condition on
    /// @param compare          Reference string to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Char, class Traits, class Alloc >
    bool end_with
        (const std::basic_string<Char, Traits, Alloc> &base,
         const std::basic_string<Char, Traits, Alloc> &compare)
    { return _impl::begin_with(base.crbegin(), base.crbegin(), compare.crbegin(), compare.crend()); }

    /// @brief                  Checks if the given BASE string ends with the
    ///                         same characters as the one provided in the COMPARE's
    ///                         string (std::String to C-String)
    ///
    /// @tparam Char            Type of the character for the string
    /// @tparam Traits          Traits of character CHAR
    /// @tparam Alloc           Allocator type, used by std::basic_string
    /// @param base             String to check the condition on
    /// @param compare          Reference string to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Char, class Traits, class Alloc >
    bool end_with
        (const std::basic_string<Char, Traits, Alloc> &base, const Char *compare)
    { return end_with(base, std::basic_string<Char, Traits, Alloc>(compare)); }

    /// @brief                  Checks if the given BASE string ends with the
    ///                         same characters as the one provided in the COMPARE's
    ///                         string (C-String to std::String)
    ///
    /// @tparam Char            Type of the character for the string
    /// @tparam Traits          Traits of character CHAR
    /// @tparam Alloc           Allocator type, used by std::basic_string
    /// @param base             String to check the condition on
    /// @param compare          Reference string to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Char, class Traits, class Alloc >
    bool end_with
        (const Char *base, const std::basic_string<Char, Traits, Alloc> &compare)
    { return end_with(std::basic_string<Char, Traits, Alloc>(base), compare); }

    /// @brief                  Checks if the given BASE string ends with the
    ///                         same characters as the one provided in the COMPARE's
    ///                         string (C-String to C-String)
    ///
    /// @param base             String to check the condition on
    /// @param compare          Reference string to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    inline bool end_with
        (const char *base, const char *compare)
    { return _impl::end_with<char>(base, compare); }
}