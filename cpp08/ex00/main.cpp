#include "easyfind.hpp"
#include <deque>
#include <vector>
#include <list>
#include <set>
#include <sstream>

int main(){
	const int arrayLength = 5;
	int intArray[arrayLength] = {1,1, 2, 3, 5};

	std::vector<int> vector(arrayLength);
	std::set<int> set;
	std::list<int> list(arrayLength);
	std::deque<int> deque(arrayLength);

	for (int i = 0; i < arrayLength; i++){
		int val = intArray[i];
		vector.push_back(val);
		list.push_back(val);
		set.insert(val);
		deque.push_back(val);
	}

	int valToSearch = 3;

	std::cout << "Value to find: " << valToSearch << std::endl;

	std::cout << "Vector:\t" << easyfind(vector, valToSearch) << std::endl;
	std::cout << "Deque:\t" << easyfind(deque, valToSearch) << std::endl;
	std::cout << "List:\t" << easyfind(list, valToSearch) << std::endl;
	std::cout << "Set:\t" << easyfind(set, valToSearch) << std::endl;
}