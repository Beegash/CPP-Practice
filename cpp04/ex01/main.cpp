#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animals[4];

	for (int i = 0; i < 2; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = 2; i < 4; ++i)
	{
		animals[i] = new Cat();
	}

	for (int i = 0; i < 4; ++i)
	{
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; ++i)
	{
		delete animals[i];
	}

	Dog basic;
	basic.setIdea(0, "I love bones!");
	Dog copyDog = basic;
	std::cout << "Copied Dog's first idea: " << copyDog.getIdea(0) << std::endl;

	return 0;
}
