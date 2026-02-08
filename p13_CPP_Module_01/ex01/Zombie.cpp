#include "Zombie.hpp"

Zombie::Zombie()
{
    this->_name = "";
    std::cout << "Zombie empty created." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " is created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " is destroyed." << std::endl;
}
void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name)
{
    this->_name = name;
}