#include "Dog.hpp"
#include <iostream>
#include <ostream>

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "[Dog][DefaultConstructor]" << std::endl << std::endl;
}

Dog::Dog(Dog &d) : Animal(d.getType())
{
	std::cout << "[Dog][CopyConstructor]" << std::endl;
	if (d.brain)
	{
		std::cout << "\t[Cat][CopyConstructorCopyBrain]" << std::endl;
		this->brain = new Brain(*d.brain);
	}
	else
	{
		std::cout << "\t[Cat][CopyConstructorNewBrain]" << std::endl;
		this->brain = new Brain();
	}
	std::cout << std::endl;
}

Dog::~Dog()
{
	std::cout << std::endl << "[Dog][Destructor]" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "[Dog]: BauBau my friend!" << std::endl;
}

Dog &Dog::operator=(const Dog &d)
{
	if (&d == this)
	{
		return *this;
	}
	this->type = d.getType();
	return *this;
}
