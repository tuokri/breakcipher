/**
 * \file main.cpp
 * \brief Provides command line interface.
 */

#include <iostream>
#include "vigenere_square.hpp"

/**
 * \brief Main function for user I/O and error handling.
 */
int main()
{
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vigenere_square vsq{alphabet};

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Vigenère cipher demo using the Vigenère table." << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    return 0;
}
