//Program written by: Kyle Lee (005054981)
//Lab 3, Exercise 1

/*
Test Cases	Prime?
----------	------
5		yes
13		yes
23		yes
31		yes
9		no
16		no
54		no
63		no
*/

#include <iostream>

using namespace std;

int main(int argc, char * args[]){
	int UserNumber;

	cout << "Please enter an integer greater than 1: ";
	cin >> UserNumber;

	if (UserNumber == 2)
		cout << UserNumber << " is prime." << endl;

	for (int Divisor = 2; Divisor < UserNumber; Divisor++){
		if (UserNumber % Divisor == 0){
			cout << UserNumber << " is not prime." << endl;
			break;
		}
		else if ((UserNumber % Divisor != 0) && (Divisor == UserNumber - 1))
			cout << UserNumber << " is prime." << endl;
	}
	
}
		
