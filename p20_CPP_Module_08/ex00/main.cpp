#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
	// --- vector test ---
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 3);

	std::cout << "=== vector ===" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 9);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(vec, 42);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// --- list test ---
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(7);
	lst.push_back(42);

	std::cout << "\n=== list ===" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(lst, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// --- deque test ---
	std::deque<int> deq;
	deq.push_back(10);
	deq.push_back(20);
	deq.push_back(30);

	std::cout << "\n=== deque ===" << std::endl;
	try
	{
		std::deque<int>::iterator it = easyfind(deq, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(deq, 99);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}