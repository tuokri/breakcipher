#include <sstream>
#include <valarray>

#include "vigenere_square.hpp"
#include "stringutils.hpp"

vigenere_square::vigenere_square(const std::string& i_alphabet) :
    alphabet(i_alphabet),
    table(std::vector<std::string>{alphabet.size()})
{
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

std::ostream& operator<<(std::ostream& os, const vigenere_square& vsq)
{
    os << vsq.to_string();
    return os;
}
