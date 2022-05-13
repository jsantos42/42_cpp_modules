#ifndef EX02_ARRAY_H
#define EX02_ARRAY_H

#include <sstream>
#include <iostream>
#include <cstring>

//==============================================================================
//	TEMPLATE DECLARATION
//==============================================================================
template<typename T>
class Array {
public:
	Array<T>();
	explicit Array<T>(unsigned int n);
	Array<T>(const Array<T> &src);
	virtual ~Array<T>();

	Array<T>&	operator=(const Array<T>& rh_instance);
	T&			operator[](std::size_t	index);
	int			size() const;
private:
	T*				array;
	unsigned int	len;

};

//==============================================================================
//	TEMPLATE DEFINITION: CONSTRUCTORS
//==============================================================================
/* Note that here it's crucial to initialize array to 0, otherwise when the
 * destructor calls the 'delete[]' to array, it will throw an error. */
template<typename T>
Array<T>::Array() : array(0), len(0) {}

/* Note that here we need to calculate the size of T to know how many bites we
 * want to set to 0. */
template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), len(n) {
	std::memset(array, 0, sizeof(T) * n);
}

/* Note that here we need to initialize array and len, just in case the new
 * Array that is being constructor was non-existent. If it already existed and
 * is going to store a new Array src, then array and len already exist and are
 * not reinitialized. */
template<typename T>
Array<T>::Array(const Array<T> &src) : array(0), len(0) {
	*this = src;
}

//==============================================================================
//	TEMPLATE DEFINITION: DESTRUCTORS
//==============================================================================

template<typename T>
Array<T>::~Array() {
	delete[] array;
};

//==============================================================================
//	TEMPLATE DEFINITION: OPERATOR OVERLOADS
//==============================================================================

template<typename T>
Array<T>&	Array<T>::operator=(const Array<T>& rh_instance) {
	if (this != &rh_instance) {
		delete[] array;
		array = 0;
		len = rh_instance.len;
		if (len) {
			array = new T[len];
			for (unsigned int i = 0; i < len; i++)
				array[i] = rh_instance.array[i];
		}
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](std::size_t index) {
	if (index < len)
		return array[index];
	else {
		std::stringstream str;
		str << "Index " << index << " is out of bounds!\n";
		throw std::out_of_range(std::string(str.str()));
	}
}

//==============================================================================
//	TEMPLATE DEFINITION: METHODS
//==============================================================================

template<typename T>
int	Array<T>::size() const {
	return len;
}

#endif //EX02_ARRAY_H
