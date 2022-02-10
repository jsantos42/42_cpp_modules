#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "utils.h"

std::string	replaceStr(const std::string& line, size_t& beg, const std::string& _from, const std::string& _to) {
	std::string	new_str;

	new_str = line.substr(0, beg);
	new_str += _to;
	new_str += line.substr(beg + _from.length(), line.npos);
	beg += _to.length();
	return (new_str);
}

void	parseFile(std::ifstream& in_file, std::ofstream& out_file, const std::string& _from, const std::string& _to) {
	size_t		i;
	std::string	line;

	std::getline(in_file, line);
	while (!line.empty()) {
		i = 0;
		i = line.find(_from, i);
		while (i != line.length() && i != line.npos) {
			line = replaceStr(line, i, _from, _to);
			i = line.find(_from, i);
		}
		out_file << line << std::endl;
		std::getline(in_file, line);
	}
}

/*
 *	Note that weh doing the strcat on the out_file name, av[1] gets changed, and
 *	so does the remaining arguments, since they are contiguously allocated.
 */

int main(int ac, char **av) {
	std::string		_from;
	std::string		_to;
	std::ifstream	in_file;
	std::ofstream	out_file;

	if (ac != 4) {
		_output("ERROR: Wrong number of arguments.", true);
		return (1); }
	_from = std::string(av[2]);
	_to = std::string(av[3]);
	in_file.open(av[1], std::ifstream::in);
	if (in_file.fail()) {
		_output("ERROR: No such file.", true);
		return (1); }
	out_file.open(strcat(av[1], ".replace"), std::ios::out);
	parseFile(in_file, out_file, _from, _to);
	in_file.close();
	out_file.close();
	std::cout << "SUCCESS: Please check the output in '" << av[1] << "'." << std::endl;
	return 0;
}
