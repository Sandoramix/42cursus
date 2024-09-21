#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

class IsoDate
{
private:
	static const int minYear = 0;

private:
	int year;
	int month;
	int day;

private:
	void parse(std::string raw);

	void validateValues();

public:
	static IsoDate parseIsoDate(std::string raw);

	IsoDate();

	IsoDate(const std::string &isostringdate);

	IsoDate(const IsoDate &isoDate);

	~IsoDate();

	IsoDate &operator=(const IsoDate &isoDate);

	bool operator<(const IsoDate &other) const;

	std::string isoDateString() const;

	int getYear() const;

	int getMonth() const;

	int getDay() const;

public:
	class InvalidDateException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const IsoDate &dt);

#endif //DATE_HPP
