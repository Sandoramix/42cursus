#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	MutantStack()
	{
	}

	~MutantStack()
	{
	}

	MutantStack<T>(const MutantStack<T> &mutantStack) : std::stack<T>(mutantStack)
	{
	}

	MutantStack<T> &operator=(const MutantStack<T> &mutantStack)
	{
		if (this != &mutantStack)
		{
			std::stack<T>::operator=(mutantStack);
		}
		return *this;
	};

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const
	{
		return this->c.begin();
	}

	const_iterator end() const
	{
		return this->c.end();
	}
};

#endif //MUTANTSTACK_HPP
