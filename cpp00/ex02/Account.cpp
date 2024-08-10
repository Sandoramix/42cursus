#include "Account.hpp"
#include <sstream>

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_totalAmount += this->_amount;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "created" << std::endl;
};

Account::Account()
{
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_accountIndex = _nbAccounts;

	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "created" << std::endl;
};

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "closed" << std::endl;
}


// STATIC VARIABLES------------------------------
int    Account::_nbAccounts = 0;
int    Account::_totalAmount = 0;
int    Account::_totalNbDeposits = 0;
int    Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}
//-----------------------------------------------

static std::string padTime(int val)
{
	std::string res;
	if (val < 10)
		res.append("0");
	std::ostringstream ss;
	ss << val;
	res.append(ss.str());
	return res;
}

void Account::_displayTimestamp(void)
{
	std::time_t time = std::time(0);
	std::tm *now = localtime(&time);

	std::cout << "["
			  << (now->tm_year + 1900) << padTime(now->tm_mon + 1) << padTime(now->tm_mday)
			  << "_" << padTime(now->tm_hour) << padTime(now->tm_min) << padTime(now->tm_sec)
			  << "] ";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << _amount << ";";
	if (deposit < 0)
	{
		std::cout << "deposit:refused" << std::endl;
		return;
	}

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << "deposit:" << deposit << ";"
			  << "amount:" << this->_amount << ";"
			  << "nb_deposits:" << this->_nbDeposits << ";"
			  << std::endl;
}


bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << _amount << ";";
	if (withdrawal < 0 || withdrawal >= this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << "withdrawal:" << withdrawal << ";"
			  << "amount:" << this->_amount << ";"
			  << "nb_withdrawals:" << this->_nbWithdrawals << ";"
			  << std::endl;
	return true;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
			  << "total:" << _totalAmount << ";"
			  << "deposits:" << _totalNbDeposits << ";"
			  << "withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";"
			  << "deposits:" << this->_nbDeposits << ";"
			  << "withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

//-----------------------------------------------
