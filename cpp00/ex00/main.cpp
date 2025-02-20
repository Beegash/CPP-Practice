#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = newZombie("Zombozo");
    zombie1->announce();
    randomChump("tempZombie");

    delete zombie1;
    return 0;
}
