#include <iostream>
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n=== Constructores ===\n";
    DiamondTrap d1("Shiny");
    d1.whoAmI();

    std::cout << "\n=== Acciones básicas ===\n";
    d1.attack("Perico Macona");    // Debe usar ScavTrap::attack
    d1.takeDamage(25);
    d1.beRepaired(10);

    std::cout << "\n=== Habilidades de padres ===\n";
    d1.guardGate();                 // ScavTrap
    d1.highFivesGuys();             // FragTrap

    std::cout << "\n=== Copia y asignación ===\n";
    DiamondTrap d2(d1);
    d2.whoAmI();
    DiamondTrap d3;
    d3 = d1;
    d3.whoAmI();

    std::cout << "\n=== Agotar energía con ataques ===\n";
    for (int i = 0; i < 60; ++i)    // EP inicial 50 → debería quedarse sin energía
    {
        d1.attack("Pedro Navaja");
        // std::cout << "\tEnergy Points left: " << d1.getEnergyPoints() << std::endl;
    }


    std::cout << "\n=== whoAmI final ===\n";
    d1.whoAmI();

    std::cout << "\n=== Destructores ===\n";
    return 0;
}
