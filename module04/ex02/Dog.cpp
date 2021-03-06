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
	std::cout << "[Dog] Default constructor.\n";
	type = "Dog";
	brain = new Brain();
}

/*
 * This is now a deep copy.
 */
Dog::Dog(const Dog &src) : Animal(src) {
	this->brain = new Brain();
	*this = src;
	std::cout << "[Dog] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Dog::~Dog() {
	std::cout << "[Dog] Destructor.\n";
	delete brain;
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Dog&	Dog::operator=(const Dog &rh_instance) {
	if (this != &rh_instance) {
		this->type = rh_instance.getType();
		*(this->brain) = *(rh_instance.getBrain());
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Dog CLASS.
//==============================================================================
void Dog::makeSound() const {
	std::cout << "WOOF WOOF!\n";
}

Brain*	Dog::getBrain() const {
	return (brain);
}
