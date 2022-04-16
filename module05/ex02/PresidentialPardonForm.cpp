#include "PresidentialPardonForm.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 25, 5),
	target("UNNAMED") {
	std::cout << "[PresidentialPardonForm] Default constructor.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target) :
	Form("PresidentialPardonForm", 25, 5),
	target(_target) {
	std::cout << "[PresidentialPardonForm] String constructor.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	Form(src) {
	*this = src;
	std::cout << "[PresidentialPardonForm] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[PresidentialPardonForm] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &rh_instance) {
	if (this != &rh_instance)
		*this = rh_instance;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE PresidentialPardonForm CLASS.
//==============================================================================
std::string	PresidentialPardonForm::getTarget() const {
	return (this->target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	try {
		if (this->getSignedStatus() && executor.getGrade() <= this->getGradeToExecute())
			;// execute
		else
			throw GradeTooLowException();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}