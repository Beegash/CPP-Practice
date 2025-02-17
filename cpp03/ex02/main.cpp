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

    return 0;
}
