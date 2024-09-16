#include "Span.hpp"

#include <ctime>
#include <iostream>
#include <vector>


void test(int numbersToGenerate, bool tryToOverflow, bool printNumbers, int maxNumberValue = RAND_MAX)
{
	const bool printInline = printNumbers && numbersToGenerate <= 10;

	std::cerr << "--------------------------------------------------------------------------------\n"
			  << "Generating random numbers:\tN: " << numbersToGenerate << "\n";
	Span randomNumbers(numbersToGenerate);

	for (int i = 0; i < numbersToGenerate + tryToOverflow; i++)
	{
		int rnd = std::rand() % maxNumberValue;
		if (printNumbers)
		{
			std::cerr << (i == numbersToGenerate ? "\n[extra]" : "") << "[" << i << "]" << (printInline ? "" : "\t") << rnd << (printInline ? "\t" : "\n");
		}
		try
		{
			randomNumbers.addNumber(rnd);
		} catch (std::exception &e)
		{
			std::cerr << (printInline ? "\t" : "") << "An exception raised: " << e.what() << std::endl;
			break;
		}
	}
	if (printInline)
	{
		std::cerr << std::endl;
	}

	try
	{
		std::cerr << "Shortest Span: ";
		std::cerr << randomNumbers.shortestSpan() << std::endl;
	} catch (std::exception &e)
	{
		std::cerr << "Exception occurred: " << e.what() << std::endl;
	}
	try
	{
		std::cerr << "Longest Span: ";
		std::cerr << randomNumbers.longestSpan() << std::endl;
	} catch (std::exception &e)
	{
		std::cerr << "Exception occurred: " << e.what() << std::endl;
	}
	std::cerr << std::endl;
}


int main()
{
	std::srand(std::time(NULL));

	test(1, false, true);

	test(2, true, true, 50);

	test(3, false, true, 21);

	test(10, false, true, 100);

	test(10000, false, false);
	test(100000, false, false);
}