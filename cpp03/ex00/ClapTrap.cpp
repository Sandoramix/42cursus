#include "ClapTrap.hpp"
#include <ostream>


ClapTrap::ClapTrap() : name("DEFAULT"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[DEFAULT]\tconstructor\tname: " << this->name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[PARAM]\tconstructor\tname: " << this->name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &clapTrap)
{
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	std::cout << "[COPY]\t\tconstructor\tname: " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[DESTRUCTOR]\t\tname: " << this->name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &ct)
{
	if (&ct == this)
	{
		return *this;
	}
	std::string oldname = this->name;
	this->name = ct.name;
	this->hitPoints = ct.hitPoints;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	std::cout << "[COPY]\tassignment\told name: " << oldname << "\tname: " << this->name << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " tried to attack " << target << "." << std::endl
				  << "\tSadly enough... dead can't hurt anyone" << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " planned to attack " << target
				  << " but got very lazy and forgot to do so" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name
			  << " attacks " << target << " by causing " << this->attackDamage << " damage points."
			  << std::endl << "\tBut we don't know who " << target << " is, so it wont ever be hurt."
			  << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << "Have mercy over " << this->name << ". Can't you see? It's already on the floor ~.~" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage." << std::endl;
	this->hitPoints -= amount > this->hitPoints ? this->hitPoints : amount % (this->hitPoints + 1);
	std::cout << "\tRemaining hitPoints: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " tried to repair itself for " << amount << " hitPoints..."
				  << std::endl
				  << "\tBut it didn't considerate that he was out of energy points (RIP)" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " repaired itself for " << amount << " hitPoints." << std::endl;
	if (!this->hitPoints)
	{
		std::cout << "\tHOLY MOLY! We witnessed to a miracle. It revived itself" << std::endl;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout << "\tCurrent hitPoints: " << this->hitPoints << std::endl;
}

void ClapTrap::setName(std::string newName)
{
	this->name = newName;
}
