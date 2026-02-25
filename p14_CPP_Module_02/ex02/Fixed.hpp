#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

public:
	Fixed();
	Fixed(const Fixed &other);
    Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &other);
	~Fixed();


private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

};

std::ostream &operator<<(std::ostream &ost, const Fixed &fixed);

#endif
