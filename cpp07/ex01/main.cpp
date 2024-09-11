#include "iter.hpp"

template<typename T>
void printNL(T &x)
{
	std::cout << x << std::endl;
}
template<typename T>
void print(T &x)
{
	std::cout << x;
}

int main()
{
	const int intlen = 5, charlen = 10, doublelen = 5;

	int intarray[intlen] = {0, 1, 2, 3, 4};
	char chararray[charlen] = "test12345";
	double doublearray[doublelen] = {0.1, 1.2, 2.3, 3.4, 4.5};

	std::cout << "Array of integers" << std::endl;
	iter(intarray, intlen, printNL<int>);

	std::cout << "Array of characters" << std::endl;
	iter(chararray, charlen - 1, print<char>);
	std::cout << std::endl;

	std::cout << "Array of doubles" << std::endl;
	iter(doublearray, doublelen, printNL<double>);

	return 0;
}