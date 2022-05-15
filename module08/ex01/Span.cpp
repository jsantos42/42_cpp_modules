#include "Span.h"
#include <iostream>
#include <algorithm>
#include <climits>

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Span::Span() : v(0), max_size(0) {
	std::cout << "[Span] Default constructor.\n";
}

/* We cannot initialize vector here as 'v(std::vector<int> (N))' since it would
 * create a vector with 5 filled slots.*/
Span::Span(unsigned int N) : max_size(N) {
	std::cout << "[Span] Unsigned int constructor.\n";
}

Span::Span(const Span &src) {
	*this = src;
	std::cout << "[Span] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Span::~Span() {
	std::cout << "[Span] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Span&	Span::operator=(const Span &rh_instance) {
	if (this != &rh_instance) {
		this->v = rh_instance.v;
		this->max_size = rh_instance.max_size;
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Span CLASS.
//==============================================================================
const std::vector<int> &Span::getVector() const {
	return (v);
}

unsigned int Span::getMaxSize() const {
	return (max_size);
}

/*	This method of adding numbers ensures the vector will always be sorted by
 * an increasing order. If the vector is not already full, finds the first
 * number that is bigger than the one we want to add. Then insert the new number
 * on that position. */
void	Span::addNumber(int n) {
	if (v.size() + 1 > max_size)
		throw std::length_error("Vector is already full.");
	std::vector<int>::iterator	n_pos = std::upper_bound(v.begin(), v.end(), n);
	if (n_pos != v.end())
		v.insert(n_pos, n);
	else
		v.push_back(n);
}

unsigned int Span::shortestSpan() {
	std::vector<int>::iterator	i = v.begin();
	std::vector<int>::iterator	ie = v.end();
	double						temp;
	double						diff = UINT_MAX;

	if (v.size() < 2)
		throw std::range_error("Need more than 2 elements to calculate span.");
	while (i < ie - 1) {
		temp = *(i + 1) - *i;
		if (diff > temp)
			diff = temp;
		i++;
	}
	return (static_cast<unsigned int>(diff));
}

unsigned int Span::longestSpan() {
	std::vector<int>::iterator	i = v.begin();
	std::vector<int>::iterator	ie = v.end();

	if (v.size() < 2)
		throw std::range_error("Need more than 2 elements to calculate span.");
	return (*(ie - 1) - *i);
}
