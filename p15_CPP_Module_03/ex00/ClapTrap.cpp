#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}
void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " can't attack because it is dead!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " can't attack because it has no energy points left!" << std::endl;
        return;
    }

    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage 
              << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " is already dead!" << std::endl;
        return;
    }
    if (amount >= this->_hitPoints)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;

    std::cout << "ClapTrap " << this->_name << " takes " 
              << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " can't be repaired because it is dead!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " can't be repaired because it has no energy points left!" << std::endl;
        return;
    }

    this->_energyPoints--;
    this->_hitPoints += amount;

    std::cout << "ClapTrap " << this->_name << " has been repaired for " 
              << amount << " hit points!" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;

    if (this != &other)
    {
        this->_name         = other._name;
        this->_hitPoints    = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }

    return *this;
}