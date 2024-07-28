#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <ostream>

void subjectTests()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
}

void animalTests()
{
	{
		std::cout << std::endl << "---------START ANIMAL CLASS TESTS---------" << std::endl;
		Animal defConstructor;
		Animal paramConstructor("SomeAnimal");
		Animal copyConstructor(paramConstructor);
		Animal copyAssignment;
		copyAssignment = paramConstructor;

		std::cout << "makeSound: ";
		copyAssignment.makeSound();
		std::cout << std::endl;
	}
	std::cout << "---------END ANIMAL CLASS TESTS-----------" << std::endl;

	std::cout << std::endl << "----------START CAT CLASS TESTS----------" << std::endl;
	{
		Cat defConstructor;
		Cat copyConstructor(defConstructor);
		Cat copyAssignment;
		copyAssignment = defConstructor;
		Animal *abstracted = new Cat(copyAssignment);

		std::cout << "makeSound: ";
		abstracted->makeSound();
		std::cout << std::endl;
		delete abstracted;
	}
	std::cout << "----------END CAT CLASS TESTS------------" << std::endl;

	std::cout << std::endl << "----------START DOG CLASS TESTS----------" << std::endl;
	{
		Dog defConstructor;
		Dog copyConstructor(defConstructor);
		Dog copyAssignment = defConstructor;
		Animal *abstracted = new Dog(copyAssignment);

		std::cout << "makeSound: ";
		abstracted->makeSound();
		std::cout << std::endl;
		delete abstracted;
	}
	std::cout << "----------END DOG CLASS TESTS------------" << std::endl;

}

void wrongAnimalTests()
{
	std::cout << std::endl << "------START WRONG ANIMAL CLASS TESTS-----" << std::endl;
	{
		WrongAnimal defConstructor;
		WrongAnimal paramConstructor("SomeWrongAnimal");
		WrongAnimal copyConstructor(paramConstructor);
		WrongAnimal copyAssignment;
		copyAssignment = paramConstructor;
		WrongAnimal *abstracted = new WrongAnimal(copyAssignment);

		std::cout << "makeSound: ";
		abstracted->makeSound();
		std::cout << std::endl;
		delete abstracted;
	}
	std::cout << "------END WRONG ANIMAL CLASS TESTS-------" << std::endl;

	std::cout << std::endl << "-------START WRONG CAT CLASS TESTS-------" << std::endl;
	{
		WrongCat defConstructor;
		WrongCat copyConstructor(defConstructor);
		WrongCat copyAssignment;
		copyAssignment = defConstructor;
		WrongAnimal *abstracted = new WrongCat(copyAssignment);

		std::cout << "makeSound: ";
		abstracted->makeSound();
		std::cout << std::endl;
		delete abstracted;
	}
	std::cout << "-------END WRONG CAT CLASS TESTS---------" << std::endl;
}


int main(void)
{

	std::cout << "\e[94mSUBJECT TESTS\e[47;0m" << std::endl;
	subjectTests();

	std::cout << std::endl;

	std::cout << "\e[94mANIMAL TESTS\e[47;0m" << std::endl;
	animalTests();

	std::cout << std::endl;

	std::cout << "\e[94mWRONG ANIMAL TESTS\e[47;0m" << std::endl;
	wrongAnimalTests();

}