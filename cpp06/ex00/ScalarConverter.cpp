#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string &str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

static bool isIntLiteral(const std::string &str)
{
	if (str.empty())
		return false;
	size_t i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	if (i == str.size())
		return false;
	for (; i < str.size(); ++i)
		if (!isdigit(str[i]))
			return false;
	return true;
}

static bool isFloatLiteral(const std::string &str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;
	if (str.empty() || str[str.length() - 1] != 'f')
		return false;
	std::string fless = str.substr(0, str.length() - 1);
	if (fless == "nan" || fless == "+inf" || fless == "-inf")
		return true;
	std::istringstream iss(fless);
	float f;
	char ch;
	return (iss >> f) && !(iss >> ch);
}

static bool isDoubleLiteral(const std::string &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
	std::istringstream iss(str);
	double d;
	char ch;
	return (iss >> d) && !(iss >> ch);
}

static bool isDisplayableChar(int ch)
{
	return ch >= 32 && ch <= 126;
}

static void printConvert(const std::string &charVal, const std::string &intVal, const std::string &floatVal, const std::string &doubleVal)
{
	std::cout << "char: " << charVal << "\n";
	std::cout << "int: " << intVal << "\n";
	std::cout << "float: " << floatVal << "\n";
	std::cout << "double: " << doubleVal << "\n";
}

static void printConvert(char charVal, int intVal, float floatVal, double doubleVal)
{
	if (std::isnan(floatVal) || floatVal < std::numeric_limits<char>::min() || floatVal > std::numeric_limits<char>::max())
		std::cout << "char: impossible\n";
	else if (isDisplayableChar(intVal))
		std::cout << "char: '" << charVal << "'\n";
	else if (intVal >= 0 && intVal <= 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: impossible\n";

	if (std::isnan(floatVal) || floatVal < std::numeric_limits<int>::min() || floatVal > std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << intVal << "\n";

	std::cout << "float: " << floatVal << "f\n";
	std::cout << "double: " << doubleVal << "\n";
}

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << std::fixed << std::setprecision(1);

	if (isCharLiteral(literal))
	{
		char ch = literal[1];
		printConvert(ch, static_cast<int>(ch), static_cast<float>(ch), static_cast<double>(ch));
		return;
	}

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		printConvert("impossible", "impossible", literal, literal.substr(0, literal.size() - 1));
		return;
	}

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		printConvert("impossible", "impossible", literal + "f", literal);
		return;
	}

	if (isIntLiteral(literal))
	{
		long lval = std::strtol(literal.c_str(), NULL, 10);
		if (lval < std::numeric_limits<int>::min() || lval > std::numeric_limits<int>::max())
		{
			printConvert("impossible", "impossible", "impossible", "impossible");
			return;
		}
		int ival = static_cast<int>(lval);
		printConvert(static_cast<char>(ival), ival, static_cast<float>(ival), static_cast<double>(ival));
		return;
	}

	if (isFloatLiteral(literal))
	{
		float fval = std::strtof(literal.c_str(), NULL);
		printConvert(static_cast<char>(fval), static_cast<int>(fval), fval, static_cast<double>(fval));
		return;
	}

	if (isDoubleLiteral(literal))
	{
		double dval = std::strtod(literal.c_str(), NULL);
		printConvert(static_cast<char>(dval), static_cast<int>(dval), static_cast<float>(dval), dval);
		return;
	}
	printConvert("impossible", "impossible", "impossible", "impossible");
	return;
}
