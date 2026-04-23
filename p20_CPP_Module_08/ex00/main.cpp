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
		vec.push_back(i * 3); // add a value to the end of the vector

	std::cout << "=== vector ===" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 9); // find value 9 and return its position
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(vec, 42); // try to find 42 (will throw if not found)
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// --- list test ---
	std::list<int> lst;
	lst.push_back(1); // add 1 to the end of the list
	lst.push_back(7); // add 7 to the end of the list
	lst.push_back(42); // add 42 to the end of the list

	std::cout << "\n=== list ===" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(lst, 42); // find value 42 in the list
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// --- deque test ---
	std::deque<int> deq;
	deq.push_back(10); // add 10 to the end of the deque
	deq.push_back(20); // add 20 to the end of the deque
	deq.push_back(30); // add 30 to the end of the deque

	std::cout << "\n=== deque ===" << std::endl;
	try
	{
		std::deque<int>::iterator it = easyfind(deq, 20); // find value 20 in the deque
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(deq, 99); // try to find 99 (will throw if not found)
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}