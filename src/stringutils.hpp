/**
 * \file stringutils.hpp
 * \brief stringutils header file.
 */

#ifndef STRINGUTILS_HPP_INCLUDED
#define STRINGUTILS_HPP_INCLUDED

#include <string>

namespace stringutils
{
    /**
     * \brief Circular shift (rotate) of string.
     * \param str Reference to string shift.
     * \param i How many times to shif the string.
              Negative values indicate left shift, positives right shift.
     * \return A copy of the original string, shifted.
     */
    std::string shift(const std::string& str, int i);

    /**
     * \brief Copies a string and converts the copy to uppercase.
     * \param str Reference to string to convert.
     * \return Uppercase copy of the original string.
     */
    std::string uppercase(const std::string& str);

    /**
     * \brief Checks if string contains all unique characters (no duplicates).
     * \param str Reference to string to check for uniqueness.
     * \return true if all unique, else false.
     */
    bool is_all_unique(const std::string& str);
}

#endif // STRINGUTILS_HPP_INCLUDED
