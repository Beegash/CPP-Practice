#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;
    std::cout << "Enter Contact Details(only first words included)" << std::endl;

    std::cout << "Enter First Name: ";
    std::cin >> input;
    newContact.setFirstName(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Last Name: ";
    std::cin >> input;
    newContact.setLastName(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout << "Enter Nickname: ";
    std::cin >> input;
    newContact.setNickname(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout << "Enter Phone Number: ";
    std::cin >> input;
    newContact.setPhoneNumber(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout << "Enter Darkest Secret: ";
    std::cin >> input;
    newContact.setDarkestSecret(input);
    

    if (contactCount < 8)
    {
        contacts[contactCount++] = newContact;
    }
    else
    {
        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
}

void PhoneBook::displayContact(int index) const
{
    if (index < 0 || index >= contactCount)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    Contact contact = contacts[index];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < contactCount; ++i)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
                  << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
                  << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::searchContact() const
{
    if (contactCount == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    displayContacts();
    std::cout << "Enter index to view details: ";
    std::string input;
    std::cin >> input;

    bool isValid = true;
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]))
        {
            isValid = false;
            break;
        }
    }

    if (isValid)
    {
        int index = 0;
        for (size_t i = 0; i < input.length(); ++i)
        {
            index = index * 10 + (input[i] - '0');
        }

        if (index < 0 || index >= contactCount)
        {
            std::cout << "Invalid index!" << std::endl;
            return;
        }
        displayContact(index);
    }
    else
    {
        std::cout << "Invalid input! Please enter a valid number." << std::endl;
    }
}