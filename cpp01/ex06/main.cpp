#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac == 1)
	{
		harl.complain("DEBUG");
	} else
	{
		harl.complain(av[1]);
	}
}