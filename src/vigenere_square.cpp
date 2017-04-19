/**
 * \file vigenere_square.cpp
 * \brief vigenere_square implementation file.
 */

#include <sstream>
#include <exception>
#include <stdexcept>

#include "vigenere_square.hpp"
#include "stringutils.hpp"

vigenere_square::vigenere_square() {}

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

vigenere_square& vigenere_square::operator=(const vigenere_square& rhs)
{
    if(this == &rhs) return *this;

    this->alphabet = rhs.alphabet;
    this->table = rhs.table;

    return *this;
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

std::string vigenere_square::encrypt(const std::string& plaintext,
                                     const std::string& key)
{
    std::string cipher;
    char char_key;
    int col_key = 0;
    int row_plain = 0;
    int k = 0;

    for(const auto& char_plain : plaintext)
    {
        char_key = key[k];
        k = (k + 1) % key.size();
        col_key = alphabet.find(char_key);
        row_plain = alphabet.find(char_plain);
        cipher += table[row_plain][col_key];
    }

    return cipher;
}

std::string vigenere_square::decrypt(const std::string& cipher,
                                     const std::string& key)
{
    std::string plaintext;
    char char_key;
    int col_key = 0;
    int k = 0;

    for(const auto& char_cipher : cipher)
    {
        char_key = key[k];
        k = (k + 1) % key.size();
        col_key = alphabet.find(char_key);

        int row_plain = 0;
        for(const auto& row : table)
        {
            if(row[col_key] == char_cipher)
            {
                break;
            }
            row_plain++;
        }

        plaintext += alphabet[row_plain];
    }

    return plaintext;
}

std::ostream& operator<<(std::ostream& os, const vigenere_square& vsq)
{
    os << vsq.to_string();
    return os;
}
