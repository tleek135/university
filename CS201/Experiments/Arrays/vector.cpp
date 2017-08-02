#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> doubleValues2(const vector <int> & v) {
	vector<int> w;
	for (int i = 0; i < v.size(); ++i){
		w.push_back(v[i] * 2);
	}
	return w;
}

void doubleValues1(vector<int> & v) {
	for (int i = 0; i < v.size(); ++i){
		v[i] = v[i] * 2;
	}
}

int main(){

	vector<int> v; // v = [ ]

	assert(v.size() == 0);
	v.push_back(3); // v = [ 3 ]
	v.push_back(9); // v = [ 3, 9 ]

	assert(v[0] == 3);
	assert(v[1] == 9);
	assert(v.size() == 2);

	vector<int> a = doubleValues2(v);
	assert(a[0] == 3 * 2);
	assert(a[1] == 9 * 2);
	assert(a.size() == 2);

	doubleValues1(v);
	assert(v[0] == 6);
	assert(v[1] == 18);
	assert(v.size() == 2);



	cout << "All tests passed." << endl;
}
