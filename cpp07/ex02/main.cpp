#include "Array.hpp"
#include "DummyData.hpp"

int main()
{
	Array<int> empty;

	const int tabLength = 5, tab[] = {0, 1, 2, 3, 4};

	Array<int> customTab(tabLength);
	for (int i = 0; i < tabLength;i++){customTab[i] = tab[i];}


	std::cout << "Non const array:" << std::endl
			  << customTab << std::endl;

	const Array<int> constCustomTab = customTab;
	std::cout << "Const array: " << std::endl
			  << constCustomTab << std::endl;

	Array<DummyData> dummy(3);
	Array<DummyData> dummyAssignment = dummy;

	std::cout << "Array<CustomClass>: " << std::endl
			  << dummyAssignment << std::endl;
	try {
		std::cout << "Array<CustomClass>, Trying to access the index [" << dummyAssignment.size() << "] (out of bounds):" << std::endl;
		std::cout << dummyAssignment[dummyAssignment.size() + 1] << std::endl;
	} catch (std::exception &e){
		std::cerr << "Array error: " << e.what() << std::endl;
	}

	return 0;
}