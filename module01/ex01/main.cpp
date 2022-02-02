#include <iostream>
#include "Zombie.h"
#include "zombieHorde.h"

int main() {
	Zombie*	horde;
	int		i;
	int		nb_zombies;

	nb_zombies = 10;
	horde = zombieHorde(nb_zombies, "Zombie #");
	for (i = 0; i < nb_zombies; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
