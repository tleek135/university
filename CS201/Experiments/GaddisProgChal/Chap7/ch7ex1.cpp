#include <iostream> 

using namespace std;

int main(){
	int store[10];
	int largest = store[0];
	int smallest = store[9];
	cout << "This program will ask for 10 values.\n";

	for (int order = 1; order < 11; ++order){
		cout << "Please enter value #" << order << ": ";
		cin >> store[order - 1];
		if (store[order - 1] < smallest)
			smallest = store[order - 1];
		else if (store[order - 1] > largest)
			largest = store[order - 1];
	}

	cout << "The smallest value is: " << smallest << endl;
	cout << "The largest value is: " << largest << endl;

}
