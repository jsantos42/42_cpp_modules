#ifndef EX00_EASYFIND_H
#define EX00_EASYFIND_H

template<typename T>
unsigned int	easyfind(const T& container, int to_find) {
	unsigned int	i;
	unsigned int	ie;

	i = container.begin();
	ie = container.end();

	if (i != ie)
	{return (to_find);}
	return i;

}

#endif //INC_42_CPP_MODULES_EASYFIND_H