#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _rawBits(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _rawBits(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

std::ostream &operator<<(std::ostream &ost, const Fixed &fixed)
{
	ost << fixed.toFloat();
	return ost;
}