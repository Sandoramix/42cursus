#include "Zombie.hpp"

int main(){
	int n = 5;
	std::string name = "Minion ";
	Zombie *horde = zombieHorde(n, name);

	delete []horde;
}