#pragma once




#include <iostream>

class Fixed {
private:
	static const int fractBits = 8;
	int	raw;

public:
	Fixed();
	Fixed(const Fixed &val);

	~Fixed();

	Fixed &operator=(const Fixed& other);


	int getRawBits() const;
	void setRawBits(const int raw);
};



