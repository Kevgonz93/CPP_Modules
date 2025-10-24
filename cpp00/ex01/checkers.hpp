#ifndef CHECKERS_HPP
#define CHECKERS_HPP

#include <iostream>
#include <string>
#include <cctype>

int isValidName(const std::string &str);
int isValidNumber(const std::string &str);
int isNotDarkestSecret(const std::string &str);
int isValidCommand(const std::string &cmd);
int isValidIndex(int index);
int detectEOF(std::istream& command, int in_main);

#endif
