#include <iostream>
#include <list>
#include "MutantStack.h"


int	main() {
	std::cout << "============================================================\n";
	std::cout << "FROM THE SUBJECT\n";
	std::cout << "============================================================\n";
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl; //17
	mstack.pop(); // 17 pops, only 5 now
	std::cout << mstack.size() << std::endl; //1
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);

	MutantStack<int>::iterator	it = mstack.b();
	MutantStack<int>::iterator	ite = mstack.e();
	++it;
	--it;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it; }

	std::stack<int> s(mstack);

	std::cout << "============================================================\n";
	std::cout << "MINE\n";
	std::cout << "============================================================\n";
	std::list<int>	l;

	l.push_back(5);
	l.push_back(17);
	std::cout << l.back() << std::endl; //17
	l.pop_back(); // 17 pops, only 5 now
	std::cout << l.size() << std::endl; //1
	l.push_back(3);
	l.push_back(5);
	l.push_back(737); //[...] l.push(0);

	std::list<int>::iterator	i = l.begin();
	std::list<int>::iterator	ie = l.end();
	while (i != ie) {
		std::cout << *i << std::endl;
		++i;
	}
	return 0;
}
