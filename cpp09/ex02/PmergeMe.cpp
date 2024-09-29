#include "PmergeMe.hpp"

// ------------------------------------

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &) { return *this; }

// ------------------------------------

int PmergeMe::jacobsthalOf(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthalOf(n - 1) + 2 * jacobsthalOf(n - 2);
}

std::vector<int> PmergeMe::getJacobsthalInsertSequence(int pendCount)
{
	int maxPendIndex = pendCount - 1;
	std::vector<int> ret;

	// 3 is the first useful number (?)
	int jIdx = 3;

	int jacobsthalValue = PmergeMe::jacobsthalOf(jIdx);
	while (jacobsthalValue < maxPendIndex)
	{
		ret.push_back(jacobsthalValue);
		jIdx++;
		jacobsthalValue = PmergeMe::jacobsthalOf(jIdx);
	}
	return ret;
}

// ------------------------------------

struct FordJohnsonPairComparator
{
	bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) const
	{
		return a.second < b.second;
	}
};

// ------------------------------------

// VECTOR IMPLEMENTATION
std::vector<int> PmergeMe::sortVector(const std::vector<int> &original)
{
	std::vector<int> nums = original;
	if (nums.empty()) { return nums; };

	std::vector<std::pair<int, int> > pairs;

	bool hasOddNumber = nums.size() % 2 != 0;
	int oddNumber = nums[nums.size() - 1];
	if (hasOddNumber) { nums.pop_back(); };

	for (size_t i = 0; i < nums.size(); i += 2)
	{
		int n1 = nums[i], n2 = nums[i + 1];
		pairs.push_back(std::make_pair(std::min(n1, n2), std::max(n1, n2)));
	}

	std::sort(pairs.begin(), pairs.end(), FordJohnsonPairComparator());

	std::vector<int> S;
	std::vector<int> pend;

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		S.push_back(it->second);
		pend.push_back(it->first);
	}

	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());


	std::vector<int> jbInsertionSequence = PmergeMe::getJacobsthalInsertSequence(pend.size());

	bool lastInsertWasJacobsthal = false;

	size_t pendIdx = 0;
	while (pendIdx < pend.size())
	{
		int val;
		if (!jbInsertionSequence.empty() && !lastInsertWasJacobsthal)
		{
			val = pend[jbInsertionSequence[0] - 1];
			jbInsertionSequence.erase(jbInsertionSequence.begin());
			lastInsertWasJacobsthal = true;
		}
		else
		{
			val = pend[pendIdx];
			pendIdx++;
			lastInsertWasJacobsthal = false;

		}
		// binary search for val insertion
		const std::vector<int>::iterator &insertPos = std::lower_bound(S.begin(), S.end(), val);
		S.insert(insertPos, val);
	}

	if (hasOddNumber)
	{
		// binary search for val insertion
		const std::vector<int>::iterator &insertPos = std::lower_bound(S.begin(), S.end(), oddNumber);
		S.insert(insertPos, oddNumber);
	}

	return S;
}

// ------------------------------------

// DEQUE IMPLEMENTATION (copy pasta of Vector)
std::deque<int> PmergeMe::sortDeque(const std::deque<int> &original)
{
	std::deque<int> nums = original;
	if (nums.empty()) { return nums; };

	std::deque<std::pair<int, int> > pairs;

	bool hasOddNumber = nums.size() % 2 != 0;
	int oddNumber = nums[nums.size() - 1];
	if (hasOddNumber) { nums.pop_back(); };

	for (size_t i = 0; i < nums.size(); i += 2)
	{
		int n1 = nums[i], n2 = nums[i + 1];
		pairs.push_back(std::make_pair(std::min(n1, n2), std::max(n1, n2)));
	}

	std::sort(pairs.begin(), pairs.end(), FordJohnsonPairComparator());

	std::deque<int> S;
	std::deque<int> pend;

	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		S.push_back(it->second);
		pend.push_back(it->first);
	}

	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());


	std::vector<int> jbInsertionSequence = PmergeMe::getJacobsthalInsertSequence(pend.size());

	bool lastInsertWasJacobsthal = false;

	size_t pendIdx = 0;
	while (pendIdx < pend.size())
	{
		int val;
		if (!jbInsertionSequence.empty() && !lastInsertWasJacobsthal)
		{
			val = pend[jbInsertionSequence[0] - 1];
			jbInsertionSequence.erase(jbInsertionSequence.begin());
			lastInsertWasJacobsthal = true;
		}
		else
		{
			val = pend[pendIdx];
			pendIdx++;
			lastInsertWasJacobsthal = false;

		}
		// binary search for val insertion
		const std::deque<int>::iterator &insertPos = std::lower_bound(S.begin(), S.end(), val);
		S.insert(insertPos, val);
	}

	if (hasOddNumber)
	{
		// binary search for val insertion
		const std::deque<int>::iterator &insertPos = std::lower_bound(S.begin(), S.end(), oddNumber);
		S.insert(insertPos, oddNumber);
	}

	return S;
}

// ------------------------------------
