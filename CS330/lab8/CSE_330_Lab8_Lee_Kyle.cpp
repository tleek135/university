// Class: CSE 330
// Term: Fall 2015
// Instructor: George M. Georgiou
// Name: Kyle Lee
// Lab 8
// Title: Multiset and Multimap

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>

using namespace std;

main()
{
	int arr[] = {3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9, 10};

	//Initialize multiset from values in array
	multiset<int> ms(arr, arr+12);
	multiset<int>::iterator setIter;

	setIter = ms.begin();
	int number;

	//Remove all instances of a number from the mulitset, 
	//then re-insert one copy of that number
	while (setIter != ms.end()) {
		if (ms.count(*setIter) > 1) {
			number = *setIter;
			ms.erase(*setIter);
			ms.insert(number);
		}

	setIter++;

	}
	
	cout << "The remaining elements in the multiset after duplicates "
		 << "are removed are: ";

	//Display all elements in multiset after duplicate removal
	for (setIter = ms.begin(); setIter != ms.end(); setIter++)
		cout << *setIter << " ";		

	cout << endl;

	
	multimap<string, int> mm;
	multimap<string, int>::iterator mapIter;

	//for converting integer to string (to make keys for multimap)
	ostringstream converter;
	string key;
	int value;
	pair<string, int> temp;

	//Do integer-to-string conversion, then use string and integer
	//as key and value to be inserted into multimap
	for (int i = 0; i < 12; i++) {
		value = arr[i];
		converter << value;
		key = converter.str();
		converter.str("");

		temp = make_pair(key, value);
		mm.insert(temp);

	}

	//Search for and erase elements that have the same key
	mapIter = mm.begin();
	while (mapIter != mm.end()) {
		if (mm.count(mapIter->first) > 1) {
			temp = *mapIter;
			mm.erase(mapIter->first);
			mm.insert(temp);
		}
	
	mapIter++;
	}

	cout << "The remaining elements in the multimap after duplicates "
		 << "are removed are: ";

	//Display all elements in multimap after duplicate removal
	for (mapIter = mm.begin(); mapIter != mm.end(); mapIter++) {
		cout << mapIter->second << " ";		
	}
	
	cout << endl;
	
}
		
