#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "IsoDate.hpp"
#include <iostream>
#include <string>
#include <map>
#include <typeinfo>
#include <fstream>

# define DB_FILEPATH "data.csv"
# define MAX_INPUT_VALUE 1000;

class BitcoinExchange
{
private:
	static const int MAX_VALUE;
	static const std::string DB_FILE;
	std::map<IsoDate, float> db;

private:
	std::pair<IsoDate, float> findByDateOrClosest(const IsoDate &date) const;

	void initDB();

	void parseInputFile(const std::string &filepath);

public:
	BitcoinExchange();

	BitcoinExchange(const std::string &filepath);

	BitcoinExchange(const BitcoinExchange &bitcoinExchange);

	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange bitcoinExchange);

	void parse(std::string filepath);

public:
	class DatabaseInitFailException : public std::exception
	{
	public:
		const char *what() const throw();
	};


	class InputGenericException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif //BITCOINEXCHANGE_HPP
