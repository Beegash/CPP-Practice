#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
	unsigned int maxSize;
	std::vector<int> numbers;

public:
	// Orthodox Canonical Form
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	// Member functions
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	// Range of iterators function
	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end);

	// Exception classes
	class FullException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; ++it)
	{
		if (numbers.size() >= maxSize)
			throw FullException();
		numbers.push_back(*it);
	}
}

#endif 
