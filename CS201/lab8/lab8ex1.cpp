//Program written by: Kyle Lee (005054981)
//Lab 8, Exercise 1

#include <iostream>
#include <cassert>
#include <vector>

using namespace std; 

/* 
	12 8 3 9 6
	3 8 12 9 6
	3 6 12 9 8 
	3 6 8 9 12

*/

void mysort(vector<int> & v){
	int least = v[0];
	for (int index = 0; index < v.size() - 1; index++){
		for (int index2 = index + 1; index2 < v.size(); index2++){
			if (v[index2] < v[index]){
				least = v[index2];
				v[index2] = v[index];
				v[index] = least;
			}
		}
	}

}

int main(){
	int a[] = {12, 8, 3, 9, 6};

	vector<int> test(a, a + 5);

	mysort(test);

	assert(test[0] == 3);
	assert(test[1] == 6);
	assert(test[2] == 8);
	assert(test[3] == 9);
	assert(test[4] == 12);

	cout << "All tests passed.\n";

}



