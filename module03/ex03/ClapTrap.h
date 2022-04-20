#ifndef EX01_CLAPTRAP_H
#define EX01_CLAPTRAP_H

#include <string>
#include <iostream>

/*
 * Note that the default constructor is set as protected, so that it cannot be
 * used except by its children.
 */
class ClapTrap {
public:
	ClapTrap(const ClapTrap &src);    			// Copy constructor
	explicit ClapTrap(const std::string& name);
	virtual ~ClapTrap();                		// Default destructor

	ClapTrap& operator=(const ClapTrap &rh_instance);    // Assign operator overload

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	ClapTrap&		setName(const std::string& new_name);
	ClapTrap&		setHitPoints(const int& value);
	ClapTrap&		setEnergyPoints(const int& value);
	ClapTrap&		setAttackDamage(const int& value);
	std::string		getName() const;
	int				getHitPoints() const;
	int				getEnergyPoints() const;
	int				getAttackDamage() const;

protected:
	ClapTrap();                       			// Default constructor

	std::string	name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;
};

#endif //EX01_CLAPTRAP_H
