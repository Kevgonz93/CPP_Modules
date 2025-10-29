#include "Harl.hpp"
#include "ft_atoi.cpp"
#include <iostream>
#include <cctype>

static std::string toUpper(std::string s) {
    for (size_t i = 0; i < s.size(); ++i) s[i] = static_cast<char>(std::toupper(s[i]));
    return s;
}

static bool isNumber(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return true;
}

static int levelIndex(const std::string& arg) {
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    if (isNumber(arg)) {
        bool found = false;
        int n = ft_atoi(arg, found);
        if (found && n >= 0 && n <= 3)
            return n;
        return -1;
    } else {
        std::string up = toUpper(arg);
        for (int i = 0; i < 4; i++) 
        {
            if (up == levels[i])
                return i;
        }
        return -1;
    }
}

int main(int argc, char** argv) {
    Harl h;
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    if (argc == 1)
    {
        for (int i = 0; i < 4; ++i)
            h.complain(levels[i]);
        return 0;
    }
    int index = levelIndex(argv[1]);
    if (index == -1) {
        std::cerr << "Usage: " << argv[0] << " Optional: [0|1|2|3|DEBUG|INFO|WARNING|ERROR]\n";
        return 1;
    }
    for (int i = index; i < 4; ++i)
        h.complain(levels[i]);
    return 0;
}
