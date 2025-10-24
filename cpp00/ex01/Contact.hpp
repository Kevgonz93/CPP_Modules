#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	void setFirstName(const std::string &fn) { firstName = fn; }
	void setLastName(const std::string &ln) { lastName = ln; }
	void setNickname(const std::string &nn) { nickname = nn; }
	void setPhoneNumber(const std::string &pn) { phoneNumber = pn; }
	void setDarkestSecret(const std::string &ds) { darkestSecret = ds; }

	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }
	std::string getNickname() const { return nickname; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getDarkestSecret() const { return darkestSecret; }

    Contact();
	void printRow(int index) const;
	void printFull() const;
};

#endif
