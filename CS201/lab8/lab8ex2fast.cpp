//Program written by: Kyle Lee (005054981)
//Lab 8, Exercise 2 (Fast algorithm)

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	vector<int> test(100000);
	srand(5);

	for (int index = 0; index < test.size(); index++)
		test[index] = rand();

	sort(test.begin(), test.end());

	cout << "Finshed sorting the vector.\n";
}
