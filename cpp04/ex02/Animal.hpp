#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <istream>
#include <ostream>
#include <string>
#include <iostream>


class Animal
{
protected:
	std::string type;

public:
	Animal();

	Animal(std::string type);

	Animal(Animal &a);

	virtual ~Animal();

	std::string getType() const;

	Animal &operator=(const Animal &a);

	virtual void makeSound() const = 0;
};


#endif //ANIMAL_HPP
