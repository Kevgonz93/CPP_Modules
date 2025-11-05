#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap("Default_FragTrap") {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " created." << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other) {
	std::cout << "FragTrap " << name << " copied." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << name << " assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
