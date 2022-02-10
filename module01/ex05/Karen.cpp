#include "Karen.h"
#include <string>
#include <iostream>

void	Karen::complain( std::string level ) {
	///pointers to functions??
}

void	Karen::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\n"
				 "ketchup burger. I really do!" << std::endl;
}

void	Karen::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\n"
				 "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Karen::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\n"
				 "years whereas you started working here since last month." << std::endl;
}

void	Karen::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

