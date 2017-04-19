/**
 * \file main.cpp
 * \brief Provides command line interface.
 */

#include <ios>
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

#include "vigenere_square.hpp"
#include "stringutils.hpp"

/**
 * \brief Main function for user I/O and error handling.
 * \return 0 if no errors.
 */
int main()
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Vigenère cipher demo using the Vigenère table." << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    std::string alphabet;
    std::string cipher;
    std::string key;
    std::stringstream ss;

    std::cout << "Input alphabet and press ENTER. Input '_DEFAULT_' " <<
                 "to use default English alphabet." << std::endl;
    std::cin >> std::skipws >> alphabet;z

    if(alphabet == "_DEFAULT_")
    {
        alphabet = "ABCDEFGHIJKLMNOPQRSTUWXYZ";
    }

    try
    {
        vigenere_square vsq{stringutils::uppercase(alphabet)};
    }
    catch(std::invalid_argument e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::cout << "Input cipher and press ENTER." << std::endl;
    std::cin >> cipher;

    std::cout << "Input key and press ENTER." << std::endl;
    std::cin >> key;

    return 0;
}
