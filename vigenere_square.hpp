#ifndef VIGENERE_SQUARE_H
#define VIGENERE_SQUARE_H

#include <string>
#include <vector>

class vigenere_square
{
    public:
        vigenere_square(const std::string& i_alphabet);

        virtual ~vigenere_square() = default;

        std::string to_string() const;

        void print(std::ostream& os) const;

    private:
        const std::string alphabet;
        std::vector<std::string> table;
};

std::ostream& operator<<(std::ostream& os, const vigenere_square& vsq);

#endif // VIGENERE_SQUARE_H
