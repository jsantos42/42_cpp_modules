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

//	Copy Assignment operator
Fixed&	Fixed::operator=(const Fixed& rh_instance) {
	if (this != &rh_instance)
		this->raw_bits = rh_instance.raw_bits;
	std::cout << "Copy assignment operator called.\n";
	return (*this);
}


//	Comparison operators
bool	Fixed::operator==(const Fixed& rh_instance) const {
	return (this->getRawBits() == rh_instance.getRawBits());
}

bool	Fixed::operator>(const Fixed& rh_instance) const {
	return (this->getRawBits() > rh_instance.getRawBits());
}

bool	Fixed::operator<(const Fixed& rh_instance) const {
	return (this->getRawBits() < rh_instance.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rh_instance) const {
	return !(*this == rh_instance);
}

bool	Fixed::operator>=(const Fixed& rh_instance) const {
	return !(*this < rh_instance);
}

bool	Fixed::operator<=(const Fixed& rh_instance) const {
	return !(*this > rh_instance);
}


//	Arithmetic operators
Fixed	Fixed::operator+(const Fixed& rh_instance) const {
	Fixed	sum(this->toFloat() + rh_instance.toFloat());

	return (sum);
}

Fixed	Fixed::operator-(const Fixed& rh_instance) const {
	Fixed	difference(this->toFloat() - rh_instance.toFloat());

	return (difference);
}

Fixed	Fixed::operator*(const Fixed& rh_instance) const {
	Fixed	product(this->toFloat() * rh_instance.toFloat());

	return (product);
}

Fixed	Fixed::operator/(const Fixed& rh_instance) const {
	Fixed	quotient(this->toFloat() / rh_instance.toFloat());

	return (quotient);
}


//	Prefix increment and decrement
Fixed&	Fixed::operator++() {
	this->raw_bits++;
	return (*this);
}

Fixed&	Fixed::operator--() {
	this->raw_bits--;
	return (*this);
}

/*
 * Why does the postfix increment operator take a dummy parameter? The following
 * explanation comes from
 * https://stackoverflow.com/questions/3574831/why-does-the-postfix-increment-operator-take-a-dummy-parameter
 *
 * Prefix and postfix ++ are different operators. With the standard Foo operator
 * symbol(Foo &) style declaration there was no obvious way to distinguish the
 * two. Rather than come up with some new syntax like Foo symbol operator(Foo &)
 * which would make it into a special case unlike all the other operators and
 * likely a bit of a pain to parse, the language designers wanted some other
 * solution.
 * The solution they chose was somewhat bizarre. They noted that all the other
 * 'postfix' operators (i.e. operators that occurred after one of their
 * operands) were actually infix operators that took two arguments. For example,
 * plain old +, / or >. On this basis the language designers decided that having
 * a random dummy argument would be a good way to distinguish between prefix and
 * postfix ++.
 */

//	Postfix increment and decrement (changes, but returns a pre-change copy)
Fixed	Fixed::operator++(int) {
	Fixed	pre_increment = *this;
	operator++();
	return (pre_increment);
}

Fixed	Fixed::operator--(int) {
	Fixed	pre_decrement = *this;
	operator--();
	return (pre_decrement);
}


//	Stream extraction and insertion
std::ostream& operator<<(std::ostream &os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}


//==============================================================================
//	METHODS OF THE FIXED CLASS.
//==============================================================================

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called.\n";
	return (this->raw_bits);
}

// This return type allows operations to be concatenated.
Fixed&	Fixed::setRawBits(const int raw) {
	std::cout << "getRawBits member function called.\n";
	this->raw_bits = raw;
	return (*this);
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

Fixed&	Fixed::min(Fixed& first, Fixed& second) {
	return ((first < second) ? first : second);
}

Fixed&	Fixed::max(Fixed& first, Fixed& second) {
	return ((first > second) ? first : second);
}

const Fixed&	Fixed::min(const Fixed& first, const Fixed& second) {
	return ((first < second) ? first : second);
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& second) {
	return ((first > second) ? first : second);
}
