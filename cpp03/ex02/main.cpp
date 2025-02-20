#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap robot("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag("Fraggy");

    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);

    scav.attack("Another Enemy");
    scav.guardGate();
    scav.takeDamage(20);
    scav.beRepaired(10);

    frag.attack("Final Enemy");
    frag.highFivesGuys();
    frag.takeDamage(30);
    frag.beRepaired(15);


    ClapTrap *clap1 = new ScavTrap("Scav-Clap");
    ClapTrap *clap2 = new FragTrap("Frag-Clap");


    clap1->attack("Enemy A");
    clap2->attack("Enemy B");

    clap1->takeDamage(10);
    clap2->takeDamage(15);

    clap1->beRepaired(5);
    clap2->beRepaired(8);

    delete clap1;
    delete clap2;
    return 0;
}
