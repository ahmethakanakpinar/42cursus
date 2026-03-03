#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name
                  << " can't attack because it is dead!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name
                  << " can't attack because it has no energy points left!" << std::endl;
        return;
    }

    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name
              << " has entered in Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " is destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;

    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}