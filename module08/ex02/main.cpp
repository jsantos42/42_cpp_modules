#include <iostream>
#include <cstdlib>
#include "MutantStack.h"


int	main() {
	std::cout << "============================================================\n";
	std::cout << "FROM THE SUBJECT\n";
	std::cout << "============================================================\n";
	MutantStack<int>	mstack;

	mstack.push(5); mstack.push(17);
	std::cout << mstack.top() << std::endl; mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);

	MutantStack<int>::iterator	it = mstack.a();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it; }
	std::stack<int> s(mstack); return 0;
//	std::cout << *mstack.a;





	std::cout << "============================================================\n";
	std::cout << "MINE\n";
	std::cout << "============================================================\n";
	return 0;
}
