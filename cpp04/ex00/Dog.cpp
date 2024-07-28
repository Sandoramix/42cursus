#include "Dog.hpp"
#include <iostream>
#include <ostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "[Dog][DefaultConstructor]" << std::endl << std::endl;
}

Dog::Dog(Dog &d) : Animal(d.getType())
{
	std::cout << "[Dog][CopyConstructor]" << std::endl << std::endl;
}

Dog::~Dog()
{
	std::cout << std::endl << "[Dog][Destructor]" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog]: BauBau my friend!" << std::endl;
}

Dog &Dog::operator=(const Dog &d)
{
	this->type = d.getType();
	return *this;
}
