#include "AMateria.hpp"
#include <ostream>



AMateria::AMateria() : type("Unknown")
{
	std::cout << "[AMateria][DefaultConstructor][type=" << this->type << "]" << std::endl << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << "[AMateria][ParamConstructor][type=" << this->type << "]" << std::endl << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria][Destructor][type=" << this->type << "]" << std::endl << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "[AMateria] " << this->type << " used on " << target.getName() << std::endl;
}

