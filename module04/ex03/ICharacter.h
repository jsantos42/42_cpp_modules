#ifndef EX03_ICHARACTER_H
#define EX03_ICHARACTER_H

//#include "AMateria.h"
#include <string>

/*
 * If this file included AMateria.h, we would have a circular dependency (this
 * file is also included by AMateria.h). This would a problem because since both
 * mention each other, the first one to be read by the compiler would be this
 * (because main.cpp includes first Ice.h, which includes AMateria.h, which
 * includes ICharacter.h) and when getting to the function equip() it would not
 * know what is the type AMateria). Hence, there has to be this forward
 * declaration of AMateria.
 * Plus, since all we're using in equip() is a pointer to AMateria, the compiler
 * does not need to know where it is defined to calculate its size or
 * dereference it, it only needs to know it exists. Hence, we can remove the
 * 'include' on line 4.
 */
class AMateria;

class ICharacter {
public:
	virtual ~ICharacter() {};
	virtual const std::string&	getName() const = 0;
	virtual void				equip(AMateria* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter& target) = 0;
};

#endif //EX03_ICHARACTER_H
