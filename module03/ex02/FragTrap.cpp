#include "FragTrap.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
FragTrap::FragTrap() {
	std::cout << "[FRAGTRAP] Default constructor called.\n";
}

/*
 *	Here, in the copy constructor of the derived class, the base class
 *	'ClapTrap' should be explicitly initialized [with its copy constructor],
 *	since new constructors were written (rule of three) (and also because the
 *	default copy constructor of the base class was replaced by a custom one?)
 */
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	*this = src;
	std::cout << "[FRAGTRAP] Copy constructor called.\n";
}

FragTrap::FragTrap(const std::string& _name) {
	name = _name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "[FRAGTRAP] String constructor called with name "
			  << name
			  << ".\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

FragTrap::~FragTrap() {
	std::cout << "[FRAGTRAP] Destructor of scavtrap named "
			  << name
			  << " called.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

FragTrap &FragTrap::operator=(const FragTrap &rh_instance) {
	if (this != &rh_instance) {
		this->name = rh_instance.name;
		this->hit_points = rh_instance.hit_points;
		this->energy_points = rh_instance.energy_points;
		this->attack_damage = rh_instance.attack_damage;
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE FragTrap CLASS.
//==============================================================================

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap named "
			  << name
			  << " just high-fived his guys.\n";
}
