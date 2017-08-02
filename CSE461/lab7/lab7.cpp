/*
 * Name: Kyle Lee
 * Date: May 29, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 7
 * Note: For lab 7, we were only required to write the constructor
 * and build_table functions.
 */

#include "Table.h"
		
int main()
{
 	Table database("disk1", 256, 128, "flatf", "index");

	string file;
	cout << "Please enter the name of the database input file: ";
	cin >> file;

	while (database.build_table(file) == 0) {
		cout << "Enter a valid file name: ";
		cin >> file;
	}
}
