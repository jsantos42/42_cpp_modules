#include <iostream>
#include "utils.h"

int main() {
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	_output("The memory address of the string itself:", false);
	std::cout << &str << std::endl;
	_output("The memory address pointed by strPTR:\t", false);
	std::cout << stringPTR << std::endl;
	_output("The memory address pointed by strREF:\t", false);
	std::cout << &stringREF << std::endl << std::endl;

	_output("The value of the string itself:\t", false);
	std::cout << str << std::endl;
	_output("The value pointed by strPTR:\t", false);
	std::cout << *stringPTR << std::endl;
	_output("The value pointed by strREF:\t", false);
	std::cout << stringREF << std::endl;
	return 0;
}
