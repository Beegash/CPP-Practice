#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Constructing Objects ===" << std::endl;
    const Animal* meta = new Animal();
    const Dog* j = new Dog();
    const Cat* i = new Cat();
    
    std::cout << "\n=== Testing getType() ===" << std::endl;
    std::cout << "Dog Type: " << j->getType() << std::endl;
    std::cout << "Cat Type: " << i->getType() << std::endl;
    
    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    i->makeSound(); 
    j->makeSound(); 
    meta->makeSound(); 

    std::cout << "\n=== Copy Constructor & Assignment Test ===" << std::endl;
    Cat copyCat(*i);
    copyCat.makeSound();

    Dog copyDog;
    copyDog = *j;
    copyDog.makeSound();

    std::cout << "\n=== Testing WrongAnimal ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongCat* wrongCat = new WrongCat();
	const WrongAnimal *a= new WrongCat();
    
    std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;
    wrongMeta->makeSound(); 
	a->makeSound();
    wrongCat->makeSound(); 

    std::cout << "\n=== Cleaning Up ===" << std::endl;
    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;
	delete a;

    return 0;
}
