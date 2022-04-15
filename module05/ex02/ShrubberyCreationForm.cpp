#include "ShrubberyCreationForm.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137),
	target("UNNAMED") {
	std::cout << "[ShrubberyCreationForm] Default constructor.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target) :
	Form("ShrubberyCreationForm", 145, 137),
	target(_target) {
	std::cout << "[ShrubberyCreationForm] String constructor.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	Form(src) {
	*this = src;
	std::cout << "[ShrubberyCreationForm] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[ShrubberyCreationForm] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rh_instance) {
	if (this != &rh_instance)
		*this = rh_instance;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE ShrubberyCreationForm CLASS.
//==============================================================================
std::string ShrubberyCreationForm::getTarget() const {
	return (this->target);
}

Form&	ShrubberyCreationForm::execute(const Bureaucrat &executor) {
	try {
		if (!this->getSignedStatus() && executor.getGrade() <= this->getGradeToSign())
			this->beSigned(executor);
		if (this->getSignedStatus() && executor.getGrade() <= this->getGradeToExecute())
			;// execute
		else
			throw GradeTooLowException();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (*this);
}
