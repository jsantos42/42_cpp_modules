#include "Array.h"

int	main() {
	Array<int>	i0;
	Array<int>	i3(3);
	Array<int>	j;

	j = i0;
	try {
		std::cout << "Accessing index 10 of j.\n";
		std::cout << j[10];
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "====== size ========\n";
	std::cout << i0.size() << std::endl;
	std::cout << i3.size() << std::endl;
	std::cout << "====== initial values ========\n";
	std::cout << i3[0] << std::endl;
	std::cout << i3[1] << std::endl;
	std::cout << i3[2] << std::endl;
	i3[0] = 'o';
	i3[1] = 'l';
	i3[2] = 'a';
	std::cout << "====== new values ========\n";
	std::cout << i3[0] << std::endl;
	std::cout << i3[1] << std::endl;
	std::cout << i3[2] << std::endl;

	std::cout << "====== copy constructor ========\n";
	Array<int>	g(3);
	g[0] = 'u';
	g[1] = 'u';
	g[2] = 'u';
	g = i3;
	std::cout << g[0] << std::endl;
	std::cout << g[1] << std::endl;
	std::cout << g[2] << std::endl;
	return 0;
}
