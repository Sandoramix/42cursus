#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::vector<int> parseArgvNumbers(std::vector<std::string> args)
{
	std::vector<int> ret;

	for (size_t i = 0; i < args.size(); ++i)
	{
		char *end = NULL;
		std::string arg = args[i];
		long value = std::strtol(arg.c_str(), &end, 10);
		// doesn't check for overflows. Solution for this case: ostrich algorithm.
		if (end == arg.c_str() || *end != '\0')
			throw std::runtime_error(arg + " is not a valid integer.");
		if (value < 0)
			throw std::invalid_argument("Input must contain positive integers.");
		ret.push_back(value);
	}
	return ret;
}

template<typename Container>
void printContainer(const std::string &headingMsg, const Container &cnt, size_t numbersToShow = 10)
{
	std::cout << headingMsg << ":";
	size_t i;

	for (i = 0; i < numbersToShow && i < cnt.size(); ++i) { std::cout << " " << cnt[i]; }
	if (i < cnt.size()) { std::cout << " ..."; }

	std::cout << std::endl;
}

int main(int ac, char **av)
{
	std::vector<std::string> args;

	std::deque<int> dequeNumbers;
	std::vector<int> vectorNumbers;

	if (ac == 1)
	{
		std::cerr << "Usage: " << av[0] << " <sequence of N positive integers>" << std::endl;
		return 1;
	}
	else { args = std::vector<std::string>(&av[1], &av[1] + ac - 1); };
	try
	{
		vectorNumbers = parseArgvNumbers(args);
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	std::copy(vectorNumbers.begin(), vectorNumbers.end(), std::back_inserter(dequeNumbers));

	size_t totalSize = vectorNumbers.size();

	printContainer("Before", vectorNumbers, 15);

	try
	{
		clock_t start = clock();
		std::vector<int> sortedVector = PmergeMe::sortVector(vectorNumbers);
		clock_t end = clock();

		printContainer("After (std::vector)", sortedVector, 15);
		std::cout << "Time to process a range of " << totalSize << " elements with std::vector :\t"
				  << std::fixed << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
	}
	catch (std::runtime_error &e) { std::cerr << e.what() << std::endl; };

	try
	{
		clock_t start = clock();
		std::deque<int> sortedDeque = PmergeMe::sortDeque(dequeNumbers);
		clock_t end = clock();
		printContainer("After (std::deque)", sortedDeque, 15);
		std::cout << "Time to process a range of " << totalSize << " elements with std::deque :\t"
				  << std::fixed << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
	}
	catch (std::runtime_error &e) { std::cerr << e.what() << std::endl; };
}



//DONT MIND THIS COMMENT.
//void foo() {
// using namespace std;
// friend clock_t;
// int *ptr = malloc(69);
// printf("ptr is %p\n", ptr);
// free(ptr);
//}