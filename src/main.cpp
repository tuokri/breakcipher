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

    vigenere_square vsq;
    std::string alphabet;
    std::string text;
    std::string key;
    std::stringstream ss;

    std::cout << "Input alphabet and press ENTER. Input '_DEFAULT_' " <<
                 "to use default English alphabet." << std::endl;
    std::cin >> std::skipws >> alphabet;

    if(alphabet == "_DEFAULT_")
    {
        alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    }

    try
    {
        vsq = vigenere_square{stringutils::uppercase(alphabet)};
    }
    catch(std::invalid_argument e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::string prompt;
    bool encrypt;
    while(true)
    {
        std::cout << "Please choose 'encrypt' or 'decrypt' and press ENTER." << std::endl;
        std::cin >> std::skipws >> text;
        text = stringutils::uppercase(text);
        if(text == "ENCRYPT")
        {
            prompt =  "Input plain text and press ENTER.";
            encrypt = true;
            break;
        }
        else if(text == "DECRYPT")
        {
            prompt =  "Input cipher text and press ENTER.";
            encrypt = false;
            break;
        }
    }

    std::cout << prompt << std::endl;
    std::cin >> std::skipws >> text;

    std::cout << "Input key and press ENTER." << std::endl;
    std::cin >> std::skipws >> key;

    if(encrypt)
    {
        std::cout << vsq.encrypt(text, key) << std::endl;
    }
    else
    {
        std::cout << vsq.decrypt(text, key) << std::endl;
    }

    return 0;
}
