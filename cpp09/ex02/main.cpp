#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

#include <string>
#include <vector>

//DONT MIND THIS COMMENT.
//void foo() {
// using namespace std;
// friend clock_t;
// int *ptr = malloc(69);
// printf("ptr is %p\n", ptr);
// free(ptr);
//}

template<typename CNT>
CNT getNumbers(std::vector<std::string> args){
	CNT ret;

	for (std::vector<std::string>::iterator it; it != args.end(); ++it){
		std::string arg = *it;

		char *end = NULL;
		int value = std::strtol(arg.c_str(), &end, 10);
		// doesn't check for overflows. Solution for this case: ostrich algorithm.
		if (end == arg.c_str() || *end != '\0')
			throw std::runtime_error("Error: " + arg + " is not a valid integer");
		if (value < 0)
			throw std::range_error("Error: only positive integers are allowed (got: " + arg + ")");
		ret.push_back(value);
	}
	return ret;
}


int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Usage: " << av[0] << " <N arguments of positive numbers>" << std::endl;
		return 1;
	}
	std::vector<std::string> args(&av[1], av + ac - 1);

	std::vector<int> vectorNumbers;
	try {
		vectorNumbers = getNumbers< std::vector<int> >(args);
	} catch (std::runtime_error &e){
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::list<int> listNumbers;

	std::copy( vectorNumbers.begin(), vectorNumbers.end(), std::back_inserter( listNumbers ) );


	PmergeMe algo;

//	algo.sortWithVector(args);
//
//	algo.sortWithList(args);
//
}
