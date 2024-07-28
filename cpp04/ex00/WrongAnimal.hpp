#include <iostream>
#include <string>

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal &a);
	virtual ~WrongAnimal();
	std::string getType() const;

	WrongAnimal &operator=(const WrongAnimal &a);

	void makeSound() const;
};


#endif //WRONGANIMAL_HPP
