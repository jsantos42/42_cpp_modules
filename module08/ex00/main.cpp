#include <list>
#include <vector>
#include <deque>
#include <iostream>
#include "easyfind.h"

int i = 0;

int	fillContainer() {
	return (i++);
}

int	main() {
	std::list<int>		l(3);
	std::vector<int>	v(3);
	std::deque<int>		d(3);

	std::generate(l.begin(), l.end(), fillContainer);
	std::generate(v.begin(), v.end(), fillContainer);
	std::generate(d.begin(), d.end(), fillContainer);

	std::cout << "======== List: ========\n";
	for (int j = 0; j < 10; j++)
		printSearchResults(l, j);
	std::cout << "======== Vector: ========\n";
	for (int j = 0; j < 10; j++)
		printSearchResults(v, j);
	std::cout << "======== Double ended queue: ========\n";
	for (int j = 0; j < 10; j++)
		printSearchResults(d, j);
	return 0;
}
