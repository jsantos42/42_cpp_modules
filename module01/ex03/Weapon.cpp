#include "Weapon.h"

/*
 *	Constructors, Destructors and Assign operator overload.
*/

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::Weapon(const Weapon &src) { *this = src; }

Weapon::~Weapon() {}

Weapon &Weapon::operator=(const Weapon &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.type;
	return (*this);
}

/*
 *	Functions of the Weapon class.
*/

const std::string&	Weapon::getType() const { return this->type; }

void	Weapon::setType(const std::string& newType) { this->type = newType; }
