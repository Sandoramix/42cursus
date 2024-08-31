#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm(const std::string target);

	ShrubberyCreationForm(const ShrubberyCreationForm &s);

	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &s);

	void execute(const Bureaucrat &b) const;

	const std::string &getTarget() const;

	void setTarget(const std::string &target);
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &p);

#endif //SHRUBBERYCREATIONFORM_HPP
