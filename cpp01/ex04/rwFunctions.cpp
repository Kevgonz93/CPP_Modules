#include "rwFunctions.hpp"

void copyContent(std::string& content, std::ifstream& in)
{
	std::string line;
	while (std::getline(in, line))
	{
		content += line;
		content.push_back('\n');
	}
}

int writeContent(std::ofstream& out,
				const std::string& outFileName, 
				const std::string& content, 
				const std::string& s1, 
				const std::string& s2)
{
	if (s1 == s2)
		out << content;
	else
	{
		std::size_t from = 0;
		while (true)
		{
			std::size_t pos = content.find(s1, from);
			if (pos == std::string::npos)
			{
				out << content.substr(from);
				break;
			}
			out << content.substr(from, pos - from);
			out << s2;
			from = pos + s1.length();
		}
	}
	if (!fileChecker(out, outFileName, WRITE_OK))
		return 1;
	out.close();
	return 0;
}
