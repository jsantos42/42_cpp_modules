#ifndef EX00_BUREAUCRAT_H
#define EX00_BUREAUCRAT_H

#include <string>
#include <iostream>

class Bureaucrat {
public:
	Bureaucrat(const std::string& _name, int _grade);
	Bureaucrat(const Bureaucrat &src);
	virtual ~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat &rh_instance);
	Bureaucrat&	operator++();
	Bureaucrat&	operator--();
	Bureaucrat	operator++(int);
	Bureaucrat	operator--(int);
	std::string	getName() const;
	int			getGrade() const;
	Bureaucrat&	setName(const std::string& _name);
	Bureaucrat&	setGrade(int _grade);


	class GradeTooHighException : public std::exception {
	public:
		const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char*	what() const throw();
	};

private:
	Bureaucrat();
	std::string	name;
	int			grade;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& rh_instance);

#endif //EX00_BUREAUCRAT_H