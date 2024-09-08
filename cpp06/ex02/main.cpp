#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <ostream>
#include <stdlib.h>

Base *generate(void)
{
	const int choice = rand() % 3;
	switch (choice)
	{
		case 0:
		{
			return new A();
		}
		case 1:
		{
			return new B();
		}
		case 2:
		{
			return new C();
		}
		default:
		{
			return new A();
		}
	}
}

void identify(Base *p)
{
	std::cout << "Identifying pointer to " << p << std::endl << "\tResult: ";

	if (dynamic_cast<A *>(p))
		std::cout << "\"A\"" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "\"B\"" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "\"C\"" << std::endl;
	else
		std::cout << "UNKNOWN!" << std::endl;
}

void identify(Base &p){
	std::cout << "Identifying reference to " << &p << std::endl << "\tResult: ";

	try{
		A &a = dynamic_cast<A &>(p);
		std::cout << "\"A\"" << std::endl;
		(void)a;
		return;
	} catch (std::exception &){};
	try{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "\"B\"" << std::endl;
		return;
	} catch (std::exception &){};
	try{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "\"C\"" << std::endl;
		return;
	} catch (std::exception &){};

	std::cout << "UNKNOWN!" << std::endl;
}


void myTests()
{
	Base *first = generate();
	Base *second = generate();
	Base *third = generate();

	identify(first);
	identify(second);
	identify(third);

	std::cout << std::endl << "";

	identify(*first);
	identify(*second);
	identify(*third);

	delete first;
	delete second;
	delete third;
}

int main()
{

	std::srand(std::time(NULL));
	myTests();
}