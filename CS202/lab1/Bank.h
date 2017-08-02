#ifndef BANK_H
#define BANK_H

//Kyle Lee
//Bank.h
//April 10, 2015
//This file declares the Bank class, with simulated checking
//and savings accounts.

#include <string>

#include "Account.h"

using namespace std;

class Bank
{
private:
	Account savings;
	Account checking;
public:
	Bank();
	Bank(double savings_amount, double checking_amount);
	void deposit(double amount, string account);
	void withdraw(double amount, string account);
	void transfer(double amount, string account);
	void print_balances();
};

#endif
