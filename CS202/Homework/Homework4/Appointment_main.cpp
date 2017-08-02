/********************************************************************
 * Kyle Lee
 * Appointment_main.cpp
 * June 13, 2015
 * CSE 202 (Wednesday lab)
 * Description: Test the functionality of the Appointment class
   and all of its derived classes.  
 * Solution: Create a vector of pointers to Appointment objects; this
   will allow you to store pointers to objects of Appointment's derived
   classes as well. Call the member functions on each object to search
   for an appointment. 
 * Percent complete: 90% (typescript missing)
*********************************************************************/
#include <vector>
#include <iostream>
#include <string>

#include "Appointment.h"

using namespace std;

//Creates instances of Appointment class and its derived classes,
//then tests their member functions
main()
{
	vector<Appointment *> appts;
	int year, month, day, hour, minute, choice;
	string description;

	appts.push_back(new Appointment("generic", 2015, 3, 7, 22, 15));
	appts.push_back(new Onetime("DMV", 2015, 4, 16, 16, 30));
	appts.push_back(new Monthly("basketball game", 7, 12, 45));
	appts.push_back(new Daily("go to school", 11, 10));

	cout << "To add an appointment, type a description and press Enter: ";
	getline(cin, description);

	cout << "Enter the appointment year, month, day, hour, and minute, all separated by spaces, or "
	     << "type ctrl-d and enter when finished: ";
	cin >> year >> month >> day >> hour >> minute;

	while (!cin.eof()) {
		cout << "Enter 1 for one-time appointment, 2 for monthly, or 3 for daily: ";
		cin >> choice;

		if (choice == 1) 
			appts.push_back(new Onetime(description, year, month, day, hour, minute));
		else if (choice == 2)
			appts.push_back(new Monthly(description, day, hour, minute));
		else if (choice == 3)
			appts.push_back(new Daily(description, hour, minute));
	}

	cin.clear();

	cout << "Please enter a year, month, and day (separated by spaces) of an "
	     << "appointment that you wish to search for, or type ctrl-d and Enter when done: ";
	cin >> year >> month >> day;

	while (!cin.eof()) {
		for (int i = 0; i < appts.size(); i++) {
			if (appts[i]->occurs_on(year, month, day))
				appts[i]->print();
		}

		cout << "Enter another year, month, and day separated by spaces, or type ctrl-d and enter when done: ";
		cin >> year >> month >> day;
	}

}
