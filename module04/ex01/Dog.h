#ifndef EX00_DOG_H
#define EX00_DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &src);
	virtual ~Dog();

	Dog&			operator=(const Dog &rh_instance);
	virtual void	makeSound() const; // in C++11 an override should be here

private:
	Brain*	brain;
};

#endif //EX00_DOG_H
