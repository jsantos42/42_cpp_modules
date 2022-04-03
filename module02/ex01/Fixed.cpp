#include <iostream>
#include "Fixed.h"

//==============================================================================
// 	Constructors
//==============================================================================

Fixed::Fixed() : raw_bits(0) {
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called.\n";
	*this = src;
}

Fixed::Fixed(const int value) {
//	It converts it to the corresponding fixed-point value. The fractional_bits bits value is
//	initialized to 8 like in exercise 00.
}

Fixed::Fixed(const float value) {
//It converts it to the corresponding fixed-point value. The fractional_bits bits value is
//initialized to 8 like in exercise 00.
}

//==============================================================================
// 	Destructor
//==============================================================================

Fixed::~Fixed() {
	std::cout << "Destructor called.\n";
}

//==============================================================================
// 	Operator Overloads
//==============================================================================

Fixed &Fixed::operator=(const Fixed& rh_instance) {
	if (this != &rh_instance)
		this->raw_bits = rh_instance.raw_bits;
	std::cout << "Copy assignment operator called.\n";
	return (*this);
}

std::ostream& operator<<(std::ostream &ostream, const Fixed& obj)
{}

//==============================================================================
//	Methods of the Fixed class.
//==============================================================================

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called.\n";
	return (this->raw_bits);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "getRawBits member function called.\n";
	this->raw_bits = raw;
}

float Fixed::toFloat() const
{
	// converts the fixed-point value to a floating-point value.
}

int Fixed::toInt() const
{
	// converts the fixed-point value to an integer value.
}
