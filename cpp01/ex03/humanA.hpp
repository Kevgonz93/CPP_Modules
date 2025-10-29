#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon& weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack() const;
};

#endif
