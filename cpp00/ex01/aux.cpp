#include "aux.hpp"

int ft_atoi(const std::string& str, bool& ok) {
    long result = 0;
    int sign = 1;
    size_t i = 0;
    ok = true;

    while (i < str.length() && std::isspace(static_cast<unsigned char>(str[i])))
        i++;
    if (i < str.length() && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (i >= str.length() || !std::isdigit(static_cast<unsigned char>(str[i]))) {
        ok = false;
        return 0;
    }
    for (; i < str.length(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
            ok = false;
            return 0;
        }
        result = result * 10 + (str[i] - '0');
        if (result > 2147483647L) {
            ok = false;
            return 0;
        }
    }
    return static_cast<int>(result * sign);
}
