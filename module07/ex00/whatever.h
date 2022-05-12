#ifndef EX00_WHATEVER_H
#define EX00_WHATEVER_H

class Awesome {
	public:
		Awesome( int n ) : _n(n) {}

		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator> ( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator< ( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }

		int get_n() const { return _n; }
	private:
		int _n;
};


std::ostream & operator<<(std::ostream & o, const Awesome &a) {
	o << a.get_n();
	return o; 
}

/* Notice that here tmp must be initialized when declared, otherwise it might
 throw an error if typename A is a class with a private default constructor. */
template<typename A>
void	swap(A& a1, A& a2) {
	A	tmp = a1;

	a1 = a2;
	a2 = tmp;
}

template<typename B>
const B&	min(const B& b1, const B& b2) {
	return (b1 < b2 ? b1 : b2);
}

template<typename C>
const C&	max(const C& c1, const C& c2) {
	return (c1 > c2 ? c1 : c2);
}

#endif //EX00_WHATEVER_H
