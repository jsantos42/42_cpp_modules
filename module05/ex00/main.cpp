#include <iostream>
#include "Bureaucrat.h"

int main() {
	Bureaucrat a("Mr Smith", 3);
	std::cout << a << std::endl;
	std::cout << "ola" << std::endl;
	a++;
	std::cout << a.getGrade() << std::endl;
	++a;
	std::cout << a.getGrade() << std::endl;

	return (0);
}