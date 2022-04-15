#include <iostream>
#include "Bureaucrat.h"
#include "Form.h"

int main() {
	Bureaucrat	smith("Mr Smith", 4);
	Bureaucrat	neo("NEO", 1);
	Form		f1("f1", 3, 2);

	std::cout << smith << std::endl;
	std::cout << f1;
	f1.beSigned(smith);
	smith.signForm(f1);
	std::cout << f1;
	f1.beSigned(neo);
	std::cout << f1;

	return (0);
}