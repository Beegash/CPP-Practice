#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap Copy constructor called for " << this->name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap Copy assignment operator called for " << this->name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target
				  << ", dealing " << attackDamage << " amount of damage!" << std::endl;
		energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << name << " has no energy or hit points left to attack!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}
