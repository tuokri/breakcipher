#include <iostream>
#include "vigenere_square.hpp"

int main()
{
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vigenere_square vsq{alphabet};

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Vigenère cipher demo using Vigenère table." << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    return 0;
}
