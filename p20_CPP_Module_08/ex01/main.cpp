#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void)
{
	// --- Subject test ---
	std::cout << "=== Subject test ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// --- Overflow test ---
	std::cout << "\n=== Overflow test ===" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// --- Too few elements test ---
	std::cout << "\n=== Too few elements ===" << std::endl;
	try
	{
		Span one(1);
		one.addNumber(1);
		one.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// --- Range addNumber with 10000 elements ---
	std::cout << "\n=== 10000 elements ===" << std::endl;
	srand(time(NULL));
	std::vector<int> big(10000);
	for (size_t i = 0; i < big.size(); i++)
		big[i] = rand();
	Span bigSpan(10000);
	bigSpan.addNumber(big.begin(), big.end());
	std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest:  " << bigSpan.longestSpan() << std::endl;

	return 0;
}