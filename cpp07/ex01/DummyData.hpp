#ifndef DUMMYDATA_HPP
#define DUMMYDATA_HPP

#include <iostream>

// Why making a struct when you can make a class ?
class DummyData
{
private:
	const bool alwaysTrueBool;
	std::string strValue;
	int coolIntCounter;
public:
	DummyData();
	DummyData(const DummyData &data);
	virtual ~DummyData();

	DummyData &operator=(const DummyData &data);

	bool getAlwaysTrueBool() const;

	const std::string &getStrValue() const;

	int getCoolIntCounter() const;
};

std::ostream &operator<<(std::ostream &os, const DummyData &data);


#endif //DUMMYDATA_HPP
