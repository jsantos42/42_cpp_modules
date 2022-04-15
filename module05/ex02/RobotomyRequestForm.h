#ifndef EX02_ROBOTOMYREQUESTFORM_H
#define EX02_ROBOTOMYREQUESTFORM_H

#include "Form.h"

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm &rh_instance);
	virtual Form&			execute(const Bureaucrat& executor);
};

#endif //EX02_ROBOTOMYREQUESTFORM_H
