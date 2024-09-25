#include "PmergeMe.hpp"

// ------------------------------------

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &) { return *this; }

// ------------------------------------

std::vector<int> PmergeMe::sortVector(std::vector<int> nums) { return PmergeMe::sortWithVector(nums); }

std::list<int> PmergeMe::sortList(std::list<int> nums) { return PmergeMe::sortWithList(nums); }

// ------------------------------------

static int jacobsthalOf(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthalOf(n - 1) + 2 * jacobsthalOf(n - 2);
}

std::vector<int> PmergeMe::getJacobsthalNumbers(int n)
{
	std::vector<int> ret;
	// 3 is the first useful number (?)
	for (int i = 3; i < n; i++){
		ret.push_back(jacobsthalOf(n));
	}
	return ret;
}

// ------------------------------------

// VECTOR IMPLEMENTATION
std::vector<int> PmergeMe::sortWithVector(std::vector<int> nums)
{
	NOT_IMPLEMENTED;
	(void) nums;
	return std::vector<int>();
}

// ------------------------------------

// LIST IMPLEMENTATION
std::list<int> PmergeMe::sortWithList(std::list<int> nums)
{
	NOT_IMPLEMENTED;
	(void) nums;
	return std::list<int>();
}

// ------------------------------------
