#include "Zombie.hpp"
#include <iostream>

int main()
{
    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    std::cout << std::endl;
    std::cout << std::endl;

    
    randomChump("Stack");
    std::cout << std::endl;
    std::cout << std::endl;

    delete heapZombie;
    return 0;
}