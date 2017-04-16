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
         *  \name Data member accessors.
         */
        //@{
        void set_ciper(const std::string& n_cipher);
        void set_key(const std::string& n_key);
        void set_plaintext(const std::string& n_plaintext);
        //@}

        /**
         *  \name Data member mutators.
         */
        //@{
        std::string get_ciper() const;
        std::string get_plaintext() const;
        std::string get_key() const;
        //@}

    private:
        std::vector<std::string> table;
        const std::string alphabet;
        std::string cipher;
        std::string key;
        std::string plaintext;
};

/**
 * \brief operator<< overload.
 * \param os Reference to std::ostream.
 * \param vsq Reference to vigenere_square.
 * \return Reference to std::ostream.
 */
std::ostream& operator<<(std::ostream& os, const vigenere_square& vsq);

#endif // VIGENERE_SQUARE_H
