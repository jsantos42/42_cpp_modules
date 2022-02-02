#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

/*	Initializing the static/class/non-member attributes. */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
 * Constructors and Destructor.
 * Incrementing the nbAccounts with each Account instance creation.
 */

Account::Account() {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::Account(int initial_deposit) {
	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

/*
 * Getters for static/class/non-member attributes.
 */

int	Account::getNbAccounts() { return (Account::_nbAccounts); }
int	Account::getTotalAmount() { return (Account::_totalAmount); }
int	Account::getNbDeposits() { return (Account::_totalNbDeposits); }
int	Account::getNbWithdrawals() { return (Account::_totalNbWithdrawals); }

/*
 *	Displaying the info for every account.
 */

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
	<< ";total:" << Account::_totalAmount
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void		Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	std::cout << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal) {
	int	tmp;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;
	tmp = this->_amount - withdrawal;
	if (tmp < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount = tmp;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbDeposits << std::endl;
	return (true);
}

int			Account::checkAmount() const {
	_displayTimestamp();
	return (this->_amount);
}

void		Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


void	Account::_displayTimestamp() {
	time_t	now;
	tm*		time_struct;

	time(&now);
	time_struct = localtime(&now);
	std::cout << '[' << time_struct->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << time_struct->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << time_struct->tm_mday;
	std::cout << '_'
			  << std::setfill('0') << std::setw(2) << time_struct->tm_hour
			  << std::setfill('0') << std::setw(2) << time_struct->tm_min
			  << std::setfill('0') << std::setw(2) << time_struct->tm_sec
			  << "] ";
}







