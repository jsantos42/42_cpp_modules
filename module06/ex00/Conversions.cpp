#include <iostream>
#include <sstream>
#include "Conversions.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Conversions::Conversions() : type(NONE) {
	std::cout << "[Conversions] Default constructor.\n";
}

Conversions::Conversions(const std::string& str) {
	std::cout << "[Conversions] String constructor.\n";
	storeType(str);
	storeStringNumber(str);
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
	if (isSpecial(str))
		type = SPECIAL;
	else if (isInt(str))
		type = INT;
	else if (isChar(str))
		type = CHAR;
	else if (isFloat(str))
		type = FLOAT;
	else if (isDouble(str))
		type = DOUBLE;
}

void Conversions::storeStringNumber(const std::string &str) {
	std::istringstream	stream(str);
	char				c;

	string = str;
	if (getType() == SPECIAL) {
		if (str == "-inff" || str == "+inff" || str == "nanf")
			string = str.substr(0, str.length() - 1);
	}
	else if (getType() == INT || getType() == FLOAT || getType() == DOUBLE)
		stream >> number;
	else if (getType() == CHAR) {
		stream >> c;
		number = c;
	}
	else
		number = 0;
}

int Conversions::getType() const {
	return (type);
}

double Conversions::getNumber() const {
	return (number);
}

std::string Conversions::getString() const {
	return (string);
}

//==============================================================================
//	IS FUNCTIONS
//==============================================================================

bool Conversions::isSpecial(const std::string &str) {
	std::string special_cases[] = {"-inf", "+inf", "inf", "nan"};

	for (unsigned long i = 0; i < 4; i++)
		if (str == special_cases[i] || str == (special_cases[i] + "f"))
			return (true);
	return (false);
}

bool Conversions::isChar(const std::string &str) {
	return (str.length() == 1 && std::isprint(str[0]));
}

/*
 *	Stream output from an istringstream (input stream that operates on strings)
 *	eof() makes sure the string has ended.
 *	fail() informs if an error occurred during the output operation
 */
bool Conversions::isInt(const std::string &str) {
	std::istringstream	stream(str);
	int					i;

	stream >> i;
	return (stream.eof() && !stream.fail());
}

bool Conversions::isFloat(const std::string &str) {
	std::string			numeric = str.substr(0, str.length() - 1);
	std::string			alpha = str.substr(str.length() - 1, 1);
	std::istringstream	stream(numeric);
	int					point = 0;
	float				f;

	for (unsigned long i = 0; i < numeric.length(); i++)
		if (numeric[i] == '.')
			point++;

	stream >> f;
	return (stream.eof() && !stream.fail() && point == 1 && alpha == "f");
}

bool Conversions::isDouble(const std::string &str) {
	std::istringstream	stream(str);
	double				d;

	stream >> d;
	return (stream.eof() && !stream.fail());
}

//==============================================================================
//	PRINT FUNCTIONS
//==============================================================================

void Conversions::printChar() const {
	std::cout << "char: ";
	if (getType() == NONE || getType() == SPECIAL)
		std::cout << "impossible\n";
	else if (std::isprint(static_cast<int>(getNumber())))
		std::cout << '\'' << static_cast<char>(getNumber()) << '\'' << std::endl;
	else
		std::cout << "non printable char\n";
}

void Conversions::printInt() const {
	std::cout << "int: ";
	if (getType() == NONE || getType() == SPECIAL)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(getNumber()) << std::endl;
}

void Conversions::printFloat() const {
	std::cout << "float: ";
	if (getType() == NONE)
		std::cout << "impossible\n";
	else if (getType() == SPECIAL)
		std::cout << getString() << "f\n";
	else
		std::cout << std::fixed << static_cast<float>(getNumber()) << "f\n";
}

void Conversions::printDouble() const {
	std::cout << "double: ";
	if (getType() == NONE)
		std::cout << "impossible\n";
	else if (getType() == SPECIAL)
		std::cout << getString() << std::endl;
	else
		std::cout << std::fixed << static_cast<double>(getNumber()) << std::endl;
}