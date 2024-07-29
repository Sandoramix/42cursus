#include "Weapon.hpp"

const std::string &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}

Weapon::Weapon(std::string type) : type(type)
{}