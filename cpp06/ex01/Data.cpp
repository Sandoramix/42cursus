#include "Data.hpp"
#include <ostream>

Data::Data() : alwaysTrueBool(true), strValue("Yep string"), coolIntCounter(69)
{
}

Data::Data(const Data &data) : alwaysTrueBool(data.alwaysTrueBool), strValue(data.strValue), coolIntCounter(data.coolIntCounter)
{
}

Data::~Data()
{
}

Data &Data::operator=(const Data &data)
{
	if (this != &data)
	{
		this->strValue = data.strValue;
		this->coolIntCounter = data.coolIntCounter;
	}
	return *this;
}

bool Data::getAlwaysTrueBool() const
{
	return alwaysTrueBool;
}

const std::string &Data::getStrValue() const
{
	return strValue;
}

int Data::getCoolIntCounter() const
{
	return coolIntCounter;
}

std::ostream &operator<<(std::ostream &os, const Data &data)
{
	os << "Data{ addr: " << &data << "; strValue: " << data.getStrValue() << "; alwaysTrueBool: "
	   << (data.getAlwaysTrueBool() ? "true" : "false") << "; coolIntCounter: " << data.getCoolIntCounter() << " }";
	return os;
}
