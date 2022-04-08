#include "DiamondTrap.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
DiamondTrap::DiamondTrap() {
	std::cout << "[DIAMONDTRAP] Default constructor called.\n";
}

/*
 *	The base class 'ClapTrap' should be explicitly initialized in the copy
 *	constructor of the derived class, (i.e. since the default copy constructor
 *	of the base class was replaced by a custom one, it has to be specified in
 *	the copy constructor of the derived ones).
 */
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src) {
	*this = src;
	std::cout << "[DIAMONDTRAP] Copy constructor called.\n";
}

DiamondTrap::DiamondTrap(const std::string& _name) {
	name = _name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "[DIAMONDTRAP] String constructor called with name "
			  << name
			  << ".\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

DiamondTrap::~DiamondTrap() {
	std::cout << "[DIAMONDTRAP] Destructor of scavtrap named "
			  << name
			  << " called.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rh_instance) {
	if (this != &rh_instance) {
		this->name = rh_instance.name;
		this->hit_points = rh_instance.hit_points;
		this->energy_points = rh_instance.energy_points;
		this->attack_damage = rh_instance.attack_damage;
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE DiamondTrap CLASS.
//==============================================================================

void	DiamondTrap::highFivesGuys() {
	std::cout << "DiamondTrap named "
			  << name
			  << " just high-fived his guys.\n";
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap named "
			<< name
			<< " says hi.\n";
}
