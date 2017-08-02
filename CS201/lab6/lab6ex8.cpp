//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 8

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

bool isUnlucky(vector<int> & v){
	for (int index = 0; index < v.size(); index++){
		if (v[index] == 13)
			return true;
	}

	return false;
}

int main(){
	vector<int> test;
	test.push_back(1), test.push_back(36), test.push_back(96);
	test.push_back(13), test.push_back(62);

	assert(isUnlucky(test));
	
	int holder[] = {5, 7, 51, 73, 64, 81};
	vector<int> test2(holder, holder + 6);

	assert(!isUnlucky(test2));

	cout << "All tests passed.\n";

}
