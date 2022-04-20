#include "Ice.h"
#include "Cure.h"
#include "Character.h"
#include "AMateria.h"
#include "MateriaSource.h"

int	main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "========================================\n";
	std::cout << "TESTING THE DEEP COPY\n";
	std::cout << "========================================\n";
	Ice* ice = new Ice();
	Character* person1 = new Character("person1");
	person1->equip(ice);
	std::cout << "Item #0 from person1 is: " << (person1->getItem(0) ? person1->getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "----------------------------------------\n";
	Character* person2 = new Character(*person1);
	std::cout << "Item #0 from person2 is: " << (person2->getItem(0) ? person2->getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "----------------------------------------\n";
	Character person3(*person1);
	std::cout << "Item #0 from person3 is: " << (person3.getItem(0) ? person3.getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "----------------------------------------\n";
	person1->unequip(0);
	std::cout << "Item #0 from person1 is: " << (person1->getItem(0) ? person1->getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "Item #0 from person2 is: " << (person2->getItem(0) ? person2->getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "Item #0 from person3 is: " << (person3.getItem(0) ? person3.getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "----------------------------------------\n";
	delete person1;
	std::cout << "Item #0 from person2 is: " << (person2->getItem(0) ? person2->getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "Item #0 from person3 is: " << (person3.getItem(0) ? person3.getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "----------------------------------------\n";
	delete person2;
	std::cout << "Item #0 from person3 is: " << (person3.getItem(0) ? person3.getItem(0)->getType() : "EMPTY") << std::endl;
	std::cout << "----------------------------------------\n";
	delete ice; //this is necessary because I called unequip()

	return (0);
}