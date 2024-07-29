#include "WrongCat.hpp"
#include <ostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat][DefaultConstructor]" << std::endl << std::endl;
}

WrongCat::WrongCat(WrongCat &wc) : WrongAnimal(wc.getType())
{
	std::cout << "[WrongCat][CopyConstructor]" << std::endl << std::endl;
}

WrongCat::~WrongCat()
{

	std::cout << std::endl << "[WrongCat][Destructor]" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &wc)
{
	if (&wc == this)
	{
		return *this;
	}
	this->type = wc.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] This message won't ever be printed" << std::endl;
}
