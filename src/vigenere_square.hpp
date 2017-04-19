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

        /** TODO: DOCS
         *
         */
        int find_keycolindex(char keychar);

        /** TODO: DOCS
         *
         */
        int find_plainrowindex(int keycolindex, char plainchar);

        /**
         * \brief Encrypt a string using the vigenere_square instance's
         *        data member table.
         * \param Reference to the string to be encrypted.
         * \return Encrypted string.
         */
        std::string encrypt(const std::string& str_plain,
                            const std::string& key);

        /**
         * \brief Decrypt a string using the vigenere_square instance's
         *        data member table.
         * \param Reference to the string to be decrypted.
         * \return Decrypted string.
         */
        std::string decrypt(const std::string& str_cipher,
                            const std::string& key);

        /**
         *  \name Data member mutators.
         */
        //@{
        /**
         * \param n_cipher New value for cipher.
         */
        void set_cipher(const std::string& n_cipher);

        /**
         * \param n_key New value for key.
         */
        void set_key(const std::string& n_key);

        /**
         * \param n_plaintext New value for plaintext.
         */
        void set_plaintext(const std::string& n_plaintext);
        //@}

        /**
         *  \name Data member accessors.
         */
        //@{
        /**
         * \return Data member cipher.
         */
        std::string get_cipher() const;

        /**
         * \return Data member plaintext.
         */
        std::string get_plaintext() const;

        /**
         * \return Data member key.
         */
        std::string get_key() const;

        /**
         * \return Data member alphabet.
         */
        std::string get_alphabet() const;
        //@}

    private:
        std::string alphabet;
        std::string key;
        std::string cipher;
        std::string plaintext;
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
