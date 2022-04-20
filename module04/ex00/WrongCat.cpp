	#include "WrongCat.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "[WrongCat] Default constructor.\n";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	*this = src;
	std::cout << "[WrongCat] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

WrongCat &WrongCat::operator=(const WrongCat &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.type;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE WrongCat CLASS.
//==============================================================================
void WrongCat::makeSound() const {
	std::cout << "MEOW!\n";
}
