#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), guardGateStatus(DISABLED)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "[ST][DEFAULT]\tconstructor\tname: " << this->name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &c) : ClapTrap(c), guardGateStatus(DISABLED)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "[ST][COPY]\tconstructor\tname: " << this->name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), guardGateStatus(DISABLED)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "[ST]\t\tconstructor\tname: " << this->name << std::endl;

}

ScavTrap::~ScavTrap()
{
	std::cout << "[ST]\t\tdestructor\tname: " << this->name << std::endl;
}

void ScavTrap::guardGate(void)
{
	this->guardGateStatus = this->guardGateStatus == DISABLED ? ENABLED : DISABLED;
	if (this->guardGateStatus == DISABLED){
		std::cout << "[ST]\tScavTrap " << this->name << " Turned off GUARD GATE. Everybody should rest eventually." << std::endl;
	} else {
		std::cout << "[ST]\tScavTrap " << this->name << "Turned on GUARD GATE. GLHF" << std::endl;
	}
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->hitPoints)
	{
		std::cout << "ScavTrap " << this->name << " attacked " << target << "." << std::endl
				  << "\tBut haven't realised he's a ghost yet." << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "ScavTrap " << this->name << " planned to attack " << target
				  << " . Surely he will do so... Maybe" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name
			  << " attacks " << target << " by causing " << this->attackDamage << " damage points."
			  << std::endl << "\tSame situation as with ClapTrap... Who is " << target << " ?"
			  << std::endl;
	this->energyPoints--;
}