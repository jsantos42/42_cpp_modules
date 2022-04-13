#include "Form.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Form::Form() : grade_to_sign(-1), grade_to_execute(-1) {
	std::cout << "[Form] Default constructor.\n";
}

Form::Form(const std::string &_name, const int to_sign, const int to_exec) :
	name(_name),
	signed_status(false),
	grade_to_sign(to_sign),
	grade_to_execute(to_exec) {
	std::cout << "[Form] Proper constructor.\n";
}

Form::Form(const Form &src) :
		name(src.name),
		signed_status(src.signed_status),
		grade_to_sign(src.grade_to_sign),
		grade_to_execute(src.grade_to_execute) {
	*this = src;
	std::cout << "[Form] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Form::~Form() {
	std::cout << "[Form] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Form &Form::operator=(const Form &rh_instance) {
	if (this != &rh_instance) {
		name = rh_instance.name;
		signed_status = rh_instance.signed_status;
		grade_to_sign = rh_instance.grade_to_sign;
		grade_to_execute = rh_instance.grade_to_execute;
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Form CLASS.
//==============================================================================
std::string Form::getName() const {
	return (this->name);
}

bool Form::getSignedStatus() const {
	return (this->signed_status);
}

int Form::getGradeToSign() const {
	return (this->grade_to_sign);
}

int Form::getGradeToExecute() const {
	return (this->grade_to_execute);
}

Form &Form::setName(const std::string& _name) {
	this->name = _name;
}

Form &Form::setSignedStatus(bool status) {
	this->signed_status = status;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("[FORM] Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("[FORM] Grade is too low!");
}