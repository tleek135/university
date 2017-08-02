//Program written by: Kyle Lee (005054981)
//Lab 4, Exercise 2

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

bool is_prime(int n){
  	for (int Divisor = 2; Divisor <= n; Divisor++){
		if (n == 2 || (n % Divisor != 0 && Divisor == n - 1))
			return true;
		else if (n % Divisor == 0)
			return false;
	}
}

int main(int argc, char * args[]){
	int UserNumber;

	cout << "This program will list all prime numbers between 2 and the number that you enter.\n";
	cout << "Please enter an integer greater than 1: ";
	cin >> UserNumber;

	for (int PrintedNum = 2; PrintedNum <= UserNumber; PrintedNum++){
		if (is_prime(PrintedNum))
			cout << PrintedNum << " ";
	}

	cout << endl;

}
