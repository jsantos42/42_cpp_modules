#ifndef EX05_KAREN_H
#define EX05_KAREN_H

#include <string>
#define NB_LEVELS	4

class Karen {
public:
	Karen();
	~Karen();
	typedef	void (Karen::*funcPtr)();
	void		complain(const std::string& level );

private:
	void	debug();
	void	info();
	void	warning();
	void	error();
	funcPtr		ptrArray[NB_LEVELS];
	std::string	levels[NB_LEVELS];
};

#endif //EX05_KAREN_H
