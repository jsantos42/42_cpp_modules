#include "Ice.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Ice::Ice() {
	std::cout << "[Ice] Default constructor.\n";
	this->type = "ice";
}

Ice::Ice(const Ice &src) : AMateria(src) {
	*this = src;
	std::cout << "[Ice] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Ice::~Ice() {
	std::cout << "[Ice] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Ice &Ice::operator=(const Ice &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.getType();
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Ice CLASS.
//==============================================================================
AMateria*	Ice::clone() const {
	AMateria*	new_amateria = new Ice;
	new_amateria->setType(this->getType());
	return (new_amateria);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at "
			  << target.getName()
			  << " *"
			  << std::endl;
}
