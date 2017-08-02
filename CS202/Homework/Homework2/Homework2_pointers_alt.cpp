/******************************************************
 * Kyle Lee
 * Homework2_pointers_alt.cpp
 * April 25, 2015
 * CSE 202 (Wednesday lab)
 * Description: Using pointers in functions to find 
   the average and maximum number in a floating-point
   number array.
 * Solution: use pointer variables in place of array
   names, because array names are themselves pointers 
   to beginning of array, then use loops to perform
   average/maximum calculations
 * Percent complete: 100%
******************************************************/

#include <iostream>

using namespace std;

//Calculates and returns the average of a floating-point array
double average(double * a, int a_size)
{
	double running_total = 0, calculated_average;

	for (int i = 0; i < a_size; i++)
		running_total += *(a+i);

	calculated_average = running_total/a_size;
	return calculated_average;
}

//Returns the location of the maximum number in a floating-point array
double * maximum(double * a, int a_size)
{
	double max = *a;
	double * max_pointer = &max;

	for (int i = 1; i < a_size; i++)
		max = ((*(a+i) > max)? *(a+i) : max);

	return max_pointer;
}

main()
{
	double numbers[1000];
	int count = 0;
	double holder;

	cout << "This program will calculate the average and maximum "
         << "value for a list of floating-point numbers that you "
         << "enter. Enter a value, then type Ctrl-D when done: ";
	cin >> holder;  

	while (!cin.eof()) {
		*(numbers + count) = holder;
		count++;
		cout << "Please enter another floating-point number: ";
		cin >> holder;
	}

	cout << endl;
	cout << "The average of those numbers is: " << average(numbers, count) << endl;
	cout << "The maximum is: " << *(maximum(numbers, count)) << endl;
}
	




