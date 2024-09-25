#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include <vector>
#include <list>

#define NOT_IMPLEMENTED \
    do { \
        std::stringstream ss; \
        ss << __func__ << " is not yet implemented" << std::endl; \
        throw std::runtime_error(ss.str()); \
    } while(0);


class PmergeMe
{
public:
	PmergeMe();

	PmergeMe(const PmergeMe &pmergeMe);

	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &pmergeMe);

private:;

public:
	static std::vector<int> sortWithVector(std::vector<int> nums);

	static std::list<int> sortWithList(std::list<int> nums);

public:
	std::vector<int> sortVector(std::vector<int> nums);

	std::list<int> sortList(std::list<int> nums);
};


#endif //PMERGEME_HPP
