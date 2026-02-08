#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("")
{
	std::cout << "Zombie empty created." << std::endl;
}

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

void Zombie::setName(const std::string& name)
{
	_name = name;
}