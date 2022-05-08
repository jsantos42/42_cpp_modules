#include "main.h"

uintptr_t serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

int main() {
	Data		d = {"Drop", 30};
	uintptr_t	raw;
	Data*		ptr;

	std::cout << d.name << std::endl;
	std::cout << d.age << std::endl;

	raw = serialize(&d);
	d.age++;
//	This would not be possible to uncomment, since raw is not a Data struct:
//	std::cout << raw->name << std::endl;
//	std::cout << raw->age << std::endl;
	ptr = deserialize(raw);

	std::cout << ptr->name << std::endl;
	std::cout << ptr->age << std::endl;

	return (0);
}