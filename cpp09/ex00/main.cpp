#include "BitcoinExchange.hpp"
#include <iostream>
#include <typeinfo>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//if (ac != 2)
	//{
	//	std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
	//	return (1);
	//}
	try {
		//BitcoinExchange bitcoinExchange(av[1]);
		IsoDate t1("2024-02-02");
		std::cout << t1 << std::endl;

		IsoDate t3("2024-02-30");



	} catch (std::exception &e){
		std::cerr << "An exception has been raised: " << e.what() << std::endl;
		return (1);
	}

}