#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();

	Cat(Cat &c);

	~Cat();

	Cat &operator=(const Cat &c);

	void makeSound() const;
};


#endif //CAT_HPP
