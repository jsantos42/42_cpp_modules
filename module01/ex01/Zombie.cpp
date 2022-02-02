#include "Zombie.h"
#include "utils.h"

/*
 *	Constructors, Destructors and Assign operator overload.
*/

Zombie::Zombie() { _output("Creating a Zombie", true); }

Zombie::Zombie(const std::string& new_name) : name(new_name) {}

Zombie::Zombie(const Zombie &src) { *this = src; }

Zombie::~Zombie() {
	_output("Destroying ", false);
	_output(name, true);
}

Zombie &Zombie::operator=(const Zombie &rh_instance) {
	if (this != &rh_instance)
		this->name = rh_instance.name;
	return (*this);
}

/*
 *	Functions of the Zombie class.
*/

void Zombie::announce() {
	_output(name, false);
	_output(": BraiiiiiiinnnzzzZ...", true);
}

void Zombie::setName(std::string new_name) {
	this->name = new_name;
}
