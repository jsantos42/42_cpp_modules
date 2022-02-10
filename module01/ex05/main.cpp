#include <iostream>
#include "Karen.h"

int main() {
	Karen		newKaren;
	int			i;

	i = -1;
	while (++i < NB_LEVELS) {
		std::cout << newKaren.getLevel(i) << " level:\n";
		newKaren.complain(newKaren.getLevel(i));
		std::cout << std::string(80, '-') << std::endl; }
	return 0; }
