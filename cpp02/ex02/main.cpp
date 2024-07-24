#include "Fixed.hpp"
#include <ostream>

void subjectTests(){
	std::cout << "SUBJECT TESTS" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

void myTests(){
	std::cout << "MY TESTS" << std::endl;

	Fixed fromInt(1);
	Fixed fromFloat(5.4321f);
	std::cout << std::endl;

	Fixed minFromInt(-42);
	Fixed maxFromInt(42);
	std::cout << std::endl;

	Fixed intCopyConstructor(fromInt);
	Fixed floatCopyConstructor(fromFloat);
	std::cout << std::endl;

	Fixed intCopyAssignment;
	intCopyAssignment = fromInt;

	Fixed floatCopyAssignment;
	floatCopyAssignment = fromFloat;
	std::cout << std::endl;

	Fixed min(Fixed::min(minFromInt, minFromInt));
	Fixed max(Fixed::max(minFromInt, maxFromInt));
	std::cout << "MAX: " << max << " --- " << "MIN: " << min << std::endl;
	std::cout << std::endl;

	bool equalCheck = fromInt == fromFloat;
	bool notEqualCheck = fromInt == fromFloat;

	bool lessThanCheck = min < max;
	bool lessOrEqualCheck = fromInt <= intCopyConstructor;

	bool greaterThanCheck = min > max;
	bool greaterOrEqualThanCheck = fromInt >= intCopyAssignment;



}



int main(void)
{
	//subjectTests();
	myTests();
	return 0;
}

