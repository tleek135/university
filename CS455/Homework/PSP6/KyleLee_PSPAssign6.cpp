// Class: CSE 455
// Term: Winter 2016
// Instructor: Dr. Concepcion
// Name: Kyle Lee
// PSP Assignment #6
// Title: Calculating LOC estimate and prediction intervals

#include <iostream>
#include <vector>
#include <cmath> //for sqrt() function

using namespace std;

class Correlation
{
private:
	double xSum, xSquaredSum, ySum, ySquaredSum, twoVariableSum, rValue, tValue, pValue;
	double xAverage, yAverage, betaZero, betaOne, variance, standardDeviation, range, projection;
	const double TCHART[2][9] = { {0, 0.20, 0.40, 0.70, 0.80, 0.90, 0.95, 0.98, 0.99} ,
	{6, 0.265, 0.553, 1.134, 1.440, 1.943, 2.447, 3.143, 3.707} };

public:
	//Constructor
	Correlation()
	{
		xSum = xSquaredSum = ySum = ySquaredSum = twoVariableSum = 0;
		xAverage = yAverage = betaZero = betaOne = 0;
		variance = standardDeviation = range = projection = 0;
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

	//Calculates p by interpolation
	double tValueCalc(double pAlphaOverTwo)
	{
		double x, y, a, b; //differences between t and p values
		double lowerTBound, upperTBound, lowerPBound, upperPBound;
		for (int i = 1; i < 9; i++)
		{
			if (pAlphaOverTwo <= TCHART[0][i])
			{
				lowerTBound = TCHART[1][i-1]; upperTBound = TCHART[1][i];
				lowerPBound = TCHART[0][i-1]; upperPBound = TCHART[0][i];
				x = pAlphaOverTwo - lowerPBound; y = upperPBound - lowerPBound;
				b = upperTBound - lowerTBound; a = x*b/y;
				tValue = lowerTBound + a;
				return tValue;
			}
		}
		return 0;
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

	double calcProjection(double xK)
	{
		projection = betaZero + betaOne*xK;
		return projection;
	}

	double StdDev(vector<double> firstSet, vector<double> secondSet)
	{
		double coefficient = (1.0/(firstSet.size() - 2));
		double sum = 0;
		for (int i = 0; i < firstSet.size(); i++) {
			sum += square(secondSet[i] - betaZero - betaOne*firstSet[i]);
		}

		variance = coefficient*sum;
		standardDeviation = sqrt(variance);
		return standardDeviation;
	}

	double calcRange(double xK, vector<double> xValues)
	{
		double sigma = 0;
		for (int i = 0; i < xValues.size(); i++) {
			sigma += square(xValues[i]-average(xValues));
		}

		range = tValue*standardDeviation*
		sqrt(1.0+(1.0/xValues.size())+(square(xK - average(xValues))/(sigma)));
		return range;
	}

	double getUPI()
	{
		return projection + range;
	}

	double getLPI()
	{
		return projection - range;
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
	cout << "Projection (N): " << dataSet.calcProjection(400) << endl;
	cout << "Standard Deviation: " << dataSet.StdDev(x,y) << endl;
	
	cout << "85 percent intervals: " << endl;
	cout << "t: " << dataSet.tValueCalc(0.85) << endl;
	cout << "Range: " << dataSet.calcRange(400, x) << endl;
	cout << "UPI: " << dataSet.getUPI() << endl;
	cout << "LPI: " << dataSet.getLPI() << endl << endl;

	cout << "95 percent intervals: " << endl;
	cout << "t: " << dataSet.tValueCalc(0.95) << endl;
	cout << "Range: " << dataSet.calcRange(400, x) << endl;
	cout << "UPI: " << dataSet.getUPI() << endl;
	cout << "LPI: " << dataSet.getLPI() << endl;

}

