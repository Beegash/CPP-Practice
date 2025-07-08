#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	srand(time(0));
	std::cout << "\n=== FORM TYPES TESTS ===\n"
			  << std::endl;

	try
	{
		Bureaucrat president("President", 1);
		Bureaucrat manager("Manager", 20);
		Bureaucrat clerk("Clerk", 137);

		// Shrubberry Form Tests
		std::cout << "\n--- Shrubbery Creation Form Tests ---\n"
				  << std::endl;
		ShrubberyCreationForm shrub("garden");
		std::cout << shrub << std::endl;

		clerk.signForm(shrub);	  // Should be able to sign
		clerk.executeForm(shrub); // Should be able to execute

		// Robotomy Form Tests
		std::cout << "\n--- Robotomy Request Form Tests ---\n"
				  << std::endl;
		RobotomyRequestForm robot("Robot-X");
		std::cout << robot << std::endl;

		manager.signForm(robot);	  // Should be able to sign
		manager.executeForm(robot);	  // Should be able to execute
		president.executeForm(robot); // Test multiple times

		// Presidential Pardon Tests
		std::cout << "\n--- Presidential Pardon Form Tests ---\n"
				  << std::endl;
		PresidentialPardonForm pardon("Criminal");
		std::cout << pardon << std::endl;

		manager.signForm(pardon);	 // Should fail (grade too low)
		manager.executeForm(pardon); // Should fail (not signed)

		president.signForm(pardon);	   // Should succeed
		president.executeForm(pardon); // Should succeed

		// Unsigned form execution test
		std::cout << "\n--- Unsigned Form Execution Test ---\n"
				  << std::endl;
		ShrubberyCreationForm unsigned_form("test");
		president.executeForm(unsigned_form); // Should fail (not signed)

		// Insufficient grade execution test
		std::cout << "\n--- Insufficient Grade Execution Test ---\n"
				  << std::endl;
		ShrubberyCreationForm signed_form("test2");
		president.signForm(signed_form);
		clerk.executeForm(signed_form); // Should fail (grade too low)
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
