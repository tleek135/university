/********************************************************************
 * Kyle Lee
 * lab8.cpp
 * May 27, 2015
 * CSE 202 (Wednesday lab)
 * Description: Analyze selection sort and binary search algorithms
   and their time complexities. 
 * Solution: Implement code for selection sort and binary search, 
   and then test them with sample input from a file and from the user. 
 * Percent complete: 100%
*********************************************************************/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Sorts a vector by swapping elements if a smaller element is found
//Time complexity: O(n^2)
void selection_sort(vector<int> & arr)
{
	int i, j;
	
	for (i = 0; i < arr.size()-1; i++) {
		for (j = i+1; j < arr.size(); j++) {
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

//Searches for an element in a sorted vector by eliminating half
//of the vector at a time
//Time complexity: O(log(n))
int binary_search(vector<int> v, int from, int to, int value)
{
	if (from > to)
		return -1;
	int mid = (from + to) / 2;
	if (v[mid] == value)
		return mid;
	else if (v[mid] < value)
		return binary_search(v, mid + 1, to, value);
	else
		return binary_search(v, from, mid - 1, value);
}

main()
{
	vector<int> numbers;
	int input;
	ifstream file;
	file.open("input.txt");
	file >> input;
	
	while (!file.eof()) {
		numbers.push_back(input);
		file >> input;
	}

	file.close();

	selection_sort(numbers);

	for (int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << endl;

	cout << "Please enter a number to search for in the vector: ";
	cin >> input;

	while (!cin.eof()) {
		cout << binary_search(numbers, 0, numbers.size()-1, input) << endl;
		cout << "Please enter another number, or type Ctrl-D when done: ";
		cin >> input;
	}
}
		

