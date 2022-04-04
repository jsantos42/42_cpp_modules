#include <iostream>
#include <climits>
#include <cmath>
#include "Fixed.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================

Fixed::Fixed() : raw_bits(0) {
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called.\n";
	*this = src;
}

/*
 * Comment taken and adapted from the repo of dcavalei:
 *	The int raw_bits is being used to store a value, with the first 24 bits
 *	reserved to the sign and integer part and the last 8 bit to the fractional
 *	part. Therefore, the maximum number we can store is 8bits shorter than the
 *	MAX_INT. Note that, in the following diagram, the bits with a 0 on MUST be 0
 *	otherwise it will be out of range. Not sure if the first bit must also be 0,
 *	since it stores the sign info.
 *							  |
 *							 \|/
 *	bits before:	x0000000 0xxxxxxx xxxxxxxx xxxxxxxx
 *	bits after:		xxxxxxxx xxxxxxxx xxxxxxxx 00000000
 *					/|\						  |........| > fractal part
 *					 |
 */

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called.\n";
	raw_bits = value << fractional_bits;
	if (value > (INT_MAX >> fractional_bits))
		std::cout << "WARNING: The value "
				  << value
				  << " is out of range, undefined behaviour from now on.\n";
}

/*
 *	The float bitwise representation in different from the one for ints. Using
 *	a fixed-point number approach though, one can do the bitwise shift by
 *	multiplying or dividing by 2^x, where x is the number of places shift (see
 *	https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html). So, here
 *	it creates an int with the value 2^8 (the '1 << _fractal_bit_amount') which
 *	will be used to do the bit shifting.
*/

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called.\n";
	raw_bits = roundf(value * (1 << fractional_bits));
	if (value > (INT_MAX >> fractional_bits))
		std::cout << "WARNING: The value "
				  << value
				  << " is out of range, undefined behaviour from now on.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Fixed::~Fixed() {
	std::cout << "Destructor called.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Fixed&	Fixed::operator=(const Fixed& rh_instance) {
	if (this != &rh_instance)
		this->raw_bits = rh_instance.raw_bits;
	std::cout << "Copy assignment operator called.\n";
	return (*this);
}

// Prefix increment
Fixed&	Fixed::operator++() {
	this->raw_bits++;
	return (*this);
}

// Postfix increment
Fixed	Fixed::operator++(int) {
	Fixed	old;

	old = *this;
	operator++();
	return old;
}
Fixed&	Fixed::operator--();		// Prefix decrement
Fixed	Fixed::operator--(int);	// Postfix decrement

/*
Add public member functions to your class to overload the following operators:
• The 6 comparison operators: >, <, >=, <=, == and !=.
• The 4 arithmetic operators: +, -, *, and /.
• The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators, that will increase or decrease the ﬁxed-point value from the smallest representable  such as 1 +  > 1.
 */

std::ostream& operator<<(std::ostream &os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}



//==============================================================================
//	METHODS OF THE Fixed CLASS.
//==============================================================================

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called.\n";
	return (this->raw_bits);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "getRawBits member function called.\n";
	this->raw_bits = raw;
}

/*
 * Converts the raw_bits value to a float and returns it. Note that you cannot
 * just right shift and then cast to float, otherwise the compiler will just
 * trim the fractional part before the casting.
 */

float Fixed::toFloat() const {
	return ((float)this->raw_bits / (1 << fractional_bits));
}

/* Returns the integer part of the raw_bits value. */

int Fixed::toInt() const {
	return (this->raw_bits >> fractional_bits);
}
