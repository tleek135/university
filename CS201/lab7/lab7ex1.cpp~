//Program written by: Kyle Lee (005054981)
//Lab 7, Exercise 1


#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

bool binarySearch(const vector<int> & v, int k){
	int upperBound = v.size() - 1;
	int lowerBound = 0;
	int midpoint;
	
	while (lowerBound <= upperBound){
		midpoint = (lowerBound + upperBound) / 2;
		if (k == v[midpoint])
			return true;
		else if (k < v[midpoint])
			upperBound = midpoint - 1;
		else
			lowerBound = midpoint + 1;
	}

	return false;
}

int main(){
	int a[] = {-4, -2, 0, 3, 6, 11, 15, 16};
	vector<int> test(a, a + 8);

	assert(binarySearch(test, -2));
	assert(binarySearch(test, 11));

	assert(!binarySearch(test, 1));
	assert(!binarySearch(test, 10));

	cout << "All tests passed.\n";

}
