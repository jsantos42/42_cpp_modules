#include <iostream>
#include "Conversions.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Conversions::Conversions() : type(NAN) {
	std::cout << "[Conversions] Default constructor.\n";
}

Conversions::Conversions(const std::string& str) {
	std::cout << "[Conversions] String constructor.\n";
	storeType(str);
	printChar();
	printInt();
	printFloat();
	printDouble();
}

Conversions::Conversions(const Conversions &src) {
	*this = src;
	std::cout << "[Conversions] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Conversions::~Conversions() {
	std::cout << "[Conversions] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Conversions &Conversions::operator=(const Conversions &rh_instance) {
	if (this != &rh_instance) {
		this->type = rh_instance.getType();
		this->string = rh_instance.getString();
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Conversions CLASS.
//==============================================================================

void	Conversions::storeType(const std::string& str) {
	if (isChar(str))
		type = CHAR;
	else if (isInt(str))
		type = INT;
	else if (isFloat(str))
		type = FLOAT;
	else if (isDouble(str))
		type = DOUBLE;
}

int Conversions::getType() const {
	return (type);
}

std::string Conversions::getString() const {
	return (string);
}

bool Conversions::isChar(const std::string &str) {
	return (str.length() == 1 && std::isprint(str[0]));
}

bool Conversions::isInt(const std::string &str) {
	return
}