#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}

	int random = std::rand() % 3;

	switch (random)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return new A();
	}
}

void identify(Base *ptr)
{
	if (dynamic_cast<A *>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "C" << std::endl;
}

void identify(Base &ptr)
{
	try
	{
		(void)dynamic_cast<A &>(ptr);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(ptr);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(ptr);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}
}
