#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name) : _name(name)
{
	std::cout << "Zombie " << _name << " is created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " is destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}