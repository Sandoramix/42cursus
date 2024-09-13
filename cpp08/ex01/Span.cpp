#include "Span.hpp"

Span::Span(unsigned int N)
{

}

Span::Span(const Span &span)
{

}

Span::~Span()
{

}

Span &Span::operator=(const Span &span)
{
	if (this != &span){
		this->capacity = span.capacity;
	}
	return *this;
}
