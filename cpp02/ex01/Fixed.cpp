#include "Fixed.hpp"
#include <ostream>
#include <cmath>

//-----------------------------------------------------------------------------
// CONSTRUCTORS + DESTRUCTOR

Fixed::Fixed(const float number)
{
	this->raw = static_cast<int>(roundf(number * static_cast<float>(1 << Fixed::fractBits)));
	std::cout << "[FLOAT\tconstructor]\tfor " << number << " as " << this->toFloat() << " called." << std::endl;
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

Fixed::Fixed(const Fixed &val) : raw(val.raw)
{
	std::cout << "[COPY\tconstructor]\tfor " << val << " called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "[DESTRUCTOR]\t\tfor " << *this << " called" << std::endl;
}

//-----------------------------------------------------------------------------
// OPERATOR OVERLOADS
Fixed &Fixed::operator=(const Fixed &other)
{
	if (&other == this)
	{
		return *this;
	}
	std::cout << "[COPY\tassignment]\tfor " << *this << " with " << raw << " called" << std::endl;
	this->raw = other.raw;
	return *this;
}


//-----------------------------------------------------------------------------
// CONVERTERS
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