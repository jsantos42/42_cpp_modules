#include "Cat.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
/*
 *  Note that here, since Cat does not (itself) have the 'type' attribute (it is
 *  only inherited), it cannot be initiated on an initializer list, i.e.
 *  : type("Cat") {
 *	See https://stackoverflow.com/questions/18479295/member-initializer-does-not-name-a-non-static-data-member-or-base-class
 */
Cat::Cat() {
	type = "Cat";
	std::cout << "[Cat] Default constructor.\n";
}

Cat::Cat(const Cat &src) : Animal(src) {
	*this = src;
	std::cout << "[Cat] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Cat::~Cat() {
	std::cout << "[Cat] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Cat &Cat::operator=(const Cat &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.type;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Cat CLASS.
//==============================================================================
void Cat::makeSound() const {
	std::cout << "MEOW!\n";
}
