/********************************************************************
 * Kyle Lee
 * Person_main_using_UML.cpp
 * May 6, 2015
 * CSE 202 (Wednesday lab)
 * Description: Create a class that represents a person
   with a name, date of birth, and gender, then create related
   classes that represent a student and an instructor.
 * Solution: Model the classes from a UML diagram. Store name, 
   DOB, and gender as protected member variables. Include function 
   prototypes for constructors, accessors, and mutators. Declare 
   Student and Instructor as classes derived from the base class Person. 
 * Percent complete: 100%
********************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
#include "Student.h"
#include "Instructor.h"

using namespace std;

main()
{
    vector<Person *> dudes(4); 

    dudes[0] = new Person("Jack", "3/11/70", "M");
    
    dudes[1] = new Student("Katie", "4/12/80", "F", "CS");

    dudes[2] = new Instructor("Tom", "5/13/90", "M", 55000);
    dudes[3] = new Instructor("Pam", "6/14/80", "F", 60000);

    for (int i = 0; i < dudes.size(); i++)
        dudes[i]->print(); 

    Person p = *(dudes[2]); 
    p.print();

    for (int i = 0; i < dudes.size(); i++)
		delete dudes[i];
}
