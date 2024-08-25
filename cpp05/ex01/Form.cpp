#include "Form.hpp"

void Form::validateRequiredGradeFieldOrThrow(int grade, const std::string &errorMsg)
{
	if (grade >= BEST_GRADE && grade <= WORST_GRADE)
		return ;
	std::cerr << "\t[Form][ValidationError] validating the grade: " << errorMsg << "\n";
	if (grade < BEST_GRADE)
		throw Form::GradeTooHighException();
	throw Form::GradeTooLowException();
}

Form::Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute)
	: name(name), requiredGradeToSign(requiredGradeToSign), requiredGradeToExecute(requiredGradeToExecute), isSigned(false)
{
	std::cout << "\n[Form][Constructor] " << *this << "\n";
	validateRequiredGradeFieldOrThrow(this->requiredGradeToSign, "Signing grade is invalid");
	validateRequiredGradeFieldOrThrow(this->requiredGradeToExecute, "Execution grade is invalid");
}

Form::Form(const Form &f)
	: name(f.name), requiredGradeToSign(f.requiredGradeToSign), requiredGradeToExecute(f.requiredGradeToExecute), isSigned(false)
{
	std::cout << "\n[Form][CopyConstructor] " << *this << "\n";
	validateRequiredGradeFieldOrThrow(requiredGradeToSign, "Signing grade is invalid");
	validateRequiredGradeFieldOrThrow(requiredGradeToExecute, "Execution grade is invalid");
}

Form::~Form()
{
	std::cout << "\n[Form][Destructor] " << *this << "\n";
}

Form &Form::operator=(const Form &f)
{
	if (this == &f)
		return *this;
	this->isSigned = f.isSigned;
	return *this;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (this->requiredGradeToSign < b.getGrade())
	{
		std::cerr << "\tForm cannot be signed by {" << b << "} Required grade is " << this->requiredGradeToSign << "\n";
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
}

std::string Form::getName() const
{
	return name;
}

int Form::getRequiredGradeToSign() const
{
	return requiredGradeToSign;
}

int Form::getRequiredGradeToExecute() const
{
	return requiredGradeToExecute;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form(name=" << f.getName() << "; signed=" << ( f.getIsSigned() ? "true" : "false")
		<< "; requiredGrades{'sign': " << f.getRequiredGradeToSign() << ", 'execute': " << f.
		getRequiredGradeToExecute() << "})";
	return os;
}
