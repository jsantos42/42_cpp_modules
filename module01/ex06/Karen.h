#ifndef EX05_KAREN_H
#define EX05_KAREN_H

#include <string>
#define NB_LEVELS	4

class Karen {
public:
	Karen();
	typedef	void (Karen::*funcPtr)();
	void		complain(const std::string& level );
	void		filter(const std::string& level );
	std::string	getLevel(int i) const;

private:
	void	debug();
	void	info();
	void	warning();
	void	error();
	funcPtr		ptrArray[NB_LEVELS];
	std::string	levels[NB_LEVELS];
};

#endif //EX05_KAREN_H
