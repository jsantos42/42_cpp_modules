#ifndef EX02_FRAGTRAP_H
#define EX02_FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
public:
	FragTrap();							// Default constructor
	FragTrap(const FragTrap &src);		// Copy constructor
	explicit FragTrap(const std::string& name);
	virtual ~FragTrap();                // Default destructor

	FragTrap&	operator=(const FragTrap &rh_instance);    // Assign operator overload

	void		highFivesGuys();
};

#endif //EX02_FRAGTRAP_H