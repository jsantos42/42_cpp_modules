#include "Cure.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Cure::Cure() {
	std::cout << "[Cure] Default constructor.\n";
	this->type = "cure";
}

Cure::Cure(const Cure &src) : AMateria(src) {
	*this = src;
	std::cout << "[Cure] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Cure::~Cure() {
	std::cout << "[Cure] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Cure &Cure::operator=(const Cure &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.type;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Cure CLASS.
//==============================================================================
AMateria*	Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals "
			  << target.getName()
			  << "'s wounds *"
			  << std::endl;
}
