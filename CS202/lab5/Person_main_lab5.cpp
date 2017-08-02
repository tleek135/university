/********************************************************************
 * Kyle Lee
 * Person_main_lab5.cpp
 * May 6, 2015
 * CSE 202 (Wednesday lab)
 * Description: Create a class that represents a person
   with a name, date of birth, and gender, then create related
   classes that represent a student and an instructor.
 * Solution: Store name, DOB, and gender as protected
   member variables. Include function prototypes for constructors,
   accessors, and mutators. Declare Student and Instructor as 
   classes derived from the base class Person.
 * Percent complete: 100%
********************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Represents a person with name, DOB, and gender
class Person
{
protected:
	string name;
	string dob;
	string gender;
public:
	//Default constructor
    Person(): name(""), dob(""), gender("") { }
    //Constructor that initializes name, DOB, gender
	Person(string n, string d, string g): name(n), dob(d), gender(g) { }
    //Prints name and DOB
	virtual void print() { cout << name << " " << dob << endl; }
};

//Represents a student with a major (derived from Person class)
class Student: public Person
{
protected:
	string major;
public:
    //Default constructor
	Student(): Person(), major("") { }
    //Constructor that initializes name, DOB, gender, major
	Student(string n, string d, string g, string m): Person(n, d, g), major(m) { }
    //Prints student name and major
	virtual void print() { Person::print(); cout << "    Student, Major: " << major << endl; }
};

//Represents an instructor with a salary (derived from Person class)
class Instructor: public Person
{
protected:
	int salary;
public:
    //Default constructor
	Instructor(): Person(), salary(0) { }
    //Initializes name, DOB, gender, and salary
	Instructor(string n, string d, string g, int s): Person(n, d, g), salary(s) { }
	//Prints instructor name and salary
    virtual void print()
	{
		if (gender == "M")
			cout << "Mr. ";
		else
			cout << "Ms. ";
		Person::print();
		cout << "    Instructor, Salary: " << salary << endl;
	}
};

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
