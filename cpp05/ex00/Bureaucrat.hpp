#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
	static const int BEST_GRADE = 1;
	static const int WORST_GRADE = 150;
private:
	const std::string name;
	int grade;

	static void validateGradeOrThrow(int grade);
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &b);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &b);

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException: public std::exception{
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception{
		virtual const char *what() const throw();
	};

};

std::ostream  &operator<<(std::ostream &os, const Bureaucrat &b);

#endif //BUREAUCRAT_HPP
