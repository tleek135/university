#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int numberofones = 0, numberoftwos = 0;
	ifstream input;
	input.open("disk1");

	input.seekg(14*128);

	char c;
	input.get(c);
	while(c != '#') {
		if (c == '1')
			numberofones++;
		else if (c == '2')
			numberoftwos++;

		input.get(c);
	}

	input.close();

	cout << "Number of ones: " << numberofones << endl;
	cout << "Number of twos: " << numberoftwos << endl;
	return 0;
}