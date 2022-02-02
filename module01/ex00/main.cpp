#include "Zombie.h"
#include "newZombie.h"
#include "randomChump.h"

int main() {
	Zombie *heap;
	Zombie classy("classy");

	classy.announce();
	randomChump("stack");
	heap = newZombie("heap");
	delete(heap);
	return 0;
}
