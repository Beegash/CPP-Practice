#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw GradeTooLowException();

	std::ofstream file(target + "_shrubbery");
	file << "      /\\" << std::endl;
	file << "     /\\*\\" << std::endl;
	file << "    /\\O\\*\\" << std::endl;
	file.close();
}
