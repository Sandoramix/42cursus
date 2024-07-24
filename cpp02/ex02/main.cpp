#include "Fixed.hpp"
#include <ostream>

static std::string prettyBool(bool val)
{
	return val ? "true" : "false";
}

void subjectTests()
{
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


void myTests()
{
	std::cout << std::endl;
	std::cout << "MY TESTS" << std::endl;

	Fixed fromInt(1);
	Fixed fromFloat(5.5f);
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

	std::cout << std::endl;
	std::cout << "MAX: " << max << " --- " << "MIN: " << min << std::endl;
	std::cout << std::endl;

	bool equalCheck = fromInt == fromFloat;
	bool notEqualCheck = fromInt == fromFloat;

	std::cout << "[CONDITION]\t" << fromInt << " == " << fromFloat
			  << "\t:\t" << prettyBool(equalCheck)
			  << std::endl;
	std::cout << "[CONDITION]\t" << fromInt << " != " << fromFloat
			  << "\t:\t" << prettyBool(notEqualCheck)
			  << std::endl;

	bool lessThanCheck = min < max;
	bool lessOrEqualCheck = fromInt <= intCopyConstructor;

	std::cout << "[CONDITION]\t" << min << " < " << max
			  << "\t:\t" << prettyBool(lessThanCheck) << std::endl;
	std::cout << "[CONDITION]\t" << fromInt << " <= " << intCopyAssignment
			  << "\t\t:\t" << prettyBool(lessOrEqualCheck) << std::endl;

	bool greaterThanCheck = min > max;
	bool greaterOrEqualThanCheck = fromInt >= intCopyAssignment;

	std::cout << "[CONDITION]\t" << min << " > " << max
			  << "\t:\t" << prettyBool(greaterThanCheck) << std::endl;
	std::cout << "[CONDITION]\t" << fromInt << " >= " << intCopyAssignment
			  << "\t\t:\t" << prettyBool(greaterOrEqualThanCheck) << std::endl;


}


int main(void)
{
	subjectTests();
	myTests();
	return 0;
}

