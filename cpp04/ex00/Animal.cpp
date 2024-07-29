#include "Animal.hpp"
#include <iostream>
#include <ostream>

Animal::Animal() : type("Unknown")
{
	std::cout << "[Animal][DefaultConstructor]\t[type=" << this->type << "]" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "[Animal][Constructor]\t\t[type=" << this->type << "]" << std::endl;
}

Animal::Animal(Animal &a) : type(a.getType())
{
	std::cout << "[Animal][CopyConstructor]\t[type=" << this->type << "]" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[Animal][Destructor]\t[type=" << this->type << "]" << std::endl;
}


std::string Animal::getType() const
{
	return this->type;
}

Animal &Animal::operator=(const Animal &a)
{
	if (&a == this)
	{
		return *this;
	}
	this->type = a.getType();
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "[Animal][type=" << this->type << "] Sound of void..." << std::endl;
}

