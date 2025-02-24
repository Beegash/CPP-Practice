#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm *form1 = intern.makeForm("shrubbery creation", "Home");
		AForm *form2 = intern.makeForm("robotomy request", "Bender");
		AForm *form3 = intern.makeForm("presidential pardon", "Zaphod");
		AForm *invalidForm = intern.makeForm("unknown form", "Test");

		if (form1)
		{
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}

		if (form2)
		{
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}

		if (form3)
		{
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}

		if (invalidForm)
		{
			delete invalidForm;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
