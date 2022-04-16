#include <iostream>
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main() {
	Bureaucrat	smith("Mr Smith", 4);
	Bureaucrat	neo("NEO", 1);
	ShrubberyCreationForm		s("s");

	std::cout << smith << std::endl;
	std::cout << s;
	s.beSigned(smith);
	smith.signForm(s);
	std::cout << s;
	s.beSigned(neo);
	std::cout << s;

	return (0);
}