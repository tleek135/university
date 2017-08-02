//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 10

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> flatten(int a[100][200]){
	vector<int> storage;
	for (int row = 0; row < 100; row++){
		for (int column = 0; column < 200; column++){
			storage.push_back(a[row][column]);
		}
	}

	return storage;
}

bool transferSuccess(int a[100][200], vector<int> b){
	int vectorIndex = 0;
	for (int row = 0; row < 100; row++){
		for (int column = 0; column < 200; column++, vectorIndex++){
			if (a[row][column] != b[vectorIndex]){
				return false;
			}
		}
	}	

	return true;
}

int main(){
	int testArray[100][200];
	vector<int> testVector;

	for (int row = 0; row < 100; row++){
		for (int column = 0; column < 200; column++){
			testArray[row][column] = column;
		}
	}
	
	testVector = flatten(testArray);

	assert(transferSuccess(testArray, testVector));

	cout << "Array successfully flattened and transferred to vector.\n";

}
