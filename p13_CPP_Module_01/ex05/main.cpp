#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl harl;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		std::cout << "[ " << levels[i] << " ]" << std::endl;
		harl.complain(levels[i]);
		std::cout << std::endl;
	}
	std::cout << "[ INVALID ]" << std::endl;
	harl.complain("INVALID");

	return (0);
}
