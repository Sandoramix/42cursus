#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <string>
#include <sstream>
#include <limits>
#include <iostream>

class ScalarConvert
{
private:
	static void printEveryStringValue(const std::string &charVal, const std::string &intVal, const std::string &floatVal, const std::string &doubleVal);

	static std::string getCharPrintString(char value);
	static std::string getIntPrintString(int value);
	static std::string getFloatPrintString(float value);
	static std::string getDoublePrintString(double value);
public:
	static void convert(const std::string &rawValue);
protected:
	ScalarConvert();
	ScalarConvert(const ScalarConvert &scalarConvert);
	virtual ~ScalarConvert() = 0;

	ScalarConvert &operator=(const ScalarConvert &c);
};

#endif //SCALARCONVERT_HPP
