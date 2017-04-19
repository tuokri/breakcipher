/**
 * \file stringutils.cpp
 * \brief stringutils implementation file.
 */

#include "stringutils.hpp"
#include <unordered_map>
#include <algorithm>

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

    std::string uppercase(const std::string& str)
    {
        std::string ret;
        for(const auto& c : str)
        {
            ret += std::toupper(c);
        }
        return ret;
    }

    bool is_all_unique(const std::string& str)
    {
        int ASCII_SIZE = 128;

        if(str.size() <= 1)
        {
            return true;
        }

        if(str.size() > ASCII_SIZE)
        {
            return false;
        }

        bool seen[ASCII_SIZE] = {false};
        for(auto& c : str)
        {
            if(seen[static_cast<int>(c)])
            {
                return false;
            }
            else
            {
                seen[static_cast<int>(c)] = true;
            }
        }

        return true;
    }
}
