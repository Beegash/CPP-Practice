#include "Bureaucrat.hpp"

void testConstructor()
{
	std::cout << "\n=== Constructor Tests ===" << std::endl;
	try
	{
		std::cout << "Testing valid grade (75):" << std::endl;
		Bureaucrat b1("Normal", 75);
		std::cout << b1 << std::endl;

		std::cout << "\nTesting too high grade (0):" << std::endl;
		Bureaucrat b2("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTesting too low grade (151):" << std::endl;
		Bureaucrat b3("TooLow", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testGradeModification()
{
	std::cout << "\n=== Grade Modification Tests ===" << std::endl;
	try
	{

		std::cout << "Testing increment at grade 1:" << std::endl;
		Bureaucrat b1("HighGrade", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{

		std::cout << "\nTesting decrement at grade 150:" << std::endl;
		Bureaucrat b2("LowGrade", 150);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{

		std::cout << "\nTesting normal grade modifications:" << std::endl;
		Bureaucrat b3("Normal", 75);
		std::cout << "Initial: " << b3 << std::endl;

		b3.incrementGrade();
		std::cout << "After increment: " << b3 << std::endl;

		b3.decrementGrade();
		std::cout << "After decrement: " << b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testCopyAndAssignment()
{
	std::cout << "\n=== Copy and Assignment Tests ===" << std::endl;
	try
	{

		Bureaucrat b1("Original", 42);
		Bureaucrat b2(b1);
		std::cout << "Original: " << b1 << std::endl;
		std::cout << "Copy: " << b2 << std::endl;

		Bureaucrat b3("ToBeAssigned", 100);
		b3 = b1;
		std::cout << "After assignment: " << b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

int main()
{
	testConstructor();
	testGradeModification();
	testCopyAndAssignment();

	return 0;
}
