#include "Contact.h"
#include "PhoneBook.h"
#include "utils.h"

int main() {
	std::string	cmd;
	PhoneBook	my_phonebook;
	int			i;

	i = 0;
	while (1) {
		printStringNl("Please type one of the following commands:");
		printStringNl("ADD");
		printStringNl("SEARCH");
		printStringNl("EXIT");
		std::cin >> cmd;
		if (cmd == "ADD")
			my_phonebook.addContact(i);
		else if (cmd == "SEARCH")
			my_phonebook.searchContacts();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
