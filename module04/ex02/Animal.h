#ifndef EX00_ANIMAL_H
#define EX00_ANIMAL_H

#include <string>
#include <iostream>

/*
 *	Note that makeSound() ends as "= 0", meaning it is an unimplemented pure
 *	virtual method (there's no implementation in the .cpp file, only in the
 *	derived classes). As such, this class becomes abstract and cannot be
 *	instantiated. If this Abstract Class only had pure virtual methods, it would
 *	be called an interface.
 */
class Animal {
public:
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();

	Animal&			operator=(const Animal &rh_instance);
	std::string		getType() const;
	virtual void	makeSound() const = 0;

protected:
	std::string	type;
};

#endif //EX00_ANIMAL_H
