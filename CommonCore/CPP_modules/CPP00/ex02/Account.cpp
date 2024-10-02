/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:49:30 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/25 16:15:49 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::checkAmount(void) const
{
	return _amount; //valot atual da conta
}

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;//amount de todas as contas 
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" <<  _accountIndex << ";"
			  << "p_amount:" << _amount - deposit << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits << std::endl;
	
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";
	if (checkAmount() < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount - withdrawal << ";"
			  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void Account::_displayTimestamp(void)
{
std::time_t result = std::time(NULL); //obtem o tempo atual
std::tm *timeInfo = std::localtime(&result); //passa o tempo atual para estrutura
std::cout << "[" << std::setfill('0') << 1900 + timeInfo->tm_year //ano atual
					<< std::setw(2) << 1 + timeInfo->tm_mon //mes atual
					<< std::setw(2) << std::setfill('0') << timeInfo->tm_mday << "_"
					<< std::setw(2) << std::setfill('0') << timeInfo->tm_hour
					<< std::setw(2) << std::setfill('0') << timeInfo->tm_min
					<< std::setw(2) << std::setfill('0') << timeInfo->tm_sec
					<< "] " << std::flush;
}
