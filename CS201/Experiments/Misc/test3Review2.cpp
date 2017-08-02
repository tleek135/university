#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int search(const vector<int> & v, int k){
	for (int index = 0; index < v.size(); index++){
		if (k == v[index])
			return index;
	}

	return -1;
}




int main(){
	int a[] = {-2, 4, 18, 6, -10};
	vector<int> test(a, a + 5);

	assert(search(test, 1) == -1);
	assert(search(test, 4) == 1);

	cout << "All tests passed.\n";
}
