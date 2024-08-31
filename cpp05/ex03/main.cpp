#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include "Intern.hpp"

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
		std::cout << "Exception occurred at Bureaucrat's creation (name=" << name << "; grade=" << grade << "): "
				  << e.what() << "\n";
		return NULL;
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
	std::cout << LOGLINE << std::endl << "----------" << "Intern creation" << "----------" << std::endl;
	Intern randomDude;

	std::cout << LOGLINE << std::endl << "----------" << "Forms invalid creation" << "----------" << std::endl;
	AForm *invalidFormName = randomDude.makeForm("inexistent formName", "someTarget");
	delete invalidFormName;

	std::cout << LOGLINE << std::endl << "----------" << "Forms valid creation" << "----------" << std::endl;
	AForm *presidentialForm = randomDude.makeForm("PresidentialPardon", "jesus");

	std::cout << std::endl;
	AForm *robotomyForm = randomDude.makeForm("robotomy request", "marvin");

	std::cout << std::endl;
	AForm *shrubberyForm = randomDude.makeForm("ShruBberycreaTion", "shenanigans");

	if (!presidentialForm || !robotomyForm || !shrubberyForm)
	{
		delete shrubberyForm;
		delete robotomyForm;
		delete presidentialForm;
		delete validWorst;
		delete validBest;
		return;
	}


	std::cout << LOGLINE << std::endl << "----------" << "ShrubberyCreation test" << "----------" << std::endl;

	validWorst->signForm(*shrubberyForm);

	std::cout << std::endl;

	validBest->executeForm(*shrubberyForm);
	validBest->signForm(*shrubberyForm);
	validBest->executeForm(*shrubberyForm);

	std::cout << LOGLINE << std::endl << "----------" << "RobotomyRequest test" << "----------" << std::endl;

	validWorst->signForm(*robotomyForm);

	std::cout << std::endl;

	validBest->executeForm(*robotomyForm);
	validBest->signForm(*robotomyForm);
	validBest->executeForm(*robotomyForm);
	validBest->executeForm(*robotomyForm);


	std::cout << LOGLINE << std::endl << "----------" << "PresidentialPardon test" << "----------" << std::endl;

	validWorst->signForm(*presidentialForm);

	std::cout << std::endl;

	validBest->executeForm(*presidentialForm);
	validBest->signForm(*presidentialForm);
	validBest->executeForm(*presidentialForm);

	std::cout << std::endl;

	delete shrubberyForm;
	delete robotomyForm;
	delete presidentialForm;
	delete validWorst;
	delete validBest;
}

int main(void)
{
	myTests();
}
