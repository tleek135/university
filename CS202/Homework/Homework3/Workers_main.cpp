/**********************************************************************
 * Kyle Lee
 * Workers_main.cpp
 * May 24, 2015
 * CSE 202 (Wednesday lab)
 * Description: Test the base Worker class and its two derived classes,
   HourlyWorker and SalariedWorker. 
 * Solution: Create instances of each class, use their constructors
   to initialize name and pay rate, and call the compute_pay function
   for each object to ensure that the proper function is being used.
 * Percent complete: 100%
**********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Workers.h"

using namespace std;

main()
{
	vector<Worker *> employees(4);

	employees[0] = new Worker("Rivers Cuomo", 11.00);
	employees[1] = new SalariedWorker("Brian Bell", 11.00);
	employees[2] = new HourlyWorker("Patrick Wilson", 12.50);
	employees[3] = new HourlyWorker("Scott Shriner", 12.50); 

	for (int i = 0; i < employees.size(); i++) {
		int hours;
		
		cout << setprecision(2) << fixed;
		cout << "Worker Name: " << employees[i]->get_name() << endl
			 << "Hourly Rate: $" << employees[i]->get_rate() << endl;
		cout << "How many hours did this employee work this week? ";
		cin >> hours;
		cout << "Weekly earnings is: $" << employees[i]->compute_pay(hours) << endl << endl;
	}

	for (int i = 0; i < employees.size(); i++)
		delete employees[i];

}

