#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
    Contact contacts[8];
	int contactCount;
	int nextIndex;
public:
    PhoneBook();
    void addContact(const Contact &newContact);
	void list() const;
	bool show(int index) const;
	int getContactCount() const;
};

#endif
