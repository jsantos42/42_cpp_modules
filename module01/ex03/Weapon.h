#ifndef EX03_WEAPON_H
#define EX03_WEAPON_H

#include <string>

class Weapon {
public:
	Weapon(const std::string& type);
	Weapon(const Weapon &src);    // Copy constructor
	virtual ~Weapon();                // Default destructor

	Weapon&				operator=(const Weapon &rh_instance);    // Assign operator overload
	const std::string&	getType() const;
	void				setType(const std::string& newType);

private:
	std::string	type;
};

#endif //EX03_WEAPON_H