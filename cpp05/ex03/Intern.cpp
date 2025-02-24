#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formTypes[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			for (int j = 0; j < 3; j++)
			{
				if (i != j)
					delete forms[j]; 
			}
			return forms[i];
		}
	}

	std::cout << "Error: Unknown form name '" << formName << "'" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		delete forms[i]; 
	}
	return NULL;
}
