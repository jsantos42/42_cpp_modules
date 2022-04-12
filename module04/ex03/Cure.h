#ifndef EX03_CURE_H
#define EX03_CURE_H

#include "AMateria.h"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &src);
	virtual ~Cure();

	Cure&				operator=(const Cure &rh_instance);
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

#endif //EX03_CURE_H
