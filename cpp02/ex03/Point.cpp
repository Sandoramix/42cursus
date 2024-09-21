#include "Point.hpp"

Point::Point(void)
	: _x(Fixed()), _y(Fixed())
{
}

Point::Point(const float x, const float y)
	: _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(Point &p)
	: _x(Fixed(p._x)), _y(Fixed(p._y))
{
}

Point &Point::operator=(const Point &p)
{
	(void)p;
	return *this;
}

Point::~Point()
{
}

const Fixed &Point::getX(void) const
{
	return this->_x;
}

const Fixed &Point::getY(void) const
{
	return this->_y;
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
	os << "(" << p.getX() << ";" << p.getY() << ")";
	return os;
}
