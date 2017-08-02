/***************************************************************
 * Kyle Lee
 * Person.h
 * April 20, 2015
 * Problem description: Write a class Person that stores name and
   birthday.
 * Solution: Declare and write constructors, accessor functions,
   mutator functions, etc. Use multiple vectors to store data
   and then relate this data to each other with subscripts.
 * Percent completed: 25% (Person.cpp not completed)
***************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

//A class that stores a name and birthday
class Person
{
private:
	string name;
	string month;
	string day;
	string year;
public:
	Person();
	void change_name(string);
	void change_month(string);
	void change_day(string);
	void change_year(string);
	string find_April();
};
	