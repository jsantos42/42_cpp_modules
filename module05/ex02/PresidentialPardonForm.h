#ifndef EX02_PRESIDENTIALPARDONFORM_H
#define EX02_PRESIDENTIALPARDONFORM_H

#include "Form.h"

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm &rh_instance);
	virtual Form&			execute(const Bureaucrat& executor);
};

#endif //EX02_PRESIDENTIALPARDONFORM_H
