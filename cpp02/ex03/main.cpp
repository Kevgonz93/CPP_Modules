#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>   // std::atof

bool bsp(Point const a, Point const b, Point const c, Point const point);

static bool readFloat(const char* prompt, float &out) {
    std::string s;
    std::cout << prompt;
    if (!std::getline(std::cin, s)) return false;     // EOF / error
    out = static_cast<float>(std::atof(s.c_str()));   // C++98-friendly
    return true;
}

int main() {
    float x, y;

    std::cout << "Enter triangle vertices (A, B, C)\n\n";

    if (!readFloat("A(x): ", x) || !readFloat("A(y): ", y)) return 0;
    Point A(x, y);
    std::cout << std::endl;

    if (!readFloat("B(x): ", x) || !readFloat("B(y): ", y)) return 0;
    Point B(x, y);
    std::cout << std::endl;

    if (!readFloat("C(x): ", x) || !readFloat("C(y): ", y)) return 0;
    Point C(x, y);
    std::cout << std::endl;

    std::cout << "Now enter the test point P\n\n";
    if (!readFloat("P(x): ", x) || !readFloat("P(y): ", y)) return 0;
    Point P(x, y);
    std::cout << std::endl;

    std::cout << "Painting the triangle";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "." << std::flush;
        usleep(500000);
    }
    std::cout << "PAINTED!" << std::endl;
    std::cout << std::endl;

    if (bsp(A, B, C, P))
        std::cout << "P is strictly inside the triangle.\n";
    else
        std::cout << "P is NOT inside.\n";

    return 0;
}
