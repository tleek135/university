// Class: CSE 455
// Term: Winter 2016
// Instructor: Dr. Concepcion
// Name: Kyle Lee
// PSP Assignment #5
// Title: Calculating Linear Regression Size-Estimating Parameters

#include <iostream>
#include <vector>
#include <cmath> //for sqrt() function

using namespace std;

class Correlation
{
private:
	double xSum, xSquaredSum, ySum, ySquaredSum, twoVariableSum;
	double xAverage, yAverage, betaZero, betaOne;

public:
	//Constructor
	Correlation()
	{
		xSum = xSquaredSum = ySum = ySquaredSum = twoVariableSum = 0;
		xAverage = yAverage = betaZero = betaOne = 0;
	}

	double square(double value)
	{
		return value * value;
	}

	double average(vector<double> data)
	{
		double sum = 0;

		for (int i = 0; i < data.size(); i++) {
			sum += data[i];
		}

		return sum/data.size();
	}

	//Calculates sigma for one variable
	double sigmaOneVariable(vector<double> data, bool variableSquared)
	{
		double sum = 0;
		
		if (variableSquared)
		{
			for (int i = 0; i < data.size(); i++) 
				sum += square(data[i]);
		}

		for (int i = 0; i < data.size(); i++)
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

	double calculateBetaOne(vector<double> firstSet, vector<double> secondSet)
	{
		xAverage = average(firstSet);
		yAverage = average(secondSet);
		int size = firstSet.size();

		betaOne = (sigmaTwoVariable(firstSet, secondSet) - (size*xAverage*yAverage))/
				  (sigmaOneVariable(firstSet, true) - (size*square(xAverage)));

		return betaOne;
	}

	double calculateBetaZero()
	{
		betaZero = yAverage - (betaOne*xAverage);
		return betaZero;
	}

};

main()
{
	vector<double> x, y;
	double temp;
	Correlation dataSet;

	for (int i = 0; i < 8; i++) {
		cout << "Enter a value for x[" << i << "]: ";
		cin >> temp;
		x.push_back(temp);
	}

	cout << endl;

	for (int i = 0; i < 8; i++) {
		cout << "Enter a value for y[" << i << "]: ";
		cin >> temp;
		y.push_back(temp);
	}

	cout << "Beta one: " << dataSet.calculateBetaOne(x, y) << endl;
	cout << "Beta zero: " << dataSet.calculateBetaZero() << endl;
	cout << "Average (x): " << dataSet.average(x) << endl;
	cout << "Average (y): " << dataSet.average(y) << endl;

}

