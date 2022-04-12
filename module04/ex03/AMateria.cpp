#include "AMateria.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
AMateria::AMateria() {
	std::cout << "[AMateria] Default constructor.\n";
}

AMateria::AMateria(const std::string &type) {
	this->type = type;
	std::cout << "[AMateria] String constructor.\n";
}

AMateria::AMateria(const AMateria &src) {
	*this = src;
	std::cout << "[AMateria] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

AMateria::~AMateria() {
	std::cout << "[AMateria] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

AMateria &AMateria::operator=(const AMateria &rh_instance) {
	if (this != &rh_instance)
		this->type = rh_instance.getType();
	return (*this);
}

//==============================================================================
// 	METHODS OF THE AMateria CLASS.
//==============================================================================

const std::string &AMateria::getType() const {
	return (this->type);
}

AMateria& AMateria::setType(const std::string& new_type) {
	this->type = new_type;
	return (*this);
}

void AMateria::use(ICharacter &target) {
	std::cout << "Target "
			  << target.getName()
			  << " with "
			  << this->type
			  << std::endl;
}