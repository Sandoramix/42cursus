#pragma once

#include "ClapTrap.hpp"
#include <ostream>

typedef enum GuardModeEnum
{
	ENABLED,
	DISABLED
}	GuardMode;

class ScavTrap: public ClapTrap
{
private:
	GuardMode guardGateStatus;
public:
	ScavTrap();
	ScavTrap(ScavTrap &c);
	ScavTrap(std::string name);

	~ScavTrap();
	void guardGate(void);

	void attack(const std::string &target);
};
