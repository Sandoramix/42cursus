#include "IsoDate.hpp"

static bool isAllDigits(const std::string &s)
{
	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		if (!isdigit(*it))
			return false;
	}
	return true;
}

void IsoDate::validateValues()
{
	if (year < IsoDate::minYear)
		throw InvalidDateException();
	if (month < 1 || month > 12)
		throw InvalidDateException();
	if (day < 1 || day > 31)
		throw InvalidDateException();

	// February
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeap ? 29 : 28))
			throw InvalidDateException();
	}

	// April, June, September, November have 30 days
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			throw InvalidDateException();
	}
}

void IsoDate::parse(std::string raw)
{
	if (raw.length() != 10 || raw[4] != '-' || raw[7] != '-')
	{
		throw InvalidDateException();
	}


	std::string yearPart = raw.substr(0, 4);
	std::string monthPart = raw.substr(5, 2);
	std::string dayPart = raw.substr(8, 2);


	if (!isAllDigits(yearPart) || !isAllDigits(monthPart) || !isAllDigits(dayPart))
	{
		throw InvalidDateException();
	}

	char *end = NULL;

	this->year = strtol(yearPart.c_str(), &end, 10);
	this->month = strtol(monthPart.c_str(), &end, 10);
	this->day = strtol(dayPart.c_str(), &end, 10);

	this->validateValues();
}

IsoDate IsoDate::parseIsoDate(std::string raw)
{
	return IsoDate(raw);
}

IsoDate::IsoDate(std::string isostringdate)
{
	this->parse(isostringdate);
}

IsoDate::IsoDate(const IsoDate &isoDate)
	: year(isoDate.year), month(isoDate.month), day(isoDate.day)
{
	this->validateValues();
}

IsoDate::~IsoDate()
{
}

std::string IsoDate::isoDateString() const
{
	std::stringstream ss;

	ss << this->year
	   << "-" << (this->month < 10 ? "0" : "") << this->month
	   << "-" << (this->day < 10 ? "0" : "") << this->day;

	return ss.str();
}

// GETTERS---------------------------------------------------------------------

int IsoDate::getYear() const
{
	return year;
}

int IsoDate::getMonth() const
{
	return month;
}

int IsoDate::getDay() const
{
	return day;
}

// ----------------------------------------------------------------------------

IsoDate &IsoDate::operator=(const IsoDate &isoDate)
{
	this->year = isoDate.year;
	this->month = isoDate.month;
	this->day = isoDate.day;
	this->validateValues();
	return *this;
}

bool IsoDate::operator<(const IsoDate &other) const
{
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
}

std::ostream &operator<<(std::ostream &os, const IsoDate &dt)
{
	os << dt.isoDateString();
	return os;
}

// ----------------------------------------------------------------------------
const char *IsoDate::InvalidDateException::what() const throw()
{
	return "Invalid date";
}
