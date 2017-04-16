/**
 * \file stringutils.cpp
 * \brief stringutils implementation file.
 */

#include "stringutils.hpp"
#include <iostream>

namespace stringutils
{
    std::string shift(const std::string& str, int i)
    {
        if(i == 0 || i == static_cast<int>(str.size()))
        {
            return str;
        }

        std::string ret;
        if(i < 0)
        {
            i = -i;
            ret = str.substr(i, str.size() - i) + str.substr(0, i);
        }
        else
        {
            ret = str.substr(str.size() - i, str.size()) +
                  str.substr(0, str.size() - i);
        }

        return ret;
    }
}
