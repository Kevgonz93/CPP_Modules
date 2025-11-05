#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap("Default_ScavTrap") {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default_ScavTrap created." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other) {
	std::cout << "ScavTrap " << name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << name << " assigned." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (energyPoints > 0 && hitPoints > 0) 
	{
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!"
				  << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

// int ScavTrap::getEnergyPoints() const {
// 	return energyPoints;
// }
