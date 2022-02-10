#include "Karen.h"
#include <string>
#include <iostream>

Karen::Karen() {
	this->ptrArray[0] = &Karen::debug;
	this->ptrArray[1] = &Karen::info;
	this->ptrArray[2] = &Karen::warning;
	this->ptrArray[3] = &Karen::error;
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR"; }


void	Karen::filter(const std::string& level ) {
	int i;

	i = -1;
	while (++i < NB_LEVELS)
		if (levels[i] == level)
			break;
	switch (i) {
		case 0:
			(this->*ptrArray[i++])();
		case 1:
			(this->*ptrArray[i++])();
		case 2:
			(this->*ptrArray[i++])();
		case 3:
			(this->*ptrArray[i])();
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n\n"; }
	}

std::string		Karen::getLevel(int i) const { return (this->levels[i]); };

void	Karen::debug() {
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\n"
				 "ketchup burger. I really do!\n\n"; }

void	Karen::info() {
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\n"
				 "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n"; }

void	Karen::warning() {
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\n"
				 "years whereas you started working here since last month.\n\n"; }

void	Karen::error() {
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n"; }
