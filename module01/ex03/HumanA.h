#ifndef EX03_HUMANA_H
#define EX03_HUMANA_H

#include <string>
#include "Weapon.h"

class HumanA {
public:
	HumanA(const std::string& name, Weapon& weapon);

	const std::string&	getName() const;
	void				setName(const std::string& newName);
	void				attack();

private:
	std::string	name;
	Weapon&		_weapon;
};


#endif //EX03_HUMANA_H
