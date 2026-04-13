#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "=== int array ===" << std::endl;
	iter(intArr, 5, print<int>);

	std::string strArr[] = {"ahmet", "hakan", "42"};
	std::cout << "=== string array ===" << std::endl;
	iter(strArr, 3, print<std::string>);

	double dblArr[] = {1.1, 2.2, 3.3};
	std::cout << "=== double array ===" << std::endl;
	iter(dblArr, 3, print<double>);

	return 0;
}
