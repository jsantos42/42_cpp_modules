#include <iostream>
#include <cctype>

int	main(int argc, char**argv) {
    std::string	buff;
	int			i;
	int			j;

	if (argc == 1)
		std::cout << "* loud and unbearable feedback noise *" << std::endl;
	else {
		i = 0;
        while (++i < argc){
			buff = argv[i];
			j = -1;
			while (++j < buff.length())
				std::cout << (char)std::toupper(buff[j]);
		}
		std::cout << std::endl;
    }
    return (0);
}
