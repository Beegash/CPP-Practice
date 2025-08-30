#include <iostream>
#include <string>
#include "iter.hpp"

// Yazdırma fonksiyonları
template <typename T>
void printElement(T const &element)
{
	std::cout << element << " ";
}

template <typename T>
void printWithIndex(T const &element)
{
	static int index = 0;
	std::cout << "[" << index++ << "]:" << element << " ";
}

// Matematik işlemleri
template <typename T>
void multiplyByTwo(T &element)
{
	element *= 2;
}

template <typename T>
void addOne(T &element)
{
	element += 1;
}

template <typename T>
void subtractOne(T &element)
{
	element -= 1;
}

template <typename T>
void divideByTwo(T &element)
{
	element /= 2;
}

template <typename T>
void makeNegative(T &element)
{
	element = -element;
}

template <typename T>
void multiplyByThree(T &element)
{
	element *= 3;
}

// String işlemleri
void toUpperCase(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
}

void addExclamation(std::string &str)
{
	str += "!";
}

// Const veriler için sadece okuma fonksiyonları
template <typename T>
void printSquare(T const &element)
{
	std::cout << element * element << " ";
}

template <typename T>
void printDouble(T const &element)
{
	std::cout << element * 2 << " ";
}

void printUpperCase(std::string const &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (c >= 'a' && c <= 'z')
			c = c - 32;
		std::cout << c;
	}
	std::cout << " ";
}

// Yardımcı fonksiyon
void printSeparator(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main()
{
	printSeparator("INT ARRAY TESTS");
	
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	iter(intArray, 5, addOne<int>);
	std::cout << "After adding 1: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	iter(intArray, 5, multiplyByTwo<int>);
	std::cout << "After multiplying by 2: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	iter(intArray, 5, subtractOne<int>);
	std::cout << "After subtracting 1: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	iter(intArray, 5, makeNegative<int>);
	std::cout << "After making negative: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	printSeparator("DOUBLE ARRAY TESTS");
	
	double doubleArray[] = {1.5, 2.5, 3.5, 4.5, 5.5};
	std::cout << "Original double array: ";
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

	iter(doubleArray, 5, multiplyByTwo<double>);
	std::cout << "After multiplying by 2: ";
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

	iter(doubleArray, 5, divideByTwo<double>);
	std::cout << "After dividing by 2: ";
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

	printSeparator("STRING ARRAY TESTS");
	
	std::string stringArray[] = {"hello", "world", "cpp", "templates"};
	std::cout << "Original string array: ";
	iter(stringArray, 4, printElement<std::string>);
	std::cout << std::endl;

	iter(stringArray, 4, toUpperCase);
	std::cout << "After converting to uppercase: ";
	iter(stringArray, 4, printElement<std::string>);
	std::cout << std::endl;

	iter(stringArray, 4, addExclamation);
	std::cout << "After adding exclamation: ";
	iter(stringArray, 4, printElement<std::string>);
	std::cout << std::endl;

	printSeparator("CONST ARRAY TESTS");
	
	const int constIntArray[] = {10, 20, 30, 40, 50};
	std::cout << "Const int array: ";
	iter(constIntArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "Squares of const int array: ";
	iter(constIntArray, 5, printSquare<int>);
	std::cout << std::endl;

	std::cout << "Double values of const int array: ";
	iter(constIntArray, 5, printDouble<int>);
	std::cout << std::endl;

	const std::string constStringArray[] = {"const", "string", "test", "array"};
	std::cout << "Const string array: ";
	iter(constStringArray, 4, printElement<std::string>);
	std::cout << std::endl;

	std::cout << "Const string array in uppercase: ";
	iter(constStringArray, 4, printUpperCase);
	std::cout << std::endl;

	printSeparator("PRINTING WITH INDEX TEST");
	
	double testArray[] = {1.1, 2.2, 3.3};
	std::cout << "Printing with index: ";
	iter(testArray, 3, printWithIndex<double>);
	std::cout << std::endl;

	printSeparator("ADDITIONAL MATH OPERATIONS");
	
	int extraArray[] = {1, 2, 3, 4, 5};
	std::cout << "Original array: ";
	iter(extraArray, 5, printElement<int>);
	std::cout << std::endl;
	
	iter(extraArray, 5, multiplyByThree<int>);
	std::cout << "After multiplying by 3: ";
	iter(extraArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "\nAll tests completed successfully!" << std::endl;
	return 0;
}
