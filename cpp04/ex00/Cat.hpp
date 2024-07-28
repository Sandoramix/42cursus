#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(Cat &d);
	~Cat();

	Cat &operator=(const Cat &c);

	void makeSound() const;
};


#endif //CAT_HPP
