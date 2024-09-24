#include <sstream>
#include "RPN.hpp"

const float RPN::minValue = RPN_MINVAL;
const float RPN::maxValue = RPN_MAXVAL;

RPN::RPN() {}

RPN::RPN(const RPN &rpn) { (void) rpn; }

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rpn)
{
	(void) rpn;
	return *this;
}

//-PRIVATE-----------------------------

// STATIC
float RPN::runExpression(float n1, float n2, const std::string &operatorStr)
{
	if (operatorStr == "+")
		return n1 + n2;
	if (operatorStr == "-")
		return n1 - n2;
	if (operatorStr == "/")
		return n1 / n2;
	if (operatorStr == "*")
		return n1 * n2;
	throw InvalidRPNExpressionException();
}

// STATIC
bool RPN::isOperator(const std::string &val)
{
	std::string validOperators[] = {"+", "-", "/", "*"};
	const int arrSize = 4;
	for (int i = 0; i < arrSize; i++){
		if (validOperators[i] == val)
			return true;
	}
	return false;
}

// STATIC
float RPN::parseNumberOrThrow(const std::string &rawValue)
{
	char *end;
	float value = std::strtof(rawValue.c_str(), &end);
	if (end == rawValue.c_str() || !end || *end != '\0')
		throw InvalidNumberException();
	return value;
}
//-PUBLIC------------------------------

// STATIC
float RPN::parseExpr(const std::string &expr)
{
	if (expr.empty())
		throw InvalidRPNExpressionException();
	std::stack<float> operands;

	std::stringstream stream(expr);

	std::string element;
	// basically split per ' '
	while (stream >> element)
	{
		bool isNumber = false;
		float number = -1;
		try
		{
			number = parseNumberOrThrow(element);
			isNumber = true;
		}
		catch (std::exception &e) {(void)e;};

		if (isOperator(element))
		{
			if (operands.size() < 2)
				throw InvalidRPNExpressionException();
			float n2 = operands.top();
			operands.pop();

			float n1 = operands.top();
			operands.pop();

			float result = RPN::runExpression(n1, n2, element);
			operands.push(result);
		}
		else if (isNumber)
		{
			if (number < RPN::minValue || number > RPN::maxValue)
				throw InvalidNumberValueException();
			operands.push(number);
		}
		else
		{
			throw InvalidRPNExpressionException();
		}
	}
	if (operands.size() != 1)
	{
		throw InvalidRPNExpressionException();
	}
	return operands.top();
}

float RPN::parse(const std::string &expr)
{
	return RPN::parseExpr(expr);
}

//EXCEPTIONS---------------------------
const char *RPN::InvalidRPNExpressionException::what() const throw()
{
	return "Invalid expression";
}

const char *RPN::InvalidNumberValueException::what() const throw()
{
	return "Number is out of range";
}

const char *RPN::InvalidNumberException::what() const throw()
{
	return "Invalid number";
}
//-------------------------------------
