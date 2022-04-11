#ifndef EX00_WRONGCAT_H
#define EX00_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	virtual ~WrongCat();

	WrongCat &operator=(const WrongCat &rh_instance);
	void	makeSound() const;
};


#endif //EX00_WRONGCAT_H
