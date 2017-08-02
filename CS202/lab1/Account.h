#ifndef ACCOUNT_H
#define ACCOUNT_H

/***************************************
 * Kyle Lee
 * Account.h
 * April 8, 2015
 * This file declares the Account class.
***************************************/

//This class simulates a bank account, with a balance and deposit/withdrawal options.
//It can also accept an interest rate and calculate the interest.
class Account 
{
private:
	double balance;
	double interest_rate; //for example, interest_rate = 6 means 6%
public:
	Account();
	Account(double amount, double rate);
	void deposit(double);
	bool withdraw(double); //returns true if enough money, returns false otherwise
	double query();
	void set_interest_rate (double rate);
	double get_interest_rate();
	void add_interest();
};

#endif
    
