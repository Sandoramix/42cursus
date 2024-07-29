#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "VALID OPTIONS:" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout << "INVALID OPTIONS:" << std::endl;
	harl.complain("INVALID");
}