#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <ostream>
#include <string>
#include <iostream>

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public:
	FragTrap();

	FragTrap(FragTrap &c);

	FragTrap(std::string name);

	~FragTrap();

	void highFivesGuys(void) const;

	void attack(const std::string &target);
};

#endif //FRAGTRAP_HPP
