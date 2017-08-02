//Kyle Lee
//Bank.cpp
//April 10, 2015
//This file implements the member functions of the Bank class,
//which can withdraw, transfer, deposit money, etc.
//Percent completed: 100%

#include <iostream>
#include <string>

#include "Account.h"
#include "Bank.h"

using namespace std;

//Default constructor
Bank::Bank() { }

//Assigns initial balances to checking and savings accounts
Bank::Bank(double savings_amount, double checking_amount)
{
	savings.deposit(savings_amount);
	checking.deposit(checking_amount);
}

//Deposits money into either checking or savings 
void Bank::deposit(double amount, string account)
{
	if (account == "S")
		savings.deposit(amount);
	else if(account == "C")
		checking.deposit(amount);
}

//Withdraws money from either checking or savings
void Bank::withdraw(double amount, string account)
{
	if (account == "S")
		savings.withdraw(amount);
	else if (account == "C")
		checking.withdraw(amount);
}

//Transfers money from one account to another
void Bank::transfer(double amount, string account)
{
	if (account == "S") {
		savings.withdraw(amount);
		checking.deposit(amount);
	}
	else if (account == "C"){
		checking.withdraw(amount);
		savings.deposit(amount);
	}
}

//Displays current balances of checking and savings accounts
void Bank::print_balances()
{
	cout << "Savings Balance: $" << savings.query() << endl;
	cout << "Checking Balance: $" << checking.query() << endl;
}



