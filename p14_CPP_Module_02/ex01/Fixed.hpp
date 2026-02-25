#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
    Fixed(const Fixed &other);
    Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &other);

    float toFloat(void) const;
	int toInt(void) const;

    int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _rawBits;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &ost, const Fixed &fixed);


#endif
