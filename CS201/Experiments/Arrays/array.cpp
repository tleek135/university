#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


void doubleValues(int a[], int size) {
	for (int i = 0; i < size; ++i){
		a[i] = a[i] * 2;
	}
}

int main(){

	int a[] = { 3, 9 };
	assert(a[0] == 3);
	assert(a[1] == 9);

	int b[2];
	b[0] = 3;
	b[1] = 9;
	assert(b[0] == 3);
	assert(b[1] == 9);

	doubleValues(a, 2);
	assert(a[0] == 3 * 2);
	assert(a[1] == 9 * 2);

	cout << "All tests passed." << endl;
}
