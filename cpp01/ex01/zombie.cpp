#include "zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

// Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::~Zombie() {
	std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce(void) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& newName) {
    this->name = newName;
}
