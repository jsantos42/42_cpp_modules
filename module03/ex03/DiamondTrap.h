#ifndef EX03_DIAMONDTRAP_H
#define EX03_DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public ScavTrap, FragTrap {
public:
	DiamondTrap();							// Default constructor
	DiamondTrap(const DiamondTrap &src);    // Copy constructor
	explicit DiamondTrap(const std::string& name);
	virtual ~DiamondTrap();                 // Default destructor

	DiamondTrap &operator=(const DiamondTrap &rh_instance);    // Assign operator overload
	void		whoAmI();
};


#endif //EX03_DIAMONDTRAP_H
