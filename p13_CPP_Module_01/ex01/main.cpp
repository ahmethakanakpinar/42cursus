#include "Zombie.hpp"
#include <iostream>

int main()
{
    int count = 10;
    Zombie* zombies = zombieHorde(count, "Zombie");
    for(int i = 0; i < count; i++)
    {
        zombies[i].announce();
    }

    delete[] zombies;
    return 0;
}