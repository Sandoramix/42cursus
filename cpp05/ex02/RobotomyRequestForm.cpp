#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][Constructor]:\t\t" << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s)
	: AForm("RobotomyRequestForm", 72, 45), target(s.target)
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][CopyConstructor]:\t\t" << *this << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][Destructor]:\t\t" << *this << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &s)
{
	if (this == &s)
	{
		return *this;
	}
	this->target = s.target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	static unsigned short count = rand() > (RAND_MAX / 2);

	AForm::validateRequiredGradeToExecuteOrThrow(b);
	if (count % 2 == 0)
	{
		std::cout << this->target << " has been robotomized\n";
	}
	else
	{
		std::cout << this->target << " escaped from being robotomized\n";
	}
	count++;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return target;
}

void RobotomyRequestForm::setTarget(const std::string &target)
{
	RobotomyRequestForm::target = target;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &f)
{
	os << "RobotomyRequestForm(name=" << f.getName()
	   << "; signed=" << (f.getIsSigned() ? "true" : "false")
	   << "; target=" << f.getTarget()
	   << "; requiredGrades{'sign': " << f.getRequiredGradeToSign()
	   << ", 'execute': " << f.getRequiredGradeToExecute() << "})";
	return os;
}
