#pragma once




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



