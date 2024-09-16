#include "Span.hpp"

Span::Span(unsigned int N) : capacity(N), container(0)
{
}

Span::Span(const Span &span) : capacity(span.capacity), container(span.container)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &span)
{
	if (this != &span)
	{
		this->capacity = span.capacity;
	}
	return *this;
}

void Span::addNumber(const int &number)
{
	if (this->container.size() == this->capacity)
	{
		throw Span::NotEnoughSpaceException();
	}
	this->container.push_back(number);
}

int Span::shortestSpan() const
{
	if (this->container.size() < 2)
	{
		throw Span::ShortestSpanCalcException();
	}

	std::vector<int> tmpCopy(this->container);
	std::sort(tmpCopy.begin(), tmpCopy.end());

	int shortest_span = std::numeric_limits<int>::max();

	for (std::size_t i = 1; i < tmpCopy.size(); ++i)
	{
		int span = tmpCopy[i] - tmpCopy[i - 1];
		if (span < shortest_span)
		{
			shortest_span = span;
		}
	}

	return (shortest_span);
}

int Span::longestSpan() const
{
	if (this->container.size() < 2)
	{
		throw Span::LongestSpanCalcException();
	}

	std::vector<int> tmpCopy(this->container);
	std::sort(tmpCopy.begin(), tmpCopy.end());

	return tmpCopy.back() - tmpCopy.front();
}

const char *Span::NotEnoughSpaceException::what() const throw()
{
	return "Not enough space";
}

const char *Span::ShortestSpanCalcException::what() const throw()
{
	return "Cannot calculate shortest span";
}

const char *Span::LongestSpanCalcException::what() const throw()
{
	return "Cannot calculate longest span";
}
