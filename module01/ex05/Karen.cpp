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
	this->levels[3] = "ERROR";
	std::cout << "Karen instance created." << std::endl;}

Karen::~Karen() {
	std::cout << "Karen instance destroyed." << std::endl; }

void	Karen::complain(const std::string& level ) {
	int			i;

	i = -1;
	while(++i < NB_LEVELS)
		if (levels[i] == level) {
			(this->*ptrArray[i])();
			break ; }
	if (i == NB_LEVELS)
		std::cout << "ERROR: Karen only has the following levels:" << std::endl
				  << "'debug', 'info', 'warning' and 'error'.\n\n"; }

void	Karen::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\n"
				 "ketchup burger. I really do!" << std::endl; }

void	Karen::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\n"
				 "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl; }

void	Karen::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\n"
				 "years whereas you started working here since last month." << std::endl; }

void	Karen::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; }
