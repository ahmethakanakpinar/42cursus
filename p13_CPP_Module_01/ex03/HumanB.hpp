#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
  public:
	HumanB(const std::string &name);
	void setWeapon(Weapon &weapon);
	void attack() const;

  private:
	std::string _name;
	Weapon *_weapon;
};

#endif