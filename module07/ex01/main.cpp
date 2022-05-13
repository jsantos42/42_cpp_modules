#include "iter.h"

//==============================================================================
// FROM THE CORRECTION SHEET
//==============================================================================
class Awesome {
public:
	Awesome( void ): _n(42) { return; }
	int	get( void ) const { return this->_n; }

private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template <typename T>
void	print( const T& x ) { std::cout << x << std::endl; return; }



//==============================================================================
// MAIN
//==============================================================================

int	main() {
	char	c[] = "ola";
	int		i[] = {1, 2, 3};
	float	f[] = {1.1, 2.2, 3.3};

	iter(c, 3, output<char>);
	iter(i, 3, output<int>);
	iter(f, 3, output<float>);

	std::cout << "============================================================\n";
	std::cout << "FROM THE CORRECTION SHEET\n";
	std::cout << "============================================================\n";

	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print<int> );
	iter( tab2, 5, print<Awesome> );

	return 0;
}
