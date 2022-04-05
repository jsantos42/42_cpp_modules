#include <iostream>
#include "Fixed.h"

int main() {
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "A is " << a << std::endl;

	std::cout << b << std::endl;
	std::cout << "Sum is " << a + a << std::endl;
	std::cout << "A is " << a << std::endl;
	std::cout << "B is " << b << std::endl;
	std::cout << "Multiplication is " << a * b << std::endl;
	std::cout << "Division is " << a / b << std::endl;


//	std::cout << Fixed::max(a, b) << std::endl;
}
