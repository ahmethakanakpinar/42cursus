#include "Fixed.hpp"
#include <cmath>

/* ---- Orthodox Canonical Form ---- */

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits)
{
}

Fixed::Fixed(const float value) : _rawBits(roundf(value * (1 << _fractionalBits)))
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

/* ---- Comparison operators ---- */

bool Fixed::operator>(const Fixed &other) const
{
	return (_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_rawBits != other._rawBits);
}

/* ---- Arithmetic operators ---- */

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result._rawBits = _rawBits + other._rawBits;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result._rawBits = _rawBits - other._rawBits;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result._rawBits = static_cast<int>((static_cast<long>(_rawBits) * other._rawBits) >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result._rawBits = static_cast<int>((static_cast<long>(_rawBits) << _fractionalBits) / other._rawBits);
	return (result);
}

/* ---- Increment / Decrement operators ---- */

Fixed &Fixed::operator++()
{
	++_rawBits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++_rawBits;
	return (temp);
}

Fixed &Fixed::operator--()
{
	--_rawBits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--_rawBits;
	return (temp);
}

/* ---- Conversion functions ---- */

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

/* ---- Min / Max ---- */

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

/* ---- Stream insertion ---- */

std::ostream &operator<<(std::ostream &ost, const Fixed &fixed)
{
	ost << fixed.toFloat();
	return (ost);
}