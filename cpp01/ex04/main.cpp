#include <fstream>
#include <iostream>
#include <string>
#include "checkFiles.hpp"
#include "rwFunctions.hpp"

bool checkArgs(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (!checkArgs(argc, argv))
		return 1;
	std::string infileName = argv[1];
	std::string s1 = argv[2];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be an empty string" << std::endl;
		return 1;
	}
	std::string s2 = argv[3];
	std::ifstream in(infileName);
	if (!fileChecker(in, infileName, OPEN_OK))
		return 1;
	std::string content;
	std::string line;
	copyContent(content, in);
	if (!fileChecker(in, infileName, READ_OK))
		return 1;
	in.close();
	const std::string outFileName = infileName + ".replace";
	std::ofstream out(outFileName);
	if (!fileChecker(out, outFileName, OPEN_OK))
		return 1;
	if (writeContent(out, outFileName, content, s1, s2))
		return 1;
	return 0;
}
