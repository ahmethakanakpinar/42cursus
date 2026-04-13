#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <cstddef>

template <typename T>
class Array
{
	private:
		T		*_arr;
		size_t	_size;

	public:
		Array(void) : _arr(new T[0]()), _size(0) {}

		Array(unsigned int n) : _arr(new T[n]()), _size(n) {}

		Array(const Array &src) : _arr(new T[src._size]()), _size(src._size)
		{
			for (size_t i = 0; i < _size; i++)
				_arr[i] = src._arr[i];
		}

		Array &operator=(const Array &rhs)
		{
			if (this != &rhs)
			{
				delete[] _arr;
				_size = rhs._size;
				_arr = new T[_size]();
				for (size_t i = 0; i < _size; i++)
					_arr[i] = rhs._arr[i];
			}
			return *this;
		}

		~Array(void) { delete[] _arr; }

		T &operator[](size_t index)
		{
			if (index >= _size)
				throw std::out_of_range("Array index out of bounds");
			return _arr[index];
		}

		const T &operator[](size_t index) const
		{
			if (index >= _size)
				throw std::out_of_range("Array index out of bounds");
			return _arr[index];
		}

		size_t size(void) const { return _size; }
};

#endif
