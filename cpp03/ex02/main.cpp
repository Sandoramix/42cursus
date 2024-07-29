#include "FragTrap.hpp"

int main(void)
{
	FragTrap pippo("Pippo");
	std::cout << std::endl;


	FragTrap originalMario("OrigMario");
	FragTrap mario = originalMario;
	mario.setName("Mario");
	std::cout << std::endl;

	pippo.attack("Mario");
	std::cout << std::endl;
	pippo.takeDamage(400);
	std::cout << std::endl;
	pippo.takeDamage(666);
	std::cout << std::endl;
	pippo.beRepaired(4);
	pippo.beRepaired(1);
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	std::cout << std::endl;
	pippo.highFivesGuys();
	std::cout << std::endl;
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	pippo.beRepaired(1);
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	std::cout << std::endl;
	pippo.highFivesGuys();
	std::cout << std::endl;
	pippo.takeDamage(666);

	std::cout << std::endl;
	pippo.attack("Mario");
	std::cout << std::endl;
	pippo.beRepaired(99);
}