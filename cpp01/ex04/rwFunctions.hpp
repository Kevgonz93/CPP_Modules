#ifndef RWFUNCTIONS_HPP
#define RWFUNCTIONS_HPP

#include <fstream>
#include <string>
#include "checkFiles.hpp"

void copyContent(std::string& content, std::ifstream& in);
int writeContent(std::ofstream& out,
				const std::string& outFileName, 
				const std::string& content, 
				const std::string& s1, 
				const std::string& s2);
		
#endif
