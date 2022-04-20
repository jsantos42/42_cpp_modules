#ifndef EX01_SCAVTRAP_H
#define EX01_SCAVTRAP_H

#include "ClapTrap.h"

/*
 * Note that this inheritance must be virtual to avoid the diamond trap.
 */
class ScavTrap : virtual public ClapTrap {
public:
	explicit ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap &src);    			// Copy constructor
	~ScavTrap();                				// Default destructor

	ScavTrap&	operator=(const ScavTrap& rh_instance);    // Assign operator overload
	void		guardGate();
	void		attack(const std::string& target);

protected:
	ScavTrap();                       			// Default constructor
};

#endif //EX01_SCAVTRAP_H
