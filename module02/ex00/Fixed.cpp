#include <iostream>
#include "Fixed.h"

/*
 *	Constructors, Destructors and Assign operator overload.
*/

Fixed::Fixed() : fixed_point_number(0)
{
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called.\n";
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called.\n";
}

Fixed&	Fixed::operator=(const Fixed &rh_instance)
{
	if (this != &rh_instance)
		this->fixed_point_number = rh_instance.fixed_point_number;
	std::cout << "Copy assignment operator called.\n";
	return (*this);
}

/*
 *	Functions of the Fixed class.
*/
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called.\n";
	return (this->fixed_point_number);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "getRawBits member function called.\n";
	this->fixed_point_number = raw;
}
