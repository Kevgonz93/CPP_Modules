#include "ClapTrap.hpp"

int main() {
    std::cout << "\n=== Creating ClapTraps ===" << std::endl;
    ClapTrap kevin("Kevin");
    ClapTrap renzo("Renzo");

    std::cout << "\n=== Round 1 ===" << std::endl;
    kevin.attack("Renzo");
    renzo.takeDamage(3);
    renzo.beRepaired(2);

    std::cout << "\n=== Round 2 ===" << std::endl;
    kevin.attack("Renzo");
    renzo.takeDamage(10);
    renzo.beRepaired(5); // should fail if HP <= 0

    std::cout << "\n=== Energy depletion test ===" << std::endl;
    for (int i = 0; i < 11; i++)
        kevin.attack("Renzo"); // should fail when energy = 0

    std::cout << "\n=== End of battle ===" << std::endl;
    return 0;
}
