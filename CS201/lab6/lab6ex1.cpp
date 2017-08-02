//Program written by: Kyle Lee (005054981)
//Lab 6, Exercise 1

#include <iostream>
#include <cassert>

using namespace std;

int mymaximum (int a[], int numberOfElements){
	int maxNumStorage = a[0];
	for (int count = 1; count < numberOfElements; count++){
		if (a[count] > maxNumStorage)
			maxNumStorage = a[count];
	}
	
	return maxNumStorage;
	
}

int main(int argc, char * args[]){

	int test1[] = {32, 4, 6, 12, 9};
	assert(mymaximum(test1, 5) == 32);

	int test2[] = {25, 7, 86, 302, 15, 77};
	assert(mymaximum(test2, 6) == 302);

	int test3[] = {0, 0, 1, 1};
	assert(mymaximum(test3, 4) == 1);

	int test4[] = {5, 8, 18};
	assert(mymaximum(test4, 3) == 18);

	int test5[] = {-2, -1, -5, -6};
	assert(mymaximum(test5, 4) == -1);

	cout << "All tests passed successfully.\n";

}

