#ifndef EX01_CLAPTRAP_H
#define EX01_CLAPTRAP_H

#include <string>
#include <iostream>

/*
 * Note that the default constructor is set as private, so that it cannot be
 * used. Another way, available in C++11) would be:
 * 		ClapTrap() = delete;
 */

class ClapTrap {
public:
	ClapTrap(const ClapTrap &src);    			// Copy constructor
	explicit ClapTrap(const std::string& name);
	virtual ~ClapTrap();                		// Default destructor

	ClapTrap& operator=(const ClapTrap &rh_instance);    // Assign operator overload

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	ClapTrap&	setName(const std::string& new_name);
	ClapTrap&	setHitPoints(const int& value);
	ClapTrap&	setEnergyPoints(const int& value);
	ClapTrap&	setAttackDamage(const int& value);

private:
	ClapTrap();                       			// Default constructor

	std::string	name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;
};

#endif //EX01_CLAPTRAP_H
