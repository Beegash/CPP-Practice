#include "Span.hpp"

// Constructors and destructor
Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxSize = other.maxSize;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span() {}

// Member functions
void Span::addNumber(int number)
{
	if (numbers.size() >= maxSize)
		throw FullException();
	numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (numbers.size() <= 1)
		throw NoSpanException();

	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (numbers.size() <= 1)
		throw NoSpanException();

	std::vector<int>::const_iterator min = std::min_element(numbers.begin(), numbers.end());
	std::vector<int>::const_iterator max = std::max_element(numbers.begin(), numbers.end());

	return static_cast<unsigned int>(*max - *min);
}

// Exception implementations
const char* Span::FullException::what() const throw()
{
	return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw()
{
	return "No span can be found with less than 2 numbers";
} 
