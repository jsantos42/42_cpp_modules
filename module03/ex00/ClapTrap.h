#ifndef EX01_CLAPTRAP_H
#define EX01_CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {
public:
	ClapTrap();                        // Default constructor
	ClapTrap(const ClapTrap &src);    // Copy constructor
	explicit ClapTrap(const std::string& name);
	virtual ~ClapTrap();                // Default destructor

	ClapTrap &operator=(const ClapTrap &rh_instance);    // Assign operator overload

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string	name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;
};


#endif //EX01_CLAPTRAP_H
