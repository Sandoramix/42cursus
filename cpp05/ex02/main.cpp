#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <ostream>

#define LOGLINE std::endl << __FILE_NAME__ << ":" << __LINE__

typedef enum e_formtype
{
	PRESIDENTIAL_PARDON_FORM,
	ROBOTOMY_REQUEST_FORM,
	SHRUBBERY_CREATION_FORM
} t_formtype;

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

AForm *tryToCreateForm(const t_formtype type, const std::string target)
{
	try
	{
		switch (type)
		{
			case PRESIDENTIAL_PARDON_FORM:
			{
				return new PresidentialPardonForm(target);
			}
			case ROBOTOMY_REQUEST_FORM:
			{
				return new RobotomyRequestForm(target);
			}
			case SHRUBBERY_CREATION_FORM:
			{
				return new ShrubberyCreationForm(target);
			}
			default:
			{
				std::cerr << "Invalid/unknown form type provided." << std::endl;
				return NULL;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred at form creation with target=" << target << "\n";
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

	std::cout << LOGLINE << std::endl << "----------" << "Forms creation" << "----------" << std::endl;
	AForm *presidentialForm = tryToCreateForm(PRESIDENTIAL_PARDON_FORM, "jesus");
	AForm *robotomyForm = tryToCreateForm(ROBOTOMY_REQUEST_FORM, "marvin");
	AForm *shrubberyForm = tryToCreateForm(SHRUBBERY_CREATION_FORM, "shenanigans");

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
