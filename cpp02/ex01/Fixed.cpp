#include "Fixed.hpp"

Fixed::Fixed() : fpNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fpNumber = value << fracBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fpNumber = roundf(value * (1 << fracBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fpNumber = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
