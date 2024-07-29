#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <ostream>

void subjectTests()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;//should not create a leak
	delete i;
}

void myTests()
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


int main(void)
{

	std::cout << "\e[94mSUBJECT TESTS\e[47;0m" << std::endl;
	subjectTests();

	std::cout << std::endl;

	std::cout << "\e[94mMY TESTS\e[47;0m" << std::endl;
	myTests();

	std::cout << std::endl;
}