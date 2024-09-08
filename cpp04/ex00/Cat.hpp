#ifndef CAT_HPP
#define CAT_HPP

#include <ostream>
#include <string>
#include <iostream>

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();

	Cat(Cat &c);

	~Cat();

	Cat &operator=(const Cat &c);

	void makeSound() const;
};


#endif //CAT_HPP
