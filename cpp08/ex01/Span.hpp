#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>

#include <limits>
#include <typeinfo>
#include <algorithm>

class Span
{
private:
	unsigned int capacity;
	std::vector<int> container;

public:
	Span(unsigned int N);

	Span(const Span &span);

	~Span();

	Span &operator=(const Span &span);

	void addNumber(const int &number);

	int shortestSpan() const;

	int longestSpan() const;

	class NotEnoughSpaceException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class ShortestSpanCalcException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class LongestSpanCalcException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};


#endif //SPAN_HPP
