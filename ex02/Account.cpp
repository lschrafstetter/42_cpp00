/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:09:25 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/17 13:08:58 by lschrafs         ###   ########.fr       */
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

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::_displayTimestamp(void) {
  time_t t = time(NULL);
  tm *tm = localtime(&t);

  std::cout << "[" << (tm->tm_year + 1900) << std::setw(2) << std::setfill('0')
            << tm->tm_mon << std::setw(2) << std::setfill('0') << tm->tm_mday
            << "_" << std::setw(2) << std::setfill('0') << tm->tm_hour
            << std::setw(2) << std::setfill('0') << tm->tm_min << std::setw(2)
            << std::setfill('0') << tm->tm_sec << "]";
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
  // Set private attributes and edit nonmember variables
  this->_accountIndex = _nbAccounts;
  _nbAccounts++;
  this->_amount = initial_deposit;
  _totalAmount += initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  // Print log
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << std::endl;
}

Account::~Account(void) {
  // Print log
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  // Print log part 1
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex
            << ";p_amount:" << this->_amount;

  // Make deposit
  this->_amount += deposit;
  this->_nbDeposits++;
  _totalAmount += deposit;
  -_totalNbDeposits++;

  // Print log part 2
  std::cout << ";deposit:" << deposit << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  // Print log part 1
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:";

  // Make withdrawal
  if (withdrawal > this->_amount) {
    std::cout << "refused" << std::endl;
    return false;
  }
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  _totalAmount -= withdrawal;
  -_totalNbWithdrawals++;

  // Print log part 2
  std::cout << withdrawal << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const { return this->_amount; }

void Account::displayStatus(void) const {
  // Print log
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}