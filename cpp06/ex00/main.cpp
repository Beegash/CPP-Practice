#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
		std::cout << std::endl;
		std::cout << "Example tests:" << std::endl;
		std::cout << "=============" << std::endl;


		std::cout << "--- CHAR LITERALS ---" << std::endl;
		ScalarConverter::convert("'a'");
		std::cout << std::endl;
		ScalarConverter::convert("'*'");
		std::cout << std::endl;
		ScalarConverter::convert("'0'");
		std::cout << std::endl;
		ScalarConverter::convert("' '"); // space
		std::cout << std::endl;

		std::cout << "--- INT LITERALS ---" << std::endl;
		ScalarConverter::convert("0");
		std::cout << std::endl;
		ScalarConverter::convert("42");
		std::cout << std::endl;
		ScalarConverter::convert("-42");
		std::cout << std::endl;
		ScalarConverter::convert("2147483647"); // INT_MAX
		std::cout << std::endl;
		ScalarConverter::convert("-2147483648"); // INT_MIN
		std::cout << std::endl;
		ScalarConverter::convert("2147483648"); // INT_MAX + 1 (overflow)
		std::cout << std::endl;

		std::cout << "--- FLOAT LITERALS ---" << std::endl;
		ScalarConverter::convert("42.0f");
		std::cout << std::endl;
		ScalarConverter::convert("-42.5f");
		std::cout << std::endl;
		ScalarConverter::convert("0.0f");
		std::cout << std::endl;
		ScalarConverter::convert("3.14159f");
		std::cout << std::endl;
		ScalarConverter::convert("999999999999999999999999999999999999999.0f"); // büyük sayı
		std::cout << std::endl;

		std::cout << "--- DOUBLE LITERALS ---" << std::endl;
		ScalarConverter::convert("42.0");
		std::cout << std::endl;
		ScalarConverter::convert("-42.5");
		std::cout << std::endl;
		ScalarConverter::convert("0.0");
		std::cout << std::endl;
		ScalarConverter::convert("3.141592653589793");
		std::cout << std::endl;

		std::cout << "--- SPECIAL VALUES ---" << std::endl;
		ScalarConverter::convert("nan");
		std::cout << std::endl;
		ScalarConverter::convert("nanf");
		std::cout << std::endl;
		ScalarConverter::convert("+inf");
		std::cout << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << std::endl;
		ScalarConverter::convert("+inff");
		std::cout << std::endl;
		ScalarConverter::convert("-inff");
		std::cout << std::endl;

		std::cout << "--- EDGE CASES ---" << std::endl;
		ScalarConverter::convert("300"); // char range dışı ama int içinde
		std::cout << std::endl;
		ScalarConverter::convert("128"); // char max + 1
		std::cout << std::endl;
		ScalarConverter::convert("-129"); // char min - 1
		std::cout << std::endl;
		ScalarConverter::convert("1.23300000000000001"); // precision test
		std::cout << std::endl;
		
		std::cout << "--- INVALID INPUTS ---" << std::endl;
		ScalarConverter::convert("invalid");
		std::cout << std::endl;
		ScalarConverter::convert("42.5.5");
		std::cout << std::endl;
		ScalarConverter::convert("abc123");
		std::cout << std::endl;
		ScalarConverter::convert("''");
		std::cout << std::endl;
		ScalarConverter::convert("'ab'");
		return 0;
	}

	ScalarConverter::convert(argv[1]);
	return 0;
}
