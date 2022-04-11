#include "WrongAnimal.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
WrongAnimal::WrongAnimal() : type("") {
	std::cout << "[WrongAnimal] Default constructor.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	*this = src;
	std::cout << "[WrongAnimal] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.type;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE WrongAnimal CLASS.
//==============================================================================
std::string WrongAnimal::getType() const {
	return (this->type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "Undefined animal type produces no sound!\n";
}
