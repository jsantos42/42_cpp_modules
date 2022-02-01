#ifndef EX01_PHONEBOOK_H
#define EX01_PHONEBOOK_H

#include <string>
#include <iostream>
#include "const.h"
#include "Contact.h"

class PhoneBook{
public:
	PhoneBook(void);					// Default constructor
	PhoneBook(const PhoneBook &src);	// Copy constructor
	virtual ~PhoneBook(void);			// Default destructor

	PhoneBook&	operator=(const PhoneBook &rh_instance);	// Assign operator overload

	void		addContact(int& index);
	void		searchContacts();
	void		displayContactList();

private:
	Contact		contact_list[MAX_NB_CONTACTS];
	int			stored;
};

#endif //EX01_PHONEBOOK_H
