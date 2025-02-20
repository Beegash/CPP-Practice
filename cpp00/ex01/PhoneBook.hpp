#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

class PhoneBook
{
public:
    PhoneBook();
    void addContact();
    void searchContact() const;

private:
    Contact contacts[8];
    int contactCount;
    int oldContact;
    void displayContact(int index) const;
    void displayContacts() const;
};

#endif
