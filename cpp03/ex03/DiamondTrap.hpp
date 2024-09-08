#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include <ostream>
#include <string>
#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();

	DiamondTrap(std::string name);

	DiamondTrap(DiamondTrap &dt);

	~DiamondTrap();

	void whoAmI();

	void attack(const std::string &target);
};
#endif //DIAMOND_TRAP_HPP