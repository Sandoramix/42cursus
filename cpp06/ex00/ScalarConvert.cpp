#include "ScalarConvert.hpp"
#include <ostream>
#include <sstream>

//-----------------------------------------------------------------------------

std::string ScalarConvert::getCharPrintString(char character)
{
	std::stringstream os;
	if (character >= 32 && character < 127)
	{
		os << "'" << character << "'";
	}
	else
	{
		os << "Non displayable";
	}
	return os.str();
}

std::string ScalarConvert::getIntPrintString(int value)
{
	std::stringstream os;
	os << value;
	return os.str();
}

std::string ScalarConvert::getFloatPrintString(float value)
{
	std::stringstream os;
	os << std::fixed << value << "f";
	return os.str();
}

std::string ScalarConvert::getDoublePrintString(double value)
{
	std::stringstream os;
	os << std::fixed << value;
	return os.str();
}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

void ScalarConvert::printEveryStringValue(const std::string &charVal, const std::string &intVal, const std::string &floatVal,
										  const std::string &doubleVal)
{
	std::cout << "char" << ": " << charVal << std::endl;
	std::cout << "int" << ": " << intVal << std::endl;
	std::cout << "float" << ": " << floatVal << std::endl;
	std::cout << "double" << ": " << doubleVal << std::endl;
}

//-----------------------------------------------------------------------------

void ScalarConvert::convert(const std::string &rawValue)
{
	char convertedChar;
	int convertedInt;
	float convertedFloat;
	double convertedDouble;

	if (rawValue == "nan" || rawValue == "nanf")
	{
		printEveryStringValue("impossible", "impossible", "nanf", "nan");
		return;
	}
	if (rawValue == "+inf" || rawValue == "-inf")
	{
		printEveryStringValue(
			"impossible",
			"impossible",
			rawValue + "f",
			rawValue
		);
		return;
	}
	if (rawValue == "+inff" || rawValue == "-inff")
	{
		printEveryStringValue(
			"impossible",
			"impossible",
			rawValue,
			rawValue.substr(0, 4)
		);
		return;
	}

	// CHAR CASE
	if ((rawValue.length() == 1 && !(rawValue[0] >= '0' && rawValue[0] <= '9')) // single non digit character. eg: a
		|| (rawValue.length() == 3 && rawValue[0] == '\'' && rawValue[2] == '\'') // char surrounded by single quotes. eg: '1'
		)
	{
		convertedChar = rawValue.length() == 3 ? rawValue[1] : rawValue[0];
		convertedInt = static_cast<int>(convertedChar);
		convertedFloat = static_cast<float>(convertedChar);
		convertedDouble = static_cast<double>(convertedChar);

		printEveryStringValue(
			getCharPrintString(convertedChar),
			getIntPrintString(convertedInt),
			getFloatPrintString(convertedFloat),
			getDoublePrintString(convertedDouble)
		);
		return;
	}
	// FLOAT CASE
	if (rawValue.length() > 1 && rawValue[rawValue.length() - 1] == 'f')
	{
		std::stringstream floatStream(rawValue);
		if (floatStream >> convertedFloat)
		{

			convertedChar = static_cast<char>(convertedFloat);
			convertedInt = static_cast<int>(convertedFloat);
			convertedDouble = static_cast<double>(convertedFloat);

			printEveryStringValue(
				getCharPrintString(convertedChar),
				getIntPrintString(convertedInt),
				getFloatPrintString(convertedFloat),
				getDoublePrintString(convertedDouble)
			);
			return;
		}
		else
		{
			std::cerr << "Invalid input provided" << std::endl;
			return;
		}
	}
	// DOUBLE CASE
	if (rawValue.find('.') != std::string::npos)
	{
		std::stringstream doubleStream(rawValue);
		if (doubleStream >> convertedDouble)
		{
			convertedChar = static_cast<char>(convertedDouble);
			convertedInt = static_cast<int>(convertedDouble);
			convertedFloat = static_cast<float>(convertedDouble);

			printEveryStringValue(
				getCharPrintString(convertedChar),
				getIntPrintString(convertedInt),
				getFloatPrintString(convertedFloat),
				getDoublePrintString(convertedDouble)
			);
			return;
		}
		else
		{
			std::cerr << "Invalid input provided" << std::endl;
			return;
		}
	}
	// INTEGER CASE
	std::stringstream intStream(rawValue);
	if (intStream >> convertedInt)
	{
		convertedChar = static_cast<char>(convertedInt);
		convertedFloat = static_cast<float>(convertedInt);
		convertedDouble = static_cast<double >(convertedInt);

		printEveryStringValue(
			getCharPrintString(convertedChar),
			getIntPrintString(convertedInt),
			getFloatPrintString(convertedFloat),
			getDoublePrintString(convertedDouble)
		);
		return;
	}
	else
	{
		std::cerr << "Invalid input provided" << std::endl;
		return;
	}
}


ScalarConvert::ScalarConvert()
{
}

ScalarConvert::ScalarConvert(const ScalarConvert &scalarConvert)
{
	(void) scalarConvert;
}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &c)
{
	if (this == &c)
	{
		return *this;
	}
	return *this;
}


