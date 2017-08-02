//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 4

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void insert(vector<int> & v, int k){
	int tempStorage;
	for (int index = 0; index < (v.size() - 1); index++){
		if (k > v[index] && k < v[index + 1]){
			tempStorage = v[v.size() - 1];
			
			for (int shiftRight = v.size() - 1; shiftRight >= (index + 1); shiftRight--){
				v[shiftRight + 1] = v[shiftRight];
			}
		
		v[index + 1] = k;
		v.push_back(tempStorage);
		}
	}
}

int main(){
	vector<int> test;

	test.push_back(4), test.push_back(7), test.push_back(15), test.push_back(19),
	test.push_back(26), test.push_back(48);

	insert(test, 11);
	assert(test[2] == 11 && test[3] == 15);

	insert(test, 21);
	assert(test[5] == 21 && test[6] == 26);

	insert(test, 33);
	assert(test[7] == 33 && test[8] == 48);

	insert(test, 47);
	assert(test[8] == 47 && test[9] == 48);

	cout << "All tests passed.\n";

}

		
