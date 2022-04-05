#include "ClapTrap.h"

int	main() {
	ClapTrap	a("AA");

	a.attack("BB");
	a.setAttackDamage(2).attack("BB");
	a.takeDamage(4);
	a.beRepaired(10);
	a.setAttackDamage(5).attack("CC");
}