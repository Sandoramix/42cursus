#ifndef ICE_HPP
#define ICE_HPP

#include <istream>
#include <ostream>
#include <string>
#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();

	Ice(const Ice &i);

	~Ice();

	Ice &operator=(const Ice &i);

	Ice *clone() const;

	void use(ICharacter &target);
};


#endif //ICE_HPP
