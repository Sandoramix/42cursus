#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string name),
	HumanB(std::string name, Weapon &weapon);

	void setWeapon(Weapon &newWeapon);

	void attack();
};

#endif //HUMANB_HPP
