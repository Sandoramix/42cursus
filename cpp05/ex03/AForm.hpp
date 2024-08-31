#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <iostream>

class AForm;

#include "Bureaucrat.hpp"

class AForm
{
public:
	static const int BEST_GRADE = 1;
	static const int WORST_GRADE = 150;

private:
	static void validateRequiredGradeFieldOrThrow(int grade, const std::string &errorMsg);

	const std::string name;
	const int requiredGradeToSign;
	const int requiredGradeToExecute;

	bool isSigned;

public:
	AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute);

	AForm(const AForm &f);

	virtual ~AForm();

	AForm &operator=(const AForm &f);

	virtual void beSigned(const Bureaucrat &b);

	std::string getName() const;

	int getRequiredGradeToSign() const;

	int getRequiredGradeToExecute() const;

	bool getIsSigned() const;

	void setIsSigned(bool isSigned);

	virtual void execute(const Bureaucrat &executor) const = 0;

	void validateRequiredGradeToExecuteOrThrow(const Bureaucrat &executor) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);


#endif //AFORM_HPP
