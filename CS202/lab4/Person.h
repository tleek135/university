/********************************************************************
 * Kyle Lee
 * Person.h
 * April 29, 2015
 * CSE 202 (Wednesday lab)
 * Description: Create a class that represents a person
   with a name, best friend, and popularity level.
 * Solution: Store name, best friend, and popularity as private 
   member variables. Include function prototypes for constructors,
   accessors, and mutators.
 * Percent complete: 100%
********************************************************************/

#ifndef PERSON_H
#define PERSON_H 

#include <string>

using namespace std;

//A class that holds a person's name, a pointer to his/her
//best friend, and the person's popularity (in terms of an integer),
//as well as accessor functions to get the name, popularity, etc.
//and a function to change the person's best friend through pointers
class Person
{
	string name;
	Person * best_friend;
	int popularity;
public:
    //Default constructor
	Person(): name(""), best_friend(0), popularity(0) { }
    //Constructor that initializes Person object with name
	Person(string n): name(n), best_friend(0), popularity(0) { }
	string get_name();
	string get_best_friend();
	int get_popularity();
	void set_best_friend(Person *);
};

#endif