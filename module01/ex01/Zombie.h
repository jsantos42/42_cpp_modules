#ifndef EX00_ZOMBIE_H
#define EX00_ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
public:
	Zombie();                     			// Default constructor
	Zombie(const std::string& new_name);
	Zombie(const Zombie &src);    			// Copy constructor
	virtual ~Zombie();            			// Default destructor

	Zombie&	operator=(const Zombie &rh_instance);    // Assign operator overload
	void	announce();
	void	setName(std::string new_name);

private:
	std::string	name;
};


#endif //EX00_ZOMBIE_H
