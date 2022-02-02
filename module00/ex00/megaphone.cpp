#include <iostream>
#include <cctype>
//#include <string>

int	main(int argc, char**argv) {
    std::string	buff;
	int			i;
	size_t		j;

	if (argc == 1)
		std::cout << "* loud and unbearable feedback noise *" << std::endl;
	else {
		i = 0;
        while (++i < argc){
			buff = argv[i];
			j = 0;
			while (j < buff.length())
				std::cout << (char)std::toupper(buff[j++]);
		}
		std::cout << std::endl;
    }
    return (0);
}
