#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap robot("ClapclapV2");
    ScavTrap scav("ScavScav");

    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    std::cout << std::endl;
    scav.attack("Another Enemy");
    scav.guardGate();
    scav.takeDamage(20);
    scav.beRepaired(10);

    return 0;
}
