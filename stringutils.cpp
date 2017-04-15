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
        if(i < 0) // Shift left.
        {
            i = -i;
            ret = str.substr(i, str.size() - i) + str.substr(0, i);
        }
        else
        {
            std::cout << "here";
        }

        return ret;
    }
}
