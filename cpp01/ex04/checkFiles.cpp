#include "checkFiles.hpp"

static bool checkOpenOk(std::ifstream& f, const std::string& name) {
    if (!f.is_open()) {
        std::cerr << "Error: cannot open file " << name << '\n';
        return false;
    }
    return true;
}

static bool checkOpenOk(std::ofstream& f, const std::string& name) {
	if (!f.is_open()) {
		std::cerr << "Error: cannot open file " << name << '\n';
		return false;
	}
	return true;
}

static bool checkReadOk(const std::ifstream& f, const std::string& name) {
    if ((f.fail() && !f.eof()) || f.bad()) {
        std::cerr << "Error: read error on file " << name << '\n';
        return false;
    }
    return true;
}

static bool checkWriteOk(const std::ofstream& f, const std::string& name) {
    if (f.fail() || f.bad()) {
        std::cerr << "Error: write error on file " << name << '\n';
        return false;
    }
    return true;
}

bool fileChecker(std::ifstream& file, const std::string& fileName,FileMode mode)
{
	switch (mode)
	{
	case OPEN_OK:
		return checkOpenOk(file, fileName);
	case READ_OK:
		return checkReadOk(file, fileName);
	default:
		return false;
	}
}

bool fileChecker(std::ofstream& file, const std::string& fileName, FileMode mode)
{
	switch (mode)
	{
	case OPEN_OK:
		return checkOpenOk(file, fileName);
	case WRITE_OK:
		return checkWriteOk(file, fileName);
	default:
		std::cerr << "Error: invalid mode for ofstream\n";
		return false;
	}
}
