#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
	Fixed _x;
	Fixed _y;
public:
	Point(void);

	Point(const float x, const float y);

	Point(Point &p);

	Point &operator=(const Point &p);

	~Point();

	const Fixed &getX(void) const;

	const Fixed &getY(void) const;
};

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif //POINT_HPP
