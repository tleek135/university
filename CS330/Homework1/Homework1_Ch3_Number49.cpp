// Class: CSE 330
// Term: Fall 2015
// Instructor: George M. Georgiou
// Name: Kyle Lee
// Homework 1, Chapter 3, #49

//Ch. 3 #49
//Implement recursive function sumDigits(), which sums the digits of
//a nonnegative integer n
//Test the program with inputs 23, 1234, and 90513

#include <iostream>

using namespace std;

int sumDigits(unsigned int n) 
{
	int sum; //To hold digit sum

	//If n < 10, return that digit
	if (n/10 == 0)
		return n;

	/*Use recursion to sum a digit with a digit to its right
	For example, the sum of digits for the number 23 would 
	be 2 + 3*/
	sum = sumDigits(n/10) + n%10;

	return sum;
}

//Test this function with a main program
main()
{
	unsigned int number;

	cout << "Enter a number for which you would like to sum the digits: ";
	cin >> number;

	cout << "The sum of the digits in the number " << number << " is: ";
	cout << sumDigits(number) << endl;

}
