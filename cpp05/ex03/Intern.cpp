#include "Intern.hpp"


static const std::string defaultValidFormsAliases[Intern::avaiableFormsCount][Intern::formAliasesCount] = {
	{"PresidentialPardon", "presidential pardon"},
	{"RobotomyRequest",    "robotomy request"},
	{"ShrubberyCreation",  "shrubbery creation"}
};


Intern::Intern()
{
	std::cerr << "[DBG-LOG]\t[" << typeid(*this).name() << "][Constructor]" << std::endl;
	for (int i = 0; i < Intern::avaiableFormsCount; i++)
	{
		for (int j = 0; j < Intern::formAliasesCount; j++)
		{
			this->allFormsAliases[i][j] = defaultValidFormsAliases[i][j];
		}
	}
}

Intern::Intern(const Intern &intern)
{
	for (int i = 0; i < Intern::avaiableFormsCount; i++)
	{
		for (int j = 0; j < Intern::formAliasesCount; j++)
		{
			this->allFormsAliases[i][j] = intern.allFormsAliases[i][j];
		}
	}
	std::cerr << "[DBG-LOG]\t[" << typeid(*this).name() << "][CopyConstructor]" << std::endl;
}

Intern::~Intern()
{
	std::cerr << "[DBG-LOG]\t[" << typeid(*this).name() << "][Destructor]" << std::endl;
}

Intern &Intern::operator=(const Intern &intern)
{
	if (&intern == this)
	{
		return *this;
	}
	for (int i = 0; i < Intern::avaiableFormsCount; i++)
	{
		for (int j = 0; j < Intern::formAliasesCount; j++)
		{
			this->allFormsAliases[i][j] = intern.allFormsAliases[i][j];
		}
	}
	return *this;
}

static std::string str_lower(std::string str)
{
	std::ostringstream os;

	std::string::iterator str_end = str.end();
	for (std::string::iterator iterator = str.begin(); iterator != str_end; ++iterator)
	{
		os << (char) tolower(*iterator);
	}
	return os.str();
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
	int idx = 0;
	bool found = false;

	while (idx < Intern::avaiableFormsCount)
	{
		for (int j = 0; j < Intern::formAliasesCount; j++)
		{
			if (str_lower(this->allFormsAliases[idx][j]) == str_lower(formName))
			{
				found = true;
				break;
			}
		}
		if (found)
			break;
		idx++;
	}
	AForm *form;

	switch ((t_formtype) idx)
	{
		case PRESIDENTIAL_PARDON_FORM:
		{
			form = new PresidentialPardonForm(formTarget);
			break;
		}
		case ROBOTOMY_REQUEST_FORM:
		{
			form = new RobotomyRequestForm(formTarget);
			break;
		}
		case SHRUBBERY_CREATION_FORM:
		{
			form = new ShrubberyCreationForm(formTarget);
			break;
		}
		default:
		case FORMTYPE_COUNT:
		{
			std::cerr << "Intern could not create a form called " << formName << ". Nobody knows what that is." << std::endl;
			return NULL;
		}
	}
	std::cout << "Intern creates " << *form << "\n";

	return form;
}
