/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  predicates.tpp                                         */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 20, 2024 [06:08 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

namespace rose
{
    namespace _impl
    {
        template < class Array >
        bool begin_with
            (const Array *base, const size_t &size_base,
             const Array *compare, const size_t &size_compare)
        {
            size_t i = 0;
            while (i < size_base && i < size_compare && base[i] == compare[i])
                i++;
            if (i < size_compare)
                return false;
            return true;
        }

        template < class Iter >
        bool begin_with
            (const Iter &base_begin, const Iter &base_end,
             const Iter &cmp_begin, const Iter &cmp_end)
        {
            Iter it_base = base_begin;
            Iter it_cmp = cmp_begin;
            while (it_base != base_end && it_cmp != cmp_end
                && *it_base == *it_cmp)
            {
                ++it_base;
                ++it_cmp;
            }
            if (it_cmp != cmp_end)
                return false;
            return true;
        }

        template < class Char >
        bool begin_with
            (const Char *base, const Char *compare)
        {
            size_t i = 0;
            while (base[i] && compare[i] && base[i] == compare[i])
                i++;
            if (compare[i] != '\0')
                return false;
            return true;
        }

        template < class Array >
        bool end_with
            (const Array *base, const size_t &size_base,
             const Array *compare, const size_t &size_compare)
        {
            if (!size_compare)
                return true;
            if (!size_base)
                return false;
            size_t i = 1;
            while (size_base - i > 0 && size_compare - i > 0
                && base[size_base - i] == compare[size_compare - i])
                ++i;
            return size_compare - i == 0
                && base[size_base - i] == compare[size_compare - i];
        }
    }
}