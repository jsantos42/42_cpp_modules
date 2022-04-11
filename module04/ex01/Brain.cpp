#include "Brain.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Brain::Brain() {
	std::cout << "[Brain] Default constructor.\n";
}

Brain::Brain(const Brain &src) {
	*this = src;
	std::cout << "[Brain] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Brain::~Brain() {
	std::cout << "[Brain] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Brain &Brain::operator=(const Brain &rh_instance) {
	if (this != &rh_instance) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rh_instance.ideas[i];
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Brain CLASS.
//==============================================================================
std::string Brain::getIdea(int i) {
	return (ideas[i]);
}