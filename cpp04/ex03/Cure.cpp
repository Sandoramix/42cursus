#include "Cure.hpp"
#include <ostream>

Cure::Cure() : AMateria("Cure")
{
	std::cout << "[Cure][DefaultConstructor]" << std::endl << std::endl;
}

Cure::Cure(const Cure &c) : AMateria(c.getType())
{
	std::cout << "[Cure][CopyConstructor]" << std::endl << std::endl;
}

Cure::~Cure()
{
	std::cout << "[Cure][Destructor]" << std::endl << std::endl;
}

Cure &Cure::operator=(const Cure &c)
{
	if (&c != this){
		this->type = c.getType();
	}
	return *this;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals "<<target.getName()<<"'s wounds *" << std::endl;
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}
