#ifndef EX01_SPAN_H
#define EX01_SPAN_H

#include <vector>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator 	iterator;
	MutantStack<T>();
	MutantStack<T>(const MutantStack &src);
	virtual ~MutantStack<T>();

	MutantStack&	operator=(const MutantStack &rh_instance);
	iterator	a();
	iterator	end();


};

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
template<typename T>
MutantStack<T>::MutantStack() {
	std::cout << "[MutantStack] Default constructor.\n";
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src) {
	*this = src;
	std::cout << "[MutantStack] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

template<typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "[MutantStack] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack &rh_instance) {
	if (this != &rh_instance) {
		this->v = rh_instance.v;
		this->max_size = rh_instance.max_size;
	}
	return (*this);
}

//==============================================================================
// ITERATORS
//==============================================================================
template<typename T>
typename MutantStack<T>::iterator 	MutantStack<T>::end() {
	
};


#endif //EX01_SPAN_H