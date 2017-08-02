//Program written by: Kyle Lee (005054981)
//Lab 3, Exercise 3

/*	Test Cases:

Number		Prime Factors
------		-------------
2		2
13		13
31		31
67		67

4		2 2
20		2 2 5
54		2 3 3 3
78		2 3 13

*/

#include <iostream>

using namespace std;

int main(int argc, char * args[]){
	int UserNumber;
	int CompositeNum;

	cout << "This program will calculate all the prime factors\n";
	cout << "of the number that you enter. Please enter a number: ";
	cin >> UserNumber;

	cout << "The prime factor(s) are: ";

	for (int Divisor = 2; Divisor <= UserNumber; Divisor++){
		
		if (UserNumber % Divisor == 0){
			cout << Divisor << " ";
			CompositeNum = UserNumber / Divisor;
			for (int PrimeFactorTester = 2; PrimeFactorTester <= CompositeNum; PrimeFactorTester++){
					while (CompositeNum % PrimeFactorTester == 0){
						cout << PrimeFactorTester << " ";
						CompositeNum /= PrimeFactorTester;
					}
					
			}
			
			break;
		
		}
				
		else if (UserNumber % Divisor != 0 && Divisor == UserNumber - 1){
			cout << UserNumber;
			break;
		}
	
	}

	cout << endl;

}

