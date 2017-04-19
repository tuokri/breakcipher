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

    std::string uppercase(const std::string& str);

    bool is_all_unique(const std::string& str);
}

#endif // STRINGUTILS_HPP_INCLUDED
