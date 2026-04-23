#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main(void)
{
	// --- Subject test ---
	std::cout << "=== MutantStack ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5); // push value on top of stack
	mstack.push(17); // push value on top of stack
	std::cout << mstack.top() << std::endl; // read top value
	mstack.pop(); // remove top value
	std::cout << mstack.size() << std::endl; // get number of elements
	mstack.push(3); // push value on top of stack
	mstack.push(5); // push value on top of stack
	mstack.push(737); // push value on top of stack
	mstack.push(0); // push value on top of stack

	MutantStack<int>::iterator it = mstack.begin(); // iterator to first element
	MutantStack<int>::iterator ite = mstack.end(); // iterator to one past last element
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack); // build normal stack from mutant stack

	// --- Same test with std::list ---
	std::cout << "\n=== std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(5); // add value to end of list
	lst.push_back(17); // add value to end of list
	std::cout << lst.back() << std::endl; // read last value
	lst.pop_back(); // remove last value
	std::cout << lst.size() << std::endl; // get number of elements
	lst.push_back(3); // add value to end of list
	lst.push_back(5); // add value to end of list
	lst.push_back(737); // add value to end of list
	lst.push_back(0); // add value to end of list

	std::list<int>::iterator lit = lst.begin(); // iterator to first list element
	std::list<int>::iterator lite = lst.end(); // iterator to one past last list element
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	// --- Reverse iterator test ---
	std::cout << "\n=== Reverse iterator ===" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin(); // reverse iterator to last element
	MutantStack<int>::reverse_iterator rite = mstack.rend(); // reverse iterator to before first element
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	// --- Copy test ---
	std::cout << "\n=== Copy test ===" << std::endl;
	MutantStack<int> copy(mstack); // copy all elements from mstack
	std::cout << "Copy size: " << copy.size() << std::endl; // show copied stack size
	std::cout << "Copy top: " << copy.top() << std::endl; // show copied stack top value

	return 0;
}
