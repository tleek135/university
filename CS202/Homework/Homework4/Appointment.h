/**********************************************************************
 * Kyle Lee
 * Appointment.h
 * June 13, 2015
 * CSE 202 (Wednesday lab)
 * Description: Create classes that represent appointments, as well
   as different appointment types (one-time, daily, monthly).
 * Solution: Since one-time, daily, and monthly are all appointment
   types, declare these classes as classes derived from the Appointment
   base class. Write a virtual function that can search for an 
   appointment date based on the type of appointment.
 * Percent complete: 90% (typescript missing)
**********************************************************************/
#include <string>

using namespace std;

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

//Represents a general appointment, with description and time of occurrence
class Appointment
{
protected:
	string description;
	int year, month, day, hour, minute;

public:
	//Default constructor
	Appointment(): description(""), year(-1), month(-1), day(-1), hour(-1), minute(-1) { }
	
	//Constructor with initialization values
	Appointment(string desc, int y, int mo, int d, int h, int min): description(desc), year(y), month(mo), day(d), hour(h), minute(min) { }
	
	//Retrieves description
	string get_description() { return description; }
	
	//Retrieves year
	int get_year() { return year; }
	
	//Retrieves month
	int get_month() { return month; }

	//Retrieves day
	int get_day() { return day; }

	//Retrieves hour
	int get_hour() { return hour; }

	//Retrieves minutes
	int get_minute() { return minute; }

	virtual bool occurs_on(int, int, int);

	virtual void print();
};

//Checks whether an appointment occurs at a specified time
bool Appointment::occurs_on(int year, int month, int day)
{
	if (year == get_year() and month == get_month() and day == get_day()) {
		return true;
	} else {
		return false;
	}
}

//Prints appointment details
void Appointment::print()
{
	cout << "Description: " << description << endl;
	cout << "Time: " << hour << ":" << minute << endl;
}

//Represents a one-time appointment, with all date and time details
class Onetime : public Appointment
{
public:
	//Default constructor
	Onetime(): Appointment() { }

	//Constructor that initializes all fields
	Onetime(string desc, int y, int mo, int d, int h, int min): Appointment(desc, y, mo, d, h, min) { }

	virtual bool occurs_on(int, int, int);

	//Prints appointment details and "one-time" tag
	void print() { Appointment::print(); cout << "Type: One-time" << endl; }
};

//Tests for one-time appointment date
bool Onetime::occurs_on(int year, int month, int day)
{
	if (Appointment::occurs_on(year, month, day)) {
			return true;
	} else {
		return false;
	}
}

//Represents a monthly appointment, with only the "day" field present
class Monthly : public Appointment
{
public:
	//Default constructor
	Monthly(): Appointment() { }

	//Constructor that initializes day and time fields
	Monthly(string desc, int d, int h, int min): Appointment(desc, -1, -1, d, h, min) { }

	virtual bool occurs_on(int, int, int);

	//Prints appointment details and "monthly" tag
	void print() { Appointment::print(); cout << "Type: Monthly" << endl; }
};

//Tests if monthly appointment occurs on a certain day
bool Monthly::occurs_on(int year, int month, int day)
{
	if (get_day() == day) {
		return true;
	} else {
		return false;
	}
}

//Represents a daily appointment, with the "hour" and "minute" field only
class Daily : public Appointment
{
public:
	//Default constructor
	Daily(): Appointment() { }

	//Constuctor that initializes time fields
	Daily(string desc, int h, int min): Appointment(desc, -1, -1, -1, h, min) { }

	virtual bool occurs_on(int, int, int);

	//Prints appointment details and "daily" tag
	void print() { Appointment::print(); cout << "Type: Daily" << endl; }
};

//Tests if daily appointment occurs at a certain time (hour and minute)
bool Daily::occurs_on(int year, int month, int day)
{
	return true;
}

#endif
