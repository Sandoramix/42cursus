#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "[FT][DEFAULT]\tconstructor\tname: " << this->name << std::endl;
}

FragTrap::FragTrap(FragTrap &c) : ClapTrap(c)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "[FT][COPY]\tconstructor\tname: " << this->name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "[FT]\t\tconstructor\tname: " << this->name << std::endl;

}

FragTrap::~FragTrap()
{
	std::cout << "[FT]\t\tdestructor\tname: " << this->name << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (!this->hitPoints)
	{
		std::cout << "FragTrap " << this->name << " wished to attack " << target << " but is already dead."
				  << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "FragTrap " << this->name << " wanted to frag " << target
				  << " but got skill issued." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name
			  << " frags " << target << " for " << this->attackDamage << " damage points."
			  << std::endl << "\tSame situation as with ClapTrap/ScavTrap... We'll never know who is " << target
			  << std::endl;
	this->energyPoints--;
}

void FragTrap::highFivesGuys(void) const
{
	static int n = 0;
	std::string tests[] = {"___ me five!", "Cleanup on ___ five!", "I've gone down: but I'll be up in 5!", "High-five relative"};
	std::string msg = tests[n];
	n = (n + 1) % 4;
	std::cout << "[FT]\t" << msg;
}