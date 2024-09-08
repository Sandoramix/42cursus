#ifndef INTERN_HPP
#define INTERN_HPP

#include <istream>
#include <ostream>
#include <string>
#include <iostream>
#include <exception>
#include <sstream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

typedef enum e_formtype
{
	PRESIDENTIAL_PARDON_FORM,
	ROBOTOMY_REQUEST_FORM,
	SHRUBBERY_CREATION_FORM,
	FORMTYPE_COUNT // needs to be always at the bottom and other values should be set to default ones.
} t_formtype;


class Intern
{
public:
	static const int avaiableFormsCount = FORMTYPE_COUNT;
	static const int formAliasesCount = 2;
private:
	std::string allFormsAliases[Intern::avaiableFormsCount][Intern::formAliasesCount];

public:
	Intern();
	Intern(const Intern &i);
	~Intern();

	Intern &operator=(const Intern &i);

	AForm *makeForm(const std::string &formName, const std::string &formTarget) const;

};


#endif //INTERN_HPP
