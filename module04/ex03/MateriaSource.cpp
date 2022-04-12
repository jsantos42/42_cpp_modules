#include "MateriaSource.h"
#include "Ice.h"
#include "Cure.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
MateriaSource::MateriaSource() {
	std::cout << "[MateriaSource] Default constructor.\n";
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
	std::cout << "[MateriaSource] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

MateriaSource::~MateriaSource() {
	std::cout << "[MateriaSource] Destructor.\n";
	for (int i = 0; i < 4; i++)
		if (this->slots[i])
			delete this->slots[i];
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

MateriaSource &MateriaSource::operator=(const MateriaSource &rh_instance) {
	if (this != &rh_instance) {
		for (int i = 0; i < 4; i++) {
			if (rh_instance.slots[i]) {
				if (rh_instance.slots[i]->getType() == "ice")
					this->slots[i] = new Ice;
				else
					this->slots[i] = new Cure;
				*(this->slots[i]) = *(rh_instance.slots[i]);
			}
		}
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE MateriaSource CLASS.
//==============================================================================
void	MateriaSource::learnMateria(AMateria *materia) {
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!this->slots[i]) {
			this->slots[i] = materia;
			std::cout << "Learned " << materia->getType() << " .\n";
			return ;
		}
	}
	std::cout << "Cannot learn any further materials.\n";
}

AMateria*	MateriaSource::createMateria(const std::string &type) {
	AMateria*	exported;

	for (int i = 0; i < 4; i++) {
		if (this->slots[i] && this->slots[i]->getType() == type) {
			if (this->slots[i]->getType() == "ice")
				exported = new Ice;
			else
				exported = new Cure;
			*exported = *(this->slots[i]);
			return (exported);
		}
	}
	std::cout << "Don't know that material.\n";
	return (0);
}