#include "Zombie.hpp"

Zombie::Zombie() : name("UnknownZombie")
{}

Zombie::Zombie(std::string name) : name(name)
{}


void Zombie::setName(std::string newName)
{
	this->name = newName;
}
Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}