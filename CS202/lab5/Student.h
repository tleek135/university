/********************************************************************
 * Kyle Lee
 * Student.h
 * May 6, 2015
 * CSE 202 (Wednesday lab)
 * Description: Create a class that represents a student 
   with name, DOB, and gender, as well as a major.
 * Solution: Define Student class as a class derived from Person 
   class, and include prototypes for usual constructor and print 
   functions. 
 * Percent complete: 100%
********************************************************************/

#ifndef Student_h
#define Student_h

#include "Person.h"
#include <string>

using namespace std;

//Represents a student with a major, as well as
//basic information (name, DOB, gender) from Person class
class Student: public Person
{
public:
	Student();
	Student(string n, string d, string g, string m);
	virtual void print();
protected:
	string major;
};

#endif // Student_h
