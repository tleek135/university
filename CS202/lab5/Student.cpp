/********************************************************************
 * Kyle Lee
 * Student.cpp
 * May 6, 2015
 * CSE 202 (Wednesday lab)
 * Description: Write functions to set and print basic information 
   (including major) about a student. 
 * Solution: Use functions from base class Person, and expand on these 
   functions with additional functionality (adding the major, etc.).
 * Percent complete: 100%
********************************************************************/

#include <string>
#include <iostream>

#include "Student.h"

using namespace std;

//Default Constructor
Student::Student(): Person(), major("") { }
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:000000000000088B begin

// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:000000000000088B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

//Constructor that sets name, DOB, and gender
Student::Student(string n, string d, string g, string m): Person(n,d,g), major(m){ }
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:000000000000088D begin

// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:000000000000088D end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

//Prints student name and major
void Student::print() { Person::print(); cout << "    Student, Major: " << major << endl; }
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:0000000000000897 begin

// section -117--74--108--126-566dc4d1:14d2b87c0eb:-8000:0000000000000897 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element
