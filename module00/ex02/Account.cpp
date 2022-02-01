#include <iostream>
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
			  << ";created:" << std::endl;
}

Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created:" << std::endl;
}

Account::~Account() {
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
	std::cout << "accounts:" << Account::_nbAccounts
	<< ";total:" << Account::_totalAmount
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void		Account::makeDeposit(int deposit) {
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal) {
	int	tmp;

	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;
	tmp = this->_amount - withdrawal;
	if (tmp < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount = tmp;
	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return (true);
}

int			Account::checkAmount() const {
	return (this->_amount);
}

void		Account::displayStatus() const {
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


static void	_displayTimestamp( void );

void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const;
