/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  begin_with.hpp                                         */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 19, 2024 [03:53 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

#include <string>
#include "../impl/predicates.tpp"

namespace rose
{
    /// @brief                  Checks if the given array BASE starts with the
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
    bool begin_with
        (const Array *base, const size_t &size_base,
         const Array *compare, const size_t &size_compare)
    { return _impl::begin_with<Array>(base, size_base, compare, size_compare); }

    /// @brief                  Checks if the given array BASE starts with the
    ///                         exact provided VALUE
    ///
    /// @tparam Array           Type of the array
    /// @tparam Value           Type of the reference value
    /// @param base             Array to check the condition on
    /// @param value            Reference value to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Array, class Value >
    bool begin_with
        (const Array *base, const Value &value)
    { return *base == value; }

    /// @brief                  Checks if the given CONTAINER starts with the
    ///                         same content as the provided reference COMPARE
    ///
    /// @tparam Container       Type of the container
    /// @param base             Container to check the condition on
    /// @param compare          Reference container to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Container >
    bool begin_with
        (const Container &base, const Container &compare)
    { return _impl::begin_with(base.cbegin(), base.cend(), compare.cbegin(), compare.cend()); }

    /// @brief                  Checks if the given CONTAINER starts with the
    ///                         exact provided VALUE
    ///
    /// @tparam Container       Type of the container
    /// @param base             Container to check the condition on
    /// @param value            Reference value to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    template < class Container >
    bool begin_with
        (const Container &base, const typename Container::value_type &value)
    { return *base.cbegin() == value; }

    /// @brief                  Iterates throught iterator ranges to check if
    ///                         BASE range starts with the same content as the
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
    bool begin_with
        (const Iterator &base_begin, const Iterator &base_end,
         const Iterator &compare_begin, const Iterator &compare_end)
    { return _impl::begin_with<Iterator>(base_begin, base_end, compare_begin, compare_end); }

    /// @brief                  Checks if the given BASE string starts with the
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
    bool begin_with
        (const std::basic_string<Char, Traits, Alloc> &base,
         const std::basic_string<Char, Traits, Alloc> &compare)
    { return _impl::begin_with<Char>(base.c_str(), compare.c_str()); }

    /// @brief                  Checks if the given BASE string starts with the
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
    bool begin_with
        (const std::basic_string<Char, Traits, Alloc> &base, const Char *compare)
    { return _impl::begin_with<Char>(base.c_str(), compare); }

    /// @brief                  Checks if the given BASE string starts with the
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
    bool begin_with
        (const Char *base, const std::basic_string<Char, Traits, Alloc> &compare)
    { return _impl::begin_with<Char>(base, compare.c_str()); }

    /// @brief                  Checks if the given BASE string starts with the
    ///                         same characters as the one provided in the COMPARE's
    ///                         string (C-String to C-String)
    ///
    /// @param base             String to check the condition on
    /// @param compare          Reference string to check condition from
    ///
    /// @return                 TRUE if condition is fulfilled, otherwise FALSE
    inline bool begin_with
        (const char *base, const char *compare)
    { return _impl::begin_with<char>(base, compare); }
}
