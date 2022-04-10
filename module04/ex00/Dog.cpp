#include "Dog.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
/*
 *  Note that here, since Cat does not (itself) have the 'type' attribute (it is
 *  only inherited), it cannot be initiated on an initializer list, i.e.
 *  : type("Cat") {
 *	See https://stackoverflow.com/questions/18479295/member-initializer-does-not-name-a-non-static-data-member-or-base-class
 */
Dog::Dog() {
	type = "Dog";
	std::cout << "[Dog] Default constructor.\n";
}

Dog::Dog(const Dog &src) : Animal(src) {
	*this = src;
	std::cout << "[Dog] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Dog::~Dog() {
	std::cout << "[Dog] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Dog &Dog::operator=(const Dog &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.type;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Dog CLASS.
//==============================================================================
void Dog::makeSound() const {
	std::cout << "WOOF WOOF!\n";
}