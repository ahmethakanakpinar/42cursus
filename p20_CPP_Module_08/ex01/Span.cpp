#include "Span.hpp"

Span::Span(void) : _maxSize(0) {}
Span::Span(unsigned int n) : _maxSize(n) {}
Span::Span(const Span &src) : _maxSize(src._maxSize), _v(src._v) {}
Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_v = rhs._v;
	}
	return *this;
}
Span::~Span(void) {}

void Span::addNumber(int num)
{
	if (_v.size() >= _maxSize)
		throw std::overflow_error("Span is full");
	_v.push_back(num);
}

int Span::shortestSpan(void) const
{
	if (_v.size() < 2)
		throw std::logic_error("Not enough elements to find a span. Min 2 Elements");
	std::vector<int> sorted(_v);
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan(void) const
{
	if (_v.size() < 2)
		throw std::logic_error("Not enough elements to find a span. Min 2 Elements");
	return *std::max_element(_v.begin(), _v.end())
		- *std::min_element(_v.begin(), _v.end());
}
