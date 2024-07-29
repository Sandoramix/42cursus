#include "DiamondTrap.hpp"
#include <ostream>

DiamondTrap::DiamondTrap() : ClapTrap("[DT]Default_clap_trap")
{
	this->name = "[DT]Default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "[DT][DEFAULT]\tconstructor\tname: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &dt) : ClapTrap(dt), ScavTrap(dt), FragTrap(dt)
{
	this->name = dt.name;
	this->hitPoints = dt.hitPoints;
	this->energyPoints = dt.energyPoints;
	this->attackDamage = dt.attackDamage;
	std::cout << "[DT][COPY]\tconstructor\tname: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "[DT]\t\tconstructor\tname: " << this->name << std::endl;

}

void DiamondTrap::attack(const std::string &target)
{
	std::cout << "[DT] is calling attack method from ScavTrap... please be patient" << std::endl;
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DT]\t\tdestructor\tname: " << this->name << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DT] Who could i possibly be? I'm batma... " << this->name << " :) nice to meet you." << std::endl;
}
