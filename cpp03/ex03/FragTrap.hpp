#pragma once

#include "ClapTrap.hpp"
#include <ostream>

class FragTrap: virtual public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(FragTrap &c);
	FragTrap(std::string name);

	~FragTrap();
	void highFivesGuys(void) const;
	void attack(const std::string &target);
};

