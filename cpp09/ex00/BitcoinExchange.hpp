#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "IsoDate.hpp"
#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::string filepath;
	std::map<IsoDate, float> db;
public:
	BitcoinExchange(const std::string &filepath);
	BitcoinExchange(const BitcoinExchange &bitcoinExchange);
	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange bitcoinExchange);




};


#endif //BITCOINEXCHANGE_HPP
