#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

#define LOGLINE std::endl << __FILE__ << ":" << __LINE__

Bureaucrat *tryToCreateBureaucrat(std::string name, int grade)
{
	try
	{
		return new Bureaucrat(name, grade);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred at Bureaucrat's creation (name=" << name << "; grade=" << grade << "): " << e.what() << std::endl;
		return NULL;
	}
}

Form *tryToCreateForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute)
{
	try
	{
		return new Form(name, requiredGradeToSign, requiredGradeToExecute);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred at Form's creation (name=" << name
				  << "; requiredGradeToSign=" << requiredGradeToSign
				  << "; requiredGradeToExecute= " << requiredGradeToExecute << "): " << e.what() << std::endl;
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
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred at Bureaucrat's incrementGrade: " << e.what() << std::endl;
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
		std::cout << "Bureaucrat (name=" << b->getName() << ") called decrementGrade.\n\tNew grade: " << b->getGrade() << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred at Bureaucrat's decrementGrade: " << e.what() << std::endl;
	}
}


void myTests()
{
	std::cout << LOGLINE << std::endl << "----------" << "Valid bureaucrats" << "----------" << std::endl;
	Bureaucrat *validBest = tryToCreateBureaucrat("PippoBest", 1);
	Bureaucrat *validWorst = tryToCreateBureaucrat("PippoWorst", 150);
	if (!validBest || !validWorst)
	{
		delete validBest;
		delete validWorst;
		return;
	}

	std::cout << LOGLINE << std::endl << "----------" << "Valid form" << "----------" << std::endl;
	Form *form1 = tryToCreateForm("VALID1", 130, 130);
	if (!form1)
	{
		delete validBest;
		delete validWorst;
		return;
	}

	std::cout << std::endl << "----------" << "Invalid form" << "----------" << std::endl;
	Form *invalid1 = tryToCreateForm("INVALID1", -1, 130);
	Form *invalid2 = tryToCreateForm("INVALID2", 130, 155);
	delete invalid2;
	delete invalid1;


	std::cout << LOGLINE << std::endl << "----------" << "Sign test" << "----------" << std::endl;
	validWorst->signForm(*form1);
	std::cout << std::endl;
	validBest->signForm(*form1);

	std::cout << LOGLINE << std::endl << "----------" << "Form info" << "----------" << std::endl;
	std::cout << "form1 info: " << *form1 << "\n";

	std::cout << std::endl;

	delete form1;
	delete validWorst;
	delete validBest;
}

int main(void)
{
	myTests();
}
