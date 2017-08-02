/************************************************************************************
 * Kyle Lee
 * Account_main_2.cpp
 * April 8, 2015
 * This file creates an instance of the Account class and tests the member functions.
************************************************************************************/

#include <iostream>

#include "Account.h"

using namespace std;

main()
{
	Account savings(10000, 6);
	int yrs = 0;

	for (int count = 0; savings.query() < 20000; ++count) {
		savings.add_interest();
		yrs++;
	}

	cout << "It will take " << yrs << " years for $10,000 to double "
		 << "at an interest rate of 6%.\n";
}
