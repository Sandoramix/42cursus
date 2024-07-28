#include "DiamondTrap.hpp"

int main(void){
	DiamondTrap pippo("Pippo");
	std::cout << std::endl;

	DiamondTrap originalMario("OrigMario");
	DiamondTrap mario = originalMario;
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

	pippo.whoAmI();
}