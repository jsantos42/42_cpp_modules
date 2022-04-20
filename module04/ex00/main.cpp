#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int	main() {
	const Animal*	animal = new Animal();
	const Animal*	cat = new Cat();
	const Animal*	dog = new Dog();
	WrongAnimal*	w_animal = new WrongCat();
	WrongCat*		w_cat = new WrongCat();

	std::cout << "============================================\n";
	std::cout << "type: " << animal->getType() << " ";
	animal->makeSound();
	std::cout << "============================================\n";
	std::cout << "type: " << cat->getType() << " ";
	cat->makeSound();
	std::cout << "============================================\n";
	std::cout << "type: " << dog->getType() << " ";
	dog->makeSound();
	std::cout << "============================================\n";
	std::cout << "type: " << w_animal->getType() << " ";
	w_animal->makeSound();
	std::cout << "============================================\n";
	std::cout << "type: " << w_cat->getType() << " ";
	w_cat->makeSound();
	std::cout << "============================================\n";

	delete animal;
	delete cat;
	delete dog;
	delete w_animal;
	delete w_cat;
	return (0);
}