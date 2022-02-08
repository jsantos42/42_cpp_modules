#include "HumanB.h"
#include <iostream>

/*
 *	Note that the constructor of B passes weapon as a pointer, since it can be
 *	NULL (having no weapon).
 */

HumanB::HumanB(const std::string& name) : name(name), _weapon(NULL) {
	std::cout << "Created a HumanB object with name " << this->name
			  << " and no weapon "
			  << std::endl;
}

const std::string&	HumanB::getName() const { return (this->name); }

void	HumanB::setName(const std::string& new_name) { this->name = new_name; }

void	HumanB::setWeapon(Weapon& new_weapon) { this->_weapon = &new_weapon; }

void	HumanB::attack() {
	if (_weapon)
		std::cout << this->name << " attacks with their "
				  << _weapon->getType() << std::endl;
}
