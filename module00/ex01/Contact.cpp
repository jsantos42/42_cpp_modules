#include "Contact.h"
#include "utils.h"

/*
 *	Constructors, Destructors and Assign operator overload.
*/

Contact::Contact() {}

Contact::Contact(const Contact &src) {
	*this = src;
}

Contact::~Contact() {}

Contact&	Contact::operator=(const Contact& rh_instance) {
	if (this != &rh_instance) {
		this->first_name = rh_instance.first_name;
		this->last_name = rh_instance.last_name;
		this->nickname = rh_instance.nickname;
		this->phone_number = rh_instance.phone_number;
		this->darkest_secret = rh_instance.darkest_secret;
	}
	return (*this);
}

/*
 *	Functions of the Contact class.
*/

std::string	Contact::getFirstName() const { return this->first_name; }
std::string	Contact::getLastName() const { return this->last_name; }
std::string	Contact::getNickname() const { return this->nickname; }

/*
 *	Note the need to protect cin against a bad input (ex: char).
 *	Note the use of the (1) getline instead of just (2) std::cin >> input. The
 *	reason is:
 *	(1) stores the whole input in one var, while
 *	(2) splits the input using the space chars.
*/

void	Contact::create()
{
	std::cout << "Please provide the new contact info:";
	std::cout << std::endl << "First Name? ";
	std::getline(std::cin >> std::ws, first_name);
	std::cout << std::endl << "Last Name? ";
	std::getline(std::cin >> std::ws, last_name);
	std::cout << std::endl << "Nickame? ";
	std::getline(std::cin >> std::ws, nickname);
	std::cout << std::endl << "Phone Number? ";
	phone_number = protected_cin("CREATE");
	std::cout << std::endl << "Darkest secret? ";
	std::getline(std::cin >> std::ws, darkest_secret);
	std::cout << std::endl << "New contact added!" << std::endl;
}

void	Contact::display() {
	printStringNl(first_name);
	printStringNl(last_name);
	printStringNl(nickname);
	std::cout << phone_number << std::endl;
	printStringNl(darkest_secret);
	std::cout << std::endl;
}
