#include "Bureaucrat.hpp"
#include <iostream>
#include <typeinfo>

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cerr << "[DBG-LOG]\t[" << typeid(*this).name() << "][Constructor]\t\t\tname=" << name << "\tgrade=" << grade
			  << std::endl;
	validateGradeOrThrow(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(WORST_GRADE)
{
	std::cerr << "[DBG-LOG]\t[" << typeid(*this).name() << "][CopyConstructor]\t\t\tname=" << b.name << "\tgrade="
			  << b.grade << std::endl;
	validateGradeOrThrow(b.grade);
	this->grade = b.grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cerr << "[DBG-LOG]\t[" << typeid(*this).name() << "][Destructor]\t\t\tname=" << name
			  << "\tgrade=" << grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this == &b)
	{
		return (*this);
	}
	validateGradeOrThrow(b.grade);
	this->grade = b.grade;
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	validateGradeOrThrow(this->grade - 1);
	this->grade--;
}

void Bureaucrat::decrementGrade()
{

	validateGradeOrThrow(this->grade + 1);
	this->grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signed " << f << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't sign " << f.getName() << " because " << e.what() << "\n";
	}
}

void Bureaucrat::validateGradeOrThrow(int grade)
{
	if (grade > WORST_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < BEST_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << "\n";
	} catch (std::exception &e)
	{
		std::cerr << *this << " could not execute " << form << ".\n\tException raised: " << e.what() << "\n";
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
