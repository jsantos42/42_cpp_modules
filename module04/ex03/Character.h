#ifndef EX03_CHARACTER_H
#define EX03_CHARACTER_H

#include "ICharacter.h"

class Character : public ICharacter {
public:
	explicit Character(const std::string& name);
	Character(const Character &src);
	virtual ~Character();

	Character&					operator=(const Character &rh_instance);
	virtual const std::string&	getName() const;
	virtual void				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);
	AMateria*					getItem(int index);

protected:
	Character();

private:
	AMateria*	inventory[4];
	std::string	name;
};


#endif //EX03_CHARACTER_H
