//Program written by: Kyle Lee (005054981)
//Lab 7, Exercise 4

#include <iostream>
#include <cassert>

using namespace std;

int binarySearch(int a[], int size, int k){
	int upperBound = size - 1;
	int lowerBound = 0;
	int midpoint;
		while (lowerBound <= upperBound){
			midpoint = (lowerBound + upperBound) / 2;
			
			if (k == a[midpoint])
				return midpoint;
			else if (k < a[midpoint])
				upperBound = midpoint - 1;
			else
				lowerBound = midpoint + 1;
		}

	return -1;
}

int main(){
	int test[] = {-5, -2, 0, 4, 7, 11, 15};

	assert(binarySearch(test, 7, 11) == 5);
	assert(binarySearch(test, 7, -5) == 0);
	assert(binarySearch(test, 7, 15) == 6);
	assert(binarySearch(test, 7, 0) == 2);

	assert(binarySearch(test, 7, 6) == -1);
	assert(binarySearch(test, 7, -1) == -1);

	cout << "All tests passed.\n";

}
