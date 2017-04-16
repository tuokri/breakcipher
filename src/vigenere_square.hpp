/**
 * \file vigenere_square.hpp
 * \brief vigenere_square header file.
 */

#ifndef VIGENERE_SQUARE_H
#define VIGENERE_SQUARE_H

#include <string>
#include <vector>

/**
 * \class vigenere_Square
 * \brief
 */
class vigenere_square
{
    public:
        /**
         * \brief Default constructor.
         */
        vigenere_square() = delete;

        /**
         * \brief Parametrized constructor.
         * \param i_alphabet String to represent available characters.
         */
        vigenere_square(const std::string& i_alphabet);

        /**
         * \brief Default destructor.
         */
        virtual ~vigenere_square() = default;

        /**
         * \brief String representation of the Vigenère table.
         * \return std::string.
         */
        std::string to_string() const;

        /**
         * \brief Print string representation to std::ostream.
         * \param os Reference to std::ostream.
         */
        void print(std::ostream& os) const;

    private:
        const std::string alphabet;
        std::vector<std::string> table;
};

/**
 * \brief operator<< overload.
 * \param os Reference to std::ostream.
 * \param vsq Reference to vigenere_square.
 * \return Reference to std::ostream.
 */
std::ostream& operator<<(std::ostream& os, const vigenere_square& vsq);

#endif // VIGENERE_SQUARE_H
