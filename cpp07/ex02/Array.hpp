#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <istream>
#include <ostream>
#include <iostream>
#include <exception>

template<typename T>
void swap(T &val1, T &val2)
{
	T tmp = val1;
	val1 = val2;
	val2 = tmp;
}

template<typename T>
class Array
{
private:
	T *content;
	size_t length;
public:
	Array();

	Array(const size_t &n);

	~Array();

	Array(const Array<T> &array);

	Array &operator=(Array<T> array);

	T &operator[](size_t idx);

	size_t size() const;

	class IndexOutOfBoundsException : std::exception
	{
	public:
		const char *what() const throw();
	};
};


template<typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array);

#include "Array.tpp"

#endif //ARRAY_HPP
