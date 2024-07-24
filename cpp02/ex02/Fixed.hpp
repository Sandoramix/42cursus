#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>

class Fixed {
private:
	static const int fractBits = 8;
	int	raw;

public:
	//-------------------------------------------
	// STATIC METHODS
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);

	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);


	//-------------------------------------------
	// CONSTRUCTORS + DESTRUCTOR
	Fixed();
	Fixed(const Fixed &val);
	Fixed(const int number);
	Fixed(const float number);

	~Fixed();
	//-------------------------------------------
	// ASSIGNMENT OPERATORS
	Fixed &operator=(const Fixed& other);

	//-------------------------------------------
	// COMPARISON OPERATORS
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;

	//-------------------------------------------
	// ARTHMETIC OPERATORS
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	//-------------------------------------------
	// UNARY OPERATORS
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	//-------------------------------------------
	// CONVERTING METHODS
	float toFloat(void) const;
	int toInt(void) const;

	//-------------------------------------------
	// GETTERS + SETTERS
	int getRawBits() const;
	void setRawBits(const int raw);

};

std::ostream &operator<<(std::ostream& os, const Fixed& val);

#endif //FIXED_HPP
