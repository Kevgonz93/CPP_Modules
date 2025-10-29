#include "Harl.hpp"
#include <string>
#include <iostream>
#include <cctype>

static std::string toUpper(std::string s) {
    for (size_t i = 0; i < s.size(); ++i) 
        s[i] = static_cast<char>(std::toupper(s[i]));
    return s;
}

static int levelIndex(const std::string& arg) {
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    std::string up = toUpper(arg);
    for (int i = 0; i < 4; ++i) 
    {
        if (up == levels[i])
            return i;
    }
    return -1;
}

int main(int argc, char** argv) {
    Harl harl;
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }
    int index = levelIndex(argv[1]);
    switch (index)
    {
    case 0:
        harl.complain(levels[0]);
        std::cout << std::endl;
    case 1:
        harl.complain(levels[1]);
        std::cout << std::endl;
    case 2:
        harl.complain(levels[2]);
        std::cout << std::endl;
    case 3:
        harl.complain(levels[3]);
        std::cout << std::endl;
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}
