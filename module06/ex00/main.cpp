#include "Conversions.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Wrong input. The program needs 1 (and only 1) argument.\n";
		return (1);
	}
	Conversions arg(argv[1]);
	std::cout << arg;
	return (0);
}