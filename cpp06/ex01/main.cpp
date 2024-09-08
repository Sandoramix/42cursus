#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <ostream>

void myTests()
{
	Data *someData = new Data();
	std::cout << "Some Data:\t\t" << *someData << std::endl;


	uintptr_t serializedValue = Serializer::serialize(someData);
	std::cout << "Serialized value:\t" << serializedValue << " (a.k.a. addr " << std::hex << serializedValue << ")" << std::dec << std::endl;

	Data *deserializedSomeData = Serializer::deserialize(serializedValue);
	std::cout << "Deserialized some Data:\t" << *deserializedSomeData << std::endl;

	delete someData;
}

int main()
{
	myTests();
}