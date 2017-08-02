#include <iostream>

using namespace std;

int main(){
	int sample[] = {5, 10};	
	bool test = true;

	cout << test << endl;
	cout << !test << endl;

	cout << sample[test] << endl;
	cout << sample[!test] << endl;
	cout << test << endl;

}
