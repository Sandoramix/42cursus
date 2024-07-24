#include "Fixed.hpp"
#include <ostream>

//-----------------------------------------------------------------------------
// CONSTRUCTORS + DESTRUCTOR

Fixed::Fixed(): raw(0){ std::cout << "[EMPTY\tconstructor]\tcalled" << std::endl;};

Fixed::Fixed(const Fixed &val)
{
	std::cout << "[COPY\tconstructor]\tfor " << val.raw << " called" << std::endl;
	this->raw = val.raw;
}

Fixed::~Fixed()
{
	std::cout << "[DESTRUCTOR]\t\tfor " << this->raw << " called" << std::endl;
}

//-----------------------------------------------------------------------------
// OPERATOR OVERLOADS

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "[COPY\tassignment]\tfor " << this->raw << " with " << other.raw << " called" << std::endl;
	this->raw = other.raw;
	return *this;
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
