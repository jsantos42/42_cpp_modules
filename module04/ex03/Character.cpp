#include "Character.h"
#include "Ice.h"
#include "Cure.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Character::Character() : inventory() {
	std::cout << "[Character] Default constructor.\n";
}

Character::Character(const std::string& name) : inventory(), name(name) {
	std::cout << "[Character] String constructor.\n";
}

Character::Character(const Character &src) {
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i]) {
			if (src.inventory[i]->getType() == "ice")
				this->inventory[i] = new Ice;
			else
				this->inventory[i] = new Cure;
		}
	}
	*this = src;
	std::cout << "[Character] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Character::~Character() {
	std::cout << "[Character] Destructor.\n";
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Character &Character::operator=(const Character &rh_instance) {
	if (this != &rh_instance) {
		this->name = rh_instance.getName();
		for (int i = 0; i < 4; i++) {
			if (rh_instance.inventory[i])
				*(this->inventory[i]) = *(rh_instance.inventory[i]);
			else
				this->inventory[i] = 0;
		}
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Character CLASS.
//==============================================================================
const std::string &Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " .\n";
			return ;
		}
	}
	std::cout << "Cannot equip any more materials.\n";
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		std::cout << "Wrong index of inventory.\n";
	else if (this->inventory[idx]) {
		std::cout << "Unequipped " << this->inventory[idx]->getType() << " .\n";
		this->inventory[idx] = 0;
	}
	else
		std::cout << "Nothing to unequip.\n";
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		std::cout << "Wrong index of inventory.\n";
	else if (this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << "Nothing to use.\n";
}

AMateria *Character::getItem(int index) {
	return (inventory[index]);
}