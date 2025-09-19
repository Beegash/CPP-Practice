#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	// Original test from the subject
	std::cout << "=== Original test ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Test with exceptions
	std::cout << "\n=== Exception tests ===" << std::endl;
	try {
		sp.addNumber(42); // Should throw FullException
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	Span emptySpan(10);
	try {
		emptySpan.shortestSpan(); // Should throw NoSpanException
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	Span singleSpan(10);
	singleSpan.addNumber(42);
	try {
		singleSpan.longestSpan(); // Should throw NoSpanException
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Test with large number of elements
	std::cout << "\n=== Large test (10,000 numbers) ===" << std::endl;
	Span largeSpan(10000);

	// Fill with range of iterators - Realistic random test
	std::vector<int> numbers;
	std::srand(std::time(NULL));
	for (int i = 0; i < 10000; ++i) {
		// Use larger range to minimize collisions
		numbers.push_back(std::rand() % 1000000000);  // 1 billion range
	}

	try {
		largeSpan.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Added 10,000 numbers successfully" << std::endl;
		std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test copy constructor and assignment operator
	std::cout << "\n=== Copy tests ===" << std::endl;
	Span sp2(sp);
	std::cout << "Copy - Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Copy - Longest span: " << sp2.longestSpan() << std::endl;

	Span sp3(10);
	sp3 = sp;
	std::cout << "Assignment - Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Assignment - Longest span: " << sp3.longestSpan() << std::endl;

	return 0;
} 
