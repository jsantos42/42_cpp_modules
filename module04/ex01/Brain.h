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
	std::string	getIdea(int index) const;
	Brain&		setIdea(int index, const std::string& new_idea);

private:
	std::string	ideas[100];
};


#endif //EX00_BRAIN_H
