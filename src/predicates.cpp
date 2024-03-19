#include "roselib/predicates.hpp"

bool ROSELIB_NAMESPACE::begin_with(
    const char *base, const char *compare)
{
    size_t i = 0;
    while (base[i] && compare[i] && base[i] == compare[i])
        i++;
    if (compare[i] != '\0')
        return false;
    return true;
}