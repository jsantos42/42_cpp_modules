#include <iostream>
#include "Karen.h"

int main() {
	Karen		newKaren;
	std::string	levels[NB_LEVELS];
	int			i;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	i = -1;
	while (++i < NB_LEVELS) {
		std::cout << levels[i] << " level:\n";
		newKaren.complain(levels[i]);
		std::cout << std::string(80, '-') << std::endl; }
	return 0; }
