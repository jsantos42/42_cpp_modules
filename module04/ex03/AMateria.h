#ifndef EX03_AMATERIA_H
#define EX03_AMATERIA_H

#include <string>
#include <iostream>
#include "ICharacter.h"

class AMateria {
public:
	explicit AMateria(const std::string& type);
	AMateria(const AMateria& src);
	virtual ~AMateria();

	AMateria&			operator=(const AMateria &rh_instance);
	const std::string&	getType() const;
	AMateria&			setType(const std::string& new_type);
	virtual void		use(ICharacter& target);
	virtual AMateria*	clone() const = 0;

protected:
	AMateria();
	std::string	type;
};

#endif //EX03_AMATERIA_H
