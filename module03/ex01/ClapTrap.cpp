#include "ClapTrap.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
ClapTrap::ClapTrap() {
	std::cout << "[CLAPTRAP] Default constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
}

ClapTrap::ClapTrap(const std::string& name)
		: name(name),
		  hit_points(10),
		  energy_points(10),
		  attack_damage(0) {
	std::cout << "[CLAPTRAP] String constructor called with name " << name << ".\n";
}


//==============================================================================
// 	DESTRUCTORS
//==============================================================================

ClapTrap::~ClapTrap() {
	std::cout << "[CLAPTRAP] Destructor of claptrap named "
			  << name
			  << " called.\n";
}


//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

ClapTrap&	ClapTrap::operator=(const ClapTrap &rh_instance) {
	if (this != &rh_instance) {
		this->name = rh_instance.name;
		this->hit_points = rh_instance.hit_points;
		this->energy_points = rh_instance.energy_points;
		this->attack_damage = rh_instance.attack_damage;
	}
	return (*this);
}


//==============================================================================
// 	METHODS OF THE ClapTrap CLASS.
//==============================================================================

void	ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap named "
			  << this->name
			  << " just attacked target named "
			  << target
			  << ", making it lose "
			  << attack_damage
			  << " points.\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap named "
			  << this->name
			  << " was just attacked, losing "
			  << amount
			  << " points.\n";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap named "
			  << this->name
			  << " was just repaired, gaining "
			  << amount
			  << " points.\n";
}

ClapTrap&	ClapTrap::setName(const std::string& new_name) {
	this->name = new_name;
	return (*this);
}

ClapTrap&	ClapTrap::setHitPoints(const int& value) {
	this->hit_points = value;
	return (*this);
}

ClapTrap&	ClapTrap::setEnergyPoints(const int& value) {
	this->energy_points = value;
	return (*this);
}
ClapTrap&	ClapTrap::setAttackDamage(const int& value) {
	this->attack_damage = value;
	return (*this);
}

std::string	ClapTrap::getName() {
	return (this->name);
}

int			ClapTrap::getHitPoints() {
	return (this->hit_points);
}

int			ClapTrap::getEnergyPoints() {
	return (this->energy_points);
}

int			ClapTrap::getAttackDamage() {
	return (this->attack_damage);
}
