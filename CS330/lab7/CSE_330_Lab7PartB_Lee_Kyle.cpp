// Class: CSE 330
// Term: Fall 2015
// Instructor: George M. Georgiou
// Name: Kyle Lee
// Lab 7
// Title: Ch. 11 #27, Part B (multiset)
//Initialize a multiset with certain city and state values,
//then use a find() function to determine if a certain 
//city/state is in the multiset. Test all possible keys, as
//well as one key that is not in the multiset.

#include <iostream>
#include <set>
#include "d_state.h" //declaration of stateCity class

main()
{
	string stateName; //to hold user input
	multiset<stateCity> ms;
	multiset<stateCity>::iterator iter;

	//Create instances of stateCity, then put them into the multiset
	stateCity first("Arizona", "Phoenix");
	ms.insert(first);
	stateCity second("Illinois", "Chicago");
	ms.insert(second);
	stateCity third("Illinois", "Gary");
	ms.insert(third);
	stateCity fourth("Nevada", "Reno");
	ms.insert(fourth);
	stateCity fifth("Illinois", "Evanston");
	ms.insert(fifth);
	stateCity sixth("California", "Sacramento");
	ms.insert(sixth);
	
	//Ask for user input
	cout << "Please enter the name of a state: ";
	cin >> stateName;

	iter = ms.find(stateName);

	//If state is found, display all cities of that state;
	//If not, display error message
	if (iter == ms.end())
		cout << stateName << " was not found.\n";
	else {
		while (iter != ms.end()) {
		cout << *iter << endl;
		ms.erase(iter);
		iter = ms.find(stateName);
		}
	}

}
