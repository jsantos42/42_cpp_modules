#ifndef EX03_HUMANB_H
#define EX03_HUMANB_H

#include <string>
#include "Weapon.h"

class HumanB {
public:
	HumanB(const std::string& name);

	const std::string&	getName() const;
	void				setName(const std::string& new_name);
	void				setWeapon(Weapon& new_weapon);
	void				attack();

private:
	std::string	name;
	Weapon*		_weapon;
};

#endif //EX03_HUMANB_H
