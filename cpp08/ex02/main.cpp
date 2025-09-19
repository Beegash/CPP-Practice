#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "=== MutantStack test ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n=== std::list comparison test ===" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\n=== Additional tests ===" << std::endl;
	
	// Test copy constructor
	MutantStack<int> mstack2(mstack);
	std::cout << "Copy size: " << mstack2.size() << std::endl;
	std::cout << "Copy top: " << mstack2.top() << std::endl;

	// Test assignment operator
	MutantStack<int> mstack3;
	mstack3 = mstack;
	std::cout << "Assignment size: " << mstack3.size() << std::endl;
	std::cout << "Assignment top: " << mstack3.top() << std::endl;

	// Test with different types
	std::cout << "\n=== String MutantStack test ===" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");

	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Test reverse iterators
	std::cout << "\n=== Reverse iterator test ===" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;

	return 0;
} 
