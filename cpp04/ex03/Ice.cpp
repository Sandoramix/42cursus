#include "Ice.hpp"
#include <ostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "[Ice][DefaultConstructor]" << std::endl << std::endl;
}

Ice::Ice(const Ice &i) : AMateria(i.getType())
{
	std::cout << "[Cure][CopyConstructor]" << std::endl << std::endl;
}

Ice::~Ice()
{
	std::cout << "[Ice][Destructor]" << std::endl << std::endl;
}

Ice &Ice::operator=(const Ice &i)
{
	if (&i != this)
	{
		this->type = i.getType();
	}
	return *this;
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
