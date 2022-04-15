#include "RobotomyRequestForm.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", 72, 45) {
	std::cout << "[RobotomyRequestForm] Default constructor.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) {
	*this = src;
	std::cout << "[RobotomyRequestForm] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[RobotomyRequestForm] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &rh_instance) {
	if (this != &rh_instance)
		*this = rh_instance;
	return (*this);
}

//==============================================================================
// 	METHODS OF THE RobotomyRequestForm CLASS.
//==============================================================================
Form&	RobotomyRequestForm::execute(const Bureaucrat &executor) {
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
