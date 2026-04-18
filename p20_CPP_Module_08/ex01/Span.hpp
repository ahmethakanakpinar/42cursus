#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iterator>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_v;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();

		void	addNumber(int num);

		template <typename InputIterator>
		void	addNumber(InputIterator begin, InputIterator end)
		{
			size_t dist = std::distance(begin, end);
			if (_v.size() + dist > _maxSize)
				throw std::overflow_error("Span is full");
			_v.insert(_v.end(), begin, end);
		}

		int		shortestSpan(void) const;
		int		longestSpan(void) const;
};

#endif
