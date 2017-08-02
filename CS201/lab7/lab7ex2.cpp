//Program written by: Kyle Lee (005054981)
//Lab 7, Exercise 2

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

const int ROWS = 4;
const int COLS = 3;

double findMax(double a[ROWS][COLS]){
	double maxNum = a[0][0];
	for (int row = 0; row < ROWS; row++){
		for (int column = 0; column < COLS; column++){
			if (a[row][column] > maxNum)
				maxNum = a[row][column];
		}
	}

	return maxNum;
}

int main(){
	double test[][3] = {0.1, 1.6, 5.9,
			    6.7, 8.2, 4.1,
			    2.2, 4.7, 3.5,
			    9.8, 1.1, 7.4};

	assert(findMax(test) == 9.8);

	cout << "All tests passed.\n";

}


