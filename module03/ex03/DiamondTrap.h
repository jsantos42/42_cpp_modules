#ifndef EX03_DIAMONDTRAP_H
#define EX03_DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	explicit DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap &src);    // Copy constructor
	virtual ~DiamondTrap();                 // Default destructor

	DiamondTrap &operator=(const DiamondTrap &rh_instance);    // Assign operator overload
	void		attack(const std::string &target);
	void		whoAmI();

protected:
	DiamondTrap();							// Default constructor

private:
	std::string	name;
};


#endif //EX03_DIAMONDTRAP_H
