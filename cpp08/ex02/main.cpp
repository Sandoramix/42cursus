#include "MutantStack.hpp"

#include <ctime>
#include <iostream>
#include <stdlib.h>

int main()
{
	std::srand(std::time(NULL));

	// Change these values.
	const int numbersToGenerate = 10;
	const int maxNumberValue = 100;

	MutantStack<int> intMutantStack;

	const bool printInline = numbersToGenerate <= 10;
	for (int i = 0; i < numbersToGenerate; i++)
	{
		int rnd = std::rand() % maxNumberValue;
		std::cerr << "[" << i << "]" << (printInline ? "" : "\t") << rnd << (printInline ? "\t" : "\n");
		intMutantStack.push(rnd);
	}
	std::cout << std::endl;

	const MutantStack<int> constIntMutantStack = intMutantStack;

	MutantStack<int>::iterator it = intMutantStack.begin();
	MutantStack<int>::const_iterator constIt = constIntMutantStack.begin();


	for (int i = 0; it != intMutantStack.end() && constIt != constIntMutantStack.end(); ++i, ++it, ++constIt)
	{
		if (i == 0){
			*it = 5;
			//*constIt = 5;
		}
		std::cout << "[" << i << "]: it[" << *it << "]; constIt[" << *constIt << "]" << std::endl;
	}
}