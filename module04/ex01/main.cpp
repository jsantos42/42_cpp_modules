#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

#define NB	6

int	main() {
/*
 * Note that the size of the parent class Animal is != from the size of the
 * derived classes Dog and Cat, so be careful not to allocate as parent and
 * fill with derived.
 */
	Animal*	animals[NB];
	int		i;

	for (i = 0; i < NB; i++)
	{
		if (i < 3)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (i = 0; i < NB; i++)
		delete animals[i];

/*
 * Thanks to the deep copy done with the copy constructor, this would work and
 * not segfault (to uncomment these lines, make both attributes public).
 */
//	Dog* dog1 = new Dog;
//	Dog* dog2 = new Dog(*dog1);
//	delete dog1;
//	std::cout << dog2->brain->ideas[0];
//	delete dog2;


//	Dog* dog1 = new Dog();
//	Dog* dog2 = dog1;
//	delete dog1;
//	dog2->makeSound();
	return (0);
}