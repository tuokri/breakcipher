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

    this->cipher = rhs.cipher;
    this->key = rhs.key;
    this->plaintext = rhs.plaintext;

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

void vigenere_square::print(std::ostream& os) const
{
    os << this->to_string();
}

int vigenere_square::find_keycolindex(char keychar)
{
    bool found = false;
    unsigned int i;

    for(i = 0; i < alphabet.size(); i++)
    {
        if(alphabet[i] == keychar)
        {
            found = true;
            break;
        }
    }

    if(found)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int vigenere_square::find_plainrowindex(int keycolindex, char plainchar)
{
    if(keycolindex < 0 || keycolindex >= static_cast<int>(alphabet.size()))
    {
        std::stringstream ss;
        ss << "keycolindex out of range [0," << alphabet.size() <<
              "[ " << "where keycolindex is " << keycolindex << ".";

        throw std::invalid_argument(ss.str());
    }

    return alphabet.find(plainchar);
}

std::string vigenere_square::encrypt(const std::string& str_plain,
                                     const std::string& key)
{

    std::string cipher;
    char keychar;
    int kci = 0;
    int pci = 0;
    int k = 0;

    for(const auto& plainchar : str_plain)
    {
        keychar = key[k];
        k = (k + 1) % key.size();
        kci = find_keycolindex(keychar);
        pci = find_plainrowindex(kci, plainchar);
        cipher += table[pci][kci];
    }

    return cipher;

    /*
    char keychar = key[0];
    int keyrowindex = find_keyrowindex(keychar);

    char plainchar = str_plain[0];
    int plaincharindex = find_plaincharindex(keyrowindex, plainchar);

    char cipherchar = table[0][plaincharindex];
    */
}

std::string vigenere_square::decrypt(const std::string& str_cipher,
                                     const std::string& key)
{
    return std::string{str_cipher};
}

void vigenere_square::set_cipher(const std::string& n_cipher)
{
    cipher = n_cipher;
}

void vigenere_square::set_key(const std::string& n_key)
{
    key = n_key;
}

void vigenere_square::set_plaintext(const std::string& n_plaintext)
{
    plaintext = n_plaintext;
}

std::string vigenere_square::get_cipher() const
{
    return cipher;
}

std::string vigenere_square::get_plaintext() const
{
    return plaintext;
}

std::string vigenere_square::get_key() const
{
    return key;
}

std::string vigenere_square::get_alphabet() const
{
    return alphabet;
}

std::ostream& operator<<(std::ostream& os, const vigenere_square& vsq)
{
    os << vsq.to_string();
    return os;
}
