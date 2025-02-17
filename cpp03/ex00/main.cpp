#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Clapclap");

	clap.attack("Enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.attack("Another Enemy");

	return 0;
}
