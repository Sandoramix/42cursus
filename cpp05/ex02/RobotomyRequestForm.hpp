#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(const std::string target);

	RobotomyRequestForm(const RobotomyRequestForm &s);

	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &s);

	void execute(const Bureaucrat &b) const;

	const std::string &getTarget() const;

	void setTarget(const std::string &target);
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &p);

#endif //ROBOTOMYREQUESTFORM_HPP
