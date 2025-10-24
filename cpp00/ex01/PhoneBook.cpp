#include "PhoneBook.hpp"

PhoneBook::PhoneBook() :
	contactCount (0),
	nextIndex (0)
{}


void PhoneBook::addContact(const Contact &newContact) {
	contacts[nextIndex] = newContact;
	if (contactCount < 8)
		contactCount++;
	nextIndex = (nextIndex + 1) % 8;
}
		
void PhoneBook::list() const {
	std::cout << "|     Index | First Name |  Last Name |  Nickname |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (contactCount == 0) {
		std::cout << "No contacts available." << std::endl;
		return;
	}
	else {
		for (int i = 0; i < contactCount; i++) {
			contacts[i].printRow(i);
		}
	}
}

bool PhoneBook::show(int index) const {
	if (index < 0 || index >= contactCount) {
		std::cout << "Invalid index." << std::endl;
		return false;
	}
	contacts[index].printFull();
		return true;
}

int PhoneBook::getContactCount() const {
	return contactCount;
}
