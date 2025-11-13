#include "Character.hpp"


Character::Character(std::string const & name) : name(name) {
	for (int i = 0; i <MAX_INVENTORY; i++) {
		inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_TRASH; i++) {
		trash[i] = NULL;
	}
}

Character::Character(Character const & other) : name(other.name) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_TRASH; i++) {
		trash[i] = NULL;
	}
}

Character & Character::operator=(Character const & other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < MAX_INVENTORY; i++) {
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		for (int i = 0; i < MAX_TRASH; i++) {
			if (trash[i])
				delete trash[i];
			trash[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (inventory[i])
			delete inventory[i];
	}
	for (int i = 0; i < MAX_TRASH; i++) {
		if (trash[i])
			delete trash[i];
	}
}

std::string const & Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_INVENTORY || !inventory[idx])
		return;
	for (int i = 0; i < MAX_TRASH; i++) {
		if (trash[i] == NULL) {
			trash[i] = inventory[idx];
			inventory[idx] = NULL;
			break;
		}
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < MAX_INVENTORY && inventory[idx]) {
		inventory[idx]->use(target);
	}
}
