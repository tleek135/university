//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 7

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

bool areIdentical(const vector<int> & a, const vector<int> & b){
	for (int index = 0; index < a.size(); index++){
		if (a.size() != b.size() || a[index] != b[index]){
			return false;
		}
	}

	return true;
}

int main(){
	int temp[] = {2, 4, 6, 8};
	vector<int> test(temp, temp + 4);
	vector<int> test2(temp, temp + 4);

	assert(areIdentical(test, test2));

	test2.pop_back();
	assert(!areIdentical(test, test2));

	test2.push_back(9);
	assert(!areIdentical(test, test2));

	test.push_back(10);
	test2.pop_back();
	test2.push_back(8), test2.push_back(10);
	assert(areIdentical(test, test2));

	cout << "All tests passed.\n";

}
		


