#include "BitcoinExchange.hpp"
#include <ostream>


const std::string BitcoinExchange::DB_FILE = DB_FILEPATH;
const int BitcoinExchange::MAX_VALUE = MAX_INPUT_VALUE;

void BitcoinExchange::initDB()
{
	std::ifstream file(BitcoinExchange::DB_FILE.c_str());

	if (!file.is_open() || file.fail())
	{
		std::cerr << "Error: could not open the file [" << BitcoinExchange::DB_FILE << "]." << std::endl;
		throw DatabaseInitFailException();
	}
	std::string line;

	for (int i = 1; getline(file, line); ++i)
	{
		if (i == 1 && line == "date,exchange_rate")
			continue;

		std::size_t commaPos = line.find(',');

		if (commaPos == std::string::npos)
		{
			std::cerr << "Error: invalid line [" << i << "]" << std::endl;
			throw DatabaseInitFailException();
		}

		std::string rawDate = line.substr(0, commaPos);
		std::string rawValue = line.substr(commaPos + 1);
		IsoDate date;
		try
		{
			date = IsoDate::parseIsoDate(rawDate);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: invalid date at line [" << i << "]" << std::endl;
			throw DatabaseInitFailException();
		}
		char *end;
		float value = std::strtof(rawValue.c_str(), &end);

		if (end == rawDate.c_str() || *end != '\0')
		{
			std::cerr << "Error: invalid value at line [" << i << "]" << std::endl;
			throw DatabaseInitFailException();
		}
		this->db[date] = value;
	}
}

void BitcoinExchange::parseInputFile(const std::string &filepath)
{
	std::ifstream file(filepath.c_str());

	if (!file.is_open() || file.fail())
	{
		std::cerr << "Error: could not open the file [" << filepath << "]." << std::endl;
		throw InputGenericException();
	}
	std::string line;
	if (db.empty())
	{
		std::cerr << "Database is empty" << std::endl;
		throw InputGenericException();
	}

	for (int i = 1; getline(file, line); ++i)
	{
		if (i == 1 && line == "date | value")
			continue;
		std::cout << "["<<i<<"]\t";
		std::size_t pipePos = line.find(" | ");

		if (pipePos == std::string::npos || pipePos == 0 || pipePos == line.size() - 3)
		{
			std::cout << "Error: bad input [" << line << "]." << std::endl;
			continue;
		}

		std::string rawDate = line.substr(0, pipePos);
		if (rawDate.length() != 10)
		{
			std::cout << "Error: bad input [" << line << "]." << std::endl;
			continue;
		}

		IsoDate date;
		try
		{
			date = IsoDate::parseIsoDate(rawDate);
		} catch (std::exception &e)
		{
			std::cout << "Error: bad date => " << rawDate << std::endl;
			continue;
		}

		std::string rawValue = line.substr(pipePos + 3);
		char *end;
		float value = std::strtof(rawValue.c_str(), &end);

		if (end == rawDate.c_str() || *end != '\0')
		{
			std::cout << "Error: invalid value => " << rawValue << std::endl;
			continue;
		}
		if (value < 0.0)
		{
			std::cout << "Error: value must be positive => " << value << std::endl;
			continue;
		}
		if (value > BitcoinExchange::MAX_VALUE)
		{
			std::cout << "Error: value is too large => " << value << std::endl;
			continue;
		}
		try
		{
			const std::pair<IsoDate, float> &foundRecord = this->findByDateOrClosest(date);
			std::cout << "input date: " << date
					  << "\t(found: " << foundRecord.first << "; price: " << foundRecord.second << ");\t\t"
					  << "=> input value: " << value << "\t= total: " << foundRecord.second * value << std::endl;
		} catch (std::exception &e)
		{
			std::cout << "Error: could not find the requested date or the closest one (line [" << line << "])" << std::endl;
		}
	}
}

std::pair<IsoDate, float> BitcoinExchange::findByDateOrClosest(const IsoDate &date) const
{
	std::map<IsoDate, float>::const_iterator it = this->db.find(date);

	if (it != this->db.end())
	{
		return std::make_pair(it->first, it->second);
	}

	it = this->db.lower_bound(date);

	if (it == this->db.begin())
	{
		throw DateNotFoundException();
	}

	--it;
	return std::make_pair(it->first, it->second);
};

BitcoinExchange::BitcoinExchange()
{
	this->initDB();
}

BitcoinExchange::BitcoinExchange(const std::string &filepath)
{
	this->initDB();
	this->parseInputFile(filepath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange) : db(bitcoinExchange.db)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange bitcoinExchange)
{
	if (this != &bitcoinExchange)
	{
		std::swap(this->db, bitcoinExchange.db);
	}
	return *this;
}

void BitcoinExchange::parse(const std::string &filepath)
{
	this->parseInputFile(filepath);
}

// EXCEPTIONS------------------------------------------------------------------
const char *BitcoinExchange::DatabaseInitFailException::what() const throw()
{
	return "Could not initialize the database";
}

const char *BitcoinExchange::InputGenericException::what() const throw()
{
	return "Could not parse the input file";
}
// ----------------------------------------------------------------------------
const char *BitcoinExchange::DateNotFoundException::what() const throw()
{
	return "Date not found";
}
