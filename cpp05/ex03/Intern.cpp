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

AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	struct FormType {
		const char* name;
		AForm* (*creator)(const std::string&);
	};
	static const FormType formTable[] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential}
	};
	for (size_t i = 0; i < sizeof(formTable)/sizeof(*formTable); ++i) {
		if (formName == formTable[i].name) {
			std::cout << "Intern creates " << formName << std::endl;
			return formTable[i].creator(target);
		}
	}
	std::cout << "Error: Unknown form name '" << formName << "'" << std::endl;
	return NULL;
}
