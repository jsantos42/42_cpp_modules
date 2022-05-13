#ifndef EX01_ITER_H
#define EX01_ITER_H

//#include <cstdlib>
#include <iostream>


template<typename T, typename F>
void	iter(T* array, size_t len, F fun) {
	for (size_t i = 0; i < len; i++)
		fun(array[i]);
}

template<typename T>
void	output(const T& element) {
	std::cout << element << std::endl;
}


#endif