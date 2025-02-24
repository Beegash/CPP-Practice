#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat alice("Alice", 50);
		ShrubberyCreationForm shrubForm("Garden");
		RobotomyRequestForm roboForm("Target");
		PresidentialPardonForm pardonForm("John Doe");

		std::cout << bob << std::endl;
		std::cout << alice << std::endl;

		bob.signForm(shrubForm);
		bob.executeForm(shrubForm);

		alice.signForm(roboForm);
		alice.executeForm(roboForm);

		bob.signForm(pardonForm);
		bob.executeForm(pardonForm);

		alice.signForm(pardonForm);
		alice.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
