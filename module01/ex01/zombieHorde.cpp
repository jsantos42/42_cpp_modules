#include <sstream>
#include "zombieHorde.h"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*				horde = new Zombie[N];
	int					i;
	std::stringstream	stream;

	for (i = 0; i < N; i++) {
		stream << name << i;
		horde[i].setName(stream.str());
		stream.str("");
	}
	return (horde);
}
