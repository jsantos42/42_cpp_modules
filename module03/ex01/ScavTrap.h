#ifndef EX01_SCAVTRAP_H
#define EX01_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();                       			// Default constructor
	ScavTrap(const ScavTrap &src);    			// Copy constructor
	explicit ScavTrap(const std::string& name);
	~ScavTrap();                				// Default destructor

	ScavTrap&	operator=(const ScavTrap& rh_instance);    // Assign operator overload
	void		guardGate();
	void		attack(const std::string& target);
};

#endif //EX01_SCAVTRAP_H
