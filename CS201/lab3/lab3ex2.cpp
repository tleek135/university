//Program written by: Kyle Lee (005054981)
//Lab 3, Exercise 2

/* Test Cases:

Number		List of Primes before the Number
------		--------------------------------
8		2 3 5 7
14		2 3 5 7 11 13
36		2 3 5 7 11 13 17 19 23 29 31
59		2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59

*/

#include <iostream>

using namespace std;

int main(int argc, char * args[]){
	int UserNumber;

	cout << "This program will list all prime numbers between 2 and the number that you enter.\n";
	cout << "Please enter an integer greater than 1: ";
	cin >> UserNumber;

	for (int PrintedNum = 2; PrintedNum <= UserNumber; PrintedNum++){
		
		for (int Divisor = 2; Divisor <= PrintedNum; Divisor++){
			if (PrintedNum == 2)
				cout << PrintedNum << " ";
			else if (PrintedNum % Divisor == 0)
				break;
			else if ((PrintedNum % Divisor != 0) && (Divisor == PrintedNum - 1))
				cout << PrintedNum << " ";
		}

	}
	
	cout << endl;

}
			
		
	
