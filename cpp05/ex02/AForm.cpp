#include "AForm.hpp"

void AForm::validateRequiredGradeFieldOrThrow(int grade, const std::string &errorMsg)
{
	if (grade >= BEST_GRADE && grade <= WORST_GRADE)
		return;
	std::cerr << "[DBG-LOG]\t\t[AForm][ValidationError] validating the grade: " << errorMsg << std::endl;
	if (grade < BEST_GRADE)
		throw AForm::GradeTooHighException();
	throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute)
	: name(name), requiredGradeToSign(requiredGradeToSign), requiredGradeToExecute(requiredGradeToExecute),
	  isSigned(false)
{
	std::srand(std::time(NULL));
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][Constructor]\t\t\t\t" << *this << std::endl;
	validateRequiredGradeFieldOrThrow(this->requiredGradeToSign, "Signing grade is invalid");
	validateRequiredGradeFieldOrThrow(this->requiredGradeToExecute, "Execution grade is invalid");
}

AForm::AForm(const AForm &f)
	: name(f.name), requiredGradeToSign(f.requiredGradeToSign), requiredGradeToExecute(f.requiredGradeToExecute),
	  isSigned(false)
{
	std::srand(std::time(NULL));
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][CopyConstructor]\t\t\t\t" << *this << std::endl;
	validateRequiredGradeFieldOrThrow(requiredGradeToSign, "Signing grade is invalid");
	validateRequiredGradeFieldOrThrow(requiredGradeToExecute, "Execution grade is invalid");
}

AForm::~AForm()
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][Destructor]\t\t\t\t" << *this << std::endl;
}

AForm &AForm::operator=(const AForm &f)
{
	if (this == &f)
		return *this;
	this->isSigned = f.isSigned;
	return *this;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (this->requiredGradeToSign < b.getGrade())
	{
		std::cerr << "[DBG-LOG]\tAForm {" << this->name << "} cannot be signed by {" << b << "}"
				  << " Required grade is " << this->requiredGradeToSign << std::endl;
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (this->requiredGradeToExecute < executor.getGrade())
	{
		std::cerr << "[DBG-LOG]\tAForm cannot be executed by {" << executor << "}"
				  << "Required grade is " << this->requiredGradeToExecute << std::endl;
		throw AForm::GradeTooLowException();
	}
}

std::string AForm::getName() const
{
	return name;
}

int AForm::getRequiredGradeToSign() const
{
	return requiredGradeToSign;
}

int AForm::getRequiredGradeToExecute() const
{
	return requiredGradeToExecute;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

void AForm::setIsSigned(bool isSigned)
{
	AForm::isSigned = isSigned;
}

void AForm::validateRequiredGradeToExecuteOrThrow(const Bureaucrat &executor) const
{
	if (!this->isSigned)
	{
		throw AForm::FormNotSignedException();
	}
	if (this->requiredGradeToExecute < executor.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm(name=" << f.getName()
	   << "; signed=" << (f.getIsSigned() ? "true" : "false")
	   << "; requiredGrades{'sign': " << f.getRequiredGradeToSign()
	   << ", 'execute': " << f.getRequiredGradeToExecute() << "})";
	return os;
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}
