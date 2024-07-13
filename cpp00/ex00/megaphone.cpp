#include <iostream>

int	main(int ac, char **av){
	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < ac; i++){
			//if (i > 1)
			//	std::cout << " ";
			char *arg = av[i];
			for (int j = 0; arg[j]; j++){
				std::cout << (char) toupper(arg[j]);
			}
		}
		std::cout << std::endl;
	}
}