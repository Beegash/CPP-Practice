#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a Command\n1-ADD\n2-SEARCH\n3-EXIT\n------------------" << std::endl;
        std::cin >> command;

        if (std::cin.peek() != '\n')
        {
            std::cout << "Invalid input! Please enter a valid command." << std::endl;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (command == "ADD" || command == "add")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH" || command == "search")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT" || command == "exit")
        {
            break;
        }
        else
        {
            std::cout << "Unknown command!" << std::endl;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
