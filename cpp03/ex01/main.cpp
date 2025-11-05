#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== Constructores ===" << std::endl;
    ScavTrap scav1("Serena");
    ScavTrap scav2(scav1);
    ScavTrap scav3;
    scav3 = scav1;

    std::cout << "\n=== Acciones ===" << std::endl;
    scav1.attack("target dummy");
    scav1.takeDamage(50);
    scav1.beRepaired(5);
    scav1.guardGate();

    std::cout << "\n=== Estados agotados ===" << std::endl;
    for (int i = 0; i < 50; ++i)
    {
        std::cout << "Attack " << i + 1 << ": \t";
        scav1.attack("robot enemy");
        // std::cout << "Energy Points left: " << scav1.getEnergyPoints() << std::endl;
    }

    std::cout << "\n=== Destructores ===" << std::endl;
    return 0;
}
