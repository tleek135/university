// Class: CSE 330
// Term: Fall 2015
// Instructor: George M. Georgiou
// Name: Kyle Lee
// Homework 1, Chapter 4, #25

//Ch. 4, #25
//Write a program that initializes a vector with array values.
//Compute the average, then output each value along with its
//deviation (+/-) from the average.

#include <iostream>
#include <vector>

using namespace std;

main()
{
	int arr[] = {1, 6, 2, 9, 12, 15, 33, 28};
	int arrSize = sizeof(arr)/sizeof(int);

	int sum = 0, average;
	
	//Sums all array elements together
	for (int i = 0; i < arrSize; i++) 
		sum += arr[i];

	//Computes the average
	average = sum / arrSize;

	cout << "The average value is: " << average << endl << endl;
	cout << "The values in the array and their deviation from the average:" << endl << endl;

	//Displays value and its deviation from the average
	for (int i = 0; i < arrSize; i++) {
		cout << "Value: " << arr[i] << endl;
		cout << "Deviation: " << arr[i] - average << endl << endl;
	}

}

	
