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
	Fixed();
	Fixed(const Fixed &val);
	Fixed(const int number);
	Fixed(const float number);

	~Fixed();
	Fixed &operator=(const Fixed& other);


	int getRawBits() const;
	void setRawBits(const int raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream& os, const Fixed& val);

#endif //FIXED_HPP
