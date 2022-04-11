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
	std::cout << "[Cat] Default constructor.\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
	this->brain = new Brain();
	*(this->brain) = *(src.brain);
	*this = src;
	std::cout << "[Cat] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Cat::~Cat() {
	std::cout << "[Cat] Destructor.\n";
	delete brain;
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Cat&	Cat::operator=(const Cat &rh_instance) {
	if (this != &rh_instance) {
		this->type = rh_instance.getType();
		*(this->brain) = *(rh_instance.getBrain());
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Cat CLASS.
//==============================================================================
void Cat::makeSound() const {
	std::cout << "MEOW!\n";
}

Brain*	Cat::getBrain() const {
	return (brain);
}
