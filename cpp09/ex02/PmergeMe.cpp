#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &){}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe &)
{return *this;}

std::vector<int> PmergeMe::sortWithVector(std::vector<int> nums)
{
	NOT_IMPLEMENTED;
	(void)nums;
	return std::vector<int>();
}

std::list<int> PmergeMe::sortWithList(std::list<int> nums)
{
	NOT_IMPLEMENTED;
	(void)nums;
	return std::list<int>();
}

std::vector<int> PmergeMe::sortVector(std::vector<int> nums)
{ return PmergeMe::sortWithVector(nums); }

std::list<int> PmergeMe::sortList(std::list<int> nums)
{ return PmergeMe::sortWithList(nums); }
