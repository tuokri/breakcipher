/**
 * \file vigenere_square.hpp
 * \brief vigenere_square header file.
 */

#ifndef VIGENERE_SQUARE_H
#define VIGENERE_SQUARE_H

#include <string>
#include <vector>

/**
 * \class vigenere_square
 * \brief Represents a Vigenère square initialized with a certain alphabet,
 *        to which strings can be passed for encryption or decryption.
 */
class vigenere_square
{
    public:

        /**
         * \brief Default constructor.
         */
        vigenere_square();

        /**
         * \brief Parametrized constructor.
         *        If i_alphabet contains duplicates, an exception is thrown.
         * \param i_alphabet String to represent available characters.
         * \throw std::invalid_argument.
         */
        vigenere_square(const std::string& i_alphabet);

        /**
         * \brief Default destructor.
         */
        virtual ~vigenere_square() = default;

        /**
         * \brief operator= overload. Copy assignment.
         * \param rhs Reference to vigenere_square.
         * \return Reference to vigenere_square.
         */
        vigenere_square& operator=(const vigenere_square& rhs);

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

        /**
         * \brief Encrypt a string using the vigenere_square instance's
         *        data member table.
         * \param plaintext Reference to the string to be encrypted.
         * \param key Reference to the key used in encryption.
         * \return Encrypted string.
         */
        std::string encrypt(const std::string& plaintext,
                            const std::string& key);

        /**
         * \brief Decrypt a string using the vigenere_square instance's
         *        data member table.
         * \param cipher Reference to the string to be decrypted.
         * \param key Reference to the key used in decryption.
         * \return Decrypted string.
         */
        std::string decrypt(const std::string& chipher,
                            const std::string& key);

    private:
        std::string alphabet;
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
