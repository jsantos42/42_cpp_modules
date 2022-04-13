#ifndef EX01_FORM_H
#define EX01_FORM_H

#include <string>
#include <iostream>

class Form {
public:
	Form(const std::string& _name, const int to_sign, const int to_exec);
	Form(const Form &src);
	virtual ~Form();

	Form&			operator=(const Form &rh_instance);
	std::string		getName() const;
	bool			getSignedStatus() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	Form&			setName(const std::string& _name);
	Form&			setSignedStatus(bool status);
//	Form&			setGradeToSign(int);
//	Form&			setGradeToExecute(int);

	class GradeTooHighException : public std::exception {
	public:
		const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char*	what() const throw();
	};

private:
	Form();
	std::string	name;
	bool		signed_status;
	const int	grade_to_sign;
	const int	grade_to_execute;
};


#endif //EX01_FORM_H
