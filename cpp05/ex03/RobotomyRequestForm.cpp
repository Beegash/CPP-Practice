#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw GradeTooLowException();

	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << target << " robotomy failed!" << std::endl;
}
