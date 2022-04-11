#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int	main() {
	const Animal*	animal = new Animal();
	const Animal*	cat = new Cat();
	const Animal*	dog = new Dog();
	WrongAnimal*	w = new WrongCat();

	std::cout << "type: " << animal->getType() << " ";
	animal->makeSound();
	std::cout << "type: " << cat->getType() << " ";
	cat->makeSound();
	std::cout << "type: " << dog->getType() << " ";
	dog->makeSound();
	std::cout << "type: " << w->getType() << " ";
	w->makeSound();

	delete animal;
	delete cat;
	delete dog;
	delete w;
	return (0);
}