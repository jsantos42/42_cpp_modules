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
 * Thanks to the deep copy done with the copy constructor, this getIdea() works
 * and does not segfault.
 */
	std::cout << "========================================\n";
	std::cout << "TESTING THE DEEP COPY\n";
	std::cout << "========================================\n";
	Dog* dog1 = new Dog;
	dog1->setIdea(3, "ola");
	std::cout << "Idea #00 from dog1 is: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea #03 from dog1 is: " << dog1->getBrain()->getIdea(3) << std::endl;
	std::cout << "Idea #99 from dog1 is: " << dog1->getBrain()->getIdea(99) << std::endl;
	std::cout << "----------------------------------------\n";
	Dog* dog2 = new Dog(*dog1);
	std::cout << "Idea #00 from dog2 is: " << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea #03 from dog2 is: " << dog2->getBrain()->getIdea(3) << std::endl;
	std::cout << "Idea #99 from dog2 is: " << dog2->getBrain()->getIdea(99) << std::endl;
	std::cout << "----------------------------------------\n";
	Dog dog3(*dog1);
	std::cout << "Idea #00 from dog3 is: " << dog3.getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea #03 from dog3 is: " << dog3.getBrain()->getIdea(3) << std::endl;
	std::cout << "Idea #99 from dog3 is: " << dog3.getBrain()->getIdea(99) << std::endl;
	std::cout << "----------------------------------------\n";
	delete dog1;
	std::cout << "Idea #00 from dog2 is: " << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea #03 from dog2 is: " << dog2->getBrain()->getIdea(3) << std::endl;
	std::cout << "Idea #99 from dog2 is: " << dog2->getBrain()->getIdea(99) << std::endl;
	std::cout << "Idea is: " << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << "----------------------------------------\n";
	std::cout << "Idea #00 from dog3 is: " << dog3.getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea #03 from dog3 is: " << dog3.getBrain()->getIdea(3) << std::endl;
	std::cout << "Idea #99 from dog3 is: " << dog3.getBrain()->getIdea(99) << std::endl;

	std::cout << "========================================\n";
	std::cout << "TESTING THE ASSIGNMENT OP OVERLOAD\n";
	std::cout << "========================================\n";
	Dog* dog4 = new Dog;
	Dog* temp = dog4;
	dog4 = dog2;
	delete dog2;
	dog4 = temp;
	std::cout << dog4->getBrain()->getIdea(0);
	dog4->makeSound();
	delete dog4;

	std::cout << "========================================\n";
	std::cout << "TESTING THE ASSIGNMENT OP OVERLOAD (from dcavalei)\n";
	std::cout << "========================================\n";
	Animal*	cat = new Cat;
	Animal*	dog = new Dog;
	/* It uses the animal assignment operator, since they are both Animal ptrs.
	So it will copy only the _type */
	*cat = *dog;
	std::cout << '|' << cat->getType() << "| ";
	cat->makeSound();
	std::cout << '|' << dog->getType() << "| ";
	dog->makeSound();
	delete cat;
	delete dog;

	return (0);
}