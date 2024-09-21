#include "BitcoinExchange.hpp"
#include <iostream>
#include <typeinfo>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange bitcoinExchange(av[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception raised: " << e.what() << std::endl;
		return (1);
	}

}