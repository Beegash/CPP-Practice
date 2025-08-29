#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	std::cout << "Testing identify functions:" << std::endl;
	std::cout << "==========================" << std::endl;

	int countA = 0, countB = 0, countC = 0;

	for (int i = 0; i < 10; ++i)
	{
		Base *ptr = generate();

		std::cout << "Test " << (i + 1) << ":" << std::endl;
		std::cout << "Pointer identification: ";
		identify(ptr);
		std::cout << "Reference identification: ";
		identify(*ptr);
		std::cout << std::endl;

		if (dynamic_cast<A *>(ptr))
			countA++;
		else if (dynamic_cast<B *>(ptr))
			countB++;
		else if (dynamic_cast<C *>(ptr))
			countC++;

		delete ptr;
	}

	std::cout << "Distribution check:" << std::endl;
	std::cout << "A: " << countA << ", B: " << countB << ", C: " << countC << std::endl;
	std::cout << std::endl;

	std::cout << "Null pointer test:" << std::endl;
	std::cout << "Pointer identification (null): ";
	identify(nullptr);
	std::cout << std::endl;

	return 0;
}
