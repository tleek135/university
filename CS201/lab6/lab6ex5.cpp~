//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 5

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int countOccurrences(const vector<int> & v, int k){
	int occurrenceCount = 0;
	for (int index = 0; index < v.size(); index++){
		if (v[index] == k)
			++occurrenceCount;
	}

	return occurrenceCount;
}

int main(){
	
	int temp[] = {2, 3, 2, 7, 7, 8, 7, 12, 26, 87, 12};
	vector<int> test(temp, temp + 11);

	assert(countOccurrences(test, 2) == 2);
	assert(countOccurrences(test, 3) == 1);
	assert(countOccurrences(test, 7) == 3);
	assert(countOccurrences(test, 12) == 2);

	cout << "All tests passed.\n";

}


