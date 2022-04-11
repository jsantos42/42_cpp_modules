#ifndef EX00_WRONGANIMAL_H
#define EX00_WRONGANIMAL_H

#include <string>
#include <iostream>

/*
 *	The only difference from Animal.h is that makeSound() is not a virtual
 *	method, making it impossible for the equally named method from the derived
 *	class to override it.
 */
class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal();

	WrongAnimal&	operator=(const WrongAnimal &rh_instance);
	std::string		getType() const;
	void	makeSound() const;

protected:
	std::string	type;
};

#endif //EX00_WRONGANIMAL_H
