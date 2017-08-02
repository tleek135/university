/********************************************************************
 * Kyle Lee
 * Person.cpp
 * May 6, 2015
 * CSE 202 (Wednesday lab)
 * Description: Implement functions found in Person.h file
 * Solution: Include constructors to initialize values (name, DOB, gender)
   and a print function to display these values 
 * Percent complete: 100%
********************************************************************/

#include <string>
#include <iostream>

#include "Person.h"

using namespace std;

//Default constructor
Person::Person(): name(""), dob(""), gender("") { }
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:000000000000087B begin


// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:000000000000087B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

//Constructor that initializes name, DOB, and gender
Person::Person(string n, string d, string g): name(n), dob(d), gender(g) { }
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:000000000000087E begin


// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:000000000000087E end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

//Prints name and DOB
void Person::print() { cout << name << " " << dob << endl; }
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:0000000000000893 begin


// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:0000000000000893 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element