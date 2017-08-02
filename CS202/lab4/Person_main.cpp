/**********************************************************
 * Kyle Lee
 * Person_main.cpp
 * April 29, 2015
 * CSE 202 (Wednesday lab)
 * Description: Test Person.h and Person.cpp
 * Solution: Create objects of class Person, store pointers
   to these objects in a vector, ask for best friend of each
   person, and print the person's name, best friend, and 
   popularity.
 * Percent complete: 100%
**********************************************************/

#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>

#include "Person.h"

using namespace std;

main()
{
	string name;
	vector<Person *> people;
	Person * person_pointer;

	cout << "Enter the names, terminate with -1: ";
	cin >> name;
	while (name != "-1") {
		person_pointer = new Person(name);
		people.push_back(person_pointer);
		
		cout << "Enter another name, end with -1: ";
		cin >> name;

		//checks for duplicate names
		for (int i = 0; i < people.size(); ++i) {
			if (name == people[i]->get_name()) {
				cout << "You have already entered that name. Please enter "
				     << "a different name: ";
				cin >> name;
				i = -1;
			}
		}
		
	}

	int i, j;

	//for each person prompt for a best friend name
	for (i = 0; i < people.size(); i++) {
		cout << "Who is " << people[i]->get_name() << "'s best friend? ";
		cin >> name;
    
    // search for best friend
        for (j = 0; j < people.size(); j++) {
            if (people[j]->get_name() == name) {
                people[i]->set_best_friend(people[j]);
                break;
            }
        	//Prompts user for another name if best friend not found
        	else if (j == people.size() - 1) {
            	cout << "Couldn't find best friend " << name << endl;
            	cout << "Please enter a different name for "
            	     << people[i]->get_name() << "'s best friend: ";
           		cin >> name;
           		j = -1;
    		}
    	}	

    }

    // list of name, best friend, and popularity count
    for (i = 0; i < people.size(); i++) {
        person_pointer = people[i];
        cout << left << setw(10) << person_pointer->get_name();
        cout << left << setw(10) << person_pointer->get_best_friend();
        cout << right << setw(2) << person_pointer->get_popularity() << endl;
    }

    // clean up
    for (i = 0; i < people.size(); i++)
        delete people[i];
}