#include "Array.hpp"
#include "DummyData.hpp"

int main()
{
	Array<int> empty;

	const int tabLength = 5;
	int tab[] = {0, 1, 2, 3, 4};
	Array<int> customTab(tabLength);
	for (int i = 0; i < tabLength;i++){customTab[i] = tab[i];}

	std::cout << customTab << std::endl;

	Array<DummyData> dummy(3);
	Array<DummyData> dummyAssignment = dummy;

	std::cout << dummyAssignment << std::endl;

	return 0;
}