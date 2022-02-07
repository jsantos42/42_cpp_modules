#include "utils.h"
#include <iostream>

void	_output(const std::string& str, bool new_line) {
	std::cout << str;
	if (new_line)
		std::cout << std::endl;
}
