/*****************************************************************
 * Kyle Lee
 * Account.cpp
 * April 8, 2015
 * This file implements the member functions of the Account class. 
 * Percent completed: 100%
*****************************************************************/

#include <iostream>

#include "Account.h"

using namespace std;

//This function initializes the member variables to 0.
Account::Account()
{
	balance = 0; 
	interest_rate = 0;
}

//This function initializes the member variables to custom amounts.
Account::Account(double amount, double rate) 
{
	balance = amount;
	interest_rate = rate;
}

//This function adds to the bank balance.
void Account::deposit(double amount)
{
	balance += amount;
}

//This function penalizes the user if he/she withdraws
//more than the amount in the account. 
bool Account::withdraw(double amount)
{
	bool status;

	if (amount > balance) {
		balance -= 5; //penalty
		status = false;
	} else {
		balance -= amount;
		status = true;
	}

	return status;
}

//This function returns the current balance of the account.
double Account::query()
{
	return balance;
}

//This function allows the user to set the interest rate.
//Example: interest_rate = 8 means 8%
void Account::set_interest_rate(double rate)
{
	interest_rate = rate;
}

//This function returns the interest rate. 
double Account::get_interest_rate()
{
	return interest_rate;
}

//This function adds the accumulated interest to 
//the balance.
void Account::add_interest()
{
	balance += balance * (interest_rate * 0.01);
}
