#include "Point.hpp"
#include <ostream>

bool bsp(const Point a, const Point b, const Point c, const Point point);

static std::string prettyBool(bool val)
{
	return val ? "true" : "false";
}

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 5.0f);
	Point c(5.0f, 0.0f);
	std::cout << "Triangle:\ta" << a << "\tb" << b << "\tc" << c << std::endl;

	Point inside(1.0f, 1.0f);
	std::cout << "Point inside" << inside << "\tbsp: "
			  << prettyBool(bsp(a, b, c, inside)) << std::endl;

	Point outside(-5.0f, -5.0f);
	std::cout << "Point outside" << outside << "\tbsp: "
			  << prettyBool(bsp(a, b, c, outside)) << std::endl;
	Point onEdge(0.0f, 3.0f);
	std::cout << "Point onEdge" << onEdge << "\tbsp: "
			  << prettyBool(bsp(a, b, c, onEdge)) << std::endl;
	return 0;
}

