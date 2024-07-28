#include "Fixed.hpp"
#include <ostream>
#include <cmath>

//-----------------------------------------------------------------------------
// STATIC METHODS

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a.toFloat() < b.toFloat() ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a.toFloat() < b.toFloat() ? a : b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a.toFloat() > b.toFloat() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a.toFloat() > b.toFloat() ? a : b;
}

//-----------------------------------------------------------------------------
// CONSTRUCTORS + DESTRUCTOR

Fixed::Fixed(const float number)
{
	this->raw = static_cast<int>(roundf(
		number * static_cast<float>(1 << Fixed::fractBits)));
	std::cout << "[FLOAT\tconstructor]\tfor " << number
			  << " as " << this->toFloat()
			  << " called." << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "[INT\tconstructor]\tfor " << number << " called" << std::endl;
	int translated = number << Fixed::fractBits;
	this->raw = translated;
}

Fixed::Fixed() : raw(0)
{
	std::cout << "[EMPTY\tconstructor]\tcalled" << std::endl;
};

Fixed::Fixed(const Fixed &val)
{
	std::cout << "[COPY\tconstructor]\tfor " << val << " called" << std::endl;
	this->raw = val.raw;
}

Fixed::~Fixed()
{
	//std::cout << "[DESTRUCTOR]\t\tfor " << *this << " called" << std::endl;
}

//-----------------------------------------------------------------------------
// ASSIGNMENT OPERATORS
Fixed &Fixed::operator=(const Fixed &other)
{
	if (&other == this){
		return *this;
	}
	std::cout << "[COPY\tassignment]\tfor " << *this << " with " << other
			  << " called" << std::endl;
	this->raw = other.raw;
	return *this;
}

//-----------------------------------------------------------------------------
// COMPARISON OPERATORS

bool Fixed::operator==(const Fixed &other) const
{
	return raw == other.raw;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->raw != other.raw;
}

bool Fixed::operator<(const Fixed &other) const
{
	return raw < other.raw;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->raw > other.raw;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->raw <= other.raw;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->raw >= other.raw;
}

//-----------------------------------------------------------------------------
// ARTHMETIC OPERATORS

Fixed Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

//-----------------------------------------------------------------------------
// UNARY OPERATORS

Fixed &Fixed::operator++(void)
{
	this->raw++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	this->raw++;
	return old;
}

Fixed &Fixed::operator--(void)
{
	this->raw--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	this->raw--;
	return old;
}

//-----------------------------------------------------------------------------
// CONVERTING METHODS

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->raw) / (1 << Fixed::fractBits);
}

int Fixed::toInt(void) const
{
	return this->raw >> Fixed::fractBits;
}

//-----------------------------------------------------------------------------
// GETTERS + SETTERS

int Fixed::getRawBits() const
{
	return this->raw;
}

void Fixed::setRawBits(const int rawBits)
{
	this->raw = rawBits;
}

//-----------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Fixed &val)
{
	os << val.toFloat();
	return os;
}
