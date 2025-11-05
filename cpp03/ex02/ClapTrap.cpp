#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << name << " assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) 
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!"
				  << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(int amount)
{
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount
			  << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(int amount)
{
	if (energyPoints > 0 && hitPoints > 0) 
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repaired itself for " << amount
				  << " HP!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
	return;
}
