#ifndef EX00_CAT_H
#define EX00_CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &src);
	virtual ~Cat();

	Cat&			operator=(const Cat &rh_instance);
	virtual void	makeSound() const; // in C++11 an override should be here
};


#endif //EX00_CAT_H
