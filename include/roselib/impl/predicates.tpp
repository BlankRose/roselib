/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  predicates.tpp                                         */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 19, 2024 [04:22 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

#include "roselib_core.hpp"
#include "../predicates.hpp"

template < class Array >
bool ROSELIB_NAMESPACE::begin_with(
    const Array &base, const size_t &size_base,
    const Array &compare, const size_t &size_compare)
{
    size_t i = 0;
    while (i < size_base && i < size_compare && base[i] == compare[i])
        i++;
    if (i < size_compare)
        return false;
    return true;
}

template < class Container >
bool ROSELIB_NAMESPACE::begin_with(
    const Container &base, const Container &compare)
{
    return begin_with(base.cbegin(), base.cend(), compare.cbegin(), compare.cend());
}

template < class Iterator >
bool ROSELIB_NAMESPACE::begin_with(
    const Iterator &base_begin, const Iterator &base_end,
    const Iterator &compare_begin, const Iterator &compare_end)
{
    size_t i = 0;
    while (base_begin + i != base_end && compare_begin + i != compare_end
        && *(base_begin + i) == *(compare_begin + i))
        i++;
    if (compare_begin + i != compare_end)
        return false;
    return true;
}

template < class Char, class Traits, class Alloc >
bool ROSELIB_NAMESPACE::begin_with(
    const std::basic_string<Char, Traits, Alloc> &base,
    const std::basic_string<Char, Traits, Alloc> &compare)
{
    size_t i = 0;
    while (base[i] && compare[i] && base[i] == compare[i])
        i++;
    if (compare[i] != '\0')
        return false;
    return true;
}