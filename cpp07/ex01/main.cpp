#include "DummyData.hpp"
#include "iter.hpp"

template<typename T>
void printValue(T &x)
{
	std::cout << x << std::endl;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	DummyData tab2[5];

	iter(tab, 5, printValue<int>);

	std::cout << std::endl;

	iter(tab2, 5, printValue<DummyData>);

	return 0;
}