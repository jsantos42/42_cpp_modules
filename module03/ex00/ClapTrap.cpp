#include "ClapTrap.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
ClapTrap::ClapTrap() {
	std::cout << "Default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name),
	hit_points(10),
	energy_points(10),
	attack_damage(0) {
	std::cout << "String constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &src)
{ *this = src; }


//==============================================================================
// 	DESTRUCTORS
//==============================================================================

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called.\n";
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

/*
 *When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.
In all of these member functions, you have to print a message to describe what hap-
pens. For example, the attack() function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!
The constructors and destructor must also display a message, so your peer-evaluators
can easily see they have been called.
Implement and turn in your own tests to ensure your code works as expected.
 */

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
