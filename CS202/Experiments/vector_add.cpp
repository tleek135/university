#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> v1, vector<int> v2)
{
    vector<int> sum;
    int i;

    for (i = 0; i < v1.size() and i < v2.size(); i++) {
        sum.push_back(v1[i] + v2[i]);
    }

    if (v1.size() == v2.size())
        return sum;

    while (i < v1.size()) {
        sum.push_back(v1[i]);
        i++;
    }
 
    while (i < v2.size()) {
        sum.push_back(v2[i]);
        i++;
    }

    return sum;
}

void print(vector<int> test)
{
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> first;
    vector<int> second;
    vector<int> third;
	int temp, temp2;

    cout << "This program will create two vectors and produce "
		 << "a third vector based on the sum of the elements of "
         << "the first two vectors.\n";

	cout << "Please enter a value for the first vector, "
		 <<	"and type Ctrl-D when done: ";
	cin >> temp;

	while (!cin.eof()) {
		first.push_back(temp);
		cout << "Enter another value for vector 1: ";
		cin >> temp;
	}

	cout << "Please enter values for the second vector, and type "
		 << "Ctrl-D when done: ";
	cin >> temp2;

	while (!cin.eof()) {
		second.push_back(temp2);
		cout << "Enter another value for vector 2: ";
		cin >> temp2;
	}

	third = add(first, second);

    print(first);
    print(second);
    print(third);

	return 0;
}

