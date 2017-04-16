/**
 * \file vigenere_square.cpp
 * \brief vigenere_square implementation file.
 */

#include <sstream>
#include <valarray>
#include <exception>
#include <stdexcept>

#include "vigenere_square.hpp"
#include "stringutils.hpp"

vigenere_square::vigenere_square(const std::string& i_alphabet) :
    alphabet(i_alphabet),
    table(std::vector<std::string>{alphabet.size()})
{
    if(!stringutils::is_all_unique(i_alphabet))
    {
        throw std::invalid_argument("Alphabet cannot contain duplicates.");
    }

    auto row_iter = table.begin();
    for(unsigned int i = 0; i < alphabet.size(); i++)
    {
        *row_iter++ = stringutils::shift(alphabet, -i);
    }
}

std::string vigenere_square::to_string() const
{
    std::stringstream ss;
    for(const auto& row : table)
    {
        ss << row << std::endl;
    }
    return ss.str();
}

void vigenere_square::print(std::ostream& os) const
{
    os << this->to_string();
}

void vigenere_square::set_ciper(const std::string& n_cipher)
{

}

void vigenere_square::set_key(const std::string& n_key)
{

}

void vigenere_square::set_plaintext(const std::string& n_plaintext)
{

}

std::string vigenere_square::get_ciper() const
{

}

std::string vigenere_square::get_plaintext() const
{

}

std::string vigenere_square::get_key() const
{

}

std::ostream& operator<<(std::ostream& os, const vigenere_square& vsq)
{
    os << vsq.to_string();
    return os;
}
