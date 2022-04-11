#ifndef EX00_ANIMAL_H
#define EX00_ANIMAL_H

#include <string>
#include <iostream>

class Animal {
public:
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();

	Animal&			operator=(const Animal &rh_instance);
	std::string		getType() const;
	virtual void	makeSound() const;

protected:
	std::string	type;
};

#endif //EX00_ANIMAL_H
