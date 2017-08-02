//Program written by: Kyle Lee (005054981)
//Lab 8, Exercise 2 (Slow algorithm)

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std; 

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
	vector<int> test(100000);
	srand(5);

	for (int index = 0; index < test.size(); index++)
		test[index] = rand();

	mysort(test);

	cout << "Finished sorting the vector.\n";
}
		
