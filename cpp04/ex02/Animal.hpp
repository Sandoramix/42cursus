#include <istream>
#include <string>

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


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
