#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	// Test with vector
	std::cout << "Testing with vector:" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 100);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test with list
	std::cout << "\nTesting with list:" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 4);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(lst, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test with deque
	std::cout << "\nTesting with deque:" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 999);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
