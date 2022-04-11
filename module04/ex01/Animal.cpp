#include "Animal.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Animal::Animal() : type("") {
	std::cout << "[Animal] Default constructor.\n";
}

Animal::Animal(const Animal &src) {
	*this = src;
	std::cout << "[Animal] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Animal::~Animal() {
	std::cout << "[Animal] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Animal &Animal::operator=(const Animal &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.type;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Animal CLASS.
//==============================================================================
std::string Animal::getType() const {
	return (this->type);
}

void	Animal::makeSound() const {
	std::cout << "Undefined animal type produces no sound!\n";
}
