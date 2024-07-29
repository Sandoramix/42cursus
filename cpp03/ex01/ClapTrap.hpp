#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

public:
	ClapTrap();

	ClapTrap(std::string name);

	ClapTrap(ClapTrap &clapTrap);

	virtual ~ClapTrap();

	ClapTrap &operator=(ClapTrap &ct);

	virtual void attack(const std::string &target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

	void setName(std::string newName);
};

#endif //CLAPTRAP_HPP
