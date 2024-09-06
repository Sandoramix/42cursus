#include "ScalarConvert.hpp"

#include <iostream>
#include <ostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " [str value]" << std::endl;
		return (1);
	}
	ScalarConvert::convert(av[1]);
	return (0);
}