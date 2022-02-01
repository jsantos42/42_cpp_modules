#ifndef EX01_CONTACT_H
#define EX01_CONTACT_H

#include <string>
#include <iostream>

class Contact {
public:
	Contact();					// Default constructor
	Contact(const Contact &src);	// Copy constructor
	virtual ~Contact();			// Default destructor

	Contact &operator=(const Contact &rh_instance);	// Assign operator overload

	std::string	getFirstName(void) const;
	std::string getLastName(void) const;
	std::string	getNickname(void) const;
	void		create();
	void		display();


private:
	std::string	first_name;
	std::string last_name;
	std::string	nickname;
	int			phone_number;  //if expecting non-portuguese numbers, it can't be an integer!!
	std::string	darkest_secret;
};

#endif //EX01_CONTACT_H
