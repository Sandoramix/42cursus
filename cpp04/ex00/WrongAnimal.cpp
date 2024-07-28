#include "WrongAnimal.hpp"
#include <ostream>

WrongAnimal::WrongAnimal() : type("UnknownButWrong")
{
	std::cout << "[WrongAnimal][DefaultConstructor]\t[type=" << this->getType() << "]" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "[WrongAnimal][Constructor]\t[type=" << this->getType() << "]" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &a) : type(a.getType())
{
	std::cout << "[WrongAnimal][CopyConstructor]\t[type=" << this->getType() << "]" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal][Destructor]\t[type=" << this->getType() << "]" << std::endl;

}

std::string WrongAnimal::getType() const
{
	return this->type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
	this->type = a.getType();
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal][type=" << this->type << "] This should feel wrong..." << std::endl;
}
