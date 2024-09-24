#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>

#define RPN_MINVAL 0.0f
#define RPN_MAXVAL 1000.0f

class RPN
{
public:
	static const float minValue;
	static const float maxValue;
private:
	static float runExpression(float n1, float n2, const std::string &operatorStr);

	static bool isOperator(const std::string &val);

	static float parseNumberOrThrow(const std::string &rawValue);

public:
	RPN();

	RPN(const RPN &rpn);

	~RPN();

	RPN &operator=(const RPN &rpn);

	float parse(const std::string &expr);

	static float parseExpr(const std::string &expr);

	class InvalidRPNExpressionException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidNumberValueException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidNumberException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};


#endif //RPN_HPP
