#include "ScavTrap.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
ScavTrap::ScavTrap() {
	std::cout << "[SCAVTRAP] Default constructor called.\n";
}

/*
 *	Here, in the copy constructor of the derived class, the base class
 *	'ClapTrap' should be explicitly initialized [with its copy constructor],
 *	since new constructors were written (rule of three) (and also because the
 *	default copy constructor of the base class was replaced by a custom one?)
 */
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	*this = src;
	std::cout << "[SCAVTRAP] Copy constructor called.\n";
}

ScavTrap::ScavTrap(const std::string& _name) {
	name = _name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "[SCAVTRAP] String constructor called with name "
			  << name
			  << ".\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

ScavTrap::~ScavTrap() {
	std::cout << "[SCAVTRAP] Destructor of scavtrap named "
			  << name
			  << " called.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

ScavTrap &ScavTrap::operator=(const ScavTrap &rh_instance) {
	if (this != &rh_instance) {
		this->name = rh_instance.name;
		this->hit_points = rh_instance.hit_points;
		this->energy_points = rh_instance.energy_points;
		this->attack_damage = rh_instance.attack_damage;
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE ScavTrap CLASS.
//==============================================================================

void ScavTrap::guardGate() {
	std::cout << "ScavTrap named "
			  << name
			  << " is now in Gate keeper mode.\n";
}