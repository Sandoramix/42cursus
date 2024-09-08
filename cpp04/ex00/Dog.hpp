#ifndef DOG_HPP
#define DOG_HPP

#include <ostream>
#include <string>
#include <iostream>

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();

	Dog(Dog &d);

	~Dog();

	Dog &operator=(const Dog &d);

	void makeSound() const;
};


#endif //DOG_HPP