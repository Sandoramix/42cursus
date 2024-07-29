#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <ostream>

class FragTrap : public ClapTrap
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

#endif //FRAGTRAP_HPP
