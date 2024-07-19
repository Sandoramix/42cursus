#pragma once

#ifndef HUMANA_HPP
#define HUMANA_HPP

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

#endif //HUMANA_HPP
