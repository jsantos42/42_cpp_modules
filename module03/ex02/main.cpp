#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

int	main() {
	ClapTrap	a("AA");
	ScavTrap	b("ola");
	ScavTrap	c(b);
	FragTrap	e("XX");

	a.attack("BB");
	a.setAttackDamage(2).attack("BB");
	a.takeDamage(4);
	a.beRepaired(10);
	a.setAttackDamage(5).attack("CC");
	b.attack("AA");
	b.guardGate();
	std::cout << b.getAttackDamage() << std::endl;
	e.highFivesGuys();
}