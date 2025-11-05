#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default")
{
	hitPoints = 100;               // FragTrap
	energyPoints = 50;            // ScavTrap
	attackDamage = 30;            // FragTrap

	this->name = "Default";
	std::cout << "DiamondTrap " << this->name 
			<< " created. (ClapTrap name: " << ClapTrap::name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	hitPoints = 100;               // FragTrap
    energyPoints = 50;            // ScavTrap
    attackDamage = 30;            // FragTrap

	this->name = name;
	std::cout << "DiamondTrap " << this->name 
			<< " created. (ClapTrap name: " << ClapTrap::name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->name = other.name;
	std::cout << "DiamondTrap " << this->name 
			<< " copied. (ClapTrap name: " << ClapTrap::name << ")" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap " << this->name 
			<< " assigned. (ClapTrap name: " << ClapTrap::name << ")" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name 
			<< " destroyed. (ClapTrap name: " << ClapTrap::name << ")" << std::endl;
}

void DiamondTrap::whoAmI(void) const {
	std::cout << "DiamondTrap name: " << this->name 
			<< ", ClapTrap name: " << ClapTrap::name << std::endl;
}

// void DiamondTrap::attack(const std::string& target) {
// 	ScavTrap::attack(target);
// }
