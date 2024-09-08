#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <string>
#include <sstream>
#include <limits>
#include <iostream>

class ScalarConvert
{
private:
	static void printResult(const std::string &charVal,
							const std::string &intVal,
							const std::string &floatVal,
							const std::string &doubleVal);

	template<class T>
	static std::string convertToString(T value);

	static std::string convertToString(float value);

	static std::string convertToString(char value);

	static bool isStringAParseableNumber(const std::string &rawValue);

public:
	static bool convert(const std::string &rawValue);

private:
	ScalarConvert();
	virtual ~ScalarConvert() = 0;
};

#endif //SCALARCONVERT_HPP
