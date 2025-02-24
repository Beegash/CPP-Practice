#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;

public:
	RobotomyRequestForm(const std::string &target);
	void execute(const Bureaucrat &executor) const;
};

#endif
