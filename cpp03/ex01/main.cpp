#include "ClapTrap.hpp"

int main(void){
	ClapTrap pippo("Pippo");
	std::cout << std::endl;


	ClapTrap originalMario("OrigMario");
	ClapTrap mario = originalMario;
	mario.setName("Mario");
	std::cout << std::endl;


	pippo.attack("Mario");
	std::cout << std::endl;
	pippo.takeDamage(9);
	pippo.beRepaired(1);
	pippo.beRepaired(1);
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	pippo.beRepaired(1);
	pippo.beRepaired(0);
	pippo.beRepaired(0);
	std::cout << std::endl;
	pippo.attack("Mario");
	std::cout << std::endl;
	pippo.beRepaired(99);
}