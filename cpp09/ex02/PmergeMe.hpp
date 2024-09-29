#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include <vector>
#include <deque>

//#define NOT_IMPLEMENTED \
//    do { \
//        std::stringstream ss; \
//        ss << __func__ << " is not yet implemented" << std::endl; \
//        throw std::runtime_error(ss.str()); \
//    } while(0);


class PmergeMe
{
private:
	PmergeMe();

	PmergeMe(const PmergeMe &pmergeMe);

	PmergeMe &operator=(const PmergeMe &pmergeMe);

public:
	~PmergeMe();

private:
	static int jacobsthalOf(int n);

	static std::vector<int> getJacobsthalInsertSequence(int pendCount);

public:
	static std::vector<int> sortVector(const std::vector<int> &nums);

	static std::deque<int> sortDeque(const std::deque<int> &nums);
};


#endif //PMERGEME_HPP
