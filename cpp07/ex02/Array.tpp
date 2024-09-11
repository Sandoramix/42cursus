#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include "Array.hpp"


template<typename T>
size_t Array<T>::size() const
{
	return length;
}

template<typename T>
Array<T>::Array(): content(NULL), length(0)
{
}

template<typename T>
Array<T>::Array(const size_t &n): content(NULL), length(n)
{
	this->content = new T[n];
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->content;
	this->length = 0;
}

template<typename T>
Array<T>::Array(const Array<T> &array): length(array.length)
{
	this->content = new T[array.length];
	for (size_t i = 0; i < length; i++)
	{
		this->content[i] = array.content[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> array)
{
	if (this != &array)
	{
		::swap(this->length, array.length);
		::swap(this->content, array.content);
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](size_t idx)
{
	if (idx >= this->length)
		throw IndexOutOfBoundsException();
	return this->content[idx];
}

template<typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}


template<typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &array)
{
	for (size_t i = 0; i < array.size(); i++)
		os << "[" << i << "]: " << array[i] << std::endl;
	return os;
}
#endif //ARRAY_TPP
