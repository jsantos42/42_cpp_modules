#include "HumanA.h"
#include <iostream>

/*
 *	Note that the constructor of A passes weapon as a ref to prevent it from
 *	ever being NULL.
 */

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), _weapon(weapon) {
	std::cout << "Created a HumanA object with name " << this->name
			  << " and weapon " << this->_weapon.getType()
			  <<std::endl;
}

const std::string&	HumanA::getName() const {
	return (this->name);
}

void	HumanA::setName(const std::string& newName) { this->name = newName; }

void	HumanA::attack() {
	std::cout << this->name << " attacks with their "
			  << this->_weapon.getType() << std::endl;
}
