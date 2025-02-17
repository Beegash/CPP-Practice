#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap Copy constructor called for " << this->name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap Copy assignment operator called for " << this->name << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destroyed!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
