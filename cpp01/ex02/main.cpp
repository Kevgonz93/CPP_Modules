#include <iostream>
#include <string>

int main ()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	// Modifying the string using pointer
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Modifying the string using stringREF..." << std::endl;
	stringREF = "MODIFIED STRING";
	std::cout << "Value of str after modification: " << str << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	
	return 0;
}
