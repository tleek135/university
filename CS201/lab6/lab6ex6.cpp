//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 6

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

bool isAllZeros(int a[50][100]){
	for (int row = 0; row < 50; row++){
		for (int column = 0; column < 100; column++){
			if (a[row][column] != 0)
				return false;
		}
	}

	return true;
}

int main(){
	int test[50][100];

	for (int row = 0; row < 50; row++){
		for (int column = 0; column < 100; column++){
			test[row][column] = 0;
		}
	}

	assert(isAllZeros(test));

	test[25][25] = 2;

	assert(!isAllZeros(test));

	test[25][25] = 0;

	assert(isAllZeros(test));

	cout << "All tests passed.\n";

}
