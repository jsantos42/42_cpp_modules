#include "PhoneBook.h"
#include "utils.h"

/*
 *	Constructors, Destructors and Assign operator overload.
*/

PhoneBook::PhoneBook(void) : stored(0) {}

PhoneBook::PhoneBook(const PhoneBook &src) {
	*this = src;
}

PhoneBook::~PhoneBook(void) {}

PhoneBook &PhoneBook::operator=(const PhoneBook &rh_instance) {
	if (this != &rh_instance)
		this->stored = rh_instance.stored;
	return (*this);
}

/*
 *	Functions of the PhoneBook class.
*/

void		PhoneBook::addContact(int& i) {
	Contact	newContact;

	newContact.create();
	contact_list[i++] = newContact;
	i %= MAX_NB_CONTACTS;
	if (stored < MAX_NB_CONTACTS)
		stored++;
}

void	PhoneBook::searchContacts() {
	std::string str;
	int			index;

	displayContactList();
	printStringNl("Which one are you looking for? Contact index: #");
	index = protected_cin("SEARCH");
	if (!(index >= 0 && index < stored)) {
		printStringNl("There is no contact with that index number.");
		std::cout << std::endl;
		return;
	}
	contact_list[index].display();
}

void	PhoneBook::displayContactList() {
	int			i;
	std::string cols[] = {"INDEX", "FIRST NAME", "LAST NAME", "NICKNAME",
						  "PHONE NUMBER", "DARKEST SECRET"};

	std::cout << "Here are the contacts on the list." << std::endl;
	i = -1;
	while (++i < 4) {
		std::cout << fitIntoSize(cols[i]) << COL_DELIMITER;
	}
	std::cout << std::endl;
	i = -1;
	while (++i < stored) {
		std::cout << "         " << i << COL_DELIMITER
				  << fitIntoSize(contact_list[i].getFirstName()) << COL_DELIMITER
				  << fitIntoSize(contact_list[i].getLastName()) << COL_DELIMITER
				  << fitIntoSize(contact_list[i].getNickname()) << COL_DELIMITER
				  << std::endl;
	}
}

