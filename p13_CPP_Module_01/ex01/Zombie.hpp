#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
  public:
	Zombie();
	Zombie(const std::string& name);
	~Zombie();
	void announce(void);
	void setName(const std::string& name);

  private:
	std::string _name;
};

Zombie* zombieHorde(int N, const std::string& name);

#endif