#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Alice", 50);
		Bureaucrat b2("Bob", 100);

		Form f1("Tax Form", 75, 50);
		Form f2("Passport Application", 25, 10);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		b1.signForm(f1);
		b2.signForm(f1);
		b1.signForm(f2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
