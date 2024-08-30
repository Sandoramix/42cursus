#include "Bureaucrat.hpp"
#include <iostream>

#define LOGLINE std::endl << __FILE__ << ":" << __LINE__

Bureaucrat *tryToCreate(std::string name, int grade)
{
	try
	{
		return new Bureaucrat(name, grade);
	} catch (std::exception &e)
	{
		std::cerr << "Exception occurred at Bureaucrat's creation (name=" << name << "; grade=" << grade << "): " << e.what() << "\n";
		return NULL;
	}
}

void printStats(Bureaucrat *b)
{
	if (!b)
	{
		return;
	}
	std::cout << "Bureaucrat's info: " << *b << "\n";
}

void tryToIncrement(Bureaucrat *b)
{
	if (!b)
	{
		return;
	}
	try
	{
		b->incrementGrade();
		std::cout << "Bureaucrat (name=" << b->getName() << ") called incrementGrade.\n\tNew grade: " << b->getGrade();
	} catch (std::exception &e)
	{
		std::cerr << "Exception occurred at Bureaucrat's incrementGrade: " << e.what() << "\n";
	}
}

void tryToDecrement(Bureaucrat *b)
{
	if (!b)
	{
		return;
	}
	try
	{
		b->decrementGrade();
		std::cout << "Bureaucrat (name=" << b->getName() << ") called decrementGrade.\n\tNew grade: " << b->getGrade()
				  << "\n";
	} catch (std::exception &e)
	{
		std::cerr << "Exception occurred at Bureaucrat's decrementGrade: " << e.what() << "\n";
	}
}


void myTests()
{
	std::cout << LOGLINE << std::endl << "----------" << "Valid variables" << "----------" << std::endl;
	Bureaucrat *validBest = tryToCreate("PippoBest", 1);
	Bureaucrat *validWorst = tryToCreate("PippoWorst", 150);
	if (!validBest || !validWorst)
	{
		delete validBest;
		delete validWorst;
		return;
	}

	Bureaucrat copyWorst(*validWorst);
	printStats(&copyWorst);

	std::cout << LOGLINE << std::endl << "----------" << "Invalid variables" << "----------" << std::endl;
	Bureaucrat *tooLow = tryToCreate("TooLow", 151);
	Bureaucrat *tooHigh = tryToCreate("TooHigh", -1);
	delete tooHigh;
	delete tooLow;

	std::cout << LOGLINE << std::endl << "----------" << "Increase/decrease test" << "----------" << std::endl;
	printStats(validBest);
	tryToDecrement(validBest);
	tryToIncrement(validBest);

	std::cout << LOGLINE << std::endl << "----------" << "Increase failure test" << "----------" << std::endl;
	tryToIncrement(validBest);

	std::cout << LOGLINE << std::endl << "----------" << "Decrease failure test" << "----------" << std::endl;
	printStats(validWorst);
	tryToDecrement(validWorst);

	std::cout << std::endl;

	delete validWorst;
	delete validBest;
}

int main(void)
{
	myTests();
}