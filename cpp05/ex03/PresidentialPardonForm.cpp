#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][Constructor]:\t" << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s)
	: AForm("PresidentialPardonForm", 25, 5), target(s.target)
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][CopyConstructor]:\t" << *this << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][Destructor]:\t" << *this << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &s)
{
	if (this == &s)
	{
		return *this;
	}
	this->target = s.target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const
{
	AForm::validateRequiredGradeToExecuteOrThrow(b);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return target;
}

void PresidentialPardonForm::setTarget(const std::string &target)
{
	PresidentialPardonForm::target = target;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &f)
{
	os << "PresidentialPardonForm(name=" << f.getName()
	   << "; signed=" << (f.getIsSigned() ? "true" : "false")
	   << "; target=" << f.getTarget()
	   << "; requiredGrades{'sign': " << f.getRequiredGradeToSign()
	   << ", 'execute': " << f.getRequiredGradeToExecute() << "})";
	return os;
}
