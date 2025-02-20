#include "Zombie.hpp"

int main()
{
    int n = 0;
    Zombie *horde = zombieHorde(n, "HordeZombie");

    if (horde)
    {
        for (int i = 0; i < n; i++)
        {
            horde[i].announce();
        }
        delete[] horde;
    }

    return 0;
}
