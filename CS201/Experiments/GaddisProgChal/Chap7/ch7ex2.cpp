#include <iostream>
#include <string>

using namespace std;

int main(){
	string month[] = {"blank", "January", "February", "March", "April", 
			  "May", "June", "July", "August", "September",
			  "October", "November", "December"};
	double rain[13];
	double highest = rain[1];
	double lowest = 100;
	int highestMonth, lowestMonth;
	double sum = 0;
	double average;
	
	cout << "This program will calculate total rainfall, "
	     << "average monthly rainfall, and the months with "
	     << "the most and least amount of rainfall.\n";

	for (int index = 1; index <= 12; ++index){
		cout << "Please enter the rainfall (in inches) "
	             << "for " << month[index] << ": ";
		cin >> rain[index];
		
		while (rain[index] < 0){
			cout << "Invalid number! Please enter "
			     << "a positive number for rainfall: ";
			cin >> rain[index];
		}

		sum += rain[index];

		if (rain[index] > highest){
			highest = rain[index];
			highestMonth = index;
		}
		else if (rain[index] < lowest){
			lowest = rain[index];
			lowestMonth = index;
		}
	}

	average = sum / 12;

	cout << "Total Rainfall for the Year: " << sum << " in.\n";
	cout << "Average Monthly Rainfall: " << average << " in.\n";
	cout << "Month of Highest Rainfall: " << month[highestMonth]
	     << " (" << highest << " in.)\n";
	cout << "Month of Lowest Rainfall: " << month[lowestMonth]
	     << " (" << lowest << " in.)\n";
}




