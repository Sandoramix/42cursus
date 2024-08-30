#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(const std::string target);

	PresidentialPardonForm(const PresidentialPardonForm &s);

	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &s);

	void execute(const Bureaucrat &b) const;

	const std::string &getTarget() const;

	void setTarget(const std::string &target);
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &p);

#endif //PRESIDENTIALPARDONFORM_HPP
