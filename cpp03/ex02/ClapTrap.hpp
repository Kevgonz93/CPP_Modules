#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(int amount);
		void beRepaired(int amount);
};

#endif
