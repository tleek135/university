//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 9

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

bool isStrictlyIncreasing(vector<int> & v){
	for (int index = 0; index < (v.size() - 1); index++){
		if (v[index] >= v[index + 1])
			return false;
	}

	return true;
}

int main(){
	int temp[] = {1, 3, 5, 7, 9};
	vector<int> test(temp, temp + 5);

	assert(isStrictlyIncreasing(test));

	test.pop_back();
	test.push_back(7);
	assert(!isStrictlyIncreasing(test));

	cout << "All tests passed.\n";

}
