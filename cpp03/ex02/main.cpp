#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== Constructores ===" << std::endl;
    FragTrap frag1("Rex");
    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag1;

    std::cout << "\n=== Acciones ===" << std::endl;
    frag1.attack("enemy");
    frag1.takeDamage(20);
    frag1.beRepaired(10);
    frag1.highFivesGuys();

    std::cout << "\n=== Destructores ===" << std::endl;
    return 0;
}
