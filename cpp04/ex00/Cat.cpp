#include "Cat.hpp"
#include <iostream>
#include <ostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "[Cat][DefaultConstructor]" << std::endl << std::endl;
}

Cat::Cat(Cat &d) : Animal(d.getType())
{
	std::cout << "[Cat][CopyConstructor]" << std::endl << std::endl;
}

Cat::~Cat()
{
	std::cout  << std::endl << "[Cat][Destructor]" << std::endl;
}

void Cat::makeSound()  const
{
	std::cout << "[Cat]: MiauMiau broski!" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
	this->type = c.getType();
	return *this;
}
