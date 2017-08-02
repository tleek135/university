//Kyle Lee
//Bank_main.cpp
//April 10, 2015
//This file creates an instance of the Bank class, as well as
//calls its member functions as a test. 

#include <iostream>
#include <string>

#include "Bank.h"

using namespace std;

main()
{
	Bank csusb_bank(1000, 100);

	csusb_bank.deposit(50, "S");
	csusb_bank.withdraw(10, "CH");
	csusb_bank.withdraw(10, "C");
	csusb_bank.transfer(40, "S");
	csusb_bank.withdraw(150, "C");
	csusb_bank.print_balances();
}

