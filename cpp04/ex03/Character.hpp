#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>

static const int MAX_TRASH = 100;
static const int MAX_INVENTORY = 4;

class Character : public ICharacter {
	private:
		std::string name;
		AMateria* inventory[MAX_INVENTORY];
		AMateria* trash[MAX_TRASH];
	public:
		Character(std::string const & name);
		Character(Character const & other);
		Character & operator=(Character const & other);
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
