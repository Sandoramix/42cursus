#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: name(name), weapon(weapon)
{}

void HumanA::setWeapon(Weapon &newWeapon)
{
	this->weapon = newWeapon;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType()
			  << std::endl;
}
