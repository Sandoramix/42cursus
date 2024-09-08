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
		const char *what() const throw();
	};
};


template<typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array);


//IMPLEMENTATIONS-------------------------------------------------------------------------------------------------------


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
		throw Array<T>::IndexOutOfBoundsException();
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

#endif //ARRAY_HPP
