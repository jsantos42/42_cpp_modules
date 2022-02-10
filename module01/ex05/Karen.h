#ifndef EX05_KAREN_H
#define EX05_KAREN_H

#include <string>
#define NB_LEVELS	4

class Karen {
public:
	Karen();
	~Karen();
	typedef	void (Karen::*funcPtr)();
	void	complain(const std::string& level );
	funcPtr	ptrArray[NB_LEVELS];

private:
	void	debug();
	void	info();
	void	warning();
	void	error();
};

#endif //EX05_KAREN_H
