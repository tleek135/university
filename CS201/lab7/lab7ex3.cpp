//Program written by: Kyle Lee (005054981)
//Lab 7, Exercise 3

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int search(int a[], int size, int k){
	for (int i = 0; i < size; i++){
		if (k == a[i])
			return i;
	}

	return -1;
}

int main(){
	int test[] = {3, 47, 21, 99, 12, 65};

	assert(search(test, 6, 12) == 4);
	assert(search(test, 6, 21) == 2);

	assert(search(test, 6, 4) == -1);
	assert(search(test, 6, 23) == -1);

	cout << "All tests passed.\n";

}
			