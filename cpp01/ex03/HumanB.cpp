#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name)
{}

HumanB::HumanB(std::string name, Weapon &weapon)
	: name(name), weapon(&weapon)
{}

void HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}

void HumanB::attack()
{
	std::cout << this->name;
	if (!weapon)
	{
		std::cout
			<< " is disarmed, but brave enough to scream at the opponent.";
	} else
	{
		std::cout << " attacks with their " << this->weapon->getType();
	}
	std::cout << std::endl;
}
