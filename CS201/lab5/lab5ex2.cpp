//Program written by: Kyle Lee (005054981)
//Lab 5, Exercise 1

#include <iostream>
#include "Number.h"

using namespace std;

int main(int argc, char * args[]){
	int n;

	cout << "This program will display all the prime numbers "
	     << "between 2 and the number you enter.\n";
	cout << "Please enter a number greater than 2: ";
	cin >> n;
	
	for (int count = 2; count <= n; count++){
		Number TestUserNum(count);
		if (TestUserNum.isPrime())
			cout << count << " ";
	}
	
	cout << endl;

}


