#ifndef EX00_BRAIN_H
#define EX00_BRAIN_H

#include <string>
#include <iostream>

class Brain {
public:
	Brain();
	Brain(const Brain &src);
	virtual ~Brain();

	Brain&		operator=(const Brain &rh_instance);
	std::string	getIdea(int i);

private:
	std::string	ideas[100];
};


#endif //EX00_BRAIN_H
