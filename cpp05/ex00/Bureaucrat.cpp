#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
	std::cout << "[Bureaucrat][Constructor]\tname=" << name << "\tgrade=" << grade << "\n";
	validateGradeOrThrow(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &b): name(b.name), grade(WORST_GRADE)
{
	std::cout << "[Bureaucrat][CopyConstructor]\tname=" << b.name << "\tgrade=" << b.grade << "\n";
	validateGradeOrThrow(b.grade);
	this->grade = b.grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat][Destructor]\tname=" << name << "\tgrade=" << grade << "\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this == &b){
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

void Bureaucrat::validateGradeOrThrow(int grade)
{
	if (grade > WORST_GRADE){
		throw Bureaucrat::GradeTooLowException();
	} else if (grade < BEST_GRADE){
		throw Bureaucrat::GradeTooHighException();
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

std::ostream  &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << "name=" << b.getName() << "; grade=" << b.getGrade();
	return os;
}
