#ifndef CHECKFILES_HPP
#define CHECKFILES_HPP

#include <fstream>
#include <string>
#include <iostream>

enum FileMode
{
    OPEN_OK,
    READ_OK,
    WRITE_OK
};

bool fileChecker(std::ifstream& file, const std::string& fileName, FileMode mode);
bool fileChecker(std::ofstream& file, const std::string& fileName, FileMode mode);

#endif
