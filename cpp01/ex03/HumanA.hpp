#pragma once




#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(std::string name, Weapon &weapon);

	void setWeapon(Weapon &newWeapon);

	void attack();
};


