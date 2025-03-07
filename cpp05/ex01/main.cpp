#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFormConstruction()
{
	std::cout << "\n=== Form Construction Tests ===" << std::endl;
	try
	{
		std::cout << "Testing valid grades:" << std::endl;
		Form f1("Contract", 75, 50);
		std::cout << f1 << std::endl;

		std::cout << "\nTesting too high grade:" << std::endl;
		Form f2("Invalid", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTesting too low grade:" << std::endl;
		Form f3("Invalid", 75, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testFormSigning()
{
	std::cout << "\n=== Form Signing Tests ===" << std::endl;
	try
	{
		Bureaucrat high("High", 1);
		Bureaucrat low("Low", 150);
		Form form("Important", 50, 25);

		std::cout << form << std::endl;
		
		std::cout << "\nTrying to sign with low grade bureaucrat:" << std::endl;
		low.signForm(form);
		
		std::cout << "\nTrying to sign with high grade bureaucrat:" << std::endl;
		high.signForm(form);
		
		std::cout << "\nForm status after signing:" << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

int main()
{
	testFormConstruction();
	testFormSigning();

	return 0;
}
