#include <iostream>
#include "Conversions.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Conversions::Conversions() {
	std::cout << "[Conversions] Default constructor.\n";
}

Conversions::Conversions(const std::string& str) {
	std::cout << "[Conversions] String constructor.\n";
	storeConversions(str);
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
		this->c = rh_instance.getChar();
		this->i = rh_instance.getInt();
		this->f = rh_instance.getFloat();
		this->d = rh_instance.getDouble();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Conversions& obj) {
	os << "char: " << obj.getChar() << std::endl
	   << "int: " << obj.getInt() << std::endl
	   << "float: " << obj.getFloat() << std::endl
	   << "double: " << obj.getDouble() << std::endl;
	return (os);
}

//==============================================================================
// 	METHODS OF THE Conversions CLASS.
//==============================================================================

int Conversions::getType(const std::string &str) {
	if (isChar(str))
		return (CHAR);

}

void Conversions::storeConversions(const std::string &str) {
	try {
		isc
		strtol
	}

}

char Conversions::getChar() const {
	return (c);
}

int Conversions::getInt() const {
	return (i);
}

float Conversions::getFloat() const {
	return (f);
}

double Conversions::getDouble() const {
	return (d);
}
