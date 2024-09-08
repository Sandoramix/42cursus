#include "DummyData.hpp"
#include <ostream>

DummyData::DummyData() : alwaysTrueBool(true), strValue("Yep string"), coolIntCounter(69)
{
}

DummyData::DummyData(const DummyData &data) : alwaysTrueBool(data.alwaysTrueBool), strValue(data.strValue), coolIntCounter(data.coolIntCounter)
{
}

DummyData::~DummyData()
{
}

DummyData &DummyData::operator=(const DummyData &data)
{
	if (this != &data)
	{
		this->strValue = data.strValue;
		this->coolIntCounter = data.coolIntCounter;
	}
	return *this;
}

bool DummyData::getAlwaysTrueBool() const
{
	return alwaysTrueBool;
}

const std::string &DummyData::getStrValue() const
{
	return strValue;
}

int DummyData::getCoolIntCounter() const
{
	return coolIntCounter;
}

std::ostream &operator<<(std::ostream &os, const DummyData &data)
{
	os << "DummyData{ addr: " << &data << "; strValue: " << data.getStrValue() << "; alwaysTrueBool: "
	   << (data.getAlwaysTrueBool() ? "true" : "false") << "; coolIntCounter: " << data.getCoolIntCounter() << " }";
	return os;
}
