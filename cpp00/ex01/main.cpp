#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "checkers.hpp"
#include "aux.hpp"

int detectEOF(std::istream &command, int in_main);

int add(PhoneBook &PhoneBook) {
	Contact newContact;
	std::string input;

	std::cout << "Enter First Name: ";
	if (detectEOF(std::getline(std::cin, input), 0))
		return 0;
	while (!isValidName(input)) {
		std::cout << "Invalid input. Enter First Name: ";
		if (detectEOF(std::getline(std::cin, input), 0))
			return 0;
	}
	newContact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	if (detectEOF(std::getline(std::cin, input), 0))
		return 0;
	while (!isValidName(input)) {
		std::cout << "Invalid input. Enter Last Name: ";
		if (detectEOF(std::getline(std::cin, input), 0))
			return 0;
	}
	newContact.setLastName(input);

	std::cout << "Enter Nickname: ";
	if (detectEOF(std::getline(std::cin, input), 0))
		return 0;
	while (input.empty()) {
		std::cout << "Invalid input. Enter Nickname: ";
		if (detectEOF(std::getline(std::cin, input), 0))
			return 0;
	}
	newContact.setNickname(input);

	std::cout << "Enter Phone Number: ";
	if (detectEOF(std::getline(std::cin, input), 0))
		return 0;
	while (!isValidNumber(input)) {
		std::cout << "Invalid input." << std::endl;
		std::cout << "Enter Phone Number: ";
		if (detectEOF(std::getline(std::cin, input), 0))
			return 0;
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter Darkest Secret: ";
	if (detectEOF(std::getline(std::cin, input), 0))
		return 0;
	while (!isNotDarkestSecret(input)) {
		std::cout << "Well, everyone has a secret. Enter Darkest Secret: ";
		if (detectEOF(std::getline(std::cin, input), 0))
			return 0;
	}
	newContact.setDarkestSecret(input);

	PhoneBook.addContact(newContact);
	std::cout << "Contact added." << std::endl;
	return 1;
}

int search(const PhoneBook &PhoneBook) {
	PhoneBook.list();

	if (PhoneBook.getContactCount() == 0)
		return 0;
	std::string input;
	std::cout << "Enter index to view details: ";
	if (detectEOF(std::getline(std::cin, input), 0))
		return 0;
	bool ok;
	int index = ft_atoi(input, ok);
	if (!ok || !isValidIndex(index)) {
		std::cout << "Invalid index." << std::endl;
		return 0;
	}
	PhoneBook.show(index);
	return 1;
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	PhoneBook pb;
	std::string command;
	std::cout << "My Awesome PhoneBook !!" << std::endl;
	while (1) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (detectEOF(std::getline(std::cin, command), 1))
			break;
		while (!isValidCommand(command)) {
			std::cout << "Invalid command. Enter command (ADD, SEARCH, EXIT): ";
			if (detectEOF(std::getline(std::cin, command), 1))
				return 0;
		}
		if (command == "ADD" || command == "add")
		{
			if (!add(pb))
				continue;
		}
		else if (command == "SEARCH" || command == "search")
		{
			if (!search(pb))
				continue;
		}
		else if (command == "EXIT" || command == "exit") 
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
	}
}
