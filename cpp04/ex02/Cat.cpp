#include "Cat.hpp"
#include <iostream>
#include <ostream>


Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "[Cat][DefaultConstructor]" << std::endl << std::endl;
}

Cat::Cat(Cat &c) : Animal(c.getType())
{
	std::cout << "[Cat][CopyConstructor]" << std::endl;
	if (c.brain)
	{
		std::cout << "\t[Cat][CopyConstructorCopyBrain]" << std::endl;
		this->brain = new Brain(*c.brain);
	}
	else
	{
		std::cout << "\t[Cat][CopyConstructorNewBrain]" << std::endl;
		this->brain = new Brain();
	}
	std::cout << std::endl;
}

Cat::~Cat()
{
	std::cout << std::endl << "[Cat][Destructor]" << std::endl;
	delete this->brain;
}

void Cat::makeSound()  const
{
	std::cout << "[Cat]: MiauMiau broski!" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
	if (&c == this){
		return *this;
	}
	this->type = c.getType();
	return *this;
}
