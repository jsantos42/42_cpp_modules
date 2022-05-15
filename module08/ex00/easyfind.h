#ifndef EX00_EASYFIND_H
#define EX00_EASYFIND_H

#include <algorithm>
#include <sstream>

/* Note that 'T::const_iterator' is a non-defined type, which is dependent on T;
 hence, everytime we use it, we need to declare 'typename' prior to it. */
template<typename T>
typename T::const_iterator	easyfind(const T& int_container, int to_be_found) {
	typename T::const_iterator	i;
	typename T::const_iterator	ie;

	i = int_container.begin();
	ie = int_container.end();

	return (std::find(i, ie, to_be_found));
}

/* An iterator can be dereferenced. */
template<typename T>
void	printSearchResults(const T& int_container, int to_search) {
	typename T::const_iterator	i;
	std::string					str;
	std::stringstream 			stream;

	i = easyfind(int_container, to_search);
	if (i != int_container.end()) {
		stream << std::string(" is on index ") << *i;
		str = stream.str();
	}
	else
		str = " is NA";
	std::cout << "The number " << to_search << str << ".\n";
}

#endif //EX00_EASYFIND_H