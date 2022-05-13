#include <list>
#include "easyfind.h"

int	main() {
	std::list<int> l(3);

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	easyfind(l, 1);
	return 0;
}
