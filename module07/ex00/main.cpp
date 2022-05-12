#include <iostream>
#include "whatever.h"

int	main() {
	std::cout << "============================================================\n";
	std::cout << "FROM THE SUBJECT (adapted)\n";
	std::cout << "============================================================\n";
	int			a = 2;
	int 		b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::string	c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;

	float	e = 2.01f;
	float	f = 3.01f;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	std::cout << std::endl;

	std::cout << "============================================================\n";
	std::cout << "FROM THE CORRECTION SHEET\n";
	std::cout << "============================================================\n";

	Awesome	g(2), h(4);
	std::cout << g << " " << h << std::endl;
	swap(g, h);
	swap<Awesome>(g, h);
	swap<Awesome>(g, h);
	std::cout << g << " " << h << std::endl;
	std::cout << max(g, h) << std::endl;
	std::cout << min(g, h) << std::endl;

	return 0;
}
