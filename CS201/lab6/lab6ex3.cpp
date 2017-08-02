//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 3

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void appendVector(vector<int> & v, const vector<int> & w){
	for (int index = 0; index < w.size(); index++)
		v.push_back(w[index]);
}

int main(){
	vector<int> firstVec, secondVec;

	firstVec.push_back(0), firstVec.push_back(8), firstVec.push_back(67);
	cout << "The first vector contains: ";
	for (int index = 0; index < firstVec.size(); index++)
		cout << firstVec[index] << " ";

	cout << endl;

	secondVec.push_back(6), secondVec.push_back(43);
	cout << "The second vector contains: ";
	for (int index = 0; index < secondVec.size(); index++)
		cout << secondVec[index] << " ";

	cout << endl;

	cout << "Appending first vector to second vector and testing result...\n";
	appendVector(firstVec, secondVec);
	assert(firstVec[0] == 0 && firstVec[1] == 8 && firstVec[2] == 67);
	assert(firstVec[3] == 6 && firstVec[4] == 43);
	
	cout << "Vectors appended and tested successfully. The new vector is now: ";
		for (int index = 0; index < firstVec.size(); index++)
		cout << firstVec[index] << " ";

	cout << endl;
		
}
