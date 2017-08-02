//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 2

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void append(vector<int> & v, int n){
	for(int addedNum = 0; addedNum <= (n - 1); ++addedNum)
		v.push_back(addedNum);
}

int main(){
	vector<int> sample;
	
	append(sample, 5);
	assert(sample[0] == 0 && sample[1] == 1);
	assert(sample[2] == 2 && sample[3] == 3);
	assert(sample[4] == 4);

	append(sample, 3);
	assert(sample[5] == 0 && sample[6] == 1);
	assert(sample[7] == 2);

	append(sample, 2);
	assert(sample[8] == 0 && sample[9] == 1);
	

	cout << "All tests passed.\n";

}
