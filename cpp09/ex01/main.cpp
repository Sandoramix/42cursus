#include "RPN.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cerr << "Usage: " << av[0] << " '<reverse polish notation expression>'" << std::endl;
		return 1;
	}
	try {
		float result = RPN::parseExpr(av[1]);
		std::cout << "Result: " << result << std::endl;
	} catch (std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}