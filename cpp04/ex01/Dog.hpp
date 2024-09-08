#ifndef DOG_HPP
#define DOG_HPP

#include <istream>
#include <ostream>
#include <string>
#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();

	Dog(Dog &d);

	~Dog();

	Dog &operator=(const Dog &d);

	void makeSound() const;
};


#endif //DOG_HPP
