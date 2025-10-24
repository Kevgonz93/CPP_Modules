#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm* late = std::localtime(&now);
	std::cout << "[" 
		<< (late->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << late->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << late->tm_mday << "_"
		<< std::setw(2) << std::setfill('0') << late->tm_hour
		<< std::setw(2) << std::setfill('0') << late->tm_min
		<< std::setw(2) << std::setfill('0') << late->tm_sec << "] ";
	std::cout << std::setfill(' ');
}

Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts),
  _amount(initial_deposit),
  _nbDeposits(0),
  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}
int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	          << ";total:" << getTotalAmount()
	          << ";deposits:" << getNbDeposits()
	          << ";withdrawals:" << getNbWithdrawals()
	          << std::endl;
}

void Account::makeDeposit( int deposit )
{
	int p = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << p
	          << ";deposit:" << deposit
	          << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits
	          << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << p
	          << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << withdrawal
	          << ";amount:" << _amount
	          << ";nb_withdrawals:" << _nbWithdrawals
	          << std::endl;
	return true;
}

int Account::checkAmount( void ) const
{
	return _amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals
	          << std::endl;
}
