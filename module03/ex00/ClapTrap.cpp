#include "ClapTrap.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
ClapTrap::ClapTrap() {
	std::cout << "Default constructor called. Missing name.\n";
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

ClapTrap::~ClapTrap()
{}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

ClapTrap& ClapTrap::operator=(const ClapTrap &rh_instance)
{
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

void ClapTrap::attack(const std::string &target) {
	target.take
}
