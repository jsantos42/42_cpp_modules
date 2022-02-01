#include <iostream>
#include <string>
#include "utils.h"

int	protected_cin(const std::string& str)
{
	int	input;

	std::cin >> input;
	while (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore();
		if (str == "SEARCH")
			return (-1);
		std::cout << std::endl << "Wrong input, please provide a valid number: ";
		std::cin >> input;
	}
	return (input);
}

void	printStringNl(const std::string &str){ std::cout << str << std::endl; }

std::string fitIntoSize(std::string str) {
	std::size_t	size;

	size = str.size();
	if (size <= COL_WIDTH)
		return (str.insert(0, COL_WIDTH - size, ' '));
	return (str.substr(0, COL_WIDTH - 1) + ".");
}
