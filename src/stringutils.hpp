/**
 * \file stringutils.hpp
 * \brief stringutils header file.
 */

#ifndef STRINGUTILS_HPP_INCLUDED
#define STRINGUTILS_HPP_INCLUDED

#include <string>

namespace stringutils
{
    std::string shift(const std::string& str, int i);

    bool is_all_unique(const std::string& str);
}

#endif // STRINGUTILS_HPP_INCLUDED
