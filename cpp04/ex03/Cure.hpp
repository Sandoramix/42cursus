#ifndef CURE_HPP
#define CURE_HPP

#include <istream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &c);
	~Cure();

	Cure &operator=(const Cure &c);
	Cure* clone() const;

	void use(ICharacter &target);
};


#endif //CURE_HPP
