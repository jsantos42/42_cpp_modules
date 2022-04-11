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
	std::cout << "========================================\n";
	std::cout << "TESTING FROM THE SUBJECT\n";
	std::cout << "========================================\n";
	Animal*	animals[NB];
	int		i;

	for (i = 0; i < NB; i++)
	{
		if (i < 3)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (i = 0; i < NB; i++) {
		animals[i]->makeSound();
		delete animals[i];
	}

/*
 * Thanks to the deep copy done with the copy constructor, this would work and
 * not segfault (to uncomment these lines, make both attributes public).
 */
	std::cout << "========================================\n";
	std::cout << "TESTING THE DEEP COPY\n";
	std::cout << "========================================\n";
	Dog* dog1 = new Dog;
	Dog* dog2 = new Dog(*dog1);
	delete dog1;
	std::cout << dog2->getBrain()->getIdea(0);

	std::cout << "========================================\n";
	std::cout << "TESTING THE ASSIGNMENT OP OVERLOAD\n";
	std::cout << "========================================\n";
	Dog* dog3 = new Dog;
	Dog* temp = dog3;
	dog3 = dog2;
	delete dog2;
	dog3 = temp;
	std::cout << dog3->getBrain()->getIdea(0);
	dog3->makeSound();
	delete dog3;

	std::cout << "========================================\n";
	std::cout << "TESTING THE ASSIGNMENT OP OVERLOAD (from dcavalei)\n";
	std::cout << "========================================\n";
	Animal*	cat = new Cat;
	Animal*	dog = new Dog;
	// it uses the animal assignment operator, since they are both Animal ptrs. So it will copy only the _type
	*cat = *dog;
	std::cout << '|' << cat->getType() << "| ";
	cat->makeSound();
	std::cout << '|' << dog->getType() << "| ";
	dog->makeSound();
	delete cat;
	delete dog;

	return (0);
}