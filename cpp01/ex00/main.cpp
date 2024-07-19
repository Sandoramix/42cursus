#include "Zombie.hpp"

int main(){
	Zombie *pointed = newZombie("Allocated Z");
	randomChump("Random champ 1");
	randomChump("Random champ 2");

	Zombie stacked("Z. on stack");
	delete pointed;
}