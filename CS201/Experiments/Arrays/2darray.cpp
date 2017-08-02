#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/*
	4	6	9
	-1	11	5
*/

void doubleValues(int a[2][3]){
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 3; ++j){
			a[i][j] *= 2;
		}
	}
}


int main(){

	int a[2][3];
	a[0][0] = 4;
	a[0][1] = 6;
	a[0][2] = 9;
	a[1][0] = -1;
	a[1][1] = 11;
	a[1][2] = 5;
	assert(a[0][0] == 4);

	int b[2][3] = {
		{ 4, 6, 9 },
		{ -1, 11, 5 }
	};
	
	doubleValues(b);
	assert(b[0][0] == 8);
	assert(b[0][1] == 12);

	cout << "All tests passed." << endl;
}
