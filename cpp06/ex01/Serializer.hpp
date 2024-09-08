#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <ostream>
#include <stdint.h>

class Serializer
{
private:
	Serializer();
public:
	virtual ~Serializer() = 0;

	static uintptr_t serialize(Data* ptr);

	static Data* deserialize(uintptr_t raw);
};


#endif //SERIALIZER_HPP
