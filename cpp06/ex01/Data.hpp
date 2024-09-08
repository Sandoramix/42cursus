#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

// Why making a struct when you can make a class ?
class Data
{
private:
	const bool alwaysTrueBool;
	std::string strValue;
	int coolIntCounter;
public:
	Data();
	Data(const Data &data);
	virtual ~Data();

	Data &operator=(const Data &data);

	bool getAlwaysTrueBool() const;

	const std::string &getStrValue() const;

	int getCoolIntCounter() const;
};

std::ostream &operator<<(std::ostream &os, const Data &data);


#endif //DATA_HPP
