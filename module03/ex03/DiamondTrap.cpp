#include "DiamondTrap.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
DiamondTrap::DiamondTrap() {
	std::cout << "[DIAMONDTRAP] Default constructor called.\n";
}

/*
 *	Here, in the copy constructor of the derived class, the base classes
 *	ClapTrap, ScavTrap and FragTrap should be explicitly initialized [with its
 *	copy constructor], since new constructors were written (rule of three) (and
 *	also because the default copy constructor of the base class was replaced by
 *	a custom one?)
 */
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	*this = src;
	std::cout << "[DIAMONDTRAP] Copy constructor called.\n";
}

/*
 * Note that both ScavTrap and FragTrap need to have virtual inheritance from
 * ClapTrap in order to avoid the diamond trap (check their .h). Otherwise, the
 * compiler would throw the following errors:
 * 1) Ambiguous conversion from derived class DiamondTrap to base class ClapTrap
 * 2) Non-static member found in multiple base-class subobjects of type ClapTrap
 *
 * Also note that, on this derived class, we have to specify which constructor
 * from the parent we want it to use, otherwise it will use the default one,
 * which does not initialize the attributes, thus giving a random number when
 * calling the method DiamondTrap::attack().
 */
DiamondTrap::DiamondTrap(const std::string& _name) : ClapTrap(_name), ScavTrap(_name), FragTrap(_name) {
	ClapTrap::name = _name + "_clap_name";			// (1)
	name = _name;
	hit_points = FragTrap::getHitPoints();			// (2)
	energy_points = ScavTrap::getEnergyPoints();	// (2)
	attack_damage = FragTrap::getAttackDamage();	// (2)
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

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "Hello, I'm DiamondTrap named "
			<< name
			<< " and my ClapTrap parent is named "
			<< ClapTrap::name
			<< ".\n";
}

