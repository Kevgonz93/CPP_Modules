#include "Contact.hpp"

Contact::Contact() : 
	firstName(""), 
	lastName(""), 
	nickname(""), 
	phoneNumber(""), 
	darkestSecret("") 
{}

std::string maxL(const std::string &str) 
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::printRow(int index) const
{
	std::cout << "| " << std::setw(10) << index << " | "
	          << std::setw(10) << maxL(firstName) << " | "
		        << std::setw(10) << maxL(lastName) << " | "
		      << std::setw(10) << maxL(nickname) << " |" << std::endl;
}

void Contact::printFull()  const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

