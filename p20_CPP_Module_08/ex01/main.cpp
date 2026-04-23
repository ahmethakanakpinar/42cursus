#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void)
{
	// --- Subject test ---
	std::cout << "=== Subject test ===" << std::endl;
	Span sp = Span(5); // create a Span that can hold 5 numbers
	sp.addNumber(6); // add one number to Span
	sp.addNumber(3); // add one number to Span
	sp.addNumber(17); // add one number to Span
	sp.addNumber(9); // add one number to Span
	sp.addNumber(11); // add one number to Span
	std::cout << sp.shortestSpan() << std::endl; // print smallest difference between two numbers
	std::cout << sp.longestSpan() << std::endl; // print biggest difference between two numbers

	// --- Overflow test ---
	std::cout << "\n=== Overflow test ===" << std::endl;
	try
	{
		sp.addNumber(42); // try to add when Span is full (will throw)
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
		one.addNumber(1); // add first number
		one.shortestSpan(); // need at least 2 numbers (will throw)
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// --- Range addNumber with 10000 elements ---
	std::cout << "\n=== 10000 elements ===" << std::endl;
	srand(time(NULL)); // seed random generator with current time
	std::vector<int> big(10000);
	for (size_t i = 0; i < big.size(); i++)
		big[i] = rand(); // generate random value
	Span bigSpan(10000);
	bigSpan.addNumber(big.begin(), big.end()); // add all values from vector range
	std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl; // show shortest span
	std::cout << "Longest:  " << bigSpan.longestSpan() << std::endl; // show longest span

	return 0;
}