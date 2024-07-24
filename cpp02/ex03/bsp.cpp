#include "Point.hpp"
#include "Fixed.hpp"

static float getArea(const Point &p1, const Point &p2, const Point &p3)
{

	float area = Fixed(((p1.getX() * (p2.getY() - p3.getY())) +
						(p2.getX() * (p3.getY() - p1.getY())) +
						(p3.getX() * (p1.getY() - p2.getY()))) /
					   Fixed(2)
	).toFloat();
	return area < 0.0f ? -area : area;
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float triangleArea = getArea(a, b, c);

	float sec1Area = getArea(point, a, b);
	float sec2Area = getArea(point, a, c);
	float sec3Area = getArea(point, b, c);

	// Point on the edge
	if (sec1Area == 0.0f || sec2Area == 0.0f || sec3Area == 0.0f)
	{
		return false;
	}

	return (sec1Area + sec2Area + sec3Area) == triangleArea;
}