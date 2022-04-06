#include "ClapTrap.h"
#include "ScavTrap.h"

int	main() {
	ClapTrap	a("AA");
	ScavTrap	b("ola");
	ScavTrap	c(b);

	a.attack("BB");
	a.setAttackDamage(2).attack("BB");
	a.takeDamage(4);
	a.beRepaired(10);
	a.setAttackDamage(5).attack("CC");
	std::cout << b.getAttackDamage() << std::endl;
}