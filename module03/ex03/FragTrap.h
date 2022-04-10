#ifndef EX02_FRAGTRAP_H
#define EX02_FRAGTRAP_H

#include "ClapTrap.h"

/*
 * Note that this inheritance must be virtual to avoid the diamond trap.
 */
class FragTrap : virtual public ClapTrap {
public:
	explicit FragTrap(const std::string& name);
	FragTrap(const FragTrap &src);		// Copy constructor
	virtual ~FragTrap();                // Default destructor

	FragTrap&	operator=(const FragTrap &rh_instance);    // Assign operator overload

	void		highFivesGuys();

protected:
	FragTrap();							// Default constructor
};

#endif //EX02_FRAGTRAP_H