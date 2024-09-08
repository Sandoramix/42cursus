#include "ScalarConvert.hpp"
#include <ostream>
#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------

void ScalarConvert::printResult(const std::string &charVal, const std::string &intVal, const std::string &floatVal,
								const std::string &doubleVal)
{
	std::cout << "char" << ": " << charVal << std::endl;
	std::cout << "int" << ": " << intVal << std::endl;
	std::cout << "float" << ": " << floatVal << std::endl;
	std::cout << "double" << ": " << doubleVal << std::endl;
}


bool ScalarConvert::isStringAParseableNumber(const std::string &rawValue)
{
	const size_t rawValueLength = rawValue.length();
	bool goneThroughADot = false;

	/// Empty string is a no-no
	if (rawValueLength == 0)
		return false;

	for (size_t i = 0; i < rawValueLength; i++)
	{
		char charAtI = rawValue[i];

		/// Skipping 1 sign at the start as valid.
		if (i == 0 && (charAtI == '+' || charAtI == '-'))
			continue;
		/// Check for `.`
		if (charAtI == '.')
		{
			///If it's the only `.` found and there is one digit either before of after then it's okay.
			if (!goneThroughADot && ((i > 0 && isdigit(rawValue[i - 1])) || (i < rawValueLength - 1 && isdigit(rawValue[i + 1]))))
			{
				goneThroughADot = true;
				continue;
			}
			else
			{
				/// There's already been found another `.` or there are no digits beside this character.
				return false;
			}
		}
		/// Check for float numbers
		if (charAtI == 'f')
		{
			/// If the `f` is not the last character or it's the only character present in the `rawValue`
			if (i != rawValueLength - 1 || rawValueLength == 1)
				return false;
			/// The `f` is last character of the string and it's fine.
			continue;
		}
		/// Any non-digit character should be invalid at this point of code.
		if (!isdigit(charAtI))
			return false;
	}
	return true;
}


//-----------------------------------------------------------------------------


template<class T>
std::string ScalarConvert::convertToString(T value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

std::string ScalarConvert::convertToString(char value)
{
	std::stringstream ss;
	if (value >= 32 && value < 127)
		ss << "'" << value << "'";
	else
		ss << "Non displayable";
	return ss.str();
}

std::string ScalarConvert::convertToString(float value)
{
	std::stringstream ss;
	ss << value << 'f';
	return ss.str();
}


//-----------------------------------------------------------------------------

bool ScalarConvert::convert(const std::string &rawValue)
{
	char convertedChar;
	int convertedInt;
	float convertedFloat;
	double convertedDouble;

	if (rawValue == "nan" || rawValue == "nanf")
	{
		printResult("impossible", "impossible", "nanf", "nan");
		return (true);
	}
	if (rawValue == "+inf" || rawValue == "-inf" || rawValue == "+inff" || rawValue == "-inff")
	{
		const bool isFloatSpecial = rawValue == "+inff" || rawValue == "-inff";
		printResult(
			"impossible",
			"impossible",
			isFloatSpecial ? rawValue : rawValue + "f",
			isFloatSpecial ? rawValue.substr(0, 4) : rawValue
		);
		return (true);
	}

	if ((rawValue.length() == 1 && !(rawValue[0] >= '0' && rawValue[0] <= '9')) /** single non digit character. eg: a */
		|| (rawValue.length() == 3 && rawValue[0] == '\'' && rawValue[2] == '\'')) /** char surrounded by single quotes. eg: '1' */
	{
		/// CHAR CASE
		convertedChar = rawValue.length() == 3 ? rawValue[1] : rawValue[0];
		convertedInt = static_cast<int>(convertedChar);
		convertedFloat = static_cast<float>(convertedChar);
		convertedDouble = static_cast<double>(convertedChar);

		printResult(
			convertToString(convertedChar),
			convertToString(convertedInt),
			convertToString(convertedFloat),
			convertToString(convertedDouble)
		);
		return (true);
	}
	/// Check if the number is valid (only digits/1 sign/one `.`/one `f` at the end)
	if (!isStringAParseableNumber(rawValue))
		return (std::cerr << "Invalid input provided" << std::endl, false);

	if (rawValue.length() > 1 && rawValue[rawValue.length() - 1] == 'f')
	{
		/// FLOAT CASE
		std::stringstream floatStream(rawValue);
		if (!(floatStream >> convertedFloat))
			return (std::cerr << "Could not parse [" << rawValue << "] as a float" << std::endl, false);
		convertedChar = static_cast<char>(convertedFloat);
		convertedInt = static_cast<int>(convertedFloat);
		convertedDouble = static_cast<double>(convertedFloat);
	}
	else if (rawValue.find('.') != std::string::npos)
	{
		/// DOUBLE CASE
		std::stringstream doubleStream(rawValue);
		if (!(doubleStream >> convertedDouble))
			return (std::cerr << "Could not parse [" << rawValue << "] as a double" << std::endl, false);
		convertedChar = static_cast<char>(convertedDouble);
		convertedInt = static_cast<int>(convertedDouble);
		convertedFloat = static_cast<float>(convertedDouble);
	}
	else
	{
		/// INTEGER CASE
		std::stringstream intStream(rawValue);
		if (!(intStream >> convertedInt))
		{
			return (std::cerr << "Could not parse [" << rawValue << "] as a int" << std::endl, false);
		}
		convertedChar = static_cast<char>(convertedInt);
		convertedFloat = static_cast<float>(convertedInt);
		convertedDouble = static_cast<double >(convertedInt);
	}

	printResult(
		convertToString(convertedChar),
		convertToString(convertedInt),
		convertToString(convertedFloat),
		convertToString(convertedDouble)
	);
	return (true);
}


ScalarConvert::ScalarConvert()
{
}
