#include <iostream>
#include "Karen.h"

int main(int ac, char** av) {
	Karen		newKaren;

	if (ac != 2) {
		std::cout << "Karen must complain about something!\n"
				  << "Give her only 1 argument. Some options: DEBUG, INFO, WARNING, ERROR.\n";
		return (1); }
	newKaren.filter(av[1]);
	return 0; }
