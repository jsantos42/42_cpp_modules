#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
//#include <iomanip>
#include "utils.h"

int main(int ac, char **av) {
	std::string	line;
	std::ifstream	in_file;
	std::ofstream	out_file;

	if (ac != 4) {
		_output("ERROR: Wrong number of arguments.", true);
		return (1); }
	in_file.open(av[1], std::ifstream::in);
	if (in_file.fail()) {
		_output("ERROR: No such file.", true);
		return (1); }
	out_file.open(strcat(av[1], ".replace"), std::ios::out);
	std::getline(in_file, line);
	while (!line.empty()) {
//		line.find
		out_file << line << std::endl;
		std::getline(in_file, line); }
	in_file.close();
	out_file.close();
	///missing: replacing strings and tests
	return 0;
}
