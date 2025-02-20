#include "Fixed.hpp"

Fixed::Fixed() : fpNumber(0) {}
Fixed::Fixed(const int value)
{
	fpNumber = value << fracBits;
}
Fixed::Fixed(const float value)
{
	fpNumber = roundf(value * (1 << fracBits));
}
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fpNumber = other.getRawBits();
	return *this;
}
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return this->fpNumber;
}
void Fixed::setRawBits(int const raw)
{
	this->fpNumber = raw;
}
float Fixed::toFloat(void) const
{
	return (float)fpNumber / (1 << fracBits);
}
int Fixed::toInt(void) const
{
	return fpNumber >> fracBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	return fpNumber > other.fpNumber;
}
bool Fixed::operator<(const Fixed &other) const
{
	return fpNumber < other.fpNumber;
}
bool Fixed::operator>=(const Fixed &other) const
{
	return fpNumber >= other.fpNumber;
}
bool Fixed::operator<=(const Fixed &other) const
{
	return fpNumber <= other.fpNumber;
}
bool Fixed::operator==(const Fixed &other) const
{
	return fpNumber == other.fpNumber;
}
bool Fixed::operator!=(const Fixed &other) const
{
	return fpNumber != other.fpNumber;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	++fpNumber;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++fpNumber;
	return temp;
}
Fixed &Fixed::operator--()
{
	--fpNumber;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--fpNumber;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
