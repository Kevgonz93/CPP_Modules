#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;

    return 0;
}
