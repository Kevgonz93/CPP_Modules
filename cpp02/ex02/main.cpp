#include "Fixed.hpp"
#include <iostream>

int main() {
    std::cout << "=== CONSTRUCTORES ===" << std::endl;
    Fixed a(5);          // 5.0
    Fixed b(2.5f);       // 2.5
    Fixed c;             // 0.0
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n\n";

    std::cout << "=== COMPARACIONES ===" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "(a > b): " << (a > b) << "\n";
    std::cout << "(a < b): " << (a < b) << "\n";
    std::cout << "(a >= b): " << (a >= b) << "\n";
    std::cout << "(a <= b): " << (a <= b) << "\n";
    std::cout << "(a == b): " << (a == b) << "\n";
    std::cout << "(a != b): " << (a != b) << "\n\n";

    std::cout << "=== ARITMÉTICOS ===" << std::endl;
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << "\n";

    // ⚠️ Prueba de división por cero
    std::cout << "\nIntentando dividir por cero:" << std::endl;
    try {
        Fixed zero(0);
        Fixed result = a / zero;
        std::cout << "Resultado: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error capturado: " << e.what() << std::endl;
    }

    std::cout << "\n=== INCREMENTOS Y DECREMENTOS ===" << std::endl;
    Fixed x(1.0f);
    std::cout << "x = " << x << std::endl;
    std::cout << "++x (pre) = " << ++x << std::endl;
    std::cout << "x++ (post) = " << x++ << " → ahora x = " << x << std::endl;
    std::cout << "--x (pre) = " << --x << std::endl;
    std::cout << "x-- (post) = " << x-- << " → ahora x = " << x << std::endl;

    std::cout << "\n=== MIN / MAX ===" << std::endl;
    Fixed &minRef = Fixed::min(a, b);
    Fixed &maxRef = Fixed::max(a, b);
    std::cout << "min(a, b) = " << minRef << ", max(a, b) = " << maxRef << std::endl;

    const Fixed ca(3.0f);
    const Fixed cb(4.0f);
    std::cout << "const min(ca, cb) = " << Fixed::min(ca, cb)
              << ", const max(ca, cb) = " << Fixed::max(ca, cb) << std::endl;

    std::cout << "\n=== PRUEBA DE MODIFICACIÓN (min no const) ===" << std::endl;
    Fixed &ref = Fixed::min(a, b);
    std::cout << "Antes de cambiar, min(a,b) = " << ref << std::endl;
    ref = Fixed(42.42f);
    std::cout << "Después de cambiar, a = " << a << ", b = " << b << std::endl;

    return 0;
}
