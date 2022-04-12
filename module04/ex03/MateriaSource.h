#ifndef EX03_MATERIASOURCE_H
#define EX03_MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	virtual ~MateriaSource();

	MateriaSource &operator=(const MateriaSource &rh_instance);
	virtual void		learnMateria(AMateria* materia);
	virtual AMateria*	createMateria(const std::string& type);

private:
	AMateria*	slots[4];
};


#endif //EX03_MATERIASOURCE_H
