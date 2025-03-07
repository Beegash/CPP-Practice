#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== INTERN TESTS ===\n" << std::endl;
	
	try
	{
		Intern someRandomIntern;
		Bureaucrat president("President", 1);
		
		// Test all form types
		std::cout << "\n--- Shrubbery Form Creation ---\n" << std::endl;
		AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
		if (form1)
		{
			std::cout << *form1 << std::endl;
			president.signForm(*form1);
			president.executeForm(*form1);
			delete form1;
		}
		
		std::cout << "\n--- Robotomy Form Creation ---\n" << std::endl;
		AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form2)
		{
			std::cout << *form2 << std::endl;
			president.signForm(*form2);
			president.executeForm(*form2);
			delete form2;
		}
		
		std::cout << "\n--- Presidential Pardon Form Creation ---\n" << std::endl;
		AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
		if (form3)
		{
			std::cout << *form3 << std::endl;
			president.signForm(*form3);
			president.executeForm(*form3);
			delete form3;
		}
		
		// Invalid form type test
		std::cout << "\n--- Invalid Form Type Test ---\n" << std::endl;
		AForm* invalid_form = someRandomIntern.makeForm("invalid form", "Test");
		if (invalid_form)
		{
			delete invalid_form;
		}
		
		// Nullptr test for memory leak check
		std::cout << "\n--- Nullptr Form Test ---\n" << std::endl;
		AForm* null_form = someRandomIntern.makeForm("", "");
		if (null_form)
		{
			delete null_form;
		}
		
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
