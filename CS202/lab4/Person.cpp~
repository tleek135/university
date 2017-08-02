/******************************************************
 * Kyle Lee
 * Person.cpp
 * April 29, 2015
 * CSE 202 (Wednesday lab)
 * Description: Implement the member functions of 
   the Person class.
 * Solution: Includes constructors that initialize 
   values, accessors that return name, pointer to a 
   best friend, and popularity. Includes a mutator 
   function to set the best friend pointer. 
 * Percent complete: 100%
******************************************************/

#include "Person.h"

//Gets the name of an object of class Person
string Person::get_name()
{
    return name;
}

//Checks for null pointer, then gets the name of 
//a person's best friend if pointer is not null
string Person::get_best_friend()
{
    if (best_friend != 0) //check for null pointer
        return best_friend->name;
    else return "";
}

//Gets popularity of a given object of class Person
int Person::get_popularity()
{
    return popularity;
}

//Sets a person's best friend and increases the
//popularity of that friend
void Person::set_best_friend(Person * bf)
{
    best_friend = bf;
    (bf->popularity)++;
}
