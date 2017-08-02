// Class: CSE 455
// Term: Winter 2016
// Instructor: Dr. Concepcion
// Name: Kyle Lee
// PSP Assignment #3
// Title: Correlation Between Two Sets of Numbers

#include <iostream>
#include <vector>
#include <cmath> //for sqrt() function

using namespace std;

class Correlation
{
private:
	double xSum, xSquaredSum, ySum, ySquaredSum, twoVariableSum, rValue;

public:
	//Constructor
	Correlation()
	{
		xSum = xSquaredSum = ySum = ySquaredSum = twoVariableSum = rValue = 0;
	}

	double square(double value)
	{
		return value * value;
	}

	//Calculates sigma for one variable
	double sigmaOneVariable(vector<double> data, bool variableSquared)
	{
		double sum = 0;
		
		if (variableSquared)
		{
			for (int i = 0; i < data.size(); i++) 
				sum += square(data[i]);
			return sum;
		}

		for (int i = 0; i < 10; i++)
			sum += data[i];
		return sum;
	}

	//Calculates sigma for two variables
	double sigmaTwoVariable(vector<double> firstSet, vector<double> secondSet)
	{
		double sum = 0;
		
		for (int i = 0; i < firstSet.size(); i++)
			sum += (firstSet[i] * secondSet[i]);
		return sum;
	}

	//Uses correlation formula to calculate correlation (r value)
	double calculateCorrelation(vector<double> firstSet, vector<double> secondSet)
	{
		xSum = sigmaOneVariable(firstSet, false);
		ySum = sigmaOneVariable(secondSet, false);
		xSquaredSum = sigmaOneVariable(firstSet, true);
		ySquaredSum = sigmaOneVariable(secondSet, true);
		twoVariableSum = sigmaTwoVariable(firstSet, secondSet);

		rValue = (firstSet.size() * twoVariableSum - (xSum * ySum))/
				 sqrt((firstSet.size()*xSquaredSum - square(xSum))*
				 (firstSet.size()*ySquaredSum - square(ySum)));

		return rValue;
	}
};

main()
{
	vector<double> x, y;
	double temp;
	Correlation dataSet;

	for (int i = 0; i < 10; i++) {
		cout << "Enter a value for x[" << i << "]: ";
		cin >> temp;
		x.push_back(temp);
	}

	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << "Enter a value for y[" << i << "]: ";
		cin >> temp;
		y.push_back(temp);
	}

	temp = dataSet.calculateCorrelation(x, y);
	cout << "r (correlation): " << temp << endl;
	cout << "r squared: " << dataSet.square(temp) << endl;

}

