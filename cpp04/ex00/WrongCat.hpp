#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <ostream>
#include <string>
#include <iostream>

#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
public:
	WrongCat();

	WrongCat(WrongCat &wc);

	~WrongCat();

	WrongCat &operator=(WrongCat &wc);

	void makeSound() const;
};


#endif //WRONGCAT_HPP
