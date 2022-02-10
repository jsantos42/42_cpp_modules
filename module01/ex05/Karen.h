#ifndef EX05_KAREN_H
#define EX05_KAREN_H

#include <string>

class Karen {
public:
	void	complain( std::string level );

private:
	void	debug();
	void	info();
	void	warning();
	void	error();
};

#endif //EX05_KAREN_H
