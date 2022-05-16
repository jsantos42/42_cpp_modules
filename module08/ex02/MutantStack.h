#ifndef EX01_SPAN_H
#define EX01_SPAN_H

#include <vector>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator 	iterator;
	MutantStack<T>();
	MutantStack<T>(const MutantStack<T> &src);
	virtual ~MutantStack<T>();

	MutantStack<T>&	operator=(const MutantStack<T> &rh_instance);
	iterator	b();
	iterator	e();


};

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
template<typename T>
MutantStack<T>::MutantStack() {
	std::cout << "[MutantStack] Default constructor.\n";
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) {
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
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T> &rh_instance) {
	if (this != &rh_instance)
		this->c = rh_instance.c;
	return (*this);
}

//==============================================================================
// ITERATORS
//==============================================================================
/*
 * Note that c is the container_type.
 */
template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::b() {
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator 	MutantStack<T>::e() {
	return (this->c.end());
};

#endif //EX01_SPAN_H