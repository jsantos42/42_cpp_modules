#ifndef EX01_MAIN_H
#define EX01_MAIN_H

#include <stdint.h>
#include <string>
#include <iostream>

typedef struct s_struc {
	std::string	name;
	int			age;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif //EX01_MAIN_H
