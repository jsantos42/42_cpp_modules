#include <iostream>
#include <cstdlib>
#include "Span.h"

#define CASES 10000

int	main() {
	std::cout << "============================================================\n";
	std::cout << "FROM THE SUBJECT\n";
	std::cout << "============================================================\n";
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "============================================================\n";
	std::cout << "MINE\n";
	std::cout << "============================================================\n";
	std::vector<int>	testing;
	Span				mine(CASES);

	srand(time(0));
	for (int i = 0; i < CASES; i++)
		testing.push_back(rand() % CASES);
	mine.addMultipleNumbers< std::vector<int> >(testing.begin(), testing.end());
	std::cout << mine.shortestSpan() << std::endl;
	std::cout << mine.longestSpan() << std::endl;
	try {
		mine.addNumber(3);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
