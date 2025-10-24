#include "checkers.hpp"

int isValidName(const std::string &str) 
{
	if (str.empty())
		return 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isalpha(static_cast<unsigned char>(str[i])))
			return 0;
	}
	return 1;
}

int isValidNumber(const std::string &str) 
{
	if (str.empty())
		return 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(str[i])) && str[i] != '+' && str[i] != '-' && str[i] != ' ')
			return 0;
	}
	return 1;
}

int isNotDarkestSecret(const std::string &str)
{
	if (str.empty())
		return 0;
	if (str.length() <= 5)
		return 0;
	return 1;
}

int isValidCommand(const std::string &cmd) 
{
	if (cmd.empty())
		return 0;
	if (cmd == "ADD" || cmd == "add" || cmd == "SEARCH" ||
		cmd == "search" || cmd == "EXIT" || cmd == "exit")
		return 1;
	return 0;
}

int isValidIndex(int index) 
{
	if (index < 0 || index >= 8)
		return 0;
	return 1;
}

int detectEOF(std::istream& command, int in_main)
{
	if (!command) {
		std::cout << "\nEOF detected." << std::endl;
		if (in_main)
		{
			std::cout << "Goodbye!" << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Returning to main menu." << std::endl;
			std::cin.clear();
			clearerr(stdin);
			return 1;
		}
	}
	return 0;
}
