/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  predicates.hpp                                         */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 19, 2024 [03:53 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once
#include <string>

#include "impl/roselib_core.hpp"
ROSELIB_BEGIN

template < class Array >
bool begin_with(
    const Array &base, const size_t &size_base,
    const Array &compare, const size_t &size_compare);

template < class Container >
bool begin_with(
    const Container &base, const Container &compare);

template < class Iterator >
bool begin_with(
    const Iterator &base_begin, const Iterator &base_end,
    const Iterator &compare_begin, const Iterator &compare_end);

template < class Char, class Traits, class Alloc >
bool begin_with(
    const std::basic_string<Char, Traits, Alloc> &base,
    const std::basic_string<Char, Traits, Alloc> &compare);

bool begin_with(
    const char *base, const char *compare);

ROSELIB_END
#include "impl/predicates.tpp"