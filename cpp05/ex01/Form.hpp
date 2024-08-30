#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form;

#include <Bureaucrat.hpp>

class Form
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
	Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute);

	Form(const Form &f);

	~Form();

	Form &operator=(const Form &f);

	void beSigned(const Bureaucrat &b);

	std::string getName() const;

	int getRequiredGradeToSign() const;

	int getRequiredGradeToExecute() const;

	bool getIsSigned() const;

	void setIsSigned(bool isSigned);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &f);


#endif //FORM_HPP
